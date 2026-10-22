/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SPI_SLAVE_H_
#define CSR_TABLE_SPI_SLAVE_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_spi_slave[] = {
	// WORD spi_slave_ip
	{ "spi_slave", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "SPI_SLAVE_IP", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SPI_SLAVE_H_
