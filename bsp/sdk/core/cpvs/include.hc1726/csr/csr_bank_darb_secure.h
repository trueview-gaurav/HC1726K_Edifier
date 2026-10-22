#ifndef CSR_BANK_DARB_SECURE_H_
#define CSR_BANK_DARB_SECURE_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from darb_secure  ***/
typedef struct csr_bank_darb_secure {
	/* READ_SECURE 10'h000 */
	union {
		uint32_t read_secure; // word name
		struct {
			uint32_t secure_r_00 : 1;
			uint32_t secure_r_01 : 1;
			uint32_t secure_r_02 : 1;
			uint32_t secure_r_03 : 1;
			uint32_t secure_r_04 : 1;
			uint32_t secure_r_05 : 1;
			uint32_t secure_r_06 : 1;
			uint32_t secure_r_07 : 1;
			uint32_t secure_r_08 : 1;
			uint32_t secure_r_09 : 1;
			uint32_t secure_r_10 : 1;
			uint32_t secure_r_11 : 1;
			uint32_t secure_r_12 : 1;
			uint32_t secure_r_13 : 1;
			uint32_t secure_r_14 : 1;
			uint32_t secure_r_15 : 1;
			uint32_t secure_r_16 : 1;
			uint32_t secure_r_17 : 1;
			uint32_t secure_r_18 : 1;
			uint32_t secure_r_19 : 1;
			uint32_t secure_r_20 : 1;
			uint32_t secure_r_21 : 1;
			uint32_t secure_r_22 : 1;
			uint32_t secure_r_23 : 1;
			uint32_t secure_r_24 : 1;
			uint32_t secure_r_25 : 1;
			uint32_t secure_r_26 : 1;
			uint32_t secure_r_27 : 1;
			uint32_t secure_r_28 : 1;
			uint32_t secure_r_29 : 1;
			uint32_t secure_r_30 : 1;
			uint32_t secure_r_31 : 1;
		};
	};
	/* WRITE_SECURE 10'h004 */
	union {
		uint32_t write_secure; // word name
		struct {
			uint32_t secure_w_00 : 1;
			uint32_t secure_w_01 : 1;
			uint32_t secure_w_02 : 1;
			uint32_t secure_w_03 : 1;
			uint32_t secure_w_04 : 1;
			uint32_t secure_w_05 : 1;
			uint32_t secure_w_06 : 1;
			uint32_t secure_w_07 : 1;
			uint32_t secure_w_08 : 1;
			uint32_t secure_w_09 : 1;
			uint32_t secure_w_10 : 1;
			uint32_t secure_w_11 : 1;
			uint32_t secure_w_12 : 1;
			uint32_t secure_w_13 : 1;
			uint32_t secure_w_14 : 1;
			uint32_t secure_w_15 : 1;
			uint32_t secure_w_16 : 1;
			uint32_t secure_w_17 : 1;
			uint32_t secure_w_18 : 1;
			uint32_t secure_w_19 : 1;
			uint32_t secure_w_20 : 1;
			uint32_t secure_w_21 : 1;
			uint32_t secure_w_22 : 1;
			uint32_t secure_w_23 : 1;
			uint32_t secure_w_24 : 1;
			uint32_t secure_w_25 : 1;
			uint32_t secure_w_26 : 1;
			uint32_t secure_w_27 : 1;
			uint32_t secure_w_28 : 1;
			uint32_t secure_w_29 : 1;
			uint32_t secure_w_30 : 1;
			uint32_t secure_w_31 : 1;
		};
	};
} CsrBankDarb_secure;

#endif
