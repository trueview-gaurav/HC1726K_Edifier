/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_MV8R_H_
#define CSR_BANK_MV8R_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from mv8r  ***/
typedef struct csr_bank_mv8r {
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
	/* SR032_04 10'h010 */
	union {
		uint32_t sr032_04; // word name
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
	/* SR032_05 10'h014 */
	union {
		uint32_t sr032_05; // word name
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
	/* SR032_06 10'h018 [Unused] */
	uint32_t empty_word_sr032_06;
	/* SR032_07 10'h01C */
	union {
		uint32_t sr032_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_08 10'h020 */
	union {
		uint32_t sr032_08; // word name
		struct {
			uint32_t target_fifo_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_09 10'h024 */
	union {
		uint32_t sr032_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_10 10'h028 [Unused] */
	uint32_t empty_word_sr032_10;
	/* SR032_11 10'h02C [Unused] */
	uint32_t empty_word_sr032_11;
	/* SR032_12 10'h030 */
	union {
		uint32_t sr032_12; // word name
		struct {
			uint32_t fifo_flush_len : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_13 10'h034 [Unused] */
	uint32_t empty_word_sr032_13;
	/* SR032_14 10'h038 [Unused] */
	uint32_t empty_word_sr032_14;
	/* SR032_15 10'h03C [Unused] */
	uint32_t empty_word_sr032_15;
	/* SR032_16 10'h040 */
	union {
		uint32_t sr032_16; // word name
		struct {
			uint32_t pixel_flush_len : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_17 10'h044 */
	union {
		uint32_t sr032_17; // word name
		struct {
			uint32_t flush_addr_skip : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_18 10'h048 */
	union {
		uint32_t sr032_18; // word name
		struct {
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_19 10'h04C */
	union {
		uint32_t sr032_19; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SR032_20 10'h050 [Unused] */
	uint32_t empty_word_sr032_20;
	/* SR032_21 10'h054 [Unused] */
	uint32_t empty_word_sr032_21;
	/* SR032_22 10'h058 [Unused] */
	uint32_t empty_word_sr032_22;
	/* SR032_23 10'h05C [Unused] */
	uint32_t empty_word_sr032_23;
	/* SR032_24 10'h060 [Unused] */
	uint32_t empty_word_sr032_24;
	/* SR032_25 10'h064 */
	union {
		uint32_t sr032_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_26 10'h068 [Unused] */
	uint32_t empty_word_sr032_26;
	/* SR032_27 10'h06C [Unused] */
	uint32_t empty_word_sr032_27;
	/* SR032_28 10'h070 [Unused] */
	uint32_t empty_word_sr032_28;
	/* SR032_29 10'h074 [Unused] */
	uint32_t empty_word_sr032_29;
	/* SR032_30 10'h078 [Unused] */
	uint32_t empty_word_sr032_30;
	/* SR032_31 10'h07C [Unused] */
	uint32_t empty_word_sr032_31;
	/* SR032_32 10'h080 [Unused] */
	uint32_t empty_word_sr032_32;
	/* SR032_33 10'h084 [Unused] */
	uint32_t empty_word_sr032_33;
	/* SR032_34 10'h088 [Unused] */
	uint32_t empty_word_sr032_34;
	/* SR032_35 10'h08C [Unused] */
	uint32_t empty_word_sr032_35;
	/* SR032_36 10'h090 [Unused] */
	uint32_t empty_word_sr032_36;
	/* SR032_37 10'h094 [Unused] */
	uint32_t empty_word_sr032_37;
	/* SR032_38 10'h098 [Unused] */
	uint32_t empty_word_sr032_38;
	/* SR032_39 10'h09C [Unused] */
	uint32_t empty_word_sr032_39;
	/* SR032_40 10'h0A0 */
	union {
		uint32_t sr032_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_41 10'h0A4 */
	union {
		uint32_t sr032_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_42 10'h0A8 */
	union {
		uint32_t sr032_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_43 10'h0AC */
	union {
		uint32_t sr032_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_44 10'h0B0 */
	union {
		uint32_t sr032_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_45 10'h0B4 */
	union {
		uint32_t sr032_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_46 10'h0B8 */
	union {
		uint32_t sr032_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_47 10'h0BC */
	union {
		uint32_t sr032_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_48 10'h0C0 */
	union {
		uint32_t sr032_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR032_49 10'h0C4 */
	union {
		uint32_t sr032_49; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_50 10'h0C8 */
	union {
		uint32_t sr032_50; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR032_51 10'h0CC [Unused] */
	uint32_t empty_word_sr032_51;
	/* SR032_52 10'h0D0 [Unused] */
	uint32_t empty_word_sr032_52;
	/* SR032_53 10'h0D4 [Unused] */
	uint32_t empty_word_sr032_53;
	/* SR032_54 10'h0D8 [Unused] */
	uint32_t empty_word_sr032_54;
	/* SR032_55 10'h0DC [Unused] */
	uint32_t empty_word_sr032_55;
	/* SR032_56 10'h0E0 [Unused] */
	uint32_t empty_word_sr032_56;
	/* SR032_57 10'h0E4 [Unused] */
	uint32_t empty_word_sr032_57;
	/* SR032_58 10'h0E8 [Unused] */
	uint32_t empty_word_sr032_58;
	/* SR032_59 10'h0EC [Unused] */
	uint32_t empty_word_sr032_59;
	/* SR032_60 10'h0F0 [Unused] */
	uint32_t empty_word_sr032_60;
	/* SR032_61 10'h0F4 [Unused] */
	uint32_t empty_word_sr032_61;
	/* SR032_62 10'h0F8 [Unused] */
	uint32_t empty_word_sr032_62;
	/* SR032_63 10'h0FC [Unused] */
	uint32_t empty_word_sr032_63;
	/* SR032_64 10'h100 [Unused] */
	uint32_t empty_word_sr032_64;
	/* SR032_65 10'h104 [Unused] */
	uint32_t empty_word_sr032_65;
	/* SR032_66 10'h108 [Unused] */
	uint32_t empty_word_sr032_66;
	/* SR032_67 10'h10C [Unused] */
	uint32_t empty_word_sr032_67;
	/* SR032_68 10'h110 [Unused] */
	uint32_t empty_word_sr032_68;
	/* SR032_69 10'h114 [Unused] */
	uint32_t empty_word_sr032_69;
	/* SR032_70 10'h118 [Unused] */
	uint32_t empty_word_sr032_70;
	/* SR032_71 10'h11C [Unused] */
	uint32_t empty_word_sr032_71;
	/* SR032_72 10'h120 [Unused] */
	uint32_t empty_word_sr032_72;
	/* SR032_73 10'h124 [Unused] */
	uint32_t empty_word_sr032_73;
	/* SR032_74 10'h128 [Unused] */
	uint32_t empty_word_sr032_74;
	/* SR032_75 10'h12C [Unused] */
	uint32_t empty_word_sr032_75;
	/* SR032_76 10'h130 [Unused] */
	uint32_t empty_word_sr032_76;
	/* SR032_77 10'h134 [Unused] */
	uint32_t empty_word_sr032_77;
	/* SR032_78 10'h138 [Unused] */
	uint32_t empty_word_sr032_78;
	/* SR032_79 10'h13C [Unused] */
	uint32_t empty_word_sr032_79;
	/* SR032_80 10'h140 [Unused] */
	uint32_t empty_word_sr032_80;
	/* SR032_81 10'h144 [Unused] */
	uint32_t empty_word_sr032_81;
	/* SR032_82 10'h148 [Unused] */
	uint32_t empty_word_sr032_82;
	/* SR032_83 10'h14C [Unused] */
	uint32_t empty_word_sr032_83;
} CsrBankMv8r;

#endif