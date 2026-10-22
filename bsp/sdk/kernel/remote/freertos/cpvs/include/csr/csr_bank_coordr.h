#ifndef CSR_BANK_COORDR_H_
#define CSR_BANK_COORDR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from coordr  ***/
typedef struct csr_bank_coordr {
	/* SR064_00 10'h000 */
	union {
		uint32_t sr064_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_01 10'h004 */
	union {
		uint32_t sr064_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_02 10'h008 [Unused] */
	uint32_t empty_word_sr064_02;
	/* SR064_03 10'h00C [Unused] */
	uint32_t empty_word_sr064_03;
	/* SR064_04 10'h010 */
	union {
		uint32_t sr064_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SR064_05 10'h014 [Unused] */
	uint32_t empty_word_sr064_05;
	/* SR064_06 10'h018 [Unused] */
	uint32_t empty_word_sr064_06;
	/* SR064_07 10'h01C */
	union {
		uint32_t sr064_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_08 10'h020 */
	union {
		uint32_t sr064_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_09 10'h024 */
	union {
		uint32_t sr064_09; // word name
		struct {
			uint32_t height : 13;
			uint32_t : 3; // padding bits
			uint32_t width : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* SR064_10 10'h028 [Unused] */
	uint32_t empty_word_sr064_10;
	/* SR064_11 10'h02C [Unused] */
	uint32_t empty_word_sr064_11;
	/* SR064_12 10'h030 */
	union {
		uint32_t sr064_12; // word name
		struct {
			uint32_t fifo_flush_len : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_13 10'h034 */
	union {
		uint32_t sr064_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_14 10'h038 */
	union {
		uint32_t sr064_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_15 10'h03C [Unused] */
	uint32_t empty_word_sr064_15;
	/* SR064_16 10'h040 */
	union {
		uint32_t sr064_16; // word name
		struct {
			uint32_t pixel_flush_len : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_17 10'h044 */
	union {
		uint32_t sr064_17; // word name
		struct {
			uint32_t flush_addr_skip : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_18 10'h048 */
	union {
		uint32_t sr064_18; // word name
		struct {
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_19 10'h04C */
	union {
		uint32_t sr064_19; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SR064_20 10'h050 [Unused] */
	uint32_t empty_word_sr064_20;
	/* SR064_21 10'h054 [Unused] */
	uint32_t empty_word_sr064_21;
	/* SR064_22 10'h058 [Unused] */
	uint32_t empty_word_sr064_22;
	/* SR064_23 10'h05C [Unused] */
	uint32_t empty_word_sr064_23;
	/* SR064_24 10'h060 [Unused] */
	uint32_t empty_word_sr064_24;
	/* SR064_25 10'h064 */
	union {
		uint32_t sr064_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR064_26 10'h068 [Unused] */
	uint32_t empty_word_sr064_26;
	/* SR064_27 10'h06C [Unused] */
	uint32_t empty_word_sr064_27;
	/* SR064_28 10'h070 [Unused] */
	uint32_t empty_word_sr064_28;
	/* SR064_29 10'h074 [Unused] */
	uint32_t empty_word_sr064_29;
	/* SR064_30 10'h078 [Unused] */
	uint32_t empty_word_sr064_30;
	/* SR064_31 10'h07C [Unused] */
	uint32_t empty_word_sr064_31;
	/* SR064_32 10'h080 [Unused] */
	uint32_t empty_word_sr064_32;
	/* SR064_33 10'h084 [Unused] */
	uint32_t empty_word_sr064_33;
	/* SR064_34 10'h088 [Unused] */
	uint32_t empty_word_sr064_34;
	/* SR064_35 10'h08C [Unused] */
	uint32_t empty_word_sr064_35;
	/* SR064_36 10'h090 [Unused] */
	uint32_t empty_word_sr064_36;
	/* SR064_37 10'h094 [Unused] */
	uint32_t empty_word_sr064_37;
	/* SR064_38 10'h098 [Unused] */
	uint32_t empty_word_sr064_38;
	/* SR064_39 10'h09C [Unused] */
	uint32_t empty_word_sr064_39;
	/* SR064_40 10'h0A0 */
	union {
		uint32_t sr064_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_41 10'h0A4 */
	union {
		uint32_t sr064_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_42 10'h0A8 */
	union {
		uint32_t sr064_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_43 10'h0AC */
	union {
		uint32_t sr064_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_44 10'h0B0 */
	union {
		uint32_t sr064_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_45 10'h0B4 */
	union {
		uint32_t sr064_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_46 10'h0B8 */
	union {
		uint32_t sr064_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_47 10'h0BC */
	union {
		uint32_t sr064_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR064_48 10'h0C0 */
	union {
		uint32_t sr064_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCoordr;

#endif