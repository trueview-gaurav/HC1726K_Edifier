/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_HDR_H_
#define SAPPORO_HDR_H_

#include "isp_utils.h"
#include "csr_bank_hdr.h"

typedef enum isp_hdr_mode {
	ISP_HDR_MODE_NORMAL = 0,
	ISP_HDR_MODE_MONO_NORMAL = 1,
	ISP_HDR_MODE_BYPASS_SE = 2,
	ISP_HDR_MODE_BYPASS_LE = 3,
	ISP_HDR_MODE_INK = 4,
	ISP_HDR_MODE_NUM,
} IspHdrMode;

typedef enum isp_hdr_anti_gma_mode {
	ISP_HDR_ANTI_GMA_MODE_NORMAL = 0,
	ISP_HDR_ANTI_GMA_MODE_DISABLE = 1,
	ISP_HDR_ANTI_GMA_MODE_NUM = 2,
} IspHdrAntiGmaMode;

typedef struct isp_hdr_anti_gma_cfg {
	enum isp_hdr_anti_gma_mode long_exp_mode; /* Long Exposure Anti-Gamma Mode */
	enum isp_hdr_anti_gma_mode short_exp_mode; /* Short Exposure Anti-Gamma Mode */
} IspHdrAntiGmaCfg;

typedef struct isp_hdr_exp_cfg {
	uint8_t exp_long_early;
	uint16_t exp_ratio;
	uint16_t exp_ratio_inv;
	uint16_t se_exp_ratio_min_int;
} IspHdrExpCfg;

typedef struct isp_hdr_weight_cfg {
	uint8_t weight_mode;
	uint8_t fallback_mode;
	uint16_t le_weight_th_max;
	uint8_t le_weight_slope;
	uint8_t le_weight_min;
	uint8_t le_weight_max;
	uint8_t le_overflow_protect_en;
	uint16_t le_overflow_protect_r_th;
	uint16_t le_overflow_protect_g_th;
	uint16_t le_overflow_protect_b_th;
	uint8_t le_overflow_ratio;
	uint8_t le_var_weight;
} IspHdrWeightCfg;

typedef struct isp_hdr_fb_cfg {
	uint16_t local_fb_th;
	uint8_t local_fb_slope;
	uint8_t local_fb_min;
	uint8_t local_fb_max;
	uint8_t frame_fb_strength;
	uint8_t fb_target;
	uint8_t fb_alpha;
	uint8_t mismatch_var_gain_2s;
} IspHdrFbCfg;

typedef struct isp_hdr_y_tone_cfg {
	uint16_t offset_tbl[HDR_LTM_RGL_HOR_NUM][HDR_LTM_RGL_VER_NUM];
} IspHdrYToneCfg;

typedef struct isp_hdr_ltm_enable {
	uint8_t enable; /* HDR Tone Mapping Enable */
	uint8_t bilinear_en;
} IspHdrLtmEnable;

typedef struct isp_hdr_ltm_cfg {
	uint16_t curve[HDR_LTM_RGL_NUM][HDR_LTM_CURVE_ENTRY_NUM]; // 64 x 257
	uint8_t global_en;
} IspHdrLtmCfg;

typedef struct isp_hdr_rgl_frame_ctrl {
	uint32_t rgl_x_cnt_step_cuv;
	uint32_t rgl_y_cnt_step_cuv;
	uint8_t rgl_h_num_cuv;
	uint8_t rgl_v_num_cuv;
} IspHdrRglFrameCtrl;

typedef struct isp_hdr_rgl_tile_ctrl {
	uint32_t rgl_y_cnt_ini_cuv;
	uint32_t rgl_x_cnt_ini_cuv;
} IspHdrRglTileCtrl;

// TO-DO: remove after DIP engine start
typedef struct isp_hdr_tm_cfg {
	//
} IspHdrTmCfg;

typedef struct isp_hdr_awb_cfg {
	uint8_t enable;
	uint16_t gain[HDR_AWB_CHN_NUM]; /* HDR White Balance Gain */
} IspHdrAwbCfg;

typedef enum isp_hdr_gma_mode {
	ISP_HDR_GMA_MODE_NORMAL = 0,
	ISP_HDR_GMA_MODE_DISABLE = 1,
	ISP_HDR_GMA_MODE_NUM = 2,
} IspHdrGmaMode;

typedef struct isp_hdr_gma_cfg {
	enum isp_hdr_gma_mode mode; /* HDR Gamma Mode */
} IspHdrGmaCfg;

typedef struct isp_hdr_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint32_t pix_num;
} IspHdrRoiStatFrameCtrl;

typedef struct isp_hdr_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} IspHdrRoiStatTileCtrl;

typedef struct isp_hdr_roi_stat {
	uint8_t overflow;
	uint32_t hist[HDR_HIST_ENTRY_NUM]; // Y Output Histogram [60]
} IspHdrRoiStat;

typedef struct isp_hdr_rgl_stat_frame_ctrl {
	uint32_t rgl_x_cnt_step_hist;
	uint32_t rgl_y_cnt_step_hist;
	uint16_t sy;
	uint16_t ey;
	uint16_t y_hist_offset;
	uint8_t rgl_h_num_hist;
	uint8_t rgl_v_num_hist;
} IspHdrRglStatFrameCtrl;

typedef struct isp_hdr_rgl_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
	uint32_t rgl_x_cnt_ini_hist;
	uint32_t rgl_y_cnt_ini_hist;
	uint8_t hist_clear;
} IspHdrRglStatTileCtrl;

typedef struct isp_hdr_rgl_stat {
	uint16_t y_hist_hist[HDR_LTM_RGL_NUM][HDR_HIST_ENTRY_NUM]; // Y Input Histogram [64][60]
	uint8_t rgl_h_num_hist;
	uint8_t rgl_v_num_hist;
} IspHdrRglStat;

/* IRQ mask */
void isp_hdr_set_irq_mask_frame_end(volatile CsrBankHdr *csr, uint8_t irq_mask_frame_end);
uint8_t isp_hdr_get_irq_mask_frame_end(volatile CsrBankHdr *csr);

/* Resolution */
void isp_hdr_set_res(volatile CsrBankHdr *csr, const struct res *res);
void isp_hdr_get_res(volatile CsrBankHdr *csr, struct res *res);

/* Bayer */
void isp_hdr_set_ini_bayer_phase(volatile CsrBankHdr *csr, enum ini_bayer_phase bayer);
enum ini_bayer_phase isp_hdr_get_ini_bayer_phase(volatile CsrBankHdr *csr);

/* HDR */
void isp_hdr_set_mode(volatile CsrBankHdr *csr, enum isp_hdr_mode mode);
enum isp_hdr_mode isp_hdr_get_mode(volatile CsrBankHdr *csr);
void isp_hdr_set_en(volatile CsrBankHdr *csr, uint8_t hdr_en);
uint8_t isp_hdr_get_en(volatile CsrBankHdr *csr);
void isp_hdr_set_anti_gma_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_anti_gma_cfg *cfg);
void isp_hdr_get_anti_gma_cfg(volatile CsrBankHdr *csr, struct isp_hdr_anti_gma_cfg *cfg);
void isp_hdr_set_exp_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_exp_cfg *cfg);
void isp_hdr_get_exp_cfg(volatile CsrBankHdr *csr, struct isp_hdr_exp_cfg *cfg);
void isp_hdr_set_weight_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_weight_cfg *cfg);
void isp_hdr_get_weight_cfg(volatile CsrBankHdr *csr, struct isp_hdr_weight_cfg *cfg);
void isp_hdr_set_fb_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_fb_cfg *cfg);
void isp_hdr_get_fb_cfg(volatile CsrBankHdr *csr, struct isp_hdr_fb_cfg *cfg);
void isp_hdr_set_y_tone_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_y_tone_cfg *cfg, int tile_dir);
void isp_hdr_get_y_tone_cfg(volatile CsrBankHdr *csr, struct isp_hdr_y_tone_cfg *cfg);
void isp_hdr_set_ltm_enable(volatile CsrBankHdr *csr, const struct isp_hdr_ltm_enable *cfg);
void isp_hdr_get_ltm_enable(volatile CsrBankHdr *csr, struct isp_hdr_ltm_enable *cfg);
void isp_hdr_set_ltm_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_ltm_cfg *cfg,
                         const struct isp_hdr_rgl_frame_ctrl *frame_ctrl, int tile_dir);
void isp_hdr_get_ltm_cfg(volatile CsrBankHdr *csr, struct isp_hdr_ltm_cfg *cfg);
void isp_hdr_set_awb_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_awb_cfg *cfg);
void isp_hdr_get_awb_cfg(volatile CsrBankHdr *csr, struct isp_hdr_awb_cfg *cfg);
void isp_hdr_set_gma_cfg(volatile CsrBankHdr *csr, const struct isp_hdr_gma_cfg *cfg);
void isp_hdr_get_gma_cfg(volatile CsrBankHdr *csr, struct isp_hdr_gma_cfg *cfg);
void isp_hdr_set_rgl_frame_ctrl(volatile CsrBankHdr *csr, const struct isp_hdr_rgl_frame_ctrl *cfg);
void isp_hdr_get_rgl_frame_ctrl(volatile CsrBankHdr *csr, struct isp_hdr_rgl_frame_ctrl *cfg);
void isp_hdr_set_rgl_tile_ctrl(volatile CsrBankHdr *csr, const struct isp_hdr_rgl_tile_ctrl *cfg);
void isp_hdr_get_rgl_tile_ctrl(volatile CsrBankHdr *csr, struct isp_hdr_rgl_tile_ctrl *cfg);

/* Statistics */
// ROI
void isp_hdr_set_roi_stat_frame_ctrl(volatile CsrBankHdr *csr, const struct isp_hdr_roi_stat_frame_ctrl *cfg);
void isp_hdr_get_roi_stat_frame_ctrl(volatile CsrBankHdr *csr, struct isp_hdr_roi_stat_frame_ctrl *cfg);
void isp_hdr_set_roi_stat_tile_ctrl(volatile CsrBankHdr *csr, const struct isp_hdr_roi_stat_tile_ctrl *cfg);
void isp_hdr_get_roi_stat_tile_ctrl(volatile CsrBankHdr *csr, struct isp_hdr_roi_stat_tile_ctrl *cfg);
void isp_hdr_set_roi_stat_clear(volatile CsrBankHdr *csr, uint8_t clear);
uint8_t isp_hdr_get_roi_stat_clear(volatile CsrBankHdr *csr);
void isp_hdr_set_roi_stat_enable(volatile CsrBankHdr *csr, uint8_t enable);
uint8_t isp_hdr_get_roi_stat_enable(volatile CsrBankHdr *csr);
void isp_hdr_get_roi_stat(volatile CsrBankHdr *csr, struct isp_hdr_roi_stat *stat);
// RGL
/*
 * TO-DO: isp_hdr_get_rgl_stat?
 */
void isp_hdr_set_rgl_stat_frame_ctrl(volatile CsrBankHdr *csr, const struct isp_hdr_rgl_stat_frame_ctrl *cfg);
void isp_hdr_get_rgl_stat_frame_ctrl(volatile CsrBankHdr *csr, struct isp_hdr_rgl_stat_frame_ctrl *cfg);
void isp_hdr_set_rgl_stat_tile_ctrl(volatile CsrBankHdr *csr, const struct isp_hdr_rgl_stat_tile_ctrl *cfg);
void isp_hdr_get_rgl_stat_tile_ctrl(volatile CsrBankHdr *csr, struct isp_hdr_rgl_stat_tile_ctrl *cfg);
void isp_hdr_set_rgl_stat_clear(volatile CsrBankHdr *csr, uint8_t clear);
uint8_t isp_hdr_get_rgl_stat_clear(volatile CsrBankHdr *csr);
void isp_hdr_set_rgl_stat_enable(volatile CsrBankHdr *csr, uint8_t enable);
uint8_t isp_hdr_get_rgl_stat_enable(volatile CsrBankHdr *csr);
uint8_t isp_hdr_get_rgl_stat_num_of_rgl(volatile CsrBankHdr *csr);
void isp_hdr_get_rgl_stat(volatile CsrBankHdr *csr, struct isp_hdr_rgl_stat *stat);

/* Debug */
void isp_hdr_set_dbg_mon_sel(volatile CsrBankHdr *csr, uint8_t debug_mon_sel);
uint8_t isp_hdr_get_dbg_mon_sel(volatile CsrBankHdr *csr);

/* Efuse */
uint8_t isp_hdr_get_efuse_dis_hdr_violation(volatile CsrBankHdr *csr);

/* Reserved */
void isp_hdr_set_reserved_0(volatile CsrBankHdr *csr, uint32_t reserved_0);
uint32_t isp_hdr_get_reserved_0(volatile CsrBankHdr *csr);
void isp_hdr_set_reserved_1(volatile CsrBankHdr *csr, uint32_t reserved_1);
uint32_t isp_hdr_get_reserved_1(volatile CsrBankHdr *csr);

/* Ink num */
void isp_hdr_set_ink_num(volatile CsrBankHdr *csr, uint8_t ink_num);
uint8_t isp_hdr_get_ink_num(volatile CsrBankHdr *csr);

#endif /* KYOTO_HDR_H_ */
