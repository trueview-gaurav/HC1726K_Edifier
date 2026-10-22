#ifndef CSR_BANK_VENC_MVR_H_
#define CSR_BANK_VENC_MVR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from venc_mvr  ***/
typedef struct csr_bank_venc_mvr {
	/* SR124_00 10'h000 */
	union {
		uint32_t sr124_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_01 10'h004 */
	union {
		uint32_t sr124_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_02 10'h008 [Unused] */
	uint32_t empty_word_sr124_02;
	/* SR124_03 10'h00C [Unused] */
	uint32_t empty_word_sr124_03;
	/* SR124_04 10'h010 */
	union {
		uint32_t sr124_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SR124_05 10'h014 [Unused] */
	uint32_t empty_word_sr124_05;
	/* SR124_06 10'h018 [Unused] */
	uint32_t empty_word_sr124_06;
	/* SR124_07 10'h01C */
	union {
		uint32_t sr124_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_08 10'h020 */
	union {
		uint32_t sr124_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_09 10'h024 */
	union {
		uint32_t sr124_09; // word name
		struct {
			uint32_t height : 12;
			uint32_t : 4; // padding bits
			uint32_t width : 16;
		};
	};
	/* SR124_10 10'h028 [Unused] */
	uint32_t empty_word_sr124_10;
	/* SR124_11 10'h02C [Unused] */
	uint32_t empty_word_sr124_11;
	/* SR124_12 10'h030 */
	union {
		uint32_t sr124_12; // word name
		struct {
			uint32_t fifo_flush_len : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_13 10'h034 */
	union {
		uint32_t sr124_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_14 10'h038 */
	union {
		uint32_t sr124_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_15 10'h03C [Unused] */
	uint32_t empty_word_sr124_15;
	/* SR124_16 10'h040 */
	union {
		uint32_t sr124_16; // word name
		struct {
			uint32_t pixel_flush_len : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_17 10'h044 */
	union {
		uint32_t sr124_17; // word name
		struct {
			uint32_t flush_addr_skip : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_18 10'h048 */
	union {
		uint32_t sr124_18; // word name
		struct {
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_19 10'h04C */
	union {
		uint32_t sr124_19; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SR124_20 10'h050 [Unused] */
	uint32_t empty_word_sr124_20;
	/* SR124_21 10'h054 [Unused] */
	uint32_t empty_word_sr124_21;
	/* SR124_22 10'h058 [Unused] */
	uint32_t empty_word_sr124_22;
	/* SR124_23 10'h05C [Unused] */
	uint32_t empty_word_sr124_23;
	/* SR124_24 10'h060 [Unused] */
	uint32_t empty_word_sr124_24;
	/* SR124_25 10'h064 */
	union {
		uint32_t sr124_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR124_26 10'h068 [Unused] */
	uint32_t empty_word_sr124_26;
	/* SR124_27 10'h06C [Unused] */
	uint32_t empty_word_sr124_27;
	/* SR124_28 10'h070 [Unused] */
	uint32_t empty_word_sr124_28;
	/* SR124_29 10'h074 [Unused] */
	uint32_t empty_word_sr124_29;
	/* SR124_30 10'h078 [Unused] */
	uint32_t empty_word_sr124_30;
	/* SR124_31 10'h07C [Unused] */
	uint32_t empty_word_sr124_31;
	/* SR124_32 10'h080 [Unused] */
	uint32_t empty_word_sr124_32;
	/* SR124_33 10'h084 [Unused] */
	uint32_t empty_word_sr124_33;
	/* SR124_34 10'h088 [Unused] */
	uint32_t empty_word_sr124_34;
	/* SR124_35 10'h08C [Unused] */
	uint32_t empty_word_sr124_35;
	/* SR124_36 10'h090 [Unused] */
	uint32_t empty_word_sr124_36;
	/* SR124_37 10'h094 [Unused] */
	uint32_t empty_word_sr124_37;
	/* SR124_38 10'h098 [Unused] */
	uint32_t empty_word_sr124_38;
	/* SR124_39 10'h09C [Unused] */
	uint32_t empty_word_sr124_39;
	/* SR124_40 10'h0A0 */
	union {
		uint32_t sr124_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_41 10'h0A4 */
	union {
		uint32_t sr124_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_42 10'h0A8 */
	union {
		uint32_t sr124_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_43 10'h0AC */
	union {
		uint32_t sr124_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_44 10'h0B0 */
	union {
		uint32_t sr124_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_45 10'h0B4 */
	union {
		uint32_t sr124_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_46 10'h0B8 */
	union {
		uint32_t sr124_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_47 10'h0BC */
	union {
		uint32_t sr124_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR124_48 10'h0C0 */
	union {
		uint32_t sr124_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankVenc_mvr;

#endif