/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DCC_H_
#define CSR_BANK_DCC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dcc  ***/
typedef struct csr_bank_dcc {
	/* WORE_FRAME_START 12'h000 */
	union {
		uint32_t wore_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 12'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 12'h008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 12'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFA_FORMAT 12'h010 */
	union {
		uint32_t cfa_format; // word name
		struct {
			uint32_t cfa_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORE_CFA_PHASE_0 12'h014 */
	union {
		uint32_t wore_cfa_phase_0; // word name
		struct {
			uint32_t cfa_phase_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_1 12'h018 */
	union {
		uint32_t word_cfa_phase_1; // word name
		struct {
			uint32_t cfa_phase_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_2 12'h01C */
	union {
		uint32_t word_cfa_phase_2; // word name
		struct {
			uint32_t cfa_phase_8 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_9 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_3 12'h020 */
	union {
		uint32_t word_cfa_phase_3; // word name
		struct {
			uint32_t cfa_phase_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* RESOLUTION 12'h024 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORE_MODE 12'h028 */
	union {
		uint32_t wore_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_0 12'h02C */
	union {
		uint32_t gain_0; // word name
		struct {
			uint32_t gain_g0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_1 12'h030 */
	union {
		uint32_t gain_1; // word name
		struct {
			uint32_t gain_r : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_2 12'h034 */
	union {
		uint32_t gain_2; // word name
		struct {
			uint32_t gain_b : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_3 12'h038 */
	union {
		uint32_t gain_3; // word name
		struct {
			uint32_t gain_g1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_4 12'h03C */
	union {
		uint32_t gain_4; // word name
		struct {
			uint32_t gain_s : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_0 12'h040 */
	union {
		uint32_t offset_0; // word name
		struct {
			uint32_t offset_g0_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_1 12'h044 */
	union {
		uint32_t offset_1; // word name
		struct {
			uint32_t offset_r_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_2 12'h048 */
	union {
		uint32_t offset_2; // word name
		struct {
			uint32_t offset_b_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_3 12'h04C */
	union {
		uint32_t offset_3; // word name
		struct {
			uint32_t offset_g1_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_4 12'h050 */
	union {
		uint32_t offset_4; // word name
		struct {
			uint32_t offset_s_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_G0_Y_0 12'h054 */
	union {
		uint32_t curve_g0_y_0; // word name
		struct {
			uint32_t mapping_curve_g0_y_0 : 16;
			uint32_t mapping_curve_g0_y_1 : 16;
		};
	};
	/* CURVE_G0_Y_1 12'h058 */
	union {
		uint32_t curve_g0_y_1; // word name
		struct {
			uint32_t mapping_curve_g0_y_2 : 16;
			uint32_t mapping_curve_g0_y_3 : 16;
		};
	};
	/* CURVE_G0_Y_2 12'h05C */
	union {
		uint32_t curve_g0_y_2; // word name
		struct {
			uint32_t mapping_curve_g0_y_4 : 16;
			uint32_t mapping_curve_g0_y_5 : 16;
		};
	};
	/* CURVE_G0_Y_3 12'h060 */
	union {
		uint32_t curve_g0_y_3; // word name
		struct {
			uint32_t mapping_curve_g0_y_6 : 16;
			uint32_t mapping_curve_g0_y_7 : 16;
		};
	};
	/* CURVE_G0_Y_4 12'h064 */
	union {
		uint32_t curve_g0_y_4; // word name
		struct {
			uint32_t mapping_curve_g0_y_8 : 16;
			uint32_t mapping_curve_g0_y_9 : 16;
		};
	};
	/* CURVE_G0_Y_5 12'h068 */
	union {
		uint32_t curve_g0_y_5; // word name
		struct {
			uint32_t mapping_curve_g0_y_10 : 16;
			uint32_t mapping_curve_g0_y_11 : 16;
		};
	};
	/* CURVE_G0_Y_6 12'h06C */
	union {
		uint32_t curve_g0_y_6; // word name
		struct {
			uint32_t mapping_curve_g0_y_12 : 16;
			uint32_t mapping_curve_g0_y_13 : 16;
		};
	};
	/* CURVE_G0_Y_7 12'h070 */
	union {
		uint32_t curve_g0_y_7; // word name
		struct {
			uint32_t mapping_curve_g0_y_14 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_R_Y_0 12'h074 */
	union {
		uint32_t curve_r_y_0; // word name
		struct {
			uint32_t mapping_curve_r_y_0 : 16;
			uint32_t mapping_curve_r_y_1 : 16;
		};
	};
	/* CURVE_R_Y_1 12'h078 */
	union {
		uint32_t curve_r_y_1; // word name
		struct {
			uint32_t mapping_curve_r_y_2 : 16;
			uint32_t mapping_curve_r_y_3 : 16;
		};
	};
	/* CURVE_R_Y_2 12'h07C */
	union {
		uint32_t curve_r_y_2; // word name
		struct {
			uint32_t mapping_curve_r_y_4 : 16;
			uint32_t mapping_curve_r_y_5 : 16;
		};
	};
	/* CURVE_R_Y_3 12'h080 */
	union {
		uint32_t curve_r_y_3; // word name
		struct {
			uint32_t mapping_curve_r_y_6 : 16;
			uint32_t mapping_curve_r_y_7 : 16;
		};
	};
	/* CURVE_R_Y_4 12'h084 */
	union {
		uint32_t curve_r_y_4; // word name
		struct {
			uint32_t mapping_curve_r_y_8 : 16;
			uint32_t mapping_curve_r_y_9 : 16;
		};
	};
	/* CURVE_R_Y_5 12'h088 */
	union {
		uint32_t curve_r_y_5; // word name
		struct {
			uint32_t mapping_curve_r_y_10 : 16;
			uint32_t mapping_curve_r_y_11 : 16;
		};
	};
	/* CURVE_R_Y_6 12'h08C */
	union {
		uint32_t curve_r_y_6; // word name
		struct {
			uint32_t mapping_curve_r_y_12 : 16;
			uint32_t mapping_curve_r_y_13 : 16;
		};
	};
	/* CURVE_R_Y_7 12'h090 */
	union {
		uint32_t curve_r_y_7; // word name
		struct {
			uint32_t mapping_curve_r_y_14 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_B_Y_0 12'h094 */
	union {
		uint32_t curve_b_y_0; // word name
		struct {
			uint32_t mapping_curve_b_y_0 : 16;
			uint32_t mapping_curve_b_y_1 : 16;
		};
	};
	/* CURVE_B_Y_1 12'h098 */
	union {
		uint32_t curve_b_y_1; // word name
		struct {
			uint32_t mapping_curve_b_y_2 : 16;
			uint32_t mapping_curve_b_y_3 : 16;
		};
	};
	/* CURVE_B_Y_2 12'h09C */
	union {
		uint32_t curve_b_y_2; // word name
		struct {
			uint32_t mapping_curve_b_y_4 : 16;
			uint32_t mapping_curve_b_y_5 : 16;
		};
	};
	/* CURVE_B_Y_3 12'h0A0 */
	union {
		uint32_t curve_b_y_3; // word name
		struct {
			uint32_t mapping_curve_b_y_6 : 16;
			uint32_t mapping_curve_b_y_7 : 16;
		};
	};
	/* CURVE_B_Y_4 12'h0A4 */
	union {
		uint32_t curve_b_y_4; // word name
		struct {
			uint32_t mapping_curve_b_y_8 : 16;
			uint32_t mapping_curve_b_y_9 : 16;
		};
	};
	/* CURVE_B_Y_5 12'h0A8 */
	union {
		uint32_t curve_b_y_5; // word name
		struct {
			uint32_t mapping_curve_b_y_10 : 16;
			uint32_t mapping_curve_b_y_11 : 16;
		};
	};
	/* CURVE_B_Y_6 12'h0AC */
	union {
		uint32_t curve_b_y_6; // word name
		struct {
			uint32_t mapping_curve_b_y_12 : 16;
			uint32_t mapping_curve_b_y_13 : 16;
		};
	};
	/* CURVE_B_Y_7 12'h0B0 */
	union {
		uint32_t curve_b_y_7; // word name
		struct {
			uint32_t mapping_curve_b_y_14 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_G1_Y_0 12'h0B4 */
	union {
		uint32_t curve_g1_y_0; // word name
		struct {
			uint32_t mapping_curve_g1_y_0 : 16;
			uint32_t mapping_curve_g1_y_1 : 16;
		};
	};
	/* CURVE_G1_Y_1 12'h0B8 */
	union {
		uint32_t curve_g1_y_1; // word name
		struct {
			uint32_t mapping_curve_g1_y_2 : 16;
			uint32_t mapping_curve_g1_y_3 : 16;
		};
	};
	/* CURVE_G1_Y_2 12'h0BC */
	union {
		uint32_t curve_g1_y_2; // word name
		struct {
			uint32_t mapping_curve_g1_y_4 : 16;
			uint32_t mapping_curve_g1_y_5 : 16;
		};
	};
	/* CURVE_G1_Y_3 12'h0C0 */
	union {
		uint32_t curve_g1_y_3; // word name
		struct {
			uint32_t mapping_curve_g1_y_6 : 16;
			uint32_t mapping_curve_g1_y_7 : 16;
		};
	};
	/* CURVE_G1_Y_4 12'h0C4 */
	union {
		uint32_t curve_g1_y_4; // word name
		struct {
			uint32_t mapping_curve_g1_y_8 : 16;
			uint32_t mapping_curve_g1_y_9 : 16;
		};
	};
	/* CURVE_G1_Y_5 12'h0C8 */
	union {
		uint32_t curve_g1_y_5; // word name
		struct {
			uint32_t mapping_curve_g1_y_10 : 16;
			uint32_t mapping_curve_g1_y_11 : 16;
		};
	};
	/* CURVE_G1_Y_6 12'h0CC */
	union {
		uint32_t curve_g1_y_6; // word name
		struct {
			uint32_t mapping_curve_g1_y_12 : 16;
			uint32_t mapping_curve_g1_y_13 : 16;
		};
	};
	/* CURVE_G1_Y_7 12'h0D0 */
	union {
		uint32_t curve_g1_y_7; // word name
		struct {
			uint32_t mapping_curve_g1_y_14 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_S_Y_0 12'h0D4 */
	union {
		uint32_t curve_s_y_0; // word name
		struct {
			uint32_t mapping_curve_s_y_0 : 16;
			uint32_t mapping_curve_s_y_1 : 16;
		};
	};
	/* CURVE_S_Y_1 12'h0D8 */
	union {
		uint32_t curve_s_y_1; // word name
		struct {
			uint32_t mapping_curve_s_y_2 : 16;
			uint32_t mapping_curve_s_y_3 : 16;
		};
	};
	/* CURVE_S_Y_2 12'h0DC */
	union {
		uint32_t curve_s_y_2; // word name
		struct {
			uint32_t mapping_curve_s_y_4 : 16;
			uint32_t mapping_curve_s_y_5 : 16;
		};
	};
	/* CURVE_S_Y_3 12'h0E0 */
	union {
		uint32_t curve_s_y_3; // word name
		struct {
			uint32_t mapping_curve_s_y_6 : 16;
			uint32_t mapping_curve_s_y_7 : 16;
		};
	};
	/* CURVE_S_Y_4 12'h0E4 */
	union {
		uint32_t curve_s_y_4; // word name
		struct {
			uint32_t mapping_curve_s_y_8 : 16;
			uint32_t mapping_curve_s_y_9 : 16;
		};
	};
	/* CURVE_S_Y_5 12'h0E8 */
	union {
		uint32_t curve_s_y_5; // word name
		struct {
			uint32_t mapping_curve_s_y_10 : 16;
			uint32_t mapping_curve_s_y_11 : 16;
		};
	};
	/* CURVE_S_Y_6 12'h0EC */
	union {
		uint32_t curve_s_y_6; // word name
		struct {
			uint32_t mapping_curve_s_y_12 : 16;
			uint32_t mapping_curve_s_y_13 : 16;
		};
	};
	/* CURVE_S_Y_7 12'h0F0 */
	union {
		uint32_t curve_s_y_7; // word name
		struct {
			uint32_t mapping_curve_s_y_14 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORE_DEBUG_MON_SEL 12'h0F4 */
	union {
		uint32_t wore_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDcc;

#endif