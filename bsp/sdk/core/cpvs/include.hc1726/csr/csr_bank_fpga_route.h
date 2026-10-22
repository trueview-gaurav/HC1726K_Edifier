/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_FPGA_ROUTE_H_
#define CSR_BANK_FPGA_ROUTE_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from fpga_route  ***/
typedef struct csr_bank_fpga_route {
	/* FPGA_VER 10'h000 */
	union {
		uint32_t fpga_ver; // word name
		struct {
			uint32_t fpga_version : 32;
		};
	};
	/* FPGA_MODULE 10'h004 */
	union {
		uint32_t fpga_module; // word name
		struct {
			uint32_t fpga_module_en : 32;
		};
	};
	/* WORD_PAD_SD_CD_ROUTE_SEL 10'h008 */
	union {
		uint32_t word_pad_sd_cd_route_sel; // word name
		struct {
			uint32_t pad_sd_cd_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D0_ROUTE_SEL 10'h00C */
	union {
		uint32_t word_pad_sd_d0_route_sel; // word name
		struct {
			uint32_t pad_sd_d0_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SENSOR_CLK_ROUTE_SEL 10'h010 */
	union {
		uint32_t word_pad_sensor_clk_route_sel; // word name
		struct {
			uint32_t pad_sensor_clk_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D2_ROUTE_SEL 10'h014 */
	union {
		uint32_t word_pad_sd_d2_route_sel; // word name
		struct {
			uint32_t pad_sd_d2_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D3_ROUTE_SEL 10'h018 */
	union {
		uint32_t word_pad_sd_d3_route_sel; // word name
		struct {
			uint32_t pad_sd_d3_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CK_ROUTE_SEL 10'h01C */
	union {
		uint32_t word_pad_sd_ck_route_sel; // word name
		struct {
			uint32_t pad_sd_ck_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CMD_ROUTE_SEL 10'h020 */
	union {
		uint32_t word_pad_sd_cmd_route_sel; // word name
		struct {
			uint32_t pad_sd_cmd_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C0_SCL_ROUTE_SEL 10'h024 */
	union {
		uint32_t word_pad_i2c0_scl_route_sel; // word name
		struct {
			uint32_t pad_i2c0_scl_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C1_SCL_ROUTE_SEL 10'h028 */
	union {
		uint32_t word_pad_i2c1_scl_route_sel; // word name
		struct {
			uint32_t pad_i2c1_scl_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C0_SDA_ROUTE_SEL 10'h02C */
	union {
		uint32_t word_pad_i2c0_sda_route_sel; // word name
		struct {
			uint32_t pad_i2c0_sda_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C1_SDA_ROUTE_SEL 10'h030 */
	union {
		uint32_t word_pad_i2c1_sda_route_sel; // word name
		struct {
			uint32_t pad_i2c1_sda_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_RX_D0_ROUTE_SEL 10'h034 */
	union {
		uint32_t word_pad_emac_rx_d0_route_sel; // word name
		struct {
			uint32_t pad_emac_rx_d0_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_RX_D1_ROUTE_SEL 10'h038 */
	union {
		uint32_t word_pad_emac_rx_d1_route_sel; // word name
		struct {
			uint32_t pad_emac_rx_d1_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_TX_D1_ROUTE_SEL 10'h03C */
	union {
		uint32_t word_pad_emac_tx_d1_route_sel; // word name
		struct {
			uint32_t pad_emac_tx_d1_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_TX_D0_ROUTE_SEL 10'h040 */
	union {
		uint32_t word_pad_emac_tx_d0_route_sel; // word name
		struct {
			uint32_t pad_emac_tx_d0_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PWM3_ROUTE_SEL 10'h044 */
	union {
		uint32_t word_pad_pwm3_route_sel; // word name
		struct {
			uint32_t pad_pwm3_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PWM1_ROUTE_SEL 10'h048 */
	union {
		uint32_t word_pad_pwm1_route_sel; // word name
		struct {
			uint32_t pad_pwm1_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_RTS_ROUTE_SEL 10'h04C */
	union {
		uint32_t word_pad_uart0_rts_route_sel; // word name
		struct {
			uint32_t pad_uart0_rts_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_CTS_ROUTE_SEL 10'h050 */
	union {
		uint32_t word_pad_uart0_cts_route_sel; // word name
		struct {
			uint32_t pad_uart0_cts_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EPHY_RST_ROUTE_SEL 10'h054 */
	union {
		uint32_t word_pad_ephy_rst_route_sel; // word name
		struct {
			uint32_t pad_ephy_rst_route_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_CK_ROUTE_SEL 10'h058 */
	union {
		uint32_t word_pad_qspi_ck_route_sel; // word name
		struct {
			uint32_t pad_qspi_ck_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_I2C_SCL_ROUTE_SEL 10'h05C */
	union {
		uint32_t word_fpga_i2c_scl_route_sel; // word name
		struct {
			uint32_t fpga_i2c_scl_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_I2C_SDA_ROUTE_SEL 10'h060 */
	union {
		uint32_t word_fpga_i2c_sda_route_sel; // word name
		struct {
			uint32_t fpga_i2c_sda_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_UART2_TXD_ROUTE_SEL 10'h064 */
	union {
		uint32_t word_fpga_uart2_txd_route_sel; // word name
		struct {
			uint32_t fpga_uart2_txd_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_UART2_RXD_ROUTE_SEL 10'h068 */
	union {
		uint32_t word_fpga_uart2_rxd_route_sel; // word name
		struct {
			uint32_t fpga_uart2_rxd_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_UART2_CTS_ROUTE_SEL 10'h06C */
	union {
		uint32_t word_fpga_uart2_cts_route_sel; // word name
		struct {
			uint32_t fpga_uart2_cts_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_UART2_RTS_ROUTE_SEL 10'h070 */
	union {
		uint32_t word_fpga_uart2_rts_route_sel; // word name
		struct {
			uint32_t fpga_uart2_rts_route_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankFpga_route;

#endif