/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ADOOUT_SYSCFG_H_
#define CSR_TABLE_ADOOUT_SYSCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_adoout_syscfg[] = {
	// WORD conf_adac_l0
	{ "cken_adac", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_adac", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "CONF_ADAC_L0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD conf_adac_l1
	{ "sw_rst_adac", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "csr_rst_adac", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "CONF_ADAC_L1", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD conf_dec0
	{ "cken_dec", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_dec", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "CONF_DEC0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD conf_dec1
	{ "sw_rst_dec", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "csr_rst_dec", 0x0000000C, 8, 8, CSR_W1P, 0x00000000 },
	{ "CONF_DEC1", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD conf_i2s0
	{ "cken_i2s", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_i2s", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "CONF_I2S0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD conf_i2s1
	{ "sw_rst_i2s", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "csr_rst_i2s", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "CONF_I2S1", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD conf_read0
	{ "cken_read", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "lv_rst_read", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "CONF_READ0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD conf_read1
	{ "sw_rst_read", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "csr_rst_read", 0x0000001C, 8, 8, CSR_W1P, 0x00000000 },
	{ "CONF_READ1", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ADOOUT_SYSCFG_H_
