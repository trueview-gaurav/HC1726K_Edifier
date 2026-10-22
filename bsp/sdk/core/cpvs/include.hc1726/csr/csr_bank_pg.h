/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PG_H_
#define CSR_BANK_PG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pg  ***/
typedef struct csr_bank_pg {
	/* CTRL 10'h000 */
	union {
		uint32_t ctrl; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 10'h004 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* MODE_SET 10'h008 */
	union {
		uint32_t mode_set; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t pat_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t color_space : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFA_SET 10'h00C */
	union {
		uint32_t cfa_set; // word name
		struct {
			uint32_t cfa_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t bayer_ini_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CFA_PHASE_0 10'h010 */
	union {
		uint32_t word_cfa_phase_0; // word name
		struct {
			uint32_t cfa_phase0 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase1 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase2 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_1 10'h014 */
	union {
		uint32_t word_cfa_phase_1; // word name
		struct {
			uint32_t cfa_phase4 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase5 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase6 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_2 10'h018 */
	union {
		uint32_t word_cfa_phase_2; // word name
		struct {
			uint32_t cfa_phase8 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase9 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase10 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_3 10'h01C */
	union {
		uint32_t word_cfa_phase_3; // word name
		struct {
			uint32_t cfa_phase12 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase13 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase14 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* ROI_X 10'h020 */
	union {
		uint32_t roi_x; // word name
		struct {
			uint32_t roi_sx : 16;
			uint32_t roi_ex : 16;
		};
	};
	/* ROI_Y 10'h024 */
	union {
		uint32_t roi_y; // word name
		struct {
			uint32_t roi_sy : 16;
			uint32_t roi_ey : 16;
		};
	};
	/* WORD_X_CNT_INI 10'h028 */
	union {
		uint32_t word_x_cnt_ini; // word name
		struct {
			uint32_t x_cnt_ini : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RP_INI_0 10'h02C */
	union {
		uint32_t word_rp_ini_0; // word name
		struct {
			uint32_t rp_initial_0 : 16;
			uint32_t rp_initial_1 : 16;
		};
	};
	/* RP_INI_1 10'h030 */
	union {
		uint32_t rp_ini_1; // word name
		struct {
			uint32_t rp_initial_2 : 16;
			uint32_t rp_initial_3 : 16;
		};
	};
	/* RP_DELTA_H_0 10'h034 */
	union {
		uint32_t rp_delta_h_0; // word name
		struct {
			uint32_t rp_delta_h_0_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_H_1 10'h038 */
	union {
		uint32_t rp_delta_h_1; // word name
		struct {
			uint32_t rp_delta_h_1_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_H_2 10'h03C */
	union {
		uint32_t rp_delta_h_2; // word name
		struct {
			uint32_t rp_delta_h_2_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_H_3 10'h040 */
	union {
		uint32_t rp_delta_h_3; // word name
		struct {
			uint32_t rp_delta_h_3_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_V_0 10'h044 */
	union {
		uint32_t rp_delta_v_0; // word name
		struct {
			uint32_t rp_delta_v_0_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_V_1 10'h048 */
	union {
		uint32_t rp_delta_v_1; // word name
		struct {
			uint32_t rp_delta_v_1_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_V_2 10'h04C */
	union {
		uint32_t rp_delta_v_2; // word name
		struct {
			uint32_t rp_delta_v_2_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_DELTA_V_3 10'h050 */
	union {
		uint32_t rp_delta_v_3; // word name
		struct {
			uint32_t rp_delta_v_3_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RP_OF_ENABLE 10'h054 */
	union {
		uint32_t rp_of_enable; // word name
		struct {
			uint32_t rp_overflow_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CB_BAR_DELTA 10'h058 */
	union {
		uint32_t word_cb_bar_delta; // word name
		struct {
			uint32_t cb_bar_delta : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* COLOR_TABLE_00 10'h05C */
	union {
		uint32_t color_table_00; // word name
		struct {
			uint32_t bar_0_ch0 : 16;
			uint32_t bar_1_ch0 : 16;
		};
	};
	/* COLOR_TABLE_01 10'h060 */
	union {
		uint32_t color_table_01; // word name
		struct {
			uint32_t bar_2_ch0 : 16;
			uint32_t bar_3_ch0 : 16;
		};
	};
	/* COLOR_TABLE_02 10'h064 */
	union {
		uint32_t color_table_02; // word name
		struct {
			uint32_t bar_4_ch0 : 16;
			uint32_t bar_5_ch0 : 16;
		};
	};
	/* COLOR_TABLE_03 10'h068 */
	union {
		uint32_t color_table_03; // word name
		struct {
			uint32_t bar_6_ch0 : 16;
			uint32_t bar_7_ch0 : 16;
		};
	};
	/* COLOR_TABLE_04 10'h06C */
	union {
		uint32_t color_table_04; // word name
		struct {
			uint32_t bar_8_ch0 : 16;
			uint32_t bar_0_ch1 : 16;
		};
	};
	/* COLOR_TABLE_05 10'h070 */
	union {
		uint32_t color_table_05; // word name
		struct {
			uint32_t bar_1_ch1 : 16;
			uint32_t bar_2_ch1 : 16;
		};
	};
	/* COLOR_TABLE_06 10'h074 */
	union {
		uint32_t color_table_06; // word name
		struct {
			uint32_t bar_3_ch1 : 16;
			uint32_t bar_4_ch1 : 16;
		};
	};
	/* COLOR_TABLE_07 10'h078 */
	union {
		uint32_t color_table_07; // word name
		struct {
			uint32_t bar_5_ch1 : 16;
			uint32_t bar_6_ch1 : 16;
		};
	};
	/* COLOR_TABLE_08 10'h07C */
	union {
		uint32_t color_table_08; // word name
		struct {
			uint32_t bar_7_ch1 : 16;
			uint32_t bar_8_ch1 : 16;
		};
	};
	/* COLOR_TABLE_09 10'h080 */
	union {
		uint32_t color_table_09; // word name
		struct {
			uint32_t bar_0_ch2 : 16;
			uint32_t bar_1_ch2 : 16;
		};
	};
	/* COLOR_TABLE_10 10'h084 */
	union {
		uint32_t color_table_10; // word name
		struct {
			uint32_t bar_2_ch2 : 16;
			uint32_t bar_3_ch2 : 16;
		};
	};
	/* COLOR_TABLE_11 10'h088 */
	union {
		uint32_t color_table_11; // word name
		struct {
			uint32_t bar_4_ch2 : 16;
			uint32_t bar_5_ch2 : 16;
		};
	};
	/* COLOR_TABLE_12 10'h08C */
	union {
		uint32_t color_table_12; // word name
		struct {
			uint32_t bar_6_ch2 : 16;
			uint32_t bar_7_ch2 : 16;
		};
	};
	/* COLOR_TABLE_13 10'h090 */
	union {
		uint32_t color_table_13; // word name
		struct {
			uint32_t bar_8_ch2 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LINE_INT_0 10'h094 */
	union {
		uint32_t line_int_0; // word name
		struct {
			uint32_t line_intensity_00 : 16;
			uint32_t line_intensity_01 : 16;
		};
	};
	/* LINE_INT_1 10'h098 */
	union {
		uint32_t line_int_1; // word name
		struct {
			uint32_t line_intensity_10 : 16;
			uint32_t line_intensity_11 : 16;
		};
	};
	/* BLOCK_INT_0 10'h09C */
	union {
		uint32_t block_int_0; // word name
		struct {
			uint32_t block_intensity_00 : 16;
			uint32_t block_intensity_01 : 16;
		};
	};
	/* BLOCK_INT_1 10'h0A0 */
	union {
		uint32_t block_int_1; // word name
		struct {
			uint32_t block_intensity_10 : 16;
			uint32_t block_intensity_11 : 16;
		};
	};
	/* WORD_LINE_WIDTH 10'h0A4 */
	union {
		uint32_t word_line_width; // word name
		struct {
			uint32_t line_width : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLOCK_BW 10'h0A8 */
	union {
		uint32_t block_bw; // word name
		struct {
			uint32_t block_side_length_bw : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LINE_MOV 10'h0AC */
	union {
		uint32_t line_mov; // word name
		struct {
			uint32_t line_moving : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 10'h0B0 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPg;

#endif