/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_FSC_H_
#define CSR_TABLE_FSC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_fsc[] = {
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
	// WORD word_mode
	{ "mode", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "frame_start_mode", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "ini_bayer_phase", 0x00000010, 17, 16, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD res_i
	{ "width_i", 0x00000014, 15, 0, CSR_RW, 0x00000A20 },
	{ "height_i", 0x00000014, 31, 16, CSR_RW, 0x00000798 },
	{ "RES_I", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD res_o
	{ "width_o", 0x00000018, 15, 0, CSR_RW, 0x000005B2 },
	{ "height_o", 0x00000018, 31, 16, CSR_RW, 0x00000446 },
	{ "RES_O", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ini_phase_cnt_hor
	{ "ini_phase_cnt_hor", 0x0000001C, 18, 0, CSR_RW, 0x00000000 },
	{ "WORD_INI_PHASE_CNT_HOR", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_ini_phase_cnt_ver
	{ "ini_phase_cnt_ver", 0x00000020, 18, 0, CSR_RW, 0x00000000 },
	{ "WORD_INI_PHASE_CNT_VER", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_phase_cnt_step_hor
	{ "phase_cnt_step_hor", 0x00000024, 18, 0, CSR_RW, 0x00000000 },
	{ "WORD_PHASE_CNT_STEP_HOR", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_phase_cnt_step_ver
	{ "phase_cnt_step_ver", 0x00000028, 18, 0, CSR_RW, 0x00000000 },
	{ "WORD_PHASE_CNT_STEP_VER", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_g_coeff_sel
	{ "g_coeff_sel", 0x0000002C, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_G_COEFF_SEL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD br_coeff_sel
	{ "b_h_coeff_sel", 0x00000030, 2, 0, CSR_RW, 0x00000000 },
	{ "b_v_coeff_sel", 0x00000030, 10, 8, CSR_RW, 0x00000000 },
	{ "r_h_coeff_sel", 0x00000030, 18, 16, CSR_RW, 0x00000000 },
	{ "r_v_coeff_sel", 0x00000030, 26, 24, CSR_RW, 0x00000000 },
	{ "BR_COEFF_SEL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD optional
	{ "is_filter_at_zero_phase", 0x00000034, 0, 0, CSR_RW, 0x00000001 },
	{ "OPTIONAL", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000038, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_FSC_H_
