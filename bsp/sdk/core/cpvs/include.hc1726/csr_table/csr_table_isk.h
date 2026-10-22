/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISK_H_
#define CSR_TABLE_ISK_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_isk[] = {
	// WORD fgma_mode
	{ "bsp_fgma_mode", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "FGMA_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD src01_broadcast
	{ "src1_broadcast_to_cvs_enable", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "src1_broadcast_to_cs_enable", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "SRC01_BROADCAST", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD fpnr_broadcast
	{ "fpnr_broadcast_to_bls_enable", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "fpnr_broadcast_to_crop_enable", 0x00000008, 8, 8, CSR_RW, 0x00000001 },
	{ "FPNR_BROADCAST", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_broadcast
	{ "crop_broadcast_to_out_enable", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "crop_broadcast_to_dbc_enable", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "CROP_BROADCAST", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bsp_broadcast
	{ "bsp_broadcast_to_out_enable", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "bsp_broadcast_to_fgma_enable", 0x00000010, 8, 8, CSR_RW, 0x00000001 },
	{ "BSP_BROADCAST", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD fgma_broadcast
	{ "fgma_broadcast_to_out_enable", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "fgma_broadcast_to_fsc_enable", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "FGMA_BROADCAST", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD bsp_mux
	{ "bsp_cvs_cs_mux_sel", 0x00000018, 1, 0, CSR_RW, 0x00000000 },
	{ "BSP_MUX", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD buf_update
	{ "double_buf_update", 0x0000001C, 0, 0, CSR_W1P, 0x00000000 },
	{ "BUF_UPDATE", 0x0000001C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD isk_ack_not0
	{ "src1_broadcast_ack_not_sel", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "fpnr_broadcast_ack_not_sel", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "crop_broadcast_ack_not_sel", 0x00000020, 16, 16, CSR_RW, 0x00000000 },
	{ "ISK_ACK_NOT0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD isk_ack_not1
	{ "bsp_broadcast_ack_not_sel", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "fgma_broadcast_ack_not_sel", 0x00000024, 8, 8, CSR_RW, 0x00000000 },
	{ "ISK_ACK_NOT1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISK_H_
