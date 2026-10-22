#ifndef CSR_BANK_ADAC_CTR_H_
#define CSR_BANK_ADAC_CTR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adac_ctr  ***/
typedef struct csr_bank_adac_ctr {
	/* DAC00 10'h000 */
	union {
		uint32_t dac00; // word name
		struct {
			uint32_t dac_clk_start : 1;
			uint32_t : 7; // padding bits
			uint32_t dac_clk_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DAC01 10'h004 */
	union {
		uint32_t dac01; // word name
		struct {
			uint32_t endac : 1;
			uint32_t : 7; // padding bits
			uint32_t mute : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DAC02 10'h008 */
	union {
		uint32_t dac02; // word name
		struct {
			uint32_t format : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DAC03 10'h00C */
	union {
		uint32_t dac03; // word name
		struct {
			uint32_t factor_l : 32;
		};
	};
	/* DAC04 10'h010 */
	union {
		uint32_t dac04; // word name
		struct {
			uint32_t factor_h : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DAC05 10'h014 [Unused] */
	uint32_t empty_word_dac05;
	/* DAC06 10'h018 [Unused] */
	uint32_t empty_word_dac06;
	/* DAC07 10'h01C */
	union {
		uint32_t dac07; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DAC08 10'h020 [Unused] */
	uint32_t empty_word_dac08;
	/* DAC09 10'h024 [Unused] */
	uint32_t empty_word_dac09;
	/* DAC10 10'h028 [Unused] */
	uint32_t empty_word_dac10;
	/* DAC11 10'h02C [Unused] */
	uint32_t empty_word_dac11;
	/* DAC12 10'h030 [Unused] */
	uint32_t empty_word_dac12;
	/* DAC13 10'h034 */
	union {
		uint32_t dac13; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankAdac_ctr;

#endif