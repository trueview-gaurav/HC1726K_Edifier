/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_TZASC_H_
#define CSR_TABLE_TZASC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_tzasc[] = {
	// WORD build_config
	{ "no_of_regions", 0x00000000, 4, 0, CSR_RO, 0x00000000 },
	{ "address_width", 0x00000000, 13, 8, CSR_RO, 0x00000000 },
	{ "no_of_filters", 0x00000000, 25, 24, CSR_RO, 0x00000000 },
	{ "BUILD_CONFIG", 0x00000000, 31, 0, CSR_RO, 0x00000000 },
	// WORD action
	{ "reaction_value", 0x00000004, 1, 0, CSR_RW, 0x00000000 },
	{ "ACTION", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD gate_keeper
	{ "open_request", 0x00000008, 1, 0, CSR_RW, 0x00000000 },
	{ "open_status", 0x00000008, 17, 16, CSR_RW, 0x00000000 },
	{ "GATE_KEEPER", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD speculation_ctrl
	{ "read_spec_disable", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "write_spec_disable", 0x0000000C, 1, 1, CSR_RW, 0x00000000 },
	{ "SPECULATION_CTRL", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD int_status
	{ "status", 0x00000010, 3, 0, CSR_RO, 0x00000000 },
	{ "overrun", 0x00000010, 11, 8, CSR_RO, 0x00000000 },
	{ "overlap", 0x00000010, 19, 16, CSR_RO, 0x00000000 },
	{ "INT_STATUS", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD int_clear
	{ "clear", 0x00000014, 3, 0, CSR_W1P, 0x00000000 },
	{ "INT_CLEAR", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD fail_address_low_0
	{ "addr_status_low0", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_LOW_0", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_high_0
	{ "addr_status_high0", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_HIGH_0", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_control_0
	{ "provoleged0", 0x00000028, 20, 20, CSR_RO, 0x00000000 },
	{ "non_secure0", 0x00000028, 21, 21, CSR_RO, 0x00000000 },
	{ "direction0", 0x00000028, 24, 24, CSR_RO, 0x00000000 },
	{ "FAIL_CONTROL_0", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_id_0
	{ "id0", 0x0000002C, 5, 0, CSR_RO, 0x00000000 },
	{ "vnet0", 0x0000002C, 27, 24, CSR_RO, 0x00000000 },
	{ "FAIL_ID_0", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_low_1
	{ "addr_status_low1", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_LOW_1", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_high_1
	{ "addr_status_high1", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_HIGH_1", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_control_1
	{ "provoleged1", 0x00000038, 20, 20, CSR_RO, 0x00000000 },
	{ "non_secure1", 0x00000038, 21, 21, CSR_RO, 0x00000000 },
	{ "direction1", 0x00000038, 24, 24, CSR_RO, 0x00000000 },
	{ "FAIL_CONTROL_1", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_id_1
	{ "id1", 0x0000003C, 5, 0, CSR_RO, 0x00000000 },
	{ "vnet1", 0x0000003C, 27, 24, CSR_RO, 0x00000000 },
	{ "FAIL_ID_1", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_low_2
	{ "addr_status_low2", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_LOW_2", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_high_2
	{ "addr_status_high2", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_HIGH_2", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_control_2
	{ "provoleged2", 0x00000048, 20, 20, CSR_RO, 0x00000000 },
	{ "non_secure2", 0x00000048, 21, 21, CSR_RO, 0x00000000 },
	{ "direction2", 0x00000048, 24, 24, CSR_RO, 0x00000000 },
	{ "FAIL_CONTROL_2", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_id_2
	{ "id2", 0x0000004C, 5, 0, CSR_RO, 0x00000000 },
	{ "vnet2", 0x0000004C, 27, 24, CSR_RO, 0x00000000 },
	{ "FAIL_ID_2", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_low_3
	{ "addr_status_low3", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_LOW_3", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_address_high_3
	{ "addr_status_high3", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	{ "FAIL_ADDRESS_HIGH_3", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_control_3
	{ "provoleged3", 0x00000058, 20, 20, CSR_RO, 0x00000000 },
	{ "non_secure3", 0x00000058, 21, 21, CSR_RO, 0x00000000 },
	{ "direction3", 0x00000058, 24, 24, CSR_RO, 0x00000000 },
	{ "FAIL_CONTROL_3", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD fail_id_3
	{ "id3", 0x0000005C, 5, 0, CSR_RO, 0x00000000 },
	{ "vnet3", 0x0000005C, 27, 24, CSR_RO, 0x00000000 },
	{ "FAIL_ID_3", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_base_low_0
	{ "base_address_low0", 0x00000100, 31, 12, CSR_RO, 0x00000000 },
	{ "REGION_BASE_LOW_0", 0x00000100, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_base_high_0
	{ "base_address_high0", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_0", 0x00000104, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_0
	{ "top_address_low0_lsb", 0x00000108, 11, 0, CSR_RO, 0x00000000 },
	{ "top_address_low0", 0x00000108, 31, 12, CSR_RO, 0x00000000 },
	{ "REGION_TOP_LOW_0", 0x00000108, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_high_0
	{ "top_address_high0", 0x0000010C, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_0", 0x0000010C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_0
	{ "filter_en0", 0x00000110, 1, 0, CSR_RW, 0x00000003 },
	{ "s_rd_en0", 0x00000110, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en0", 0x00000110, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_0", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_0
	{ "nsaid_rd_en0", 0x00000114, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en0", 0x00000114, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_0", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_1
	{ "base_address_low1", 0x00000120, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_1", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_1
	{ "base_address_high1", 0x00000124, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_1", 0x00000124, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_1
	{ "top_address_low1", 0x00000128, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_1", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_1
	{ "top_address_high1", 0x0000012C, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_1", 0x0000012C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_1
	{ "filter_en1", 0x00000130, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en1", 0x00000130, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en1", 0x00000130, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_1", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_1
	{ "nsaid_rd_en1", 0x00000134, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en1", 0x00000134, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_1", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_2
	{ "base_address_low2", 0x00000140, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_2", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_2
	{ "base_address_high2", 0x00000144, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_2", 0x00000144, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_2
	{ "top_address_low2", 0x00000148, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_2", 0x00000148, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_2
	{ "top_address_high2", 0x0000014C, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_2", 0x0000014C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_2
	{ "filter_en2", 0x00000150, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en2", 0x00000150, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en2", 0x00000150, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_2", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_2
	{ "nsaid_rd_en2", 0x00000154, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en2", 0x00000154, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_2", 0x00000154, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_3
	{ "base_address_low3", 0x00000160, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_3", 0x00000160, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_3
	{ "base_address_high3", 0x00000164, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_3", 0x00000164, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_3
	{ "top_address_low3", 0x00000168, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_3", 0x00000168, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_3
	{ "top_address_high3", 0x0000016C, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_3", 0x0000016C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_3
	{ "filter_en3", 0x00000170, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en3", 0x00000170, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en3", 0x00000170, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_3", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_3
	{ "nsaid_rd_en3", 0x00000174, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en3", 0x00000174, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_3", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_4
	{ "base_address_low4", 0x00000180, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_4", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_4
	{ "base_address_high4", 0x00000184, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_4", 0x00000184, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_4
	{ "top_address_low4", 0x00000188, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_4", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_4
	{ "top_address_high4", 0x0000018C, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_4", 0x0000018C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_4
	{ "filter_en4", 0x00000190, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en4", 0x00000190, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en4", 0x00000190, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_4", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_4
	{ "nsaid_rd_en4", 0x00000194, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en4", 0x00000194, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_4", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_5
	{ "base_address_low5", 0x000001A0, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_5", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_5
	{ "base_address_high5", 0x000001A4, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_5", 0x000001A4, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_5
	{ "top_address_low5", 0x000001A8, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_5", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_5
	{ "top_address_high5", 0x000001AC, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_5", 0x000001AC, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_5
	{ "filter_en5", 0x000001B0, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en5", 0x000001B0, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en5", 0x000001B0, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_5", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_5
	{ "nsaid_rd_en5", 0x000001B4, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en5", 0x000001B4, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_5", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_6
	{ "base_address_low6", 0x000001C0, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_6", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_6
	{ "base_address_high6", 0x000001C4, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_6", 0x000001C4, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_6
	{ "top_address_low6", 0x000001C8, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_6", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_6
	{ "top_address_high6", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_6", 0x000001CC, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_6
	{ "filter_en6", 0x000001D0, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en6", 0x000001D0, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en6", 0x000001D0, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_6", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_6
	{ "nsaid_rd_en6", 0x000001D4, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en6", 0x000001D4, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_6", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_7
	{ "base_address_low7", 0x000001E0, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_7", 0x000001E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_7
	{ "base_address_high7", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_7", 0x000001E4, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_7
	{ "top_address_low7", 0x000001E8, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_7", 0x000001E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_7
	{ "top_address_high7", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_7", 0x000001EC, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_7
	{ "filter_en7", 0x000001F0, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en7", 0x000001F0, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en7", 0x000001F0, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_7", 0x000001F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_7
	{ "nsaid_rd_en7", 0x000001F4, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en7", 0x000001F4, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_7", 0x000001F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_low_8
	{ "base_address_low8", 0x00000200, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_BASE_LOW_8", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_base_high_8
	{ "base_address_high8", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_BASE_HIGH_8", 0x00000204, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_top_low_8
	{ "top_address_low8", 0x00000208, 31, 12, CSR_RW, 0x00000000 },
	{ "REGION_TOP_LOW_8", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_top_high_8
	{ "top_address_high8", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	{ "REGION_TOP_HIGH_8", 0x0000020C, 31, 0, CSR_RO, 0x00000000 },
	// WORD region_attributes_8
	{ "filter_en8", 0x00000210, 1, 0, CSR_RW, 0x00000000 },
	{ "s_rd_en8", 0x00000210, 30, 30, CSR_RW, 0x00000000 },
	{ "s_wr_en8", 0x00000210, 31, 31, CSR_RW, 0x00000000 },
	{ "REGION_ATTRIBUTES_8", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD region_id_access_8
	{ "nsaid_rd_en8", 0x00000214, 15, 0, CSR_RW, 0x00000000 },
	{ "nsaid_wr_en8", 0x00000214, 31, 16, CSR_RW, 0x00000000 },
	{ "REGION_ID_ACCESS_8", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	// WORD pid4
	{ "jep106_c_code", 0x00000FD0, 3, 0, CSR_RO, 0x00000000 },
	{ "4kb_count", 0x00000FD0, 7, 4, CSR_RO, 0x00000000 },
	{ "PID4", 0x00000FD0, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid5
	{ "pid5_value", 0x00000FD4, 7, 0, CSR_RO, 0x00000000 },
	{ "PID5", 0x00000FD4, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid6
	{ "pid6_value", 0x00000FD8, 7, 0, CSR_RO, 0x00000000 },
	{ "PID6", 0x00000FD8, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid7
	{ "pid7_value", 0x00000FDC, 7, 0, CSR_RO, 0x00000000 },
	{ "PID7", 0x00000FDC, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid0
	{ "part_number_0", 0x00000FE0, 7, 0, CSR_RO, 0x00000000 },
	{ "PID0", 0x00000FE0, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid1
	{ "part_number_1", 0x00000FE4, 3, 0, CSR_RO, 0x00000000 },
	{ "jep106_id_3_0", 0x00000FE4, 7, 4, CSR_RO, 0x00000000 },
	{ "PID1", 0x00000FE4, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid2
	{ "jep106_id_6_4", 0x00000FE8, 2, 0, CSR_RO, 0x00000000 },
	{ "jedec_used", 0x00000FE8, 3, 3, CSR_RO, 0x00000000 },
	{ "revision", 0x00000FE8, 7, 4, CSR_RO, 0x00000000 },
	{ "PID2", 0x00000FE8, 31, 0, CSR_RO, 0x00000000 },
	// WORD pid3
	{ "mod_number", 0x00000FEC, 3, 0, CSR_RO, 0x00000000 },
	{ "revand", 0x00000FEC, 7, 4, CSR_RO, 0x00000000 },
	{ "PID3", 0x00000FEC, 31, 0, CSR_RO, 0x00000000 },
	// WORD cid0
	{ "comp_id_0", 0x00000FF0, 7, 0, CSR_RO, 0x00000000 },
	{ "CID0", 0x00000FF0, 31, 0, CSR_RO, 0x00000000 },
	// WORD cid1
	{ "comp_id_1", 0x00000FF4, 7, 0, CSR_RO, 0x00000000 },
	{ "CID1", 0x00000FF4, 31, 0, CSR_RO, 0x00000000 },
	// WORD cid2
	{ "comp_id_2", 0x00000FF8, 7, 0, CSR_RO, 0x00000000 },
	{ "CID2", 0x00000FF8, 31, 0, CSR_RO, 0x00000000 },
	// WORD cid3
	{ "comp_id_3", 0x00000FFC, 7, 0, CSR_RO, 0x00000000 },
	{ "CID3", 0x00000FFC, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_TZASC_H_
