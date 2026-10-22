/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ENC_OSD_H_
#define CSR_TABLE_ENC_OSD_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_enc_osd[] = {
	// WORD layer_setting
	{ "input_order", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "output_order", 0x00000000, 18, 16, CSR_RW, 0x00000000 },
	{ "LAYER_SETTING", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD chroma_sub_samble_mode
	{ "sub_sample_mode", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "CHROMA_SUB_SAMBLE_MODE", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD wildcard_color_0
	{ "wildcard_color_0_y", 0x00000008, 7, 0, CSR_RW, 0x00000000 },
	{ "wildcard_color_0_u", 0x00000008, 15, 8, CSR_RW, 0x00000080 },
	{ "wildcard_color_0_v", 0x00000008, 23, 16, CSR_RW, 0x00000080 },
	{ "WILDCARD_COLOR_0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD wildcard_color_1
	{ "wildcard_color_1_y", 0x0000000C, 7, 0, CSR_RW, 0x000000FF },
	{ "wildcard_color_1_u", 0x0000000C, 15, 8, CSR_RW, 0x00000080 },
	{ "wildcard_color_1_v", 0x0000000C, 23, 16, CSR_RW, 0x00000080 },
	{ "WILDCARD_COLOR_1", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wildcard_alpha
	{ "wildcard_alpha_0", 0x00000010, 7, 0, CSR_RW, 0x00000064 },
	{ "wildcard_alpha_1", 0x00000010, 15, 8, CSR_RW, 0x000000C8 },
	{ "WILDCARD_ALPHA", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cst_coeff_y_0
	{ "csr_cst_coeff_r2y_2s", 0x00000014, 13, 0, CSR_RW, 0x00000177 },
	{ "csr_cst_coeff_g2y_2s", 0x00000014, 29, 16, CSR_RW, 0x000004E9 },
	{ "CST_COEFF_Y_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD cst_coeff_y_1
	{ "csr_cst_coeff_b2y_2s", 0x00000018, 13, 0, CSR_RW, 0x0000007F },
	{ "csr_cst_offset_y_2s", 0x00000018, 26, 16, CSR_RW, 0x00000040 },
	{ "CST_COEFF_Y_1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cst_coeff_u_0
	{ "csr_cst_coeff_r2u_2s", 0x0000001C, 13, 0, CSR_RW, 0x00003F31 },
	{ "csr_cst_coeff_g2u_2s", 0x0000001C, 29, 16, CSR_RW, 0x00003D4C },
	{ "CST_COEFF_U_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cst_coeff_u_1
	{ "csr_cst_coeff_b2u_2s", 0x00000020, 13, 0, CSR_RW, 0x00000383 },
	{ "csr_cst_offset_u_2s", 0x00000020, 26, 16, CSR_RW, 0x00000200 },
	{ "CST_COEFF_U_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD cst_coeff_v_0
	{ "csr_cst_coeff_r2v_2s", 0x00000024, 13, 0, CSR_RW, 0x00000383 },
	{ "csr_cst_coeff_g2v_2s", 0x00000024, 29, 16, CSR_RW, 0x00003CCF },
	{ "CST_COEFF_V_0", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cst_coeff_v_1
	{ "csr_cst_coeff_b2v_2s", 0x00000028, 13, 0, CSR_RW, 0x00003FAE },
	{ "csr_cst_offset_v_2s", 0x00000028, 26, 16, CSR_RW, 0x00000200 },
	{ "CST_COEFF_V_1", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_setting
	{ "layer_img_0_order_i", 0x0000002C, 2, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_order_o", 0x0000002C, 10, 8, CSR_RW, 0x00000002 },
	{ "layer_img_0_mode", 0x0000002C, 19, 16, CSR_RW, 0x00000000 },
	{ "layer_img_0_yuv_sel", 0x0000002C, 26, 24, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_SETTING", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_00_enable
	{ "layer_img_0_roi_00_en", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_00_ENABLE", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_00_start
	{ "layer_img_0_roi_00_sx", 0x00000034, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_00_sy", 0x00000034, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_00_START", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_00_end
	{ "layer_img_0_roi_00_ex", 0x00000038, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_00_ey", 0x00000038, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_00_END", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_01_enable
	{ "layer_img_0_roi_01_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_01_ENABLE", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_01_start
	{ "layer_img_0_roi_01_sx", 0x00000040, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_01_sy", 0x00000040, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_01_START", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_01_end
	{ "layer_img_0_roi_01_ex", 0x00000044, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_01_ey", 0x00000044, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_01_END", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_02_enable
	{ "layer_img_0_roi_02_en", 0x00000048, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_02_ENABLE", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_02_start
	{ "layer_img_0_roi_02_sx", 0x0000004C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_02_sy", 0x0000004C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_02_START", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_02_end
	{ "layer_img_0_roi_02_ex", 0x00000050, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_02_ey", 0x00000050, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_02_END", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_03_enable
	{ "layer_img_0_roi_03_en", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_03_ENABLE", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_03_start
	{ "layer_img_0_roi_03_sx", 0x00000058, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_03_sy", 0x00000058, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_03_START", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_03_end
	{ "layer_img_0_roi_03_ex", 0x0000005C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_03_ey", 0x0000005C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_03_END", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_04_enable
	{ "layer_img_0_roi_04_en", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_04_ENABLE", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_04_start
	{ "layer_img_0_roi_04_sx", 0x00000064, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_04_sy", 0x00000064, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_04_START", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_04_end
	{ "layer_img_0_roi_04_ex", 0x00000068, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_04_ey", 0x00000068, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_04_END", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_05_enable
	{ "layer_img_0_roi_05_en", 0x0000006C, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_05_ENABLE", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_05_start
	{ "layer_img_0_roi_05_sx", 0x00000070, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_05_sy", 0x00000070, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_05_START", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_05_end
	{ "layer_img_0_roi_05_ex", 0x00000074, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_05_ey", 0x00000074, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_05_END", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_06_enable
	{ "layer_img_0_roi_06_en", 0x00000078, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_06_ENABLE", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_06_start
	{ "layer_img_0_roi_06_sx", 0x0000007C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_06_sy", 0x0000007C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_06_START", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_06_end
	{ "layer_img_0_roi_06_ex", 0x00000080, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_06_ey", 0x00000080, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_06_END", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_07_enable
	{ "layer_img_0_roi_07_en", 0x00000084, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_07_ENABLE", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_07_start
	{ "layer_img_0_roi_07_sx", 0x00000088, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_07_sy", 0x00000088, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_07_START", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_0_07_end
	{ "layer_img_0_roi_07_ex", 0x0000008C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_0_roi_07_ey", 0x0000008C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_0_07_END", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_setting
	{ "layer_img_1_order_i", 0x00000090, 2, 0, CSR_RW, 0x00000001 },
	{ "layer_img_1_order_o", 0x00000090, 10, 8, CSR_RW, 0x00000003 },
	{ "layer_img_1_mode", 0x00000090, 19, 16, CSR_RW, 0x00000000 },
	{ "layer_img_1_yuv_sel", 0x00000090, 26, 24, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_SETTING", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_00_enable
	{ "layer_img_1_roi_00_en", 0x00000094, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_00_ENABLE", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_00_start
	{ "layer_img_1_roi_00_sx", 0x00000098, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_00_sy", 0x00000098, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_00_START", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_00_end
	{ "layer_img_1_roi_00_ex", 0x0000009C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_00_ey", 0x0000009C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_00_END", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_01_enable
	{ "layer_img_1_roi_01_en", 0x000000A0, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_01_ENABLE", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_01_start
	{ "layer_img_1_roi_01_sx", 0x000000A4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_01_sy", 0x000000A4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_01_START", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_01_end
	{ "layer_img_1_roi_01_ex", 0x000000A8, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_01_ey", 0x000000A8, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_01_END", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_02_enable
	{ "layer_img_1_roi_02_en", 0x000000AC, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_02_ENABLE", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_02_start
	{ "layer_img_1_roi_02_sx", 0x000000B0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_02_sy", 0x000000B0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_02_START", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_02_end
	{ "layer_img_1_roi_02_ex", 0x000000B4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_02_ey", 0x000000B4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_02_END", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_03_enable
	{ "layer_img_1_roi_03_en", 0x000000B8, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_03_ENABLE", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_03_start
	{ "layer_img_1_roi_03_sx", 0x000000BC, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_03_sy", 0x000000BC, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_03_START", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_03_end
	{ "layer_img_1_roi_03_ex", 0x000000C0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_03_ey", 0x000000C0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_03_END", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_04_enable
	{ "layer_img_1_roi_04_en", 0x000000C4, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_04_ENABLE", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_04_start
	{ "layer_img_1_roi_04_sx", 0x000000C8, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_04_sy", 0x000000C8, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_04_START", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_04_end
	{ "layer_img_1_roi_04_ex", 0x000000CC, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_04_ey", 0x000000CC, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_04_END", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_05_enable
	{ "layer_img_1_roi_05_en", 0x000000D0, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_05_ENABLE", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_05_start
	{ "layer_img_1_roi_05_sx", 0x000000D4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_05_sy", 0x000000D4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_05_START", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_05_end
	{ "layer_img_1_roi_05_ex", 0x000000D8, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_05_ey", 0x000000D8, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_05_END", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_06_enable
	{ "layer_img_1_roi_06_en", 0x000000DC, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_06_ENABLE", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_06_start
	{ "layer_img_1_roi_06_sx", 0x000000E0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_06_sy", 0x000000E0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_06_START", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_06_end
	{ "layer_img_1_roi_06_ex", 0x000000E4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_06_ey", 0x000000E4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_06_END", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_07_enable
	{ "layer_img_1_roi_07_en", 0x000000E8, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_07_ENABLE", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_07_start
	{ "layer_img_1_roi_07_sx", 0x000000EC, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_07_sy", 0x000000EC, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_07_START", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_image_1_07_end
	{ "layer_img_1_roi_07_ex", 0x000000F0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_img_1_roi_07_ey", 0x000000F0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_IMAGE_1_07_END", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_setting
	{ "layer_bbox_0_order_i", 0x000000F4, 2, 0, CSR_RW, 0x00000002 },
	{ "layer_bbox_0_order_o", 0x000000F4, 10, 8, CSR_RW, 0x00000004 },
	{ "layer_bbox_0_yuv_sel", 0x000000F4, 18, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_SETTING", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_00_enable
	{ "layer_bbox_0_roi_00_en", 0x000000F8, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_00_ENABLE", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_00_start
	{ "layer_bbox_0_roi_00_sx", 0x000000FC, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_00_sy", 0x000000FC, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_00_START", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_00_end
	{ "layer_bbox_0_roi_00_ex", 0x00000100, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_00_ey", 0x00000100, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_00_END", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_00_info
	{ "layer_bbox_0_roi_00_mask", 0x00000104, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_00_alpha", 0x00000104, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_00_width", 0x00000104, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_00_INFO", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_00_color
	{ "layer_bbox_0_roi_00_ch_0", 0x00000108, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_00_ch_1", 0x00000108, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_00_ch_2", 0x00000108, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_00_COLOR", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_01_enable
	{ "layer_bbox_0_roi_01_en", 0x0000010C, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_01_ENABLE", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_01_start
	{ "layer_bbox_0_roi_01_sx", 0x00000110, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_01_sy", 0x00000110, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_01_START", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_01_end
	{ "layer_bbox_0_roi_01_ex", 0x00000114, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_01_ey", 0x00000114, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_01_END", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_01_info
	{ "layer_bbox_0_roi_01_mask", 0x00000118, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_01_alpha", 0x00000118, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_01_width", 0x00000118, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_01_INFO", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_01_color
	{ "layer_bbox_0_roi_01_ch_0", 0x0000011C, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_01_ch_1", 0x0000011C, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_01_ch_2", 0x0000011C, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_01_COLOR", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_02_enable
	{ "layer_bbox_0_roi_02_en", 0x00000120, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_02_ENABLE", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_02_start
	{ "layer_bbox_0_roi_02_sx", 0x00000124, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_02_sy", 0x00000124, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_02_START", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_02_end
	{ "layer_bbox_0_roi_02_ex", 0x00000128, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_02_ey", 0x00000128, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_02_END", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_02_info
	{ "layer_bbox_0_roi_02_mask", 0x0000012C, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_02_alpha", 0x0000012C, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_02_width", 0x0000012C, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_02_INFO", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_02_color
	{ "layer_bbox_0_roi_02_ch_0", 0x00000130, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_02_ch_1", 0x00000130, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_02_ch_2", 0x00000130, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_02_COLOR", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_03_enable
	{ "layer_bbox_0_roi_03_en", 0x00000134, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_03_ENABLE", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_03_start
	{ "layer_bbox_0_roi_03_sx", 0x00000138, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_03_sy", 0x00000138, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_03_START", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_03_end
	{ "layer_bbox_0_roi_03_ex", 0x0000013C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_03_ey", 0x0000013C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_03_END", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_03_info
	{ "layer_bbox_0_roi_03_mask", 0x00000140, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_03_alpha", 0x00000140, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_03_width", 0x00000140, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_03_INFO", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_03_color
	{ "layer_bbox_0_roi_03_ch_0", 0x00000144, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_03_ch_1", 0x00000144, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_03_ch_2", 0x00000144, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_03_COLOR", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_04_enable
	{ "layer_bbox_0_roi_04_en", 0x00000148, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_04_ENABLE", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_04_start
	{ "layer_bbox_0_roi_04_sx", 0x0000014C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_04_sy", 0x0000014C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_04_START", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_04_end
	{ "layer_bbox_0_roi_04_ex", 0x00000150, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_04_ey", 0x00000150, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_04_END", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_04_info
	{ "layer_bbox_0_roi_04_mask", 0x00000154, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_04_alpha", 0x00000154, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_04_width", 0x00000154, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_04_INFO", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_04_color
	{ "layer_bbox_0_roi_04_ch_0", 0x00000158, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_04_ch_1", 0x00000158, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_04_ch_2", 0x00000158, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_04_COLOR", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_05_enable
	{ "layer_bbox_0_roi_05_en", 0x0000015C, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_05_ENABLE", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_05_start
	{ "layer_bbox_0_roi_05_sx", 0x00000160, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_05_sy", 0x00000160, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_05_START", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_05_end
	{ "layer_bbox_0_roi_05_ex", 0x00000164, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_05_ey", 0x00000164, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_05_END", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_05_info
	{ "layer_bbox_0_roi_05_mask", 0x00000168, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_05_alpha", 0x00000168, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_05_width", 0x00000168, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_05_INFO", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_05_color
	{ "layer_bbox_0_roi_05_ch_0", 0x0000016C, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_05_ch_1", 0x0000016C, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_05_ch_2", 0x0000016C, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_05_COLOR", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_06_enable
	{ "layer_bbox_0_roi_06_en", 0x00000170, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_06_ENABLE", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_06_start
	{ "layer_bbox_0_roi_06_sx", 0x00000174, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_06_sy", 0x00000174, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_06_START", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_06_end
	{ "layer_bbox_0_roi_06_ex", 0x00000178, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_06_ey", 0x00000178, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_06_END", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_06_info
	{ "layer_bbox_0_roi_06_mask", 0x0000017C, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_06_alpha", 0x0000017C, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_06_width", 0x0000017C, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_06_INFO", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_06_color
	{ "layer_bbox_0_roi_06_ch_0", 0x00000180, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_06_ch_1", 0x00000180, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_06_ch_2", 0x00000180, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_06_COLOR", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_07_enable
	{ "layer_bbox_0_roi_07_en", 0x00000184, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_07_ENABLE", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_07_start
	{ "layer_bbox_0_roi_07_sx", 0x00000188, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_07_sy", 0x00000188, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_07_START", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_07_end
	{ "layer_bbox_0_roi_07_ex", 0x0000018C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_07_ey", 0x0000018C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_07_END", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_07_info
	{ "layer_bbox_0_roi_07_mask", 0x00000190, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_07_alpha", 0x00000190, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_07_width", 0x00000190, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_0_07_INFO", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_0_07_color
	{ "layer_bbox_0_roi_07_ch_0", 0x00000194, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_07_ch_1", 0x00000194, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_0_roi_07_ch_2", 0x00000194, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_0_07_COLOR", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_setting
	{ "layer_bbox_1_order_i", 0x00000198, 2, 0, CSR_RW, 0x00000003 },
	{ "layer_bbox_1_order_o", 0x00000198, 10, 8, CSR_RW, 0x00000005 },
	{ "layer_bbox_1_yuv_sel", 0x00000198, 18, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_SETTING", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_00_enable
	{ "layer_bbox_1_roi_00_en", 0x0000019C, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_00_ENABLE", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_00_start
	{ "layer_bbox_1_roi_00_sx", 0x000001A0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_00_sy", 0x000001A0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_00_START", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_00_end
	{ "layer_bbox_1_roi_00_ex", 0x000001A4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_00_ey", 0x000001A4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_00_END", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_00_info
	{ "layer_bbox_1_roi_00_mask", 0x000001A8, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_00_alpha", 0x000001A8, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_00_width", 0x000001A8, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_00_INFO", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_00_color
	{ "layer_bbox_1_roi_00_ch_0", 0x000001AC, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_00_ch_1", 0x000001AC, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_00_ch_2", 0x000001AC, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_00_COLOR", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_01_enable
	{ "layer_bbox_1_roi_01_en", 0x000001B0, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_01_ENABLE", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_01_start
	{ "layer_bbox_1_roi_01_sx", 0x000001B4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_01_sy", 0x000001B4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_01_START", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_01_end
	{ "layer_bbox_1_roi_01_ex", 0x000001B8, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_01_ey", 0x000001B8, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_01_END", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_01_info
	{ "layer_bbox_1_roi_01_mask", 0x000001BC, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_01_alpha", 0x000001BC, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_01_width", 0x000001BC, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_01_INFO", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_01_color
	{ "layer_bbox_1_roi_01_ch_0", 0x000001C0, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_01_ch_1", 0x000001C0, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_01_ch_2", 0x000001C0, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_01_COLOR", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_02_enable
	{ "layer_bbox_1_roi_02_en", 0x000001C4, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_02_ENABLE", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_02_start
	{ "layer_bbox_1_roi_02_sx", 0x000001C8, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_02_sy", 0x000001C8, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_02_START", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_02_end
	{ "layer_bbox_1_roi_02_ex", 0x000001CC, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_02_ey", 0x000001CC, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_02_END", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_02_info
	{ "layer_bbox_1_roi_02_mask", 0x000001D0, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_02_alpha", 0x000001D0, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_02_width", 0x000001D0, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_02_INFO", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_02_color
	{ "layer_bbox_1_roi_02_ch_0", 0x000001D4, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_02_ch_1", 0x000001D4, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_02_ch_2", 0x000001D4, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_02_COLOR", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_03_enable
	{ "layer_bbox_1_roi_03_en", 0x000001D8, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_03_ENABLE", 0x000001D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_03_start
	{ "layer_bbox_1_roi_03_sx", 0x000001DC, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_03_sy", 0x000001DC, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_03_START", 0x000001DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_03_end
	{ "layer_bbox_1_roi_03_ex", 0x000001E0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_03_ey", 0x000001E0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_03_END", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_03_info
	{ "layer_bbox_1_roi_03_mask", 0x000001E4, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_03_alpha", 0x000001E4, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_03_width", 0x000001E4, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_03_INFO", 0x000001E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_03_color
	{ "layer_bbox_1_roi_03_ch_0", 0x000001E8, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_03_ch_1", 0x000001E8, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_03_ch_2", 0x000001E8, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_03_COLOR", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_04_enable
	{ "layer_bbox_1_roi_04_en", 0x000001EC, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_04_ENABLE", 0x000001EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_04_start
	{ "layer_bbox_1_roi_04_sx", 0x000001F0, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_04_sy", 0x000001F0, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_04_START", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_04_end
	{ "layer_bbox_1_roi_04_ex", 0x000001F4, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_04_ey", 0x000001F4, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_04_END", 0x000001F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_04_info
	{ "layer_bbox_1_roi_04_mask", 0x000001F8, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_04_alpha", 0x000001F8, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_04_width", 0x000001F8, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_04_INFO", 0x000001F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_04_color
	{ "layer_bbox_1_roi_04_ch_0", 0x000001FC, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_04_ch_1", 0x000001FC, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_04_ch_2", 0x000001FC, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_04_COLOR", 0x000001FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_05_enable
	{ "layer_bbox_1_roi_05_en", 0x00000200, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_05_ENABLE", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_05_start
	{ "layer_bbox_1_roi_05_sx", 0x00000204, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_05_sy", 0x00000204, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_05_START", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_05_end
	{ "layer_bbox_1_roi_05_ex", 0x00000208, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_05_ey", 0x00000208, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_05_END", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_05_info
	{ "layer_bbox_1_roi_05_mask", 0x0000020C, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_05_alpha", 0x0000020C, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_05_width", 0x0000020C, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_05_INFO", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_05_color
	{ "layer_bbox_1_roi_05_ch_0", 0x00000210, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_05_ch_1", 0x00000210, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_05_ch_2", 0x00000210, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_05_COLOR", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_06_enable
	{ "layer_bbox_1_roi_06_en", 0x00000214, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_06_ENABLE", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_06_start
	{ "layer_bbox_1_roi_06_sx", 0x00000218, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_06_sy", 0x00000218, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_06_START", 0x00000218, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_06_end
	{ "layer_bbox_1_roi_06_ex", 0x0000021C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_06_ey", 0x0000021C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_06_END", 0x0000021C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_06_info
	{ "layer_bbox_1_roi_06_mask", 0x00000220, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_06_alpha", 0x00000220, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_06_width", 0x00000220, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_06_INFO", 0x00000220, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_06_color
	{ "layer_bbox_1_roi_06_ch_0", 0x00000224, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_06_ch_1", 0x00000224, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_06_ch_2", 0x00000224, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_06_COLOR", 0x00000224, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_07_enable
	{ "layer_bbox_1_roi_07_en", 0x00000228, 0, 0, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_07_ENABLE", 0x00000228, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_07_start
	{ "layer_bbox_1_roi_07_sx", 0x0000022C, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_07_sy", 0x0000022C, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_07_START", 0x0000022C, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_07_end
	{ "layer_bbox_1_roi_07_ex", 0x00000230, 12, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_07_ey", 0x00000230, 28, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_07_END", 0x00000230, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_07_info
	{ "layer_bbox_1_roi_07_mask", 0x00000234, 0, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_07_alpha", 0x00000234, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_07_width", 0x00000234, 27, 16, CSR_RW, 0x00000002 },
	{ "LAYER_BBOX_1_07_INFO", 0x00000234, 31, 0, CSR_RW, 0x00000000 },
	// WORD layer_bbox_1_07_color
	{ "layer_bbox_1_roi_07_ch_0", 0x00000238, 7, 0, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_07_ch_1", 0x00000238, 15, 8, CSR_RW, 0x00000000 },
	{ "layer_bbox_1_roi_07_ch_2", 0x00000238, 23, 16, CSR_RW, 0x00000000 },
	{ "LAYER_BBOX_1_07_COLOR", 0x00000238, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_monitor_sel
	{ "debug_mon_sel", 0x0000023C, 1, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_MONITOR_SEL", 0x0000023C, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_osd_reserved_0
	{ "reserved_0", 0x00000240, 31, 0, CSR_RW, 0x00000000 },
	{ "ENC_OSD_RESERVED_0", 0x00000240, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_osd_reserved_1
	{ "reserved_1", 0x00000244, 31, 0, CSR_RW, 0x00000000 },
	{ "ENC_OSD_RESERVED_1", 0x00000244, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_osd_reserved_2
	{ "reserved_2", 0x00000248, 31, 0, CSR_RW, 0x00000000 },
	{ "ENC_OSD_RESERVED_2", 0x00000248, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ENC_OSD_H_
