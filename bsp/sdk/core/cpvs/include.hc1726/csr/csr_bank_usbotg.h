/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_USBOTG_H_
#define CSR_BANK_USBOTG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from usbotg  ***/
typedef struct csr_bank_usbotg {
	/* IP00 8'h00 */
	union {
		uint32_t ip00; // word name
		struct {
			uint32_t ip : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankUsbotg;

#endif