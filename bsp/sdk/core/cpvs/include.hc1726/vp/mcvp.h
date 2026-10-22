/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef MCVP_H_
#define MCVP_H_

#include "da_utils.h"
#include "csr_bank_mcvp.h"

typedef struct vp_mcvp_nrw_coring_cfg {
	uint8_t enable;
	uint16_t th;
	uint16_t slope;
} VpMcvpNrwCoringCfg;

void vp_mcvp_set_nrw_coring_cfg(volatile CsrBankMcvp *csr, const VpMcvpNrwCoringCfg *cfg);
void vp_mcvp_get_nrw_coring_cfg(volatile CsrBankMcvp *csr, VpMcvpNrwCoringCfg *cfg);

#endif
