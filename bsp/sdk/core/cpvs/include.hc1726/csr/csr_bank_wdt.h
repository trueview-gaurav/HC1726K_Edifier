/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_WDT_H_
#define CSR_BANK_WDT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from wdt  ***/
typedef struct csr_bank_wdt {
	/* WDT00 10'h000 */
	union {
		uint32_t WDT_TRIGGER; // word name
		struct {
			uint32_t trigger : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT01 10'h004 */
	union {
		uint32_t IRQ_CLR; // word name
		struct {
			uint32_t irq_clear_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT02 10'h008 */
	union {
		uint32_t IRQ_STATUS; // word name
		struct {
			uint32_t status_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT03 10'h00C */
	union {
		uint32_t WDT_STATUS; // word name
		struct {
			uint32_t lock_status : 1;
			uint32_t : 7; // padding bits
			uint32_t stage : 2;
			uint32_t : 6; // padding bits
			uint32_t count_value : 16;
		};
	};
	/* WDT04 10'h010 */
	union {
		uint32_t WDT_UNLOCK; // word name
		struct {
			uint32_t unlock_reg : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT05 10'h014 */
	union {
		uint32_t WDT_CTRL; // word name
		struct {
			uint32_t sw_disable : 1;
			uint32_t : 7; // padding bits
			uint32_t active_timeout_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t prescaler : 4;
			uint32_t : 4; // padding bits
			uint32_t wdt_pad_rst_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WDT06 10'h018 */
	union {
		uint32_t WDT_CNT_TH_INIT; // word name
		struct {
			uint32_t count_init : 16;
			uint32_t : 16; // padding bits
		};
	};
	/* WDT07 10'h01C */
	union {
		uint32_t WDT_CNT_TH_NORMAL; // word name
		struct {
			uint32_t count_normal_min : 16;
			uint32_t count_normal_max : 16;
		};
	};
	/* WDT08 10'h020 */
	union {
		uint32_t WDT_CNT_TH_TIMEOUT; // word name
		struct {
			uint32_t count_timeout_1 : 15;
			uint32_t : 1; // padding bits
			uint32_t count_timeout_2 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* WDT09 10'h024 */
	union {
		uint32_t WDT_RESERVED; // word name
		struct {
			uint32_t reserved : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankWdt;

#endif