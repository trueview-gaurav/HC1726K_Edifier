/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_VP_CHECKSUM_H_
#define CSR_TABLE_VP_CHECKSUM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_vp_checksum[] = {
	// WORD clr
	{ "clear", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dhz
	{ "checksum_dhz", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	{ "DHZ", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_nr_disp0
	{ "checksum_mcvp_nr_disp_0", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "MCVP_NR_DISP0", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_nr_disp1
	{ "checksum_mcvp_nr_disp_1", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "MCVP_NR_DISP1", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_nr_disp2
	{ "checksum_mcvp_nr_disp_2", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "MCVP_NR_DISP2", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_nr_ink0
	{ "checksum_mcvp_nr_ink_0", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "MCVP_NR_INK0", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_nr_ink1
	{ "checksum_mcvp_nr_ink_1", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "MCVP_NR_INK1", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD mcvp_nr_ink2
	{ "checksum_mcvp_nr_ink_2", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "MCVP_NR_INK2", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD unpacker
	{ "checksum_unpacker", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "UNPACKER", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD b2r
	{ "checksum_b2r", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "B2R", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD vppup0
	{ "checksum_vppup0", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "VPPUP0", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD vppup1
	{ "checksum_vppup1", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	{ "VPPUP1", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD vplp
	{ "checksum_vplp", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "VPLP", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_VP_CHECKSUM_H_
