#ifndef CSR_BANK_FCS_H_
#define CSR_BANK_FCS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from fcs  ***/
typedef struct csr_bank_fcs {
	/* WORD_FRAME_START 8'h00 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 8'h04 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_STATUS 8'h08 */
	union {
		uint32_t irq_status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 8'h0C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MODE 8'h10 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 8'h14 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* TRANS 8'h18 */
	union {
		uint32_t trans; // word name
		struct {
			uint32_t trans_diff_level_max : 6;
			uint32_t : 2; // padding bits
			uint32_t trans_gain : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GRID_CNT 8'h1C */
	union {
		uint32_t grid_cnt; // word name
		struct {
			uint32_t grid_cnt_th_high : 3;
			uint32_t : 5; // padding bits
			uint32_t grid_cnt_th_low : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GRID_CNT_TH 8'h20 */
	union {
		uint32_t grid_cnt_th; // word name
		struct {
			uint32_t grid_cnt_raw_th : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GRID_TRANS 8'h24 */
	union {
		uint32_t grid_trans; // word name
		struct {
			uint32_t grid_trans_level_th : 9;
			uint32_t : 7; // padding bits
			uint32_t grid_trans_round_bit_high : 2;
			uint32_t : 6; // padding bits
			uint32_t grid_trans_round_bit_low : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* COLOR 8'h28 */
	union {
		uint32_t color; // word name
		struct {
			uint32_t color_diff_self_th : 6;
			uint32_t : 2; // padding bits
			uint32_t color_diff_neighbor_th : 6;
			uint32_t : 2; // padding bits
			uint32_t color_coring_th : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CORRECTION 8'h2C */
	union {
		uint32_t correction; // word name
		struct {
			uint32_t correction_gain : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TARGET_RATIO 8'h30 */
	union {
		uint32_t target_ratio; // word name
		struct {
			uint32_t target_bg_ratio : 9;
			uint32_t : 7; // padding bits
			uint32_t target_rg_ratio : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* ATPG_TEST 8'h34 */
	union {
		uint32_t atpg_test; // word name
		struct {
			uint32_t atpg_test_enable_0 : 2;
			uint32_t : 6; // padding bits
			uint32_t atpg_test_enable_1 : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG_MON 8'h38 */
	union {
		uint32_t debug_mon; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED 8'h3C */
	union {
		uint32_t word_reserved; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankFcs;

#endif