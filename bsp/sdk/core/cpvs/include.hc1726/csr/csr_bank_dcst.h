/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DCST_H_
#define CSR_BANK_DCST_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dcst  ***/
typedef struct csr_bank_dcst {
	/* Y_PARA_0 16'h0000 */
	union {
		uint32_t y_para_0; // word name
		struct {
			uint32_t coeff_00_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_PARA_1 16'h0004 */
	union {
		uint32_t y_para_1; // word name
		struct {
			uint32_t coeff_01_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_PARA_2 16'h0008 */
	union {
		uint32_t y_para_2; // word name
		struct {
			uint32_t coeff_02_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* Y_PARA_3 16'h000C */
	union {
		uint32_t y_para_3; // word name
		struct {
			uint32_t offset_i_0_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* U_PARA_0 16'h0010 */
	union {
		uint32_t u_para_0; // word name
		struct {
			uint32_t coeff_10_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* U_PARA_1 16'h0014 */
	union {
		uint32_t u_para_1; // word name
		struct {
			uint32_t coeff_11_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* U_PARA_2 16'h0018 */
	union {
		uint32_t u_para_2; // word name
		struct {
			uint32_t coeff_12_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* U_PARA_3 16'h001C */
	union {
		uint32_t u_para_3; // word name
		struct {
			uint32_t offset_i_1_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* V_PARA_0 16'h0020 */
	union {
		uint32_t v_para_0; // word name
		struct {
			uint32_t coeff_20_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* V_PARA_1 16'h0024 */
	union {
		uint32_t v_para_1; // word name
		struct {
			uint32_t coeff_21_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* V_PARA_2 16'h0028 */
	union {
		uint32_t v_para_2; // word name
		struct {
			uint32_t coeff_22_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* V_PARA_3 16'h002C */
	union {
		uint32_t v_para_3; // word name
		struct {
			uint32_t offset_i_2_2s : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ATPG_TEST 16'h0030 */
	union {
		uint32_t atpg_test; // word name
		struct {
			uint32_t atpg_test_enable : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h0034 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED 16'h0038 */
	union {
		uint32_t word_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankDcst;

#endif