#ifndef CSR_BANK_QSPI_H_
#define CSR_BANK_QSPI_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from qspi  ***/
typedef struct csr_bank_qspi {
	/* QSPI00 16'h00 */
	union {
		uint32_t qspi00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI01 16'h04 */
	union {
		uint32_t qspi01; // word name
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
	/* QSPI02 16'h08 */
	union {
		uint32_t qspi02; // word name
		struct {
			uint32_t irq_clear_spi_done : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_auto_done : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_clear_done : 1;
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
	/* QSPI03 16'h0C */
	union {
		uint32_t qspi03; // word name
		struct {
			uint32_t status_spi_done : 1;
			uint32_t : 1; // padding bits
			uint32_t status_auto_done : 1;
			uint32_t : 1; // padding bits
			uint32_t status_done : 1;
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
	/* QSPI04 16'h10 */
	union {
		uint32_t qspi04; // word name
		struct {
			uint32_t irq_mask_spi_done : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_auto_done : 1;
			uint32_t : 1; // padding bits
			uint32_t irq_mask_done : 1;
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
	/* QSPI05 16'h14 */
	union {
		uint32_t qspi05; // word name
		struct {
			uint32_t spi_busy : 1;
			uint32_t : 1; // padding bits
			uint32_t spi_done : 1;
			uint32_t : 1; // padding bits
			uint32_t auto_busy : 1;
			uint32_t : 1; // padding bits
			uint32_t auto_done : 1;
			uint32_t : 1; // padding bits
			uint32_t done : 1;
			uint32_t : 1; // padding bits
			uint32_t error : 1;
			uint32_t : 5; // padding bits
			uint32_t tx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t tx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t rx_fifo_full : 1;
			uint32_t : 1; // padding bits
			uint32_t rx_fifo_empty : 1;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI06 16'h18 */
	union {
		uint32_t qspi06; // word name
		struct {
			uint32_t mst_state : 3;
			uint32_t : 1; // padding bits
			uint32_t auto_state : 4;
			uint32_t : 8; // padding bits
			uint32_t cnt_frame : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI07 16'h1C */
	union {
		uint32_t qspi07; // word name
		struct {
			uint32_t df_cnt : 16;
			uint32_t tdf_cnt : 16;
		};
	};
	/* QSPI08 16'h20 */
	union {
		uint32_t qspi08; // word name
		struct {
			uint32_t transfer_mode : 1;
			uint32_t : 1; // padding bits
			uint32_t frame_format : 2;
			uint32_t data_frame_size : 5;
			uint32_t : 1; // padding bits
			uint32_t msb_first : 1;
			uint32_t : 1; // padding bits
			uint32_t endian_sel : 1;
			uint32_t : 1; // padding bits
			uint32_t transfer_type : 2;
			uint32_t inst_l : 2;
			uint32_t addr_l : 4;
			uint32_t : 2; // padding bits
			uint32_t wait_l : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* QSPI09 16'h24 */
	union {
		uint32_t qspi09; // word name
		struct {
			uint32_t ndf : 16;
			uint32_t ndfw : 16;
		};
	};
	/* QSPI10 16'h28 */
	union {
		uint32_t qspi10; // word name
		struct {
			uint32_t sck_dv : 8;
			uint32_t sck_pol : 1;
			uint32_t : 1; // padding bits
			uint32_t sck_pha : 1;
			uint32_t : 5; // padding bits
			uint32_t sck_dly : 8;
			uint32_t rx_delay : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* QSPI11 16'h2C */
	union {
		uint32_t qspi11; // word name
		struct {
			uint32_t wr_data : 32;
		};
	};
	/* QSPI12 16'h30 */
	union {
		uint32_t qspi12; // word name
		struct {
			uint32_t rd_data : 32;
		};
	};
	/* QSPI13 16'h34 */
	union {
		uint32_t qspi13; // word name
		struct {
			uint32_t rd_data_r : 32;
		};
	};
	/* QSPI14 16'h38 */
	union {
		uint32_t qspi14; // word name
		struct {
			uint32_t dma_mode_en : 1;
			uint32_t : 7; // padding bits
			uint32_t auto_mode_en : 1;
			uint32_t : 1; // padding bits
			uint32_t status_bo_sel : 1;
			uint32_t : 1; // padding bits
			uint32_t timeout_free : 1;
			uint32_t : 3; // padding bits
			uint32_t pre_scaler_th : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI15 16'h3C */
	union {
		uint32_t qspi15; // word name
		struct {
			uint32_t flash_start_addr : 16;
			uint32_t flash_page_size : 16;
		};
	};
	/* QSPI16 16'h40 */
	union {
		uint32_t qspi16; // word name
		struct {
			uint32_t status_flash : 32;
		};
	};
	/* QSPI17 16'h44 */
	union {
		uint32_t qspi17; // word name
		struct {
			uint32_t flash_addr : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI18 16'h48 */
	union {
		uint32_t qspi18; // word name
		struct {
			uint32_t op_code_page_rd : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI19 16'h4C */
	union {
		uint32_t qspi19; // word name
		struct {
			uint32_t transfer_mode_page_rd : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_page_rd : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_page_rd : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_page_rd : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI20 16'h50 */
	union {
		uint32_t qspi20; // word name
		struct {
			uint32_t inst_l_page_rd : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_page_rd : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_page_rd : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI21 16'h54 */
	union {
		uint32_t qspi21; // word name
		struct {
			uint32_t ndf_page_rd : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_page_rd : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI22 16'h58 */
	union {
		uint32_t qspi22; // word name
		struct {
			uint32_t op_code_page_rd_poll : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI23 16'h5C */
	union {
		uint32_t qspi23; // word name
		struct {
			uint32_t reg_page_rd_poll : 32;
		};
	};
	/* QSPI24 16'h60 */
	union {
		uint32_t qspi24; // word name
		struct {
			uint32_t transfer_mode_page_rd_poll : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_page_rd_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_page_rd_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_page_rd_poll : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI25 16'h64 */
	union {
		uint32_t qspi25; // word name
		struct {
			uint32_t inst_l_page_rd_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_page_rd_poll : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_page_rd_poll : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI26 16'h68 */
	union {
		uint32_t qspi26; // word name
		struct {
			uint32_t ndf_page_rd_poll : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_page_rd_poll : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI27 16'h6C */
	union {
		uint32_t qspi27; // word name
		struct {
			uint32_t op_code_read : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI28 16'h70 */
	union {
		uint32_t qspi28; // word name
		struct {
			uint32_t reg_read : 32;
		};
	};
	/* QSPI29 16'h74 */
	union {
		uint32_t qspi29; // word name
		struct {
			uint32_t transfer_mode_read : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_read : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_read : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_read : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI30 16'h78 */
	union {
		uint32_t qspi30; // word name
		struct {
			uint32_t inst_l_read : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_read : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_read : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI31 16'h7C */
	union {
		uint32_t qspi31; // word name
		struct {
			uint32_t ndf_read : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_read : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI32 16'h80 */
	union {
		uint32_t qspi32; // word name
		struct {
			uint32_t op_code_we_pg : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI33 16'h84 */
	union {
		uint32_t qspi33; // word name
		struct {
			uint32_t reg_we_pg : 32;
		};
	};
	/* QSPI34 16'h88 */
	union {
		uint32_t qspi34; // word name
		struct {
			uint32_t transfer_mode_we_pg : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_we_pg : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_we_pg : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_we_pg : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI35 16'h8C */
	union {
		uint32_t qspi35; // word name
		struct {
			uint32_t inst_l_we_pg : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_we_pg : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_we_pg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI36 16'h90 */
	union {
		uint32_t qspi36; // word name
		struct {
			uint32_t ndf_we_pg : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_we_pg : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI37 16'h94 */
	union {
		uint32_t qspi37; // word name
		struct {
			uint32_t op_code_we_pg_poll : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI38 16'h98 */
	union {
		uint32_t qspi38; // word name
		struct {
			uint32_t reg_we_pg_poll : 32;
		};
	};
	/* QSPI39 16'h9C */
	union {
		uint32_t qspi39; // word name
		struct {
			uint32_t transfer_mode_we_pg_poll : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_we_pg_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_we_pg_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_we_pg_poll : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI40 16'hA0 */
	union {
		uint32_t qspi40; // word name
		struct {
			uint32_t inst_l_we_pg_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_we_pg_poll : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_we_pg_poll : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI41 16'hA4 */
	union {
		uint32_t qspi41; // word name
		struct {
			uint32_t ndf_we_pg_poll : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_we_pg_poll : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI42 16'hA8 */
	union {
		uint32_t qspi42; // word name
		struct {
			uint32_t op_code_prog : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI43 16'hAC */
	union {
		uint32_t qspi43; // word name
		struct {
			uint32_t reg_prog : 32;
		};
	};
	/* QSPI44 16'hB0 */
	union {
		uint32_t qspi44; // word name
		struct {
			uint32_t transfer_mode_prog : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_prog : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_prog : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_prog : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI45 16'hB4 */
	union {
		uint32_t qspi45; // word name
		struct {
			uint32_t inst_l_prog : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_prog : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_prog : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI46 16'hB8 */
	union {
		uint32_t qspi46; // word name
		struct {
			uint32_t ndf_prog : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_prog : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI47 16'hBC */
	union {
		uint32_t qspi47; // word name
		struct {
			uint32_t op_code_we_exe : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI48 16'hC0 */
	union {
		uint32_t qspi48; // word name
		struct {
			uint32_t reg_we_exe : 32;
		};
	};
	/* QSPI49 16'hC4 */
	union {
		uint32_t qspi49; // word name
		struct {
			uint32_t transfer_mode_we_exe : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_we_exe : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_we_exe : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_we_exe : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI50 16'hC8 */
	union {
		uint32_t qspi50; // word name
		struct {
			uint32_t inst_l_we_exe : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_we_exe : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_we_exe : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI51 16'hCC */
	union {
		uint32_t qspi51; // word name
		struct {
			uint32_t ndf_we_exe : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_we_exe : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI52 16'hD0 */
	union {
		uint32_t qspi52; // word name
		struct {
			uint32_t op_code_we_exe_poll : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI53 16'hD4 */
	union {
		uint32_t qspi53; // word name
		struct {
			uint32_t reg_we_exe_poll : 32;
		};
	};
	/* QSPI54 16'hD8 */
	union {
		uint32_t qspi54; // word name
		struct {
			uint32_t transfer_mode_we_exe_poll : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_we_exe_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_we_exe_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_we_exe_poll : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI55 16'hDC */
	union {
		uint32_t qspi55; // word name
		struct {
			uint32_t inst_l_we_exe_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_we_exe_poll : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_we_exe_poll : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI56 16'hE0 */
	union {
		uint32_t qspi56; // word name
		struct {
			uint32_t ndf_we_exe_poll : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_we_exe_poll : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI57 16'hE4 */
	union {
		uint32_t qspi57; // word name
		struct {
			uint32_t op_code_exec : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI58 16'hE8 */
	union {
		uint32_t qspi58; // word name
		struct {
			uint32_t transfer_mode_exec : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_exec : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_exec : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_exec : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI59 16'hEC */
	union {
		uint32_t qspi59; // word name
		struct {
			uint32_t inst_l_exec : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_exec : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_exec : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI60 16'hF0 */
	union {
		uint32_t qspi60; // word name
		struct {
			uint32_t ndf_exec : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_exec : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI61 16'hF4 */
	union {
		uint32_t qspi61; // word name
		struct {
			uint32_t op_code_exec_poll : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI62 16'hF8 */
	union {
		uint32_t qspi62; // word name
		struct {
			uint32_t reg_exec_poll : 32;
		};
	};
	/* QSPI63 16'hFC */
	union {
		uint32_t qspi63; // word name
		struct {
			uint32_t transfer_mode_exec_poll : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_format_exec_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t transfer_type_exec_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t data_frame_size_exec_poll : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI64 16'h100 */
	union {
		uint32_t qspi64; // word name
		struct {
			uint32_t inst_l_exec_poll : 2;
			uint32_t : 6; // padding bits
			uint32_t addr_l_exec_poll : 4;
			uint32_t : 4; // padding bits
			uint32_t wait_l_exec_poll : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI65 16'h104 */
	union {
		uint32_t qspi65; // word name
		struct {
			uint32_t ndf_exec_poll : 13;
			uint32_t : 3; // padding bits
			uint32_t ndfw_exec_poll : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* QSPI66 16'h108 */
	union {
		uint32_t qspi66; // word name
		struct {
			uint32_t run_type_page_rd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI67 16'h10C */
	union {
		uint32_t qspi67; // word name
		struct {
			uint32_t timeout_time_page_rd : 16;
			uint32_t wait_busy_time_page_rd : 16;
		};
	};
	/* QSPI68 16'h110 */
	union {
		uint32_t qspi68; // word name
		struct {
			uint32_t valid_status_page_rd_poll : 32;
		};
	};
	/* QSPI69 16'h114 */
	union {
		uint32_t qspi69; // word name
		struct {
			uint32_t timeout_time_page_rd_poll : 16;
			uint32_t wait_busy_time_page_rd_poll : 16;
		};
	};
	/* QSPI70 16'h118 */
	union {
		uint32_t qspi70; // word name
		struct {
			uint32_t run_type_read : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI71 16'h11C */
	union {
		uint32_t qspi71; // word name
		struct {
			uint32_t timeout_time_read : 16;
			uint32_t wait_busy_time_read : 16;
		};
	};
	/* QSPI72 16'h120 */
	union {
		uint32_t qspi72; // word name
		struct {
			uint32_t run_type_we_pg : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI73 16'h124 */
	union {
		uint32_t qspi73; // word name
		struct {
			uint32_t timeout_time_we_pg : 16;
			uint32_t wait_busy_time_we_pg : 16;
		};
	};
	/* QSPI74 16'h128 */
	union {
		uint32_t qspi74; // word name
		struct {
			uint32_t valid_status_we_pg_poll : 32;
		};
	};
	/* QSPI75 16'h12C */
	union {
		uint32_t qspi75; // word name
		struct {
			uint32_t timeout_time_we_pg_poll : 16;
			uint32_t wait_busy_time_we_pg_poll : 16;
		};
	};
	/* QSPI76 16'h130 */
	union {
		uint32_t qspi76; // word name
		struct {
			uint32_t run_type_prog : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI77 16'h134 */
	union {
		uint32_t qspi77; // word name
		struct {
			uint32_t timeout_time_prog : 16;
			uint32_t wait_busy_time_prog : 16;
		};
	};
	/* QSPI78 16'h138 [Unused] */
	uint32_t empty_word_qspi78;
	/* QSPI79 16'h13C [Unused] */
	uint32_t empty_word_qspi79;
	/* QSPI80 16'h140 */
	union {
		uint32_t qspi80; // word name
		struct {
			uint32_t run_type_we_exe : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI81 16'h144 */
	union {
		uint32_t qspi81; // word name
		struct {
			uint32_t timeout_time_we_exe : 16;
			uint32_t wait_busy_time_we_exe : 16;
		};
	};
	/* QSPI82 16'h148 */
	union {
		uint32_t qspi82; // word name
		struct {
			uint32_t valid_status_we_exe_poll : 32;
		};
	};
	/* QSPI83 16'h14C */
	union {
		uint32_t qspi83; // word name
		struct {
			uint32_t timeout_time_we_exe_poll : 16;
			uint32_t wait_busy_time_we_exe_poll : 16;
		};
	};
	/* QSPI84 16'h150 */
	union {
		uint32_t qspi84; // word name
		struct {
			uint32_t run_type_exec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI85 16'h154 */
	union {
		uint32_t qspi85; // word name
		struct {
			uint32_t timeout_time_exec : 16;
			uint32_t wait_busy_time_exec : 16;
		};
	};
	/* QSPI86 16'h158 */
	union {
		uint32_t qspi86; // word name
		struct {
			uint32_t valid_status_exec_poll : 32;
		};
	};
	/* QSPI87 16'h15C */
	union {
		uint32_t qspi87; // word name
		struct {
			uint32_t timeout_time_exec_poll : 16;
			uint32_t wait_busy_time_exec_poll : 16;
		};
	};
	/* QSPI88 16'h160 [Unused] */
	uint32_t empty_word_qspi88;
	/* QSPI89 16'h164 [Unused] */
	uint32_t empty_word_qspi89;
	/* QSPI90 16'h168 */
	union {
		uint32_t qspi90; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI91 16'h16C */
	union {
		uint32_t qspi91; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankQspi;

#endif