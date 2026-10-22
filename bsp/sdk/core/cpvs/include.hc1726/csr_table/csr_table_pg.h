/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PG_H_
#define CSR_TABLE_PG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pg[] = {
	// WORD ctrl
	{ "start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "stop", 0x00000000, 16, 16, CSR_W1P, 0x00000000 },
	{ "CTRL", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000004, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000004, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD mode_set
	{ "mode", 0x00000008, 1, 0, CSR_RW, 0x00000001 },
	{ "pat_sel", 0x00000008, 9, 8, CSR_RW, 0x00000000 },
	{ "color_space", 0x00000008, 16, 16, CSR_RW, 0x00000001 },
	{ "MODE_SET", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_set
	{ "cfa_mode", 0x0000000C, 1, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase", 0x0000000C, 17, 16, CSR_RW, 0x00000000 },
	{ "CFA_SET", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_0
	{ "cfa_phase0", 0x00000010, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase1", 0x00000010, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase2", 0x00000010, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase3", 0x00000010, 26, 24, CSR_RW, 0x00000000 },
	{ "WORD_CFA_PHASE_0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_1
	{ "cfa_phase4", 0x00000014, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase5", 0x00000014, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase6", 0x00000014, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase7", 0x00000014, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_2
	{ "cfa_phase8", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase9", 0x00000018, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase10", 0x00000018, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase11", 0x00000018, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_2", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_3
	{ "cfa_phase12", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase13", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase14", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase15", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_3", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_x
	{ "roi_sx", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_ex", 0x00000020, 31, 16, CSR_RW, 0x000003C0 },
	{ "ROI_X", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y
	{ "roi_sy", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_ey", 0x00000024, 31, 16, CSR_RW, 0x0000021C },
	{ "ROI_Y", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_x_cnt_ini
	{ "x_cnt_ini", 0x00000028, 15, 0, CSR_RW, 0x00000000 },
	{ "WORD_X_CNT_INI", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_rp_ini_0
	{ "rp_initial_0", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "rp_initial_1", 0x0000002C, 31, 16, CSR_RW, 0x00000000 },
	{ "WORD_RP_INI_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_ini_1
	{ "rp_initial_2", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "rp_initial_3", 0x00000030, 31, 16, CSR_RW, 0x00000000 },
	{ "RP_INI_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_h_0
	{ "rp_delta_h_0_2s", 0x00000034, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_H_0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_h_1
	{ "rp_delta_h_1_2s", 0x00000038, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_H_1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_h_2
	{ "rp_delta_h_2_2s", 0x0000003C, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_H_2", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_h_3
	{ "rp_delta_h_3_2s", 0x00000040, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_H_3", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_v_0
	{ "rp_delta_v_0_2s", 0x00000044, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_V_0", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_v_1
	{ "rp_delta_v_1_2s", 0x00000048, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_V_1", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_v_2
	{ "rp_delta_v_2_2s", 0x0000004C, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_V_2", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_delta_v_3
	{ "rp_delta_v_3_2s", 0x00000050, 16, 0, CSR_RW, 0x0000001E },
	{ "RP_DELTA_V_3", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD rp_of_enable
	{ "rp_overflow_enable", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "RP_OF_ENABLE", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cb_bar_delta
	{ "cb_bar_delta", 0x00000058, 13, 0, CSR_RW, 0x000000D5 },
	{ "WORD_CB_BAR_DELTA", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_00
	{ "bar_0_ch0", 0x0000005C, 15, 0, CSR_RW, 0x00000000 },
	{ "bar_1_ch0", 0x0000005C, 31, 16, CSR_RW, 0x00004000 },
	{ "COLOR_TABLE_00", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_01
	{ "bar_2_ch0", 0x00000060, 15, 0, CSR_RW, 0x00008000 },
	{ "bar_3_ch0", 0x00000060, 31, 16, CSR_RW, 0x0000FFFF },
	{ "COLOR_TABLE_01", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_02
	{ "bar_4_ch0", 0x00000064, 15, 0, CSR_RW, 0x00000000 },
	{ "bar_5_ch0", 0x00000064, 31, 16, CSR_RW, 0x00004000 },
	{ "COLOR_TABLE_02", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_03
	{ "bar_6_ch0", 0x00000068, 15, 0, CSR_RW, 0x00008000 },
	{ "bar_7_ch0", 0x00000068, 31, 16, CSR_RW, 0x0000FFFF },
	{ "COLOR_TABLE_03", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_04
	{ "bar_8_ch0", 0x0000006C, 15, 0, CSR_RW, 0x00000000 },
	{ "bar_0_ch1", 0x0000006C, 31, 16, CSR_RW, 0x00000000 },
	{ "COLOR_TABLE_04", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_05
	{ "bar_1_ch1", 0x00000070, 15, 0, CSR_RW, 0x00004000 },
	{ "bar_2_ch1", 0x00000070, 31, 16, CSR_RW, 0x00008000 },
	{ "COLOR_TABLE_05", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_06
	{ "bar_3_ch1", 0x00000074, 15, 0, CSR_RW, 0x0000FFFF },
	{ "bar_4_ch1", 0x00000074, 31, 16, CSR_RW, 0x00000000 },
	{ "COLOR_TABLE_06", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_07
	{ "bar_5_ch1", 0x00000078, 15, 0, CSR_RW, 0x00004000 },
	{ "bar_6_ch1", 0x00000078, 31, 16, CSR_RW, 0x00008000 },
	{ "COLOR_TABLE_07", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_08
	{ "bar_7_ch1", 0x0000007C, 15, 0, CSR_RW, 0x0000FFFF },
	{ "bar_8_ch1", 0x0000007C, 31, 16, CSR_RW, 0x00000000 },
	{ "COLOR_TABLE_08", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_09
	{ "bar_0_ch2", 0x00000080, 15, 0, CSR_RW, 0x00000000 },
	{ "bar_1_ch2", 0x00000080, 31, 16, CSR_RW, 0x00004000 },
	{ "COLOR_TABLE_09", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_10
	{ "bar_2_ch2", 0x00000084, 15, 0, CSR_RW, 0x00008000 },
	{ "bar_3_ch2", 0x00000084, 31, 16, CSR_RW, 0x0000FFFF },
	{ "COLOR_TABLE_10", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_11
	{ "bar_4_ch2", 0x00000088, 15, 0, CSR_RW, 0x00000000 },
	{ "bar_5_ch2", 0x00000088, 31, 16, CSR_RW, 0x00004000 },
	{ "COLOR_TABLE_11", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_12
	{ "bar_6_ch2", 0x0000008C, 15, 0, CSR_RW, 0x00008000 },
	{ "bar_7_ch2", 0x0000008C, 31, 16, CSR_RW, 0x0000FFFF },
	{ "COLOR_TABLE_12", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD color_table_13
	{ "bar_8_ch2", 0x00000090, 15, 0, CSR_RW, 0x00000000 },
	{ "COLOR_TABLE_13", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD line_int_0
	{ "line_intensity_00", 0x00000094, 15, 0, CSR_RW, 0x00001000 },
	{ "line_intensity_01", 0x00000094, 31, 16, CSR_RW, 0x00001000 },
	{ "LINE_INT_0", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD line_int_1
	{ "line_intensity_10", 0x00000098, 15, 0, CSR_RW, 0x00001000 },
	{ "line_intensity_11", 0x00000098, 31, 16, CSR_RW, 0x00001000 },
	{ "LINE_INT_1", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD block_int_0
	{ "block_intensity_00", 0x0000009C, 15, 0, CSR_RW, 0x0000EB00 },
	{ "block_intensity_01", 0x0000009C, 31, 16, CSR_RW, 0x0000EB00 },
	{ "BLOCK_INT_0", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD block_int_1
	{ "block_intensity_10", 0x000000A0, 15, 0, CSR_RW, 0x0000EB00 },
	{ "block_intensity_11", 0x000000A0, 31, 16, CSR_RW, 0x0000EB00 },
	{ "BLOCK_INT_1", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_line_width
	{ "line_width", 0x000000A4, 15, 0, CSR_RW, 0x00000004 },
	{ "WORD_LINE_WIDTH", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD block_bw
	{ "block_side_length_bw", 0x000000A8, 3, 0, CSR_RW, 0x00000005 },
	{ "BLOCK_BW", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD line_mov
	{ "line_moving", 0x000000AC, 0, 0, CSR_RW, 0x00000000 },
	{ "LINE_MOV", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x000000B0, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PG_H_
