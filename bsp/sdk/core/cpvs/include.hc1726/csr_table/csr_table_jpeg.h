/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_JPEG_H_
#define CSR_TABLE_JPEG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_jpeg[] = {
	// WORD jpeg00
	{ "frm_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "JPEG00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD jpeg01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "JPEG01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD jpeg02
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "JPEG02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD jpeg03
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "JPEG03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg04
	{ "jpeg_enc_format", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "JPEG04", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg05
	{ "frm_width", 0x00000014, 15, 0, CSR_RW, 0x00000400 },
	{ "frm_height", 0x00000014, 31, 16, CSR_RW, 0x00000300 },
	{ "JPEG05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg06
	{ "frm_mcu_hor_num_m1", 0x00000018, 12, 0, CSR_RW, 0x0000003F },
	{ "frm_mcu_ver_num_m1", 0x00000018, 28, 16, CSR_RW, 0x0000005F },
	{ "JPEG06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg07
	{ "quality", 0x0000001C, 6, 0, CSR_RW, 0x00000032 },
	{ "JPEG07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg08
	{ "q_table_sr_en", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "JPEG08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg09
	{ "q_table_sr_addr", 0x00000024, 5, 0, CSR_RW, 0x00000000 },
	{ "JPEG09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg10
	{ "q_table_sr_data_0", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "JPEG10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg11
	{ "q_table_sr_data_1", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "JPEG11", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg12
	{ "q_table_sr_data_2", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	{ "JPEG12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg13
	{ "q_table_sr_data_3", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	{ "JPEG13", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg14
	{ "reserved_0", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "JPEG14", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg15
	{ "reserved_1", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	{ "JPEG15", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD jpeg16
	{ "debug_mon_reg", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "JPEG16", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD jpeg17
	{ "frame_bs_byte_length", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	{ "JPEG17", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_JPEG_H_
