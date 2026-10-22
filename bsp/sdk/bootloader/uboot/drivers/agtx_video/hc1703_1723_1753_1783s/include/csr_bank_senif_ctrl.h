#ifndef CSR_BANK_SENIF_CTRL_H_
#define CSR_BANK_SENIF_CTRL_H_

#include <linux/types.h>

/***  C struct generated from senif_ctrl  ***/
typedef struct csr_bank_senif_ctrl {
	/* MUX0 10'h0000 */
	union {
		uint32_t mux0; // word name
		struct {
			uint32_t mux0_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MUX1 10'h0004 */
	union {
		uint32_t mux1; // word name
		struct {
			uint32_t mux1_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LBUF 10'h0008 */
	union {
		uint32_t lbuf; // word name
		struct {
			uint32_t lbuf_share : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENIFCTRL3 10'h000C [Unused] */
	uint32_t empty_word_senifctrl3;
	/* SSCTRL 10'h0010 */
	union {
		uint32_t ssctrl; // word name
		struct {
			uint32_t slave_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t slave_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSEN 10'h0014 */
	union {
		uint32_t ssen; // word name
		struct {
			uint32_t slave_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSCFG 10'h0018 */
	union {
		uint32_t sscfg; // word name
		struct {
			uint32_t slave_hpolar : 1;
			uint32_t : 7; // padding bits
			uint32_t slave_vpolar : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSSTA 10'h001C */
	union {
		uint32_t sssta; // word name
		struct {
			uint32_t slave_run : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t slave_sta : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* SSH0 10'h0020 */
	union {
		uint32_t ssh0; // word name
		struct {
			uint32_t slave_hactive : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSH1 10'h0024 */
	union {
		uint32_t ssh1; // word name
		struct {
			uint32_t slave_hbp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSH2 10'h0028 */
	union {
		uint32_t ssh2; // word name
		struct {
			uint32_t slave_hfp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSH3 10'h002C [Unused] */
	uint32_t empty_word_ssh3;
	/* SSV0 10'h0030 */
	union {
		uint32_t ssv0; // word name
		struct {
			uint32_t slave_vactive : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSV1 10'h0034 */
	union {
		uint32_t ssv1; // word name
		struct {
			uint32_t slave_vbp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSV2 10'h0038 */
	union {
		uint32_t ssv2; // word name
		struct {
			uint32_t slave_vfp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSV3 10'h003C [Unused] */
	uint32_t empty_word_ssv3;
	/* DBG 10'h0040 */
	union {
		uint32_t dbg; // word name
		struct {
			uint32_t debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV 10'h0044 */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t slb_out_data_shift : 32;
		};
	};
} CsrBankSenif_ctrl;

#endif