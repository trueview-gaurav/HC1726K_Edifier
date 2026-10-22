/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SPIRX_DEC_H_
#define CSR_TABLE_SPIRX_DEC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_spirx_dec[] = {
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
	{ "status_spi_short_pkt", 0x00000008, 3, 3, CSR_RO, 0x00000000 },
	{ "status_spi_pkt_err", 0x00000008, 4, 4, CSR_RO, 0x00000000 },
	{ "status_spi_line_err", 0x00000008, 5, 5, CSR_RO, 0x00000000 },
	{ "status_himax_crc_err", 0x00000008, 6, 6, CSR_RO, 0x00000000 },
	{ "status_frame_size_err", 0x00000008, 7, 7, CSR_RO, 0x00000000 },
	{ "IRQSTA", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD irqack
	{ "irq_clear_frame_done", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_end", 0x0000000C, 1, 1, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_start", 0x0000000C, 2, 2, CSR_W1P, 0x00000000 },
	{ "irq_clear_spi_short_pkt", 0x0000000C, 3, 3, CSR_W1P, 0x00000000 },
	{ "irq_clear_spi_pkt_err", 0x0000000C, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_spi_line_err", 0x0000000C, 5, 5, CSR_W1P, 0x00000000 },
	{ "irq_clear_himax_crc_err", 0x0000000C, 6, 6, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_size_err", 0x0000000C, 7, 7, CSR_W1P, 0x00000000 },
	{ "IRQACK", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irqmsk
	{ "irq_mask_frame_done", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_end", 0x00000010, 1, 1, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_start", 0x00000010, 2, 2, CSR_RW, 0x00000000 },
	{ "irq_mask_spi_short_pkt", 0x00000010, 3, 3, CSR_RW, 0x00000000 },
	{ "irq_mask_spi_pkt_err", 0x00000010, 4, 4, CSR_RW, 0x00000000 },
	{ "irq_mask_spi_line_err", 0x00000010, 5, 5, CSR_RW, 0x00000000 },
	{ "irq_mask_himax_crc_err", 0x00000010, 6, 6, CSR_RW, 0x00000000 },
	{ "irq_mask_frame_size_err", 0x00000010, 7, 7, CSR_RW, 0x00000000 },
	{ "IRQMSK", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD cfg
	{ "des_bit_size", 0x00000014, 1, 0, CSR_RW, 0x00000000 },
	{ "wire_inverse", 0x00000014, 2, 2, CSR_RW, 0x00000000 },
	{ "sensor_type", 0x00000014, 5, 4, CSR_RW, 0x00000000 },
	{ "ddr_mode_en", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "sclk_pol_sel", 0x00000014, 9, 9, CSR_RW, 0x00000000 },
	{ "sclk_latch_en", 0x00000014, 10, 10, CSR_RW, 0x00000001 },
	{ "rise_sclk_middle", 0x00000014, 11, 11, CSR_RW, 0x00000000 },
	{ "msb_first", 0x00000014, 13, 13, CSR_RW, 0x00000000 },
	{ "yuv422_mode", 0x00000014, 14, 14, CSR_RW, 0x00000000 },
	{ "sclk_gating", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "himax_frame_code_en", 0x00000014, 17, 17, CSR_RW, 0x00000000 },
	{ "himax_crc_check", 0x00000014, 18, 18, CSR_RW, 0x00000000 },
	{ "CFG", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD delay_cfg
	{ "sd0_data_delay_sel", 0x00000018, 2, 0, CSR_RW, 0x00000000 },
	{ "sd1_data_delay_sel", 0x00000018, 6, 4, CSR_RW, 0x00000000 },
	{ "sd2_data_delay_sel", 0x00000018, 10, 8, CSR_RW, 0x00000000 },
	{ "sd3_data_delay_sel", 0x00000018, 14, 12, CSR_RW, 0x00000000 },
	{ "sclk_data_delay_sel", 0x00000018, 18, 16, CSR_RW, 0x00000000 },
	{ "DELAY_CFG", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD sync_code
	{ "custom_sync_code0", 0x0000001C, 7, 0, CSR_RW, 0x000000FF },
	{ "custom_sync_code1", 0x0000001C, 15, 8, CSR_RW, 0x00000000 },
	{ "custom_sync_code2", 0x0000001C, 23, 16, CSR_RW, 0x00000000 },
	{ "SYNC_CODE", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sync_id0
	{ "line_end_id", 0x00000020, 7, 0, CSR_RW, 0x0000009D },
	{ "line_start_id", 0x00000020, 15, 8, CSR_RW, 0x00000080 },
	{ "frame_end_id", 0x00000020, 23, 16, CSR_RW, 0x000000B6 },
	{ "frame_start_id", 0x00000020, 31, 24, CSR_RW, 0x000000AB },
	{ "SYNC_ID0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD sync_id1
	{ "line_data_id", 0x00000024, 7, 0, CSR_RW, 0x00000040 },
	{ "SYNC_ID1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD wth
	{ "word_num", 0x00000028, 15, 0, CSR_RW, 0x00000000 },
	{ "WTH", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD high
	{ "line_num", 0x0000002C, 15, 0, CSR_RW, 0x00000000 },
	{ "HIGH", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD err
	{ "ec_en", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "ERR", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD size
	{ "width", 0x00000034, 15, 0, CSR_RW, 0x00000000 },
	{ "height", 0x00000034, 31, 16, CSR_RW, 0x00000000 },
	{ "SIZE", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD fcnt
	{ "frame_count", 0x00000038, 15, 0, CSR_RO, 0x00000000 },
	{ "FCNT", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD stas0
	{ "spi_sensor_dec_sta", 0x0000003C, 6, 0, CSR_RO, 0x00000000 },
	{ "STAS0", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD stas1
	{ "spi_sensor_active_count", 0x00000040, 15, 0, CSR_RO, 0x00000000 },
	{ "STAS1", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD stas2
	{ "spi_sensor_word_count", 0x00000044, 15, 0, CSR_RO, 0x00000000 },
	{ "STAS2", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD himax_size
	{ "himax_hsize", 0x00000048, 9, 0, CSR_RO, 0x00000000 },
	{ "himax_vsize", 0x00000048, 24, 16, CSR_RO, 0x00000000 },
	{ "HIMAX_SIZE", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD himax_length
	{ "himax_line_length", 0x0000004C, 15, 0, CSR_RO, 0x00000000 },
	{ "himax_frame_length", 0x0000004C, 31, 16, CSR_RO, 0x00000000 },
	{ "HIMAX_LENGTH", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD himax_gain
	{ "himax_ana_gain", 0x00000050, 7, 0, CSR_RO, 0x00000000 },
	{ "himax_dig_gain", 0x00000050, 26, 16, CSR_RO, 0x00000000 },
	{ "HIMAX_GAIN", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD himax_frame
	{ "himax_frame_count", 0x00000054, 15, 0, CSR_RO, 0x00000000 },
	{ "himax_frame_status", 0x00000054, 31, 16, CSR_RO, 0x00000000 },
	{ "HIMAX_FRAME", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD himax_intg
	{ "himax_intg_time", 0x00000058, 15, 0, CSR_RO, 0x00000000 },
	{ "himax_int_src", 0x00000058, 20, 16, CSR_RO, 0x00000000 },
	{ "HIMAX_INTG", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD himax_crc
	{ "himax_crc1", 0x0000005C, 7, 0, CSR_RO, 0x00000000 },
	{ "himax_crc2", 0x0000005C, 15, 8, CSR_RO, 0x00000000 },
	{ "himax_crc_cal", 0x0000005C, 31, 16, CSR_RO, 0x00000000 },
	{ "HIMAX_CRC", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg0
	{ "debug_sel", 0x00000060, 2, 0, CSR_RW, 0x00000000 },
	{ "DBG0", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg1
	{ "debug_mon", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG1", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SPIRX_DEC_H_
