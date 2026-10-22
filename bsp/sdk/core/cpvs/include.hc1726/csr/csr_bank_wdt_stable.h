/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_WDT_STABLE_H_
#define CSR_BANK_WDT_STABLE_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from wdt_stable  ***/
typedef struct csr_bank_wdt_stable {
	/* WDT_STABLE00 10'h000 */
	union {
		uint32_t WDT_ACTIVE_RESET_FLAG; // word name
		struct {
			uint32_t rg_active_reset_flag : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_STABLE01 10'h004 */
	union {
		uint32_t WDT_ACTIVE_RESET_FLAG_CLR; // word name
		struct {
			uint32_t rg_clr_active_reset_flag : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_STABLE02 10'h008 */
	union {
		uint32_t WDT_LOCK_STATUS; // word name
		struct {
			uint32_t wdt_stable_lock : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_STABLE03 10'h00C */
	union {
		uint32_t WDT_RESET_CYCLE_CTRL; // word name
		struct {
			uint32_t wdt_rst_cycle : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDT_STABLE04 10'h010 */
	union {
		uint32_t WDT_STABLE_RESERVED; // word name
		struct {
			uint32_t rg_reserved : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankWdt_stable;

#endif