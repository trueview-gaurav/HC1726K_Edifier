/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_FM_H_
#define CSR_TABLE_FM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_fm[] = {
	// WORD fm00
	{ "start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "FM00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD fm01
	{ "busy", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "done", 0x00000004, 16, 16, CSR_RO, 0x00000000 },
	{ "pass", 0x00000004, 31, 31, CSR_RO, 0x00000000 },
	{ "FM01", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD fm02
	{ "cnt_th", 0x00000008, 9, 0, CSR_RW, 0x00000000 },
	{ "FM02", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD fm03
	{ "target", 0x0000000C, 14, 0, CSR_RW, 0x00000000 },
	{ "tolerance", 0x0000000C, 23, 16, CSR_RW, 0x00000000 },
	{ "FM03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD fm04
	{ "clk_cnt", 0x00000010, 9, 0, CSR_RO, 0x00000000 },
	{ "meas_cnt", 0x00000010, 30, 16, CSR_RO, 0x00000000 },
	{ "FM04", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_FM_H_
