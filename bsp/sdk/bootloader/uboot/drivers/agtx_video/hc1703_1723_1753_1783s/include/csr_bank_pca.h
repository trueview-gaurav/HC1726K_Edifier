#ifndef CSR_BANK_PCA_H_
#define CSR_BANK_PCA_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pca  ***/
typedef struct csr_bank_pca {
	/* WORD_FRAME_START 8'h00 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 8'h04 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 8'h08 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 8'h0C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RES 8'h10 */
	union {
		uint32_t res; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_H_PRIME_SHIFT 8'h14 */
	union {
		uint32_t word_h_prime_shift; // word name
		struct {
			uint32_t h_prime_shift : 14;
			uint32_t : 2; // padding bits
			uint32_t h_prime_from_rgb_shift : 14;
			uint32_t : 2; // padding bits
		};
	};
	/* H_PRIME_REDEF_R 8'h18 */
	union {
		uint32_t h_prime_redef_r; // word name
		struct {
			uint32_t h_prime_r_redefined : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* H_PRIME_REDEF_G 8'h1C */
	union {
		uint32_t h_prime_redef_g; // word name
		struct {
			uint32_t h_prime_g_redefined : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* H_PRIME_REDEF_B 8'h20 */
	union {
		uint32_t h_prime_redef_b; // word name
		struct {
			uint32_t h_prime_b_redefined : 14;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* H_PRIME_R_DEG 8'h24 */
	union {
		uint32_t h_prime_r_deg; // word name
		struct {
			uint32_t h_prime_r_pos_60degree : 16;
			uint32_t h_prime_r_neg_60degree : 16;
		};
	};
	/* H_PRIME_G_DEG 8'h28 */
	union {
		uint32_t h_prime_g_deg; // word name
		struct {
			uint32_t h_prime_g_pos_60degree : 16;
			uint32_t h_prime_g_neg_60degree : 16;
		};
	};
	/* H_PRIME_B_DEG 8'h2C */
	union {
		uint32_t h_prime_b_deg; // word name
		struct {
			uint32_t h_prime_b_pos_60degree : 16;
			uint32_t h_prime_b_neg_60degree : 16;
		};
	};
	/* H_PRIME_CORR 8'h30 */
	union {
		uint32_t h_prime_corr; // word name
		struct {
			uint32_t h_prime_correction_term : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* H_CAL_DEG 8'h34 */
	union {
		uint32_t h_cal_deg; // word name
		struct {
			uint32_t h_cal_60_degree : 15;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_CTRL 8'h38 */
	union {
		uint32_t table_ctrl; // word name
		struct {
			uint32_t table_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EEE_WADDR 8'h3C */
	union {
		uint32_t table_eee_waddr; // word name
		struct {
			uint32_t table_eee_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EEE_WDATA 8'h40 */
	union {
		uint32_t table_eee_wdata; // word name
		struct {
			uint32_t table_eee_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EOE_WADDR 8'h44 */
	union {
		uint32_t table_eoe_waddr; // word name
		struct {
			uint32_t table_eoe_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EOE_WDATA 8'h48 */
	union {
		uint32_t table_eoe_wdata; // word name
		struct {
			uint32_t table_eoe_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OEE_WADDR 8'h4C */
	union {
		uint32_t table_oee_waddr; // word name
		struct {
			uint32_t table_oee_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OEE_WDATA 8'h50 */
	union {
		uint32_t table_oee_wdata; // word name
		struct {
			uint32_t table_oee_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OOE_WADDR 8'h54 */
	union {
		uint32_t table_ooe_waddr; // word name
		struct {
			uint32_t table_ooe_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OOE_WDATA 8'h58 */
	union {
		uint32_t table_ooe_wdata; // word name
		struct {
			uint32_t table_ooe_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EEO_WADDR 8'h5C */
	union {
		uint32_t table_eeo_waddr; // word name
		struct {
			uint32_t table_eeo_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EEO_WDATA 8'h60 */
	union {
		uint32_t table_eeo_wdata; // word name
		struct {
			uint32_t table_eeo_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EOO_WADDR 8'h64 */
	union {
		uint32_t table_eoo_waddr; // word name
		struct {
			uint32_t table_eoo_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EOO_WDATA 8'h68 */
	union {
		uint32_t table_eoo_wdata; // word name
		struct {
			uint32_t table_eoo_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OEO_WADDR 8'h6C */
	union {
		uint32_t table_oeo_waddr; // word name
		struct {
			uint32_t table_oeo_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OEO_WDATA 8'h70 */
	union {
		uint32_t table_oeo_wdata; // word name
		struct {
			uint32_t table_oeo_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OOO_WADDR 8'h74 */
	union {
		uint32_t table_ooo_waddr; // word name
		struct {
			uint32_t table_ooo_w_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OOO_WDATA 8'h78 */
	union {
		uint32_t table_ooo_wdata; // word name
		struct {
			uint32_t table_ooo_w_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EEE_RADDR 8'h7C */
	union {
		uint32_t table_eee_raddr; // word name
		struct {
			uint32_t table_eee_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EEE_RDATA 8'h80 */
	union {
		uint32_t table_eee_rdata; // word name
		struct {
			uint32_t table_eee_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EOE_RADDR 8'h84 */
	union {
		uint32_t table_eoe_raddr; // word name
		struct {
			uint32_t table_eoe_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EOE_RDATA 8'h88 */
	union {
		uint32_t table_eoe_rdata; // word name
		struct {
			uint32_t table_eoe_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OEE_RADDR 8'h8C */
	union {
		uint32_t table_oee_raddr; // word name
		struct {
			uint32_t table_oee_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OEE_RDATA 8'h90 */
	union {
		uint32_t table_oee_rdata; // word name
		struct {
			uint32_t table_oee_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OOE_RADDR 8'h94 */
	union {
		uint32_t table_ooe_raddr; // word name
		struct {
			uint32_t table_ooe_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OOE_RDATA 8'h98 */
	union {
		uint32_t table_ooe_rdata; // word name
		struct {
			uint32_t table_ooe_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EEO_RADDR 8'h9C */
	union {
		uint32_t table_eeo_raddr; // word name
		struct {
			uint32_t table_eeo_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EEO_RDATA 8'hA0 */
	union {
		uint32_t table_eeo_rdata; // word name
		struct {
			uint32_t table_eeo_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_EOO_RADDR 8'hA4 */
	union {
		uint32_t table_eoo_raddr; // word name
		struct {
			uint32_t table_eoo_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EOO_RDATA 8'hA8 */
	union {
		uint32_t table_eoo_rdata; // word name
		struct {
			uint32_t table_eoo_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OEO_RADDR 8'hAC */
	union {
		uint32_t table_oeo_raddr; // word name
		struct {
			uint32_t table_oeo_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OEO_RDATA 8'hB0 */
	union {
		uint32_t table_oeo_rdata; // word name
		struct {
			uint32_t table_oeo_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* TABLE_OOO_RADDR 8'hB4 */
	union {
		uint32_t table_ooo_raddr; // word name
		struct {
			uint32_t table_ooo_r_addr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OOO_RDATA 8'hB8 */
	union {
		uint32_t table_ooo_rdata; // word name
		struct {
			uint32_t table_ooo_r_data : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 8'hBC */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 8'hC0 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
} CsrBankPca;

#endif