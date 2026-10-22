/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_LLI_H_
#define CSR_TABLE_LLI_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_lli[] = {
	// WORD linked_listed_pointer
	{ "first_lli_addr", 0x00000000, 30, 3, CSR_RW, 0x00000000 },
	{ "LINKED_LISTED_POINTER", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD lli_ctrl
	{ "lli_start", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "LLI_CTRL", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD lli_cfg
	{ "lli_debug_mon_sel", 0x00000008, 25, 24, CSR_RW, 0x00000000 },
	{ "LLI_CFG", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_clr
	{ "irq_clr_csr_check_fail", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clr_receive_unexpect_irq", 0x0000000C, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clr_all_lli_done", 0x0000000C, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clr_one_lli_done", 0x0000000C, 3, 3, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status
	{ "status_csr_check_fail", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_receive_unexpect_irq", 0x00000010, 1, 1, CSR_RO, 0x00000000 },
	{ "status_all_lli_done", 0x00000010, 2, 2, CSR_RO, 0x00000000 },
	{ "status_one_lli_done", 0x00000010, 3, 3, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_csr_check_fail", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_receive_unexpect_irq", 0x00000014, 1, 1, CSR_RW, 0x00000001 },
	{ "irq_mask_all_lli_done", 0x00000014, 2, 2, CSR_RW, 0x00000001 },
	{ "irq_mask_one_lli_done", 0x00000014, 3, 3, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD arb_mode
	{ "arbitration_mode", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "ARB_MODE", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD resv
	{ "reserved", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	{ "RESV", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_apb_m_addr
	{ "status_addr_to_apb_m", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_APB_M_ADDR", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_apb_m_data
	{ "status_data_to_apb_m", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_APB_M_DATA", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_apb_m_irq_mask0
	{ "internal_irq_mask_0", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_APB_M_IRQ_MASK0", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_apb_m_irq_mask1
	{ "internal_irq_mask_1", 0x0000002C, 25, 0, CSR_RO, 0x00000000 },
	{ "DEBUG_APB_M_IRQ_MASK1", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug_op_status
	{ "status_op_write", 0x00000030, 0, 0, CSR_RO, 0x00000000 },
	{ "status_op_check", 0x00000030, 1, 1, CSR_RO, 0x00000000 },
	{ "status_op_polling", 0x00000030, 2, 2, CSR_RO, 0x00000000 },
	{ "status_op_wait_irq", 0x00000030, 3, 3, CSR_RO, 0x00000000 },
	{ "status_op_issue_irq", 0x00000030, 4, 4, CSR_RO, 0x00000000 },
	{ "DEBUG_OP_STATUS", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_finish_num
	{ "finish_lli_cnt", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_FINISH_NUM", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_0
	{ "lli_reg_0", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_0", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_1
	{ "lli_reg_1", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_1", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_2
	{ "lli_reg_2", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_2", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_3
	{ "lli_reg_3", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_3", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_4
	{ "lli_reg_4", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_4", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_5
	{ "lli_reg_5", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_5", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_6
	{ "lli_reg_6", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_6", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_7
	{ "lli_reg_7", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_7", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_8
	{ "lli_reg_8", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_8", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_9
	{ "lli_reg_9", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_9", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_10
	{ "lli_reg_10", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_10", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_11
	{ "lli_reg_11", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_11", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_12
	{ "lli_reg_12", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_12", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_13
	{ "lli_reg_13", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_13", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_14
	{ "lli_reg_14", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_14", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// WORD lli_reg_offset_15
	{ "lli_reg_15", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	{ "LLI_REG_OFFSET_15", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_LLI_H_
