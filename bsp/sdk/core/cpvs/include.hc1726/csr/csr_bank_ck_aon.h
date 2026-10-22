/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CK_AON_H_
#define CSR_BANK_CK_AON_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ck_aon  ***/
typedef struct csr_bank_ck_aon {
	/* CKG_AON_0 10'h000 */
	union {
		uint32_t ckg_aon_0; // word name
		struct {
			uint32_t cken_psd : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_lpmd : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_rtc : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_wdt : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CKG_AON_1 10'h004 */
	union {
		uint32_t ckg_aon_1; // word name
		struct {
			uint32_t cken_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_irq : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dvp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 10'h008 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_1 10'h00C */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCk_aon;

#endif