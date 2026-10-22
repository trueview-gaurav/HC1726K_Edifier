/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_NRW_H_
#define CSR_BANK_NRW_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from nrw  ***/
typedef struct csr_bank_nrw {
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
	/* BW0_04 10'h010 */
	union {
		uint32_t bw0_04; // word name
		struct {
			uint32_t access_illegal_hang : 1;
			uint32_t : 7; // padding bits
			uint32_t access_illegal_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_05 10'h014 */
	union {
		uint32_t bw0_05; // word name
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
	/* BW0_06 10'h018 [Unused] */
	uint32_t empty_word_bw0_06;
	/* BW0_07 10'h01C */
	union {
		uint32_t bw0_07; // word name
		struct {
			uint32_t target_burst_len : 5;
			uint32_t : 3; // padding bits
			uint32_t access_end_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_08 10'h020 */
	union {
		uint32_t bw0_08; // word name
		struct {
			uint32_t target_fifo_level : 9;
			uint32_t : 7; // padding bits
			uint32_t fifo_full_level : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* BW0_09 10'h024 */
	union {
		uint32_t bw0_09; // word name
		struct {
			uint32_t height : 16;
			uint32_t block_cnt_hor : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* BW0_10 10'h028 */
	union {
		uint32_t bw0_10; // word name
		struct {
			uint32_t y_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t msb_only : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_11 10'h02C [Unused] */
	uint32_t empty_word_bw0_11;
	/* BW0_12 10'h030 */
	union {
		uint32_t bw0_12; // word name
		struct {
			uint32_t fifo_flush_len : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_13 10'h034 [Unused] */
	uint32_t empty_word_bw0_13;
	/* BW0_14 10'h038 [Unused] */
	uint32_t empty_word_bw0_14;
	/* BW0_15 10'h03C [Unused] */
	uint32_t empty_word_bw0_15;
	/* BW0_16 10'h040 */
	union {
		uint32_t bw0_16; // word name
		struct {
			uint32_t pixel_flush_len : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_17 10'h044 */
	union {
		uint32_t bw0_17; // word name
		struct {
			uint32_t h_start : 13;
			uint32_t : 3; // padding bits
			uint32_t h_end : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* BW0_18 10'h048 */
	union {
		uint32_t bw0_18; // word name
		struct {
			uint32_t v_start : 16;
			uint32_t v_end : 16;
		};
	};
	/* BW0_19 10'h04C */
	union {
		uint32_t bw0_19; // word name
		struct {
			uint32_t flush_addr_skip : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_20 10'h050 [Unused] */
	uint32_t empty_word_bw0_20;
	/* BW0_21 10'h054 */
	union {
		uint32_t bw0_21; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* BW0_22 10'h058 [Unused] */
	uint32_t empty_word_bw0_22;
	/* BW0_23 10'h05C [Unused] */
	uint32_t empty_word_bw0_23;
	/* BW0_24 10'h060 [Unused] */
	uint32_t empty_word_bw0_24;
	/* BW0_25 10'h064 */
	union {
		uint32_t bw0_25; // word name
		struct {
			uint32_t bank_interleave_type : 2;
			uint32_t : 6; // padding bits
			uint32_t bank_group_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_26 10'h068 [Unused] */
	uint32_t empty_word_bw0_26;
	/* BW0_27 10'h06C [Unused] */
	uint32_t empty_word_bw0_27;
	/* BW0_28 10'h070 [Unused] */
	uint32_t empty_word_bw0_28;
	/* BW0_29 10'h074 [Unused] */
	uint32_t empty_word_bw0_29;
	/* BW0_30 10'h078 [Unused] */
	uint32_t empty_word_bw0_30;
	/* BW0_31 10'h07C [Unused] */
	uint32_t empty_word_bw0_31;
	/* BW0_32 10'h080 [Unused] */
	uint32_t empty_word_bw0_32;
	/* BW0_33 10'h084 [Unused] */
	uint32_t empty_word_bw0_33;
	/* BW0_34 10'h088 [Unused] */
	uint32_t empty_word_bw0_34;
	/* BW0_35 10'h08C [Unused] */
	uint32_t empty_word_bw0_35;
	/* BW0_36 10'h090 [Unused] */
	uint32_t empty_word_bw0_36;
	/* BW0_37 10'h094 [Unused] */
	uint32_t empty_word_bw0_37;
	/* BW0_38 10'h098 [Unused] */
	uint32_t empty_word_bw0_38;
	/* BW0_39 10'h09C [Unused] */
	uint32_t empty_word_bw0_39;
	/* BW0_40 10'h0A0 */
	union {
		uint32_t bw0_40; // word name
		struct {
			uint32_t ini_addr_linear_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_41 10'h0A4 */
	union {
		uint32_t bw0_41; // word name
		struct {
			uint32_t ini_addr_linear_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_42 10'h0A8 */
	union {
		uint32_t bw0_42; // word name
		struct {
			uint32_t ini_addr_linear_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_43 10'h0AC */
	union {
		uint32_t bw0_43; // word name
		struct {
			uint32_t ini_addr_linear_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_44 10'h0B0 */
	union {
		uint32_t bw0_44; // word name
		struct {
			uint32_t ini_addr_linear_4 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_45 10'h0B4 */
	union {
		uint32_t bw0_45; // word name
		struct {
			uint32_t ini_addr_linear_5 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_46 10'h0B8 */
	union {
		uint32_t bw0_46; // word name
		struct {
			uint32_t ini_addr_linear_6 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_47 10'h0BC */
	union {
		uint32_t bw0_47; // word name
		struct {
			uint32_t ini_addr_linear_7 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_48 10'h0C0 */
	union {
		uint32_t bw0_48; // word name
		struct {
			uint32_t ini_addr_bank_offset : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BW0_49 10'h0C4 */
	union {
		uint32_t bw0_49; // word name
		struct {
			uint32_t start_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_50 10'h0C8 */
	union {
		uint32_t bw0_50; // word name
		struct {
			uint32_t end_addr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* BW0_51 10'h0CC [Unused] */
	uint32_t empty_word_bw0_51;
	/* BW0_52 10'h0D0 [Unused] */
	uint32_t empty_word_bw0_52;
	/* BW0_53 10'h0D4 [Unused] */
	uint32_t empty_word_bw0_53;
	/* BW0_54 10'h0D8 [Unused] */
	uint32_t empty_word_bw0_54;
	/* BW0_55 10'h0DC [Unused] */
	uint32_t empty_word_bw0_55;
	/* BW0_56 10'h0E0 [Unused] */
	uint32_t empty_word_bw0_56;
	/* BW0_57 10'h0E4 [Unused] */
	uint32_t empty_word_bw0_57;
	/* BW0_58 10'h0E8 [Unused] */
	uint32_t empty_word_bw0_58;
	/* BW0_59 10'h0EC [Unused] */
	uint32_t empty_word_bw0_59;
	/* BW0_60 10'h0F0 [Unused] */
	uint32_t empty_word_bw0_60;
	/* BW0_61 10'h0F4 [Unused] */
	uint32_t empty_word_bw0_61;
	/* BW0_62 10'h0F8 [Unused] */
	uint32_t empty_word_bw0_62;
	/* BW0_63 10'h0FC [Unused] */
	uint32_t empty_word_bw0_63;
	/* BW0_64 10'h100 [Unused] */
	uint32_t empty_word_bw0_64;
	/* BW0_65 10'h104 [Unused] */
	uint32_t empty_word_bw0_65;
	/* BW0_66 10'h108 [Unused] */
	uint32_t empty_word_bw0_66;
	/* BW0_67 10'h10C [Unused] */
	uint32_t empty_word_bw0_67;
	/* BW0_68 10'h110 [Unused] */
	uint32_t empty_word_bw0_68;
	/* BW0_69 10'h114 [Unused] */
	uint32_t empty_word_bw0_69;
	/* BW0_70 10'h118 [Unused] */
	uint32_t empty_word_bw0_70;
	/* BW0_71 10'h11C [Unused] */
	uint32_t empty_word_bw0_71;
	/* BW0_72 10'h120 [Unused] */
	uint32_t empty_word_bw0_72;
	/* BW0_73 10'h124 [Unused] */
	uint32_t empty_word_bw0_73;
	/* BW0_74 10'h128 [Unused] */
	uint32_t empty_word_bw0_74;
} CsrBankNrw;

#endif