/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ISP_CHECKSUM_H_
#define CSR_BANK_ISP_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isp_checksum  ***/
typedef struct csr_bank_isp_checksum {
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
	/* ISPIN0 10'h004 */
	union {
		uint32_t ispin0; // word name
		struct {
			uint32_t checksum_ispin0 : 32;
		};
	};
	/* ISPIN1 10'h008 */
	union {
		uint32_t ispin1; // word name
		struct {
			uint32_t checksum_ispin1 : 32;
		};
	};
	/* HDR 10'h00C */
	union {
		uint32_t hdr; // word name
		struct {
			uint32_t checksum_hdr : 32;
		};
	};
	/* BLD 10'h010 */
	union {
		uint32_t bld; // word name
		struct {
			uint32_t checksum_bld : 32;
		};
	};
	/* RGBP 10'h014 */
	union {
		uint32_t rgbp; // word name
		struct {
			uint32_t checksum_rgbp : 32;
		};
	};
	/* NR2D0 10'h018 */
	union {
		uint32_t nr2d0; // word name
		struct {
			uint32_t checksum_nr2d_0 : 32;
		};
	};
	/* NR2D1 10'h01C */
	union {
		uint32_t nr2d1; // word name
		struct {
			uint32_t checksum_nr2d_1 : 32;
		};
	};
	/* CCM0 10'h020 */
	union {
		uint32_t ccm0; // word name
		struct {
			uint32_t checksum_ccm_0 : 32;
		};
	};
	/* CCM1 10'h024 */
	union {
		uint32_t ccm1; // word name
		struct {
			uint32_t checksum_ccm_1 : 32;
		};
	};
	/* PCA 10'h028 */
	union {
		uint32_t pca; // word name
		struct {
			uint32_t checksum_pca : 32;
		};
	};
	/* SHP 10'h02C */
	union {
		uint32_t shp; // word name
		struct {
			uint32_t checksum_shp : 32;
		};
	};
	/* SC 10'h030 */
	union {
		uint32_t sc; // word name
		struct {
			uint32_t checksum_sc : 32;
		};
	};
	/* CUS 10'h034 */
	union {
		uint32_t cus; // word name
		struct {
			uint32_t checksum_cus : 32;
		};
	};
	/* CDS 10'h038 */
	union {
		uint32_t cds; // word name
		struct {
			uint32_t checksum_cds : 32;
		};
	};
} CsrBankIsp_checksum;

#endif