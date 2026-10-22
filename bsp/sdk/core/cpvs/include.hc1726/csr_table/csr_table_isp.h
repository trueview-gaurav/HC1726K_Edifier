/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ISP_H_
#define CSR_TABLE_ISP_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_isp[] = {
	// WORD prd_mode
	{ "prd1_mode", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "PRD_MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg_mon_sel
	{ "debug_mon_sel", 0x00000004, 5, 0, CSR_RW, 0x00000000 },
	{ "DBG_MON_SEL", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD mem_lp_ctrl
	{ "sd", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "MEM_LP_CTRL", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD buf_update
	{ "double_buf_update", 0x0000000C, 0, 0, CSR_W1P, 0x00000000 },
	{ "BUF_UPDATE", 0x0000000C, 31, 0, CSR_W1P, 0x00000000 },
	// WORD bld0_mux_y
	{ "bld0_mux_y_sel_buf", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_MUX_Y", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_mux_c
	{ "bld0_mux_c_sel_buf", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_MUX_C", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld1_mux_y
	{ "bld1_mux_y_sel_buf", 0x00000018, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD1_MUX_Y", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld1_mux_c
	{ "bld1_mux_c_sel_buf", 0x0000001C, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD1_MUX_C", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr1_mux
	{ "hdr1_mux_sel_buf", 0x00000020, 1, 0, CSR_RW, 0x00000000 },
	{ "HDR1_MUX", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_mux
	{ "rgbp_mux_sel_buf", 0x00000024, 1, 0, CSR_RW, 0x00000000 },
	{ "RGBP_MUX", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_mux_y
	{ "cus_mux_y_sel_buf", 0x00000028, 1, 0, CSR_RW, 0x00000000 },
	{ "CUS_MUX_Y", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_mux_c
	{ "cus_mux_c_sel_buf", 0x0000002C, 1, 0, CSR_RW, 0x00000000 },
	{ "CUS_MUX_C", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_mux_y
	{ "cds_mux_y_sel_buf", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_MUX_Y", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_mux_c
	{ "cds_mux_c_sel_buf", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_MUX_C", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_mux_y
	{ "nr2d_mux_y_sel_buf", 0x00000038, 0, 0, CSR_RW, 0x00000000 },
	{ "NR2D_MUX_Y", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_mux_c
	{ "nr2d_mux_c_sel_buf", 0x0000003C, 0, 0, CSR_RW, 0x00000000 },
	{ "NR2D_MUX_C", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_mux_y
	{ "sc_mux_y_sel_buf", 0x00000040, 2, 0, CSR_RW, 0x00000000 },
	{ "SC_MUX_Y", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_mux_c
	{ "sc_mux_c_sel_buf", 0x00000044, 2, 0, CSR_RW, 0x00000000 },
	{ "SC_MUX_C", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo0_mux_y
	{ "fifo0_mux_y_sel_buf", 0x00000048, 2, 0, CSR_RW, 0x00000000 },
	{ "FIFO0_MUX_Y", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo0_mux_c
	{ "fifo0_mux_c_sel_buf", 0x0000004C, 2, 0, CSR_RW, 0x00000000 },
	{ "FIFO0_MUX_C", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo1_mux_y
	{ "fifo1_mux_y_sel_buf", 0x00000050, 2, 0, CSR_RW, 0x00000000 },
	{ "FIFO1_MUX_Y", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo1_mux_c
	{ "fifo1_mux_c_sel_buf", 0x00000054, 2, 0, CSR_RW, 0x00000000 },
	{ "FIFO1_MUX_C", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo2_mux_y
	{ "fifo2_mux_y_sel_buf", 0x00000058, 2, 0, CSR_RW, 0x00000000 },
	{ "FIFO2_MUX_Y", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo2_mux_c
	{ "fifo2_mux_c_sel_buf", 0x0000005C, 2, 0, CSR_RW, 0x00000000 },
	{ "FIFO2_MUX_C", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_bc_y
	{ "ispin0_bc_y_enable_buf", 0x00000060, 9, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_BC_Y", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_bc_c
	{ "ispin0_bc_c_enable_buf", 0x00000064, 6, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_BC_C", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin1_bc_y
	{ "ispin1_bc_y_enable_buf", 0x00000068, 8, 0, CSR_RW, 0x00000000 },
	{ "ISPIN1_BC_Y", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin1_bc_c
	{ "ispin1_bc_c_enable_buf", 0x0000006C, 6, 0, CSR_RW, 0x00000000 },
	{ "ISPIN1_BC_C", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_bc_y
	{ "bld0_bc_y_enable_buf", 0x00000070, 5, 0, CSR_RW, 0x00000000 },
	{ "BLD0_BC_Y", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_bc_c
	{ "bld0_bc_c_enable_buf", 0x00000074, 3, 0, CSR_RW, 0x00000000 },
	{ "BLD0_BC_C", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr0_bc_y
	{ "hdr0_bc_y_enable_buf", 0x00000078, 3, 0, CSR_RW, 0x00000000 },
	{ "HDR0_BC_Y", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr0_bc_c
	{ "hdr0_bc_c_enable_buf", 0x0000007C, 2, 0, CSR_RW, 0x00000000 },
	{ "HDR0_BC_C", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_bc_y
	{ "rgbp_bc_y_enable_buf", 0x00000080, 2, 0, CSR_RW, 0x00000000 },
	{ "RGBP_BC_Y", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_bc_c
	{ "rgbp_bc_c_enable_buf", 0x00000084, 2, 0, CSR_RW, 0x00000000 },
	{ "RGBP_BC_C", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_bc_y
	{ "cus_bc_y_enable_buf", 0x00000088, 1, 0, CSR_RW, 0x00000000 },
	{ "CUS_BC_Y", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_bc_c
	{ "cus_bc_c_enable_buf", 0x0000008C, 1, 0, CSR_RW, 0x00000000 },
	{ "CUS_BC_C", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_bc_y
	{ "cds_bc_y_enable_buf", 0x00000090, 2, 0, CSR_RW, 0x00000000 },
	{ "CDS_BC_Y", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_bc_c
	{ "cds_bc_c_enable_buf", 0x00000094, 2, 0, CSR_RW, 0x00000000 },
	{ "CDS_BC_C", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_bc_y
	{ "shp_bc_y_enable_buf", 0x00000098, 1, 0, CSR_RW, 0x00000000 },
	{ "SHP_BC_Y", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_bc_c
	{ "shp_bc_c_enable_buf", 0x0000009C, 1, 0, CSR_RW, 0x00000000 },
	{ "SHP_BC_C", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_bc_y
	{ "sc_bc_y_enable_buf", 0x000000A0, 2, 0, CSR_RW, 0x00000000 },
	{ "SC_BC_Y", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_bc_c
	{ "sc_bc_c_enable_buf", 0x000000A4, 2, 0, CSR_RW, 0x00000000 },
	{ "SC_BC_C", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_yc_bc
	{ "ispin0_yc_bc_enable_buf", 0x000000A8, 1, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_YC_BC", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin1_yc_bc
	{ "ispin1_yc_bc_enable_buf", 0x000000AC, 1, 0, CSR_RW, 0x00000000 },
	{ "ISPIN1_YC_BC", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_yc_bc
	{ "bld0_yc_bc_enable_buf", 0x000000B0, 1, 0, CSR_RW, 0x00000000 },
	{ "BLD0_YC_BC", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr0_yc_bc
	{ "hdr0_yc_bc_enable_buf", 0x000000B4, 1, 0, CSR_RW, 0x00000000 },
	{ "HDR0_YC_BC", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_yc_bc
	{ "rgbp_yc_bc_enable_buf", 0x000000B8, 1, 0, CSR_RW, 0x00000000 },
	{ "RGBP_YC_BC", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_yc_bc
	{ "cus_yc_bc_enable_buf", 0x000000BC, 1, 0, CSR_RW, 0x00000000 },
	{ "CUS_YC_BC", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_yc_bc
	{ "cds_yc_bc_enable_buf", 0x000000C0, 1, 0, CSR_RW, 0x00000000 },
	{ "CDS_YC_BC", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_yc_bc
	{ "nr2d_yc_bc_enable_buf", 0x000000C4, 1, 0, CSR_RW, 0x00000000 },
	{ "NR2D_YC_BC", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ccm_yc_bc
	{ "ccm_yc_bc_enable_buf", 0x000000C8, 1, 0, CSR_RW, 0x00000000 },
	{ "CCM_YC_BC", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pca_yc_bc
	{ "pca_yc_bc_enable_buf", 0x000000CC, 1, 0, CSR_RW, 0x00000000 },
	{ "PCA_YC_BC", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_yc_bc
	{ "shp_yc_bc_enable_buf", 0x000000D0, 1, 0, CSR_RW, 0x00000000 },
	{ "SHP_YC_BC", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_yc_bc
	{ "sc_yc_bc_enable_buf", 0x000000D4, 1, 0, CSR_RW, 0x00000000 },
	{ "SC_YC_BC", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_mux_y_nsel
	{ "bld0_mux_y_ack_not_sel", 0x000000D8, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_MUX_Y_NSEL", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_mux_c_nsel
	{ "bld0_mux_c_ack_not_sel", 0x000000DC, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_MUX_C_NSEL", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld1_mux_y_nsel
	{ "bld1_mux_y_ack_not_sel", 0x000000E0, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD1_MUX_Y_NSEL", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld1_mux_c_nsel
	{ "bld1_mux_c_ack_not_sel", 0x000000E4, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD1_MUX_C_NSEL", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr1_mux_nsel
	{ "hdr1_mux_ack_not_sel", 0x000000E8, 0, 0, CSR_RW, 0x00000000 },
	{ "HDR1_MUX_NSEL", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_mux_nsel
	{ "rgbp_mux_ack_not_sel", 0x000000EC, 0, 0, CSR_RW, 0x00000000 },
	{ "RGBP_MUX_NSEL", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_mux_y_nsel
	{ "cus_mux_y_ack_not_sel", 0x000000F0, 0, 0, CSR_RW, 0x00000000 },
	{ "CUS_MUX_Y_NSEL", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_mux_c_nsel
	{ "cus_mux_c_ack_not_sel", 0x000000F4, 0, 0, CSR_RW, 0x00000000 },
	{ "CUS_MUX_C_NSEL", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_mux_y_nsel
	{ "cds_mux_y_ack_not_sel", 0x000000F8, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_MUX_Y_NSEL", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_mux_c_nsel
	{ "cds_mux_c_ack_not_sel", 0x000000FC, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_MUX_C_NSEL", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_mux_y_nsel
	{ "nr2d_mux_y_ack_not_sel", 0x00000100, 0, 0, CSR_RW, 0x00000000 },
	{ "NR2D_MUX_Y_NSEL", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_mux_c_nsel
	{ "nr2d_mux_c_ack_not_sel", 0x00000104, 0, 0, CSR_RW, 0x00000000 },
	{ "NR2D_MUX_C_NSEL", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_mux_y_nsel
	{ "sc_mux_y_ack_not_sel", 0x00000108, 0, 0, CSR_RW, 0x00000000 },
	{ "SC_MUX_Y_NSEL", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_mux_c_nsel
	{ "sc_mux_c_ack_not_sel", 0x0000010C, 0, 0, CSR_RW, 0x00000000 },
	{ "SC_MUX_C_NSEL", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo0_mux_y_nsel
	{ "fifo0_mux_y_ack_not_sel", 0x00000110, 0, 0, CSR_RW, 0x00000000 },
	{ "FIFO0_MUX_Y_NSEL", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo0_mux_c_nsel
	{ "fifo0_mux_c_ack_not_sel", 0x00000114, 0, 0, CSR_RW, 0x00000000 },
	{ "FIFO0_MUX_C_NSEL", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo1_mux_y_nsel
	{ "fifo1_mux_y_ack_not_sel", 0x00000118, 0, 0, CSR_RW, 0x00000000 },
	{ "FIFO1_MUX_Y_NSEL", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo1_mux_c_nsel
	{ "fifo1_mux_c_ack_not_sel", 0x0000011C, 0, 0, CSR_RW, 0x00000000 },
	{ "FIFO1_MUX_C_NSEL", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo2_mux_y_nsel
	{ "fifo2_mux_y_ack_not_sel", 0x00000120, 0, 0, CSR_RW, 0x00000000 },
	{ "FIFO2_MUX_Y_NSEL", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD fifo2_mux_c_nsel
	{ "fifo2_mux_c_ack_not_sel", 0x00000124, 0, 0, CSR_RW, 0x00000000 },
	{ "FIFO2_MUX_C_NSEL", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_bc_y_nsel
	{ "ispin0_bc_y_ack_not_sel", 0x00000128, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_BC_Y_NSEL", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_bc_c_nsel
	{ "ispin0_bc_c_ack_not_sel", 0x0000012C, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_BC_C_NSEL", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin1_bc_y_nsel
	{ "ispin1_bc_y_ack_not_sel", 0x00000130, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN1_BC_Y_NSEL", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin1_bc_c_nsel
	{ "ispin1_bc_c_ack_not_sel", 0x00000134, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN1_BC_C_NSEL", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_bc_y_nsel
	{ "bld0_bc_y_ack_not_sel", 0x00000138, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_BC_Y_NSEL", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_bc_c_nsel
	{ "bld0_bc_c_ack_not_sel", 0x0000013C, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_BC_C_NSEL", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr0_bc_y_nsel
	{ "hdr0_bc_y_ack_not_sel", 0x00000140, 0, 0, CSR_RW, 0x00000000 },
	{ "HDR0_BC_Y_NSEL", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr0_bc_c_nsel
	{ "hdr0_bc_c_ack_not_sel", 0x00000144, 0, 0, CSR_RW, 0x00000000 },
	{ "HDR0_BC_C_NSEL", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_bc_y_nsel
	{ "rgbp_bc_y_ack_not_sel", 0x00000148, 0, 0, CSR_RW, 0x00000000 },
	{ "RGBP_BC_Y_NSEL", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_bc_c_nsel
	{ "rgbp_bc_c_ack_not_sel", 0x0000014C, 0, 0, CSR_RW, 0x00000000 },
	{ "RGBP_BC_C_NSEL", 0x0000014C, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_bc_y_nsel
	{ "cus_bc_y_ack_not_sel", 0x00000150, 0, 0, CSR_RW, 0x00000000 },
	{ "CUS_BC_Y_NSEL", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_bc_c_nsel
	{ "cus_bc_c_ack_not_sel", 0x00000154, 0, 0, CSR_RW, 0x00000000 },
	{ "CUS_BC_C_NSEL", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_bc_y_nsel
	{ "cds_bc_y_ack_not_sel", 0x00000158, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_BC_Y_NSEL", 0x00000158, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_bc_c_nsel
	{ "cds_bc_c_ack_not_sel", 0x0000015C, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_BC_C_NSEL", 0x0000015C, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_bc_y_nsel
	{ "shp_bc_y_ack_not_sel", 0x00000160, 0, 0, CSR_RW, 0x00000000 },
	{ "SHP_BC_Y_NSEL", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_bc_c_nsel
	{ "shp_bc_c_ack_not_sel", 0x00000164, 0, 0, CSR_RW, 0x00000000 },
	{ "SHP_BC_C_NSEL", 0x00000164, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_bc_y_nsel
	{ "sc_bc_y_ack_not_sel", 0x00000168, 0, 0, CSR_RW, 0x00000000 },
	{ "SC_BC_Y_NSEL", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_bc_c_nsel
	{ "sc_bc_c_ack_not_sel", 0x0000016C, 0, 0, CSR_RW, 0x00000000 },
	{ "SC_BC_C_NSEL", 0x0000016C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_yc_bc_nsel
	{ "ispin0_yc_bc_ack_not_sel", 0x00000170, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_YC_BC_NSEL", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin1_yc_bc_nsel
	{ "ispin1_yc_bc_ack_not_sel", 0x00000174, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN1_YC_BC_NSEL", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD bld0_yc_bc_nsel
	{ "bld0_yc_bc_ack_not_sel", 0x00000178, 0, 0, CSR_RW, 0x00000000 },
	{ "BLD0_YC_BC_NSEL", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD hdr0_yc_bc_nsel
	{ "hdr0_yc_bc_ack_not_sel", 0x0000017C, 0, 0, CSR_RW, 0x00000000 },
	{ "HDR0_YC_BC_NSEL", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rgbp_yc_bc_nsel
	{ "rgbp_yc_bc_ack_not_sel", 0x00000180, 0, 0, CSR_RW, 0x00000000 },
	{ "RGBP_YC_BC_NSEL", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD cus_yc_bc_nsel
	{ "cus_yc_bc_ack_not_sel", 0x00000184, 0, 0, CSR_RW, 0x00000000 },
	{ "CUS_YC_BC_NSEL", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD cds_yc_bc_nsel
	{ "cds_yc_bc_ack_not_sel", 0x00000188, 0, 0, CSR_RW, 0x00000000 },
	{ "CDS_YC_BC_NSEL", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD nr2d_yc_bc_nsel
	{ "nr2d_yc_bc_ack_not_sel", 0x0000018C, 0, 0, CSR_RW, 0x00000000 },
	{ "NR2D_YC_BC_NSEL", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ccm_yc_bc_nsel
	{ "ccm_yc_bc_ack_not_sel", 0x00000190, 0, 0, CSR_RW, 0x00000000 },
	{ "CCM_YC_BC_NSEL", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD pca_yc_bc_nsel
	{ "pca_yc_bc_ack_not_sel", 0x00000194, 0, 0, CSR_RW, 0x00000000 },
	{ "PCA_YC_BC_NSEL", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD shp_yc_bc_nsel
	{ "shp_yc_bc_ack_not_sel", 0x00000198, 0, 0, CSR_RW, 0x00000000 },
	{ "SHP_YC_BC_NSEL", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD sc_yc_bc_nsel
	{ "sc_yc_bc_ack_not_sel", 0x0000019C, 0, 0, CSR_RW, 0x00000000 },
	{ "SC_YC_BC_NSEL", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_mux
	{ "ispin0_mux_sel_buf", 0x000001A0, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_MUX", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr0_bc
	{ "ispr0_bc_enable_buf", 0x000001A4, 1, 0, CSR_RW, 0x00000000 },
	{ "ISPR0_BC", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispin0_mux_nsel
	{ "ispin0_mux_ack_not_sel", 0x000001A8, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPIN0_MUX_NSEL", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD ispr0_bc_nsel
	{ "ispr0_bc_ack_not_sel", 0x000001AC, 0, 0, CSR_RW, 0x00000000 },
	{ "ISPR0_BC_NSEL", 0x000001AC, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ISP_H_
