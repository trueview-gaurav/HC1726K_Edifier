#ifndef CSR_BANK_PERI_H_
#define CSR_BANK_PERI_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from peri  ***/
typedef struct csr_bank_peri {
	/* PERI00 16'h00 */
	union {
		uint32_t peri00; // word name
		struct {
			uint32_t uart0_mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart1_mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart2_mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PERI01 16'h04 */
	union {
		uint32_t peri01; // word name
		struct {
			uint32_t uart3_mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart4_mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t uart5_mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PERI02 16'h08 */
	union {
		uint32_t peri02; // word name
		struct {
			uint32_t uart0_debug_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t uart1_debug_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t uart2_debug_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PERI03 16'h0C */
	union {
		uint32_t peri03; // word name
		struct {
			uint32_t uart3_debug_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t uart4_debug_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t uart5_debug_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PERI04 16'h10 */
	union {
		uint32_t peri04; // word name
		struct {
			uint32_t debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPeri;

#endif