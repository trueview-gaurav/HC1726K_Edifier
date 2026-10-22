/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DCC_H_
#define SAPPORO_DCC_H_

#include "is_utils.h"
#include "csr_bank_dcc.h"

typedef enum is_dcc_mode {
	IS_DCC_MODE_NORMAL = 0,
	IS_DCC_MODE_DISABLE = 1,
	IS_DCC_MODE_NUM = 2,
} IsDccMode;

typedef struct is_dcc_cfg {
	enum is_dcc_mode mode;
	uint32_t gain[CFA_PHASE_NUM];
	uint32_t offset_2s[CFA_PHASE_NUM];
} IsDccCfg;

typedef struct is_dcc_gain_curve_cfg {
	uint16_t y[DCC_GAIN_CURVE_CTRL_POINT_NUM]; /**< Curve value */
} IsDccGainCurveCfg;

/* IRQ mask */
void is_dcc_set_irq_mask_frame_end(volatile CsrBankDcc *csr, uint8_t irq_mask_frame_end);
uint8_t is_dcc_get_irq_mask_frame_end(volatile CsrBankDcc *csr);

/* Resolution */
void is_dcc_set_res(volatile CsrBankDcc *csr, const struct res *res);
void is_dcc_get_res(volatile CsrBankDcc *csr, struct res *res);

/* Input format */
void is_dcc_set_input_format(volatile CsrBankDcc *csr, const struct is_input_format *cfg);
void is_dcc_get_input_format(volatile CsrBankDcc *csr, struct is_input_format *cfg);

/* DCC */
void is_dcc_set_cfg(volatile CsrBankDcc *csr, const struct is_dcc_cfg *cfg);
void is_dcc_get_cfg(volatile CsrBankDcc *csr, struct is_dcc_cfg *cfg);
void is_dcc_set_gain_curve_cfg(volatile CsrBankDcc *csr, const enum cfa_phase phase,
                               const struct is_dcc_gain_curve_cfg *cfg);
void is_dcc_get_gain_curve_cfg(volatile CsrBankDcc *csr, const enum cfa_phase phase, struct is_dcc_gain_curve_cfg *cfg);

/* Debug */
void is_dcc_set_dbg_mon_sel(volatile CsrBankDcc *csr, uint8_t debug_mon_sel);
uint8_t is_dcc_get_dbg_mon_sel(volatile CsrBankDcc *csr);

#endif /* SAPPORO_DCC_H_ */
