#ifndef CSR_BANK_FM_H_
#define CSR_BANK_FM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from fm  ***/
typedef struct csr_bank_fm {
	/* FM00 10'h000 */
	union {
		uint32_t fm00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FM01 10'h004 */
	union {
		uint32_t fm01; // word name
		struct {
			uint32_t busy : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t done : 1;
			uint32_t : 7; // padding bits
			uint32_t : 7; // padding bits
			uint32_t pass : 1;
		};
	};
	/* FM02 10'h008 */
	union {
		uint32_t fm02; // word name
		struct {
			uint32_t cnt_th : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FM03 10'h00C */
	union {
		uint32_t fm03; // word name
		struct {
			uint32_t target : 15;
			uint32_t : 1; // padding bits
			uint32_t tolerance : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* FM04 10'h010 */
	union {
		uint32_t fm04; // word name
		struct {
			uint32_t clk_cnt : 10;
			uint32_t : 6; // padding bits
			uint32_t meas_cnt : 15;
			uint32_t : 1; // padding bits
		};
	};
} CsrBankFm;

#endif