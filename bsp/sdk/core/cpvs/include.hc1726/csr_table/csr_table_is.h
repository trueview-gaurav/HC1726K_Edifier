/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_IS_H_
#define CSR_TABLE_IS_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_is[] = {
	// WORD word_frame_start
	{ "frame_start_fe0", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "frame_start_fe1", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear_sensor0
	{ "irq_clear_frame_end_auto0", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_start_late_auto0", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR_SENSOR0", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_clear_sensor1
	{ "irq_clear_frame_end_auto1", 0x00000008, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_frame_start_late_auto1", 0x00000008, 8, 8, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR_SENSOR1", 0x00000008, 31, 0, CSR_W1P, 0x00000000 },
	// WORD status_sensor0
	{ "status_frame_end_auto0", 0x0000000C, 0, 0, CSR_RO, 0x00000000 },
	{ "status_frame_start_late_auto0", 0x0000000C, 8, 8, CSR_RO, 0x00000000 },
	{ "STATUS_SENSOR0", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD status_sensor1
	{ "status_frame_end_auto1", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "status_frame_start_late_auto1", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "STATUS_SENSOR1", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_mask_sensor0
	{ "irq_mask_frame_end_auto0", 0x00000014, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_frame_start_late_auto0", 0x00000014, 8, 8, CSR_RW, 0x00000001 },
	{ "IRQ_MASK_SENSOR0", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_mask_sensor1
	{ "irq_mask_frame_end_auto1", 0x00000018, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_frame_start_late_auto1", 0x00000018, 8, 8, CSR_RW, 0x00000001 },
	{ "IRQ_MASK_SENSOR1", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD efuse_vio
	{ "fe0_efuse_resolution_violation", 0x0000001C, 0, 0, CSR_RO, 0x00000000 },
	{ "fe0_efuse_data_rate_violation", 0x0000001C, 8, 8, CSR_RO, 0x00000000 },
	{ "fe1_efuse_resolution_violation", 0x0000001C, 16, 16, CSR_RO, 0x00000000 },
	{ "fe1_efuse_data_rate_violation", 0x0000001C, 24, 24, CSR_RO, 0x00000000 },
	{ "EFUSE_VIO", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD resolution_path_0
	{ "width_0", 0x00000020, 15, 0, CSR_RW, 0x00000780 },
	{ "height_0", 0x00000020, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION_PATH_0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD resolution_path_1
	{ "width_1", 0x00000024, 15, 0, CSR_RW, 0x00000780 },
	{ "height_1", 0x00000024, 31, 16, CSR_RW, 0x00000438 },
	{ "RESOLUTION_PATH_1", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD auto_frame_start_ctrl
	{ "fe0_auto_frame_start_mode", 0x00000028, 0, 0, CSR_RW, 0x00000001 },
	{ "fe1_auto_frame_start_mode", 0x00000028, 8, 8, CSR_RW, 0x00000001 },
	{ "auto_frame_start_blanking_mode", 0x00000028, 16, 16, CSR_RW, 0x00000001 },
	{ "AUTO_FRAME_START_CTRL", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD fe0_ctrl
	{ "fe0_prd_mode", 0x0000002C, 0, 0, CSR_RW, 0x00000000 },
	{ "fe0_broadcast_enable", 0x0000002C, 9, 8, CSR_RW, 0x00000002 },
	{ "fe0_edp_mux_sel", 0x0000002C, 16, 16, CSR_RW, 0x00000000 },
	{ "fe0_ack_not_sel", 0x0000002C, 25, 24, CSR_RW, 0x00000000 },
	{ "FE0_CTRL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD fe1_ctrl
	{ "fe1_prd_mode", 0x00000030, 0, 0, CSR_RW, 0x00000000 },
	{ "fe1_broadcast_enable", 0x00000030, 9, 8, CSR_RW, 0x00000002 },
	{ "fe1_edp_mux_sel", 0x00000030, 16, 16, CSR_RW, 0x00000000 },
	{ "fe1_ack_not_sel", 0x00000030, 25, 24, CSR_RW, 0x00000000 },
	{ "FE1_CTRL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD iroute_enable_0
	{ "iroute_src_fe0_edp0_broadcast_enable", 0x00000034, 5, 0, CSR_RW, 0x00000001 },
	{ "iroute_src_fe0_edp1_broadcast_enable", 0x00000034, 13, 8, CSR_RW, 0x00000004 },
	{ "iroute_src_fe0_isr_broadcast_enable", 0x00000034, 21, 16, CSR_RW, 0x00000002 },
	{ "IROUTE_ENABLE_0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD iroute_enable_1
	{ "iroute_src_fe1_edp0_broadcast_enable", 0x00000038, 5, 0, CSR_RW, 0x00000008 },
	{ "iroute_src_fe1_edp1_broadcast_enable", 0x00000038, 13, 8, CSR_RW, 0x00000020 },
	{ "iroute_src_fe1_isr_broadcast_enable", 0x00000038, 21, 16, CSR_RW, 0x00000010 },
	{ "IROUTE_ENABLE_1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD iroute_sel_0
	{ "iroute_dst_bypass_isk0_sel", 0x0000003C, 2, 0, CSR_RW, 0x00000000 },
	{ "iroute_dst_isk0_in0_sel", 0x0000003C, 10, 8, CSR_RW, 0x00000000 },
	{ "iroute_dst_isk0_in1_sel", 0x0000003C, 18, 16, CSR_RW, 0x00000001 },
	{ "IROUTE_SEL_0", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD iroute_sel_1
	{ "iroute_dst_bypass_isk1_sel", 0x00000040, 2, 0, CSR_RW, 0x00000003 },
	{ "iroute_dst_isk1_in0_sel", 0x00000040, 10, 8, CSR_RW, 0x00000003 },
	{ "iroute_dst_isk1_in1_sel", 0x00000040, 18, 16, CSR_RW, 0x00000004 },
	{ "IROUTE_SEL_1", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD iroute_ack_not_sel
	{ "iroute_src_broadcast_ack_not_sel", 0x00000044, 5, 0, CSR_RW, 0x00000000 },
	{ "iroute_dst_mux_ack_not_sel", 0x00000044, 13, 8, CSR_RW, 0x00000000 },
	{ "IROUTE_ACK_NOT_SEL", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD iroute_cat
	{ "iroute_dst_msb_cat", 0x00000048, 5, 0, CSR_RW, 0x00000000 },
	{ "IROUTE_CAT", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_enable_0
	{ "oroute_src_bypass_isk0_broadcast_enable", 0x0000004C, 3, 0, CSR_RW, 0x00000001 },
	{ "oroute_src_isk0_crop_broadcast_enable", 0x0000004C, 11, 8, CSR_RW, 0x00000000 },
	{ "oroute_src_isk0_bsp_broadcast_enable", 0x0000004C, 19, 16, CSR_RW, 0x00000000 },
	{ "OROUTE_ENABLE_0", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_enable_1
	{ "oroute_src_isk0_fgma_broadcast_enable", 0x00000050, 3, 0, CSR_RW, 0x00000000 },
	{ "oroute_src_isk0_fsc_broadcast_enable", 0x00000050, 11, 8, CSR_RW, 0x00000002 },
	{ "oroute_src_isk0_cvs_broadcast_enable", 0x00000050, 19, 16, CSR_RW, 0x00000000 },
	{ "oroute_src_isk0_cs_broadcast_enable", 0x00000050, 27, 24, CSR_RW, 0x00000000 },
	{ "OROUTE_ENABLE_1", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_enable_2
	{ "oroute_src_bypass_isk1_broadcast_enable", 0x00000054, 3, 0, CSR_RW, 0x00000004 },
	{ "oroute_src_isk1_crop_broadcast_enable", 0x00000054, 11, 8, CSR_RW, 0x00000000 },
	{ "oroute_src_isk1_bsp_broadcast_enable", 0x00000054, 19, 16, CSR_RW, 0x00000000 },
	{ "OROUTE_ENABLE_2", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_enable_3
	{ "oroute_src_isk1_fgma_broadcast_enable", 0x00000058, 3, 0, CSR_RW, 0x00000000 },
	{ "oroute_src_isk1_fsc_broadcast_enable", 0x00000058, 11, 8, CSR_RW, 0x00000008 },
	{ "oroute_src_isk1_cvs_broadcast_enable", 0x00000058, 19, 16, CSR_RW, 0x00000000 },
	{ "oroute_src_isk1_cs_broadcast_enable", 0x00000058, 27, 24, CSR_RW, 0x00000000 },
	{ "OROUTE_ENABLE_3", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_sel
	{ "oroute_dst_isw0_sel", 0x0000005C, 3, 0, CSR_RW, 0x00000000 },
	{ "oroute_dst_isw1_sel", 0x0000005C, 11, 8, CSR_RW, 0x00000004 },
	{ "oroute_dst_isw2_sel", 0x0000005C, 19, 16, CSR_RW, 0x00000007 },
	{ "oroute_dst_isw3_sel", 0x0000005C, 27, 24, CSR_RW, 0x0000000B },
	{ "OROUTE_SEL", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_cat
	{ "oroute_dst_isw0_msb_cat", 0x00000060, 0, 0, CSR_RW, 0x00000000 },
	{ "oroute_dst_isw1_msb_cat", 0x00000060, 8, 8, CSR_RW, 0x00000000 },
	{ "oroute_dst_isw2_msb_cat", 0x00000060, 16, 16, CSR_RW, 0x00000000 },
	{ "oroute_dst_isw3_msb_cat", 0x00000060, 24, 24, CSR_RW, 0x00000000 },
	{ "OROUTE_CAT", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_ack_not_sel_0
	{ "oroute_src0_broadcast_ack_not_sel", 0x00000064, 6, 0, CSR_RW, 0x00000000 },
	{ "oroute_src1_broadcast_ack_not_sel", 0x00000064, 14, 8, CSR_RW, 0x00000000 },
	{ "OROUTE_ACK_NOT_SEL_0", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD oroute_ack_not_sel_1
	{ "oroute_dst_mux_ack_not_sel", 0x00000068, 3, 0, CSR_RW, 0x00000000 },
	{ "OROUTE_ACK_NOT_SEL_1", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD lpmd_enable
	{ "lpmd_broadcast_to_is_enable", 0x0000006C, 0, 0, CSR_RW, 0x00000001 },
	{ "lpmd_broadcast_to_lpmd_enable", 0x0000006C, 8, 8, CSR_RW, 0x00000001 },
	{ "LPMD_ENABLE", 0x0000006C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_lpmd_ack_not_sel
	{ "lpmd_ack_not_sel", 0x00000070, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_LPMD_ACK_NOT_SEL", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD shared_sram_fsc
	{ "fsc_buf_mode", 0x00000074, 0, 0, CSR_RW, 0x00000001 },
	{ "SHARED_SRAM_FSC", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD shared_sram_cfg
	{ "bsp_cvs_cs_sram_mode", 0x00000078, 0, 0, CSR_RW, 0x00000001 },
	{ "bsp_cvs_cs_sram_master", 0x00000078, 8, 8, CSR_RW, 0x00000000 },
	{ "SHARED_SRAM_CFG", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwe_mode
	{ "pwe0_mode", 0x0000007C, 0, 0, CSR_RW, 0x00000001 },
	{ "pwe1_mode", 0x0000007C, 8, 8, CSR_RW, 0x00000001 },
	{ "pwe2_mode", 0x0000007C, 16, 16, CSR_RW, 0x00000001 },
	{ "pwe3_mode", 0x0000007C, 24, 24, CSR_RW, 0x00000001 },
	{ "PWE_MODE", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_0_0
	{ "isw0_ex_ini_addr_0", 0x00000080, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_0_0", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_0_1
	{ "isw0_ex_ini_addr_1", 0x00000084, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_0_1", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_0_2
	{ "isw0_ex_ini_addr_2", 0x00000088, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_0_2", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_0_3
	{ "isw0_ex_ini_addr_3", 0x0000008C, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_0_3", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_1_0
	{ "isw1_ex_ini_addr_0", 0x00000090, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_1_0", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_1_1
	{ "isw1_ex_ini_addr_1", 0x00000094, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_1_1", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_1_2
	{ "isw1_ex_ini_addr_2", 0x00000098, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_1_2", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_1_3
	{ "isw1_ex_ini_addr_3", 0x0000009C, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_1_3", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_2_0
	{ "isw2_ex_ini_addr_0", 0x000000A0, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_2_0", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_2_1
	{ "isw2_ex_ini_addr_1", 0x000000A4, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_2_1", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_2_2
	{ "isw2_ex_ini_addr_2", 0x000000A8, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_2_2", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_2_3
	{ "isw2_ex_ini_addr_3", 0x000000AC, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_2_3", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_3_0
	{ "isw3_ex_ini_addr_0", 0x000000B0, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_3_0", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_3_1
	{ "isw3_ex_ini_addr_1", 0x000000B4, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_3_1", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_3_2
	{ "isw3_ex_ini_addr_2", 0x000000B8, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_3_2", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dram_waddr_3_3
	{ "isw3_ex_ini_addr_3", 0x000000BC, 27, 0, CSR_RW, 0x00000000 },
	{ "DRAM_WADDR_3_3", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD sensor_sw_status
	{ "mipi_sel", 0x000000C0, 1, 0, CSR_RO, 0x00000000 },
	{ "SENSOR_SW_STATUS", 0x000000C0, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg_mon_sel
	{ "debug_mon_sel", 0x000000C4, 5, 0, CSR_RW, 0x00000000 },
	{ "DBG_MON_SEL", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD buf_update
	{ "double_buf_update", 0x000000C8, 0, 0, CSR_W1P, 0x00000000 },
	{ "BUF_UPDATE", 0x000000C8, 31, 0, CSR_W1P, 0x00000000 },
	// WORD mem_lp_ctrl
	{ "sd", 0x000000CC, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x000000CC, 8, 8, CSR_RW, 0x00000000 },
	{ "MEM_LP_CTRL", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD fe_dbg_mon_sel
	{ "fe0_debug_mon_sel", 0x000000D0, 1, 0, CSR_RW, 0x00000000 },
	{ "fe1_debug_mon_sel", 0x000000D0, 9, 8, CSR_RW, 0x00000000 },
	{ "FE_DBG_MON_SEL", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD isk_dbg_mon_sel
	{ "isk0_debug_mon_sel", 0x000000D4, 2, 0, CSR_RW, 0x00000000 },
	{ "isk1_debug_mon_sel", 0x000000D4, 10, 8, CSR_RW, 0x00000000 },
	{ "ISK_DBG_MON_SEL", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_IS_H_
