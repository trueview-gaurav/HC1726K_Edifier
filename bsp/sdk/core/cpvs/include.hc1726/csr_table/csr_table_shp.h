/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SHP_H_
#define CSR_TABLE_SHP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_shp[] = {
	// WORD shp_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "SHP_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_mode
	{ "mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "ink_num", 0x00000010, 12, 8, CSR_RW, 0x00000000 },
	{ "SHP_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000014, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000014, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_level_gain
	{ "level_gain", 0x00000018, 8, 0, CSR_RW, 0x00000010 },
	{ "SHP_LEVEL_GAIN", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_0_set
	{ "level_gain_roi_0_en", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi_0", 0x0000001C, 24, 16, CSR_RW, 0x00000010 },
	{ "LEVEL_GAIN_ROI_0_SET", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_0_sxsy
	{ "level_gain_roi0_sx", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi0_sy", 0x00000020, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_0_SXSY", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_0_exey
	{ "level_gain_roi0_ex", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi0_ey", 0x00000024, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_0_EXEY", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_1_set
	{ "level_gain_roi_1_en", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi_1", 0x00000028, 24, 16, CSR_RW, 0x00000010 },
	{ "LEVEL_GAIN_ROI_1_SET", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_1_sxsy
	{ "level_gain_roi1_sx", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi1_sy", 0x0000002C, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_1_SXSY", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_1_exey
	{ "level_gain_roi1_ex", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi1_ey", 0x00000030, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_1_EXEY", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_2_set
	{ "level_gain_roi_2_en", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi_2", 0x00000034, 24, 16, CSR_RW, 0x00000010 },
	{ "LEVEL_GAIN_ROI_2_SET", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_2_sxsy
	{ "level_gain_roi2_sx", 0x00000038, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi2_sy", 0x00000038, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_2_SXSY", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_2_exey
	{ "level_gain_roi2_ex", 0x0000003C, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi2_ey", 0x0000003C, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_2_EXEY", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_3_set
	{ "level_gain_roi_3_en", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi_3", 0x00000040, 24, 16, CSR_RW, 0x00000010 },
	{ "LEVEL_GAIN_ROI_3_SET", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_3_sxsy
	{ "level_gain_roi3_sx", 0x00000044, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi3_sy", 0x00000044, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_3_SXSY", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_gain_roi_3_exey
	{ "level_gain_roi3_ex", 0x00000048, 15, 0, CSR_RW, 0x00000000 },
	{ "level_gain_roi3_ey", 0x00000048, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_GAIN_ROI_3_EXEY", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD ring_control
	{ "ring_control_en", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "RING_CONTROL", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD boundary
	{ "minmax_outer_bound", 0x00000050, 2, 0, CSR_RW, 0x00000000 },
	{ "minmax_central_bound", 0x00000050, 10, 8, CSR_RW, 0x00000000 },
	{ "var_central_bound", 0x00000050, 18, 16, CSR_RW, 0x00000000 },
	{ "var_edge_bound", 0x00000050, 26, 24, CSR_RW, 0x00000000 },
	{ "BOUNDARY", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD variance_norm_0
	{ "var_central_norm", 0x00000054, 17, 0, CSR_RW, 0x00000000 },
	{ "VARIANCE_NORM_0", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD variance_norm_1
	{ "var_edge_norm", 0x00000058, 17, 0, CSR_RW, 0x00000000 },
	{ "VARIANCE_NORM_1", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_1
	{ "hpf_hpf_gain", 0x0000005C, 7, 0, CSR_RW, 0x00000010 },
	{ "hpf_bpf_gain", 0x0000005C, 15, 8, CSR_RW, 0x00000010 },
	{ "hpf_lpf_gain", 0x0000005C, 23, 16, CSR_RW, 0x00000010 },
	{ "GAIN_1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_2
	{ "bpf_bpf_gain", 0x00000060, 7, 0, CSR_RW, 0x00000010 },
	{ "bpf_lpf_gain", 0x00000060, 15, 8, CSR_RW, 0x00000010 },
	{ "GAIN_2", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_ini
	{ "high_band_gain_curve_y_ini", 0x00000064, 9, 0, CSR_RW, 0x00000000 },
	{ "middle_band_gain_curve_y_ini", 0x00000064, 25, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_INI", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_0
	{ "high_band_gain_curve_x_0", 0x00000068, 9, 0, CSR_RW, 0x00000005 },
	{ "high_band_gain_curve_y_0", 0x00000068, 25, 16, CSR_RW, 0x00000001 },
	{ "GAIN_CURVE_0", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_1
	{ "high_band_gain_curve_x_1", 0x0000006C, 9, 0, CSR_RW, 0x00000023 },
	{ "high_band_gain_curve_y_1", 0x0000006C, 25, 16, CSR_RW, 0x00000010 },
	{ "GAIN_CURVE_1", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_2
	{ "high_band_gain_curve_x_2", 0x00000070, 9, 0, CSR_RW, 0x00000069 },
	{ "high_band_gain_curve_y_2", 0x00000070, 25, 16, CSR_RW, 0x0000003C },
	{ "GAIN_CURVE_2", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_3
	{ "high_band_gain_curve_x_3", 0x00000074, 9, 0, CSR_RW, 0x00000087 },
	{ "high_band_gain_curve_y_3", 0x00000074, 25, 16, CSR_RW, 0x00000040 },
	{ "GAIN_CURVE_3", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_4
	{ "high_band_gain_curve_x_4", 0x00000078, 9, 0, CSR_RW, 0x0000012C },
	{ "high_band_gain_curve_y_4", 0x00000078, 25, 16, CSR_RW, 0x00000040 },
	{ "GAIN_CURVE_4", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_5
	{ "high_band_gain_curve_x_5", 0x0000007C, 9, 0, CSR_RW, 0x0000014A },
	{ "high_band_gain_curve_y_5", 0x0000007C, 25, 16, CSR_RW, 0x0000003C },
	{ "GAIN_CURVE_5", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_6
	{ "high_band_gain_curve_x_6", 0x00000080, 9, 0, CSR_RW, 0x0000019A },
	{ "high_band_gain_curve_y_6", 0x00000080, 25, 16, CSR_RW, 0x00000010 },
	{ "GAIN_CURVE_6", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_7
	{ "high_band_gain_curve_x_7", 0x00000084, 9, 0, CSR_RW, 0x000001D2 },
	{ "high_band_gain_curve_y_7", 0x00000084, 25, 16, CSR_RW, 0x00000004 },
	{ "GAIN_CURVE_7", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_8
	{ "high_band_gain_curve_x_8", 0x00000088, 9, 0, CSR_RW, 0x000001FF },
	{ "high_band_gain_curve_y_8", 0x00000088, 25, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_8", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_9
	{ "middle_band_gain_curve_x_0", 0x0000008C, 9, 0, CSR_RW, 0x00000005 },
	{ "middle_band_gain_curve_y_0", 0x0000008C, 25, 16, CSR_RW, 0x00000001 },
	{ "GAIN_CURVE_9", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_10
	{ "middle_band_gain_curve_x_1", 0x00000090, 9, 0, CSR_RW, 0x00000023 },
	{ "middle_band_gain_curve_y_1", 0x00000090, 25, 16, CSR_RW, 0x00000010 },
	{ "GAIN_CURVE_10", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_11
	{ "middle_band_gain_curve_x_2", 0x00000094, 9, 0, CSR_RW, 0x00000069 },
	{ "middle_band_gain_curve_y_2", 0x00000094, 25, 16, CSR_RW, 0x0000003C },
	{ "GAIN_CURVE_11", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_12
	{ "middle_band_gain_curve_x_3", 0x00000098, 9, 0, CSR_RW, 0x00000087 },
	{ "middle_band_gain_curve_y_3", 0x00000098, 25, 16, CSR_RW, 0x00000040 },
	{ "GAIN_CURVE_12", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_13
	{ "middle_band_gain_curve_x_4", 0x0000009C, 9, 0, CSR_RW, 0x0000012C },
	{ "middle_band_gain_curve_y_4", 0x0000009C, 25, 16, CSR_RW, 0x00000040 },
	{ "GAIN_CURVE_13", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_14
	{ "middle_band_gain_curve_x_5", 0x000000A0, 9, 0, CSR_RW, 0x0000014A },
	{ "middle_band_gain_curve_y_5", 0x000000A0, 25, 16, CSR_RW, 0x0000003C },
	{ "GAIN_CURVE_14", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_15
	{ "middle_band_gain_curve_x_6", 0x000000A4, 9, 0, CSR_RW, 0x0000019A },
	{ "middle_band_gain_curve_y_6", 0x000000A4, 25, 16, CSR_RW, 0x00000010 },
	{ "GAIN_CURVE_15", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_16
	{ "middle_band_gain_curve_x_7", 0x000000A8, 9, 0, CSR_RW, 0x000001D2 },
	{ "middle_band_gain_curve_y_7", 0x000000A8, 25, 16, CSR_RW, 0x00000004 },
	{ "GAIN_CURVE_16", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_17
	{ "middle_band_gain_curve_x_8", 0x000000AC, 9, 0, CSR_RW, 0x000001FF },
	{ "middle_band_gain_curve_y_8", 0x000000AC, 25, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_17", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_0
	{ "high_band_gain_curve_m_0_2s", 0x000000B0, 13, 0, CSR_RW, 0x00000000 },
	{ "high_band_gain_curve_m_1_2s", 0x000000B0, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_0", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_1
	{ "high_band_gain_curve_m_2_2s", 0x000000B4, 13, 0, CSR_RW, 0x00000000 },
	{ "high_band_gain_curve_m_3_2s", 0x000000B4, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_1", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_2
	{ "high_band_gain_curve_m_4_2s", 0x000000B8, 13, 0, CSR_RW, 0x00000000 },
	{ "high_band_gain_curve_m_5_2s", 0x000000B8, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_2", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_3
	{ "high_band_gain_curve_m_6_2s", 0x000000BC, 13, 0, CSR_RW, 0x00000000 },
	{ "high_band_gain_curve_m_7_2s", 0x000000BC, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_3", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_4
	{ "high_band_gain_curve_m_8_2s", 0x000000C0, 13, 0, CSR_RW, 0x00000000 },
	{ "middle_band_gain_curve_m_8_2s", 0x000000C0, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_4", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_5
	{ "middle_band_gain_curve_m_0_2s", 0x000000C4, 13, 0, CSR_RW, 0x00000000 },
	{ "middle_band_gain_curve_m_1_2s", 0x000000C4, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_5", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_6
	{ "middle_band_gain_curve_m_2_2s", 0x000000C8, 13, 0, CSR_RW, 0x00000000 },
	{ "middle_band_gain_curve_m_3_2s", 0x000000C8, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_6", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_7
	{ "middle_band_gain_curve_m_4_2s", 0x000000CC, 13, 0, CSR_RW, 0x00000000 },
	{ "middle_band_gain_curve_m_5_2s", 0x000000CC, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_7", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD gain_curve_m_8
	{ "middle_band_gain_curve_m_6_2s", 0x000000D0, 13, 0, CSR_RW, 0x00000000 },
	{ "middle_band_gain_curve_m_7_2s", 0x000000D0, 29, 16, CSR_RW, 0x00000000 },
	{ "GAIN_CURVE_M_8", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_ini
	{ "luma_lut_y_ini", 0x000000D4, 9, 0, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_INI", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_0_xy
	{ "luma_lut_x_0", 0x000000D8, 9, 0, CSR_RW, 0x00000080 },
	{ "luma_lut_y_0", 0x000000D8, 25, 16, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_0_XY", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_0_m
	{ "luma_lut_m_0_2s", 0x000000DC, 6, 0, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_0_M", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_1_xy
	{ "luma_lut_x_1", 0x000000E0, 9, 0, CSR_RW, 0x00000084 },
	{ "luma_lut_y_1", 0x000000E0, 25, 16, CSR_RW, 0x00000040 },
	{ "LUMA_LUT_1_XY", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_1_m
	{ "luma_lut_m_1_2s", 0x000000E4, 6, 0, CSR_RW, 0x00000001 },
	{ "LUMA_LUT_1_M", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_2_xy
	{ "luma_lut_x_2", 0x000000E8, 9, 0, CSR_RW, 0x00000086 },
	{ "luma_lut_y_2", 0x000000E8, 25, 16, CSR_RW, 0x00000080 },
	{ "LUMA_LUT_2_XY", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_2_m
	{ "luma_lut_m_2_2s", 0x000000EC, 6, 0, CSR_RW, 0x00000002 },
	{ "LUMA_LUT_2_M", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_3_xy
	{ "luma_lut_x_3", 0x000000F0, 9, 0, CSR_RW, 0x00000088 },
	{ "luma_lut_y_3", 0x000000F0, 25, 16, CSR_RW, 0x00000100 },
	{ "LUMA_LUT_3_XY", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_3_m
	{ "luma_lut_m_3_2s", 0x000000F4, 6, 0, CSR_RW, 0x00000004 },
	{ "LUMA_LUT_3_M", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_4_xy
	{ "luma_lut_x_4", 0x000000F8, 9, 0, CSR_RW, 0x0000008E },
	{ "luma_lut_y_4", 0x000000F8, 25, 16, CSR_RW, 0x00000180 },
	{ "LUMA_LUT_4_XY", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_4_m
	{ "luma_lut_m_4_2s", 0x000000FC, 6, 0, CSR_RW, 0x00000002 },
	{ "LUMA_LUT_4_M", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_5_xy
	{ "luma_lut_x_5", 0x00000100, 9, 0, CSR_RW, 0x00000092 },
	{ "luma_lut_y_5", 0x00000100, 25, 16, CSR_RW, 0x00000200 },
	{ "LUMA_LUT_5_XY", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_5_m
	{ "luma_lut_m_5_2s", 0x00000104, 6, 0, CSR_RW, 0x00000001 },
	{ "LUMA_LUT_5_M", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_6_xy
	{ "luma_lut_x_6", 0x00000108, 9, 0, CSR_RW, 0x00000374 },
	{ "luma_lut_y_6", 0x00000108, 25, 16, CSR_RW, 0x00000200 },
	{ "LUMA_LUT_6_XY", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_6_m
	{ "luma_lut_m_6_2s", 0x0000010C, 6, 0, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_6_M", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_7_xy
	{ "luma_lut_x_7", 0x00000110, 9, 0, CSR_RW, 0x00000378 },
	{ "luma_lut_y_7", 0x00000110, 25, 16, CSR_RW, 0x00000100 },
	{ "LUMA_LUT_7_XY", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_7_m
	{ "luma_lut_m_7_2s", 0x00000114, 6, 0, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_7_M", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_8_xy
	{ "luma_lut_x_8", 0x00000118, 9, 0, CSR_RW, 0x00000380 },
	{ "luma_lut_y_8", 0x00000118, 25, 16, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_8_XY", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_8_m
	{ "luma_lut_m_8_2s", 0x0000011C, 6, 0, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_8_M", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD luma_lut_9_m
	{ "luma_lut_m_9_2s", 0x00000120, 14, 8, CSR_RW, 0x00000000 },
	{ "LUMA_LUT_9_M", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD soft_clip
	{ "soft_clip_slope", 0x00000124, 4, 0, CSR_RW, 0x0000000C },
	{ "SOFT_CLIP", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_set
	{ "rgl_y_lpf_en", 0x00000128, 0, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_lpf_clear", 0x00000128, 8, 8, CSR_RW, 0x00000000 },
	{ "RGL_Y_LPF_SET", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_rgl_wh
	{ "rgl_y_lpf_rgl_wd", 0x0000012C, 12, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_lpf_rgl_ht", 0x0000012C, 28, 16, CSR_RW, 0x00000000 },
	{ "RGL_Y_LPF_RGL_WH", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_x
	{ "rgl_y_lpf_sx", 0x00000130, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_lpf_ex", 0x00000130, 31, 16, CSR_RW, 0x00000000 },
	{ "RGL_Y_LPF_X", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_y
	{ "rgl_y_lpf_sy", 0x00000134, 15, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_lpf_ey", 0x00000134, 31, 16, CSR_RW, 0x00000000 },
	{ "RGL_Y_LPF_Y", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_xy_cnt_ini
	{ "rgl_y_lpf_x_cnt_ini", 0x00000138, 12, 0, CSR_RW, 0x00000000 },
	{ "rgl_y_lpf_y_cnt_ini", 0x00000138, 31, 16, CSR_RW, 0x00000000 },
	{ "RGL_Y_LPF_XY_CNT_INI", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_r_cnt_set
	{ "rgl_y_lpf_r_cnt_ini", 0x0000013C, 2, 0, CSR_RW, 0x00000000 },
	{ "RGL_Y_LPF_R_CNT_SET", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_lpf_pix_number
	{ "rgl_y_lpf_pix_num", 0x00000140, 25, 0, CSR_RW, 0x00002710 },
	{ "RGL_Y_LPF_PIX_NUMBER", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y_lpf_avg_0_set
	{ "roi_y_lpf_avg_0_clear", 0x00000144, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_y_lpf_avg_0_en", 0x00000144, 8, 8, CSR_RW, 0x00000000 },
	{ "ROI_Y_LPF_AVG_0_SET", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y_lpf_avg_0_sxsy
	{ "roi_y_lpf_avg_0_sx", 0x00000148, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_y_lpf_avg_0_sy", 0x00000148, 31, 16, CSR_RW, 0x00000000 },
	{ "ROI_Y_LPF_AVG_0_SXSY", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y_lpf_avg_0_exey
	{ "roi_y_lpf_avg_0_ex", 0x0000014C, 15, 0, CSR_RW, 0x00000000 },
	{ "roi_y_lpf_avg_0_ey", 0x0000014C, 31, 16, CSR_RW, 0x00000000 },
	{ "ROI_Y_LPF_AVG_0_EXEY", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y_lpf_avg_0_pix_number
	{ "roi_y_lpf_avg_0_pix_num", 0x00000150, 25, 0, CSR_RW, 0x00002710 },
	{ "ROI_Y_LPF_AVG_0_PIX_NUMBER", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD roi_y_lpf_avg_0_average
	{ "roi_y_lpf_avg_0_avg", 0x00000154, 9, 0, CSR_RO, 0x00000000 },
	{ "ROI_Y_LPF_AVG_0_AVERAGE", 0x00000154, 31, 0, CSR_RO, 0x00000000 },
	// WORD rgl_y_stat_ctrl
	{ "rgl_y_stat_en", 0x00000158, 0, 0, CSR_RW, 0x00000000 },
	{ "RGL_Y_STAT_CTRL", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_stat_read_addr
	{ "rgl_y_stat_r_addr", 0x0000015C, 6, 0, CSR_RW, 0x00000000 },
	{ "RGL_Y_STAT_READ_ADDR", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgl_y_stat_read_data
	{ "rgl_y_stat_r_data", 0x00000160, 19, 0, CSR_RO, 0x00000000 },
	{ "RGL_Y_STAT_READ_DATA", 0x00000160, 31, 0, CSR_RO, 0x00000000 },
	// WORD demo_set
	{ "demo_en", 0x00000164, 0, 0, CSR_RW, 0x00000000 },
	{ "DEMO_SET", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_x
	{ "demo_x_min", 0x00000168, 15, 0, CSR_RW, 0x00000000 },
	{ "demo_x_max", 0x00000168, 31, 16, CSR_RW, 0x00000000 },
	{ "DEMO_X", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD demo_y
	{ "demo_y_min", 0x0000016C, 15, 0, CSR_RW, 0x00000000 },
	{ "demo_y_max", 0x0000016C, 31, 16, CSR_RW, 0x00000000 },
	{ "DEMO_Y", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_mon
	{ "debug_mon_sel", 0x00000170, 0, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_MON", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_reserved
	{ "reserved", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	{ "SHP_RESERVED", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_edge_gain
	{ "edge_gain", 0x00000178, 4, 0, CSR_RW, 0x00000000 },
	{ "edge_variance_tolarance", 0x00000178, 18, 8, CSR_RW, 0x00000000 },
	{ "SHP_EDGE_GAIN", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD peak_gain_1
	{ "peak_gain", 0x0000017C, 5, 0, CSR_RW, 0x00000000 },
	{ "overshoot_gain", 0x0000017C, 12, 8, CSR_RW, 0x00000000 },
	{ "undershoot_gain", 0x0000017C, 20, 16, CSR_RW, 0x00000001 },
	{ "PEAK_GAIN_1", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD peak_gain_2
	{ "peak_variance_tolarance", 0x00000180, 10, 0, CSR_RW, 0x00000000 },
	{ "PEAK_GAIN_2", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD atpg_ctrl
	{ "atpg_ctrl_0", 0x00000184, 0, 0, CSR_RW, 0x00000000 },
	{ "atpg_ctrl_1", 0x00000184, 8, 8, CSR_RW, 0x00000000 },
	{ "ATPG_CTRL", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_0
	{ "rgl_y_stat_r_data_0", 0x00000188, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_0", 0x00000188, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_1
	{ "rgl_y_stat_r_data_1", 0x0000018C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_1", 0x0000018C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_2
	{ "rgl_y_stat_r_data_2", 0x00000190, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_2", 0x00000190, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_3
	{ "rgl_y_stat_r_data_3", 0x00000194, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_3", 0x00000194, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_4
	{ "rgl_y_stat_r_data_4", 0x00000198, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_4", 0x00000198, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_5
	{ "rgl_y_stat_r_data_5", 0x0000019C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_5", 0x0000019C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_6
	{ "rgl_y_stat_r_data_6", 0x000001A0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_6", 0x000001A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_7
	{ "rgl_y_stat_r_data_7", 0x000001A4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_7", 0x000001A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_8
	{ "rgl_y_stat_r_data_8", 0x000001A8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_8", 0x000001A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_9
	{ "rgl_y_stat_r_data_9", 0x000001AC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_9", 0x000001AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_10
	{ "rgl_y_stat_r_data_10", 0x000001B0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_10", 0x000001B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_11
	{ "rgl_y_stat_r_data_11", 0x000001B4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_11", 0x000001B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_12
	{ "rgl_y_stat_r_data_12", 0x000001B8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_12", 0x000001B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_13
	{ "rgl_y_stat_r_data_13", 0x000001BC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_13", 0x000001BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_14
	{ "rgl_y_stat_r_data_14", 0x000001C0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_14", 0x000001C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_15
	{ "rgl_y_stat_r_data_15", 0x000001C4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_15", 0x000001C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_16
	{ "rgl_y_stat_r_data_16", 0x000001C8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_16", 0x000001C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_17
	{ "rgl_y_stat_r_data_17", 0x000001CC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_17", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_18
	{ "rgl_y_stat_r_data_18", 0x000001D0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_18", 0x000001D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_19
	{ "rgl_y_stat_r_data_19", 0x000001D4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_19", 0x000001D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_20
	{ "rgl_y_stat_r_data_20", 0x000001D8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_20", 0x000001D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_21
	{ "rgl_y_stat_r_data_21", 0x000001DC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_21", 0x000001DC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_22
	{ "rgl_y_stat_r_data_22", 0x000001E0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_22", 0x000001E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_23
	{ "rgl_y_stat_r_data_23", 0x000001E4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_23", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_24
	{ "rgl_y_stat_r_data_24", 0x000001E8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_24", 0x000001E8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_25
	{ "rgl_y_stat_r_data_25", 0x000001EC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_25", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_26
	{ "rgl_y_stat_r_data_26", 0x000001F0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_26", 0x000001F0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_27
	{ "rgl_y_stat_r_data_27", 0x000001F4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_27", 0x000001F4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_28
	{ "rgl_y_stat_r_data_28", 0x000001F8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_28", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_29
	{ "rgl_y_stat_r_data_29", 0x000001FC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_29", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_30
	{ "rgl_y_stat_r_data_30", 0x00000200, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_30", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_31
	{ "rgl_y_stat_r_data_31", 0x00000204, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_31", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_32
	{ "rgl_y_stat_r_data_32", 0x00000208, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_32", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_33
	{ "rgl_y_stat_r_data_33", 0x0000020C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_33", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_34
	{ "rgl_y_stat_r_data_34", 0x00000210, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_34", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_35
	{ "rgl_y_stat_r_data_35", 0x00000214, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_35", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_36
	{ "rgl_y_stat_r_data_36", 0x00000218, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_36", 0x00000218, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_37
	{ "rgl_y_stat_r_data_37", 0x0000021C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_37", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_38
	{ "rgl_y_stat_r_data_38", 0x00000220, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_38", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_39
	{ "rgl_y_stat_r_data_39", 0x00000224, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_39", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_40
	{ "rgl_y_stat_r_data_40", 0x00000228, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_40", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_41
	{ "rgl_y_stat_r_data_41", 0x0000022C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_41", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_42
	{ "rgl_y_stat_r_data_42", 0x00000230, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_42", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_43
	{ "rgl_y_stat_r_data_43", 0x00000234, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_43", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_44
	{ "rgl_y_stat_r_data_44", 0x00000238, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_44", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_45
	{ "rgl_y_stat_r_data_45", 0x0000023C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_45", 0x0000023C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_46
	{ "rgl_y_stat_r_data_46", 0x00000240, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_46", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_47
	{ "rgl_y_stat_r_data_47", 0x00000244, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_47", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_48
	{ "rgl_y_stat_r_data_48", 0x00000248, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_48", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_49
	{ "rgl_y_stat_r_data_49", 0x0000024C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_49", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_50
	{ "rgl_y_stat_r_data_50", 0x00000250, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_50", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_51
	{ "rgl_y_stat_r_data_51", 0x00000254, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_51", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_52
	{ "rgl_y_stat_r_data_52", 0x00000258, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_52", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_53
	{ "rgl_y_stat_r_data_53", 0x0000025C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_53", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_54
	{ "rgl_y_stat_r_data_54", 0x00000260, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_54", 0x00000260, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_55
	{ "rgl_y_stat_r_data_55", 0x00000264, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_55", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_56
	{ "rgl_y_stat_r_data_56", 0x00000268, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_56", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_57
	{ "rgl_y_stat_r_data_57", 0x0000026C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_57", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_58
	{ "rgl_y_stat_r_data_58", 0x00000270, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_58", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_59
	{ "rgl_y_stat_r_data_59", 0x00000274, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_59", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_60
	{ "rgl_y_stat_r_data_60", 0x00000278, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_60", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_61
	{ "rgl_y_stat_r_data_61", 0x0000027C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_61", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_62
	{ "rgl_y_stat_r_data_62", 0x00000280, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_62", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_63
	{ "rgl_y_stat_r_data_63", 0x00000284, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_63", 0x00000284, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_64
	{ "rgl_y_stat_r_data_64", 0x00000288, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_64", 0x00000288, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_65
	{ "rgl_y_stat_r_data_65", 0x0000028C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_65", 0x0000028C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_66
	{ "rgl_y_stat_r_data_66", 0x00000290, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_66", 0x00000290, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_67
	{ "rgl_y_stat_r_data_67", 0x00000294, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_67", 0x00000294, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_68
	{ "rgl_y_stat_r_data_68", 0x00000298, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_68", 0x00000298, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_69
	{ "rgl_y_stat_r_data_69", 0x0000029C, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_69", 0x0000029C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_70
	{ "rgl_y_stat_r_data_70", 0x000002A0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_70", 0x000002A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_71
	{ "rgl_y_stat_r_data_71", 0x000002A4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_71", 0x000002A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_72
	{ "rgl_y_stat_r_data_72", 0x000002A8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_72", 0x000002A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_73
	{ "rgl_y_stat_r_data_73", 0x000002AC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_73", 0x000002AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_74
	{ "rgl_y_stat_r_data_74", 0x000002B0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_74", 0x000002B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_75
	{ "rgl_y_stat_r_data_75", 0x000002B4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_75", 0x000002B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_76
	{ "rgl_y_stat_r_data_76", 0x000002B8, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_76", 0x000002B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_77
	{ "rgl_y_stat_r_data_77", 0x000002BC, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_77", 0x000002BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_78
	{ "rgl_y_stat_r_data_78", 0x000002C0, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_78", 0x000002C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD fpga_rgl_y_stat_r_data_79
	{ "rgl_y_stat_r_data_79", 0x000002C4, 19, 0, CSR_RO, 0x00000000 },
	{ "FPGA_RGL_Y_STAT_R_DATA_79", 0x000002C4, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SHP_H_
