/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_EMAC_H_
#define CSR_TABLE_EMAC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_emac[] = {
	// WORD emac_ip00
	{ "emac_ip", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "EMAC_IP00", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_EMAC_H_
