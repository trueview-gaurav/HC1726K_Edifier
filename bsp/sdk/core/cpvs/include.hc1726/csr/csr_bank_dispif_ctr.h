/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_DISPIF_CTR_H_
#define CSR_BANK_DISPIF_CTR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dispif_ctr  ***/
typedef struct csr_bank_dispif_ctr {
	/* MUX0 10'h000 */
	union {
		uint32_t mux0; // word name
		struct {
			uint32_t src_broadcast_enable_pd : 1;
			uint32_t : 7; // padding bits
			uint32_t src_broadcast_enable_mipi : 1;
			uint32_t : 7; // padding bits
			uint32_t src_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MUX1 10'h004 [Unused] */
	uint32_t empty_word_mux1;
	/* LBUF 10'h008 [Unused] */
	uint32_t empty_word_lbuf;
	/* SENIFCTRL3 10'h00C [Unused] */
	uint32_t empty_word_senifctrl3;
	/* SSCTRL 10'h010 [Unused] */
	uint32_t empty_word_ssctrl;
	/* SSEN 10'h014 [Unused] */
	uint32_t empty_word_ssen;
	/* SSCFG 10'h018 [Unused] */
	uint32_t empty_word_sscfg;
	/* SSSTA 10'h01C [Unused] */
	uint32_t empty_word_sssta;
	/* SSH0 10'h020 [Unused] */
	uint32_t empty_word_ssh0;
	/* SSH1 10'h024 [Unused] */
	uint32_t empty_word_ssh1;
	/* SSH2 10'h028 [Unused] */
	uint32_t empty_word_ssh2;
	/* SSH3 10'h02C [Unused] */
	uint32_t empty_word_ssh3;
	/* SSV0 10'h030 [Unused] */
	uint32_t empty_word_ssv0;
	/* SSV1 10'h034 [Unused] */
	uint32_t empty_word_ssv1;
	/* SSV2 10'h038 [Unused] */
	uint32_t empty_word_ssv2;
	/* SSV3 10'h03C [Unused] */
	uint32_t empty_word_ssv3;
	/* DBG 10'h040 */
	union {
		uint32_t dbg; // word name
		struct {
			uint32_t debug_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDispif_ctr;

#endif