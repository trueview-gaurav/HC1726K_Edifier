/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_LSC_H_
#define SAPPORO_LSC_H_

#include "autoconf.h"

#include "is_utils.h"
#include "csr_bank_lsc.h"

typedef enum iss_lsc_mode {
	IS_LSC_MODE_NORMAL = 0,
	IS_LSC_MODE_DISABLE = 1,
	IS_LSC_MODE_NUM = 2,
} IssLscMode;

typedef struct is_lsc_cfg {
	enum iss_lsc_mode mode;
	uint32_t bayer_phase_srep;
} IsLscCfg;

typedef struct is_lsc_curve_coeff {
	uint32_t fit_y0x0;
	uint32_t dx_y0x0_2s;
	uint32_t dy_y0x0_2s;
	uint32_t dx2;
	uint32_t dy2;
	uint32_t dydx_2s;
} IsLscCurveCoeff;

typedef struct is_lsc_curve_cfg {
	uint8_t enable;
	struct is_lsc_curve_coeff coeff[INI_BAYER_PHASE_NUM];
} IsLscCurveCfg;

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
typedef struct is_lsc_table_coeff {
	uint16_t ee[LSC_TABLE_EE_WORD_NUM];
} IsLsctableCoeff;

typedef enum is_lsc_table_gain_prec {
	IS_LSC_TABLE_GAIN_PREC_8 = 0,
	IS_LSC_TABLE_GAIN_PREC_9 = 1,
	IS_LSC_TABLE_GAIN_PREC_10 = 2,
	IS_LSC_TABLE_GAIN_PREC_11 = 3,
	IS_LSC_TABLE_GAIN_PREC_12 = 4,
	IS_LSC_TABLE_GAIN_PREC_NUM = 5,
} IsLscTableGainPrec;

typedef struct is_lsc_table_cfg {
	uint8_t enable;
	uint8_t merge_en;
	enum is_lsc_table_gain_prec prec;
	uint16_t gain_mod;
	uint8_t hori_start_int;
	uint32_t hori_start_frac;
	uint32_t hori_step;
	uint8_t verti_start_int;
	uint32_t verti_start_frac;
	uint32_t verti_step;
	struct is_lsc_table_coeff coeff;
} IsLscTableCfg;
#endif

/* IRQ mask */
void is_lsc_set_irq_mask_frame_end(volatile CsrBankLsc *csr, uint8_t irq_mask_frame_end);
uint8_t is_lsc_get_irq_mask_frame_end(volatile CsrBankLsc *csr);

/* Resolution */
void is_lsc_set_res(volatile CsrBankLsc *csr, const struct res *res);
void is_lsc_get_res(volatile CsrBankLsc *csr, struct res *res);

/* Input format */
void is_lsc_set_input_format(volatile CsrBankLsc *csr, const struct is_input_format *cfg);
void is_lsc_get_input_format(volatile CsrBankLsc *csr, struct is_input_format *cfg);

// In the Kyoto, bayer_phase_srep always set as 3
void is_lsc_set_cfg(volatile CsrBankLsc *csr, const struct is_lsc_cfg *cfg);
void is_lsc_get_cfg(volatile CsrBankLsc *csr, struct is_lsc_cfg *cfg);
void is_lsc_set_curve_cfg(volatile CsrBankLsc *csr, const struct is_lsc_curve_cfg *cfg);
void is_lsc_get_curve_cfg(volatile CsrBankLsc *csr, struct is_lsc_curve_cfg *cfg);

#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
void is_lsc_set_table_cfg(volatile CsrBankLsc *csr, const struct is_lsc_table_cfg *cfg);
void is_lsc_get_table_cfg(volatile CsrBankLsc *csr, struct is_lsc_table_cfg *cfg);
void is_lsc_set_table_coeff(volatile CsrBankLsc *csr, const struct is_lsc_table_cfg *cfg);
void is_lsc_get_table_coeff(volatile CsrBankLsc *csr, struct is_lsc_table_cfg *cfg);
uint8_t is_lsc_get_csr2sram_en(volatile CsrBankLsc *csr);
#endif

/* Debug */
void is_lsc_set_dbg_mon_sel(volatile CsrBankLsc *csr, uint8_t debug_mon_sel);
uint8_t is_lsc_get_dbg_mon_sel(volatile CsrBankLsc *csr);

#endif /* SAPPORO_LSC_H_ */
