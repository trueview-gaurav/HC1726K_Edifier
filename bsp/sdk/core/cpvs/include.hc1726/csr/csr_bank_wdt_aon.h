/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_WDT_AON_H_
#define CSR_BANK_WDT_AON_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from wdt_aon  ***/
typedef struct csr_bank_wdt_aon {
	/* WDT_AON00 8'h00 */
	union {
		uint32_t wdt_aon00; // word name
		struct {
			uint32_t dis_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON01 8'h04 */
	union {
		uint32_t wdt_aon01; // word name
		struct {
			uint32_t prescaler_th : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON02 8'h08 */
	union {
		uint32_t wdt_aon02; // word name
		struct {
			uint32_t cnt_th_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON03 8'h0C */
	union {
		uint32_t wdt_aon03; // word name
		struct {
			uint32_t cnt_th_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON04 8'h10 */
	union {
		uint32_t wdt_aon04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t cnt_th_2 : 16;
		};
	};
	/* WDT_AON05 8'h14 */
	union {
		uint32_t wdt_aon05; // word name
		struct {
			uint32_t cnt : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON06 8'h18 */
	union {
		uint32_t wdt_aon06; // word name
		struct {
			uint32_t stage : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON07 8'h1C */
	union {
		uint32_t wdt_aon07; // word name
		struct {
			uint32_t polarity : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_AON08 8'h20 */
	union {
		uint32_t wdt_aon08; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankWdt_aon;

#endif