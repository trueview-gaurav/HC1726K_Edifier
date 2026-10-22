/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_EIRQ_H_
#define CSR_TABLE_EIRQ_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_eirq[] = {
	// WORD irq_clr
	{ "irq_clear_pos_0", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_pos_1", 0x00000000, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_pos_2", 0x00000000, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clear_pos_3", 0x00000000, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clear_pos_4", 0x00000000, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_neg_0", 0x00000000, 5, 5, CSR_W1P, 0x00000000 },
	{ "irq_clear_neg_1", 0x00000000, 6, 6, CSR_W1P, 0x00000000 },
	{ "irq_clear_neg_2", 0x00000000, 7, 7, CSR_W1P, 0x00000000 },
	{ "irq_clear_neg_3", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_neg_4", 0x00000000, 9, 9, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status
	{ "status_pos_0", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "status_pos_1", 0x00000004, 1, 1, CSR_RO, 0x00000000 },
	{ "status_pos_2", 0x00000004, 2, 2, CSR_RO, 0x00000000 },
	{ "status_pos_3", 0x00000004, 3, 3, CSR_RO, 0x00000000 },
	{ "status_pos_4", 0x00000004, 4, 4, CSR_RO, 0x00000000 },
	{ "status_neg_0", 0x00000004, 5, 5, CSR_RO, 0x00000000 },
	{ "status_neg_1", 0x00000004, 6, 6, CSR_RO, 0x00000000 },
	{ "status_neg_2", 0x00000004, 7, 7, CSR_RO, 0x00000000 },
	{ "status_neg_3", 0x00000004, 8, 8, CSR_RO, 0x00000000 },
	{ "status_neg_4", 0x00000004, 9, 9, CSR_RO, 0x00000000 },
	{ "STATUS", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_pos_0", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_pos_1", 0x00000008, 1, 1, CSR_RW, 0x00000001 },
	{ "irq_mask_pos_2", 0x00000008, 2, 2, CSR_RW, 0x00000001 },
	{ "irq_mask_pos_3", 0x00000008, 3, 3, CSR_RW, 0x00000001 },
	{ "irq_mask_pos_4", 0x00000008, 4, 4, CSR_RW, 0x00000001 },
	{ "irq_mask_neg_0", 0x00000008, 5, 5, CSR_RW, 0x00000001 },
	{ "irq_mask_neg_1", 0x00000008, 6, 6, CSR_RW, 0x00000001 },
	{ "irq_mask_neg_2", 0x00000008, 7, 7, CSR_RW, 0x00000001 },
	{ "irq_mask_neg_3", 0x00000008, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_neg_4", 0x00000008, 9, 9, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD edge_en
	{ "pos_en_0", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "pos_en_1", 0x0000000C, 1, 1, CSR_RW, 0x00000000 },
	{ "pos_en_2", 0x0000000C, 2, 2, CSR_RW, 0x00000000 },
	{ "pos_en_3", 0x0000000C, 3, 3, CSR_RW, 0x00000000 },
	{ "pos_en_4", 0x0000000C, 4, 4, CSR_RW, 0x00000000 },
	{ "neg_en_0", 0x0000000C, 5, 5, CSR_RW, 0x00000000 },
	{ "neg_en_1", 0x0000000C, 6, 6, CSR_RW, 0x00000000 },
	{ "neg_en_2", 0x0000000C, 7, 7, CSR_RW, 0x00000000 },
	{ "neg_en_3", 0x0000000C, 8, 8, CSR_RW, 0x00000000 },
	{ "neg_en_4", 0x0000000C, 9, 9, CSR_RW, 0x00000000 },
	{ "EDGE_EN", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbnc_en
	{ "dbnc_en_0", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "dbnc_en_1", 0x00000010, 1, 1, CSR_RW, 0x00000000 },
	{ "dbnc_en_2", 0x00000010, 2, 2, CSR_RW, 0x00000000 },
	{ "dbnc_en_3", 0x00000010, 3, 3, CSR_RW, 0x00000000 },
	{ "dbnc_en_4", 0x00000010, 4, 4, CSR_RW, 0x00000000 },
	{ "DBNC_EN", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_sens_num_0
	{ "sens_num_0", 0x00000014, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_SENS_NUM_0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_hold_num_0
	{ "hold_num_0", 0x00000018, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_HOLD_NUM_0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_sens_num_1
	{ "sens_num_1", 0x0000001C, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_SENS_NUM_1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_hold_num_1
	{ "hold_num_1", 0x00000020, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_HOLD_NUM_1", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_sens_num_2
	{ "sens_num_2", 0x00000024, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_SENS_NUM_2", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_hold_num_2
	{ "hold_num_2", 0x00000028, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_HOLD_NUM_2", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_sens_num_3
	{ "sens_num_3", 0x0000002C, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_SENS_NUM_3", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_hold_num_3
	{ "hold_num_3", 0x00000030, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_HOLD_NUM_3", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_sens_num_4
	{ "sens_num_4", 0x00000034, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_SENS_NUM_4", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_hold_num_4
	{ "hold_num_4", 0x00000038, 19, 0, CSR_RW, 0x000493E0 },
	{ "WORD_HOLD_NUM_4", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD lvl_trig_inv_en
	{ "level_trigger_inv_en_0", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "level_trigger_inv_en_1", 0x0000003C, 1, 1, CSR_RW, 0x00000000 },
	{ "level_trigger_inv_en_2", 0x0000003C, 2, 2, CSR_RW, 0x00000000 },
	{ "level_trigger_inv_en_3", 0x0000003C, 3, 3, CSR_RW, 0x00000000 },
	{ "level_trigger_inv_en_4", 0x0000003C, 4, 4, CSR_RW, 0x00000000 },
	{ "LVL_TRIG_INV_EN", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_EIRQ_H_
