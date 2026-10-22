/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_QSPI_H_
#define CSR_BANK_QSPI_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from qspi  ***/
typedef struct csr_bank_qspi {
	/* QSPI_START 16'h00 */
	union {
		uint32_t qspi_start; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_MEM_WRAPPER 16'h04 */
	union {
		uint32_t qspi_mem_wrapper; // word name
		struct {
			uint32_t enable : 1;
			uint32_t : 7; // padding bits
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_IRQ_CLEAR 16'h08 */
	union {
		uint32_t qspi_irq_clear; // word name
		struct {
			uint32_t irq_clear_spi_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_spi_dma_done : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_error : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_tx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_tx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_rx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_rx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_IRQ_STATUS 16'h0C */
	union {
		uint32_t qspi_irq_status; // word name
		struct {
			uint32_t status_spi_done : 1;
			uint32_t : 3; // padding bits
			uint32_t status_spi_dma_done : 1;
			uint32_t : 1; // padding bits
			uint32_t status_error : 1;
			uint32_t : 1; // padding bits
			uint32_t status_tx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t status_tx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t status_rx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t status_rx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_IRQ_MASK 16'h10 */
	union {
		uint32_t qspi_irq_mask; // word name
		struct {
			uint32_t irq_mask_spi_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_spi_dma_done : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_error : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_tx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_tx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_rx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_rx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_STATUS 16'h14 */
	union {
		uint32_t qspi_status; // word name
		struct {
			uint32_t spi_busy : 1;
			uint32_t : 1; // padding bits
			uint32_t spi_done : 1;
			uint32_t : 1; // padding bits
			uint32_t error : 1;
			uint32_t : 1; // padding bits
			uint32_t tx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t tx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t rx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t rx_fifo_empty : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_MST_STATUS 16'h18 */
	union {
		uint32_t qspi_mst_status; // word name
		struct {
			uint32_t mst_state : 3;
			uint32_t : 5; // padding bits
			uint32_t cnt_frame : 22;
			uint32_t : 2; // padding bits
		};
	};
	/* QSPI_TRANS_CTRL_0 16'h1C */
	union {
		uint32_t qspi_trans_ctrl_0; // word name
		struct {
			uint32_t transfer_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t transfer_type : 2;
			uint32_t : 6; // padding bits
			uint32_t dma_mode_en : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* QSPI_TRANS_CTRL_1 16'h20 */
	union {
		uint32_t qspi_trans_ctrl_1; // word name
		struct {
			uint32_t msb_first : 1;
			uint32_t : 7; // padding bits
			uint32_t endian_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_DATA_FORMAT 16'h24 */
	union {
		uint32_t qspi_data_format; // word name
		struct {
			uint32_t inst_l : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l : 6;
			uint32_t : 2; // padding bits
			uint32_t data_frame_size : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI_DATA_SIZE 16'h28 */
	union {
		uint32_t qspi_data_size; // word name
		struct {
			uint32_t ndf : 22;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_DELAY 16'h2C */
	union {
		uint32_t qspi_delay; // word name
		struct {
			uint32_t wr_cycle : 3;
			uint32_t : 5; // padding bits
			uint32_t rd_cycle : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_SCK_CTRL 16'h30 */
	union {
		uint32_t qspi_sck_ctrl; // word name
		struct {
			uint32_t sck_dv : 8;
			uint32_t sck_pol : 1;
			uint32_t : 1; // padding bits
			uint32_t sck_pha : 1;
			uint32_t : 5; // padding bits
			uint32_t sck_phase_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t sck_dly : 8;
		};
	};
	/* QSPI_RX_CLK_CTRL 16'h34 */
	union {
		uint32_t qspi_rx_clk_ctrl; // word name
		struct {
			uint32_t rx_delay : 4;
			uint32_t : 4; // padding bits
			uint32_t rx_smpl_phase_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_WR_DATA 16'h38 */
	union {
		uint32_t qspi_wr_data; // word name
		struct {
			uint32_t wr_data : 32;
		};
	};
	/* QSPI_RD_DATA 16'h3C */
	union {
		uint32_t qspi_rd_data; // word name
		struct {
			uint32_t rd_data : 32;
		};
	};
	/* QSPI_RD_DATA_INV 16'h40 */
	union {
		uint32_t qspi_rd_data_inv; // word name
		struct {
			uint32_t rd_data_inv : 32;
		};
	};
	/* QSPI_KERNEL_CLK_BYPASS 16'h44 */
	union {
		uint32_t qspi_kernel_clk_bypass; // word name
		struct {
			uint32_t kernel_clk_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_SCK_GATING_FUNC_CTRL 16'h48 */
	union {
		uint32_t qspi_sck_gating_func_ctrl; // word name
		struct {
			uint32_t sck_wr_state_gating_en : 1;
			uint32_t : 7; // padding bits
			uint32_t sck_rd_state_gating_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_DEBUG_MON_SEL 16'h4C */
	union {
		uint32_t qspi_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankQspi;

#endif