#ifndef CSR_BANK_PXR_H_
#define CSR_BANK_PXR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pxr  ***/
typedef struct csr_bank_pxr {
	/* PR0_00 10'h000 */
	union {
		uint32_t pr0_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_01 10'h004 */
	union {
		uint32_t pr0_01; // word name
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
	/* PR0_02 10'h008 */
	union {
		uint32_t pr0_02; // word name
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
	/* PR0_03 10'h00C */
	union {
		uint32_t pr0_03; // word name
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
	/* PR0_04 10'h010 */
	union {
		uint32_t pr0_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_05 10'h014 [Unused] */
	uint32_t empty_word_pr0_05;
	/* PR0_06 10'h018 */
	union {
		uint32_t pr0_06; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_07 10'h01C */
	union {
		uint32_t pr0_07; // word name
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
	/* PR0_08 10'h020 */
	union {
		uint32_t pr0_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* PR0_09 10'h024 */
	union {
		uint32_t pr0_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t width : 16;
		};
	};
	/* PR0_10 10'h028 */
	union {
		uint32_t pr0_10; // word name
		struct {
			uint32_t y_only_e : 1;
			uint32_t : 7; // padding bits
			uint32_t y_only_o : 1;
			uint32_t : 7; // padding bits
			uint32_t msb_only : 1;
			uint32_t : 7; // padding bits
			uint32_t channel_swap : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PR0_11 10'h02C */
	union {
		uint32_t pr0_11; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_12 10'h030 [Unused] */
	uint32_t empty_word_pr0_12;
	/* PR0_13 10'h034 */
	union {
		uint32_t pr0_13; // word name
		struct {
			uint32_t fifo_flush_len : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_14 10'h038 [Unused] */
	uint32_t empty_word_pr0_14;
	/* PR0_15 10'h03C [Unused] */
	uint32_t empty_word_pr0_15;
	/* PR0_16 10'h040 */
	union {
		uint32_t pr0_16; // word name
		struct {
			uint32_t pixel_flush_len : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_17 10'h044 [Unused] */
	uint32_t empty_word_pr0_17;
	/* PR0_18 10'h048 */
	union {
		uint32_t pr0_18; // word name
		struct {
			uint32_t flush_addr_skip_e : 14;
			uint32_t : 2; // padding bits
			uint32_t flush_addr_skip_sign_e : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_19 10'h04C */
	union {
		uint32_t pr0_19; // word name
		struct {
			uint32_t flush_addr_skip_o : 14;
			uint32_t : 2; // padding bits
			uint32_t flush_addr_skip_sign_o : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_20 10'h050 */
	union {
		uint32_t pr0_20; // word name
		struct {
			uint32_t fifo_start_phase : 5;
			uint32_t : 3; // padding bits
			uint32_t fifo_end_phase : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_21 10'h054 */
	union {
		uint32_t pr0_21; // word name
		struct {
			uint32_t fifo_flush_len_last : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_22 10'h058 */
	union {
		uint32_t pr0_22; // word name
		struct {
			uint32_t package_size_last : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_23 10'h05C */
	union {
		uint32_t pr0_23; // word name
		struct {
			uint32_t block_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_24 10'h060 */
	union {
		uint32_t pr0_24; // word name
		struct {
			uint32_t addr_per_row : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_25 10'h064 */
	union {
		uint32_t pr0_25; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t lsb_append_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_26 10'h068 */
	union {
		uint32_t pr0_26; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_27 10'h06C */
	union {
		uint32_t pr0_27; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_28 10'h070 [Unused] */
	uint32_t empty_word_pr0_28;
	/* PR0_29 10'h074 */
	union {
		uint32_t pr0_29; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* PR0_30 10'h078 [Unused] */
	uint32_t empty_word_pr0_30;
	/* PR0_31 10'h07C [Unused] */
	uint32_t empty_word_pr0_31;
	/* PR0_32 10'h080 [Unused] */
	uint32_t empty_word_pr0_32;
	/* PR0_33 10'h084 [Unused] */
	uint32_t empty_word_pr0_33;
	/* PR0_34 10'h088 [Unused] */
	uint32_t empty_word_pr0_34;
	/* PR0_35 10'h08C [Unused] */
	uint32_t empty_word_pr0_35;
	/* PR0_36 10'h090 [Unused] */
	uint32_t empty_word_pr0_36;
	/* PR0_37 10'h094 [Unused] */
	uint32_t empty_word_pr0_37;
	/* PR0_38 10'h098 [Unused] */
	uint32_t empty_word_pr0_38;
	/* PR0_39 10'h09C [Unused] */
	uint32_t empty_word_pr0_39;
	/* PR0_40 10'h0A0 */
	union {
		uint32_t pr0_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_41 10'h0A4 */
	union {
		uint32_t pr0_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_42 10'h0A8 */
	union {
		uint32_t pr0_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_43 10'h0AC */
	union {
		uint32_t pr0_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_44 10'h0B0 */
	union {
		uint32_t pr0_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_45 10'h0B4 */
	union {
		uint32_t pr0_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_46 10'h0B8 */
	union {
		uint32_t pr0_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_47 10'h0BC */
	union {
		uint32_t pr0_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PR0_48 10'h0C0 */
	union {
		uint32_t pr0_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t ini_addr_bank_add_sub : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PR0_49 10'h0C4 */
	union {
		uint32_t pr0_49; // word name
		struct {
			uint32_t mirror_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t flip_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPxr;

#endif