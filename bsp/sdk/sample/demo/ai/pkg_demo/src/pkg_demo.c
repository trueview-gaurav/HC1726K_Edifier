#include "json_object.h"
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
// stderror
#include <string.h>
#include <errno.h>

#include <syslog.h> // unknown the openlog should use it or not

// #include <unistd.h>
// #include <sys/time.h>

#include "utils/systemUtils/log.h"
#include "mpi_sys.h"
#include "ml_pkg.h"
#include "utils/systemUtils/systemUtils.h"
#include "pkg_demo.h"

#define CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI 1
#ifdef CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI
#include "utils/sei_support/pkg_sei_server.h"
#endif
#define WAIT_WIN_TIMEOUT 0
#define SHOW_Y_AVG_VAL 1
#define MAX_CFG_NUM ML_PKG_MAX_REG_NUM

static volatile sig_atomic_t g_run_flag = false;

void help(const char *name)
{
	printf("Usage: %s -i [options] ...\n"
	       "Options:\n"
	       "  -i <file>            PKG parameter in .json format.\n"
	       "  -c <channel>         Specify which video channel to use. (Default 0).\n"
	       "  -w <window>          Specify which video window to use. (Default 0).\n"
	       "  -s <snap_duration_ms> Sleep if no any action occur in ms. (Default 0, 0 mean run foraver).\n"
	       "\n"
	       "Example:\n"
	       "  $ mpi_stream -d /system/mpp/case_config/case_config_1001_FHD &\n"
	       "  $ %s -i /system/mpp/pkg_config/pkg_conf_1.json &\n"
#ifdef CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI
	       "  $ agtx-rtsp-server -S\n",
#else
	       "  $ agtx-rtsp-server -n\n",
#endif
	       name, name);
}

int main(int argc, char **argv)
{
	// System configuration
	// Open logger. Currently we use syslog as our logging system.
	openlog(NULL, 0, LOG_LOCAL7);

	if (signal(SIGINT, handleSigInt) == SIG_ERR) {
		log_err("Cannot handle SIGINT! err: %s", strerror(errno));
		return EXIT_FAILURE;
	}

	if (signal(SIGTERM, handleSigInt) == SIG_ERR) {
		log_err("Cannot handle SIGTERM! err: %s", strerror(errno));
		return EXIT_FAILURE;
	}

	MPI_WIN win_idx = MPI_VIDEO_WIN(0, 0, 0);
	uint32_t snap_duration_ms = 0;
	int c;
	const char *config_fname = NULL;

	// Argument parsing
	while ((c = getopt(argc, argv, "i:c:w:s:h")) != -1) {
		switch (c) {
		case 'i':
			config_fname = optarg;
			break;

		case 'c':
			win_idx.chn = atoi(optarg);
			break;

		case 'w':
			win_idx.win = atoi(optarg);
			break;

		case 's':
			snap_duration_ms = atoi(optarg);
			break;

		case 'h':
			help(argv[0]);
			return EXIT_SUCCESS;

		default:
			help(argv[0]);
			return EXIT_FAILURE;
		}
	}

	// MPI information initialization
	MPI_ISP_Y_AVG_CFG_S frame_y_avg_cfg;
	frame_y_avg_cfg.roi.sx = 0;
	frame_y_avg_cfg.roi.sy = 0;
	frame_y_avg_cfg.roi.ex = 0;
	frame_y_avg_cfg.roi.ey = 0;
	frame_y_avg_cfg.diff_thr = 0;

	MPI_ISP_Y_AVG_CFG_S roi_y_avg_cfg[MAX_CFG_NUM];
	for (int i = 0; i < MAX_CFG_NUM; i++) {
		roi_y_avg_cfg[i].roi.sx = 0;
		roi_y_avg_cfg[i].roi.sy = 0;
		roi_y_avg_cfg[i].roi.ex = 0;
		roi_y_avg_cfg[i].roi.ey = 0;
		roi_y_avg_cfg[i].diff_thr = 0;
	}

	// OD Param. setup
	MPI_IVA_OD_PARAM_S od_param = {
		.od_qual = 46,
		.od_track_refine = 42,
		.od_size_th = 40,
		.od_sen = 254,
		.en_stop_det = 0,
		.en_gmv_det = 0,
	};

	// RoI attribute must be load from config file.
	ML_PKG_PARAM_S pkg_param = {
		.pkg_snapshot_w = 1280,
		.pkg_snapshot_h = 720,
		.idle2in_th = 21,
		.in2idle_th = 21,
		.region_num = 1,
		.roi[0] = { .sx = 0, .sy = 0, .ex = 0, .ey = 0 },
		.event_type = ML_PKG_EVENT_PACKAGE, // package detection
		.duration = 0,
		.background_merge_delay = 2592000, // 86400 sec = 1 day
	};

	uint8_t frame_y_avg_cfg_idx;
	uint8_t roi_y_avg_cfg_idx[MAX_CFG_NUM];
	int err;

	parseConfig(config_fname, &od_param, &pkg_param);
	fprintf(stderr, "Maximum MPI config number: %d, Maximum roi numbers: %d\n", MPI_MAX_ISP_VAR_CFG_NUM,
	        ML_PKG_MAX_REG_NUM);
	fprintf(stderr, "region_num: %d\n", pkg_param.region_num);
	fprintf(stderr, "frame_y_avg_cfg.roi: (%d, %d, %d, %d)\n", frame_y_avg_cfg.roi.sx, frame_y_avg_cfg.roi.sy,
	        frame_y_avg_cfg.roi.ex, frame_y_avg_cfg.roi.ey);
	for (int i = 0; i < pkg_param.region_num; i++) {
		roi_y_avg_cfg[i].roi = pkg_param.roi[i];
		fprintf(stderr, "pkg_param_cfg[%d].roi: (%d, %d, %d, %d)\n", i, pkg_param.roi[i].sx,
		        pkg_param.roi[i].sy, pkg_param.roi[i].ex, pkg_param.roi[i].ey);
		fprintf(stderr, "roi_y_avg_cfg[%d].roi: (%d, %d, %d, %d)\n", i, roi_y_avg_cfg[i].roi.sx,
		        roi_y_avg_cfg[i].roi.sy, roi_y_avg_cfg[i].roi.ex, roi_y_avg_cfg[i].roi.ey);
	}

	// First, initialize MPI system to access video pipeline.
	// #ifdef PKG_DEMO_START_EARLIER_THAN_MPI_STREAM
	// 	while (MPI_SYS_init() != MPI_SUCCESS) {
	// 		delay_ms(50); // sleep for 50 ms
	// 	}
	// #else
	err = MPI_SYS_init();
	if (err != MPI_SUCCESS) {
		return EXIT_FAILURE;
	}
	// #endif // PKG_DEMO_START_EARLIER_THAN_MPI_STREAM

	// Then, set OD attribute and start OD threading.
	// For system wide, OD threading can be activated only once.
	err = MPI_IVA_setObjParam(win_idx, &od_param);
	if (err != MPI_SUCCESS) {
		log_err("Failed to set OD param. err: %d", err);
		goto error;
	}

	/* Check parameters */
	err = ML_PKG_checkParam(&pkg_param);
	if (err) {
		log_err("Invalid PKG parameters. err: %d", err);
		goto error;
	}

	err = MPI_IVA_enableObjDet(win_idx);
	if (err != MPI_SUCCESS) {
		log_err("Failed to enable object detection. err: %d", err);
		goto error;
	}

	// After that, continuously get object list from MPI.
	// Initialize SEI server if you need to send SEI.
	err = initSeiServer(win_idx);
	if (err) {
		goto error;
	}

	err = MPI_DEV_addIspYAvgCfg(win_idx, &frame_y_avg_cfg, &frame_y_avg_cfg_idx);
	if (err != MPI_SUCCESS) {
		log_err("Failed to add Frame ISP Y average config. err: %d", err);
		goto error;
	}
	for (int i = 0; i < pkg_param.region_num; i++) {
		err = MPI_DEV_addIspYAvgCfg(win_idx, &roi_y_avg_cfg[i], &roi_y_avg_cfg_idx[i]);
		if (err != MPI_SUCCESS) {
			log_err("Failed to add ROI ISP Y average config. err: %d", err);
			goto error;
		}
	}

	runPackageDetection(win_idx, &pkg_param, frame_y_avg_cfg_idx, roi_y_avg_cfg_idx, snap_duration_ms);

error:

	for (int i = 0; i < pkg_param.region_num; i++) {
		err = MPI_DEV_rmIspYAvgCfg(win_idx, roi_y_avg_cfg_idx[i]);
		if (err != MPI_SUCCESS) {
			log_err("Failed to remove ROI ISP Y average config. err: %d", err);
		}
	}
	err = MPI_DEV_rmIspYAvgCfg(win_idx, frame_y_avg_cfg_idx);
	if (err != MPI_SUCCESS) {
		log_err("Failed to remove Frame ISP Y average config. err: %d", err);
	}

	exitSeiServer(win_idx);

	err = MPI_IVA_disableObjDet(win_idx);
	if (err != MPI_SUCCESS) {
		log_err("Failed to disable object detection. err: %d", err);
	}

	MPI_SYS_exit();

	closelog();

	return 0;
}

int modifyParam(ML_PKG_PARAM_S *output_param, const ML_PKG_PARAM_S *input_param)
{
	if (!output_param || !input_param) {
		log_err("Parameters should not be NULL.");
		return -EFAULT;
	}

	output_param->pkg_snapshot_w = input_param->pkg_snapshot_w;
	output_param->pkg_snapshot_h = input_param->pkg_snapshot_h;
	output_param->idle2in_th = input_param->idle2in_th;
	output_param->in2idle_th = input_param->in2idle_th;
	output_param->region_num = input_param->region_num;
	printf("PKG demo, check region number: %d\n", output_param->region_num);
	for (int i = 0; i < input_param->region_num; i++) {
		output_param->roi[i] = input_param->roi[i];
	}
	output_param->event_type = input_param->event_type;
	output_param->duration = input_param->duration;
	output_param->background_merge_delay = input_param->background_merge_delay;
	return 0;
}

static void determinePkgStatus(const ML_PKG_STATUS_S *foreground_status, int od_idx, int buf_idx, int start, int end,
                               UINT16 *y_avg)
{
	VIDEO_OD_CTX_S *od_ctx = &vftr_res_shm->od_ctx[od_idx];

	for (int i = start; i < end; i++) {
		int idx = i - start;
		char value_str[16];
		snprintf(value_str, sizeof(value_str), "%d-%d", y_avg[idx], foreground_status->stat[idx].motion_level);
		switch (foreground_status->stat[idx].result) {
		case ML_PKG_DET_IDLE:
#if SHOW_Y_AVG_VAL == 1
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "IDLE:%s", value_str);
#else
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "IDLE");
#endif
			break;
		case ML_PKG_DET_IN:
#if SHOW_Y_AVG_VAL == 1
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "IN:%s", value_str);
#else
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "IN");
#endif
			log_info("Package is placed in roi.");
			break;
		case ML_PKG_DET_OUT:
#if SHOW_Y_AVG_VAL == 1
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "OUT:%s", value_str);
#else
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "OUT");
#endif
			log_info("Package is removed out of roi.");
			break;
		default:
			assert(0);
		}
	}

	if (start > 0) {
		for (int i = 0; i < start; i++) {
			strncpy(od_ctx->ol[buf_idx].obj_attr[i].cat, "", VFTR_OBJ_CAT_LEN - 1);
		}
	}

	return;
}

int runPackageDetection(MPI_WIN mpi_idx, const ML_PKG_PARAM_S *pkg_input_param, uint8_t frame_y_avg_cfg_idx,
                        uint8_t *roi_y_avg_cfg_idx, uint32_t snap_duration_ms)
{
	ML_PKG_INSTANCE_S *instance;
	ML_PKG_INPUT_S input;
	ML_PKG_PARAM_S pkg_param;
	uint32_t timestamp = 0;
	int region_num = pkg_input_param->region_num;
	input.region_num = region_num;
	int ret = 0;

#ifdef CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI
	// Ring buffer, get the buffer from vftr api
	int od_idx = findOdCtx(mpi_idx, vftr_res_shm->od_ctx, NULL);
	int buf_info_idx = findVftrBufCtx(mpi_idx, vftr_res_shm->buf_info, NULL);
	VIDEO_OD_CTX_S *od_ctx = &vftr_res_shm->od_ctx[od_idx];
	AVFTR_VIDEO_BUF_INFO_S *buf_info = &vftr_res_shm->buf_info[buf_info_idx];

	MPI_IVA_OBJ_LIST_S *obj_list = NULL; // A pointer variable for reference information by address
	int buf_idx;
#else
	// wo/ vftr ring buffer, we can allocation obj dynamically
	MPI_IVA_OBJ_LIST_S tmp_ol;
	MPI_IVA_OBJ_LIST_S *obj_list = &tmp_ol;
	const int buf_idx = 0;
#endif

	ML_PKG_STATUS_S tmp_status = { 0 };
	ML_PKG_STATUS_S *status = &tmp_status;

	/* ML_PKG initialization*/

	// Create PKG instance
	instance = ML_PKG_newInstance(mpi_idx);
	if (!instance) {
		log_err("Failed to create PKG instance.");
		return -EINVAL;
	}

	// Get PKG default parameters
	ret = ML_PKG_getParam(instance, &pkg_param);
	if (ret != 0) {
		log_err("Failed to get PKG param. err: %d\n", ret);
		return EXIT_FAILURE;
	}

	// Overwrite default parameters with input parameters
	ret = modifyParam(&pkg_param, pkg_input_param);
	if (ret != 0) {
		log_err("Failed to modify PKG param. err: %d\n", ret);
		return EXIT_FAILURE;
	}

	// Set parameter to PKG instance
	ret = ML_PKG_setParam(instance, &pkg_param);
	if (ret) {
		log_err("Failed to set PKG parameters.");
		return -EINVAL;
	}
	// printf("PKG demo region_number: %d\n", instance->usr_param.region_num);

	g_run_flag = true;

	uint32_t _timer_counting = 0;
	while (g_run_flag) {
		// Wait one video frame processed.
		// This function returns after one frame is done.
		ret = MPI_DEV_waitWin(mpi_idx, &timestamp, WAIT_WIN_TIMEOUT);
		if (ret != MPI_SUCCESS) {
			log_err("Failed to waitWin for win: (%d, %d, %d). err: %d", mpi_idx.dev, mpi_idx.chn,
			        mpi_idx.win, ret);
			continue;
		}

#ifdef CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI
		buf_idx = updateBufferIdx(buf_info, timestamp);
		obj_list = &od_ctx->ol[buf_idx].basic_list;
#endif
		input.obj_list = obj_list;

		/* ML_PKG Required, get roi/frame y_avg and */

		// For statastic driver time
		static uint8_t is_first_time = 0;

		// Continuously get detection result from MPI.
		// If SEI is supported, we write the result into shared memory.

		// // Memory limitation, we cannot get image from two-side
		// if (!is_first_time){
		// 	// Test snapshot at the first time
		// 	timer_record_ms();
		// 	MPI_VIDEO_FRAME_INFO_S frame_info;
		// 	frame_info.width = pkg_input_param->pkg_snapshot_w;
		// 	frame_info.height = pkg_input_param->pkg_snapshot_h;
		// 	frame_info.type = MPI_SNAPSHOT_NV12; // NV12
		// 	int err = MPI_DEV_getWinFrame(mpi_idx, &frame_info, 100);
		// 	if (err != MPI_SUCCESS) {
		// 		fprintf(stderr, "MPI_DEV_getWinFrame failed!\n");
		// 		break;
		// 	}
		// 	printf("Frame snapshot driver time %u ms\n", timer_record_ms());
		// }

		if (!is_first_time) {
			timer_record_ms();
		}
		ret = MPI_IVA_getBitStreamObjList(mpi_idx, timestamp, obj_list);
		if (ret != MPI_SUCCESS) {
			log_err("Failed to get object list. err: %d", ret);
			continue;
		}
		if (!is_first_time) {
			_timer_counting = timer_record_ms();
			printf("Get object driver time %u ms\n", _timer_counting);
		}

		if (!is_first_time) {
			timer_record_ms();
		}
		ret = MPI_DEV_getIspYAvg(mpi_idx, frame_y_avg_cfg_idx, &input.frame_y_avg);
		if (ret != MPI_SUCCESS) {
			log_err("Get frame y average fail for win: (%d, %d, %d). err: %d", mpi_idx.dev, mpi_idx.chn,
			        mpi_idx.win, ret);
			continue;
		}
		if (!is_first_time) {
			_timer_counting = timer_record_ms();
			printf("Frame Y_avg driver time %u ms\n", _timer_counting);
			_timer_counting = 0;
		}

		for (int i = 0; i < region_num; i++) {
			if (!is_first_time) {
				timer_record_ms();
			}
			ret = MPI_DEV_getIspYAvg(mpi_idx, roi_y_avg_cfg_idx[i], &input.roi_y_avg[i]);
			if (!is_first_time) {
				_timer_counting += timer_record_ms();
			}
			if (ret != MPI_SUCCESS) {
				log_err("Get roi y average %d fail for win: (%d, %d, %d). err: %d", i, mpi_idx.dev,
				        mpi_idx.chn, mpi_idx.win, ret);
				continue;
			}
		}
		if (!is_first_time) {
			printf("Frame roi_y_avg driver time %u ms\n", (uint32_t)(_timer_counting / region_num));
			_timer_counting = 0;
		}
		is_first_time = 1;
		if (snap_duration_ms != 0) {
			// Camera status
			if (isStatusChanged(status, region_num, obj_list) == 1) {
				_timer_counting = 0;
				timer_record_ms();
			} else {
				_timer_counting += timer_record_ms();
			}

			ML_PKG_CAM_EVENT *pkg_cam_event = &input.camera_event;

			if (snap_duration_ms <= _timer_counting) {
				// suspend
				*pkg_cam_event = ML_PKG_CAM_ASLEEP;
			} else {
				*pkg_cam_event = ML_PKG_CAM_NORMAL;
			}
		}

		// Send video statistics to PKG algorithm module.
		ret = ML_PKG_detect(instance, &input, status);
		if (ret == ML_PKG_CAM_READY_FOR_SLEEP) {
			break;
		}
		if (ret != ML_PKG_MPI_SUCCESS) {
			log_err("Failed to detect foreground. err: %d", ret);
			continue;
		}

		for (int i = 0; i < region_num; i++) {
			obj_list->obj_num += 1;
			MPI_IVA_OBJ_ATTR_S *roi_obj_attr = &obj_list->obj[obj_list->obj_num - 1];
			roi_obj_attr->id = i;
			roi_obj_attr->life = status->stat[i].life_counter / 1000;
			roi_obj_attr->rect = pkg_input_param->roi[i];
			roi_obj_attr->mv.x = 0;
			roi_obj_attr->mv.y = 0;
			roi_obj_attr->cat = 1;
			roi_obj_attr->conf = 100;
		}

		determinePkgStatus(status, od_idx, buf_idx, obj_list->obj_num - region_num, obj_list->obj_num,
		                   input.roi_y_avg);
#ifdef CONFIG_SAMPLE_DEMO_PKG_SUPPORT_SEI
		// Mark buffer ready for sending SEI info
		buf_info->buf_ready[buf_idx] = 1;
#endif
	}

	ML_PKG_deleteInstance(&instance);

	return 0;
}
uint8_t isStatusChanged(const ML_PKG_STATUS_S *status, const int region_num, MPI_IVA_OBJ_LIST_S *obj_list)
{
	uint8_t is_status_changed = 0;
	int start = obj_list->obj_num - region_num;
	int end = obj_list->obj_num;

	// // Using status is not reasonable, use motion to check busy or not is more reasonable
	// static ML_PKG_DET_RESULT_E previous_status[MAX_CFG_NUM] = { 0 };
	// for (int i = start; i < end; i++) {
	// 	int idx = i - start;
	// 	if (status->stat[idx].result != previous_status[idx]) {
	// 		is_status_changed = 1;
	// 		break;
	// 	}
	// }

	// for (int i = start; i < end; i++) {
	// 	int idx = i - start;
	// 	previous_status[idx] = status->stat[idx].result;
	// }

	for (int i = start; i < end; i++) {
		int idx = i - start;
		if (status->stat[idx].motion_level != 0) {
			is_status_changed = 1;
			break;
		}
	}
	return is_status_changed;
}
static void handleSigInt(int signo)
{
	if (signo == SIGINT || signo == SIGTERM) {
		g_run_flag = false;
	}
}
