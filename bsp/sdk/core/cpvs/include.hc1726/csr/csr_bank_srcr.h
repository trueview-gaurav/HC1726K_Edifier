/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SRCR_H_
#define CSR_BANK_SRCR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from srcr  ***/
typedef struct csr_bank_srcr {
	/* FRM_START 10'h000 */
	union {
		uint32_t frm_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 10'h004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATUS 10'h008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t status_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQ_MASK 10'h00C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* BR1_04 10'h010 */
	union {
		uint32_t br1_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 3; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* BR1_05 10'h014 */
	union {
		uint32_t br1_05; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t fifo_ready_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_06 10'h018 [Unused] */
	uint32_t empty_word_br1_06;
	/* BR1_07 10'h01C */
	union {
		uint32_t br1_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_08 10'h020 */
	union {
		uint32_t br1_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* BR1_09 10'h024 */
	union {
		uint32_t br1_09; // word name
		struct {
			uint32_t total_fifo_flush_cnt : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* BR1_10 10'h028 */
	union {
		uint32_t br1_10; // word name
		struct {
			uint32_t y_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t msb_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_11 10'h02C */
	union {
		uint32_t br1_11; // word name
		struct {
			uint32_t block_size : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_12 10'h030 */
	union {
		uint32_t br1_12; // word name
		struct {
			uint32_t block_cnt_per_row : 13;
			uint32_t : 3; // padding bits
			uint32_t total_block_row : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* BR1_13 10'h034 [Unused] */
	uint32_t empty_word_br1_13;
	/* BR1_14 10'h038 [Unused] */
	uint32_t empty_word_br1_14;
	/* BR1_15 10'h03C [Unused] */
	uint32_t empty_word_br1_15;
	/* BR1_16 10'h040 */
	union {
		uint32_t br1_16; // word name
		struct {
			uint32_t flush_addr_skip : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_17 10'h044 */
	union {
		uint32_t br1_17; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* BR1_18 10'h048 */
	union {
		uint32_t br1_18; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_19 10'h04C */
	union {
		uint32_t br1_19; // word name
		struct {
			uint32_t flush_addr_skip_extra : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_20 10'h050 */
	union {
		uint32_t br1_20; // word name
		struct {
			uint32_t lcu_32x32 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_21 10'h054 [Unused] */
	uint32_t empty_word_br1_21;
	/* BR1_22 10'h058 [Unused] */
	uint32_t empty_word_br1_22;
	/* BR1_23 10'h05C [Unused] */
	uint32_t empty_word_br1_23;
	/* BR1_24 10'h060 [Unused] */
	uint32_t empty_word_br1_24;
	/* BR1_25 10'h064 [Unused] */
	uint32_t empty_word_br1_25;
	/* BR1_26 10'h068 [Unused] */
	uint32_t empty_word_br1_26;
	/* BR1_27 10'h06C [Unused] */
	uint32_t empty_word_br1_27;
	/* BR1_28 10'h070 [Unused] */
	uint32_t empty_word_br1_28;
	/* BR1_29 10'h074 [Unused] */
	uint32_t empty_word_br1_29;
	/* BR1_30 10'h078 [Unused] */
	uint32_t empty_word_br1_30;
	/* BR1_31 10'h07C [Unused] */
	uint32_t empty_word_br1_31;
	/* BR1_32 10'h080 [Unused] */
	uint32_t empty_word_br1_32;
	/* BR1_33 10'h084 [Unused] */
	uint32_t empty_word_br1_33;
	/* BR1_34 10'h088 [Unused] */
	uint32_t empty_word_br1_34;
	/* BR1_35 10'h08C [Unused] */
	uint32_t empty_word_br1_35;
	/* BR1_36 10'h090 [Unused] */
	uint32_t empty_word_br1_36;
	/* BR1_37 10'h094 [Unused] */
	uint32_t empty_word_br1_37;
	/* BR1_38 10'h098 [Unused] */
	uint32_t empty_word_br1_38;
	/* BR1_39 10'h09C [Unused] */
	uint32_t empty_word_br1_39;
	/* BR1_40 10'h0A0 */
	union {
		uint32_t br1_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_41 10'h0A4 */
	union {
		uint32_t br1_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_42 10'h0A8 */
	union {
		uint32_t br1_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_43 10'h0AC */
	union {
		uint32_t br1_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_44 10'h0B0 */
	union {
		uint32_t br1_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_45 10'h0B4 */
	union {
		uint32_t br1_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_46 10'h0B8 */
	union {
		uint32_t br1_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_47 10'h0BC */
	union {
		uint32_t br1_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_48 10'h0C0 */
	union {
		uint32_t br1_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_49 10'h0C4 */
	union {
		uint32_t br1_49; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_50 10'h0C8 */
	union {
		uint32_t br1_50; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_51 10'h0CC [Unused] */
	uint32_t empty_word_br1_51;
	/* BR1_52 10'h0D0 [Unused] */
	uint32_t empty_word_br1_52;
	/* BR1_53 10'h0D4 [Unused] */
	uint32_t empty_word_br1_53;
	/* BR1_54 10'h0D8 [Unused] */
	uint32_t empty_word_br1_54;
	/* BR1_55 10'h0DC [Unused] */
	uint32_t empty_word_br1_55;
	/* BR1_56 10'h0E0 [Unused] */
	uint32_t empty_word_br1_56;
	/* BR1_57 10'h0E4 [Unused] */
	uint32_t empty_word_br1_57;
	/* BR1_58 10'h0E8 [Unused] */
	uint32_t empty_word_br1_58;
	/* BR1_59 10'h0EC [Unused] */
	uint32_t empty_word_br1_59;
	/* BR1_60 10'h0F0 [Unused] */
	uint32_t empty_word_br1_60;
	/* BR1_61 10'h0F4 [Unused] */
	uint32_t empty_word_br1_61;
	/* BR1_62 10'h0F8 [Unused] */
	uint32_t empty_word_br1_62;
	/* BR1_63 10'h0FC [Unused] */
	uint32_t empty_word_br1_63;
	/* BR1_64 10'h100 [Unused] */
	uint32_t empty_word_br1_64;
	/* BR1_65 10'h104 [Unused] */
	uint32_t empty_word_br1_65;
	/* BR1_66 10'h108 [Unused] */
	uint32_t empty_word_br1_66;
	/* BR1_67 10'h10C [Unused] */
	uint32_t empty_word_br1_67;
	/* BR1_68 10'h110 [Unused] */
	uint32_t empty_word_br1_68;
	/* BR1_69 10'h114 [Unused] */
	uint32_t empty_word_br1_69;
	/* BR1_70 10'h118 [Unused] */
	uint32_t empty_word_br1_70;
	/* BR1_71 10'h11C [Unused] */
	uint32_t empty_word_br1_71;
	/* BR1_72 10'h120 [Unused] */
	uint32_t empty_word_br1_72;
	/* BR1_73 10'h124 [Unused] */
	uint32_t empty_word_br1_73;
	/* BR1_74 10'h128 [Unused] */
	uint32_t empty_word_br1_74;
	/* BR1_75 10'h12C [Unused] */
	uint32_t empty_word_br1_75;
	/* BR1_76 10'h130 [Unused] */
	uint32_t empty_word_br1_76;
	/* BR1_77 10'h134 [Unused] */
	uint32_t empty_word_br1_77;
	/* BR1_78 10'h138 [Unused] */
	uint32_t empty_word_br1_78;
	/* BR1_79 10'h13C [Unused] */
	uint32_t empty_word_br1_79;
	/* BR1_80 10'h140 [Unused] */
	uint32_t empty_word_br1_80;
	/* BR1_81 10'h144 [Unused] */
	uint32_t empty_word_br1_81;
} CsrBankSrcr;

#endif