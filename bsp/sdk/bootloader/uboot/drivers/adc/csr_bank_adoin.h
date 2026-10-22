/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADOIN_H_
#define CSR_BANK_ADOIN_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoin  ***/
typedef struct csr_bank_adoin {
	/* ADOIN00 10'h000 */
	union {
		uint32_t adoin00; // word name
		struct {
			uint32_t audiow_irq_clear_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_irq_clear_buffer_full : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_irq_clear_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_irq_clear_write_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOIN01 10'h004 */
	union {
		uint32_t adoin01; // word name
		struct {
			uint32_t i2s_irq_clear_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_clear_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN02 10'h008 */
	union {
		uint32_t adoin02; // word name
		struct {
			uint32_t adc_irq_clear_adc_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_clear_no_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_clear_no_eoc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN03 10'h00C */
	union {
		uint32_t adoin03; // word name
		struct {
			uint32_t adc_irq_clear_env_de_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_clear_env_de_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_clear_env_de_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_clear_env_de_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOIN04 10'h010 */
	union {
		uint32_t adoin04; // word name
		struct {
			uint32_t audiow_status_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_status_buffer_full : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_status_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_status_write_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOIN05 10'h014 */
	union {
		uint32_t adoin05; // word name
		struct {
			uint32_t i2s_status_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_status_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN06 10'h018 */
	union {
		uint32_t adoin06; // word name
		struct {
			uint32_t adc_status_adc_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_status_no_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_status_no_eoc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN07 10'h01C */
	union {
		uint32_t adoin07; // word name
		struct {
			uint32_t adc_status_env_de_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_status_env_de_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_status_env_de_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_status_env_de_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOIN08 10'h020 */
	union {
		uint32_t adoin08; // word name
		struct {
			uint32_t audiow_irq_mask_bw_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_irq_mask_buffer_full : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_irq_mask_access_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t audiow_irq_mask_write_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOIN09 10'h024 */
	union {
		uint32_t adoin09; // word name
		struct {
			uint32_t i2s_irq_mask_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_mask_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN10 10'h028 */
	union {
		uint32_t adoin10; // word name
		struct {
			uint32_t adc_irq_mask_adc_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_mask_no_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_mask_no_eoc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN11 10'h02C */
	union {
		uint32_t adoin11; // word name
		struct {
			uint32_t adc_irq_mask_env_de_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_mask_env_de_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_mask_env_de_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_mask_env_de_3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADOIN12 10'h030 */
	union {
		uint32_t adoin12; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN13 10'h034 */
	union {
		uint32_t adoin13; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN14 10'h038 */
	union {
		uint32_t adoin14; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* ADOIN15 10'h03C */
	union {
		uint32_t adoin15; // word name
		struct {
			uint32_t adc_irq_clear_env_de_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_clear_env_de_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN16 10'h040 */
	union {
		uint32_t adoin16; // word name
		struct {
			uint32_t adc_status_env_de_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_status_env_de_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN17 10'h044 */
	union {
		uint32_t adoin17; // word name
		struct {
			uint32_t adc_irq_mask_env_de_4 : 1;
			uint32_t : 7; // padding bits
			uint32_t adc_irq_mask_env_de_5 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOIN18 10'h048 */
	union {
		uint32_t adoin18; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* ADOIN19 10'h04C [Unused] */
	uint32_t empty_word_adoin19;
	/* ADOIN20 10'h050 [Unused] */
	uint32_t empty_word_adoin20;
	/* ADOIN21 10'h054 [Unused] */
	uint32_t empty_word_adoin21;
	/* ADOIN22 10'h058 [Unused] */
	uint32_t empty_word_adoin22;
	/* ADOIN23 10'h05C [Unused] */
	uint32_t empty_word_adoin23;
	/* ADOIN24 10'h060 [Unused] */
	uint32_t empty_word_adoin24;
	/* ADOIN25 10'h064 [Unused] */
	uint32_t empty_word_adoin25;
	/* ADOIN26 10'h068 [Unused] */
	uint32_t empty_word_adoin26;
	/* ADOIN27 10'h06C [Unused] */
	uint32_t empty_word_adoin27;
	/* ADOIN28 10'h070 [Unused] */
	uint32_t empty_word_adoin28;
	/* ADOIN29 10'h074 [Unused] */
	uint32_t empty_word_adoin29;
	/* ADOIN30 10'h078 [Unused] */
	uint32_t empty_word_adoin30;
	/* ADOIN31 10'h07C [Unused] */
	uint32_t empty_word_adoin31;
	/* ADOIN32 10'h080 [Unused] */
	uint32_t empty_word_adoin32;
	/* ADOIN33 10'h084 [Unused] */
	uint32_t empty_word_adoin33;
	/* ADOIN34 10'h088 [Unused] */
	uint32_t empty_word_adoin34;
	/* ADOIN35 10'h08C [Unused] */
	uint32_t empty_word_adoin35;
	/* ADOIN36 10'h090 [Unused] */
	uint32_t empty_word_adoin36;
	/* ADOIN37 10'h094 [Unused] */
	uint32_t empty_word_adoin37;
	/* ADOIN38 10'h098 [Unused] */
	uint32_t empty_word_adoin38;
	/* ADOIN39 10'h09C [Unused] */
	uint32_t empty_word_adoin39;
	/* ADOIN40 10'h0A0 [Unused] */
	uint32_t empty_word_adoin40;
	/* ADOIN41 10'h0A4 [Unused] */
	uint32_t empty_word_adoin41;
	/* SRC_SEL 10'h0A8 */
	union {
		uint32_t src_sel; // word name
		struct {
			uint32_t audio_source : 1;
			uint32_t : 7; // padding bits
			uint32_t audio_source_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DN_BYPASS 10'h0AC */
	union {
		uint32_t dn_bypass; // word name
		struct {
			uint32_t down_sample_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DOUBLE_BUF_UPDATE 10'h0B0 */
	union {
		uint32_t word_double_buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdoin;

#endif
