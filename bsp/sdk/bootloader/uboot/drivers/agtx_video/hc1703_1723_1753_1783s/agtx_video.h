#ifndef AGTX_VIDEO_H_
#define AGTX_VIDEO_H_

#include <linux/types.h>

#include "da.h"
#include "isp.h"
#include "buffer_layout.h"

#define EARLYVIDEO_MAX_PATH_NUM (2)
#define EARLYVIDEO_MAX_MIPI_LANE_NUM (4)
#define EARLYVIDEO_MAX_HEIGHT ((1 << 16) - 1) /* BITWIDTH = 16 */
#define EARLYVIDEO_SNAPSHOT_WIDTH (320)
#define EARLYVIDEO_SNAPSHOT_HEIGHT (192)

/* IRQ numbers */
#define GIC_SPI_BASE (32)
#define IRQ_BSP_0 (16 + GIC_SPI_BASE)
#define IRQ_BSP_1 (26 + GIC_SPI_BASE)
#define IRQ_NRW (58 + GIC_SPI_BASE)
#define IRQ_VPW_0 (64 + GIC_SPI_BASE)
#define IRQ_VPW_1 (65 + GIC_SPI_BASE)

/* Video done flag */
#define VIDEO_DONE_SNAPSHOT (0x1)
#define VIDEO_DONE_PATH_0 (0x2)
#define VIDEO_DONE_PATH_1 (0x4)

/* Debugging use */
#define EARLYVIDEO_DEBUG (0)
#define SEC_TO_TICKS (1000000000ULL)

#if EARLYVIDEO_DEBUG
#define debug_print(format, args...) printf("[%s] " format, __func__, ##args)
#else
#define debug_print(format, args...) ((void)0)
#endif

/* SENIF data structures */
struct senif_csr {
	volatile struct csr_bank_senif_ctrl *senif_ctrl;
	volatile struct csr_bank_senif_syscfg *senif_syscfg;
	volatile struct csr_bank_slb *slb[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx *lvds_rx[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dec *lvds_dec[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx_phycfg *rxphy_phycfg[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx_ctrl *rxphy_ctrl[EARLYVIDEO_MAX_PATH_NUM];
};

struct senif_param {
	uint8_t lane_num;
	uint8_t lane_idx[EARLYVIDEO_MAX_MIPI_LANE_NUM];
	uint8_t bit_depth;
	uint32_t width;
	uint32_t height;
	uint32_t t_hs_settle_ns;
	uint32_t t_d_term_en_ns;
	uint32_t t_clk_settle_ns;
	uint32_t t_clk_term_en_ns;
};

/* IS data structures */
struct is_csr {
	/* IS */
	volatile struct csr_bank_is *is;
	volatile struct csr_bank_is_cfg *is_cfg;
	/* FE */
	volatile struct csr_bank_frame_time_gen *frame_time_gen[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_edp *edp[EARLYVIDEO_MAX_PATH_NUM];
	/* ISK */
	volatile struct csr_bank_isk *isk[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_gma *gma[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_fpnr *fpnr[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_crop *crop[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dbc *dbc[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dcc *dcc[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_lsc *lsc[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_bsp *bsp[EARLYVIDEO_MAX_PATH_NUM];
	/* DA */
	volatile struct csr_bank_pxw *iswroi[EARLYVIDEO_MAX_PATH_NUM];
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

/* False alarm detection */
struct false_alarm_info {
	uint8_t frame_num;
	uint8_t thres;
	uint8_t type;
};

/* Earlyvideo data structures */
struct earlyvideo_drvdata {
	struct senif_csr senif_csr;
	struct senif_param senif_param[EARLYVIDEO_MAX_PATH_NUM];
	struct is_csr is_csr;
	struct is_param is_param[EARLYVIDEO_MAX_PATH_NUM];
	struct isp_csr isp_csr;
#if ISP_USE_CCQ
	struct isp_ccq isp_ccq_s;
#endif
#if CONFIG_AMP
	struct false_alarm_info false_alarm;
#endif
	struct isp_frame_table isp_ftbl[EARLYVIDEO_ISP_FRAME_NUM];
	struct dram_agent_config da_cfg[DRAM_AGENT_EARLYVIDEO_NUM];
	struct earlyvideo_shm_info *shm_ptr;
	uint8_t sensor_bmp; /* BIT(0): sensor 0, BIT(1): sensor 1 */
	uint8_t done_flag;
};

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

typedef void (*CbFuncPtr)(uint8_t);

struct agtx_video_route {
	uint8_t path;
	bool image_capture;
	/* If the callback is NULL, sw_light_meter is disabled; otherwise, it is enabled. */
	CbFuncPtr sw_light_meter_cb;
};

struct sensor_info {
	void (*start)(int);
	void (*set_exposure)(int);
	void (*set_fps)(int);
	int i2c_slave_addr;
};

/* SENIF functions */
void senif_init_hw(void);
void senif_trigger_start(void);

/* IS functions */
void is_init_hw(void);
void is_enable_dram_route(uint8_t path);
void is_adjust_kernel_height(uint8_t path, uint8_t *frame_num);
void is_enable_bsp_route(uint8_t path);
void is_trigger_start(uint8_t path);
void is_install_irq_handler(void);
void is_set_irq_cb(uint8_t path, CbFuncPtr cb);
#if EARLYVIDEO_DEBUG
void is_poll_da(uint8_t path);
void is_show_checksum(void);
void is_print(void);
#endif

void agtx_video_init_drvdata(struct earlyvideo_drvdata *drvdata);
void agtx_video_init(void);
void agtx_video_adjust_light_meter_height(uint8_t path, uint8_t *frame_num);
void agtx_video_start(struct agtx_video_route *route);
void agtx_video_start_snapshot(void);

extern int uboot_irq_install_handler(uint32_t irq, void (*handler)(uint32_t, void *), void *arg);

#endif /* AGTX_VIDEO_H_ */
