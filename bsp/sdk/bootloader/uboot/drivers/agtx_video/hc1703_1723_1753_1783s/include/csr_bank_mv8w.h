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
	/* SW024_00 10'h000 */
	union {
		uint32_t sw024_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_01 10'h004 */
	union {
		uint32_t sw024_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_02 10'h008 [Unused] */
	uint32_t empty_word_sw024_02;
	/* SW024_03 10'h00C [Unused] */
	uint32_t empty_word_sw024_03;
	/* SW024_04 10'h010 */
	union {
		uint32_t sw024_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SW024_05 10'h014 [Unused] */
	uint32_t empty_word_sw024_05;
	/* SW024_06 10'h018 [Unused] */
	uint32_t empty_word_sw024_06;
	/* SW024_07 10'h01C */
	union {
		uint32_t sw024_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_08 10'h020 */
	union {
		uint32_t sw024_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_09 10'h024 */
	union {
		uint32_t sw024_09; // word name
		struct {
			uint32_t height : 13;
			uint32_t : 3; // padding bits
			uint32_t width : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* SW024_10 10'h028 [Unused] */
	uint32_t empty_word_sw024_10;
	/* SW024_11 10'h02C [Unused] */
	uint32_t empty_word_sw024_11;
	/* SW024_12 10'h030 */
	union {
		uint32_t sw024_12; // word name
		struct {
			uint32_t fifo_flush_len : 12;
			uint32_t : 4; // padding bits
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t fifo_end_phase : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SW024_13 10'h034 */
	union {
		uint32_t sw024_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_14 10'h038 */
	union {
		uint32_t sw024_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_15 10'h03C [Unused] */
	uint32_t empty_word_sw024_15;
	/* SW024_16 10'h040 */
	union {
		uint32_t sw024_16; // word name
		struct {
			uint32_t pixel_flush_len : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_17 10'h044 */
	union {
		uint32_t sw024_17; // word name
		struct {
			uint32_t flush_addr_skip : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_18 10'h048 */
	union {
		uint32_t sw024_18; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SW024_19 10'h04C [Unused] */
	uint32_t empty_word_sw024_19;
	/* SW024_20 10'h050 [Unused] */
	uint32_t empty_word_sw024_20;
	/* SW024_21 10'h054 [Unused] */
	uint32_t empty_word_sw024_21;
	/* SW024_22 10'h058 [Unused] */
	uint32_t empty_word_sw024_22;
	/* SW024_23 10'h05C [Unused] */
	uint32_t empty_word_sw024_23;
	/* SW024_24 10'h060 [Unused] */
	uint32_t empty_word_sw024_24;
	/* SW024_25 10'h064 */
	union {
		uint32_t sw024_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW024_26 10'h068 */
	union {
		uint32_t sw024_26; // word name
		struct {
			uint32_t v_start : 13;
			uint32_t : 3; // padding bits
			uint32_t v_end : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* SW024_27 10'h06C */
	union {
		uint32_t sw024_27; // word name
		struct {
			uint32_t h_start : 13;
			uint32_t : 3; // padding bits
			uint32_t h_end : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* SW024_28 10'h070 [Unused] */
	uint32_t empty_word_sw024_28;
	/* SW024_29 10'h074 [Unused] */
	uint32_t empty_word_sw024_29;
	/* SW024_30 10'h078 [Unused] */
	uint32_t empty_word_sw024_30;
	/* SW024_31 10'h07C [Unused] */
	uint32_t empty_word_sw024_31;
	/* SW024_32 10'h080 [Unused] */
	uint32_t empty_word_sw024_32;
	/* SW024_33 10'h084 [Unused] */
	uint32_t empty_word_sw024_33;
	/* SW024_34 10'h088 [Unused] */
	uint32_t empty_word_sw024_34;
	/* SW024_35 10'h08C [Unused] */
	uint32_t empty_word_sw024_35;
	/* SW024_36 10'h090 [Unused] */
	uint32_t empty_word_sw024_36;
	/* SW024_37 10'h094 [Unused] */
	uint32_t empty_word_sw024_37;
	/* SW024_38 10'h098 [Unused] */
	uint32_t empty_word_sw024_38;
	/* SW024_39 10'h09C [Unused] */
	uint32_t empty_word_sw024_39;
	/* SW024_40 10'h0A0 */
	union {
		uint32_t sw024_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_41 10'h0A4 */
	union {
		uint32_t sw024_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_42 10'h0A8 */
	union {
		uint32_t sw024_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_43 10'h0AC */
	union {
		uint32_t sw024_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_44 10'h0B0 */
	union {
		uint32_t sw024_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_45 10'h0B4 */
	union {
		uint32_t sw024_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_46 10'h0B8 */
	union {
		uint32_t sw024_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_47 10'h0BC */
	union {
		uint32_t sw024_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW024_48 10'h0C0 */
	union {
		uint32_t sw024_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankMv8w;

#endif