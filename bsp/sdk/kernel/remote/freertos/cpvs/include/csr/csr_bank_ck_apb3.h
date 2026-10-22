#ifndef CSR_BANK_CK_APB3_H_
#define CSR_BANK_CK_APB3_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ck_apb3  ***/
typedef struct csr_bank_ck_apb3 {
	/* HW_CKG_APB3 12'h000 */
	union {
		uint32_t hw_ckg_apb3; // word name
		struct {
			uint32_t dis_cg_apb_3 : 1;
			uint32_t : 7; // padding bits
			uint32_t cg_delay_m1_apb_3 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCk_apb3;

#endif