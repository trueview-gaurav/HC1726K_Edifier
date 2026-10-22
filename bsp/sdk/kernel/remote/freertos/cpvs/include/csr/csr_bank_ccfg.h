#ifndef CSR_BANK_CCFG_H_
#define CSR_BANK_CCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from ccfg  ***/
typedef struct csr_bank_ccfg {
	/* DDRC_IRQ_STA_0 10'h000 */
	union {
		uint32_t ddrc_irq_sta_0; // word name
		struct {
			uint32_t status_perf_log_done : 1;
			uint32_t : 7; // padding bits
			uint32_t status_dramc_lp_done : 1;
			uint32_t : 7; // padding bits
			uint32_t status_dramc_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t status_axi_0_lp_done : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DDRC_IRQ_STA_1 10'h004 */
	union {
		uint32_t ddrc_irq_sta_1; // word name
		struct {
			uint32_t status_axi_0_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t status_axi_1_lp_done : 1;
			uint32_t : 7; // padding bits
			uint32_t status_axi_1_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t status_apb_slverr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DDRC_IRQ_STA_2 10'h008 */
	union {
		uint32_t ddrc_irq_sta_2; // word name
		struct {
			uint32_t status_axi_0_id_err : 1;
			uint32_t : 7; // padding bits
			uint32_t status_axi_1_id_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_IRQ_CLR_0 10'h00C */
	union {
		uint32_t ddrc_irq_clr_0; // word name
		struct {
			uint32_t irq_clear_perf_log_done : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_dramc_lp_done : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_dramc_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_axi_0_lp_done : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DDRC_IRQ_CLR_1 10'h010 */
	union {
		uint32_t ddrc_irq_clr_1; // word name
		struct {
			uint32_t irq_clear_axi_0_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_axi_1_lp_done : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_axi_1_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_apb_slverr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DDRC_IRQ_CLR_2 10'h014 */
	union {
		uint32_t ddrc_irq_clr_2; // word name
		struct {
			uint32_t irq_clear_axi_0_id_err : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_axi_1_id_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_IRQ_MSK_0 10'h018 */
	union {
		uint32_t ddrc_irq_msk_0; // word name
		struct {
			uint32_t irq_mask_perf_log_done : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_dramc_lp_done : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_dramc_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_axi_0_lp_done : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DDRC_IRQ_MSK_1 10'h01C */
	union {
		uint32_t ddrc_irq_msk_1; // word name
		struct {
			uint32_t irq_mask_axi_0_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_axi_1_lp_done : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_axi_1_lp_peri_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_apb_slverr : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DDRC_IRQ_MSK_2 10'h020 */
	union {
		uint32_t ddrc_irq_msk_2; // word name
		struct {
			uint32_t irq_mask_axi_0_id_err : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_axi_1_id_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_MISC_00 10'h024 */
	union {
		uint32_t ddrc_misc_00; // word name
		struct {
			uint32_t lpr_credit_cnt : 7;
			uint32_t : 1; // padding bits
			uint32_t hpr_credit_cnt : 7;
			uint32_t : 1; // padding bits
			uint32_t wr_credit_cnt : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_MISC_01 10'h028 */
	union {
		uint32_t ddrc_misc_01; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t selfref_type : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* DDRC_MISC_02 10'h02C */
	union {
		uint32_t ddrc_misc_02; // word name
		struct {
			uint32_t ctl_idle : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_MISC_03 10'h030 [Unused] */
	uint32_t empty_word_ddrc_misc_03;
	/* DDRC_MISC_04 10'h034 [Unused] */
	uint32_t empty_word_ddrc_misc_04;
	/* DDRC_LP_ENTR 10'h038 */
	union {
		uint32_t ddrc_lp_entr; // word name
		struct {
			uint32_t dramc_lp_enter : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_LP_EXIT 10'h03C */
	union {
		uint32_t ddrc_lp_exit; // word name
		struct {
			uint32_t dramc_lp_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_LP_CFG 10'h040 */
	union {
		uint32_t ddrc_lp_cfg; // word name
		struct {
			uint32_t dramc_lp_peri_auto : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DDRC_LP_STA 10'h044 */
	union {
		uint32_t ddrc_lp_sta; // word name
		struct {
			uint32_t dramc_lp_status : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_ENTR 10'h048 */
	union {
		uint32_t axi_lp_entr; // word name
		struct {
			uint32_t axi_0_lp_enter : 1;
			uint32_t : 7; // padding bits
			uint32_t axi_1_lp_enter : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_EXIT 10'h04C */
	union {
		uint32_t axi_lp_exit; // word name
		struct {
			uint32_t axi_0_lp_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t axi_1_lp_exit : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_CFG 10'h050 */
	union {
		uint32_t axi_lp_cfg; // word name
		struct {
			uint32_t axi_0_lp_peri_auto : 1;
			uint32_t : 7; // padding bits
			uint32_t axi_1_lp_peri_auto : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AXI_LP_STA 10'h054 */
	union {
		uint32_t axi_lp_sta; // word name
		struct {
			uint32_t axi_0_lp_status : 1;
			uint32_t : 7; // padding bits
			uint32_t axi_1_lp_status : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* APB_STA 10'h058 */
	union {
		uint32_t apb_sta; // word name
		struct {
			uint32_t pslverr_addr : 32;
		};
	};
	/* DBG_CFG 10'h05C */
	union {
		uint32_t dbg_cfg; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_MON 10'h060 */
	union {
		uint32_t dbg_mon; // word name
		struct {
			uint32_t debug_mon_out : 32;
		};
	};
	/* DRAMCCFG19 10'h064 [Unused] */
	uint32_t empty_word_dramccfg19;
	/* DRAMCCFG20 10'h068 [Unused] */
	uint32_t empty_word_dramccfg20;
	/* DRAMCCFG21 10'h06C [Unused] */
	uint32_t empty_word_dramccfg21;
	/* DRAMCCFG22 10'h070 [Unused] */
	uint32_t empty_word_dramccfg22;
	/* DRAMCCFG23 10'h074 [Unused] */
	uint32_t empty_word_dramccfg23;
	/* IOTST_CMD_00 10'h078 [Unused] */
	uint32_t empty_word_iotst_cmd_00;
	/* IOTST_CMD_01 10'h07C [Unused] */
	uint32_t empty_word_iotst_cmd_01;
	/* IOTST_CMD_02 10'h080 [Unused] */
	uint32_t empty_word_iotst_cmd_02;
	/* IOTST_CMD_03 10'h084 [Unused] */
	uint32_t empty_word_iotst_cmd_03;
	/* IOTST_CMD_04 10'h088 [Unused] */
	uint32_t empty_word_iotst_cmd_04;
	/* IOTST_CMD_05 10'h08C [Unused] */
	uint32_t empty_word_iotst_cmd_05;
	/* IOTST_CMD_06 10'h090 [Unused] */
	uint32_t empty_word_iotst_cmd_06;
	/* IOTST_CMD_07 10'h094 [Unused] */
	uint32_t empty_word_iotst_cmd_07;
	/* IOTST_CMD_08 10'h098 [Unused] */
	uint32_t empty_word_iotst_cmd_08;
	/* IOTST_CMD_09 10'h09C [Unused] */
	uint32_t empty_word_iotst_cmd_09;
	/* IOTST_CMD_10 10'h0A0 [Unused] */
	uint32_t empty_word_iotst_cmd_10;
	/* IOTST_CMD_11 10'h0A4 [Unused] */
	uint32_t empty_word_iotst_cmd_11;
	/* IOTST_CMD_12 10'h0A8 [Unused] */
	uint32_t empty_word_iotst_cmd_12;
	/* IOTST_CMD_13 10'h0AC [Unused] */
	uint32_t empty_word_iotst_cmd_13;
	/* IOTST_CMD_14 10'h0B0 [Unused] */
	uint32_t empty_word_iotst_cmd_14;
	/* IOTST_CMD_15 10'h0B4 [Unused] */
	uint32_t empty_word_iotst_cmd_15;
	/* IOTST_CMD_16 10'h0B8 [Unused] */
	uint32_t empty_word_iotst_cmd_16;
	/* IOTST_CMD_17 10'h0BC [Unused] */
	uint32_t empty_word_iotst_cmd_17;
	/* IOTST_CMD_18 10'h0C0 [Unused] */
	uint32_t empty_word_iotst_cmd_18;
	/* IOTST_CMD_19 10'h0C4 [Unused] */
	uint32_t empty_word_iotst_cmd_19;
	/* IOTST_CMD_20 10'h0C8 [Unused] */
	uint32_t empty_word_iotst_cmd_20;
	/* IOTST_CMD_21 10'h0CC [Unused] */
	uint32_t empty_word_iotst_cmd_21;
	/* IOTST_CMD_22 10'h0D0 [Unused] */
	uint32_t empty_word_iotst_cmd_22;
	/* IOTST_A_0 10'h0D4 [Unused] */
	uint32_t empty_word_iotst_a_0;
	/* IOTST_A_1 10'h0D8 [Unused] */
	uint32_t empty_word_iotst_a_1;
	/* IOTST_A_2 10'h0DC [Unused] */
	uint32_t empty_word_iotst_a_2;
	/* IOTST_A_3 10'h0E0 [Unused] */
	uint32_t empty_word_iotst_a_3;
	/* IOTST_A_4 10'h0E4 [Unused] */
	uint32_t empty_word_iotst_a_4;
	/* IOTST_DQ_0 10'h0E8 [Unused] */
	uint32_t empty_word_iotst_dq_0;
	/* IOTST_DQ_1 10'h0EC [Unused] */
	uint32_t empty_word_iotst_dq_1;
	/* IOTST_DQ_2 10'h0F0 [Unused] */
	uint32_t empty_word_iotst_dq_2;
	/* IOTST_DQ_3 10'h0F4 [Unused] */
	uint32_t empty_word_iotst_dq_3;
	/* IOTST_DQ_4 10'h0F8 [Unused] */
	uint32_t empty_word_iotst_dq_4;
	/* DRAMCCFG40 10'h0FC [Unused] */
	uint32_t empty_word_dramccfg40;
	/* MEM_WRAPPER 10'h100 */
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
} CsrBankCcfg;

#endif