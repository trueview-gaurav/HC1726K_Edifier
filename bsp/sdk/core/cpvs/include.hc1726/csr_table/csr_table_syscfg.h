/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SYSCFG_H_
#define CSR_TABLE_SYSCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_syscfg[] = {
	// WORD word_chip_id
	{ "chip_id", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	{ "WORD_CHIP_ID", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_chip_version
	{ "chip_version", 0x00000004, 7, 0, CSR_RO, 0x00000000 },
	{ "WORD_CHIP_VERSION", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_bootstrap
	{ "bootstrap", 0x00000008, 2, 0, CSR_RO, 0x00000000 },
	{ "WORD_BOOTSTRAP", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD version
	{ "hardware_version", 0x0000000C, 15, 0, CSR_RO, 0x00000000 },
	{ "software_version", 0x0000000C, 31, 16, CSR_RO, 0x00000000 },
	{ "VERSION", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD boot_status
	{ "boot_ctrl", 0x00000010, 15, 0, CSR_RO, 0x00000000 },
	{ "BOOT_STATUS", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD boot_addr
	{ "sec_boot_addr", 0x00000014, 31, 0, CSR_RW, 0xFFFF0004 },
	{ "BOOT_ADDR", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD hresize
	{ "hresize_sdc_0_csr", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "hresize_sdc_1_csr", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "hresize_usb_csr", 0x00000018, 16, 16, CSR_RW, 0x00000001 },
	{ "HRESIZE", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_mon_set
	{ "debug_mon_sel", 0x0000001C, 4, 0, CSR_RW, 0x00000000 },
	{ "debug_mon_rev", 0x0000001C, 8, 8, CSR_RW, 0x00000000 },
	{ "DEBUG_MON_SET", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon
	{ "debug_mon", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "WORD_DEBUG_MON", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD test_mon
	{ "test_mon_0", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "TEST_MON", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD tc_mode
	{ "testchip_mode", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "TC_MODE", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD pmu_en
	{ "pmu_apb_read_en", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "pmu_apb_write_en", 0x0000002C, 8, 8, CSR_RW, 0x00000000 },
	{ "pmu_irq_en", 0x0000002C, 16, 16, CSR_RW, 0x00000000 },
	{ "pmu_gpio_i_en", 0x0000002C, 24, 24, CSR_RW, 0x00000000 },
	{ "PMU_EN", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hw_strap
	{ "normal_mode", 0x00000030, 0, 0, CSR_RO, 0x00000000 },
	{ "fnct_mode", 0x00000030, 1, 1, CSR_RO, 0x00000000 },
	{ "dc_scan_mode", 0x00000030, 2, 2, CSR_RO, 0x00000000 },
	{ "ac_scan_mode", 0x00000030, 3, 3, CSR_RO, 0x00000000 },
	{ "mbist_mode", 0x00000030, 4, 4, CSR_RO, 0x00000000 },
	{ "bsd_mode", 0x00000030, 5, 5, CSR_RO, 0x00000000 },
	{ "HW_STRAP", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SYSCFG_H_
