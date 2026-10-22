/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_GPIOC_H_
#define CSR_TABLE_GPIOC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_gpioc[] = {
	// WORD pmu_gpio_o
	{ "pmu_gpio_o_0", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "PMU_GPIO_O", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD pmu_gpio_oe
	{ "pmu_gpio_oe_0", 0x00000004, 2, 0, CSR_RW, 0x00000000 },
	{ "PMU_GPIO_OE", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD pmu_gpio_i
	{ "pmu_gpio_i_0", 0x00000008, 2, 0, CSR_RO, 0x00000000 },
	{ "PMU_GPIO_I", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD pmu_off_gpio_i
	{ "pmu_off_gpio_i_0", 0x0000000C, 2, 0, CSR_RO, 0x00000000 },
	{ "PMU_OFF_GPIO_I", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_gpio_o_0
	{ "gpio_o_0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_GPIO_O_0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_gpio_oe_0
	{ "gpio_oe_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_GPIO_OE_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_gpio_i_0
	{ "gpio_i_0", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "WORD_GPIO_I_0", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_gpio_ie_0
	{ "gpio_ie_0", 0x0000001C, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "WORD_GPIO_IE_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_gpio_o_1
	{ "gpio_o_1", 0x00000020, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_GPIO_O_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_gpio_oe_1
	{ "gpio_oe_1", 0x00000024, 16, 0, CSR_RW, 0x00000000 },
	{ "WORD_GPIO_OE_1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_gpio_i_1
	{ "gpio_i_1", 0x00000028, 16, 0, CSR_RO, 0x00000000 },
	{ "WORD_GPIO_I_1", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_gpio_ie_1
	{ "gpio_ie_1", 0x0000002C, 16, 0, CSR_RW, 0x0001FFFF },
	{ "WORD_GPIO_IE_1", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mipi_rx_gpio_i_0
	{ "mipi_rx_gpio_i_0", 0x00000030, 7, 0, CSR_RO, 0x00000000 },
	{ "WORD_MIPI_RX_GPIO_I_0", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_sdc_gpi_sel
	{ "sdc0_wp_gpi_sel_r", 0x00000034, 5, 0, CSR_RW, 0x0000003F },
	{ "sdc0_cd_gpi_sel_r", 0x00000034, 13, 8, CSR_RW, 0x0000003F },
	{ "sdc1_wp_gpi_sel_r", 0x00000034, 21, 16, CSR_RW, 0x0000003F },
	{ "sdc1_cd_gpi_sel_r", 0x00000034, 29, 24, CSR_RW, 0x0000003F },
	{ "WORD_SDC_GPI_SEL", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_GPIOC_H_
