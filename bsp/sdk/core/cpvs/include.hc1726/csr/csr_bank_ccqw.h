/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_CCQW_H_
#define CSR_BANK_CCQW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ccqw  ***/
typedef struct csr_bank_ccqw {
	/* LW432_00 10'h000 */
	union {
		uint32_t lw432_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t buffer_set_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t buffer_set_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_01 10'h004 */
	union {
		uint32_t lw432_01; // word name
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
	/* LW432_02 10'h008 */
	union {
		uint32_t lw432_02; // word name
		struct {
			uint32_t irq_clear_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_03 10'h00C */
	union {
		uint32_t lw432_03; // word name
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
	/* LW432_04 10'h010 */
	union {
		uint32_t lw432_04; // word name
		struct {
			uint32_t status_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t status_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_05 10'h014 */
	union {
		uint32_t lw432_05; // word name
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
	/* LW432_06 10'h018 */
	union {
		uint32_t lw432_06; // word name
		struct {
			uint32_t irq_mask_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_07 10'h01C */
	union {
		uint32_t lw432_07; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_08 10'h020 [Unused] */
	uint32_t empty_word_lw432_08;
	/* LW432_09 10'h024 [Unused] */
	uint32_t empty_word_lw432_09;
	/* LW432_10 10'h028 */
	union {
		uint32_t lw432_10; // word name
		struct {
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_11 10'h02C */
	union {
		uint32_t lw432_11; // word name
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
	/* LW432_12 10'h030 */
	union {
		uint32_t lw432_12; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_13 10'h034 */
	union {
		uint32_t lw432_13; // word name
		struct {
			uint32_t target_fifo_level : 6;
			uint32_t : 2; // padding bits
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t fifo_full_level : 6;
			uint32_t : 2; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 2; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* LW432_14 10'h038 */
	union {
		uint32_t lw432_14; // word name
		struct {
			uint32_t buffer_size : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_15 10'h03C */
	union {
		uint32_t lw432_15; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW432_16 10'h040 */
	union {
		uint32_t lw432_16; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW432_17 10'h044 */
	union {
		uint32_t lw432_17; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LW432_18 10'h048 [Unused] */
	uint32_t empty_word_lw432_18;
	/* LW432_19 10'h04C [Unused] */
	uint32_t empty_word_lw432_19;
	/* LW432_20 10'h050 [Unused] */
	uint32_t empty_word_lw432_20;
	/* LW432_21 10'h054 [Unused] */
	uint32_t empty_word_lw432_21;
	/* LW432_22 10'h058 [Unused] */
	uint32_t empty_word_lw432_22;
	/* LW432_23 10'h05C [Unused] */
	uint32_t empty_word_lw432_23;
	/* LW432_24 10'h060 [Unused] */
	uint32_t empty_word_lw432_24;
	/* LW432_25 10'h064 [Unused] */
	uint32_t empty_word_lw432_25;
	/* LW432_26 10'h068 [Unused] */
	uint32_t empty_word_lw432_26;
	/* LW432_27 10'h06C [Unused] */
	uint32_t empty_word_lw432_27;
	/* LW432_28 10'h070 [Unused] */
	uint32_t empty_word_lw432_28;
	/* LW432_29 10'h074 [Unused] */
	uint32_t empty_word_lw432_29;
	/* LW432_30 10'h078 [Unused] */
	uint32_t empty_word_lw432_30;
	/* LW432_31 10'h07C [Unused] */
	uint32_t empty_word_lw432_31;
	/* LW432_32 10'h080 [Unused] */
	uint32_t empty_word_lw432_32;
	/* LW432_33 10'h084 [Unused] */
	uint32_t empty_word_lw432_33;
	/* LW432_34 10'h088 [Unused] */
	uint32_t empty_word_lw432_34;
	/* LW432_35 10'h08C [Unused] */
	uint32_t empty_word_lw432_35;
	/* LW432_36 10'h090 [Unused] */
	uint32_t empty_word_lw432_36;
	/* LW432_37 10'h094 [Unused] */
	uint32_t empty_word_lw432_37;
	/* LW432_38 10'h098 [Unused] */
	uint32_t empty_word_lw432_38;
	/* LW432_39 10'h09C [Unused] */
	uint32_t empty_word_lw432_39;
	/* LW432_40 10'h0A0 */
	union {
		uint32_t lw432_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW432_41 10'h0A4 */
	union {
		uint32_t lw432_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW432_42 10'h0A8 */
	union {
		uint32_t lw432_42; // word name
		struct {
			uint32_t sample_count : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LW432_43 10'h0AC [Unused] */
	uint32_t empty_word_lw432_43;
	/* LW432_44 10'h0B0 [Unused] */
	uint32_t empty_word_lw432_44;
	/* LW432_45 10'h0B4 [Unused] */
	uint32_t empty_word_lw432_45;
	/* LW432_46 10'h0B8 [Unused] */
	uint32_t empty_word_lw432_46;
	/* LW432_47 10'h0BC [Unused] */
	uint32_t empty_word_lw432_47;
	/* LW432_48 10'h0C0 [Unused] */
	uint32_t empty_word_lw432_48;
} CsrBankCcqw;

#endif