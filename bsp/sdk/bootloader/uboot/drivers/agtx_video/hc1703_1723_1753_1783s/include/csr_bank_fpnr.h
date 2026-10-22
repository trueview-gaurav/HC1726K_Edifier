#ifndef CSR_BANK_FPNR_H_
#define CSR_BANK_FPNR_H_

#include <linux/types.h>

/***  C struct generated from fpnr  ***/
typedef struct csr_bank_fpnr {
	/* WORD_FRAME_START 16'h0000 */
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
	/* IRQ_CLEAR 16'h0004 */
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
	/* STATUS 16'h0008 */
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
	/* IRQ_MASK 16'h000C */
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
	/* RESOLUTION 16'h0010 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_MODE 16'h0014 */
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
	/* ROI_0 16'h0018 */
	union {
		uint32_t roi_0; // word name
		struct {
			uint32_t roi_sx : 16;
			uint32_t roi_ex : 16;
		};
	};
	/* ROI_1 16'h001C */
	union {
		uint32_t roi_1; // word name
		struct {
			uint32_t roi_sy : 16;
			uint32_t roi_ey : 16;
		};
	};
	/* DRAM_DEC 16'h0020 */
	union {
		uint32_t dram_dec; // word name
		struct {
			uint32_t offset_bw : 5;
			uint32_t : 3; // padding bits
			uint32_t offset_shift_bit : 4;
			uint32_t : 4; // padding bits
			uint32_t gain_bw : 5;
			uint32_t : 3; // padding bits
			uint32_t gain_prec : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* ATPG_TEST 16'h0024 */
	union {
		uint32_t atpg_test; // word name
		struct {
			uint32_t atpg_test_enable : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h0028 */
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
} CsrBankFpnr;

#endif