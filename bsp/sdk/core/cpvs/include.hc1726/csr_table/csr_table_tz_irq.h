/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_TZ_IRQ_H_
#define CSR_TABLE_TZ_IRQ_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_tz_irq[] = {
	// WORD irq_clear_0
	{ "irq_clear_write_error", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_read_error", 0x00000000, 1, 1, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR_0", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status_0
	{ "status_irq", 0x00000004, 1, 0, CSR_RO, 0x00000000 },
	{ "STATUS_0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask_0
	{ "irq_mask_write_error", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_read_error", 0x00000008, 1, 1, CSR_RW, 0x00000001 },
	{ "IRQ_MASK_0", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD write_addr
	{ "status_error_awaddr", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "WRITE_ADDR", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD read_addr
	{ "status_error_araddr", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "READ_ADDR", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_TZ_IRQ_H_
