/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

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
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_PARA_1 16'h0004 */
	union {
		uint32_t r_para_1; // word name
		struct {
			uint32_t coeff_01_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_PARA_2 16'h0008 */
	union {
		uint32_t r_para_2; // word name
		struct {
			uint32_t coeff_02_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* R_PARA_3 16'h000C */
	union {
		uint32_t r_para_3; // word name
		struct {
			uint32_t offset_o_0_2s : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_PARA_0 16'h0010 */
	union {
		uint32_t g_para_0; // word name
		struct {
			uint32_t coeff_10_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_PARA_1 16'h0014 */
	union {
		uint32_t g_para_1; // word name
		struct {
			uint32_t coeff_11_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_PARA_2 16'h0018 */
	union {
		uint32_t g_para_2; // word name
		struct {
			uint32_t coeff_12_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* G_PARA_3 16'h001C */
	union {
		uint32_t g_para_3; // word name
		struct {
			uint32_t offset_o_1_2s : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_PARA_0 16'h0020 */
	union {
		uint32_t b_para_0; // word name
		struct {
			uint32_t coeff_20_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_PARA_1 16'h0024 */
	union {
		uint32_t b_para_1; // word name
		struct {
			uint32_t coeff_21_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_PARA_2 16'h0028 */
	union {
		uint32_t b_para_2; // word name
		struct {
			uint32_t coeff_22_2s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* B_PARA_3 16'h002C */
	union {
		uint32_t b_para_3; // word name
		struct {
			uint32_t offset_o_2_2s : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CORING_EN 16'h0030 */
	union {
		uint32_t word_coring_en; // word name
		struct {
			uint32_t coring_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CORING_TH_0 16'h0034 */
	union {
		uint32_t word_coring_th_0; // word name
		struct {
			uint32_t coring_th_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CORING_TH_1 16'h0038 */
	union {
		uint32_t word_coring_th_1; // word name
		struct {
			uint32_t coring_th_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CORING_TH_2 16'h003C */
	union {
		uint32_t word_coring_th_2; // word name
		struct {
			uint32_t coring_th_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CORING_TH_3 16'h0040 */
	union {
		uint32_t word_coring_th_3; // word name
		struct {
			uint32_t coring_th_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CORING_PREC 16'h0044 */
	union {
		uint32_t word_coring_prec; // word name
		struct {
			uint32_t coring_th_prec_0 : 4;
			uint32_t coring_th_prec_1 : 4;
			uint32_t coring_th_prec_2 : 4;
			uint32_t coring_th_prec_3 : 4;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ALPHA_INI 16'h0048 */
	union {
		uint32_t word_alpha_ini; // word name
		struct {
			uint32_t alpha_ini : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h004C */
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
	/* MODE_CTRL 16'h0050 */
	union {
		uint32_t mode_ctrl; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t atpg_test_enable : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCcm;

#endif