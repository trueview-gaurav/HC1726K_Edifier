/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef PMU_H
#define PMU_H

void pmu_prepare(void);
void pmu_done(void);

/* 
 * pmu_prepare() should be called before any pmu actions (pmu functions below)
 * pmu_done() should be called after pmu actions are done
 */

void pmu_disable_wdt(void);
void pmu_enable_pmu_gpio(void);

#endif
