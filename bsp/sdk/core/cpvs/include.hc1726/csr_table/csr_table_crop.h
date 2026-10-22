/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CROP_H_
#define CSR_TABLE_CROP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_crop[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD resolution
	{ "width", 0x00000004, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000004, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_x
	{ "crop_left", 0x00000008, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_right", 0x00000008, 31, 16, CSR_RW, 0x0000077F },
	{ "CROP_X", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_y
	{ "crop_up", 0x0000000C, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_down", 0x0000000C, 31, 16, CSR_RW, 0x00000437 },
	{ "CROP_Y", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CROP_H_
