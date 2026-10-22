#ifndef CSR_BANK_I2CS_H_
#define CSR_BANK_I2CS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from i2cs  ***/
typedef struct csr_bank_i2cs {
	/* I2CS00 16'h00 [Unused] */
	uint32_t empty_word_i2cs00;
	/* I2CS01 16'h04 */
	union {
		uint32_t i2cs01; // word name
		struct {
			uint32_t irq_clear_wake_up : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CS02 16'h08 */
	union {
		uint32_t i2cs02; // word name
		struct {
			uint32_t status_wake_up : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CS03 16'h0C */
	union {
		uint32_t i2cs03; // word name
		struct {
			uint32_t irq_mask_wake_up : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CS04 16'h10 */
	union {
		uint32_t i2cs04; // word name
		struct {
			uint32_t idle : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CS05 16'h14 */
	union {
		uint32_t i2cs05; // word name
		struct {
			uint32_t target_address : 7;
			uint32_t : 1; // padding bits
			uint32_t scl_deglitch_th : 8;
			uint32_t sda_deglitch_th : 8;
			uint32_t trans_size : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* I2CS06 16'h18 */
	union {
		uint32_t i2cs06; // word name
		struct {
			uint32_t efuse_dis_i2c_slave_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CS07 16'h1C */
	union {
		uint32_t i2cs07; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CS08 16'h20 */
	union {
		uint32_t i2cs08; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankI2cs;

#endif