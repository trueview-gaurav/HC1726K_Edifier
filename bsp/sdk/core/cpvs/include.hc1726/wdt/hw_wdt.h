/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_WDT_H_
#define HW_WDT_H_

#include "csr_bank_wdt.h"
#include "csr_bank_wdt_stable.h"

typedef struct wdt_dev {
	uint32_t wdt_base;
	uint32_t wdt_stable_base;
} WdtDev;

void hw_wdt_unlock(volatile struct csr_bank_wdt *base);
void hw_wdt_lock(volatile struct csr_bank_wdt *base);
void hw_wdt_disable(volatile struct csr_bank_wdt *base);
void hw_wdt_enable(volatile struct csr_bank_wdt *base);
void hw_wdt_reboot(volatile struct csr_bank_wdt *base);

#endif /* HW_WDT_H_ */
