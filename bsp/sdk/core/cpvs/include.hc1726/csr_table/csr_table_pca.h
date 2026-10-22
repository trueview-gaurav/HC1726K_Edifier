/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PCA_H_
#define CSR_TABLE_PCA_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pca[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD res
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000010, 31, 16, CSR_RW, 0x00000438 },
	{ "RES", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mode_ctrl
	{ "mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "enable_regional_prcessing", 0x00000014, 10, 10, CSR_RW, 0x00000001 },
	{ "ink_mode", 0x00000014, 18, 16, CSR_RW, 0x00000007 },
	{ "ink_delta_sum_th", 0x00000014, 28, 24, CSR_RW, 0x00000000 },
	{ "MODE_CTRL", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_h_prime_shift
	{ "h_prime_shift", 0x00000018, 15, 0, CSR_RW, 0x00000000 },
	{ "h_prime_from_rgb_shift", 0x00000018, 31, 16, CSR_RW, 0x00000000 },
	{ "WORD_H_PRIME_SHIFT", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_redef_r
	{ "h_prime_r_redefined", 0x0000001C, 15, 0, CSR_RW, 0x00000000 },
	{ "H_PRIME_REDEF_R", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_redef_g
	{ "h_prime_g_redefined", 0x00000020, 15, 0, CSR_RW, 0x00004000 },
	{ "H_PRIME_REDEF_G", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_redef_b
	{ "h_prime_b_redefined", 0x00000024, 15, 0, CSR_RW, 0x00008000 },
	{ "H_PRIME_REDEF_B", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_r_deg
	{ "h_prime_r_pos_60degree", 0x00000028, 15, 0, CSR_RW, 0x00002000 },
	{ "h_prime_r_neg_60degree", 0x00000028, 31, 16, CSR_RW, 0x00002000 },
	{ "H_PRIME_R_DEG", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_g_deg
	{ "h_prime_g_pos_60degree", 0x0000002C, 15, 0, CSR_RW, 0x00002000 },
	{ "h_prime_g_neg_60degree", 0x0000002C, 31, 16, CSR_RW, 0x00002000 },
	{ "H_PRIME_G_DEG", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_b_deg
	{ "h_prime_b_pos_60degree", 0x00000030, 15, 0, CSR_RW, 0x00002000 },
	{ "h_prime_b_neg_60degree", 0x00000030, 31, 16, CSR_RW, 0x00002000 },
	{ "H_PRIME_B_DEG", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_prime_corr
	{ "h_prime_correction_term", 0x00000034, 14, 0, CSR_RW, 0x00000000 },
	{ "H_PRIME_CORR", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD h_cal_deg
	{ "h_cal_60_degree", 0x00000038, 14, 0, CSR_RW, 0x00001555 },
	{ "H_CAL_DEG", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ctrl
	{ "table_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "TABLE_CTRL", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eee_waddr
	{ "table_eee_w_addr", 0x00000040, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EEE_WADDR", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eee_wdata
	{ "table_eee_w_data", 0x00000044, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EEE_WDATA", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eoe_waddr
	{ "table_eoe_w_addr", 0x00000048, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EOE_WADDR", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eoe_wdata
	{ "table_eoe_w_data", 0x0000004C, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EOE_WDATA", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_oee_waddr
	{ "table_oee_w_addr", 0x00000050, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OEE_WADDR", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_oee_wdata
	{ "table_oee_w_data", 0x00000054, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OEE_WDATA", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ooe_waddr
	{ "table_ooe_w_addr", 0x00000058, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OOE_WADDR", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ooe_wdata
	{ "table_ooe_w_data", 0x0000005C, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OOE_WDATA", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eeo_waddr
	{ "table_eeo_w_addr", 0x00000060, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EEO_WADDR", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eeo_wdata
	{ "table_eeo_w_data", 0x00000064, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EEO_WDATA", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eoo_waddr
	{ "table_eoo_w_addr", 0x00000068, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EOO_WADDR", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eoo_wdata
	{ "table_eoo_w_data", 0x0000006C, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EOO_WDATA", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_oeo_waddr
	{ "table_oeo_w_addr", 0x00000070, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OEO_WADDR", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_oeo_wdata
	{ "table_oeo_w_data", 0x00000074, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OEO_WDATA", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ooo_waddr
	{ "table_ooo_w_addr", 0x00000078, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OOO_WADDR", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ooo_wdata
	{ "table_ooo_w_data", 0x0000007C, 25, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OOO_WDATA", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eee_raddr
	{ "table_eee_r_addr", 0x00000080, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EEE_RADDR", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eee_rdata
	{ "table_eee_r_data", 0x00000084, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_EEE_RDATA", 0x00000084, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_eoe_raddr
	{ "table_eoe_r_addr", 0x00000088, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EOE_RADDR", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eoe_rdata
	{ "table_eoe_r_data", 0x0000008C, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_EOE_RDATA", 0x0000008C, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_oee_raddr
	{ "table_oee_r_addr", 0x00000090, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OEE_RADDR", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_oee_rdata
	{ "table_oee_r_data", 0x00000094, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_OEE_RDATA", 0x00000094, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_ooe_raddr
	{ "table_ooe_r_addr", 0x00000098, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OOE_RADDR", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ooe_rdata
	{ "table_ooe_r_data", 0x0000009C, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_OOE_RDATA", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_eeo_raddr
	{ "table_eeo_r_addr", 0x000000A0, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EEO_RADDR", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eeo_rdata
	{ "table_eeo_r_data", 0x000000A4, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_EEO_RDATA", 0x000000A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_eoo_raddr
	{ "table_eoo_r_addr", 0x000000A8, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_EOO_RADDR", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_eoo_rdata
	{ "table_eoo_r_data", 0x000000AC, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_EOO_RDATA", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_oeo_raddr
	{ "table_oeo_r_addr", 0x000000B0, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OEO_RADDR", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_oeo_rdata
	{ "table_oeo_r_data", 0x000000B4, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_OEO_RDATA", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD table_ooo_raddr
	{ "table_ooo_r_addr", 0x000000B8, 8, 0, CSR_RW, 0x00000000 },
	{ "TABLE_OOO_RADDR", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD table_ooo_rdata
	{ "table_ooo_r_data", 0x000000BC, 25, 0, CSR_RO, 0x00000000 },
	{ "TABLE_OOO_RDATA", 0x000000BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x000000C0, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_0
	{ "reserved_0", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_0", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PCA_H_
