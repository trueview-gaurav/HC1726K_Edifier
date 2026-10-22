#ifndef UBOOT_AGTX_VIDEO_H_
#define UBOOT_AGTX_VIDEO_H_

#include <linux/types.h>

#define EARLYVIDEO_MAX_PATH_NUM (2)
#define EARLYVIDEO_DEBUG 0
#define EARLYVIDEO_MAX_HEIGHT ((1 << 16) - 1) /* BITWIDTH = 16 */

#if EARLYVIDEO_DEBUG
#define POLLING_CNT 1000000
#define debug_print(format, args...) printf("[%s] " format, __func__, ##args)
#else
#define debug_print(format, args...) ((void)0)
#endif

/* IS functions */
void is_init_drvdata(void);
void is_init_hw(void);
void is_enable_dram_route(uint8_t path);
void is_enable_bsp_route(uint8_t path);
void is_trigger_start(uint8_t path);
void is_poll_bsp_path(uint8_t path);
#if EARLYVIDEO_DEBUG
void is_poll_da(uint8_t path);
void is_show_checksum(void);
void is_print(void);
#endif

/* SENIF functions */
void senif_init_drvdata(void);
void senif_init_hw(void);
void senif_trigger_start(void);

/* IS data structures */
struct is_csr {
	/* IS */
	volatile struct csr_bank_is *is;
	volatile struct csr_bank_is_cfg *is_cfg;
	/* FE */
	volatile struct csr_bank_tg *tg[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_edp *edp[EARLYVIDEO_MAX_PATH_NUM];
	/* ISK */
	volatile struct csr_bank_isk *isk[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_crop *crop[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dbc *dbc[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dcc *dcc[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_lsc *lsc[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dfk *dfk[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_bsp *bsp[EARLYVIDEO_MAX_PATH_NUM];
	/* DA */
	volatile struct csr_bank_pxw *isw[EARLYVIDEO_MAX_PATH_NUM];
#if EARLYVIDEO_DEBUG
	volatile struct csr_bank_is_checksum *is_checksum;
	volatile struct csr_bank_isk_checksum *isk_checksum[EARLYVIDEO_MAX_PATH_NUM];
#endif
};

#define ENABLE_DRAM_ROUTE BIT(0)
#define ENABLE_BSP_ROUTE BIT(1)
struct is_param {
	uint8_t bit_depth;
	uint8_t bayer_phase;
	uint8_t route_bmp;
};

struct is_drvdata {
	struct is_csr csr;
	struct is_param path_param[EARLYVIDEO_MAX_PATH_NUM];
	struct earlyvideo_shm_info *shm_ptr;
	uint8_t sensor_bmp; /* BIT(0): sensor 0, BIT(1): sensor 1 */
};

#define EV_DRIVER_SHM_SIZE (4 * 1024)
typedef union uboot_hw_motion_vec {
	struct {
		int64_t x0 : 10;
		int64_t y0 : 10;
		int64_t valid0 : 1;
		int64_t padding0 : 11;
		int64_t x1 : 10;
		int64_t y1 : 10;
		int64_t valid1 : 1;
		int64_t padding1 : 11;
	};
	int64_t value;
} UbootHwMotionVec;

struct uboot_mv_info {
	UbootHwMotionVec *phy_addr; /* Address of the starting point of motion vectors (MV) */
	uint32_t fps; /* Frame rate of the sensor in U-Boot */
	uint32_t duration; /* Duration of one frame in jiffies (10ms) */
	uint16_t win_width; /* Width of the window in pixels */
	uint16_t win_height; /* Height of the window in pixels */
};

struct uboot_snapshot_info {
	void *phy_addr_y; /* Address of the frame's starting point, containing the luminance data of the YUV format. */
	void *phy_addr_c; /* Address of the chrominance data of the YUV format. */
	uint32_t size_y; /* Size of the luminance data in bytes. */
	uint32_t size_c; /* Size of the chrominance data in bytes. */
	uint16_t width; /* Width of the snapshot in pixels. */
	uint16_t height; /* Height of the snapshot in pixels. */
	uint8_t bit_depth; /* Bit depth of the snapshot. */
};

struct early_detect_info {
	struct uboot_mv_info mv;
	struct uboot_snapshot_info snapshot;
	uint8_t is_used; /* Flag indicating whether these information has been used and can be freed. */
};

/*
 * Early Video Buffer Layout
 * ==================================================================== early_vb_memaddr
 * EV_DRIVER_SHM_SIZE
 *  - Shared memory between U-Boot and Linux early video driver
 *
 * ==================================================================== segments[0].base_addr
 * SNAPSHOT_SIZE
 *  - For the scaling down pass VPW buffer
 * SNAPSHOT_SIZE
 *  - For the reordering chroma pixels pass VPW buffer (snapshot for RTOS)
 * SNAPSHOT_SIZE * 2
 *  - For the processing MV pass NRW/MER buffers
 *
 * ==================================================================== segments[0].mv_addr
 * MV_SIZE
 *  - For the processing MV pass MV8W/MV8R buffer (MV for RTOS)
 * MV_SIZE
 *  - For the processing MV pass VENC_MVW buffer
 *
 * ==================================================================== segments[0].raw_addr
 * POOL_SIZE
 *  - Raw buffer pool
 *
 * ==================================================================== segments[1].base_addr
 * (Same layout as segments[0])
 */

/* Structure for shared memory between Uboot and Linux early video driver */
struct earlyvideo_shm_segment {
	uint32_t base_addr;
	uint32_t snapshot_size;
	uint32_t mv_addr; /* Equals base_addr + 4 * snapshot_size */
	uint32_t mv_size;
	uint32_t raw_addr; /* Equals mv_addr + 2 * mv_size */
	uint32_t pool_size;
	uint32_t frame_size;
	uint32_t total_frame_num;
	uint32_t uboot_capture_num;
	uint32_t keep_num;
	/* Resolution */
	uint32_t width;
	uint32_t height;
	/* Sensor data */
	uint32_t fps;
	uint32_t exps_time_us;
	uint32_t gain32;
	/* Snapshot and MV information */
	struct early_detect_info early_detect_info;
};
struct earlyvideo_shm_info {
	struct earlyvideo_shm_segment segments[EARLYVIDEO_MAX_PATH_NUM];
};

#endif
