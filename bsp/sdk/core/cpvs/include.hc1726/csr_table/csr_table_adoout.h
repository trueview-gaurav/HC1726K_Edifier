/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_ADOOUT_H_
#define CSR_TABLE_ADOOUT_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_adoout[] = {
	// WORD adoout_i2s_irq
	{ "i2s_irq_clear_real_stop", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "i2s_irq_clear_error", 0x00000000, 8, 8, CSR_W1P, 0x00000000 },
	{ "ADOOUT_I2S_IRQ", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD adoout_i2s_status
	{ "i2s_status_real_stop", 0x00000004, 0, 0, CSR_RO, 0x00000000 },
	{ "i2s_status_error", 0x00000004, 8, 8, CSR_RO, 0x00000000 },
	{ "ADOOUT_I2S_STATUS", 0x00000004, 31, 0, CSR_RO, 0x00000000 },
	// WORD adoout_irq_mask
	{ "i2s_irq_mask_real_stop", 0x00000008, 0, 0, CSR_RW, 0x00000001 },
	{ "i2s_irq_mask_error", 0x00000008, 8, 8, CSR_RW, 0x00000001 },
	{ "ADOOUT_IRQ_MASK", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoout_sel
	{ "audio_out_sel", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "ADOOUT_SEL", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoupsamp
	{ "mode", 0x00000010, 2, 0, CSR_RW, 0x00000000 },
	{ "up_sample_input_bw", 0x00000010, 13, 8, CSR_RW, 0x0000000C },
	{ "ADOUPSAMP", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoupsamp_on
	{ "up_sample_start", 0x00000014, 0, 0, CSR_W1P, 0x00000000 },
	{ "up_sample_stop", 0x00000014, 8, 8, CSR_W1P, 0x00000000 },
	{ "ADOUPSAMP_ON", 0x00000014, 31, 0, CSR_W1P, 0x00000000 },
	// WORD adoupsamp_sample
	{ "sample_osr_num", 0x00000018, 15, 0, CSR_RW, 0x00000000 },
	{ "sample_phase_num", 0x00000018, 31, 16, CSR_RW, 0x00000000 },
	{ "ADOUPSAMP_SAMPLE", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoout_debug_sel
	{ "debug_mon_sel", 0x0000001C, 2, 0, CSR_RW, 0x00000000 },
	{ "ADOOUT_DEBUG_SEL", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoout_debug_reg
	{ "debug_mon_reg", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	{ "ADOOUT_DEBUG_REG", 0x00000020, 31, 0, CSR_RO, 0x00000000 },
	// WORD adoout_mem
	{ "sd", 0x00000024, 0, 0, CSR_RW, 0x00000000 },
	{ "slp", 0x00000024, 8, 8, CSR_RW, 0x00000000 },
	{ "ADOOUT_MEM", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoout_reserved_0
	{ "reserved_0", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "ADOOUT_RESERVED_0", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD adoout_reserved_1
	{ "reserved_1", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "ADOOUT_RESERVED_1", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_ADOOUT_H_
