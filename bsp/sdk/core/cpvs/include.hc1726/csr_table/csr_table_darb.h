/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DARB_H_
#define CSR_TABLE_DARB_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_darb[] = {
	// WORD chksum_clear
	{ "checksum_0_clear", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "checksum_1_clear", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "checksum_2_clear", 0x00000000, 16, 16, CSR_W1P, 0x00000000 },
	{ "checksum_3_clear", 0x00000000, 24, 24, CSR_W1P, 0x00000000 },
	{ "CHKSUM_CLEAR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear_a
	{ "irq_clear_w_resp_error", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_r_resp_error", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_timeout_w_addr", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_timeout_w_data", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR_A", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear_b
	{ "irq_clear_timeout_w_resp", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_timeout_r_addr", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_timeout_r_data", 0x00000008, 16, 16, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR_B", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status_a
	{ "status_w_resp_error", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "status_r_resp_error", 0x0000000C, 8, 8, CSR_RO, 0x00000000 },
	{ "status_timeout_w_addr", 0x0000000C, 16, 16, CSR_RO, 0x00000000 },
	{ "status_timeout_w_data", 0x0000000C, 24, 24, CSR_RO, 0x00000000 },
	{ "STATUS_A", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_b
	{ "status_timeout_w_resp", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_timeout_r_addr", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "status_timeout_r_data", 0x00000010, 16, 16, CSR_RO, 0x00000000 },
	{ "STATUS_B", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask_a
	{ "irq_mask_w_resp_error", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_r_resp_error", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_timeout_w_addr", 0x00000014, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_timeout_w_data", 0x00000014, 24, 24, CSR_RW, 0x00000001 },
	{ "IRQ_MASK_A", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_mask_b
	{ "irq_mask_timeout_w_resp", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_timeout_r_addr", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_timeout_r_data", 0x00000018, 16, 16, CSR_RW, 0x00000001 },
	{ "IRQ_MASK_B", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD remap_port_en_0
	{ "remap_w_i_en", 0x0000001C, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "REMAP_PORT_EN_0", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD remap_port_en_1
	{ "remap_r_i_en", 0x00000020, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "REMAP_PORT_EN_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD remap_port_en_2
	{ "remap_w_o_en", 0x00000024, 31, 0, CSR_RW, 0x7FFFFFFF },
	{ "REMAP_PORT_EN_2", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD remap_port_en_3
	{ "remap_r_o_en", 0x00000028, 31, 0, CSR_RW, 0x7FFFFFFF },
	{ "REMAP_PORT_EN_3", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_0
	{ "priority_w_00", 0x0000003C, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_01", 0x0000003C, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_02", 0x0000003C, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_03", 0x0000003C, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_0", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_1
	{ "priority_w_04", 0x00000040, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_05", 0x00000040, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_06", 0x00000040, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_07", 0x00000040, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_1", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_2
	{ "priority_w_08", 0x00000044, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_09", 0x00000044, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_10", 0x00000044, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_11", 0x00000044, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_2", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_3
	{ "priority_w_12", 0x00000048, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_13", 0x00000048, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_14", 0x00000048, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_15", 0x00000048, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_3", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_4
	{ "priority_w_16", 0x0000004C, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_17", 0x0000004C, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_18", 0x0000004C, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_19", 0x0000004C, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_4", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_5
	{ "priority_w_20", 0x00000050, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_21", 0x00000050, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_22", 0x00000050, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_23", 0x00000050, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_5", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_6
	{ "priority_w_24", 0x00000054, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_25", 0x00000054, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_26", 0x00000054, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_27", 0x00000054, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_6", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_w_7
	{ "priority_w_28", 0x00000058, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_w_29", 0x00000058, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_w_30", 0x00000058, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_w_31", 0x00000058, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_W_7", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_0
	{ "priority_r_00", 0x0000005C, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_01", 0x0000005C, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_02", 0x0000005C, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_03", 0x0000005C, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_0", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_1
	{ "priority_r_04", 0x00000060, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_05", 0x00000060, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_06", 0x00000060, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_07", 0x00000060, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_1", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_2
	{ "priority_r_08", 0x00000064, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_09", 0x00000064, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_10", 0x00000064, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_11", 0x00000064, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_2", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_3
	{ "priority_r_12", 0x00000068, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_13", 0x00000068, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_14", 0x00000068, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_15", 0x00000068, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_3", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_4
	{ "priority_r_16", 0x0000006C, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_17", 0x0000006C, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_18", 0x0000006C, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_19", 0x0000006C, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_4", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_5
	{ "priority_r_20", 0x00000070, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_21", 0x00000070, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_22", 0x00000070, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_23", 0x00000070, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_5", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_6
	{ "priority_r_24", 0x00000074, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_25", 0x00000074, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_26", 0x00000074, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_27", 0x00000074, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_6", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD priority_r_7
	{ "priority_r_28", 0x00000078, 1, 0, CSR_RW, 0x00000000 },
	{ "priority_r_29", 0x00000078, 9, 8, CSR_RW, 0x00000000 },
	{ "priority_r_30", 0x00000078, 17, 16, CSR_RW, 0x00000000 },
	{ "priority_r_31", 0x00000078, 25, 24, CSR_RW, 0x00000000 },
	{ "PRIORITY_R_7", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_0
	{ "ini_score_w_00", 0x0000007C, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_01", 0x0000007C, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_02", 0x0000007C, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_03", 0x0000007C, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_0", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_1
	{ "ini_score_w_04", 0x00000080, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_05", 0x00000080, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_06", 0x00000080, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_07", 0x00000080, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_1", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_2
	{ "ini_score_w_08", 0x00000084, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_09", 0x00000084, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_10", 0x00000084, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_11", 0x00000084, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_2", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_3
	{ "ini_score_w_12", 0x00000088, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_13", 0x00000088, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_14", 0x00000088, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_15", 0x00000088, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_3", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_4
	{ "ini_score_w_16", 0x0000008C, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_17", 0x0000008C, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_18", 0x0000008C, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_19", 0x0000008C, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_4", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_5
	{ "ini_score_w_20", 0x00000090, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_21", 0x00000090, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_22", 0x00000090, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_23", 0x00000090, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_5", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_6
	{ "ini_score_w_24", 0x00000094, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_25", 0x00000094, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_26", 0x00000094, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_27", 0x00000094, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_6", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_w_7
	{ "ini_score_w_28", 0x00000098, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_w_29", 0x00000098, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_w_30", 0x00000098, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_w_31", 0x00000098, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_W_7", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_0
	{ "ini_score_r_00", 0x0000009C, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_01", 0x0000009C, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_02", 0x0000009C, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_03", 0x0000009C, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_0", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_1
	{ "ini_score_r_04", 0x000000A0, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_05", 0x000000A0, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_06", 0x000000A0, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_07", 0x000000A0, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_1", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_2
	{ "ini_score_r_08", 0x000000A4, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_09", 0x000000A4, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_10", 0x000000A4, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_11", 0x000000A4, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_2", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_3
	{ "ini_score_r_12", 0x000000A8, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_13", 0x000000A8, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_14", 0x000000A8, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_15", 0x000000A8, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_3", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_4
	{ "ini_score_r_16", 0x000000AC, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_17", 0x000000AC, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_18", 0x000000AC, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_19", 0x000000AC, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_4", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_5
	{ "ini_score_r_20", 0x000000B0, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_21", 0x000000B0, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_22", 0x000000B0, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_23", 0x000000B0, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_5", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_6
	{ "ini_score_r_24", 0x000000B4, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_25", 0x000000B4, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_26", 0x000000B4, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_27", 0x000000B4, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_6", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_score_r_7
	{ "ini_score_r_28", 0x000000B8, 4, 0, CSR_RW, 0x00000000 },
	{ "ini_score_r_29", 0x000000B8, 12, 8, CSR_RW, 0x00000000 },
	{ "ini_score_r_30", 0x000000B8, 20, 16, CSR_RW, 0x00000000 },
	{ "ini_score_r_31", 0x000000B8, 28, 24, CSR_RW, 0x00000000 },
	{ "INI_SCORE_R_7", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_0
	{ "wait_cnt_norm_w_00", 0x000000BC, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_01", 0x000000BC, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_02", 0x000000BC, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_03", 0x000000BC, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_0", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_1
	{ "wait_cnt_norm_w_04", 0x000000C0, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_05", 0x000000C0, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_06", 0x000000C0, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_07", 0x000000C0, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_1", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_2
	{ "wait_cnt_norm_w_08", 0x000000C4, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_09", 0x000000C4, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_10", 0x000000C4, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_11", 0x000000C4, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_2", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_3
	{ "wait_cnt_norm_w_12", 0x000000C8, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_13", 0x000000C8, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_14", 0x000000C8, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_15", 0x000000C8, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_3", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_4
	{ "wait_cnt_norm_w_16", 0x000000CC, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_17", 0x000000CC, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_18", 0x000000CC, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_19", 0x000000CC, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_4", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_5
	{ "wait_cnt_norm_w_20", 0x000000D0, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_21", 0x000000D0, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_22", 0x000000D0, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_23", 0x000000D0, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_5", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_6
	{ "wait_cnt_norm_w_24", 0x000000D4, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_25", 0x000000D4, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_26", 0x000000D4, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_27", 0x000000D4, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_6", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_w_7
	{ "wait_cnt_norm_w_28", 0x000000D8, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_29", 0x000000D8, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_30", 0x000000D8, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_w_31", 0x000000D8, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_W_7", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_0
	{ "wait_cnt_norm_r_00", 0x000000DC, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_01", 0x000000DC, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_02", 0x000000DC, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_03", 0x000000DC, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_0", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_1
	{ "wait_cnt_norm_r_04", 0x000000E0, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_05", 0x000000E0, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_06", 0x000000E0, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_07", 0x000000E0, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_1", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_2
	{ "wait_cnt_norm_r_08", 0x000000E4, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_09", 0x000000E4, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_10", 0x000000E4, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_11", 0x000000E4, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_2", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_3
	{ "wait_cnt_norm_r_12", 0x000000E8, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_13", 0x000000E8, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_14", 0x000000E8, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_15", 0x000000E8, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_3", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_4
	{ "wait_cnt_norm_r_16", 0x000000EC, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_17", 0x000000EC, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_18", 0x000000EC, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_19", 0x000000EC, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_4", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_5
	{ "wait_cnt_norm_r_20", 0x000000F0, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_21", 0x000000F0, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_22", 0x000000F0, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_23", 0x000000F0, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_5", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_6
	{ "wait_cnt_norm_r_24", 0x000000F4, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_25", 0x000000F4, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_26", 0x000000F4, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_27", 0x000000F4, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_6", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD wait_cnt_r_7
	{ "wait_cnt_norm_r_28", 0x000000F8, 2, 0, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_29", 0x000000F8, 10, 8, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_30", 0x000000F8, 18, 16, CSR_RW, 0x00000004 },
	{ "wait_cnt_norm_r_31", 0x000000F8, 26, 24, CSR_RW, 0x00000004 },
	{ "WAIT_CNT_R_7", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_0
	{ "page_match_score_w_00", 0x000000FC, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_01", 0x000000FC, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_02", 0x000000FC, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_03", 0x000000FC, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_0", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_1
	{ "page_match_score_w_04", 0x00000100, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_05", 0x00000100, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_06", 0x00000100, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_07", 0x00000100, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_1", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_2
	{ "page_match_score_w_08", 0x00000104, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_09", 0x00000104, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_10", 0x00000104, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_11", 0x00000104, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_2", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_3
	{ "page_match_score_w_12", 0x00000108, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_13", 0x00000108, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_14", 0x00000108, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_15", 0x00000108, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_3", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_4
	{ "page_match_score_w_16", 0x0000010C, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_17", 0x0000010C, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_18", 0x0000010C, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_19", 0x0000010C, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_4", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_5
	{ "page_match_score_w_20", 0x00000110, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_21", 0x00000110, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_22", 0x00000110, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_23", 0x00000110, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_5", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_6
	{ "page_match_score_w_24", 0x00000114, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_25", 0x00000114, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_26", 0x00000114, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_27", 0x00000114, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_6", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_w_7
	{ "page_match_score_w_28", 0x00000118, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_w_29", 0x00000118, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_w_30", 0x00000118, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_w_31", 0x00000118, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_W_7", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_0
	{ "page_match_score_r_00", 0x0000011C, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_01", 0x0000011C, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_02", 0x0000011C, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_03", 0x0000011C, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_0", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_1
	{ "page_match_score_r_04", 0x00000120, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_05", 0x00000120, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_06", 0x00000120, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_07", 0x00000120, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_1", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_2
	{ "page_match_score_r_08", 0x00000124, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_09", 0x00000124, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_10", 0x00000124, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_11", 0x00000124, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_2", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_3
	{ "page_match_score_r_12", 0x00000128, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_13", 0x00000128, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_14", 0x00000128, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_15", 0x00000128, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_3", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_4
	{ "page_match_score_r_16", 0x0000012C, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_17", 0x0000012C, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_18", 0x0000012C, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_19", 0x0000012C, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_4", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_5
	{ "page_match_score_r_20", 0x00000130, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_21", 0x00000130, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_22", 0x00000130, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_23", 0x00000130, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_5", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_6
	{ "page_match_score_r_24", 0x00000134, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_25", 0x00000134, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_26", 0x00000134, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_27", 0x00000134, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_6", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD page_match_r_7
	{ "page_match_score_r_28", 0x00000138, 3, 0, CSR_RW, 0x00000008 },
	{ "page_match_score_r_29", 0x00000138, 11, 8, CSR_RW, 0x00000008 },
	{ "page_match_score_r_30", 0x00000138, 19, 16, CSR_RW, 0x00000008 },
	{ "page_match_score_r_31", 0x00000138, 27, 24, CSR_RW, 0x00000008 },
	{ "PAGE_MATCH_R_7", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD general_score
	{ "bank_switch_score", 0x0000013C, 3, 0, CSR_RW, 0x00000004 },
	{ "keep_agent_score", 0x0000013C, 11, 8, CSR_RW, 0x00000004 },
	{ "keep_rw_score", 0x0000013C, 19, 16, CSR_RW, 0x00000002 },
	{ "debug_mon_sel", 0x0000013C, 29, 24, CSR_RW, 0x00000000 },
	{ "GENERAL_SCORE", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_type
	{ "row_before_bank", 0x00000140, 0, 0, CSR_RW, 0x00000001 },
	{ "bank_addr_type", 0x00000140, 8, 8, CSR_RW, 0x00000001 },
	{ "row_addr_type", 0x00000140, 18, 16, CSR_RW, 0x00000000 },
	{ "col_addr_type", 0x00000140, 25, 24, CSR_RW, 0x00000000 },
	{ "DRAM_TYPE", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_ctrl_0
	{ "pat_gen_0_en", 0x00000144, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_0_write", 0x00000144, 8, 8, CSR_RW, 0x00000000 },
	{ "pat_gen_0_all_agent", 0x00000144, 16, 16, CSR_RW, 0x00000000 },
	{ "pat_gen_0_agent", 0x00000144, 28, 24, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_CTRL_0", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_ctrl_1
	{ "pat_gen_0_shuffle", 0x00000148, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_0_wstrb_en", 0x00000148, 8, 8, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_CTRL_1", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_ctrl_2
	{ "pat_gen_0_wstrb", 0x0000014C, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "PAT_GEN_0_CTRL_2", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_0
	{ "pat_gen_0_data_0", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_0", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_1
	{ "pat_gen_0_data_1", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_1", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_2
	{ "pat_gen_0_data_2", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_2", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_3
	{ "pat_gen_0_data_3", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_3", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_4
	{ "pat_gen_0_data_4", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_4", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_5
	{ "pat_gen_0_data_5", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_5", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_6
	{ "pat_gen_0_data_6", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_6", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_0_dat_7
	{ "pat_gen_0_data_7", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_0_DAT_7", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_ctrl_0
	{ "pat_gen_1_en", 0x00000170, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_1_write", 0x00000170, 8, 8, CSR_RW, 0x00000000 },
	{ "pat_gen_1_all_agent", 0x00000170, 16, 16, CSR_RW, 0x00000000 },
	{ "pat_gen_1_agent", 0x00000170, 28, 24, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_CTRL_0", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_ctrl_1
	{ "pat_gen_1_shuffle", 0x00000174, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_1_wstrb_en", 0x00000174, 8, 8, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_CTRL_1", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_ctrl_2
	{ "pat_gen_1_wstrb", 0x00000178, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "PAT_GEN_1_CTRL_2", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_0
	{ "pat_gen_1_data_0", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_0", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_1
	{ "pat_gen_1_data_1", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_1", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_2
	{ "pat_gen_1_data_2", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_2", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_3
	{ "pat_gen_1_data_3", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_3", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_4
	{ "pat_gen_1_data_4", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_4", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_5
	{ "pat_gen_1_data_5", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_5", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_6
	{ "pat_gen_1_data_6", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_6", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_1_dat_7
	{ "pat_gen_1_data_7", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_1_DAT_7", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_ctrl_0
	{ "pat_gen_2_en", 0x0000019C, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_2_write", 0x0000019C, 8, 8, CSR_RW, 0x00000000 },
	{ "pat_gen_2_all_agent", 0x0000019C, 16, 16, CSR_RW, 0x00000000 },
	{ "pat_gen_2_agent", 0x0000019C, 28, 24, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_CTRL_0", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_ctrl_1
	{ "pat_gen_2_shuffle", 0x000001A0, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_2_wstrb_en", 0x000001A0, 8, 8, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_CTRL_1", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_ctrl_2
	{ "pat_gen_2_wstrb", 0x000001A4, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "PAT_GEN_2_CTRL_2", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_0
	{ "pat_gen_2_data_0", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_0", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_1
	{ "pat_gen_2_data_1", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_1", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_2
	{ "pat_gen_2_data_2", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_2", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_3
	{ "pat_gen_2_data_3", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_3", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_4
	{ "pat_gen_2_data_4", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_4", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_5
	{ "pat_gen_2_data_5", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_5", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_6
	{ "pat_gen_2_data_6", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_6", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_2_dat_7
	{ "pat_gen_2_data_7", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_2_DAT_7", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_ctrl_0
	{ "pat_gen_3_en", 0x000001C8, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_3_write", 0x000001C8, 8, 8, CSR_RW, 0x00000000 },
	{ "pat_gen_3_all_agent", 0x000001C8, 16, 16, CSR_RW, 0x00000000 },
	{ "pat_gen_3_agent", 0x000001C8, 28, 24, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_CTRL_0", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_ctrl_1
	{ "pat_gen_3_shuffle", 0x000001CC, 0, 0, CSR_RW, 0x00000000 },
	{ "pat_gen_3_wstrb_en", 0x000001CC, 8, 8, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_CTRL_1", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_ctrl_2
	{ "pat_gen_3_wstrb", 0x000001D0, 31, 0, CSR_RW, 0xFFFFFFFF },
	{ "PAT_GEN_3_CTRL_2", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_0
	{ "pat_gen_3_data_0", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_0", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_1
	{ "pat_gen_3_data_1", 0x000001D8, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_1", 0x000001D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_2
	{ "pat_gen_3_data_2", 0x000001DC, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_2", 0x000001DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_3
	{ "pat_gen_3_data_3", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_3", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_4
	{ "pat_gen_3_data_4", 0x000001E4, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_4", 0x000001E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_5
	{ "pat_gen_3_data_5", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_5", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_6
	{ "pat_gen_3_data_6", 0x000001EC, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_6", 0x000001EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pat_gen_3_dat_7
	{ "pat_gen_3_data_7", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	{ "PAT_GEN_3_DAT_7", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD chksum_0_ctrl
	{ "checksum_0_en", 0x000001F4, 0, 0, CSR_RW, 0x00000000 },
	{ "checksum_0_type", 0x000001F4, 9, 8, CSR_RW, 0x00000000 },
	{ "checksum_0_agent", 0x000001F4, 20, 16, CSR_RW, 0x00000000 },
	{ "CHKSUM_0_CTRL", 0x000001F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD chksum_0_0
	{ "checksum_0_0", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_0", 0x000001F8, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_1
	{ "checksum_0_1", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_1", 0x000001FC, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_2
	{ "checksum_0_2", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_2", 0x00000200, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_3
	{ "checksum_0_3", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_3", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_4
	{ "checksum_0_4", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_4", 0x00000208, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_5
	{ "checksum_0_5", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_5", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_6
	{ "checksum_0_6", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_6", 0x00000210, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_0_7
	{ "checksum_0_7", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_0_7", 0x00000214, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_ctrl
	{ "checksum_1_en", 0x00000218, 0, 0, CSR_RW, 0x00000000 },
	{ "checksum_1_type", 0x00000218, 9, 8, CSR_RW, 0x00000000 },
	{ "checksum_1_agent", 0x00000218, 20, 16, CSR_RW, 0x00000000 },
	{ "CHKSUM_1_CTRL", 0x00000218, 31, 0, CSR_RW, 0x00000000 },
	// WORD chksum_1_0
	{ "checksum_1_0", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_0", 0x0000021C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_1
	{ "checksum_1_1", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_1", 0x00000220, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_2
	{ "checksum_1_2", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_2", 0x00000224, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_3
	{ "checksum_1_3", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_3", 0x00000228, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_4
	{ "checksum_1_4", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_4", 0x0000022C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_5
	{ "checksum_1_5", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_5", 0x00000230, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_6
	{ "checksum_1_6", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_6", 0x00000234, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_1_7
	{ "checksum_1_7", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_1_7", 0x00000238, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_ctrl
	{ "checksum_2_en", 0x0000023C, 0, 0, CSR_RW, 0x00000000 },
	{ "checksum_2_type", 0x0000023C, 9, 8, CSR_RW, 0x00000000 },
	{ "checksum_2_agent", 0x0000023C, 20, 16, CSR_RW, 0x00000000 },
	{ "CHKSUM_2_CTRL", 0x0000023C, 31, 0, CSR_RW, 0x00000000 },
	// WORD chksum_2_0
	{ "checksum_2_0", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_0", 0x00000240, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_1
	{ "checksum_2_1", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_1", 0x00000244, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_2
	{ "checksum_2_2", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_2", 0x00000248, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_3
	{ "checksum_2_3", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_3", 0x0000024C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_4
	{ "checksum_2_4", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_4", 0x00000250, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_5
	{ "checksum_2_5", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_5", 0x00000254, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_6
	{ "checksum_2_6", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_6", 0x00000258, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_2_7
	{ "checksum_2_7", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_2_7", 0x0000025C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_ctrl
	{ "checksum_3_en", 0x00000260, 0, 0, CSR_RW, 0x00000000 },
	{ "checksum_3_type", 0x00000260, 9, 8, CSR_RW, 0x00000000 },
	{ "checksum_3_agent", 0x00000260, 20, 16, CSR_RW, 0x00000000 },
	{ "CHKSUM_3_CTRL", 0x00000260, 31, 0, CSR_RW, 0x00000000 },
	// WORD chksum_3_0
	{ "checksum_3_0", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_0", 0x00000264, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_1
	{ "checksum_3_1", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_1", 0x00000268, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_2
	{ "checksum_3_2", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_2", 0x0000026C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_3
	{ "checksum_3_3", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_3", 0x00000270, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_4
	{ "checksum_3_4", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_4", 0x00000274, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_5
	{ "checksum_3_5", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_5", 0x00000278, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_6
	{ "checksum_3_6", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_6", 0x0000027C, 31, 0, CSR_RO, 0x00000000 },
	// WORD chksum_3_7
	{ "checksum_3_7", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	{ "CHKSUM_3_7", 0x00000280, 31, 0, CSR_RO, 0x00000000 },
	// WORD mon_agent
	{ "w_addr_mon_agent", 0x00000284, 4, 0, CSR_RW, 0x00000000 },
	{ "r_addr_mon_agent", 0x00000284, 12, 8, CSR_RW, 0x00000000 },
	{ "w_data_mon_agent", 0x00000284, 20, 16, CSR_RW, 0x00000000 },
	{ "r_data_mon_agent", 0x00000284, 28, 24, CSR_RW, 0x00000000 },
	{ "MON_AGENT", 0x00000284, 31, 0, CSR_RW, 0x00000000 },
	// WORD last_status_en
	{ "last_w_addr_en", 0x00000288, 0, 0, CSR_RW, 0x00000000 },
	{ "last_r_addr_en", 0x00000288, 8, 8, CSR_RW, 0x00000000 },
	{ "last_w_data_en", 0x00000288, 16, 16, CSR_RW, 0x00000000 },
	{ "last_r_data_en", 0x00000288, 24, 24, CSR_RW, 0x00000000 },
	{ "LAST_STATUS_EN", 0x00000288, 31, 0, CSR_RW, 0x00000000 },
	// WORD last_status_all_agent
	{ "last_w_addr_all_agent", 0x0000028C, 0, 0, CSR_RW, 0x00000001 },
	{ "last_r_addr_all_agent", 0x0000028C, 8, 8, CSR_RW, 0x00000001 },
	{ "last_w_data_all_agent", 0x0000028C, 16, 16, CSR_RW, 0x00000001 },
	{ "last_r_data_all_agent", 0x0000028C, 24, 24, CSR_RW, 0x00000001 },
	{ "LAST_STATUS_ALL_AGENT", 0x0000028C, 31, 0, CSR_RW, 0x00000000 },
	// WORD status_last_w_addr
	{ "last_w_addr", 0x00000290, 30, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_ADDR", 0x00000290, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_addr
	{ "last_r_addr", 0x00000294, 30, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_ADDR", 0x00000294, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_0
	{ "last_w_data_0", 0x00000298, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_0", 0x00000298, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_1
	{ "last_w_data_1", 0x0000029C, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_1", 0x0000029C, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_2
	{ "last_w_data_2", 0x000002A0, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_2", 0x000002A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_3
	{ "last_w_data_3", 0x000002A4, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_3", 0x000002A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_4
	{ "last_w_data_4", 0x000002A8, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_4", 0x000002A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_5
	{ "last_w_data_5", 0x000002AC, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_5", 0x000002AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_6
	{ "last_w_data_6", 0x000002B0, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_6", 0x000002B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_w_data_7
	{ "last_w_data_7", 0x000002B4, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_W_DATA_7", 0x000002B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_0
	{ "last_r_data_0", 0x000002B8, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_0", 0x000002B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_1
	{ "last_r_data_1", 0x000002BC, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_1", 0x000002BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_2
	{ "last_r_data_2", 0x000002C0, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_2", 0x000002C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_3
	{ "last_r_data_3", 0x000002C4, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_3", 0x000002C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_4
	{ "last_r_data_4", 0x000002C8, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_4", 0x000002C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_5
	{ "last_r_data_5", 0x000002CC, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_5", 0x000002CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_6
	{ "last_r_data_6", 0x000002D0, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_6", 0x000002D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_last_r_data_7
	{ "last_r_data_7", 0x000002D4, 31, 0, CSR_RO, 0x00000000 },
	{ "STATUS_LAST_R_DATA_7", 0x000002D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD resp_error_agent
	{ "w_resp_error_agent", 0x000002D8, 4, 0, CSR_RO, 0x00000000 },
	{ "r_resp_error_agent", 0x000002D8, 12, 8, CSR_RO, 0x00000000 },
	{ "RESP_ERROR_AGENT", 0x000002D8, 31, 0, CSR_RO, 0x00000000 },
	// WORD timeout_ctrl
	{ "timeout_en", 0x000002DC, 0, 0, CSR_RW, 0x00000000 },
	{ "timeout_cycle_th", 0x000002DC, 31, 16, CSR_RW, 0x0000FFFF },
	{ "TIMEOUT_CTRL", 0x000002DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD timeout_agent_0
	{ "timeout_w_resp_agent", 0x000002E0, 4, 0, CSR_RO, 0x00000000 },
	{ "timeout_r_addr_agent", 0x000002E0, 12, 8, CSR_RO, 0x00000000 },
	{ "timeout_w_addr_agent", 0x000002E0, 20, 16, CSR_RO, 0x00000000 },
	{ "timeout_w_data_agent", 0x000002E0, 28, 24, CSR_RO, 0x00000000 },
	{ "TIMEOUT_AGENT_0", 0x000002E0, 31, 0, CSR_RO, 0x00000000 },
	// WORD timeout_agent_1
	{ "timeout_r_data_agent", 0x000002E4, 20, 16, CSR_RO, 0x00000000 },
	{ "TIMEOUT_AGENT_1", 0x000002E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD darb_reserved_0
	{ "reserved_0", 0x000002E8, 31, 0, CSR_RW, 0x00000000 },
	{ "DARB_RESERVED_0", 0x000002E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD general_score_1
	{ "ini_r_score", 0x000002EC, 3, 0, CSR_RW, 0x00000000 },
	{ "ini_w_score", 0x000002EC, 11, 8, CSR_RW, 0x00000000 },
	{ "GENERAL_SCORE_1", 0x000002EC, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DARB_H_
