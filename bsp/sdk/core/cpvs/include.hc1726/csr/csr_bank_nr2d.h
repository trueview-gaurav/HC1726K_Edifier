/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_NR2D_H_
#define CSR_BANK_NR2D_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from nr2d  ***/
typedef struct csr_bank_nr2d {
	/* WORD_FRAME_START 9'h000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 9'h004 */
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
	/* STATUS 9'h008 */
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
	/* IRQ_MASK 9'h00C */
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
	/* WORD_MODE 9'h010 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t y_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t c_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t ink_num : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* RESOLUTION 9'h014 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* DEMO_SET 9'h018 */
	union {
		uint32_t demo_set; // word name
		struct {
			uint32_t demo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEMO_X 9'h01C */
	union {
		uint32_t demo_x; // word name
		struct {
			uint32_t demo_x_min : 16;
			uint32_t demo_x_max : 16;
		};
	};
	/* DEMO_Y 9'h020 */
	union {
		uint32_t demo_y; // word name
		struct {
			uint32_t demo_y_min : 16;
			uint32_t demo_y_max : 16;
		};
	};
	/* DEBUG_MON 9'h024 */
	union {
		uint32_t debug_mon; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_00 9'h028 */
	union {
		uint32_t nr2d_00; // word name
		struct {
			uint32_t chroma_control_gain_x_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t chroma_control_gain_x_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* NR2D_01 9'h02C */
	union {
		uint32_t nr2d_01; // word name
		struct {
			uint32_t chroma_control_gain_y_0 : 9;
			uint32_t : 7; // padding bits
			uint32_t chroma_control_gain_y_1 : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* NR2D_02 9'h030 */
	union {
		uint32_t nr2d_02; // word name
		struct {
			uint32_t chroma_control_gain_m : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_03 9'h034 */
	union {
		uint32_t nr2d_03; // word name
		struct {
			uint32_t luma_lut_x_0 : 8;
			uint32_t luma_lut_x_1 : 8;
			uint32_t luma_lut_x_2 : 8;
			uint32_t luma_lut_x_3 : 8;
		};
	};
	/* NR2D_04 9'h038 */
	union {
		uint32_t nr2d_04; // word name
		struct {
			uint32_t luma_lut_x_4 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_05 9'h03C */
	union {
		uint32_t nr2d_05; // word name
		struct {
			uint32_t luma_lut_y_ini : 8;
			uint32_t luma_lut_y_0 : 8;
			uint32_t luma_lut_y_1 : 8;
			uint32_t luma_lut_y_2 : 8;
		};
	};
	/* NR2D_06 9'h040 */
	union {
		uint32_t nr2d_06; // word name
		struct {
			uint32_t luma_lut_y_3 : 8;
			uint32_t luma_lut_y_4 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_07 9'h044 */
	union {
		uint32_t nr2d_07; // word name
		struct {
			uint32_t luma_lut_m_0_2s : 10;
			uint32_t luma_lut_m_1_2s : 10;
			uint32_t luma_lut_m_2_2s : 10;
			uint32_t : 2; // padding bits
		};
	};
	/* NR2D_08 9'h048 */
	union {
		uint32_t nr2d_08; // word name
		struct {
			uint32_t luma_lut_m_3_2s : 10;
			uint32_t luma_lut_m_4_2s : 10;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_09 9'h04C */
	union {
		uint32_t nr2d_09; // word name
		struct {
			uint32_t edge_confidence_x_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t edge_confidence_x_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* NR2D_10 9'h050 */
	union {
		uint32_t nr2d_10; // word name
		struct {
			uint32_t edge_confidence_y_0 : 8;
			uint32_t edge_confidence_y_1 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_11 9'h054 */
	union {
		uint32_t nr2d_11; // word name
		struct {
			uint32_t edge_confidence_m : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_12 9'h058 */
	union {
		uint32_t nr2d_12; // word name
		struct {
			uint32_t luma_nlm_weight_th_2s : 10;
			uint32_t : 6; // padding bits
			uint32_t chroma_nlm_weight_th_2s : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* NR2D_13 9'h05C */
	union {
		uint32_t nr2d_13; // word name
		struct {
			uint32_t nlm_lut_x_0 : 8;
			uint32_t nlm_lut_x_1 : 8;
			uint32_t nlm_lut_x_2 : 8;
			uint32_t nlm_lut_x_3 : 8;
		};
	};
	/* NR2D_14 9'h060 */
	union {
		uint32_t nr2d_14; // word name
		struct {
			uint32_t nlm_lut_x_4 : 8;
			uint32_t nlm_lut_x_5 : 8;
			uint32_t nlm_lut_x_6 : 8;
			uint32_t nlm_lut_x_7 : 8;
		};
	};
	/* NR2D_15 9'h064 */
	union {
		uint32_t nr2d_15; // word name
		struct {
			uint32_t nlm_lut_x_8 : 8;
			uint32_t nlm_lut_x_9 : 8;
			uint32_t nlm_lut_x_10 : 8;
			uint32_t nlm_lut_x_11 : 8;
		};
	};
	/* NR2D_16 9'h068 */
	union {
		uint32_t nr2d_16; // word name
		struct {
			uint32_t nlm_lut_x_12 : 8;
			uint32_t nlm_lut_x_13 : 8;
			uint32_t nlm_lut_x_14 : 8;
			uint32_t nlm_lut_x_15 : 8;
		};
	};
	/* NR2D_17 9'h06C */
	union {
		uint32_t nr2d_17; // word name
		struct {
			uint32_t nlm_lut_x_16 : 8;
			uint32_t nlm_lut_x_17 : 8;
			uint32_t nlm_lut_x_18 : 8;
			uint32_t nlm_lut_x_19 : 8;
		};
	};
	/* NR2D_18 9'h070 */
	union {
		uint32_t nr2d_18; // word name
		struct {
			uint32_t nlm_lut_x_20 : 8;
			uint32_t nlm_lut_x_21 : 8;
			uint32_t nlm_lut_x_22 : 8;
			uint32_t nlm_lut_x_23 : 8;
		};
	};
	/* NR2D_19 9'h074 */
	union {
		uint32_t nr2d_19; // word name
		struct {
			uint32_t nlm_lut_x_24 : 8;
			uint32_t nlm_lut_x_25 : 8;
			uint32_t nlm_lut_x_26 : 8;
			uint32_t nlm_lut_x_27 : 8;
		};
	};
	/* NR2D_20 9'h078 */
	union {
		uint32_t nr2d_20; // word name
		struct {
			uint32_t nlm_lut_x_28 : 8;
			uint32_t nlm_lut_x_29 : 8;
			uint32_t nlm_lut_x_30 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_21 9'h07C */
	union {
		uint32_t nr2d_21; // word name
		struct {
			uint32_t nlm_lut_y_0 : 8;
			uint32_t nlm_lut_y_1 : 8;
			uint32_t nlm_lut_y_2 : 8;
			uint32_t nlm_lut_y_3 : 8;
		};
	};
	/* NR2D_22 9'h080 */
	union {
		uint32_t nr2d_22; // word name
		struct {
			uint32_t nlm_lut_y_4 : 8;
			uint32_t nlm_lut_y_5 : 8;
			uint32_t nlm_lut_y_6 : 8;
			uint32_t nlm_lut_y_7 : 8;
		};
	};
	/* NR2D_23 9'h084 */
	union {
		uint32_t nr2d_23; // word name
		struct {
			uint32_t nlm_lut_y_8 : 8;
			uint32_t nlm_lut_y_9 : 8;
			uint32_t nlm_lut_y_10 : 8;
			uint32_t nlm_lut_y_11 : 8;
		};
	};
	/* NR2D_24 9'h088 */
	union {
		uint32_t nr2d_24; // word name
		struct {
			uint32_t nlm_lut_y_12 : 8;
			uint32_t nlm_lut_y_13 : 8;
			uint32_t nlm_lut_y_14 : 8;
			uint32_t nlm_lut_y_15 : 8;
		};
	};
	/* NR2D_25 9'h08C */
	union {
		uint32_t nr2d_25; // word name
		struct {
			uint32_t nlm_lut_y_16 : 8;
			uint32_t nlm_lut_y_17 : 8;
			uint32_t nlm_lut_y_18 : 8;
			uint32_t nlm_lut_y_19 : 8;
		};
	};
	/* NR2D_26 9'h090 */
	union {
		uint32_t nr2d_26; // word name
		struct {
			uint32_t nlm_lut_y_20 : 8;
			uint32_t nlm_lut_y_21 : 8;
			uint32_t nlm_lut_y_22 : 8;
			uint32_t nlm_lut_y_23 : 8;
		};
	};
	/* NR2D_27 9'h094 */
	union {
		uint32_t nr2d_27; // word name
		struct {
			uint32_t nlm_lut_y_24 : 8;
			uint32_t nlm_lut_y_25 : 8;
			uint32_t nlm_lut_y_26 : 8;
			uint32_t nlm_lut_y_27 : 8;
		};
	};
	/* NR2D_28 9'h098 */
	union {
		uint32_t nr2d_28; // word name
		struct {
			uint32_t nlm_lut_y_28 : 8;
			uint32_t nlm_lut_y_29 : 8;
			uint32_t nlm_lut_y_30 : 8;
			uint32_t nlm_lut_y_31 : 8;
		};
	};
	/* NR2D_29 9'h09C */
	union {
		uint32_t nr2d_29; // word name
		struct {
			uint32_t luma_nlm_mean_candidate_th : 8;
			uint32_t luma_nlm_count_fallback_ratio : 13;
			uint32_t : 3; // padding bits
			uint32_t luma_nlm_count_th : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* NR2D_30 9'h0A0 */
	union {
		uint32_t nr2d_30; // word name
		struct {
			uint32_t luma_nlm_fallback_min : 7;
			uint32_t : 1; // padding bits
			uint32_t luma_nlm_fallback_max : 7;
			uint32_t : 1; // padding bits
			uint32_t luma_nlm_noise_level_control : 8;
			uint32_t luma_nlm_global_fallback_alpha : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* NR2D_31 9'h0A4 */
	union {
		uint32_t nr2d_31; // word name
		struct {
			uint32_t chroma_nlm_mean_candidate_th : 8;
			uint32_t chroma_nlm_count_fallback_ratio : 13;
			uint32_t : 3; // padding bits
			uint32_t chroma_nlm_count_th : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* NR2D_32 9'h0A8 */
	union {
		uint32_t nr2d_32; // word name
		struct {
			uint32_t chroma_nlm_fallback_min : 7;
			uint32_t : 1; // padding bits
			uint32_t chroma_nlm_fallback_max : 7;
			uint32_t : 1; // padding bits
			uint32_t chroma_nlm_noise_level_control : 8;
			uint32_t chroma_nlm_global_fallback_alpha : 7;
			uint32_t : 1; // padding bits
		};
	};
	/* ATPG 9'h0AC */
	union {
		uint32_t atpg; // word name
		struct {
			uint32_t atpg_ctrl : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED 9'h0B0 */
	union {
		uint32_t word_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankNr2d;

#endif