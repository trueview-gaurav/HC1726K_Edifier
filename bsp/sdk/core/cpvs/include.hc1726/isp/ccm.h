/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_CCM_H_
#define SAPPORO_CCM_H_

#include "isp_utils.h"
#include "csr_bank_ccm.h"

typedef enum isp_ccm_mode {
	ISP_CCM_MODE_NORMAL = 0,
	ISP_CCM_MODE_DISABLE,
	ISP_CCM_MODE_BYPASS,
	ISP_CCM_MODE_INK,
	ISP_CCM_MODE_NUM,
} IspCcmMode;

typedef struct isp_ccm_cfg {
	uint8_t mode;
	uint16_t coeff_2s[COLOR_CHN_NUM * COLOR_CHN_NUM]; /**< Matrix for calibrate the image color in RGB color space */
	uint32_t offset_2s[COLOR_CHN_NUM]; /**< Set offset */
	struct coring_th {
		uint8_t enable;
		uint16_t alpha_ini;
		uint16_t th[CCM_CORING_TH_ENTRY_NUM];
		uint8_t th_prec[CCM_CORING_TH_ENTRY_NUM];
	} coring;
} IspCcmCfg;

/* CCM */
void isp_ccm_set_cfg(volatile CsrBankCcm *csr, const struct isp_ccm_cfg *cfg);
void isp_ccm_get_cfg(volatile CsrBankCcm *csr, struct isp_ccm_cfg *cfg);

/* Debug */
void isp_ccm_set_dbg_mon_sel(volatile CsrBankCcm *csr, uint8_t debug_mon_sel);
uint8_t isp_ccm_get_dbg_mon_sel(volatile CsrBankCcm *csr);

/* Atpg */
void isp_ccm_set_atpg_test_enable(volatile CsrBankCcm *csr, uint8_t atpg_test_enable);
uint8_t isp_ccm_get_atpg_test_enable(volatile CsrBankCcm *csr);

#endif /* SAPPORO_CCM_H_ */
