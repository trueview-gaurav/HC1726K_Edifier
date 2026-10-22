/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef IS_PG_H_
#define IS_PG_H_

//#include "stdint.h"
#include "is_utils.h"
#include "csr_bank_pg.h"

typedef enum is_pg_mode {
	IS_PG_MODE_ROI = 0,
	IS_PG_MODE_SNS_IN = 1,
	IS_PG_MODE_PG_IN = 2,
	IS_PG_MODE_NUM = 3,
} IsPgMode;

typedef enum is_pg_color_space {
	IS_PG_COLOR_SPACE_CFA = 0,
	IS_PG_COLOR_SPACE_YUV = 1,
	IS_PG_COLOR_SPACE_NUM = 2,
} IsPgColorSpace;

typedef struct is_pg_input_format {
	enum is_pg_color_space color_space;
	enum is_pixel_format_i mode;
	enum ini_bayer_phase bayer;
	enum cfa_phase cfa[CFA_PHASE_ENTRY_NUM];
} IsPgInputFormat;

typedef enum is_pg_pat_sel {
	IS_PG_PAT_SEL_RAMP = 0,
	IS_PG_PAT_SEL_COLOR_BAR = 1,
	IS_PG_PAT_SEL_GRID = 2,
	IS_PG_PAT_SEL_RANDOM = 3,
	IS_PG_PAT_SEL_NUM = 4,
} IsPgPatSel;

typedef struct is_pg_ramp_cfg {
	uint16_t ini[INI_BAYER_PHASE_NUM];
	uint32_t delta_h_2s[INI_BAYER_PHASE_NUM];
	uint32_t delta_v_2s[INI_BAYER_PHASE_NUM];
} IsPgRampCfg;

typedef struct is_pg_color_bar_cfg {
	uint16_t width;
	uint32_t ch0[IS_PG_CB_ENTRY_NUM];
	uint32_t ch1[IS_PG_CB_ENTRY_NUM];
	uint32_t ch2[IS_PG_CB_ENTRY_NUM];
} IsPgColorBarCfg;

typedef struct is_pg_grid_cfg {
	uint16_t line_width;
	uint8_t block_side_length_bw;
	uint32_t line_intensity[INI_BAYER_PHASE_NUM];
	uint32_t block_intensity[INI_BAYER_PHASE_NUM];
} IsPgGridCfg;

typedef struct is_pg_cfg {
	enum is_pg_pat_sel sel;
	uint16_t x_cnt_ini;
	uint8_t line_moving;
	struct is_pg_ramp_cfg ramp;
	struct is_pg_color_bar_cfg color_bar;
	struct is_pg_grid_cfg grid;
} IsPgCfg;

//
/* Resolution */
void is_pg_set_res(volatile CsrBankPg *csr, const struct res *res);
void is_pg_get_res(volatile CsrBankPg *csr, struct res *res);

/* Mode */
void is_pg_set_mode(volatile CsrBankPg *csr, enum is_pg_mode mode);
enum is_pg_mode is_pg_get_mode(volatile CsrBankPg *csr);

/* Input format */
void is_pg_set_input_format(volatile CsrBankPg *csr, const struct is_pg_input_format *cfg);
void is_pg_get_input_format(volatile CsrBankPg *csr, struct is_pg_input_format *cfg);

/* ROI */
void is_pg_set_roi(volatile CsrBankPg *csr, const struct rect_point *cfg);
void is_pg_get_roi(volatile CsrBankPg *csr, struct rect_point *cfg);

/* PG */
void is_pg_set_cfg(volatile CsrBankPg *csr, const struct is_pg_cfg *cfg);
void is_pg_get_cfg(volatile CsrBankPg *csr, struct is_pg_cfg *cfg);

/* Debug */
void is_pg_set_dbg_mon_sel(volatile CsrBankPg *csr, uint8_t debug_mon_sel);
uint8_t is_pg_get_dbg_mon_sel(volatile CsrBankPg *csr);

#define IS_PG_CFA_PHASE_IDX 3
#define IS_PG_CFA_PHASE_NUM 16

#define IS_PG_RAMP_IDX 2
#define IS_PG_RAMP_NUM 4

typedef struct is_pg_resolution {
	uint32_t width;
	uint32_t height;
} IsPgResolution;

typedef struct is_pg_cfa_set {
	uint32_t cfa_mode;
	uint32_t bayer_ini_phase;
	uint32_t cfa_phase[IS_PG_CFA_PHASE_NUM];
} IsPgCfaSet;

typedef struct is_pg_ctx {
	IsPgResolution pg_res;
	IsPgCfaSet pg_cfa_set;
	uint32_t pg_mode;
	uint32_t pg_pattern_idx;
	uint32_t pg_ramp_idx;
	uint32_t pg_rp_initial[IS_PG_RAMP_NUM];
	uint32_t pg_rp_delta_h[IS_PG_RAMP_NUM];
	uint32_t pg_rp_delta_v[IS_PG_RAMP_NUM];

} IsPgCtx;

typedef struct is_pg_attr {
	uint32_t pg_width;
	uint32_t pg_height;
	uint32_t pg_mode;
	uint32_t pg_cfa_mode_idx;
	uint32_t pg_bayer_init_phase;
	uint32_t pg_pattern_idx;
	uint32_t pg_ramp_idx;

} IsPgAttr;

void hw_is_pg_resolution(uint32_t width, uint32_t height);
void hw_is_pg_bypass(void);
void hw_is_pg_enable(IsPgAttr *pgattr);
void hw_is_pg_set_ctx(IsPgCtx *pgctx, IsPgAttr *pgattr);
void hw_is_pg_set_cfa_ctx(IsPgCtx *pgctx, IsPgAttr *pgattr);
void hw_is_pg_set_pattern_ctx(IsPgCtx *pgctx, IsPgAttr *pgattr);
void hw_is_pg_set_ramp_ctx(IsPgCtx *pgctx);
void hw_is_pg_set_reg(IsPgCtx *pgctx);
void hw_is_pg_cfa_reg(IsPgCtx *pgctx);
void hw_is_pg_set_pattern_reg(IsPgCtx *pgctx);
void hw_is_pg_start(void);
void hw_is_pg_stop(void);
void hw_is_pg_debug_mon_sel(uint32_t debug_mon_sel);
void hw_is_pg_dump_reg(void);
void hw_is_pg_mode(int mode);
void hw_is_pg_setting(void);

#endif