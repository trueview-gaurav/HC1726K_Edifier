/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_MCVP_H_
#define CSR_BANK_MCVP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from mcvp  ***/
typedef struct csr_bank_mcvp {
	/* MCVP_START 10'h000 */
	union {
		uint32_t mcvp_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_IRQ_CLEAR 10'h004 */
	union {
		uint32_t mcvp_irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 3; // padding bits
			uint32_t mer_irq_clear_frame_end : 1;
			uint32_t mer_irq_clear_bw_insufficient : 1;
			uint32_t mer_irq_clear_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t nrw_irq_clear_frame_end : 1;
			uint32_t nrw_irq_clear_bw_insufficient : 1;
			uint32_t nrw_irq_clear_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t mvr_irq_clear_frame_end : 1;
			uint32_t mvr_irq_clear_bw_insufficient : 1;
			uint32_t mvr_irq_clear_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t mvw_irq_clear_frame_end : 1;
			uint32_t mvw_irq_clear_bw_insufficient : 1;
			uint32_t mvw_irq_clear_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t venc_mvw_irq_clear_frame_end : 1;
			uint32_t venc_mvw_irq_clear_bw_insufficient : 1;
			uint32_t venc_mvw_irq_clear_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_IRQ 10'h008 */
	union {
		uint32_t mcvp_irq; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 3; // padding bits
			uint32_t mer_status_frame_end : 1;
			uint32_t mer_status_bw_insufficient : 1;
			uint32_t mer_status_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t nrw_status_frame_end : 1;
			uint32_t nrw_status_bw_insufficient : 1;
			uint32_t nrw_status_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t mvr_status_frame_end : 1;
			uint32_t mvr_status_bw_insufficient : 1;
			uint32_t mvr_status_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t mvw_status_frame_end : 1;
			uint32_t mvw_status_bw_insufficient : 1;
			uint32_t mvw_status_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t venc_mvw_status_frame_end : 1;
			uint32_t venc_mvw_status_bw_insufficient : 1;
			uint32_t venc_mvw_status_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_IRQ_MASK 10'h00C */
	union {
		uint32_t mcvp_irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 3; // padding bits
			uint32_t mer_irq_mask_frame_end : 1;
			uint32_t mer_irq_mask_bw_insufficient : 1;
			uint32_t mer_irq_mask_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t nrw_irq_mask_frame_end : 1;
			uint32_t nrw_irq_mask_bw_insufficient : 1;
			uint32_t nrw_irq_mask_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t mvr_irq_mask_frame_end : 1;
			uint32_t mvr_irq_mask_bw_insufficient : 1;
			uint32_t mvr_irq_mask_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t mvw_irq_mask_frame_end : 1;
			uint32_t mvw_irq_mask_bw_insufficient : 1;
			uint32_t mvw_irq_mask_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t venc_mvw_irq_mask_frame_end : 1;
			uint32_t venc_mvw_irq_mask_bw_insufficient : 1;
			uint32_t venc_mvw_irq_mask_access_violation : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_DEBUG_MON_SEL 10'h010 */
	union {
		uint32_t mcvp_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_DISABLE 10'h014 */
	union {
		uint32_t mcvp_disable; // word name
		struct {
			uint32_t disable_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP006 10'h018 */
	union {
		uint32_t mcvp006; // word name
		struct {
			uint32_t frame_width_i : 9;
			uint32_t : 7; // padding bits
			uint32_t frame_height : 16;
		};
	};
	/* MCVP007 10'h01C */
	union {
		uint32_t mcvp007; // word name
		struct {
			uint32_t most_left_tile : 1;
			uint32_t : 7; // padding bits
			uint32_t most_right_tile : 1;
			uint32_t : 7; // padding bits
			uint32_t padding_right_venc_mv : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP008 10'h020 */
	union {
		uint32_t mcvp008; // word name
		struct {
			uint32_t r2b_left_skip_pel : 9;
			uint32_t : 7; // padding bits
			uint32_t r2b_out_blk_width : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP009 10'h024 */
	union {
		uint32_t mcvp009; // word name
		struct {
			uint32_t me_out_blk_width : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t me_out_blk_width_m1 : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP010 10'h028 */
	union {
		uint32_t mcvp010; // word name
		struct {
			uint32_t blk_height : 13;
			uint32_t : 3; // padding bits
			uint32_t blk_height_m1 : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* MCVP011 10'h02C */
	union {
		uint32_t mcvp011; // word name
		struct {
			uint32_t sr_ix : 7;
			uint32_t : 1; // padding bits
			uint32_t sr_iy : 7;
			uint32_t : 1; // padding bits
			uint32_t sr_blk8_ix : 5;
			uint32_t : 3; // padding bits
			uint32_t sr_blk8_iy : 5;
			uint32_t : 3; // padding bits
		};
	};
} CsrBankMcvp;

#endif