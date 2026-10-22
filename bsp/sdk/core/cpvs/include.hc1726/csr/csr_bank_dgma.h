/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DGMA_H_
#define CSR_BANK_DGMA_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dgma  ***/
typedef struct csr_bank_dgma {
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
	/* GAMMA_CURVE_0_0 16'h0004 */
	union {
		uint32_t gamma_curve_0_0; // word name
		struct {
			uint32_t gma_curve_0_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_1 16'h0008 */
	union {
		uint32_t gamma_curve_0_1; // word name
		struct {
			uint32_t gma_curve_0_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_2 16'h000C */
	union {
		uint32_t gamma_curve_0_2; // word name
		struct {
			uint32_t gma_curve_0_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_3 16'h0010 */
	union {
		uint32_t gamma_curve_0_3; // word name
		struct {
			uint32_t gma_curve_0_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_4 16'h0014 */
	union {
		uint32_t gamma_curve_0_4; // word name
		struct {
			uint32_t gma_curve_0_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_10 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_5 16'h0018 */
	union {
		uint32_t gamma_curve_0_5; // word name
		struct {
			uint32_t gma_curve_0_11 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_12 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_6 16'h001C */
	union {
		uint32_t gamma_curve_0_6; // word name
		struct {
			uint32_t gma_curve_0_13 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_14 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_7 16'h0020 */
	union {
		uint32_t gamma_curve_0_7; // word name
		struct {
			uint32_t gma_curve_0_15 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_16 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_8 16'h0024 */
	union {
		uint32_t gamma_curve_0_8; // word name
		struct {
			uint32_t gma_curve_0_17 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_18 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_9 16'h0028 */
	union {
		uint32_t gamma_curve_0_9; // word name
		struct {
			uint32_t gma_curve_0_19 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_20 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_10 16'h002C */
	union {
		uint32_t gamma_curve_0_10; // word name
		struct {
			uint32_t gma_curve_0_21 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_22 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_11 16'h0030 */
	union {
		uint32_t gamma_curve_0_11; // word name
		struct {
			uint32_t gma_curve_0_23 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_24 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_12 16'h0034 */
	union {
		uint32_t gamma_curve_0_12; // word name
		struct {
			uint32_t gma_curve_0_25 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_26 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_13 16'h0038 */
	union {
		uint32_t gamma_curve_0_13; // word name
		struct {
			uint32_t gma_curve_0_27 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_28 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_14 16'h003C */
	union {
		uint32_t gamma_curve_0_14; // word name
		struct {
			uint32_t gma_curve_0_29 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_30 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_15 16'h0040 */
	union {
		uint32_t gamma_curve_0_15; // word name
		struct {
			uint32_t gma_curve_0_31 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_32 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_16 16'h0044 */
	union {
		uint32_t gamma_curve_0_16; // word name
		struct {
			uint32_t gma_curve_0_33 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_34 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_17 16'h0048 */
	union {
		uint32_t gamma_curve_0_17; // word name
		struct {
			uint32_t gma_curve_0_35 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_36 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_18 16'h004C */
	union {
		uint32_t gamma_curve_0_18; // word name
		struct {
			uint32_t gma_curve_0_37 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_38 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_19 16'h0050 */
	union {
		uint32_t gamma_curve_0_19; // word name
		struct {
			uint32_t gma_curve_0_39 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_40 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_20 16'h0054 */
	union {
		uint32_t gamma_curve_0_20; // word name
		struct {
			uint32_t gma_curve_0_41 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_42 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_21 16'h0058 */
	union {
		uint32_t gamma_curve_0_21; // word name
		struct {
			uint32_t gma_curve_0_43 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_44 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_22 16'h005C */
	union {
		uint32_t gamma_curve_0_22; // word name
		struct {
			uint32_t gma_curve_0_45 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_46 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_23 16'h0060 */
	union {
		uint32_t gamma_curve_0_23; // word name
		struct {
			uint32_t gma_curve_0_47 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_48 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_24 16'h0064 */
	union {
		uint32_t gamma_curve_0_24; // word name
		struct {
			uint32_t gma_curve_0_49 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_50 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_25 16'h0068 */
	union {
		uint32_t gamma_curve_0_25; // word name
		struct {
			uint32_t gma_curve_0_51 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_52 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_26 16'h006C */
	union {
		uint32_t gamma_curve_0_26; // word name
		struct {
			uint32_t gma_curve_0_53 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_54 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_27 16'h0070 */
	union {
		uint32_t gamma_curve_0_27; // word name
		struct {
			uint32_t gma_curve_0_55 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_56 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_0_28 16'h0074 */
	union {
		uint32_t gamma_curve_0_28; // word name
		struct {
			uint32_t gma_curve_0_57 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_0_58 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_0 16'h0078 */
	union {
		uint32_t gamma_curve_1_0; // word name
		struct {
			uint32_t gma_curve_1_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_1 16'h007C */
	union {
		uint32_t gamma_curve_1_1; // word name
		struct {
			uint32_t gma_curve_1_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_2 16'h0080 */
	union {
		uint32_t gamma_curve_1_2; // word name
		struct {
			uint32_t gma_curve_1_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_3 16'h0084 */
	union {
		uint32_t gamma_curve_1_3; // word name
		struct {
			uint32_t gma_curve_1_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_4 16'h0088 */
	union {
		uint32_t gamma_curve_1_4; // word name
		struct {
			uint32_t gma_curve_1_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_10 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_5 16'h008C */
	union {
		uint32_t gamma_curve_1_5; // word name
		struct {
			uint32_t gma_curve_1_11 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_12 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_6 16'h0090 */
	union {
		uint32_t gamma_curve_1_6; // word name
		struct {
			uint32_t gma_curve_1_13 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_14 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_7 16'h0094 */
	union {
		uint32_t gamma_curve_1_7; // word name
		struct {
			uint32_t gma_curve_1_15 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_16 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_8 16'h0098 */
	union {
		uint32_t gamma_curve_1_8; // word name
		struct {
			uint32_t gma_curve_1_17 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_18 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_9 16'h009C */
	union {
		uint32_t gamma_curve_1_9; // word name
		struct {
			uint32_t gma_curve_1_19 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_20 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_10 16'h00A0 */
	union {
		uint32_t gamma_curve_1_10; // word name
		struct {
			uint32_t gma_curve_1_21 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_22 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_11 16'h00A4 */
	union {
		uint32_t gamma_curve_1_11; // word name
		struct {
			uint32_t gma_curve_1_23 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_24 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_12 16'h00A8 */
	union {
		uint32_t gamma_curve_1_12; // word name
		struct {
			uint32_t gma_curve_1_25 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_26 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_13 16'h00AC */
	union {
		uint32_t gamma_curve_1_13; // word name
		struct {
			uint32_t gma_curve_1_27 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_28 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_14 16'h00B0 */
	union {
		uint32_t gamma_curve_1_14; // word name
		struct {
			uint32_t gma_curve_1_29 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_30 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_15 16'h00B4 */
	union {
		uint32_t gamma_curve_1_15; // word name
		struct {
			uint32_t gma_curve_1_31 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_32 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_16 16'h00B8 */
	union {
		uint32_t gamma_curve_1_16; // word name
		struct {
			uint32_t gma_curve_1_33 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_34 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_17 16'h00BC */
	union {
		uint32_t gamma_curve_1_17; // word name
		struct {
			uint32_t gma_curve_1_35 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_36 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_18 16'h00C0 */
	union {
		uint32_t gamma_curve_1_18; // word name
		struct {
			uint32_t gma_curve_1_37 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_38 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_19 16'h00C4 */
	union {
		uint32_t gamma_curve_1_19; // word name
		struct {
			uint32_t gma_curve_1_39 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_40 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_20 16'h00C8 */
	union {
		uint32_t gamma_curve_1_20; // word name
		struct {
			uint32_t gma_curve_1_41 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_42 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_21 16'h00CC */
	union {
		uint32_t gamma_curve_1_21; // word name
		struct {
			uint32_t gma_curve_1_43 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_44 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_22 16'h00D0 */
	union {
		uint32_t gamma_curve_1_22; // word name
		struct {
			uint32_t gma_curve_1_45 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_46 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_23 16'h00D4 */
	union {
		uint32_t gamma_curve_1_23; // word name
		struct {
			uint32_t gma_curve_1_47 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_48 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_24 16'h00D8 */
	union {
		uint32_t gamma_curve_1_24; // word name
		struct {
			uint32_t gma_curve_1_49 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_50 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_25 16'h00DC */
	union {
		uint32_t gamma_curve_1_25; // word name
		struct {
			uint32_t gma_curve_1_51 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_52 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_26 16'h00E0 */
	union {
		uint32_t gamma_curve_1_26; // word name
		struct {
			uint32_t gma_curve_1_53 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_54 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_27 16'h00E4 */
	union {
		uint32_t gamma_curve_1_27; // word name
		struct {
			uint32_t gma_curve_1_55 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_56 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_1_28 16'h00E8 */
	union {
		uint32_t gamma_curve_1_28; // word name
		struct {
			uint32_t gma_curve_1_57 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_1_58 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_0 16'h00EC */
	union {
		uint32_t gamma_curve_2_0; // word name
		struct {
			uint32_t gma_curve_2_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_1 16'h00F0 */
	union {
		uint32_t gamma_curve_2_1; // word name
		struct {
			uint32_t gma_curve_2_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_2 16'h00F4 */
	union {
		uint32_t gamma_curve_2_2; // word name
		struct {
			uint32_t gma_curve_2_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_3 16'h00F8 */
	union {
		uint32_t gamma_curve_2_3; // word name
		struct {
			uint32_t gma_curve_2_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_4 16'h00FC */
	union {
		uint32_t gamma_curve_2_4; // word name
		struct {
			uint32_t gma_curve_2_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_10 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_5 16'h0100 */
	union {
		uint32_t gamma_curve_2_5; // word name
		struct {
			uint32_t gma_curve_2_11 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_12 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_6 16'h0104 */
	union {
		uint32_t gamma_curve_2_6; // word name
		struct {
			uint32_t gma_curve_2_13 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_14 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_7 16'h0108 */
	union {
		uint32_t gamma_curve_2_7; // word name
		struct {
			uint32_t gma_curve_2_15 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_16 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_8 16'h010C */
	union {
		uint32_t gamma_curve_2_8; // word name
		struct {
			uint32_t gma_curve_2_17 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_18 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_9 16'h0110 */
	union {
		uint32_t gamma_curve_2_9; // word name
		struct {
			uint32_t gma_curve_2_19 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_20 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_10 16'h0114 */
	union {
		uint32_t gamma_curve_2_10; // word name
		struct {
			uint32_t gma_curve_2_21 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_22 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_11 16'h0118 */
	union {
		uint32_t gamma_curve_2_11; // word name
		struct {
			uint32_t gma_curve_2_23 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_24 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_12 16'h011C */
	union {
		uint32_t gamma_curve_2_12; // word name
		struct {
			uint32_t gma_curve_2_25 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_26 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_13 16'h0120 */
	union {
		uint32_t gamma_curve_2_13; // word name
		struct {
			uint32_t gma_curve_2_27 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_28 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_14 16'h0124 */
	union {
		uint32_t gamma_curve_2_14; // word name
		struct {
			uint32_t gma_curve_2_29 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_30 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_15 16'h0128 */
	union {
		uint32_t gamma_curve_2_15; // word name
		struct {
			uint32_t gma_curve_2_31 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_32 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_16 16'h012C */
	union {
		uint32_t gamma_curve_2_16; // word name
		struct {
			uint32_t gma_curve_2_33 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_34 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_17 16'h0130 */
	union {
		uint32_t gamma_curve_2_17; // word name
		struct {
			uint32_t gma_curve_2_35 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_36 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_18 16'h0134 */
	union {
		uint32_t gamma_curve_2_18; // word name
		struct {
			uint32_t gma_curve_2_37 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_38 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_19 16'h0138 */
	union {
		uint32_t gamma_curve_2_19; // word name
		struct {
			uint32_t gma_curve_2_39 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_40 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_20 16'h013C */
	union {
		uint32_t gamma_curve_2_20; // word name
		struct {
			uint32_t gma_curve_2_41 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_42 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_21 16'h0140 */
	union {
		uint32_t gamma_curve_2_21; // word name
		struct {
			uint32_t gma_curve_2_43 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_44 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_22 16'h0144 */
	union {
		uint32_t gamma_curve_2_22; // word name
		struct {
			uint32_t gma_curve_2_45 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_46 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_23 16'h0148 */
	union {
		uint32_t gamma_curve_2_23; // word name
		struct {
			uint32_t gma_curve_2_47 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_48 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_24 16'h014C */
	union {
		uint32_t gamma_curve_2_24; // word name
		struct {
			uint32_t gma_curve_2_49 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_50 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_25 16'h0150 */
	union {
		uint32_t gamma_curve_2_25; // word name
		struct {
			uint32_t gma_curve_2_51 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_52 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_26 16'h0154 */
	union {
		uint32_t gamma_curve_2_26; // word name
		struct {
			uint32_t gma_curve_2_53 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_54 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_27 16'h0158 */
	union {
		uint32_t gamma_curve_2_27; // word name
		struct {
			uint32_t gma_curve_2_55 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_56 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* GAMMA_CURVE_2_28 16'h015C */
	union {
		uint32_t gamma_curve_2_28; // word name
		struct {
			uint32_t gma_curve_2_57 : 14;
			uint32_t : 2; // padding bits
			uint32_t gma_curve_2_58 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h0160 */
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
} CsrBankDgma;

#endif