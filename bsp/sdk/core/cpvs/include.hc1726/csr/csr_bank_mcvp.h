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
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_IRQ 10'h008 */
	union {
		uint32_t mcvp_irq; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP_IRQ_MASK 10'h00C */
	union {
		uint32_t mcvp_irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
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
			uint32_t frame_width_i : 16;
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
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MCVP008 10'h020 */
	union {
		uint32_t mcvp008; // word name
		struct {
			uint32_t write_ver_4_mv : 1;
			uint32_t : 7; // padding bits
			uint32_t padding_right_venc_mv_num : 2;
			uint32_t : 6; // padding bits
			uint32_t padding_bottom_venc_mv_num : 2;
			uint32_t : 6; // padding bits
			uint32_t mcvp_mono_mode : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MCVP009 10'h024 */
	union {
		uint32_t mcvp009; // word name
		struct {
			uint32_t r2b_left_skip_pel : 16;
			uint32_t r2b_out_blk_width : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* MCVP010 10'h028 */
	union {
		uint32_t mcvp010; // word name
		struct {
			uint32_t me_out_blk_width : 13;
			uint32_t : 3; // padding bits
			uint32_t me_out_blk_width_m1 : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* MCVP011 10'h02C */
	union {
		uint32_t mcvp011; // word name
		struct {
			uint32_t blk_height : 13;
			uint32_t : 3; // padding bits
			uint32_t blk_height_m1 : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* MCVP012 10'h030 */
	union {
		uint32_t mcvp012; // word name
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
	/* MCVP013 10'h034 */
	union {
		uint32_t mcvp013; // word name
		struct {
			uint32_t yuv420_format : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CORING_0 10'h038 */
	union {
		uint32_t coring_0; // word name
		struct {
			uint32_t chroma_coring_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CORING_1 10'h03C */
	union {
		uint32_t coring_1; // word name
		struct {
			uint32_t coring_th : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CORING_2 10'h040 */
	union {
		uint32_t coring_2; // word name
		struct {
			uint32_t coring_slope : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROUNDING_0 10'h044 */
	union {
		uint32_t rounding_0; // word name
		struct {
			uint32_t y_rounding_en : 1;
			uint32_t : 7; // padding bits
			uint32_t c_rounding_en : 1;
			uint32_t : 7; // padding bits
			uint32_t c_adap_rounding : 1;
			uint32_t : 7; // padding bits
			uint32_t atpg_ctrl : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankMcvp;

#endif