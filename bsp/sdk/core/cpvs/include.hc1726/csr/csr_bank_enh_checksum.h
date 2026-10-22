/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ENH_CHECKSUM_H_
#define CSR_BANK_ENH_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from enh_checksum  ***/
typedef struct csr_bank_enh_checksum {
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
	/* ENH_Y 10'h004 */
	union {
		uint32_t enh_y; // word name
		struct {
			uint32_t checksum_enh_y : 32;
		};
	};
	/* SHP_Y 10'h008 */
	union {
		uint32_t shp_y; // word name
		struct {
			uint32_t checksum_shp_y : 32;
		};
	};
	/* SUBSAMPLE 10'h00C */
	union {
		uint32_t subsample; // word name
		struct {
			uint32_t checksum_subsample : 32;
		};
	};
	/* ENH_C 10'h010 */
	union {
		uint32_t enh_c; // word name
		struct {
			uint32_t checksum_enh_c : 32;
		};
	};
} CsrBankEnh_checksum;

#endif