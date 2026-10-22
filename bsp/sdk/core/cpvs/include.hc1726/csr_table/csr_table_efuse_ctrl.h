/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_EFUSE_CTRL_H_
#define CSR_TABLE_EFUSE_CTRL_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_efuse_ctrl[] = {
	// WORD word_mode
	{ "mode", 0x00000000, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD time_set0
	{ "tsu_pd_ps", 0x00000004, 6, 0, CSR_RW, 0x00000000 },
	{ "tsu_ps_cs", 0x00000004, 14, 8, CSR_RW, 0x00000019 },
	{ "th_cs", 0x00000004, 18, 16, CSR_RW, 0x00000003 },
	{ "th_ps_cs", 0x00000004, 27, 24, CSR_RW, 0x00000004 },
	{ "TIME_SET0", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD time_set1
	{ "tsu_a", 0x00000008, 2, 0, CSR_RW, 0x00000004 },
	{ "th_a", 0x00000008, 10, 8, CSR_RW, 0x00000004 },
	{ "t_strobe", 0x00000008, 26, 16, CSR_RW, 0x00000005 },
	{ "TIME_SET1", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl
	{ "start", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "stop", 0x0000000C, 8, 8, CSR_W1P, 0x00000000 },
	{ "CTRL", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD addr
	{ "rw_addr", 0x00000010, 9, 0, CSR_RW, 0x00000000 },
	{ "ADDR", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD wdata
	{ "w_data", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "WDATA", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD rdata
	{ "r_data", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "RDATA", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD hw_rdata
	{ "hardware_r_data", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "HW_RDATA", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD status
	{ "rw_ready", 0x00000020, 0, 0, CSR_RO, 0x00000000 },
	{ "rd_done", 0x00000020, 8, 8, CSR_RO, 0x00000000 },
	{ "esc_done", 0x00000020, 16, 16, CSR_RO, 0x00000000 },
	{ "power_dn", 0x00000020, 24, 24, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_time_cnt
	{ "time_cnt", 0x00000024, 15, 0, CSR_RO, 0x00000000 },
	{ "WORD_TIME_CNT", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_lock
	{ "lock", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_LOCK", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD status_irq
	{ "status_irq_pgm", 0x0000002C, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS_IRQ", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD mask
	{ "irq_mask_pgm", 0x00000030, 0, 0, CSR_RW, 0x00000001 },
	{ "MASK", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD clear_irq
	{ "irq_clear_pgm", 0x00000034, 0, 0, CSR_W1P, 0x00000000 },
	{ "CLEAR_IRQ", 0x00000034, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status_r
	{ "rf0", 0x00000038, 0, 0, CSR_RO, 0x00000000 },
	{ "rf1", 0x00000038, 8, 8, CSR_RO, 0x00000000 },
	{ "rf2", 0x00000038, 16, 16, CSR_RO, 0x00000000 },
	{ "rf3", 0x00000038, 24, 24, CSR_RO, 0x00000000 },
	{ "STATUS_R", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_hw_rdata
	{ "hw_rdata_done", 0x0000003C, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS_HW_RDATA", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD mask_hw_r
	{ "hw_rdata_mask", 0x00000040, 0, 0, CSR_RW, 0x00000001 },
	{ "MASK_HW_R", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD clear_hw_r
	{ "hw_rdata_clear", 0x00000044, 0, 0, CSR_W1P, 0x00000000 },
	{ "CLEAR_HW_R", 0x00000044, 31, 0, CSR_W1P, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_EFUSE_CTRL_H_
