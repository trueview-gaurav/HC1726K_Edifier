/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_MV8W_H_
#define CSR_BANK_MV8W_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from mv8w  ***/
typedef struct csr_bank_mv8w {
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
	/* SW032_04 10'h010 */
	union {
		uint32_t sw032_04; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_05 10'h014 */
	union {
		uint32_t sw032_05; // word name
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
	/* SW032_06 10'h018 [Unused] */
	uint32_t empty_word_sw032_06;
	/* SW032_07 10'h01C */
	union {
		uint32_t sw032_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_08 10'h020 */
	union {
		uint32_t sw032_08; // word name
		struct {
			uint32_t target_fifo_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_09 10'h024 */
	union {
		uint32_t sw032_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t width : 16;
		};
	};
	/* SW032_10 10'h028 [Unused] */
	uint32_t empty_word_sw032_10;
	/* SW032_11 10'h02C [Unused] */
	uint32_t empty_word_sw032_11;
	/* SW032_12 10'h030 */
	union {
		uint32_t sw032_12; // word name
		struct {
			uint32_t fifo_flush_len : 15;
			uint32_t : 1; // padding bits
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t fifo_end_phase : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SW032_13 10'h034 [Unused] */
	uint32_t empty_word_sw032_13;
	/* SW032_14 10'h038 [Unused] */
	uint32_t empty_word_sw032_14;
	/* SW032_15 10'h03C [Unused] */
	uint32_t empty_word_sw032_15;
	/* SW032_16 10'h040 */
	union {
		uint32_t sw032_16; // word name
		struct {
			uint32_t pixel_flush_len : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_17 10'h044 */
	union {
		uint32_t sw032_17; // word name
		struct {
			uint32_t flush_addr_skip : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_18 10'h048 */
	union {
		uint32_t sw032_18; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SW032_19 10'h04C [Unused] */
	uint32_t empty_word_sw032_19;
	/* SW032_20 10'h050 [Unused] */
	uint32_t empty_word_sw032_20;
	/* SW032_21 10'h054 [Unused] */
	uint32_t empty_word_sw032_21;
	/* SW032_22 10'h058 [Unused] */
	uint32_t empty_word_sw032_22;
	/* SW032_23 10'h05C [Unused] */
	uint32_t empty_word_sw032_23;
	/* SW032_24 10'h060 [Unused] */
	uint32_t empty_word_sw032_24;
	/* SW032_25 10'h064 */
	union {
		uint32_t sw032_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_26 10'h068 */
	union {
		uint32_t sw032_26; // word name
		struct {
			uint32_t v_start : 16;
			uint32_t v_end : 16;
		};
	};
	/* SW032_27 10'h06C */
	union {
		uint32_t sw032_27; // word name
		struct {
			uint32_t h_start : 16;
			uint32_t h_end : 16;
		};
	};
	/* SW032_28 10'h070 [Unused] */
	uint32_t empty_word_sw032_28;
	/* SW032_29 10'h074 [Unused] */
	uint32_t empty_word_sw032_29;
	/* SW032_30 10'h078 [Unused] */
	uint32_t empty_word_sw032_30;
	/* SW032_31 10'h07C [Unused] */
	uint32_t empty_word_sw032_31;
	/* SW032_32 10'h080 [Unused] */
	uint32_t empty_word_sw032_32;
	/* SW032_33 10'h084 [Unused] */
	uint32_t empty_word_sw032_33;
	/* SW032_34 10'h088 [Unused] */
	uint32_t empty_word_sw032_34;
	/* SW032_35 10'h08C [Unused] */
	uint32_t empty_word_sw032_35;
	/* SW032_36 10'h090 [Unused] */
	uint32_t empty_word_sw032_36;
	/* SW032_37 10'h094 [Unused] */
	uint32_t empty_word_sw032_37;
	/* SW032_38 10'h098 [Unused] */
	uint32_t empty_word_sw032_38;
	/* SW032_39 10'h09C [Unused] */
	uint32_t empty_word_sw032_39;
	/* SW032_40 10'h0A0 */
	union {
		uint32_t sw032_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_41 10'h0A4 */
	union {
		uint32_t sw032_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_42 10'h0A8 */
	union {
		uint32_t sw032_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_43 10'h0AC */
	union {
		uint32_t sw032_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_44 10'h0B0 */
	union {
		uint32_t sw032_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_45 10'h0B4 */
	union {
		uint32_t sw032_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_46 10'h0B8 */
	union {
		uint32_t sw032_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_47 10'h0BC */
	union {
		uint32_t sw032_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_48 10'h0C0 */
	union {
		uint32_t sw032_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW032_49 10'h0C4 */
	union {
		uint32_t sw032_49; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_50 10'h0C8 */
	union {
		uint32_t sw032_50; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW032_51 10'h0CC [Unused] */
	uint32_t empty_word_sw032_51;
	/* SW032_52 10'h0D0 [Unused] */
	uint32_t empty_word_sw032_52;
	/* SW032_53 10'h0D4 [Unused] */
	uint32_t empty_word_sw032_53;
	/* SW032_54 10'h0D8 [Unused] */
	uint32_t empty_word_sw032_54;
	/* SW032_55 10'h0DC [Unused] */
	uint32_t empty_word_sw032_55;
	/* SW032_56 10'h0E0 [Unused] */
	uint32_t empty_word_sw032_56;
	/* SW032_57 10'h0E4 [Unused] */
	uint32_t empty_word_sw032_57;
	/* SW032_58 10'h0E8 [Unused] */
	uint32_t empty_word_sw032_58;
	/* SW032_59 10'h0EC [Unused] */
	uint32_t empty_word_sw032_59;
	/* SW032_60 10'h0F0 [Unused] */
	uint32_t empty_word_sw032_60;
	/* SW032_61 10'h0F4 [Unused] */
	uint32_t empty_word_sw032_61;
	/* SW032_62 10'h0F8 [Unused] */
	uint32_t empty_word_sw032_62;
	/* SW032_63 10'h0FC [Unused] */
	uint32_t empty_word_sw032_63;
	/* SW032_64 10'h100 [Unused] */
	uint32_t empty_word_sw032_64;
	/* SW032_65 10'h104 [Unused] */
	uint32_t empty_word_sw032_65;
	/* SW032_66 10'h108 [Unused] */
	uint32_t empty_word_sw032_66;
	/* SW032_67 10'h10C [Unused] */
	uint32_t empty_word_sw032_67;
	/* SW032_68 10'h110 [Unused] */
	uint32_t empty_word_sw032_68;
} CsrBankMv8w;

#endif