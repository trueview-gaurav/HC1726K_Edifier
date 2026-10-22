#ifndef CSR_BANK_SDMA_SYSCFG_H_
#define CSR_BANK_SDMA_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from sdma_syscfg  ***/
typedef struct csr_bank_sdma_syscfg {
	/* CFG_CG_DMAR 10'h000 */
	union {
		uint32_t cfg_cg_dmar; // word name
		struct {
			uint32_t cken_dmar_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dmar_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dmar_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_DMAR 10'h004 */
	union {
		uint32_t cfg_lv_rst_dmar; // word name
		struct {
			uint32_t lv_rst_dmar_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmar_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmar_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_DMAR 10'h008 */
	union {
		uint32_t cfg_sw_rst_dmar; // word name
		struct {
			uint32_t sw_rst_dmar_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dmar_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dmar_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_DMAW 10'h00C */
	union {
		uint32_t cfg_cg_dmaw; // word name
		struct {
			uint32_t cken_dmaw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dmaw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_dmaw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_DMAW 10'h010 */
	union {
		uint32_t cfg_lv_rst_dmaw; // word name
		struct {
			uint32_t lv_rst_dmaw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmaw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dmaw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_DMAW 10'h014 */
	union {
		uint32_t cfg_sw_rst_dmaw; // word name
		struct {
			uint32_t sw_rst_dmaw_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dmaw_d : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_dmaw_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_AES 10'h018 */
	union {
		uint32_t cfg_cg_aes; // word name
		struct {
			uint32_t cken_aes_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_aes_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_AES 10'h01C */
	union {
		uint32_t cfg_lv_rst_aes; // word name
		struct {
			uint32_t lv_rst_aes_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_aes_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_AES 10'h020 */
	union {
		uint32_t cfg_sw_rst_aes; // word name
		struct {
			uint32_t sw_rst_aes_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_aes_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_CG_LLI 10'h024 */
	union {
		uint32_t cfg_cg_lli; // word name
		struct {
			uint32_t cken_lli_k : 1;
			uint32_t : 7; // padding bits
			uint32_t cken_lli_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_LV_RST_LLI 10'h028 */
	union {
		uint32_t cfg_lv_rst_lli; // word name
		struct {
			uint32_t lv_rst_lli_k : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_lli_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_SW_RST_LLI 10'h02C */
	union {
		uint32_t cfg_sw_rst_lli; // word name
		struct {
			uint32_t sw_rst_lli_k : 1;
			uint32_t : 7; // padding bits
			uint32_t sw_rst_lli_p_clk_g : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankSdma_syscfg;

#endif