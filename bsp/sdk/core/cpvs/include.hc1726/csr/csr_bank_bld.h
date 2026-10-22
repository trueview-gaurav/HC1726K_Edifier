/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_BLD_H_
#define CSR_BANK_BLD_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from bld  ***/
typedef struct csr_bank_bld {
	/* WORD_FRAME_START 9'h000 */
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
	/* IRQ_CLEAR 9'h004 */
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
	/* STATUS 9'h008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 9'h00C */
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
	/* RESOLUTION 9'h010 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_TABLE_X_NUM 9'h014 */
	union {
		uint32_t word_table_x_num; // word name
		struct {
			uint32_t table_x_num : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_TABLE_CNT_INI 9'h018 */
	union {
		uint32_t word_table_cnt_ini; // word name
		struct {
			uint32_t table_x_cnt_ini : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t table_y_cnt_ini : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_TABLE_CNT_STEP 9'h01C */
	union {
		uint32_t word_table_cnt_step; // word name
		struct {
			uint32_t table_x_cnt_step : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t table_y_cnt_step : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 9'h020 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 9'h024 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* WORD_RESERVED_1 9'h028 */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* WORD_WEIGHT_0 9'h02C */
	union {
		uint32_t word_weight_0; // word name
		struct {
			uint32_t weight_0 : 9;
			uint32_t weight_1 : 9;
			uint32_t weight_2 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_1 9'h030 */
	union {
		uint32_t word_weight_1; // word name
		struct {
			uint32_t weight_3 : 9;
			uint32_t weight_4 : 9;
			uint32_t weight_5 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_2 9'h034 */
	union {
		uint32_t word_weight_2; // word name
		struct {
			uint32_t weight_6 : 9;
			uint32_t weight_7 : 9;
			uint32_t weight_8 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_3 9'h038 */
	union {
		uint32_t word_weight_3; // word name
		struct {
			uint32_t weight_9 : 9;
			uint32_t weight_10 : 9;
			uint32_t weight_11 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_4 9'h03C */
	union {
		uint32_t word_weight_4; // word name
		struct {
			uint32_t weight_12 : 9;
			uint32_t weight_13 : 9;
			uint32_t weight_14 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_5 9'h040 */
	union {
		uint32_t word_weight_5; // word name
		struct {
			uint32_t weight_15 : 9;
			uint32_t weight_16 : 9;
			uint32_t weight_17 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_6 9'h044 */
	union {
		uint32_t word_weight_6; // word name
		struct {
			uint32_t weight_18 : 9;
			uint32_t weight_19 : 9;
			uint32_t weight_20 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_7 9'h048 */
	union {
		uint32_t word_weight_7; // word name
		struct {
			uint32_t weight_21 : 9;
			uint32_t weight_22 : 9;
			uint32_t weight_23 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_8 9'h04C */
	union {
		uint32_t word_weight_8; // word name
		struct {
			uint32_t weight_24 : 9;
			uint32_t weight_25 : 9;
			uint32_t weight_26 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_9 9'h050 */
	union {
		uint32_t word_weight_9; // word name
		struct {
			uint32_t weight_27 : 9;
			uint32_t weight_28 : 9;
			uint32_t weight_29 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_WEIGHT_10 9'h054 */
	union {
		uint32_t word_weight_10; // word name
		struct {
			uint32_t weight_30 : 9;
			uint32_t weight_31 : 9;
			uint32_t weight_32 : 9;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_TABLE_GRID 9'h058 */
	union {
		uint32_t word_table_grid; // word name
		struct {
			uint32_t table_grid_width : 4;
			uint32_t : 1; // padding bits
			uint32_t table_grid_height_inv : 21;
			uint32_t : 6; // padding bits
		};
	};
	/* CTRL 9'h05C */
	union {
		uint32_t ctrl; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankBld;

#endif