/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CK_APB1_H_
#define CSR_TABLE_CK_APB1_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ck_apb1[] = {
	// WORD hw_ckg_apb1
	{ "dis_cg_apb_1", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "cg_delay_m1_apb_1", 0x00000000, 10, 8, CSR_RW, 0x00000002 },
	{ "HW_CKG_APB1", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CK_APB1_H_
