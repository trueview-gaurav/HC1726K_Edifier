/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_FSC_H_
#define CSR_BANK_FSC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from fsc  ***/
typedef struct csr_bank_fsc {
	/* WORD_FRAME_START 6'h00 */
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
	/* IRQ_CLEAR 6'h04 */
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
	/* STATUS 6'h08 */
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
	/* IRQ_MASK 6'h0C */
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
	/* WORD_MODE 6'h10 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_start_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t ini_bayer_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RES_I 6'h14 */
	union {
		uint32_t res_i; // word name
		struct {
			uint32_t width_i : 16;
			uint32_t height_i : 16;
		};
	};
	/* RES_O 6'h18 */
	union {
		uint32_t res_o; // word name
		struct {
			uint32_t width_o : 16;
			uint32_t height_o : 16;
		};
	};
	/* WORD_INI_PHASE_CNT_HOR 6'h1C */
	union {
		uint32_t word_ini_phase_cnt_hor; // word name
		struct {
			uint32_t ini_phase_cnt_hor : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_INI_PHASE_CNT_VER 6'h20 */
	union {
		uint32_t word_ini_phase_cnt_ver; // word name
		struct {
			uint32_t ini_phase_cnt_ver : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PHASE_CNT_STEP_HOR 6'h24 */
	union {
		uint32_t word_phase_cnt_step_hor; // word name
		struct {
			uint32_t phase_cnt_step_hor : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PHASE_CNT_STEP_VER 6'h28 */
	union {
		uint32_t word_phase_cnt_step_ver; // word name
		struct {
			uint32_t phase_cnt_step_ver : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_G_COEFF_SEL 6'h2C */
	union {
		uint32_t word_g_coeff_sel; // word name
		struct {
			uint32_t g_coeff_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BR_COEFF_SEL 6'h30 */
	union {
		uint32_t br_coeff_sel; // word name
		struct {
			uint32_t b_h_coeff_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t b_v_coeff_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t r_h_coeff_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t r_v_coeff_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* OPTIONAL 6'h34 */
	union {
		uint32_t optional; // word name
		struct {
			uint32_t is_filter_at_zero_phase : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 6'h38 */
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
} CsrBankFsc;

#endif