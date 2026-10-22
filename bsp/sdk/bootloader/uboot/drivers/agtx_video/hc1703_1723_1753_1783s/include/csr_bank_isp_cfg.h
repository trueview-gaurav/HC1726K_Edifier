#ifndef CSR_BANK_ISP_CFG_H_
#define CSR_BANK_ISP_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isp_cfg  ***/
typedef struct csr_bank_isp_cfg {
	/* CONF0_ISPR0 10'h000 */
	union {
		uint32_t conf0_ispr0; // word name
		struct {
			uint32_t cken_ispr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISPR0 10'h004 */
	union {
		uint32_t conf1_ispr0; // word name
		struct {
			uint32_t sw_rst_ispr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_ispr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISPR1 10'h008 */
	union {
		uint32_t conf0_ispr1; // word name
		struct {
			uint32_t cken_ispr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ispr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISPR1 10'h00C */
	union {
		uint32_t conf1_ispr1; // word name
		struct {
			uint32_t sw_rst_ispr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_ispr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_GFX0 10'h010 */
	union {
		uint32_t conf0_gfx0; // word name
		struct {
			uint32_t cken_gfx0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_gfx0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_GFX0 10'h014 */
	union {
		uint32_t conf1_gfx0; // word name
		struct {
			uint32_t sw_rst_gfx0 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_gfx0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_GFX1 10'h018 */
	union {
		uint32_t conf0_gfx1; // word name
		struct {
			uint32_t cken_gfx1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_gfx1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_GFX1 10'h01C */
	union {
		uint32_t conf1_gfx1; // word name
		struct {
			uint32_t sw_rst_gfx1 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_gfx1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CS0 10'h020 */
	union {
		uint32_t conf0_cs0; // word name
		struct {
			uint32_t cken_cs0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CS0 10'h024 */
	union {
		uint32_t conf1_cs0; // word name
		struct {
			uint32_t sw_rst_cs0 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_cs0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CS1 10'h028 */
	union {
		uint32_t conf0_cs1; // word name
		struct {
			uint32_t cken_cs1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CS1 10'h02C */
	union {
		uint32_t conf1_cs1; // word name
		struct {
			uint32_t sw_rst_cs1 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_cs1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_GFXBLD 10'h030 */
	union {
		uint32_t conf0_gfxbld; // word name
		struct {
			uint32_t cken_gfxbld : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_gfxbld : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_GFXBLD 10'h034 */
	union {
		uint32_t conf1_gfxbld; // word name
		struct {
			uint32_t sw_rst_gfxbld : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_gfxbld : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_DPC 10'h038 */
	union {
		uint32_t conf0_dpc; // word name
		struct {
			uint32_t cken_dpc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dpc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_DPC 10'h03C */
	union {
		uint32_t conf1_dpc; // word name
		struct {
			uint32_t sw_rst_dpc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dpc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_HDR 10'h040 */
	union {
		uint32_t conf0_hdr; // word name
		struct {
			uint32_t cken_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_HDR 10'h044 */
	union {
		uint32_t conf1_hdr; // word name
		struct {
			uint32_t sw_rst_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_hdr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_RGBP 10'h048 */
	union {
		uint32_t conf0_rgbp; // word name
		struct {
			uint32_t cken_rgbp : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_rgbp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_RGBP 10'h04C */
	union {
		uint32_t conf1_rgbp; // word name
		struct {
			uint32_t sw_rst_rgbp : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_rgbp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_SC 10'h050 */
	union {
		uint32_t conf0_sc; // word name
		struct {
			uint32_t cken_sc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_sc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_SC 10'h054 */
	union {
		uint32_t conf1_sc; // word name
		struct {
			uint32_t sw_rst_sc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_sc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ENH 10'h058 */
	union {
		uint32_t conf0_enh; // word name
		struct {
			uint32_t cken_enh : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_enh : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ENH 10'h05C */
	union {
		uint32_t conf1_enh; // word name
		struct {
			uint32_t sw_rst_enh : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_enh : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CTRL 10'h060 */
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
	/* CONF1_CTRL 10'h064 */
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
} CsrBankIsp_cfg;

#endif