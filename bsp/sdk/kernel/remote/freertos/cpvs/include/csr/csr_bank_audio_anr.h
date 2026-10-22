#ifndef CSR_BANK_AUDIO_ANR_H_
#define CSR_BANK_AUDIO_ANR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from audio_anr  ***/
typedef struct csr_bank_audio_anr {
	/* AUDIO_ANR_0 16'h0000 */
	union {
		uint32_t audio_anr_0; // word name
		struct {
			uint32_t weight_0_0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_1 16'h0004 */
	union {
		uint32_t audio_anr_1; // word name
		struct {
			uint32_t weight_0_1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_2 16'h0008 */
	union {
		uint32_t audio_anr_2; // word name
		struct {
			uint32_t weight_0_2 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_3 16'h000C */
	union {
		uint32_t audio_anr_3; // word name
		struct {
			uint32_t weight_0_3 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_4 16'h0010 */
	union {
		uint32_t audio_anr_4; // word name
		struct {
			uint32_t weight_0_4 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_5 16'h0014 */
	union {
		uint32_t audio_anr_5; // word name
		struct {
			uint32_t weight_0_5 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_6 16'h0018 */
	union {
		uint32_t audio_anr_6; // word name
		struct {
			uint32_t weight_0_6 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_7 16'h001C */
	union {
		uint32_t audio_anr_7; // word name
		struct {
			uint32_t weight_0_7 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_8 16'h0020 */
	union {
		uint32_t audio_anr_8; // word name
		struct {
			uint32_t weight_0_8 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_9 16'h0024 */
	union {
		uint32_t audio_anr_9; // word name
		struct {
			uint32_t weight_0_9 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_10 16'h0028 */
	union {
		uint32_t audio_anr_10; // word name
		struct {
			uint32_t weight_1_0 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_11 16'h002C */
	union {
		uint32_t audio_anr_11; // word name
		struct {
			uint32_t weight_1_1 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_12 16'h0030 */
	union {
		uint32_t audio_anr_12; // word name
		struct {
			uint32_t weight_1_2 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_13 16'h0034 */
	union {
		uint32_t audio_anr_13; // word name
		struct {
			uint32_t weight_1_3 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_14 16'h0038 */
	union {
		uint32_t audio_anr_14; // word name
		struct {
			uint32_t weight_1_4 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_15 16'h003C */
	union {
		uint32_t audio_anr_15; // word name
		struct {
			uint32_t weight_1_5 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_16 16'h0040 */
	union {
		uint32_t audio_anr_16; // word name
		struct {
			uint32_t weight_1_6 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_17 16'h0044 */
	union {
		uint32_t audio_anr_17; // word name
		struct {
			uint32_t weight_1_7 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_18 16'h0048 */
	union {
		uint32_t audio_anr_18; // word name
		struct {
			uint32_t weight_1_8 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AUDIO_ANR_19 16'h004C */
	union {
		uint32_t audio_anr_19; // word name
		struct {
			uint32_t weight_1_9 : 19;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BUF_UPDATE 16'h0050 */
	union {
		uint32_t buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ANR0_MODE 16'h0054 */
	union {
		uint32_t word_anr0_mode; // word name
		struct {
			uint32_t anr0_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ANR1_MODE 16'h0058 */
	union {
		uint32_t word_anr1_mode; // word name
		struct {
			uint32_t anr1_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAudio_anr;

#endif