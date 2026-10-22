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
	/* DPCHDR 10'h00C */
	union {
		uint32_t dpchdr; // word name
		struct {
			uint32_t checksum_dpchdr : 32;
		};
	};
	/* RGBP 10'h010 */
	union {
		uint32_t rgbp; // word name
		struct {
			uint32_t checksum_rgbp : 32;
		};
	};
	/* SC 10'h014 */
	union {
		uint32_t sc; // word name
		struct {
			uint32_t checksum_sc : 32;
		};
	};
	/* ENH 10'h018 */
	union {
		uint32_t enh; // word name
		struct {
			uint32_t checksum_enh : 32;
		};
	};
	/* DHZ 10'h01C */
	union {
		uint32_t dhz; // word name
		struct {
			uint32_t checksum_dhz : 32;
		};
	};
} CsrBankIsp_checksum;

#endif