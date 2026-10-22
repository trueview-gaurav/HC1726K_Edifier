/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DMA_8_C1_D64_SYSCFG_H_
#define CSR_BANK_DMA_8_C1_D64_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dma_8_c1_d64_syscfg  ***/
typedef struct csr_bank_dma_8_c1_d64_syscfg {
	/* CKG_DMA_K 10'h000 */
	union {
		uint32_t ckg_dma_k; // word name
		struct {
			uint32_t cken_dma_k_dummy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DMA_D 10'h004 */
	union {
		uint32_t ckg_dma_d; // word name
		struct {
			uint32_t cken_dma_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CKG_DMA_A 10'h008 */
	union {
		uint32_t ckg_dma_a; // word name
		struct {
			uint32_t cken_dma_a_dummy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV 10'h00C */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDma_8_c1_d64_syscfg;

#endif