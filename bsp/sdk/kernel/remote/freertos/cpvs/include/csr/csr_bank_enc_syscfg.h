#ifndef CSR_BANK_ENC_SYSCFG_H_
#define CSR_BANK_ENC_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from enc_syscfg  ***/
typedef struct csr_bank_enc_syscfg {
	/* CFG_SP 8'h00 */
	union {
		uint32_t cfg_sp; // word name
		struct {
			uint32_t cken_sp : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_sp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_W1P_SP 8'h04 */
	union {
		uint32_t cfg_w1p_sp; // word name
		struct {
			uint32_t sw_rst_sp : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_sp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_JPEG 8'h08 */
	union {
		uint32_t cfg_jpeg; // word name
		struct {
			uint32_t cken_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_W1P_JPEG 8'h0C */
	union {
		uint32_t cfg_w1p_jpeg; // word name
		struct {
			uint32_t sw_rst_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_jpeg : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_VENC 8'h10 */
	union {
		uint32_t cfg_venc; // word name
		struct {
			uint32_t cken_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_W1P_VENC 8'h14 */
	union {
		uint32_t cfg_w1p_venc; // word name
		struct {
			uint32_t sw_rst_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_venc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SRCR 8'h18 */
	union {
		uint32_t cfg_srcr; // word name
		struct {
			uint32_t cken_srcr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_srcr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_W1P_SRCR 8'h1C */
	union {
		uint32_t cfg_w1p_srcr; // word name
		struct {
			uint32_t sw_rst_srcr : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_srcr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_BSW 8'h20 */
	union {
		uint32_t cfg_bsw; // word name
		struct {
			uint32_t cken_bsw : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bsw : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_W1P_BSW 8'h24 */
	union {
		uint32_t cfg_w1p_bsw; // word name
		struct {
			uint32_t sw_rst_bsw : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_bsw : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_OSDR 8'h28 */
	union {
		uint32_t cfg_osdr; // word name
		struct {
			uint32_t cken_osdr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_osdr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_W1P_OSDR 8'h2C */
	union {
		uint32_t cfg_w1p_osdr; // word name
		struct {
			uint32_t sw_rst_osdr : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_osdr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEnc_syscfg;

#endif