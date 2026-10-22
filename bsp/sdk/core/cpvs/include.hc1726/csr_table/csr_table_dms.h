/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DMS_H_
#define CSR_TABLE_DMS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dms[] = {
	// WORD dms00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMS00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dms01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "DMS01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dms02
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "DMS02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD dms03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "DMS03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dms04
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000010, 31, 16, CSR_RW, 0x00000438 },
	{ "DMS04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD dms05
	{ "mode", 0x00000014, 1, 0, CSR_RW, 0x00000000 },
	{ "ini_bayer_phase", 0x00000014, 9, 8, CSR_RW, 0x00000000 },
	{ "debug_mon_sel", 0x00000014, 17, 16, CSR_RW, 0x00000000 },
	{ "DMS05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD dms06
	{ "g_var_gain", 0x00000018, 3, 0, CSR_RW, 0x0000000A },
	{ "fcs_threshold", 0x00000018, 12, 8, CSR_RW, 0x0000000D },
	{ "inter_conf_slope", 0x00000018, 21, 16, CSR_RW, 0x00000012 },
	{ "fcs_offset", 0x00000018, 28, 24, CSR_RW, 0x00000000 },
	{ "DMS06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD dms07
	{ "g_at_m_inter_ratio", 0x0000001C, 5, 0, CSR_RW, 0x00000013 },
	{ "m_at_m_inter_ratio", 0x0000001C, 13, 8, CSR_RW, 0x00000020 },
	{ "m_at_g_inter_ratio", 0x0000001C, 21, 16, CSR_RW, 0x00000020 },
	{ "DMS07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dms08
	{ "g_at_m_soft_clip_slope", 0x00000020, 4, 0, CSR_RW, 0x0000000C },
	{ "m_at_m_soft_clip_slope", 0x00000020, 12, 8, CSR_RW, 0x00000010 },
	{ "m_at_g_soft_clip_slope", 0x00000020, 20, 16, CSR_RW, 0x00000010 },
	{ "m_at_g_gradient_src_ratio", 0x00000020, 28, 24, CSR_RW, 0x00000004 },
	{ "DMS08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD dms09
	{ "reserved", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	{ "DMS09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DMS_H_
