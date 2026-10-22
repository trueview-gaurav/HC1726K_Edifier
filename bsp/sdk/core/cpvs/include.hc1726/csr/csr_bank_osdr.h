/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_OSDR_H_
#define CSR_BANK_OSDR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from osdr  ***/
typedef struct csr_bank_osdr {
	/* FRM_START 10'h000 */
	union {
		uint32_t frm_start; // word name
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
			uint32_t irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_resp_error : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATUS 10'h008 */
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
	/* IRQ_MASK 10'h00C */
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
	/* LR564_04 10'h010 */
	union {
		uint32_t lr564_04; // word name
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
	/* LR564_05 10'h014 */
	union {
		uint32_t lr564_05; // word name
		struct {
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR564_06 10'h018 */
	union {
		uint32_t lr564_06; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 1;
			uint32_t : 3; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* LR564_07 10'h01C */
	union {
		uint32_t lr564_07; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LR564_08 10'h020 */
	union {
		uint32_t lr564_08; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LR564_09 10'h024 */
	union {
		uint32_t lr564_09; // word name
		struct {
			uint32_t ini_addr_linear_tag_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_10 10'h028 */
	union {
		uint32_t lr564_10; // word name
		struct {
			uint32_t ini_addr_linear_tag_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_11 10'h02C */
	union {
		uint32_t lr564_11; // word name
		struct {
			uint32_t ini_addr_linear_tag_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_12 10'h030 */
	union {
		uint32_t lr564_12; // word name
		struct {
			uint32_t ini_addr_linear_tag_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_13 10'h034 */
	union {
		uint32_t lr564_13; // word name
		struct {
			uint32_t ini_addr_linear_tag_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_14 10'h038 */
	union {
		uint32_t lr564_14; // word name
		struct {
			uint32_t ini_addr_linear_tag_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_15 10'h03C */
	union {
		uint32_t lr564_15; // word name
		struct {
			uint32_t ini_addr_linear_tag_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_16 10'h040 */
	union {
		uint32_t lr564_16; // word name
		struct {
			uint32_t ini_addr_linear_tag_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_17 10'h044 */
	union {
		uint32_t lr564_17; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_18 10'h048 */
	union {
		uint32_t lr564_18; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LR564_19 10'h04C [Unused] */
	uint32_t empty_word_lr564_19;
	/* LR564_20 10'h050 [Unused] */
	uint32_t empty_word_lr564_20;
	/* LR564_21 10'h054 [Unused] */
	uint32_t empty_word_lr564_21;
	/* LR564_22 10'h058 [Unused] */
	uint32_t empty_word_lr564_22;
	/* LR564_23 10'h05C [Unused] */
	uint32_t empty_word_lr564_23;
	/* LR564_24 10'h060 [Unused] */
	uint32_t empty_word_lr564_24;
	/* LR564_25 10'h064 [Unused] */
	uint32_t empty_word_lr564_25;
	/* LR564_26 10'h068 [Unused] */
	uint32_t empty_word_lr564_26;
	/* LR564_27 10'h06C [Unused] */
	uint32_t empty_word_lr564_27;
	/* LR564_28 10'h070 [Unused] */
	uint32_t empty_word_lr564_28;
	/* LR564_29 10'h074 [Unused] */
	uint32_t empty_word_lr564_29;
	/* LR564_30 10'h078 [Unused] */
	uint32_t empty_word_lr564_30;
	/* LR564_31 10'h07C [Unused] */
	uint32_t empty_word_lr564_31;
	/* LR564_32 10'h080 [Unused] */
	uint32_t empty_word_lr564_32;
} CsrBankOsdr;

#endif