/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DARB_H_
#define CSR_BANK_DARB_H_

#include <stdint.h>

/***  C struct generated from darb  ***/
typedef struct csr_bank_darb {
	/* CHKSUM_CLEAR 10'h000 */
	union {
		uint32_t chksum_clear; // word name
		struct {
			uint32_t checksum_0_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_1_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_2_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_3_clear : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQ_CLEAR_A 10'h004 */
	union {
		uint32_t irq_clear_a; // word name
		struct {
			uint32_t irq_clear_w_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_r_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_timeout_w_addr : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_timeout_w_data : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQ_CLEAR_B 10'h008 */
	union {
		uint32_t irq_clear_b; // word name
		struct {
			uint32_t irq_clear_timeout_w_resp : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_timeout_r_addr : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_timeout_r_data : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS_A 10'h00C */
	union {
		uint32_t status_a; // word name
		struct {
			uint32_t status_w_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t status_r_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t status_timeout_w_addr : 1;
			uint32_t : 7; // padding bits
			uint32_t status_timeout_w_data : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATUS_B 10'h010 */
	union {
		uint32_t status_b; // word name
		struct {
			uint32_t status_timeout_w_resp : 1;
			uint32_t : 7; // padding bits
			uint32_t status_timeout_r_addr : 1;
			uint32_t : 7; // padding bits
			uint32_t status_timeout_r_data : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK_A 10'h014 */
	union {
		uint32_t irq_mask_a; // word name
		struct {
			uint32_t irq_mask_w_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_r_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_timeout_w_addr : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_timeout_w_data : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQ_MASK_B 10'h018 */
	union {
		uint32_t irq_mask_b; // word name
		struct {
			uint32_t irq_mask_timeout_w_resp : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_timeout_r_addr : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_timeout_r_data : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMAP_PORT_EN_0 10'h01C */
	union {
		uint32_t remap_port_en_0; // word name
		struct {
			uint32_t remap_w_i_en : 32;
		};
	};
	/* REMAP_PORT_EN_1 10'h020 */
	union {
		uint32_t remap_port_en_1; // word name
		struct {
			uint32_t remap_r_i_en : 32;
		};
	};
	/* REMAP_PORT_EN_2 10'h024 */
	union {
		uint32_t remap_port_en_2; // word name
		struct {
			uint32_t remap_w_o_en : 32;
		};
	};
	/* REMAP_PORT_EN_3 10'h028 */
	union {
		uint32_t remap_port_en_3; // word name
		struct {
			uint32_t remap_r_o_en : 32;
		};
	};
	/* GROUP_0 10'h02C [Unused] */
	uint32_t empty_word_group_0;
	/* GROUP_1 10'h030 [Unused] */
	uint32_t empty_word_group_1;
	/* GROUP_2 10'h034 [Unused] */
	uint32_t empty_word_group_2;
	/* GROUP_3 10'h038 [Unused] */
	uint32_t empty_word_group_3;
	/* PRIORITY_W_0 10'h03C */
	union {
		uint32_t priority_w_0; // word name
		struct {
			uint32_t priority_w_00 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_01 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_02 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_03 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_1 10'h040 */
	union {
		uint32_t priority_w_1; // word name
		struct {
			uint32_t priority_w_04 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_05 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_06 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_07 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_2 10'h044 */
	union {
		uint32_t priority_w_2; // word name
		struct {
			uint32_t priority_w_08 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_09 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_10 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_11 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_3 10'h048 */
	union {
		uint32_t priority_w_3; // word name
		struct {
			uint32_t priority_w_12 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_13 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_14 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_15 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_4 10'h04C */
	union {
		uint32_t priority_w_4; // word name
		struct {
			uint32_t priority_w_16 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_17 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_18 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_19 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_5 10'h050 */
	union {
		uint32_t priority_w_5; // word name
		struct {
			uint32_t priority_w_20 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_21 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_22 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_23 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_6 10'h054 */
	union {
		uint32_t priority_w_6; // word name
		struct {
			uint32_t priority_w_24 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_25 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_26 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_27 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_W_7 10'h058 */
	union {
		uint32_t priority_w_7; // word name
		struct {
			uint32_t priority_w_28 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_29 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_30 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_w_31 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_0 10'h05C */
	union {
		uint32_t priority_r_0; // word name
		struct {
			uint32_t priority_r_00 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_01 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_02 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_03 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_1 10'h060 */
	union {
		uint32_t priority_r_1; // word name
		struct {
			uint32_t priority_r_04 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_05 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_06 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_07 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_2 10'h064 */
	union {
		uint32_t priority_r_2; // word name
		struct {
			uint32_t priority_r_08 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_09 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_10 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_11 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_3 10'h068 */
	union {
		uint32_t priority_r_3; // word name
		struct {
			uint32_t priority_r_12 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_13 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_14 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_15 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_4 10'h06C */
	union {
		uint32_t priority_r_4; // word name
		struct {
			uint32_t priority_r_16 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_17 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_18 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_19 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_5 10'h070 */
	union {
		uint32_t priority_r_5; // word name
		struct {
			uint32_t priority_r_20 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_21 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_22 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_23 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_6 10'h074 */
	union {
		uint32_t priority_r_6; // word name
		struct {
			uint32_t priority_r_24 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_25 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_26 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_27 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PRIORITY_R_7 10'h078 */
	union {
		uint32_t priority_r_7; // word name
		struct {
			uint32_t priority_r_28 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_29 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_30 : 2;
			uint32_t : 6; // padding bits
			uint32_t priority_r_31 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* INI_SCORE_W_0 10'h07C */
	union {
		uint32_t ini_score_w_0; // word name
		struct {
			uint32_t ini_score_w_00 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_01 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_02 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_03 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_1 10'h080 */
	union {
		uint32_t ini_score_w_1; // word name
		struct {
			uint32_t ini_score_w_04 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_05 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_06 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_07 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_2 10'h084 */
	union {
		uint32_t ini_score_w_2; // word name
		struct {
			uint32_t ini_score_w_08 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_09 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_10 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_11 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_3 10'h088 */
	union {
		uint32_t ini_score_w_3; // word name
		struct {
			uint32_t ini_score_w_12 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_13 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_14 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_15 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_4 10'h08C */
	union {
		uint32_t ini_score_w_4; // word name
		struct {
			uint32_t ini_score_w_16 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_17 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_18 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_19 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_5 10'h090 */
	union {
		uint32_t ini_score_w_5; // word name
		struct {
			uint32_t ini_score_w_20 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_21 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_22 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_23 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_6 10'h094 */
	union {
		uint32_t ini_score_w_6; // word name
		struct {
			uint32_t ini_score_w_24 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_25 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_26 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_27 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_W_7 10'h098 */
	union {
		uint32_t ini_score_w_7; // word name
		struct {
			uint32_t ini_score_w_28 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_29 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_30 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_w_31 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_0 10'h09C */
	union {
		uint32_t ini_score_r_0; // word name
		struct {
			uint32_t ini_score_r_00 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_01 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_02 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_03 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_1 10'h0A0 */
	union {
		uint32_t ini_score_r_1; // word name
		struct {
			uint32_t ini_score_r_04 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_05 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_06 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_07 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_2 10'h0A4 */
	union {
		uint32_t ini_score_r_2; // word name
		struct {
			uint32_t ini_score_r_08 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_09 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_10 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_11 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_3 10'h0A8 */
	union {
		uint32_t ini_score_r_3; // word name
		struct {
			uint32_t ini_score_r_12 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_13 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_14 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_15 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_4 10'h0AC */
	union {
		uint32_t ini_score_r_4; // word name
		struct {
			uint32_t ini_score_r_16 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_17 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_18 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_19 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_5 10'h0B0 */
	union {
		uint32_t ini_score_r_5; // word name
		struct {
			uint32_t ini_score_r_20 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_21 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_22 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_23 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_6 10'h0B4 */
	union {
		uint32_t ini_score_r_6; // word name
		struct {
			uint32_t ini_score_r_24 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_25 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_26 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_27 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* INI_SCORE_R_7 10'h0B8 */
	union {
		uint32_t ini_score_r_7; // word name
		struct {
			uint32_t ini_score_r_28 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_29 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_30 : 5;
			uint32_t : 3; // padding bits
			uint32_t ini_score_r_31 : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* WAIT_CNT_W_0 10'h0BC */
	union {
		uint32_t wait_cnt_w_0; // word name
		struct {
			uint32_t wait_cnt_norm_w_00 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_01 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_02 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_03 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_1 10'h0C0 */
	union {
		uint32_t wait_cnt_w_1; // word name
		struct {
			uint32_t wait_cnt_norm_w_04 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_05 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_06 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_07 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_2 10'h0C4 */
	union {
		uint32_t wait_cnt_w_2; // word name
		struct {
			uint32_t wait_cnt_norm_w_08 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_09 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_3 10'h0C8 */
	union {
		uint32_t wait_cnt_w_3; // word name
		struct {
			uint32_t wait_cnt_norm_w_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_4 10'h0CC */
	union {
		uint32_t wait_cnt_w_4; // word name
		struct {
			uint32_t wait_cnt_norm_w_16 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_17 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_18 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_19 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_5 10'h0D0 */
	union {
		uint32_t wait_cnt_w_5; // word name
		struct {
			uint32_t wait_cnt_norm_w_20 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_21 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_22 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_23 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_6 10'h0D4 */
	union {
		uint32_t wait_cnt_w_6; // word name
		struct {
			uint32_t wait_cnt_norm_w_24 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_25 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_26 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_27 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_W_7 10'h0D8 */
	union {
		uint32_t wait_cnt_w_7; // word name
		struct {
			uint32_t wait_cnt_norm_w_28 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_29 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_30 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_w_31 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_0 10'h0DC */
	union {
		uint32_t wait_cnt_r_0; // word name
		struct {
			uint32_t wait_cnt_norm_r_00 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_01 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_02 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_03 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_1 10'h0E0 */
	union {
		uint32_t wait_cnt_r_1; // word name
		struct {
			uint32_t wait_cnt_norm_r_04 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_05 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_06 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_07 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_2 10'h0E4 */
	union {
		uint32_t wait_cnt_r_2; // word name
		struct {
			uint32_t wait_cnt_norm_r_08 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_09 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_3 10'h0E8 */
	union {
		uint32_t wait_cnt_r_3; // word name
		struct {
			uint32_t wait_cnt_norm_r_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_4 10'h0EC */
	union {
		uint32_t wait_cnt_r_4; // word name
		struct {
			uint32_t wait_cnt_norm_r_16 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_17 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_18 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_19 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_5 10'h0F0 */
	union {
		uint32_t wait_cnt_r_5; // word name
		struct {
			uint32_t wait_cnt_norm_r_20 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_21 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_22 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_23 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_6 10'h0F4 */
	union {
		uint32_t wait_cnt_r_6; // word name
		struct {
			uint32_t wait_cnt_norm_r_24 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_25 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_26 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_27 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WAIT_CNT_R_7 10'h0F8 */
	union {
		uint32_t wait_cnt_r_7; // word name
		struct {
			uint32_t wait_cnt_norm_r_28 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_29 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_30 : 3;
			uint32_t : 5; // padding bits
			uint32_t wait_cnt_norm_r_31 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* PAGE_MATCH_W_0 10'h0FC */
	union {
		uint32_t page_match_w_0; // word name
		struct {
			uint32_t page_match_score_w_00 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_01 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_02 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_03 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_1 10'h100 */
	union {
		uint32_t page_match_w_1; // word name
		struct {
			uint32_t page_match_score_w_04 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_05 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_06 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_07 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_2 10'h104 */
	union {
		uint32_t page_match_w_2; // word name
		struct {
			uint32_t page_match_score_w_08 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_09 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_10 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_11 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_3 10'h108 */
	union {
		uint32_t page_match_w_3; // word name
		struct {
			uint32_t page_match_score_w_12 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_13 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_14 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_15 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_4 10'h10C */
	union {
		uint32_t page_match_w_4; // word name
		struct {
			uint32_t page_match_score_w_16 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_17 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_18 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_19 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_5 10'h110 */
	union {
		uint32_t page_match_w_5; // word name
		struct {
			uint32_t page_match_score_w_20 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_21 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_22 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_23 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_6 10'h114 */
	union {
		uint32_t page_match_w_6; // word name
		struct {
			uint32_t page_match_score_w_24 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_25 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_26 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_27 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_W_7 10'h118 */
	union {
		uint32_t page_match_w_7; // word name
		struct {
			uint32_t page_match_score_w_28 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_29 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_30 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_w_31 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_0 10'h11C */
	union {
		uint32_t page_match_r_0; // word name
		struct {
			uint32_t page_match_score_r_00 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_01 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_02 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_03 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_1 10'h120 */
	union {
		uint32_t page_match_r_1; // word name
		struct {
			uint32_t page_match_score_r_04 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_05 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_06 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_07 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_2 10'h124 */
	union {
		uint32_t page_match_r_2; // word name
		struct {
			uint32_t page_match_score_r_08 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_09 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_10 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_11 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_3 10'h128 */
	union {
		uint32_t page_match_r_3; // word name
		struct {
			uint32_t page_match_score_r_12 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_13 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_14 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_15 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_4 10'h12C */
	union {
		uint32_t page_match_r_4; // word name
		struct {
			uint32_t page_match_score_r_16 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_17 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_18 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_19 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_5 10'h130 */
	union {
		uint32_t page_match_r_5; // word name
		struct {
			uint32_t page_match_score_r_20 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_21 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_22 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_23 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_6 10'h134 */
	union {
		uint32_t page_match_r_6; // word name
		struct {
			uint32_t page_match_score_r_24 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_25 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_26 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_27 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* PAGE_MATCH_R_7 10'h138 */
	union {
		uint32_t page_match_r_7; // word name
		struct {
			uint32_t page_match_score_r_28 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_29 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_30 : 4;
			uint32_t : 4; // padding bits
			uint32_t page_match_score_r_31 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* GENERAL_SCORE 10'h13C */
	union {
		uint32_t general_score; // word name
		struct {
			uint32_t bank_switch_score : 4;
			uint32_t : 4; // padding bits
			uint32_t keep_agent_score : 4;
			uint32_t : 4; // padding bits
			uint32_t keep_rw_score : 4;
			uint32_t : 4; // padding bits
			uint32_t debug_mon_sel : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* DRAM_TYPE 10'h140 */
	union {
		uint32_t dram_type; // word name
		struct {
			uint32_t row_before_bank : 1;
			uint32_t : 7; // padding bits
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t row_addr_type : 3;
			uint32_t : 5; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* PAT_GEN_0_CTRL_0 10'h144 */
	union {
		uint32_t pat_gen_0_ctrl_0; // word name
		struct {
			uint32_t pat_gen_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_0_write : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_0_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_0_agent : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* PAT_GEN_0_CTRL_1 10'h148 */
	union {
		uint32_t pat_gen_0_ctrl_1; // word name
		struct {
			uint32_t pat_gen_0_shuffle : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_0_wstrb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PAT_GEN_0_CTRL_2 10'h14C */
	union {
		uint32_t pat_gen_0_ctrl_2; // word name
		struct {
			uint32_t pat_gen_0_wstrb : 32;
		};
	};
	/* PAT_GEN_0_DAT_0 10'h150 */
	union {
		uint32_t pat_gen_0_dat_0; // word name
		struct {
			uint32_t pat_gen_0_data_0 : 32;
		};
	};
	/* PAT_GEN_0_DAT_1 10'h154 */
	union {
		uint32_t pat_gen_0_dat_1; // word name
		struct {
			uint32_t pat_gen_0_data_1 : 32;
		};
	};
	/* PAT_GEN_0_DAT_2 10'h158 */
	union {
		uint32_t pat_gen_0_dat_2; // word name
		struct {
			uint32_t pat_gen_0_data_2 : 32;
		};
	};
	/* PAT_GEN_0_DAT_3 10'h15C */
	union {
		uint32_t pat_gen_0_dat_3; // word name
		struct {
			uint32_t pat_gen_0_data_3 : 32;
		};
	};
	/* PAT_GEN_0_DAT_4 10'h160 */
	union {
		uint32_t pat_gen_0_dat_4; // word name
		struct {
			uint32_t pat_gen_0_data_4 : 32;
		};
	};
	/* PAT_GEN_0_DAT_5 10'h164 */
	union {
		uint32_t pat_gen_0_dat_5; // word name
		struct {
			uint32_t pat_gen_0_data_5 : 32;
		};
	};
	/* PAT_GEN_0_DAT_6 10'h168 */
	union {
		uint32_t pat_gen_0_dat_6; // word name
		struct {
			uint32_t pat_gen_0_data_6 : 32;
		};
	};
	/* PAT_GEN_0_DAT_7 10'h16C */
	union {
		uint32_t pat_gen_0_dat_7; // word name
		struct {
			uint32_t pat_gen_0_data_7 : 32;
		};
	};
	/* PAT_GEN_1_CTRL_0 10'h170 */
	union {
		uint32_t pat_gen_1_ctrl_0; // word name
		struct {
			uint32_t pat_gen_1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_1_write : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_1_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_1_agent : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* PAT_GEN_1_CTRL_1 10'h174 */
	union {
		uint32_t pat_gen_1_ctrl_1; // word name
		struct {
			uint32_t pat_gen_1_shuffle : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_1_wstrb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PAT_GEN_1_CTRL_2 10'h178 */
	union {
		uint32_t pat_gen_1_ctrl_2; // word name
		struct {
			uint32_t pat_gen_1_wstrb : 32;
		};
	};
	/* PAT_GEN_1_DAT_0 10'h17C */
	union {
		uint32_t pat_gen_1_dat_0; // word name
		struct {
			uint32_t pat_gen_1_data_0 : 32;
		};
	};
	/* PAT_GEN_1_DAT_1 10'h180 */
	union {
		uint32_t pat_gen_1_dat_1; // word name
		struct {
			uint32_t pat_gen_1_data_1 : 32;
		};
	};
	/* PAT_GEN_1_DAT_2 10'h184 */
	union {
		uint32_t pat_gen_1_dat_2; // word name
		struct {
			uint32_t pat_gen_1_data_2 : 32;
		};
	};
	/* PAT_GEN_1_DAT_3 10'h188 */
	union {
		uint32_t pat_gen_1_dat_3; // word name
		struct {
			uint32_t pat_gen_1_data_3 : 32;
		};
	};
	/* PAT_GEN_1_DAT_4 10'h18C */
	union {
		uint32_t pat_gen_1_dat_4; // word name
		struct {
			uint32_t pat_gen_1_data_4 : 32;
		};
	};
	/* PAT_GEN_1_DAT_5 10'h190 */
	union {
		uint32_t pat_gen_1_dat_5; // word name
		struct {
			uint32_t pat_gen_1_data_5 : 32;
		};
	};
	/* PAT_GEN_1_DAT_6 10'h194 */
	union {
		uint32_t pat_gen_1_dat_6; // word name
		struct {
			uint32_t pat_gen_1_data_6 : 32;
		};
	};
	/* PAT_GEN_1_DAT_7 10'h198 */
	union {
		uint32_t pat_gen_1_dat_7; // word name
		struct {
			uint32_t pat_gen_1_data_7 : 32;
		};
	};
	/* PAT_GEN_2_CTRL_0 10'h19C */
	union {
		uint32_t pat_gen_2_ctrl_0; // word name
		struct {
			uint32_t pat_gen_2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_2_write : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_2_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_2_agent : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* PAT_GEN_2_CTRL_1 10'h1A0 */
	union {
		uint32_t pat_gen_2_ctrl_1; // word name
		struct {
			uint32_t pat_gen_2_shuffle : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_2_wstrb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PAT_GEN_2_CTRL_2 10'h1A4 */
	union {
		uint32_t pat_gen_2_ctrl_2; // word name
		struct {
			uint32_t pat_gen_2_wstrb : 32;
		};
	};
	/* PAT_GEN_2_DAT_0 10'h1A8 */
	union {
		uint32_t pat_gen_2_dat_0; // word name
		struct {
			uint32_t pat_gen_2_data_0 : 32;
		};
	};
	/* PAT_GEN_2_DAT_1 10'h1AC */
	union {
		uint32_t pat_gen_2_dat_1; // word name
		struct {
			uint32_t pat_gen_2_data_1 : 32;
		};
	};
	/* PAT_GEN_2_DAT_2 10'h1B0 */
	union {
		uint32_t pat_gen_2_dat_2; // word name
		struct {
			uint32_t pat_gen_2_data_2 : 32;
		};
	};
	/* PAT_GEN_2_DAT_3 10'h1B4 */
	union {
		uint32_t pat_gen_2_dat_3; // word name
		struct {
			uint32_t pat_gen_2_data_3 : 32;
		};
	};
	/* PAT_GEN_2_DAT_4 10'h1B8 */
	union {
		uint32_t pat_gen_2_dat_4; // word name
		struct {
			uint32_t pat_gen_2_data_4 : 32;
		};
	};
	/* PAT_GEN_2_DAT_5 10'h1BC */
	union {
		uint32_t pat_gen_2_dat_5; // word name
		struct {
			uint32_t pat_gen_2_data_5 : 32;
		};
	};
	/* PAT_GEN_2_DAT_6 10'h1C0 */
	union {
		uint32_t pat_gen_2_dat_6; // word name
		struct {
			uint32_t pat_gen_2_data_6 : 32;
		};
	};
	/* PAT_GEN_2_DAT_7 10'h1C4 */
	union {
		uint32_t pat_gen_2_dat_7; // word name
		struct {
			uint32_t pat_gen_2_data_7 : 32;
		};
	};
	/* PAT_GEN_3_CTRL_0 10'h1C8 */
	union {
		uint32_t pat_gen_3_ctrl_0; // word name
		struct {
			uint32_t pat_gen_3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_3_write : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_3_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_3_agent : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* PAT_GEN_3_CTRL_1 10'h1CC */
	union {
		uint32_t pat_gen_3_ctrl_1; // word name
		struct {
			uint32_t pat_gen_3_shuffle : 1;
			uint32_t : 7; // padding bits
			uint32_t pat_gen_3_wstrb_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PAT_GEN_3_CTRL_2 10'h1D0 */
	union {
		uint32_t pat_gen_3_ctrl_2; // word name
		struct {
			uint32_t pat_gen_3_wstrb : 32;
		};
	};
	/* PAT_GEN_3_DAT_0 10'h1D4 */
	union {
		uint32_t pat_gen_3_dat_0; // word name
		struct {
			uint32_t pat_gen_3_data_0 : 32;
		};
	};
	/* PAT_GEN_3_DAT_1 10'h1D8 */
	union {
		uint32_t pat_gen_3_dat_1; // word name
		struct {
			uint32_t pat_gen_3_data_1 : 32;
		};
	};
	/* PAT_GEN_3_DAT_2 10'h1DC */
	union {
		uint32_t pat_gen_3_dat_2; // word name
		struct {
			uint32_t pat_gen_3_data_2 : 32;
		};
	};
	/* PAT_GEN_3_DAT_3 10'h1E0 */
	union {
		uint32_t pat_gen_3_dat_3; // word name
		struct {
			uint32_t pat_gen_3_data_3 : 32;
		};
	};
	/* PAT_GEN_3_DAT_4 10'h1E4 */
	union {
		uint32_t pat_gen_3_dat_4; // word name
		struct {
			uint32_t pat_gen_3_data_4 : 32;
		};
	};
	/* PAT_GEN_3_DAT_5 10'h1E8 */
	union {
		uint32_t pat_gen_3_dat_5; // word name
		struct {
			uint32_t pat_gen_3_data_5 : 32;
		};
	};
	/* PAT_GEN_3_DAT_6 10'h1EC */
	union {
		uint32_t pat_gen_3_dat_6; // word name
		struct {
			uint32_t pat_gen_3_data_6 : 32;
		};
	};
	/* PAT_GEN_3_DAT_7 10'h1F0 */
	union {
		uint32_t pat_gen_3_dat_7; // word name
		struct {
			uint32_t pat_gen_3_data_7 : 32;
		};
	};
	/* CHKSUM_0_CTRL 10'h1F4 */
	union {
		uint32_t chksum_0_ctrl; // word name
		struct {
			uint32_t checksum_0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_0_type : 2;
			uint32_t : 6; // padding bits
			uint32_t checksum_0_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CHKSUM_0_0 10'h1F8 */
	union {
		uint32_t chksum_0_0; // word name
		struct {
			uint32_t checksum_0_0 : 32;
		};
	};
	/* CHKSUM_0_1 10'h1FC */
	union {
		uint32_t chksum_0_1; // word name
		struct {
			uint32_t checksum_0_1 : 32;
		};
	};
	/* CHKSUM_0_2 10'h200 */
	union {
		uint32_t chksum_0_2; // word name
		struct {
			uint32_t checksum_0_2 : 32;
		};
	};
	/* CHKSUM_0_3 10'h204 */
	union {
		uint32_t chksum_0_3; // word name
		struct {
			uint32_t checksum_0_3 : 32;
		};
	};
	/* CHKSUM_0_4 10'h208 */
	union {
		uint32_t chksum_0_4; // word name
		struct {
			uint32_t checksum_0_4 : 32;
		};
	};
	/* CHKSUM_0_5 10'h20C */
	union {
		uint32_t chksum_0_5; // word name
		struct {
			uint32_t checksum_0_5 : 32;
		};
	};
	/* CHKSUM_0_6 10'h210 */
	union {
		uint32_t chksum_0_6; // word name
		struct {
			uint32_t checksum_0_6 : 32;
		};
	};
	/* CHKSUM_0_7 10'h214 */
	union {
		uint32_t chksum_0_7; // word name
		struct {
			uint32_t checksum_0_7 : 32;
		};
	};
	/* CHKSUM_1_CTRL 10'h218 */
	union {
		uint32_t chksum_1_ctrl; // word name
		struct {
			uint32_t checksum_1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_1_type : 2;
			uint32_t : 6; // padding bits
			uint32_t checksum_1_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CHKSUM_1_0 10'h21C */
	union {
		uint32_t chksum_1_0; // word name
		struct {
			uint32_t checksum_1_0 : 32;
		};
	};
	/* CHKSUM_1_1 10'h220 */
	union {
		uint32_t chksum_1_1; // word name
		struct {
			uint32_t checksum_1_1 : 32;
		};
	};
	/* CHKSUM_1_2 10'h224 */
	union {
		uint32_t chksum_1_2; // word name
		struct {
			uint32_t checksum_1_2 : 32;
		};
	};
	/* CHKSUM_1_3 10'h228 */
	union {
		uint32_t chksum_1_3; // word name
		struct {
			uint32_t checksum_1_3 : 32;
		};
	};
	/* CHKSUM_1_4 10'h22C */
	union {
		uint32_t chksum_1_4; // word name
		struct {
			uint32_t checksum_1_4 : 32;
		};
	};
	/* CHKSUM_1_5 10'h230 */
	union {
		uint32_t chksum_1_5; // word name
		struct {
			uint32_t checksum_1_5 : 32;
		};
	};
	/* CHKSUM_1_6 10'h234 */
	union {
		uint32_t chksum_1_6; // word name
		struct {
			uint32_t checksum_1_6 : 32;
		};
	};
	/* CHKSUM_1_7 10'h238 */
	union {
		uint32_t chksum_1_7; // word name
		struct {
			uint32_t checksum_1_7 : 32;
		};
	};
	/* CHKSUM_2_CTRL 10'h23C */
	union {
		uint32_t chksum_2_ctrl; // word name
		struct {
			uint32_t checksum_2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_2_type : 2;
			uint32_t : 6; // padding bits
			uint32_t checksum_2_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CHKSUM_2_0 10'h240 */
	union {
		uint32_t chksum_2_0; // word name
		struct {
			uint32_t checksum_2_0 : 32;
		};
	};
	/* CHKSUM_2_1 10'h244 */
	union {
		uint32_t chksum_2_1; // word name
		struct {
			uint32_t checksum_2_1 : 32;
		};
	};
	/* CHKSUM_2_2 10'h248 */
	union {
		uint32_t chksum_2_2; // word name
		struct {
			uint32_t checksum_2_2 : 32;
		};
	};
	/* CHKSUM_2_3 10'h24C */
	union {
		uint32_t chksum_2_3; // word name
		struct {
			uint32_t checksum_2_3 : 32;
		};
	};
	/* CHKSUM_2_4 10'h250 */
	union {
		uint32_t chksum_2_4; // word name
		struct {
			uint32_t checksum_2_4 : 32;
		};
	};
	/* CHKSUM_2_5 10'h254 */
	union {
		uint32_t chksum_2_5; // word name
		struct {
			uint32_t checksum_2_5 : 32;
		};
	};
	/* CHKSUM_2_6 10'h258 */
	union {
		uint32_t chksum_2_6; // word name
		struct {
			uint32_t checksum_2_6 : 32;
		};
	};
	/* CHKSUM_2_7 10'h25C */
	union {
		uint32_t chksum_2_7; // word name
		struct {
			uint32_t checksum_2_7 : 32;
		};
	};
	/* CHKSUM_3_CTRL 10'h260 */
	union {
		uint32_t chksum_3_ctrl; // word name
		struct {
			uint32_t checksum_3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t checksum_3_type : 2;
			uint32_t : 6; // padding bits
			uint32_t checksum_3_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CHKSUM_3_0 10'h264 */
	union {
		uint32_t chksum_3_0; // word name
		struct {
			uint32_t checksum_3_0 : 32;
		};
	};
	/* CHKSUM_3_1 10'h268 */
	union {
		uint32_t chksum_3_1; // word name
		struct {
			uint32_t checksum_3_1 : 32;
		};
	};
	/* CHKSUM_3_2 10'h26C */
	union {
		uint32_t chksum_3_2; // word name
		struct {
			uint32_t checksum_3_2 : 32;
		};
	};
	/* CHKSUM_3_3 10'h270 */
	union {
		uint32_t chksum_3_3; // word name
		struct {
			uint32_t checksum_3_3 : 32;
		};
	};
	/* CHKSUM_3_4 10'h274 */
	union {
		uint32_t chksum_3_4; // word name
		struct {
			uint32_t checksum_3_4 : 32;
		};
	};
	/* CHKSUM_3_5 10'h278 */
	union {
		uint32_t chksum_3_5; // word name
		struct {
			uint32_t checksum_3_5 : 32;
		};
	};
	/* CHKSUM_3_6 10'h27C */
	union {
		uint32_t chksum_3_6; // word name
		struct {
			uint32_t checksum_3_6 : 32;
		};
	};
	/* CHKSUM_3_7 10'h280 */
	union {
		uint32_t chksum_3_7; // word name
		struct {
			uint32_t checksum_3_7 : 32;
		};
	};
	/* MON_AGENT 10'h284 */
	union {
		uint32_t mon_agent; // word name
		struct {
			uint32_t w_addr_mon_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t r_addr_mon_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t w_data_mon_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t r_data_mon_agent : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* LAST_STATUS_EN 10'h288 */
	union {
		uint32_t last_status_en; // word name
		struct {
			uint32_t last_w_addr_en : 1;
			uint32_t : 7; // padding bits
			uint32_t last_r_addr_en : 1;
			uint32_t : 7; // padding bits
			uint32_t last_w_data_en : 1;
			uint32_t : 7; // padding bits
			uint32_t last_r_data_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LAST_STATUS_ALL_AGENT 10'h28C */
	union {
		uint32_t last_status_all_agent; // word name
		struct {
			uint32_t last_w_addr_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t last_r_addr_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t last_w_data_all_agent : 1;
			uint32_t : 7; // padding bits
			uint32_t last_r_data_all_agent : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATUS_LAST_W_ADDR 10'h290 */
	union {
		uint32_t status_last_w_addr; // word name
		struct {
			uint32_t last_w_addr : 31;
			uint32_t : 1; // padding bits
		};
	};
	/* STATUS_LAST_R_ADDR 10'h294 */
	union {
		uint32_t status_last_r_addr; // word name
		struct {
			uint32_t last_r_addr : 31;
			uint32_t : 1; // padding bits
		};
	};
	/* STATUS_LAST_W_DATA_0 10'h298 */
	union {
		uint32_t status_last_w_data_0; // word name
		struct {
			uint32_t last_w_data_0 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_1 10'h29C */
	union {
		uint32_t status_last_w_data_1; // word name
		struct {
			uint32_t last_w_data_1 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_2 10'h2A0 */
	union {
		uint32_t status_last_w_data_2; // word name
		struct {
			uint32_t last_w_data_2 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_3 10'h2A4 */
	union {
		uint32_t status_last_w_data_3; // word name
		struct {
			uint32_t last_w_data_3 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_4 10'h2A8 */
	union {
		uint32_t status_last_w_data_4; // word name
		struct {
			uint32_t last_w_data_4 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_5 10'h2AC */
	union {
		uint32_t status_last_w_data_5; // word name
		struct {
			uint32_t last_w_data_5 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_6 10'h2B0 */
	union {
		uint32_t status_last_w_data_6; // word name
		struct {
			uint32_t last_w_data_6 : 32;
		};
	};
	/* STATUS_LAST_W_DATA_7 10'h2B4 */
	union {
		uint32_t status_last_w_data_7; // word name
		struct {
			uint32_t last_w_data_7 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_0 10'h2B8 */
	union {
		uint32_t status_last_r_data_0; // word name
		struct {
			uint32_t last_r_data_0 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_1 10'h2BC */
	union {
		uint32_t status_last_r_data_1; // word name
		struct {
			uint32_t last_r_data_1 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_2 10'h2C0 */
	union {
		uint32_t status_last_r_data_2; // word name
		struct {
			uint32_t last_r_data_2 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_3 10'h2C4 */
	union {
		uint32_t status_last_r_data_3; // word name
		struct {
			uint32_t last_r_data_3 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_4 10'h2C8 */
	union {
		uint32_t status_last_r_data_4; // word name
		struct {
			uint32_t last_r_data_4 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_5 10'h2CC */
	union {
		uint32_t status_last_r_data_5; // word name
		struct {
			uint32_t last_r_data_5 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_6 10'h2D0 */
	union {
		uint32_t status_last_r_data_6; // word name
		struct {
			uint32_t last_r_data_6 : 32;
		};
	};
	/* STATUS_LAST_R_DATA_7 10'h2D4 */
	union {
		uint32_t status_last_r_data_7; // word name
		struct {
			uint32_t last_r_data_7 : 32;
		};
	};
	/* RESP_ERROR_AGENT 10'h2D8 */
	union {
		uint32_t resp_error_agent; // word name
		struct {
			uint32_t w_resp_error_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t r_resp_error_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIMEOUT_CTRL 10'h2DC */
	union {
		uint32_t timeout_ctrl; // word name
		struct {
			uint32_t timeout_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t timeout_cycle_th : 16;
		};
	};
	/* TIMEOUT_AGENT_0 10'h2E0 */
	union {
		uint32_t timeout_agent_0; // word name
		struct {
			uint32_t timeout_w_resp_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t timeout_r_addr_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t timeout_w_addr_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t timeout_w_data_agent : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* TIMEOUT_AGENT_1 10'h2E4 */
	union {
		uint32_t timeout_agent_1; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t timeout_r_data_agent : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DARB_RESERVED_0 10'h2E8 */
	union {
		uint32_t darb_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* GENERAL_SCORE_1 10'h2EC */
	union {
		uint32_t general_score_1; // word name
		struct {
			uint32_t ini_r_score : 4;
			uint32_t : 4; // padding bits
			uint32_t ini_w_score : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDarb;

#endif