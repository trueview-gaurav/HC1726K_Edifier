/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PERI_H_
#define CSR_TABLE_PERI_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_peri[] = {
	// WORD uart_md
	{ "uart0_mode_sel", 0x00000000, 1, 0, CSR_RW, 0x00000000 },
	{ "uart1_mode_sel", 0x00000000, 9, 8, CSR_RW, 0x00000000 },
	{ "uart2_mode_sel", 0x00000000, 17, 16, CSR_RW, 0x00000000 },
	{ "UART_MD", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD uart_dbug
	{ "uart0_debug_sel", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "uart1_debug_sel", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "uart2_debug_sel", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "UART_DBUG", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD peri_dbug
	{ "debug_sel", 0x00000008, 2, 0, CSR_RW, 0x00000000 },
	{ "PERI_DBUG", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PERI_H_
