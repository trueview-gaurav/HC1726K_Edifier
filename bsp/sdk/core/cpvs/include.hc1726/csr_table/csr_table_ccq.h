/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_CCQ_H_
#define CSR_TABLE_CCQ_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ccq[] = {
	// WORD irq_clr
	{ "irq_clr_csr_check_fail", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clr_receive_unexpect_irq", 0x00000000, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clr_csr_bus_conflict", 0x00000000, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clr_ccq_sys_timeout", 0x00000000, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clr_invalid_instruction", 0x00000000, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clr_ccq_issue_irq", 0x00000000, 5, 5, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status
	{ "status_csr_check_fail", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "status_receive_unexpect_irq", 0x00000004, 1, 1, CSR_RO, 0x00000000 },
	{ "status_csr_bus_conflict", 0x00000004, 2, 2, CSR_RO, 0x00000000 },
	{ "status_ccq_sys_timeout", 0x00000004, 3, 3, CSR_RO, 0x00000000 },
	{ "status_invalid_instruction", 0x00000004, 4, 4, CSR_RO, 0x00000000 },
	{ "status_ccq_issue_irq", 0x00000004, 5, 5, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_csr_check_fail", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_receive_unexpect_irq", 0x00000008, 1, 1, CSR_RW, 0x00000000 },
	{ "irq_mask_csr_bus_conflict", 0x00000008, 2, 2, CSR_RW, 0x00000000 },
	{ "irq_mask_ccq_sys_timeout", 0x00000008, 3, 3, CSR_RW, 0x00000000 },
	{ "irq_mask_invalid_instruction", 0x00000008, 4, 4, CSR_RW, 0x00000000 },
	{ "irq_mask_ccq_issue_irq", 0x00000008, 5, 5, CSR_RW, 0x00000000 },
	{ "IRQ_MASK", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD main
	{ "ccq_start", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "MAIN", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ins_length
	{ "instruction_length", 0x00000010, 21, 0, CSR_RW, 0x00000000 },
	{ "INS_LENGTH", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mode
	{ "arbitration_mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "bypass_cmd", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "monitor_en", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "MODE", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD sys_timeout_th_lsb
	{ "timeout_threshold_lsb", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	{ "SYS_TIMEOUT_TH_LSB", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD sys_timeout_th_msb
	{ "timeout_threshold_msb", 0x0000001C, 31, 0, CSR_RW, 0x00000001 },
	{ "SYS_TIMEOUT_TH_MSB", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ccq_status
	{ "ccq_idle", 0x00000020, 0, 0, CSR_RO, 0x00000000 },
	{ "program_counter", 0x00000020, 29, 8, CSR_RO, 0x00000000 },
	{ "CCQ_STATUS", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD cg_en_ctrl
	{ "dis_cg", 0x00000024, 0, 0, CSR_RW, 0x00000001 },
	{ "cg_delay_num", 0x00000024, 10, 8, CSR_RW, 0x00000005 },
	{ "CG_EN_CTRL", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug_sel
	{ "debug_mon_sel", 0x00000028, 1, 0, CSR_RW, 0x00000000 },
	{ "DEBUG_SEL", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_CCQ_H_
