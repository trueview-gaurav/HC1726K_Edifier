/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_MCVP_H_
#define CSR_TABLE_MCVP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_mcvp[] = {
	// WORD mcvp_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "MCVP000", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mcvp_irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "MCVP001", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mcvp_irq
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "MCVP002", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "MCVP003", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp_debug_mon_sel
	{ "debug_mon_sel", 0x00000010, 2, 0, CSR_RW, 0x00000000 },
	{ "MCVP004", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp_disable
	{ "disable_mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "MCVP005", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp006
	{ "frame_width_i", 0x00000018, 15, 0, CSR_RW, 0x00000000 },
	{ "frame_height", 0x00000018, 31, 16, CSR_RW, 0x00000000 },
	{ "MCVP006", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp007
	{ "most_left_tile", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "most_right_tile", 0x0000001C, 8, 8, CSR_RW, 0x00000000 },
	{ "MCVP007", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp008
	{ "write_ver_4_mv", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "padding_right_venc_mv_num", 0x00000020, 9, 8, CSR_RW, 0x00000000 },
	{ "padding_bottom_venc_mv_num", 0x00000020, 17, 16, CSR_RW, 0x00000000 },
	{ "mcvp_mono_mode", 0x00000020, 24, 24, CSR_RW, 0x00000000 },
	{ "MCVP008", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp009
	{ "r2b_left_skip_pel", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "r2b_out_blk_width", 0x00000024, 28, 16, CSR_RW, 0x00000000 },
	{ "MCVP009", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp010
	{ "me_out_blk_width", 0x00000028, 12, 0, CSR_RW, 0x00000000 },
	{ "me_out_blk_width_m1", 0x00000028, 28, 16, CSR_RW, 0x00000000 },
	{ "MCVP010", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp011
	{ "blk_height", 0x0000002C, 12, 0, CSR_RW, 0x00000000 },
	{ "blk_height_m1", 0x0000002C, 28, 16, CSR_RW, 0x00000000 },
	{ "MCVP011", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp012
	{ "sr_ix", 0x00000030, 6, 0, CSR_RW, 0x0000007C },
	{ "sr_iy", 0x00000030, 14, 8, CSR_RW, 0x00000044 },
	{ "sr_blk8_ix", 0x00000030, 20, 16, CSR_RW, 0x00000010 },
	{ "sr_blk8_iy", 0x00000030, 28, 24, CSR_RW, 0x00000009 },
	{ "MCVP012", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp013
	{ "yuv420_format", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "MCVP013", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD coring_0
	{ "chroma_coring_en", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "CORING_0", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD coring_1
	{ "coring_th", 0x0000003C, 9, 0, CSR_RW, 0x00000014 },
	{ "CORING_1", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD coring_2
	{ "coring_slope", 0x00000040, 15, 0, CSR_RW, 0x00000020 },
	{ "CORING_2", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD rounding_0
	{ "y_rounding_en", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "c_rounding_en", 0x00000044, 8, 8, CSR_RW, 0x00000000 },
	{ "c_adap_rounding", 0x00000044, 16, 16, CSR_RW, 0x00000000 },
	{ "atpg_ctrl", 0x00000044, 24, 24, CSR_RW, 0x00000000 },
	{ "ROUNDING_0", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_MCVP_H_
