/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AXIQOS_H_
#define CSR_TABLE_AXIQOS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_axiqos[] = {
	// WORD update
	{ "awqos_upd", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "arqos_upd", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "UPDATE", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD wfbd
	{ "awid_forbid", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	{ "WFBD", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfbd
	{ "arid_forbid", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	{ "RFBD", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdet
	{ "awid_detect", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "WDET", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD rdet
	{ "arid_detect", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "RDET", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD werr
	{ "awid_error", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "WERR", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD rerr
	{ "arid_error", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "RERR", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD wmap0
	{ "awqos_id_0", 0x00000020, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_1", 0x00000020, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_2", 0x00000020, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_3", 0x00000020, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap1
	{ "awqos_id_4", 0x00000024, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_5", 0x00000024, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_6", 0x00000024, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_7", 0x00000024, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap2
	{ "awqos_id_8", 0x00000028, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_9", 0x00000028, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_10", 0x00000028, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_11", 0x00000028, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP2", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap3
	{ "awqos_id_12", 0x0000002C, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_13", 0x0000002C, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_14", 0x0000002C, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_15", 0x0000002C, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP3", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap4
	{ "awqos_id_16", 0x00000030, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_17", 0x00000030, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_18", 0x00000030, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_19", 0x00000030, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP4", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap5
	{ "awqos_id_20", 0x00000034, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_21", 0x00000034, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_22", 0x00000034, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_23", 0x00000034, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP5", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap6
	{ "awqos_id_24", 0x00000038, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_25", 0x00000038, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_26", 0x00000038, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_27", 0x00000038, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP6", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD wmap7
	{ "awqos_id_28", 0x0000003C, 3, 0, CSR_RW, 0x00000000 },
	{ "awqos_id_29", 0x0000003C, 11, 8, CSR_RW, 0x00000000 },
	{ "awqos_id_30", 0x0000003C, 19, 16, CSR_RW, 0x00000000 },
	{ "awqos_id_31", 0x0000003C, 27, 24, CSR_RW, 0x00000000 },
	{ "WMAP7", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap0
	{ "arqos_id_0", 0x00000040, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_1", 0x00000040, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_2", 0x00000040, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_3", 0x00000040, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP0", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap1
	{ "arqos_id_4", 0x00000044, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_5", 0x00000044, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_6", 0x00000044, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_7", 0x00000044, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP1", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap2
	{ "arqos_id_8", 0x00000048, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_9", 0x00000048, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_10", 0x00000048, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_11", 0x00000048, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP2", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap3
	{ "arqos_id_12", 0x0000004C, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_13", 0x0000004C, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_14", 0x0000004C, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_15", 0x0000004C, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP3", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap4
	{ "arqos_id_16", 0x00000050, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_17", 0x00000050, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_18", 0x00000050, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_19", 0x00000050, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP4", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap5
	{ "arqos_id_20", 0x00000054, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_21", 0x00000054, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_22", 0x00000054, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_23", 0x00000054, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP5", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap6
	{ "arqos_id_24", 0x00000058, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_25", 0x00000058, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_26", 0x00000058, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_27", 0x00000058, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP6", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD rmap7
	{ "arqos_id_28", 0x0000005C, 3, 0, CSR_RW, 0x00000000 },
	{ "arqos_id_29", 0x0000005C, 11, 8, CSR_RW, 0x00000000 },
	{ "arqos_id_30", 0x0000005C, 19, 16, CSR_RW, 0x00000000 },
	{ "arqos_id_31", 0x0000005C, 27, 24, CSR_RW, 0x00000000 },
	{ "RMAP7", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AXIQOS_H_
