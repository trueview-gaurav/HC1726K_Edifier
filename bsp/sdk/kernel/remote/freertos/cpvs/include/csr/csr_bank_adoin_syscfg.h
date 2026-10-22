#ifndef CSR_BANK_ADOIN_SYSCFG_H_
#define CSR_BANK_ADOIN_SYSCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adoin_syscfg  ***/
typedef struct csr_bank_adoin_syscfg {
	/* CONF_ADC0 10'h000 */
	union {
		uint32_t conf_adc0; // word name
		struct {
			uint32_t cken_adc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_adc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ADC1 10'h004 */
	union {
		uint32_t conf_adc1; // word name
		struct {
			uint32_t sw_rst_adc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_adc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ENC0 10'h008 */
	union {
		uint32_t conf_enc0; // word name
		struct {
			uint32_t cken_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ENC1 10'h00C */
	union {
		uint32_t conf_enc1; // word name
		struct {
			uint32_t sw_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_enc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_FADE0 10'h010 */
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
	/* CONF_FADE1 10'h014 */
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
	/* CONF_I2S0 10'h018 */
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
	/* CONF_I2S1 10'h01C */
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
	/* CONF_WRITE0 10'h020 */
	union {
		uint32_t conf_write0; // word name
		struct {
			uint32_t cken_write : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_write : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_WRITE1 10'h024 */
	union {
		uint32_t conf_write1; // word name
		struct {
			uint32_t sw_rst_write : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_write : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_AGC0 10'h028 */
	union {
		uint32_t conf_agc0; // word name
		struct {
			uint32_t cken_agc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_agc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_AGC1 10'h02C */
	union {
		uint32_t conf_agc1; // word name
		struct {
			uint32_t sw_rst_agc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_agc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ARES0 10'h030 */
	union {
		uint32_t conf_ares0; // word name
		struct {
			uint32_t cken_ares : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ares : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ARES1 10'h034 */
	union {
		uint32_t conf_ares1; // word name
		struct {
			uint32_t sw_rst_ares : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_ares : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ANR0 10'h038 */
	union {
		uint32_t conf_anr0; // word name
		struct {
			uint32_t cken_anr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_anr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_ANR1 10'h03C */
	union {
		uint32_t conf_anr1; // word name
		struct {
			uint32_t sw_rst_anr : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_anr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_HPF0 10'h040 */
	union {
		uint32_t conf_hpf0; // word name
		struct {
			uint32_t cken_hpf : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_hpf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF_HPF1 10'h044 */
	union {
		uint32_t conf_hpf1; // word name
		struct {
			uint32_t sw_rst_hpf : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_hpf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdoin_syscfg;

#endif