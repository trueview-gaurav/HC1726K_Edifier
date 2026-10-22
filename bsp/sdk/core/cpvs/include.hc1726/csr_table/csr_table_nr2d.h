/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_NR2D_H_
#define CSR_TABLE_NR2D_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_nr2d[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "y_mode", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "c_mode", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "mode", 0x00000010, 17, 16, CSR_RW, 0x00000000 },
	{ "ink_num", 0x00000010, 28, 24, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000014, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000014, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_set
	{ "demo_en", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "DEMO_SET", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_x
	{ "demo_x_min", 0x0000001C, 15, 0, CSR_RW, 0x00000000 },
	{ "demo_x_max", 0x0000001C, 31, 16, CSR_RW, 0x00000000 },
	{ "DEMO_X", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_y
	{ "demo_y_min", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "demo_y_max", 0x00000020, 31, 16, CSR_RW, 0x00000000 },
	{ "DEMO_Y", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_mon
	{ "debug_mon_sel", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_MON", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_00
	{ "chroma_control_gain_x_0", 0x00000028, 8, 0, CSR_RW, 0x0000000A },
	{ "chroma_control_gain_x_1", 0x00000028, 24, 16, CSR_RW, 0x0000000F },
	{ "NR2D_00", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_01
	{ "chroma_control_gain_y_0", 0x0000002C, 8, 0, CSR_RW, 0x00000080 },
	{ "chroma_control_gain_y_1", 0x0000002C, 24, 16, CSR_RW, 0x000000C0 },
	{ "NR2D_01", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_02
	{ "chroma_control_gain_m", 0x00000030, 13, 0, CSR_RW, 0x00000333 },
	{ "NR2D_02", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_03
	{ "luma_lut_x_0", 0x00000034, 7, 0, CSR_RW, 0x00000008 },
	{ "luma_lut_x_1", 0x00000034, 15, 8, CSR_RW, 0x00000010 },
	{ "luma_lut_x_2", 0x00000034, 23, 16, CSR_RW, 0x00000020 },
	{ "luma_lut_x_3", 0x00000034, 31, 24, CSR_RW, 0x00000040 },
	{ "NR2D_03", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_04
	{ "luma_lut_x_4", 0x00000038, 7, 0, CSR_RW, 0x000000FF },
	{ "NR2D_04", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_05
	{ "luma_lut_y_ini", 0x0000003C, 7, 0, CSR_RW, 0x00000080 },
	{ "luma_lut_y_0", 0x0000003C, 15, 8, CSR_RW, 0x00000080 },
	{ "luma_lut_y_1", 0x0000003C, 23, 16, CSR_RW, 0x00000080 },
	{ "luma_lut_y_2", 0x0000003C, 31, 24, CSR_RW, 0x00000080 },
	{ "NR2D_05", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_06
	{ "luma_lut_y_3", 0x00000040, 7, 0, CSR_RW, 0x00000080 },
	{ "luma_lut_y_4", 0x00000040, 15, 8, CSR_RW, 0x00000080 },
	{ "NR2D_06", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_07
	{ "luma_lut_m_0_2s", 0x00000044, 9, 0, CSR_RW, 0x00000000 },
	{ "luma_lut_m_1_2s", 0x00000044, 19, 10, CSR_RW, 0x00000000 },
	{ "luma_lut_m_2_2s", 0x00000044, 29, 20, CSR_RW, 0x00000000 },
	{ "NR2D_07", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_08
	{ "luma_lut_m_3_2s", 0x00000048, 9, 0, CSR_RW, 0x00000000 },
	{ "luma_lut_m_4_2s", 0x00000048, 19, 10, CSR_RW, 0x00000000 },
	{ "NR2D_08", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_09
	{ "edge_confidence_x_0", 0x0000004C, 13, 0, CSR_RW, 0x0000012C },
	{ "edge_confidence_x_1", 0x0000004C, 29, 16, CSR_RW, 0x00000190 },
	{ "NR2D_09", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_10
	{ "edge_confidence_y_0", 0x00000050, 7, 0, CSR_RW, 0x00000000 },
	{ "edge_confidence_y_1", 0x00000050, 15, 8, CSR_RW, 0x00000080 },
	{ "NR2D_10", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_11
	{ "edge_confidence_m", 0x00000054, 13, 0, CSR_RW, 0x0000003B },
	{ "NR2D_11", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_12
	{ "luma_nlm_weight_th_2s", 0x00000058, 9, 0, CSR_RW, 0x00000008 },
	{ "chroma_nlm_weight_th_2s", 0x00000058, 25, 16, CSR_RW, 0x00000096 },
	{ "NR2D_12", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_13
	{ "nlm_lut_x_0", 0x0000005C, 7, 0, CSR_RW, 0x00000004 },
	{ "nlm_lut_x_1", 0x0000005C, 15, 8, CSR_RW, 0x00000008 },
	{ "nlm_lut_x_2", 0x0000005C, 23, 16, CSR_RW, 0x0000000C },
	{ "nlm_lut_x_3", 0x0000005C, 31, 24, CSR_RW, 0x00000010 },
	{ "NR2D_13", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_14
	{ "nlm_lut_x_4", 0x00000060, 7, 0, CSR_RW, 0x00000014 },
	{ "nlm_lut_x_5", 0x00000060, 15, 8, CSR_RW, 0x00000018 },
	{ "nlm_lut_x_6", 0x00000060, 23, 16, CSR_RW, 0x0000001C },
	{ "nlm_lut_x_7", 0x00000060, 31, 24, CSR_RW, 0x00000020 },
	{ "NR2D_14", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_15
	{ "nlm_lut_x_8", 0x00000064, 7, 0, CSR_RW, 0x00000024 },
	{ "nlm_lut_x_9", 0x00000064, 15, 8, CSR_RW, 0x00000028 },
	{ "nlm_lut_x_10", 0x00000064, 23, 16, CSR_RW, 0x0000002C },
	{ "nlm_lut_x_11", 0x00000064, 31, 24, CSR_RW, 0x00000030 },
	{ "NR2D_15", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_16
	{ "nlm_lut_x_12", 0x00000068, 7, 0, CSR_RW, 0x00000034 },
	{ "nlm_lut_x_13", 0x00000068, 15, 8, CSR_RW, 0x00000038 },
	{ "nlm_lut_x_14", 0x00000068, 23, 16, CSR_RW, 0x0000003C },
	{ "nlm_lut_x_15", 0x00000068, 31, 24, CSR_RW, 0x00000040 },
	{ "NR2D_16", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_17
	{ "nlm_lut_x_16", 0x0000006C, 7, 0, CSR_RW, 0x00000044 },
	{ "nlm_lut_x_17", 0x0000006C, 15, 8, CSR_RW, 0x00000048 },
	{ "nlm_lut_x_18", 0x0000006C, 23, 16, CSR_RW, 0x0000004C },
	{ "nlm_lut_x_19", 0x0000006C, 31, 24, CSR_RW, 0x00000050 },
	{ "NR2D_17", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_18
	{ "nlm_lut_x_20", 0x00000070, 7, 0, CSR_RW, 0x00000054 },
	{ "nlm_lut_x_21", 0x00000070, 15, 8, CSR_RW, 0x00000058 },
	{ "nlm_lut_x_22", 0x00000070, 23, 16, CSR_RW, 0x0000005C },
	{ "nlm_lut_x_23", 0x00000070, 31, 24, CSR_RW, 0x00000060 },
	{ "NR2D_18", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_19
	{ "nlm_lut_x_24", 0x00000074, 7, 0, CSR_RW, 0x00000064 },
	{ "nlm_lut_x_25", 0x00000074, 15, 8, CSR_RW, 0x00000068 },
	{ "nlm_lut_x_26", 0x00000074, 23, 16, CSR_RW, 0x0000006C },
	{ "nlm_lut_x_27", 0x00000074, 31, 24, CSR_RW, 0x00000070 },
	{ "NR2D_19", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_20
	{ "nlm_lut_x_28", 0x00000078, 7, 0, CSR_RW, 0x00000074 },
	{ "nlm_lut_x_29", 0x00000078, 15, 8, CSR_RW, 0x00000078 },
	{ "nlm_lut_x_30", 0x00000078, 23, 16, CSR_RW, 0x0000007C },
	{ "NR2D_20", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_21
	{ "nlm_lut_y_0", 0x0000007C, 7, 0, CSR_RW, 0x00000080 },
	{ "nlm_lut_y_1", 0x0000007C, 15, 8, CSR_RW, 0x0000007E },
	{ "nlm_lut_y_2", 0x0000007C, 23, 16, CSR_RW, 0x0000007C },
	{ "nlm_lut_y_3", 0x0000007C, 31, 24, CSR_RW, 0x0000007A },
	{ "NR2D_21", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_22
	{ "nlm_lut_y_4", 0x00000080, 7, 0, CSR_RW, 0x00000078 },
	{ "nlm_lut_y_5", 0x00000080, 15, 8, CSR_RW, 0x00000076 },
	{ "nlm_lut_y_6", 0x00000080, 23, 16, CSR_RW, 0x0000006E },
	{ "nlm_lut_y_7", 0x00000080, 31, 24, CSR_RW, 0x00000066 },
	{ "NR2D_22", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_23
	{ "nlm_lut_y_8", 0x00000084, 7, 0, CSR_RW, 0x0000005E },
	{ "nlm_lut_y_9", 0x00000084, 15, 8, CSR_RW, 0x00000056 },
	{ "nlm_lut_y_10", 0x00000084, 23, 16, CSR_RW, 0x00000048 },
	{ "nlm_lut_y_11", 0x00000084, 31, 24, CSR_RW, 0x0000003A },
	{ "NR2D_23", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_24
	{ "nlm_lut_y_12", 0x00000088, 7, 0, CSR_RW, 0x0000002C },
	{ "nlm_lut_y_13", 0x00000088, 15, 8, CSR_RW, 0x0000001E },
	{ "nlm_lut_y_14", 0x00000088, 23, 16, CSR_RW, 0x00000014 },
	{ "nlm_lut_y_15", 0x00000088, 31, 24, CSR_RW, 0x00000010 },
	{ "NR2D_24", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_25
	{ "nlm_lut_y_16", 0x0000008C, 7, 0, CSR_RW, 0x0000000C },
	{ "nlm_lut_y_17", 0x0000008C, 15, 8, CSR_RW, 0x0000000A },
	{ "nlm_lut_y_18", 0x0000008C, 23, 16, CSR_RW, 0x00000008 },
	{ "nlm_lut_y_19", 0x0000008C, 31, 24, CSR_RW, 0x00000006 },
	{ "NR2D_25", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_26
	{ "nlm_lut_y_20", 0x00000090, 7, 0, CSR_RW, 0x00000004 },
	{ "nlm_lut_y_21", 0x00000090, 15, 8, CSR_RW, 0x00000003 },
	{ "nlm_lut_y_22", 0x00000090, 23, 16, CSR_RW, 0x00000002 },
	{ "nlm_lut_y_23", 0x00000090, 31, 24, CSR_RW, 0x00000001 },
	{ "NR2D_26", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_27
	{ "nlm_lut_y_24", 0x00000094, 7, 0, CSR_RW, 0x00000001 },
	{ "nlm_lut_y_25", 0x00000094, 15, 8, CSR_RW, 0x00000000 },
	{ "nlm_lut_y_26", 0x00000094, 23, 16, CSR_RW, 0x00000000 },
	{ "nlm_lut_y_27", 0x00000094, 31, 24, CSR_RW, 0x00000000 },
	{ "NR2D_27", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_28
	{ "nlm_lut_y_28", 0x00000098, 7, 0, CSR_RW, 0x00000000 },
	{ "nlm_lut_y_29", 0x00000098, 15, 8, CSR_RW, 0x00000000 },
	{ "nlm_lut_y_30", 0x00000098, 23, 16, CSR_RW, 0x00000000 },
	{ "nlm_lut_y_31", 0x00000098, 31, 24, CSR_RW, 0x00000000 },
	{ "NR2D_28", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_29
	{ "luma_nlm_mean_candidate_th", 0x0000009C, 7, 0, CSR_RW, 0x00000000 },
	{ "luma_nlm_count_fallback_ratio", 0x0000009C, 20, 8, CSR_RW, 0x00000200 },
	{ "luma_nlm_count_th", 0x0000009C, 30, 24, CSR_RW, 0x00000008 },
	{ "NR2D_29", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_30
	{ "luma_nlm_fallback_min", 0x000000A0, 6, 0, CSR_RW, 0x00000010 },
	{ "luma_nlm_fallback_max", 0x000000A0, 14, 8, CSR_RW, 0x00000018 },
	{ "luma_nlm_noise_level_control", 0x000000A0, 23, 16, CSR_RW, 0x00000000 },
	{ "luma_nlm_global_fallback_alpha", 0x000000A0, 30, 24, CSR_RW, 0x00000000 },
	{ "NR2D_30", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_31
	{ "chroma_nlm_mean_candidate_th", 0x000000A4, 7, 0, CSR_RW, 0x00000000 },
	{ "chroma_nlm_count_fallback_ratio", 0x000000A4, 20, 8, CSR_RW, 0x00000200 },
	{ "chroma_nlm_count_th", 0x000000A4, 30, 24, CSR_RW, 0x00000008 },
	{ "NR2D_31", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_32
	{ "chroma_nlm_fallback_min", 0x000000A8, 6, 0, CSR_RW, 0x00000008 },
	{ "chroma_nlm_fallback_max", 0x000000A8, 14, 8, CSR_RW, 0x00000010 },
	{ "chroma_nlm_noise_level_control", 0x000000A8, 23, 16, CSR_RW, 0x00000000 },
	{ "chroma_nlm_global_fallback_alpha", 0x000000A8, 30, 24, CSR_RW, 0x00000000 },
	{ "NR2D_32", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD atpg
	{ "atpg_ctrl", 0x000000AC, 1, 0, CSR_RW, 0x00000000 },
	{ "ATPG", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved
	{ "reserved", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_NR2D_H_
