/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_GMA_H_
#define CSR_BANK_GMA_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from gma  ***/
typedef struct csr_bank_gma {
	/* WORD_MODE 16'h0000 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_0 16'h0004 */
	union {
		uint32_t word_gamma_curve_0; // word name
		struct {
			uint32_t gamma_curve_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_1 16'h0008 */
	union {
		uint32_t word_gamma_curve_1; // word name
		struct {
			uint32_t gamma_curve_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_2 16'h000C */
	union {
		uint32_t word_gamma_curve_2; // word name
		struct {
			uint32_t gamma_curve_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_3 16'h0010 */
	union {
		uint32_t word_gamma_curve_3; // word name
		struct {
			uint32_t gamma_curve_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_4 16'h0014 */
	union {
		uint32_t word_gamma_curve_4; // word name
		struct {
			uint32_t gamma_curve_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_10 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_5 16'h0018 */
	union {
		uint32_t word_gamma_curve_5; // word name
		struct {
			uint32_t gamma_curve_11 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_12 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_6 16'h001C */
	union {
		uint32_t word_gamma_curve_6; // word name
		struct {
			uint32_t gamma_curve_13 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_14 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_7 16'h0020 */
	union {
		uint32_t word_gamma_curve_7; // word name
		struct {
			uint32_t gamma_curve_15 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_16 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_8 16'h0024 */
	union {
		uint32_t word_gamma_curve_8; // word name
		struct {
			uint32_t gamma_curve_17 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_18 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_9 16'h0028 */
	union {
		uint32_t word_gamma_curve_9; // word name
		struct {
			uint32_t gamma_curve_19 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_20 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_10 16'h002C */
	union {
		uint32_t word_gamma_curve_10; // word name
		struct {
			uint32_t gamma_curve_21 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_22 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_11 16'h0030 */
	union {
		uint32_t word_gamma_curve_11; // word name
		struct {
			uint32_t gamma_curve_23 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_24 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_12 16'h0034 */
	union {
		uint32_t word_gamma_curve_12; // word name
		struct {
			uint32_t gamma_curve_25 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_26 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_13 16'h0038 */
	union {
		uint32_t word_gamma_curve_13; // word name
		struct {
			uint32_t gamma_curve_27 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_28 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_14 16'h003C */
	union {
		uint32_t word_gamma_curve_14; // word name
		struct {
			uint32_t gamma_curve_29 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_30 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_15 16'h0040 */
	union {
		uint32_t word_gamma_curve_15; // word name
		struct {
			uint32_t gamma_curve_31 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_32 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_16 16'h0044 */
	union {
		uint32_t word_gamma_curve_16; // word name
		struct {
			uint32_t gamma_curve_33 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_34 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_17 16'h0048 */
	union {
		uint32_t word_gamma_curve_17; // word name
		struct {
			uint32_t gamma_curve_35 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_36 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_18 16'h004C */
	union {
		uint32_t word_gamma_curve_18; // word name
		struct {
			uint32_t gamma_curve_37 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_38 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_19 16'h0050 */
	union {
		uint32_t word_gamma_curve_19; // word name
		struct {
			uint32_t gamma_curve_39 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_40 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_20 16'h0054 */
	union {
		uint32_t word_gamma_curve_20; // word name
		struct {
			uint32_t gamma_curve_41 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_42 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_21 16'h0058 */
	union {
		uint32_t word_gamma_curve_21; // word name
		struct {
			uint32_t gamma_curve_43 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_44 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_22 16'h005C */
	union {
		uint32_t word_gamma_curve_22; // word name
		struct {
			uint32_t gamma_curve_45 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_46 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_23 16'h0060 */
	union {
		uint32_t word_gamma_curve_23; // word name
		struct {
			uint32_t gamma_curve_47 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_48 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_24 16'h0064 */
	union {
		uint32_t word_gamma_curve_24; // word name
		struct {
			uint32_t gamma_curve_49 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_50 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_25 16'h0068 */
	union {
		uint32_t word_gamma_curve_25; // word name
		struct {
			uint32_t gamma_curve_51 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_52 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_26 16'h006C */
	union {
		uint32_t word_gamma_curve_26; // word name
		struct {
			uint32_t gamma_curve_53 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_54 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_27 16'h0070 */
	union {
		uint32_t word_gamma_curve_27; // word name
		struct {
			uint32_t gamma_curve_55 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_56 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_GAMMA_CURVE_28 16'h0074 */
	union {
		uint32_t word_gamma_curve_28; // word name
		struct {
			uint32_t gamma_curve_57 : 14;
			uint32_t : 2; // padding bits
			uint32_t gamma_curve_58 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h0078 */
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
} CsrBankGma;

#endif