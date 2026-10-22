/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_VP_H_
#define CSR_TABLE_VP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_vp[] = {
	// WORD word_debug_mon_sel
	{ "debug_mon_sel", 0x00000000, 4, 0, CSR_RW, 0x00000000 },
	{ "WORD_DEBUG_MON_SEL", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD mem_lp_ctrl
	{ "sd", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "MEM_LP_CTRL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD buf_update
	{ "double_buf_update", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "BUF_UPDATE", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD dhz_mux
	{ "dhz_mux_sel_buf", 0x0000000C, 1, 0, CSR_RW, 0x00000000 },
	{ "DHZ_MUX", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp_mux
	{ "mcvp_mux_sel_buf", 0x00000010, 1, 0, CSR_RW, 0x00000000 },
	{ "MCVP_MUX", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD unpacker_mux
	{ "unpacker_mux_sel_buf", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "UNPACKER_MUX", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD vppup0_mux
	{ "vppup0_mux_sel_buf", 0x00000018, 1, 0, CSR_RW, 0x00000000 },
	{ "VPPUP0_MUX", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw0_mux
	{ "vpw0_mux_sel_buf", 0x0000001C, 1, 0, CSR_RW, 0x00000000 },
	{ "VPW0_MUX", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw1_mux
	{ "vpw1_mux_sel_buf", 0x00000020, 2, 0, CSR_RW, 0x00000000 },
	{ "VPW1_MUX", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD vp0_bc
	{ "vp0_bc_enable_buf", 0x00000024, 1, 0, CSR_RW, 0x00000000 },
	{ "VP0_BC", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD vp1_bc
	{ "vp1_bc_enable_buf", 0x00000028, 4, 0, CSR_RW, 0x00000000 },
	{ "VP1_BC", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD vp2_bc
	{ "vp2_bc_enable_buf", 0x0000002C, 4, 0, CSR_RW, 0x00000000 },
	{ "VP2_BC", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dhz_bc
	{ "dhz_bc_enable_buf", 0x00000030, 3, 0, CSR_RW, 0x00000000 },
	{ "DHZ_BC", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD b2r_bc
	{ "b2r_bc_enable_buf", 0x00000034, 2, 0, CSR_RW, 0x00000000 },
	{ "B2R_BC", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD dhz_mux_nsel
	{ "dhz_mux_ack_not_sel", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "DHZ_MUX_NSEL", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD mcvp_mux_nsel
	{ "mcvp_mux_ack_not_sel", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "MCVP_MUX_NSEL", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD unpacker_mux_nsel
	{ "unpacker_mux_ack_not_sel", 0x00000040, 0, 0, CSR_RW, 0x00000000 },
	{ "UNPACKER_MUX_NSEL", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD vppup0_mux_nsel
	{ "vppup0_mux_ack_not_sel", 0x00000044, 0, 0, CSR_RW, 0x00000000 },
	{ "VPPUP0_MUX_NSEL", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw0_mux_nsel
	{ "vpw0_mux_ack_not_sel", 0x00000048, 0, 0, CSR_RW, 0x00000000 },
	{ "VPW0_MUX_NSEL", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD vpw1_mux_nsel
	{ "vpw1_mux_ack_not_sel", 0x0000004C, 0, 0, CSR_RW, 0x00000000 },
	{ "VPW1_MUX_NSEL", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD vp0_bc_nsel
	{ "vp0_bc_ack_not_sel", 0x00000050, 0, 0, CSR_RW, 0x00000000 },
	{ "VP0_BC_NSEL", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD vp1_bc_nsel
	{ "vp1_bc_ack_not_sel", 0x00000054, 0, 0, CSR_RW, 0x00000000 },
	{ "VP1_BC_NSEL", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD vp2_bc_nsel
	{ "vp2_bc_ack_not_sel", 0x00000058, 0, 0, CSR_RW, 0x00000000 },
	{ "VP2_BC_NSEL", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD dhz_bc_nsel
	{ "dhz_bc_ack_not_sel", 0x0000005C, 0, 0, CSR_RW, 0x00000000 },
	{ "DHZ_BC_NSEL", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD b2r_bc_nsel
	{ "b2r_bc_ack_not_sel", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "B2R_BC_NSEL", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_VP_H_
