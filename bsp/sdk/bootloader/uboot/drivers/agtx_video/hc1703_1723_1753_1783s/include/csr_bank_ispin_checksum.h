#ifndef CSR_BANK_ISPIN_CHECKSUM_H_
#define CSR_BANK_ISPIN_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ispin_checksum  ***/
typedef struct csr_bank_ispin_checksum {
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
	/* ISPR0_0 10'h004 */
	union {
		uint32_t ispr0_0; // word name
		struct {
			uint32_t checksum_ispr0 : 32;
		};
	};
	/* ISPR0_1 10'h008 */
	union {
		uint32_t ispr0_1; // word name
		struct {
			uint32_t checksum_ispr0_data_0 : 32;
		};
	};
	/* ISPR0_2 10'h00C */
	union {
		uint32_t ispr0_2; // word name
		struct {
			uint32_t checksum_ispr0_data_1 : 32;
		};
	};
	/* ISPR0_3 10'h010 */
	union {
		uint32_t ispr0_3; // word name
		struct {
			uint32_t checksum_ispr0_data_2 : 32;
		};
	};
	/* ISPR1_0 10'h014 */
	union {
		uint32_t ispr1_0; // word name
		struct {
			uint32_t checksum_ispr1 : 32;
		};
	};
	/* ISPR1_1 10'h018 */
	union {
		uint32_t ispr1_1; // word name
		struct {
			uint32_t checksum_ispr1_data_0 : 32;
		};
	};
	/* ISPR1_2 10'h01C */
	union {
		uint32_t ispr1_2; // word name
		struct {
			uint32_t checksum_ispr1_data_1 : 32;
		};
	};
	/* ISPR1_3 10'h020 */
	union {
		uint32_t ispr1_3; // word name
		struct {
			uint32_t checksum_ispr1_data_2 : 32;
		};
	};
	/* PG0 10'h024 */
	union {
		uint32_t pg0; // word name
		struct {
			uint32_t checksum_pg0 : 32;
		};
	};
	/* PG1 10'h028 */
	union {
		uint32_t pg1; // word name
		struct {
			uint32_t checksum_pg1 : 32;
		};
	};
	/* GFX0 10'h02C */
	union {
		uint32_t gfx0; // word name
		struct {
			uint32_t checksum_gfx0 : 32;
		};
	};
	/* GFX1 10'h030 */
	union {
		uint32_t gfx1; // word name
		struct {
			uint32_t checksum_gfx1 : 32;
		};
	};
	/* CS0 10'h034 */
	union {
		uint32_t cs0; // word name
		struct {
			uint32_t checksum_cs0 : 32;
		};
	};
	/* CS1 10'h038 */
	union {
		uint32_t cs1; // word name
		struct {
			uint32_t checksum_cs1 : 32;
		};
	};
	/* PRD0 10'h03C */
	union {
		uint32_t prd0; // word name
		struct {
			uint32_t checksum_prd0 : 32;
		};
	};
	/* PRD1 10'h040 */
	union {
		uint32_t prd1; // word name
		struct {
			uint32_t checksum_prd1 : 32;
		};
	};
	/* BLD 10'h044 */
	union {
		uint32_t bld; // word name
		struct {
			uint32_t checksum_bld : 32;
		};
	};
} CsrBankIspin_checksum;

#endif