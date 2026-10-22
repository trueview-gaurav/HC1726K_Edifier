#ifndef CSR_BANK_APREAMPCFG_H_
#define CSR_BANK_APREAMPCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from apreampcfg  ***/
typedef struct csr_bank_apreampcfg {
	/* AUDIO_PREAMP_ENABLE 8'h00 */
	union {
		uint32_t audio_preamp_enable; // word name
		struct {
			uint32_t rg_audio_preamp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_audio_preamp_clken : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_PREAMP_REF 8'h04 */
	union {
		uint32_t audio_preamp_ref; // word name
		struct {
			uint32_t rg_audio_preamp_ref_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audio_preamp_plus_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audio_preamp_minus_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_PREAMP_SW 8'h08 */
	union {
		uint32_t audio_preamp_sw; // word name
		struct {
			uint32_t rg_audio_preamp_sw1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audio_preamp_sw2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_audio_preamp_sw3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_PREAMP_MON 8'h0C */
	union {
		uint32_t audio_preamp_mon; // word name
		struct {
			uint32_t preamp_ctrl_mon : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankApreampcfg;

#endif