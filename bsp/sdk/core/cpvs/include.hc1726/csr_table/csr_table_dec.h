/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DEC_H_
#define CSR_TABLE_DEC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dec[] = {
	// WORD main
	{ "dec_en", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "MAIN", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD rst
	{ "dec_reset", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "frame_reset", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "RST", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irqsta
	{ "status_frame_done", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "status_frame_end", 0x00000008, 1, 1, CSR_RO, 0x00000000 },
	{ "status_frame_start", 0x00000008, 2, 2, CSR_RO, 0x00000000 },
	{ "status_mipi_short_pkt", 0x00000008, 3, 3, CSR_RO, 0x00000000 },
	{ "status_mipi_ecc_crt", 0x00000008, 4, 4, CSR_RO, 0x00000000 },
	{ "status_mipi_ecc_err", 0x00000008, 5, 5, CSR_RO, 0x00000000 },
	{ "status_mipi_pkt_err", 0x00000008, 6, 6, CSR_RO, 0x00000000 },
	{ "status_mipi_vc_err", 0x00000008, 7, 7, CSR_RO, 0x00000000 },
	{ "status_mipi_crc_err", 0x00000008, 8, 8, CSR_RO, 0x00000000 },
	{ "status_mipi_ovr_err", 0x00000008, 9, 9, CSR_RO, 0x00000000 },
	{ "status_mipi_word_err", 0x00000008, 10, 10, CSR_RO, 0x00000000 },
	{ "status_mipi_line_err", 0x00000008, 11, 11, CSR_RO, 0x00000000 },
	{ "status_hsp_ptc_err", 0x00000008, 12, 12, CSR_RO, 0x00000000 },
	{ "status_sony_ptc_err", 0x00000008, 13, 13, CSR_RO, 0x00000000 },
	{ "status_frame_size_err", 0x00000008, 14, 14, CSR_RO, 0x00000000 },
	{ "status_fifo_over_err", 0x00000008, 15, 15, CSR_RO, 0x00000000 },
	{ "status_lane_skew_err", 0x00000008, 16, 16, CSR_RO, 0x00000000 },
	{ "IRQSTA", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irqack
	{ "irq_clear_frame_done", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_end", 0x0000000C, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_start", 0x0000000C, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_short_pkt", 0x0000000C, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_ecc_crt", 0x0000000C, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_ecc_err", 0x0000000C, 5, 5, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_pkt_err", 0x0000000C, 6, 6, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_vc_err", 0x0000000C, 7, 7, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_crc_err", 0x0000000C, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_ovr_err", 0x0000000C, 9, 9, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_word_err", 0x0000000C, 10, 10, CSR_W1P, 0x00000000 },
	{ "irq_clear_mipi_line_err", 0x0000000C, 11, 11, CSR_W1P, 0x00000000 },
	{ "irq_clear_hsp_ptc_err", 0x0000000C, 12, 12, CSR_W1P, 0x00000000 },
	{ "irq_clear_sony_ptc_err", 0x0000000C, 13, 13, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_size_err", 0x0000000C, 14, 14, CSR_W1P, 0x00000000 },
	{ "irq_clear_fifo_over_err", 0x0000000C, 15, 15, CSR_W1P, 0x00000000 },
	{ "irq_clear_lane_skew_err", 0x0000000C, 16, 16, CSR_W1P, 0x00000000 },
	{ "IRQACK", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irqmsk
	{ "irq_mask_frame_done", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_end", 0x00000010, 1, 1, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_start", 0x00000010, 2, 2, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_short_pkt", 0x00000010, 3, 3, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_ecc_crt", 0x00000010, 4, 4, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_ecc_err", 0x00000010, 5, 5, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_pkt_err", 0x00000010, 6, 6, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_vc_err", 0x00000010, 7, 7, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_crc_err", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_ovr_err", 0x00000010, 9, 9, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_word_err", 0x00000010, 10, 10, CSR_RW, 0x00000000 },
	{ "irq_mask_mipi_line_err", 0x00000010, 11, 11, CSR_RW, 0x00000000 },
	{ "irq_mask_hsp_ptc_err", 0x00000010, 12, 12, CSR_RW, 0x00000000 },
	{ "irq_mask_sony_ptc_err", 0x00000010, 13, 13, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_size_err", 0x00000010, 14, 14, CSR_RW, 0x00000000 },
	{ "irq_mask_fifo_over_err", 0x00000010, 15, 15, CSR_RW, 0x00000000 },
	{ "irq_mask_lane_skew_err", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "IRQMSK", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg
	{ "spec_sel", 0x00000014, 2, 0, CSR_RW, 0x00000000 },
	{ "mode_sel", 0x00000014, 9, 8, CSR_RW, 0x00000000 },
	{ "lane_sel", 0x00000014, 17, 16, CSR_RW, 0x00000000 },
	{ "mipi_sw_en", 0x00000014, 24, 24, CSR_RW, 0x00000000 },
	{ "mipi_sw_num", 0x00000014, 29, 28, CSR_RW, 0x00000000 },
	{ "CFG", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word
	{ "word_size", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "msb_first", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD wth
	{ "word_num", 0x0000001C, 15, 0, CSR_RW, 0x00000000 },
	{ "WTH", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD high
	{ "line_num", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "HIGH", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD hsp
	{ "enable_word_flr", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "enable_word_crc", 0x00000024, 8, 8, CSR_RW, 0x00000000 },
	{ "ail_msb_first", 0x00000024, 16, 16, CSR_RW, 0x00000000 },
	{ "flr_word_num", 0x00000024, 31, 24, CSR_RW, 0x00000000 },
	{ "HSP", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD vblk
	{ "vbp_line_num", 0x00000028, 11, 0, CSR_RW, 0x00000004 },
	{ "vfp_line_num", 0x00000028, 27, 16, CSR_RW, 0x00000004 },
	{ "VBLK", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD hblk
	{ "hbp_word_num", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "hfp_word_num", 0x0000002C, 31, 16, CSR_RW, 0x00000000 },
	{ "HBLK", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD chk
	{ "dis_ecc_crt", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "dis_crc_check", 0x00000030, 8, 8, CSR_RW, 0x00000000 },
	{ "vc_num_bypass", 0x00000030, 31, 16, CSR_RW, 0x00000000 },
	{ "CHK", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi0
	{ "short_pkt_en", 0x00000034, 7, 0, CSR_RW, 0x00000000 },
	{ "user_pkt_en", 0x00000034, 15, 8, CSR_RW, 0x00000000 },
	{ "MIPI0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD mipi1
	{ "out0_vc_vld", 0x00000038, 15, 0, CSR_RW, 0x00000001 },
	{ "out1_vc_vld", 0x00000038, 31, 16, CSR_RW, 0x00000002 },
	{ "MIPI1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD err
	{ "ec_en", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "ERR", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD size
	{ "width", 0x00000040, 15, 0, CSR_RW, 0x00000000 },
	{ "height", 0x00000040, 31, 16, CSR_RW, 0x00000000 },
	{ "SIZE", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD out
	{ "frame_start_sel", 0x00000044, 1, 0, CSR_RW, 0x00000000 },
	{ "frame_done_sel", 0x00000044, 9, 8, CSR_RW, 0x00000000 },
	{ "frame_end_sel", 0x00000044, 17, 16, CSR_RW, 0x00000000 },
	{ "OUT", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcmp
	{ "dcmp_en", 0x00000048, 0, 0, CSR_RW, 0x00000000 },
	{ "dcmp_mode", 0x00000048, 8, 8, CSR_RW, 0x00000000 },
	{ "DCMP", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD sony
	{ "dol_sydinfo_en", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "SONY", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD fcnt
	{ "frame_count_0", 0x00000050, 15, 0, CSR_RO, 0x00000000 },
	{ "frame_count_1", 0x00000050, 31, 16, CSR_RO, 0x00000000 },
	{ "FCNT", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD gspkt
	{ "gene_short_pkt", 0x00000054, 23, 0, CSR_RO, 0x00000000 },
	{ "mipi_sw_status", 0x00000054, 29, 28, CSR_RO, 0x00000000 },
	{ "GSPKT", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg0
	{ "debug_sel", 0x00000058, 3, 0, CSR_RW, 0x00000000 },
	{ "DBG0", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg1
	{ "debug_mon", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG1", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD cstm0
	{ "custom_sync_code_size", 0x00000060, 3, 0, CSR_RW, 0x00000000 },
	{ "custom_byte_format", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "custom_dis_eof_eol", 0x00000060, 16, 16, CSR_RW, 0x00000000 },
	{ "custom_dis_sof_eof", 0x00000060, 24, 24, CSR_RW, 0x00000000 },
	{ "CSTM0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm1
	{ "custom_idl", 0x00000064, 15, 0, CSR_RW, 0x00000000 },
	{ "enable_custom_idl", 0x00000064, 16, 16, CSR_RW, 0x00000000 },
	{ "CSTM1", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm2
	{ "custom_sync_code_0", 0x00000068, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sync_code_1", 0x00000068, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM2", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm3
	{ "custom_sync_code_2", 0x0000006C, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sync_code_3", 0x0000006C, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM3", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm4
	{ "custom_sync_code_4", 0x00000070, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sync_code_5", 0x00000070, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM4", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm5
	{ "custom_sync_code_6", 0x00000074, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sync_code_7", 0x00000074, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM5", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm6
	{ "custom_sof_0", 0x00000078, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sol_0", 0x00000078, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM6", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm7
	{ "custom_eof_0", 0x0000007C, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_eol_0", 0x0000007C, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM7", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm8
	{ "custom_sof_1", 0x00000080, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sol_1", 0x00000080, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM8", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm9
	{ "custom_eof_1", 0x00000084, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_eol_1", 0x00000084, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM9", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm10
	{ "custom_sof_2", 0x00000088, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sol_2", 0x00000088, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM10", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm11
	{ "custom_eof_2", 0x0000008C, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_eol_2", 0x0000008C, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM11", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm12
	{ "custom_sof_3", 0x00000090, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_sol_3", 0x00000090, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM12", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD cstm13
	{ "custom_eof_3", 0x00000094, 15, 0, CSR_RW, 0x00000000 },
	{ "custom_eol_3", 0x00000094, 31, 16, CSR_RW, 0x00000000 },
	{ "CSTM13", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD sta0
	{ "sync_bytes", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	{ "STA0", 0x00000098, 31, 0, CSR_RO, 0x00000000 },
	// WORD stah0
	{ "hispi_status", 0x0000009C, 7, 0, CSR_RO, 0x00000000 },
	{ "STAH0", 0x0000009C, 31, 0, CSR_RO, 0x00000000 },
	// WORD stah1
	{ "hispi_active_count", 0x000000A0, 15, 0, CSR_RO, 0x00000000 },
	{ "hispi_blank_count", 0x000000A0, 31, 16, CSR_RO, 0x00000000 },
	{ "STAH1", 0x000000A0, 31, 0, CSR_RO, 0x00000000 },
	// WORD stah2
	{ "hispi_word_count", 0x000000A4, 15, 0, CSR_RO, 0x00000000 },
	{ "STAH2", 0x000000A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD stas0
	{ "sony_status", 0x000000A8, 15, 0, CSR_RO, 0x00000000 },
	{ "STAS0", 0x000000A8, 31, 0, CSR_RO, 0x00000000 },
	// WORD stas1
	{ "sony_active_count", 0x000000AC, 15, 0, CSR_RO, 0x00000000 },
	{ "sony_blank_count", 0x000000AC, 31, 16, CSR_RO, 0x00000000 },
	{ "STAS1", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD stas2
	{ "sony_word_count", 0x000000B0, 15, 0, CSR_RO, 0x00000000 },
	{ "STAS2", 0x000000B0, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam0
	{ "mipi_hs_ln0_sta", 0x000000B4, 7, 0, CSR_RO, 0x00000000 },
	{ "mipi_hs_ln1_sta", 0x000000B4, 15, 8, CSR_RO, 0x00000000 },
	{ "mipi_hs_ln2_sta", 0x000000B4, 23, 16, CSR_RO, 0x00000000 },
	{ "mipi_hs_ln3_sta", 0x000000B4, 31, 24, CSR_RO, 0x00000000 },
	{ "STAM0", 0x000000B4, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam1
	{ "mipi_active_count", 0x000000B8, 15, 0, CSR_RO, 0x00000000 },
	{ "mipi_active_count_1", 0x000000B8, 31, 16, CSR_RO, 0x00000000 },
	{ "STAM1", 0x000000B8, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam2
	{ "mipi_blank_count", 0x000000BC, 15, 0, CSR_RO, 0x00000000 },
	{ "mipi_blank_count_1", 0x000000BC, 31, 16, CSR_RO, 0x00000000 },
	{ "STAM2", 0x000000BC, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam3
	{ "mipi_word_count", 0x000000C0, 15, 0, CSR_RO, 0x00000000 },
	{ "STAM3", 0x000000C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam4
	{ "mipi_frame_number", 0x000000C4, 15, 0, CSR_RO, 0x00000000 },
	{ "mipi_frame_number_1", 0x000000C4, 31, 16, CSR_RO, 0x00000000 },
	{ "STAM4", 0x000000C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam5
	{ "mipi_crc_word", 0x000000C8, 15, 0, CSR_RO, 0x00000000 },
	{ "mipi_crc_calc", 0x000000C8, 31, 16, CSR_RO, 0x00000000 },
	{ "STAM5", 0x000000C8, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam6
	{ "pkt_hdr_rec_0", 0x000000CC, 31, 0, CSR_RO, 0x00000000 },
	{ "STAM6", 0x000000CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam7
	{ "pkt_hdr_rec_1", 0x000000D0, 31, 0, CSR_RO, 0x00000000 },
	{ "STAM7", 0x000000D0, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam8
	{ "pkt_hdr_rec_2", 0x000000D4, 31, 0, CSR_RO, 0x00000000 },
	{ "STAM8", 0x000000D4, 31, 0, CSR_RO, 0x00000000 },
	// WORD stam9
	{ "pkt_hdr_rec_3", 0x000000D8, 31, 0, CSR_RO, 0x00000000 },
	{ "STAM9", 0x000000D8, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DEC_H_
