#include "agtx_video.h"

#include <common.h>
#include <sensor_def.h>

#include "utils.h"
#include "da.h"
#include "isp.h"

#ifdef CONFIG_EARLYVIDEO
#include "sensor_settings.h"
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
#include "sensor_settings_1.h"
#endif
#endif

DECLARE_GLOBAL_DATA_PTR;

struct earlyvideo_drvdata g_earlyvideo_drvdata;

void agtx_video_init(void)
{
	is_install_irq_handler();
#ifdef CONFIG_AMP
	isp_install_irq_handler();
#endif

	agtx_video_init_drvdata(&g_earlyvideo_drvdata);
	senif_init_hw();
	senif_trigger_start();
	is_init_hw();
}

inline void agtx_video_adjust_light_meter_height(uint8_t path, uint8_t *frame_num)
{
	is_adjust_kernel_height(path, frame_num);
}

void agtx_video_start_snapshot(void)
{
	isp_start_snapshot();
}

#if EARLYVIDEO_DEBUG
inline void agtx_video_poll_frame_end(uint8_t path)
{
	is_poll_da(path);
}

inline void agtx_video_show_checksum(void)
{
	is_show_checksum();
}
#endif

void agtx_video_start(struct agtx_video_route *route)
{
	uint8_t path = route->path;

	if (route->sw_light_meter_cb) {
		is_enable_bsp_route(path);
		is_set_irq_cb(path, route->sw_light_meter_cb);
	}

	if (route->image_capture) {
		is_enable_dram_route(path);
	}

	is_trigger_start(path);
}

unsigned long agtx_video_setmem(unsigned long addr)
{
	unsigned long reserved_size_mb = EARLY_VB_SIZE;

	addr -= (reserved_size_mb << 20);
#if EARLYVIDEO_DEBUG
	printf("Reserving %luk for augentix video at: %08lx\n", reserved_size_mb << 10, addr);
#endif

	return addr;
}

void agtx_video_set_env(void)
{
	char value_buf[32];
	/* Set the information of shared memory */
	sprintf(value_buf, "0x%08x", (unsigned int)g_earlyvideo_drvdata.shm_ptr);
	setenv("early_vb_memaddr", value_buf);
	sprintf(value_buf, "%d", EARLY_VB_SIZE);
	setenv("early_vb_size", value_buf);
#ifdef CONFIG_AMP
	if (g_earlyvideo_drvdata.false_alarm.type != 0) {
		sprintf(value_buf, "0x%08x",
		        (unsigned int)g_earlyvideo_drvdata.shm_ptr->segments[0].early_detect_info.snapshot.phy_addr_y);
		setenv("uboot_snapshot_addr", value_buf);
		sprintf(value_buf, "%d", g_earlyvideo_drvdata.shm_ptr->segments[0].snapshot_size);
		setenv("uboot_snapshot_size", value_buf);
		sprintf(value_buf, "0x%08x",
		        (unsigned int)g_earlyvideo_drvdata.shm_ptr->segments[0].early_detect_info.mv.phy_addr);
		setenv("uboot_mv_addr", value_buf);
		sprintf(value_buf, "%d", g_earlyvideo_drvdata.shm_ptr->segments[0].mv_size);
		setenv("uboot_mv_size", value_buf);
	}
#endif
}

void agtx_video_init_shm_info(struct earlyvideo_drvdata *drvdata)
{
	struct earlyvideo_shm_info *shm_info = NULL;
#if CONFIG_AMP
	struct early_detect_info *early_detect_info = NULL;
#endif
	uint32_t pool_size[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t frame_size[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t keep_num[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t total_vb_size = 0;
	uint32_t path_vb_size[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t duration = 0;
	uint8_t path_fps[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint8_t active_path_num = 0;
	uint8_t path;

	/* 1. Assign the address of shared memory from global data. */
	drvdata->shm_ptr = (struct earlyvideo_shm_info *)gd->fb_base;
	memset((void *)drvdata->shm_ptr, 0, EV_DRIVER_SHM_SIZE);
	shm_info = drvdata->shm_ptr;

	/* 2. Get the memory information from U-Boot environment variable. */
	total_vb_size = EARLY_VB_SIZE << 20;
	if (total_vb_size == 0) {
		printf("Invalid early_vb_size %d\n", total_vb_size);
	}
#if LOCK_PARAM_TO_SPEED_UP
	shm_info->segments[0].width = EARLY_VIDEO_PATH0_WIDTH;
	shm_info->segments[0].height = EARLY_VIDEO_PATH0_HEIGHT;
	shm_info->segments[1].width = EARLY_VIDEO_PATH1_WIDTH;
	shm_info->segments[1].height = EARLY_VIDEO_PATH1_HEIGHT;
	path_vb_size[0] = EARLY_VB_PATH0_SIZE << 20;
	path_vb_size[1] = EARLY_VB_PATH1_SIZE << 20;
	keep_num[0] = EARLY_VB_PATH0_KEEP_NUM;
	keep_num[1] = EARLY_VB_PATH1_KEEP_NUM;
	path_fps[0] = CAMERA_FPS;
	path_fps[1] = CAMERA1_FPS;
	duration = UBOOT_CAPTURE_DURATION;
#else
	shm_info->segments[0].width = (uint32_t)simple_strtoul(getenv("path0_width"), NULL, 10);
	shm_info->segments[0].height = (uint32_t)simple_strtoul(getenv("path0_height"), NULL, 10);
	shm_info->segments[1].width = (uint32_t)simple_strtoul(getenv("path1_width"), NULL, 10);
	shm_info->segments[1].height = (uint32_t)simple_strtoul(getenv("path1_height"), NULL, 10);
	path_vb_size[0] = (uint32_t)simple_strtoul(getenv("early_vb_path0_size"), NULL, 10) << 20;
	path_vb_size[1] = (uint32_t)simple_strtoul(getenv("early_vb_path1_size"), NULL, 10) << 20;
	keep_num[0] = (uint32_t)simple_strtoul(getenv("early_vb_path0_keep_num"), NULL, 10);
	keep_num[1] = (uint32_t)simple_strtoul(getenv("early_vb_path1_keep_num"), NULL, 10);
	path_fps[0] = (uint8_t)simple_strtoul(getenv("camera_fps"), NULL, 10);
	path_fps[1] = (uint8_t)simple_strtoul(getenv("camera_fps_1"), NULL, 10);
	duration = (uint32_t)simple_strtoul(getenv("uboot_capture_duration"), NULL, 10);
#endif
	if (keep_num[0] < 2) {
		printf("Attempt to set an invalid value of %d for the keep_blk_num of path 0; still uses the default value of 2\n",
		       keep_num[0]);
		keep_num[0] = 2;
	}
	shm_info->segments[0].keep_num = keep_num[0];
	if (keep_num[1] < 2) {
		printf("Attempt to set an invalid value of %d for the keep_blk_num of path 1; still uses the default value of 2\n",
		       keep_num[1]);
		keep_num[1] = 2;
	}
	shm_info->segments[1].keep_num = keep_num[1];
	if (path_fps[0] > SENSOR_FPS_MAX || path_fps[0] < SENSOR_FPS_MIN) {
		path_fps[0] = SENSOR_FPS_START;
	}
	if (path_fps[1] > SENSOR_FPS_MAX || path_fps[1] < SENSOR_FPS_MIN) {
		path_fps[1] = SENSOR_FPS_START;
	}
	debug_print("total_vb_size = %u\n", total_vb_size);
	debug_print("path_vb_size[0] = %u\n", path_vb_size[0]);
	debug_print("path_vb_size[1] = %u\n", path_vb_size[1]);
	debug_print("keep_num[0] = %u\n", keep_num[0]);
	debug_print("keep_num[1] = %u\n", keep_num[1]);
	debug_print("path_fps[0] = %u\n", path_fps[0]);
	debug_print("path_fps[1] = %u\n", path_fps[1]);
	debug_print("duration = %u\n", duration);

	/* 3. Calculate the frame size. */
	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		frame_size[path] = calc_pxw_buffer_size(shm_info->segments[path].width, shm_info->segments[path].height,
		                                        &drvdata->da_cfg[DRAM_AGENT_ISW], 0);
		shm_info->segments[path].frame_size = frame_size[path];
		debug_print("frame_size[%u] = %u\n", path, frame_size[path]);
	}

	/* 4. Calculate and reserve memory for the U-Boot snapshot if detect_type is non-zero. */
#if CONFIG_AMP
	if (g_earlyvideo_drvdata.false_alarm.type != 0) {
		shm_info->segments[0].snapshot_size = calc_pxw_buffer_size(
		        EARLYVIDEO_SNAPSHOT_WIDTH, EARLYVIDEO_SNAPSHOT_HEIGHT, &drvdata->da_cfg[DRAM_AGENT_INTER], 1);
		shm_info->segments[0].mv_size = calc_mvw_buffer_size(
		        EARLYVIDEO_SNAPSHOT_WIDTH, EARLYVIDEO_SNAPSHOT_HEIGHT, &drvdata->da_cfg[DRAM_AGENT_MV8W]);
	} else {
		shm_info->segments[0].snapshot_size = 0;
		shm_info->segments[0].mv_size = 0;
	}
#else
	shm_info->segments[0].snapshot_size = 0;
	shm_info->segments[0].mv_size = 0;
#endif
	/* U-Boot snapshot is currently not supported on path 1 */
	shm_info->segments[1].snapshot_size = 0;
	shm_info->segments[1].mv_size = 0;

	/* 5. Calculate the pool size. */
	if (drvdata->sensor_bmp == (BIT(0) | BIT(1))) {
		/* Dual sensor */
		active_path_num = 2;
		if (path_vb_size[0] == 0 && path_vb_size[1] == 0) {
			/* Auto */
			pool_size[0] = path_fps[0] * frame_size[0] >> 10; /* KB to prevent overflow */
			pool_size[1] = path_fps[1] * frame_size[1] >> 10; /* KB to prevent overflow */
			if (pool_size[0] == 0 && pool_size[1] == 0) {
				printf("Failed to calculate pool size.\n\tpath[0] fps %d, frame_size %d\n\tpath[1] fps %d, frame_size %d\n",
				       path_fps[0], frame_size[0], path_fps[1], frame_size[1]);
			} else {
				uint32_t keep_vb_size = frame_size[0] * keep_num[0] + frame_size[1] * keep_num[1];
				if (total_vb_size > keep_vb_size) {
#define AUTO_PRECISE 10
					uint32_t p0_percent_x1024 =
					        (pool_size[0] << AUTO_PRECISE) / (pool_size[0] + pool_size[1]);
					uint32_t remain_vb_size_kb = (total_vb_size - keep_vb_size) >> 10;
					pool_size[0] =
					        (((remain_vb_size_kb * p0_percent_x1024) >> AUTO_PRECISE) << 10) +
					        frame_size[0] * keep_num[0]; /* << 10 for KB to BYTE */
					pool_size[1] = total_vb_size - pool_size[0];
				} else {
					pool_size[0] = 0;
					pool_size[1] = 0;
					printf("Not enough memory for keep_num in each pool.\nvb size %d < frame_size[0] %d * keep_num[0] %d + frame_size[1] %d * keep_num[1] %d = %d\n",
					       total_vb_size, frame_size[0], keep_num[0], frame_size[1], keep_num[1],
					       keep_vb_size);
				}
			}

		} else if (path_vb_size[0] == 0) {
			/* Semi-auto */
			pool_size[1] = path_vb_size[1];
			pool_size[0] = total_vb_size - pool_size[1];
		} else if (path_vb_size[1] == 0) {
			/* Semi-auto */
			pool_size[0] = path_vb_size[0];
			pool_size[1] = total_vb_size - pool_size[0];
		} else {
			/* Manual */
			pool_size[0] = path_vb_size[0];
			pool_size[1] = path_vb_size[1];
		}
	} else {
		/* Single sensor*/
		active_path_num = 1;
		if (drvdata->sensor_bmp == BIT(0)) {
			/* Sensor 0 */
			pool_size[0] = path_vb_size[0] == 0 ? total_vb_size : path_vb_size[0];
		} else if (drvdata->sensor_bmp == BIT(1)) {
			/* Sensor 1 */
			pool_size[1] = path_vb_size[1] == 0 ? total_vb_size : path_vb_size[1];
		} else {
			printf("Invalid sensor setting.\n");
		}
	}

	/* 6. Check the calculated pool sizes. */
	if ((pool_size[0] + pool_size[1]) > total_vb_size) {
		printf("Invalid pool size path[0] %d + path[1] %d > total_vb_size %d\n", pool_size[0], pool_size[1],
		       total_vb_size);
		printf("Disable the early video !\n");
		pool_size[0] = 0;
		pool_size[1] = 0;
		active_path_num = 0;
	}
	debug_print("Before pool_size[0] = %u\n", pool_size[0]);
	debug_print("Before pool_size[1] = %u\n", pool_size[1]);

	/* 7. Adjust the pool_size. */
	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		if (pool_size[path] != 0) {
			pool_size[path] -= (EV_DRIVER_SHM_SIZE / active_path_num);
			pool_size[path] -= EV_TOTAL_SNAPSHOT_SIZE(shm_info->segments[path].snapshot_size);
			pool_size[path] -= EV_TOTAL_MV_SIZE(shm_info->segments[path].mv_size);
		}
		shm_info->segments[path].pool_size = pool_size[path];
		debug_print("After pool_size[%u] = %u\n", path, pool_size[path]);
	}

	/* 8. Calculate the number of frames. */
	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		if (frame_size[path] != 0 && pool_size[path] != 0) {
			shm_info->segments[path].total_frame_num = pool_size[path] / frame_size[path];
			shm_info->segments[path].uboot_capture_num =
			        MIN(duration * path_fps[path] / 1000, shm_info->segments[path].total_frame_num);
			shm_info->segments[path].uboot_capture_num =
			        MIN(EARLYVIDEO_MAX_HEIGHT / shm_info->segments[path].height,
			            shm_info->segments[path].uboot_capture_num);
		} else {
			shm_info->segments[path].total_frame_num = 0;
			shm_info->segments[path].uboot_capture_num = 0;
		}
		/*
		 * Temporarily store the FPS value from U-Boot environment,
		 * and it will be overwritten by the sensor driver
		 */
		shm_info->segments[path].fps = path_fps[path];
	}

	/* 9. Assign the base and raw address. */
	shm_info->segments[0].base_addr = gd->fb_base + EV_DRIVER_SHM_SIZE;
	shm_info->segments[0].mv_addr = shm_info->segments[0].base_addr + EV_TOTAL_SNAPSHOT_SIZE(shm_info->segments[0].snapshot_size);
	shm_info->segments[0].raw_addr = shm_info->segments[0].mv_addr + EV_TOTAL_MV_SIZE(shm_info->segments[0].mv_size);
	shm_info->segments[1].base_addr = shm_info->segments[0].raw_addr + pool_size[0];
	shm_info->segments[1].mv_addr = shm_info->segments[1].base_addr + EV_TOTAL_SNAPSHOT_SIZE(shm_info->segments[1].snapshot_size);
	shm_info->segments[1].raw_addr = shm_info->segments[1].mv_addr + EV_TOTAL_MV_SIZE(shm_info->segments[1].mv_size);

	/* 10. Fill in the snapshot and MV information. */
#if CONFIG_AMP
	if (g_earlyvideo_drvdata.false_alarm.type != 0) {
		struct earlyvideo_shm_segment *segment = &shm_info->segments[0];
		early_detect_info = &segment->early_detect_info;
		early_detect_info->is_used = 0;
		early_detect_info->snapshot.width = EARLYVIDEO_SNAPSHOT_WIDTH;
		early_detect_info->snapshot.height = EARLYVIDEO_SNAPSHOT_HEIGHT;
		early_detect_info->snapshot.bit_depth = 8;
		early_detect_info->snapshot.size_y = early_detect_info->snapshot.width *
		                                     early_detect_info->snapshot.height *
		                                     early_detect_info->snapshot.bit_depth / 8;
		early_detect_info->snapshot.size_c = early_detect_info->snapshot.size_y / 2; /* yuv420d */
		early_detect_info->snapshot.phy_addr_y = (void *)(segment->base_addr + segment->snapshot_size);
		early_detect_info->snapshot.phy_addr_c =
		        (void *)(early_detect_info->snapshot.phy_addr_y + early_detect_info->snapshot.size_y);
		early_detect_info->mv.phy_addr = (UbootHwMotionVec *)segment->mv_addr;
		early_detect_info->mv.win_width = EARLYVIDEO_SNAPSHOT_WIDTH;
		early_detect_info->mv.win_height = EARLYVIDEO_SNAPSHOT_HEIGHT;
		early_detect_info->mv.fps = segment->fps;
		early_detect_info->mv.duration = (segment->fps == 0) ? 0 : (1000 / segment->fps) / 10;
	}
	debug_print("segments[0].is_used = %u\n", early_detect_info->is_used);
	debug_print("segments[0].snapshot.width = %u\n", early_detect_info->snapshot.width);
	debug_print("segments[0].snapshot.height = %u\n", early_detect_info->snapshot.height);
	debug_print("segments[0].snapshot.bit_depth = %u\n", early_detect_info->snapshot.bit_depth);
	debug_print("segments[0].snapshot.size_y = %u\n", early_detect_info->snapshot.size_y);
	debug_print("segments[0].snapshot.size_c = %u\n", early_detect_info->snapshot.size_c);
	debug_print("segments[0].snapshot.phy_addr_y = 0x%08x\n", (unsigned int)early_detect_info->snapshot.phy_addr_y);
	debug_print("segments[0].snapshot.phy_addr_c = 0x%08x\n", (unsigned int)early_detect_info->snapshot.phy_addr_c);
	debug_print("segments[0].mv.phy_addr = 0x%08x\n", (unsigned int)early_detect_info->mv.phy_addr);
	debug_print("segments[0].mv.win_width = %u\n", early_detect_info->mv.win_width);
	debug_print("segments[0].mv.win_height = %u\n", early_detect_info->mv.win_height);
	debug_print("segments[0].mv.fps = %u\n", early_detect_info->mv.fps);
	debug_print("segments[0].mv.duration = %u\n", early_detect_info->mv.duration);
#endif

	debug_print("segments[0].base_addr = 0x%08x\n", &shm_info->segments[0].base_addr);
	debug_print("segments[0].snapshot_size = %u\n", &shm_info->segments[0].snapshot_size);
	debug_print("segments[0].mv_addr = 0x%08x\n", &shm_info->segments[0].mv_addr);
	debug_print("segments[0].mv_size = %u\n", &shm_info->segments[0].mv_size);
	debug_print("segments[0].raw_addr = 0x%08x\n", &shm_info->segments[0].raw_addr);
	debug_print("segments[0].pool_size = %u\n", &shm_info->segments[0].pool_size);
	debug_print("segments[0].frame_size = %u\n", &shm_info->segments[0].frame_size);
	debug_print("segments[0].total_frame_num = %u\n", &shm_info->segments[0].total_frame_num);
	debug_print("segments[0].uboot_capture_num = %u\n", &shm_info->segments[0].uboot_capture_num);
	debug_print("segments[0].keep_num = %u\n", &shm_info->segments[0].keep_num);
	debug_print("segments[1].base_addr = 0x%08x\n", &shm_info->segments[1].base_addr);
	debug_print("segments[1].snapshot_size = %u\n", &shm_info->segments[1].snapshot_size);
	debug_print("segments[1].mv_addr = 0x%08x\n", &shm_info->segments[1].mv_addr);
	debug_print("segments[1].mv_size = %u\n", &shm_info->segments[1].mv_size);
	debug_print("segments[1].raw_addr = 0x%08x\n", &shm_info->segments[1].raw_addr);
	debug_print("segments[1].pool_size = %u\n", &shm_info->segments[1].pool_size);
	debug_print("segments[1].frame_size = %u\n", &shm_info->segments[1].frame_size);
	debug_print("segments[1].total_frame_num = %u\n", &shm_info->segments[1].total_frame_num);
	debug_print("segments[1].uboot_capture_num = %u\n", &shm_info->segments[1].uboot_capture_num);
	debug_print("segments[1].keep_num = %u\n", &shm_info->segments[1].keep_num);
}

void agtx_video_init_drvdata(struct earlyvideo_drvdata *drvdata)
{
#if CONFIG_AMP
	struct earlyvideo_shm_segment *segment = NULL;
	struct isp_frame_table *ftbl = NULL;
#endif
	struct senif_csr *senif_csr = &g_earlyvideo_drvdata.senif_csr;
	struct senif_param *senif_param = NULL;
	struct is_csr *is_csr = &g_earlyvideo_drvdata.is_csr;
	struct is_param *is_param = NULL;
	struct isp_csr *isp_csr = &g_earlyvideo_drvdata.isp_csr;
	struct earlyvideo_shm_info *shm_info = NULL;
	uint8_t lane_idx_bmp = 0;
	int i;

	drvdata->done_flag = 0;

	/* Initialize SENIF csr address */
	senif_csr->senif_ctrl = (void *)0x83570400;
	senif_csr->senif_syscfg = (void *)0x83570000;
	senif_csr->slb[0] = (void *)0x83550000;
	senif_csr->slb[1] = (void *)0x83560000;
	senif_csr->lvds_rx[0] = (void *)0x83520000;
	senif_csr->lvds_rx[1] = (void *)0x83530000;
	senif_csr->lvds_dec[0] = (void *)0x83520400;
	senif_csr->lvds_dec[1] = (void *)0x83530400;
	senif_csr->rxphy_phycfg[0] = (void *)0x83500000;
	senif_csr->rxphy_phycfg[1] = (void *)0x83510000;
	senif_csr->rxphy_ctrl[0] = (void *)0x83500400;
	senif_csr->rxphy_ctrl[1] = (void *)0x83510400;

	/* Initialize IS csr address */
	is_csr->is = (void *)0x83000000;
	is_csr->is_cfg = (void *)0x83000400;
	is_csr->frame_time_gen[0] = (void *)0x83020400;
	is_csr->frame_time_gen[1] = (void *)0x83050400;
	is_csr->edp[0] = (void *)0x83040000;
	is_csr->edp[1] = (void *)0x83070000;
	is_csr->isk[0] = (void *)0x83100000;
	is_csr->gma[0] = (void *)0x83110000;
	is_csr->fpnr[0] = (void *)0x83120000;
	is_csr->crop[0] = (void *)0x83130000;
	is_csr->dbc[0] = (void *)0x83150000;
	is_csr->dcc[0] = (void *)0x83160000;
	is_csr->lsc[0] = (void *)0x83170000;
	is_csr->bsp[0] = (void *)0x83180000;
	is_csr->isk[1] = (void *)0x83200000;
	is_csr->gma[1] = (void *)0x83210000;
	is_csr->fpnr[1] = (void *)0x83220000;
	is_csr->crop[1] = (void *)0x83230000;
	is_csr->dbc[1] = (void *)0x83250000;
	is_csr->dcc[1] = (void *)0x83260000;
	is_csr->lsc[1] = (void *)0x83270000;
	is_csr->bsp[1] = (void *)0x83280000;
	is_csr->iswroi[0] = (void *)0x83080000;
	is_csr->iswroi[1] = (void *)0x83090000;
#if EARLYVIDEO_DEBUG
	is_csr->is_checksum = (void *)0x83000800;
	is_csr->isk_checksum[0] = (void *)0x83100800;
	is_csr->isk_checksum[1] = (void *)0x83200800;
#endif

	/* Initialize ISP csr address */
	isp_csr->isp = (void *)0x82000000;
	isp_csr->isp_cfg = (void *)0x82000400;
#if ISP_USE_CCQ
	isp_csr->ccq = (void *)0x82010000;
	isp_csr->ccqr = (void *)0x82010400;
	isp_csr->ccqw = (void *)0x82010800;
#endif
	isp_csr->ispr[0] = (void *)0x82040000;
	isp_csr->ispr[1] = (void *)0x82060000;
	isp_csr->pg[0] = (void *)0x82020000;
	isp_csr->pg[1] = (void *)0x82030000;
	isp_csr->cs[0] = (void *)0x82050000;
	isp_csr->cs[1] = (void *)0x82070000;
	isp_csr->dms = (void *)0x82130000;
	isp_csr->fcs = (void *)0x82140000;
	isp_csr->dbf = (void *)0x82150000;
	isp_csr->ccm = (void *)0x82160000;
	isp_csr->gma = (void *)0x82170000;
	isp_csr->pca = (void *)0x82180000;
	isp_csr->cst = (void *)0x82190000;
	isp_csr->sc = (void *)0x821A0000;
	isp_csr->enh = (void *)0x821B0000;
	isp_csr->shp = (void *)0x821C0000;
	isp_csr->dhz = (void *)0x821D0000;
	isp_csr->vp = (void *)0x82202000;
	isp_csr->mcvp = (void *)0x82200000;
	isp_csr->me = (void *)0x82200400;
	isp_csr->nr = (void *)0x82200800;
	isp_csr->mer = (void *)0x82200C00;
	isp_csr->nrw = (void *)0x82201000;
	isp_csr->mv8w = (void *)0x82201400;
	isp_csr->mv8r = (void *)0x82201800;
	isp_csr->venc_mvw = (void *)0x82201C00;
	isp_csr->b2r = (void *)0x82210000;
	isp_csr->vpw[0] = (void *)0x82240000;
	isp_csr->vpw[1] = (void *)0x82250000;
#if EARLYVIDEO_DEBUG
	isp_csr->isp_checksum = (void *)0x82000800;
	isp_csr->ispin_checksum = (void *)0x82000C00;
	isp_csr->enh_checksum = (void *)0x82001400;
	isp_csr->vp_checksum = (void *)0x82202400;
#endif

	/* Initialize the sensor bitmap and SENIF/IS parameters */
	g_earlyvideo_drvdata.sensor_bmp = 0;
#ifdef _SENSOR_DEF_0_H_
	g_earlyvideo_drvdata.sensor_bmp |= BIT(0);
	senif_param = &g_earlyvideo_drvdata.senif_param[0];
	is_param = &g_earlyvideo_drvdata.is_param[0];

	senif_param->lane_num = LVDS_DATA_NUM_0;
	is_param->route_bmp = 0;
	is_param->bit_depth = 8; /* FIXME */
	is_param->bayer_phase = SENSOR_BAYER_PHASE_0;

	i = 0;
#ifdef LVDS_DATA_LANE_0_0
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_0_0);
	senif_param->lane_idx[0] = LVDS_DATA_LANE_0_0;
	i++;
#endif
#ifdef LVDS_DATA_LANE_1_0
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_1_0);
	senif_param->lane_idx[1] = LVDS_DATA_LANE_1_0;
	i++;
#endif
#ifdef LVDS_DATA_LANE_2_0
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_2_0);
	senif_param->lane_idx[2] = LVDS_DATA_LANE_2_0;
	i++;
#endif
#ifdef LVDS_DATA_LANE_3_0
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_3_0);
	senif_param->lane_idx[3] = LVDS_DATA_LANE_3_0;
	i++;
#endif
	for (; i < EARLYVIDEO_MAX_MIPI_LANE_NUM; i++) {
		uint8_t idx;
		for (idx = 0; lane_idx_bmp & BIT(idx); idx++) {
			;
		}
		if (idx >= EARLYVIDEO_MAX_MIPI_LANE_NUM) {
			idx = 0;
		}
		lane_idx_bmp |= BIT(idx);
		senif_param->lane_idx[i] = idx;
	}
	senif_param->width = SENSOR_WIDTH_0;
	senif_param->height = SENSOR_HEIGHT_0;
	senif_param->bit_depth = SENSOR_BIT_DEPTH_0;
	senif_param->t_hs_settle_ns = T_HS_SETTLE_NS_0;
	senif_param->t_d_term_en_ns = T_D_TERM_EN_NS_0;
	senif_param->t_clk_settle_ns = T_CLK_SETTLE_NS_0;
	senif_param->t_clk_term_en_ns = T_CLK_TERM_EN_NS_0;
#endif /* _SENSOR_DEF_0_H_ */

#ifdef _SENSOR_DEF_1_H_
	g_earlyvideo_drvdata.sensor_bmp |= BIT(1);
	senif_param = &g_earlyvideo_drvdata.senif_param[1];
	is_param = &g_earlyvideo_drvdata.is_param[1];

	senif_param->lane_num = LVDS_DATA_NUM_1;
	is_param->route_bmp = 0;
	is_param->bit_depth = 8; /* FIXME */
	is_param->bayer_phase = SENSOR_BAYER_PHASE_1;

	i = 0;
	lane_idx_bmp = 0;
#ifdef LVDS_DATA_LANE_0_1
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_0_1);
	senif_param->lane_idx[0] = LVDS_DATA_LANE_0_1;
	i++;
#endif
#ifdef LVDS_DATA_LANE_1_1
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_1_1);
	senif_param->lane_idx[1] = LVDS_DATA_LANE_1_1;
	i++;
#endif
#ifdef LVDS_DATA_LANE_2_1
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_2_1);
	senif_param->lane_idx[2] = LVDS_DATA_LANE_2_1;
	i++;
#endif
#ifdef LVDS_DATA_LANE_3_1
	lane_idx_bmp |= BIT(LVDS_DATA_LANE_3_1);
	senif_param->lane_idx[3] = LVDS_DATA_LANE_3_1;
	i++;
#endif
	for (; i < EARLYVIDEO_MAX_MIPI_LANE_NUM; i++) {
		uint8_t idx;
		for (idx = 0; lane_idx_bmp & BIT(idx); idx++) {
			;
		}
		if (idx >= EARLYVIDEO_MAX_MIPI_LANE_NUM) {
			idx = 0;
		}
		lane_idx_bmp |= BIT(idx);
		senif_param->lane_idx[i] = idx;
	}
	senif_param->width = SENSOR_WIDTH_1;
	senif_param->height = SENSOR_HEIGHT_1;
	senif_param->bit_depth = SENSOR_BIT_DEPTH_1;
	senif_param->t_hs_settle_ns = T_HS_SETTLE_NS_1;
	senif_param->t_d_term_en_ns = T_D_TERM_EN_NS_1;
	senif_param->t_clk_settle_ns = T_CLK_SETTLE_NS_1;
	senif_param->t_clk_term_en_ns = T_CLK_TERM_EN_NS_1;
#endif /* _SENSOR_DEF_1_H_ */
	gen_da_setting(drvdata->da_cfg, DRAM_AGENT_ISW, DRAM_AGENT_EARLYVIDEO_NUM);

	/* Initialize share memory */
	agtx_video_init_shm_info(drvdata);

	/* Update sensor bitmap according to pool size */
	shm_info = (struct earlyvideo_shm_info *)gd->fb_base;

#ifdef _SENSOR_DEF_0_H_
	if (shm_info->segments[0].pool_size == 0) {
		g_earlyvideo_drvdata.sensor_bmp &= ~BIT(0);
	}
#endif
#ifdef _SENSOR_DEF_1_H_
	if (shm_info->segments[1].pool_size == 0) {
		g_earlyvideo_drvdata.sensor_bmp &= ~BIT(1);
	}
#endif
	printf("sensor bmp: %u\n", g_earlyvideo_drvdata.sensor_bmp);

#if CONFIG_AMP
	if (g_earlyvideo_drvdata.false_alarm.type != 0) {
		/* Initialize ISP frame table 0 - scaling down */
		ftbl = &drvdata->isp_ftbl[0];
		ftbl->idx = 0;
		ftbl->binding_path = 0;

		segment = &drvdata->shm_ptr->segments[ftbl->binding_path];
		ftbl->bayer_phase = drvdata->is_param[ftbl->binding_path].bayer_phase;

		ftbl->start_ispr[0] = 1;
		ftbl->start_ispr[1] = 0;
		ftbl->start_dms = 1;
		ftbl->start_sc = 1;
		ftbl->start_enh = 0;
		ftbl->start_mcvp = 0;
		ftbl->start_vpw[0] = 0;
		ftbl->start_vpw[1] = 1;

		ftbl->frame_width_i = segment->width;
		ftbl->frame_height_i = segment->height;
		ftbl->frame_width_o = EARLYVIDEO_SNAPSHOT_WIDTH;
		ftbl->frame_height_o = EARLYVIDEO_SNAPSHOT_HEIGHT;

		isp_calc_scale_down_tile(ftbl);
		isp_calc_pca_reg(ftbl);

		/* Calculate the parameters of SC */
		isp_calc_sc_ver_param(&ftbl->sc_param, ftbl->frame_height_i, ftbl->frame_height_o);
		isp_calc_sc_hor_param(&ftbl->sc_param, ftbl->frame_width_i, ftbl->frame_width_o, ftbl->pre_sc,
		                      ftbl->post_sc, ftbl->tile_n);

		isp_calc_da_tile_info(ftbl);

		/* Initialize ISP frame table 1 - processing MV */
		ftbl = &drvdata->isp_ftbl[1];
		ftbl->idx = 1;
		ftbl->binding_path = 0;

		segment = &drvdata->shm_ptr->segments[ftbl->binding_path];
		ftbl->bayer_phase = drvdata->is_param[ftbl->binding_path].bayer_phase;

		ftbl->start_ispr[0] = 1;
		ftbl->start_ispr[1] = 0;
		ftbl->start_dms = 0;
		ftbl->start_sc = 0;
		ftbl->start_enh = 1;
		ftbl->start_mcvp = 1;
		ftbl->start_vpw[0] = 0;
		ftbl->start_vpw[1] = 0;

		ftbl->frame_width_i = EARLYVIDEO_SNAPSHOT_WIDTH;
		ftbl->frame_height_i = EARLYVIDEO_SNAPSHOT_HEIGHT;
		ftbl->frame_width_o = EARLYVIDEO_SNAPSHOT_WIDTH;
		ftbl->frame_height_o = EARLYVIDEO_SNAPSHOT_HEIGHT;

		isp_calc_process_mv_tile(ftbl);
		isp_calc_da_tile_info(ftbl);

		/* Initialize ISP frame table 2 - reordering chroma pixels */
		ftbl = &drvdata->isp_ftbl[2];
		ftbl->idx = 2;
		ftbl->binding_path = 0;

		segment = &drvdata->shm_ptr->segments[ftbl->binding_path];
		ftbl->bayer_phase = drvdata->is_param[ftbl->binding_path].bayer_phase;

		ftbl->start_ispr[0] = 1;
		ftbl->start_ispr[1] = 1;
		ftbl->start_dms = 0;
		ftbl->start_sc = 0;
		ftbl->start_enh = 0;
		ftbl->start_mcvp = 0;
		ftbl->start_vpw[0] = 1;
		ftbl->start_vpw[1] = 1;

		ftbl->tile_n = 1;
		ftbl->pre_sc[0].first_x = 0;
		ftbl->pre_sc[0].first_out_x = 0;
		ftbl->pre_sc[0].last_out_x = EARLYVIDEO_SNAPSHOT_WIDTH - 1;
		ftbl->pre_sc[0].last_x = EARLYVIDEO_SNAPSHOT_WIDTH - 1;
		ftbl->pre_sc[0].tile_in_width = EARLYVIDEO_SNAPSHOT_WIDTH;
		ftbl->pre_sc[0].tile_out_width = EARLYVIDEO_SNAPSHOT_WIDTH;
		memcpy(&ftbl->post_sc[0], &ftbl->pre_sc[0], sizeof(struct tile_info));

		ftbl->frame_width_i = EARLYVIDEO_SNAPSHOT_WIDTH;
		ftbl->frame_height_i = EARLYVIDEO_SNAPSHOT_HEIGHT;
		ftbl->frame_width_o = EARLYVIDEO_SNAPSHOT_WIDTH;
		ftbl->frame_height_o = EARLYVIDEO_SNAPSHOT_HEIGHT;

		isp_calc_da_tile_info(ftbl);
	}
#endif /* CONFIG_AMP */
}
