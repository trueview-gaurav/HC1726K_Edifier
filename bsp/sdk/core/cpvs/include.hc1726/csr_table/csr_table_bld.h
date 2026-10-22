/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_BLD_H_
#define CSR_TABLE_BLD_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_bld[] = {
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
	// WORD resolution
	{ "width", 0x00000010, 15, 0, CSR_RW, 0x00000100 },
	{ "height", 0x00000010, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_table_x_num
	{ "table_x_num", 0x00000014, 5, 0, CSR_RW, 0x00000021 },
	{ "WORD_TABLE_X_NUM", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_table_cnt_ini
	{ "table_x_cnt_ini", 0x00000018, 6, 0, CSR_RW, 0x00000000 },
	{ "table_y_cnt_ini", 0x00000018, 22, 16, CSR_RW, 0x00000000 },
	{ "WORD_TABLE_CNT_INI", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_table_cnt_step
	{ "table_x_cnt_step", 0x0000001C, 6, 0, CSR_RW, 0x00000000 },
	{ "table_y_cnt_step", 0x0000001C, 22, 16, CSR_RW, 0x00000000 },
	{ "WORD_TABLE_CNT_STEP", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000020, 1, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_0
	{ "reserved_0", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_0", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_reserved_1
	{ "reserved_1", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "WORD_RESERVED_1", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_0
	{ "weight_0", 0x0000002C, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_1", 0x0000002C, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_2", 0x0000002C, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_0", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_1
	{ "weight_3", 0x00000030, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_4", 0x00000030, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_5", 0x00000030, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_1", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_2
	{ "weight_6", 0x00000034, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_7", 0x00000034, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_8", 0x00000034, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_2", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_3
	{ "weight_9", 0x00000038, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_10", 0x00000038, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_11", 0x00000038, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_3", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_4
	{ "weight_12", 0x0000003C, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_13", 0x0000003C, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_14", 0x0000003C, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_4", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_5
	{ "weight_15", 0x00000040, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_16", 0x00000040, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_17", 0x00000040, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_5", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_6
	{ "weight_18", 0x00000044, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_19", 0x00000044, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_20", 0x00000044, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_6", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_7
	{ "weight_21", 0x00000048, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_22", 0x00000048, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_23", 0x00000048, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_7", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_8
	{ "weight_24", 0x0000004C, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_25", 0x0000004C, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_26", 0x0000004C, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_8", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_9
	{ "weight_27", 0x00000050, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_28", 0x00000050, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_29", 0x00000050, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_9", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_weight_10
	{ "weight_30", 0x00000054, 8, 0, CSR_RW, 0x00000000 },
	{ "weight_31", 0x00000054, 17, 9, CSR_RW, 0x00000000 },
	{ "weight_32", 0x00000054, 26, 18, CSR_RW, 0x00000000 },
	{ "WORD_WEIGHT_10", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_table_grid
	{ "table_grid_width", 0x00000058, 3, 0, CSR_RW, 0x00000008 },
	{ "table_grid_height_inv", 0x00000058, 25, 5, CSR_RW, 0x00007878 },
	{ "WORD_TABLE_GRID", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD ctrl
	{ "mode", 0x0000005C, 0, 0, CSR_RW, 0x00000000 },
	{ "CTRL", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_BLD_H_
