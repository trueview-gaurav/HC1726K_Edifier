#include "agtx_video.h"

#include <stdlib.h>
#include <common.h>

#include "hw_dram.h"
#include "csr_bank_pxw.h"

#ifdef CONFIG_EARLYVIDEO
#include "sensor_settings.h"
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
#include "sensor_settings_1.h"
#endif
#endif

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

DECLARE_GLOBAL_DATA_PTR;

static inline void __calc_frame_size(struct earlyvideo_shm_segment *segment, struct is_param *param)
{
	/* TODO: Support YUV format through configuration */
	segment->frame_size = segment->width * segment->height * param->bit_depth / 8;
}

void is_init_dram_agent(struct is_drvdata *drvdata)
{
	struct earlyvideo_shm_segment *segment = NULL;
	volatile struct csr_bank_pxw *isw = NULL;
	uint8_t path;

	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		segment = &drvdata->shm_ptr->segments[path];
		isw = drvdata->csr.isw[path];
		/* General setting */
		isw->irq_mask_frame_end = 1;
		isw->irq_mask_bw_insufficient = 1;
		isw->irq_mask_overflow = 1;
		isw->irq_mask_access_violation = 1;
		isw->irq_mask_burst_fifo_full = 1;
		isw->irq_mask_resp_error = 1;
		isw->col_addr_type = COL_ADDR_TYPE;
		isw->bank_group_type = 0;
		isw->bank_interleave_type = BANK_ADDR_TYPE + 2;
		isw->frame_start_mode = 1;
		/* Settings related to the parameter */
		isw->y_only_e = 1; /* FIXME */
		isw->y_only_o = 1; /* FIXME */
		isw->pixel_flush_len = segment->width;
		isw->msb_only = drvdata->path_param[path].bit_depth == 8 ? 1 : 0;
		if (isw->msb_only) {
			isw->fifo_end_phase = (segment->width - 1) % 8;
			isw->fifo_flush_len = isw->pixel_flush_len / 8;
			isw->fifo_flush_len_last = 0;
			isw->package_size_last = 0;
		} else {
			isw->fifo_end_phase = (segment->width - 1) % 32;
			isw->fifo_flush_len = isw->pixel_flush_len / 8 + isw->pixel_flush_len / 32;
			isw->fifo_flush_len_last = 5;
			isw->package_size_last = 5;
		}
		isw->fifo_start_phase = 0;
		isw->width = segment->width;
		isw->height = segment->height * segment->uboot_capture_num;
		isw->h_end = segment->width - 1;
		isw->v_end = segment->height * segment->uboot_capture_num - 1;

		isw->ini_addr_linear_0 = segment->base_addr >> 3;
	}
}

void is_init_shm_info(struct is_drvdata *drvdata)
{
	struct earlyvideo_shm_info *shm_info = NULL;
	uint32_t pool_size[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t frame_size[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t keep_num[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t total_vb_size = 0;
	uint32_t path_vb_size[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint32_t duration = 0;
	uint8_t path_fps[EARLYVIDEO_MAX_PATH_NUM] = { 0 };
	uint8_t path;

	/* 1. Assign the address of shared memory from global data */
	drvdata->shm_ptr = (struct earlyvideo_shm_info *)gd->fb_base;
	memset((void *)drvdata->shm_ptr, 0, EV_DRIVER_SHM_SIZE);
	shm_info = drvdata->shm_ptr;

	/* 2. Get the memory information from Uboot environment variable */
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

	/* 3. Calculate the frame size */
	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		__calc_frame_size(&shm_info->segments[path], &drvdata->path_param[path]);
		frame_size[path] = shm_info->segments[path].frame_size;
		debug_print("frame_size[%u] = %u\n", path, frame_size[path]);
	}

	/* 4. Calculate the pool size */
	if (drvdata->sensor_bmp == (BIT(0) | BIT(1))) {
		/* Dual sensor */
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

	/* 5. Check the calculated pool sizes */
	if ((pool_size[0] + pool_size[1]) > total_vb_size) {
		printf("Invalid pool size path[0] %d + path[1] %d > total_vb_size %d\n", pool_size[0], pool_size[1],
		       total_vb_size);
		printf("Disable the early video !\n");
		pool_size[0] = 0;
		pool_size[1] = 0;
	}
	debug_print("Before pool_size[0] = %u\n", pool_size[0]);
	debug_print("Before pool_size[1] = %u\n", pool_size[1]);
	/* 6. Adjust the pool_size for shared memory */
	if (pool_size[0] != 0) {
		pool_size[0] -= EV_DRIVER_SHM_SIZE;
	} else if (pool_size[1] != 0) {
		pool_size[1] -= EV_DRIVER_SHM_SIZE;
	}
	shm_info->segments[0].pool_size = pool_size[0];
	shm_info->segments[1].pool_size = pool_size[1];
	debug_print("After pool_size[0] = %u\n", pool_size[0]);
	debug_print("After pool_size[1] = %u\n", pool_size[1]);

	/* 7. Calculate frame number */
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

	/* 8. Assign the base address */
	shm_info->segments[0].base_addr = gd->fb_base + EV_DRIVER_SHM_SIZE;
	shm_info->segments[1].base_addr = shm_info->segments[0].base_addr + pool_size[0];

	/* FIXME: Replace these assignments with the actual snapshot mechanism */
	shm_info->segments[0].raw_addr = shm_info->segments[0].base_addr;
	shm_info->segments[0].snapshot_size = 0;
	shm_info->segments[0].mv_addr = shm_info->segments[0].base_addr;
	shm_info->segments[0].mv_size = 0;
	shm_info->segments[1].raw_addr = shm_info->segments[1].base_addr;
	shm_info->segments[1].snapshot_size = 0;
	shm_info->segments[1].mv_addr = shm_info->segments[1].base_addr;
	shm_info->segments[1].mv_size = 0;

	debug_print("segments[0].base_addr = 0x%08x\n", shm_info->segments[0].base_addr);
	debug_print("segments[0].pool_size = %u\n", shm_info->segments[0].pool_size);
	debug_print("segments[0].frame_size = %u\n", shm_info->segments[0].frame_size);
	debug_print("segments[0].total_frame_num = %u\n", shm_info->segments[0].total_frame_num);
	debug_print("segments[0].uboot_capture_num = %u\n", shm_info->segments[0].uboot_capture_num);
	debug_print("segments[1].base_addr = 0x%08x\n", shm_info->segments[1].base_addr);
	debug_print("segments[1].pool_size = %u\n", shm_info->segments[1].pool_size);
	debug_print("segments[1].frame_size = %u\n", shm_info->segments[1].frame_size);
	debug_print("segments[1].total_frame_num = %u\n", shm_info->segments[1].total_frame_num);
	debug_print("segments[1].uboot_capture_num = %u\n", shm_info->segments[1].uboot_capture_num);
}
