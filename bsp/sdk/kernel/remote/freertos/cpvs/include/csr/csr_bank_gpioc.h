#ifndef CSR_BANK_GPIOC_H_
#define CSR_BANK_GPIOC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from gpioc  ***/
typedef struct csr_bank_gpioc {
	/* AON_GPIO_O 10'h000 */
	union {
		uint32_t aon_gpio_o; // word name
		struct {
			uint32_t aon_gpio_o_0 : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AON_GPIO_OE 10'h004 */
	union {
		uint32_t aon_gpio_oe; // word name
		struct {
			uint32_t aon_gpio_oe_0 : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AON_GPIO_I 10'h008 */
	union {
		uint32_t aon_gpio_i; // word name
		struct {
			uint32_t aon_gpio_i_0 : 13;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GPIO_O_0 10'h00C */
	union {
		uint32_t word_gpio_o_0; // word name
		struct {
			uint32_t gpio_o_0 : 32;
		};
	};
	/* WORD_GPIO_OE_0 10'h010 */
	union {
		uint32_t word_gpio_oe_0; // word name
		struct {
			uint32_t gpio_oe_0 : 32;
		};
	};
	/* WORD_GPIO_I_0 10'h014 */
	union {
		uint32_t word_gpio_i_0; // word name
		struct {
			uint32_t gpio_i_0 : 32;
		};
	};
	/* WORD_GPIO_O_1 10'h018 */
	union {
		uint32_t word_gpio_o_1; // word name
		struct {
			uint32_t gpio_o_1 : 32;
		};
	};
	/* WORD_GPIO_OE_1 10'h01C */
	union {
		uint32_t word_gpio_oe_1; // word name
		struct {
			uint32_t gpio_oe_1 : 32;
		};
	};
	/* WORD_GPIO_I_1 10'h020 */
	union {
		uint32_t word_gpio_i_1; // word name
		struct {
			uint32_t gpio_i_1 : 32;
		};
	};
	/* WORD_GPIO_O_2 10'h024 */
	union {
		uint32_t word_gpio_o_2; // word name
		struct {
			uint32_t gpio_o_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GPIO_OE_2 10'h028 */
	union {
		uint32_t word_gpio_oe_2; // word name
		struct {
			uint32_t gpio_oe_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* undefined word 0x2C [Undefined] */
	uint32_t undefined_word_0x2C;
	/* WORD_GPIO_I_2 10'h030 */
	union {
		uint32_t word_gpio_i_2; // word name
		struct {
			uint32_t gpio_i_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MIPI_TX_GPIO_O_0 10'h034 */
	union {
		uint32_t word_mipi_tx_gpio_o_0; // word name
		struct {
			uint32_t mipi_tx_gpio_o_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MIPI_RX_GPIO_I_0 10'h038 */
	union {
		uint32_t word_mipi_rx_gpio_i_0; // word name
		struct {
			uint32_t mipi_rx_gpio_i_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_MIPI_RX_GPIO_I_1 10'h03C */
	union {
		uint32_t word_mipi_rx_gpio_i_1; // word name
		struct {
			uint32_t mipi_rx_gpio_i_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankGpioc;

#endif