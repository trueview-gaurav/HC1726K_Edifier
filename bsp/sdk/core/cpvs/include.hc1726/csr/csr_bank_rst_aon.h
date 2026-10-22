/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_RST_AON_H_
#define CSR_BANK_RST_AON_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rst_aon  ***/
typedef struct csr_bank_rst_aon {
	/* RST_AON_0 10'h000 */
	union {
		uint32_t rst_aon_0; // word name
		struct {
			uint32_t sw_rst_psdecoder : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_lpmd : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_rtc : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RST_AON_1 10'h004 */
	union {
		uint32_t rst_aon_1; // word name
		struct {
			uint32_t sw_rst_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_irq : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dvp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LVRST_AON_0 10'h008 */
	union {
		uint32_t lvrst_aon_0; // word name
		struct {
			uint32_t lv_rst_psdecoder : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_lpmd : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_wdt : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_rtc : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* LVRST_AON_1 10'h00C */
	union {
		uint32_t lvrst_aon_1; // word name
		struct {
			uint32_t lv_rst_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_irq : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dvp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AONRST04 10'h010 [Unused] */
	uint32_t empty_word_aonrst04;
	/* AONRST05 10'h014 [Unused] */
	uint32_t empty_word_aonrst05;
	/* WORD_RESERVED_0 10'h018 */
	union {
		uint32_t word_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RESERVED_1 10'h01C */
	union {
		uint32_t word_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankRst_aon;

#endif