/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_WDT_H_
#define CSR_TABLE_WDT_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_wdt[] = {
	// WORD wdt_trigger
	{ "trigger", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WDT_TRIGGER", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clr
	{ "irq_clear_wdt", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status
	{ "status_wdt", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD wdt_status
	{ "lock_status", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "stage", 0x0000000C, 9, 8, CSR_RO, 0x00000000 },
	{ "count_value", 0x0000000C, 31, 16, CSR_RO, 0x00000000 },
	{ "WDT_STATUS", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD wdt_unlock
	{ "unlock_reg", 0x00000010, 7, 0, CSR_RW, 0x00000000 },
	{ "WDT_UNLOCK", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_ctrl
	{ "sw_disable", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "active_timeout_reset", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "prescaler", 0x00000014, 19, 16, CSR_RW, 0x0000000F },
	{ "wdt_pad_rst_en", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "WDT_CTRL", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_cnt_th_init
	{ "count_init", 0x00000018, 15, 0, CSR_RW, 0x000055D5 },
	{ "WDT_CNT_TH_INIT", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_cnt_th_normal
	{ "count_normal_min", 0x0000001C, 15, 0, CSR_RW, 0x00001C9C },
	{ "count_normal_max", 0x0000001C, 31, 16, CSR_RW, 0x000055D5 },
	{ "WDT_CNT_TH_NORMAL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_cnt_th_timeout
	{ "count_timeout_1", 0x00000020, 14, 0, CSR_RW, 0x000005B8 },
	{ "count_timeout_2", 0x00000020, 30, 16, CSR_RW, 0x000002DC },
	{ "WDT_CNT_TH_TIMEOUT", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdt_reserved
	{ "reserved", 0x00000024, 7, 0, CSR_RW, 0x00000000 },
	{ "WDT_RESERVED", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_WDT_H_
