/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AON_H_
#define CSR_BANK_AON_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from aon  ***/
typedef struct csr_bank_aon {
	/* CK_GEN 10'h000 */
	union {
		uint32_t ck_gen; // word name
		struct {
			uint32_t cken_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_misc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST_GEN 10'h004 */
	union {
		uint32_t rst_gen; // word name
		struct {
			uint32_t lv_rst_amc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_misc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SLEEP_CTRL 10'h008 */
	union {
		uint32_t sleep_ctrl; // word name
		struct {
			uint32_t sleep_pulse : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SLEEP_DLY 10'h00C */
	union {
		uint32_t sleep_dly; // word name
		struct {
			uint32_t sleep_dly_cnt : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROSC_CTRL 10'h010 */
	union {
		uint32_t rosc_ctrl; // word name
		struct {
			uint32_t rosc_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROSC_TRIM 10'h014 */
	union {
		uint32_t rosc_trim; // word name
		struct {
			uint32_t rosc_div_th : 8;
			uint32_t : 8; // padding bits
			uint32_t rosc_freqctrl : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROSC_WRITE 10'h018 */
	union {
		uint32_t rosc_write; // word name
		struct {
			uint32_t trim_pulse : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AON_STATUS 10'h01C */
	union {
		uint32_t aon_status; // word name
		struct {
			uint32_t uvlo_1v8_vsh : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAon;

#endif