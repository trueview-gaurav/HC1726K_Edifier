/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SENIF_CTRL_H_
#define CSR_TABLE_SENIF_CTRL_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_senif_ctrl[] = {
	// WORD mux0
	{ "mux0_sel", 0x00000000, 1, 0, CSR_RW, 0x00000000 },
	{ "MUX0", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD mux1
	{ "mux1_sel", 0x00000004, 1, 0, CSR_RW, 0x00000000 },
	{ "MUX1", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD lbuf
	{ "lbuf_share", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "LBUF", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD ssctrl
	{ "slave_start", 0x00000010, 0, 0, CSR_W1P, 0x00000000 },
	{ "slave_stop", 0x00000010, 16, 16, CSR_W1P, 0x00000000 },
	{ "SSCTRL", 0x00000010, 31, 0, CSR_W1P, 0x00000000 },
	// WORD ssen
	{ "slave_mode", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "SSEN", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD sscfg
	{ "slave_hpolar", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "slave_vpolar", 0x00000018, 8, 8, CSR_RW, 0x00000000 },
	{ "SSCFG", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD sssta
	{ "slave_run", 0x0000001C, 0, 0, CSR_RO, 0x00000000 },
	{ "slave_sta", 0x0000001C, 23, 16, CSR_RO, 0x00000000 },
	{ "SSSTA", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD ssh0
	{ "slave_hactive", 0x00000020, 15, 0, CSR_RW, 0x00000000 },
	{ "SSH0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD ssh1
	{ "slave_hbp", 0x00000024, 15, 0, CSR_RW, 0x00000000 },
	{ "SSH1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD ssh2
	{ "slave_hfp", 0x00000028, 15, 0, CSR_RW, 0x00000000 },
	{ "SSH2", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD ssv0
	{ "slave_vactive", 0x00000030, 15, 0, CSR_RW, 0x00000000 },
	{ "SSV0", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD ssv1
	{ "slave_vbp", 0x00000034, 15, 0, CSR_RW, 0x00000000 },
	{ "SSV1", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD ssv2
	{ "slave_vfp", 0x00000038, 15, 0, CSR_RW, 0x00000000 },
	{ "SSV2", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg
	{ "debug_sel", 0x00000040, 3, 0, CSR_RW, 0x00000000 },
	{ "DBG", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD data_shift
	{ "slb0_data_shift", 0x0000008C, 2, 0, CSR_RW, 0x00000000 },
	{ "slb1_data_shift", 0x0000008C, 10, 8, CSR_RW, 0x00000000 },
	{ "DATA_SHIFT", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dvp_ctrl
	{ "lv_rst_dvp", 0x00000090, 0, 0, CSR_RW, 0x00000000 },
	{ "dvp_data_sel", 0x00000090, 8, 8, CSR_RW, 0x00000000 },
	{ "DVP_CTRL", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD db_update
	{ "double_buf_update", 0x00000094, 0, 0, CSR_W1P, 0x00000000 },
	{ "DB_UPDATE", 0x00000094, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mem_wrapper
	{ "sd", 0x00000098, 8, 8, CSR_RW, 0x00000000 },
	{ "slp", 0x00000098, 16, 16, CSR_RW, 0x00000000 },
	{ "MEM_WRAPPER", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD resv
	{ "reserved", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	{ "RESV", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SENIF_CTRL_H_
