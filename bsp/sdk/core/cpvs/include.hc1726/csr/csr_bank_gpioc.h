/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_GPIOC_H_
#define CSR_BANK_GPIOC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from gpioc  ***/
typedef struct csr_bank_gpioc {
	/* PMU_GPIO_O 8'h00 */
	union {
		uint32_t pmu_gpio_o; // word name
		struct {
			uint32_t pmu_gpio_o_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PMU_GPIO_OE 8'h04 */
	union {
		uint32_t pmu_gpio_oe; // word name
		struct {
			uint32_t pmu_gpio_oe_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PMU_GPIO_I 8'h08 */
	union {
		uint32_t pmu_gpio_i; // word name
		struct {
			uint32_t pmu_gpio_i_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PMU_OFF_GPIO_I 8'h0C */
	union {
		uint32_t pmu_off_gpio_i; // word name
		struct {
			uint32_t pmu_off_gpio_i_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GPIO_O_0 8'h10 */
	union {
		uint32_t word_gpio_o_0; // word name
		struct {
			uint32_t gpio_o_0 : 32;
		};
	};
	/* WORD_GPIO_OE_0 8'h14 */
	union {
		uint32_t word_gpio_oe_0; // word name
		struct {
			uint32_t gpio_oe_0 : 32;
		};
	};
	/* WORD_GPIO_I_0 8'h18 */
	union {
		uint32_t word_gpio_i_0; // word name
		struct {
			uint32_t gpio_i_0 : 32;
		};
	};
	/* WORD_GPIO_IE_0 8'h1C */
	union {
		uint32_t word_gpio_ie_0; // word name
		struct {
			uint32_t gpio_ie_0 : 32;
		};
	};
	/* WORD_GPIO_O_1 8'h20 */
	union {
		uint32_t word_gpio_o_1; // word name
		struct {
			uint32_t gpio_o_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GPIO_OE_1 8'h24 */
	union {
		uint32_t word_gpio_oe_1; // word name
		struct {
			uint32_t gpio_oe_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GPIO_I_1 8'h28 */
	union {
		uint32_t word_gpio_i_1; // word name
		struct {
			uint32_t gpio_i_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GPIO_IE_1 8'h2C */
	union {
		uint32_t word_gpio_ie_1; // word name
		struct {
			uint32_t gpio_ie_1 : 17;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MIPI_RX_GPIO_I_0 8'h30 */
	union {
		uint32_t word_mipi_rx_gpio_i_0; // word name
		struct {
			uint32_t mipi_rx_gpio_i_0 : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SDC_GPI_SEL 8'h34 */
	union {
		uint32_t word_sdc_gpi_sel; // word name
		struct {
			uint32_t sdc0_wp_gpi_sel_r : 6;
			uint32_t : 2; // padding bits
			uint32_t sdc0_cd_gpi_sel_r : 6;
			uint32_t : 2; // padding bits
			uint32_t sdc1_wp_gpi_sel_r : 6;
			uint32_t : 2; // padding bits
			uint32_t sdc1_cd_gpi_sel_r : 6;
			uint32_t : 2; // padding bits
		};
	};
} CsrBankGpioc;

#endif