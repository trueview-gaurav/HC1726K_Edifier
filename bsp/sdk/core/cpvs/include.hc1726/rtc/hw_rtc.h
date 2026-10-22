/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_RTC_H_
#define HW_RTC_H_

#include "csr_bank_rtc.h"

typedef struct rtc_time {
	uint32_t sec;
	uint32_t min;
	uint32_t hour;
	uint32_t day;
} RTC_TIME;

void hw_rtc_run(volatile struct csr_bank_rtc *base);
void hw_rtc_stop(volatile struct csr_bank_rtc *base);
void hw_rtc_clr_irq_cpu(volatile struct csr_bank_rtc *base);
void hw_rtc_clr_irq_pmu(volatile struct csr_bank_rtc *base);
void hw_rtc_set_irq_mask_cpu(volatile struct csr_bank_rtc *base, uint32_t irq_mask);
void hw_rtc_set_irq_mask_pmu(volatile struct csr_bank_rtc *base, uint32_t irq_mask);
void hw_rtc_sw_reset(volatile struct csr_bank_rtc *base);
void hw_rtc_set_time(volatile struct csr_bank_rtc *base, RTC_TIME *rtc_time);
void hw_rtc_get_time(volatile struct csr_bank_rtc *base, RTC_TIME *rtc_time);
void hw_rtc_set_alarm_cpu(volatile struct csr_bank_rtc *base, RTC_TIME *rtc_time);
void hw_rtc_set_alarm_pmu(volatile struct csr_bank_rtc *base, RTC_TIME *rtc_time);

#endif /* HW_RTC_H_ */
