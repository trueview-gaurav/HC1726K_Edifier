/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_FGMA_H_
#define SAPPORO_FGMA_H_

#include "is_utils.h"
#include "csr_bank_isk.h"

typedef enum is_fgma_mode {
	IS_FGMA_MODE_NORMAL = 0,
	IS_FGMA_MODE_DISABLE = 1,
	IS_FGMA_MODE_NUM = 2,
} IsFgmaMode;

typedef struct is_fgma_cfg {
	enum is_fgma_mode mode;
} IsFgmaCfg;

/* FGMA */
void is_fgma_set_cfg(volatile CsrBankIsk *csr, const struct is_fgma_cfg *cfg);
void is_fgma_get_cfg(volatile CsrBankIsk *csr, struct is_fgma_cfg *cfg);

#endif /* SAPPORO_FGMA_H_ */