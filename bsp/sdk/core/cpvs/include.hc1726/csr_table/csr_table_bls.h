/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_BLS_H_
#define CSR_TABLE_BLS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_bls[] = {
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
	// WORD cfa_format
	{ "cfa_mode", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "bayer_ini_phase", 0x00000010, 9, 8, CSR_RW, 0x00000000 },
	{ "CFA_FORMAT", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_0
	{ "cfa_phase_0", 0x00000014, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_1", 0x00000014, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_2", 0x00000014, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_3", 0x00000014, 26, 24, CSR_RW, 0x00000000 },
	{ "WORD_CFA_PHASE_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_1
	{ "cfa_phase_4", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_5", 0x00000018, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_6", 0x00000018, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_7", 0x00000018, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_2
	{ "cfa_phase_8", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_9", 0x0000001C, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_10", 0x0000001C, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_11", 0x0000001C, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_cfa_phase_3
	{ "cfa_phase_12", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "cfa_phase_13", 0x00000020, 10, 8, CSR_RW, 0x00000000 },
	{ "cfa_phase_14", 0x00000020, 18, 16, CSR_RW, 0x00000000 },
	{ "cfa_phase_15", 0x00000020, 26, 24, CSR_RW, 0x00000000 },
	{ "CFA_PHASE_3", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution_i
	{ "width", 0x00000024, 15, 0, CSR_RW, 0x00000780 },
	{ "height", 0x00000024, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION_I", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_status
	{ "level_enable", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "level_clear", 0x00000028, 8, 8, CSR_RW, 0x00000001 },
	{ "LEVEL_STATUS", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_lf_pix
	{ "level_lf_sx", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "level_lf_ex", 0x0000002C, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_LF_PIX", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_rt_pix
	{ "level_rt_sx", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "level_rt_ex", 0x00000030, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_RT_PIX", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_up_pix
	{ "level_up_sy", 0x00000034, 15, 0, CSR_RW, 0x00000000 },
	{ "level_up_ey", 0x00000034, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_UP_PIX", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_dn_pix
	{ "level_dn_sy", 0x00000038, 15, 0, CSR_RW, 0x00000000 },
	{ "level_dn_ey", 0x00000038, 31, 16, CSR_RW, 0x00000000 },
	{ "LEVEL_DN_PIX", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_pix_num_0
	{ "level_pix_num_g0", 0x0000003C, 22, 0, CSR_RW, 0x00000000 },
	{ "LEVEL_PIX_NUM_0", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_pix_num_1
	{ "level_pix_num_r", 0x00000040, 22, 0, CSR_RW, 0x00000000 },
	{ "LEVEL_PIX_NUM_1", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_pix_num_2
	{ "level_pix_num_b", 0x00000044, 22, 0, CSR_RW, 0x00000000 },
	{ "LEVEL_PIX_NUM_2", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_pix_num_3
	{ "level_pix_num_g1", 0x00000048, 22, 0, CSR_RW, 0x00000000 },
	{ "LEVEL_PIX_NUM_3", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_pix_num_4
	{ "level_pix_num_s", 0x0000004C, 22, 0, CSR_RW, 0x00000000 },
	{ "LEVEL_PIX_NUM_4", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD level_stat_0
	{ "level_g0", 0x00000050, 15, 0, CSR_RO, 0x00000000 },
	{ "level_r", 0x00000050, 31, 16, CSR_RO, 0x00000000 },
	{ "LEVEL_STAT_0", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD level_stat_1
	{ "level_b", 0x00000054, 15, 0, CSR_RO, 0x00000000 },
	{ "level_g1", 0x00000054, 31, 16, CSR_RO, 0x00000000 },
	{ "LEVEL_STAT_1", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD level_stat_2
	{ "level_s", 0x00000058, 15, 0, CSR_RO, 0x00000000 },
	{ "LEVEL_STAT_2", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD remainder_0
	{ "remainder_g0", 0x0000005C, 22, 0, CSR_RO, 0x00000000 },
	{ "REMAINDER_0", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD remainder_1
	{ "remainder_r", 0x00000060, 22, 0, CSR_RO, 0x00000000 },
	{ "REMAINDER_1", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD remainder_2
	{ "remainder_b", 0x00000064, 22, 0, CSR_RO, 0x00000000 },
	{ "REMAINDER_2", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD remainder_3
	{ "remainder_g1", 0x00000068, 22, 0, CSR_RO, 0x00000000 },
	{ "REMAINDER_3", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD remainder_4
	{ "remainder_s", 0x0000006C, 22, 0, CSR_RO, 0x00000000 },
	{ "REMAINDER_4", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000070, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_BLS_H_
