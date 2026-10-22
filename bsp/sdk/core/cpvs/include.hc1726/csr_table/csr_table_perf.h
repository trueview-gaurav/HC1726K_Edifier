/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PERF_H_
#define CSR_TABLE_PERF_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_perf[] = {
	// WORD log_en
	{ "log_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "LOG_EN", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD log_cfg
	{ "log_period", 0x00000004, 31, 0, CSR_RW, 0x00001000 },
	{ "LOG_CFG", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD log_sta_00
	{ "log_hif_rd_or_wr", 0x00000008, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_00", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_01
	{ "log_hif_wr", 0x0000000C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_01", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_02
	{ "log_hif_rd", 0x00000010, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_02", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_03
	{ "log_hif_rmw", 0x00000014, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_03", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_04
	{ "log_hif_hi_pri_rd", 0x00000018, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_04", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_05
	{ "log_read_bypass", 0x0000001C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_05", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_06
	{ "log_act_bypass", 0x00000020, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_06", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_07
	{ "log_dfi_wr_data_cycles", 0x00000024, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_07", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_08
	{ "log_dfi_rd_data_cycles", 0x00000028, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_08", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_09
	{ "log_hpr_xact_when_critical", 0x0000002C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_09", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_10
	{ "log_lpr_xact_when_critical", 0x00000030, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_10", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_11
	{ "log_wr_xact_when_critical", 0x00000034, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_11", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_12
	{ "log_op_is_activate", 0x00000038, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_12", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_13
	{ "log_op_is_rd_or_wr", 0x0000003C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_13", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_14
	{ "log_op_is_rd_activate", 0x00000040, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_14", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_15
	{ "log_op_is_rd", 0x00000044, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_15", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_16
	{ "log_op_is_wr", 0x00000048, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_16", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_17
	{ "log_op_is_precharge", 0x0000004C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_17", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_18
	{ "log_precharge_for_rdwr", 0x00000050, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_18", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_19
	{ "log_precharge_for_other", 0x00000054, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_19", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_20
	{ "log_rdwr_transitions", 0x00000058, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_20", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_21
	{ "log_write_combine", 0x0000005C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_21", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_22
	{ "log_war_hazard", 0x00000060, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_22", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_23
	{ "log_raw_hazard", 0x00000064, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_23", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_24
	{ "log_waw_hazard", 0x00000068, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_24", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_25
	{ "log_op_is_enter_selfref", 0x0000006C, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_25", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_26
	{ "log_op_is_enter_powerdown", 0x00000070, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_26", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_27
	{ "log_op_is_refresh", 0x00000074, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_27", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_28
	{ "log_op_is_load_mode", 0x00000078, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_28", 0x00000078, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_29
	{ "log_op_is_zqcl", 0x0000007C, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_29", 0x0000007C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_30
	{ "log_op_is_zqcs", 0x00000080, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_30", 0x00000080, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_31
	{ "log_selfref_mode", 0x00000084, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_31", 0x00000084, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_32
	{ "log_hpr_req_with_nocredit", 0x00000088, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_32", 0x00000088, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_33
	{ "log_lpr_req_with_nocredit", 0x0000008C, 27, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_33", 0x0000008C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_34
	{ "log_op_is_crit_ref", 0x00000090, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_34", 0x00000090, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_35
	{ "log_op_is_spec_ref", 0x00000094, 23, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_35", 0x00000094, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_36
	{ "log_bank_rec_0", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_36", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_37
	{ "log_bank_rec_1", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_37", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_38
	{ "log_bank_rec_2", 0x000000A0, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_38", 0x000000A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_39
	{ "log_bank_rec_3", 0x000000A4, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_39", 0x000000A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_40
	{ "log_bypass_bank_rec_0", 0x000000A8, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_40", 0x000000A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_41
	{ "log_bypass_bank_rec_1", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_41", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_42
	{ "log_bypass_bank_rec_2", 0x000000B0, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_42", 0x000000B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD log_sta_43
	{ "log_bypass_bank_rec_3", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	{ "LOG_STA_43", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PERF_H_
