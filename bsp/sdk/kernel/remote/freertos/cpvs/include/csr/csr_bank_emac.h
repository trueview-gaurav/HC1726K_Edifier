#ifndef CSR_BANK_EMAC_H_
#define CSR_BANK_EMAC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from emac  ***/
typedef struct csr_bank_emac {
	/* IP00 13'h00 */
	union {
		uint32_t ip00; // word name
		struct {
			uint32_t ip : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEmac;

#endif