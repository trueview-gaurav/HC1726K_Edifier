#ifndef CSR_BANK_SLB_H_
#define CSR_BANK_SLB_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from slb  ***/
typedef struct csr_bank_slb {
	/* MAIN 12'h000 */
	union {
		uint32_t main; // word name
		struct {
			uint32_t enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQSTA_0 12'h004 */
	union {
		uint32_t irqsta_0; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_lbuf_over_err : 1;
			uint32_t : 7; // padding bits
			uint32_t status_lbuf_drop_err : 1;
			uint32_t : 7; // padding bits
			uint32_t status_frame_comp : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQSTA_1 12'h008 */
	union {
		uint32_t irqsta_1; // word name
		struct {
			uint32_t status_frame_drop : 1;
			uint32_t : 7; // padding bits
			uint32_t status_src_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQMSK_0 12'h00C */
	union {
		uint32_t irqmsk_0; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_lbuf_over_err : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_lbuf_drop_err : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_frame_comp : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQMSK_1 12'h010 */
	union {
		uint32_t irqmsk_1; // word name
		struct {
			uint32_t irq_mask_frame_drop : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_src_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQACK_0 12'h014 */
	union {
		uint32_t irqack_0; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_lbuf_over_err : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_lbuf_drop_err : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_frame_comp : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IRQACK_1 12'h018 */
	union {
		uint32_t irqack_1; // word name
		struct {
			uint32_t irq_clear_frame_drop : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_src_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST 12'h01C */
	union {
		uint32_t rst; // word name
		struct {
			uint32_t frame_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG 12'h020 */
	union {
		uint32_t cfg; // word name
		struct {
			uint32_t lbuf_en : 1;
			uint32_t : 7; // padding bits
			uint32_t crop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t comp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_drop_ack : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* SRC 12'h024 */
	union {
		uint32_t src; // word name
		struct {
			uint32_t src_width : 16;
			uint32_t src_height : 16;
		};
	};
	/* DST 12'h028 */
	union {
		uint32_t dst; // word name
		struct {
			uint32_t dst_width : 16;
			uint32_t dst_height : 16;
		};
	};
	/* CROPX 12'h02C */
	union {
		uint32_t cropx; // word name
		struct {
			uint32_t cord_x_left : 16;
			uint32_t cord_x_right : 16;
		};
	};
	/* CROPY 12'h030 */
	union {
		uint32_t cropy; // word name
		struct {
			uint32_t cord_y_top : 16;
			uint32_t cord_y_bottom : 16;
		};
	};
	/* WORD 12'h034 */
	union {
		uint32_t word; // word name
		struct {
			uint32_t data_type : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SB11 12'h038 [Unused] */
	uint32_t empty_word_sb11;
	/* SB12 12'h03C [Unused] */
	uint32_t empty_word_sb12;
	/* FCNT 12'h040 */
	union {
		uint32_t fcnt; // word name
		struct {
			uint32_t frame_count : 16;
			uint32_t frame_drop_count : 16;
		};
	};
	/* DBG0 12'h044 */
	union {
		uint32_t dbg0; // word name
		struct {
			uint32_t debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG1 12'h048 */
	union {
		uint32_t dbg1; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* STA0 12'h04C */
	union {
		uint32_t sta0; // word name
		struct {
			uint32_t src_width_count : 16;
			uint32_t src_height_count : 16;
		};
	};
	/* STA1 12'h050 */
	union {
		uint32_t sta1; // word name
		struct {
			uint32_t lbuf_wr_width_count : 16;
			uint32_t lbuf_wr_height_count : 16;
		};
	};
	/* STA2 12'h054 */
	union {
		uint32_t sta2; // word name
		struct {
			uint32_t lbuf_rd_width_count : 16;
			uint32_t lbuf_rd_height_count : 16;
		};
	};
	/* STA3 12'h058 */
	union {
		uint32_t sta3; // word name
		struct {
			uint32_t dst_width_count : 16;
			uint32_t dst_height_count : 16;
		};
	};
	/* SB30 12'h05C [Unused] */
	uint32_t empty_word_sb30;
	/* SB31 12'h060 [Unused] */
	uint32_t empty_word_sb31;
	/* SB32 12'h064 [Unused] */
	uint32_t empty_word_sb32;
	/* SB33 12'h068 [Unused] */
	uint32_t empty_word_sb33;
	/* SB34 12'h06C [Unused] */
	uint32_t empty_word_sb34;
	/* SB35 12'h070 [Unused] */
	uint32_t empty_word_sb35;
	/* SB36 12'h074 [Unused] */
	uint32_t empty_word_sb36;
	/* SB37 12'h078 [Unused] */
	uint32_t empty_word_sb37;
	/* SB38 12'h07C [Unused] */
	uint32_t empty_word_sb38;
	/* SB39 12'h080 [Unused] */
	uint32_t empty_word_sb39;
	/* SB40 12'h084 [Unused] */
	uint32_t empty_word_sb40;
	/* SB41 12'h088 [Unused] */
	uint32_t empty_word_sb41;
	/* SB42 12'h08C [Unused] */
	uint32_t empty_word_sb42;
	/* SB43 12'h090 [Unused] */
	uint32_t empty_word_sb43;
	/* SB44 12'h094 [Unused] */
	uint32_t empty_word_sb44;
	/* SB45 12'h098 [Unused] */
	uint32_t empty_word_sb45;
	/* SB46 12'h09C [Unused] */
	uint32_t empty_word_sb46;
	/* SB47 12'h0A0 [Unused] */
	uint32_t empty_word_sb47;
	/* SB48 12'h0A4 [Unused] */
	uint32_t empty_word_sb48;
	/* SB49 12'h0A8 [Unused] */
	uint32_t empty_word_sb49;
	/* SB50 12'h0AC [Unused] */
	uint32_t empty_word_sb50;
	/* SB51 12'h0B0 [Unused] */
	uint32_t empty_word_sb51;
	/* SB52 12'h0B4 [Unused] */
	uint32_t empty_word_sb52;
	/* SB53 12'h0B8 [Unused] */
	uint32_t empty_word_sb53;
	/* SB54 12'h0BC [Unused] */
	uint32_t empty_word_sb54;
	/* SB55 12'h0C0 [Unused] */
	uint32_t empty_word_sb55;
	/* SB56 12'h0C4 [Unused] */
	uint32_t empty_word_sb56;
	/* SB57 12'h0C8 [Unused] */
	uint32_t empty_word_sb57;
	/* SB58 12'h0CC [Unused] */
	uint32_t empty_word_sb58;
	/* SB59 12'h0D0 [Unused] */
	uint32_t empty_word_sb59;
	/* SB60 12'h0D4 [Unused] */
	uint32_t empty_word_sb60;
	/* SB61 12'h0D8 [Unused] */
	uint32_t empty_word_sb61;
	/* SB62 12'h0DC [Unused] */
	uint32_t empty_word_sb62;
	/* SB63 12'h0E0 [Unused] */
	uint32_t empty_word_sb63;
	/* SB64 12'h0E4 [Unused] */
	uint32_t empty_word_sb64;
	/* SB65 12'h0E8 [Unused] */
	uint32_t empty_word_sb65;
	/* SB66 12'h0EC [Unused] */
	uint32_t empty_word_sb66;
	/* SB67 12'h0F0 [Unused] */
	uint32_t empty_word_sb67;
	/* SB68 12'h0F4 [Unused] */
	uint32_t empty_word_sb68;
	/* SB69 12'h0F8 [Unused] */
	uint32_t empty_word_sb69;
	/* SB70 12'h0FC [Unused] */
	uint32_t empty_word_sb70;
	/* SB71 12'h100 [Unused] */
	uint32_t empty_word_sb71;
	/* SB72 12'h104 [Unused] */
	uint32_t empty_word_sb72;
	/* SB73 12'h108 [Unused] */
	uint32_t empty_word_sb73;
	/* SB74 12'h10C [Unused] */
	uint32_t empty_word_sb74;
	/* SB75 12'h110 [Unused] */
	uint32_t empty_word_sb75;
	/* SB76 12'h114 [Unused] */
	uint32_t empty_word_sb76;
	/* SB77 12'h118 [Unused] */
	uint32_t empty_word_sb77;
	/* SB78 12'h11C [Unused] */
	uint32_t empty_word_sb78;
	/* SB79 12'h120 [Unused] */
	uint32_t empty_word_sb79;
	/* SB80 12'h124 [Unused] */
	uint32_t empty_word_sb80;
	/* SB81 12'h128 [Unused] */
	uint32_t empty_word_sb81;
	/* SB82 12'h12C [Unused] */
	uint32_t empty_word_sb82;
} CsrBankSlb;

#endif