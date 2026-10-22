/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_WEIGHTR_H_
#define CSR_BANK_WEIGHTR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from weightr  ***/
typedef struct csr_bank_weightr {
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
	/* SR008_04 10'h010 */
	union {
		uint32_t sr008_04; // word name
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
	/* SR008_05 10'h014 */
	union {
		uint32_t sr008_05; // word name
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
	/* SR008_06 10'h018 [Unused] */
	uint32_t empty_word_sr008_06;
	/* SR008_07 10'h01C */
	union {
		uint32_t sr008_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_08 10'h020 */
	union {
		uint32_t sr008_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_09 10'h024 */
	union {
		uint32_t sr008_09; // word name
		struct {
			uint32_t height : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_10 10'h028 [Unused] */
	uint32_t empty_word_sr008_10;
	/* SR008_11 10'h02C [Unused] */
	uint32_t empty_word_sr008_11;
	/* SR008_12 10'h030 */
	union {
		uint32_t sr008_12; // word name
		struct {
			uint32_t fifo_flush_len : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_13 10'h034 [Unused] */
	uint32_t empty_word_sr008_13;
	/* SR008_14 10'h038 [Unused] */
	uint32_t empty_word_sr008_14;
	/* SR008_15 10'h03C [Unused] */
	uint32_t empty_word_sr008_15;
	/* SR008_16 10'h040 */
	union {
		uint32_t sr008_16; // word name
		struct {
			uint32_t pixel_flush_len : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_17 10'h044 */
	union {
		uint32_t sr008_17; // word name
		struct {
			uint32_t flush_addr_skip : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_18 10'h048 */
	union {
		uint32_t sr008_18; // word name
		struct {
			uint32_t fifo_start_phase : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_19 10'h04C */
	union {
		uint32_t sr008_19; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SR008_20 10'h050 [Unused] */
	uint32_t empty_word_sr008_20;
	/* SR008_21 10'h054 [Unused] */
	uint32_t empty_word_sr008_21;
	/* SR008_22 10'h058 [Unused] */
	uint32_t empty_word_sr008_22;
	/* SR008_23 10'h05C [Unused] */
	uint32_t empty_word_sr008_23;
	/* SR008_24 10'h060 [Unused] */
	uint32_t empty_word_sr008_24;
	/* SR008_25 10'h064 */
	union {
		uint32_t sr008_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_26 10'h068 [Unused] */
	uint32_t empty_word_sr008_26;
	/* SR008_27 10'h06C [Unused] */
	uint32_t empty_word_sr008_27;
	/* SR008_28 10'h070 [Unused] */
	uint32_t empty_word_sr008_28;
	/* SR008_29 10'h074 [Unused] */
	uint32_t empty_word_sr008_29;
	/* SR008_30 10'h078 [Unused] */
	uint32_t empty_word_sr008_30;
	/* SR008_31 10'h07C [Unused] */
	uint32_t empty_word_sr008_31;
	/* SR008_32 10'h080 [Unused] */
	uint32_t empty_word_sr008_32;
	/* SR008_33 10'h084 [Unused] */
	uint32_t empty_word_sr008_33;
	/* SR008_34 10'h088 [Unused] */
	uint32_t empty_word_sr008_34;
	/* SR008_35 10'h08C [Unused] */
	uint32_t empty_word_sr008_35;
	/* SR008_36 10'h090 [Unused] */
	uint32_t empty_word_sr008_36;
	/* SR008_37 10'h094 [Unused] */
	uint32_t empty_word_sr008_37;
	/* SR008_38 10'h098 [Unused] */
	uint32_t empty_word_sr008_38;
	/* SR008_39 10'h09C [Unused] */
	uint32_t empty_word_sr008_39;
	/* SR008_40 10'h0A0 */
	union {
		uint32_t sr008_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_41 10'h0A4 */
	union {
		uint32_t sr008_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_42 10'h0A8 */
	union {
		uint32_t sr008_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_43 10'h0AC */
	union {
		uint32_t sr008_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_44 10'h0B0 */
	union {
		uint32_t sr008_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_45 10'h0B4 */
	union {
		uint32_t sr008_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_46 10'h0B8 */
	union {
		uint32_t sr008_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_47 10'h0BC */
	union {
		uint32_t sr008_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_48 10'h0C0 */
	union {
		uint32_t sr008_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_49 10'h0C4 */
	union {
		uint32_t sr008_49; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_50 10'h0C8 */
	union {
		uint32_t sr008_50; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_51 10'h0CC [Unused] */
	uint32_t empty_word_sr008_51;
	/* SR008_52 10'h0D0 [Unused] */
	uint32_t empty_word_sr008_52;
	/* SR008_53 10'h0D4 [Unused] */
	uint32_t empty_word_sr008_53;
	/* SR008_54 10'h0D8 [Unused] */
	uint32_t empty_word_sr008_54;
	/* SR008_55 10'h0DC [Unused] */
	uint32_t empty_word_sr008_55;
	/* SR008_56 10'h0E0 [Unused] */
	uint32_t empty_word_sr008_56;
	/* SR008_57 10'h0E4 [Unused] */
	uint32_t empty_word_sr008_57;
	/* SR008_58 10'h0E8 [Unused] */
	uint32_t empty_word_sr008_58;
	/* SR008_59 10'h0EC [Unused] */
	uint32_t empty_word_sr008_59;
	/* SR008_60 10'h0F0 [Unused] */
	uint32_t empty_word_sr008_60;
	/* SR008_61 10'h0F4 [Unused] */
	uint32_t empty_word_sr008_61;
	/* SR008_62 10'h0F8 [Unused] */
	uint32_t empty_word_sr008_62;
	/* SR008_63 10'h0FC [Unused] */
	uint32_t empty_word_sr008_63;
	/* SR008_64 10'h100 [Unused] */
	uint32_t empty_word_sr008_64;
	/* SR008_65 10'h104 [Unused] */
	uint32_t empty_word_sr008_65;
	/* SR008_66 10'h108 [Unused] */
	uint32_t empty_word_sr008_66;
	/* SR008_67 10'h10C [Unused] */
	uint32_t empty_word_sr008_67;
	/* SR008_68 10'h110 [Unused] */
	uint32_t empty_word_sr008_68;
	/* SR008_69 10'h114 [Unused] */
	uint32_t empty_word_sr008_69;
	/* SR008_70 10'h118 [Unused] */
	uint32_t empty_word_sr008_70;
	/* SR008_71 10'h11C [Unused] */
	uint32_t empty_word_sr008_71;
	/* SR008_72 10'h120 [Unused] */
	uint32_t empty_word_sr008_72;
	/* SR008_73 10'h124 [Unused] */
	uint32_t empty_word_sr008_73;
	/* SR008_74 10'h128 [Unused] */
	uint32_t empty_word_sr008_74;
	/* SR008_75 10'h12C [Unused] */
	uint32_t empty_word_sr008_75;
	/* SR008_76 10'h130 [Unused] */
	uint32_t empty_word_sr008_76;
	/* SR008_77 10'h134 [Unused] */
	uint32_t empty_word_sr008_77;
	/* SR008_78 10'h138 [Unused] */
	uint32_t empty_word_sr008_78;
	/* SR008_79 10'h13C [Unused] */
	uint32_t empty_word_sr008_79;
	/* SR008_80 10'h140 [Unused] */
	uint32_t empty_word_sr008_80;
	/* SR008_81 10'h144 [Unused] */
	uint32_t empty_word_sr008_81;
	/* SR008_82 10'h148 [Unused] */
	uint32_t empty_word_sr008_82;
	/* SR008_83 10'h14C [Unused] */
	uint32_t empty_word_sr008_83;
} CsrBankWeightr;

#endif