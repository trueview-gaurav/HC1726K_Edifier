/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PS_H_
#define CSR_BANK_PS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ps  ***/
typedef struct csr_bank_ps {
	/* MAIN 10'h000 */
	union {
		uint32_t main; // word name
		struct {
			uint32_t ps_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQSTA 10'h004 */
	union {
		uint32_t irqsta; // word name
		struct {
			uint32_t status_frame_done : 1;
			uint32_t status_frame_end : 1;
			uint32_t status_frame_start : 1;
			uint32_t status_frame_size_err : 1;
			uint32_t status_fifo_over_err : 1;
			uint32_t status_sync_code_err : 1;
			uint32_t status_out_over_err : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQMSK 10'h008 */
	union {
		uint32_t irqmsk; // word name
		struct {
			uint32_t irq_mask_frame_done : 1;
			uint32_t irq_mask_frame_end : 1;
			uint32_t irq_mask_frame_start : 1;
			uint32_t irq_mask_frame_size_err : 1;
			uint32_t irq_mask_fifo_over_err : 1;
			uint32_t irq_mask_sync_code_err : 1;
			uint32_t irq_mask_out_over_err : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQACK 10'h00C */
	union {
		uint32_t irqack; // word name
		struct {
			uint32_t irq_clear_frame_done : 1;
			uint32_t irq_clear_frame_end : 1;
			uint32_t irq_clear_frame_start : 1;
			uint32_t irq_clear_frame_size_err : 1;
			uint32_t irq_clear_fifo_over_err : 1;
			uint32_t irq_clear_sync_code_err : 1;
			uint32_t irq_clear_out_over_err : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST 10'h010 */
	union {
		uint32_t rst; // word name
		struct {
			uint32_t ps_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t frame_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG 10'h014 */
	union {
		uint32_t cfg; // word name
		struct {
			uint32_t dec_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t lp_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD 10'h018 */
	union {
		uint32_t word; // word name
		struct {
			uint32_t word_size : 3;
			uint32_t : 5; // padding bits
			uint32_t word_shift : 4;
			uint32_t : 4; // padding bits
			uint32_t word_order : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SIZE 10'h01C */
	union {
		uint32_t size; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* EC 10'h020 */
	union {
		uint32_t ec; // word name
		struct {
			uint32_t dis_ec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HV 10'h024 */
	union {
		uint32_t hv; // word name
		struct {
			uint32_t hsync_polar : 1;
			uint32_t : 7; // padding bits
			uint32_t vsync_polar : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DESR 10'h028 */
	union {
		uint32_t desr; // word name
		struct {
			uint32_t des_en : 1;
			uint32_t : 7; // padding bits
			uint32_t des_bit_size : 2;
			uint32_t : 6; // padding bits
			uint32_t des_unpac_num : 4;
			uint32_t : 4; // padding bits
			uint32_t des_order : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* FMT 10'h02C */
	union {
		uint32_t fmt; // word name
		struct {
			uint32_t data_type : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SCTRL 10'h030 */
	union {
		uint32_t sctrl; // word name
		struct {
			uint32_t sof_en : 1;
			uint32_t : 7; // padding bits
			uint32_t eof_en : 1;
			uint32_t : 7; // padding bits
			uint32_t eol_en : 1;
			uint32_t : 7; // padding bits
			uint32_t sov_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SCODE0 10'h034 */
	union {
		uint32_t scode0; // word name
		struct {
			uint32_t sync_code_0 : 16;
			uint32_t sync_code_1 : 16;
		};
	};
	/* SCODE1 10'h038 */
	union {
		uint32_t scode1; // word name
		struct {
			uint32_t sync_code_2 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FCODE 10'h03C */
	union {
		uint32_t fcode; // word name
		struct {
			uint32_t sof_code : 16;
			uint32_t eof_code : 16;
		};
	};
	/* LCODE 10'h040 */
	union {
		uint32_t lcode; // word name
		struct {
			uint32_t sol_code : 16;
			uint32_t eol_code : 16;
		};
	};
	/* VCODE 10'h044 */
	union {
		uint32_t vcode; // word name
		struct {
			uint32_t sov_code : 16;
			uint32_t eov_code : 16;
		};
	};
	/* PS18 10'h048 [Unused] */
	uint32_t empty_word_ps18;
	/* PS19 10'h04C [Unused] */
	uint32_t empty_word_ps19;
	/* FCNT 10'h050 */
	union {
		uint32_t fcnt; // word name
		struct {
			uint32_t frame_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STA0 10'h054 */
	union {
		uint32_t sta0; // word name
		struct {
			uint32_t active_line_count : 16;
			uint32_t blank_line_count : 16;
		};
	};
	/* STA1 10'h058 */
	union {
		uint32_t sta1; // word name
		struct {
			uint32_t word_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STA2 10'h05C [Unused] */
	uint32_t empty_word_sta2;
	/* DBG0 10'h060 */
	union {
		uint32_t dbg0; // word name
		struct {
			uint32_t debug_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG1 10'h064 */
	union {
		uint32_t dbg1; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* PS26 10'h068 [Unused] */
	uint32_t empty_word_ps26;
	/* PS27 10'h06C [Unused] */
	uint32_t empty_word_ps27;
	/* PS28 10'h070 [Unused] */
	uint32_t empty_word_ps28;
	/* PS29 10'h074 [Unused] */
	uint32_t empty_word_ps29;
	/* PS30 10'h078 [Unused] */
	uint32_t empty_word_ps30;
	/* PS31 10'h07C [Unused] */
	uint32_t empty_word_ps31;
	/* PS32 10'h080 [Unused] */
	uint32_t empty_word_ps32;
	/* PS33 10'h084 [Unused] */
	uint32_t empty_word_ps33;
	/* PS34 10'h088 [Unused] */
	uint32_t empty_word_ps34;
	/* PS35 10'h08C [Unused] */
	uint32_t empty_word_ps35;
	/* PS36 10'h090 [Unused] */
	uint32_t empty_word_ps36;
	/* PS37 10'h094 [Unused] */
	uint32_t empty_word_ps37;
	/* PS38 10'h098 [Unused] */
	uint32_t empty_word_ps38;
	/* PS39 10'h09C [Unused] */
	uint32_t empty_word_ps39;
	/* PS40 10'h0A0 [Unused] */
	uint32_t empty_word_ps40;
	/* PS41 10'h0A4 [Unused] */
	uint32_t empty_word_ps41;
	/* PS42 10'h0A8 [Unused] */
	uint32_t empty_word_ps42;
	/* PS43 10'h0AC [Unused] */
	uint32_t empty_word_ps43;
	/* PS44 10'h0B0 [Unused] */
	uint32_t empty_word_ps44;
	/* PS45 10'h0B4 [Unused] */
	uint32_t empty_word_ps45;
	/* PS46 10'h0B8 [Unused] */
	uint32_t empty_word_ps46;
	/* PS47 10'h0BC [Unused] */
	uint32_t empty_word_ps47;
	/* PS48 10'h0C0 [Unused] */
	uint32_t empty_word_ps48;
	/* PS49 10'h0C4 [Unused] */
	uint32_t empty_word_ps49;
	/* PS50 10'h0C8 [Unused] */
	uint32_t empty_word_ps50;
	/* PS51 10'h0CC [Unused] */
	uint32_t empty_word_ps51;
	/* PS52 10'h0D0 [Unused] */
	uint32_t empty_word_ps52;
	/* PS53 10'h0D4 [Unused] */
	uint32_t empty_word_ps53;
	/* PS54 10'h0D8 [Unused] */
	uint32_t empty_word_ps54;
	/* PS55 10'h0DC [Unused] */
	uint32_t empty_word_ps55;
	/* PS56 10'h0E0 [Unused] */
	uint32_t empty_word_ps56;
	/* PS57 10'h0E4 [Unused] */
	uint32_t empty_word_ps57;
	/* PS58 10'h0E8 [Unused] */
	uint32_t empty_word_ps58;
	/* PS59 10'h0EC [Unused] */
	uint32_t empty_word_ps59;
	/* PS60 10'h0F0 [Unused] */
	uint32_t empty_word_ps60;
	/* PS61 10'h0F4 [Unused] */
	uint32_t empty_word_ps61;
	/* PS62 10'h0F8 [Unused] */
	uint32_t empty_word_ps62;
	/* PS63 10'h0FC [Unused] */
	uint32_t empty_word_ps63;
	/* PS64 10'h100 [Unused] */
	uint32_t empty_word_ps64;
	/* PS65 10'h104 [Unused] */
	uint32_t empty_word_ps65;
	/* PS66 10'h108 [Unused] */
	uint32_t empty_word_ps66;
	/* PS67 10'h10C [Unused] */
	uint32_t empty_word_ps67;
	/* PS68 10'h110 [Unused] */
	uint32_t empty_word_ps68;
	/* PS69 10'h114 [Unused] */
	uint32_t empty_word_ps69;
	/* PS70 10'h118 [Unused] */
	uint32_t empty_word_ps70;
	/* PS71 10'h11C [Unused] */
	uint32_t empty_word_ps71;
	/* PS72 10'h120 [Unused] */
	uint32_t empty_word_ps72;
	/* PS73 10'h124 [Unused] */
	uint32_t empty_word_ps73;
	/* PS74 10'h128 [Unused] */
	uint32_t empty_word_ps74;
	/* PS75 10'h12C [Unused] */
	uint32_t empty_word_ps75;
} CsrBankPs;

#endif