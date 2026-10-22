/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_WDT_STABLE_H_
#define CSR_TABLE_WDT_STABLE_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_wdt_stable[] = {
	// WORD wdt_active_reset_flag
	{ "rg_active_reset_flag", 0x00000000, 0, 0, CSR_RO, 0x00000000 },
	{ "WDT_ACTIVE_RESET_FLAG", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	// WORD wdt_active_reset_flag_clr
	{ "rg_clr_active_reset_flag", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "WDT_ACTIVE_RESET_FLAG_CLR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD wdt_lock_status
	{ "wdt_stable_lock", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "WDT_LOCK_STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD wdt_reset_cycle_ctrl
	{ "wdt_rst_cycle", 0x0000000C, 7, 0, CSR_RW, 0x00000009 },
	{ "WDT_RESET_CYCLE_CTRL", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_stable_reserved
	{ "rg_reserved", 0x00000010, 7, 0, CSR_RW, 0x00000000 },
	{ "WDT_STABLE_RESERVED", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_WDT_STABLE_H_
