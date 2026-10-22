/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DCC_H_
#define CSR_TABLE_DCC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dcc[] = {
	// WORD wore_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORE_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_format
	{ "cfa_mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "CFA_FORMAT", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD wore_cfa_phase_0
	{ "cfa_phase_0", 0x00000014, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_1", 0x00000014, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_2", 0x00000014, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_3", 0x00000014, 26, 24, CSR_RW, 0x00000000 },
	{ "WORE_CFA_PHASE_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_1
	{ "cfa_phase_4", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_5", 0x00000018, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_6", 0x00000018, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_7", 0x00000018, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_2
	{ "cfa_phase_8", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_9", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_10", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_11", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_3
	{ "cfa_phase_12", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_13", 0x00000020, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_14", 0x00000020, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_15", 0x00000020, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_3", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000024, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000024, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD wore_mode
	{ "mode", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "WORE_MODE", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_0
	{ "gain_g0", 0x0000002C, 18, 0, CSR_RW, 0x00000400 },
	{ "GAIN_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_1
	{ "gain_r", 0x00000030, 18, 0, CSR_RW, 0x00000400 },
	{ "GAIN_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_2
	{ "gain_b", 0x00000034, 18, 0, CSR_RW, 0x00000400 },
	{ "GAIN_2", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_3
	{ "gain_g1", 0x00000038, 18, 0, CSR_RW, 0x00000400 },
	{ "GAIN_3", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_4
	{ "gain_s", 0x0000003C, 18, 0, CSR_RW, 0x00000400 },
	{ "GAIN_4", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD offset_0
	{ "offset_g0_2s", 0x00000040, 16, 0, CSR_RW, 0x00000000 },
	{ "OFFSET_0", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD offset_1
	{ "offset_r_2s", 0x00000044, 16, 0, CSR_RW, 0x00000000 },
	{ "OFFSET_1", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD offset_2
	{ "offset_b_2s", 0x00000048, 16, 0, CSR_RW, 0x00000000 },
	{ "OFFSET_2", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD offset_3
	{ "offset_g1_2s", 0x0000004C, 16, 0, CSR_RW, 0x00000000 },
	{ "OFFSET_3", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD offset_4
	{ "offset_s_2s", 0x00000050, 16, 0, CSR_RW, 0x00000000 },
	{ "OFFSET_4", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_0
	{ "mapping_curve_g0_y_0", 0x00000054, 15, 0, CSR_RW, 0x00000100 },
	{ "mapping_curve_g0_y_1", 0x00000054, 31, 16, CSR_RW, 0x00000200 },
	{ "CURVE_G0_Y_0", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_1
	{ "mapping_curve_g0_y_2", 0x00000058, 15, 0, CSR_RW, 0x00000300 },
	{ "mapping_curve_g0_y_3", 0x00000058, 31, 16, CSR_RW, 0x00000400 },
	{ "CURVE_G0_Y_1", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_2
	{ "mapping_curve_g0_y_4", 0x0000005C, 15, 0, CSR_RW, 0x00000800 },
	{ "mapping_curve_g0_y_5", 0x0000005C, 31, 16, CSR_RW, 0x00000C00 },
	{ "CURVE_G0_Y_2", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_3
	{ "mapping_curve_g0_y_6", 0x00000060, 15, 0, CSR_RW, 0x00001000 },
	{ "mapping_curve_g0_y_7", 0x00000060, 31, 16, CSR_RW, 0x00001800 },
	{ "CURVE_G0_Y_3", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_4
	{ "mapping_curve_g0_y_8", 0x00000064, 15, 0, CSR_RW, 0x00002000 },
	{ "mapping_curve_g0_y_9", 0x00000064, 31, 16, CSR_RW, 0x00002800 },
	{ "CURVE_G0_Y_4", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_5
	{ "mapping_curve_g0_y_10", 0x00000068, 15, 0, CSR_RW, 0x00003000 },
	{ "mapping_curve_g0_y_11", 0x00000068, 31, 16, CSR_RW, 0x00004000 },
	{ "CURVE_G0_Y_5", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_6
	{ "mapping_curve_g0_y_12", 0x0000006C, 15, 0, CSR_RW, 0x00006000 },
	{ "mapping_curve_g0_y_13", 0x0000006C, 31, 16, CSR_RW, 0x00008000 },
	{ "CURVE_G0_Y_6", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g0_y_7
	{ "mapping_curve_g0_y_14", 0x00000070, 15, 0, CSR_RW, 0x0000C000 },
	{ "CURVE_G0_Y_7", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_0
	{ "mapping_curve_r_y_0", 0x00000074, 15, 0, CSR_RW, 0x00000100 },
	{ "mapping_curve_r_y_1", 0x00000074, 31, 16, CSR_RW, 0x00000200 },
	{ "CURVE_R_Y_0", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_1
	{ "mapping_curve_r_y_2", 0x00000078, 15, 0, CSR_RW, 0x00000300 },
	{ "mapping_curve_r_y_3", 0x00000078, 31, 16, CSR_RW, 0x00000400 },
	{ "CURVE_R_Y_1", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_2
	{ "mapping_curve_r_y_4", 0x0000007C, 15, 0, CSR_RW, 0x00000800 },
	{ "mapping_curve_r_y_5", 0x0000007C, 31, 16, CSR_RW, 0x00000C00 },
	{ "CURVE_R_Y_2", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_3
	{ "mapping_curve_r_y_6", 0x00000080, 15, 0, CSR_RW, 0x00001000 },
	{ "mapping_curve_r_y_7", 0x00000080, 31, 16, CSR_RW, 0x00001800 },
	{ "CURVE_R_Y_3", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_4
	{ "mapping_curve_r_y_8", 0x00000084, 15, 0, CSR_RW, 0x00002000 },
	{ "mapping_curve_r_y_9", 0x00000084, 31, 16, CSR_RW, 0x00002800 },
	{ "CURVE_R_Y_4", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_5
	{ "mapping_curve_r_y_10", 0x00000088, 15, 0, CSR_RW, 0x00003000 },
	{ "mapping_curve_r_y_11", 0x00000088, 31, 16, CSR_RW, 0x00004000 },
	{ "CURVE_R_Y_5", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_6
	{ "mapping_curve_r_y_12", 0x0000008C, 15, 0, CSR_RW, 0x00006000 },
	{ "mapping_curve_r_y_13", 0x0000008C, 31, 16, CSR_RW, 0x00008000 },
	{ "CURVE_R_Y_6", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_r_y_7
	{ "mapping_curve_r_y_14", 0x00000090, 15, 0, CSR_RW, 0x0000C000 },
	{ "CURVE_R_Y_7", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_0
	{ "mapping_curve_b_y_0", 0x00000094, 15, 0, CSR_RW, 0x00000100 },
	{ "mapping_curve_b_y_1", 0x00000094, 31, 16, CSR_RW, 0x00000200 },
	{ "CURVE_B_Y_0", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_1
	{ "mapping_curve_b_y_2", 0x00000098, 15, 0, CSR_RW, 0x00000300 },
	{ "mapping_curve_b_y_3", 0x00000098, 31, 16, CSR_RW, 0x00000400 },
	{ "CURVE_B_Y_1", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_2
	{ "mapping_curve_b_y_4", 0x0000009C, 15, 0, CSR_RW, 0x00000800 },
	{ "mapping_curve_b_y_5", 0x0000009C, 31, 16, CSR_RW, 0x00000C00 },
	{ "CURVE_B_Y_2", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_3
	{ "mapping_curve_b_y_6", 0x000000A0, 15, 0, CSR_RW, 0x00001000 },
	{ "mapping_curve_b_y_7", 0x000000A0, 31, 16, CSR_RW, 0x00001800 },
	{ "CURVE_B_Y_3", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_4
	{ "mapping_curve_b_y_8", 0x000000A4, 15, 0, CSR_RW, 0x00002000 },
	{ "mapping_curve_b_y_9", 0x000000A4, 31, 16, CSR_RW, 0x00002800 },
	{ "CURVE_B_Y_4", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_5
	{ "mapping_curve_b_y_10", 0x000000A8, 15, 0, CSR_RW, 0x00003000 },
	{ "mapping_curve_b_y_11", 0x000000A8, 31, 16, CSR_RW, 0x00004000 },
	{ "CURVE_B_Y_5", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_6
	{ "mapping_curve_b_y_12", 0x000000AC, 15, 0, CSR_RW, 0x00006000 },
	{ "mapping_curve_b_y_13", 0x000000AC, 31, 16, CSR_RW, 0x00008000 },
	{ "CURVE_B_Y_6", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_b_y_7
	{ "mapping_curve_b_y_14", 0x000000B0, 15, 0, CSR_RW, 0x0000C000 },
	{ "CURVE_B_Y_7", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_0
	{ "mapping_curve_g1_y_0", 0x000000B4, 15, 0, CSR_RW, 0x00000100 },
	{ "mapping_curve_g1_y_1", 0x000000B4, 31, 16, CSR_RW, 0x00000200 },
	{ "CURVE_G1_Y_0", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_1
	{ "mapping_curve_g1_y_2", 0x000000B8, 15, 0, CSR_RW, 0x00000300 },
	{ "mapping_curve_g1_y_3", 0x000000B8, 31, 16, CSR_RW, 0x00000400 },
	{ "CURVE_G1_Y_1", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_2
	{ "mapping_curve_g1_y_4", 0x000000BC, 15, 0, CSR_RW, 0x00000800 },
	{ "mapping_curve_g1_y_5", 0x000000BC, 31, 16, CSR_RW, 0x00000C00 },
	{ "CURVE_G1_Y_2", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_3
	{ "mapping_curve_g1_y_6", 0x000000C0, 15, 0, CSR_RW, 0x00001000 },
	{ "mapping_curve_g1_y_7", 0x000000C0, 31, 16, CSR_RW, 0x00001800 },
	{ "CURVE_G1_Y_3", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_4
	{ "mapping_curve_g1_y_8", 0x000000C4, 15, 0, CSR_RW, 0x00002000 },
	{ "mapping_curve_g1_y_9", 0x000000C4, 31, 16, CSR_RW, 0x00002800 },
	{ "CURVE_G1_Y_4", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_5
	{ "mapping_curve_g1_y_10", 0x000000C8, 15, 0, CSR_RW, 0x00003000 },
	{ "mapping_curve_g1_y_11", 0x000000C8, 31, 16, CSR_RW, 0x00004000 },
	{ "CURVE_G1_Y_5", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_6
	{ "mapping_curve_g1_y_12", 0x000000CC, 15, 0, CSR_RW, 0x00006000 },
	{ "mapping_curve_g1_y_13", 0x000000CC, 31, 16, CSR_RW, 0x00008000 },
	{ "CURVE_G1_Y_6", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_g1_y_7
	{ "mapping_curve_g1_y_14", 0x000000D0, 15, 0, CSR_RW, 0x0000C000 },
	{ "CURVE_G1_Y_7", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_0
	{ "mapping_curve_s_y_0", 0x000000D4, 15, 0, CSR_RW, 0x00000100 },
	{ "mapping_curve_s_y_1", 0x000000D4, 31, 16, CSR_RW, 0x00000200 },
	{ "CURVE_S_Y_0", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_1
	{ "mapping_curve_s_y_2", 0x000000D8, 15, 0, CSR_RW, 0x00000300 },
	{ "mapping_curve_s_y_3", 0x000000D8, 31, 16, CSR_RW, 0x00000400 },
	{ "CURVE_S_Y_1", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_2
	{ "mapping_curve_s_y_4", 0x000000DC, 15, 0, CSR_RW, 0x00000800 },
	{ "mapping_curve_s_y_5", 0x000000DC, 31, 16, CSR_RW, 0x00000C00 },
	{ "CURVE_S_Y_2", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_3
	{ "mapping_curve_s_y_6", 0x000000E0, 15, 0, CSR_RW, 0x00001000 },
	{ "mapping_curve_s_y_7", 0x000000E0, 31, 16, CSR_RW, 0x00001800 },
	{ "CURVE_S_Y_3", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_4
	{ "mapping_curve_s_y_8", 0x000000E4, 15, 0, CSR_RW, 0x00002000 },
	{ "mapping_curve_s_y_9", 0x000000E4, 31, 16, CSR_RW, 0x00002800 },
	{ "CURVE_S_Y_4", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_5
	{ "mapping_curve_s_y_10", 0x000000E8, 15, 0, CSR_RW, 0x00003000 },
	{ "mapping_curve_s_y_11", 0x000000E8, 31, 16, CSR_RW, 0x00004000 },
	{ "CURVE_S_Y_5", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_6
	{ "mapping_curve_s_y_12", 0x000000EC, 15, 0, CSR_RW, 0x00006000 },
	{ "mapping_curve_s_y_13", 0x000000EC, 31, 16, CSR_RW, 0x00008000 },
	{ "CURVE_S_Y_6", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD curve_s_y_7
	{ "mapping_curve_s_y_14", 0x000000F0, 15, 0, CSR_RW, 0x0000C000 },
	{ "CURVE_S_Y_7", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wore_debug_mon_sel
	{ "debug_mon_sel", 0x000000F4, 1, 0, CSR_RW, 0x00000000 },
	{ "WORE_DEBUG_MON_SEL", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DCC_H_
