/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ENC_H_
#define CSR_TABLE_ENC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_enc[] = {
	// WORD enc001
	{ "encoder_mode", 0x00000000, 1, 0, CSR_RW, 0x00000000 },
	{ "ENC001", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc002
	{ "efuse_enc_pix_rate_violation", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "ENC002", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD enc003
	{ "debug_mon_sel", 0x00000008, 2, 0, CSR_RW, 0x00000000 },
	{ "ENC003", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc004
	{ "debug_mon_reg", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "ENC004", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD mem_ctrl
	{ "sd", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "MEM_CTRL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_0
	{ "reserved_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD src_proc_mono
	{ "mono_mode", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "SRC_PROC_MONO", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_0_en
	{ "cover_roi_0_en", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_0_EN", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_0_start
	{ "cover_roi_0_sx", 0x00000020, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_0_sy", 0x00000020, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_0_START", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_0_end
	{ "cover_roi_0_ex", 0x00000024, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_0_ey", 0x00000024, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_0_END", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_0_color
	{ "cover_roi_0_color_y", 0x00000028, 7, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_0_color_u", 0x00000028, 15, 8, CSR_RW, 0x00000000 },
	{ "cover_roi_0_color_v", 0x00000028, 23, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_0_COLOR", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_1_en
	{ "cover_roi_1_en", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_1_EN", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_1_start
	{ "cover_roi_1_sx", 0x00000030, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_1_sy", 0x00000030, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_1_START", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_1_end
	{ "cover_roi_1_ex", 0x00000034, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_1_ey", 0x00000034, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_1_END", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_1_color
	{ "cover_roi_1_color_y", 0x00000038, 7, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_1_color_u", 0x00000038, 15, 8, CSR_RW, 0x00000000 },
	{ "cover_roi_1_color_v", 0x00000038, 23, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_1_COLOR", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_2_en
	{ "cover_roi_2_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_2_EN", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_2_start
	{ "cover_roi_2_sx", 0x00000040, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_2_sy", 0x00000040, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_2_START", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_2_end
	{ "cover_roi_2_ex", 0x00000044, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_2_ey", 0x00000044, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_2_END", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_2_color
	{ "cover_roi_2_color_y", 0x00000048, 7, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_2_color_u", 0x00000048, 15, 8, CSR_RW, 0x00000000 },
	{ "cover_roi_2_color_v", 0x00000048, 23, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_2_COLOR", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_3_en
	{ "cover_roi_3_en", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_3_EN", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_3_start
	{ "cover_roi_3_sx", 0x00000050, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_3_sy", 0x00000050, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_3_START", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_3_end
	{ "cover_roi_3_ex", 0x00000054, 12, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_3_ey", 0x00000054, 28, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_3_END", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_cover_roi_3_color
	{ "cover_roi_3_color_y", 0x00000058, 7, 0, CSR_RW, 0x00000000 },
	{ "cover_roi_3_color_u", 0x00000058, 15, 8, CSR_RW, 0x00000000 },
	{ "cover_roi_3_color_v", 0x00000058, 23, 16, CSR_RW, 0x00000000 },
	{ "ENC_COVER_ROI_3_COLOR", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_reserved_1
	{ "reserved_1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	{ "ENC_RESERVED_1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD enc_reserved_2
	{ "reserved_2", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	{ "ENC_RESERVED_2", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ENC_H_
