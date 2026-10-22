#ifndef CSR_BANK_AUDIO_FADE_IN_H_
#define CSR_BANK_AUDIO_FADE_IN_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audio_fade_in  ***/
typedef struct csr_bank_audio_fade_in {
	/* AUDIO_IN_W1P 16'h0000 */
	union {
		uint32_t audio_in_w1p; // word name
		struct {
			uint32_t audio_in_audio_start : 1;
			uint32_t : 7; // padding bits
			uint32_t audio_in_fade_start : 1;
			uint32_t : 7; // padding bits
			uint32_t audio_in_fade_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_IN_FADE 16'h0004 */
	union {
		uint32_t audio_in_fade; // word name
		struct {
			uint32_t audio_in_fade_time : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_IN_IRQ 16'h0008 */
	union {
		uint32_t audio_in_irq; // word name
		struct {
			uint32_t audio_in_irq_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAudio_fade_in;

#endif