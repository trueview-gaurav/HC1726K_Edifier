/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DPC_H_
#define CSR_BANK_DPC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dpc  ***/
typedef struct csr_bank_dpc {
	/* DPC00 16'h000 */
	union {
		uint32_t dpc00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC01 16'h004 */
	union {
		uint32_t dpc01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC02 16'h008 */
	union {
		uint32_t dpc02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC03 16'h00C */
	union {
		uint32_t dpc03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC04 16'h010 */
	union {
		uint32_t dpc04; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* DPC05 16'h014 */
	union {
		uint32_t dpc05; // word name
		struct {
			uint32_t operation : 2;
			uint32_t : 6; // padding bits
			uint32_t yuv_chroma_pos : 1;
			uint32_t : 7; // padding bits
			uint32_t dpc_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t ini_bayer_phase : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DPC06 16'h018 */
	union {
		uint32_t dpc06; // word name
		struct {
			uint32_t input_swap : 1;
			uint32_t : 7; // padding bits
			uint32_t output_swap : 1;
			uint32_t : 7; // padding bits
			uint32_t main_sub_align : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC07 16'h01C */
	union {
		uint32_t dpc07; // word name
		struct {
			uint32_t main_hdi_en : 1;
			uint32_t : 7; // padding bits
			uint32_t main_hdi_at_left : 1;
			uint32_t : 7; // padding bits
			uint32_t sub_hdi_en : 1;
			uint32_t : 7; // padding bits
			uint32_t sub_hdi_at_left : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DPC08 16'h020 */
	union {
		uint32_t dpc08; // word name
		struct {
			uint32_t g_dislike_th : 8;
			uint32_t : 8; // padding bits
			uint32_t br_dislike_th : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DPC09 16'h024 */
	union {
		uint32_t dpc09; // word name
		struct {
			uint32_t g_correct_overshoot : 8;
			uint32_t : 8; // padding bits
			uint32_t br_correct_overshoot : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DPC10 16'h028 */
	union {
		uint32_t dpc10; // word name
		struct {
			uint32_t g_sad_gain : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t br_sad_gain : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC11 16'h02C */
	union {
		uint32_t dpc11; // word name
		struct {
			uint32_t correct_bright_en : 1;
			uint32_t : 7; // padding bits
			uint32_t correct_dark_en : 1;
			uint32_t : 7; // padding bits
			uint32_t correct_mid_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC12 16'h030 */
	union {
		uint32_t dpc12; // word name
		struct {
			uint32_t bright_th : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t dark_th : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 16'h034 */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t debug_mon_sel_dpc : 2;
			uint32_t : 6; // padding bits
			uint32_t debug_mon_sel_vdi : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC14 16'h038 */
	union {
		uint32_t dpc14; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankDpc;

#endif