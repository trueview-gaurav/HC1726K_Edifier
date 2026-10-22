#ifndef CSR_BANK_SRCR_H_
#define CSR_BANK_SRCR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from srcr  ***/
typedef struct csr_bank_srcr {
	/* BR1_00 10'h000 */
	union {
		uint32_t br1_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_01 10'h004 */
	union {
		uint32_t br1_01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_02 10'h008 */
	union {
		uint32_t br1_02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_03 10'h00C */
	union {
		uint32_t br1_03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_04 10'h010 */
	union {
		uint32_t br1_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* BR1_05 10'h014 */
	union {
		uint32_t br1_05; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_06 10'h018 [Unused] */
	uint32_t empty_word_br1_06;
	/* BR1_07 10'h01C */
	union {
		uint32_t br1_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_08 10'h020 */
	union {
		uint32_t br1_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* BR1_09 10'h024 */
	union {
		uint32_t br1_09; // word name
		struct {
			uint32_t total_fifo_flush_cnt : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* BR1_10 10'h028 */
	union {
		uint32_t br1_10; // word name
		struct {
			uint32_t y_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t msb_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_11 10'h02C */
	union {
		uint32_t br1_11; // word name
		struct {
			uint32_t block_size : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_12 10'h030 */
	union {
		uint32_t br1_12; // word name
		struct {
			uint32_t block_cnt_per_row : 13;
			uint32_t : 3; // padding bits
			uint32_t total_block_row : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* BR1_13 10'h034 */
	union {
		uint32_t br1_13; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_14 10'h038 */
	union {
		uint32_t br1_14; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_15 10'h03C [Unused] */
	uint32_t empty_word_br1_15;
	/* BR1_16 10'h040 */
	union {
		uint32_t br1_16; // word name
		struct {
			uint32_t flush_addr_skip : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_17 10'h044 */
	union {
		uint32_t br1_17; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* BR1_18 10'h048 */
	union {
		uint32_t br1_18; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_19 10'h04C */
	union {
		uint32_t br1_19; // word name
		struct {
			uint32_t flush_addr_skip_extra : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR1_20 10'h050 [Unused] */
	uint32_t empty_word_br1_20;
	/* BR1_21 10'h054 [Unused] */
	uint32_t empty_word_br1_21;
	/* BR1_22 10'h058 [Unused] */
	uint32_t empty_word_br1_22;
	/* BR1_23 10'h05C [Unused] */
	uint32_t empty_word_br1_23;
	/* BR1_24 10'h060 [Unused] */
	uint32_t empty_word_br1_24;
	/* BR1_25 10'h064 [Unused] */
	uint32_t empty_word_br1_25;
	/* BR1_26 10'h068 [Unused] */
	uint32_t empty_word_br1_26;
	/* BR1_27 10'h06C [Unused] */
	uint32_t empty_word_br1_27;
	/* BR1_28 10'h070 [Unused] */
	uint32_t empty_word_br1_28;
	/* BR1_29 10'h074 [Unused] */
	uint32_t empty_word_br1_29;
	/* BR1_30 10'h078 [Unused] */
	uint32_t empty_word_br1_30;
	/* BR1_31 10'h07C [Unused] */
	uint32_t empty_word_br1_31;
	/* BR1_32 10'h080 [Unused] */
	uint32_t empty_word_br1_32;
	/* BR1_33 10'h084 [Unused] */
	uint32_t empty_word_br1_33;
	/* BR1_34 10'h088 [Unused] */
	uint32_t empty_word_br1_34;
	/* BR1_35 10'h08C [Unused] */
	uint32_t empty_word_br1_35;
	/* BR1_36 10'h090 [Unused] */
	uint32_t empty_word_br1_36;
	/* BR1_37 10'h094 [Unused] */
	uint32_t empty_word_br1_37;
	/* BR1_38 10'h098 [Unused] */
	uint32_t empty_word_br1_38;
	/* BR1_39 10'h09C [Unused] */
	uint32_t empty_word_br1_39;
	/* BR1_40 10'h0A0 */
	union {
		uint32_t br1_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_41 10'h0A4 */
	union {
		uint32_t br1_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_42 10'h0A8 */
	union {
		uint32_t br1_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_43 10'h0AC */
	union {
		uint32_t br1_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_44 10'h0B0 */
	union {
		uint32_t br1_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_45 10'h0B4 */
	union {
		uint32_t br1_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_46 10'h0B8 */
	union {
		uint32_t br1_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_47 10'h0BC */
	union {
		uint32_t br1_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BR1_48 10'h0C0 */
	union {
		uint32_t br1_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankSrcr;

#endif