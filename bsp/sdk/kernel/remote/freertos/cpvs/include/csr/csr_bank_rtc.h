#ifndef CSR_BANK_RTC_H_
#define CSR_BANK_RTC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rtc  ***/
typedef struct csr_bank_rtc {
	/* RTC00 10'h000 */
	union {
		uint32_t rtc00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC01 10'h004 */
	union {
		uint32_t rtc01; // word name
		struct {
			uint32_t irq_clear_match_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC02 10'h008 */
	union {
		uint32_t rtc02; // word name
		struct {
			uint32_t status_match_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC03 10'h00C */
	union {
		uint32_t rtc03; // word name
		struct {
			uint32_t irq_mask_match_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC04 10'h010 */
	union {
		uint32_t rtc04; // word name
		struct {
			uint32_t irq_clear_match_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC05 10'h014 */
	union {
		uint32_t rtc05; // word name
		struct {
			uint32_t status_match_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC06 10'h018 */
	union {
		uint32_t rtc06; // word name
		struct {
			uint32_t irq_mask_match_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC07 10'h01C */
	union {
		uint32_t rtc07; // word name
		struct {
			uint32_t enable : 1;
			uint32_t : 7; // padding bits
			uint32_t alarm_en : 1;
			uint32_t : 7; // padding bits
			uint32_t out_en : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC08 10'h020 */
	union {
		uint32_t rtc08; // word name
		struct {
			uint32_t busy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RTC09 10'h024 */
	union {
		uint32_t rtc09; // word name
		struct {
			uint32_t rtc_current : 32;
		};
	};
	/* RTC10 10'h028 */
	union {
		uint32_t rtc10; // word name
		struct {
			uint32_t prescaler_th : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* RTC11 10'h02C */
	union {
		uint32_t rtc11; // word name
		struct {
			uint32_t rtc_load : 32;
		};
	};
	/* RTC12 10'h030 */
	union {
		uint32_t rtc12; // word name
		struct {
			uint32_t rtc_match_0 : 32;
		};
	};
	/* RTC13 10'h034 */
	union {
		uint32_t rtc13; // word name
		struct {
			uint32_t rtc_match_1 : 32;
		};
	};
} CsrBankRtc;

#endif