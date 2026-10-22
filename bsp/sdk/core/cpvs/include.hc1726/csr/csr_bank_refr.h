/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_REFR_H_
#define CSR_BANK_REFR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from refr  ***/
typedef struct csr_bank_refr {
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
	/* RR_04 10'h010 */
	union {
		uint32_t rr_04; // word name
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
	/* RR_05 10'h014 */
	union {
		uint32_t rr_05; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_06 10'h018 */
	union {
		uint32_t rr_06; // word name
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
	/* RR_07 10'h01C */
	union {
		uint32_t rr_07; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* RR_08 10'h020 */
	union {
		uint32_t rr_08; // word name
		struct {
			uint32_t height : 16;
			uint32_t width : 16;
		};
	};
	/* RR_09 10'h024 [Unused] */
	uint32_t empty_word_rr_09;
	/* RR_10 10'h028 */
	union {
		uint32_t rr_10; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* RR_11 10'h02C */
	union {
		uint32_t rr_11; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 2; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 2; // padding bits
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 1; // padding bits
			uint32_t ini_addr_bank_offset_c : 3;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RR_12 10'h030 */
	union {
		uint32_t rr_12; // word name
		struct {
			uint32_t ini_addr_linear_y_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_13 10'h034 */
	union {
		uint32_t rr_13; // word name
		struct {
			uint32_t ini_addr_linear_y_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_14 10'h038 */
	union {
		uint32_t rr_14; // word name
		struct {
			uint32_t ini_addr_linear_y_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_15 10'h03C */
	union {
		uint32_t rr_15; // word name
		struct {
			uint32_t ini_addr_linear_y_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_16 10'h040 */
	union {
		uint32_t rr_16; // word name
		struct {
			uint32_t ini_addr_linear_c_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_17 10'h044 */
	union {
		uint32_t rr_17; // word name
		struct {
			uint32_t ini_addr_linear_c_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_18 10'h048 */
	union {
		uint32_t rr_18; // word name
		struct {
			uint32_t ini_addr_linear_c_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_19 10'h04C */
	union {
		uint32_t rr_19; // word name
		struct {
			uint32_t ini_addr_linear_c_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_20 10'h050 */
	union {
		uint32_t rr_20; // word name
		struct {
			uint32_t frmsync_addr_start_y_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_21 10'h054 */
	union {
		uint32_t rr_21; // word name
		struct {
			uint32_t frmsync_addr_start_y_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_22 10'h058 */
	union {
		uint32_t rr_22; // word name
		struct {
			uint32_t frmsync_addr_start_y_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_23 10'h05C */
	union {
		uint32_t rr_23; // word name
		struct {
			uint32_t frmsync_addr_start_y_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_24 10'h060 */
	union {
		uint32_t rr_24; // word name
		struct {
			uint32_t frmsync_addr_start_c_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_25 10'h064 */
	union {
		uint32_t rr_25; // word name
		struct {
			uint32_t frmsync_addr_start_c_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_26 10'h068 */
	union {
		uint32_t rr_26; // word name
		struct {
			uint32_t frmsync_addr_start_c_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_27 10'h06C */
	union {
		uint32_t rr_27; // word name
		struct {
			uint32_t frmsync_addr_start_c_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_28 10'h070 */
	union {
		uint32_t rr_28; // word name
		struct {
			uint32_t frmsync_addr_end_y : 28;
			uint32_t frmsync_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* RR_29 10'h074 */
	union {
		uint32_t rr_29; // word name
		struct {
			uint32_t frmsync_addr_end_c : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_30 10'h078 */
	union {
		uint32_t rr_30; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_31 10'h07C */
	union {
		uint32_t rr_31; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RR_32 10'h080 [Unused] */
	uint32_t empty_word_rr_32;
} CsrBankRefr;

#endif