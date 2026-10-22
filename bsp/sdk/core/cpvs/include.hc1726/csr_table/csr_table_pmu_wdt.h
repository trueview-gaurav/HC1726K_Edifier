/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PMU_WDT_H_
#define CSR_TABLE_PMU_WDT_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pmu_wdt[] = {
	// WORD wdt_trigger
	{ "trigger", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WDT_TRIGGER", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD clear
	{ "pmu_wdt_state_clear", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "aon_wdt_state_clear", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ctrl
	{ "pmu_wdt_csr_en", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "aon_wdt_timeout_en", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "CTRL", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD period
	{ "cnt_th", 0x0000000C, 15, 0, CSR_RW, 0x00000020 },
	{ "rst_cnt_th", 0x0000000C, 31, 16, CSR_RW, 0x000007D0 },
	{ "PERIOD", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD state
	{ "pmu_wdt_state", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "aon_wdt_state", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "STATE", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD amc_ctrl
	{ "shutdown_reset_en", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "shutdown_power_off_en", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "autobootup_en", 0x00000014, 16, 16, CSR_RW, 0x00000001 },
	{ "AMC_CTRL", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PMU_WDT_H_
