/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_BSP_H_
#define SAPPORO_BSP_H_

#include "is_utils.h"
#include "csr_bank_bsp.h"


#define BSP_ROI_CONTRAST_AVG_PIXEL_MIN (16384) // Maximum contrast is 16383
#define BSP_RGL_CONTRAST_AVG_PIXEL_MIN (16384) // Maximum contrast is 16383
#define BSP_RGL_CONTRAST_AVG_PIXEL_MAX (262143) // Row buffer size

typedef struct is_bsp_dpd_cfg {
	struct is_dynamic_dpd {
		uint8_t enable;
		uint16_t dir_straight_th;
		uint16_t dir_slash_th;
		uint16_t dir_pt_min_th;
		uint16_t dir_dp_th;
		uint16_t flat_dt_th;
		uint16_t flat_pix_th;
		uint16_t smooth_dt_th;
		uint16_t smooth_pix_th;
	} ddpd;
} IsBspDpdCfg;

typedef struct is_bsp_dpc_cfg {
	uint8_t enable;
	uint16_t avg_ratio;
} IsBspDpcCfg;

typedef struct is_bsp_ctc_cfg {
	uint8_t enable;
	uint16_t avg_lb;
	uint16_t avg_ratio;
	uint16_t corr_region_th;
} IsBspCtcCfg;

typedef struct is_bsp_dpd_stat {
	uint32_t dp_num;
} IsBspDpdStat;

typedef struct is_bsp_ctc_stat {
	uint32_t corr_val;
	uint32_t smooth_str;
} IsBspCtcStat;

/*
 * _______________________________   _______________________________
 * | 0 0 | 0 1 | 0 2 | 0 1 | 0 0 |   |  0  |  1  |  2  |  1  |  0  |
 * _______________________________   _______________________________
 * | 0 1 | 1 1 | 1 2 | 1 1 | 0 1 |   |  1  |  3  |  4  |  3  |  1  |
 * _______________________________   _______________________________
 * | 0 2 | 0 1 | 2 2 | 1 2 | 0 2 |   |  2  |  1  |  5  |  1  |  2  |
 * _______________________________   _______________________________
 * | 0 1 | 1 1 | 1 2 | 1 1 | 0 1 |   |  1  |  3  |  4  |  3  |  1  |
 * _______________________________   _______________________________
 * | 0 0 | 0 1 | 0 2 | 0 1 | 0 0 |   |  0  |  1  |  2  |  1  |  0  |
 * _______________________________   _______________________________
 */
typedef struct is_bsp_chn_wgt_cfg {
	uint8_t coeff[BSP_CHN_WGT_ENTRY_NUM];
} IsBspChnWgtCfg;

typedef struct is_bsp_luma_est_cfg {
	uint8_t weight[INI_BAYER_PHASE_NUM];
} IsBspLumaEstCfg;

typedef struct is_bsp_remosaic_cfg {
	uint8_t enable;
	uint16_t coeff_2s[COLOR_CHN_NUM * INI_BAYER_PHASE_NUM];
} IsBspRemosaicCfg;

typedef struct is_bsp_y_est_mode_ctrl {
	enum is_luma_input_mode mode;
} IsBspYEstModeCtrl;

typedef struct is_bsp_tm_cfg {
	uint8_t enable;
	uint8_t y_lpf_str;
	struct is_tone_curve {
		uint16_t val[TM_CURVE_ENTRY_NUM];
	} curve; /**< Tone Mapping curve */
} IsBspTmCfg;

typedef struct is_bsp_wb_cfg {
	uint8_t enable;
	struct is_wb_gain {
		uint16_t g0[BSP_WB_GAIN_ENTRY_NUM]; /**< White balance r gain */
		uint16_t r[BSP_WB_GAIN_ENTRY_NUM]; /**< White balance r gain */
		uint16_t b[BSP_WB_GAIN_ENTRY_NUM]; /**< White balance r gain */
		uint16_t g1[BSP_WB_GAIN_ENTRY_NUM]; /**< White balance r gain */
	} gain;
} IsBspWbCfg;

typedef struct is_bsp_wb_bilinear_cfg {
	uint8_t enable;
	uint32_t x_cnt_ini;
	uint32_t y_cnt_ini;
	uint32_t x_cnt_step;
	uint32_t y_cnt_step;
	uint32_t size_x;
	uint32_t size_y;
} IsBspWbBilinearCfg;

typedef struct is_bsp_y_hist_roi_ctrl {
	enum is_luma_input_mode mode;
	uint16_t offset;
} IsBspYHistRoiCtrl;

typedef struct is_bsp_y_hist_roi_stat_frame_ctrl {
	struct rect_point roi;
} IsBspYHistRoiStatFrameCtrl;

typedef struct is_bsp_y_hist_roi_stat {
	uint8_t overflow;
	uint32_t hist[BSP_Y_HIST_ENTRY_NUM];
} IsBspYHistRoiStat;

/* ROI Y Avg */
typedef struct is_bsp_y_avg_roi_ctrl {
	enum is_luma_input_mode mode;
} IsBspYAvgRoiCtrl;

typedef struct is_bsp_y_avg_roi_stat_frame_ctrl {
	struct rect_point roi;
	uint32_t pix_num;
} IsBspYAvgRoiStatFrameCtrl;

typedef struct is_bsp_y_avg_roi_stat {
	uint16_t avg;
	uint32_t remainder;
} IsBspYAvgRoiStat;

/* RGL Y Avg*/
typedef struct is_bsp_y_avg_rgl_ctrl {
	enum is_luma_input_mode mode;
} IsBspYAvgRglCtrl;

typedef struct is_bsp_y_avg_rgl_stat_frame_ctrl {
	struct rect_point roi;
	uint16_t blk_ht;
	uint16_t blk_wd;
	uint32_t pix_num;
} IsBspYAvgRglStatFrameCtrl;

typedef struct is_bsp_y_avg_rgl_stat {
	uint8_t avg[BSP_Y_AVG_MAX_RGL_NUM];
} IsBspYAvgRglStat;

/* RGL Rtx */
typedef struct is_bsp_rtx_ctrl {
	enum is_luma_input_mode mode;
	uint8_t force_performed_phase;
	uint8_t cfa_peform_rtx[CFA_PHASE_NUM];
	uint8_t y_th_min;
	uint8_t y_th_max;
	uint8_t y_m;
	uint8_t dyn_range_th;
	uint8_t dyn_range_slope;
} IsBspRtxCtrl;

typedef struct is_bsp_rtx_rgl_stat_frame_ctrl {
	struct rect_point roi;
	uint16_t blk_ht;
	uint16_t blk_wd;
} IsBspRtxRglStatFrameCtrl;

typedef struct is_bsp_rtx_rgl_stat {
	uint16_t weight[BSP_RTX_MAX_RGL_NUM];
	uint16_t r[BSP_RTX_MAX_RGL_NUM];
	uint16_t g[BSP_RTX_MAX_RGL_NUM];
	uint16_t b[BSP_RTX_MAX_RGL_NUM];
} IsBspRtxRglStat;

typedef struct is_bsp_rtx_roi_stat {
	// TO-DO: remove when enable dip
} IsBspRtxRoiStat;

typedef struct is_rtx_rgl_param {
	uint16_t max_pix;
	uint8_t wgt;
} IsRtxRglParam;

/* ROI Gwd */
typedef struct is_bsp_gwd_ctrl {
	enum is_luma_input_mode mode;
	uint8_t y_th_min;
	uint8_t y_th_max;
	uint16_t y_slope_min;
	uint16_t y_slope_max;
	uint16_t resample_saturation;
	uint16_t saturation_th;
	uint16_t rto_gray_level_slope;
	uint16_t r_bias;
	uint16_t g_bias;
	uint16_t b_bias;
	uint16_t gain_prev_r;
	uint16_t gain_prev_g;
	uint16_t gain_prev_b;
} IsBspGwdCtrl;

typedef struct is_bsp_rtx_roi_stat_frame_ctrl {
	struct rect_point roi;
} IsBspRtxRoiStatFrameCtrl;

typedef struct is_bsp_gwd_roi_stat_frame_ctrl {
	struct rect_point roi;
} IsBspGwdRoiStatFrameCtrl;

typedef struct is_bsp_gwd_roi_stat {
	uint32_t sum[INI_BAYER_PHASE_NUM];
	uint32_t norm[INI_BAYER_PHASE_NUM];
} IsBspGwdRoiStat;

typedef struct is_bsp_gwd_rgl_stat_frame_ctrl {
	struct rect_point roi;
	uint16_t blk_ht;
	uint16_t blk_wd;
} IsBspGwdRglStatFrameCtrl;

typedef struct is_gwd_rgl_param {
	uint8_t avg;
} IsGwdRglParam;

typedef struct is_bsp_gwd_rgl_stat {
	struct is_gwd_rgl_param g[BSP_GWD_MAX_RGL_NUM];
	struct is_gwd_rgl_param r[BSP_GWD_MAX_RGL_NUM];
	struct is_gwd_rgl_param b[BSP_GWD_MAX_RGL_NUM];
} IsBspGwdRglStat;

/* ROI RGB Hist*/
typedef struct is_bsp_rgb_hist_ctrl {
	uint16_t offset;
} IsBspRgbHistCtrl;

typedef struct is_bsp_rgb_hist_roi_stat_frame_ctrl {
	struct rect_point roi;
} IsBspRgbHistRoiStatFrameCtrl;

typedef struct is_bsp_rgb_hist_roi_stat {
	uint32_t r_hist[BSP_RGB_HIST_ENTRY_NUM];
	uint32_t g_hist[BSP_RGB_HIST_ENTRY_NUM];
	uint32_t b_hist[BSP_RGB_HIST_ENTRY_NUM];
	uint8_t r_overflow;
	uint8_t g_overflow;
	uint8_t b_overflow;
} IsBspRgbHistRoiStat;

/* AF Ctrl */
typedef struct is_bsp_contrast_ctrl {
	uint8_t cfa_phase_en[CFA_PHASE_NUM];
	enum is_luma_input_mode mode;
	uint8_t y_th_min;
	uint8_t y_th_max;
	uint8_t y_m;
	struct contrast_h_iir_weight {
		uint16_t h1[BSP_CONTRAST_H_WGT_ENTRY_NUM];
		uint16_t h2[BSP_CONTRAST_H_WGT_ENTRY_NUM];
	} iir_weight;
	struct contrast_v_fir_weight {
		uint16_t v1[BSP_CONTRAST_V_WGT_ENTRY_NUM];
		uint16_t v2[BSP_CONTRAST_V_WGT_ENTRY_NUM];
	} fir_weight;
	uint16_t coring_th;
} IsBspContrastCtrl;

/* ROI Contrast */
typedef struct is_bsp_contrast_roi_stat_frame_ctrl {
	struct rect_point roi;
	uint32_t pix_num;
} IsBspContrastRoiStatFrameCtrl;

typedef struct is_bsp_contrast_roi_stat {
	uint16_t h1_avg;
	uint16_t h2_avg;
	uint16_t v1_avg;
	uint16_t v2_avg;
} IsBspContrastRoiStat;

/* RGL Contrast */
typedef struct is_bsp_contrast_rgl_stat_frame_ctrl {
	struct rect_point roi;
	uint16_t blk_ht;
	uint16_t blk_wd;
	uint32_t pix_num;
} IsBspContrastRglStatFrameCtrl;

typedef struct is_bsp_contrast_rgl_stat {
	uint16_t h1_avg[BSP_CONTRAST_MAX_RGL_NUM];
	uint16_t h2_avg[BSP_CONTRAST_MAX_RGL_NUM];
	uint16_t v1_avg[BSP_CONTRAST_MAX_RGL_NUM];
	uint16_t v2_avg[BSP_CONTRAST_MAX_RGL_NUM];
	uint8_t rgl_x_num;
	uint8_t rgl_y_num;
} IsBspContrastRglStat;

typedef struct is_bsp_cfa_phase_enable_cfg {
	uint8_t enable[CFA_PHASE_ENTRY_NUM];
} IsBspCfaPhaseEnableCfg;

/* IRQ mask */
void is_bsp_set_irq_mask_frame_end(volatile CsrBankBsp *csr, uint8_t irq_mask_frame_end);
uint8_t is_bsp_get_irq_mask_frame_end(volatile CsrBankBsp *csr);

/* Resolution */
void is_bsp_set_res(volatile CsrBankBsp *csr, const struct res *res);
void is_bsp_get_res(volatile CsrBankBsp *csr, struct res *res);

/* BSP-mode */
void is_bsp_set_mode(volatile CsrBankBsp *csr, uint8_t mode);
uint8_t is_bsp_get_mode(volatile CsrBankBsp *csr);

/* Input format */
void is_bsp_set_input_format(volatile CsrBankBsp *csr, const struct is_input_format *cfg);
void is_bsp_get_input_format(volatile CsrBankBsp *csr, struct is_input_format *cfg);

/* Output format */
void is_bsp_set_output_format(volatile CsrBankBsp *csr, const struct is_output_format *cfg);
void is_bsp_get_output_format(volatile CsrBankBsp *csr, struct is_output_format *cfg);

/* DPD + DPC + CTC */
void is_bsp_set_dpd_cfg(volatile CsrBankBsp *csr, const struct is_bsp_dpd_cfg *cfg);
void is_bsp_get_dpd_cfg(volatile CsrBankBsp *csr, struct is_bsp_dpd_cfg *cfg);
void is_bsp_get_dpd_stat(volatile CsrBankBsp *csr, struct is_bsp_dpd_stat *stat);

void is_bsp_set_dpc_cfg(volatile CsrBankBsp *csr, const struct is_bsp_dpc_cfg *cfg);
void is_bsp_get_dpc_cfg(volatile CsrBankBsp *csr, struct is_bsp_dpc_cfg *cfg);

void is_bsp_set_ctc_cfg(volatile CsrBankBsp *csr, const struct is_bsp_ctc_cfg *cfg);
void is_bsp_get_ctc_cfg(volatile CsrBankBsp *csr, struct is_bsp_ctc_cfg *cfg);
void is_bsp_get_ctc_stat(volatile CsrBankBsp *csr, struct is_bsp_ctc_stat *stat);

/* Channel Weighted Sum and Average */
void is_bsp_set_chn_wgt_cfg(volatile CsrBankBsp *csr, const struct is_bsp_chn_wgt_cfg *cfg);
void is_bsp_get_chn_wgt_cfg(volatile CsrBankBsp *csr, struct is_bsp_chn_wgt_cfg *cfg);

/* Luma Estimation*/
void is_bsp_set_luma_est_cfg(volatile CsrBankBsp *csr, const struct is_bsp_luma_est_cfg *cfg);
void is_bsp_get_luma_est_cfg(volatile CsrBankBsp *csr, struct is_bsp_luma_est_cfg *cfg);

/* Re-mosaic */
void is_bsp_set_remosaic_cfg(volatile CsrBankBsp *csr, const struct is_bsp_remosaic_cfg *cfg);
void is_bsp_get_remosaic_cfg(volatile CsrBankBsp *csr, struct is_bsp_remosaic_cfg *cfg);

/* TM */
void is_bsp_set_y_est_mode_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_est_mode_ctrl *cfg);
void is_bsp_get_y_est_mode_ctrl(volatile CsrBankBsp *csr, struct is_bsp_y_est_mode_ctrl *cfg);
void is_bsp_set_tm_cfg(volatile CsrBankBsp *csr, const struct is_bsp_tm_cfg *cfg);
void is_bsp_get_tm_cfg(volatile CsrBankBsp *csr, struct is_bsp_tm_cfg *cfg);

/* WB */
void is_bsp_set_wb_cfg(volatile CsrBankBsp *csr, const struct is_bsp_wb_cfg *cfg);
void is_bsp_get_wb_cfg(volatile CsrBankBsp *csr, struct is_bsp_wb_cfg *cfg);
void is_bsp_set_wb_bilinear_cfg(volatile CsrBankBsp *csr, const struct is_bsp_wb_bilinear_cfg *cfg);
void is_bsp_get_wb_bilinear_cfg(volatile CsrBankBsp *csr, struct is_bsp_wb_bilinear_cfg *cfg);

/* Statistics */

// CSR2SRAM
void is_bsp_set_csr2sram_sel(volatile CsrBankBsp *csr, uint8_t enable);
uint8_t is_bsp_get_csr2sram_sel(volatile CsrBankBsp *csr);

// AE
// Ctrl
void is_bsp_set_y_hist_roi_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_hist_roi_ctrl *cfg);
void is_bsp_get_y_hist_roi_ctrl(volatile CsrBankBsp *csr, struct is_bsp_y_hist_roi_ctrl *cfg);

void is_bsp_set_y_avg_roi_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_avg_roi_ctrl *cfg);
void is_bsp_get_y_avg_roi_ctrl(volatile CsrBankBsp *csr, struct is_bsp_y_avg_roi_ctrl *cfg);

void is_bsp_set_y_avg_rgl_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_avg_rgl_ctrl *cfg);
void is_bsp_get_y_avg_rgl_ctrl(volatile CsrBankBsp *csr, struct is_bsp_y_avg_rgl_ctrl *cfg);

// ROI Y hist
void is_bsp_set_y_hist_roi_stat_frame_ctrl(volatile CsrBankBsp *csr,
                                           const struct is_bsp_y_hist_roi_stat_frame_ctrl *cfg);
void is_bsp_get_y_hist_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, struct is_bsp_y_hist_roi_stat_frame_ctrl *cfg);
void is_bsp_set_y_hist_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t enable);
uint8_t is_bsp_get_y_hist_roi_stat_enable(volatile CsrBankBsp *csr);
void is_bsp_get_y_hist_roi_stat(volatile CsrBankBsp *csr, struct is_bsp_y_hist_roi_stat *stat);

// ROI Y avg
void is_bsp_set_y_avg_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                          const struct is_bsp_y_avg_roi_stat_frame_ctrl *cfg);
void is_bsp_get_y_avg_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                          struct is_bsp_y_avg_roi_stat_frame_ctrl *cfg);
void is_bsp_set_y_avg_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t idx, uint8_t enable);
uint8_t is_bsp_get_y_avg_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t idx);
void is_bsp_get_y_avg_roi_stat(volatile CsrBankBsp *csr, uint8_t idx, struct is_bsp_y_avg_roi_stat *stat);

// RGL Y avg
void is_bsp_set_y_avg_rgl_stat_frame_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_avg_rgl_stat_frame_ctrl *cfg);
void is_bsp_get_y_avg_rgl_stat_frame_ctrl(volatile CsrBankBsp *csr, struct is_bsp_y_avg_rgl_stat_frame_ctrl *cfg);
void is_bsp_set_y_avg_rgl_stat_enable(volatile CsrBankBsp *csr, uint8_t enable);
uint8_t is_bsp_get_y_avg_rgl_stat_enable(volatile CsrBankBsp *csr);
void is_bsp_get_y_avg_rgl_stat(volatile CsrBankBsp *csr, struct is_bsp_y_avg_rgl_stat *stat);

// AWB
// Ctrl
void is_bsp_set_rtx_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_rtx_ctrl *cfg);
void is_bsp_get_rtx_ctrl(volatile CsrBankBsp *csr, struct is_bsp_rtx_ctrl *cfg);

void is_bsp_set_gwd_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_gwd_ctrl *cfg);
void is_bsp_get_gwd_ctrl(volatile CsrBankBsp *csr, struct is_bsp_gwd_ctrl *cfg);

void is_bsp_set_rgb_hist_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_rgb_hist_ctrl *cfg);
void is_bsp_get_rgb_hist_ctrl(volatile CsrBankBsp *csr, struct is_bsp_rgb_hist_ctrl *cfg);

// RGL Rtx
void is_bsp_set_rtx_rgl_stat_frame_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_rtx_rgl_stat_frame_ctrl *cfg);
void is_bsp_get_rtx_rgl_stat_frame_ctrl(volatile CsrBankBsp *csr, struct is_bsp_rtx_rgl_stat_frame_ctrl *cfg);
void is_bsp_set_rtx_rgl_stat_enable(volatile CsrBankBsp *csr, uint8_t enable);
uint8_t is_bsp_get_rtx_rgl_stat_enable(volatile CsrBankBsp *csr);
void is_bsp_get_rtx_rgl_stat(volatile CsrBankBsp *csr, struct is_bsp_rtx_rgl_stat *stat);

// ROI Gwd
void is_bsp_set_gwd_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                        const struct is_bsp_gwd_roi_stat_frame_ctrl *cfg);
void is_bsp_get_gwd_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                        struct is_bsp_gwd_roi_stat_frame_ctrl *cfg);
void is_bsp_set_gwd_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t idx, uint8_t enable);
uint8_t is_bsp_get_gwd_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t idx);
void is_bsp_get_gwd_roi_stat(volatile CsrBankBsp *csr, uint8_t idx, struct is_bsp_gwd_roi_stat *stat);

// ROI RGB hist
void is_bsp_set_rgb_hist_roi_stat_frame_ctrl(volatile CsrBankBsp *csr,
                                             const struct is_bsp_rgb_hist_roi_stat_frame_ctrl *cfg);
void is_bsp_get_rgb_hist_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, struct is_bsp_rgb_hist_roi_stat_frame_ctrl *cfg);
void is_bsp_set_rgb_hist_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t enable);
uint8_t is_bsp_get_rgb_hist_roi_stat_enable(volatile CsrBankBsp *csr);
void is_bsp_get_rgb_hist_roi_stat(volatile CsrBankBsp *csr, struct is_bsp_rgb_hist_roi_stat *stat);

// AF
// Ctrl
void is_bsp_set_contrast_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_contrast_ctrl *cfg);
void is_bsp_get_contrast_ctrl(volatile CsrBankBsp *csr, struct is_bsp_contrast_ctrl *cfg);

// ROI Contrast
void is_bsp_set_contrast_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                             const struct is_bsp_contrast_roi_stat_frame_ctrl *cfg);
void is_bsp_get_contrast_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                             struct is_bsp_contrast_roi_stat_frame_ctrl *cfg);
void is_bsp_set_contrast_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t idx, uint8_t enable);
uint8_t is_bsp_get_contrast_roi_stat_enable(volatile CsrBankBsp *csr, uint8_t idx);
void is_bsp_get_contrast_roi_stat(volatile CsrBankBsp *csr, uint8_t idx, struct is_bsp_contrast_roi_stat *stat);

// RGL Contrast
void is_bsp_set_contrast_rgl_stat_frame_ctrl(volatile CsrBankBsp *csr,
                                             const struct is_bsp_contrast_rgl_stat_frame_ctrl *cfg);
void is_bsp_get_contrast_rgl_stat_frame_ctrl(volatile CsrBankBsp *csr, struct is_bsp_contrast_rgl_stat_frame_ctrl *cfg);
void is_bsp_set_contrast_rgl_stat_enable(volatile CsrBankBsp *csr, uint8_t enable);
uint8_t is_bsp_get_contrast_rgl_stat_enable(volatile CsrBankBsp *csr);
void is_bsp_get_contrast_rgl_stat(volatile CsrBankBsp *csr, struct is_bsp_contrast_rgl_stat *stat);

/* Cfa phase en */
void is_bsp_set_cfa_phase_enable_cfg(volatile CsrBankBsp *csr, const struct is_bsp_cfa_phase_enable_cfg *cfg);
void is_bsp_get_cfa_phase_enable_cfg(volatile CsrBankBsp *csr, struct is_bsp_cfa_phase_enable_cfg *cfg);

/* Debug */
void is_bsp_set_dbg_mon_sel(volatile CsrBankBsp *csr, uint8_t debug_mon_sel);
uint8_t is_bsp_get_dbg_mon_sel(volatile CsrBankBsp *csr);

/* ATPG */
void is_bsp_set_atpg_ctrl(volatile CsrBankBsp *csr, uint8_t atpg_ctrl);
uint8_t is_bsp_get_atpg_ctrl(volatile CsrBankBsp *csr);

/* Efuse */
uint8_t is_bsp_get_efuse_sensor_cfa_violation(volatile CsrBankBsp *csr);

/* Ink */
void is_bsp_set_ink_num(volatile CsrBankBsp *csr, uint8_t ink_num);
uint8_t is_bsp_get_ink_num(volatile CsrBankBsp *csr);

#endif /* SAPPORO_BSP_H_ */