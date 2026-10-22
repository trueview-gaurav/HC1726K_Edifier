#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>

#include <fcntl.h>

#include <unistd.h>
#include <sys/stat.h>

#include "mpi_enc.h"

#include "parse.h"
#include "sample_stream.h"
#include "sample_light_src.h"
#include "sample_dip.h"
#include "sample_osd.h"
#include "sample_utils.h"
#include "sample_ctrl.h"
#include "sample_publisher.h"
#include "gpio.h"
#ifdef CB_BASED_OD
#include "sample_od.h"
#endif

#include "sample_venc_extend.h"

#include "utlist.h"

APP_CONF_S g_conf;
VencExtendInfo *g_vencExtendInfo = NULL;
static pthread_t gthreadAovDetect;
extern sem_t g_semAov;
extern int g_AovRun;

#ifdef CB_BASED_OD
ML_CB_CTX_S *cb_ctx;
#endif
/**
 * @brief Set global flag g_bsb_run[] as 0 when SIGINT or SIGTERM is received.
 */
static void sigintHandler(int signo)
{
	if (signo == SIGINT) {
		printf("[mpi_stream] Caught SIGINT!\n");
	} else if (signo == SIGTERM) {
		printf("[mpi_stream] Caught SIGTERM!\n");
	} else {
		perror("[mpi_stream] Unexpected signal!\n");
		exit(1);
	}

	SAMPLE_signalAllStreamThreadToShutdown();
	SAMPLE_signalAllAudioThreadToShutdown();
}

/**
 * @brief Transform setting based on application spec.
 */
static void adjustConf(SAMPLE_CONF_S *conf)
{
	MPI_CHN_LAYOUT_S *layout;
	MPI_CHN_ATTR_S *attr;
	int i, j, k;

	for (i = 0; i < MPI_MAX_VIDEO_DEV_NUM; i++) {
		/**
		 * Update member field 'path' in struct MPI_DEV_ATTR_S
		 *
		 * path<N>_en must be set as 1 when you want to read image
		 * signal from path<N>.
		 */
		conf->dev[i].attr.path.bit.path0_en = conf->dev[i].path[0].enable;
		conf->dev[i].attr.path.bit.path1_en = conf->dev[i].path[1].enable;
		conf->dev[i].attr.path.bit.path2_en = conf->dev[i].path[2].enable;
		conf->dev[i].attr.path.bit.path3_en = conf->dev[i].path[3].enable;

		/**
		 * Generate path to PCA setting file.
		 * Similar to the default .ini file, but without flexibility to change the target path.
		 */
		for (j = 0; j < MPI_MAX_INPUT_PATH_NUM; j++) {
			snprintf(conf->dev[i].path[j].pca_file, PATH_MAX - 1, "%s/pca_cal_%d.lut", DIP_FILE_PATH, j);
		}

		/**
		 * Transfrom video channel layout from ratio (max: 1024) to absolute coordinate.
		 * The coordinate of right bottom corder should not run over 1024.
		 */
		for (j = 0; j < MPI_MAX_VIDEO_CHN_NUM; j++) {
			attr = &conf->dev[i].chn[j].attr;
			layout = &conf->dev[i].chn[j].layout;

			for (k = 0; k < layout->window_num; k++) {
				layout->win_id[k] = MPI_VIDEO_WIN(i, j, k);

				assert(layout->window[k].x <= 1024);
				assert(layout->window[k].y <= 1024);
				assert(layout->window[k].x + layout->window[k].width <= 1024);
				assert(layout->window[k].y + layout->window[k].height <= 1024);
				layout->window[k] = SAMPLE_toMpiLayoutWindow(&layout->window[k], &attr->res);
			}
		}

		/* Initialize the venc_extend ini files if they exist */

		for (int enc_chn_idx = 0; enc_chn_idx < MPI_MAX_ENC_CHN_NUM; ++enc_chn_idx) {
			/*Check the encoder channel is enable or not*/
			if (conf->enc_chn[enc_chn_idx].enable != 1) {
				continue;
			}

			UINT8 enc_chn = conf->enc_chn[enc_chn_idx].bind.idx.chn;
			UINT32 enc_chn_path = conf->dev->chn[enc_chn].win[0].path.bmp;
			VencExtendInfo *vencExtendInfo = (VencExtendInfo *)malloc(sizeof(VencExtendInfo));
			vencExtendInfo->venc_extend[SRC_TYPE_DAY][0] = '\0';
			vencExtendInfo->venc_extend[SRC_TYPE_IR][0] = '\0';
			vencExtendInfo->venc_extend[SRC_TYPE_LIGHT][0] = '\0';
			vencExtendInfo->chn = MPI_ENC_CHN(enc_chn);

			snprintf(vencExtendInfo->venc_extend[SRC_TYPE_DAY], PATH_MAX, "%s/venc_extend_%d.ini",
			         DIP_FILE_PATH, enc_chn_idx);

			switch (enc_chn_path) {
			case 1:
				/* bmp = 0001, path = 0 */
				vencExtendInfo->path = MPI_INPUT_PATH(i, 0);
				break;
			case 2:
				/* bmp = 0010, path = 1 */
				vencExtendInfo->path = MPI_INPUT_PATH(i, 1);
				break;
			case 4:
				/* bmp = 0100, path = 2 */
				vencExtendInfo->path = MPI_INPUT_PATH(i, 2);
				break;
			default:
				break;
			}

			if (access(vencExtendInfo->venc_extend[SRC_TYPE_DAY], R_OK) != 0) {
				memset(vencExtendInfo->venc_extend[SRC_TYPE_DAY], 0, PATH_MAX * sizeof(char));
			}

#ifdef MULTIPLE_IQ_SUPPORT
			snprintf(vencExtendInfo->venc_extend[SRC_TYPE_IR], PATH_MAX, "%s/venc_extend_ir_%d.ini",
			         DIP_FILE_PATH, enc_chn_idx);
			if (access(vencExtendInfo->venc_extend[SRC_TYPE_IR], R_OK) != 0) {
				snprintf(vencExtendInfo->venc_extend[SRC_TYPE_IR], PATH_MAX, "%s",
				         vencExtendInfo->venc_extend[SRC_TYPE_DAY]);
			}

			snprintf(vencExtendInfo->venc_extend[SRC_TYPE_LIGHT], PATH_MAX, "%s/venc_extend_light_%d.ini",
			         DIP_FILE_PATH, enc_chn_idx);
			if (access(vencExtendInfo->venc_extend[SRC_TYPE_LIGHT], R_OK) != 0) {
				snprintf(vencExtendInfo->venc_extend[SRC_TYPE_LIGHT], PATH_MAX, "%s",
				         vencExtendInfo->venc_extend[SRC_TYPE_DAY]);
			}
#endif
			LL_APPEND(g_vencExtendInfo, vencExtendInfo);
		}
	}

	if (conf->casegen.show_params) {
		VencExtendInfo *venc_item_debug, *venc_tmp_debug;
		LL_FOREACH_SAFE(g_vencExtendInfo, venc_item_debug, venc_tmp_debug)
		{
			printf("[mpi_stream] path%d chn%d : \n\t%s + %s + %s \n", venc_item_debug->path.path,
			       venc_item_debug->chn.chn, venc_item_debug->venc_extend[0],
			       venc_item_debug->venc_extend[1], venc_item_debug->venc_extend[2]);
		}
		printf("NULL\n");
	}
}

/**
 * @brief Remove the signal file.
 * @param[in] signal_file The path of signal file.
 * @return The execution result.
 * @retval 0      success
 * @retval others unexpected failure
 */
static int removeSignalFile(const char *signal_file)
{
	if (access(signal_file, F_OK) == 0) {
		if (remove(signal_file) != 0) {
			// Failed to remove the signal file
			return -1;
		}
	}
	return 0;
}

/**
 * @brief Create a signal file to notify success.
 * @param[in] signal_file The path of signal file.
 * @return The execution result.
 * @retval 0      success
 * @retval others unexpected failure
 */
static int createSignalFile(const char *signal_file)
{
	pid_t pid = 0;
	char buf[7] = { 0 }; // Augentix Max. pid is 4096. But general Max. pid is 32768, 5+1(\n)+1(\0) bytes is enough.
	int len = 0;

	int fd = open(signal_file, O_CREAT | O_EXCL | O_WRONLY, 0666);
	if (fd < 0) {
		// Failed to create the signal file
		return -1;
	}

	pid = getpid(); // obtain current PID
	len = snprintf(buf, sizeof(buf), "%d\n", pid);

	if (write(fd, buf, len) != len) {
		close(fd);
		return -1;
	}

	close(fd);
	return 0;
}

/**
 * @brief Entry point of streaming.
 * @param[in] conf Pointer to the video streaming configuration
 * @return The execution result.
 * @retval 0      success
 * @retval others unexpected failure
 */
static int streaming(const APP_CONF_S *conf)
{
	MPI_PATH path_idx;
	MPI_ECHN echn_idx;
	const int sleepTime_us = 300000;
	int idx = 0;
	int ret;
	int dip_path_cnt = 0;
	const SAMPLE_CONF_S *sample_conf = &conf->sample_conf;
	const char *signal_file = "/run/mpi_stream.pid";

	ret = removeSignalFile(signal_file);
	if (removeSignalFile(signal_file) != 0) {
		fprintf(stderr, "[mpi_stream] Remove signal file failed. err: %d\n", ret);
		return ret;
	}

	/** Step 1. Initialize MPP system for the process. */
	ret = MPI_SYS_init();
	if (ret != MPI_SUCCESS) {
		fprintf(stderr, "[mpi_stream] Initialize system failed. err: %d\n", ret);
		return ret;
	}

	/** Step 2. Create and configure video pipeline. */
	ret = SAMPLE_createVideoPipeline(&conf->sample_conf);
	if (ret != MPI_SUCCESS) {
		return ret;
	}

	/** Step 3. Create thread to update DIP attributes when sensor IQ file is modified. */
	/** Step 3.1 Determine how many ini update threads are needed */
	if (conf->sample_conf.dev[0].stitch.enable) {
		// We only allow stitching 2 sensors into a single video path, and no more.
		dip_path_cnt = 1;
	} else {
		for (idx = 0; idx < MPI_MAX_INPUT_PATH_NUM; idx++) {
			if (conf->sample_conf.dev[0].path[idx].enable) {
				dip_path_cnt++;
			}
		}
	}

	/** Step 3.2 Create ini update threads for each input path */
	for (idx = 0; idx < dip_path_cnt; idx++) {
		path_idx = MPI_INPUT_PATH(0, idx);
		const CONF_PATH_PARAM_S *path_param = &conf->sample_conf.dev[0].path[idx];
		VencExtendInfo *l_vencExtendInfo = g_vencExtendInfo;
		char *ini_path = NULL;
		char *dip_extend_ini_path = NULL;
		/** whether support multiple iq or not, day lightSrc always created. */
		LightSrc *item, *tmp;

#ifdef MULTIPLE_IQ_SUPPORT
		/** off all light src */
		LL_FOREACH_SAFE(conf->head[idx], item, tmp)
		{
			if ((item->off != NULL) && (item->private != NULL)) {
				item->off(item->private);
			}
		}
		char req_name[NAME_MAX] = { '0' };
		SAMPLE_detectLightSrcOnce(path_idx, conf->detection[idx], req_name, NAME_MAX);

		if (strcmp(req_name, "0") == 0) {
			snprintf(req_name, NAME_MAX, "%s", "day");
		}

		fprintf(stdout, "\n[mpi_stream] SAMPLE_detectLightSrcOnce() success, mode name is %s\n", req_name);

		LL_FOREACH_SAFE(conf->head[idx], item, tmp)
		{
			if (strcmp(item->name, req_name) == 0) {
				snprintf(conf->detection[idx]->curr_name, NAME_MAX, "%s", req_name);
				ini_path = (char *)item->sensor_path;
				dip_extend_ini_path = (char *)item->dip_extend_path;
				break;
			}
		}

#else
		LL_FOREACH_SAFE(conf->head[idx], item, tmp)
		{
			if (strcmp(item->name, "day") == 0) {
				ini_path = (char *)item->sensor_path;
				dip_extend_ini_path = (char *)item->dip_extend_path;
				break;
			}
		}
#endif

		if (access(ini_path, R_OK) != 0) {
			fprintf(stderr, "[mpi_stream] Unfound default ini file:%s", ini_path);
			goto stop_video_pipeline;
		}

		if (!dip_extend_ini_path || access(dip_extend_ini_path, R_OK) != 0) {
			fprintf(stdout, "Unfound default dip_extend ini file , not going to update dip_extend\n");
			dip_extend_ini_path = NULL;
		}

		ret = SAMPLE_updateDipAttrOnce(path_idx, (const char *)ini_path, dip_extend_ini_path);
		if (ret != 0) {
			return ret;
		}

		ret = SAMPLE_initVencExtendInfo(l_vencExtendInfo);
		if (ret != MPI_SUCCESS) {
			fprintf(stderr, "SAMPLE_initVencExtendInfo() failed\n");
		}
#ifdef DIP_UPDATE_ENABLE
		ret = SAMPLE_createDipAttrUpdateThread(path_idx, (const char *)ini_path, dip_extend_ini_path);
		if (ret != 0) {
			return ret;
		}
#else
		(void)(path_idx);
		(void)(ini_path);
		(void)(dip_extend_ini_path);
#endif /*< DIP_UPDATE_ENABLE */
		if (access(path_param->pca_file, R_OK) == 0) {
			ret = SAMPLE_updatePca(path_idx, path_param->pca_file);
			if (ret != 0) {
				fprintf(stderr, "[mpi_stream] Unable to set PCA settings, err: %d\n", ret);
			}
		}

#ifdef MULTIPLE_IQ_SUPPORT
		/** off all light src */
		LL_FOREACH_SAFE(conf->head[idx], item, tmp)
		{
			if ((item->off != NULL) && (item->private != NULL)) {
				item->off(item->private);
			}
		}

		/** Step 3.3 */
		if (conf->head[idx] && conf->detection[idx]) {
			ret = SAMPLE_createLightSrcDetectionThread(path_idx, conf->head[idx], conf->detection[idx]);
			if (ret != 0) {
				return ret;
			}
		} else {
			fprintf(stderr, "[mpi_stream] detect thread not create");
		}
#endif
	}

	/** Step 3.3 Optional feature: Update dip window attr for sub-stream */
	for (idx = 0; idx < MPI_MAX_VIDEO_CHN_NUM; idx++) {
		if (conf->sample_conf.dev[0].chn[idx].enable) {
			SAMPLE_updateChnDipAttr(MPI_VIDEO_CHN(0, idx), conf->window_path);
		}
	}

#ifdef OSD_ENABLE
	MPI_CHN chn_idx;
	UINT32 output_num;
	UINT16 width;
	UINT16 height;
	/** Step 4 Optional feature: Create OSDs on video */
	if (conf->sample_conf.osd_visible) {
		SAMPLE_initOsd();

		if (sample_conf->casegen.aov_en) {
			SAMPLE_installAovFont();
		}

		output_num = 0;
		for (idx = 0; idx < MPI_MAX_VIDEO_CHN_NUM; idx++) {
			if (conf->sample_conf.dev[0].chn[idx].enable) {
				output_num++;
			}
		}

		for (idx = 0; idx < MPI_MAX_VIDEO_CHN_NUM; idx++) {
			if (!conf->sample_conf.dev[0].chn[idx].enable) {
				continue;
			}

			width = conf->sample_conf.dev[0].chn[idx].attr.res.width;
			height = conf->sample_conf.dev[0].chn[idx].attr.res.height;

			chn_idx = MPI_VIDEO_CHN(0, idx);
			ret = SAMPLE_createOsd(conf->sample_conf.osd_visible, chn_idx, output_num, width, height);
			if (ret != MPI_SUCCESS) {
				fprintf(stderr, "[mpi_stream] Create OSD on channel %d failed. err: %d\n",
				        MPI_GET_VIDEO_CHN(chn_idx), ret);
				return ret;
			}
		}

		if (!sample_conf->casegen.aov_en)
			SAMPLE_createOsdUpdateThread();
	}
#endif /*< OSD_ENABLE */

#ifdef CB_BASED_OD
	/** Step 5. Optional feature: Register OD CallBack Function

	 * Register the custom AI algorithm for Object Detection.
	 * The default MV-based OD will be executed if not registered.
	 */
	MPI_IVA_OD_CALLBACK_S cb;
	cb_ctx = calloc(1, sizeof(ML_CB_CTX_S));

	for (uint8_t i = 0; i < MPI_MAX_VIDEO_DEV_NUM; i++) {
		for (uint8_t j = 0; j < MPI_MAX_VIDEO_CHN_NUM; j++) {
			if (conf->sample_conf.dev[i].chn[j].enable)
				for (uint8_t k = 0; k < conf->sample_conf.dev[i].chn[j].layout.window_num; k++) {
					SAMPLE_OD_registerCallback(MPI_VIDEO_WIN(i, j, k), &cb);
					MPI_IVA_regOdCallback(MPI_VIDEO_WIN(i, j, k), &cb, cb_ctx);
				}
		}
	}
#endif /*< CB_BASED_OD */

	/**
	 * Step 6. Create bit-stream channel to pull frames.
	 *
	 * After video pipeline is started, you can get frames from desired
	 * encoder (ECHN) channel via bit-stream channel (BCHN).
	 * To do so, User should initialize bit stream system first.
	 */

	MPI_initBitStreamSystem();

	/**
	 * Step 7. Create bit-stream channel and pull frames continuously.
	 *
	 * For each encoder, we create 1 thread for getting frames from it.
	 *
	 * Then, main thread monitors global flag 'g_bsb_run[]' and sleep
	 * if you need streaming. The threads will join to main thread
	 * when it satisfy the conditions to end.
	 *  - UDP stream does not be enabled and write enough frames to file, or
	 *  - Receives SIGINT or SIGTERM.
	 *
	 * It's recommended to create BCHN before starting to run video pipline.
	 * When a frame is encoded, its bit-stream will be droped if there are no BCHN readers.
	 */

	for (idx = 0; idx < MPI_MAX_ENC_CHN_NUM; idx++) {
		if (!conf->sample_conf.enc_chn[idx].enable) {
			continue;
		}

		echn_idx = MPI_ENC_CHN(idx);
		printf("[mpi_stream] Start get stream from channel %d\n", idx);
		ret = SAMPLE_startStreamPublisher(echn_idx, &conf->sample_conf.bitstream[idx], conf->reservation_level,
		                                  conf->recycle_level,
		                                  conf->sample_conf.bitstream[idx].record.sync_with_audio);

		if (ret != MPI_SUCCESS) {
			return ret;
		}
	}
	if (conf->sample_conf.audio.enable) {
		ret = SAMPLE_startAudioPublisher(&conf->sample_conf.audio, conf->reservation_level,
		                                 conf->recycle_level);
		if (ret != 0) {
			return ret;
		}
	}

	/** Step 8. Start to run video pipeline. */
	ret = SAMPLE_startStream(&conf->sample_conf);
	if (ret == MPI_SUCCESS) {
		if (createSignalFile(signal_file) != 0) {
			fprintf(stderr, "[mpi_stream] Create signal file failed.\n");
			// Not return error even signal file creation failed.
			// Fastboot script will retry 2s only.
		}
	} else if (ret == -EAGAIN) {
		goto stop_osd;
	} else {
		return ret;
	}

	/** Step 9. Check if AOV enabled. */
	if (sample_conf->casegen.aov_en) {
		printf("Setup AOV, wake src=%d, sleep period=%d ms\n",
			sample_conf->casegen.aov_src, sample_conf->casegen.aov_period_ms);

		// use a semaphore to control AOV for long polling interval
		if (sem_init(&g_semAov, 0, 0) == 0) {
			CONF_CASE_GEN_PARAM aov_conf = conf->sample_conf.casegen;
			g_AovRun = 1;
			ret = pthread_create(&gthreadAovDetect, NULL, (void *)ThreadAovDetect, (void *)&aov_conf);
			if (ret) {
				printf("Failed to create OSDUpdate thread! err: %d\n", ret);
				sem_destroy(&g_semAov);
				g_AovRun = 0;
				// return ret;
			}
		} else {
			printf("Failed to create AOV semaphore! Stop AOV\n");
		}
	}

	/** The loop will be break if global flags in array 'g_bsb_run[]' are reset as 0. */
	do {
		usleep(sleepTime_us);
	} while (SAMPLE_hasAnyPublisherThreadActive());

	/**
	 * When streaming is no need anymore, User should release the MPP resources
	 * properly. Generally you need to stop streaming, suspend video pipeline and
	 * destroy them, just do the actions with the reverse order of construction
	 * phase.
	 */

	if (g_AovRun) {
		sem_post(&g_semAov);
		g_AovRun = 0;
		pthread_join(gthreadAovDetect, NULL);
		sem_destroy(&g_semAov);
	}

	for (idx = 0; idx < MPI_MAX_ENC_CHN_NUM; idx++) {
		if (!conf->sample_conf.enc_chn[idx].enable) {
			continue;
		}

		echn_idx = MPI_ENC_CHN(idx);
		SAMPLE_shutdownStreamPublisher(echn_idx);
	}

	SAMPLE_shutdownAudioPublisher();

	MPI_exitBitStreamSystem();
	SAMPLE_stopStream(&conf->sample_conf);

stop_osd:
#ifdef OSD_ENABLE
	if (conf->sample_conf.osd_visible) {
		/** Optional feature: Destruct OSDs after they're no needed anymore. */
		SAMPLE_destroyOsdUpdateThread();

		for (idx = 0; idx < MPI_MAX_VIDEO_CHN_NUM; idx++) {
			if (!conf->sample_conf.dev[0].chn[idx].enable) {
				continue;
			}

			chn_idx = MPI_VIDEO_CHN(0, idx);
			ret = SAMPLE_stopOsd(chn_idx);
			if (ret != MPI_SUCCESS) {
				fprintf(stderr, "[mpi_stream] Stop OSD %d failed. err: %d\n",
				        MPI_GET_VIDEO_CHN(chn_idx), ret);
				return ret;
			}
		}

		SAMPLE_freeOsdResources();
	}
#endif /*< OSD_ENABLE */

	/** Close ini update thread and recycle peripheral functions */
	for (idx = 0; idx < dip_path_cnt; idx++) {
		path_idx = MPI_INPUT_PATH(0, idx);
#ifdef DIP_UPDATE_ENABLE
		SAMPLE_destroyDipAttrUpdateThread(path_idx);
#else
		(void)(path_idx);
#endif /*< DIP_UPDATE_ENABLE */

#ifdef MULTIPLE_IQ_SUPPORT
		SAMPLE_destroyLightSrcDetectionThread(path_idx);
#endif
	}

stop_video_pipeline:
	SAMPLE_destroyVideoPipeline(&conf->sample_conf);

#ifdef CB_BASED_OD
	if (cb_ctx) {
		free(cb_ctx);
	}
#endif

	ret = MPI_SYS_exit();
	if (ret != MPI_SUCCESS) {
		fprintf(stderr, "[mpi_stream] Exit system failed. err: %d\n", ret);
		return ret;
	}

	return 0;
}

void deinitVencExtendInfo(VencExtendInfo **head)
{
	SAMPLE_deinitVencExtendInfo();

	VencExtendInfo *item, *test;
	LL_FOREACH_SAFE(*head, item, test)
	{
		LL_DELETE(*head, item);
		free(item);
	}
	*head = NULL;
}

int main(int argc, char **argv)
{
	int ret;

	/**
	 * Parse cmdargs then store to variable 'conf'. Then, print config
	 * to console if needed.
	 */

	initConf(&g_conf);

	if (!parseCmdArgs(argc, argv, &g_conf)) {
		return -1;
	}

	adjustConf(&g_conf.sample_conf);
	if (g_conf.sample_conf.casegen.show_params) {
		printConf(&g_conf.sample_conf);
	}

	/** Set signal handler. */

	if (signal(SIGINT, sigintHandler) == SIG_ERR) {
		perror("Cannot handle SIGINT!\n");
		exit(1);
	}

	if (signal(SIGTERM, sigintHandler) == SIG_ERR) {
		perror("Cannot handle SIGTERM!\n");
		exit(1);
	}

	/** Configure, start video pipeline then get frames continuously. */

	ret = streaming(&g_conf);
	if (ret != 0) {
		return EXIT_FAILURE;
	}

	deinitConf(&g_conf);
	deinitVencExtendInfo(&g_vencExtendInfo);

	printf("\n");

	return 0;
}
