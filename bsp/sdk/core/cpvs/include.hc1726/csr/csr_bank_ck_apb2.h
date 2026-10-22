/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CK_APB2_H_
#define CSR_BANK_CK_APB2_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ck_apb2  ***/
typedef struct csr_bank_ck_apb2 {
	/* HW_CKG_APB2 12'h000 */
	union {
		uint32_t hw_ckg_apb2; // word name
		struct {
			uint32_t dis_cg_apb_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t cg_delay_m1_apb_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCk_apb2;

#endif