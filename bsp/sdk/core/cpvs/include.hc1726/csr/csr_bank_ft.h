/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_FT_H_
#define CSR_BANK_FT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ft  ***/
typedef struct csr_bank_ft {
	/* FTI00 16'h00 */
	union {
		uint32_t fti00; // word name
		struct {
			uint32_t trans_size : 2;
			uint32_t : 6; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FTI01 16'h04 */
	union {
		uint32_t fti01; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankFt;

#endif