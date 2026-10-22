#ifndef CSR_BANK_LSC_H_
#define CSR_BANK_LSC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from lsc  ***/
typedef struct csr_bank_lsc {
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
	/* CFA_FORMAT 8'h10 */
	union {
		uint32_t cfa_format; // word name
		struct {
			uint32_t cfa_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_CFA_PHASE_0 8'h14 */
	union {
		uint32_t word_cfa_phase_0; // word name
		struct {
			uint32_t cfa_phase_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_1 8'h18 */
	union {
		uint32_t word_cfa_phase_1; // word name
		struct {
			uint32_t cfa_phase_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_2 8'h1C */
	union {
		uint32_t word_cfa_phase_2; // word name
		struct {
			uint32_t cfa_phase_8 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_9 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* WORD_CFA_PHASE_3 8'h20 */
	union {
		uint32_t word_cfa_phase_3; // word name
		struct {
			uint32_t cfa_phase_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* RESOLUTION 8'h24 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORD_MODE 8'h28 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t bayer_phase_srep : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_MODE 8'h2C */
	union {
		uint32_t curve_mode; // word name
		struct {
			uint32_t curve_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_R_0 8'h30 */
	union {
		uint32_t curve_gain_r_0; // word name
		struct {
			uint32_t curve_gain_origin_r : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_R_1 8'h34 */
	union {
		uint32_t curve_gain_r_1; // word name
		struct {
			uint32_t curve_gain_x_trend_2s_r : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_R_2 8'h38 */
	union {
		uint32_t curve_gain_r_2; // word name
		struct {
			uint32_t curve_gain_y_trend_2s_r : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_R_3 8'h3C */
	union {
		uint32_t curve_gain_r_3; // word name
		struct {
			uint32_t curve_gain_x_curvature_r : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_R_4 8'h40 */
	union {
		uint32_t curve_gain_r_4; // word name
		struct {
			uint32_t curve_gain_y_curvature_r : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_R_5 8'h44 */
	union {
		uint32_t curve_gain_r_5; // word name
		struct {
			uint32_t curve_gain_tilt_2s_r : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* CURVE_GAIN_G_0 8'h48 */
	union {
		uint32_t curve_gain_g_0; // word name
		struct {
			uint32_t curve_gain_origin_g : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_G_1 8'h4C */
	union {
		uint32_t curve_gain_g_1; // word name
		struct {
			uint32_t curve_gain_x_trend_2s_g : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_G_2 8'h50 */
	union {
		uint32_t curve_gain_g_2; // word name
		struct {
			uint32_t curve_gain_y_trend_2s_g : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_G_3 8'h54 */
	union {
		uint32_t curve_gain_g_3; // word name
		struct {
			uint32_t curve_gain_x_curvature_g : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_G_4 8'h58 */
	union {
		uint32_t curve_gain_g_4; // word name
		struct {
			uint32_t curve_gain_y_curvature_g : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_G_5 8'h5C */
	union {
		uint32_t curve_gain_g_5; // word name
		struct {
			uint32_t curve_gain_tilt_2s_g : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* CURVE_GAIN_B_0 8'h60 */
	union {
		uint32_t curve_gain_b_0; // word name
		struct {
			uint32_t curve_gain_origin_b : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_B_1 8'h64 */
	union {
		uint32_t curve_gain_b_1; // word name
		struct {
			uint32_t curve_gain_x_trend_2s_b : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_B_2 8'h68 */
	union {
		uint32_t curve_gain_b_2; // word name
		struct {
			uint32_t curve_gain_y_trend_2s_b : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_B_3 8'h6C */
	union {
		uint32_t curve_gain_b_3; // word name
		struct {
			uint32_t curve_gain_x_curvature_b : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_B_4 8'h70 */
	union {
		uint32_t curve_gain_b_4; // word name
		struct {
			uint32_t curve_gain_y_curvature_b : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_B_5 8'h74 */
	union {
		uint32_t curve_gain_b_5; // word name
		struct {
			uint32_t curve_gain_tilt_2s_b : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* CURVE_GAIN_S_0 8'h78 */
	union {
		uint32_t curve_gain_s_0; // word name
		struct {
			uint32_t curve_gain_origin_s : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_S_1 8'h7C */
	union {
		uint32_t curve_gain_s_1; // word name
		struct {
			uint32_t curve_gain_x_trend_2s_s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_S_2 8'h80 */
	union {
		uint32_t curve_gain_s_2; // word name
		struct {
			uint32_t curve_gain_y_trend_2s_s : 20;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_GAIN_S_3 8'h84 */
	union {
		uint32_t curve_gain_s_3; // word name
		struct {
			uint32_t curve_gain_x_curvature_s : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_S_4 8'h88 */
	union {
		uint32_t curve_gain_s_4; // word name
		struct {
			uint32_t curve_gain_y_curvature_s : 26;
			uint32_t : 6; // padding bits
		};
	};
	/* CURVE_GAIN_S_5 8'h8C */
	union {
		uint32_t curve_gain_s_5; // word name
		struct {
			uint32_t curve_gain_tilt_2s_s : 27;
			uint32_t : 5; // padding bits
		};
	};
	/* TABLE_MODE 8'h90 */
	union {
		uint32_t table_mode; // word name
		struct {
			uint32_t table_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t table_merge_en : 1;
			uint32_t : 7; // padding bits
			uint32_t table_gain_prec_m8 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_GAIN_MOD 8'h94 */
	union {
		uint32_t table_gain_mod; // word name
		struct {
			uint32_t gain_mod : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_POS_H_0 8'h98 */
	union {
		uint32_t table_pos_h_0; // word name
		struct {
			uint32_t hori_start_int : 6;
			uint32_t : 2; // padding bits
			uint32_t hori_start_frac : 17;
			uint32_t : 7; // padding bits
		};
	};
	/* TABLE_POS_H_1 8'h9C */
	union {
		uint32_t table_pos_h_1; // word name
		struct {
			uint32_t hori_step : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_POS_V_0 8'hA0 */
	union {
		uint32_t table_pos_v_0; // word name
		struct {
			uint32_t verti_start_int : 6;
			uint32_t : 2; // padding bits
			uint32_t verti_start_frac : 17;
			uint32_t : 7; // padding bits
		};
	};
	/* TABLE_POS_V_1 8'hA4 */
	union {
		uint32_t table_pos_v_1; // word name
		struct {
			uint32_t verti_step : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CSR2SRAM_SEL 8'hA8 */
	union {
		uint32_t csr2sram_sel; // word name
		struct {
			uint32_t lsc_csr_2_sram_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EE_W_ADDR 8'hAC */
	union {
		uint32_t table_ee_w_addr; // word name
		struct {
			uint32_t lsc_table_ee_w_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EE_W_DATA 8'hB0 */
	union {
		uint32_t table_ee_w_data; // word name
		struct {
			uint32_t lsc_table_ee_w_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EO_W_ADDR 8'hB4 */
	union {
		uint32_t table_eo_w_addr; // word name
		struct {
			uint32_t lsc_table_eo_w_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EO_W_DATA 8'hB8 */
	union {
		uint32_t table_eo_w_data; // word name
		struct {
			uint32_t lsc_table_eo_w_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OE_W_ADDR 8'hBC */
	union {
		uint32_t table_oe_w_addr; // word name
		struct {
			uint32_t lsc_table_oe_w_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OE_W_DATA 8'hC0 */
	union {
		uint32_t table_oe_w_data; // word name
		struct {
			uint32_t lsc_table_oe_w_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OO_W_ADDR 8'hC4 */
	union {
		uint32_t table_oo_w_addr; // word name
		struct {
			uint32_t lsc_table_oo_w_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OO_W_DATA 8'hC8 */
	union {
		uint32_t table_oo_w_data; // word name
		struct {
			uint32_t lsc_table_oo_w_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EE_R_ADDR 8'hCC */
	union {
		uint32_t table_ee_r_addr; // word name
		struct {
			uint32_t lsc_table_ee_r_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EE_R_DATA 8'hD0 */
	union {
		uint32_t table_ee_r_data; // word name
		struct {
			uint32_t lsc_table_ee_r_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EO_R_ADDR 8'hD4 */
	union {
		uint32_t table_eo_r_addr; // word name
		struct {
			uint32_t lsc_table_eo_r_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_EO_R_DATA 8'hD8 */
	union {
		uint32_t table_eo_r_data; // word name
		struct {
			uint32_t lsc_table_eo_r_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OE_R_ADDR 8'hDC */
	union {
		uint32_t table_oe_r_addr; // word name
		struct {
			uint32_t lsc_table_oe_r_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OE_R_DATA 8'hE0 */
	union {
		uint32_t table_oe_r_data; // word name
		struct {
			uint32_t lsc_table_oe_r_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OO_R_ADDR 8'hE4 */
	union {
		uint32_t table_oo_r_addr; // word name
		struct {
			uint32_t lsc_table_oo_r_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TABLE_OO_R_DATA 8'hE8 */
	union {
		uint32_t table_oo_r_data; // word name
		struct {
			uint32_t lsc_table_oo_r_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 8'hEC */
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
} CsrBankLsc;

#endif