/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AUDIO_LDO_H_
#define CSR_BANK_AUDIO_LDO_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audio_ldo  ***/
typedef struct csr_bank_audio_ldo {
	/* AUDIO_LDO_REG00 10'h000 */
	union {
		uint32_t audio_ldo_reg00; // word name
		struct {
			uint32_t rg_audldo_vref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audldo_vreg_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audldo_vreg25_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audldo_vreg18_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AUDIO_LDO_REG01 10'h004 */
	union {
		uint32_t audio_ldo_reg01; // word name
		struct {
			uint32_t rg_audldo_reserved : 32;
		};
	};
} CsrBankAudio_ldo;

#endif