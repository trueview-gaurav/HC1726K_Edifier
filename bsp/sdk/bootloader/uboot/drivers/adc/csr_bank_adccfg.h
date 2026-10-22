/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADCCFG_H_
#define CSR_BANK_ADCCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adccfg  ***/
typedef struct csr_bank_adccfg {
	/* ADCCFG00 8'h00 */
	union {
		uint32_t adccfg00; // word name
		struct {
			uint32_t adc_enadc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADCCFG01 8'h04 */
	union {
		uint32_t adccfg01; // word name
		struct {
			uint32_t adc_selres : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADCCFG02 8'h08 */
	union {
		uint32_t adccfg02; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t adc_enctr : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADCCFG03 8'h0C */
	union {
		uint32_t adccfg03; // word name
		struct {
			uint32_t adc_out_mon : 12;
			uint32_t : 4; // padding bits
			uint32_t adc_ctrl_mon : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdccfg;

#endif
