#ifndef CSR_BANK_AON_H_
#define CSR_BANK_AON_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from aon  ***/
typedef struct csr_bank_aon {
	/* PSD_IN_CTRL 10'h000 */
	union {
		uint32_t psd_in_ctrl; // word name
		struct {
			uint32_t dvp_in_reverse : 1;
			uint32_t : 7; // padding bits
			uint32_t dvp_in_big_endian : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AON_DEBUG 10'h004 */
	union {
		uint32_t aon_debug; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_LP_CTRL 10'h008 */
	union {
		uint32_t mem_lp_ctrl; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_0 10'h00C */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_1 10'h010 */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAon;

#endif