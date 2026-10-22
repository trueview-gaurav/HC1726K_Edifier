/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ADOOUT_H_
#define CSR_BANK_ADOOUT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoout  ***/
typedef struct csr_bank_adoout {
	/* ADOOUT_I2S_IRQ 10'h000 */
	union {
		uint32_t adoout_i2s_irq; // word name
		struct {
			uint32_t i2s_irq_clear_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_clear_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT_I2S_STATUS 10'h004 */
	union {
		uint32_t adoout_i2s_status; // word name
		struct {
			uint32_t i2s_status_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_status_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT_IRQ_MASK 10'h008 */
	union {
		uint32_t adoout_irq_mask; // word name
		struct {
			uint32_t i2s_irq_mask_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t i2s_irq_mask_error : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT_SEL 10'h00C */
	union {
		uint32_t adoout_sel; // word name
		struct {
			uint32_t audio_out_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOUPSAMP 10'h010 */
	union {
		uint32_t adoupsamp; // word name
		struct {
			uint32_t mode : 3;
			uint32_t : 5; // padding bits
			uint32_t up_sample_input_bw : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOUPSAMP_ON 10'h014 */
	union {
		uint32_t adoupsamp_on; // word name
		struct {
			uint32_t up_sample_start : 1;
			uint32_t : 7; // padding bits
			uint32_t up_sample_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOUPSAMP_SAMPLE 10'h018 */
	union {
		uint32_t adoupsamp_sample; // word name
		struct {
			uint32_t sample_osr_num : 16;
			uint32_t sample_phase_num : 16;
		};
	};
	/* ADOOUT_DEBUG_SEL 10'h01C */
	union {
		uint32_t adoout_debug_sel; // word name
		struct {
			uint32_t debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT_DEBUG_REG 10'h020 */
	union {
		uint32_t adoout_debug_reg; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* ADOOUT_MEM 10'h024 */
	union {
		uint32_t adoout_mem; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADOOUT_RESERVED_0 10'h028 */
	union {
		uint32_t adoout_reserved_0; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* ADOOUT_RESERVED_1 10'h02C */
	union {
		uint32_t adoout_reserved_1; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
} CsrBankAdoout;

#endif