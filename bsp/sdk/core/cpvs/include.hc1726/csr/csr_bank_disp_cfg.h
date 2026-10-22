/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DISP_CFG_H_
#define CSR_BANK_DISP_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from disp_cfg  ***/
typedef struct csr_bank_disp_cfg {
	/* CONF0_DISPR 10'h000 */
	union {
		uint32_t conf0_dispr; // word name
		struct {
			uint32_t cken_dispr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dispr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DISPR 10'h004 */
	union {
		uint32_t conf1_dispr; // word name
		struct {
			uint32_t sw_rst_dispr : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dispr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CS 10'h008 */
	union {
		uint32_t conf0_cs; // word name
		struct {
			uint32_t cken_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CS 10'h00C */
	union {
		uint32_t conf1_cs; // word name
		struct {
			uint32_t sw_rst_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_YUV422 10'h010 */
	union {
		uint32_t conf0_yuv422; // word name
		struct {
			uint32_t cken_yuv422 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_yuv422 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_YUV422 10'h014 */
	union {
		uint32_t conf1_yuv422; // word name
		struct {
			uint32_t sw_rst_yuv422 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_YUV444 10'h018 */
	union {
		uint32_t conf0_yuv444; // word name
		struct {
			uint32_t cken_yuv444 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_yuv444 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_YUV444 10'h01C */
	union {
		uint32_t conf1_yuv444; // word name
		struct {
			uint32_t sw_rst_yuv444 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_DOSD 10'h020 */
	union {
		uint32_t conf0_dosd; // word name
		struct {
			uint32_t cken_dosd : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dosd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DOSD 10'h024 */
	union {
		uint32_t conf1_dosd; // word name
		struct {
			uint32_t sw_rst_dosd : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dosd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_DCST 10'h028 */
	union {
		uint32_t conf0_dcst; // word name
		struct {
			uint32_t cken_dcst : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dcst : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DCST 10'h02C */
	union {
		uint32_t conf1_dcst; // word name
		struct {
			uint32_t sw_rst_dcst : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_DGMA 10'h030 */
	union {
		uint32_t conf0_dgma; // word name
		struct {
			uint32_t cken_dgma : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dgma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DGMA 10'h034 */
	union {
		uint32_t conf1_dgma; // word name
		struct {
			uint32_t sw_rst_dgma : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dgma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_DCS 10'h038 */
	union {
		uint32_t conf0_dcs; // word name
		struct {
			uint32_t cken_dcs : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dcs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DCS 10'h03C */
	union {
		uint32_t conf1_dcs; // word name
		struct {
			uint32_t sw_rst_dcs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_DCFA 10'h040 */
	union {
		uint32_t conf0_dcfa; // word name
		struct {
			uint32_t cken_dcfa : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dcfa : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DCFA 10'h044 */
	union {
		uint32_t conf1_dcfa; // word name
		struct {
			uint32_t sw_rst_dcfa : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_BUF 10'h048 */
	union {
		uint32_t conf0_buf; // word name
		struct {
			uint32_t cken_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_BUF 10'h04C */
	union {
		uint32_t conf1_buf; // word name
		struct {
			uint32_t sw_rst_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CTRL 10'h050 */
	union {
		uint32_t conf0_ctrl; // word name
		struct {
			uint32_t cken_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CTRL 10'h054 */
	union {
		uint32_t conf1_ctrl; // word name
		struct {
			uint32_t sw_rst_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDisp_cfg;

#endif