/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DARB_SECURE_H_
#define CSR_TABLE_DARB_SECURE_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_darb_secure[] = {
	// WORD read_secure
	{ "secure_r_00", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "secure_r_01", 0x00000000, 1, 1, CSR_RW, 0x00000000 },
	{ "secure_r_02", 0x00000000, 2, 2, CSR_RW, 0x00000000 },
	{ "secure_r_03", 0x00000000, 3, 3, CSR_RW, 0x00000000 },
	{ "secure_r_04", 0x00000000, 4, 4, CSR_RW, 0x00000000 },
	{ "secure_r_05", 0x00000000, 5, 5, CSR_RW, 0x00000000 },
	{ "secure_r_06", 0x00000000, 6, 6, CSR_RW, 0x00000000 },
	{ "secure_r_07", 0x00000000, 7, 7, CSR_RW, 0x00000000 },
	{ "secure_r_08", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "secure_r_09", 0x00000000, 9, 9, CSR_RW, 0x00000000 },
	{ "secure_r_10", 0x00000000, 10, 10, CSR_RW, 0x00000000 },
	{ "secure_r_11", 0x00000000, 11, 11, CSR_RW, 0x00000000 },
	{ "secure_r_12", 0x00000000, 12, 12, CSR_RW, 0x00000000 },
	{ "secure_r_13", 0x00000000, 13, 13, CSR_RW, 0x00000000 },
	{ "secure_r_14", 0x00000000, 14, 14, CSR_RW, 0x00000000 },
	{ "secure_r_15", 0x00000000, 15, 15, CSR_RW, 0x00000000 },
	{ "secure_r_16", 0x00000000, 16, 16, CSR_RW, 0x00000000 },
	{ "secure_r_17", 0x00000000, 17, 17, CSR_RW, 0x00000000 },
	{ "secure_r_18", 0x00000000, 18, 18, CSR_RW, 0x00000000 },
	{ "secure_r_19", 0x00000000, 19, 19, CSR_RW, 0x00000000 },
	{ "secure_r_20", 0x00000000, 20, 20, CSR_RW, 0x00000000 },
	{ "secure_r_21", 0x00000000, 21, 21, CSR_RW, 0x00000000 },
	{ "secure_r_22", 0x00000000, 22, 22, CSR_RW, 0x00000000 },
	{ "secure_r_23", 0x00000000, 23, 23, CSR_RW, 0x00000000 },
	{ "secure_r_24", 0x00000000, 24, 24, CSR_RW, 0x00000000 },
	{ "secure_r_25", 0x00000000, 25, 25, CSR_RW, 0x00000000 },
	{ "secure_r_26", 0x00000000, 26, 26, CSR_RW, 0x00000000 },
	{ "secure_r_27", 0x00000000, 27, 27, CSR_RW, 0x00000000 },
	{ "secure_r_28", 0x00000000, 28, 28, CSR_RW, 0x00000000 },
	{ "secure_r_29", 0x00000000, 29, 29, CSR_RW, 0x00000000 },
	{ "secure_r_30", 0x00000000, 30, 30, CSR_RW, 0x00000000 },
	{ "secure_r_31", 0x00000000, 31, 31, CSR_RW, 0x00000000 },
	{ "READ_SECURE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD write_secure
	{ "secure_w_00", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "secure_w_01", 0x00000004, 1, 1, CSR_RW, 0x00000000 },
	{ "secure_w_02", 0x00000004, 2, 2, CSR_RW, 0x00000000 },
	{ "secure_w_03", 0x00000004, 3, 3, CSR_RW, 0x00000000 },
	{ "secure_w_04", 0x00000004, 4, 4, CSR_RW, 0x00000000 },
	{ "secure_w_05", 0x00000004, 5, 5, CSR_RW, 0x00000000 },
	{ "secure_w_06", 0x00000004, 6, 6, CSR_RW, 0x00000000 },
	{ "secure_w_07", 0x00000004, 7, 7, CSR_RW, 0x00000000 },
	{ "secure_w_08", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "secure_w_09", 0x00000004, 9, 9, CSR_RW, 0x00000000 },
	{ "secure_w_10", 0x00000004, 10, 10, CSR_RW, 0x00000000 },
	{ "secure_w_11", 0x00000004, 11, 11, CSR_RW, 0x00000000 },
	{ "secure_w_12", 0x00000004, 12, 12, CSR_RW, 0x00000000 },
	{ "secure_w_13", 0x00000004, 13, 13, CSR_RW, 0x00000000 },
	{ "secure_w_14", 0x00000004, 14, 14, CSR_RW, 0x00000000 },
	{ "secure_w_15", 0x00000004, 15, 15, CSR_RW, 0x00000000 },
	{ "secure_w_16", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "secure_w_17", 0x00000004, 17, 17, CSR_RW, 0x00000000 },
	{ "secure_w_18", 0x00000004, 18, 18, CSR_RW, 0x00000000 },
	{ "secure_w_19", 0x00000004, 19, 19, CSR_RW, 0x00000000 },
	{ "secure_w_20", 0x00000004, 20, 20, CSR_RW, 0x00000000 },
	{ "secure_w_21", 0x00000004, 21, 21, CSR_RW, 0x00000000 },
	{ "secure_w_22", 0x00000004, 22, 22, CSR_RW, 0x00000000 },
	{ "secure_w_23", 0x00000004, 23, 23, CSR_RW, 0x00000000 },
	{ "secure_w_24", 0x00000004, 24, 24, CSR_RW, 0x00000000 },
	{ "secure_w_25", 0x00000004, 25, 25, CSR_RW, 0x00000000 },
	{ "secure_w_26", 0x00000004, 26, 26, CSR_RW, 0x00000000 },
	{ "secure_w_27", 0x00000004, 27, 27, CSR_RW, 0x00000000 },
	{ "secure_w_28", 0x00000004, 28, 28, CSR_RW, 0x00000000 },
	{ "secure_w_29", 0x00000004, 29, 29, CSR_RW, 0x00000000 },
	{ "secure_w_30", 0x00000004, 30, 30, CSR_RW, 0x00000000 },
	{ "secure_w_31", 0x00000004, 31, 31, CSR_RW, 0x00000000 },
	{ "WRITE_SECURE", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DARB_SECURE_H_
