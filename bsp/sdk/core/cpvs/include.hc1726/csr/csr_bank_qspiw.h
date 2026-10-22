/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_QSPIW_H_
#define CSR_BANK_QSPIW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from qspiw  ***/
typedef struct csr_bank_qspiw {
	/* LW032_00 10'h000 */
	union {
		uint32_t lw032_00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_01 10'h004 */
	union {
		uint32_t lw032_01; // word name
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
	/* LW032_02 10'h008 */
	union {
		uint32_t lw032_02; // word name
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
	/* LW032_03 10'h00C */
	union {
		uint32_t lw032_03; // word name
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
	/* LW032_04 10'h010 */
	union {
		uint32_t lw032_04; // word name
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
	/* LW032_05 10'h014 [Unused] */
	uint32_t empty_word_lw032_05;
	/* LW032_06 10'h018 */
	union {
		uint32_t lw032_06; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_07 10'h01C */
	union {
		uint32_t lw032_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_08 10'h020 */
	union {
		uint32_t lw032_08; // word name
		struct {
			uint32_t target_fifo_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t fifo_full_level : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_09 10'h024 */
	union {
		uint32_t lw032_09; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW032_10 10'h028 */
	union {
		uint32_t lw032_10; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW032_11 10'h02C */
	union {
		uint32_t lw032_11; // word name
		struct {
			uint32_t pixel_flush_len : 23;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_12 10'h030 [Unused] */
	uint32_t empty_word_lw032_12;
	/* LW032_13 10'h034 */
	union {
		uint32_t lw032_13; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* LW032_14 10'h038 */
	union {
		uint32_t lw032_14; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ini_addr_word : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_15 10'h03C */
	union {
		uint32_t lw032_15; // word name
		struct {
			uint32_t bank_addr_type : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LW032_16 10'h040 [Unused] */
	uint32_t empty_word_lw032_16;
	/* LW032_17 10'h044 [Unused] */
	uint32_t empty_word_lw032_17;
	/* LW032_18 10'h048 [Unused] */
	uint32_t empty_word_lw032_18;
	/* LW032_19 10'h04C [Unused] */
	uint32_t empty_word_lw032_19;
	/* LW032_20 10'h050 [Unused] */
	uint32_t empty_word_lw032_20;
	/* LW032_21 10'h054 [Unused] */
	uint32_t empty_word_lw032_21;
	/* LW032_22 10'h058 [Unused] */
	uint32_t empty_word_lw032_22;
	/* LW032_23 10'h05C [Unused] */
	uint32_t empty_word_lw032_23;
	/* LW032_24 10'h060 [Unused] */
	uint32_t empty_word_lw032_24;
	/* LW032_25 10'h064 [Unused] */
	uint32_t empty_word_lw032_25;
	/* LW032_26 10'h068 [Unused] */
	uint32_t empty_word_lw032_26;
	/* LW032_27 10'h06C [Unused] */
	uint32_t empty_word_lw032_27;
	/* LW032_28 10'h070 [Unused] */
	uint32_t empty_word_lw032_28;
	/* LW032_29 10'h074 [Unused] */
	uint32_t empty_word_lw032_29;
	/* LW032_30 10'h078 [Unused] */
	uint32_t empty_word_lw032_30;
	/* LW032_31 10'h07C [Unused] */
	uint32_t empty_word_lw032_31;
	/* LW032_32 10'h080 [Unused] */
	uint32_t empty_word_lw032_32;
	/* LW032_33 10'h084 [Unused] */
	uint32_t empty_word_lw032_33;
	/* LW032_34 10'h088 [Unused] */
	uint32_t empty_word_lw032_34;
	/* LW032_35 10'h08C [Unused] */
	uint32_t empty_word_lw032_35;
	/* LW032_36 10'h090 [Unused] */
	uint32_t empty_word_lw032_36;
	/* LW032_37 10'h094 [Unused] */
	uint32_t empty_word_lw032_37;
	/* LW032_38 10'h098 [Unused] */
	uint32_t empty_word_lw032_38;
	/* LW032_39 10'h09C [Unused] */
	uint32_t empty_word_lw032_39;
	/* LW032_40 10'h0A0 */
	union {
		uint32_t lw032_40; // word name
		struct {
			uint32_t ini_addr_linear : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LW032_41 10'h0A4 [Unused] */
	uint32_t empty_word_lw032_41;
	/* LW032_42 10'h0A8 [Unused] */
	uint32_t empty_word_lw032_42;
	/* LW032_43 10'h0AC [Unused] */
	uint32_t empty_word_lw032_43;
	/* LW032_44 10'h0B0 [Unused] */
	uint32_t empty_word_lw032_44;
	/* LW032_45 10'h0B4 [Unused] */
	uint32_t empty_word_lw032_45;
	/* LW032_46 10'h0B8 [Unused] */
	uint32_t empty_word_lw032_46;
	/* LW032_47 10'h0BC [Unused] */
	uint32_t empty_word_lw032_47;
	/* LW032_48 10'h0C0 [Unused] */
	uint32_t empty_word_lw032_48;
} CsrBankQspiw;

#endif