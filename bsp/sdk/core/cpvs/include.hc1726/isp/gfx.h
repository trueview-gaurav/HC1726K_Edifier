/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_GFX_H_
#define KYOTO_GFX_H_

#include "isp_utils.h"
#include "csr_bank_gfx.h"
#include "csr_bank_coordr.h"

typedef struct isp_gfx_img_size {
	struct point min;
	struct point max;
} IspGfxImgSize;

typedef struct isp_gfx_invalid_cfg {
	uint16_t r;
	uint16_t g;
	uint16_t b;
} IspGfxInvalidCfg;

typedef struct isp_gfx_opt_mode {
	uint8_t dot_by_dot;
	uint8_t mono_mode;
	uint8_t interp_range_x;
	uint8_t interp_range_y;
} IspGfxOptMode;

typedef struct isp_gfx_table_cfg {
	uint8_t enable;
	// table param will be control by sample_read_t0_le64_c1_d64
} IspGfxTableCfg;

typedef struct isp_gfx_aff_coeff {
	uint32_t matrix_00_2s;
	uint32_t matrix_01_2s;
	uint32_t matrix_10_2s;
	uint32_t matrix_11_2s;
	uint32_t shift_x_2s;
	uint32_t shift_y_2s;
} IspGfxAffCoeff;

typedef struct isp_gfx_dst_aff_cfg {
	struct isp_gfx_aff_coeff coeff[DST_AFF_MAX_NUM];
} IspGfxDstAffCfg;

typedef struct isp_gfx_coord_shift {
	uint32_t x_2s;
	uint32_t y_2s;
} IspGfxCoordShift;

typedef struct isp_gfx_nus_coeff {
	uint32_t in_1;
	uint32_t in_2;
	uint32_t out_1;
	uint32_t out_2;
	uint16_t slope_base_0;
	uint16_t slope_base_1;
	uint16_t slope_base_2;
	uint32_t slope_step_0;
	uint32_t slope_step_1;
	uint32_t slope_step_2;
} IspGfxNusCoeff;

typedef struct isp_gfx_nus_cfg {
	struct isp_gfx_coord_shift shift;
	struct nus_slope_sign {
		uint8_t x;
		uint8_t y;
	} slope_sign;
	struct isp_gfx_nus_coeff x;
	struct isp_gfx_nus_coeff y;
} IspGfxNusCfg;

typedef struct isp_gfx_sph_cfg {
	struct isp_gfx_coord_shift shift;
	uint8_t enable;
	uint8_t view_index;
	uint16_t view_x_min_int;
	uint16_t view_x_max_int;
	uint16_t dst_width;
	uint32_t theta_step_0;
	uint32_t theta_step_1;
	uint32_t phi_step_0;
	uint32_t phi_step_1;
	uint32_t stitch_r_0;
	uint32_t stitch_r_1;
	uint8_t r_ratio_adj_2s[SPH_R_RATIO_ADJ_NUM];
} IspGfxSphCfg;

typedef struct isp_gfx_pol_cfg {
	struct isp_gfx_coord_shift shift;
	uint8_t enable;
	uint32_t r_center;
	uint32_t r_step;
	uint32_t theta_step;
} IspGfxPolCfg;

typedef struct isp_gfx_squ_cfg {
	struct isp_gfx_coord_shift shift;
	uint8_t x_strength;
	uint8_t y_strength;
	uint32_t inv_r;
} IspGfxSquCfg;

typedef struct isp_gfx_ldc_cfg {
	struct isp_gfx_coord_shift shift;
	uint8_t strength;
	uint8_t ratio_origin;
	uint16_t curvature;
	struct ldc_lut_curve {
		uint32_t i[LDC_CURVE_CTRL_POINT_NUM - 1];
		uint32_t m[LDC_CURVE_CTRL_POINT_NUM];
		uint32_t o[LDC_CURVE_CTRL_POINT_NUM - 1];
	} curve;
} IspGfxLdcCfg;

typedef struct isp_gfx_psp_coeff {
	uint32_t u_x_coeff_2s_l;
	uint8_t u_x_coeff_2s_h;
	uint32_t u_y_coeff_2s_l;
	uint8_t u_y_coeff_2s_h;
	uint32_t u_offset_2s_l;
	uint16_t u_offset_2s_h;
	uint32_t v_x_coeff_2s_l;
	uint8_t v_x_coeff_2s_h;
	uint32_t v_y_coeff_2s_l;
	uint8_t v_y_coeff_2s_h;
	uint32_t v_offset_2s_l;
	uint16_t v_offset_2s_h;
	uint32_t w_x_coeff_2s;
	uint32_t w_y_coeff_2s;
	uint32_t w_offset_2s;
} IspGfxPspCoeff;

typedef struct isp_gfx_src_psp_cfg {
	struct isp_gfx_psp_coeff coeff[SRC_PSP_MAX_NUM];
} IspGfxSrcPspCfg;

typedef struct isp_gfx_coord_stat_ctrl {
	uint8_t valid;
} IspGfxCoordStatCtrl;

typedef struct isp_gfx_coord_stat {
	uint16_t x_min_int_2s;
	uint16_t x_max_int_2s;
	uint16_t y_min_int_2s;
	uint16_t y_max_int_2s;
} IspGfxCoordStat;

typedef struct isp_gfx_cache_cfg {
	uint8_t window_all_access;
	uint8_t cache_overflow_clip;
} IspGfxCacheCfg;

typedef struct isp_gfx_cfg {
	struct isp_gfx_img_size src_img;
	struct isp_gfx_img_size dst_img;
	struct isp_gfx_opt_mode opt_mode;
	struct isp_gfx_invalid_cfg invalid;
	struct isp_gfx_table_cfg table;
	struct isp_gfx_nus_cfg nus;
	struct isp_gfx_squ_cfg squ;
	struct isp_gfx_cache_cfg cache;
	struct isp_gfx_dst_aff_cfg dst_aff;
	struct isp_gfx_sph_cfg sph;
	struct isp_gfx_pol_cfg pol;
	struct isp_gfx_ldc_cfg ldc;
	struct isp_gfx_src_psp_cfg src_psp;
	struct point first_coord;
} IspGfxCfg;

typedef struct isp_gfx_demo {
	uint8_t enable;
	uint16_t x_min;
	uint16_t x_max;
	uint16_t y_min;
	uint16_t y_max;
} IspGfxDemo;

/* IRQ mask */
void isp_gfx_set_irq_mask_frame_end(volatile CsrBankGfx *csr, uint8_t irq_mask_frame_end);
void isp_gfx_set_irq_mask_cache_overflow(volatile CsrBankGfx *csr, uint8_t irq_mask_cache_overflow);
uint8_t isp_gfx_get_irq_mask_frame_end(volatile CsrBankGfx *csr);
uint8_t isp_gfx_get_irq_mask_cache_overflow(volatile CsrBankGfx *csr);

/* Resolution */
// by tile
void isp_gfx_set_res(volatile CsrBankGfx *csr, const struct res *res);
void isp_gfx_get_res(volatile CsrBankGfx *csr, struct res *res);
void isp_gfx_set_dst_first_coord(volatile CsrBankGfx *csr, const struct point *point);
void isp_gfx_get_dst_first_coord(volatile CsrBankGfx *csr, struct point *point);
// by frame
void isp_gfx_set_src_img_size(volatile CsrBankGfx *csr, const struct isp_gfx_img_size *src);
void isp_gfx_get_src_img_size(volatile CsrBankGfx *csr, struct isp_gfx_img_size *src);
void isp_gfx_set_dst_img_size(volatile CsrBankGfx *csr, const struct isp_gfx_img_size *dst);
void isp_gfx_get_dst_img_size(volatile CsrBankGfx *csr, struct isp_gfx_img_size *dst);

/* Bayer */
void isp_gfx_set_src_ini_bayer_phase(volatile CsrBankGfx *csr, enum ini_bayer_phase bayer);
enum ini_bayer_phase isp_gfx_get_src_ini_bayer_phase(volatile CsrBankGfx *csr);
void isp_gfx_set_dst_ini_bayer_phase(volatile CsrBankGfx *csr, enum ini_bayer_phase bayer);
enum ini_bayer_phase isp_gfx_get_dst_ini_bayer_phase(volatile CsrBankGfx *csr);

/* Invalid */
void isp_gfx_set_invalid_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_invalid_cfg *cfg);
void isp_gfx_get_invalid_cfg(volatile CsrBankGfx *csr, struct isp_gfx_invalid_cfg *cfg);

/* GFX */
// Opt
void isp_gfx_set_opt_mode(volatile CsrBankGfx *csr, const struct isp_gfx_opt_mode *cfg);
void isp_gfx_get_opt_mode(volatile CsrBankGfx *csr, struct isp_gfx_opt_mode *cfg);

// Table
void isp_gfx_set_table_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_table_cfg *cfg);
void isp_gfx_get_table_cfg(volatile CsrBankGfx *csr, struct isp_gfx_table_cfg *cfg);

// DST AFF
void isp_gfx_set_dst_aff_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_dst_aff_cfg *cfg);
void isp_gfx_get_dst_aff_cfg(volatile CsrBankGfx *csr, struct isp_gfx_dst_aff_cfg *cfg);

// NUS
void isp_gfx_set_nus_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_nus_cfg *cfg);
void isp_gfx_get_nus_cfg(volatile CsrBankGfx *csr, struct isp_gfx_nus_cfg *cfg);

// SPH
void isp_gfx_set_sph_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_sph_cfg *cfg);
void isp_gfx_get_sph_cfg(volatile CsrBankGfx *csr, struct isp_gfx_sph_cfg *cfg);

// POL
void isp_gfx_set_pol_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_pol_cfg *cfg);
void isp_gfx_get_pol_cfg(volatile CsrBankGfx *csr, struct isp_gfx_pol_cfg *cfg);

// SQU
void isp_gfx_set_squ_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_squ_cfg *cfg);
void isp_gfx_get_squ_cfg(volatile CsrBankGfx *csr, struct isp_gfx_squ_cfg *cfg);

// LDC
void isp_gfx_set_ldc_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_ldc_cfg *cfg);
void isp_gfx_get_ldc_cfg(volatile CsrBankGfx *csr, struct isp_gfx_ldc_cfg *cfg);

// PSP
void isp_gfx_set_src_psp_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_src_psp_cfg *cfg);
void isp_gfx_get_src_psp_cfg(volatile CsrBankGfx *csr, struct isp_gfx_src_psp_cfg *cfg);

/* Coord stat */
void isp_gfx_set_coord_stat_ctrl(volatile CsrBankGfx *csr, const struct isp_gfx_coord_stat_ctrl *cfg);
void isp_gfx_get_coord_stat_ctrl(volatile CsrBankGfx *csr, struct isp_gfx_coord_stat_ctrl *cfg);
void isp_gfx_get_coord_stat(volatile CsrBankGfx *csr, struct isp_gfx_coord_stat *stat);

/* Cache */
void isp_gfx_set_cache_cfg(volatile CsrBankGfx *csr, const struct isp_gfx_cache_cfg *cfg);
void isp_gfx_get_cache_cfg(volatile CsrBankGfx *csr, struct isp_gfx_cache_cfg *cfg);

/* Efuse */
uint8_t isp_gfx_get_efuse_dis_gfx_sph_violation(volatile CsrBankGfx *csr);
uint8_t isp_gfx_get_efuse_dis_gfx_pol_violation(volatile CsrBankGfx *csr);
uint8_t isp_gfx_get_efuse_dis_gfx_squ_violation(volatile CsrBankGfx *csr);
uint8_t isp_gfx_get_efuse_dis_gfx_ldc_violation(volatile CsrBankGfx *csr);

/* Debug */
void isp_gfx_set_dbg_mon_sel(volatile CsrBankGfx *csr, uint8_t debug_mon_sel);
uint8_t isp_gfx_get_dbg_mon_sel(volatile CsrBankGfx *csr);

/* Demo */
void isp_gfx_set_demo(volatile CsrBankGfx *csr, const struct isp_gfx_demo *demo);
void isp_gfx_get_demo(volatile CsrBankGfx *csr, struct isp_gfx_demo *demo);

/* Reserved */
void isp_gfx_set_reserved_0(volatile CsrBankGfx *csr, uint32_t reserved_0);
uint32_t isp_gfx_get_reserved_0(volatile CsrBankGfx *csr);
void isp_gfx_set_reserved_1(volatile CsrBankGfx *csr, uint32_t reserved_1);
uint32_t isp_gfx_get_reserved_1(volatile CsrBankGfx *csr);
void isp_gfx_bypass(volatile CsrBankGfx *csr, uint16_t width_i, uint16_t height_i, uint16_t width_o, uint16_t height_o,
                    struct isp_gfx_cfg *cfg);
#endif /* KYOTO_GFX_H_ */
