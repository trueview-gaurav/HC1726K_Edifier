/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_VP_CHECKSUM_H_
#define CSR_BANK_VP_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from vp_checksum  ***/
typedef struct csr_bank_vp_checksum {
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
	/* DHZ 10'h004 */
	union {
		uint32_t dhz; // word name
		struct {
			uint32_t checksum_dhz : 32;
		};
	};
	/* MCVP_NR_DISP0 10'h008 */
	union {
		uint32_t mcvp_nr_disp0; // word name
		struct {
			uint32_t checksum_mcvp_nr_disp_0 : 32;
		};
	};
	/* MCVP_NR_DISP1 10'h00C */
	union {
		uint32_t mcvp_nr_disp1; // word name
		struct {
			uint32_t checksum_mcvp_nr_disp_1 : 32;
		};
	};
	/* MCVP_NR_DISP2 10'h010 */
	union {
		uint32_t mcvp_nr_disp2; // word name
		struct {
			uint32_t checksum_mcvp_nr_disp_2 : 32;
		};
	};
	/* MCVP_NR_INK0 10'h014 */
	union {
		uint32_t mcvp_nr_ink0; // word name
		struct {
			uint32_t checksum_mcvp_nr_ink_0 : 32;
		};
	};
	/* MCVP_NR_INK1 10'h018 */
	union {
		uint32_t mcvp_nr_ink1; // word name
		struct {
			uint32_t checksum_mcvp_nr_ink_1 : 32;
		};
	};
	/* MCVP_NR_INK2 10'h01C */
	union {
		uint32_t mcvp_nr_ink2; // word name
		struct {
			uint32_t checksum_mcvp_nr_ink_2 : 32;
		};
	};
	/* UNPACKER 10'h020 */
	union {
		uint32_t unpacker; // word name
		struct {
			uint32_t checksum_unpacker : 32;
		};
	};
	/* B2R 10'h024 */
	union {
		uint32_t b2r; // word name
		struct {
			uint32_t checksum_b2r : 32;
		};
	};
	/* VPPUP0 10'h028 */
	union {
		uint32_t vppup0; // word name
		struct {
			uint32_t checksum_vppup0 : 32;
		};
	};
	/* VPPUP1 10'h02C */
	union {
		uint32_t vppup1; // word name
		struct {
			uint32_t checksum_vppup1 : 32;
		};
	};
	/* VPLP 10'h030 */
	union {
		uint32_t vplp; // word name
		struct {
			uint32_t checksum_vplp : 32;
		};
	};
} CsrBankVp_checksum;

#endif