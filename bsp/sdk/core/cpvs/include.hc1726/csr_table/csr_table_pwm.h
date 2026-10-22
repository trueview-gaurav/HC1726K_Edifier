/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PWM_H_
#define CSR_TABLE_PWM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pwm[] = {
	// WORD trigger
	{ "trigger_0", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "trigger_1", 0x00000000, 1, 1, CSR_W1P, 0x00000000 },
	{ "trigger_2", 0x00000000, 2, 2, CSR_W1P, 0x00000000 },
	{ "trigger_3", 0x00000000, 3, 3, CSR_W1P, 0x00000000 },
	{ "trigger_4", 0x00000000, 4, 4, CSR_W1P, 0x00000000 },
	{ "trigger_5", 0x00000000, 5, 5, CSR_W1P, 0x00000000 },
	{ "trigger_6", 0x00000000, 6, 6, CSR_W1P, 0x00000000 },
	{ "TRIGGER", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD busy
	{ "status_0", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "status_1", 0x00000004, 1, 1, CSR_RO, 0x00000000 },
	{ "status_2", 0x00000004, 2, 2, CSR_RO, 0x00000000 },
	{ "status_3", 0x00000004, 3, 3, CSR_RO, 0x00000000 },
	{ "status_4", 0x00000004, 4, 4, CSR_RO, 0x00000000 },
	{ "status_5", 0x00000004, 5, 5, CSR_RO, 0x00000000 },
	{ "status_6", 0x00000004, 6, 6, CSR_RO, 0x00000000 },
	{ "BUSY", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_clr
	{ "irq_clear_0", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_1", 0x00000008, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_2", 0x00000008, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clear_3", 0x00000008, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clear_4", 0x00000008, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_5", 0x00000008, 5, 5, CSR_W1P, 0x00000000 },
	{ "irq_clear_6", 0x00000008, 6, 6, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_st
	{ "irq_status_0", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "irq_status_1", 0x0000000C, 1, 1, CSR_RO, 0x00000000 },
	{ "irq_status_2", 0x0000000C, 2, 2, CSR_RO, 0x00000000 },
	{ "irq_status_3", 0x0000000C, 3, 3, CSR_RO, 0x00000000 },
	{ "irq_status_4", 0x0000000C, 4, 4, CSR_RO, 0x00000000 },
	{ "irq_status_5", 0x0000000C, 5, 5, CSR_RO, 0x00000000 },
	{ "irq_status_6", 0x0000000C, 6, 6, CSR_RO, 0x00000000 },
	{ "IRQ_ST", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_0", 0x00000010, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_1", 0x00000010, 1, 1, CSR_RW, 0x00000001 },
	{ "irq_mask_2", 0x00000010, 2, 2, CSR_RW, 0x00000001 },
	{ "irq_mask_3", 0x00000010, 3, 3, CSR_RW, 0x00000001 },
	{ "irq_mask_4", 0x00000010, 4, 4, CSR_RW, 0x00000001 },
	{ "irq_mask_5", 0x00000010, 5, 5, CSR_RW, 0x00000001 },
	{ "irq_mask_6", 0x00000010, 6, 6, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mode
	{ "mode_0", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "mode_1", 0x00000014, 1, 1, CSR_RW, 0x00000000 },
	{ "mode_2", 0x00000014, 2, 2, CSR_RW, 0x00000000 },
	{ "mode_3", 0x00000014, 3, 3, CSR_RW, 0x00000000 },
	{ "mode_4", 0x00000014, 4, 4, CSR_RW, 0x00000000 },
	{ "mode_5", 0x00000014, 5, 5, CSR_RW, 0x00000000 },
	{ "mode_6", 0x00000014, 6, 6, CSR_RW, 0x00000000 },
	{ "MODE", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_0
	{ "prescaler_0", 0x00000018, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_0", 0x00000018, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_0", 0x00000018, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_0", 0x00000018, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_1
	{ "prescaler_1", 0x0000001C, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_1", 0x0000001C, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_1", 0x0000001C, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_1", 0x0000001C, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_2
	{ "prescaler_2", 0x00000020, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_2", 0x00000020, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_2", 0x00000020, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_2", 0x00000020, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_2", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_3
	{ "prescaler_3", 0x00000024, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_3", 0x00000024, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_3", 0x00000024, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_3", 0x00000024, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_3", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_4
	{ "prescaler_4", 0x00000028, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_4", 0x00000028, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_4", 0x00000028, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_4", 0x00000028, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_4", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_5
	{ "prescaler_5", 0x0000002C, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_5", 0x0000002C, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_5", 0x0000002C, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_5", 0x0000002C, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_5", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD config_6
	{ "prescaler_6", 0x00000030, 4, 0, CSR_RW, 0x00000000 },
	{ "count_period_6", 0x00000030, 15, 8, CSR_RW, 0x00000002 },
	{ "count_high_6", 0x00000030, 23, 16, CSR_RW, 0x00000001 },
	{ "num_period_6", 0x00000030, 31, 24, CSR_RW, 0x00000000 },
	{ "CONFIG_6", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug
	{ "debug_mon_sel", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "DEBUG", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PWM_H_
