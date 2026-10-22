/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_I2CS_H_
#define CSR_TABLE_I2CS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_i2cs[] = {
	// WORD i2cs01
	{ "irq_clear_wake_up", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "I2CS01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD i2cs02
	{ "status_wake_up", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "I2CS02", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD i2cs03
	{ "irq_mask_wake_up", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "I2CS03", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD i2cs04
	{ "idle", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "I2CS04", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD i2cs05
	{ "target_address", 0x00000014, 6, 0, CSR_RW, 0x0000003A },
	{ "scl_deglitch_th", 0x00000014, 15, 8, CSR_RW, 0x00000000 },
	{ "sda_deglitch_th", 0x00000014, 23, 16, CSR_RW, 0x00000000 },
	{ "trans_size", 0x00000014, 25, 24, CSR_RW, 0x00000002 },
	{ "I2CS05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD i2cs06
	{ "efuse_dis_i2c_slave_violation", 0x00000018, 0, 0, CSR_RO, 0x00000000 },
	{ "I2CS06", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD i2cs07
	{ "debug_mon_sel", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "I2CS07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD i2cs08
	{ "reserved", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	{ "I2CS08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_I2CS_H_
