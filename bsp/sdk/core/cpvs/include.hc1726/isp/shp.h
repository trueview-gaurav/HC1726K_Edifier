/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_SHP_H_
#define SAPPORO_SHP_H_

#include "autoconf.h"

#include "isp_utils.h"

#include "csr_bank_shp.h"

typedef enum isp_shp_mode {
	ISP_SHP_MODE_NORMAL = 0,
	ISP_SHP_MODE_DISABLE = 1,
	ISP_SHP_MODE_BYPASS = 2,
	ISP_SHP_MODE_INK = 3,
	ISP_SHP_MODE_NUM = 4,
} IspShpMode;

typedef struct isp_shp_cfg {
	IspShpMode mode;
	uint8_t ring_ctrl_en;
	uint8_t minmax_outer_bound;
	uint8_t minmax_central_bound;

	struct var {
		uint8_t central_bound;
		uint8_t edge_bound;
		uint32_t central_norm;
		uint32_t edge_norm;
	} var;

	uint16_t hpf_hpf_gain;
	uint16_t hpf_bpf_gain;
	uint16_t hpf_lpf_gain;
	uint16_t bpf_bpf_gain;
	uint16_t bpf_lpf_gain;

	struct high_band_gain_curve {
		uint16_t x[SHP_GAIN_CURVE_CTRL_POINT_NUM];
		uint16_t y[SHP_GAIN_CURVE_CTRL_POINT_NUM];
		uint16_t m_2s[SHP_GAIN_CURVE_CTRL_POINT_NUM - 1];
	} high_gain;

	struct middle_band_gain_curve {
		uint16_t x[SHP_GAIN_CURVE_CTRL_POINT_NUM];
		uint16_t y[SHP_GAIN_CURVE_CTRL_POINT_NUM];
		uint16_t m_2s[SHP_GAIN_CURVE_CTRL_POINT_NUM - 1];
	} mid_gain;

	uint8_t edge_gain;
	uint16_t edge_variance_tolarance;
	uint8_t peak_gain;
	uint8_t overshoot_gain;
	uint8_t undershoot_gain;
	uint16_t peak_variance_tolarance;
	uint16_t level_gain;
	uint8_t soft_clip_slope;

	struct isp_shp_luma_ctrl_gain {
		uint16_t x[SHP_LUMA_CTRL_GAIN_CTRL_POINT_NUM]; /**< Curve bin */
		uint8_t m_2s[SHP_LUMA_CTRL_GAIN_CTRL_POINT_NUM - 1]; /**< Curve slope */
		uint16_t y[SHP_LUMA_CTRL_GAIN_CTRL_POINT_NUM]; /**< Curve value */
	} luma_ctrl_gain; /**< Luma control gain curve */
} IspShpCfg;

// #if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
typedef struct isp_shp_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint32_t pix_num;
} IspShpRoiStatFrameCtrl;

typedef struct isp_shp_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} IspShpRoiStatTileCtrl;

typedef struct isp_shp_roi_stat {
	uint16_t lpf_luma_avg;
} IspShpRoiStat;

typedef struct isp_shp_rgl_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint16_t rgl_y_lpf_rgl_wd;
	uint16_t rgl_y_lpf_rgl_ht;
	uint32_t pix_num;
} IspShpRglStatFrameCtrl;

typedef struct isp_shp_rgl_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
	uint16_t rgl_y_lpf_x_cnt_ini;
	uint16_t rgl_y_lpf_y_cnt_ini;
	uint8_t rgl_y_lpf_r_cnt_ini;
} IspShpRglStatTileCtrl;

typedef struct isp_shp_rgl_stat {
	uint16_t lpf_luma_min[SHP_MAX_RGL_NUM];
	uint16_t lpf_luma_avg[SHP_MAX_RGL_NUM];
	uint32_t r_data[80]; // For FPGA verification
} IspShpRglStat;
// #endif

void isp_shp_set_cfg(volatile CsrBankShp *csr, const struct isp_shp_cfg *cfg);
void isp_shp_get_cfg(volatile CsrBankShp *csr, struct isp_shp_cfg *cfg);

void isp_shp_set_ink_num(volatile CsrBankShp *csr, uint8_t ink_num);
uint8_t isp_shp_get_ink_num(volatile CsrBankShp *csr);

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
/* ROI Stat */
void isp_shp_set_roi_stat_frame_ctrl(volatile CsrBankShp *csr, const struct isp_shp_roi_stat_frame_ctrl *cfg);
void isp_shp_get_roi_stat_frame_ctrl(volatile CsrBankShp *csr, struct isp_shp_roi_stat_frame_ctrl *cfg);
void isp_shp_set_roi_stat_tile_ctrl(volatile CsrBankShp *csr, const struct isp_shp_roi_stat_tile_ctrl *cfg);
void isp_shp_get_roi_stat_tile_ctrl(volatile CsrBankShp *csr, struct isp_shp_roi_stat_tile_ctrl *cfg);
void isp_shp_get_roi_stat(volatile CsrBankShp *csr, struct isp_shp_roi_stat *stat);

/* RGL Stat */
void isp_shp_set_rgl_stat_frame_ctrl(volatile CsrBankShp *csr, const struct isp_shp_rgl_stat_frame_ctrl *cfg);
void isp_shp_get_rgl_stat_frame_ctrl(volatile CsrBankShp *csr, struct isp_shp_rgl_stat_frame_ctrl *cfg);
void isp_shp_set_rgl_stat_tile_ctrl(volatile CsrBankShp *csr, const struct isp_shp_rgl_stat_tile_ctrl *cfg);
void isp_shp_get_rgl_stat_tile_ctrl(volatile CsrBankShp *csr, struct isp_shp_rgl_stat_tile_ctrl *cfg);
uint8_t isp_shp_get_rgl_stat_num_of_rgl(volatile CsrBankShp *csr);
void isp_shp_get_rgl_stat(volatile CsrBankShp *csr, uint8_t num_of_rgl, struct isp_shp_rgl_stat *stat);
#endif

#endif /* SAPPORO_SHP_H_ */
