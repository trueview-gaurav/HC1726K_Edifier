#ifndef CSR_BANK_ADACCFG_H_
#define CSR_BANK_ADACCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adaccfg  ***/
typedef struct csr_bank_adaccfg {
	/* ADACCFG00 8'h00 */
	union {
		uint32_t adaccfg00; // word name
		struct {
			uint32_t adac_endac : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_envbg : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADACCFG01 8'h04 [Unused] */
	uint32_t empty_word_adaccfg01;
	/* ADACCFG02 8'h08 */
	union {
		uint32_t adaccfg02; // word name
		struct {
			uint32_t adac_in_mon : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdaccfg;

#endif