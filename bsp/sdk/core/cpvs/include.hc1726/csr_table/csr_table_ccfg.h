/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CCFG_H_
#define CSR_TABLE_CCFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ccfg[] = {
	// WORD ddrc_irq_sta_0
	{ "status_perf_log_done", 0x00000000, 0, 0, CSR_RO, 0x00000000 },
	{ "status_dramc_lp_done", 0x00000000, 8, 8, CSR_RO, 0x00000000 },
	{ "status_dramc_lp_peri_exit", 0x00000000, 16, 16, CSR_RO, 0x00000000 },
	{ "status_axi_0_lp_done", 0x00000000, 24, 24, CSR_RO, 0x00000000 },
	{ "DDRC_IRQ_STA_0", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	// WORD ddrc_irq_sta_1
	{ "status_axi_0_lp_peri_exit", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "status_axi_1_lp_done", 0x00000004, 8, 8, CSR_RO, 0x00000000 },
	{ "status_axi_1_lp_peri_exit", 0x00000004, 16, 16, CSR_RO, 0x00000000 },
	{ "status_apb_slverr", 0x00000004, 24, 24, CSR_RO, 0x00000000 },
	{ "DDRC_IRQ_STA_1", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD ddrc_irq_sta_2
	{ "status_axi_0_id_err", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_axi_1_id_err", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "DDRC_IRQ_STA_2", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD ddrc_irq_clr_0
	{ "irq_clear_perf_log_done", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_dramc_lp_done", 0x0000000C, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_dramc_lp_peri_exit", 0x0000000C, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_axi_0_lp_done", 0x0000000C, 24, 24, CSR_W1P, 0x00000000 },
	{ "DDRC_IRQ_CLR_0", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ddrc_irq_clr_1
	{ "irq_clear_axi_0_lp_peri_exit", 0x00000010, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_axi_1_lp_done", 0x00000010, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_axi_1_lp_peri_exit", 0x00000010, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_apb_slverr", 0x00000010, 24, 24, CSR_W1P, 0x00000000 },
	{ "DDRC_IRQ_CLR_1", 0x00000010, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ddrc_irq_clr_2
	{ "irq_clear_axi_0_id_err", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_axi_1_id_err", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "DDRC_IRQ_CLR_2", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ddrc_irq_msk_0
	{ "irq_mask_perf_log_done", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_dramc_lp_done", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_dramc_lp_peri_exit", 0x00000018, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_axi_0_lp_done", 0x00000018, 24, 24, CSR_RW, 0x00000001 },
	{ "DDRC_IRQ_MSK_0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddrc_irq_msk_1
	{ "irq_mask_axi_0_lp_peri_exit", 0x0000001C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_axi_1_lp_done", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_axi_1_lp_peri_exit", 0x0000001C, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_apb_slverr", 0x0000001C, 24, 24, CSR_RW, 0x00000001 },
	{ "DDRC_IRQ_MSK_1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddrc_irq_msk_2
	{ "irq_mask_axi_0_id_err", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_axi_1_id_err", 0x00000020, 8, 8, CSR_RW, 0x00000001 },
	{ "DDRC_IRQ_MSK_2", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD waq
	{ "waq_wcount", 0x00000024, 15, 0, CSR_RO, 0x00000000 },
	{ "WAQ", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD raq
	{ "raq_wcount", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "RAQ", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD dfi_status
	{ "dfi_freq_ratio", 0x0000002C, 0, 0, CSR_RO, 0x00000000 },
	{ "dfi_frequency", 0x0000002C, 12, 8, CSR_RO, 0x00000000 },
	{ "DFI_STATUS", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD axi_urgent
	{ "arurgent", 0x00000030, 7, 0, CSR_RW, 0x00000000 },
	{ "awurgent", 0x00000030, 11, 8, CSR_RW, 0x00000000 },
	{ "AXI_URGENT", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD pa_mask
	{ "pa_rmask", 0x00000034, 7, 0, CSR_RW, 0x00000000 },
	{ "pa_wmask", 0x00000034, 11, 8, CSR_RW, 0x00000000 },
	{ "PA_MASK", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddrc_misc_00
	{ "lpr_credit_cnt", 0x00000038, 6, 0, CSR_RO, 0x00000000 },
	{ "hpr_credit_cnt", 0x00000038, 14, 8, CSR_RO, 0x00000000 },
	{ "wr_credit_cnt", 0x00000038, 22, 16, CSR_RO, 0x00000000 },
	{ "DDRC_MISC_00", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD ddrc_misc_01
	{ "selfref_type", 0x0000003C, 25, 24, CSR_RO, 0x00000000 },
	{ "DDRC_MISC_01", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD ddrc_misc_02
	{ "ctl_idle", 0x00000040, 0, 0, CSR_RO, 0x00000000 },
	{ "DDRC_MISC_02", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD ddrc_lp_entr
	{ "dramc_lp_enter", 0x0000004C, 0, 0, CSR_W1P, 0x00000000 },
	{ "DDRC_LP_ENTR", 0x0000004C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ddrc_lp_exit
	{ "dramc_lp_exit", 0x00000050, 0, 0, CSR_W1P, 0x00000000 },
	{ "DDRC_LP_EXIT", 0x00000050, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ddrc_lp_cfg
	{ "dramc_lp_peri_auto", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "DDRC_LP_CFG", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD ddrc_lp_sta
	{ "dramc_lp_status", 0x00000058, 0, 0, CSR_RO, 0x00000000 },
	{ "DDRC_LP_STA", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD axi_lp_entr
	{ "axi_0_lp_enter", 0x0000005C, 0, 0, CSR_W1P, 0x00000000 },
	{ "axi_1_lp_enter", 0x0000005C, 8, 8, CSR_W1P, 0x00000000 },
	{ "AXI_LP_ENTR", 0x0000005C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD axi_lp_exit
	{ "axi_0_lp_exit", 0x00000060, 0, 0, CSR_W1P, 0x00000000 },
	{ "axi_1_lp_exit", 0x00000060, 8, 8, CSR_W1P, 0x00000000 },
	{ "AXI_LP_EXIT", 0x00000060, 31, 0, CSR_W1P, 0x00000000 },
	// WORD axi_lp_cfg
	{ "axi_0_lp_peri_auto", 0x00000064, 0, 0, CSR_RW, 0x00000000 },
	{ "axi_1_lp_peri_auto", 0x00000064, 8, 8, CSR_RW, 0x00000000 },
	{ "AXI_LP_CFG", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD axi_lp_sta
	{ "axi_0_lp_status", 0x00000068, 0, 0, CSR_RO, 0x00000000 },
	{ "axi_1_lp_status", 0x00000068, 8, 8, CSR_RO, 0x00000000 },
	{ "AXI_LP_STA", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD apb_sta
	{ "pslverr_addr", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	{ "APB_STA", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg_cfg
	{ "debug_mon_sel", 0x00000070, 2, 0, CSR_RW, 0x00000000 },
	{ "DBG_CFG", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg_mon
	{ "debug_mon_out", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG_MON", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	// WORD mem_wrapper
	{ "sd", 0x00000114, 8, 8, CSR_RW, 0x00000000 },
	{ "slp", 0x00000114, 16, 16, CSR_RW, 0x00000000 },
	{ "MEM_WRAPPER", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CCFG_H_
