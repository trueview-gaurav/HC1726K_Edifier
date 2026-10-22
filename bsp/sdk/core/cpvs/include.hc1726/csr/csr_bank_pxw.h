/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PXW_H_
#define CSR_BANK_PXW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pxw  ***/
typedef struct csr_bank_pxw {
	/* PW0_00 10'h000 */
	union {
		uint32_t pw0_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_01 10'h004 */
	union {
		uint32_t pw0_01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_02 10'h008 */
	union {
		uint32_t pw0_02; // word name
		struct {
			uint32_t irq_clear_burst_fifo_full : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_03 10'h00C */
	union {
		uint32_t pw0_03; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_04 10'h010 */
	union {
		uint32_t pw0_04; // word name
		struct {
			uint32_t status_burst_fifo_full : 1;
			uint32_t : 7; // padding bits
			uint32_t status_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_05 10'h014 */
	union {
		uint32_t pw0_05; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_overflow : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_06 10'h018 */
	union {
		uint32_t pw0_06; // word name
		struct {
			uint32_t irq_mask_burst_fifo_full : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_resp_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_07 10'h01C */
	union {
		uint32_t pw0_07; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_08 10'h020 */
	union {
		uint32_t pw0_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_09 10'h024 */
	union {
		uint32_t pw0_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t width : 16;
		};
	};
	/* PW0_10 10'h028 */
	union {
		uint32_t pw0_10; // word name
		struct {
			uint32_t y_only_e : 1;
			uint32_t : 7; // padding bits
			uint32_t y_only_o : 1;
			uint32_t : 7; // padding bits
			uint32_t msb_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_11 10'h02C [Unused] */
	uint32_t empty_word_pw0_11;
	/* PW0_12 10'h030 */
	union {
		uint32_t pw0_12; // word name
		struct {
			uint32_t fifo_flush_len : 14;
			uint32_t : 2; // padding bits
			uint32_t fifo_start_phase : 5;
			uint32_t : 3; // padding bits
			uint32_t fifo_end_phase : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* PW0_13 10'h034 [Unused] */
	uint32_t empty_word_pw0_13;
	/* PW0_14 10'h038 [Unused] */
	uint32_t empty_word_pw0_14;
	/* PW0_15 10'h03C [Unused] */
	uint32_t empty_word_pw0_15;
	/* PW0_16 10'h040 */
	union {
		uint32_t pw0_16; // word name
		struct {
			uint32_t pixel_flush_len : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_17 10'h044 */
	union {
		uint32_t pw0_17; // word name
		struct {
			uint32_t flush_addr_skip_e : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_18 10'h048 */
	union {
		uint32_t pw0_18; // word name
		struct {
			uint32_t flush_addr_skip_o : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_19 10'h04C */
	union {
		uint32_t pw0_19; // word name
		struct {
			uint32_t fifo_flush_len_last : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t package_size_last : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_20 10'h050 */
	union {
		uint32_t pw0_20; // word name
		struct {
			uint32_t v_start : 16;
			uint32_t v_end : 16;
		};
	};
	/* PW0_21 10'h054 */
	union {
		uint32_t pw0_21; // word name
		struct {
			uint32_t h_start : 16;
			uint32_t h_end : 16;
		};
	};
	/* PW0_22 10'h058 */
	union {
		uint32_t pw0_22; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_23 10'h05C */
	union {
		uint32_t pw0_23; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* PW0_24 10'h060 [Unused] */
	uint32_t empty_word_pw0_24;
	/* PW0_25 10'h064 [Unused] */
	uint32_t empty_word_pw0_25;
	/* PW0_26 10'h068 [Unused] */
	uint32_t empty_word_pw0_26;
	/* PW0_27 10'h06C [Unused] */
	uint32_t empty_word_pw0_27;
	/* PW0_28 10'h070 [Unused] */
	uint32_t empty_word_pw0_28;
	/* PW0_29 10'h074 [Unused] */
	uint32_t empty_word_pw0_29;
	/* PW0_30 10'h078 [Unused] */
	uint32_t empty_word_pw0_30;
	/* PW0_31 10'h07C [Unused] */
	uint32_t empty_word_pw0_31;
	/* PW0_32 10'h080 [Unused] */
	uint32_t empty_word_pw0_32;
	/* PW0_33 10'h084 [Unused] */
	uint32_t empty_word_pw0_33;
	/* PW0_34 10'h088 [Unused] */
	uint32_t empty_word_pw0_34;
	/* PW0_35 10'h08C [Unused] */
	uint32_t empty_word_pw0_35;
	/* PW0_36 10'h090 [Unused] */
	uint32_t empty_word_pw0_36;
	/* PW0_37 10'h094 [Unused] */
	uint32_t empty_word_pw0_37;
	/* PW0_38 10'h098 [Unused] */
	uint32_t empty_word_pw0_38;
	/* PW0_39 10'h09C [Unused] */
	uint32_t empty_word_pw0_39;
	/* PW0_40 10'h0A0 */
	union {
		uint32_t pw0_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_41 10'h0A4 */
	union {
		uint32_t pw0_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_42 10'h0A8 */
	union {
		uint32_t pw0_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_43 10'h0AC */
	union {
		uint32_t pw0_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_44 10'h0B0 */
	union {
		uint32_t pw0_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_45 10'h0B4 */
	union {
		uint32_t pw0_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_46 10'h0B8 */
	union {
		uint32_t pw0_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_47 10'h0BC */
	union {
		uint32_t pw0_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_48 10'h0C0 */
	union {
		uint32_t pw0_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_from_ext : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_49 10'h0C4 */
	union {
		uint32_t pw0_49; // word name
		struct {
			uint32_t roi_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_50 10'h0C8 */
	union {
		uint32_t pw0_50; // word name
		struct {
			uint32_t roi_enable_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_51 10'h0CC */
	union {
		uint32_t pw0_51; // word name
		struct {
			uint32_t roi_enable_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_6 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_7 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_52 10'h0D0 */
	union {
		uint32_t pw0_52; // word name
		struct {
			uint32_t roi_enable_8 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_9 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_a : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_b : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_53 10'h0D4 */
	union {
		uint32_t pw0_53; // word name
		struct {
			uint32_t roi_enable_c : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_d : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_e : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_enable_f : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PW0_54 10'h0D8 */
	union {
		uint32_t pw0_54; // word name
		struct {
			uint32_t v_start_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_0 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_55 10'h0DC */
	union {
		uint32_t pw0_55; // word name
		struct {
			uint32_t h_start_0 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_0 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_56 10'h0E0 */
	union {
		uint32_t pw0_56; // word name
		struct {
			uint32_t v_start_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_57 10'h0E4 */
	union {
		uint32_t pw0_57; // word name
		struct {
			uint32_t h_start_1 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_1 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_58 10'h0E8 */
	union {
		uint32_t pw0_58; // word name
		struct {
			uint32_t v_start_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_59 10'h0EC */
	union {
		uint32_t pw0_59; // word name
		struct {
			uint32_t h_start_2 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_2 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_60 10'h0F0 */
	union {
		uint32_t pw0_60; // word name
		struct {
			uint32_t v_start_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_61 10'h0F4 */
	union {
		uint32_t pw0_61; // word name
		struct {
			uint32_t h_start_3 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_3 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_62 10'h0F8 */
	union {
		uint32_t pw0_62; // word name
		struct {
			uint32_t v_start_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_63 10'h0FC */
	union {
		uint32_t pw0_63; // word name
		struct {
			uint32_t h_start_4 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_4 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_64 10'h100 */
	union {
		uint32_t pw0_64; // word name
		struct {
			uint32_t v_start_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_65 10'h104 */
	union {
		uint32_t pw0_65; // word name
		struct {
			uint32_t h_start_5 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_5 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_66 10'h108 */
	union {
		uint32_t pw0_66; // word name
		struct {
			uint32_t v_start_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_67 10'h10C */
	union {
		uint32_t pw0_67; // word name
		struct {
			uint32_t h_start_6 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_6 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_68 10'h110 */
	union {
		uint32_t pw0_68; // word name
		struct {
			uint32_t v_start_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_69 10'h114 */
	union {
		uint32_t pw0_69; // word name
		struct {
			uint32_t h_start_7 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_7 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_70 10'h118 */
	union {
		uint32_t pw0_70; // word name
		struct {
			uint32_t v_start_8 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_71 10'h11C */
	union {
		uint32_t pw0_71; // word name
		struct {
			uint32_t h_start_8 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_8 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_72 10'h120 */
	union {
		uint32_t pw0_72; // word name
		struct {
			uint32_t v_start_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_9 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_73 10'h124 */
	union {
		uint32_t pw0_73; // word name
		struct {
			uint32_t h_start_9 : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_9 : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_74 10'h128 */
	union {
		uint32_t pw0_74; // word name
		struct {
			uint32_t v_start_a : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_a : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_75 10'h12C */
	union {
		uint32_t pw0_75; // word name
		struct {
			uint32_t h_start_a : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_a : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_76 10'h130 */
	union {
		uint32_t pw0_76; // word name
		struct {
			uint32_t v_start_b : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_b : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_77 10'h134 */
	union {
		uint32_t pw0_77; // word name
		struct {
			uint32_t h_start_b : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_b : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_78 10'h138 */
	union {
		uint32_t pw0_78; // word name
		struct {
			uint32_t v_start_c : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_c : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_79 10'h13C */
	union {
		uint32_t pw0_79; // word name
		struct {
			uint32_t h_start_c : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_c : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_80 10'h140 */
	union {
		uint32_t pw0_80; // word name
		struct {
			uint32_t v_start_d : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_d : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_81 10'h144 */
	union {
		uint32_t pw0_81; // word name
		struct {
			uint32_t h_start_d : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_d : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_82 10'h148 */
	union {
		uint32_t pw0_82; // word name
		struct {
			uint32_t v_start_e : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_e : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_83 10'h14C */
	union {
		uint32_t pw0_83; // word name
		struct {
			uint32_t h_start_e : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_e : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_84 10'h150 */
	union {
		uint32_t pw0_84; // word name
		struct {
			uint32_t v_start_f : 14;
			uint32_t : 2; // padding bits
			uint32_t v_end_f : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_85 10'h154 */
	union {
		uint32_t pw0_85; // word name
		struct {
			uint32_t h_start_f : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end_f : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* PW0_86 10'h158 */
	union {
		uint32_t pw0_86; // word name
		struct {
			uint32_t allow_stall : 1;
			uint32_t : 7; // padding bits
			uint32_t allow_drop_frame : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_87 10'h15C [Unused] */
	uint32_t empty_word_pw0_87;
	/* PW0_88 10'h160 [Unused] */
	uint32_t empty_word_pw0_88;
	/* PW0_89 10'h164 [Unused] */
	uint32_t empty_word_pw0_89;
	/* PW0_90 10'h168 */
	union {
		uint32_t pw0_90; // word name
		struct {
			uint32_t frame_start_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PW0_91 10'h16C */
	union {
		uint32_t pw0_91; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 3; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* PW0_92 10'h170 */
	union {
		uint32_t pw0_92; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_93 10'h174 */
	union {
		uint32_t pw0_93; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PW0_94 10'h178 [Unused] */
	uint32_t empty_word_pw0_94;
	/* PW0_95 10'h17C [Unused] */
	uint32_t empty_word_pw0_95;
	/* PW0_96 10'h180 [Unused] */
	uint32_t empty_word_pw0_96;
	/* PW0_97 10'h184 [Unused] */
	uint32_t empty_word_pw0_97;
	/* PW0_98 10'h188 [Unused] */
	uint32_t empty_word_pw0_98;
	/* PW0_99 10'h18C [Unused] */
	uint32_t empty_word_pw0_99;
	/* PW0_100 10'h190 [Unused] */
	uint32_t empty_word_pw0_100;
} CsrBankPxw;

#endif