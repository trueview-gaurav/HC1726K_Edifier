#ifndef CSR_BANK_WEIGHTR_H_
#define CSR_BANK_WEIGHTR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from weightr  ***/
typedef struct csr_bank_weightr {
	/* SR008_00 10'h000 */
	union {
		uint32_t sr008_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_01 10'h004 */
	union {
		uint32_t sr008_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR008_02 10'h008 [Unused] */
	uint32_t empty_word_sr008_02;
	/* SR008_03 10'h00C [Unused] */
	uint32_t empty_word_sr008_03;
	/* SR008_04 10'h010 */
	union {
		uint32_t sr008_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SR008_05 10'h014 [Unused] */
	uint32_t empty_word_sr008_05;
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
			uint32_t width : 13;
			uint32_t : 3; // padding bits
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
	/* SR008_13 10'h034 */
	union {
		uint32_t sr008_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR008_14 10'h038 */
	union {
		uint32_t sr008_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
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
} CsrBankWeightr;

#endif