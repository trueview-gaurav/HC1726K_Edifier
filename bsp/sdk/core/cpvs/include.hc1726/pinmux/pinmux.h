/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef PINMUX_H
#define PINMUX_H

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

enum pin_name {
	PAD_PWM0,
	PAD_PWM1,
	PAD_PWM3,
	PAD_UART1_TXD,
	PAD_UART1_RXD,
	PAD_SD_CD,
	PAD_SD_D2,
	PAD_SD_D3,
	PAD_SD_CMD,
	PAD_SD_CK,
	PAD_SD_D0,
	PAD_SD_D1,
	PAD_QSPI_CE_N,
	PAD_QSPI_D1,
	PAD_QSPI_D2,
	PAD_QSPI_D3,
	PAD_QSPI_CK,
	PAD_QSPI_D0,
	PAD_EPHY_RST,
	PAD_EMAC_TX_CK,
	PAD_EMAC_TX_CTL,
	PAD_EMAC_TX_D1,
	PAD_EMAC_TX_D0,
	PAD_EMAC_RX_CK,
	PAD_EMAC_RX_D0,
	PAD_EMAC_RX_D1,
	PAD_EMAC_RX_CTL,
	PAD_EMAC_MDC,
	PAD_EMAC_MDIO,
	PAD_I2C2_SCL,
	PAD_I2C2_SDA,
	PAD_GPIO31,
	PAD_DVP_HSYNC,
	PAD_DVP_VSYNC,
	PAD_DVP_D7,
	PAD_DVP_D6,
	PAD_MIPI_SEL0,
	PAD_SENSOR_CLK,
	PAD_I2C0_SCL,
	PAD_I2C0_SDA,
	PAD_ADC_CH0,
	PAD_GPIO41,
	PAD_GPIO42,
	PAD_I2C1_SCL,
	PAD_I2C1_SDA,
	PAD_UART0_TXD,
	PAD_UART0_RXD,
	PAD_UART0_RTS,
	PAD_UART0_CTS,
	PAD_PMU_PWR_CTRL,
	PAD_PMU_WAKEUP,
	PAD_PMU_BUTTON,
	//PAD_PIN_AMOUNT is for getting pins amount, please put PAD_PIN_AMOUNT at the last of enum pin_name
	PAD_PIN_AMOUNT,
};

struct pinctrl_machine_table {
	// current mux use 3 bits
	// current pud use 2 bits
	// current pcfg use 6 bits
	uint32_t mux : 3;
	uint32_t pud : 2;
	uint32_t pcfg : 6;
};

/*
 * pincfg_type: Supported pin configuration types
 * @PINCFG_PU & PINCFG_PD: Pull up/down
 * @PINCFG_DS: Driving strength
 * @PINCFG_ST: Schmitt trigger
 * @PINCFG_SL: Slew rate
 * @PINCFG_HE: Hold enable
 */
enum pincfg_type { PINCFG_PU, PINCFG_PD, PINCFG_DS, PINCFG_ST, PINCFG_SL, PINCFG_HE };

typedef enum {
	PD_3V3, //0~30, 40~48
	PD_1V8, //31~39
	PMU_1V8, //49~53
} PINCFG_CELL;

int pinmux_set_pinmux(enum pin_name name, uint32_t value);
int pinmux_get_pinmux(enum pin_name name, uint32_t *value);
int pinmux_set_pinconf(enum pin_name name, enum pincfg_type type, uint32_t value);
int pinmux_get_pinconf(enum pin_name name, enum pincfg_type type, uint32_t *value);
int _pinmux_init(struct pinctrl_machine_table table[], int check_pins_num);
#define pinmux_init(x) _pinmux_init(x, sizeof(x) / sizeof(struct pinctrl_machine_table))

#endif
