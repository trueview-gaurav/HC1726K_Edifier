/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DBC_H_
#define CSR_BANK_DBC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dbc  ***/
typedef struct csr_bank_dbc {
	/* WORD_FRAME_START 10'h000 */
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
	/* IRQ_CLEAR 10'h004 */
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
	/* STATUS 10'h008 */
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
	/* IRQ_MASK 10'h00C */
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
	/* CFA_FORMAT 10'h010 */
	union {
		uint32_t cfa_format; // word name
		struct {
			uint32_t cfa_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CFA_PHASE_0 10'h014 */
	union {
		uint32_t word_cfa_phase_0; // word name
		struct {
			uint32_t cfa_phase_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_1 10'h018 */
	union {
		uint32_t word_cfa_phase_1; // word name
		struct {
			uint32_t cfa_phase_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_2 10'h01C */
	union {
		uint32_t word_cfa_phase_2; // word name
		struct {
			uint32_t cfa_phase_8 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_9 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_3 10'h020 */
	union {
		uint32_t word_cfa_phase_3; // word name
		struct {
			uint32_t cfa_phase_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* RESOLUTION 10'h024 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_MODE 10'h028 */
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
	/* LEVEL_0 10'h02C */
	union {
		uint32_t level_0; // word name
		struct {
			uint32_t level_g0 : 16;
			uint32_t level_r : 16;
		};
	};
	/* LEVEL_1 10'h030 */
	union {
		uint32_t level_1; // word name
		struct {
			uint32_t level_b : 16;
			uint32_t level_g1 : 16;
		};
	};
	/* LEVEL_2 10'h034 */
	union {
		uint32_t level_2; // word name
		struct {
			uint32_t level_s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 10'h038 */
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
} CsrBankDbc;

#endif