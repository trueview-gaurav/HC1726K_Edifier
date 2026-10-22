#ifndef CSR_BANK_PIOC_H_
#define CSR_BANK_PIOC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pioc  ***/
typedef struct csr_bank_pioc {
	/* SPI0_SCK_IOCFG 10'h000 */
	union {
		uint32_t spi0_sck_iocfg; // word name
		struct {
			uint32_t pad_spi0_sck_pu : 1;
			uint32_t pad_spi0_sck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_spi0_sck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI0_SDI_IOCFG 10'h004 */
	union {
		uint32_t spi0_sdi_iocfg; // word name
		struct {
			uint32_t pad_spi0_sdi_pu : 1;
			uint32_t pad_spi0_sdi_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_spi0_sdi_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI0_SDO_IOCFG 10'h008 */
	union {
		uint32_t spi0_sdo_iocfg; // word name
		struct {
			uint32_t pad_spi0_sdo_pu : 1;
			uint32_t pad_spi0_sdo_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_spi0_sdo_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EIRQ0_IOCFG 10'h00C */
	union {
		uint32_t eirq0_iocfg; // word name
		struct {
			uint32_t pad_eirq0_pu : 1;
			uint32_t pad_eirq0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_eirq0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_CD_IOCFG 10'h010 */
	union {
		uint32_t sd_cd_iocfg; // word name
		struct {
			uint32_t pad_sd_cd_pu : 1;
			uint32_t pad_sd_cd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_cd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D2_IOCFG 10'h014 */
	union {
		uint32_t sd_d2_iocfg; // word name
		struct {
			uint32_t pad_sd_d2_pu : 1;
			uint32_t pad_sd_d2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d2_pcfg : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D3_IOCFG 10'h018 */
	union {
		uint32_t sd_d3_iocfg; // word name
		struct {
			uint32_t pad_sd_d3_pu : 1;
			uint32_t pad_sd_d3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d3_pcfg : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_CMD_IOCFG 10'h01C */
	union {
		uint32_t sd_cmd_iocfg; // word name
		struct {
			uint32_t pad_sd_cmd_pu : 1;
			uint32_t pad_sd_cmd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_cmd_pcfg : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_CK_IOCFG 10'h020 */
	union {
		uint32_t sd_ck_iocfg; // word name
		struct {
			uint32_t pad_sd_ck_pu : 1;
			uint32_t pad_sd_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_ck_pcfg : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D0_IOCFG 10'h024 */
	union {
		uint32_t sd_d0_iocfg; // word name
		struct {
			uint32_t pad_sd_d0_pu : 1;
			uint32_t pad_sd_d0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d0_pcfg : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D1_IOCFG 10'h028 */
	union {
		uint32_t sd_d1_iocfg; // word name
		struct {
			uint32_t pad_sd_d1_pu : 1;
			uint32_t pad_sd_d1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d1_pcfg : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_POC_IOCFG 10'h02C */
	union {
		uint32_t sd_poc_iocfg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_poc_pcfg : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO3_IOCFG 10'h030 */
	union {
		uint32_t gpio3_iocfg; // word name
		struct {
			uint32_t pad_gpio3_pu : 1;
			uint32_t pad_gpio3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio3_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM1_IOCFG 10'h034 */
	union {
		uint32_t pwm1_iocfg; // word name
		struct {
			uint32_t pad_pwm1_pu : 1;
			uint32_t pad_pwm1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pwm1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM4_IOCFG 10'h038 */
	union {
		uint32_t pwm4_iocfg; // word name
		struct {
			uint32_t pad_pwm4_pu : 1;
			uint32_t pad_pwm4_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pwm4_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C1_SCL_IOCFG 10'h03C */
	union {
		uint32_t i2c1_scl_iocfg; // word name
		struct {
			uint32_t pad_i2c1_scl_pu : 1;
			uint32_t pad_i2c1_scl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c1_scl_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C1_SDA_IOCFG 10'h040 */
	union {
		uint32_t i2c1_sda_iocfg; // word name
		struct {
			uint32_t pad_i2c1_sda_pu : 1;
			uint32_t pad_i2c1_sda_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c1_sda_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART1_TXD_IOCFG 10'h044 */
	union {
		uint32_t uart1_txd_iocfg; // word name
		struct {
			uint32_t pad_uart1_txd_pu : 1;
			uint32_t pad_uart1_txd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart1_txd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART1_RXD_IOCFG 10'h048 */
	union {
		uint32_t uart1_rxd_iocfg; // word name
		struct {
			uint32_t pad_uart1_rxd_pu : 1;
			uint32_t pad_uart1_rxd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart1_rxd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART2_TXD_IOCFG 10'h04C */
	union {
		uint32_t uart2_txd_iocfg; // word name
		struct {
			uint32_t pad_uart2_txd_pu : 1;
			uint32_t pad_uart2_txd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart2_txd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART2_RXD_IOCFG 10'h050 */
	union {
		uint32_t uart2_rxd_iocfg; // word name
		struct {
			uint32_t pad_uart2_rxd_pu : 1;
			uint32_t pad_uart2_rxd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart2_rxd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_CE_N_IOCFG 10'h054 */
	union {
		uint32_t qspi_ce_n_iocfg; // word name
		struct {
			uint32_t pad_qspi_ce_n_pu : 1;
			uint32_t pad_qspi_ce_n_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_qspi_ce_n_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D1_IOCFG 10'h058 */
	union {
		uint32_t qspi_d1_iocfg; // word name
		struct {
			uint32_t pad_qspi_d1_pu : 1;
			uint32_t pad_qspi_d1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_qspi_d1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D2_IOCFG 10'h05C */
	union {
		uint32_t qspi_d2_iocfg; // word name
		struct {
			uint32_t pad_qspi_d2_pu : 1;
			uint32_t pad_qspi_d2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_qspi_d2_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D3_IOCFG 10'h060 */
	union {
		uint32_t qspi_d3_iocfg; // word name
		struct {
			uint32_t pad_qspi_d3_pu : 1;
			uint32_t pad_qspi_d3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_qspi_d3_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_CK_IOCFG 10'h064 */
	union {
		uint32_t qspi_ck_iocfg; // word name
		struct {
			uint32_t pad_qspi_ck_pu : 1;
			uint32_t pad_qspi_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_qspi_ck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D0_IOCFG 10'h068 */
	union {
		uint32_t qspi_d0_iocfg; // word name
		struct {
			uint32_t pad_qspi_d0_pu : 1;
			uint32_t pad_qspi_d0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_qspi_d0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EPHY_RST_IOCFG 10'h06C */
	union {
		uint32_t ephy_rst_iocfg; // word name
		struct {
			uint32_t pad_ephy_rst_pu : 1;
			uint32_t pad_ephy_rst_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ephy_rst_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_CK_IOCFG 10'h070 */
	union {
		uint32_t emac_tx_ck_iocfg; // word name
		struct {
			uint32_t pad_emac_tx_ck_pu : 1;
			uint32_t pad_emac_tx_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_tx_ck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_CTL_IOCFG 10'h074 */
	union {
		uint32_t emac_tx_ctl_iocfg; // word name
		struct {
			uint32_t pad_emac_tx_ctl_pu : 1;
			uint32_t pad_emac_tx_ctl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_tx_ctl_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D3_IOCFG 10'h078 */
	union {
		uint32_t emac_tx_d3_iocfg; // word name
		struct {
			uint32_t pad_emac_tx_d3_pu : 1;
			uint32_t pad_emac_tx_d3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_tx_d3_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D2_IOCFG 10'h07C */
	union {
		uint32_t emac_tx_d2_iocfg; // word name
		struct {
			uint32_t pad_emac_tx_d2_pu : 1;
			uint32_t pad_emac_tx_d2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_tx_d2_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D1_IOCFG 10'h080 */
	union {
		uint32_t emac_tx_d1_iocfg; // word name
		struct {
			uint32_t pad_emac_tx_d1_pu : 1;
			uint32_t pad_emac_tx_d1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_tx_d1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D0_IOCFG 10'h084 */
	union {
		uint32_t emac_tx_d0_iocfg; // word name
		struct {
			uint32_t pad_emac_tx_d0_pu : 1;
			uint32_t pad_emac_tx_d0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_tx_d0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_CK_IOCFG 10'h088 */
	union {
		uint32_t emac_rx_ck_iocfg; // word name
		struct {
			uint32_t pad_emac_rx_ck_pu : 1;
			uint32_t pad_emac_rx_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_rx_ck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D0_IOCFG 10'h08C */
	union {
		uint32_t emac_rx_d0_iocfg; // word name
		struct {
			uint32_t pad_emac_rx_d0_pu : 1;
			uint32_t pad_emac_rx_d0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_rx_d0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D1_IOCFG 10'h090 */
	union {
		uint32_t emac_rx_d1_iocfg; // word name
		struct {
			uint32_t pad_emac_rx_d1_pu : 1;
			uint32_t pad_emac_rx_d1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_rx_d1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D2_IOCFG 10'h094 */
	union {
		uint32_t emac_rx_d2_iocfg; // word name
		struct {
			uint32_t pad_emac_rx_d2_pu : 1;
			uint32_t pad_emac_rx_d2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_rx_d2_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D3_IOCFG 10'h098 */
	union {
		uint32_t emac_rx_d3_iocfg; // word name
		struct {
			uint32_t pad_emac_rx_d3_pu : 1;
			uint32_t pad_emac_rx_d3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_rx_d3_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_CTL_IOCFG 10'h09C */
	union {
		uint32_t emac_rx_ctl_iocfg; // word name
		struct {
			uint32_t pad_emac_rx_ctl_pu : 1;
			uint32_t pad_emac_rx_ctl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_rx_ctl_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_MDC_IOCFG 10'h0A0 */
	union {
		uint32_t emac_mdc_iocfg; // word name
		struct {
			uint32_t pad_emac_mdc_pu : 1;
			uint32_t pad_emac_mdc_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_mdc_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_MDIO_IOCFG 10'h0A4 */
	union {
		uint32_t emac_mdio_iocfg; // word name
		struct {
			uint32_t pad_emac_mdio_pu : 1;
			uint32_t pad_emac_mdio_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_emac_mdio_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI1_SDI_IOCFG 10'h0A8 */
	union {
		uint32_t spi1_sdi_iocfg; // word name
		struct {
			uint32_t pad_spi1_sdi_pu : 1;
			uint32_t pad_spi1_sdi_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_spi1_sdi_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI1_SDO_IOCFG 10'h0AC */
	union {
		uint32_t spi1_sdo_iocfg; // word name
		struct {
			uint32_t pad_spi1_sdo_pu : 1;
			uint32_t pad_spi1_sdo_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_spi1_sdo_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI1_SCK_IOCFG 10'h0B0 */
	union {
		uint32_t spi1_sck_iocfg; // word name
		struct {
			uint32_t pad_spi1_sck_pu : 1;
			uint32_t pad_spi1_sck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_spi1_sck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO7_IOCFG 10'h0B4 */
	union {
		uint32_t gpio7_iocfg; // word name
		struct {
			uint32_t pad_gpio7_pu : 1;
			uint32_t pad_gpio7_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio7_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C0_SDA_IOCFG 10'h0B8 */
	union {
		uint32_t i2c0_sda_iocfg; // word name
		struct {
			uint32_t pad_i2c0_sda_pu : 1;
			uint32_t pad_i2c0_sda_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c0_sda_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C0_SCL_IOCFG 10'h0BC */
	union {
		uint32_t i2c0_scl_iocfg; // word name
		struct {
			uint32_t pad_i2c0_scl_pu : 1;
			uint32_t pad_i2c0_scl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c0_scl_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_CLK_IOCFG 10'h0C0 */
	union {
		uint32_t sensor_clk_iocfg; // word name
		struct {
			uint32_t pad_sensor_clk_pu : 1;
			uint32_t pad_sensor_clk_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sensor_clk_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM2_IOCFG 10'h0C4 */
	union {
		uint32_t pwm2_iocfg; // word name
		struct {
			uint32_t pad_pwm2_pu : 1;
			uint32_t pad_pwm2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pwm2_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_RSTB_IOCFG 10'h0C8 */
	union {
		uint32_t sensor_rstb_iocfg; // word name
		struct {
			uint32_t pad_sensor_rstb_pu : 1;
			uint32_t pad_sensor_rstb_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sensor_rstb_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_PWDN_IOCFG 10'h0CC */
	union {
		uint32_t sensor_pwdn_iocfg; // word name
		struct {
			uint32_t pad_sensor_pwdn_pu : 1;
			uint32_t pad_sensor_pwdn_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sensor_pwdn_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO4_IOCFG 10'h0D0 */
	union {
		uint32_t gpio4_iocfg; // word name
		struct {
			uint32_t pad_gpio4_pu : 1;
			uint32_t pad_gpio4_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio4_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO5_IOCFG 10'h0D4 */
	union {
		uint32_t gpio5_iocfg; // word name
		struct {
			uint32_t pad_gpio5_pu : 1;
			uint32_t pad_gpio5_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio5_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO6_IOCFG 10'h0D8 */
	union {
		uint32_t gpio6_iocfg; // word name
		struct {
			uint32_t pad_gpio6_pu : 1;
			uint32_t pad_gpio6_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio6_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_TX_CK_IOCFG 10'h0DC */
	union {
		uint32_t i2s_tx_ck_iocfg; // word name
		struct {
			uint32_t pad_i2s_tx_ck_pu : 1;
			uint32_t pad_i2s_tx_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2s_tx_ck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RX_CK_IOCFG 10'h0E0 */
	union {
		uint32_t i2s_rx_ck_iocfg; // word name
		struct {
			uint32_t pad_i2s_rx_ck_pu : 1;
			uint32_t pad_i2s_rx_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2s_rx_ck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RX_SD_IOCFG 10'h0E4 */
	union {
		uint32_t i2s_rx_sd_iocfg; // word name
		struct {
			uint32_t pad_i2s_rx_sd_pu : 1;
			uint32_t pad_i2s_rx_sd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2s_rx_sd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_TX_SD_IOCFG 10'h0E8 */
	union {
		uint32_t i2s_tx_sd_iocfg; // word name
		struct {
			uint32_t pad_i2s_tx_sd_pu : 1;
			uint32_t pad_i2s_tx_sd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2s_tx_sd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RX_WS_IOCFG 10'h0EC */
	union {
		uint32_t i2s_rx_ws_iocfg; // word name
		struct {
			uint32_t pad_i2s_rx_ws_pu : 1;
			uint32_t pad_i2s_rx_ws_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2s_rx_ws_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_TX_WS_IOCFG 10'h0F0 */
	union {
		uint32_t i2s_tx_ws_iocfg; // word name
		struct {
			uint32_t pad_i2s_tx_ws_pu : 1;
			uint32_t pad_i2s_tx_ws_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2s_tx_ws_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO2_IOCFG 10'h0F4 */
	union {
		uint32_t gpio2_iocfg; // word name
		struct {
			uint32_t pad_gpio2_pu : 1;
			uint32_t pad_gpio2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio2_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_TXD_IOCFG 10'h0F8 */
	union {
		uint32_t uart0_txd_iocfg; // word name
		struct {
			uint32_t pad_uart0_txd_pu : 1;
			uint32_t pad_uart0_txd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart0_txd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_RXD_IOCFG 10'h0FC */
	union {
		uint32_t uart0_rxd_iocfg; // word name
		struct {
			uint32_t pad_uart0_rxd_pu : 1;
			uint32_t pad_uart0_rxd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart0_rxd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EIRQ1_IOCFG 10'h100 */
	union {
		uint32_t eirq1_iocfg; // word name
		struct {
			uint32_t pad_eirq1_pu : 1;
			uint32_t pad_eirq1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_eirq1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM3_IOCFG 10'h104 */
	union {
		uint32_t pwm3_iocfg; // word name
		struct {
			uint32_t pad_pwm3_pu : 1;
			uint32_t pad_pwm3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pwm3_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM0_IOCFG 10'h108 */
	union {
		uint32_t pwm0_iocfg; // word name
		struct {
			uint32_t pad_pwm0_pu : 1;
			uint32_t pad_pwm0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_pwm0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO0_IOCFG 10'h10C */
	union {
		uint32_t gpio0_iocfg; // word name
		struct {
			uint32_t pad_gpio0_pu : 1;
			uint32_t pad_gpio0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO1_IOCFG 10'h110 */
	union {
		uint32_t gpio1_iocfg; // word name
		struct {
			uint32_t pad_gpio1_pu : 1;
			uint32_t pad_gpio1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI0_SCK_IOSEL 10'h114 */
	union {
		uint32_t spi0_sck_iosel; // word name
		struct {
			uint32_t pad_spi0_sck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI0_SDI_IOSEL 10'h118 */
	union {
		uint32_t spi0_sdi_iosel; // word name
		struct {
			uint32_t pad_spi0_sdi_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI0_SDO_IOSEL 10'h11C */
	union {
		uint32_t spi0_sdo_iosel; // word name
		struct {
			uint32_t pad_spi0_sdo_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EIRQ0_IOSEL 10'h120 */
	union {
		uint32_t eirq0_iosel; // word name
		struct {
			uint32_t pad_eirq0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_CD_IOSEL 10'h124 */
	union {
		uint32_t sd_cd_iosel; // word name
		struct {
			uint32_t pad_sd_cd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D2_IOSEL 10'h128 */
	union {
		uint32_t sd_d2_iosel; // word name
		struct {
			uint32_t pad_sd_d2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D3_IOSEL 10'h12C */
	union {
		uint32_t sd_d3_iosel; // word name
		struct {
			uint32_t pad_sd_d3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_CMD_IOSEL 10'h130 */
	union {
		uint32_t sd_cmd_iosel; // word name
		struct {
			uint32_t pad_sd_cmd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_CK_IOSEL 10'h134 */
	union {
		uint32_t sd_ck_iosel; // word name
		struct {
			uint32_t pad_sd_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D0_IOSEL 10'h138 */
	union {
		uint32_t sd_d0_iosel; // word name
		struct {
			uint32_t pad_sd_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SD_D1_IOSEL 10'h13C */
	union {
		uint32_t sd_d1_iosel; // word name
		struct {
			uint32_t pad_sd_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO3_IOSEL 10'h140 */
	union {
		uint32_t gpio3_iosel; // word name
		struct {
			uint32_t pad_gpio3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM1_IOSEL 10'h144 */
	union {
		uint32_t pwm1_iosel; // word name
		struct {
			uint32_t pad_pwm1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM4_IOSEL 10'h148 */
	union {
		uint32_t pwm4_iosel; // word name
		struct {
			uint32_t pad_pwm4_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C1_SCL_IOSEL 10'h14C */
	union {
		uint32_t i2c1_scl_iosel; // word name
		struct {
			uint32_t pad_i2c1_scl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C1_SDA_IOSEL 10'h150 */
	union {
		uint32_t i2c1_sda_iosel; // word name
		struct {
			uint32_t pad_i2c1_sda_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART1_TXD_IOSEL 10'h154 */
	union {
		uint32_t uart1_txd_iosel; // word name
		struct {
			uint32_t pad_uart1_txd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART1_RXD_IOSEL 10'h158 */
	union {
		uint32_t uart1_rxd_iosel; // word name
		struct {
			uint32_t pad_uart1_rxd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART2_TXD_IOSEL 10'h15C */
	union {
		uint32_t uart2_txd_iosel; // word name
		struct {
			uint32_t pad_uart2_txd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART2_RXD_IOSEL 10'h160 */
	union {
		uint32_t uart2_rxd_iosel; // word name
		struct {
			uint32_t pad_uart2_rxd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* POWER_CTRL_0_IOSEL 10'h164 [Unused] */
	uint32_t empty_word_power_ctrl_0_iosel;
	/* POWER_CTRL_1_IOSEL 10'h168 [Unused] */
	uint32_t empty_word_power_ctrl_1_iosel;
	/* DVP_0_IOSEL 10'h16C [Unused] */
	uint32_t empty_word_dvp_0_iosel;
	/* DVP_1_IOSEL 10'h170 [Unused] */
	uint32_t empty_word_dvp_1_iosel;
	/* DVP_2_IOSEL 10'h174 [Unused] */
	uint32_t empty_word_dvp_2_iosel;
	/* DVP_3_IOSEL 10'h178 [Unused] */
	uint32_t empty_word_dvp_3_iosel;
	/* DVP_4_IOSEL 10'h17C [Unused] */
	uint32_t empty_word_dvp_4_iosel;
	/* DVP_5_IOSEL 10'h180 [Unused] */
	uint32_t empty_word_dvp_5_iosel;
	/* DVP_6_IOSEL 10'h184 [Unused] */
	uint32_t empty_word_dvp_6_iosel;
	/* DVP_7_IOSEL 10'h188 [Unused] */
	uint32_t empty_word_dvp_7_iosel;
	/* DVP_8_IOSEL 10'h18C [Unused] */
	uint32_t empty_word_dvp_8_iosel;
	/* AO_BUTTON_IOSEL 10'h190 [Unused] */
	uint32_t empty_word_ao_button_iosel;
	/* AO_WAKEUP_IOSEL 10'h194 [Unused] */
	uint32_t empty_word_ao_wakeup_iosel;
	/* QSPI_CE_N_IOSEL 10'h198 */
	union {
		uint32_t qspi_ce_n_iosel; // word name
		struct {
			uint32_t pad_qspi_ce_n_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D1_IOSEL 10'h19C */
	union {
		uint32_t qspi_d1_iosel; // word name
		struct {
			uint32_t pad_qspi_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D2_IOSEL 10'h1A0 */
	union {
		uint32_t qspi_d2_iosel; // word name
		struct {
			uint32_t pad_qspi_d2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D3_IOSEL 10'h1A4 */
	union {
		uint32_t qspi_d3_iosel; // word name
		struct {
			uint32_t pad_qspi_d3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_CK_IOSEL 10'h1A8 */
	union {
		uint32_t qspi_ck_iosel; // word name
		struct {
			uint32_t pad_qspi_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* QSPI_D0_IOSEL 10'h1AC */
	union {
		uint32_t qspi_d0_iosel; // word name
		struct {
			uint32_t pad_qspi_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EPHY_RST_IOSEL 10'h1B0 */
	union {
		uint32_t ephy_rst_iosel; // word name
		struct {
			uint32_t pad_ephy_rst_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_CK_IOSEL 10'h1B4 */
	union {
		uint32_t emac_tx_ck_iosel; // word name
		struct {
			uint32_t pad_emac_tx_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_CTL_IOSEL 10'h1B8 */
	union {
		uint32_t emac_tx_ctl_iosel; // word name
		struct {
			uint32_t pad_emac_tx_ctl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D3_IOSEL 10'h1BC */
	union {
		uint32_t emac_tx_d3_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D2_IOSEL 10'h1C0 */
	union {
		uint32_t emac_tx_d2_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D1_IOSEL 10'h1C4 */
	union {
		uint32_t emac_tx_d1_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_TX_D0_IOSEL 10'h1C8 */
	union {
		uint32_t emac_tx_d0_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_CK_IOSEL 10'h1CC */
	union {
		uint32_t emac_rx_ck_iosel; // word name
		struct {
			uint32_t pad_emac_rx_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D0_IOSEL 10'h1D0 */
	union {
		uint32_t emac_rx_d0_iosel; // word name
		struct {
			uint32_t pad_emac_rx_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D1_IOSEL 10'h1D4 */
	union {
		uint32_t emac_rx_d1_iosel; // word name
		struct {
			uint32_t pad_emac_rx_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D2_IOSEL 10'h1D8 */
	union {
		uint32_t emac_rx_d2_iosel; // word name
		struct {
			uint32_t pad_emac_rx_d2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_D3_IOSEL 10'h1DC */
	union {
		uint32_t emac_rx_d3_iosel; // word name
		struct {
			uint32_t pad_emac_rx_d3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_RX_CTL_IOSEL 10'h1E0 */
	union {
		uint32_t emac_rx_ctl_iosel; // word name
		struct {
			uint32_t pad_emac_rx_ctl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_MDC_IOSEL 10'h1E4 */
	union {
		uint32_t emac_mdc_iosel; // word name
		struct {
			uint32_t pad_emac_mdc_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EMAC_MDIO_IOSEL 10'h1E8 */
	union {
		uint32_t emac_mdio_iosel; // word name
		struct {
			uint32_t pad_emac_mdio_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI1_SDI_IOSEL 10'h1EC */
	union {
		uint32_t spi1_sdi_iosel; // word name
		struct {
			uint32_t pad_spi1_sdi_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI1_SDO_IOSEL 10'h1F0 */
	union {
		uint32_t spi1_sdo_iosel; // word name
		struct {
			uint32_t pad_spi1_sdo_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPI1_SCK_IOSEL 10'h1F4 */
	union {
		uint32_t spi1_sck_iosel; // word name
		struct {
			uint32_t pad_spi1_sck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO7_IOSEL 10'h1F8 */
	union {
		uint32_t gpio7_iosel; // word name
		struct {
			uint32_t pad_gpio7_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C0_SDA_IOSEL 10'h1FC */
	union {
		uint32_t i2c0_sda_iosel; // word name
		struct {
			uint32_t pad_i2c0_sda_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2C0_SCL_IOSEL 10'h200 */
	union {
		uint32_t i2c0_scl_iosel; // word name
		struct {
			uint32_t pad_i2c0_scl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_CLK_IOSEL 10'h204 */
	union {
		uint32_t sensor_clk_iosel; // word name
		struct {
			uint32_t pad_sensor_clk_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM2_IOSEL 10'h208 */
	union {
		uint32_t pwm2_iosel; // word name
		struct {
			uint32_t pad_pwm2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_RSTB_IOSEL 10'h20C */
	union {
		uint32_t sensor_rstb_iosel; // word name
		struct {
			uint32_t pad_sensor_rstb_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_PWDN_IOSEL 10'h210 */
	union {
		uint32_t sensor_pwdn_iosel; // word name
		struct {
			uint32_t pad_sensor_pwdn_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO4_IOSEL 10'h214 */
	union {
		uint32_t gpio4_iosel; // word name
		struct {
			uint32_t pad_gpio4_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO5_IOSEL 10'h218 */
	union {
		uint32_t gpio5_iosel; // word name
		struct {
			uint32_t pad_gpio5_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO6_IOSEL 10'h21C */
	union {
		uint32_t gpio6_iosel; // word name
		struct {
			uint32_t pad_gpio6_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_TX_CK_IOSEL 10'h220 */
	union {
		uint32_t i2s_tx_ck_iosel; // word name
		struct {
			uint32_t pad_i2s_tx_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RX_CK_IOSEL 10'h224 */
	union {
		uint32_t i2s_rx_ck_iosel; // word name
		struct {
			uint32_t pad_i2s_rx_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RX_SD_IOSEL 10'h228 */
	union {
		uint32_t i2s_rx_sd_iosel; // word name
		struct {
			uint32_t pad_i2s_rx_sd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_TX_SD_IOSEL 10'h22C */
	union {
		uint32_t i2s_tx_sd_iosel; // word name
		struct {
			uint32_t pad_i2s_tx_sd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_RX_WS_IOSEL 10'h230 */
	union {
		uint32_t i2s_rx_ws_iosel; // word name
		struct {
			uint32_t pad_i2s_rx_ws_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S_TX_WS_IOSEL 10'h234 */
	union {
		uint32_t i2s_tx_ws_iosel; // word name
		struct {
			uint32_t pad_i2s_tx_ws_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO2_IOSEL 10'h238 */
	union {
		uint32_t gpio2_iosel; // word name
		struct {
			uint32_t pad_gpio2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_TXD_IOSEL 10'h23C */
	union {
		uint32_t uart0_txd_iosel; // word name
		struct {
			uint32_t pad_uart0_txd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* UART0_RXD_IOSEL 10'h240 */
	union {
		uint32_t uart0_rxd_iosel; // word name
		struct {
			uint32_t pad_uart0_rxd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EIRQ1_IOSEL 10'h244 */
	union {
		uint32_t eirq1_iosel; // word name
		struct {
			uint32_t pad_eirq1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM3_IOSEL 10'h248 */
	union {
		uint32_t pwm3_iosel; // word name
		struct {
			uint32_t pad_pwm3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWM0_IOSEL 10'h24C */
	union {
		uint32_t pwm0_iosel; // word name
		struct {
			uint32_t pad_pwm0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO0_IOSEL 10'h250 */
	union {
		uint32_t gpio0_iosel; // word name
		struct {
			uint32_t pad_gpio0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GPIO1_IOSEL 10'h254 */
	union {
		uint32_t gpio1_iosel; // word name
		struct {
			uint32_t pad_gpio1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPioc;

#endif