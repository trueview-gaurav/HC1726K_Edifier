/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_BLS_H_
#define CSR_BANK_BLS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from bls  ***/
typedef struct csr_bank_bls {
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
	/* RESOLUTION_I 10'h024 */
	union {
		uint32_t resolution_i; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* LEVEL_STATUS 10'h028 */
	union {
		uint32_t level_status; // word name
		struct {
			uint32_t level_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t level_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_LF_PIX 10'h02C */
	union {
		uint32_t level_lf_pix; // word name
		struct {
			uint32_t level_lf_sx : 16;
			uint32_t level_lf_ex : 16;
		};
	};
	/* LEVEL_RT_PIX 10'h030 */
	union {
		uint32_t level_rt_pix; // word name
		struct {
			uint32_t level_rt_sx : 16;
			uint32_t level_rt_ex : 16;
		};
	};
	/* LEVEL_UP_PIX 10'h034 */
	union {
		uint32_t level_up_pix; // word name
		struct {
			uint32_t level_up_sy : 16;
			uint32_t level_up_ey : 16;
		};
	};
	/* LEVEL_DN_PIX 10'h038 */
	union {
		uint32_t level_dn_pix; // word name
		struct {
			uint32_t level_dn_sy : 16;
			uint32_t level_dn_ey : 16;
		};
	};
	/* LEVEL_PIX_NUM_0 10'h03C */
	union {
		uint32_t level_pix_num_0; // word name
		struct {
			uint32_t level_pix_num_g0 : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_PIX_NUM_1 10'h040 */
	union {
		uint32_t level_pix_num_1; // word name
		struct {
			uint32_t level_pix_num_r : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_PIX_NUM_2 10'h044 */
	union {
		uint32_t level_pix_num_2; // word name
		struct {
			uint32_t level_pix_num_b : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_PIX_NUM_3 10'h048 */
	union {
		uint32_t level_pix_num_3; // word name
		struct {
			uint32_t level_pix_num_g1 : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_PIX_NUM_4 10'h04C */
	union {
		uint32_t level_pix_num_4; // word name
		struct {
			uint32_t level_pix_num_s : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LEVEL_STAT_0 10'h050 */
	union {
		uint32_t level_stat_0; // word name
		struct {
			uint32_t level_g0 : 16;
			uint32_t level_r : 16;
		};
	};
	/* LEVEL_STAT_1 10'h054 */
	union {
		uint32_t level_stat_1; // word name
		struct {
			uint32_t level_b : 16;
			uint32_t level_g1 : 16;
		};
	};
	/* LEVEL_STAT_2 10'h058 */
	union {
		uint32_t level_stat_2; // word name
		struct {
			uint32_t level_s : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMAINDER_0 10'h05C */
	union {
		uint32_t remainder_0; // word name
		struct {
			uint32_t remainder_g0 : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMAINDER_1 10'h060 */
	union {
		uint32_t remainder_1; // word name
		struct {
			uint32_t remainder_r : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMAINDER_2 10'h064 */
	union {
		uint32_t remainder_2; // word name
		struct {
			uint32_t remainder_b : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMAINDER_3 10'h068 */
	union {
		uint32_t remainder_3; // word name
		struct {
			uint32_t remainder_g1 : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* REMAINDER_4 10'h06C */
	union {
		uint32_t remainder_4; // word name
		struct {
			uint32_t remainder_s : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 10'h070 */
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
	/* RESERVED_0 10'h074 [Unused] */
	uint32_t empty_word_reserved_0;
} CsrBankBls;

#endif