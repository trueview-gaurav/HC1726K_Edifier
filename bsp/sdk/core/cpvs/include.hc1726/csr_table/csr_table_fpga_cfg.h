/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_FPGA_CFG_H_
#define CSR_TABLE_FPGA_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_fpga_cfg[] = {
	// WORD reserve
	{ "reverse_word", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	{ "RESERVE", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_fpga_dbg0_iosel
	{ "fpga_dbg0_iosel", 0x00000004, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_FPGA_DBG0_IOSEL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg1_iosel
	{ "fpga_dbg1_iosel", 0x00000008, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_FPGA_DBG1_IOSEL", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg2_iosel
	{ "fpga_dbg2_iosel", 0x0000000C, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_FPGA_DBG2_IOSEL", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg3_iosel
	{ "fpga_dbg3_iosel", 0x00000010, 1, 0, CSR_RW, 0x00000001 },
	{ "WORD_FPGA_DBG3_IOSEL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg4_iosel
	{ "fpga_dbg4_iosel", 0x00000014, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG4_IOSEL", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg5_iosel
	{ "fpga_dbg5_iosel", 0x00000018, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG5_IOSEL", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg6_iosel
	{ "fpga_dbg6_iosel", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG6_IOSEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg7_iosel
	{ "fpga_dbg7_iosel", 0x00000020, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG7_IOSEL", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg8_iosel
	{ "fpga_dbg8_iosel", 0x00000024, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG8_IOSEL", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg9_iosel
	{ "fpga_dbg9_iosel", 0x00000028, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG9_IOSEL", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg10_iosel
	{ "fpga_dbg10_iosel", 0x0000002C, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG10_IOSEL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg11_iosel
	{ "fpga_dbg11_iosel", 0x00000030, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG11_IOSEL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_fpga_dbg12_iosel
	{ "fpga_dbg12_iosel", 0x00000034, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_FPGA_DBG12_IOSEL", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_FPGA_CFG_H_
