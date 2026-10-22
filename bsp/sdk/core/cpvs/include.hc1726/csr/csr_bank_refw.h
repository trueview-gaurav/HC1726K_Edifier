/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_REFW_H_
#define CSR_BANK_REFW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from refw  ***/
typedef struct csr_bank_refw {
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
	/* RW_04 10'h010 */
	union {
		uint32_t rw_04; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_05 10'h014 */
	union {
		uint32_t rw_05; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_06 10'h018 */
	union {
		uint32_t rw_06; // word name
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
	/* RW_07 10'h01C */
	union {
		uint32_t rw_07; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* RW_08 10'h020 */
	union {
		uint32_t rw_08; // word name
		struct {
			uint32_t mb_cnt_ver : 12;
			uint32_t : 4; // padding bits
			uint32_t mb_cnt_hor : 12;
			uint32_t y_only : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* RW_09 10'h024 */
	union {
		uint32_t rw_09; // word name
		struct {
			uint32_t total_fifo_cnt : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* RW_10 10'h028 */
	union {
		uint32_t rw_10; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* RW_11 10'h02C */
	union {
		uint32_t rw_11; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 2; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 2; // padding bits
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 1; // padding bits
			uint32_t ini_addr_bank_offset_c : 3;
			uint32_t : 1; // padding bits
			uint32_t lcu_32x32 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RW_12 10'h030 */
	union {
		uint32_t rw_12; // word name
		struct {
			uint32_t ini_addr_linear_y_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_13 10'h034 */
	union {
		uint32_t rw_13; // word name
		struct {
			uint32_t ini_addr_linear_y_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_14 10'h038 */
	union {
		uint32_t rw_14; // word name
		struct {
			uint32_t ini_addr_linear_y_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_15 10'h03C */
	union {
		uint32_t rw_15; // word name
		struct {
			uint32_t ini_addr_linear_y_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_16 10'h040 */
	union {
		uint32_t rw_16; // word name
		struct {
			uint32_t ini_addr_linear_c_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_17 10'h044 */
	union {
		uint32_t rw_17; // word name
		struct {
			uint32_t ini_addr_linear_c_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_18 10'h048 */
	union {
		uint32_t rw_18; // word name
		struct {
			uint32_t ini_addr_linear_c_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_19 10'h04C */
	union {
		uint32_t rw_19; // word name
		struct {
			uint32_t ini_addr_linear_c_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_20 10'h050 */
	union {
		uint32_t rw_20; // word name
		struct {
			uint32_t frmsync_addr_start_y_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_21 10'h054 */
	union {
		uint32_t rw_21; // word name
		struct {
			uint32_t frmsync_addr_start_y_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_22 10'h058 */
	union {
		uint32_t rw_22; // word name
		struct {
			uint32_t frmsync_addr_start_y_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_23 10'h05C */
	union {
		uint32_t rw_23; // word name
		struct {
			uint32_t frmsync_addr_start_y_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_24 10'h060 */
	union {
		uint32_t rw_24; // word name
		struct {
			uint32_t frmsync_addr_start_c_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_25 10'h064 */
	union {
		uint32_t rw_25; // word name
		struct {
			uint32_t frmsync_addr_start_c_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_26 10'h068 */
	union {
		uint32_t rw_26; // word name
		struct {
			uint32_t frmsync_addr_start_c_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_27 10'h06C */
	union {
		uint32_t rw_27; // word name
		struct {
			uint32_t frmsync_addr_start_c_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_28 10'h070 */
	union {
		uint32_t rw_28; // word name
		struct {
			uint32_t frmsync_addr_end_y : 28;
			uint32_t frmsync_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* RW_29 10'h074 [Unused] */
	uint32_t empty_word_rw_29;
	/* RW_30 10'h078 */
	union {
		uint32_t rw_30; // word name
		struct {
			uint32_t status_last_addr_y : 28;
			uint32_t status_last_bank_y : 3;
			uint32_t : 1; // padding bits
		};
	};
	/* RW_31 10'h07C */
	union {
		uint32_t rw_31; // word name
		struct {
			uint32_t status_lastm1_addr_y : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_32 10'h080 */
	union {
		uint32_t rw_32; // word name
		struct {
			uint32_t status_lastm2_addr_y : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_33 10'h084 */
	union {
		uint32_t rw_33; // word name
		struct {
			uint32_t status_lastm3_addr_y : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_34 10'h088 */
	union {
		uint32_t rw_34; // word name
		struct {
			uint32_t status_last_addr_c : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_35 10'h08C */
	union {
		uint32_t rw_35; // word name
		struct {
			uint32_t status_frmsync_addr_end_y : 28;
			uint32_t status_frmsync_end_bank_y : 3;
			uint32_t : 1; // padding bits
		};
	};
	/* RW_36 10'h090 */
	union {
		uint32_t rw_36; // word name
		struct {
			uint32_t status_frmsync_addr_end_c : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_37 10'h094 [Unused] */
	uint32_t empty_word_rw_37;
	/* RW_38 10'h098 [Unused] */
	uint32_t empty_word_rw_38;
	/* RW_39 10'h09C [Unused] */
	uint32_t empty_word_rw_39;
	/* RW_40 10'h0A0 */
	union {
		uint32_t rw_40; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_41 10'h0A4 */
	union {
		uint32_t rw_41; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* RW_42 10'h0A8 [Unused] */
	uint32_t empty_word_rw_42;
	/* RW_43 10'h0AC [Unused] */
	uint32_t empty_word_rw_43;
} CsrBankRefw;

#endif