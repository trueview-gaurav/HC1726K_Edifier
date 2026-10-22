/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DWB2R_H_
#define CSR_TABLE_DWB2R_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dwb2r[] = {
	// WORD dwb2r000
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "DWB2R000", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dwb2r001
	{ "y_block_h_num", 0x00000004, 5, 0, CSR_RW, 0x00000020 },
	{ "y_block_v_num", 0x00000004, 27, 16, CSR_RW, 0x00000020 },
	{ "DWB2R001", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD dwb2r002
	{ "c_block_h_num", 0x00000008, 5, 0, CSR_RW, 0x00000020 },
	{ "c_block_v_num", 0x00000008, 27, 16, CSR_RW, 0x00000020 },
	{ "DWB2R002", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD dwb2r003
	{ "irq_clear_frame_end", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "DWB2R003", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dwb2r004
	{ "status_frame_end", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "DWB2R004", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD dwb2r005
	{ "irq_mask_frame_end", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "DWB2R005", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DWB2R_H_
