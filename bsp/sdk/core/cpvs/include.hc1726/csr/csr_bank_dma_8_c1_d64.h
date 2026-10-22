/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DMA_8_C1_D64_H_
#define CSR_BANK_DMA_8_C1_D64_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dma_8_c1_d64  ***/
typedef struct csr_bank_dma_8_c1_d64 {
	/* DMA_8_00 10'h000 */
	union {
		uint32_t dma_8_00; // word name
		struct {
			uint32_t access_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_01 10'h004 */
	union {
		uint32_t dma_8_01; // word name
		struct {
			uint32_t irq_clear_access_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient_r : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation_r : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient_w : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_02 10'h008 */
	union {
		uint32_t dma_8_02; // word name
		struct {
			uint32_t irq_clear_access_violation_w : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_03 10'h00C */
	union {
		uint32_t dma_8_03; // word name
		struct {
			uint32_t status_access_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient_r : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation_r : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient_w : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_04 10'h010 */
	union {
		uint32_t dma_8_04; // word name
		struct {
			uint32_t status_access_violation_w : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_05 10'h014 */
	union {
		uint32_t dma_8_05; // word name
		struct {
			uint32_t irq_mask_access_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient_r : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation_r : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient_w : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_06 10'h018 */
	union {
		uint32_t dma_8_06; // word name
		struct {
			uint32_t irq_mask_access_violation_w : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_07 10'h01C */
	union {
		uint32_t dma_8_07; // word name
		struct {
			uint32_t access_illegal_hang_r : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask_r : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_hang_w : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask_w : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_08 10'h020 [Unused] */
	uint32_t empty_word_dma_8_08;
	/* DMA_8_09 10'h024 [Unused] */
	uint32_t empty_word_dma_8_09;
	/* DMA_8_10 10'h028 */
	union {
		uint32_t dma_8_10; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t total_access_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DMA_8_11 10'h02C */
	union {
		uint32_t dma_8_11; // word name
		struct {
			uint32_t target_burst_len_r : 5;
			uint32_t : 3; // padding bits
			uint32_t target_burst_len_w : 5;
			uint32_t : 3; // padding bits
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_12 10'h030 */
	union {
		uint32_t dma_8_12; // word name
		struct {
			uint32_t target_fifo_level_r : 6;
			uint32_t : 2; // padding bits
			uint32_t target_fifo_level_w : 6;
			uint32_t : 2; // padding bits
			uint32_t fifo_full_level_r : 6;
			uint32_t : 2; // padding bits
			uint32_t fifo_full_level_w : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* DMA_8_13 10'h034 */
	union {
		uint32_t dma_8_13; // word name
		struct {
			uint32_t access_length_r_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_14 10'h038 */
	union {
		uint32_t dma_8_14; // word name
		struct {
			uint32_t efuse_dis_aes_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_15 10'h03C */
	union {
		uint32_t dma_8_15; // word name
		struct {
			uint32_t access_length_r_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_16 10'h040 */
	union {
		uint32_t dma_8_16; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_0 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_17 10'h044 */
	union {
		uint32_t dma_8_17; // word name
		struct {
			uint32_t aes_mode_0 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_0 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_0 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_18 10'h048 */
	union {
		uint32_t dma_8_18; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_1 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_19 10'h04C [Unused] */
	uint32_t empty_word_dma_8_19;
	/* DMA_8_20 10'h050 [Unused] */
	uint32_t empty_word_dma_8_20;
	/* DMA_8_21 10'h054 */
	union {
		uint32_t dma_8_21; // word name
		struct {
			uint32_t aes_mode_1 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_1 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_1 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_22 10'h058 */
	union {
		uint32_t dma_8_22; // word name
		struct {
			uint32_t access_length_r_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_23 10'h05C [Unused] */
	uint32_t empty_word_dma_8_23;
	/* DMA_8_24 10'h060 [Unused] */
	uint32_t empty_word_dma_8_24;
	/* DMA_8_25 10'h064 */
	union {
		uint32_t dma_8_25; // word name
		struct {
			uint32_t aes_mode_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_2 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_26 10'h068 */
	union {
		uint32_t dma_8_26; // word name
		struct {
			uint32_t access_length_r_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_27 10'h06C [Unused] */
	uint32_t empty_word_dma_8_27;
	/* DMA_8_28 10'h070 [Unused] */
	uint32_t empty_word_dma_8_28;
	/* DMA_8_29 10'h074 */
	union {
		uint32_t dma_8_29; // word name
		struct {
			uint32_t aes_mode_3 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_3 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_3 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_30 10'h078 */
	union {
		uint32_t dma_8_30; // word name
		struct {
			uint32_t access_length_r_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_31 10'h07C [Unused] */
	uint32_t empty_word_dma_8_31;
	/* DMA_8_32 10'h080 [Unused] */
	uint32_t empty_word_dma_8_32;
	/* DMA_8_33 10'h084 */
	union {
		uint32_t dma_8_33; // word name
		struct {
			uint32_t aes_mode_4 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_4 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_4 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_34 10'h088 */
	union {
		uint32_t dma_8_34; // word name
		struct {
			uint32_t access_length_r_5 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_35 10'h08C [Unused] */
	uint32_t empty_word_dma_8_35;
	/* DMA_8_36 10'h090 [Unused] */
	uint32_t empty_word_dma_8_36;
	/* DMA_8_37 10'h094 */
	union {
		uint32_t dma_8_37; // word name
		struct {
			uint32_t aes_mode_5 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_5 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_5 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_38 10'h098 */
	union {
		uint32_t dma_8_38; // word name
		struct {
			uint32_t access_length_r_6 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_39 10'h09C [Unused] */
	uint32_t empty_word_dma_8_39;
	/* DMA_8_40 10'h0A0 [Unused] */
	uint32_t empty_word_dma_8_40;
	/* DMA_8_41 10'h0A4 */
	union {
		uint32_t dma_8_41; // word name
		struct {
			uint32_t aes_mode_6 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_6 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_6 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_42 10'h0A8 */
	union {
		uint32_t dma_8_42; // word name
		struct {
			uint32_t access_length_r_7 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_43 10'h0AC [Unused] */
	uint32_t empty_word_dma_8_43;
	/* DMA_8_44 10'h0B0 [Unused] */
	uint32_t empty_word_dma_8_44;
	/* DMA_8_45 10'h0B4 */
	union {
		uint32_t dma_8_45; // word name
		struct {
			uint32_t aes_mode_7 : 2;
			uint32_t : 6; // padding bits
			uint32_t access_mode_7 : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_addr_word_r_7 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_word_w_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_46 10'h0B8 */
	union {
		uint32_t dma_8_46; // word name
		struct {
			uint32_t bank_interleave_type_0 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_1 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_3 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DMA_8_47 10'h0BC */
	union {
		uint32_t dma_8_47; // word name
		struct {
			uint32_t bank_interleave_type_4 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_5 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_6 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_7 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DMA_8_48 10'h0C0 */
	union {
		uint32_t dma_8_48; // word name
		struct {
			uint32_t ini_addr_bank_offset_r_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_r_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_r_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_r_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_49 10'h0C4 */
	union {
		uint32_t dma_8_49; // word name
		struct {
			uint32_t ini_addr_bank_offset_r_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_r_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_r_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_r_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_50 10'h0C8 */
	union {
		uint32_t dma_8_50; // word name
		struct {
			uint32_t ini_addr_linear_w_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_51 10'h0CC */
	union {
		uint32_t dma_8_51; // word name
		struct {
			uint32_t ini_addr_linear_w_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_52 10'h0D0 */
	union {
		uint32_t dma_8_52; // word name
		struct {
			uint32_t ini_addr_linear_w_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_53 10'h0D4 */
	union {
		uint32_t dma_8_53; // word name
		struct {
			uint32_t ini_addr_linear_w_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_54 10'h0D8 */
	union {
		uint32_t dma_8_54; // word name
		struct {
			uint32_t ini_addr_linear_w_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_55 10'h0DC */
	union {
		uint32_t dma_8_55; // word name
		struct {
			uint32_t ini_addr_linear_w_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_56 10'h0E0 */
	union {
		uint32_t dma_8_56; // word name
		struct {
			uint32_t ini_addr_linear_w_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_57 10'h0E4 */
	union {
		uint32_t dma_8_57; // word name
		struct {
			uint32_t ini_addr_linear_w_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_58 10'h0E8 */
	union {
		uint32_t dma_8_58; // word name
		struct {
			uint32_t ini_addr_linear_r_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_59 10'h0EC */
	union {
		uint32_t dma_8_59; // word name
		struct {
			uint32_t ini_addr_linear_r_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_60 10'h0F0 */
	union {
		uint32_t dma_8_60; // word name
		struct {
			uint32_t ini_addr_linear_r_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_61 10'h0F4 */
	union {
		uint32_t dma_8_61; // word name
		struct {
			uint32_t ini_addr_linear_r_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_62 10'h0F8 */
	union {
		uint32_t dma_8_62; // word name
		struct {
			uint32_t ini_addr_linear_r_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_63 10'h0FC */
	union {
		uint32_t dma_8_63; // word name
		struct {
			uint32_t ini_addr_linear_r_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_64 10'h100 */
	union {
		uint32_t dma_8_64; // word name
		struct {
			uint32_t ini_addr_linear_r_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_65 10'h104 */
	union {
		uint32_t dma_8_65; // word name
		struct {
			uint32_t ini_addr_linear_r_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_66 10'h108 */
	union {
		uint32_t dma_8_66; // word name
		struct {
			uint32_t flush_addr_skip_r_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_0 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_67 10'h10C */
	union {
		uint32_t dma_8_67; // word name
		struct {
			uint32_t flush_addr_skip_r_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_68 10'h110 */
	union {
		uint32_t dma_8_68; // word name
		struct {
			uint32_t flush_addr_skip_r_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_2 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_69 10'h114 */
	union {
		uint32_t dma_8_69; // word name
		struct {
			uint32_t flush_addr_skip_r_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_70 10'h118 */
	union {
		uint32_t dma_8_70; // word name
		struct {
			uint32_t flush_addr_skip_r_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_4 : 1;
			uint32_t : 2; // padding bits
			uint32_t bypass_ado : 1;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_71 10'h11C */
	union {
		uint32_t dma_8_71; // word name
		struct {
			uint32_t flush_addr_skip_r_5 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_5 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_72 10'h120 */
	union {
		uint32_t dma_8_72; // word name
		struct {
			uint32_t flush_addr_skip_r_6 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_6 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_73 10'h124 */
	union {
		uint32_t dma_8_73; // word name
		struct {
			uint32_t flush_addr_skip_r_7 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_r_7 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_74 10'h128 [Unused] */
	uint32_t empty_word_dma_8_74;
	/* DMA_8_75 10'h12C [Unused] */
	uint32_t empty_word_dma_8_75;
	/* DMA_8_76 10'h130 */
	union {
		uint32_t dma_8_76; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_2 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_77 10'h134 */
	union {
		uint32_t dma_8_77; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_3 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_78 10'h138 */
	union {
		uint32_t dma_8_78; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_4 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_79 10'h13C */
	union {
		uint32_t dma_8_79; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_5 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_80 10'h140 */
	union {
		uint32_t dma_8_80; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_6 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_81 10'h144 */
	union {
		uint32_t dma_8_81; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t loop_cnt_7 : 15;
			uint32_t : 1; // padding bits
		};
	};
	/* DMA_8_82 10'h148 */
	union {
		uint32_t dma_8_82; // word name
		struct {
			uint32_t flush_addr_skip_w_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_0 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_83 10'h14C */
	union {
		uint32_t dma_8_83; // word name
		struct {
			uint32_t flush_addr_skip_w_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_1 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_84 10'h150 */
	union {
		uint32_t dma_8_84; // word name
		struct {
			uint32_t flush_addr_skip_w_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_2 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_85 10'h154 */
	union {
		uint32_t dma_8_85; // word name
		struct {
			uint32_t flush_addr_skip_w_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_86 10'h158 */
	union {
		uint32_t dma_8_86; // word name
		struct {
			uint32_t flush_addr_skip_w_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_4 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_87 10'h15C */
	union {
		uint32_t dma_8_87; // word name
		struct {
			uint32_t flush_addr_skip_w_5 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_5 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_88 10'h160 */
	union {
		uint32_t dma_8_88; // word name
		struct {
			uint32_t flush_addr_skip_w_6 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_6 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_89 10'h164 */
	union {
		uint32_t dma_8_89; // word name
		struct {
			uint32_t flush_addr_skip_w_7 : 20;
			uint32_t : 4; // padding bits
			uint32_t flush_addr_skip_sign_w_7 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DMA_8_90 10'h168 */
	union {
		uint32_t dma_8_90; // word name
		struct {
			uint32_t bank_interleave_type_w_0 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_w_1 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_w_2 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_w_3 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DMA_8_91 10'h16c */
	union {
		uint32_t dma_8_91; // word name
		struct {
			uint32_t bank_interleave_type_w_4 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_w_5 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_w_6 : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_interleave_type_w_7 : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DMA_8_92 10'h170 */
	union {
		uint32_t dma_8_92; // word name
		struct {
			uint32_t ini_addr_bank_offset_w_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_w_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_w_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_w_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_93 10'h174 */
	union {
		uint32_t dma_8_93; // word name
		struct {
			uint32_t ini_addr_bank_offset_w_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_w_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_w_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_offset_w_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DMA_8_94 10'h178 */
	union {
		uint32_t dma_8_94; // word name
		struct {
			uint32_t start_addr_r : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_95 10'h17c */
	union {
		uint32_t dma_8_95; // word name
		struct {
			uint32_t end_addr_r : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_96 10'h180 */
	union {
		uint32_t dma_8_96; // word name
		struct {
			uint32_t start_addr_w : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_97 10'h184 */
	union {
		uint32_t dma_8_97; // word name
		struct {
			uint32_t end_addr_w : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DMA_8_98 10'h188 */
	union {
		uint32_t dma_8_98; // word name
		struct {
			uint32_t access_length_w_0 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_99 10'h18c */
	union {
		uint32_t dma_8_99; // word name
		struct {
			uint32_t access_length_w_1 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_100 10'h190 */
	union {
		uint32_t dma_8_100; // word name
		struct {
			uint32_t access_length_w_2 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_101 10'h194 */
	union {
		uint32_t dma_8_101; // word name
		struct {
			uint32_t access_length_w_3 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_102 10'h198 */
	union {
		uint32_t dma_8_102; // word name
		struct {
			uint32_t access_length_w_4 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_103 10'h19c */
	union {
		uint32_t dma_8_103; // word name
		struct {
			uint32_t access_length_w_5 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_104 10'h1a0 */
	union {
		uint32_t dma_8_104; // word name
		struct {
			uint32_t access_length_w_6 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_105 10'h1a4 */
	union {
		uint32_t dma_8_105; // word name
		struct {
			uint32_t access_length_w_7 : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_8_106 10'h1a8 */
	union {
		uint32_t dma_8_106; // word name
		struct {
			uint32_t scan_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankDma_8_c1_d64;

#endif