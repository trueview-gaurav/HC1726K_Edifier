/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PERI_H_
#define CSR_BANK_PERI_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from peri  ***/
typedef struct csr_bank_peri {
	/* UART_MD 16'h00 */
	union {
		uint32_t uart_md; // word name
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
	/* UART_DBUG 16'h04 */
	union {
		uint32_t uart_dbug; // word name
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
	/* PERI_DBUG 16'h08 */
	union {
		uint32_t peri_dbug; // word name
		struct {
			uint32_t debug_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankPeri;

#endif