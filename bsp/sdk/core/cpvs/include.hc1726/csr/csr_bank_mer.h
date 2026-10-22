/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_MER_H_
#define CSR_BANK_MER_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from mer  ***/
typedef struct csr_bank_mer {
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
	/* BR0_04 10'h010 */
	union {
		uint32_t br0_04; // word name
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
	/* BR0_05 10'h014 */
	union {
		uint32_t br0_05; // word name
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
	/* BR0_06 10'h018 [Unused] */
	uint32_t empty_word_br0_06;
	/* BR0_07 10'h01C */
	union {
		uint32_t br0_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_08 10'h020 */
	union {
		uint32_t br0_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* BR0_09 10'h024 */
	union {
		uint32_t br0_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t width : 16;
		};
	};
	/* BR0_10 10'h028 */
	union {
		uint32_t br0_10; // word name
		struct {
			uint32_t y_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t msb_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_11 10'h02C [Unused] */
	uint32_t empty_word_br0_11;
	/* BR0_12 10'h030 */
	union {
		uint32_t br0_12; // word name
		struct {
			uint32_t fifo_flush_len : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_13 10'h034 [Unused] */
	uint32_t empty_word_br0_13;
	/* BR0_14 10'h038 [Unused] */
	uint32_t empty_word_br0_14;
	/* BR0_15 10'h03C [Unused] */
	uint32_t empty_word_br0_15;
	/* BR0_16 10'h040 */
	union {
		uint32_t br0_16; // word name
		struct {
			uint32_t pixel_flush_len : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_17 10'h044 [Unused] */
	uint32_t empty_word_br0_17;
	/* BR0_18 10'h048 [Unused] */
	uint32_t empty_word_br0_18;
	/* BR0_19 10'h04C */
	union {
		uint32_t br0_19; // word name
		struct {
			uint32_t flush_addr_skip : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_20 10'h050 */
	union {
		uint32_t br0_20; // word name
		struct {
			uint32_t lsb_append_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_21 10'h054 */
	union {
		uint32_t br0_21; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* BR0_22 10'h058 [Unused] */
	uint32_t empty_word_br0_22;
	/* BR0_23 10'h05C [Unused] */
	uint32_t empty_word_br0_23;
	/* BR0_24 10'h060 [Unused] */
	uint32_t empty_word_br0_24;
	/* BR0_25 10'h064 */
	union {
		uint32_t br0_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_26 10'h068 [Unused] */
	uint32_t empty_word_br0_26;
	/* BR0_27 10'h06C [Unused] */
	uint32_t empty_word_br0_27;
	/* BR0_28 10'h070 [Unused] */
	uint32_t empty_word_br0_28;
	/* BR0_29 10'h074 [Unused] */
	uint32_t empty_word_br0_29;
	/* BR0_30 10'h078 [Unused] */
	uint32_t empty_word_br0_30;
	/* BR0_31 10'h07C [Unused] */
	uint32_t empty_word_br0_31;
	/* BR0_32 10'h080 [Unused] */
	uint32_t empty_word_br0_32;
	/* BR0_33 10'h084 [Unused] */
	uint32_t empty_word_br0_33;
	/* BR0_34 10'h088 [Unused] */
	uint32_t empty_word_br0_34;
	/* BR0_35 10'h08C [Unused] */
	uint32_t empty_word_br0_35;
	/* BR0_36 10'h090 [Unused] */
	uint32_t empty_word_br0_36;
	/* BR0_37 10'h094 [Unused] */
	uint32_t empty_word_br0_37;
	/* BR0_38 10'h098 [Unused] */
	uint32_t empty_word_br0_38;
	/* BR0_39 10'h09C [Unused] */
	uint32_t empty_word_br0_39;
	/* BR0_40 10'h0A0 */
	union {
		uint32_t br0_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_41 10'h0A4 */
	union {
		uint32_t br0_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_42 10'h0A8 */
	union {
		uint32_t br0_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_43 10'h0AC */
	union {
		uint32_t br0_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_44 10'h0B0 */
	union {
		uint32_t br0_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_45 10'h0B4 */
	union {
		uint32_t br0_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_46 10'h0B8 */
	union {
		uint32_t br0_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_47 10'h0BC */
	union {
		uint32_t br0_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_48 10'h0C0 */
	union {
		uint32_t br0_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR0_49 10'h0C4 */
	union {
		uint32_t br0_49; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_50 10'h0C8 */
	union {
		uint32_t br0_50; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR0_51 10'h0CC [Unused] */
	uint32_t empty_word_br0_51;
	/* BR0_52 10'h0D0 [Unused] */
	uint32_t empty_word_br0_52;
	/* BR0_53 10'h0D4 [Unused] */
	uint32_t empty_word_br0_53;
	/* BR0_54 10'h0D8 [Unused] */
	uint32_t empty_word_br0_54;
	/* BR0_55 10'h0DC [Unused] */
	uint32_t empty_word_br0_55;
	/* BR0_56 10'h0E0 [Unused] */
	uint32_t empty_word_br0_56;
	/* BR0_57 10'h0E4 [Unused] */
	uint32_t empty_word_br0_57;
	/* BR0_58 10'h0E8 [Unused] */
	uint32_t empty_word_br0_58;
	/* BR0_59 10'h0EC [Unused] */
	uint32_t empty_word_br0_59;
	/* BR0_60 10'h0F0 [Unused] */
	uint32_t empty_word_br0_60;
	/* BR0_61 10'h0F4 [Unused] */
	uint32_t empty_word_br0_61;
	/* BR0_62 10'h0F8 [Unused] */
	uint32_t empty_word_br0_62;
	/* BR0_63 10'h0FC [Unused] */
	uint32_t empty_word_br0_63;
	/* BR0_64 10'h100 [Unused] */
	uint32_t empty_word_br0_64;
	/* BR0_65 10'h104 [Unused] */
	uint32_t empty_word_br0_65;
	/* BR0_66 10'h108 [Unused] */
	uint32_t empty_word_br0_66;
	/* BR0_67 10'h10C [Unused] */
	uint32_t empty_word_br0_67;
	/* BR0_68 10'h110 [Unused] */
	uint32_t empty_word_br0_68;
	/* BR0_69 10'h114 [Unused] */
	uint32_t empty_word_br0_69;
	/* BR0_70 10'h118 [Unused] */
	uint32_t empty_word_br0_70;
	/* BR0_71 10'h11C [Unused] */
	uint32_t empty_word_br0_71;
	/* BR0_72 10'h120 [Unused] */
	uint32_t empty_word_br0_72;
	/* BR0_73 10'h124 [Unused] */
	uint32_t empty_word_br0_73;
	/* BR0_74 10'h128 [Unused] */
	uint32_t empty_word_br0_74;
	/* BR0_75 10'h12C [Unused] */
	uint32_t empty_word_br0_75;
	/* BR0_76 10'h130 [Unused] */
	uint32_t empty_word_br0_76;
	/* BR0_77 10'h134 [Unused] */
	uint32_t empty_word_br0_77;
	/* BR0_78 10'h138 [Unused] */
	uint32_t empty_word_br0_78;
	/* BR0_79 10'h13C [Unused] */
	uint32_t empty_word_br0_79;
	/* BR0_80 10'h140 [Unused] */
	uint32_t empty_word_br0_80;
	/* BR0_81 10'h144 [Unused] */
	uint32_t empty_word_br0_81;
	/* BR0_82 10'h148 [Unused] */
	uint32_t empty_word_br0_82;
	/* BR0_83 10'h14C [Unused] */
	uint32_t empty_word_br0_83;
} CsrBankMer;

#endif