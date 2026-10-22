#include "sample_ctrl.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#include "mpi_enc.h"

#include "sample_stream.h"
#include "sample_utils.h"
#include "sample_osd.h"
#include "mpi_dip_alg.h"


#define SAMPLE_VIDEO_CHN_IDX_EQUAL(a, b) (((a).dev == (b).dev) && (a).chn == (b).chn)

#if defined(AOV_BLOCK_BY_OBJECT)
#include "od_shm_protocol.h"
//#define OD_AOV_DEBUG
static od_shm_data_t *g_od_shm = NULL;
static unsigned int g_last_seq = 0; // Local buffer to track the last processed sequence number

int init_od_shm_reader(void)
{
	/* * Use O_CREAT | O_RDWR instead of just O_RDONLY.
     * This ensures the SHM file is created even if the Reader starts first.
     */
    int fd = shm_open(OD_SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        // Maybe od_demo hasn't started yet
        return -1; 
    }

	/* * ftruncate is safe to call even if the file already exists.
     * It ensures the size is exactly 64 bytes.
     */
	 if (ftruncate(fd, OD_SHM_SIZE) == -1) {
        close(fd);
        return -1;
    }

	g_od_shm = (od_shm_data_t *)mmap(NULL, OD_SHM_SIZE, 
		PROT_READ | PROT_WRITE, 
		MAP_SHARED, fd, 0);
    
    if (g_od_shm == MAP_FAILED) {
        close(fd);
        g_od_shm = NULL;
        return -1;
    }

    close(fd);
    return 0;
}


/**
 * Release Shared Memory resources for the Reader.
 */
void exit_od_shm_reader(void)
{
    if (g_od_shm != NULL && g_od_shm != MAP_FAILED) {
        if (munmap(g_od_shm, OD_SHM_SIZE) == -1) {
            /* Using standard perror, replace with log_err if preferred */
            perror("munmap reader");
        }
        g_od_shm = NULL;
    }
}

static int check_od_and_block_aov(int *cnt)
{
    if (!g_od_shm)
        return 0;

    int is_detected = g_od_shm->detect_flag;

#if defined(OD_AOV_DEBUG)
	int count = g_od_shm->obj_num;
    char local_name[OD_NAME_MAX_LEN];
	
    strncpy(local_name, g_od_shm->od_name, OD_NAME_MAX_LEN - 1);
    local_name[OD_NAME_MAX_LEN - 1] = '\0';
	
	fprintf(stderr,"[READ] shm=%p\n", g_od_shm);
    fprintf(stderr,
        "[AOV][OD] detect=%d, obj_num=%d, cat=%s\n",
        is_detected, count, local_name);
#endif

    if (is_detected) {
#if defined(OD_AOV_DEBUG)
        fprintf(stderr,
            "[AOV] Object detected (%d items, %s), holding system active.\n",
            count, local_name);
#endif
        *cnt = 0;
        return 1;  // block AOV
    }

    return 0;  // allow AOV
}

#endif

sem_t g_semAov;
int g_AovRun = 0;

static int disableOsd(const SAMPLE_CONF_S *conf)
{
	int err = 0;
	/** Stop all OSD */
	SAMPLE_destroyOsdUpdateThread();

	for (int i = 0; i < MPI_MAX_VIDEO_CHN_NUM; i++) {
		if (!conf->dev[0].chn[i].enable) {
			continue;
		}

		err = SAMPLE_stopOsd(MPI_VIDEO_CHN(0, i));
		assert(err == 0);
	}

	/**
	 * native: free font, logo ptr
	 * libosd: OSD_destroy
	 */
	SAMPLE_freeOsdResources();

	return err;
}

static int enableOsd(const SAMPLE_CONF_S *conf)
{
	int err = 0;
	/** Add OSD back to video channels */
	UINT32 output_num = 0;
	UINT16 width = 0;
	UINT16 height = 0;
	MPI_ENC_CHN_ATTR_S enc_attr;

	/**
	 * native: load font, logo resource
	 * libosd: OSD_init
	 */
	SAMPLE_initOsd();

	for (int i = 0; i < MPI_MAX_VIDEO_CHN_NUM; i++) {
		if (conf->dev[0].chn[i].enable) {
			output_num++;
		}
	}

	for (int i = 0; i < MPI_MAX_VIDEO_CHN_NUM; i++) {
		if (!conf->dev[0].chn[i].enable) {
			continue;
		}
		/** chn resolution maybe changed, not same to case_config */
		err = MPI_ENC_getChnAttr(MPI_ENC_CHN(i), &enc_attr);
		assert(err == 0);

		width = enc_attr.res.width;
		width = enc_attr.res.height;

		err = SAMPLE_createOsd(conf->osd_visible, MPI_VIDEO_CHN(0, i), output_num, width, height);
		assert(err == 0);
	}

	SAMPLE_createOsdUpdateThread();

	return err;
}

static int g_wake_fd = -1;
static int g_state_fd = -1;

/**
 * @brief Pre-open sysfs fds
 *
 * Must be called while /sys is still reachable.
 *
 * @retval  0   both fds opened successfully
 * @retval -1   at least one fd could not be opened (both are closed on error)
 */
static int initAoVFd(void)
{
	g_wake_fd = open("/sys/devices/system/augentix-core/wake", O_WRONLY);
	if (g_wake_fd < 0) {
		fprintf(stderr, "[AOV] open wake fd failed: %s\n", strerror(errno));
		goto err;
	}
	fprintf(stderr, "[AOV] opened wake fd=%d\n", g_wake_fd);

	g_state_fd = open("/sys/power/state", O_WRONLY);
	if (g_state_fd < 0) {
		fprintf(stderr, "[AOV] open state fd failed: %s\n", strerror(errno));
		goto err;
	}
	fprintf(stderr, "[AOV] opened state fd=%d\n", g_state_fd);
	return 0;

err:
	if (g_wake_fd >= 0) {
		close(g_wake_fd);
		g_wake_fd = -1;
	}
	/* g_state_fd open failed here, nothing to close */
	return -1;
}

/**
 * @brief Close pre-opened sysfs fds for AoV.
 *
 * Must be called when the AoV thread exits to release the file descriptors
 * acquired by initAoVFd().
 */
static void exitAoVFd(void)
{
	if (g_wake_fd >= 0) {
		close(g_wake_fd);
		g_wake_fd = -1;
	}
	if (g_state_fd >= 0) {
		close(g_state_fd);
		g_state_fd = -1;
	}
}

/**
 * @brief Enable or disable Always-On Vision (AOV) feature and configure its wakeup period.
 *
 * This function writes to the sysfs node "/sys/devices/system/augentix-core/wake"
 * to control the AOV wakeup feature.
 *
 * @param[in] aov_en         1 to enable AOV, 0 to disable
 * @param[in] aov_src        AOV wakeup source (e.g., AOV_RTC)
 * @param[in] aov_period_ms  AOV wakeup period in milliseconds
 * @retval 0        Success
 * @retval -ENODEV  Failed to open sysfs node
 * @retval -EIO     Failed to write to sysfs node
 *
 */
INT32 SAMPLE_enableAOV(UINT8 aov_en, UINT8 aov_src, UINT32 aov_period_ms)
{
	char cmd[64] = "";

	if (g_wake_fd < 0 || g_state_fd < 0) {
		fprintf(stderr, "[AOV] wake/state fd not available\n");
		return -ENODEV;
	}

	switch (aov_src) {
	case AOV_RTC:
		if (aov_en)
			snprintf(cmd, sizeof(cmd), "rtc,1,%d", aov_period_ms);
		else
			snprintf(cmd, sizeof(cmd), "clear,rtc");
		break;
	case AOV_PIR:
		if (aov_en)
			snprintf(cmd, sizeof(cmd), "eirq,1,4,rise");
		else
			snprintf(cmd, sizeof(cmd), "clear,eirq");
		break;
	default:
		fprintf(stderr, "[AOV] wakeup source %d not supported\n", aov_src);
		return -EINVAL;
	}

	/* sysfs store is a stateless single-shot operation; offset is irrelevant */
	if (write(g_wake_fd, cmd, strlen(cmd)) < 0) {
		fprintf(stderr, "[AOV] Failed to write wake: %s\n", strerror(errno));
		return -EIO;
	}

	if (aov_en) {
		const char aov_ctrl[] = AOV_CTRL_FNAME;
		bool exist = (access(aov_ctrl, F_OK) == 0);

		if (exist)
			system("/etc/aov suspend");

		/* Reset offset before writing power state */
		if (write(g_state_fd, "mem", 3) < 0) {
			fprintf(stderr, "[AOV] Failed to write power state: %s\n",
			        strerror(errno));
			return -EIO;
		}
		/* Execution resumes here after system wakes from suspend */

		if (exist)
			system("/etc/aov resume");
	}

	return 0;
}

/**
 * @brief AOV detection thread using semaphore timed-wait as a timer.
 */
INT32 ThreadAovDetect(CONF_CASE_GEN_PARAM *aov_parms)
{
	UINT32 cnt = 0;
	int ret;
	struct timespec ts;

	if (initAoVFd() < 0) {
		fprintf(stderr, "[AOV] Failed to pre-open sysfs fds - exit AoV\n");
		return 0;
	}

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

#if defined(AOV_BLOCK_BY_OBJECT)
	fprintf(stderr,"init_od_shm_reader-1\n");

	if (g_od_shm == NULL) {
		fprintf(stderr,"init_od_shm_reader-2\n");
		init_od_shm_reader();
	}
#endif

	// printf("AoV detection thread started\n");
	while (g_AovRun) {
		clock_gettime(CLOCK_REALTIME, &ts);
		ts.tv_sec += 1; /* Check it every 1 sec */
		ret = sem_timedwait(&g_semAov, &ts);
		if (ret == 0) {
			// printf("AoV semaphore posted - exit AoV\n");
			break;
		}
		if (errno == ETIMEDOUT) {
			/* timeout: act as timer tick, continue to check below */
			MPI_LPMD_INFO_S lpmd_rpt;
			MPI_PATH idx = { { .dev = 0, .path = 0, .dummy1 = 0, .dummy0 = 0 } };

#if defined(AOV_BLOCK_BY_OBJECT)
			if (check_od_and_block_aov(&cnt)) {
				//fprintf(stderr,"cnt:%d, detected\n", cnt);
				continue;
			}
#endif

			ret = MPI_DEV_getLpmdInfo(idx, &lpmd_rpt);
			if (ret != MPI_SUCCESS)
				continue;
		
			if (lpmd_rpt.status_frame_alarm == 0) {
				if (++cnt < aov_parms->aov_stable_cnt) {
					printf("AoV motion alarm:%d, check cnt=%d\n",
						lpmd_rpt.status_frame_alarm, cnt);
					continue;
				}

				if (SAMPLE_enableAOV(1, aov_parms->aov_src, aov_parms->aov_period_ms) < 0) {
					printf("Failed to setup AOV - exit AoV\n");
					break;
				}
			}
			cnt = 0;
			continue;
		} else if (errno == EINTR) {
			printf("AoV interrupted by signal - exit AoV\n");
			break;
		} else {
			/* unexpected error: log and exit */
			printf("AoV unexpected error - exit AoV\n");
			break;
		}

		pthread_testcancel();
	}

#if defined(AOV_BLOCK_BY_OBJECT)
	exit_od_shm_reader();
#endif
	exitAoVFd();
	return 0;
}

/**
 * @brief Reconfig video resolution when video pipeline is running.
 * @details
 * The sample function is expected to work under the following context:
 *  - Video device, video channels and encoders are running.
 *    Otherwise, stop flow and restart flow must be adjusted.
 *  - Object detection is disabled before reconfiguring resolution.
 * @param[in,out] conf    Pointer to video pipeline configuration.
 * @param[in]     idx     Index of the target video channel
 * @param[in]     res     Pointer to target output resolution
 * @return The execution result
 * @retval 0      success
 * @exception SIGABRT if any MPI returns not success.
 * @exception SIGFAULT if NULL pointer is received.
 */
INT32 SAMPLE_reconfigResolution(const SAMPLE_CONF_S *conf, MPI_CHN idx, const MPI_SIZE_S *resolution)
{
	MPI_ENC_CHN_ATTR_S enc_attr[MPI_MAX_ENC_CHN_NUM];
	MPI_CHN_ATTR_S chn_attr;
	MPI_CHN_LAYOUT_S layout;
	int err;
	int i;

	/**
	 * To reconfigure resolution, update fields in the following attributes are needed:
	 *  - MPI_CHN_ATTR_S
	 *  - MPI_CHN_LAYOUT_S
	 *  - MPI_ENC_CHN_ATTR_S.
	 *
	 * Making sample code as simple as possible, we configure layout without PIP or POP
	 * features, just keep only 1 window. Please modify layout attribute as you want.
	 */

	err = MPI_DEV_getChnAttr(idx, &chn_attr);
	assert(err == 0);

	err = MPI_DEV_getChnLayout(idx, &layout);
	assert(err == 0);

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_getChnAttr(MPI_ENC_CHN(i), &enc_attr[i]);
		assert(err == 0);
	}

	chn_attr.res = *resolution;

	layout.window_num = 1;
	layout.window[0] = (MPI_RECT_S){ .x = 0, .y = 0, .width = resolution->width, .height = resolution->height };

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		// Configure encoders that are bound to target video channel.
		if (SAMPLE_VIDEO_CHN_IDX_EQUAL(conf->enc_chn[i].bind.idx, idx)) {
			enc_attr[i].res = *resolution;
			enc_attr[i].max_res = *resolution;
		}
	}

	/** First, stop encoders and video channels before configuring resolution and layout. */

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_stopChn(MPI_ENC_CHN(i));
		assert(err == 0);

		err = MPI_ENC_unbindFromVideoChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	err = MPI_DEV_stopAllChn(MPI_VIDEO_DEV(0));
	assert(err == 0);

	/** Stop all OSD */
	if (conf->osd_visible) {
		disableOsd(conf);
	}

	/** Then, call related setting MPIs to configure resolution */

	err = MPI_DEV_setChnAttr(idx, &chn_attr);
	assert(err == 0);

	err = MPI_DEV_setChnLayout(idx, &layout);
	assert(err == 0);

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		// Configure encoders that are bound to target video channel.
		if (SAMPLE_VIDEO_CHN_IDX_EQUAL(conf->enc_chn[i].bind.idx, idx)) {
			err = MPI_ENC_setChnAttr(MPI_ENC_CHN(i), &enc_attr[i]);
			assert(err == 0);
		}
	}

	/** Add OSD back to video channels */
	if (conf->osd_visible) {
		enableOsd(conf);
	}

	/** Finally, restart video channels and encoders to generate frames again. */

	err = MPI_DEV_startAllChn(MPI_VIDEO_DEV(0));
	assert(err == 0);

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_bindToVideoChn(MPI_ENC_CHN(i), &conf->enc_chn[i].bind);
		assert(err == 0);

		err = MPI_ENC_startChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	return 0;
}

/**
 * @brief Reconfig video layout when video pipeline is running.
 * @details
 * The sample function is expected to work under the following context:
 *  - Video device, video channels and encoders are running
 *    Otherwise, stop flow and restart flow must be adjusted
 *  - Object detection is disabled before reconfiguring layout.
 * @param[in,out] conf      Pointer to video pipeline configuration.
 * @param[in]     idx       Index of the target video channel
 * @param[in]     layout    Pointer to target video layout
 * @return The execution result
 * @retval 0      success
 * @exception SIGABRT if any MPI returns not success.
 */
INT32 SAMPLE_reconfigLayout(const SAMPLE_CONF_S *conf, MPI_CHN idx, const MPI_CHN_LAYOUT_S *layout)
{
	int err;
	int i;

	/** First, stop encoders and video channels before configuring layout. */

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_stopChn(MPI_ENC_CHN(i));
		assert(err == 0);

		err = MPI_ENC_unbindFromVideoChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	err = MPI_DEV_stopAllChn(MPI_VIDEO_DEV(0));
	assert(err == 0);

	/** Stop all OSD */
	if (conf->osd_visible) {
		disableOsd(conf);
	}

	/** Then, call related setting MPIs to configure video layout */

	err = MPI_DEV_setChnLayout(idx, layout);
	assert(err == 0);

	/** Add OSD back to video channels */
	if (conf->osd_visible) {
		enableOsd(conf);
	}

	/** Finally, restart video channels and encoders to generate frames again. */

	err = MPI_DEV_startAllChn(MPI_VIDEO_DEV(0));
	assert(err == 0);

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_bindToVideoChn(MPI_ENC_CHN(i), &conf->enc_chn[i].bind);
		assert(err == 0);

		err = MPI_ENC_startChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	return 0;
}

/**
 * @brief Update channel FPS.
 * @param[in] idx    Index of the target video channel
 * @param[in] res    Pointer to target output fps
 * @return The execution result
 * @retval 0      success
 * @retval others unexpected failure
 */
INT32 SAMPLE_updateFps(MPI_CHN idx, FLOAT fps)
{
	MPI_CHN_ATTR_S attr;
	int err;

	/** User only needs to update .fps in MPI_CHN_ATTR_S to update FPS */

	err = MPI_DEV_getChnAttr(idx, &attr);
	if (err != 0) {
		return err;
	}

	attr.fps = fps;

	err = MPI_DEV_setChnAttr(idx, &attr);
	if (err != 0) {
		return err;
	}

	/** Also update venc sps fps info */
	MPI_ECHN enc_idx;
	enc_idx.chn = idx.chn;
	err = SAMPLE_updateSpsVuiFpsInfo(enc_idx, (UINT32)fps);
	if (err != 0) {
		return err;
	}

	return 0;
}

/**
 * @brief Update region of interest (RoI) for target window
 * @details RoI is dynamic configuratable attributes.
 * @param[in] idx    Index of the target video window
 * @param[in] roi    Pointer to target output RoI.
 * @return The execution result
 * @retval 0      success
 * @retval others unexpeced failure
 */
INT32 SAMPLE_updateWindowRoi(MPI_WIN idx, const MPI_RECT_S *roi)
{
	MPI_WIN_ATTR_S attr;
	int err;

	/** User only needs to update .roi in MPI_WIN_ATTR_S to update RoI */

	err = MPI_DEV_getWindowAttr(idx, &attr);
	if (err != 0) {
		return err;
	}

	attr.roi = *roi;

	err = MPI_DEV_setWindowAttr(idx, &attr);
	if (err != 0) {
		return err;
	}

	return 0;
}

/**
 * @brief Update mirroring flag.
 * @details Mirror is dynamic configuratable attributes.
 * For now, mirroring can be configured on WIN(0, 0, 0) only.
 * @param[in] enable boolean value. 0 for disable, otherwise for enable.
 * @return The execution result
 * @retval 0      success
 * @retval others failure
 */
INT32 SAMPLE_updateMirrorAttr(UINT8 enable)
{
	MPI_WIN_ATTR_S attr;
	int err;

	/** User only needs to update .mirr_en in MPI_WIN_ATTR_S to update mirroring attribute */

	err = MPI_DEV_getWindowAttr(MPI_VIDEO_WIN(0, 0, 0), &attr);
	if (err != 0) {
		return err;
	}

	attr.mirr_en = enable;

	err = MPI_DEV_setWindowAttr(MPI_VIDEO_WIN(0, 0, 0), &attr);
	if (err != 0) {
		return err;
	}

	return 0;
}

/**
 * @brief Update flipping flag.
 * @details Flipping is dynamic configuratable attributes.
 * For now, flipping can be configured on WIN(0, 0, 0) only.
 * @param[in] enable boolean value. 0 for disable, otherwise for enable.
 * @return The execution result
 * @retval 0      success
 * @retval others failure
 */
INT32 SAMPLE_updateFlipAttr(UINT8 enable)
{
	MPI_WIN_ATTR_S attr;
	int err;

	/** User only needs to update .flip_en in MPI_WIN_ATTR_S to update flipping attribute */

	err = MPI_DEV_getWindowAttr(MPI_VIDEO_WIN(0, 0, 0), &attr);
	if (err != 0) {
		return err;
	}

	attr.flip_en = enable;

	err = MPI_DEV_setWindowAttr(MPI_VIDEO_WIN(0, 0, 0), &attr);
	if (err != 0) {
		return err;
	}

	return 0;
}

/**
 * @brief Reconfig window view type when video pipeline is running.
 * @details
 * The sample function is expected to work under the following context:
 *  - Video device, video channels and encoders are running.
 *    Otherwise, stop flow and restart flow must be adjusted
 *  - Object detection is disabled before reconfiguring resolution.
 * @param[in,out] conf    Pointer to video pipeline configuration.
 * @param[in]     idx     Index of the target video window
 * @param[in]     res     Target window view type
 * @return The execution result
 * @retval 0      success
 * @exception SIGABRT if any MPI returns not success.
 * @exception SIGFAULT if NULL pointer is received.
 */
INT32 SAMPLE_reconfigWindowViewType(const SAMPLE_CONF_S *conf, MPI_WIN idx, MPI_WIN_VIEW_TYPE_E type)
{
	MPI_WIN_ATTR_S win_attr;
	int err;
	int i;

	/** To reconfigure window view type, update field in MPI_WIN_ATTR_S is needed. */

	err = MPI_DEV_getWindowAttr(idx, &win_attr);
	assert(err == 0);

	win_attr.view_type = type;

	/** First, stop encoders and video channels before configuring window view type. */

	for (int i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_stopChn(MPI_ENC_CHN(i));
		assert(err == 0);

		err = MPI_ENC_unbindFromVideoChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	err = MPI_DEV_stopAllChn(MPI_VIDEO_DEV(0));
	assert(err == 0);

	/** Stop all OSD in video channels */
	if (conf->osd_visible) {
		disableOsd(conf);
	}

	/** Then, call related setting MPIs to configure window view type */

	err = MPI_DEV_setWindowAttr(idx, &win_attr);
	assert(err == 0);

	/** Add OSD back to video channels */
	if (conf->osd_visible) {
		enableOsd(conf);
	}

	/** Finally, restart video channels and encoders to generate frames again. */

	err = MPI_DEV_startAllChn(MPI_VIDEO_DEV(0));
	assert(err == 0);

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_bindToVideoChn(MPI_ENC_CHN(i), &conf->enc_chn[i].bind);
		assert(err == 0);

		err = MPI_ENC_startChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	return 0;
}

/**
 * @brief Update stitch attribute.
 * @details Parameters of stitch transform is dynamic configuratable attributes.
 * For now, stitch can be configured on WIN(0, 0, 0) only.
 * @param[in] attr    pointer to stitch attributes
 * @return The execution result
 * @retval 0       success
 * @retval others  failure
 */
INT32 SAMPLE_updateStitchAttr(const MPI_STITCH_ATTR_S *attr)
{
	/** User only needs to update MPI_STITCH_ATTR_S */
	return MPI_DEV_setStitchAttr(MPI_VIDEO_WIN(0, 0, 0), attr);
}

/**
 * @brief Update panorama attribute.
 * @details Parameters of panorama transform is dynamic configuratable attributes.
 * For now, panorama can be configured on WIN(0, 0, 0) only.
 * @param[in] attr    pointer to panorama attributes
 * @return The execution result
 * @retval 0       success
 * @retval others  failure
 */
INT32 SAMPLE_updatePanoramaAttr(const MPI_PANORAMA_ATTR_S *attr)
{
	/** User only needs to update MPI_PANORAMA_ATTR_S */
	return MPI_DEV_setPanoramaAttr(MPI_VIDEO_WIN(0, 0, 0), attr);
}

/**
 * @brief Update panning attribute.
 * @details Parameters of panning transform is dynamic configuratable attributes.
 * For now, panning can be configured on WIN(0, 0, 0) only.
 * @param[in] attr    pointer to panning attributes
 * @return The execution result
 * @retval 0       success
 * @retval others  failure
 */
INT32 SAMPLE_updatePanningAttr(const MPI_PANNING_ATTR_S *attr)
{
	/** User only needs to update MPI_PANNING_ATTR_S */
	return MPI_DEV_setPanningAttr(MPI_VIDEO_WIN(0, 0, 0), attr);
}

/**
 * @brief Update surround attribute.
 * @details Parameters of surround transform is dynamic configuratable attributes.
 * For now, surround can be configured on WIN(0, 0, 0) only.
 * @param[in] attr    pointer to surround attributes
 * @return The execution result
 * @retval 0      success
 * @retval others failure
 */
INT32 SAMPLE_updateSurroundAttr(const MPI_SURROUND_ATTR_S *attr)
{
	/** User only needs to update MPI_SURROUND_ATTR_S */
	return MPI_DEV_setSurroundAttr(MPI_VIDEO_WIN(0, 0, 0), attr);
}

/**
 * @brief Update lens distortion correction attribute.
 * @details Parameters of LDC transform is dynamic configuratable attributes.
 * For now, LDC can be configured on WIN(0, 0, 0) only.
 * @param[in] attr    pointer to LDC attributes
 * @return The execution result
 * @retval 0      success
 * @retval others failure
 */
INT32 SAMPLE_updateLdcAttr(const MPI_LDC_ATTR_S *attr)
{
	/** User only needs to update MPI_LDC_ATTR_S */
	return MPI_DEV_setLdcAttr(MPI_VIDEO_WIN(0, 0, 0), attr);
}

/**
 * @brief Reconfig codec type when video pipeline is running.
 * @details
 * The sample function is expected to work under the following context:
 *  - Video device, video channels and encoders are running
 *    Otherwise, stop flow and restart flow must be adjusted
 * @param[in,out] conf      Pointer to video pipeline configuration.
 * @param[in]     idx       Index of the target video channel
 * @param[in]     layout    Pointer to target encoder attributes.
 * @return The execution result
 * @retval 0      success
 * @exception SIGABRT if any MPI returns not success.
 */
INT32 SAMPLE_reconfigCodec(const SAMPLE_CONF_S *conf, MPI_ECHN idx, const MPI_VENC_ATTR_S *attr)
{
	int err;
	int i;

	/** First, stop all encoders before configuring codec type. */

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_stopChn(MPI_ENC_CHN(i));
		assert(err == 0);

		err = MPI_ENC_unbindFromVideoChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	/** Stop all OSD in video channels */
	if (conf->osd_visible) {
		disableOsd(conf);
	}

	/** Then, call MPI to configure codec type. */

	err = MPI_ENC_setVencAttr(idx, attr);
	assert(err == 0);

	/** Add OSD back to video channels */
	if (conf->osd_visible) {
		enableOsd(conf);
	}

	/** Finally, restart encoders to generate frames again. */

	for (i = 0; i < MPI_MAX_ENC_CHN_NUM; i++) {
		if (!conf->enc_chn[i].enable) {
			continue;
		}

		err = MPI_ENC_bindToVideoChn(MPI_ENC_CHN(i), &conf->enc_chn[i].bind);
		assert(err == 0);

		err = MPI_ENC_startChn(MPI_ENC_CHN(i));
		assert(err == 0);
	}

	return 0;
}

/**
 * @brief Update VBR parameters when encoder is running on VBR mode.
 * @param[in] idx      Index of the target encoder
 * @param[in] param    Pointer to target VBR parameters
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 */
INT32 SAMPLE_updateVbrParams(MPI_ECHN idx, const MPI_MCVC_VBR_PARAM_S *param)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		attr.h264.rc.vbr = *param;
		break;

	case MPI_VENC_TYPE_H265:
		attr.h265.rc.vbr = *param;
		break;

	default:
		return -1;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

/**
 * @brief Update CBR parameters when encoder is running on CBR mode.
 * @param[in] idx      Index of the target encoder
 * @param[in] param    Pointer to target CBR parameters
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 */
INT32 SAMPLE_updateCbrParams(MPI_ECHN idx, const MPI_MCVC_CBR_PARAM_S *param)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		attr.h264.rc.cbr = *param;
		break;

	case MPI_VENC_TYPE_H265:
		attr.h265.rc.cbr = *param;
		break;

	default:
		return -EFAULT;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

/**
 * @brief Update SBR parameters when encoder is running on SBR mode.
 * @param[in] idx      Index of the target encoder
 * @param[in] param    Pointer to target SBR parameters
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 */
INT32 SAMPLE_updateSbrParams(MPI_ECHN idx, const MPI_MCVC_SBR_PARAM_S *param)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		attr.h264.rc.sbr = *param;
		break;

	case MPI_VENC_TYPE_H265:
		attr.h265.rc.sbr = *param;
		break;

	default:
		return -EFAULT;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

/**
 * @brief Update CQP parameters when encoder is running on CQP mode.
 * @param[in] idx      Index of the target encoder
 * @param[in] param    Pointer to target CQP parameters
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 */
INT32 SAMPLE_updateCqpParams(MPI_ECHN idx, const MPI_MCVC_CQP_PARAM_S *param)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		attr.h264.rc.cqp = *param;
		break;

	case MPI_VENC_TYPE_H265:
		attr.h265.rc.cqp = *param;
		break;

	default:
		return -EFAULT;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

/**
 * @brief Update GOP parameters when encoder is running in H.264 or H.265.
 * @param[in] idx      Index of the target encoder
 * @param[in] param    Target GOP
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 */
INT32 SAMPLE_updateGopAttr(MPI_ECHN idx, UINT32 gop)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		attr.h264.rc.gop = gop;
		break;

	case MPI_VENC_TYPE_H265:
		attr.h265.rc.gop = gop;
		break;

	default:
		return -EFAULT;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

static inline void setBitRate(void *param, MPI_RC_MODE_E mode, UINT32 rate)
{
	switch (mode) {
	case MPI_RC_MODE_VBR:
		((MPI_MCVC_RC_ATTR_S *)param)->vbr.max_bit_rate = rate;
		break;

	case MPI_RC_MODE_CBR:
		((MPI_MCVC_RC_ATTR_S *)param)->cbr.bit_rate = rate;
		break;

	case MPI_RC_MODE_SBR:
		((MPI_MCVC_RC_ATTR_S *)param)->sbr.bit_rate = rate;
		break;

	default:
		break;
	}

	return;
}

/**
 * @brief Update encoder bitrate when encoder is running in H.264 or H.265.
 * @param[in] idx      Index of the target encoder
 * @param[in] rate     Target bit rate
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 */
INT32 SAMPLE_updateBitRate(MPI_ECHN idx, UINT32 rate)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		setBitRate(&attr.h264.rc, attr.h264.rc.mode, rate);
		break;

	case MPI_VENC_TYPE_H265:
		setBitRate(&attr.h265.rc, attr.h265.rc.mode, rate);
		break;

	default:
		return -EFAULT;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}

/**
 * @brief Update encoder bitrate when encoder is running in H.264 or H.265.
 * @param[in] idx      Index of the target encoder
 * @param[in] fps      Target fps
 * @return The execution result
 * @retval 0          success
 * @retval others     unexpected failure
 * @note only support H264/H265
 */
INT32 SAMPLE_updateSpsVuiFpsInfo(MPI_ECHN idx, UINT32 fps)
{
	MPI_VENC_ATTR_S attr;
	int ret;

	ret = MPI_ENC_getVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	switch (attr.type) {
	case MPI_VENC_TYPE_H264:
		attr.h264.rc.frm_rate_o = fps;
		break;

	case MPI_VENC_TYPE_H265:
		attr.h265.rc.frm_rate_o = fps;
		break;

	default:
		/** only H264/H265 need to change VUI*/
		return -EINVAL;
	}

	ret = MPI_ENC_setVencAttr(idx, &attr);
	if (ret != 0) {
		return ret;
	}

	return 0;
}
