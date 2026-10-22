#ifndef CSR_BANK_ADOCODEC_H_
#define CSR_BANK_ADOCODEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from adocodec  ***/
typedef struct csr_bank_adocodec {
	/* WORD_CODEC_MODE 10'h000 */
	union {
		uint32_t word_codec_mode; // word name
		struct {
			uint32_t codec_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t codec_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_G711_MODE 10'h004 */
	union {
		uint32_t word_g711_mode; // word name
		struct {
			uint32_t g711_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_G726_MODE 10'h008 */
	union {
		uint32_t word_g726_mode; // word name
		struct {
			uint32_t g726_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOUBLE_BUF 10'h00C */
	union {
		uint32_t double_buf; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLEAR 10'h010 */
	union {
		uint32_t clear; // word name
		struct {
			uint32_t codec_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PACK_I_CTRL 10'h014 */
	union {
		uint32_t pack_i_ctrl; // word name
		struct {
			uint32_t pki_little_endian : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PACK_O_CTRL 10'h018 */
	union {
		uint32_t pack_o_ctrl; // word name
		struct {
			uint32_t pko_little_endian : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAdocodec;

#endif