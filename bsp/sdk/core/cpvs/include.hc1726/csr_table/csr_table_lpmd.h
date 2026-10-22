/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_LPMD_H_
#define CSR_TABLE_LPMD_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_lpmd[] = {
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_alarm", 0x00000004, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_pix_cnt_mismatch", 0x00000004, 2, 2, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_frame_alarm", 0x00000008, 1, 1, CSR_RO, 0x00000000 },
	{ "status_pix_cnt_mismatch", 0x00000008, 2, 2, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_frame_alarm", 0x0000000C, 1, 1, CSR_RW, 0x00000001 },
	{ "irq_mask_pix_cnt_mismatch", 0x0000000C, 2, 2, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_frame_cnt_th
	{ "frame_cnt_th", 0x00000014, 7, 0, CSR_RW, 0x00000000 },
	{ "WORD_FRAME_CNT_TH", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD pix_num
	{ "frame_pix_num", 0x00000018, 22, 0, CSR_RW, 0x00012C00 },
	{ "PIX_NUM", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width_i", 0x0000001C, 15, 0, CSR_RW, 0x00000140 },
	{ "height_i", 0x0000001C, 31, 16, CSR_RW, 0x000000F0 },
	{ "RESOLUTION", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_x
	{ "crop_left", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_right", 0x00000020, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_X", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_y
	{ "crop_up", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_down", 0x00000024, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_Y", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD det_resolution
	{ "det_width", 0x00000028, 11, 0, CSR_RW, 0x00000140 },
	{ "det_height", 0x00000028, 26, 16, CSR_RW, 0x000000F0 },
	{ "DET_RESOLUTION", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_config
	{ "region_x_num_m1", 0x0000002C, 3, 0, CSR_RW, 0x0000000F },
	{ "region_pix_num", 0x0000002C, 30, 16, CSR_RW, 0x00000258 },
	{ "RGL_CONFIG", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_resolution
	{ "region_width", 0x00000030, 7, 0, CSR_RW, 0x00000014 },
	{ "region_height", 0x00000030, 22, 16, CSR_RW, 0x0000001E },
	{ "RGL_RESOLUTION", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD iir_weight
	{ "apl_iir_weight", 0x00000034, 4, 0, CSR_RW, 0x00000006 },
	{ "IIR_WEIGHT", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD apl_config
	{ "apl_coring_th", 0x00000038, 5, 0, CSR_RW, 0x00000004 },
	{ "apl_step_shift_bw", 0x00000038, 10, 8, CSR_RW, 0x00000002 },
	{ "apl_alarm_max", 0x00000038, 18, 16, CSR_RW, 0x00000004 },
	{ "APL_CONFIG", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD status_config
	{ "status_dec", 0x0000003C, 3, 0, CSR_RW, 0x00000002 },
	{ "status_max", 0x0000003C, 12, 8, CSR_RW, 0x00000010 },
	{ "status_th_high", 0x0000003C, 20, 16, CSR_RW, 0x0000000C },
	{ "status_th_low", 0x0000003C, 28, 24, CSR_RW, 0x00000008 },
	{ "STATUS_CONFIG", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD frame_alarm_config
	{ "frame_alarm_th", 0x00000040, 9, 0, CSR_RW, 0x00000003 },
	{ "status_th_high_detect", 0x00000040, 20, 16, CSR_RW, 0x0000000C },
	{ "FRAME_ALARM_CONFIG", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_0
	{ "region_weight_0", 0x00000044, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_1", 0x00000044, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_2", 0x00000044, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_3", 0x00000044, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_0", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_1
	{ "region_weight_4", 0x00000048, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_5", 0x00000048, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_6", 0x00000048, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_7", 0x00000048, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_1", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_2
	{ "region_weight_8", 0x0000004C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_9", 0x0000004C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_10", 0x0000004C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_11", 0x0000004C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_2", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_3
	{ "region_weight_12", 0x00000050, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_13", 0x00000050, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_14", 0x00000050, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_15", 0x00000050, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_3", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_4
	{ "region_weight_16", 0x00000054, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_17", 0x00000054, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_18", 0x00000054, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_19", 0x00000054, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_4", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_5
	{ "region_weight_20", 0x00000058, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_21", 0x00000058, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_22", 0x00000058, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_23", 0x00000058, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_5", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_6
	{ "region_weight_24", 0x0000005C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_25", 0x0000005C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_26", 0x0000005C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_27", 0x0000005C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_6", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_7
	{ "region_weight_28", 0x00000060, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_29", 0x00000060, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_30", 0x00000060, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_31", 0x00000060, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_7", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_8
	{ "region_weight_32", 0x00000064, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_33", 0x00000064, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_34", 0x00000064, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_35", 0x00000064, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_8", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_9
	{ "region_weight_36", 0x00000068, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_37", 0x00000068, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_38", 0x00000068, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_39", 0x00000068, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_9", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_10
	{ "region_weight_40", 0x0000006C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_41", 0x0000006C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_42", 0x0000006C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_43", 0x0000006C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_10", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_11
	{ "region_weight_44", 0x00000070, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_45", 0x00000070, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_46", 0x00000070, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_47", 0x00000070, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_11", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_12
	{ "region_weight_48", 0x00000074, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_49", 0x00000074, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_50", 0x00000074, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_51", 0x00000074, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_12", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_13
	{ "region_weight_52", 0x00000078, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_53", 0x00000078, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_54", 0x00000078, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_55", 0x00000078, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_13", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_14
	{ "region_weight_56", 0x0000007C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_57", 0x0000007C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_58", 0x0000007C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_59", 0x0000007C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_14", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_15
	{ "region_weight_60", 0x00000080, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_61", 0x00000080, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_62", 0x00000080, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_63", 0x00000080, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_15", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_16
	{ "region_weight_64", 0x00000084, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_65", 0x00000084, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_66", 0x00000084, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_67", 0x00000084, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_16", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_17
	{ "region_weight_68", 0x00000088, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_69", 0x00000088, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_70", 0x00000088, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_71", 0x00000088, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_17", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_18
	{ "region_weight_72", 0x0000008C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_73", 0x0000008C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_74", 0x0000008C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_75", 0x0000008C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_18", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_19
	{ "region_weight_76", 0x00000090, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_77", 0x00000090, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_78", 0x00000090, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_79", 0x00000090, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_19", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_20
	{ "region_weight_80", 0x00000094, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_81", 0x00000094, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_82", 0x00000094, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_83", 0x00000094, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_20", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_21
	{ "region_weight_84", 0x00000098, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_85", 0x00000098, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_86", 0x00000098, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_87", 0x00000098, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_21", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_22
	{ "region_weight_88", 0x0000009C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_89", 0x0000009C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_90", 0x0000009C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_91", 0x0000009C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_22", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_23
	{ "region_weight_92", 0x000000A0, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_93", 0x000000A0, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_94", 0x000000A0, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_95", 0x000000A0, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_23", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_24
	{ "region_weight_96", 0x000000A4, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_97", 0x000000A4, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_98", 0x000000A4, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_99", 0x000000A4, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_24", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_25
	{ "region_weight_100", 0x000000A8, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_101", 0x000000A8, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_102", 0x000000A8, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_103", 0x000000A8, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_25", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_26
	{ "region_weight_104", 0x000000AC, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_105", 0x000000AC, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_106", 0x000000AC, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_107", 0x000000AC, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_26", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_27
	{ "region_weight_108", 0x000000B0, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_109", 0x000000B0, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_110", 0x000000B0, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_111", 0x000000B0, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_27", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_28
	{ "region_weight_112", 0x000000B4, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_113", 0x000000B4, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_114", 0x000000B4, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_115", 0x000000B4, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_28", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_29
	{ "region_weight_116", 0x000000B8, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_117", 0x000000B8, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_118", 0x000000B8, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_119", 0x000000B8, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_29", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_30
	{ "region_weight_120", 0x000000BC, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_121", 0x000000BC, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_122", 0x000000BC, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_123", 0x000000BC, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_30", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_31
	{ "region_weight_124", 0x000000C0, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_125", 0x000000C0, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_126", 0x000000C0, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_127", 0x000000C0, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_31", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_32
	{ "region_weight_128", 0x000000C4, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_129", 0x000000C4, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_130", 0x000000C4, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_131", 0x000000C4, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_32", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_33
	{ "region_weight_132", 0x000000C8, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_133", 0x000000C8, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_134", 0x000000C8, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_135", 0x000000C8, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_33", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_34
	{ "region_weight_136", 0x000000CC, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_137", 0x000000CC, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_138", 0x000000CC, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_139", 0x000000CC, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_34", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_35
	{ "region_weight_140", 0x000000D0, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_141", 0x000000D0, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_142", 0x000000D0, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_143", 0x000000D0, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_35", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_36
	{ "region_weight_144", 0x000000D4, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_145", 0x000000D4, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_146", 0x000000D4, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_147", 0x000000D4, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_36", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_37
	{ "region_weight_148", 0x000000D8, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_149", 0x000000D8, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_150", 0x000000D8, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_151", 0x000000D8, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_37", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_38
	{ "region_weight_152", 0x000000DC, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_153", 0x000000DC, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_154", 0x000000DC, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_155", 0x000000DC, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_38", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_39
	{ "region_weight_156", 0x000000E0, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_157", 0x000000E0, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_158", 0x000000E0, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_159", 0x000000E0, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_39", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_40
	{ "region_weight_160", 0x000000E4, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_161", 0x000000E4, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_162", 0x000000E4, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_163", 0x000000E4, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_40", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_41
	{ "region_weight_164", 0x000000E8, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_165", 0x000000E8, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_166", 0x000000E8, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_167", 0x000000E8, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_41", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_42
	{ "region_weight_168", 0x000000EC, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_169", 0x000000EC, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_170", 0x000000EC, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_171", 0x000000EC, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_42", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_43
	{ "region_weight_172", 0x000000F0, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_173", 0x000000F0, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_174", 0x000000F0, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_175", 0x000000F0, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_43", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_44
	{ "region_weight_176", 0x000000F4, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_177", 0x000000F4, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_178", 0x000000F4, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_179", 0x000000F4, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_44", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_45
	{ "region_weight_180", 0x000000F8, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_181", 0x000000F8, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_182", 0x000000F8, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_183", 0x000000F8, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_45", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_46
	{ "region_weight_184", 0x000000FC, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_185", 0x000000FC, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_186", 0x000000FC, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_187", 0x000000FC, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_46", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_47
	{ "region_weight_188", 0x00000100, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_189", 0x00000100, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_190", 0x00000100, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_191", 0x00000100, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_47", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_48
	{ "region_weight_192", 0x00000104, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_193", 0x00000104, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_194", 0x00000104, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_195", 0x00000104, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_48", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_49
	{ "region_weight_196", 0x00000108, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_197", 0x00000108, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_198", 0x00000108, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_199", 0x00000108, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_49", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_50
	{ "region_weight_200", 0x0000010C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_201", 0x0000010C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_202", 0x0000010C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_203", 0x0000010C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_50", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_51
	{ "region_weight_204", 0x00000110, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_205", 0x00000110, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_206", 0x00000110, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_207", 0x00000110, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_51", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_52
	{ "region_weight_208", 0x00000114, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_209", 0x00000114, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_210", 0x00000114, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_211", 0x00000114, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_52", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_53
	{ "region_weight_212", 0x00000118, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_213", 0x00000118, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_214", 0x00000118, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_215", 0x00000118, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_53", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_54
	{ "region_weight_216", 0x0000011C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_217", 0x0000011C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_218", 0x0000011C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_219", 0x0000011C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_54", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_55
	{ "region_weight_220", 0x00000120, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_221", 0x00000120, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_222", 0x00000120, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_223", 0x00000120, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_55", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_56
	{ "region_weight_224", 0x00000124, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_225", 0x00000124, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_226", 0x00000124, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_227", 0x00000124, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_56", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_57
	{ "region_weight_228", 0x00000128, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_229", 0x00000128, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_230", 0x00000128, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_231", 0x00000128, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_57", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_58
	{ "region_weight_232", 0x0000012C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_233", 0x0000012C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_234", 0x0000012C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_235", 0x0000012C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_58", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_59
	{ "region_weight_236", 0x00000130, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_237", 0x00000130, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_238", 0x00000130, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_239", 0x00000130, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_59", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_60
	{ "region_weight_240", 0x00000134, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_241", 0x00000134, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_242", 0x00000134, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_243", 0x00000134, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_60", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_61
	{ "region_weight_244", 0x00000138, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_245", 0x00000138, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_246", 0x00000138, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_247", 0x00000138, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_61", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_62
	{ "region_weight_248", 0x0000013C, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_249", 0x0000013C, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_250", 0x0000013C, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_251", 0x0000013C, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_62", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_weight_set_63
	{ "region_weight_252", 0x00000140, 1, 0, CSR_RW, 0x00000001 },
	{ "region_weight_253", 0x00000140, 9, 8, CSR_RW, 0x00000001 },
	{ "region_weight_254", 0x00000140, 17, 16, CSR_RW, 0x00000001 },
	{ "region_weight_255", 0x00000140, 25, 24, CSR_RW, 0x00000001 },
	{ "REGION_WEIGHT_SET_63", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000144, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_0
	{ "reserved_0", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_0", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_LPMD_H_
