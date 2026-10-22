/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DBC_H_
#define SAPPORO_DBC_H_

#include "is_utils.h"
#include "csr_bank_dbc.h"

typedef enum is_dbc_mode {
	IS_DBC_MODE_NORMAL = 0,
	IS_DBC_MODE_DISABLE = 1,
	IS_DBC_MODE_NUM = 2,
} IsDbcMode;

typedef struct is_dbc_cfg {
	enum is_dbc_mode mode;
	uint16_t level[CFA_PHASE_NUM];
} IsDbcCfg;

/* IRQ mask */
void is_dbc_set_irq_mask_frame_end(volatile CsrBankDbc *csr, uint8_t irq_mask_frame_end);
uint8_t is_dbc_get_irq_mask_frame_end(volatile CsrBankDbc *csr);

/* Resolution */
void is_dbc_set_res(volatile CsrBankDbc *csr, const struct res *res);
void is_dbc_get_res(volatile CsrBankDbc *csr, struct res *res);

/* Input format */
void is_dbc_set_input_format(volatile CsrBankDbc *csr, const struct is_input_format *cfg);
void is_dbc_get_input_format(volatile CsrBankDbc *csr, struct is_input_format *cfg);

/* DBC */
void is_dbc_set_cfg(volatile CsrBankDbc *csr, const struct is_dbc_cfg *cfg);
void is_dbc_get_cfg(volatile CsrBankDbc *csr, struct is_dbc_cfg *cfg);

/* Debug */
void is_dbc_set_dbg_mon_sel(volatile CsrBankDbc *csr, uint8_t debug_mon_sel);
uint8_t is_dbc_get_dbg_mon_sel(volatile CsrBankDbc *csr);

#endif /* SAPPORO_DBC_H_ */
