/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DISP_CHECKSUM_H_
#define CSR_BANK_DISP_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from disp_checksum  ***/
typedef struct csr_bank_disp_checksum {
	/* WORD_CLEAR 10'h000 */
	union {
		uint32_t word_clear; // word name
		struct {
			uint32_t clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DISPR 10'h004 */
	union {
		uint32_t dispr; // word name
		struct {
			uint32_t checksum_dispr : 32;
		};
	};
	/* PAT_GEN 10'h008 */
	union {
		uint32_t pat_gen; // word name
		struct {
			uint32_t checksum_pg : 32;
		};
	};
	/* DISP_CS 10'h00C */
	union {
		uint32_t disp_cs; // word name
		struct {
			uint32_t checksum_disp_cs : 32;
		};
	};
	/* PRD 10'h010 */
	union {
		uint32_t prd; // word name
		struct {
			uint32_t checksum_prd : 32;
		};
	};
	/* YUV422 10'h014 */
	union {
		uint32_t yuv422; // word name
		struct {
			uint32_t checksum_yuv420to422 : 32;
		};
	};
	/* YUV444_0 10'h018 */
	union {
		uint32_t yuv444_0; // word name
		struct {
			uint32_t checksum_yuv422to444_0 : 32;
		};
	};
	/* YUV444_1 10'h01C */
	union {
		uint32_t yuv444_1; // word name
		struct {
			uint32_t checksum_yuv422to444_1 : 32;
		};
	};
	/* DOSD0 10'h020 */
	union {
		uint32_t dosd0; // word name
		struct {
			uint32_t checksum_dosd_0 : 32;
		};
	};
	/* DOSD1 10'h024 */
	union {
		uint32_t dosd1; // word name
		struct {
			uint32_t checksum_dosd_1 : 32;
		};
	};
	/* DOSDR0 10'h028 */
	union {
		uint32_t dosdr0; // word name
		struct {
			uint32_t checksum_dosdr_0 : 32;
		};
	};
	/* DOSDR1 10'h02C */
	union {
		uint32_t dosdr1; // word name
		struct {
			uint32_t checksum_dosdr_1 : 32;
		};
	};
	/* DCS 10'h030 */
	union {
		uint32_t dcs; // word name
		struct {
			uint32_t checksum_dcs : 32;
		};
	};
	/* DCST0 10'h034 */
	union {
		uint32_t dcst0; // word name
		struct {
			uint32_t checksum_dcst_0 : 32;
		};
	};
	/* DCST1 10'h038 */
	union {
		uint32_t dcst1; // word name
		struct {
			uint32_t checksum_dcst_1 : 32;
		};
	};
	/* DGMA0 10'h03C */
	union {
		uint32_t dgma0; // word name
		struct {
			uint32_t checksum_dgma_0 : 32;
		};
	};
	/* DGMA1 10'h040 */
	union {
		uint32_t dgma1; // word name
		struct {
			uint32_t checksum_dgma_1 : 32;
		};
	};
	/* DCFA 10'h044 */
	union {
		uint32_t dcfa; // word name
		struct {
			uint32_t checksum_dcfa : 32;
		};
	};
} CsrBankDisp_checksum;

#endif