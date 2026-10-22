/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DFK_H_
#define CSR_TABLE_DFK_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dfk[] = {
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
	// WORD dfk_mode
	{ "deflicker_enable", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "deflicker_bypass", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "DFK_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD sensor_setting_00
	{ "line_per_period", 0x00000014, 9, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase_i", 0x00000014, 17, 16, CSR_RW, 0x00000000 },
	{ "cfa_mode", 0x00000014, 25, 24, CSR_RW, 0x00000000 },
	{ "SENSOR_SETTING_00", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD sensor_setting_01
	{ "width", 0x00000018, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000018, 31, 16, CSR_RW, 0x00000438 },
	{ "SENSOR_SETTING_01", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_setting_0
	{ "cfa_phase_0", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_1", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_2", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_3", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_SETTING_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_setting_1
	{ "cfa_phase_4", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_5", 0x00000020, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_6", 0x00000020, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_7", 0x00000020, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_SETTING_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_setting_2
	{ "cfa_phase_8", 0x00000024, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_9", 0x00000024, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_10", 0x00000024, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_11", 0x00000024, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_SETTING_2", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfa_phase_setting_3
	{ "cfa_phase_12", 0x00000028, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_13", 0x00000028, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_14", 0x00000028, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_15", 0x00000028, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_SETTING_3", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_x_0
	{ "roi_g_line_avg_sx_0", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_ex_0", 0x0000002C, 31, 16, CSR_RW, 0x00000780 },
	{ "G_LINE_AVG_ROI_X_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_y_0
	{ "roi_g_line_avg_sy_0", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_ey_0", 0x00000030, 31, 16, CSR_RW, 0x00000438 },
	{ "G_LINE_AVG_ROI_Y_0", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_x_1
	{ "roi_g_line_avg_sx_1", 0x00000034, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_ex_1", 0x00000034, 31, 16, CSR_RW, 0x00000780 },
	{ "G_LINE_AVG_ROI_X_1", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_y_1
	{ "roi_g_line_avg_sy_1", 0x00000038, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_ey_1", 0x00000038, 31, 16, CSR_RW, 0x00000438 },
	{ "G_LINE_AVG_ROI_Y_1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_x_2
	{ "roi_g_line_avg_sx_2", 0x0000003C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_ex_2", 0x0000003C, 31, 16, CSR_RW, 0x00000780 },
	{ "G_LINE_AVG_ROI_X_2", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_y_2
	{ "roi_g_line_avg_sy_2", 0x00000040, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_ey_2", 0x00000040, 31, 16, CSR_RW, 0x00000438 },
	{ "G_LINE_AVG_ROI_Y_2", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_pix_num
	{ "roi_g_line_avg_pix_num_0", 0x00000044, 15, 0, CSR_RW, 0x000003C0 },
	{ "roi_g_line_avg_pix_num_1", 0x00000044, 31, 16, CSR_RW, 0x000003C0 },
	{ "G_LINE_AVG_ROI_PIX_NUM", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_x_apply_0
	{ "roi_g_line_avg_pix_num_2", 0x00000048, 15, 0, CSR_RW, 0x000003C0 },
	{ "amp_x_apply_0", 0x00000048, 31, 16, CSR_RW, 0x00000000 },
	{ "DFK_X_APPLY_0", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_x_apply_1
	{ "amp_x_apply_1", 0x0000004C, 15, 0, CSR_RW, 0x00000000 },
	{ "amp_x_apply_2", 0x0000004C, 31, 16, CSR_RW, 0x00000000 },
	{ "DFK_X_APPLY_1", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD g_line_avg_roi_en
	{ "roi_g_line_avg_en_0", 0x00000050, 0, 0, CSR_RW, 0x00000001 },
	{ "roi_g_line_avg_en_1", 0x00000050, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_g_line_avg_en_2", 0x00000050, 16, 16, CSR_RW, 0x00000000 },
	{ "G_LINE_AVG_ROI_EN", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_gain_0
	{ "dfk_amp_0", 0x00000054, 6, 0, CSR_RW, 0x00000040 },
	{ "dfk_amp_1", 0x00000054, 14, 8, CSR_RW, 0x00000040 },
	{ "dfk_amp_2", 0x00000054, 22, 16, CSR_RW, 0x00000040 },
	{ "DFK_GAIN_0", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_phase
	{ "dfk_phase_curr", 0x00000058, 8, 0, CSR_RW, 0x00000000 },
	{ "DFK_PHASE", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_gain_1
	{ "amp_slop_0", 0x0000005C, 15, 0, CSR_RW, 0x00000000 },
	{ "amp_slop_1", 0x0000005C, 31, 16, CSR_RW, 0x00000000 },
	{ "DFK_GAIN_1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_csr2sram_sel
	{ "csr2sram_sel", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_CSR2SRAM_SEL", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_avg_addr
	{ "roi_avg_r_addr", 0x00000064, 10, 0, CSR_RW, 0x00000000 },
	{ "ROI_AVG_ADDR", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_r_data
	{ "roi_avg_r_data", 0x00000068, 29, 0, CSR_RO, 0x00000000 },
	{ "ROI_R_DATA", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD dfk_sin_0
	{ "sin_wave_0", 0x0000006C, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_1", 0x0000006C, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_2", 0x0000006C, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_3", 0x0000006C, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_0", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_1
	{ "sin_wave_4", 0x00000070, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_5", 0x00000070, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_6", 0x00000070, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_7", 0x00000070, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_1", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_2
	{ "sin_wave_8", 0x00000074, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_9", 0x00000074, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_10", 0x00000074, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_11", 0x00000074, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_2", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_3
	{ "sin_wave_12", 0x00000078, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_13", 0x00000078, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_14", 0x00000078, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_15", 0x00000078, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_3", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_4
	{ "sin_wave_16", 0x0000007C, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_17", 0x0000007C, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_18", 0x0000007C, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_19", 0x0000007C, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_4", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_5
	{ "sin_wave_20", 0x00000080, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_21", 0x00000080, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_22", 0x00000080, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_23", 0x00000080, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_5", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_6
	{ "sin_wave_24", 0x00000084, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_25", 0x00000084, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_26", 0x00000084, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_27", 0x00000084, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_6", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_7
	{ "sin_wave_28", 0x00000088, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_29", 0x00000088, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_30", 0x00000088, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_31", 0x00000088, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_7", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_8
	{ "sin_wave_32", 0x0000008C, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_33", 0x0000008C, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_34", 0x0000008C, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_35", 0x0000008C, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_8", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_9
	{ "sin_wave_36", 0x00000090, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_37", 0x00000090, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_38", 0x00000090, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_39", 0x00000090, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_9", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_10
	{ "sin_wave_40", 0x00000094, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_41", 0x00000094, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_42", 0x00000094, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_43", 0x00000094, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_10", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_11
	{ "sin_wave_44", 0x00000098, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_45", 0x00000098, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_46", 0x00000098, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_47", 0x00000098, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_11", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_12
	{ "sin_wave_48", 0x0000009C, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_49", 0x0000009C, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_50", 0x0000009C, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_51", 0x0000009C, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_12", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_13
	{ "sin_wave_52", 0x000000A0, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_53", 0x000000A0, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_54", 0x000000A0, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_55", 0x000000A0, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_13", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_14
	{ "sin_wave_56", 0x000000A4, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_57", 0x000000A4, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_58", 0x000000A4, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_59", 0x000000A4, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_14", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_15
	{ "sin_wave_60", 0x000000A8, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_61", 0x000000A8, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_62", 0x000000A8, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_63", 0x000000A8, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_15", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_16
	{ "sin_wave_64", 0x000000AC, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_65", 0x000000AC, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_66", 0x000000AC, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_67", 0x000000AC, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_16", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_17
	{ "sin_wave_68", 0x000000B0, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_69", 0x000000B0, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_70", 0x000000B0, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_71", 0x000000B0, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_17", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_18
	{ "sin_wave_72", 0x000000B4, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_73", 0x000000B4, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_74", 0x000000B4, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_75", 0x000000B4, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_18", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_19
	{ "sin_wave_76", 0x000000B8, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_77", 0x000000B8, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_78", 0x000000B8, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_79", 0x000000B8, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_19", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_20
	{ "sin_wave_80", 0x000000BC, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_81", 0x000000BC, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_82", 0x000000BC, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_83", 0x000000BC, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_20", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_21
	{ "sin_wave_84", 0x000000C0, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_85", 0x000000C0, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_86", 0x000000C0, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_87", 0x000000C0, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_21", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_22
	{ "sin_wave_88", 0x000000C4, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_89", 0x000000C4, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_90", 0x000000C4, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_91", 0x000000C4, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_22", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_23
	{ "sin_wave_92", 0x000000C8, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_93", 0x000000C8, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_94", 0x000000C8, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_95", 0x000000C8, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_23", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_24
	{ "sin_wave_96", 0x000000CC, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_97", 0x000000CC, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_98", 0x000000CC, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_99", 0x000000CC, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_24", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_25
	{ "sin_wave_100", 0x000000D0, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_101", 0x000000D0, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_102", 0x000000D0, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_103", 0x000000D0, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_25", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_26
	{ "sin_wave_104", 0x000000D4, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_105", 0x000000D4, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_106", 0x000000D4, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_107", 0x000000D4, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_26", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_27
	{ "sin_wave_108", 0x000000D8, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_109", 0x000000D8, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_110", 0x000000D8, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_111", 0x000000D8, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_27", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_28
	{ "sin_wave_112", 0x000000DC, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_113", 0x000000DC, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_114", 0x000000DC, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_115", 0x000000DC, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_28", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_29
	{ "sin_wave_116", 0x000000E0, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_117", 0x000000E0, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_118", 0x000000E0, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_119", 0x000000E0, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_29", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_30
	{ "sin_wave_120", 0x000000E4, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_121", 0x000000E4, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_122", 0x000000E4, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_123", 0x000000E4, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_30", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_31
	{ "sin_wave_124", 0x000000E8, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_125", 0x000000E8, 15, 8, CSR_RW, 0x00000000 },
	{ "sin_wave_126", 0x000000E8, 23, 16, CSR_RW, 0x00000000 },
	{ "sin_wave_127", 0x000000E8, 31, 24, CSR_RW, 0x00000000 },
	{ "DFK_SIN_31", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfk_sin_32
	{ "sin_wave_128", 0x000000EC, 7, 0, CSR_RW, 0x00000000 },
	{ "sin_wave_ds", 0x000000EC, 9, 8, CSR_RW, 0x00000002 },
	{ "DFK_SIN_32", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_atpg_ctrl
	{ "atpg_ctrl", 0x000000F0, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_ATPG_CTRL", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD reserved_0
	{ "resevered_0", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	{ "RESERVED_0", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD reserved_1
	{ "resevered_1", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	{ "RESERVED_1", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD fpga_roi_r_data_0
	{ "roi_avg_r_data_0", 0x000000FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_0", 0x000000FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1
	{ "roi_avg_r_data_1", 0x00000100, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1", 0x00000100, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_2
	{ "roi_avg_r_data_2", 0x00000104, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_2", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_3
	{ "roi_avg_r_data_3", 0x00000108, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_3", 0x00000108, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_4
	{ "roi_avg_r_data_4", 0x0000010C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_4", 0x0000010C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_5
	{ "roi_avg_r_data_5", 0x00000110, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_5", 0x00000110, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_6
	{ "roi_avg_r_data_6", 0x00000114, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_6", 0x00000114, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_7
	{ "roi_avg_r_data_7", 0x00000118, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_7", 0x00000118, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_8
	{ "roi_avg_r_data_8", 0x0000011C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_8", 0x0000011C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_9
	{ "roi_avg_r_data_9", 0x00000120, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_9", 0x00000120, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_10
	{ "roi_avg_r_data_10", 0x00000124, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_10", 0x00000124, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_11
	{ "roi_avg_r_data_11", 0x00000128, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_11", 0x00000128, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_12
	{ "roi_avg_r_data_12", 0x0000012C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_12", 0x0000012C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_13
	{ "roi_avg_r_data_13", 0x00000130, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_13", 0x00000130, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_14
	{ "roi_avg_r_data_14", 0x00000134, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_14", 0x00000134, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_15
	{ "roi_avg_r_data_15", 0x00000138, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_15", 0x00000138, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_16
	{ "roi_avg_r_data_16", 0x0000013C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_16", 0x0000013C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_17
	{ "roi_avg_r_data_17", 0x00000140, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_17", 0x00000140, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_18
	{ "roi_avg_r_data_18", 0x00000144, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_18", 0x00000144, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_19
	{ "roi_avg_r_data_19", 0x00000148, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_19", 0x00000148, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_20
	{ "roi_avg_r_data_20", 0x0000014C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_20", 0x0000014C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_21
	{ "roi_avg_r_data_21", 0x00000150, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_21", 0x00000150, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_22
	{ "roi_avg_r_data_22", 0x00000154, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_22", 0x00000154, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_23
	{ "roi_avg_r_data_23", 0x00000158, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_23", 0x00000158, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_24
	{ "roi_avg_r_data_24", 0x0000015C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_24", 0x0000015C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_25
	{ "roi_avg_r_data_25", 0x00000160, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_25", 0x00000160, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_26
	{ "roi_avg_r_data_26", 0x00000164, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_26", 0x00000164, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_27
	{ "roi_avg_r_data_27", 0x00000168, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_27", 0x00000168, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_28
	{ "roi_avg_r_data_28", 0x0000016C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_28", 0x0000016C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_29
	{ "roi_avg_r_data_29", 0x00000170, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_29", 0x00000170, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_30
	{ "roi_avg_r_data_30", 0x00000174, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_30", 0x00000174, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_31
	{ "roi_avg_r_data_31", 0x00000178, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_31", 0x00000178, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_32
	{ "roi_avg_r_data_32", 0x0000017C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_32", 0x0000017C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_33
	{ "roi_avg_r_data_33", 0x00000180, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_33", 0x00000180, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_34
	{ "roi_avg_r_data_34", 0x00000184, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_34", 0x00000184, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_35
	{ "roi_avg_r_data_35", 0x00000188, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_35", 0x00000188, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_36
	{ "roi_avg_r_data_36", 0x0000018C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_36", 0x0000018C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_37
	{ "roi_avg_r_data_37", 0x00000190, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_37", 0x00000190, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_38
	{ "roi_avg_r_data_38", 0x00000194, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_38", 0x00000194, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_39
	{ "roi_avg_r_data_39", 0x00000198, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_39", 0x00000198, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_40
	{ "roi_avg_r_data_40", 0x0000019C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_40", 0x0000019C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_41
	{ "roi_avg_r_data_41", 0x000001A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_41", 0x000001A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_42
	{ "roi_avg_r_data_42", 0x000001A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_42", 0x000001A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_43
	{ "roi_avg_r_data_43", 0x000001A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_43", 0x000001A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_44
	{ "roi_avg_r_data_44", 0x000001AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_44", 0x000001AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_45
	{ "roi_avg_r_data_45", 0x000001B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_45", 0x000001B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_46
	{ "roi_avg_r_data_46", 0x000001B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_46", 0x000001B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_47
	{ "roi_avg_r_data_47", 0x000001B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_47", 0x000001B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_48
	{ "roi_avg_r_data_48", 0x000001BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_48", 0x000001BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_49
	{ "roi_avg_r_data_49", 0x000001C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_49", 0x000001C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_50
	{ "roi_avg_r_data_50", 0x000001C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_50", 0x000001C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_51
	{ "roi_avg_r_data_51", 0x000001C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_51", 0x000001C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_52
	{ "roi_avg_r_data_52", 0x000001CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_52", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_53
	{ "roi_avg_r_data_53", 0x000001D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_53", 0x000001D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_54
	{ "roi_avg_r_data_54", 0x000001D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_54", 0x000001D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_55
	{ "roi_avg_r_data_55", 0x000001D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_55", 0x000001D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_56
	{ "roi_avg_r_data_56", 0x000001DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_56", 0x000001DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_57
	{ "roi_avg_r_data_57", 0x000001E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_57", 0x000001E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_58
	{ "roi_avg_r_data_58", 0x000001E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_58", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_59
	{ "roi_avg_r_data_59", 0x000001E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_59", 0x000001E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_60
	{ "roi_avg_r_data_60", 0x000001EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_60", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_61
	{ "roi_avg_r_data_61", 0x000001F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_61", 0x000001F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_62
	{ "roi_avg_r_data_62", 0x000001F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_62", 0x000001F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_63
	{ "roi_avg_r_data_63", 0x000001F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_63", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_64
	{ "roi_avg_r_data_64", 0x000001FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_64", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_65
	{ "roi_avg_r_data_65", 0x00000200, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_65", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_66
	{ "roi_avg_r_data_66", 0x00000204, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_66", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_67
	{ "roi_avg_r_data_67", 0x00000208, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_67", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_68
	{ "roi_avg_r_data_68", 0x0000020C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_68", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_69
	{ "roi_avg_r_data_69", 0x00000210, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_69", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_70
	{ "roi_avg_r_data_70", 0x00000214, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_70", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_71
	{ "roi_avg_r_data_71", 0x00000218, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_71", 0x00000218, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_72
	{ "roi_avg_r_data_72", 0x0000021C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_72", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_73
	{ "roi_avg_r_data_73", 0x00000220, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_73", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_74
	{ "roi_avg_r_data_74", 0x00000224, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_74", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_75
	{ "roi_avg_r_data_75", 0x00000228, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_75", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_76
	{ "roi_avg_r_data_76", 0x0000022C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_76", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_77
	{ "roi_avg_r_data_77", 0x00000230, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_77", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_78
	{ "roi_avg_r_data_78", 0x00000234, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_78", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_79
	{ "roi_avg_r_data_79", 0x00000238, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_79", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_80
	{ "roi_avg_r_data_80", 0x0000023C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_80", 0x0000023C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_81
	{ "roi_avg_r_data_81", 0x00000240, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_81", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_82
	{ "roi_avg_r_data_82", 0x00000244, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_82", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_83
	{ "roi_avg_r_data_83", 0x00000248, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_83", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_84
	{ "roi_avg_r_data_84", 0x0000024C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_84", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_85
	{ "roi_avg_r_data_85", 0x00000250, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_85", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_86
	{ "roi_avg_r_data_86", 0x00000254, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_86", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_87
	{ "roi_avg_r_data_87", 0x00000258, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_87", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_88
	{ "roi_avg_r_data_88", 0x0000025C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_88", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_89
	{ "roi_avg_r_data_89", 0x00000260, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_89", 0x00000260, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_90
	{ "roi_avg_r_data_90", 0x00000264, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_90", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_91
	{ "roi_avg_r_data_91", 0x00000268, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_91", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_92
	{ "roi_avg_r_data_92", 0x0000026C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_92", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_93
	{ "roi_avg_r_data_93", 0x00000270, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_93", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_94
	{ "roi_avg_r_data_94", 0x00000274, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_94", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_95
	{ "roi_avg_r_data_95", 0x00000278, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_95", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_96
	{ "roi_avg_r_data_96", 0x0000027C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_96", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_97
	{ "roi_avg_r_data_97", 0x00000280, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_97", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_98
	{ "roi_avg_r_data_98", 0x00000284, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_98", 0x00000284, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_99
	{ "roi_avg_r_data_99", 0x00000288, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_99", 0x00000288, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_100
	{ "roi_avg_r_data_100", 0x0000028C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_100", 0x0000028C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_101
	{ "roi_avg_r_data_101", 0x00000290, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_101", 0x00000290, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_102
	{ "roi_avg_r_data_102", 0x00000294, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_102", 0x00000294, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_103
	{ "roi_avg_r_data_103", 0x00000298, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_103", 0x00000298, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_104
	{ "roi_avg_r_data_104", 0x0000029C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_104", 0x0000029C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_105
	{ "roi_avg_r_data_105", 0x000002A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_105", 0x000002A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_106
	{ "roi_avg_r_data_106", 0x000002A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_106", 0x000002A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_107
	{ "roi_avg_r_data_107", 0x000002A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_107", 0x000002A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_108
	{ "roi_avg_r_data_108", 0x000002AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_108", 0x000002AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_109
	{ "roi_avg_r_data_109", 0x000002B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_109", 0x000002B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_110
	{ "roi_avg_r_data_110", 0x000002B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_110", 0x000002B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_111
	{ "roi_avg_r_data_111", 0x000002B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_111", 0x000002B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_112
	{ "roi_avg_r_data_112", 0x000002BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_112", 0x000002BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_113
	{ "roi_avg_r_data_113", 0x000002C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_113", 0x000002C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_114
	{ "roi_avg_r_data_114", 0x000002C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_114", 0x000002C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_115
	{ "roi_avg_r_data_115", 0x000002C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_115", 0x000002C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_116
	{ "roi_avg_r_data_116", 0x000002CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_116", 0x000002CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_117
	{ "roi_avg_r_data_117", 0x000002D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_117", 0x000002D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_118
	{ "roi_avg_r_data_118", 0x000002D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_118", 0x000002D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_119
	{ "roi_avg_r_data_119", 0x000002D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_119", 0x000002D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_120
	{ "roi_avg_r_data_120", 0x000002DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_120", 0x000002DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_121
	{ "roi_avg_r_data_121", 0x000002E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_121", 0x000002E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_122
	{ "roi_avg_r_data_122", 0x000002E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_122", 0x000002E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_123
	{ "roi_avg_r_data_123", 0x000002E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_123", 0x000002E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_124
	{ "roi_avg_r_data_124", 0x000002EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_124", 0x000002EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_125
	{ "roi_avg_r_data_125", 0x000002F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_125", 0x000002F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_126
	{ "roi_avg_r_data_126", 0x000002F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_126", 0x000002F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_127
	{ "roi_avg_r_data_127", 0x000002F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_127", 0x000002F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_128
	{ "roi_avg_r_data_128", 0x000002FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_128", 0x000002FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_129
	{ "roi_avg_r_data_129", 0x00000300, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_129", 0x00000300, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_130
	{ "roi_avg_r_data_130", 0x00000304, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_130", 0x00000304, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_131
	{ "roi_avg_r_data_131", 0x00000308, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_131", 0x00000308, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_132
	{ "roi_avg_r_data_132", 0x0000030C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_132", 0x0000030C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_133
	{ "roi_avg_r_data_133", 0x00000310, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_133", 0x00000310, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_134
	{ "roi_avg_r_data_134", 0x00000314, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_134", 0x00000314, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_135
	{ "roi_avg_r_data_135", 0x00000318, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_135", 0x00000318, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_136
	{ "roi_avg_r_data_136", 0x0000031C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_136", 0x0000031C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_137
	{ "roi_avg_r_data_137", 0x00000320, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_137", 0x00000320, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_138
	{ "roi_avg_r_data_138", 0x00000324, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_138", 0x00000324, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_139
	{ "roi_avg_r_data_139", 0x00000328, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_139", 0x00000328, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_140
	{ "roi_avg_r_data_140", 0x0000032C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_140", 0x0000032C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_141
	{ "roi_avg_r_data_141", 0x00000330, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_141", 0x00000330, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_142
	{ "roi_avg_r_data_142", 0x00000334, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_142", 0x00000334, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_143
	{ "roi_avg_r_data_143", 0x00000338, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_143", 0x00000338, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_144
	{ "roi_avg_r_data_144", 0x0000033C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_144", 0x0000033C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_145
	{ "roi_avg_r_data_145", 0x00000340, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_145", 0x00000340, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_146
	{ "roi_avg_r_data_146", 0x00000344, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_146", 0x00000344, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_147
	{ "roi_avg_r_data_147", 0x00000348, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_147", 0x00000348, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_148
	{ "roi_avg_r_data_148", 0x0000034C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_148", 0x0000034C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_149
	{ "roi_avg_r_data_149", 0x00000350, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_149", 0x00000350, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_150
	{ "roi_avg_r_data_150", 0x00000354, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_150", 0x00000354, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_151
	{ "roi_avg_r_data_151", 0x00000358, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_151", 0x00000358, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_152
	{ "roi_avg_r_data_152", 0x0000035C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_152", 0x0000035C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_153
	{ "roi_avg_r_data_153", 0x00000360, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_153", 0x00000360, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_154
	{ "roi_avg_r_data_154", 0x00000364, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_154", 0x00000364, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_155
	{ "roi_avg_r_data_155", 0x00000368, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_155", 0x00000368, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_156
	{ "roi_avg_r_data_156", 0x0000036C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_156", 0x0000036C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_157
	{ "roi_avg_r_data_157", 0x00000370, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_157", 0x00000370, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_158
	{ "roi_avg_r_data_158", 0x00000374, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_158", 0x00000374, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_159
	{ "roi_avg_r_data_159", 0x00000378, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_159", 0x00000378, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_160
	{ "roi_avg_r_data_160", 0x0000037C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_160", 0x0000037C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_161
	{ "roi_avg_r_data_161", 0x00000380, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_161", 0x00000380, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_162
	{ "roi_avg_r_data_162", 0x00000384, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_162", 0x00000384, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_163
	{ "roi_avg_r_data_163", 0x00000388, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_163", 0x00000388, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_164
	{ "roi_avg_r_data_164", 0x0000038C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_164", 0x0000038C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_165
	{ "roi_avg_r_data_165", 0x00000390, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_165", 0x00000390, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_166
	{ "roi_avg_r_data_166", 0x00000394, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_166", 0x00000394, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_167
	{ "roi_avg_r_data_167", 0x00000398, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_167", 0x00000398, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_168
	{ "roi_avg_r_data_168", 0x0000039C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_168", 0x0000039C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_169
	{ "roi_avg_r_data_169", 0x000003A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_169", 0x000003A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_170
	{ "roi_avg_r_data_170", 0x000003A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_170", 0x000003A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_171
	{ "roi_avg_r_data_171", 0x000003A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_171", 0x000003A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_172
	{ "roi_avg_r_data_172", 0x000003AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_172", 0x000003AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_173
	{ "roi_avg_r_data_173", 0x000003B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_173", 0x000003B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_174
	{ "roi_avg_r_data_174", 0x000003B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_174", 0x000003B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_175
	{ "roi_avg_r_data_175", 0x000003B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_175", 0x000003B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_176
	{ "roi_avg_r_data_176", 0x000003BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_176", 0x000003BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_177
	{ "roi_avg_r_data_177", 0x000003C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_177", 0x000003C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_178
	{ "roi_avg_r_data_178", 0x000003C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_178", 0x000003C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_179
	{ "roi_avg_r_data_179", 0x000003C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_179", 0x000003C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_180
	{ "roi_avg_r_data_180", 0x000003CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_180", 0x000003CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_181
	{ "roi_avg_r_data_181", 0x000003D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_181", 0x000003D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_182
	{ "roi_avg_r_data_182", 0x000003D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_182", 0x000003D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_183
	{ "roi_avg_r_data_183", 0x000003D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_183", 0x000003D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_184
	{ "roi_avg_r_data_184", 0x000003DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_184", 0x000003DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_185
	{ "roi_avg_r_data_185", 0x000003E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_185", 0x000003E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_186
	{ "roi_avg_r_data_186", 0x000003E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_186", 0x000003E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_187
	{ "roi_avg_r_data_187", 0x000003E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_187", 0x000003E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_188
	{ "roi_avg_r_data_188", 0x000003EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_188", 0x000003EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_189
	{ "roi_avg_r_data_189", 0x000003F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_189", 0x000003F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_190
	{ "roi_avg_r_data_190", 0x000003F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_190", 0x000003F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_191
	{ "roi_avg_r_data_191", 0x000003F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_191", 0x000003F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_192
	{ "roi_avg_r_data_192", 0x000003FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_192", 0x000003FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_193
	{ "roi_avg_r_data_193", 0x00000400, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_193", 0x00000400, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_194
	{ "roi_avg_r_data_194", 0x00000404, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_194", 0x00000404, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_195
	{ "roi_avg_r_data_195", 0x00000408, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_195", 0x00000408, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_196
	{ "roi_avg_r_data_196", 0x0000040C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_196", 0x0000040C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_197
	{ "roi_avg_r_data_197", 0x00000410, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_197", 0x00000410, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_198
	{ "roi_avg_r_data_198", 0x00000414, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_198", 0x00000414, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_199
	{ "roi_avg_r_data_199", 0x00000418, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_199", 0x00000418, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_200
	{ "roi_avg_r_data_200", 0x0000041C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_200", 0x0000041C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_201
	{ "roi_avg_r_data_201", 0x00000420, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_201", 0x00000420, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_202
	{ "roi_avg_r_data_202", 0x00000424, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_202", 0x00000424, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_203
	{ "roi_avg_r_data_203", 0x00000428, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_203", 0x00000428, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_204
	{ "roi_avg_r_data_204", 0x0000042C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_204", 0x0000042C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_205
	{ "roi_avg_r_data_205", 0x00000430, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_205", 0x00000430, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_206
	{ "roi_avg_r_data_206", 0x00000434, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_206", 0x00000434, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_207
	{ "roi_avg_r_data_207", 0x00000438, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_207", 0x00000438, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_208
	{ "roi_avg_r_data_208", 0x0000043C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_208", 0x0000043C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_209
	{ "roi_avg_r_data_209", 0x00000440, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_209", 0x00000440, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_210
	{ "roi_avg_r_data_210", 0x00000444, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_210", 0x00000444, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_211
	{ "roi_avg_r_data_211", 0x00000448, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_211", 0x00000448, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_212
	{ "roi_avg_r_data_212", 0x0000044C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_212", 0x0000044C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_213
	{ "roi_avg_r_data_213", 0x00000450, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_213", 0x00000450, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_214
	{ "roi_avg_r_data_214", 0x00000454, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_214", 0x00000454, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_215
	{ "roi_avg_r_data_215", 0x00000458, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_215", 0x00000458, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_216
	{ "roi_avg_r_data_216", 0x0000045C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_216", 0x0000045C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_217
	{ "roi_avg_r_data_217", 0x00000460, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_217", 0x00000460, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_218
	{ "roi_avg_r_data_218", 0x00000464, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_218", 0x00000464, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_219
	{ "roi_avg_r_data_219", 0x00000468, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_219", 0x00000468, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_220
	{ "roi_avg_r_data_220", 0x0000046C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_220", 0x0000046C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_221
	{ "roi_avg_r_data_221", 0x00000470, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_221", 0x00000470, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_222
	{ "roi_avg_r_data_222", 0x00000474, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_222", 0x00000474, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_223
	{ "roi_avg_r_data_223", 0x00000478, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_223", 0x00000478, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_224
	{ "roi_avg_r_data_224", 0x0000047C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_224", 0x0000047C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_225
	{ "roi_avg_r_data_225", 0x00000480, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_225", 0x00000480, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_226
	{ "roi_avg_r_data_226", 0x00000484, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_226", 0x00000484, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_227
	{ "roi_avg_r_data_227", 0x00000488, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_227", 0x00000488, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_228
	{ "roi_avg_r_data_228", 0x0000048C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_228", 0x0000048C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_229
	{ "roi_avg_r_data_229", 0x00000490, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_229", 0x00000490, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_230
	{ "roi_avg_r_data_230", 0x00000494, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_230", 0x00000494, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_231
	{ "roi_avg_r_data_231", 0x00000498, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_231", 0x00000498, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_232
	{ "roi_avg_r_data_232", 0x0000049C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_232", 0x0000049C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_233
	{ "roi_avg_r_data_233", 0x000004A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_233", 0x000004A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_234
	{ "roi_avg_r_data_234", 0x000004A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_234", 0x000004A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_235
	{ "roi_avg_r_data_235", 0x000004A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_235", 0x000004A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_236
	{ "roi_avg_r_data_236", 0x000004AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_236", 0x000004AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_237
	{ "roi_avg_r_data_237", 0x000004B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_237", 0x000004B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_238
	{ "roi_avg_r_data_238", 0x000004B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_238", 0x000004B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_239
	{ "roi_avg_r_data_239", 0x000004B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_239", 0x000004B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_240
	{ "roi_avg_r_data_240", 0x000004BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_240", 0x000004BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_241
	{ "roi_avg_r_data_241", 0x000004C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_241", 0x000004C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_242
	{ "roi_avg_r_data_242", 0x000004C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_242", 0x000004C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_243
	{ "roi_avg_r_data_243", 0x000004C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_243", 0x000004C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_244
	{ "roi_avg_r_data_244", 0x000004CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_244", 0x000004CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_245
	{ "roi_avg_r_data_245", 0x000004D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_245", 0x000004D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_246
	{ "roi_avg_r_data_246", 0x000004D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_246", 0x000004D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_247
	{ "roi_avg_r_data_247", 0x000004D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_247", 0x000004D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_248
	{ "roi_avg_r_data_248", 0x000004DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_248", 0x000004DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_249
	{ "roi_avg_r_data_249", 0x000004E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_249", 0x000004E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_250
	{ "roi_avg_r_data_250", 0x000004E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_250", 0x000004E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_251
	{ "roi_avg_r_data_251", 0x000004E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_251", 0x000004E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_252
	{ "roi_avg_r_data_252", 0x000004EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_252", 0x000004EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_253
	{ "roi_avg_r_data_253", 0x000004F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_253", 0x000004F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_254
	{ "roi_avg_r_data_254", 0x000004F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_254", 0x000004F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_255
	{ "roi_avg_r_data_255", 0x000004F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_255", 0x000004F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_256
	{ "roi_avg_r_data_256", 0x000004FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_256", 0x000004FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_257
	{ "roi_avg_r_data_257", 0x00000500, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_257", 0x00000500, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_258
	{ "roi_avg_r_data_258", 0x00000504, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_258", 0x00000504, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_259
	{ "roi_avg_r_data_259", 0x00000508, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_259", 0x00000508, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_260
	{ "roi_avg_r_data_260", 0x0000050C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_260", 0x0000050C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_261
	{ "roi_avg_r_data_261", 0x00000510, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_261", 0x00000510, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_262
	{ "roi_avg_r_data_262", 0x00000514, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_262", 0x00000514, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_263
	{ "roi_avg_r_data_263", 0x00000518, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_263", 0x00000518, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_264
	{ "roi_avg_r_data_264", 0x0000051C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_264", 0x0000051C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_265
	{ "roi_avg_r_data_265", 0x00000520, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_265", 0x00000520, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_266
	{ "roi_avg_r_data_266", 0x00000524, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_266", 0x00000524, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_267
	{ "roi_avg_r_data_267", 0x00000528, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_267", 0x00000528, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_268
	{ "roi_avg_r_data_268", 0x0000052C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_268", 0x0000052C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_269
	{ "roi_avg_r_data_269", 0x00000530, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_269", 0x00000530, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_270
	{ "roi_avg_r_data_270", 0x00000534, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_270", 0x00000534, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_271
	{ "roi_avg_r_data_271", 0x00000538, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_271", 0x00000538, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_272
	{ "roi_avg_r_data_272", 0x0000053C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_272", 0x0000053C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_273
	{ "roi_avg_r_data_273", 0x00000540, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_273", 0x00000540, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_274
	{ "roi_avg_r_data_274", 0x00000544, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_274", 0x00000544, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_275
	{ "roi_avg_r_data_275", 0x00000548, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_275", 0x00000548, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_276
	{ "roi_avg_r_data_276", 0x0000054C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_276", 0x0000054C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_277
	{ "roi_avg_r_data_277", 0x00000550, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_277", 0x00000550, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_278
	{ "roi_avg_r_data_278", 0x00000554, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_278", 0x00000554, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_279
	{ "roi_avg_r_data_279", 0x00000558, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_279", 0x00000558, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_280
	{ "roi_avg_r_data_280", 0x0000055C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_280", 0x0000055C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_281
	{ "roi_avg_r_data_281", 0x00000560, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_281", 0x00000560, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_282
	{ "roi_avg_r_data_282", 0x00000564, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_282", 0x00000564, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_283
	{ "roi_avg_r_data_283", 0x00000568, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_283", 0x00000568, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_284
	{ "roi_avg_r_data_284", 0x0000056C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_284", 0x0000056C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_285
	{ "roi_avg_r_data_285", 0x00000570, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_285", 0x00000570, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_286
	{ "roi_avg_r_data_286", 0x00000574, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_286", 0x00000574, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_287
	{ "roi_avg_r_data_287", 0x00000578, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_287", 0x00000578, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_288
	{ "roi_avg_r_data_288", 0x0000057C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_288", 0x0000057C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_289
	{ "roi_avg_r_data_289", 0x00000580, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_289", 0x00000580, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_290
	{ "roi_avg_r_data_290", 0x00000584, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_290", 0x00000584, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_291
	{ "roi_avg_r_data_291", 0x00000588, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_291", 0x00000588, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_292
	{ "roi_avg_r_data_292", 0x0000058C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_292", 0x0000058C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_293
	{ "roi_avg_r_data_293", 0x00000590, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_293", 0x00000590, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_294
	{ "roi_avg_r_data_294", 0x00000594, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_294", 0x00000594, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_295
	{ "roi_avg_r_data_295", 0x00000598, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_295", 0x00000598, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_296
	{ "roi_avg_r_data_296", 0x0000059C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_296", 0x0000059C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_297
	{ "roi_avg_r_data_297", 0x000005A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_297", 0x000005A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_298
	{ "roi_avg_r_data_298", 0x000005A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_298", 0x000005A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_299
	{ "roi_avg_r_data_299", 0x000005A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_299", 0x000005A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_300
	{ "roi_avg_r_data_300", 0x000005AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_300", 0x000005AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_301
	{ "roi_avg_r_data_301", 0x000005B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_301", 0x000005B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_302
	{ "roi_avg_r_data_302", 0x000005B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_302", 0x000005B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_303
	{ "roi_avg_r_data_303", 0x000005B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_303", 0x000005B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_304
	{ "roi_avg_r_data_304", 0x000005BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_304", 0x000005BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_305
	{ "roi_avg_r_data_305", 0x000005C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_305", 0x000005C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_306
	{ "roi_avg_r_data_306", 0x000005C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_306", 0x000005C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_307
	{ "roi_avg_r_data_307", 0x000005C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_307", 0x000005C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_308
	{ "roi_avg_r_data_308", 0x000005CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_308", 0x000005CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_309
	{ "roi_avg_r_data_309", 0x000005D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_309", 0x000005D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_310
	{ "roi_avg_r_data_310", 0x000005D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_310", 0x000005D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_311
	{ "roi_avg_r_data_311", 0x000005D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_311", 0x000005D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_312
	{ "roi_avg_r_data_312", 0x000005DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_312", 0x000005DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_313
	{ "roi_avg_r_data_313", 0x000005E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_313", 0x000005E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_314
	{ "roi_avg_r_data_314", 0x000005E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_314", 0x000005E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_315
	{ "roi_avg_r_data_315", 0x000005E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_315", 0x000005E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_316
	{ "roi_avg_r_data_316", 0x000005EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_316", 0x000005EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_317
	{ "roi_avg_r_data_317", 0x000005F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_317", 0x000005F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_318
	{ "roi_avg_r_data_318", 0x000005F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_318", 0x000005F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_319
	{ "roi_avg_r_data_319", 0x000005F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_319", 0x000005F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_320
	{ "roi_avg_r_data_320", 0x000005FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_320", 0x000005FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_321
	{ "roi_avg_r_data_321", 0x00000600, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_321", 0x00000600, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_322
	{ "roi_avg_r_data_322", 0x00000604, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_322", 0x00000604, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_323
	{ "roi_avg_r_data_323", 0x00000608, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_323", 0x00000608, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_324
	{ "roi_avg_r_data_324", 0x0000060C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_324", 0x0000060C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_325
	{ "roi_avg_r_data_325", 0x00000610, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_325", 0x00000610, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_326
	{ "roi_avg_r_data_326", 0x00000614, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_326", 0x00000614, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_327
	{ "roi_avg_r_data_327", 0x00000618, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_327", 0x00000618, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_328
	{ "roi_avg_r_data_328", 0x0000061C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_328", 0x0000061C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_329
	{ "roi_avg_r_data_329", 0x00000620, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_329", 0x00000620, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_330
	{ "roi_avg_r_data_330", 0x00000624, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_330", 0x00000624, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_331
	{ "roi_avg_r_data_331", 0x00000628, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_331", 0x00000628, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_332
	{ "roi_avg_r_data_332", 0x0000062C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_332", 0x0000062C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_333
	{ "roi_avg_r_data_333", 0x00000630, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_333", 0x00000630, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_334
	{ "roi_avg_r_data_334", 0x00000634, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_334", 0x00000634, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_335
	{ "roi_avg_r_data_335", 0x00000638, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_335", 0x00000638, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_336
	{ "roi_avg_r_data_336", 0x0000063C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_336", 0x0000063C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_337
	{ "roi_avg_r_data_337", 0x00000640, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_337", 0x00000640, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_338
	{ "roi_avg_r_data_338", 0x00000644, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_338", 0x00000644, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_339
	{ "roi_avg_r_data_339", 0x00000648, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_339", 0x00000648, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_340
	{ "roi_avg_r_data_340", 0x0000064C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_340", 0x0000064C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_341
	{ "roi_avg_r_data_341", 0x00000650, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_341", 0x00000650, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_342
	{ "roi_avg_r_data_342", 0x00000654, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_342", 0x00000654, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_343
	{ "roi_avg_r_data_343", 0x00000658, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_343", 0x00000658, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_344
	{ "roi_avg_r_data_344", 0x0000065C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_344", 0x0000065C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_345
	{ "roi_avg_r_data_345", 0x00000660, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_345", 0x00000660, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_346
	{ "roi_avg_r_data_346", 0x00000664, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_346", 0x00000664, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_347
	{ "roi_avg_r_data_347", 0x00000668, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_347", 0x00000668, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_348
	{ "roi_avg_r_data_348", 0x0000066C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_348", 0x0000066C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_349
	{ "roi_avg_r_data_349", 0x00000670, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_349", 0x00000670, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_350
	{ "roi_avg_r_data_350", 0x00000674, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_350", 0x00000674, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_351
	{ "roi_avg_r_data_351", 0x00000678, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_351", 0x00000678, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_352
	{ "roi_avg_r_data_352", 0x0000067C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_352", 0x0000067C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_353
	{ "roi_avg_r_data_353", 0x00000680, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_353", 0x00000680, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_354
	{ "roi_avg_r_data_354", 0x00000684, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_354", 0x00000684, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_355
	{ "roi_avg_r_data_355", 0x00000688, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_355", 0x00000688, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_356
	{ "roi_avg_r_data_356", 0x0000068C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_356", 0x0000068C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_357
	{ "roi_avg_r_data_357", 0x00000690, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_357", 0x00000690, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_358
	{ "roi_avg_r_data_358", 0x00000694, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_358", 0x00000694, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_359
	{ "roi_avg_r_data_359", 0x00000698, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_359", 0x00000698, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_360
	{ "roi_avg_r_data_360", 0x0000069C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_360", 0x0000069C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_361
	{ "roi_avg_r_data_361", 0x000006A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_361", 0x000006A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_362
	{ "roi_avg_r_data_362", 0x000006A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_362", 0x000006A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_363
	{ "roi_avg_r_data_363", 0x000006A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_363", 0x000006A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_364
	{ "roi_avg_r_data_364", 0x000006AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_364", 0x000006AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_365
	{ "roi_avg_r_data_365", 0x000006B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_365", 0x000006B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_366
	{ "roi_avg_r_data_366", 0x000006B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_366", 0x000006B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_367
	{ "roi_avg_r_data_367", 0x000006B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_367", 0x000006B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_368
	{ "roi_avg_r_data_368", 0x000006BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_368", 0x000006BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_369
	{ "roi_avg_r_data_369", 0x000006C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_369", 0x000006C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_370
	{ "roi_avg_r_data_370", 0x000006C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_370", 0x000006C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_371
	{ "roi_avg_r_data_371", 0x000006C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_371", 0x000006C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_372
	{ "roi_avg_r_data_372", 0x000006CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_372", 0x000006CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_373
	{ "roi_avg_r_data_373", 0x000006D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_373", 0x000006D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_374
	{ "roi_avg_r_data_374", 0x000006D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_374", 0x000006D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_375
	{ "roi_avg_r_data_375", 0x000006D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_375", 0x000006D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_376
	{ "roi_avg_r_data_376", 0x000006DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_376", 0x000006DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_377
	{ "roi_avg_r_data_377", 0x000006E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_377", 0x000006E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_378
	{ "roi_avg_r_data_378", 0x000006E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_378", 0x000006E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_379
	{ "roi_avg_r_data_379", 0x000006E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_379", 0x000006E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_380
	{ "roi_avg_r_data_380", 0x000006EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_380", 0x000006EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_381
	{ "roi_avg_r_data_381", 0x000006F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_381", 0x000006F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_382
	{ "roi_avg_r_data_382", 0x000006F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_382", 0x000006F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_383
	{ "roi_avg_r_data_383", 0x000006F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_383", 0x000006F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_384
	{ "roi_avg_r_data_384", 0x000006FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_384", 0x000006FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_385
	{ "roi_avg_r_data_385", 0x00000700, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_385", 0x00000700, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_386
	{ "roi_avg_r_data_386", 0x00000704, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_386", 0x00000704, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_387
	{ "roi_avg_r_data_387", 0x00000708, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_387", 0x00000708, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_388
	{ "roi_avg_r_data_388", 0x0000070C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_388", 0x0000070C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_389
	{ "roi_avg_r_data_389", 0x00000710, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_389", 0x00000710, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_390
	{ "roi_avg_r_data_390", 0x00000714, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_390", 0x00000714, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_391
	{ "roi_avg_r_data_391", 0x00000718, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_391", 0x00000718, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_392
	{ "roi_avg_r_data_392", 0x0000071C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_392", 0x0000071C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_393
	{ "roi_avg_r_data_393", 0x00000720, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_393", 0x00000720, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_394
	{ "roi_avg_r_data_394", 0x00000724, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_394", 0x00000724, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_395
	{ "roi_avg_r_data_395", 0x00000728, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_395", 0x00000728, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_396
	{ "roi_avg_r_data_396", 0x0000072C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_396", 0x0000072C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_397
	{ "roi_avg_r_data_397", 0x00000730, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_397", 0x00000730, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_398
	{ "roi_avg_r_data_398", 0x00000734, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_398", 0x00000734, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_399
	{ "roi_avg_r_data_399", 0x00000738, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_399", 0x00000738, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_400
	{ "roi_avg_r_data_400", 0x0000073C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_400", 0x0000073C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_401
	{ "roi_avg_r_data_401", 0x00000740, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_401", 0x00000740, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_402
	{ "roi_avg_r_data_402", 0x00000744, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_402", 0x00000744, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_403
	{ "roi_avg_r_data_403", 0x00000748, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_403", 0x00000748, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_404
	{ "roi_avg_r_data_404", 0x0000074C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_404", 0x0000074C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_405
	{ "roi_avg_r_data_405", 0x00000750, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_405", 0x00000750, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_406
	{ "roi_avg_r_data_406", 0x00000754, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_406", 0x00000754, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_407
	{ "roi_avg_r_data_407", 0x00000758, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_407", 0x00000758, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_408
	{ "roi_avg_r_data_408", 0x0000075C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_408", 0x0000075C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_409
	{ "roi_avg_r_data_409", 0x00000760, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_409", 0x00000760, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_410
	{ "roi_avg_r_data_410", 0x00000764, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_410", 0x00000764, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_411
	{ "roi_avg_r_data_411", 0x00000768, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_411", 0x00000768, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_412
	{ "roi_avg_r_data_412", 0x0000076C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_412", 0x0000076C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_413
	{ "roi_avg_r_data_413", 0x00000770, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_413", 0x00000770, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_414
	{ "roi_avg_r_data_414", 0x00000774, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_414", 0x00000774, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_415
	{ "roi_avg_r_data_415", 0x00000778, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_415", 0x00000778, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_416
	{ "roi_avg_r_data_416", 0x0000077C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_416", 0x0000077C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_417
	{ "roi_avg_r_data_417", 0x00000780, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_417", 0x00000780, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_418
	{ "roi_avg_r_data_418", 0x00000784, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_418", 0x00000784, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_419
	{ "roi_avg_r_data_419", 0x00000788, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_419", 0x00000788, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_420
	{ "roi_avg_r_data_420", 0x0000078C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_420", 0x0000078C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_421
	{ "roi_avg_r_data_421", 0x00000790, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_421", 0x00000790, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_422
	{ "roi_avg_r_data_422", 0x00000794, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_422", 0x00000794, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_423
	{ "roi_avg_r_data_423", 0x00000798, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_423", 0x00000798, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_424
	{ "roi_avg_r_data_424", 0x0000079C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_424", 0x0000079C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_425
	{ "roi_avg_r_data_425", 0x000007A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_425", 0x000007A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_426
	{ "roi_avg_r_data_426", 0x000007A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_426", 0x000007A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_427
	{ "roi_avg_r_data_427", 0x000007A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_427", 0x000007A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_428
	{ "roi_avg_r_data_428", 0x000007AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_428", 0x000007AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_429
	{ "roi_avg_r_data_429", 0x000007B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_429", 0x000007B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_430
	{ "roi_avg_r_data_430", 0x000007B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_430", 0x000007B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_431
	{ "roi_avg_r_data_431", 0x000007B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_431", 0x000007B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_432
	{ "roi_avg_r_data_432", 0x000007BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_432", 0x000007BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_433
	{ "roi_avg_r_data_433", 0x000007C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_433", 0x000007C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_434
	{ "roi_avg_r_data_434", 0x000007C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_434", 0x000007C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_435
	{ "roi_avg_r_data_435", 0x000007C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_435", 0x000007C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_436
	{ "roi_avg_r_data_436", 0x000007CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_436", 0x000007CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_437
	{ "roi_avg_r_data_437", 0x000007D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_437", 0x000007D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_438
	{ "roi_avg_r_data_438", 0x000007D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_438", 0x000007D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_439
	{ "roi_avg_r_data_439", 0x000007D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_439", 0x000007D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_440
	{ "roi_avg_r_data_440", 0x000007DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_440", 0x000007DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_441
	{ "roi_avg_r_data_441", 0x000007E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_441", 0x000007E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_442
	{ "roi_avg_r_data_442", 0x000007E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_442", 0x000007E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_443
	{ "roi_avg_r_data_443", 0x000007E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_443", 0x000007E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_444
	{ "roi_avg_r_data_444", 0x000007EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_444", 0x000007EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_445
	{ "roi_avg_r_data_445", 0x000007F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_445", 0x000007F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_446
	{ "roi_avg_r_data_446", 0x000007F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_446", 0x000007F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_447
	{ "roi_avg_r_data_447", 0x000007F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_447", 0x000007F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_448
	{ "roi_avg_r_data_448", 0x000007FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_448", 0x000007FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_449
	{ "roi_avg_r_data_449", 0x00000800, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_449", 0x00000800, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_450
	{ "roi_avg_r_data_450", 0x00000804, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_450", 0x00000804, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_451
	{ "roi_avg_r_data_451", 0x00000808, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_451", 0x00000808, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_452
	{ "roi_avg_r_data_452", 0x0000080C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_452", 0x0000080C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_453
	{ "roi_avg_r_data_453", 0x00000810, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_453", 0x00000810, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_454
	{ "roi_avg_r_data_454", 0x00000814, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_454", 0x00000814, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_455
	{ "roi_avg_r_data_455", 0x00000818, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_455", 0x00000818, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_456
	{ "roi_avg_r_data_456", 0x0000081C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_456", 0x0000081C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_457
	{ "roi_avg_r_data_457", 0x00000820, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_457", 0x00000820, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_458
	{ "roi_avg_r_data_458", 0x00000824, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_458", 0x00000824, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_459
	{ "roi_avg_r_data_459", 0x00000828, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_459", 0x00000828, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_460
	{ "roi_avg_r_data_460", 0x0000082C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_460", 0x0000082C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_461
	{ "roi_avg_r_data_461", 0x00000830, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_461", 0x00000830, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_462
	{ "roi_avg_r_data_462", 0x00000834, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_462", 0x00000834, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_463
	{ "roi_avg_r_data_463", 0x00000838, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_463", 0x00000838, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_464
	{ "roi_avg_r_data_464", 0x0000083C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_464", 0x0000083C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_465
	{ "roi_avg_r_data_465", 0x00000840, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_465", 0x00000840, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_466
	{ "roi_avg_r_data_466", 0x00000844, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_466", 0x00000844, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_467
	{ "roi_avg_r_data_467", 0x00000848, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_467", 0x00000848, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_468
	{ "roi_avg_r_data_468", 0x0000084C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_468", 0x0000084C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_469
	{ "roi_avg_r_data_469", 0x00000850, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_469", 0x00000850, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_470
	{ "roi_avg_r_data_470", 0x00000854, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_470", 0x00000854, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_471
	{ "roi_avg_r_data_471", 0x00000858, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_471", 0x00000858, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_472
	{ "roi_avg_r_data_472", 0x0000085C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_472", 0x0000085C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_473
	{ "roi_avg_r_data_473", 0x00000860, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_473", 0x00000860, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_474
	{ "roi_avg_r_data_474", 0x00000864, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_474", 0x00000864, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_475
	{ "roi_avg_r_data_475", 0x00000868, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_475", 0x00000868, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_476
	{ "roi_avg_r_data_476", 0x0000086C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_476", 0x0000086C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_477
	{ "roi_avg_r_data_477", 0x00000870, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_477", 0x00000870, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_478
	{ "roi_avg_r_data_478", 0x00000874, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_478", 0x00000874, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_479
	{ "roi_avg_r_data_479", 0x00000878, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_479", 0x00000878, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_480
	{ "roi_avg_r_data_480", 0x0000087C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_480", 0x0000087C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_481
	{ "roi_avg_r_data_481", 0x00000880, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_481", 0x00000880, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_482
	{ "roi_avg_r_data_482", 0x00000884, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_482", 0x00000884, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_483
	{ "roi_avg_r_data_483", 0x00000888, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_483", 0x00000888, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_484
	{ "roi_avg_r_data_484", 0x0000088C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_484", 0x0000088C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_485
	{ "roi_avg_r_data_485", 0x00000890, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_485", 0x00000890, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_486
	{ "roi_avg_r_data_486", 0x00000894, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_486", 0x00000894, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_487
	{ "roi_avg_r_data_487", 0x00000898, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_487", 0x00000898, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_488
	{ "roi_avg_r_data_488", 0x0000089C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_488", 0x0000089C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_489
	{ "roi_avg_r_data_489", 0x000008A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_489", 0x000008A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_490
	{ "roi_avg_r_data_490", 0x000008A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_490", 0x000008A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_491
	{ "roi_avg_r_data_491", 0x000008A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_491", 0x000008A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_492
	{ "roi_avg_r_data_492", 0x000008AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_492", 0x000008AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_493
	{ "roi_avg_r_data_493", 0x000008B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_493", 0x000008B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_494
	{ "roi_avg_r_data_494", 0x000008B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_494", 0x000008B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_495
	{ "roi_avg_r_data_495", 0x000008B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_495", 0x000008B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_496
	{ "roi_avg_r_data_496", 0x000008BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_496", 0x000008BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_497
	{ "roi_avg_r_data_497", 0x000008C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_497", 0x000008C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_498
	{ "roi_avg_r_data_498", 0x000008C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_498", 0x000008C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_499
	{ "roi_avg_r_data_499", 0x000008C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_499", 0x000008C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_500
	{ "roi_avg_r_data_500", 0x000008CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_500", 0x000008CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_501
	{ "roi_avg_r_data_501", 0x000008D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_501", 0x000008D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_502
	{ "roi_avg_r_data_502", 0x000008D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_502", 0x000008D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_503
	{ "roi_avg_r_data_503", 0x000008D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_503", 0x000008D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_504
	{ "roi_avg_r_data_504", 0x000008DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_504", 0x000008DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_505
	{ "roi_avg_r_data_505", 0x000008E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_505", 0x000008E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_506
	{ "roi_avg_r_data_506", 0x000008E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_506", 0x000008E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_507
	{ "roi_avg_r_data_507", 0x000008E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_507", 0x000008E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_508
	{ "roi_avg_r_data_508", 0x000008EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_508", 0x000008EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_509
	{ "roi_avg_r_data_509", 0x000008F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_509", 0x000008F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_510
	{ "roi_avg_r_data_510", 0x000008F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_510", 0x000008F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_511
	{ "roi_avg_r_data_511", 0x000008F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_511", 0x000008F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_512
	{ "roi_avg_r_data_512", 0x000008FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_512", 0x000008FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_513
	{ "roi_avg_r_data_513", 0x00000900, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_513", 0x00000900, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_514
	{ "roi_avg_r_data_514", 0x00000904, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_514", 0x00000904, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_515
	{ "roi_avg_r_data_515", 0x00000908, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_515", 0x00000908, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_516
	{ "roi_avg_r_data_516", 0x0000090C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_516", 0x0000090C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_517
	{ "roi_avg_r_data_517", 0x00000910, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_517", 0x00000910, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_518
	{ "roi_avg_r_data_518", 0x00000914, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_518", 0x00000914, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_519
	{ "roi_avg_r_data_519", 0x00000918, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_519", 0x00000918, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_520
	{ "roi_avg_r_data_520", 0x0000091C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_520", 0x0000091C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_521
	{ "roi_avg_r_data_521", 0x00000920, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_521", 0x00000920, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_522
	{ "roi_avg_r_data_522", 0x00000924, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_522", 0x00000924, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_523
	{ "roi_avg_r_data_523", 0x00000928, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_523", 0x00000928, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_524
	{ "roi_avg_r_data_524", 0x0000092C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_524", 0x0000092C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_525
	{ "roi_avg_r_data_525", 0x00000930, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_525", 0x00000930, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_526
	{ "roi_avg_r_data_526", 0x00000934, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_526", 0x00000934, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_527
	{ "roi_avg_r_data_527", 0x00000938, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_527", 0x00000938, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_528
	{ "roi_avg_r_data_528", 0x0000093C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_528", 0x0000093C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_529
	{ "roi_avg_r_data_529", 0x00000940, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_529", 0x00000940, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_530
	{ "roi_avg_r_data_530", 0x00000944, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_530", 0x00000944, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_531
	{ "roi_avg_r_data_531", 0x00000948, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_531", 0x00000948, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_532
	{ "roi_avg_r_data_532", 0x0000094C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_532", 0x0000094C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_533
	{ "roi_avg_r_data_533", 0x00000950, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_533", 0x00000950, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_534
	{ "roi_avg_r_data_534", 0x00000954, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_534", 0x00000954, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_535
	{ "roi_avg_r_data_535", 0x00000958, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_535", 0x00000958, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_536
	{ "roi_avg_r_data_536", 0x0000095C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_536", 0x0000095C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_537
	{ "roi_avg_r_data_537", 0x00000960, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_537", 0x00000960, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_538
	{ "roi_avg_r_data_538", 0x00000964, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_538", 0x00000964, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_539
	{ "roi_avg_r_data_539", 0x00000968, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_539", 0x00000968, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_540
	{ "roi_avg_r_data_540", 0x0000096C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_540", 0x0000096C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_541
	{ "roi_avg_r_data_541", 0x00000970, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_541", 0x00000970, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_542
	{ "roi_avg_r_data_542", 0x00000974, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_542", 0x00000974, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_543
	{ "roi_avg_r_data_543", 0x00000978, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_543", 0x00000978, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_544
	{ "roi_avg_r_data_544", 0x0000097C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_544", 0x0000097C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_545
	{ "roi_avg_r_data_545", 0x00000980, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_545", 0x00000980, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_546
	{ "roi_avg_r_data_546", 0x00000984, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_546", 0x00000984, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_547
	{ "roi_avg_r_data_547", 0x00000988, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_547", 0x00000988, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_548
	{ "roi_avg_r_data_548", 0x0000098C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_548", 0x0000098C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_549
	{ "roi_avg_r_data_549", 0x00000990, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_549", 0x00000990, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_550
	{ "roi_avg_r_data_550", 0x00000994, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_550", 0x00000994, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_551
	{ "roi_avg_r_data_551", 0x00000998, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_551", 0x00000998, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_552
	{ "roi_avg_r_data_552", 0x0000099C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_552", 0x0000099C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_553
	{ "roi_avg_r_data_553", 0x000009A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_553", 0x000009A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_554
	{ "roi_avg_r_data_554", 0x000009A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_554", 0x000009A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_555
	{ "roi_avg_r_data_555", 0x000009A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_555", 0x000009A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_556
	{ "roi_avg_r_data_556", 0x000009AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_556", 0x000009AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_557
	{ "roi_avg_r_data_557", 0x000009B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_557", 0x000009B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_558
	{ "roi_avg_r_data_558", 0x000009B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_558", 0x000009B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_559
	{ "roi_avg_r_data_559", 0x000009B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_559", 0x000009B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_560
	{ "roi_avg_r_data_560", 0x000009BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_560", 0x000009BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_561
	{ "roi_avg_r_data_561", 0x000009C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_561", 0x000009C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_562
	{ "roi_avg_r_data_562", 0x000009C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_562", 0x000009C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_563
	{ "roi_avg_r_data_563", 0x000009C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_563", 0x000009C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_564
	{ "roi_avg_r_data_564", 0x000009CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_564", 0x000009CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_565
	{ "roi_avg_r_data_565", 0x000009D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_565", 0x000009D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_566
	{ "roi_avg_r_data_566", 0x000009D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_566", 0x000009D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_567
	{ "roi_avg_r_data_567", 0x000009D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_567", 0x000009D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_568
	{ "roi_avg_r_data_568", 0x000009DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_568", 0x000009DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_569
	{ "roi_avg_r_data_569", 0x000009E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_569", 0x000009E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_570
	{ "roi_avg_r_data_570", 0x000009E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_570", 0x000009E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_571
	{ "roi_avg_r_data_571", 0x000009E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_571", 0x000009E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_572
	{ "roi_avg_r_data_572", 0x000009EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_572", 0x000009EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_573
	{ "roi_avg_r_data_573", 0x000009F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_573", 0x000009F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_574
	{ "roi_avg_r_data_574", 0x000009F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_574", 0x000009F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_575
	{ "roi_avg_r_data_575", 0x000009F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_575", 0x000009F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_576
	{ "roi_avg_r_data_576", 0x000009FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_576", 0x000009FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_577
	{ "roi_avg_r_data_577", 0x00000A00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_577", 0x00000A00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_578
	{ "roi_avg_r_data_578", 0x00000A04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_578", 0x00000A04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_579
	{ "roi_avg_r_data_579", 0x00000A08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_579", 0x00000A08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_580
	{ "roi_avg_r_data_580", 0x00000A0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_580", 0x00000A0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_581
	{ "roi_avg_r_data_581", 0x00000A10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_581", 0x00000A10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_582
	{ "roi_avg_r_data_582", 0x00000A14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_582", 0x00000A14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_583
	{ "roi_avg_r_data_583", 0x00000A18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_583", 0x00000A18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_584
	{ "roi_avg_r_data_584", 0x00000A1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_584", 0x00000A1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_585
	{ "roi_avg_r_data_585", 0x00000A20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_585", 0x00000A20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_586
	{ "roi_avg_r_data_586", 0x00000A24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_586", 0x00000A24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_587
	{ "roi_avg_r_data_587", 0x00000A28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_587", 0x00000A28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_588
	{ "roi_avg_r_data_588", 0x00000A2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_588", 0x00000A2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_589
	{ "roi_avg_r_data_589", 0x00000A30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_589", 0x00000A30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_590
	{ "roi_avg_r_data_590", 0x00000A34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_590", 0x00000A34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_591
	{ "roi_avg_r_data_591", 0x00000A38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_591", 0x00000A38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_592
	{ "roi_avg_r_data_592", 0x00000A3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_592", 0x00000A3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_593
	{ "roi_avg_r_data_593", 0x00000A40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_593", 0x00000A40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_594
	{ "roi_avg_r_data_594", 0x00000A44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_594", 0x00000A44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_595
	{ "roi_avg_r_data_595", 0x00000A48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_595", 0x00000A48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_596
	{ "roi_avg_r_data_596", 0x00000A4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_596", 0x00000A4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_597
	{ "roi_avg_r_data_597", 0x00000A50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_597", 0x00000A50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_598
	{ "roi_avg_r_data_598", 0x00000A54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_598", 0x00000A54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_599
	{ "roi_avg_r_data_599", 0x00000A58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_599", 0x00000A58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_600
	{ "roi_avg_r_data_600", 0x00000A5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_600", 0x00000A5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_601
	{ "roi_avg_r_data_601", 0x00000A60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_601", 0x00000A60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_602
	{ "roi_avg_r_data_602", 0x00000A64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_602", 0x00000A64, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_603
	{ "roi_avg_r_data_603", 0x00000A68, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_603", 0x00000A68, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_604
	{ "roi_avg_r_data_604", 0x00000A6C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_604", 0x00000A6C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_605
	{ "roi_avg_r_data_605", 0x00000A70, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_605", 0x00000A70, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_606
	{ "roi_avg_r_data_606", 0x00000A74, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_606", 0x00000A74, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_607
	{ "roi_avg_r_data_607", 0x00000A78, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_607", 0x00000A78, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_608
	{ "roi_avg_r_data_608", 0x00000A7C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_608", 0x00000A7C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_609
	{ "roi_avg_r_data_609", 0x00000A80, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_609", 0x00000A80, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_610
	{ "roi_avg_r_data_610", 0x00000A84, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_610", 0x00000A84, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_611
	{ "roi_avg_r_data_611", 0x00000A88, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_611", 0x00000A88, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_612
	{ "roi_avg_r_data_612", 0x00000A8C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_612", 0x00000A8C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_613
	{ "roi_avg_r_data_613", 0x00000A90, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_613", 0x00000A90, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_614
	{ "roi_avg_r_data_614", 0x00000A94, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_614", 0x00000A94, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_615
	{ "roi_avg_r_data_615", 0x00000A98, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_615", 0x00000A98, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_616
	{ "roi_avg_r_data_616", 0x00000A9C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_616", 0x00000A9C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_617
	{ "roi_avg_r_data_617", 0x00000AA0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_617", 0x00000AA0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_618
	{ "roi_avg_r_data_618", 0x00000AA4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_618", 0x00000AA4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_619
	{ "roi_avg_r_data_619", 0x00000AA8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_619", 0x00000AA8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_620
	{ "roi_avg_r_data_620", 0x00000AAC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_620", 0x00000AAC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_621
	{ "roi_avg_r_data_621", 0x00000AB0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_621", 0x00000AB0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_622
	{ "roi_avg_r_data_622", 0x00000AB4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_622", 0x00000AB4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_623
	{ "roi_avg_r_data_623", 0x00000AB8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_623", 0x00000AB8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_624
	{ "roi_avg_r_data_624", 0x00000ABC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_624", 0x00000ABC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_625
	{ "roi_avg_r_data_625", 0x00000AC0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_625", 0x00000AC0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_626
	{ "roi_avg_r_data_626", 0x00000AC4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_626", 0x00000AC4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_627
	{ "roi_avg_r_data_627", 0x00000AC8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_627", 0x00000AC8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_628
	{ "roi_avg_r_data_628", 0x00000ACC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_628", 0x00000ACC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_629
	{ "roi_avg_r_data_629", 0x00000AD0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_629", 0x00000AD0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_630
	{ "roi_avg_r_data_630", 0x00000AD4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_630", 0x00000AD4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_631
	{ "roi_avg_r_data_631", 0x00000AD8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_631", 0x00000AD8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_632
	{ "roi_avg_r_data_632", 0x00000ADC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_632", 0x00000ADC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_633
	{ "roi_avg_r_data_633", 0x00000AE0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_633", 0x00000AE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_634
	{ "roi_avg_r_data_634", 0x00000AE4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_634", 0x00000AE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_635
	{ "roi_avg_r_data_635", 0x00000AE8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_635", 0x00000AE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_636
	{ "roi_avg_r_data_636", 0x00000AEC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_636", 0x00000AEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_637
	{ "roi_avg_r_data_637", 0x00000AF0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_637", 0x00000AF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_638
	{ "roi_avg_r_data_638", 0x00000AF4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_638", 0x00000AF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_639
	{ "roi_avg_r_data_639", 0x00000AF8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_639", 0x00000AF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_640
	{ "roi_avg_r_data_640", 0x00000AFC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_640", 0x00000AFC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_641
	{ "roi_avg_r_data_641", 0x00000B00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_641", 0x00000B00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_642
	{ "roi_avg_r_data_642", 0x00000B04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_642", 0x00000B04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_643
	{ "roi_avg_r_data_643", 0x00000B08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_643", 0x00000B08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_644
	{ "roi_avg_r_data_644", 0x00000B0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_644", 0x00000B0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_645
	{ "roi_avg_r_data_645", 0x00000B10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_645", 0x00000B10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_646
	{ "roi_avg_r_data_646", 0x00000B14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_646", 0x00000B14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_647
	{ "roi_avg_r_data_647", 0x00000B18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_647", 0x00000B18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_648
	{ "roi_avg_r_data_648", 0x00000B1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_648", 0x00000B1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_649
	{ "roi_avg_r_data_649", 0x00000B20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_649", 0x00000B20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_650
	{ "roi_avg_r_data_650", 0x00000B24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_650", 0x00000B24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_651
	{ "roi_avg_r_data_651", 0x00000B28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_651", 0x00000B28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_652
	{ "roi_avg_r_data_652", 0x00000B2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_652", 0x00000B2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_653
	{ "roi_avg_r_data_653", 0x00000B30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_653", 0x00000B30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_654
	{ "roi_avg_r_data_654", 0x00000B34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_654", 0x00000B34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_655
	{ "roi_avg_r_data_655", 0x00000B38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_655", 0x00000B38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_656
	{ "roi_avg_r_data_656", 0x00000B3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_656", 0x00000B3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_657
	{ "roi_avg_r_data_657", 0x00000B40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_657", 0x00000B40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_658
	{ "roi_avg_r_data_658", 0x00000B44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_658", 0x00000B44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_659
	{ "roi_avg_r_data_659", 0x00000B48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_659", 0x00000B48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_660
	{ "roi_avg_r_data_660", 0x00000B4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_660", 0x00000B4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_661
	{ "roi_avg_r_data_661", 0x00000B50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_661", 0x00000B50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_662
	{ "roi_avg_r_data_662", 0x00000B54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_662", 0x00000B54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_663
	{ "roi_avg_r_data_663", 0x00000B58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_663", 0x00000B58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_664
	{ "roi_avg_r_data_664", 0x00000B5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_664", 0x00000B5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_665
	{ "roi_avg_r_data_665", 0x00000B60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_665", 0x00000B60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_666
	{ "roi_avg_r_data_666", 0x00000B64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_666", 0x00000B64, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_667
	{ "roi_avg_r_data_667", 0x00000B68, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_667", 0x00000B68, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_668
	{ "roi_avg_r_data_668", 0x00000B6C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_668", 0x00000B6C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_669
	{ "roi_avg_r_data_669", 0x00000B70, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_669", 0x00000B70, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_670
	{ "roi_avg_r_data_670", 0x00000B74, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_670", 0x00000B74, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_671
	{ "roi_avg_r_data_671", 0x00000B78, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_671", 0x00000B78, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_672
	{ "roi_avg_r_data_672", 0x00000B7C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_672", 0x00000B7C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_673
	{ "roi_avg_r_data_673", 0x00000B80, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_673", 0x00000B80, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_674
	{ "roi_avg_r_data_674", 0x00000B84, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_674", 0x00000B84, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_675
	{ "roi_avg_r_data_675", 0x00000B88, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_675", 0x00000B88, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_676
	{ "roi_avg_r_data_676", 0x00000B8C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_676", 0x00000B8C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_677
	{ "roi_avg_r_data_677", 0x00000B90, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_677", 0x00000B90, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_678
	{ "roi_avg_r_data_678", 0x00000B94, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_678", 0x00000B94, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_679
	{ "roi_avg_r_data_679", 0x00000B98, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_679", 0x00000B98, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_680
	{ "roi_avg_r_data_680", 0x00000B9C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_680", 0x00000B9C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_681
	{ "roi_avg_r_data_681", 0x00000BA0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_681", 0x00000BA0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_682
	{ "roi_avg_r_data_682", 0x00000BA4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_682", 0x00000BA4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_683
	{ "roi_avg_r_data_683", 0x00000BA8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_683", 0x00000BA8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_684
	{ "roi_avg_r_data_684", 0x00000BAC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_684", 0x00000BAC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_685
	{ "roi_avg_r_data_685", 0x00000BB0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_685", 0x00000BB0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_686
	{ "roi_avg_r_data_686", 0x00000BB4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_686", 0x00000BB4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_687
	{ "roi_avg_r_data_687", 0x00000BB8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_687", 0x00000BB8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_688
	{ "roi_avg_r_data_688", 0x00000BBC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_688", 0x00000BBC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_689
	{ "roi_avg_r_data_689", 0x00000BC0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_689", 0x00000BC0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_690
	{ "roi_avg_r_data_690", 0x00000BC4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_690", 0x00000BC4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_691
	{ "roi_avg_r_data_691", 0x00000BC8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_691", 0x00000BC8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_692
	{ "roi_avg_r_data_692", 0x00000BCC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_692", 0x00000BCC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_693
	{ "roi_avg_r_data_693", 0x00000BD0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_693", 0x00000BD0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_694
	{ "roi_avg_r_data_694", 0x00000BD4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_694", 0x00000BD4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_695
	{ "roi_avg_r_data_695", 0x00000BD8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_695", 0x00000BD8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_696
	{ "roi_avg_r_data_696", 0x00000BDC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_696", 0x00000BDC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_697
	{ "roi_avg_r_data_697", 0x00000BE0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_697", 0x00000BE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_698
	{ "roi_avg_r_data_698", 0x00000BE4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_698", 0x00000BE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_699
	{ "roi_avg_r_data_699", 0x00000BE8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_699", 0x00000BE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_700
	{ "roi_avg_r_data_700", 0x00000BEC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_700", 0x00000BEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_701
	{ "roi_avg_r_data_701", 0x00000BF0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_701", 0x00000BF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_702
	{ "roi_avg_r_data_702", 0x00000BF4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_702", 0x00000BF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_703
	{ "roi_avg_r_data_703", 0x00000BF8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_703", 0x00000BF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_704
	{ "roi_avg_r_data_704", 0x00000BFC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_704", 0x00000BFC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_705
	{ "roi_avg_r_data_705", 0x00000C00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_705", 0x00000C00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_706
	{ "roi_avg_r_data_706", 0x00000C04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_706", 0x00000C04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_707
	{ "roi_avg_r_data_707", 0x00000C08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_707", 0x00000C08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_708
	{ "roi_avg_r_data_708", 0x00000C0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_708", 0x00000C0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_709
	{ "roi_avg_r_data_709", 0x00000C10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_709", 0x00000C10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_710
	{ "roi_avg_r_data_710", 0x00000C14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_710", 0x00000C14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_711
	{ "roi_avg_r_data_711", 0x00000C18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_711", 0x00000C18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_712
	{ "roi_avg_r_data_712", 0x00000C1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_712", 0x00000C1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_713
	{ "roi_avg_r_data_713", 0x00000C20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_713", 0x00000C20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_714
	{ "roi_avg_r_data_714", 0x00000C24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_714", 0x00000C24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_715
	{ "roi_avg_r_data_715", 0x00000C28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_715", 0x00000C28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_716
	{ "roi_avg_r_data_716", 0x00000C2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_716", 0x00000C2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_717
	{ "roi_avg_r_data_717", 0x00000C30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_717", 0x00000C30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_718
	{ "roi_avg_r_data_718", 0x00000C34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_718", 0x00000C34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_719
	{ "roi_avg_r_data_719", 0x00000C38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_719", 0x00000C38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_720
	{ "roi_avg_r_data_720", 0x00000C3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_720", 0x00000C3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_721
	{ "roi_avg_r_data_721", 0x00000C40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_721", 0x00000C40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_722
	{ "roi_avg_r_data_722", 0x00000C44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_722", 0x00000C44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_723
	{ "roi_avg_r_data_723", 0x00000C48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_723", 0x00000C48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_724
	{ "roi_avg_r_data_724", 0x00000C4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_724", 0x00000C4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_725
	{ "roi_avg_r_data_725", 0x00000C50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_725", 0x00000C50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_726
	{ "roi_avg_r_data_726", 0x00000C54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_726", 0x00000C54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_727
	{ "roi_avg_r_data_727", 0x00000C58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_727", 0x00000C58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_728
	{ "roi_avg_r_data_728", 0x00000C5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_728", 0x00000C5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_729
	{ "roi_avg_r_data_729", 0x00000C60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_729", 0x00000C60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_730
	{ "roi_avg_r_data_730", 0x00000C64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_730", 0x00000C64, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_731
	{ "roi_avg_r_data_731", 0x00000C68, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_731", 0x00000C68, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_732
	{ "roi_avg_r_data_732", 0x00000C6C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_732", 0x00000C6C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_733
	{ "roi_avg_r_data_733", 0x00000C70, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_733", 0x00000C70, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_734
	{ "roi_avg_r_data_734", 0x00000C74, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_734", 0x00000C74, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_735
	{ "roi_avg_r_data_735", 0x00000C78, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_735", 0x00000C78, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_736
	{ "roi_avg_r_data_736", 0x00000C7C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_736", 0x00000C7C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_737
	{ "roi_avg_r_data_737", 0x00000C80, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_737", 0x00000C80, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_738
	{ "roi_avg_r_data_738", 0x00000C84, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_738", 0x00000C84, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_739
	{ "roi_avg_r_data_739", 0x00000C88, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_739", 0x00000C88, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_740
	{ "roi_avg_r_data_740", 0x00000C8C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_740", 0x00000C8C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_741
	{ "roi_avg_r_data_741", 0x00000C90, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_741", 0x00000C90, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_742
	{ "roi_avg_r_data_742", 0x00000C94, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_742", 0x00000C94, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_743
	{ "roi_avg_r_data_743", 0x00000C98, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_743", 0x00000C98, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_744
	{ "roi_avg_r_data_744", 0x00000C9C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_744", 0x00000C9C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_745
	{ "roi_avg_r_data_745", 0x00000CA0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_745", 0x00000CA0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_746
	{ "roi_avg_r_data_746", 0x00000CA4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_746", 0x00000CA4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_747
	{ "roi_avg_r_data_747", 0x00000CA8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_747", 0x00000CA8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_748
	{ "roi_avg_r_data_748", 0x00000CAC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_748", 0x00000CAC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_749
	{ "roi_avg_r_data_749", 0x00000CB0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_749", 0x00000CB0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_750
	{ "roi_avg_r_data_750", 0x00000CB4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_750", 0x00000CB4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_751
	{ "roi_avg_r_data_751", 0x00000CB8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_751", 0x00000CB8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_752
	{ "roi_avg_r_data_752", 0x00000CBC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_752", 0x00000CBC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_753
	{ "roi_avg_r_data_753", 0x00000CC0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_753", 0x00000CC0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_754
	{ "roi_avg_r_data_754", 0x00000CC4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_754", 0x00000CC4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_755
	{ "roi_avg_r_data_755", 0x00000CC8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_755", 0x00000CC8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_756
	{ "roi_avg_r_data_756", 0x00000CCC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_756", 0x00000CCC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_757
	{ "roi_avg_r_data_757", 0x00000CD0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_757", 0x00000CD0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_758
	{ "roi_avg_r_data_758", 0x00000CD4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_758", 0x00000CD4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_759
	{ "roi_avg_r_data_759", 0x00000CD8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_759", 0x00000CD8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_760
	{ "roi_avg_r_data_760", 0x00000CDC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_760", 0x00000CDC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_761
	{ "roi_avg_r_data_761", 0x00000CE0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_761", 0x00000CE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_762
	{ "roi_avg_r_data_762", 0x00000CE4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_762", 0x00000CE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_763
	{ "roi_avg_r_data_763", 0x00000CE8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_763", 0x00000CE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_764
	{ "roi_avg_r_data_764", 0x00000CEC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_764", 0x00000CEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_765
	{ "roi_avg_r_data_765", 0x00000CF0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_765", 0x00000CF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_766
	{ "roi_avg_r_data_766", 0x00000CF4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_766", 0x00000CF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_767
	{ "roi_avg_r_data_767", 0x00000CF8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_767", 0x00000CF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_768
	{ "roi_avg_r_data_768", 0x00000CFC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_768", 0x00000CFC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_769
	{ "roi_avg_r_data_769", 0x00000D00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_769", 0x00000D00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_770
	{ "roi_avg_r_data_770", 0x00000D04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_770", 0x00000D04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_771
	{ "roi_avg_r_data_771", 0x00000D08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_771", 0x00000D08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_772
	{ "roi_avg_r_data_772", 0x00000D0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_772", 0x00000D0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_773
	{ "roi_avg_r_data_773", 0x00000D10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_773", 0x00000D10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_774
	{ "roi_avg_r_data_774", 0x00000D14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_774", 0x00000D14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_775
	{ "roi_avg_r_data_775", 0x00000D18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_775", 0x00000D18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_776
	{ "roi_avg_r_data_776", 0x00000D1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_776", 0x00000D1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_777
	{ "roi_avg_r_data_777", 0x00000D20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_777", 0x00000D20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_778
	{ "roi_avg_r_data_778", 0x00000D24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_778", 0x00000D24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_779
	{ "roi_avg_r_data_779", 0x00000D28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_779", 0x00000D28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_780
	{ "roi_avg_r_data_780", 0x00000D2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_780", 0x00000D2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_781
	{ "roi_avg_r_data_781", 0x00000D30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_781", 0x00000D30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_782
	{ "roi_avg_r_data_782", 0x00000D34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_782", 0x00000D34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_783
	{ "roi_avg_r_data_783", 0x00000D38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_783", 0x00000D38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_784
	{ "roi_avg_r_data_784", 0x00000D3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_784", 0x00000D3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_785
	{ "roi_avg_r_data_785", 0x00000D40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_785", 0x00000D40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_786
	{ "roi_avg_r_data_786", 0x00000D44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_786", 0x00000D44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_787
	{ "roi_avg_r_data_787", 0x00000D48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_787", 0x00000D48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_788
	{ "roi_avg_r_data_788", 0x00000D4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_788", 0x00000D4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_789
	{ "roi_avg_r_data_789", 0x00000D50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_789", 0x00000D50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_790
	{ "roi_avg_r_data_790", 0x00000D54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_790", 0x00000D54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_791
	{ "roi_avg_r_data_791", 0x00000D58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_791", 0x00000D58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_792
	{ "roi_avg_r_data_792", 0x00000D5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_792", 0x00000D5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_793
	{ "roi_avg_r_data_793", 0x00000D60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_793", 0x00000D60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_794
	{ "roi_avg_r_data_794", 0x00000D64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_794", 0x00000D64, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_795
	{ "roi_avg_r_data_795", 0x00000D68, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_795", 0x00000D68, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_796
	{ "roi_avg_r_data_796", 0x00000D6C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_796", 0x00000D6C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_797
	{ "roi_avg_r_data_797", 0x00000D70, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_797", 0x00000D70, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_798
	{ "roi_avg_r_data_798", 0x00000D74, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_798", 0x00000D74, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_799
	{ "roi_avg_r_data_799", 0x00000D78, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_799", 0x00000D78, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_800
	{ "roi_avg_r_data_800", 0x00000D7C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_800", 0x00000D7C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_801
	{ "roi_avg_r_data_801", 0x00000D80, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_801", 0x00000D80, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_802
	{ "roi_avg_r_data_802", 0x00000D84, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_802", 0x00000D84, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_803
	{ "roi_avg_r_data_803", 0x00000D88, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_803", 0x00000D88, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_804
	{ "roi_avg_r_data_804", 0x00000D8C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_804", 0x00000D8C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_805
	{ "roi_avg_r_data_805", 0x00000D90, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_805", 0x00000D90, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_806
	{ "roi_avg_r_data_806", 0x00000D94, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_806", 0x00000D94, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_807
	{ "roi_avg_r_data_807", 0x00000D98, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_807", 0x00000D98, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_808
	{ "roi_avg_r_data_808", 0x00000D9C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_808", 0x00000D9C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_809
	{ "roi_avg_r_data_809", 0x00000DA0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_809", 0x00000DA0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_810
	{ "roi_avg_r_data_810", 0x00000DA4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_810", 0x00000DA4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_811
	{ "roi_avg_r_data_811", 0x00000DA8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_811", 0x00000DA8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_812
	{ "roi_avg_r_data_812", 0x00000DAC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_812", 0x00000DAC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_813
	{ "roi_avg_r_data_813", 0x00000DB0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_813", 0x00000DB0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_814
	{ "roi_avg_r_data_814", 0x00000DB4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_814", 0x00000DB4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_815
	{ "roi_avg_r_data_815", 0x00000DB8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_815", 0x00000DB8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_816
	{ "roi_avg_r_data_816", 0x00000DBC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_816", 0x00000DBC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_817
	{ "roi_avg_r_data_817", 0x00000DC0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_817", 0x00000DC0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_818
	{ "roi_avg_r_data_818", 0x00000DC4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_818", 0x00000DC4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_819
	{ "roi_avg_r_data_819", 0x00000DC8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_819", 0x00000DC8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_820
	{ "roi_avg_r_data_820", 0x00000DCC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_820", 0x00000DCC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_821
	{ "roi_avg_r_data_821", 0x00000DD0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_821", 0x00000DD0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_822
	{ "roi_avg_r_data_822", 0x00000DD4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_822", 0x00000DD4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_823
	{ "roi_avg_r_data_823", 0x00000DD8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_823", 0x00000DD8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_824
	{ "roi_avg_r_data_824", 0x00000DDC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_824", 0x00000DDC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_825
	{ "roi_avg_r_data_825", 0x00000DE0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_825", 0x00000DE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_826
	{ "roi_avg_r_data_826", 0x00000DE4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_826", 0x00000DE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_827
	{ "roi_avg_r_data_827", 0x00000DE8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_827", 0x00000DE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_828
	{ "roi_avg_r_data_828", 0x00000DEC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_828", 0x00000DEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_829
	{ "roi_avg_r_data_829", 0x00000DF0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_829", 0x00000DF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_830
	{ "roi_avg_r_data_830", 0x00000DF4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_830", 0x00000DF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_831
	{ "roi_avg_r_data_831", 0x00000DF8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_831", 0x00000DF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_832
	{ "roi_avg_r_data_832", 0x00000DFC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_832", 0x00000DFC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_833
	{ "roi_avg_r_data_833", 0x00000E00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_833", 0x00000E00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_834
	{ "roi_avg_r_data_834", 0x00000E04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_834", 0x00000E04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_835
	{ "roi_avg_r_data_835", 0x00000E08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_835", 0x00000E08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_836
	{ "roi_avg_r_data_836", 0x00000E0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_836", 0x00000E0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_837
	{ "roi_avg_r_data_837", 0x00000E10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_837", 0x00000E10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_838
	{ "roi_avg_r_data_838", 0x00000E14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_838", 0x00000E14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_839
	{ "roi_avg_r_data_839", 0x00000E18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_839", 0x00000E18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_840
	{ "roi_avg_r_data_840", 0x00000E1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_840", 0x00000E1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_841
	{ "roi_avg_r_data_841", 0x00000E20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_841", 0x00000E20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_842
	{ "roi_avg_r_data_842", 0x00000E24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_842", 0x00000E24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_843
	{ "roi_avg_r_data_843", 0x00000E28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_843", 0x00000E28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_844
	{ "roi_avg_r_data_844", 0x00000E2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_844", 0x00000E2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_845
	{ "roi_avg_r_data_845", 0x00000E30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_845", 0x00000E30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_846
	{ "roi_avg_r_data_846", 0x00000E34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_846", 0x00000E34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_847
	{ "roi_avg_r_data_847", 0x00000E38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_847", 0x00000E38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_848
	{ "roi_avg_r_data_848", 0x00000E3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_848", 0x00000E3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_849
	{ "roi_avg_r_data_849", 0x00000E40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_849", 0x00000E40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_850
	{ "roi_avg_r_data_850", 0x00000E44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_850", 0x00000E44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_851
	{ "roi_avg_r_data_851", 0x00000E48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_851", 0x00000E48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_852
	{ "roi_avg_r_data_852", 0x00000E4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_852", 0x00000E4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_853
	{ "roi_avg_r_data_853", 0x00000E50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_853", 0x00000E50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_854
	{ "roi_avg_r_data_854", 0x00000E54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_854", 0x00000E54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_855
	{ "roi_avg_r_data_855", 0x00000E58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_855", 0x00000E58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_856
	{ "roi_avg_r_data_856", 0x00000E5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_856", 0x00000E5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_857
	{ "roi_avg_r_data_857", 0x00000E60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_857", 0x00000E60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_858
	{ "roi_avg_r_data_858", 0x00000E64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_858", 0x00000E64, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_859
	{ "roi_avg_r_data_859", 0x00000E68, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_859", 0x00000E68, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_860
	{ "roi_avg_r_data_860", 0x00000E6C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_860", 0x00000E6C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_861
	{ "roi_avg_r_data_861", 0x00000E70, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_861", 0x00000E70, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_862
	{ "roi_avg_r_data_862", 0x00000E74, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_862", 0x00000E74, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_863
	{ "roi_avg_r_data_863", 0x00000E78, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_863", 0x00000E78, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_864
	{ "roi_avg_r_data_864", 0x00000E7C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_864", 0x00000E7C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_865
	{ "roi_avg_r_data_865", 0x00000E80, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_865", 0x00000E80, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_866
	{ "roi_avg_r_data_866", 0x00000E84, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_866", 0x00000E84, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_867
	{ "roi_avg_r_data_867", 0x00000E88, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_867", 0x00000E88, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_868
	{ "roi_avg_r_data_868", 0x00000E8C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_868", 0x00000E8C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_869
	{ "roi_avg_r_data_869", 0x00000E90, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_869", 0x00000E90, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_870
	{ "roi_avg_r_data_870", 0x00000E94, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_870", 0x00000E94, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_871
	{ "roi_avg_r_data_871", 0x00000E98, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_871", 0x00000E98, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_872
	{ "roi_avg_r_data_872", 0x00000E9C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_872", 0x00000E9C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_873
	{ "roi_avg_r_data_873", 0x00000EA0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_873", 0x00000EA0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_874
	{ "roi_avg_r_data_874", 0x00000EA4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_874", 0x00000EA4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_875
	{ "roi_avg_r_data_875", 0x00000EA8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_875", 0x00000EA8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_876
	{ "roi_avg_r_data_876", 0x00000EAC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_876", 0x00000EAC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_877
	{ "roi_avg_r_data_877", 0x00000EB0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_877", 0x00000EB0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_878
	{ "roi_avg_r_data_878", 0x00000EB4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_878", 0x00000EB4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_879
	{ "roi_avg_r_data_879", 0x00000EB8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_879", 0x00000EB8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_880
	{ "roi_avg_r_data_880", 0x00000EBC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_880", 0x00000EBC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_881
	{ "roi_avg_r_data_881", 0x00000EC0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_881", 0x00000EC0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_882
	{ "roi_avg_r_data_882", 0x00000EC4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_882", 0x00000EC4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_883
	{ "roi_avg_r_data_883", 0x00000EC8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_883", 0x00000EC8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_884
	{ "roi_avg_r_data_884", 0x00000ECC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_884", 0x00000ECC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_885
	{ "roi_avg_r_data_885", 0x00000ED0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_885", 0x00000ED0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_886
	{ "roi_avg_r_data_886", 0x00000ED4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_886", 0x00000ED4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_887
	{ "roi_avg_r_data_887", 0x00000ED8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_887", 0x00000ED8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_888
	{ "roi_avg_r_data_888", 0x00000EDC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_888", 0x00000EDC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_889
	{ "roi_avg_r_data_889", 0x00000EE0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_889", 0x00000EE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_890
	{ "roi_avg_r_data_890", 0x00000EE4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_890", 0x00000EE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_891
	{ "roi_avg_r_data_891", 0x00000EE8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_891", 0x00000EE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_892
	{ "roi_avg_r_data_892", 0x00000EEC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_892", 0x00000EEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_893
	{ "roi_avg_r_data_893", 0x00000EF0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_893", 0x00000EF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_894
	{ "roi_avg_r_data_894", 0x00000EF4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_894", 0x00000EF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_895
	{ "roi_avg_r_data_895", 0x00000EF8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_895", 0x00000EF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_896
	{ "roi_avg_r_data_896", 0x00000EFC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_896", 0x00000EFC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_897
	{ "roi_avg_r_data_897", 0x00000F00, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_897", 0x00000F00, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_898
	{ "roi_avg_r_data_898", 0x00000F04, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_898", 0x00000F04, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_899
	{ "roi_avg_r_data_899", 0x00000F08, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_899", 0x00000F08, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_900
	{ "roi_avg_r_data_900", 0x00000F0C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_900", 0x00000F0C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_901
	{ "roi_avg_r_data_901", 0x00000F10, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_901", 0x00000F10, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_902
	{ "roi_avg_r_data_902", 0x00000F14, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_902", 0x00000F14, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_903
	{ "roi_avg_r_data_903", 0x00000F18, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_903", 0x00000F18, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_904
	{ "roi_avg_r_data_904", 0x00000F1C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_904", 0x00000F1C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_905
	{ "roi_avg_r_data_905", 0x00000F20, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_905", 0x00000F20, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_906
	{ "roi_avg_r_data_906", 0x00000F24, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_906", 0x00000F24, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_907
	{ "roi_avg_r_data_907", 0x00000F28, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_907", 0x00000F28, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_908
	{ "roi_avg_r_data_908", 0x00000F2C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_908", 0x00000F2C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_909
	{ "roi_avg_r_data_909", 0x00000F30, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_909", 0x00000F30, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_910
	{ "roi_avg_r_data_910", 0x00000F34, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_910", 0x00000F34, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_911
	{ "roi_avg_r_data_911", 0x00000F38, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_911", 0x00000F38, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_912
	{ "roi_avg_r_data_912", 0x00000F3C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_912", 0x00000F3C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_913
	{ "roi_avg_r_data_913", 0x00000F40, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_913", 0x00000F40, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_914
	{ "roi_avg_r_data_914", 0x00000F44, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_914", 0x00000F44, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_915
	{ "roi_avg_r_data_915", 0x00000F48, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_915", 0x00000F48, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_916
	{ "roi_avg_r_data_916", 0x00000F4C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_916", 0x00000F4C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_917
	{ "roi_avg_r_data_917", 0x00000F50, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_917", 0x00000F50, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_918
	{ "roi_avg_r_data_918", 0x00000F54, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_918", 0x00000F54, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_919
	{ "roi_avg_r_data_919", 0x00000F58, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_919", 0x00000F58, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_920
	{ "roi_avg_r_data_920", 0x00000F5C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_920", 0x00000F5C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_921
	{ "roi_avg_r_data_921", 0x00000F60, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_921", 0x00000F60, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_922
	{ "roi_avg_r_data_922", 0x00000F64, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_922", 0x00000F64, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_923
	{ "roi_avg_r_data_923", 0x00000F68, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_923", 0x00000F68, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_924
	{ "roi_avg_r_data_924", 0x00000F6C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_924", 0x00000F6C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_925
	{ "roi_avg_r_data_925", 0x00000F70, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_925", 0x00000F70, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_926
	{ "roi_avg_r_data_926", 0x00000F74, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_926", 0x00000F74, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_927
	{ "roi_avg_r_data_927", 0x00000F78, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_927", 0x00000F78, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_928
	{ "roi_avg_r_data_928", 0x00000F7C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_928", 0x00000F7C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_929
	{ "roi_avg_r_data_929", 0x00000F80, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_929", 0x00000F80, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_930
	{ "roi_avg_r_data_930", 0x00000F84, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_930", 0x00000F84, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_931
	{ "roi_avg_r_data_931", 0x00000F88, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_931", 0x00000F88, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_932
	{ "roi_avg_r_data_932", 0x00000F8C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_932", 0x00000F8C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_933
	{ "roi_avg_r_data_933", 0x00000F90, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_933", 0x00000F90, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_934
	{ "roi_avg_r_data_934", 0x00000F94, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_934", 0x00000F94, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_935
	{ "roi_avg_r_data_935", 0x00000F98, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_935", 0x00000F98, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_936
	{ "roi_avg_r_data_936", 0x00000F9C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_936", 0x00000F9C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_937
	{ "roi_avg_r_data_937", 0x00000FA0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_937", 0x00000FA0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_938
	{ "roi_avg_r_data_938", 0x00000FA4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_938", 0x00000FA4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_939
	{ "roi_avg_r_data_939", 0x00000FA8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_939", 0x00000FA8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_940
	{ "roi_avg_r_data_940", 0x00000FAC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_940", 0x00000FAC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_941
	{ "roi_avg_r_data_941", 0x00000FB0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_941", 0x00000FB0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_942
	{ "roi_avg_r_data_942", 0x00000FB4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_942", 0x00000FB4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_943
	{ "roi_avg_r_data_943", 0x00000FB8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_943", 0x00000FB8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_944
	{ "roi_avg_r_data_944", 0x00000FBC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_944", 0x00000FBC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_945
	{ "roi_avg_r_data_945", 0x00000FC0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_945", 0x00000FC0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_946
	{ "roi_avg_r_data_946", 0x00000FC4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_946", 0x00000FC4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_947
	{ "roi_avg_r_data_947", 0x00000FC8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_947", 0x00000FC8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_948
	{ "roi_avg_r_data_948", 0x00000FCC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_948", 0x00000FCC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_949
	{ "roi_avg_r_data_949", 0x00000FD0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_949", 0x00000FD0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_950
	{ "roi_avg_r_data_950", 0x00000FD4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_950", 0x00000FD4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_951
	{ "roi_avg_r_data_951", 0x00000FD8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_951", 0x00000FD8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_952
	{ "roi_avg_r_data_952", 0x00000FDC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_952", 0x00000FDC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_953
	{ "roi_avg_r_data_953", 0x00000FE0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_953", 0x00000FE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_954
	{ "roi_avg_r_data_954", 0x00000FE4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_954", 0x00000FE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_955
	{ "roi_avg_r_data_955", 0x00000FE8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_955", 0x00000FE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_956
	{ "roi_avg_r_data_956", 0x00000FEC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_956", 0x00000FEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_957
	{ "roi_avg_r_data_957", 0x00000FF0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_957", 0x00000FF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_958
	{ "roi_avg_r_data_958", 0x00000FF4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_958", 0x00000FF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_959
	{ "roi_avg_r_data_959", 0x00000FF8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_959", 0x00000FF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_960
	{ "roi_avg_r_data_960", 0x00000FFC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_960", 0x00000FFC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_961
	{ "roi_avg_r_data_961", 0x00001000, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_961", 0x00001000, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_962
	{ "roi_avg_r_data_962", 0x00001004, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_962", 0x00001004, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_963
	{ "roi_avg_r_data_963", 0x00001008, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_963", 0x00001008, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_964
	{ "roi_avg_r_data_964", 0x0000100C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_964", 0x0000100C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_965
	{ "roi_avg_r_data_965", 0x00001010, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_965", 0x00001010, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_966
	{ "roi_avg_r_data_966", 0x00001014, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_966", 0x00001014, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_967
	{ "roi_avg_r_data_967", 0x00001018, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_967", 0x00001018, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_968
	{ "roi_avg_r_data_968", 0x0000101C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_968", 0x0000101C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_969
	{ "roi_avg_r_data_969", 0x00001020, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_969", 0x00001020, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_970
	{ "roi_avg_r_data_970", 0x00001024, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_970", 0x00001024, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_971
	{ "roi_avg_r_data_971", 0x00001028, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_971", 0x00001028, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_972
	{ "roi_avg_r_data_972", 0x0000102C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_972", 0x0000102C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_973
	{ "roi_avg_r_data_973", 0x00001030, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_973", 0x00001030, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_974
	{ "roi_avg_r_data_974", 0x00001034, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_974", 0x00001034, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_975
	{ "roi_avg_r_data_975", 0x00001038, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_975", 0x00001038, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_976
	{ "roi_avg_r_data_976", 0x0000103C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_976", 0x0000103C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_977
	{ "roi_avg_r_data_977", 0x00001040, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_977", 0x00001040, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_978
	{ "roi_avg_r_data_978", 0x00001044, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_978", 0x00001044, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_979
	{ "roi_avg_r_data_979", 0x00001048, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_979", 0x00001048, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_980
	{ "roi_avg_r_data_980", 0x0000104C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_980", 0x0000104C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_981
	{ "roi_avg_r_data_981", 0x00001050, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_981", 0x00001050, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_982
	{ "roi_avg_r_data_982", 0x00001054, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_982", 0x00001054, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_983
	{ "roi_avg_r_data_983", 0x00001058, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_983", 0x00001058, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_984
	{ "roi_avg_r_data_984", 0x0000105C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_984", 0x0000105C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_985
	{ "roi_avg_r_data_985", 0x00001060, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_985", 0x00001060, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_986
	{ "roi_avg_r_data_986", 0x00001064, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_986", 0x00001064, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_987
	{ "roi_avg_r_data_987", 0x00001068, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_987", 0x00001068, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_988
	{ "roi_avg_r_data_988", 0x0000106C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_988", 0x0000106C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_989
	{ "roi_avg_r_data_989", 0x00001070, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_989", 0x00001070, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_990
	{ "roi_avg_r_data_990", 0x00001074, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_990", 0x00001074, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_991
	{ "roi_avg_r_data_991", 0x00001078, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_991", 0x00001078, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_992
	{ "roi_avg_r_data_992", 0x0000107C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_992", 0x0000107C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_993
	{ "roi_avg_r_data_993", 0x00001080, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_993", 0x00001080, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_994
	{ "roi_avg_r_data_994", 0x00001084, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_994", 0x00001084, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_995
	{ "roi_avg_r_data_995", 0x00001088, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_995", 0x00001088, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_996
	{ "roi_avg_r_data_996", 0x0000108C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_996", 0x0000108C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_997
	{ "roi_avg_r_data_997", 0x00001090, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_997", 0x00001090, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_998
	{ "roi_avg_r_data_998", 0x00001094, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_998", 0x00001094, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_999
	{ "roi_avg_r_data_999", 0x00001098, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_999", 0x00001098, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1000
	{ "roi_avg_r_data_1000", 0x0000109C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1000", 0x0000109C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1001
	{ "roi_avg_r_data_1001", 0x000010A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1001", 0x000010A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1002
	{ "roi_avg_r_data_1002", 0x000010A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1002", 0x000010A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1003
	{ "roi_avg_r_data_1003", 0x000010A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1003", 0x000010A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1004
	{ "roi_avg_r_data_1004", 0x000010AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1004", 0x000010AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1005
	{ "roi_avg_r_data_1005", 0x000010B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1005", 0x000010B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1006
	{ "roi_avg_r_data_1006", 0x000010B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1006", 0x000010B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1007
	{ "roi_avg_r_data_1007", 0x000010B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1007", 0x000010B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1008
	{ "roi_avg_r_data_1008", 0x000010BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1008", 0x000010BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1009
	{ "roi_avg_r_data_1009", 0x000010C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1009", 0x000010C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1010
	{ "roi_avg_r_data_1010", 0x000010C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1010", 0x000010C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1011
	{ "roi_avg_r_data_1011", 0x000010C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1011", 0x000010C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1012
	{ "roi_avg_r_data_1012", 0x000010CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1012", 0x000010CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1013
	{ "roi_avg_r_data_1013", 0x000010D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1013", 0x000010D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1014
	{ "roi_avg_r_data_1014", 0x000010D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1014", 0x000010D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1015
	{ "roi_avg_r_data_1015", 0x000010D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1015", 0x000010D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1016
	{ "roi_avg_r_data_1016", 0x000010DC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1016", 0x000010DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1017
	{ "roi_avg_r_data_1017", 0x000010E0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1017", 0x000010E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1018
	{ "roi_avg_r_data_1018", 0x000010E4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1018", 0x000010E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1019
	{ "roi_avg_r_data_1019", 0x000010E8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1019", 0x000010E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1020
	{ "roi_avg_r_data_1020", 0x000010EC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1020", 0x000010EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1021
	{ "roi_avg_r_data_1021", 0x000010F0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1021", 0x000010F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1022
	{ "roi_avg_r_data_1022", 0x000010F4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1022", 0x000010F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1023
	{ "roi_avg_r_data_1023", 0x000010F8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1023", 0x000010F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1024
	{ "roi_avg_r_data_1024", 0x000010FC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1024", 0x000010FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1025
	{ "roi_avg_r_data_1025", 0x00001100, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1025", 0x00001100, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1026
	{ "roi_avg_r_data_1026", 0x00001104, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1026", 0x00001104, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1027
	{ "roi_avg_r_data_1027", 0x00001108, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1027", 0x00001108, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1028
	{ "roi_avg_r_data_1028", 0x0000110C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1028", 0x0000110C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1029
	{ "roi_avg_r_data_1029", 0x00001110, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1029", 0x00001110, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1030
	{ "roi_avg_r_data_1030", 0x00001114, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1030", 0x00001114, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1031
	{ "roi_avg_r_data_1031", 0x00001118, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1031", 0x00001118, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1032
	{ "roi_avg_r_data_1032", 0x0000111C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1032", 0x0000111C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1033
	{ "roi_avg_r_data_1033", 0x00001120, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1033", 0x00001120, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1034
	{ "roi_avg_r_data_1034", 0x00001124, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1034", 0x00001124, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1035
	{ "roi_avg_r_data_1035", 0x00001128, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1035", 0x00001128, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1036
	{ "roi_avg_r_data_1036", 0x0000112C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1036", 0x0000112C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1037
	{ "roi_avg_r_data_1037", 0x00001130, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1037", 0x00001130, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1038
	{ "roi_avg_r_data_1038", 0x00001134, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1038", 0x00001134, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1039
	{ "roi_avg_r_data_1039", 0x00001138, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1039", 0x00001138, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1040
	{ "roi_avg_r_data_1040", 0x0000113C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1040", 0x0000113C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1041
	{ "roi_avg_r_data_1041", 0x00001140, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1041", 0x00001140, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1042
	{ "roi_avg_r_data_1042", 0x00001144, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1042", 0x00001144, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1043
	{ "roi_avg_r_data_1043", 0x00001148, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1043", 0x00001148, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1044
	{ "roi_avg_r_data_1044", 0x0000114C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1044", 0x0000114C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1045
	{ "roi_avg_r_data_1045", 0x00001150, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1045", 0x00001150, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1046
	{ "roi_avg_r_data_1046", 0x00001154, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1046", 0x00001154, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1047
	{ "roi_avg_r_data_1047", 0x00001158, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1047", 0x00001158, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1048
	{ "roi_avg_r_data_1048", 0x0000115C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1048", 0x0000115C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1049
	{ "roi_avg_r_data_1049", 0x00001160, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1049", 0x00001160, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1050
	{ "roi_avg_r_data_1050", 0x00001164, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1050", 0x00001164, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1051
	{ "roi_avg_r_data_1051", 0x00001168, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1051", 0x00001168, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1052
	{ "roi_avg_r_data_1052", 0x0000116C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1052", 0x0000116C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1053
	{ "roi_avg_r_data_1053", 0x00001170, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1053", 0x00001170, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1054
	{ "roi_avg_r_data_1054", 0x00001174, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1054", 0x00001174, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1055
	{ "roi_avg_r_data_1055", 0x00001178, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1055", 0x00001178, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1056
	{ "roi_avg_r_data_1056", 0x0000117C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1056", 0x0000117C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1057
	{ "roi_avg_r_data_1057", 0x00001180, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1057", 0x00001180, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1058
	{ "roi_avg_r_data_1058", 0x00001184, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1058", 0x00001184, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1059
	{ "roi_avg_r_data_1059", 0x00001188, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1059", 0x00001188, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1060
	{ "roi_avg_r_data_1060", 0x0000118C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1060", 0x0000118C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1061
	{ "roi_avg_r_data_1061", 0x00001190, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1061", 0x00001190, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1062
	{ "roi_avg_r_data_1062", 0x00001194, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1062", 0x00001194, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1063
	{ "roi_avg_r_data_1063", 0x00001198, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1063", 0x00001198, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1064
	{ "roi_avg_r_data_1064", 0x0000119C, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1064", 0x0000119C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1065
	{ "roi_avg_r_data_1065", 0x000011A0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1065", 0x000011A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1066
	{ "roi_avg_r_data_1066", 0x000011A4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1066", 0x000011A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1067
	{ "roi_avg_r_data_1067", 0x000011A8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1067", 0x000011A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1068
	{ "roi_avg_r_data_1068", 0x000011AC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1068", 0x000011AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1069
	{ "roi_avg_r_data_1069", 0x000011B0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1069", 0x000011B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1070
	{ "roi_avg_r_data_1070", 0x000011B4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1070", 0x000011B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1071
	{ "roi_avg_r_data_1071", 0x000011B8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1071", 0x000011B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1072
	{ "roi_avg_r_data_1072", 0x000011BC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1072", 0x000011BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1073
	{ "roi_avg_r_data_1073", 0x000011C0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1073", 0x000011C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1074
	{ "roi_avg_r_data_1074", 0x000011C4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1074", 0x000011C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1075
	{ "roi_avg_r_data_1075", 0x000011C8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1075", 0x000011C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1076
	{ "roi_avg_r_data_1076", 0x000011CC, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1076", 0x000011CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1077
	{ "roi_avg_r_data_1077", 0x000011D0, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1077", 0x000011D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1078
	{ "roi_avg_r_data_1078", 0x000011D4, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1078", 0x000011D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_roi_r_data_1079
	{ "roi_avg_r_data_1079", 0x000011D8, 29, 0, CSR_RO, 0x00000000 },
	{ "FPGA_ROI_R_DATA_1079", 0x000011D8, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DFK_H_
