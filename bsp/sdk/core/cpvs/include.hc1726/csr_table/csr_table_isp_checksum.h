/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISP_CHECKSUM_H_
#define CSR_TABLE_ISP_CHECKSUM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_isp_checksum[] = {
	// WORD clr
	{ "clear", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ispin0
	{ "checksum_ispin0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPIN0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD ispin1
	{ "checksum_ispin1", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "ISPIN1", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD hdr
	{ "checksum_hdr", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "HDR", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD bld
	{ "checksum_bld", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "BLD", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD rgbp
	{ "checksum_rgbp", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "RGBP", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD nr2d0
	{ "checksum_nr2d_0", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "NR2D0", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD nr2d1
	{ "checksum_nr2d_1", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "NR2D1", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD ccm0
	{ "checksum_ccm_0", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "CCM0", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD ccm1
	{ "checksum_ccm_1", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "CCM1", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD pca
	{ "checksum_pca", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "PCA", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD shp
	{ "checksum_shp", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	{ "SHP", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD sc
	{ "checksum_sc", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "SC", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD cus
	{ "checksum_cus", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "CUS", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD cds
	{ "checksum_cds", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	{ "CDS", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISP_CHECKSUM_H_
