/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_PXW_H_
#define CSR_TABLE_PXW_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_pxw[] = {
	// WORD pw0_00
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "PW0_00", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pw0_01
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_bw_insufficient", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_overflow", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_access_violation", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "PW0_01", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pw0_02
	{ "irq_clear_burst_fifo_full", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_resp_error", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "PW0_02", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD pw0_03
	{ "status_frame_end", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "status_bw_insufficient", 0x0000000C, 8, 8, CSR_RO, 0x00000000 },
	{ "status_overflow", 0x0000000C, 16, 16, CSR_RO, 0x00000000 },
	{ "status_access_violation", 0x0000000C, 24, 24, CSR_RO, 0x00000000 },
	{ "PW0_03", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD pw0_04
	{ "status_burst_fifo_full", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_resp_error", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "PW0_04", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD pw0_05
	{ "irq_mask_frame_end", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_bw_insufficient", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_overflow", 0x00000014, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_access_violation", 0x00000014, 24, 24, CSR_RW, 0x00000001 },
	{ "PW0_05", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_06
	{ "irq_mask_burst_fifo_full", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_resp_error", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "PW0_06", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_07
	{ "access_illegal_hang", 0x0000001C, 0, 0, CSR_RW, 0x00000001 },
	{ "access_illegal_mask", 0x0000001C, 8, 8, CSR_RW, 0x00000001 },
	{ "PW0_07", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_08
	{ "target_fifo_level", 0x00000020, 8, 0, CSR_RW, 0x00000020 },
	{ "fifo_full_level", 0x00000020, 24, 16, CSR_RW, 0x00000100 },
	{ "PW0_08", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_09
	{ "height", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "width", 0x00000024, 31, 16, CSR_RW, 0x00000000 },
	{ "PW0_09", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_10
	{ "y_only_e", 0x00000028, 0, 0, CSR_RW, 0x00000000 },
	{ "y_only_o", 0x00000028, 8, 8, CSR_RW, 0x00000000 },
	{ "msb_only", 0x00000028, 16, 16, CSR_RW, 0x00000000 },
	{ "PW0_10", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_12
	{ "fifo_flush_len", 0x00000030, 13, 0, CSR_RW, 0x00000000 },
	{ "fifo_start_phase", 0x00000030, 20, 16, CSR_RW, 0x00000000 },
	{ "fifo_end_phase", 0x00000030, 28, 24, CSR_RW, 0x0000001F },
	{ "PW0_12", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_16
	{ "pixel_flush_len", 0x00000040, 15, 0, CSR_RW, 0x00000000 },
	{ "PW0_16", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_17
	{ "flush_addr_skip_e", 0x00000044, 13, 0, CSR_RW, 0x00000000 },
	{ "PW0_17", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_18
	{ "flush_addr_skip_o", 0x00000048, 13, 0, CSR_RW, 0x00000000 },
	{ "PW0_18", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_19
	{ "fifo_flush_len_last", 0x0000004C, 2, 0, CSR_RW, 0x00000000 },
	{ "package_size_last", 0x0000004C, 18, 16, CSR_RW, 0x00000000 },
	{ "PW0_19", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_20
	{ "v_start", 0x00000050, 15, 0, CSR_RW, 0x00000000 },
	{ "v_end", 0x00000050, 31, 16, CSR_RW, 0x00000000 },
	{ "PW0_20", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_21
	{ "h_start", 0x00000054, 15, 0, CSR_RW, 0x00000000 },
	{ "h_end", 0x00000054, 31, 16, CSR_RW, 0x00000000 },
	{ "PW0_21", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_22
	{ "bank_interleave_type", 0x00000058, 1, 0, CSR_RW, 0x00000002 },
	{ "bank_group_type", 0x00000058, 9, 8, CSR_RW, 0x00000001 },
	{ "PW0_22", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_23
	{ "reserved", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	{ "PW0_23", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_40
	{ "ini_addr_linear_0", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_40", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_41
	{ "ini_addr_linear_1", 0x000000A4, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_41", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_42
	{ "ini_addr_linear_2", 0x000000A8, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_42", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_43
	{ "ini_addr_linear_3", 0x000000AC, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_43", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_44
	{ "ini_addr_linear_4", 0x000000B0, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_44", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_45
	{ "ini_addr_linear_5", 0x000000B4, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_45", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_46
	{ "ini_addr_linear_6", 0x000000B8, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_46", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_47
	{ "ini_addr_linear_7", 0x000000BC, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_47", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_48
	{ "ini_addr_bank_offset", 0x000000C0, 2, 0, CSR_RW, 0x00000000 },
	{ "ini_addr_from_ext", 0x000000C0, 8, 8, CSR_RW, 0x00000000 },
	{ "PW0_48", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_49
	{ "roi_enable", 0x000000C4, 0, 0, CSR_RW, 0x00000000 },
	{ "PW0_49", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_50
	{ "roi_enable_0", 0x000000C8, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_enable_1", 0x000000C8, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_enable_2", 0x000000C8, 16, 16, CSR_RW, 0x00000000 },
	{ "roi_enable_3", 0x000000C8, 24, 24, CSR_RW, 0x00000000 },
	{ "PW0_50", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_51
	{ "roi_enable_4", 0x000000CC, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_enable_5", 0x000000CC, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_enable_6", 0x000000CC, 16, 16, CSR_RW, 0x00000000 },
	{ "roi_enable_7", 0x000000CC, 24, 24, CSR_RW, 0x00000000 },
	{ "PW0_51", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_52
	{ "roi_enable_8", 0x000000D0, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_enable_9", 0x000000D0, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_enable_a", 0x000000D0, 16, 16, CSR_RW, 0x00000000 },
	{ "roi_enable_b", 0x000000D0, 24, 24, CSR_RW, 0x00000000 },
	{ "PW0_52", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_53
	{ "roi_enable_c", 0x000000D4, 0, 0, CSR_RW, 0x00000000 },
	{ "roi_enable_d", 0x000000D4, 8, 8, CSR_RW, 0x00000000 },
	{ "roi_enable_e", 0x000000D4, 16, 16, CSR_RW, 0x00000000 },
	{ "roi_enable_f", 0x000000D4, 24, 24, CSR_RW, 0x00000000 },
	{ "PW0_53", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_54
	{ "v_start_0", 0x000000D8, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_0", 0x000000D8, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_54", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_55
	{ "h_start_0", 0x000000DC, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_0", 0x000000DC, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_55", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_56
	{ "v_start_1", 0x000000E0, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_1", 0x000000E0, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_56", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_57
	{ "h_start_1", 0x000000E4, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_1", 0x000000E4, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_57", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_58
	{ "v_start_2", 0x000000E8, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_2", 0x000000E8, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_58", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_59
	{ "h_start_2", 0x000000EC, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_2", 0x000000EC, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_59", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_60
	{ "v_start_3", 0x000000F0, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_3", 0x000000F0, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_60", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_61
	{ "h_start_3", 0x000000F4, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_3", 0x000000F4, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_61", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_62
	{ "v_start_4", 0x000000F8, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_4", 0x000000F8, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_62", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_63
	{ "h_start_4", 0x000000FC, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_4", 0x000000FC, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_63", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_64
	{ "v_start_5", 0x00000100, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_5", 0x00000100, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_64", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_65
	{ "h_start_5", 0x00000104, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_5", 0x00000104, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_65", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_66
	{ "v_start_6", 0x00000108, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_6", 0x00000108, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_66", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_67
	{ "h_start_6", 0x0000010C, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_6", 0x0000010C, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_67", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_68
	{ "v_start_7", 0x00000110, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_7", 0x00000110, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_68", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_69
	{ "h_start_7", 0x00000114, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_7", 0x00000114, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_69", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_70
	{ "v_start_8", 0x00000118, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_8", 0x00000118, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_70", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_71
	{ "h_start_8", 0x0000011C, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_8", 0x0000011C, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_71", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_72
	{ "v_start_9", 0x00000120, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_9", 0x00000120, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_72", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_73
	{ "h_start_9", 0x00000124, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_9", 0x00000124, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_73", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_74
	{ "v_start_a", 0x00000128, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_a", 0x00000128, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_74", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_75
	{ "h_start_a", 0x0000012C, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_a", 0x0000012C, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_75", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_76
	{ "v_start_b", 0x00000130, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_b", 0x00000130, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_76", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_77
	{ "h_start_b", 0x00000134, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_b", 0x00000134, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_77", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_78
	{ "v_start_c", 0x00000138, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_c", 0x00000138, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_78", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_79
	{ "h_start_c", 0x0000013C, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_c", 0x0000013C, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_79", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_80
	{ "v_start_d", 0x00000140, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_d", 0x00000140, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_80", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_81
	{ "h_start_d", 0x00000144, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_d", 0x00000144, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_81", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_82
	{ "v_start_e", 0x00000148, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_e", 0x00000148, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_82", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_83
	{ "h_start_e", 0x0000014C, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_e", 0x0000014C, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_83", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_84
	{ "v_start_f", 0x00000150, 13, 0, CSR_RW, 0x00000000 },
	{ "v_end_f", 0x00000150, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_84", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_85
	{ "h_start_f", 0x00000154, 13, 0, CSR_RW, 0x00000000 },
	{ "h_end_f", 0x00000154, 29, 16, CSR_RW, 0x00003FFF },
	{ "PW0_85", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_86
	{ "allow_stall", 0x00000158, 0, 0, CSR_RW, 0x00000001 },
	{ "allow_drop_frame", 0x00000158, 8, 8, CSR_RW, 0x00000000 },
	{ "PW0_86", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_90
	{ "frame_start_mode", 0x00000168, 0, 0, CSR_RW, 0x00000000 },
	{ "col_addr_type", 0x00000168, 9, 8, CSR_RW, 0x00000000 },
	{ "PW0_90", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_91
	{ "target_burst_len", 0x0000016C, 4, 0, CSR_RW, 0x00000010 },
	{ "access_end_sel", 0x0000016C, 8, 8, CSR_RW, 0x00000001 },
	{ "debug_mon_sel", 0x0000016C, 24, 24, CSR_RW, 0x00000000 },
	{ "axi_en", 0x0000016C, 28, 28, CSR_RW, 0x00000001 },
	{ "PW0_91", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_92
	{ "start_addr", 0x00000170, 27, 0, CSR_RW, 0x00000000 },
	{ "PW0_92", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD pw0_93
	{ "end_addr", 0x00000174, 27, 0, CSR_RW, 0x0FFFFFFF },
	{ "PW0_93", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_PXW_H_
