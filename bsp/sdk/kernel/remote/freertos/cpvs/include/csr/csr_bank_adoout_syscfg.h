#ifndef CSR_BANK_ADOOUT_SYSCFG_H_
#define CSR_BANK_ADOOUT_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoout_syscfg  ***/
typedef struct csr_bank_adoout_syscfg {
	/* CONF_ADAC_L0 10'h000 */
	union {
		uint32_t conf_adac_l0; // word name
		struct {
			uint32_t cken_adac : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_adac : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ADAC_L1 10'h004 */
	union {
		uint32_t conf_adac_l1; // word name
		struct {
			uint32_t sw_rst_adac : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_adac : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ADAC_R0 10'h008 [Unused] */
	uint32_t empty_word_conf_adac_r0;
	/* CONF_ADAC_R1 10'h00C [Unused] */
	uint32_t empty_word_conf_adac_r1;
	/* CONF_DEC0 10'h010 */
	union {
		uint32_t conf_dec0; // word name
		struct {
			uint32_t cken_dec : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_dec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_DEC1 10'h014 */
	union {
		uint32_t conf_dec1; // word name
		struct {
			uint32_t sw_rst_dec : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_dec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_FADE0 10'h018 */
	union {
		uint32_t conf_fade0; // word name
		struct {
			uint32_t cken_fade : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fade : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_FADE1 10'h01C */
	union {
		uint32_t conf_fade1; // word name
		struct {
			uint32_t sw_rst_fade : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_fade : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_I2S0 10'h020 */
	union {
		uint32_t conf_i2s0; // word name
		struct {
			uint32_t cken_i2s : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_i2s : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_I2S1 10'h024 */
	union {
		uint32_t conf_i2s1; // word name
		struct {
			uint32_t sw_rst_i2s : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_i2s : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_READ0 10'h028 */
	union {
		uint32_t conf_read0; // word name
		struct {
			uint32_t cken_read : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_read : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_READ1 10'h02C */
	union {
		uint32_t conf_read1; // word name
		struct {
			uint32_t sw_rst_read : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_read : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_UPSAMPLE0 10'h030 */
	union {
		uint32_t conf_upsample0; // word name
		struct {
			uint32_t cken_up_sample : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_up_sample : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_UPSAMPLE1 10'h034 */
	union {
		uint32_t conf_upsample1; // word name
		struct {
			uint32_t sw_rst_up_sample : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_up_sample : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdoout_syscfg;

#endif