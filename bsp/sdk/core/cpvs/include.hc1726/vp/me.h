/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_ME_H_
#define SAPPORO_ME_H_

#include "common.h"
#include "da_define.h"
#include "isp_utils.h"
#include "csr_bank_me.h"

#define ME_FIXED_MVR_EXTEND_DIST (8)
#define ME_BLK_WD (8)
#define ME_BLK_HT (8)
#define ME_MV_MAX_CNT_BIT (12)

typedef struct vp_pte_cfg {
	struct vp_pte_curve {
		uint16_t val[PTE_CURVE_ENTRY_NUM];
	} curve; /**< Post tone enhancement curve */
} VpPteCfg;

typedef enum vp_me_mode {
	VP_ME_MODE_NORMAL = 0,
	VP_ME_MODE_DISABLE = 1,
	VP_ME_MODE_MUM = 2,
} VpMeMode;

typedef struct vp_me_cfg {
	enum vp_me_mode mode;
	// candidates
	uint8_t scene_change;
	uint16_t gmv_x;
	uint16_t gmv_y;
	uint8_t gmv_cand_valid;
	uint32_t mode_left_mv_diff_th;
	uint32_t mode_top_left_mv_diff_th;
	uint32_t mode_top_right_mv_diff_th;
	uint8_t bottom_left_dist_x;
	uint8_t bottom_left_dist_y;
	uint8_t bottom_right_dist_x;
	uint8_t bottom_right_dist_y;
	// search range
	uint8_t sw_center_mode;
	uint16_t sw_center_x_sw;
	uint16_t sw_center_y_sw;
	uint8_t sw_center_weight;
	uint8_t sw_ix;
	uint8_t sw_iy;
	uint8_t sw_ix_size;
	uint8_t sw_iy_size;
	uint8_t mvr_left_extend_dist;
	uint8_t mvr_right_extend_dist;
	// motion search
	uint8_t ime_penalty_gain_x_sel;
	uint8_t ime_penalty_gain_y_sel;
	uint8_t ime_penalty_bound_x_ini;
	uint8_t ime_penalty_bound_y_ini;
	uint16_t search_texture_th;
	// cost
	uint16_t valid_true_mv_th;
	uint8_t matching_weight;
	uint8_t singularity_weight;
	uint8_t range_weight;
	// block matching
	uint8_t m_cost_quarter_gain;
	uint8_t m_cost_half_gain;
	uint16_t m_cost_frac_offset;
	// singularity
	uint16_t singularity_min_th;
	uint16_t singularity_max_th;
	uint16_t texture_gain_low_th;
	uint16_t texture_gain_high_th;
	uint8_t texture_gain_low;
	uint8_t texture_gain_high;
	uint8_t texture_gain_slope;
	// mv range
	uint16_t range_min_x_th;
	uint16_t range_max_x_th;
	uint16_t range_min_y_th;
	uint16_t range_max_y_th;
	// type
	uint16_t spatial_cost_offset;
	uint16_t temporal_cost_offset;
	uint16_t search_weak_cost_offset;
	uint16_t search_cost_offset;
	uint16_t refine_cost_offset;
	uint16_t gmv_cost_offset;
	// non zero
	uint16_t non_zero_mv_cost_offset;
	uint8_t singularity_type_bias_en;
	uint8_t singularity_type_wei_sp;
	uint8_t valid_true_mv_cost_mode;
	uint8_t tr_cost_en;
	uint16_t tr_texture_crop;
	uint8_t tr_base_min;
	uint8_t tr_base_max;
	uint8_t tr_base_rto;
	uint8_t tr_non_zero_mv_cost_offset_ratio;
	uint8_t tr_spatial_cost_offset_ratio;
	uint8_t tr_temporal_cost_offset_ratio;
	uint8_t tr_search_cost_offset_ratio;
	uint8_t tr_refine_cost_offset_ratio;
	uint8_t tr_gmv_cost_offset_ratio;
	uint8_t tr_r_cost_max_ratio;
	uint8_t tr_s_cost_max_ratio;
	uint8_t tr_range_ratio;
	uint8_t tr_singularity_ratio;
	uint8_t qualification_matching_level_round;
	uint8_t qualification_aim_mode;
	uint8_t qualification_ignore_gmv;
	uint8_t qualification_mv_coring;
} VpMeCfg;

typedef struct vp_me_mv_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint8_t x_accuracy;
	uint8_t y_accuracy;
	uint8_t step;
	uint8_t mv_hist_only_texture_en;
	uint16_t mv_hist_texture_th;
} VpMeMvRoiStatFrameCtrl;

typedef IspvpTileCtrl VpMeMvRoiStatTileCtrl;

typedef struct vp_me_mv_hist {
	uint16_t x;
	uint16_t y;
	uint16_t count;
} VpMeMvHist;

typedef struct vp_me_mv_roi_stat {
	struct vp_me_mv_hist hist[ME_MV_HIST_ENTRY_NUM];
	uint32_t valid_cnt;
	uint32_t best_sad_hist[ME_BEST_SAD_HIST_ENTRY_NUM];
} VpMeMvRoiStat;

typedef struct vp_me_mv_roi_raw_stat {
	uint32_t hist[ME_MV_HIST_ENTRY_NUM];
	uint32_t valid_cnt;
} VpMeMvRoiRawStat;

typedef enum vp_me_strip_motion_mode {
	VP_ME_STRIP_MOTION_MODE_UNI_DIR = 0,
	VP_ME_STRIP_MOTION_MODE_BI_DIR = 1,
	VP_ME_STRIP_MOTION_MODE_NUM = 2,
} VpMeStripMotionMode;

typedef struct vp_me_strip_motion_roi_stat_frame_ctrl {
	enum vp_me_strip_motion_mode mode;
	uint8_t th_2s;
	uint8_t qs;
	uint16_t sy;
	uint16_t ey;
} VpMeStripMotionRoiStatFrameCtrl;

typedef struct vp_me_strip_motion_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} VpMeStripMotionRoiStatTileCtrl;

typedef struct vp_me_strip_motion_roi_stat {
	uint16_t index;
} VpMeStripMotionRoiStat;

typedef IspvpFrameCtrl VpMeYAvgRoiStatFrameCtrl;

typedef IspvpTileCtrl VpMeYAvgRoiStatTileCtrl;

typedef struct vp_me_y_avg_roi_stat {
	uint16_t luma_before_pte;
	uint16_t luma_after_pte;
} VpMeYAvgRoiStat;

typedef struct vp_me_texture_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
} VpMeTextureRoiStatFrameCtrl;

typedef IspvpTileCtrl VpMeTextureRoiStatTileCtrl;

typedef struct vp_me_texture_roi_stat {
	uint32_t hor;
	uint32_t ver;
	uint32_t hor_ver;
	uint32_t texture_blk_num;
} VpMeTextureRoiStat;

typedef struct vp_me_fg_y_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint8_t soft_clip_slope;
	uint8_t soft_clip_th;
	uint16_t gmv_x;
	uint16_t gmv_y;
} VpMeFgYRoiStatFrameCtrl;

typedef struct vp_me_fg_y_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} VpMeFgYRoiStatTileCtrl;

typedef struct vp_me_fg_y_roi_stat {
	uint32_t hist[ME_FG_Y_ENTRY_NUM];
	uint32_t confidence;
	uint32_t pix_sum;
} VpMeFgYRoiStat;

typedef struct vp_me_fg_texture_roi_stat_frame_ctrl {
	uint16_t sy;
	uint16_t ey;
	uint8_t soft_clip_slope;
	uint8_t soft_clip_th;
	uint16_t gmv_x;
	uint16_t gmv_y;
} VpMeFgTextureRoiStatFrameCtrl;

typedef struct vp_me_fg_texture_roi_stat_tile_ctrl {
	uint16_t sx;
	uint16_t ex;
} VpMeFgTextureRoiStatTileCtrl;

typedef struct vp_me_fg_texture_roi_stat {
	uint32_t confidence;
	uint32_t hor;
	uint32_t ver;
	uint32_t hor_ver;
} VpMeFgTextureRoiStat;

/* PTE*/
void vp_pte_set_cfg(volatile CsrBankMe *csr, const struct vp_pte_cfg *cfg);
void vp_pte_get_cfg(volatile CsrBankMe *csr, struct vp_pte_cfg *cfg);

/* ME*/
void vp_me_set_cfg(volatile CsrBankMe *csr, const struct vp_me_cfg *cfg);
void vp_me_get_cfg(volatile CsrBankMe *csr, struct vp_me_cfg *cfg);

/* Statistics */
// MV
void vp_me_set_mv_roi_stat_frame_ctrl(volatile CsrBankMe *csr, const struct vp_me_mv_roi_stat_frame_ctrl *cfg);
void vp_me_get_mv_roi_stat_frame_ctrl(volatile CsrBankMe *csr, struct vp_me_mv_roi_stat_frame_ctrl *cfg);
void vp_me_set_mv_roi_stat_tile_ctrl(volatile CsrBankMe *csr, const VpMeMvRoiStatTileCtrl *cfg);
void vp_me_get_mv_roi_stat_tile_ctrl(volatile CsrBankMe *csr, VpMeMvRoiStatTileCtrl *cfg);
void vp_me_set_mv_roi_stat_clear(volatile CsrBankMe *csr, uint8_t clear);
uint8_t vp_me_get_mv_roi_stat_clear(volatile CsrBankMe *csr);
void vp_me_set_mv_roi_stat_enable(volatile CsrBankMe *csr, uint8_t enable);
uint8_t vp_me_get_mv_roi_stat_enable(volatile CsrBankMe *csr);
void vp_me_get_mv_roi_stat(volatile CsrBankMe *csr, struct vp_me_mv_roi_stat *stat);
void vp_me_get_mv_roi_raw_stat(volatile CsrBankMe *csr, struct vp_me_mv_roi_raw_stat *stat);
// Strip Motion
void vp_me_set_strip_motion_roi_stat_frame_ctrl(volatile CsrBankMe *csr, uint8_t idx,
                                                const struct vp_me_strip_motion_roi_stat_frame_ctrl *cfg);
void vp_me_get_strip_motion_roi_stat_frame_ctrl(volatile CsrBankMe *csr, uint8_t idx,
                                                struct vp_me_strip_motion_roi_stat_frame_ctrl *cfg);
void vp_me_set_strip_motion_roi_stat_tile_ctrl(volatile CsrBankMe *csr, uint8_t idx,
                                               const struct vp_me_strip_motion_roi_stat_tile_ctrl *cfg);
void vp_me_get_strip_motion_roi_stat_tile_ctrl(volatile CsrBankMe *csr, uint8_t idx,
                                               struct vp_me_strip_motion_roi_stat_tile_ctrl *cfg);
void vp_me_set_strip_motion_roi_stat_enable(volatile CsrBankMe *csr, uint8_t idx, uint8_t enable);
uint8_t vp_me_get_strip_motion_roi_stat_enable(volatile CsrBankMe *csr, uint8_t idx);
void vp_me_get_strip_motion_roi_stat(volatile CsrBankMe *csr, uint8_t idx, struct vp_me_strip_motion_roi_stat *stat);
// Y Avg
void vp_me_set_y_avg_roi_stat_frame_ctrl(volatile CsrBankMe *csr, const VpMeYAvgRoiStatFrameCtrl *cfg);
void vp_me_get_y_avg_roi_stat_frame_ctrl(volatile CsrBankMe *csr, VpMeYAvgRoiStatFrameCtrl *cfg);
void vp_me_set_y_avg_roi_stat_tile_ctrl(volatile CsrBankMe *csr, const VpMeYAvgRoiStatTileCtrl *cfg);
void vp_me_get_y_avg_roi_stat_tile_ctrl(volatile CsrBankMe *csr, VpMeYAvgRoiStatTileCtrl *cfg);
void vp_me_set_y_avg_roi_stat_clear(volatile CsrBankMe *csr, uint8_t clear);
uint8_t vp_me_get_y_avg_roi_stat_clear(volatile CsrBankMe *csr);
void vp_me_set_y_avg_roi_stat_enable(volatile CsrBankMe *csr, uint8_t enable);
uint8_t vp_me_get_y_avg_roi_stat_enable(volatile CsrBankMe *csr);
void vp_me_get_y_avg_roi_stat(volatile CsrBankMe *csr, struct vp_me_y_avg_roi_stat *stat);
// Texture
void vp_me_set_texture_roi_stat_frame_ctrl(volatile CsrBankMe *csr,
                                           const struct vp_me_texture_roi_stat_frame_ctrl *cfg);
void vp_me_get_texture_roi_stat_frame_ctrl(volatile CsrBankMe *csr, struct vp_me_texture_roi_stat_frame_ctrl *cfg);
void vp_me_set_texture_roi_stat_tile_ctrl(volatile CsrBankMe *csr, const VpMeTextureRoiStatTileCtrl *cfg);
void vp_me_get_texture_roi_stat_tile_ctrl(volatile CsrBankMe *csr, VpMeTextureRoiStatTileCtrl *cfg);
void vp_me_set_texture_roi_stat_clear(volatile CsrBankMe *csr, uint8_t clear);
uint8_t vp_me_get_texture_roi_stat_clear(volatile CsrBankMe *csr);
void vp_me_set_texture_roi_stat_enable(volatile CsrBankMe *csr, uint8_t enable);
uint8_t vp_me_get_texture_roi_stat_enable(volatile CsrBankMe *csr);
void vp_me_get_texture_roi_stat(volatile CsrBankMe *csr, struct vp_me_texture_roi_stat *stat);
// Fg Y
void vp_me_set_fg_y_roi_stat_frame_ctrl(volatile CsrBankMe *csr, const struct vp_me_fg_y_roi_stat_frame_ctrl *cfg);
void vp_me_get_fg_y_roi_stat_frame_ctrl(volatile CsrBankMe *csr, struct vp_me_fg_y_roi_stat_frame_ctrl *cfg);
void vp_me_set_fg_y_roi_stat_tile_ctrl(volatile CsrBankMe *csr, const struct vp_me_fg_y_roi_stat_tile_ctrl *cfg);
void vp_me_get_fg_y_roi_stat_tile_ctrl(volatile CsrBankMe *csr, struct vp_me_fg_y_roi_stat_tile_ctrl *cfg);
void vp_me_set_fg_y_roi_stat_clear(volatile CsrBankMe *csr, uint8_t clear);
uint8_t vp_me_get_fg_y_roi_stat_clear(volatile CsrBankMe *csr);
void vp_me_set_fg_y_roi_stat_enable(volatile CsrBankMe *csr, uint8_t enable);
uint8_t vp_me_get_fg_y_roi_stat_enable(volatile CsrBankMe *csr);
void vp_me_get_fg_y_roi_stat(volatile CsrBankMe *csr, struct vp_me_fg_y_roi_stat *stat);
// Fg Texture
void vp_me_set_fg_texture_roi_stat_frame_ctrl(volatile CsrBankMe *csr,
                                              const struct vp_me_fg_texture_roi_stat_frame_ctrl *cfg);
void vp_me_get_fg_texture_roi_stat_frame_ctrl(volatile CsrBankMe *csr,
                                              struct vp_me_fg_texture_roi_stat_frame_ctrl *cfg);
void vp_me_set_fg_texture_roi_stat_tile_ctrl(volatile CsrBankMe *csr,
                                             const struct vp_me_fg_texture_roi_stat_tile_ctrl *cfg);
void vp_me_get_fg_texture_roi_stat_tile_ctrl(volatile CsrBankMe *csr, struct vp_me_fg_texture_roi_stat_tile_ctrl *cfg);
void vp_me_set_fg_texture_roi_stat_clear(volatile CsrBankMe *csr, uint8_t clear);
uint8_t vp_me_get_fg_texture_roi_stat_clear(volatile CsrBankMe *csr);
void vp_me_set_fg_texture_roi_stat_enable(volatile CsrBankMe *csr, uint8_t enable);
uint8_t vp_me_get_fg_texture_roi_stat_enable(volatile CsrBankMe *csr);
void vp_me_get_fg_texture_roi_stat(volatile CsrBankMe *csr, struct vp_me_fg_texture_roi_stat *stat);

// ink
void vp_me_set_mv_ink_range_sel(volatile CsrBankMe *csr, uint8_t mv_ink_range_sel);
uint8_t vp_me_get_mv_ink_range_sel(volatile CsrBankMe *csr);

#endif /* SAPPORO_ME_H_ */
