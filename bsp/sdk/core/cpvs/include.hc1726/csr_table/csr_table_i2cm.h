/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_I2CM_H_
#define CSR_TABLE_I2CM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_i2cm[] = {
	// WORD start
	{ "action_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_action_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_action_tx_half", 0x00000004, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_action_rx_half", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_timeout_min", 0x00000004, 12, 12, CSR_W1P, 0x00000000 },
	{ "irq_clear_timeout_max", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_lowtext_viola", 0x00000004, 20, 20, CSR_W1P, 0x00000000 },
	{ "irq_clear_lowcext_viola", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD state
	{ "irq_action_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "irq_action_tx_half", 0x00000008, 4, 4, CSR_RO, 0x00000000 },
	{ "irq_action_rx_half", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "irq_action_timeout_min", 0x00000008, 12, 12, CSR_RO, 0x00000000 },
	{ "irq_action_timeout_max", 0x00000008, 16, 16, CSR_RO, 0x00000000 },
	{ "irq_action_lowtext_viola", 0x00000008, 20, 20, CSR_RO, 0x00000000 },
	{ "irq_action_lowcext_viola", 0x00000008, 24, 24, CSR_RO, 0x00000000 },
	{ "excu_which_half", 0x00000008, 25, 25, CSR_RO, 0x00000000 },
	{ "engine_status", 0x00000008, 26, 26, CSR_RO, 0x00000000 },
	{ "action_status", 0x00000008, 28, 27, CSR_RO, 0x00000000 },
	{ "STATE", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_action_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_tx_half", 0x0000000C, 4, 4, CSR_RW, 0x00000001 },
	{ "irq_mask_rx_half", 0x0000000C, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_timeout_min", 0x0000000C, 12, 12, CSR_RW, 0x00000001 },
	{ "irq_mask_timeout_max", 0x0000000C, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_lowtext_viola", 0x0000000C, 20, 20, CSR_RW, 0x00000001 },
	{ "irq_mask_lowcext_viola", 0x0000000C, 24, 24, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD smb_time_fig00
	{ "lowcext_num", 0x00000010, 8, 0, CSR_RW, 0x00000075 },
	{ "lowtext_num", 0x00000010, 17, 9, CSR_RW, 0x00000124 },
	{ "timeout_min", 0x00000010, 26, 18, CSR_RW, 0x00000124 },
	{ "SMB_TIME_FIG00", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD smb_time_fig01
	{ "timeout_max", 0x00000014, 8, 0, CSR_RW, 0x00000199 },
	{ "SMB_TIME_FIG01", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD smb_time_en
	{ "lowtext_abort_enable", 0x00000018, 1, 1, CSR_RW, 0x00000000 },
	{ "timeout_abort_enable", 0x00000018, 2, 2, CSR_RW, 0x00000000 },
	{ "SMB_TIME_EN", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD curnt_cnt
	{ "write_byte_cnt", 0x0000001C, 7, 0, CSR_RO, 0x00000000 },
	{ "write_trans_cnt", 0x0000001C, 15, 8, CSR_RO, 0x00000000 },
	{ "read_byte_cnt", 0x0000001C, 23, 16, CSR_RO, 0x00000000 },
	{ "read_trans_cnt", 0x0000001C, 31, 24, CSR_RO, 0x00000000 },
	{ "CURNT_CNT", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD trsi_config_0
	{ "sda_deglitch_th", 0x00000020, 5, 0, CSR_RW, 0x00000000 },
	{ "scl_deglitch_th", 0x00000020, 13, 8, CSR_RW, 0x00000000 },
	{ "TRSI_CONFIG_0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD trsi_config_1
	{ "sdo_delay_cycle", 0x00000024, 10, 0, CSR_RW, 0x00000000 },
	{ "scl_rate_cycle", 0x00000024, 21, 11, CSR_RW, 0x00000078 },
	{ "TRSI_CONFIG_1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD actiondef
	{ "write_and_read_mode", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "sccb_enable", 0x00000028, 4, 4, CSR_RW, 0x00000000 },
	{ "restart_mode", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "operation", 0x00000028, 12, 12, CSR_RW, 0x00000000 },
	{ "pec_enable", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "ACTIONDEF", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD addr_func_by
	{ "target_address", 0x0000002C, 6, 0, CSR_RW, 0x00000000 },
	{ "function_byte", 0x0000002C, 15, 8, CSR_RW, 0x00000000 },
	{ "function_byte_enable", 0x0000002C, 16, 16, CSR_RW, 0x00000000 },
	{ "function_byte_only", 0x0000002C, 24, 24, CSR_RW, 0x00000000 },
	{ "ADDR_FUNC_BY", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD segmentdef
	{ "write_byte_num", 0x00000030, 7, 0, CSR_RW, 0x00000003 },
	{ "write_trans_num", 0x00000030, 15, 8, CSR_RW, 0x00000000 },
	{ "read_byte_num", 0x00000030, 23, 16, CSR_RW, 0x00000001 },
	{ "read_trans_num", 0x00000030, 31, 24, CSR_RW, 0x00000000 },
	{ "SEGMENTDEF", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD write00
	{ "wdata_0", 0x00000034, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_1", 0x00000034, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_2", 0x00000034, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_3", 0x00000034, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE00", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD write01
	{ "wdata_4", 0x00000038, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_5", 0x00000038, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_6", 0x00000038, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_7", 0x00000038, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE01", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD write02
	{ "wdata_8", 0x0000003C, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_9", 0x0000003C, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_10", 0x0000003C, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_11", 0x0000003C, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE02", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD write03
	{ "wdata_12", 0x00000040, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_13", 0x00000040, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_14", 0x00000040, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_15", 0x00000040, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE03", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD write04
	{ "wdata_16", 0x00000044, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_17", 0x00000044, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_18", 0x00000044, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_19", 0x00000044, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE04", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD write05
	{ "wdata_20", 0x00000048, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_21", 0x00000048, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_22", 0x00000048, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_23", 0x00000048, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE05", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD write06
	{ "wdata_24", 0x0000004C, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_25", 0x0000004C, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_26", 0x0000004C, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_27", 0x0000004C, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE06", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD write07
	{ "wdata_28", 0x00000050, 7, 0, CSR_RW, 0x00000000 },
	{ "wdata_29", 0x00000050, 15, 8, CSR_RW, 0x00000000 },
	{ "wdata_30", 0x00000050, 23, 16, CSR_RW, 0x00000000 },
	{ "wdata_31", 0x00000050, 31, 24, CSR_RW, 0x00000000 },
	{ "WRITE07", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD read00
	{ "rdata_0", 0x00000054, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_1", 0x00000054, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_2", 0x00000054, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_3", 0x00000054, 31, 24, CSR_RO, 0x00000000 },
	{ "READ00", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD read01
	{ "rdata_4", 0x00000058, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_5", 0x00000058, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_6", 0x00000058, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_7", 0x00000058, 31, 24, CSR_RO, 0x00000000 },
	{ "READ01", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD read02
	{ "rdata_8", 0x0000005C, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_9", 0x0000005C, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_10", 0x0000005C, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_11", 0x0000005C, 31, 24, CSR_RO, 0x00000000 },
	{ "READ02", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD read03
	{ "rdata_12", 0x00000060, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_13", 0x00000060, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_14", 0x00000060, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_15", 0x00000060, 31, 24, CSR_RO, 0x00000000 },
	{ "READ03", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD read04
	{ "rdata_16", 0x00000064, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_17", 0x00000064, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_18", 0x00000064, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_19", 0x00000064, 31, 24, CSR_RO, 0x00000000 },
	{ "READ04", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD read05
	{ "rdata_20", 0x00000068, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_21", 0x00000068, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_22", 0x00000068, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_23", 0x00000068, 31, 24, CSR_RO, 0x00000000 },
	{ "READ05", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD read06
	{ "rdata_24", 0x0000006C, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_25", 0x0000006C, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_26", 0x0000006C, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_27", 0x0000006C, 31, 24, CSR_RO, 0x00000000 },
	{ "READ06", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD read07
	{ "rdata_28", 0x00000070, 7, 0, CSR_RO, 0x00000000 },
	{ "rdata_29", 0x00000070, 15, 8, CSR_RO, 0x00000000 },
	{ "rdata_30", 0x00000070, 23, 16, CSR_RO, 0x00000000 },
	{ "rdata_31", 0x00000070, 31, 24, CSR_RO, 0x00000000 },
	{ "READ07", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// WORD debug
	{ "debug_mon_sel", 0x00000074, 0, 0, CSR_RW, 0x00000000 },
	{ "DEBUG", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD resv
	{ "reserved", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	{ "RESV", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_I2CM_H_
