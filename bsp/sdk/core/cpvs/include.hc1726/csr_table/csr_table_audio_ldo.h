/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AUDIO_LDO_H_
#define CSR_TABLE_AUDIO_LDO_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_audio_ldo[] = {
	// WORD audio_ldo_reg00
	{ "rg_audldo_vref_en", 0x00000000, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_audldo_vreg_en", 0x00000000, 8, 8, CSR_RW, 0x00000000 },
	{ "rg_audldo_vreg25_en", 0x00000000, 16, 16, CSR_RW, 0x00000000 },
	{ "rg_audldo_vreg18_en", 0x00000000, 24, 24, CSR_RW, 0x00000000 },
	{ "AUDIO_LDO_REG00", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD audio_ldo_reg01
	{ "rg_audldo_reserved", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	{ "AUDIO_LDO_REG01", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AUDIO_LDO_H_
