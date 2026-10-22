#ifndef CSR_BANK_SENIF_CTRL_H_
#define CSR_BANK_SENIF_CTRL_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from senif_ctrl  ***/
typedef struct csr_bank_senif_ctrl {
	/* MUX0 10'h000 */
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
	/* MUX1 10'h004 */
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
	/* LBUF 10'h008 */
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
	/* SENIFCTRL3 10'h00C [Unused] */
	uint32_t empty_word_senifctrl3;
	/* SSCTRL 10'h010 */
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
	/* SSEN 10'h014 */
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
	/* SSCFG 10'h018 */
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
	/* SSSTA 10'h01C */
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
	/* SSH0 10'h020 */
	union {
		uint32_t ssh0; // word name
		struct {
			uint32_t slave_hactive : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSH1 10'h024 */
	union {
		uint32_t ssh1; // word name
		struct {
			uint32_t slave_hbp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSH2 10'h028 */
	union {
		uint32_t ssh2; // word name
		struct {
			uint32_t slave_hfp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSH3 10'h02C [Unused] */
	uint32_t empty_word_ssh3;
	/* SSV0 10'h030 */
	union {
		uint32_t ssv0; // word name
		struct {
			uint32_t slave_vactive : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSV1 10'h034 */
	union {
		uint32_t ssv1; // word name
		struct {
			uint32_t slave_vbp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSV2 10'h038 */
	union {
		uint32_t ssv2; // word name
		struct {
			uint32_t slave_vfp : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SSV3 10'h03C [Unused] */
	uint32_t empty_word_ssv3;
	/* DBG 10'h040 */
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
	/* SENIFCTRL18 10'h044 [Unused] */
	uint32_t empty_word_senifctrl18;
	/* SENIFCTRL19 10'h048 [Unused] */
	uint32_t empty_word_senifctrl19;
	/* SENIFCTRL20 10'h04C [Unused] */
	uint32_t empty_word_senifctrl20;
	/* SENIFCTRL21 10'h050 [Unused] */
	uint32_t empty_word_senifctrl21;
	/* SENIFCTRL22 10'h054 [Unused] */
	uint32_t empty_word_senifctrl22;
	/* SENIFCTRL23 10'h058 [Unused] */
	uint32_t empty_word_senifctrl23;
	/* SENIFCTRL24 10'h05C [Unused] */
	uint32_t empty_word_senifctrl24;
	/* SENIFCTRL25 10'h060 [Unused] */
	uint32_t empty_word_senifctrl25;
	/* SENIFCTRL26 10'h064 [Unused] */
	uint32_t empty_word_senifctrl26;
	/* SENIFCTRL27 10'h068 [Unused] */
	uint32_t empty_word_senifctrl27;
	/* SENIFCTRL28 10'h06C [Unused] */
	uint32_t empty_word_senifctrl28;
	/* SENIFCTRL29 10'h070 [Unused] */
	uint32_t empty_word_senifctrl29;
	/* SENIFCTRL30 10'h074 [Unused] */
	uint32_t empty_word_senifctrl30;
	/* SENIFCTRL31 10'h078 [Unused] */
	uint32_t empty_word_senifctrl31;
	/* SENIFCTRL32 10'h07C [Unused] */
	uint32_t empty_word_senifctrl32;
	/* SENIFCTRL33 10'h080 [Unused] */
	uint32_t empty_word_senifctrl33;
	/* SENIFCTRL34 10'h084 [Unused] */
	uint32_t empty_word_senifctrl34;
	/* SENIFCTRL35 10'h088 [Unused] */
	uint32_t empty_word_senifctrl35;
	/* DATA_SHIFT 10'h08C */
	union {
		uint32_t data_shift; // word name
		struct {
			uint32_t slb0_data_shift : 3;
			uint32_t : 5; // padding bits
			uint32_t slb1_data_shift : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DVP_CTRL 10'h090 */
	union {
		uint32_t dvp_ctrl; // word name
		struct {
			uint32_t lv_rst_dvp : 1;
			uint32_t : 7; // padding bits
			uint32_t dvp_data_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DB_UPDATE 10'h094 */
	union {
		uint32_t db_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_WRAPPER 10'h098 */
	union {
		uint32_t mem_wrapper; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESV 10'h09C */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankSenif_ctrl;

#endif