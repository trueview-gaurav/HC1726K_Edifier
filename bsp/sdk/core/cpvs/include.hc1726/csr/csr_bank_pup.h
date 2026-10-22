/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PUP_H_
#define CSR_BANK_PUP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pup  ***/
typedef struct csr_bank_pup {
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
	/* COLOR 16'h0014 */
	union {
		uint32_t color; // word name
		struct {
			uint32_t color_space : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PIX_STATE 16'h0018 */
	union {
		uint32_t pix_state; // word name
		struct {
			uint32_t pix_0_state : 2;
			uint32_t : 5; // padding bits
			uint32_t pix_1_state : 2;
			uint32_t : 6; // padding bits
			uint32_t pix_2_state : 2;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADJ 16'h001C */
	union {
		uint32_t adj; // word name
		struct {
			uint32_t pix_adj : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SWAP 16'h0020 */
	union {
		uint32_t swap; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t pix_swap : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UNMERGE 16'h0024 */
	union {
		uint32_t unmerge; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 7; // padding bits
			uint32_t pix_unmerge : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG 16'h0028 */
	union {
		uint32_t debug; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPup;

#endif