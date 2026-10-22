/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_IS_CHECKSUM_H_
#define CSR_TABLE_IS_CHECKSUM_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_is_checksum[] = {
	// WORD clr
	{ "clear_k", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "clear_d", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "CLR", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD fe0_edp0
	{ "checksum_fe0_edp_0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	{ "FE0_EDP0", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD fe0_edp1
	{ "checksum_fe0_edp_1", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "FE0_EDP1", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD isr0
	{ "checksum_isr0", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "ISR0", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD fe1_edp0
	{ "checksum_fe1_edp_0", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	{ "FE1_EDP0", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD fe1_edp1
	{ "checksum_fe1_edp_1", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	{ "FE1_EDP1", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD isr1
	{ "checksum_isr1", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	{ "ISR1", 0x00000018, 31, 0, CSR_RO, 0x00000000 },
	// WORD input_route0
	{ "checksum_input_route_dst0", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	{ "INPUT_ROUTE0", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD input_route1
	{ "checksum_input_route_dst1", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "INPUT_ROUTE1", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD input_route2
	{ "checksum_input_route_dst2", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	{ "INPUT_ROUTE2", 0x00000024, 31, 0, CSR_RO, 0x00000000 },
	// WORD input_route3
	{ "checksum_input_route_dst3", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	{ "INPUT_ROUTE3", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD input_route4
	{ "checksum_input_route_dst4", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	{ "INPUT_ROUTE4", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD input_route5
	{ "checksum_input_route_dst5", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "INPUT_ROUTE5", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD output_route0
	{ "checksum_output_route_dst0", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "OUTPUT_ROUTE0", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD output_route1
	{ "checksum_output_route_dst1", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	{ "OUTPUT_ROUTE1", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD output_route2
	{ "checksum_output_route_dst2", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	{ "OUTPUT_ROUTE2", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD output_route3
	{ "checksum_output_route_dst3", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "OUTPUT_ROUTE3", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD pwe0
	{ "checksum_pwe0", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	{ "PWE0", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD pwe1
	{ "checksum_pwe1", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	{ "PWE1", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD pwe2
	{ "checksum_pwe2", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	{ "PWE2", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// WORD pwe3
	{ "checksum_pwe3", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	{ "PWE3", 0x00000050, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw0_lsb
	{ "checksum_isw0_lsb", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW0_LSB", 0x00000054, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw0_msb
	{ "checksum_isw0_msb", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW0_MSB", 0x00000058, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw1_lsb
	{ "checksum_isw1_lsb", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW1_LSB", 0x0000005C, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw1_msb
	{ "checksum_isw1_msb", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW1_MSB", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw2_lsb
	{ "checksum_isw2_lsb", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW2_LSB", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw2_msb
	{ "checksum_isw2_msb", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW2_MSB", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw3_lsb
	{ "checksum_isw3_lsb", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW3_LSB", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD isw3_msb
	{ "checksum_isw3_msb", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	{ "ISW3_MSB", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_IS_CHECKSUM_H_
