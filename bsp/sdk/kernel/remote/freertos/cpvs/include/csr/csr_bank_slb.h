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
			uint32_t : 8; // padding bits
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
} CsrBankSlb;

#endif