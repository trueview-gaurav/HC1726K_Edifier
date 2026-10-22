#include "json_object.h"
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/time.h>

#include "json.h"
#include "log.h"
#include "mpi_base_types.h"
#include "mpi_dev.h"
#include "mpi_iva.h"
#include "mpi_sys.h"
#include "vftr.h"
#include "vftr_lod.h"

/**
 * If SUPPORT_SEI is defined, the application supports sending
 * inference result to clients via RTSP server.
 *
 * To do so, inter-process communication should be initalized by
 * API AVFTR_initServer().
 */
#ifdef CONFIG_SAMPLE_DEMO_LOD_SUPPORT_SEI
#include "avftr_conn.h"
#endif

#define WAIT_WIN_TIMEOUT 0
#define MAX_CFG_NUM 10

static volatile sig_atomic_t g_run_flag = false;

#ifdef CONFIG_SAMPLE_DEMO_LOD_SUPPORT_SEI
extern AVFTR_VIDEO_CTX_S *vftr_res_shm;

static int findOdCtx(MPI_WIN idx, VIDEO_OD_CTX_S *ctx, int *empty)
{
	int i = 0;
	int find_idx = -1;
	int emp_idx = -1;

	if (empty == NULL) {
		emp_idx = -2;
	} else {
		emp_idx = -1;
	}

	for (i = 0; i < VIDEO_OD_MAX_SUPPORT_NUM; i++) {
		if (find_idx == -1 && ctx[i].idx.value == idx.value && (ctx[i].en || ctx[i].en_implicit)) {
			find_idx = i;
		} else if (emp_idx == -1 && !(ctx[i].en || ctx[i].en_implicit)) {
			emp_idx = i;
		}
	}

	if (empty != NULL) {
		*empty = emp_idx;
	}

	return find_idx;
}

static int clearOdCtx(MPI_WIN idx, VIDEO_OD_CTX_S *ctx)
{
	int ctx_idx = findOdCtx(idx, ctx, NULL);
	if (ctx_idx < 0) {
		log_err("The OD ctx doesn't exist.");
		return -EINVAL;
	}
	memset(&ctx[ctx_idx], 0, sizeof(VIDEO_OD_CTX_S));
	return 0;
}

static int findVftrBufCtx(MPI_WIN idx, const AVFTR_VIDEO_BUF_INFO_S *ctx, int *empty)
{
	int i = 0;
	int find_idx = -1;
	int emp_idx = -1;

	if (empty == NULL) {
		emp_idx = -2;
	} else {
		emp_idx = -1;
	}

	for (i = 0; i < AVFTR_VIDEO_MAX_SUPPORT_NUM; i++) {
		if (find_idx == -1 && ctx[i].idx.value == idx.value && ctx[i].en) {
			find_idx = i;
		} else if (emp_idx == -1 && !ctx[i].en) {
			emp_idx = i;
		}
	}

	if (empty != NULL) {
		*empty = emp_idx;
	}

	return find_idx;
}

static int clearVftrBufCtx(MPI_WIN idx, AVFTR_VIDEO_BUF_INFO_S *info)
{
	int info_idx = findVftrBufCtx(idx, info, NULL);
	if (info_idx < 0) {
		log_err("The VFTR buffer ctx doesn't exist.");
		return -EINVAL;
	}
	memset(&info[info_idx], 0, sizeof(AVFTR_VIDEO_BUF_INFO_S));
	return 0;
}

static int updateBufferIdx(AVFTR_VIDEO_BUF_INFO_S *buf_info, UINT32 timestamp)
{
	buf_info->buf_cur_idx = ((buf_info->buf_cur_idx + 1) % AVFTR_VIDEO_RING_BUF_SIZE);
	buf_info->buf_ready[buf_info->buf_cur_idx] = 0;
	buf_info->buf_time[buf_info->buf_cur_idx] = timestamp;
	buf_info->buf_cur_time = timestamp;

	return buf_info->buf_cur_idx;
}

// If you need to generate SEI, set the process as SEI server.
static int initSeiServer(MPI_WIN win_idx)
{
	MPI_CHN_ATTR_S attr;
	MPI_CHN chn_idx = MPI_VIDEO_CHN(0, win_idx.chn);

	VIDEO_OD_CTX_S *od_ctx;
	int ret;

	ret = AVFTR_initServer();
	if (ret) {
		log_err("Failed to initialize AVFTR server. err: %d", ret);
		return ret;
	}

	ret = MPI_DEV_getChnAttr(chn_idx, &attr);
	if (ret != MPI_SUCCESS) {
		log_err("Failed to get video channel attribute. err: %d", ret);
		return ret;
	}

	/* init OD ctx */
	int empty_idx, set_idx;
	set_idx = findOdCtx(win_idx, vftr_res_shm->od_ctx, &empty_idx);
	if (set_idx >= 0) {
		log_warn("OD is already registered on win(%u, %u, %u).", win_idx.dev, win_idx.chn, win_idx.win);
		od_ctx = &vftr_res_shm->od_ctx[set_idx];
		return 0;
	} else {
		if (empty_idx < 0) {
			log_err("Failed to create OD on win(%u, %u, %u).", win_idx.dev, win_idx.chn, win_idx.win);
			return -ENOMEM;
		}

		od_ctx = &vftr_res_shm->od_ctx[empty_idx];
		od_ctx->en = 1;
		od_ctx->en_implicit = 0;
		od_ctx->en_shake_det = 0;
		od_ctx->en_crop_outside_obj = 0;
		od_ctx->idx = win_idx;
		od_ctx->cb = NULL;
		od_ctx->bdry =
		        (MPI_RECT_POINT_S){ .sx = 0, .sy = 0, .ex = attr.res.width - 1, .ey = attr.res.height - 1 };
	}

	// init vftr buffer ctx
	int buf_info_idx;
	set_idx = findVftrBufCtx(win_idx, vftr_res_shm->buf_info, &empty_idx);
	if (set_idx >= 0) {
		buf_info_idx = set_idx;
	} else if (empty_idx >= 0) {
		buf_info_idx = empty_idx;
	} else {
		log_err("Failed to register vftr buffer ctx on win(%u, %u, %u).", win_idx.dev, win_idx.chn,
		        win_idx.win);
		return -ENOMEM;
	}

	AVFTR_VIDEO_BUF_INFO_S *buf_info = &vftr_res_shm->buf_info[buf_info_idx];
	buf_info->idx = win_idx;
	buf_info->en = 1;

	return 0;
}
static void exitSeiServer(MPI_WIN idx)
{
	clearOdCtx(idx, vftr_res_shm->od_ctx);
	clearVftrBufCtx(idx, vftr_res_shm->buf_info);
	AVFTR_exitServer();
}
#else
// If that's no need to generated SEI, skips the actions.
static int initSeiServer(MPI_WIN win __attribute__((unused)))
{
	return 0;
}
#define exitSeiServer()
#endif

int modifyParam(VFTR_LOD_PARAM_S *output_param, const VFTR_LOD_PARAM_S *input_param)
{
	if (!output_param || !input_param) {
		log_err("Parameters should not be NULL.");
		return -EFAULT;
	}

	output_param->noise_level = input_param->noise_level;
	output_param->region_num = input_param->region_num;
	for (int i = 0; i < input_param->region_num; i++) {
		output_param->roi[i] = input_param->roi[i];
	}
	output_param->event_type = input_param->event_type;
	output_param->duration = input_param->duration;
	output_param->background_merge_delay = input_param->background_merge_delay;
	return 0;
}

static void determineLeftObjectStatus(const VFTR_LOD_STATUS_S *foreground_status, int od_idx, int buf_idx, int start,
                                      int end, UINT16 *y_avg)
{
	VIDEO_OD_CTX_S *od_ctx = &vftr_res_shm->od_ctx[od_idx];

	for (int i = start; i < end; i++) {
		int idx = i - start;
		// char value_str[16];
		// snprintf(value_str, sizeof(value_str), "%d", y_avg[idx]);
		switch (foreground_status->stat[idx].event) {
		case VFTR_LOD_OBJECT_IDLE:
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "NORMAL");
			// snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			//          "IDLE:%s", value_str);
			break;
		case VFTR_LOD_OBJECT_IN:
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "LEFT");
			// snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			//          "IN:%s", value_str);
			break;
		case VFTR_LOD_OBJECT_OUT:
			snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			         "REMOVED");
			// snprintf(od_ctx->ol[buf_idx].obj_attr[i].cat, sizeof(od_ctx->ol[buf_idx].obj_attr[i].cat),
			//          "OUT:%s", value_str);
			log_info("Object is moved out of roi.");
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

int runLeftObjectDetection(MPI_WIN idx, const VFTR_LOD_PARAM_S *lod_input_param, uint8_t *y_avg_cfg_idx)
{
	VFTR_LOD_INSTANCE_S *instance;
	VFTR_LOD_INPUT_S input;
	VFTR_LOD_PARAM_S lod_param;
	uint32_t timestamp = 0;
	int region_num = lod_input_param->region_num;
	input.region_num = region_num;
	int ret = 0;

#ifdef CONFIG_SAMPLE_DEMO_LOD_SUPPORT_SEI
	int od_idx = findOdCtx(idx, vftr_res_shm->od_ctx, NULL);
	int buf_info_idx = findVftrBufCtx(idx, vftr_res_shm->buf_info, NULL);

	VIDEO_OD_CTX_S *od_ctx = &vftr_res_shm->od_ctx[od_idx];
	AVFTR_VIDEO_BUF_INFO_S *buf_info = &vftr_res_shm->buf_info[buf_info_idx];
	MPI_IVA_OBJ_LIST_S *obj_list = malloc(sizeof(MPI_IVA_OBJ_LIST_S));
	VFTR_LOD_STATUS_S tmp_status = { 0 };
	VFTR_LOD_STATUS_S *status = &tmp_status;
	int buf_idx;
#else
	MPI_IVA_OBJ_LIST_S tmp_ol;
	MPI_IVA_OBJ_LIST_S *obj_list = &tmp_ol;
	VFTR_LOD_STATUS_S tmp_status;
	VFTR_LOD_STATUS_S *status = &tmp_status;
	const int buf_idx = 0;
#endif

	VFTR_init(NULL);

	// Create LOD instance
	instance = VFTR_LOD_newInstance();
	if (!instance) {
		log_err("Failed to create LOD instance.");
		return -EINVAL;
	}

	// Get LOD default parameters
	ret = VFTR_LOD_getParam(instance, &lod_param);
	if (ret != 0) {
		log_err("Failed to get CD param. err: %d\n", ret);
		return EXIT_FAILURE;
	}

	// Overwrite default parameters with input parameters
	ret = modifyParam(&lod_param, lod_input_param);
	if (ret != 0) {
		log_err("Failed to modify CD param. err: %d\n", ret);
		return EXIT_FAILURE;
	}

	// Check LOD parameters
	ret = VFTR_LOD_checkParam(&lod_param);
	if (ret != 0) {
		log_err("Invalid CD parameters. err: %d\n", ret);
		return EXIT_FAILURE;
	}

	// Set parameter to LOD instance
	ret = VFTR_LOD_setParam(instance, &lod_param);
	if (ret) {
		log_err("Failed to set LOD parameters.");
		return -EINVAL;
	}

	g_run_flag = true;
	while (g_run_flag) {
		// Wait one video frame processed.
		// This function returns after one frame is done.
		ret = MPI_DEV_waitWin(idx, &timestamp, WAIT_WIN_TIMEOUT);
		if (ret != MPI_SUCCESS) {
			log_err("Failed to waitWin for win: (%d, %d, %d). err: %d", idx.dev, idx.chn, idx.win, ret);
			continue;
		}

#ifdef CONFIG_SAMPLE_DEMO_LOD_SUPPORT_SEI
		buf_idx = updateBufferIdx(buf_info, timestamp);
		obj_list = &od_ctx->ol[buf_idx].basic_list;
#endif

		input.obj_list = obj_list;

		// Continuously get detection result from MPI.
		// If SEI is supported, we write the result into shared memory.
		ret = MPI_IVA_getBitStreamObjList(idx, timestamp, obj_list);
		if (ret != MPI_SUCCESS) {
			log_err("Failed to get object list. err: %d", ret);
			continue;
		}

		for (int i = 0; i < region_num; i++) {
			ret = MPI_DEV_getIspYAvg(idx, y_avg_cfg_idx[i], &input.y_avg[i]);
			if (ret != MPI_SUCCESS) {
				log_err("Get y average %d fail for win: (%d, %d, %d). err: %d", i, idx.dev, idx.chn,
				        idx.win, ret);
				continue;
			}
		}

		// /* for next version with texture */
		// for (int i = 0; i < region_num; i++) {
		// 	ret = MPI_DEV_getIspVar(idx, var_cfg_idx[i], &input.texture_var[i]);
		// 	if (ret != MPI_SUCCESS) {
		// 		log_err("Get texture var %d fail for win: (%d, %d, %d). err: %d", i, idx.dev, idx.chn, idx.win, ret);
		// 		continue;
		// 	}
		// }

		// Send video statistics to LOD algorithm module.
		ret = VFTR_LOD_detect(instance, &input, status);
		if (ret != MPI_SUCCESS) {
			log_err("Failed to detect foreground. err: %d", ret);
			continue;
		}

		for (int i = 0; i < region_num; i++) {
			obj_list->obj_num += 1;
			MPI_IVA_OBJ_ATTR_S *roi_obj_attr = &obj_list->obj[obj_list->obj_num - 1];
			roi_obj_attr->id = 0;
			roi_obj_attr->life = 100;
			roi_obj_attr->rect = lod_input_param->roi[i];
			roi_obj_attr->mv.x = 0;
			roi_obj_attr->mv.y = 0;
			roi_obj_attr->cat = 0;
			roi_obj_attr->conf = 100;
		}

		determineLeftObjectStatus(status, od_idx, buf_idx, obj_list->obj_num - region_num, obj_list->obj_num,
		                          input.y_avg);
#ifdef CONFIG_SAMPLE_DEMO_LOD_SUPPORT_SEI
		// Mark buffer ready for sending SEI info
		buf_info->buf_ready[buf_idx] = 1;
#endif
	}

	VFTR_LOD_deleteInstance(&instance);
	VFTR_exit();

	return 0;
}

static void handleSigInt(int signo)
{
	if (signo == SIGINT || signo == SIGTERM) {
		g_run_flag = false;
	}
}

int parseConfig(const char *file_name, MPI_IVA_OD_PARAM_S *od_param, VFTR_LOD_PARAM_S *lod_param)
{
	json_object *root = NULL;
	json_object *child = NULL;
	json_object *child1 = NULL;
	json_object *child2 = NULL;
	json_object *child3 = NULL;

	// Error is logged by json-c.
	root = (file_name[0] != '\0') ? json_object_from_file(file_name) : json_object_new_object();
	if (!root) {
		root = json_object_new_object();
	}

	// RoI is required parameter.
	if (!json_object_object_get_ex(root, "roi", &child)) {
		log_err("Not found required parameter 'roi' in configuration file.");
		exit(1);
	}

	int roi_cnt = json_object_array_length(child);
	lod_param->region_num = roi_cnt;
	for (int i = 0; i < roi_cnt; i++) {
		child1 = json_object_array_get_idx(child, i);
		if (!child1) {
			log_err("Not found roi %d in configuration file.", i);
			exit(1);
		}

		json_object_object_get_ex(child1, "start", &child2);
		child3 = json_object_array_get_idx(child2, 0);
		lod_param->roi[i].sx = json_object_get_int(child3);
		child3 = json_object_array_get_idx(child2, 1);
		lod_param->roi[i].sy = json_object_get_int(child3);

		json_object_object_get_ex(child1, "end", &child2);
		child3 = json_object_array_get_idx(child2, 0);
		lod_param->roi[i].ex = json_object_get_int(child3);
		child3 = json_object_array_get_idx(child2, 1);
		lod_param->roi[i].ey = json_object_get_int(child3);
	}

	if (json_object_object_get_ex(root, "duration", &child)) {
		lod_param->duration = json_object_get_int(child);
	} else {
		json_object_object_add(root, "duration", json_object_new_int(lod_param->duration));
	}

	if (json_object_object_get_ex(root, "background_merge_delay", &child)) {
		lod_param->background_merge_delay = json_object_get_int(child);
	} else {
		json_object_object_add(root, "background_merge_delay",
		                       json_object_new_int(lod_param->background_merge_delay));
	}

	if (json_object_object_get_ex(root, "noise_level", &child)) {
		lod_param->noise_level = json_object_get_int(child);
	} else {
		json_object_object_add(root, "noise_level", json_object_new_int(lod_param->noise_level));
	}

	if (json_object_object_get_ex(root, "od_qual", &child)) {
		od_param->od_qual = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_qual", json_object_new_int(od_param->od_qual));
	}

	if (json_object_object_get_ex(root, "od_track_refine", &child)) {
		od_param->od_track_refine = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_track_refine", json_object_new_int(od_param->od_track_refine));
	}

	if (json_object_object_get_ex(root, "od_size_th", &child)) {
		od_param->od_size_th = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_size_th", json_object_new_int(od_param->od_size_th));
	}

	if (json_object_object_get_ex(root, "od_sen", &child)) {
		od_param->od_sen = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_sen", json_object_new_int(od_param->od_sen));
	}

	if (json_object_object_get_ex(root, "en_stop_det", &child)) {
		od_param->en_stop_det = json_object_get_boolean(child);
	} else {
		json_object_object_add(root, "en_stop_det", json_object_new_boolean(od_param->en_stop_det));
	}

	printf("%s\n", json_object_to_json_string(root));
	json_object_put(root);

	return 0;
}

void help(const char *name)
{
	printf("Usage: %s -i [options] ...\n"
	       "Options:\n"
	       "  -i <file>            LOD parameter in .json format.\n"
	       "  -c <channel>         Specify which video channel to use. (Default 0).\n"
	       "  -w <window>          Specify which video window to use. (Default 0).\n"
	       "\n"
	       "Example:\n"
	       "  $ mpi_stream -d /system/mpp/case_config/case_config_1001_FHD &\n"
	       "  $ %s -i /system/mpp/lod_config/lod_conf_1.json &\n"
#ifdef CONFIG_SAMPLE_DEMO_LOD_SUPPORT_SEI
	       "  $ testOnDemandRTSPServer 0 -S\n",
#else
	       "  $ testOnDemandRTSPServer 0 -n\n",
#endif
	       name, name);
}

int main(int argc, char **argv)
{
	MPI_WIN win_idx = MPI_VIDEO_WIN(0, 0, 0);

	MPI_ISP_Y_AVG_CFG_S y_avg_cfg[MAX_CFG_NUM];
	for (int i = 0; i < MAX_CFG_NUM; i++) {
		y_avg_cfg[i].roi.sx = 0;
		y_avg_cfg[i].roi.sy = 0;
		y_avg_cfg[i].roi.ex = 0;
		y_avg_cfg[i].roi.ey = 0;
		y_avg_cfg[i].diff_thr = 0;
	}

	/* for next version with texture */
	// MPI_ISP_VAR_CFG_S var_cfg[MAX_CFG_NUM];
	// for (int i = 0; i < MAX_CFG_NUM; i++) {
	// 	var_cfg[i].roi.sx = 0;
	// 	var_cfg[i].roi.sy = 0;
	// 	var_cfg[i].roi.ex = 0;
	// 	var_cfg[i].roi.ey = 0;
	// }

	MPI_IVA_OD_PARAM_S od_param = {
		.od_qual = 46,
		.od_track_refine = 42,
		.od_size_th = 40,
		.od_sen = 254,
		.en_stop_det = 0,
		.en_gmv_det = 0,
	};

	// RoI attribute must be load from config file.
	VFTR_LOD_PARAM_S lod_param = {
		.noise_level = 5,
		.region_num = 1,
		.roi[0] = { .sx = 0, .sy = 0, .ex = 0, .ey = 0 },
		.event_type = 0,
		.duration = 0,
		.background_merge_delay = 50000,
	};

	int c;
	const char *config_fname = NULL;
	uint8_t y_avg_cfg_idx[MAX_CFG_NUM];
	// uint8_t var_cfg_idx;	/* for next version with texture */
	int err;

	while ((c = getopt(argc, argv, "i:c:w:h")) != -1) {
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

		case 'h':
			help(argv[0]);
			return EXIT_SUCCESS;

		default:
			help(argv[0]);
			return EXIT_FAILURE;
		}
	}

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

	parseConfig(config_fname, &od_param, &lod_param);

	fprintf(stderr, "region_num: %d\n", lod_param.region_num);
	for (int i = 0; i < lod_param.region_num; i++) {
		y_avg_cfg[i].roi = lod_param.roi[i];
		// var_cfg[i].roi = lod_param.roi[i];	/* for next version with texture */
		fprintf(stderr, "y_avg_cfg[%d].roi: (%d, %d, %d, %d)\n", i, y_avg_cfg[i].roi.sx, y_avg_cfg[i].roi.sy,
		        y_avg_cfg[i].roi.ex, y_avg_cfg[i].roi.ey);
	}

	// First, initialize MPI system to access video pipeline.
	err = MPI_SYS_init();
	if (err != MPI_SUCCESS) {
		return EXIT_FAILURE;
	}

	// Then, set OD attribute and start OD threading.
	// For system wide, OD threading can be activated only once.
	err = MPI_IVA_setObjParam(win_idx, &od_param);
	if (err != MPI_SUCCESS) {
		log_err("Failed to set OD param. err: %d", err);
		goto error;
	}

	/* Check parameters */
	err = VFTR_LOD_checkParam(&lod_param);
	if (err) {
		log_err("Invalid LOD parameters. err: %d", err);
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

	for (int i = 0; i < lod_param.region_num; i++) {
		err = MPI_DEV_addIspYAvgCfg(win_idx, &y_avg_cfg[i], &y_avg_cfg_idx[i]);
		if (err != MPI_SUCCESS) {
			log_err("Failed to add ISP Y average config. err: %d", err);
			goto error;
		}
	}

	/* for next version with texture */
	// err = MPI_DEV_addIspVarCfg(win_idx, &var_cfg, &var_cfg_idx);
	// if (err != MPI_SUCCESS) {
	// 	log_err("Failed to add Isp Var average config. err: %d", err);
	// 	return err;
	// }

	runLeftObjectDetection(win_idx, &lod_param, y_avg_cfg_idx);

error:

	/* for next version with texture */
	// err = MPI_DEV_rmIspVarCfg(win_idx, var_cfg_idx);
	// if (err != MPI_SUCCESS) {
	// 	log_err("Failed to remove ISP Var average config. err: %d", err);
	// }

	for (int i = 0; i < lod_param.region_num; i++) {
		err = MPI_DEV_rmIspYAvgCfg(win_idx, y_avg_cfg_idx[i]);
		if (err != MPI_SUCCESS) {
			log_err("Failed to remove ISP Y average config. err: %d", err);
		}
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
