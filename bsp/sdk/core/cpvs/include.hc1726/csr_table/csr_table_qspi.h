/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_QSPI_H_
#define CSR_TABLE_QSPI_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_qspi[] = {
	// WORD qspi_start
	{ "start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "QSPI_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD qspi_mem_wrapper
	{ "enable", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "sd", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "slp", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "QSPI_MEM_WRAPPER", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_irq_clear
	{ "irq_clear_spi_done", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_spi_dma_done", 0x00000008, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_error", 0x00000008, 6, 6, CSR_W1P, 0x00000000 },
	{ "irq_clear_tx_fifo_full", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_tx_fifo_empty", 0x00000008, 10, 10, CSR_W1P, 0x00000000 },
	{ "irq_clear_rx_fifo_full", 0x00000008, 12, 12, CSR_W1P, 0x00000000 },
	{ "irq_clear_rx_fifo_empty", 0x00000008, 14, 14, CSR_W1P, 0x00000000 },
	{ "QSPI_IRQ_CLEAR", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD qspi_irq_status
	{ "status_spi_done", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "status_spi_dma_done", 0x0000000C, 4, 4, CSR_RO, 0x00000000 },
	{ "status_error", 0x0000000C, 6, 6, CSR_RO, 0x00000000 },
	{ "status_tx_fifo_full", 0x0000000C, 8, 8, CSR_RO, 0x00000000 },
	{ "status_tx_fifo_empty", 0x0000000C, 10, 10, CSR_RO, 0x00000000 },
	{ "status_rx_fifo_full", 0x0000000C, 12, 12, CSR_RO, 0x00000000 },
	{ "status_rx_fifo_empty", 0x0000000C, 14, 14, CSR_RO, 0x00000000 },
	{ "QSPI_IRQ_STATUS", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD qspi_irq_mask
	{ "irq_mask_spi_done", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_spi_dma_done", 0x00000010, 4, 4, CSR_RW, 0x00000001 },
	{ "irq_mask_error", 0x00000010, 6, 6, CSR_RW, 0x00000001 },
	{ "irq_mask_tx_fifo_full", 0x00000010, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_tx_fifo_empty", 0x00000010, 10, 10, CSR_RW, 0x00000001 },
	{ "irq_mask_rx_fifo_full", 0x00000010, 12, 12, CSR_RW, 0x00000001 },
	{ "irq_mask_rx_fifo_empty", 0x00000010, 14, 14, CSR_RW, 0x00000001 },
	{ "QSPI_IRQ_MASK", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_status
	{ "spi_busy", 0x00000014, 0, 0, CSR_RO, 0x00000000 },
	{ "spi_done", 0x00000014, 2, 2, CSR_RO, 0x00000000 },
	{ "error", 0x00000014, 4, 4, CSR_RO, 0x00000000 },
	{ "tx_fifo_full", 0x00000014, 6, 6, CSR_RO, 0x00000000 },
	{ "tx_fifo_empty", 0x00000014, 8, 8, CSR_RO, 0x00000000 },
	{ "rx_fifo_full", 0x00000014, 10, 10, CSR_RO, 0x00000000 },
	{ "rx_fifo_empty", 0x00000014, 12, 12, CSR_RO, 0x00000000 },
	{ "QSPI_STATUS", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD qspi_mst_status
	{ "mst_state", 0x00000018, 2, 0, CSR_RO, 0x00000000 },
	{ "cnt_frame", 0x00000018, 29, 8, CSR_RO, 0x00000000 },
	{ "QSPI_MST_STATUS", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD qspi_trans_ctrl_0
	{ "transfer_mode", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "transfer_type", 0x0000001C, 9, 8, CSR_RW, 0x00000000 },
	{ "dma_mode_en", 0x0000001C, 16, 16, CSR_RW, 0x00000000 },
	{ "frame_format", 0x0000001C, 25, 24, CSR_RW, 0x00000000 },
	{ "QSPI_TRANS_CTRL_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_trans_ctrl_1
	{ "msb_first", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "endian_sel", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "QSPI_TRANS_CTRL_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_data_format
	{ "inst_l", 0x00000024, 1, 0, CSR_RW, 0x00000002 },
	{ "addr_l", 0x00000024, 11, 8, CSR_RW, 0x00000004 },
	{ "wait_l", 0x00000024, 21, 16, CSR_RW, 0x00000008 },
	{ "data_frame_size", 0x00000024, 28, 24, CSR_RW, 0x0000001F },
	{ "QSPI_DATA_FORMAT", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_data_size
	{ "ndf", 0x00000028, 21, 0, CSR_RW, 0x00000000 },
	{ "QSPI_DATA_SIZE", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_delay
	{ "wr_cycle", 0x0000002C, 2, 0, CSR_RW, 0x00000007 },
	{ "rd_cycle", 0x0000002C, 10, 8, CSR_RW, 0x00000007 },
	{ "QSPI_DELAY", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_sck_ctrl
	{ "sck_dv", 0x00000030, 7, 0, CSR_RW, 0x00000000 },
	{ "sck_pol", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "sck_pha", 0x00000030, 10, 10, CSR_RW, 0x00000000 },
	{ "sck_phase_sel", 0x00000030, 17, 16, CSR_RW, 0x00000000 },
	{ "sck_dly", 0x00000030, 31, 24, CSR_RW, 0x00000000 },
	{ "QSPI_SCK_CTRL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_rx_clk_ctrl
	{ "rx_delay", 0x00000034, 3, 0, CSR_RW, 0x00000000 },
	{ "rx_smpl_phase_sel", 0x00000034, 8, 8, CSR_RW, 0x00000001 },
	{ "QSPI_RX_CLK_CTRL", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_wr_data
	{ "wr_data", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "QSPI_WR_DATA", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_rd_data
	{ "rd_data", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	{ "QSPI_RD_DATA", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD qspi_rd_data_inv
	{ "rd_data_inv", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "QSPI_RD_DATA_INV", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD qspi_kernel_clk_bypass
	{ "kernel_clk_bypass", 0x00000044, 0, 0, CSR_RW, 0x00000001 },
	{ "QSPI_KERNEL_CLK_BYPASS", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_sck_gating_func_ctrl
	{ "sck_wr_state_gating_en", 0x00000048, 0, 0, CSR_RW, 0x00000001 },
	{ "sck_rd_state_gating_en", 0x00000048, 8, 8, CSR_RW, 0x00000001 },
	{ "QSPI_SCK_GATING_FUNC_CTRL", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD qspi_debug_mon_sel
	{ "debug_mon_sel", 0x0000004C, 1, 0, CSR_RW, 0x00000000 },
	{ "QSPI_DEBUG_MON_SEL", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_QSPI_H_
