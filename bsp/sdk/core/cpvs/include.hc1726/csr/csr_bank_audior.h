/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AUDIOR_H_
#define CSR_BANK_AUDIOR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audior  ***/
typedef struct csr_bank_audior {
	/* LR432_00 10'h000 */
	union {
		uint32_t lr432_00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t buffer_set_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t buffer_set_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t read_end_req : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LR432_01 10'h004 */
	union {
		uint32_t lr432_01; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t fifo_ready_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR432_02 10'h008 [Unused] */
	uint32_t empty_word_lr432_02;
	/* LR432_03 10'h00C [Unused] */
	uint32_t empty_word_lr432_03;
	/* LR432_04 10'h010 */
	union {
		uint32_t lr432_04; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 3; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* LR432_05 10'h014 */
	union {
		uint32_t lr432_05; // word name
		struct {
			uint32_t buffer_available_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t buffer_available_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t current_buffer : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR432_06 10'h018 */
	union {
		uint32_t lr432_06; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR432_07 10'h01C */
	union {
		uint32_t lr432_07; // word name
		struct {
			uint32_t target_fifo_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR432_08 10'h020 */
	union {
		uint32_t lr432_08; // word name
		struct {
			uint32_t buffer_size : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LR432_09 10'h024 */
	union {
		uint32_t lr432_09; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR432_10 10'h028 */
	union {
		uint32_t lr432_10; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR432_11 10'h02C */
	union {
		uint32_t lr432_11; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LR432_12 10'h030 */
	union {
		uint32_t lr432_12; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR432_13 10'h034 */
	union {
		uint32_t lr432_13; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR432_14 10'h038 */
	union {
		uint32_t lr432_14; // word name
		struct {
			uint32_t sample_count : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LR432_15 10'h03C [Unused] */
	uint32_t empty_word_lr432_15;
	/* LR432_16 10'h040 [Unused] */
	uint32_t empty_word_lr432_16;
	/* LR432_17 10'h044 [Unused] */
	uint32_t empty_word_lr432_17;
	/* LR432_18 10'h048 [Unused] */
	uint32_t empty_word_lr432_18;
	/* LR432_19 10'h04C [Unused] */
	uint32_t empty_word_lr432_19;
	/* LR432_20 10'h050 [Unused] */
	uint32_t empty_word_lr432_20;
	/* LR432_21 10'h054 [Unused] */
	uint32_t empty_word_lr432_21;
	/* LR432_22 10'h058 [Unused] */
	uint32_t empty_word_lr432_22;
	/* LR432_23 10'h05C [Unused] */
	uint32_t empty_word_lr432_23;
	/* LR432_24 10'h060 [Unused] */
	uint32_t empty_word_lr432_24;
	/* LR432_25 10'h064 [Unused] */
	uint32_t empty_word_lr432_25;
	/* LR432_26 10'h068 [Unused] */
	uint32_t empty_word_lr432_26;
	/* LR432_27 10'h06C [Unused] */
	uint32_t empty_word_lr432_27;
	/* LR432_28 10'h070 [Unused] */
	uint32_t empty_word_lr432_28;
	/* LR432_29 10'h074 [Unused] */
	uint32_t empty_word_lr432_29;
	/* IRQ_CLEAR 10'h078 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQ_CLEAR_1 10'h07C */
	union {
		uint32_t irq_clear_1; // word name
		struct {
			uint32_t irq_clear_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 10'h080 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t status_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATUS_1 10'h084 */
	union {
		uint32_t status_1; // word name
		struct {
			uint32_t status_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t status_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h088 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQ_MASK_1 10'h08C */
	union {
		uint32_t irq_mask_1; // word name
		struct {
			uint32_t irq_mask_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAudior;

#endif