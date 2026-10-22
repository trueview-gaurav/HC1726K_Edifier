/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DRAMCONTROLLER_H_
#define CSR_BANK_DRAMCONTROLLER_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dramcontroller  ***/
typedef struct csr_bank_dramcontroller {
	/* IP00 15'h00 */
	union {
		uint32_t ip00; // word name
		struct {
			uint32_t ip : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDramcontroller;

#endif