/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_EQOS_CFG_H_
#define CSR_TABLE_EQOS_CFG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_eqos_cfg[] = {
	// WORD ephy_intf_sel
	{ "phy_intf_sel_csr", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "EPHY_INTF_SEL", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD axi_lp_enter
	{ "lp_enter", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "AXI_LP_ENTER", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD axi_lp_exit
	{ "lp_exit", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "AXI_LP_EXIT", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD axi_lp_auto
	{ "lp_peri_auto", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "AXI_LP_AUTO", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD axi_lp_status
	{ "lp_status", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "AXI_LP_STATUS", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD cfg_irq_sta_0
	{ "status_perch_tx", 0x00000014, 0, 0, CSR_RO, 0x00000000 },
	{ "status_perch_rx", 0x00000014, 8, 8, CSR_RO, 0x00000000 },
	{ "status_lpi_exit", 0x00000014, 16, 16, CSR_RO, 0x00000000 },
	{ "status_axi_lp_done", 0x00000014, 24, 24, CSR_RO, 0x00000000 },
	{ "CFG_IRQ_STA_0", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD cfg_irq_sta_1
	{ "status_axi_lp_peri_exit", 0x00000018, 0, 0, CSR_RO, 0x00000000 },
	{ "CFG_IRQ_STA_1", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD cfg_irq_msk_0
	{ "irq_mask_perch_tx", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_perch_rx", 0x0000001C, 8, 8, CSR_RW, 0x00000000 },
	{ "irq_mask_lpi_exit", 0x0000001C, 16, 16, CSR_RW, 0x00000000 },
	{ "irq_mask_axi_lp_done", 0x0000001C, 24, 24, CSR_RW, 0x00000000 },
	{ "CFG_IRQ_MSK_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_irq_msk_1
	{ "irq_mask_axi_lp_peri_exit", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "CFG_IRQ_MSK_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg_irq_ack_0
	{ "irq_clear_perch_tx", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_perch_rx", 0x00000024, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_lpi_exit", 0x00000024, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_axi_lp_done", 0x00000024, 24, 24, CSR_W1P, 0x00000000 },
	{ "CFG_IRQ_ACK_0", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD cfg_irq_ack_1
	{ "irq_clear_axi_lp_peri_exit", 0x00000028, 0, 0, CSR_W1P, 0x00000000 },
	{ "CFG_IRQ_ACK_1", 0x00000028, 31, 0, CSR_W1P, 0x00000000 },
	// WORD debug_mon_sel
	{ "debug_sel", 0x0000002C, 2, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_MON_SEL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_mon_status
	{ "debug_sta", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_MON_STATUS", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD mem_wrapper
	{ "sd", 0x00000034, 8, 8, CSR_RW, 0x00000000 },
	{ "slp", 0x00000034, 16, 16, CSR_RW, 0x00000000 },
	{ "MEM_WRAPPER", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_EQOS_CFG_H_
