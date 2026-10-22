/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DHZ_H_
#define SAPPORO_DHZ_H_

#include "isp_utils.h"
#include "csr_bank_dhz.h"

typedef enum vp_dhz_mode {
	VP_DHZ_MODE_NORMAL = 0,
	VP_DHZ_MODE_BYPASS,
	VP_DHZ_MODE_NUM,
} VpDhzMode;

typedef struct isp_dhz_rgl_stat_frame_ctrl {
	uint32_t rgl_x_num;
	uint32_t rgl_y_num;
	uint32_t rgl_x_cnt_step;
	uint32_t rgl_y_cnt_step;
} IspDhzRglCtrl;

typedef struct isp_dhz_rgl_stat_tile_ctrl {
	uint32_t rgl_x_cnt_ini;
	uint32_t rgl_y_cnt_ini;
} IspDhzTileRglCtrl;

typedef struct isp_dhz_rgl_cfg {
	uint16_t gain[DHZ_MAX_RGL_NUM];
	uint16_t offset[DHZ_MAX_RGL_NUM];
} IspDhzRglCfg;

typedef struct isp_dhz_cfg {
	uint8_t mode;
	uint16_t strength;
	uint16_t y_gain_max;
	uint16_t c_gain_max;
	uint16_t y_dc;
	uint16_t u_dc;
	uint16_t v_dc;
	uint8_t y_protect;
} IspDhzCfg;

typedef struct isp_dhz_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint32_t pix_num;
} IspDhzRoiStatFrameCtrl;

typedef struct isp_dhz_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} IspDhzRoiStatTileCtrl;

typedef struct isp_dhz_roi_stat {
	uint16_t luma_avg;
} IspDhzRoiStat;

/* IRQ mask */
void isp_dhz_set_irq_mask_frame_end(volatile CsrBankDhz *csr, uint8_t irq_mask_frame_end);
uint8_t isp_dhz_get_irq_mask_frame_end(volatile CsrBankDhz *csr);

/* Resolution */
void isp_dhz_set_res(volatile CsrBankDhz *csr, const Res *res);
void isp_dhz_get_res(volatile CsrBankDhz *csr, Res *res);

/* Dehaze */
void isp_dhz_set_rgl_ctrl(volatile CsrBankDhz *csr, const struct isp_dhz_rgl_stat_frame_ctrl *cfg);
void isp_dhz_get_rgl_ctrl(volatile CsrBankDhz *csr, struct isp_dhz_rgl_stat_frame_ctrl *cfg);
void isp_dhz_set_tile_rgl_ctrl(volatile CsrBankDhz *csr, const struct isp_dhz_rgl_stat_tile_ctrl *cfg);
void isp_dhz_get_tile_rgl_ctrl(volatile CsrBankDhz *csr, struct isp_dhz_rgl_stat_tile_ctrl *cfg);
uint8_t isp_dhz_get_rgl_cfg_num_of_rgl(volatile CsrBankDhz *csr);
void isp_dhz_set_rgl_cfg(volatile CsrBankDhz *csr, uint8_t num_of_rgl, const struct isp_dhz_rgl_cfg *cfg);
void isp_dhz_get_rgl_cfg(volatile CsrBankDhz *csr, uint8_t num_of_rgl, struct isp_dhz_rgl_cfg *cfg);
uint8_t isp_dhz_get_rgl_attr_clk_sel(volatile CsrBankDhz *csr);
void isp_dhz_set_cfg(volatile CsrBankDhz *csr, const struct isp_dhz_cfg *cfg);
void isp_dhz_get_cfg(volatile CsrBankDhz *csr, struct isp_dhz_cfg *cfg);

/* Statistics */
void isp_dhz_set_roi_stat_frame_ctrl(volatile CsrBankDhz *csr, const struct isp_dhz_roi_stat_frame_ctrl *cfg);
void isp_dhz_get_roi_stat_frame_ctrl(volatile CsrBankDhz *csr, struct isp_dhz_roi_stat_frame_ctrl *cfg);
void isp_dhz_set_roi_stat_tile_ctrl(volatile CsrBankDhz *csr, const struct isp_dhz_roi_stat_tile_ctrl *cfg);
void isp_dhz_get_roi_stat_tile_ctrl(volatile CsrBankDhz *csr, struct isp_dhz_roi_stat_tile_ctrl *cfg);
void isp_dhz_set_roi_stat_clear(volatile CsrBankDhz *csr, uint8_t clear);
uint8_t isp_dhz_get_roi_stat_clear(volatile CsrBankDhz *csr);
void isp_dhz_set_roi_stat_enable(volatile CsrBankDhz *csr, uint8_t enable);
uint8_t isp_dhz_get_roi_stat_enable(volatile CsrBankDhz *csr);
void isp_dhz_get_roi_stat(volatile CsrBankDhz *csr, struct isp_dhz_roi_stat *stat);

/* Debug */
void isp_dhz_set_dbg_mon_sel(volatile CsrBankDhz *csr, uint8_t debug_mon_sel);
uint8_t isp_dhz_get_dbg_mon_sel(volatile CsrBankDhz *csr);

#endif /* SAPPORO_DHZ_H_ */
