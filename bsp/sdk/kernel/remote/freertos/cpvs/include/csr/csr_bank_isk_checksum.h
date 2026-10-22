#ifndef CSR_BANK_ISK_CHECKSUM_H_
#define CSR_BANK_ISK_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isk_checksum  ***/
typedef struct csr_bank_isk_checksum {
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
	/* AGMA 10'h004 */
	union {
		uint32_t agma; // word name
		struct {
			uint32_t checksum_agma : 32;
		};
	};
	/* FPNR 10'h008 */
	union {
		uint32_t fpnr; // word name
		struct {
			uint32_t checksum_fpnr : 32;
		};
	};
	/* CROP 10'h00C */
	union {
		uint32_t crop; // word name
		struct {
			uint32_t checksum_crop : 32;
		};
	};
	/* DBC 10'h010 */
	union {
		uint32_t dbc; // word name
		struct {
			uint32_t checksum_dbc : 32;
		};
	};
	/* DCC 10'h014 */
	union {
		uint32_t dcc; // word name
		struct {
			uint32_t checksum_dcc : 32;
		};
	};
	/* LSC 10'h018 */
	union {
		uint32_t lsc; // word name
		struct {
			uint32_t checksum_lsc : 32;
		};
	};
	/* DPCR 10'h01C */
	union {
		uint32_t dpcr; // word name
		struct {
			uint32_t checksum_dpcr : 32;
		};
	};
	/* BSP 10'h020 */
	union {
		uint32_t bsp; // word name
		struct {
			uint32_t checksum_bsp : 32;
		};
	};
	/* FGMA 10'h024 */
	union {
		uint32_t fgma; // word name
		struct {
			uint32_t checksum_fgma : 32;
		};
	};
	/* FSC 10'h028 */
	union {
		uint32_t fsc; // word name
		struct {
			uint32_t checksum_fsc : 32;
		};
	};
	/* YUV422TO420 10'h02C */
	union {
		uint32_t yuv422to420; // word name
		struct {
			uint32_t checksum_yuv422to420 : 32;
		};
	};
	/* CS 10'h030 */
	union {
		uint32_t cs; // word name
		struct {
			uint32_t checksum_cs : 32;
		};
	};
	/* INK 10'h034 */
	union {
		uint32_t ink; // word name
		struct {
			uint32_t checksum_ink : 32;
		};
	};
} CsrBankIsk_checksum;

#endif