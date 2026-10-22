/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SC_H_
#define CSR_TABLE_SC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_sc[] = {
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
	// WORD scaling_mode
	{ "up_scaling_hor", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "up_scaling_ver", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "SCALING_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD res_i
	{ "width_i", 0x00000014, 15, 0, CSR_RW, 0x00000000 },
	{ "height_i", 0x00000014, 31, 16, CSR_RW, 0x00000000 },
	{ "RES_I", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD res_o
	{ "width_o", 0x00000018, 15, 0, CSR_RW, 0x00000000 },
	{ "height_o", 0x00000018, 31, 16, CSR_RW, 0x00000000 },
	{ "RES_O", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_phase_h
	{ "ini_phase_hor", 0x0000001C, 27, 0, CSR_RW, 0x00000000 },
	{ "INI_PHASE_H", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_phase_v
	{ "ini_phase_ver", 0x00000020, 27, 0, CSR_RW, 0x00000000 },
	{ "INI_PHASE_V", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD phase_step_h
	{ "phase_step_hor", 0x00000024, 24, 0, CSR_RW, 0x00000000 },
	{ "PHASE_STEP_H", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD phase_step_v
	{ "phase_step_ver", 0x00000028, 24, 0, CSR_RW, 0x00000000 },
	{ "PHASE_STEP_V", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_phase_ds_h
	{ "ini_filt_phase_ds_hor", 0x0000002C, 22, 0, CSR_RW, 0x00000000 },
	{ "INI_PHASE_DS_H", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_phase_ds_v
	{ "ini_filt_phase_ds_ver", 0x00000030, 22, 0, CSR_RW, 0x00000000 },
	{ "INI_PHASE_DS_V", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD phase_step_ds_h
	{ "filt_phase_step_ds_hor", 0x00000034, 19, 0, CSR_RW, 0x00000000 },
	{ "PHASE_STEP_DS_H", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD phase_step_ds_v
	{ "filt_phase_step_ds_ver", 0x00000038, 19, 0, CSR_RW, 0x00000000 },
	{ "PHASE_STEP_DS_V", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_cnt_h_0
	{ "ini_cnt_0_hor", 0x0000003C, 7, 0, CSR_RW, 0x00000000 },
	{ "ini_cnt_1_hor", 0x0000003C, 15, 8, CSR_RW, 0x00000000 },
	{ "ini_cnt_2_hor", 0x0000003C, 23, 16, CSR_RW, 0x00000000 },
	{ "ini_cnt_3_hor", 0x0000003C, 31, 24, CSR_RW, 0x00000000 },
	{ "INI_CNT_H_0", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_cnt_h_1
	{ "ini_cnt_4_hor", 0x00000040, 7, 0, CSR_RW, 0x00000000 },
	{ "ini_cnt_5_hor", 0x00000040, 15, 8, CSR_RW, 0x00000000 },
	{ "INI_CNT_H_1", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_cnt_v_0
	{ "ini_cnt_0_ver", 0x00000044, 7, 0, CSR_RW, 0x00000000 },
	{ "ini_cnt_1_ver", 0x00000044, 15, 8, CSR_RW, 0x00000000 },
	{ "ini_cnt_2_ver", 0x00000044, 23, 16, CSR_RW, 0x00000000 },
	{ "ini_cnt_3_ver", 0x00000044, 31, 24, CSR_RW, 0x00000000 },
	{ "INI_CNT_V_0", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD ini_cnt_v_1
	{ "ini_cnt_4_ver", 0x00000048, 7, 0, CSR_RW, 0x00000000 },
	{ "ini_cnt_5_ver", 0x00000048, 15, 8, CSR_RW, 0x00000000 },
	{ "INI_CNT_V_1", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_i_res
	{ "width_i_before_crop", 0x0000004C, 15, 0, CSR_RW, 0x00000000 },
	{ "height_i_before_crop", 0x0000004C, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_I_RES", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_i_lr
	{ "crop_i_left", 0x00000050, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_i_right", 0x00000050, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_I_LR", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_i_ud
	{ "crop_i_up", 0x00000054, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_i_down", 0x00000054, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_I_UD", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_o_lr
	{ "crop_o_left", 0x00000058, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_o_right", 0x00000058, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_O_LR", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD crop_o_ud
	{ "crop_o_up", 0x0000005C, 15, 0, CSR_RW, 0x00000000 },
	{ "crop_o_down", 0x0000005C, 31, 16, CSR_RW, 0x00000000 },
	{ "CROP_O_UD", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000060, 2, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_0
	{ "reserved_0", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_0", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SC_H_
