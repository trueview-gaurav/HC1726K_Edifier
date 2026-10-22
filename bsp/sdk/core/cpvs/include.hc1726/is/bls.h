/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_BLS_H_
#define SAPPORO_BLS_H_

#include "is_utils.h"
#include "csr_bank_bls.h"

typedef struct is_bls_stat_frame_ctrl {
	struct rect_point black_rgl;
	struct rect_point active_rgl;
	uint32_t level_pix_num[CFA_PHASE_NUM];
} IsBlsStatFrameCtrl;

typedef struct is_bls_stat {
	uint16_t level[CFA_PHASE_NUM];
	uint16_t remainder[CFA_PHASE_NUM];
} IsBlsStat;

/* IRQ mask */
void is_bls_set_irq_mask_frame_end(volatile CsrBankBls *csr, uint8_t irq_mask_frame_end);
uint8_t is_bls_get_irq_mask_frame_end(volatile CsrBankBls *csr);

/* Resolution */
void is_bls_set_res(volatile CsrBankBls *csr, const struct res *res);
void is_bls_get_res(volatile CsrBankBls *csr, struct res *res);

/* Input format */
void is_bls_set_input_format(volatile CsrBankBls *csr, const struct is_input_format *cfg);
void is_bls_get_input_format(volatile CsrBankBls *csr, struct is_input_format *cfg);

/* Statistics */
void is_bls_set_stat_frame_ctrl(volatile CsrBankBls *csr, const struct is_bls_stat_frame_ctrl *cfg);
void is_bls_get_stat_frame_ctrl(volatile CsrBankBls *csr, struct is_bls_stat_frame_ctrl *cfg);
void is_bls_set_stat_clear(volatile CsrBankBls *csr, uint8_t clear);
uint8_t is_bls_get_stat_clear(volatile CsrBankBls *csr);
void is_bls_set_stat_enable(volatile CsrBankBls *csr, uint8_t enable);
uint8_t is_bls_get_stat_enable(volatile CsrBankBls *csr);
void is_bls_get_stat(volatile CsrBankBls *csr, struct is_bls_stat *stat);

/* Debug */
void is_bls_set_dbg_mon_sel(volatile CsrBankBls *csr, uint8_t debug_mon_sel);
uint8_t is_bls_get_dbg_mon_sel(volatile CsrBankBls *csr);

#endif /* SAPPORO_BLS_H_ */