/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CPU_CFG_H_
#define CSR_TABLE_CPU_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_cpu_cfg[] = {
	// WORD word_cfg
	{ "cp15sdisable", 0x00000000, 1, 0, CSR_RW, 0x00000000 },
	{ "cfgsdisable", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "spiden", 0x00000000, 17, 16, CSR_RW, 0x00000003 },
	{ "WORD_CFG", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_dbg_sel
	{ "debug_mon_sel", 0x00000004, 6, 0, CSR_RW, 0x00000000 },
	{ "WORD_DBG_SEL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_dbg_mon
	{ "debug_mon", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "WORD_DBG_MON", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CPU_CFG_H_
