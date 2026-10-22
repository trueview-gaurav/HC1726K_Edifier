/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_ISR_H
#define HW_ISR_H

#include "csr_bank_ccqr.h"
#include "da_define.h"

void isr_config(volatile CsrBankCcqr *isr, DramAgentConfig *cfg, FrameInfo *frame);

#endif
