/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_TRNG_H_
#define CSR_TABLE_TRNG_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_trng[] = {
	// WORD start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD trng_en
	{ "rg_trng_en", 0x00000004, 0, 0, CSR_RW, 0x00000000 },
	{ "inv_chain_en", 0x00000004, 4, 4, CSR_RW, 0x00000000 },
	{ "digi_ana_sel", 0x00000004, 8, 8, CSR_RW, 0x00000000 },
	{ "inv_chain_sel", 0x00000004, 13, 12, CSR_RW, 0x00000000 },
	{ "TRNG_EN", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD trng_out_0
	{ "rg_trng_out", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	{ "TRNG_OUT_0", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD trng_out_1
	{ "rg_trng_out_1", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	{ "TRNG_OUT_1", 0x0000000C, 31, 0, CSR_RO, 0x00000000 },
	// WORD st_config
	{ "busy", 0x00000010, 0, 0, CSR_RO, 0x00000000 },
	{ "out_valid", 0x00000010, 8, 8, CSR_RO, 0x00000000 },
	{ "des_busy", 0x00000010, 16, 16, CSR_RO, 0x00000000 },
	{ "ST_CONFIG", 0x00000010, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_st
	{ "irq_status_pack_done", 0x00000014, 0, 0, CSR_RO, 0x00000000 },
	{ "IRQ_ST", 0x00000014, 31, 0, CSR_RO, 0x00000000 },
	// WORD irq_clr
	{ "irq_clear_pack_done", 0x00000018, 0, 0, CSR_W1P, 0x00000000 },
	{ "IRQ_CLR", 0x00000018, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_mask
	{ "irq_mask_pack_done", 0x0000001C, 0, 0, CSR_RW, 0x00000001 },
	{ "IRQ_MASK", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD op_config
	{ "pack_target", 0x00000020, 1, 0, CSR_RW, 0x00000000 },
	{ "recur_en", 0x00000020, 8, 8, CSR_RW, 0x00000000 },
	{ "key_protect_en", 0x00000020, 16, 16, CSR_RW, 0x00000000 },
	{ "OP_CONFIG", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD trng_bypass
	{ "bypass_trng", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "TRNG_BYPASS", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD trng_byp_00
	{ "trng_fake_data0", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "TRNG_BYP_00", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD trng_byp_01
	{ "trng_fake_data1", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "TRNG_BYP_01", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD out_00
	{ "data_00", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_00", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_01
	{ "data_01", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_01", 0x00000034, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_02
	{ "data_02", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_02", 0x00000038, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_03
	{ "data_03", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_03", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_04
	{ "data_04", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_04", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_05
	{ "data_05", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_05", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_06
	{ "data_06", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_06", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD out_07
	{ "data_07", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	{ "OUT_07", 0x0000004C, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_TRNG_H_
