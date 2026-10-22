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
			uint32_t irq_clear_weightr_frame_end : 1;
			uint32_t irq_clear_weightr_bw_insufficient : 1;
			uint32_t irq_clear_weightr_access_violation : 1;
			uint32_t : 4; // padding bits
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
			uint32_t status_weightr_frame_end : 1;
			uint32_t status_weightr_bw_insufficient : 1;
			uint32_t status_weightr_access_violation : 1;
			uint32_t : 4; // padding bits
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
			uint32_t irq_mask_weightr_frame_end : 1;
			uint32_t irq_mask_weightr_bw_insufficient : 1;
			uint32_t irq_mask_weightr_access_violation : 1;
			uint32_t : 4; // padding bits
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
} CsrBankBld;

#endif