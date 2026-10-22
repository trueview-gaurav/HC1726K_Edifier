/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DMA_H_
#define CSR_TABLE_DMA_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dma[] = {
	// WORD dmar_brct
	{ "dmar_broadcast_to_dmaw", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "dmar_broadcast_to_lli", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "DMAR_BRCT", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD dmar_brct_not_sel
	{ "dmar_broadcast_ack_not_sel", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "DMAR_BRCT_NOT_SEL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD dma_debug_mon
	{ "dma_debug_mon_sel", 0x00000008, 1, 0, CSR_RW, 0x00000000 },
	{ "DMA_DEBUG_MON", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_axi_r_status_0
	{ "debug_arsize", 0x0000000C, 2, 0, CSR_RO, 0x00000000 },
	{ "debug_arlen", 0x0000000C, 11, 8, CSR_RO, 0x00000000 },
	{ "debug_araddr_bank", 0x0000000C, 18, 16, CSR_RO, 0x00000000 },
	{ "debug_araddr_word", 0x0000000C, 26, 24, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_R_STATUS_0", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_r_status_1
	{ "debug_araddr_row", 0x00000010, 15, 0, CSR_RO, 0x00000000 },
	{ "debug_araddr_col", 0x00000010, 24, 16, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_R_STATUS_1", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_r_status_2
	{ "debug_rdata_b31_0", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_R_STATUS_2", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_r_status_3
	{ "debug_rdata_b63_32", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_R_STATUS_3", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_w_status_0
	{ "debug_awsize", 0x0000001C, 2, 0, CSR_RO, 0x00000000 },
	{ "debug_awlen", 0x0000001C, 11, 8, CSR_RO, 0x00000000 },
	{ "debug_awaddr_bank", 0x0000001C, 18, 16, CSR_RO, 0x00000000 },
	{ "debug_awaddr_word", 0x0000001C, 26, 24, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_W_STATUS_0", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_w_status_1
	{ "debug_awaddr_row", 0x00000020, 15, 0, CSR_RO, 0x00000000 },
	{ "debug_awaddr_col", 0x00000020, 24, 16, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_W_STATUS_1", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_w_status_2
	{ "debug_wdata_b31_0", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_W_STATUS_2", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_axi_w_status_3
	{ "debug_wdata_b63_32", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_AXI_W_STATUS_3", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD resv
	{ "reserved", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "RESV", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DMA_H_
