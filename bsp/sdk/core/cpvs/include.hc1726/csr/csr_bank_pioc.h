/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PIOC_H_
#define CSR_BANK_PIOC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pioc  ***/
typedef struct csr_bank_pioc {
	/* TEST_SEL 10'h000 */
	union {
		uint32_t test_sel; // word name
		struct {
			uint32_t tst_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PWM0_PCFG 10'h004 */
	union {
		uint32_t word_pad_pwm0_pcfg; // word name
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
	/* WORD_PAD_PWM1_PCFG 10'h008 */
	union {
		uint32_t word_pad_pwm1_pcfg; // word name
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
	/* WORD_PAD_PWM3_PCFG 10'h00C */
	union {
		uint32_t word_pad_pwm3_pcfg; // word name
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
	/* WORD_PAD_UART1_TXD_PCFG 10'h010 */
	union {
		uint32_t word_pad_uart1_txd_pcfg; // word name
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
	/* WORD_PAD_UART1_RXD_PCFG 10'h014 */
	union {
		uint32_t word_pad_uart1_rxd_pcfg; // word name
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
	/* WORD_PAD_SD_CD_PCFG 10'h018 */
	union {
		uint32_t word_pad_sd_cd_pcfg; // word name
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
	/* WORD_PAD_SD_D2_PCFG 10'h01C */
	union {
		uint32_t word_pad_sd_d2_pcfg; // word name
		struct {
			uint32_t pad_sd_d2_pu : 1;
			uint32_t pad_sd_d2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d2_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D3_PCFG 10'h020 */
	union {
		uint32_t word_pad_sd_d3_pcfg; // word name
		struct {
			uint32_t pad_sd_d3_pu : 1;
			uint32_t pad_sd_d3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d3_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CMD_PCFG 10'h024 */
	union {
		uint32_t word_pad_sd_cmd_pcfg; // word name
		struct {
			uint32_t pad_sd_cmd_pu : 1;
			uint32_t pad_sd_cmd_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_cmd_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CK_PCFG 10'h028 */
	union {
		uint32_t word_pad_sd_ck_pcfg; // word name
		struct {
			uint32_t pad_sd_ck_pu : 1;
			uint32_t pad_sd_ck_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_ck_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D0_PCFG 10'h02C */
	union {
		uint32_t word_pad_sd_d0_pcfg; // word name
		struct {
			uint32_t pad_sd_d0_pu : 1;
			uint32_t pad_sd_d0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D1_PCFG 10'h030 */
	union {
		uint32_t word_pad_sd_d1_pcfg; // word name
		struct {
			uint32_t pad_sd_d1_pu : 1;
			uint32_t pad_sd_d1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sd_d1_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_CE_N_PCFG 10'h034 */
	union {
		uint32_t word_pad_qspi_ce_n_pcfg; // word name
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
	/* WORD_PAD_QSPI_D1_PCFG 10'h038 */
	union {
		uint32_t word_pad_qspi_d1_pcfg; // word name
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
	/* WORD_PAD_QSPI_D2_PCFG 10'h03C */
	union {
		uint32_t word_pad_qspi_d2_pcfg; // word name
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
	/* WORD_PAD_QSPI_D3_PCFG 10'h040 */
	union {
		uint32_t word_pad_qspi_d3_pcfg; // word name
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
	/* WORD_PAD_QSPI_CK_PCFG 10'h044 */
	union {
		uint32_t word_pad_qspi_ck_pcfg; // word name
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
	/* WORD_PAD_QSPI_D0_PCFG 10'h048 */
	union {
		uint32_t word_pad_qspi_d0_pcfg; // word name
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
	/* WORD_PAD_EPHY_RST_PCFG 10'h04C */
	union {
		uint32_t word_pad_ephy_rst_pcfg; // word name
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
	/* WORD_PAD_EMAC_TX_CK_PCFG 10'h050 */
	union {
		uint32_t word_pad_emac_tx_ck_pcfg; // word name
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
	/* WORD_PAD_EMAC_TX_CTL_PCFG 10'h054 */
	union {
		uint32_t word_pad_emac_tx_ctl_pcfg; // word name
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
	/* WORD_PAD_EMAC_TX_D1_PCFG 10'h058 */
	union {
		uint32_t word_pad_emac_tx_d1_pcfg; // word name
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
	/* WORD_PAD_EMAC_TX_D0_PCFG 10'h05C */
	union {
		uint32_t word_pad_emac_tx_d0_pcfg; // word name
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
	/* WORD_PAD_EMAC_RX_CK_PCFG 10'h060 */
	union {
		uint32_t word_pad_emac_rx_ck_pcfg; // word name
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
	/* WORD_PAD_EMAC_RX_D0_PCFG 10'h064 */
	union {
		uint32_t word_pad_emac_rx_d0_pcfg; // word name
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
	/* WORD_PAD_EMAC_RX_D1_PCFG 10'h068 */
	union {
		uint32_t word_pad_emac_rx_d1_pcfg; // word name
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
	/* WORD_PAD_EMAC_RX_CTL_PCFG 10'h06C */
	union {
		uint32_t word_pad_emac_rx_ctl_pcfg; // word name
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
	/* WORD_PAD_EMAC_MDC_PCFG 10'h070 */
	union {
		uint32_t word_pad_emac_mdc_pcfg; // word name
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
	/* WORD_PAD_EMAC_MDIO_PCFG 10'h074 */
	union {
		uint32_t word_pad_emac_mdio_pcfg; // word name
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
	/* WORD_PAD_I2C2_SCL_PCFG 10'h078 */
	union {
		uint32_t word_pad_i2c2_scl_pcfg; // word name
		struct {
			uint32_t pad_i2c2_scl_pu : 1;
			uint32_t pad_i2c2_scl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c2_scl_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C2_SDA_PCFG 10'h07C */
	union {
		uint32_t word_pad_i2c2_sda_pcfg; // word name
		struct {
			uint32_t pad_i2c2_sda_pu : 1;
			uint32_t pad_i2c2_sda_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c2_sda_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_GPIO31_PCFG 10'h080 */
	union {
		uint32_t word_pad_gpio31_pcfg; // word name
		struct {
			uint32_t pad_gpio31_pu : 1;
			uint32_t pad_gpio31_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio31_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_HSYNC_PCFG 10'h084 */
	union {
		uint32_t word_pad_dvp_hsync_pcfg; // word name
		struct {
			uint32_t pad_dvp_hsync_pu : 1;
			uint32_t pad_dvp_hsync_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_dvp_hsync_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_VSYNC_PCFG 10'h088 */
	union {
		uint32_t word_pad_dvp_vsync_pcfg; // word name
		struct {
			uint32_t pad_dvp_vsync_pu : 1;
			uint32_t pad_dvp_vsync_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_dvp_vsync_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_D7_PCFG 10'h08C */
	union {
		uint32_t word_pad_dvp_d7_pcfg; // word name
		struct {
			uint32_t pad_dvp_d7_pu : 1;
			uint32_t pad_dvp_d7_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_dvp_d7_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_D6_PCFG 10'h090 */
	union {
		uint32_t word_pad_dvp_d6_pcfg; // word name
		struct {
			uint32_t pad_dvp_d6_pu : 1;
			uint32_t pad_dvp_d6_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_dvp_d6_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_MIPI_SEL0_PCFG 10'h094 */
	union {
		uint32_t word_pad_mipi_sel0_pcfg; // word name
		struct {
			uint32_t pad_mipi_sel0_pu : 1;
			uint32_t pad_mipi_sel0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_mipi_sel0_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SENSOR_CLK_PCFG 10'h098 */
	union {
		uint32_t word_pad_sensor_clk_pcfg; // word name
		struct {
			uint32_t pad_sensor_clk_pu : 1;
			uint32_t pad_sensor_clk_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_sensor_clk_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C0_SCL_PCFG 10'h09C */
	union {
		uint32_t word_pad_i2c0_scl_pcfg; // word name
		struct {
			uint32_t pad_i2c0_scl_pu : 1;
			uint32_t pad_i2c0_scl_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c0_scl_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C0_SDA_PCFG 10'h0A0 */
	union {
		uint32_t word_pad_i2c0_sda_pcfg; // word name
		struct {
			uint32_t pad_i2c0_sda_pu : 1;
			uint32_t pad_i2c0_sda_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_i2c0_sda_pcfg : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_ADC_CH0_PCFG 10'h0A4 */
	union {
		uint32_t word_pad_adc_ch0_pcfg; // word name
		struct {
			uint32_t pad_adc_ch0_pu : 1;
			uint32_t pad_adc_ch0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_adc_ch0_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_GPIO41_PCFG 10'h0A8 */
	union {
		uint32_t word_pad_gpio41_pcfg; // word name
		struct {
			uint32_t pad_gpio41_pu : 1;
			uint32_t pad_gpio41_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio41_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_GPIO42_PCFG 10'h0AC */
	union {
		uint32_t word_pad_gpio42_pcfg; // word name
		struct {
			uint32_t pad_gpio42_pu : 1;
			uint32_t pad_gpio42_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_gpio42_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C1_SCL_PCFG 10'h0B0 */
	union {
		uint32_t word_pad_i2c1_scl_pcfg; // word name
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
	/* WORD_PAD_I2C1_SDA_PCFG 10'h0B4 */
	union {
		uint32_t word_pad_i2c1_sda_pcfg; // word name
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
	/* WORD_PAD_UART0_TXD_PCFG 10'h0B8 */
	union {
		uint32_t word_pad_uart0_txd_pcfg; // word name
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
	/* WORD_PAD_UART0_RXD_PCFG 10'h0BC */
	union {
		uint32_t word_pad_uart0_rxd_pcfg; // word name
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
	/* WORD_PAD_UART0_RTS_PCFG 10'h0C0 */
	union {
		uint32_t word_pad_uart0_rts_pcfg; // word name
		struct {
			uint32_t pad_uart0_rts_pu : 1;
			uint32_t pad_uart0_rts_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart0_rts_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_CTS_PCFG 10'h0C4 */
	union {
		uint32_t word_pad_uart0_cts_pcfg; // word name
		struct {
			uint32_t pad_uart0_cts_pu : 1;
			uint32_t pad_uart0_cts_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_uart0_cts_pcfg : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PWM0_IOSEL 10'h0C8 */
	union {
		uint32_t word_pad_pwm0_iosel; // word name
		struct {
			uint32_t pad_pwm0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PWM1_IOSEL 10'h0CC */
	union {
		uint32_t word_pad_pwm1_iosel; // word name
		struct {
			uint32_t pad_pwm1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_PWM3_IOSEL 10'h0D0 */
	union {
		uint32_t word_pad_pwm3_iosel; // word name
		struct {
			uint32_t pad_pwm3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART1_TXD_IOSEL 10'h0D4 */
	union {
		uint32_t word_pad_uart1_txd_iosel; // word name
		struct {
			uint32_t pad_uart1_txd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART1_RXD_IOSEL 10'h0D8 */
	union {
		uint32_t word_pad_uart1_rxd_iosel; // word name
		struct {
			uint32_t pad_uart1_rxd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CD_IOSEL 10'h0DC */
	union {
		uint32_t word_pad_sd_cd_iosel; // word name
		struct {
			uint32_t pad_sd_cd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D2_IOSEL 10'h0E0 */
	union {
		uint32_t word_pad_sd_d2_iosel; // word name
		struct {
			uint32_t pad_sd_d2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D3_IOSEL 10'h0E4 */
	union {
		uint32_t word_pad_sd_d3_iosel; // word name
		struct {
			uint32_t pad_sd_d3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CMD_IOSEL 10'h0E8 */
	union {
		uint32_t word_pad_sd_cmd_iosel; // word name
		struct {
			uint32_t pad_sd_cmd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_CK_IOSEL 10'h0EC */
	union {
		uint32_t word_pad_sd_ck_iosel; // word name
		struct {
			uint32_t pad_sd_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D0_IOSEL 10'h0F0 */
	union {
		uint32_t word_pad_sd_d0_iosel; // word name
		struct {
			uint32_t pad_sd_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SD_D1_IOSEL 10'h0F4 */
	union {
		uint32_t word_pad_sd_d1_iosel; // word name
		struct {
			uint32_t pad_sd_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_CE_N_IOSEL 10'h0F8 */
	union {
		uint32_t word_pad_qspi_ce_n_iosel; // word name
		struct {
			uint32_t pad_qspi_ce_n_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_D1_IOSEL 10'h0FC */
	union {
		uint32_t word_pad_qspi_d1_iosel; // word name
		struct {
			uint32_t pad_qspi_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_D2_IOSEL 10'h100 */
	union {
		uint32_t word_pad_qspi_d2_iosel; // word name
		struct {
			uint32_t pad_qspi_d2_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_D3_IOSEL 10'h104 */
	union {
		uint32_t word_pad_qspi_d3_iosel; // word name
		struct {
			uint32_t pad_qspi_d3_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_CK_IOSEL 10'h108 */
	union {
		uint32_t word_pad_qspi_ck_iosel; // word name
		struct {
			uint32_t pad_qspi_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_QSPI_D0_IOSEL 10'h10C */
	union {
		uint32_t word_pad_qspi_d0_iosel; // word name
		struct {
			uint32_t pad_qspi_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EPHY_RST_IOSEL 10'h110 */
	union {
		uint32_t word_pad_ephy_rst_iosel; // word name
		struct {
			uint32_t pad_ephy_rst_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_TX_CK_IOSEL 10'h114 */
	union {
		uint32_t word_pad_emac_tx_ck_iosel; // word name
		struct {
			uint32_t pad_emac_tx_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_TX_CTL_IOSEL 10'h118 */
	union {
		uint32_t word_pad_emac_tx_ctl_iosel; // word name
		struct {
			uint32_t pad_emac_tx_ctl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_TX_D1_IOSEL 10'h11C */
	union {
		uint32_t word_pad_emac_tx_d1_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_TX_D0_IOSEL 10'h120 */
	union {
		uint32_t word_pad_emac_tx_d0_iosel; // word name
		struct {
			uint32_t pad_emac_tx_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_RX_CK_IOSEL 10'h124 */
	union {
		uint32_t word_pad_emac_rx_ck_iosel; // word name
		struct {
			uint32_t pad_emac_rx_ck_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_RX_D0_IOSEL 10'h128 */
	union {
		uint32_t word_pad_emac_rx_d0_iosel; // word name
		struct {
			uint32_t pad_emac_rx_d0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_RX_D1_IOSEL 10'h12C */
	union {
		uint32_t word_pad_emac_rx_d1_iosel; // word name
		struct {
			uint32_t pad_emac_rx_d1_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_RX_CTL_IOSEL 10'h130 */
	union {
		uint32_t word_pad_emac_rx_ctl_iosel; // word name
		struct {
			uint32_t pad_emac_rx_ctl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_MDC_IOSEL 10'h134 */
	union {
		uint32_t word_pad_emac_mdc_iosel; // word name
		struct {
			uint32_t pad_emac_mdc_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_EMAC_MDIO_IOSEL 10'h138 */
	union {
		uint32_t word_pad_emac_mdio_iosel; // word name
		struct {
			uint32_t pad_emac_mdio_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C2_SCL_IOSEL 10'h13C */
	union {
		uint32_t word_pad_i2c2_scl_iosel; // word name
		struct {
			uint32_t pad_i2c2_scl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C2_SDA_IOSEL 10'h140 */
	union {
		uint32_t word_pad_i2c2_sda_iosel; // word name
		struct {
			uint32_t pad_i2c2_sda_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_GPIO31_IOSEL 10'h144 */
	union {
		uint32_t word_pad_gpio31_iosel; // word name
		struct {
			uint32_t pad_gpio31_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_HSYNC_IOSEL 10'h148 */
	union {
		uint32_t word_pad_dvp_hsync_iosel; // word name
		struct {
			uint32_t pad_dvp_hsync_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_VSYNC_IOSEL 10'h14C */
	union {
		uint32_t word_pad_dvp_vsync_iosel; // word name
		struct {
			uint32_t pad_dvp_vsync_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_D7_IOSEL 10'h150 */
	union {
		uint32_t word_pad_dvp_d7_iosel; // word name
		struct {
			uint32_t pad_dvp_d7_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_DVP_D6_IOSEL 10'h154 */
	union {
		uint32_t word_pad_dvp_d6_iosel; // word name
		struct {
			uint32_t pad_dvp_d6_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_MIPI_SEL0_IOSEL 10'h158 */
	union {
		uint32_t word_pad_mipi_sel0_iosel; // word name
		struct {
			uint32_t pad_mipi_sel0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_SENSOR_CLK_IOSEL 10'h15C */
	union {
		uint32_t word_pad_sensor_clk_iosel; // word name
		struct {
			uint32_t pad_sensor_clk_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C0_SCL_IOSEL 10'h160 */
	union {
		uint32_t word_pad_i2c0_scl_iosel; // word name
		struct {
			uint32_t pad_i2c0_scl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C0_SDA_IOSEL 10'h164 */
	union {
		uint32_t word_pad_i2c0_sda_iosel; // word name
		struct {
			uint32_t pad_i2c0_sda_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_ADC_CH0_IOSEL 10'h168 */
	union {
		uint32_t word_pad_adc_ch0_iosel; // word name
		struct {
			uint32_t pad_adc_ch0_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_GPIO41_IOSEL 10'h16C */
	union {
		uint32_t word_pad_gpio41_iosel; // word name
		struct {
			uint32_t pad_gpio41_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_GPIO42_IOSEL 10'h170 */
	union {
		uint32_t word_pad_gpio42_iosel; // word name
		struct {
			uint32_t pad_gpio42_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C1_SCL_IOSEL 10'h174 */
	union {
		uint32_t word_pad_i2c1_scl_iosel; // word name
		struct {
			uint32_t pad_i2c1_scl_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_I2C1_SDA_IOSEL 10'h178 */
	union {
		uint32_t word_pad_i2c1_sda_iosel; // word name
		struct {
			uint32_t pad_i2c1_sda_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_TXD_IOSEL 10'h17C */
	union {
		uint32_t word_pad_uart0_txd_iosel; // word name
		struct {
			uint32_t pad_uart0_txd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_RXD_IOSEL 10'h180 */
	union {
		uint32_t word_pad_uart0_rxd_iosel; // word name
		struct {
			uint32_t pad_uart0_rxd_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_RTS_IOSEL 10'h184 */
	union {
		uint32_t word_pad_uart0_rts_iosel; // word name
		struct {
			uint32_t pad_uart0_rts_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_PAD_UART0_CTS_IOSEL 10'h188 */
	union {
		uint32_t word_pad_uart0_cts_iosel; // word name
		struct {
			uint32_t pad_uart0_cts_iosel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPioc;

#endif