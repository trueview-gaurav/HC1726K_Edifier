/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_RTC_H_
#define CSR_BANK_RTC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rtc  ***/
typedef struct csr_bank_rtc {
	/* RTC_CTRL 10'h000 */
	union {
		uint32_t rtc_ctrl; // word name
		struct {
			uint32_t run_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t read : 1;
			uint32_t : 7; // padding bits
			uint32_t write : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC_STATE 10'h004 */
	union {
		uint32_t rtc_state; // word name
		struct {
			uint32_t counting_busy : 1;
			uint32_t : 7; // padding bits
			uint32_t read_done : 1;
			uint32_t : 7; // padding bits
			uint32_t write_done : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC_RST_STATE 10'h008 */
	union {
		uint32_t rtc_rst_state; // word name
		struct {
			uint32_t rst_state : 32;
		};
	};
	/* IRQ_CLEAR 10'h00C */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_alarm_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_alarm_pmu : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h010 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_alarm_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_alarm_pmu : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 10'h014 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_match_alarm_cpu : 1;
			uint32_t : 7; // padding bits
			uint32_t status_match_alarm_pmu : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIME_WRITE 10'h018 */
	union {
		uint32_t time_write; // word name
		struct {
			uint32_t time_sec_write : 6;
			uint32_t time_min_write : 6;
			uint32_t time_hour_write : 5;
			uint32_t time_day_write : 15;
		};
	};
	/* TIME_READ 10'h01C */
	union {
		uint32_t time_read; // word name
		struct {
			uint32_t time_sec_read : 6;
			uint32_t time_min_read : 6;
			uint32_t time_hour_read : 5;
			uint32_t time_day_read : 15;
		};
	};
	/* ALARM_CPU 10'h020 */
	union {
		uint32_t alarm_cpu; // word name
		struct {
			uint32_t alarm_cpu_sec_th : 6;
			uint32_t alarm_cpu_min_th : 6;
			uint32_t alarm_cpu_hour_th : 5;
			uint32_t alarm_cpu_day_th : 15;
		};
	};
	/* ALARM_PMU 10'h024 */
	union {
		uint32_t alarm_pmu; // word name
		struct {
			uint32_t alarm_pmu_sec_th : 6;
			uint32_t alarm_pmu_min_th : 6;
			uint32_t alarm_pmu_hour_th : 5;
			uint32_t alarm_pmu_day_th : 15;
		};
	};
} CsrBankRtc;

#endif