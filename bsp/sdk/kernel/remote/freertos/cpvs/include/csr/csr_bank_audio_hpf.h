#ifndef CSR_BANK_AUDIO_HPF_H_
#define CSR_BANK_AUDIO_HPF_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audio_hpf  ***/
typedef struct csr_bank_audio_hpf {
	/* AUDIO_HPF_B0 16'h0000 */
	union {
		uint32_t audio_hpf_b0; // word name
		struct {
			uint32_t hpf_b0 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_HPF_B1 16'h0004 */
	union {
		uint32_t audio_hpf_b1; // word name
		struct {
			uint32_t hpf_b1 : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_HPF_A 16'h0008 */
	union {
		uint32_t audio_hpf_a; // word name
		struct {
			uint32_t hpf_a : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAudio_hpf;

#endif