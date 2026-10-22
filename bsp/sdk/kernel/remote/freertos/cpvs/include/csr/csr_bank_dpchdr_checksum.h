#ifndef CSR_BANK_DPCHDR_CHECKSUM_H_
#define CSR_BANK_DPCHDR_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dpchdr_checksum  ***/
typedef struct csr_bank_dpchdr_checksum {
	/* CLR 10'h000 */
	union {
		uint32_t clr; // word name
		struct {
			uint32_t clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPC 10'h004 */
	union {
		uint32_t dpc; // word name
		struct {
			uint32_t checksum_dpc : 32;
		};
	};
	/* HDR 10'h008 */
	union {
		uint32_t hdr; // word name
		struct {
			uint32_t checksum_hdr : 32;
		};
	};
} CsrBankDpchdr_checksum;

#endif