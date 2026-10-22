#ifndef CSR_BANK_EQOS_CFG_H_
#define CSR_BANK_EQOS_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from eqos_cfg  ***/
typedef struct csr_bank_eqos_cfg {
	/* MAC_CTRL 16'h000 */
	union {
		uint32_t mac_ctrl; // word name
		struct {
			uint32_t mac_spec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DIV_CTRL 16'h004 */
	union {
		uint32_t div_ctrl; // word name
		struct {
			uint32_t mac_1000m_div_num_m1 : 8;
			uint32_t mac_100m_div_num_m1 : 8;
			uint32_t mac_10m_div_num_m1 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* DIV_STA 16'h008 */
	union {
		uint32_t div_sta; // word name
		struct {
			uint32_t rgmii_div_num_load : 8;
			uint32_t rmii_div_num_load : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MAC_03 16'h00C [Unused] */
	uint32_t empty_word_mac_03;
	/* CFG_IRQ_STA_0 16'h010 */
	union {
		uint32_t cfg_irq_sta_0; // word name
		struct {
			uint32_t status_perch_tx : 1;
			uint32_t : 7; // padding bits
			uint32_t status_perch_rx : 1;
			uint32_t : 7; // padding bits
			uint32_t status_lpi_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t status_axi_lp_done : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFG_IRQ_STA_1 16'h014 */
	union {
		uint32_t cfg_irq_sta_1; // word name
		struct {
			uint32_t status_axi_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_IRQ_ACK_0 16'h018 */
	union {
		uint32_t cfg_irq_ack_0; // word name
		struct {
			uint32_t irq_clear_perch_tx : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_perch_rx : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_lpi_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_axi_lp_done : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFG_IRQ_ACK_1 16'h01C */
	union {
		uint32_t cfg_irq_ack_1; // word name
		struct {
			uint32_t irq_clear_axi_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG_IRQ_MSK_0 16'h020 */
	union {
		uint32_t cfg_irq_msk_0; // word name
		struct {
			uint32_t irq_mask_perch_tx : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_perch_rx : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_lpi_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_axi_lp_done : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CFG_IRQ_MSK_1 16'h024 */
	union {
		uint32_t cfg_irq_msk_1; // word name
		struct {
			uint32_t irq_mask_axi_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CG_USB 16'h028 [Unused] */
	uint32_t empty_word_cg_usb;
	/* AXI_LP_0 16'h02C */
	union {
		uint32_t axi_lp_0; // word name
		struct {
			uint32_t lp_enter : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_1 16'h030 */
	union {
		uint32_t axi_lp_1; // word name
		struct {
			uint32_t lp_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_2 16'h034 */
	union {
		uint32_t axi_lp_2; // word name
		struct {
			uint32_t lp_peri_auto : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_3 16'h038 */
	union {
		uint32_t axi_lp_3; // word name
		struct {
			uint32_t lp_status : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_0 16'h03C */
	union {
		uint32_t dbg_0; // word name
		struct {
			uint32_t debug_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_1 16'h040 */
	union {
		uint32_t dbg_1; // word name
		struct {
			uint32_t debug_sta : 32;
		};
	};
	/* PHY 16'h044 */
	union {
		uint32_t phy; // word name
		struct {
			uint32_t phy_rst : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_WRAPPER 16'h048 */
	union {
		uint32_t mem_wrapper; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEqos_cfg;

#endif