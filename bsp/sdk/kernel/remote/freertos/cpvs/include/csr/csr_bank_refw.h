#ifndef CSR_BANK_REFW_H_
#define CSR_BANK_REFW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from refw  ***/
typedef struct csr_bank_refw {
	/* RW_00 10'h000 */
	union {
		uint32_t rw_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_01 10'h004 */
	union {
		uint32_t rw_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_02 10'h008 [Unused] */
	uint32_t empty_word_rw_02;
	/* RW_03 10'h00C [Unused] */
	uint32_t empty_word_rw_03;
	/* RW_04 10'h010 */
	union {
		uint32_t rw_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_05 10'h014 [Unused] */
	uint32_t empty_word_rw_05;
	/* RW_06 10'h018 [Unused] */
	uint32_t empty_word_rw_06;
	/* RW_07 10'h01C */
	union {
		uint32_t rw_07; // word name
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
	/* RW_08 10'h020 */
	union {
		uint32_t rw_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* RW_09 10'h024 */
	union {
		uint32_t rw_09; // word name
		struct {
			uint32_t mb_cnt_ver : 12;
			uint32_t : 4; // padding bits
			uint32_t mb_cnt_hor : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_10 10'h028 */
	union {
		uint32_t rw_10; // word name
		struct {
			uint32_t y_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_11 10'h02C */
	union {
		uint32_t rw_11; // word name
		struct {
			uint32_t total_fifo_cnt : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* RW_12 10'h030 */
	union {
		uint32_t rw_12; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_13 10'h034 */
	union {
		uint32_t rw_13; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_14 10'h038 [Unused] */
	uint32_t empty_word_rw_14;
	/* RW_15 10'h03C */
	union {
		uint32_t rw_15; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* RW_16 10'h040 */
	union {
		uint32_t rw_16; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_17 10'h044 */
	union {
		uint32_t rw_17; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_18 10'h048 */
	union {
		uint32_t rw_18; // word name
		struct {
			uint32_t ini_addr_linear_y : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_19 10'h04C */
	union {
		uint32_t rw_19; // word name
		struct {
			uint32_t ini_addr_linear_c : 28;
			uint32_t : 4; // padding bits
		};
	};
} CsrBankRefw;

#endif