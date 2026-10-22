#ifndef CSR_BANK_MV8R_H_
#define CSR_BANK_MV8R_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from mv8r  ***/
typedef struct csr_bank_mv8r {
	/* SR024_00 10'h000 */
	union {
		uint32_t sr024_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_01 10'h004 */
	union {
		uint32_t sr024_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_02 10'h008 [Unused] */
	uint32_t empty_word_sr024_02;
	/* SR024_03 10'h00C [Unused] */
	uint32_t empty_word_sr024_03;
	/* SR024_04 10'h010 */
	union {
		uint32_t sr024_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SR024_05 10'h014 [Unused] */
	uint32_t empty_word_sr024_05;
	/* SR024_06 10'h018 [Unused] */
	uint32_t empty_word_sr024_06;
	/* SR024_07 10'h01C */
	union {
		uint32_t sr024_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_08 10'h020 */
	union {
		uint32_t sr024_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_09 10'h024 */
	union {
		uint32_t sr024_09; // word name
		struct {
			uint32_t height : 13;
			uint32_t : 3; // padding bits
			uint32_t width : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* SR024_10 10'h028 [Unused] */
	uint32_t empty_word_sr024_10;
	/* SR024_11 10'h02C [Unused] */
	uint32_t empty_word_sr024_11;
	/* SR024_12 10'h030 */
	union {
		uint32_t sr024_12; // word name
		struct {
			uint32_t fifo_flush_len : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_13 10'h034 */
	union {
		uint32_t sr024_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_14 10'h038 */
	union {
		uint32_t sr024_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_15 10'h03C [Unused] */
	uint32_t empty_word_sr024_15;
	/* SR024_16 10'h040 */
	union {
		uint32_t sr024_16; // word name
		struct {
			uint32_t pixel_flush_len : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_17 10'h044 */
	union {
		uint32_t sr024_17; // word name
		struct {
			uint32_t flush_addr_skip : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_18 10'h048 */
	union {
		uint32_t sr024_18; // word name
		struct {
			uint32_t fifo_start_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_19 10'h04C */
	union {
		uint32_t sr024_19; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* SR024_20 10'h050 [Unused] */
	uint32_t empty_word_sr024_20;
	/* SR024_21 10'h054 [Unused] */
	uint32_t empty_word_sr024_21;
	/* SR024_22 10'h058 [Unused] */
	uint32_t empty_word_sr024_22;
	/* SR024_23 10'h05C [Unused] */
	uint32_t empty_word_sr024_23;
	/* SR024_24 10'h060 [Unused] */
	uint32_t empty_word_sr024_24;
	/* SR024_25 10'h064 */
	union {
		uint32_t sr024_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SR024_26 10'h068 [Unused] */
	uint32_t empty_word_sr024_26;
	/* SR024_27 10'h06C [Unused] */
	uint32_t empty_word_sr024_27;
	/* SR024_28 10'h070 [Unused] */
	uint32_t empty_word_sr024_28;
	/* SR024_29 10'h074 [Unused] */
	uint32_t empty_word_sr024_29;
	/* SR024_30 10'h078 [Unused] */
	uint32_t empty_word_sr024_30;
	/* SR024_31 10'h07C [Unused] */
	uint32_t empty_word_sr024_31;
	/* SR024_32 10'h080 [Unused] */
	uint32_t empty_word_sr024_32;
	/* SR024_33 10'h084 [Unused] */
	uint32_t empty_word_sr024_33;
	/* SR024_34 10'h088 [Unused] */
	uint32_t empty_word_sr024_34;
	/* SR024_35 10'h08C [Unused] */
	uint32_t empty_word_sr024_35;
	/* SR024_36 10'h090 [Unused] */
	uint32_t empty_word_sr024_36;
	/* SR024_37 10'h094 [Unused] */
	uint32_t empty_word_sr024_37;
	/* SR024_38 10'h098 [Unused] */
	uint32_t empty_word_sr024_38;
	/* SR024_39 10'h09C [Unused] */
	uint32_t empty_word_sr024_39;
	/* SR024_40 10'h0A0 */
	union {
		uint32_t sr024_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_41 10'h0A4 */
	union {
		uint32_t sr024_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_42 10'h0A8 */
	union {
		uint32_t sr024_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_43 10'h0AC */
	union {
		uint32_t sr024_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_44 10'h0B0 */
	union {
		uint32_t sr024_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_45 10'h0B4 */
	union {
		uint32_t sr024_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_46 10'h0B8 */
	union {
		uint32_t sr024_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_47 10'h0BC */
	union {
		uint32_t sr024_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SR024_48 10'h0C0 */
	union {
		uint32_t sr024_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankMv8r;

#endif