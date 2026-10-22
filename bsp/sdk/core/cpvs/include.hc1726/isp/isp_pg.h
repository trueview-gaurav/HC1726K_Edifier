/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef ISP_PG_H_
#define ISP_PG_H_

#include "isp_utils.h"
#include "csr_bank_pg.h"

typedef enum isp_pg_mode {
	ISP_PG_MODE_ROI = 0,
	ISP_PG_MODE_SNS_IN = 1,
	ISP_PG_MODE_PG_IN = 2,
	ISP_PG_MODE_NUM = 3,
} IspPgMode;

typedef enum isp_pg_color_space {
	ISP_PG_COLOR_SPACE_CFA = 0,
	ISP_PG_COLOR_SPACE_YUV = 1,
	ISP_PG_COLOR_SPACE_NUM = 2,
} IspPgColorSpace;

typedef struct isp_pg_input_format {
	enum isp_pg_color_space color_space;
	enum isp_pixel_format_i mode;
	enum ini_bayer_phase bayer;
	enum cfa_phase cfa[CFA_PHASE_ENTRY_NUM];
} IspPgInputFormat;

typedef enum isp_pg_pat_sel {
	ISP_PG_PAT_SEL_RAMP = 0,
	ISP_PG_PAT_SEL_COLOR_PAMP = 1,
	ISP_PG_PAT_SEL_GRID = 2,
	ISP_PG_PAT_SEL_RANDOM = 3,
	ISP_PG_PAT_SEL_NUM = 4,
} IspPgPatSel;

typedef struct isp_pg_ramp_cfg {
	uint16_t ini[INI_BAYER_PHASE_NUM];
	uint32_t delta_h_2s[INI_BAYER_PHASE_NUM];
	uint32_t delta_v_2s[INI_BAYER_PHASE_NUM];
} IspPgRampCfg;

typedef struct isp_pg_color_bar_cfg {
	uint16_t width;
	uint32_t ch0[PG_CB_ENTRY_NUM];
	uint32_t ch1[PG_CB_ENTRY_NUM];
	uint32_t ch2[PG_CB_ENTRY_NUM];
} IspPgColorBarCfg;

typedef struct isp_pg_grid_cfg {
	uint16_t line_width;
	uint8_t block_side_length_bw;
	uint32_t line_intensity[INI_BAYER_PHASE_NUM];
	uint32_t block_intensity[INI_BAYER_PHASE_NUM];
} IspPgGridCfg;

typedef struct isp_pg_cfg {
	enum isp_pg_pat_sel sel;
	uint16_t x_cnt_ini;
	uint8_t line_moving;
	struct isp_pg_ramp_cfg ramp;
	struct isp_pg_color_bar_cfg color_bar;
	struct isp_pg_grid_cfg grid;
} IspPgCfg;

/* Start */
void hw_isp_pg_start(uint8_t view);

/* Stop */
void hw_isp_pg_stop(uint8_t view);

/* Resolution */
void hw_isp_pg_set_res(uint8_t view, const struct res *res);
void hw_isp_pg_get_res(uint8_t view, struct res *res);

/* Mode */
void hw_isp_pg_set_mode(uint8_t view, enum isp_pg_mode mode);
enum isp_pg_mode hw_isp_pg_get_mode(uint8_t view);

/* Input format */
void hw_isp_pg_set_input_format(uint8_t view, const struct isp_pg_input_format *cfg);
void hw_isp_pg_get_input_format(uint8_t view, struct isp_pg_input_format *cfg);

/* ROI */
void hw_isp_pg_set_roi(uint8_t view, const struct rect_point *cfg);
void hw_isp_pg_get_roi(uint8_t view, struct rect_point *cfg);

/* PG */
void hw_isp_pg_set_cfg(uint8_t view, const struct isp_pg_cfg *cfg);
void hw_isp_pg_get_cfg(uint8_t view, struct isp_pg_cfg *cfg);

/* Debug */
void hw_isp_pg_set_dbg_mon_sel(uint8_t view, uint8_t debug_mon_sel);
uint8_t hw_isp_pg_get_dbg_mon_sel(uint8_t view);

//
/* Resolution */
void isp_pg_set_res(volatile CsrBankPg *csr, const struct res *res);
void isp_pg_get_res(volatile CsrBankPg *csr, struct res *res);

/* Mode */
void isp_pg_set_mode(volatile CsrBankPg *csr, enum isp_pg_mode mode);
enum isp_pg_mode isp_pg_get_mode(volatile CsrBankPg *csr);

/* Input format */
void isp_pg_set_input_format(volatile CsrBankPg *csr, const struct isp_pg_input_format *cfg);
void isp_pg_get_input_format(volatile CsrBankPg *csr, struct isp_pg_input_format *cfg);

/* ROI */
void isp_pg_set_roi(volatile CsrBankPg *csr, const struct rect_point *cfg);
void isp_pg_get_roi(volatile CsrBankPg *csr, struct rect_point *cfg);

/* PG */
void isp_pg_set_cfg(volatile CsrBankPg *csr, const struct isp_pg_cfg *cfg);
void isp_pg_get_cfg(volatile CsrBankPg *csr, struct isp_pg_cfg *cfg);

/* Debug */
void isp_pg_set_dbg_mon_sel(volatile CsrBankPg *csr, uint8_t debug_mon_sel);
uint8_t isp_pg_get_dbg_mon_sel(volatile CsrBankPg *csr);

//
void hw_isp_pg0_resolution(uint32_t width, uint32_t height);
void hw_isp_pg0_bypass(void);
void hw_isp_pg0_enable(uint32_t pattern_idx, uint32_t cfa_mode_idx, uint32_t bayer_ini_phase);
void hw_isp_pg0_pattern(uint32_t isp_pattern_idx);
void hw_isp_pg0_cfa_mode(uint32_t isp_cfa_mode_idx, uint32_t isp_bayer_ini_phase);
void hw_isp_pg0_start(void);
void hw_isp_pg0_stop(void);
void hw_isp_pg0_debug_mon_sel(uint32_t debug_mon_sel);
void hw_isp_pg0_dump_reg(void);

#endif