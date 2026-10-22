/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_I2S_H_
#define CSR_TABLE_I2S_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_i2s[] = {
	// WORD switch
	{ "start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "stop", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "SWITCH", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD interclk
	{ "sd_format", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "master_mode", 0x00000004, 8, 8, CSR_RW, 0x00000001 },
	{ "use_sck_inter", 0x00000004, 16, 16, CSR_RW, 0x00000000 },
	{ "use_ws_inter", 0x00000004, 24, 24, CSR_RW, 0x00000000 },
	{ "INTERCLK", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD out_en
	{ "output_sck_inter", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "output_ws_inter", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "OUT_EN", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD cycle_def
	{ "master_sck_0_cycle", 0x0000000C, 7, 0, CSR_RW, 0x00000005 },
	{ "master_sck_1_cycle", 0x0000000C, 23, 16, CSR_RW, 0x00000005 },
	{ "CYCLE_DEF", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cycle_cnt
	{ "master_ws_len", 0x00000010, 8, 0, CSR_RW, 0x00000096 },
	{ "master_sd_len", 0x00000010, 17, 9, CSR_RW, 0x00000096 },
	{ "tx_data_len", 0x00000010, 23, 18, CSR_RW, 0x00000020 },
	{ "CYCLE_CNT", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD deg
	{ "sck_deglitch_en", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "ws_deglitch_en", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "sd_deglitch_en", 0x00000014, 16, 16, CSR_RW, 0x00000000 },
	{ "DEG", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD deg_by
	{ "sck_deglitch_bypass", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "ws_deglitch_bypass", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "sd_deglitch_bypass", 0x00000018, 16, 16, CSR_RW, 0x00000001 },
	{ "DEG_BY", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD deg_th
	{ "sck_deglitch_th", 0x0000001C, 5, 0, CSR_RW, 0x00000000 },
	{ "ws_deglitch_th", 0x0000001C, 13, 8, CSR_RW, 0x00000000 },
	{ "sd_deglitch_th", 0x0000001C, 21, 16, CSR_RW, 0x00000000 },
	{ "DEG_TH", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD debug
	{ "debug_mon_sel", 0x00000020, 0, 0, CSR_RW, 0x00000000 },
	{ "mute", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "DEBUG", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resv
	{ "reserved", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	{ "RESV", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_I2S_H_
