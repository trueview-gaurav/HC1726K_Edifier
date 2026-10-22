#ifndef CSR_BANK_REFR_H_
#define CSR_BANK_REFR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from refr  ***/
typedef struct csr_bank_refr {
	/* RR_00 10'h000 */
	union {
		uint32_t rr_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_01 10'h004 */
	union {
		uint32_t rr_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_02 10'h008 [Unused] */
	uint32_t empty_word_rr_02;
	/* RR_03 10'h00C [Unused] */
	uint32_t empty_word_rr_03;
	/* RR_04 10'h010 */
	union {
		uint32_t rr_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_05 10'h014 [Unused] */
	uint32_t empty_word_rr_05;
	/* RR_06 10'h018 [Unused] */
	uint32_t empty_word_rr_06;
	/* RR_07 10'h01C */
	union {
		uint32_t rr_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RR_08 10'h020 */
	union {
		uint32_t rr_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* RR_09 10'h024 */
	union {
		uint32_t rr_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t width : 16;
		};
	};
	/* RR_10 10'h028 [Unused] */
	uint32_t empty_word_rr_10;
	/* RR_11 10'h02C [Unused] */
	uint32_t empty_word_rr_11;
	/* RR_12 10'h030 */
	union {
		uint32_t rr_12; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_13 10'h034 */
	union {
		uint32_t rr_13; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_14 10'h038 [Unused] */
	uint32_t empty_word_rr_14;
	/* RR_15 10'h03C */
	union {
		uint32_t rr_15; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* RR_16 10'h040 */
	union {
		uint32_t rr_16; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_17 10'h044 */
	union {
		uint32_t rr_17; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_18 10'h048 */
	union {
		uint32_t rr_18; // word name
		struct {
			uint32_t ini_addr_linear_y : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_19 10'h04C */
	union {
		uint32_t rr_19; // word name
		struct {
			uint32_t ini_addr_linear_c : 28;
			uint32_t : 4; // padding bits
		};
	};
} CsrBankRefr;

#endif