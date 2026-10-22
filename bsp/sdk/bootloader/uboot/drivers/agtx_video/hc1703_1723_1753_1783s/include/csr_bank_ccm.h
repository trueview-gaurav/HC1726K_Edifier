#ifndef CSR_BANK_CCM_H_
#define CSR_BANK_CCM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ccm  ***/
typedef struct csr_bank_ccm {
	/* R_PARA_0 16'h0000 */
	union {
		uint32_t r_para_0; // word name
		struct {
			uint32_t coeff_00_2s : 16;
			uint32_t coeff_01_2s : 16;
		};
	};
	/* R_PARA_1 16'h0004 */
	union {
		uint32_t r_para_1; // word name
		struct {
			uint32_t coeff_02_2s : 16;
			uint32_t offset_o_0_2s : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* G_PARA_0 16'h0008 */
	union {
		uint32_t g_para_0; // word name
		struct {
			uint32_t coeff_10_2s : 16;
			uint32_t coeff_11_2s : 16;
		};
	};
	/* G_PARA_1 16'h000C */
	union {
		uint32_t g_para_1; // word name
		struct {
			uint32_t coeff_12_2s : 16;
			uint32_t offset_o_1_2s : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* B_PARA_0 16'h0010 */
	union {
		uint32_t b_para_0; // word name
		struct {
			uint32_t coeff_20_2s : 16;
			uint32_t coeff_21_2s : 16;
		};
	};
	/* B_PARA_1 16'h0014 */
	union {
		uint32_t b_para_1; // word name
		struct {
			uint32_t coeff_22_2s : 16;
			uint32_t offset_o_2_2s : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h0018 */
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
} CsrBankCcm;

#endif