/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_BSW_H_
#define CSR_BANK_BSW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from bsw  ***/
typedef struct csr_bank_bsw {
	/* LW464_00 10'h000 */
	union {
		uint32_t lw464_00; // word name
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
	/* LW464_01 10'h004 */
	union {
		uint32_t lw464_01; // word name
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
	/* LW464_02 10'h008 */
	union {
		uint32_t lw464_02; // word name
		struct {
			uint32_t irq_clear_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_03 10'h00C */
	union {
		uint32_t lw464_03; // word name
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
	/* LW464_04 10'h010 */
	union {
		uint32_t lw464_04; // word name
		struct {
			uint32_t status_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t status_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_05 10'h014 */
	union {
		uint32_t lw464_05; // word name
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
	/* LW464_06 10'h018 */
	union {
		uint32_t lw464_06; // word name
		struct {
			uint32_t irq_mask_buffer_full_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_buffer_full_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_07 10'h01C */
	union {
		uint32_t lw464_07; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_08 10'h020 [Unused] */
	uint32_t empty_word_lw464_08;
	/* LW464_09 10'h024 [Unused] */
	uint32_t empty_word_lw464_09;
	/* LW464_10 10'h028 */
	union {
		uint32_t lw464_10; // word name
		struct {
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t col_addr_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_11 10'h02C */
	union {
		uint32_t lw464_11; // word name
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
	/* LW464_12 10'h030 */
	union {
		uint32_t lw464_12; // word name
		struct {
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_13 10'h034 */
	union {
		uint32_t lw464_13; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 2; // padding bits
			uint32_t axi_en : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* LW464_14 10'h038 */
	union {
		uint32_t lw464_14; // word name
		struct {
			uint32_t buffer_size : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_15 10'h03C */
	union {
		uint32_t lw464_15; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW464_16 10'h040 */
	union {
		uint32_t lw464_16; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW464_17 10'h044 */
	union {
		uint32_t lw464_17; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LW464_18 10'h048 [Unused] */
	uint32_t empty_word_lw464_18;
	/* LW464_19 10'h04C [Unused] */
	uint32_t empty_word_lw464_19;
	/* LW464_20 10'h050 [Unused] */
	uint32_t empty_word_lw464_20;
	/* LW464_21 10'h054 [Unused] */
	uint32_t empty_word_lw464_21;
	/* LW464_22 10'h058 [Unused] */
	uint32_t empty_word_lw464_22;
	/* LW464_23 10'h05C [Unused] */
	uint32_t empty_word_lw464_23;
	/* LW464_24 10'h060 [Unused] */
	uint32_t empty_word_lw464_24;
	/* LW464_25 10'h064 [Unused] */
	uint32_t empty_word_lw464_25;
	/* LW464_26 10'h068 [Unused] */
	uint32_t empty_word_lw464_26;
	/* LW464_27 10'h06C [Unused] */
	uint32_t empty_word_lw464_27;
	/* LW464_28 10'h070 [Unused] */
	uint32_t empty_word_lw464_28;
	/* LW464_29 10'h074 [Unused] */
	uint32_t empty_word_lw464_29;
	/* LW464_30 10'h078 [Unused] */
	uint32_t empty_word_lw464_30;
	/* LW464_31 10'h07C [Unused] */
	uint32_t empty_word_lw464_31;
	/* LW464_32 10'h080 [Unused] */
	uint32_t empty_word_lw464_32;
	/* LW464_33 10'h084 [Unused] */
	uint32_t empty_word_lw464_33;
	/* LW464_34 10'h088 [Unused] */
	uint32_t empty_word_lw464_34;
	/* LW464_35 10'h08C [Unused] */
	uint32_t empty_word_lw464_35;
	/* LW464_36 10'h090 [Unused] */
	uint32_t empty_word_lw464_36;
	/* LW464_37 10'h094 [Unused] */
	uint32_t empty_word_lw464_37;
	/* LW464_38 10'h098 [Unused] */
	uint32_t empty_word_lw464_38;
	/* LW464_39 10'h09C [Unused] */
	uint32_t empty_word_lw464_39;
	/* LW464_40 10'h0A0 */
	union {
		uint32_t lw464_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW464_41 10'h0A4 */
	union {
		uint32_t lw464_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW464_42 10'h0A8 */
	union {
		uint32_t lw464_42; // word name
		struct {
			uint32_t sample_count : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LW464_43 10'h0AC [Unused] */
	uint32_t empty_word_lw464_43;
	/* LW464_44 10'h0B0 [Unused] */
	uint32_t empty_word_lw464_44;
	/* LW464_45 10'h0B4 [Unused] */
	uint32_t empty_word_lw464_45;
	/* LW464_46 10'h0B8 [Unused] */
	uint32_t empty_word_lw464_46;
	/* LW464_47 10'h0BC [Unused] */
	uint32_t empty_word_lw464_47;
	/* LW464_48 10'h0C0 [Unused] */
	uint32_t empty_word_lw464_48;
} CsrBankBsw;

#endif