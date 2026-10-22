/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_CST_H_
#define SAPPORO_CST_H_

#include "isp_utils.h"
#include "csr_bank_cst.h"

typedef struct isp_cst_cfg {
	uint16_t coeff_2s[COLOR_CHN_NUM * COLOR_CHN_NUM]; /**< Matrix for RGB to YUV */
	uint16_t offset_2s[COLOR_CHN_NUM]; /**< Set offset */
} IspCstCfg;

/* CST */
void isp_cst_set_cfg(volatile CsrBankCst *csr, const struct isp_cst_cfg *cfg);
void isp_cst_get_cfg(volatile CsrBankCst *csr, struct isp_cst_cfg *cfg);

/* Debug */
void isp_cst_set_dbg_mon_sel(volatile CsrBankCst *csr, uint8_t debug_mon_sel);
uint8_t isp_cst_get_dbg_mon_sel(volatile CsrBankCst *csr);

#endif /* SAPPORO_CST_H_ */