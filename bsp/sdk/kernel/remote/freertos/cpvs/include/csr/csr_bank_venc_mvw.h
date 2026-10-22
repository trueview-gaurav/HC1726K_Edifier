#ifndef CSR_BANK_VENC_MVW_H_
#define CSR_BANK_VENC_MVW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from venc_mvw  ***/
typedef struct csr_bank_venc_mvw {
	/* SW132_00 10'h000 */
	union {
		uint32_t sw132_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_01 10'h004 */
	union {
		uint32_t sw132_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_02 10'h008 [Unused] */
	uint32_t empty_word_sw132_02;
	/* SW132_03 10'h00C [Unused] */
	uint32_t empty_word_sw132_03;
	/* SW132_04 10'h010 */
	union {
		uint32_t sw132_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SW132_05 10'h014 [Unused] */
	uint32_t empty_word_sw132_05;
	/* SW132_06 10'h018 [Unused] */
	uint32_t empty_word_sw132_06;
	/* SW132_07 10'h01C */
	union {
		uint32_t sw132_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_08 10'h020 */
	union {
		uint32_t sw132_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_09 10'h024 */
	union {
		uint32_t sw132_09; // word name
		struct {
			uint32_t height : 12;
			uint32_t : 4; // padding bits
			uint32_t width : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* SW132_10 10'h028 [Unused] */
	uint32_t empty_word_sw132_10;
	/* SW132_11 10'h02C [Unused] */
	uint32_t empty_word_sw132_11;
	/* SW132_12 10'h030 */
	union {
		uint32_t sw132_12; // word name
		struct {
			uint32_t fifo_flush_len : 13;
			uint32_t : 3; // padding bits
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t fifo_end_phase : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SW132_13 10'h034 */
	union {
		uint32_t sw132_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_14 10'h038 */
	union {
		uint32_t sw132_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_15 10'h03C [Unused] */
	uint32_t empty_word_sw132_15;
	/* SW132_16 10'h040 */
	union {
		uint32_t sw132_16; // word name
		struct {
			uint32_t pixel_flush_len : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_17 10'h044 */
	union {
		uint32_t sw132_17; // word name
		struct {
			uint32_t flush_addr_skip : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_18 10'h048 */
	union {
		uint32_t sw132_18; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SW132_19 10'h04C [Unused] */
	uint32_t empty_word_sw132_19;
	/* SW132_20 10'h050 [Unused] */
	uint32_t empty_word_sw132_20;
	/* SW132_21 10'h054 [Unused] */
	uint32_t empty_word_sw132_21;
	/* SW132_22 10'h058 [Unused] */
	uint32_t empty_word_sw132_22;
	/* SW132_23 10'h05C [Unused] */
	uint32_t empty_word_sw132_23;
	/* SW132_24 10'h060 [Unused] */
	uint32_t empty_word_sw132_24;
	/* SW132_25 10'h064 */
	union {
		uint32_t sw132_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SW132_26 10'h068 */
	union {
		uint32_t sw132_26; // word name
		struct {
			uint32_t v_start : 12;
			uint32_t : 4; // padding bits
			uint32_t v_end : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_27 10'h06C */
	union {
		uint32_t sw132_27; // word name
		struct {
			uint32_t h_start : 14;
			uint32_t : 2; // padding bits
			uint32_t h_end : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* SW132_28 10'h070 [Unused] */
	uint32_t empty_word_sw132_28;
	/* SW132_29 10'h074 [Unused] */
	uint32_t empty_word_sw132_29;
	/* SW132_30 10'h078 [Unused] */
	uint32_t empty_word_sw132_30;
	/* SW132_31 10'h07C [Unused] */
	uint32_t empty_word_sw132_31;
	/* SW132_32 10'h080 [Unused] */
	uint32_t empty_word_sw132_32;
	/* SW132_33 10'h084 [Unused] */
	uint32_t empty_word_sw132_33;
	/* SW132_34 10'h088 [Unused] */
	uint32_t empty_word_sw132_34;
	/* SW132_35 10'h08C [Unused] */
	uint32_t empty_word_sw132_35;
	/* SW132_36 10'h090 [Unused] */
	uint32_t empty_word_sw132_36;
	/* SW132_37 10'h094 [Unused] */
	uint32_t empty_word_sw132_37;
	/* SW132_38 10'h098 [Unused] */
	uint32_t empty_word_sw132_38;
	/* SW132_39 10'h09C [Unused] */
	uint32_t empty_word_sw132_39;
	/* SW132_40 10'h0A0 */
	union {
		uint32_t sw132_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_41 10'h0A4 */
	union {
		uint32_t sw132_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_42 10'h0A8 */
	union {
		uint32_t sw132_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_43 10'h0AC */
	union {
		uint32_t sw132_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_44 10'h0B0 */
	union {
		uint32_t sw132_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_45 10'h0B4 */
	union {
		uint32_t sw132_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_46 10'h0B8 */
	union {
		uint32_t sw132_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_47 10'h0BC */
	union {
		uint32_t sw132_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SW132_48 10'h0C0 */
	union {
		uint32_t sw132_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankVenc_mvw;

#endif