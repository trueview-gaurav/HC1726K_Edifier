/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_TIMER_H_
#define CSR_TABLE_TIMER_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_timer[] = {
	// WORD tri
	{ "trigger_0", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "trigger_1", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "trigger_2", 0x00000000, 16, 16, CSR_W1P, 0x00000000 },
	{ "trigger_3", 0x00000000, 24, 24, CSR_W1P, 0x00000000 },
	{ "TRI", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clr
	{ "irq_clear_match_0", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_match_1", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_match_2", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_match_3", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_st
	{ "status_match_0", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_match_1", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "status_match_2", 0x00000008, 16, 16, CSR_RO, 0x00000000 },
	{ "status_match_3", 0x00000008, 24, 24, CSR_RO, 0x00000000 },
	{ "IRQ_ST", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_match_0", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_match_1", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_match_2", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_match_3", 0x0000000C, 24, 24, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD st
	{ "status_0", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_1", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "status_2", 0x00000010, 16, 16, CSR_RO, 0x00000000 },
	{ "status_3", 0x00000010, 24, 24, CSR_RO, 0x00000000 },
	{ "ST", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD set_00
	{ "mode_0", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "prescaler_0", 0x00000014, 23, 16, CSR_RW, 0x00000000 },
	{ "SET_00", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD target_00
	{ "count_load_0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	{ "TARGET_00", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cnt_00
	{ "count_value_0", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "CNT_00", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD set_01
	{ "mode_1", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "prescaler_1", 0x00000020, 23, 16, CSR_RW, 0x00000000 },
	{ "SET_01", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD target_01
	{ "count_load_1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	{ "TARGET_01", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cnt_01
	{ "count_value_1", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "CNT_01", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD set_02
	{ "mode_2", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "prescaler_2", 0x0000002C, 23, 16, CSR_RW, 0x00000000 },
	{ "SET_02", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD target_02
	{ "count_load_2", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	{ "TARGET_02", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD cnt_02
	{ "count_value_2", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "CNT_02", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD set_03
	{ "mode_3", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "prescaler_3", 0x00000038, 23, 16, CSR_RW, 0x00000000 },
	{ "SET_03", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD target_03
	{ "count_load_3", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	{ "TARGET_03", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cnt_03
	{ "count_value_3", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "CNT_03", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_TIMER_H_
