#ifndef CSR_BANK_ADOOUT_H_
#define CSR_BANK_ADOOUT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoout  ***/
typedef struct csr_bank_adoout {
	/* ADOOUT00 10'h000 */
	union {
		uint32_t adoout00; // word name
		struct {
			uint32_t audior_irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_irq_clear_buffer_full : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_irq_clear_read_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOOUT01 10'h004 */
	union {
		uint32_t adoout01; // word name
		struct {
			uint32_t i2s_irq_clear_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_clear_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT02 10'h008 */
	union {
		uint32_t adoout02; // word name
		struct {
			uint32_t adac_l_irq_clear_no_ready : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_l_irq_clear_incr_arrival : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_l_irq_clear_decr_arrival : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT03 10'h00C */
	union {
		uint32_t adoout03; // word name
		struct {
			uint32_t audior_status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_status_buffer_full : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_status_read_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOOUT04 10'h010 */
	union {
		uint32_t adoout04; // word name
		struct {
			uint32_t i2s_status_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_status_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT05 10'h014 */
	union {
		uint32_t adoout05; // word name
		struct {
			uint32_t adac_l_status_no_ready : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_l_status_incr_arrival : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_l_status_decr_arrival : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT06 10'h018 */
	union {
		uint32_t adoout06; // word name
		struct {
			uint32_t audior_irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_irq_mask_buffer_full : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t audior_irq_mask_read_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOOUT07 10'h01C */
	union {
		uint32_t adoout07; // word name
		struct {
			uint32_t i2s_irq_mask_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_mask_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT08 10'h020 */
	union {
		uint32_t adoout08; // word name
		struct {
			uint32_t adac_l_irq_mask_no_ready : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_l_irq_mask_incr_arrival : 1;
			uint32_t : 7; // padding bits
			uint32_t adac_l_irq_mask_decr_arrival : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT09 10'h024 */
	union {
		uint32_t adoout09; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t audio_destination : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT10 10'h028 */
	union {
		uint32_t adoout10; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT11 10'h02C */
	union {
		uint32_t adoout11; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* ADOOUT12 10'h030 */
	union {
		uint32_t adoout12; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* ADOOUT13 10'h034 [Unused] */
	uint32_t empty_word_adoout13;
	/* ADOOUT14 10'h038 [Unused] */
	uint32_t empty_word_adoout14;
	/* ADOOUT15 10'h03C [Unused] */
	uint32_t empty_word_adoout15;
	/* ADOOUT16 10'h040 [Unused] */
	uint32_t empty_word_adoout16;
	/* ADOOUT17 10'h044 [Unused] */
	uint32_t empty_word_adoout17;
	/* ADOOUT18 10'h048 [Unused] */
	uint32_t empty_word_adoout18;
	/* ADOOUT19 10'h04C [Unused] */
	uint32_t empty_word_adoout19;
	/* ADOOUT20 10'h050 [Unused] */
	uint32_t empty_word_adoout20;
	/* ADOOUT21 10'h054 [Unused] */
	uint32_t empty_word_adoout21;
	/* ADOOUT22 10'h058 [Unused] */
	uint32_t empty_word_adoout22;
	/* ADOOUT23 10'h05C [Unused] */
	uint32_t empty_word_adoout23;
	/* ADOOUT24 10'h060 [Unused] */
	uint32_t empty_word_adoout24;
	/* ADOOUT25 10'h064 [Unused] */
	uint32_t empty_word_adoout25;
	/* ADOOUT26 10'h068 [Unused] */
	uint32_t empty_word_adoout26;
	/* ADOOUT27 10'h06C [Unused] */
	uint32_t empty_word_adoout27;
	/* ADOOUT28 10'h070 [Unused] */
	uint32_t empty_word_adoout28;
	/* ADOOUT29 10'h074 [Unused] */
	uint32_t empty_word_adoout29;
	/* ADOOUT30 10'h078 [Unused] */
	uint32_t empty_word_adoout30;
	/* ADOOUT31 10'h07C [Unused] */
	uint32_t empty_word_adoout31;
	/* ADOOUT32 10'h080 [Unused] */
	uint32_t empty_word_adoout32;
	/* ADOOUT33 10'h084 [Unused] */
	uint32_t empty_word_adoout33;
	/* ADOOUT34 10'h088 [Unused] */
	uint32_t empty_word_adoout34;
	/* ADOOUT35 10'h08C [Unused] */
	uint32_t empty_word_adoout35;
	/* ADOOUT36 10'h090 [Unused] */
	uint32_t empty_word_adoout36;
	/* ADOOUT37 10'h094 [Unused] */
	uint32_t empty_word_adoout37;
	/* ADOOUT38 10'h098 [Unused] */
	uint32_t empty_word_adoout38;
	/* ADOOUT39 10'h09C [Unused] */
	uint32_t empty_word_adoout39;
	/* ADOUPDATE 10'h0A0 */
	union {
		uint32_t adoupdate; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOUPSAMP 10'h0A4 */
	union {
		uint32_t adoupsamp; // word name
		struct {
			uint32_t up_sample_scale : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdoout;

#endif