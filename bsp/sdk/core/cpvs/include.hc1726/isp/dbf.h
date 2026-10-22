/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DBF_H_
#define SAPPORO_DBF_H_

#include "isp_utils.h"
#include "csr_bank_dbf.h"

typedef struct isp_dbf_cfg {
	uint8_t enable;
	uint8_t filter_type;
	uint8_t range;
	uint8_t alpha_slope;
	uint8_t alpha_max;
} IspDbfCfg;

/* DBF */
void isp_dbf_set_cfg(volatile CsrBankDbf *csr, const struct isp_dbf_cfg *cfg);
void isp_dbf_get_cfg(volatile CsrBankDbf *csr, struct isp_dbf_cfg *cfg);
void isp_dbf_set_width(volatile CsrBankDbf *csr, uint16_t width);
uint16_t isp_dbf_get_width(volatile CsrBankDbf *csr);
void isp_dbf_set_block_x(volatile CsrBankDbf *csr, uint16_t block_x);
uint16_t isp_dbf_get_block_x(volatile CsrBankDbf *csr);

/* Debug */
void isp_dbf_set_dbg_mon_sel(volatile CsrBankDbf *csr, uint8_t debug_mon_sel);
uint8_t isp_dbf_get_dbg_mon_sel(volatile CsrBankDbf *csr);

#endif /* SAPPORO_DBF_H_ */