/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef VPK_NR_H_
#define VPK_NR_H_

#include "autoconf.h"

#include "common.h"
#include "isp_utils.h"
#include "csr_bank_nr.h"

#define NR_MA_Y_LUT_CTRL_POINT_NUM (9)
#define NR_MC_Y_LUT_CTRL_POINT_NUM (9)
#define NR_MA_C_LUT_CTRL_POINT_NUM (9)
#define NR_ABS_DIFF_ENTRY_NUM (19)
#define NR_MAX_TDIFF_ROI_NUM (4)
#define NR_MA_STILL_LVL_SLOPE_RND_BIT_SHIFT_BIT 8
#define NR_MA_SMOOTH_LVL_SLOP_RND_BIT_SHIFT_BIT 24
#define NR_MA_NON_STILL_SLOPE_RND_BIT_SHIFT_BIT 16
#define NR_MA_EDGE_LVL_SLOPE_RND_BIT_BIT_MASK 0b0011
#define NR_MA_STILL_LVL_SLOPE_RND_BIT_BIT_MASK 0b0001
#define NR_MA_SMOOTH_LVL_SLOP_RND_BIT_BIT_MASK 0b0011
#define NR_MA_NON_STILL_SLOPE_RND_BIT_BIT_MASK 0b0011

typedef enum vp_nr_mode {
	VP_NR_MODE_NORMAL = 0,
	VP_NR_MODE_2D_ONLY = 1,
	VP_NR_MODE_3D_ONLY = 2,
	VP_NR_MODE_MONO = 3,
	VP_NR_MODE_DISABLE = 4,
	VP_NR_MODE_BYPASS = 5,
	VP_NR_MODE_NUM = 6,
} VpNrMode;

typedef enum vp_nr_fir_kernel_sel_y {
	VP_NR_FIR_KERNEL_SEL_Y_3X3 = 0,
	VP_NR_FIR_KERNEL_SEL_Y_5X5 = 1,
	VP_NR_FIR_KERNEL_SEL_Y_NUM = 2,
} VpNrFirKernelSelY;

typedef enum vp_nr_iir_y_conf_sel {
	VP_NR_IIR_Y_CONF_SEL_MAX_HP = 0,
	VP_NR_IIR_Y_CONF_SEL_MAX_LP_DYN = 1,
	VP_NR_IIR_Y_CONF_SEL_MAX_LP = 2,
	VP_NR_IIR_Y_CONF_SEL_NUM = 3,
} VpNrIirYConfSel;

typedef enum vp_nr_weight_y_ref_sel {
	VP_NR_WEIGHT_Y_REF_SEL_HP = 0,
	VP_NR_WEIGHT_Y_REF_SEL_LP_DYN = 1,
	VP_NR_WEIGHT_Y_REF_SEL_LP = 2,
	VP_NR_WEIGHT_Y_REF_SEL_NUM = 3,
} VpNrWeightYRefSel;

typedef struct vp_nr_cfg {
	enum vp_nr_mode mode;
	uint8_t moving_coring_th;
	uint8_t moving_perblk_max;
	uint8_t mv_consist_coring;
	uint8_t mv_consist_perblk_max;
	uint8_t texture_coring_bits;
	uint8_t mv_consist_round_bit;
	uint8_t force_mv_consist_en;
	uint8_t force_mv_consist;
	struct nr_3d_ma_y {
		uint16_t lut_i[NR_MA_Y_LUT_CTRL_POINT_NUM];
		uint8_t lut_o[NR_MA_Y_LUT_CTRL_POINT_NUM];
		uint16_t lut_slope[NR_MA_Y_LUT_CTRL_POINT_NUM - 1];
		uint8_t lp_dyn_gain_th_min;
		uint8_t lp_dyn_gain_th_max;
		uint8_t lp_dyn_gain_min;
		uint8_t lp_dyn_gain_max;
		uint16_t lp_dyn_gain_slope;
		uint8_t edge_thd;
		uint8_t edge_lvl_slope_rnd_bit;
		uint8_t still_consistency_thd;
		uint8_t still_lvl_moving_upper_bnd;
		uint8_t still_lvl_slope_rnd_bit;
		uint8_t still_edge_add_weight_max;
		uint8_t smooth_texture_upper_bnd;
		uint8_t smooth_lvl_slope_rnd_bit;
		uint8_t sad_norm_texture_shift_bit;
		uint8_t nonstill_moving_thd;
		uint8_t non_still_slope_rnd_bit;
		uint8_t nonstill_smooth_fb_discard_match;
		uint8_t nonstill_smooth_sub_wei_rto;
	} ma_y;
	struct nr_3d_mc_y {
		uint16_t lut_i[NR_MA_Y_LUT_CTRL_POINT_NUM];
		uint8_t lut_o[NR_MA_Y_LUT_CTRL_POINT_NUM];
		uint16_t lut_slope[NR_MA_Y_LUT_CTRL_POINT_NUM - 1];
		uint8_t texture_thd;
		uint8_t iir_mc_conf_edge_add_weight_max;
		uint8_t mixing_fir_level;
		uint8_t consistency_thd;
		uint8_t force_ratio_en;
		uint8_t force_ratio;
		uint8_t ratio_moving_thd;
		uint8_t ratio_texture_thd;
		uint8_t ratio_texture_round_bit;
		uint8_t ratio_ignore_mcmatcher_lvl;
	} mc_y;
	struct nr_3d_ma_c {
		uint16_t lut_i[NR_MA_Y_LUT_CTRL_POINT_NUM];
		uint8_t lut_o[NR_MA_Y_LUT_CTRL_POINT_NUM];
		uint16_t lut_slope[NR_MA_Y_LUT_CTRL_POINT_NUM - 1];
		uint8_t weight_sel;
	} ma_c;
	struct nr_2d_fir {
		enum vp_nr_fir_kernel_sel_y kernel;
		uint8_t weight_y;
		uint8_t weight_c;
		uint8_t diff_tolerance_thd;
		uint8_t stronger_level;
		uint8_t stronger_by_frame;
	} fir;
	struct nr_blend_2d_and_3d {
		uint8_t alpha_y_offset;
		uint8_t alpha_c_offset;
		uint8_t ma_max_strength;
		uint8_t mc_max_strength;
	} iir;
} VpNrCfg;

typedef enum vp_nr_abs_diff_hist_sel {
	VP_NR_ABS_DIFF_HIST_SEL_BLEND_Y_VS_MC_Y = 0,
	VP_NR_ABS_DIFF_HIST_SEL_INPUT_Y_VS_MC_Y = 1,
	VP_NR_ABS_DIFF_HIST_SEL_INPUT_Y_VS_MA_Y = 2,
	VP_NR_ABS_DIFF_HIST_SEL_INPUT_Y_VS_MA_C = 3,
	VP_NR_ABS_DIFF_HIST_SEL_NUM = 4,
} VpNrAbsDiffHistSel;

typedef enum vp_nr_abs_diff_hist_mode {
	VP_NR_ABS_DIFF_HIST_MODE_OVERFLOW_STOP = 0,
	VP_NR_ABS_DIFF_HIST_MODE_OVERFLOW_SAT = 1,
	VP_NR_ABS_DIFF_HIST_MODE_NUM = 2,
} VpNrAbsDiffHistMode;

typedef struct vp_nr_abs_diff_roi_stat_frame_ctrl {
	enum vp_nr_abs_diff_hist_sel sel;
	enum vp_nr_abs_diff_hist_mode mode;
	uint8_t step;
	uint16_t sy;
	uint16_t ey;
} VpNrAbsDiffRoiStatFrameCtrl;

typedef struct vp_nr_abs_diff_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} VpNrAbsDiffRoiStatTileCtrl;

typedef struct vp_nr_abs_diff_roi_stat {
	uint8_t overflow;
	uint32_t hist[NR_ABS_DIFF_ENTRY_NUM];
} VpNrAbsDiffRoiStat;

typedef enum vp_nr_tdiff_mode {
	VP_NR_TDIFF_MODE_NORMAL = 0,
	VP_NR_TDIFF_MODE_DISABLE = 1,
	VP_NR_TDIFF_MODE_MUM = 2,
} VpNrTdiffMode;

typedef struct vp_nr_tdiff_roi_stat_frame_ctrl {
	enum vp_nr_tdiff_mode mode;
	uint16_t sy;
	uint16_t ey;
	uint32_t acc_th_y;
	uint32_t acc_th_c;
} VpNrTdiffRoiStatFrameCtrl;

typedef struct vp_nr_tdiff_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} VpNrTdiffRoiStatTileCtrl;

typedef struct vp_nr_tdiff_roi_stat {
	uint16_t avg_y;
	uint16_t avg_c;
} VpNrTdiffRoiStat;

typedef enum vp_nr_demo_mode {
	VP_NR_DEMO_MODE_NORMAL = 0,
	VP_NR_DEMO_MODE_2D_ONLY = 1,
	VP_NR_DEMO_MODE_3D_ONLY = 2,
	VP_NR_DEMO_MODE_MONO = 3,
	VP_NR_DEMO_MODE_DISABLE = 4,
	VP_NR_DEMO_MODE_BYPASS = 5,
	VP_NR_DEMO_MODE_NUM = 6,
} VpNrDemoMode;

typedef struct vp_nr_demo {
	uint8_t enable;
	enum vp_nr_demo_mode mode;
	uint16_t sx;
	uint16_t sy;
	uint16_t ex;
	uint16_t ey;
} VpNrDemo;

typedef struct vp_nr_ink_cfg {
	uint8_t enable;
	uint8_t mode;
	uint8_t ink_nrw_en;
	uint8_t ink_odd_pxl_sel;
	uint8_t ink_odd_line_sel;
} VpNrInkCfg;

/* NR */
void vp_nr_set_cfg(volatile CsrBankNr *csr, const struct vp_nr_cfg *cfg);
void vp_nr_get_cfg(volatile CsrBankNr *csr, struct vp_nr_cfg *cfg);

/* Statistics */
// Abs Diff
void vp_nr_set_abs_diff_roi_stat_frame_ctrl(volatile CsrBankNr *csr,
                                            const struct vp_nr_abs_diff_roi_stat_frame_ctrl *cfg);
void vp_nr_get_abs_diff_roi_stat_frame_ctrl(volatile CsrBankNr *csr, struct vp_nr_abs_diff_roi_stat_frame_ctrl *cfg);
void vp_nr_set_abs_diff_roi_stat_tile_ctrl(volatile CsrBankNr *csr,
                                           const struct vp_nr_abs_diff_roi_stat_tile_ctrl *cfg);
void vp_nr_get_abs_diff_roi_stat_tile_ctrl(volatile CsrBankNr *csr, struct vp_nr_abs_diff_roi_stat_tile_ctrl *cfg);
void vp_nr_set_abs_diff_roi_stat_clear(volatile CsrBankNr *csr, uint8_t clear);
uint8_t vp_nr_get_abs_diff_roi_stat_clear(volatile CsrBankNr *csr);
void vp_nr_set_abs_diff_roi_stat_enable(volatile CsrBankNr *csr, uint8_t enable);
uint8_t vp_nr_get_abs_diff_roi_stat_enable(volatile CsrBankNr *csr);
void vp_nr_get_abs_diff_roi_stat(volatile CsrBankNr *csr, struct vp_nr_abs_diff_roi_stat *stat);
// Tdiff
void vp_nr_set_tdiff_roi_stat_frame_ctrl(volatile CsrBankNr *csr, uint8_t idx,
                                         const struct vp_nr_tdiff_roi_stat_frame_ctrl *cfg);
void vp_nr_get_tdiff_roi_stat_frame_ctrl(volatile CsrBankNr *csr, uint8_t idx,
                                         struct vp_nr_tdiff_roi_stat_frame_ctrl *cfg);
void vp_nr_set_tdiff_roi_stat_tile_ctrl(volatile CsrBankNr *csr, uint8_t idx,
                                        const struct vp_nr_tdiff_roi_stat_tile_ctrl *cfg);
void vp_nr_get_tdiff_roi_stat_tile_ctrl(volatile CsrBankNr *csr, uint8_t idx,
                                        struct vp_nr_tdiff_roi_stat_tile_ctrl *cfg);
void vp_nr_set_tdiff_roi_stat_clear(volatile CsrBankNr *csr, uint8_t idx, uint8_t clear);
uint8_t vp_nr_get_tdiff_roi_stat_clear(volatile CsrBankNr *csr, uint8_t idx);
void vp_nr_set_tdiff_roi_stat_enable(volatile CsrBankNr *csr, uint8_t idx, uint8_t enable);
uint8_t vp_nr_get_tdiff_roi_stat_enable(volatile CsrBankNr *csr, uint8_t idx);
void vp_nr_get_tdiff_roi_stat(volatile CsrBankNr *csr, uint8_t idx, struct vp_nr_tdiff_roi_stat *stat);

/* Demo */
void vp_nr_set_demo(volatile CsrBankNr *csr, const struct vp_nr_demo *demo);
void vp_nr_get_demo(volatile CsrBankNr *csr, struct vp_nr_demo *demo);

/* Ink */
void vp_nr_set_ink(volatile CsrBankNr *csr, const struct vp_nr_ink_cfg *ink_cfg);
void vp_nr_get_ink(volatile CsrBankNr *csr, struct vp_nr_ink_cfg *ink_cfg);

#endif
