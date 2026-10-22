/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AON_H_
#define CSR_TABLE_AON_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_aon[] = {
	// WORD ck_gen
	{ "cken_amc", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cken_misc", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "CK_GEN", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD rst_gen
	{ "lv_rst_amc", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "lv_rst_misc", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "RST_GEN", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD sleep_ctrl
	{ "sleep_pulse", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "SLEEP_CTRL", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD sleep_dly
	{ "sleep_dly_cnt", 0x0000000C, 7, 0, CSR_RW, 0x00000000 },
	{ "SLEEP_DLY", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rosc_ctrl
	{ "rosc_en", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "ROSC_CTRL", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD rosc_trim
	{ "rosc_div_th", 0x00000014, 7, 0, CSR_RW, 0x00000080 },
	{ "rosc_freqctrl", 0x00000014, 19, 16, CSR_RW, 0x00000008 },
	{ "ROSC_TRIM", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD rosc_write
	{ "trim_pulse", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "ROSC_WRITE", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD aon_status
	{ "uvlo_1v8_vsh", 0x0000001C, 0, 0, CSR_RO, 0x00000000 },
	{ "AON_STATUS", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD iso_en
	{ "scan_iso_en", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "ISO_EN", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AON_H_
