#ifndef CSR_BANK_DCC_H_
#define CSR_BANK_DCC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dcc  ***/
typedef struct csr_bank_dcc {
	/* WORE_FRAME_START 16'h0000 */
	union {
		uint32_t wore_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 16'h0004 */
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
	/* STATUS 16'h0008 */
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
	/* IRQ_MASK 16'h000C */
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
	/* CFA_FORMAT 16'h0010 */
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
	/* WORE_CFA_PHASE_0 16'h0014 */
	union {
		uint32_t wore_cfa_phase_0; // word name
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
	/* WORD_CFA_PHASE_1 16'h0018 */
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
	/* WORD_CFA_PHASE_2 16'h001C */
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
	/* WORD_CFA_PHASE_3 16'h0020 */
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
	/* RESOLUTION 16'h0024 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WORE_MODE 16'h0028 */
	union {
		uint32_t wore_mode; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_0 16'h002C */
	union {
		uint32_t gain_0; // word name
		struct {
			uint32_t gain_g0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_1 16'h0030 */
	union {
		uint32_t gain_1; // word name
		struct {
			uint32_t gain_r : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_2 16'h0034 */
	union {
		uint32_t gain_2; // word name
		struct {
			uint32_t gain_b : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_3 16'h0038 */
	union {
		uint32_t gain_3; // word name
		struct {
			uint32_t gain_g1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GAIN_4 16'h003C */
	union {
		uint32_t gain_4; // word name
		struct {
			uint32_t gain_s : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_0 16'h0040 */
	union {
		uint32_t offset_0; // word name
		struct {
			uint32_t offset_g0_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_1 16'h0044 */
	union {
		uint32_t offset_1; // word name
		struct {
			uint32_t offset_r_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_2 16'h0048 */
	union {
		uint32_t offset_2; // word name
		struct {
			uint32_t offset_b_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_3 16'h004C */
	union {
		uint32_t offset_3; // word name
		struct {
			uint32_t offset_g1_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OFFSET_4 16'h0050 */
	union {
		uint32_t offset_4; // word name
		struct {
			uint32_t offset_s_2s : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_Y_INI_0 16'h0054 */
	union {
		uint32_t curve_y_ini_0; // word name
		struct {
			uint32_t mapping_curve_g0_y_ini : 16;
			uint32_t mapping_curve_r_y_ini : 16;
		};
	};
	/* CURVE_Y_INI_1 16'h0058 */
	union {
		uint32_t curve_y_ini_1; // word name
		struct {
			uint32_t mapping_curve_b_y_ini : 16;
			uint32_t mapping_curve_g1_y_ini : 16;
		};
	};
	/* CURVE_Y_INI_2 16'h005C */
	union {
		uint32_t curve_y_ini_2; // word name
		struct {
			uint32_t mapping_curve_s_y_ini : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CURVE_G0_Y_0 16'h0060 */
	union {
		uint32_t curve_g0_y_0; // word name
		struct {
			uint32_t mapping_curve_g0_y_0 : 16;
			uint32_t mapping_curve_g0_y_1 : 16;
		};
	};
	/* CURVE_G0_Y_1 16'h0064 */
	union {
		uint32_t curve_g0_y_1; // word name
		struct {
			uint32_t mapping_curve_g0_y_2 : 16;
			uint32_t mapping_curve_g0_y_3 : 16;
		};
	};
	/* CURVE_G0_Y_2 16'h0068 */
	union {
		uint32_t curve_g0_y_2; // word name
		struct {
			uint32_t mapping_curve_g0_y_4 : 16;
			uint32_t mapping_curve_g0_y_5 : 16;
		};
	};
	/* CURVE_G0_Y_3 16'h006C */
	union {
		uint32_t curve_g0_y_3; // word name
		struct {
			uint32_t mapping_curve_g0_y_6 : 16;
			uint32_t mapping_curve_g0_y_7 : 16;
		};
	};
	/* CURVE_G0_X_0 16'h0070 */
	union {
		uint32_t curve_g0_x_0; // word name
		struct {
			uint32_t mapping_curve_g0_x_0 : 16;
			uint32_t mapping_curve_g0_x_1 : 16;
		};
	};
	/* CURVE_G0_X_1 16'h0074 */
	union {
		uint32_t curve_g0_x_1; // word name
		struct {
			uint32_t mapping_curve_g0_x_2 : 16;
			uint32_t mapping_curve_g0_x_3 : 16;
		};
	};
	/* CURVE_G0_X_2 16'h0078 */
	union {
		uint32_t curve_g0_x_2; // word name
		struct {
			uint32_t mapping_curve_g0_x_4 : 16;
			uint32_t mapping_curve_g0_x_5 : 16;
		};
	};
	/* CURVE_G0_X_3 16'h007C */
	union {
		uint32_t curve_g0_x_3; // word name
		struct {
			uint32_t mapping_curve_g0_x_6 : 16;
			uint32_t mapping_curve_g0_x_7 : 16;
		};
	};
	/* CURVE_G0_M_0 16'h0080 */
	union {
		uint32_t curve_g0_m_0; // word name
		struct {
			uint32_t mapping_curve_g0_m_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g0_m_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g0_m_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g0_m_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_G0_M_1 16'h0084 */
	union {
		uint32_t curve_g0_m_1; // word name
		struct {
			uint32_t mapping_curve_g0_m_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g0_m_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g0_m_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g0_m_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_R_Y_0 16'h0088 */
	union {
		uint32_t curve_r_y_0; // word name
		struct {
			uint32_t mapping_curve_r_y_0 : 16;
			uint32_t mapping_curve_r_y_1 : 16;
		};
	};
	/* CURVE_R_Y_1 16'h008C */
	union {
		uint32_t curve_r_y_1; // word name
		struct {
			uint32_t mapping_curve_r_y_2 : 16;
			uint32_t mapping_curve_r_y_3 : 16;
		};
	};
	/* CURVE_R_Y_2 16'h0090 */
	union {
		uint32_t curve_r_y_2; // word name
		struct {
			uint32_t mapping_curve_r_y_4 : 16;
			uint32_t mapping_curve_r_y_5 : 16;
		};
	};
	/* CURVE_R_Y_3 16'h0094 */
	union {
		uint32_t curve_r_y_3; // word name
		struct {
			uint32_t mapping_curve_r_y_6 : 16;
			uint32_t mapping_curve_r_y_7 : 16;
		};
	};
	/* CURVE_R_X_0 16'h0098 */
	union {
		uint32_t curve_r_x_0; // word name
		struct {
			uint32_t mapping_curve_r_x_0 : 16;
			uint32_t mapping_curve_r_x_1 : 16;
		};
	};
	/* CURVE_R_X_1 16'h009C */
	union {
		uint32_t curve_r_x_1; // word name
		struct {
			uint32_t mapping_curve_r_x_2 : 16;
			uint32_t mapping_curve_r_x_3 : 16;
		};
	};
	/* CURVE_R_X_2 16'h00A0 */
	union {
		uint32_t curve_r_x_2; // word name
		struct {
			uint32_t mapping_curve_r_x_4 : 16;
			uint32_t mapping_curve_r_x_5 : 16;
		};
	};
	/* CURVE_R_X_3 16'h00A4 */
	union {
		uint32_t curve_r_x_3; // word name
		struct {
			uint32_t mapping_curve_r_x_6 : 16;
			uint32_t mapping_curve_r_x_7 : 16;
		};
	};
	/* CURVE_R_M_0 16'h00A8 */
	union {
		uint32_t curve_r_m_0; // word name
		struct {
			uint32_t mapping_curve_r_m_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_r_m_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_r_m_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_r_m_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_R_M_1 16'h00AC */
	union {
		uint32_t curve_r_m_1; // word name
		struct {
			uint32_t mapping_curve_r_m_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_r_m_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_r_m_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_r_m_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_B_Y_0 16'h00B0 */
	union {
		uint32_t curve_b_y_0; // word name
		struct {
			uint32_t mapping_curve_b_y_0 : 16;
			uint32_t mapping_curve_b_y_1 : 16;
		};
	};
	/* CURVE_B_Y_1 16'h00B4 */
	union {
		uint32_t curve_b_y_1; // word name
		struct {
			uint32_t mapping_curve_b_y_2 : 16;
			uint32_t mapping_curve_b_y_3 : 16;
		};
	};
	/* CURVE_B_Y_2 16'h00B8 */
	union {
		uint32_t curve_b_y_2; // word name
		struct {
			uint32_t mapping_curve_b_y_4 : 16;
			uint32_t mapping_curve_b_y_5 : 16;
		};
	};
	/* CURVE_B_Y_3 16'h00BC */
	union {
		uint32_t curve_b_y_3; // word name
		struct {
			uint32_t mapping_curve_b_y_6 : 16;
			uint32_t mapping_curve_b_y_7 : 16;
		};
	};
	/* CURVE_B_X_0 16'h00C0 */
	union {
		uint32_t curve_b_x_0; // word name
		struct {
			uint32_t mapping_curve_b_x_0 : 16;
			uint32_t mapping_curve_b_x_1 : 16;
		};
	};
	/* CURVE_B_X_1 16'h00C4 */
	union {
		uint32_t curve_b_x_1; // word name
		struct {
			uint32_t mapping_curve_b_x_2 : 16;
			uint32_t mapping_curve_b_x_3 : 16;
		};
	};
	/* CURVE_B_X_2 16'h00C8 */
	union {
		uint32_t curve_b_x_2; // word name
		struct {
			uint32_t mapping_curve_b_x_4 : 16;
			uint32_t mapping_curve_b_x_5 : 16;
		};
	};
	/* CURVE_B_X_3 16'h00CC */
	union {
		uint32_t curve_b_x_3; // word name
		struct {
			uint32_t mapping_curve_b_x_6 : 16;
			uint32_t mapping_curve_b_x_7 : 16;
		};
	};
	/* CURVE_B_M_0 16'h00D0 */
	union {
		uint32_t curve_b_m_0; // word name
		struct {
			uint32_t mapping_curve_b_m_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_b_m_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_b_m_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_b_m_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_B_M_1 16'h00D4 */
	union {
		uint32_t curve_b_m_1; // word name
		struct {
			uint32_t mapping_curve_b_m_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_b_m_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_b_m_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_b_m_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_G1_Y_0 16'h00D8 */
	union {
		uint32_t curve_g1_y_0; // word name
		struct {
			uint32_t mapping_curve_g1_y_0 : 16;
			uint32_t mapping_curve_g1_y_1 : 16;
		};
	};
	/* CURVE_G1_Y_1 16'h00DC */
	union {
		uint32_t curve_g1_y_1; // word name
		struct {
			uint32_t mapping_curve_g1_y_2 : 16;
			uint32_t mapping_curve_g1_y_3 : 16;
		};
	};
	/* CURVE_G1_Y_2 16'h00E0 */
	union {
		uint32_t curve_g1_y_2; // word name
		struct {
			uint32_t mapping_curve_g1_y_4 : 16;
			uint32_t mapping_curve_g1_y_5 : 16;
		};
	};
	/* CURVE_G1_Y_3 16'h00E4 */
	union {
		uint32_t curve_g1_y_3; // word name
		struct {
			uint32_t mapping_curve_g1_y_6 : 16;
			uint32_t mapping_curve_g1_y_7 : 16;
		};
	};
	/* CURVE_G1_X_0 16'h00E8 */
	union {
		uint32_t curve_g1_x_0; // word name
		struct {
			uint32_t mapping_curve_g1_x_0 : 16;
			uint32_t mapping_curve_g1_x_1 : 16;
		};
	};
	/* CURVE_G1_X_1 16'h00EC */
	union {
		uint32_t curve_g1_x_1; // word name
		struct {
			uint32_t mapping_curve_g1_x_2 : 16;
			uint32_t mapping_curve_g1_x_3 : 16;
		};
	};
	/* CURVE_G1_X_2 16'h00F0 */
	union {
		uint32_t curve_g1_x_2; // word name
		struct {
			uint32_t mapping_curve_g1_x_4 : 16;
			uint32_t mapping_curve_g1_x_5 : 16;
		};
	};
	/* CURVE_G1_X_3 16'h00F4 */
	union {
		uint32_t curve_g1_x_3; // word name
		struct {
			uint32_t mapping_curve_g1_x_6 : 16;
			uint32_t mapping_curve_g1_x_7 : 16;
		};
	};
	/* CURVE_G1_M_0 16'h00F8 */
	union {
		uint32_t curve_g1_m_0; // word name
		struct {
			uint32_t mapping_curve_g1_m_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g1_m_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g1_m_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g1_m_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_G1_M_1 16'h00FC */
	union {
		uint32_t curve_g1_m_1; // word name
		struct {
			uint32_t mapping_curve_g1_m_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g1_m_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g1_m_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_g1_m_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_S_Y_0 16'h0100 */
	union {
		uint32_t curve_s_y_0; // word name
		struct {
			uint32_t mapping_curve_s_y_0 : 16;
			uint32_t mapping_curve_s_y_1 : 16;
		};
	};
	/* CURVE_S_Y_1 16'h0104 */
	union {
		uint32_t curve_s_y_1; // word name
		struct {
			uint32_t mapping_curve_s_y_2 : 16;
			uint32_t mapping_curve_s_y_3 : 16;
		};
	};
	/* CURVE_S_Y_2 16'h0108 */
	union {
		uint32_t curve_s_y_2; // word name
		struct {
			uint32_t mapping_curve_s_y_4 : 16;
			uint32_t mapping_curve_s_y_5 : 16;
		};
	};
	/* CURVE_S_Y_3 16'h010C */
	union {
		uint32_t curve_s_y_3; // word name
		struct {
			uint32_t mapping_curve_s_y_6 : 16;
			uint32_t mapping_curve_s_y_7 : 16;
		};
	};
	/* CURVE_S_X_0 16'h0110 */
	union {
		uint32_t curve_s_x_0; // word name
		struct {
			uint32_t mapping_curve_s_x_0 : 16;
			uint32_t mapping_curve_s_x_1 : 16;
		};
	};
	/* CURVE_S_X_1 16'h0114 */
	union {
		uint32_t curve_s_x_1; // word name
		struct {
			uint32_t mapping_curve_s_x_2 : 16;
			uint32_t mapping_curve_s_x_3 : 16;
		};
	};
	/* CURVE_S_X_2 16'h0118 */
	union {
		uint32_t curve_s_x_2; // word name
		struct {
			uint32_t mapping_curve_s_x_4 : 16;
			uint32_t mapping_curve_s_x_5 : 16;
		};
	};
	/* CURVE_S_X_3 16'h011C */
	union {
		uint32_t curve_s_x_3; // word name
		struct {
			uint32_t mapping_curve_s_x_6 : 16;
			uint32_t mapping_curve_s_x_7 : 16;
		};
	};
	/* CURVE_S_M_0 16'h0120 */
	union {
		uint32_t curve_s_m_0; // word name
		struct {
			uint32_t mapping_curve_s_m_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_s_m_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_s_m_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_s_m_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* CURVE_S_M_1 16'h0124 */
	union {
		uint32_t curve_s_m_1; // word name
		struct {
			uint32_t mapping_curve_s_m_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_s_m_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_s_m_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t mapping_curve_s_m_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WORE_DEBUG_MON_SEL 16'h0128 */
	union {
		uint32_t wore_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDcc;

#endif