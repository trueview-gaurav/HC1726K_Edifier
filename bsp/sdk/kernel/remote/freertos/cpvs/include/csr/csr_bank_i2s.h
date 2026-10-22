#ifndef CSR_BANK_I2S_H_
#define CSR_BANK_I2S_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from i2s  ***/
typedef struct csr_bank_i2s {
	/* I2S00 16'h0000 */
	union {
		uint32_t i2s00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S01 16'h0004 [Unused] */
	uint32_t empty_word_i2s01;
	/* I2S02 16'h0008 [Unused] */
	uint32_t empty_word_i2s02;
	/* I2S03 16'h000C [Unused] */
	uint32_t empty_word_i2s03;
	/* I2S04 16'h0010 */
	union {
		uint32_t i2s04; // word name
		struct {
			uint32_t sd_format : 1;
			uint32_t : 7; // padding bits
			uint32_t master_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t use_sck_inter : 1;
			uint32_t : 7; // padding bits
			uint32_t use_ws_inter : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* I2S05 16'h0014 */
	union {
		uint32_t i2s05; // word name
		struct {
			uint32_t master_sck_0_cycle : 8;
			uint32_t : 8; // padding bits
			uint32_t master_sck_1_cycle : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* I2S06 16'h0018 */
	union {
		uint32_t i2s06; // word name
		struct {
			uint32_t master_ws_len : 9;
			uint32_t : 7; // padding bits
			uint32_t master_sd_len : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* I2S07 16'h001C */
	union {
		uint32_t i2s07; // word name
		struct {
			uint32_t sck_deglitch_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ws_deglitch_en : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_deglitch_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S08 16'h0020 */
	union {
		uint32_t i2s08; // word name
		struct {
			uint32_t sck_deglitch_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t ws_deglitch_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_deglitch_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S09 16'h0024 */
	union {
		uint32_t i2s09; // word name
		struct {
			uint32_t sck_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t ws_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t sd_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S10 16'h0028 */
	union {
		uint32_t i2s10; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t mute : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2S11 16'h002C */
	union {
		uint32_t i2s11; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* I2S12 16'h0030 */
	union {
		uint32_t i2s12; // word name
		struct {
			uint32_t output_sck_inter : 1;
			uint32_t : 7; // padding bits
			uint32_t output_ws_inter : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankI2s;

#endif