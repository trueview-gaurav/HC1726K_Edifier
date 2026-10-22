#ifndef CSR_BANK_AXIQOS_H_
#define CSR_BANK_AXIQOS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from axiqos  ***/
typedef struct csr_bank_axiqos {
	/* UPDATE 8'h00 */
	union {
		uint32_t update; // word name
		struct {
			uint32_t awqos_upd : 1;
			uint32_t : 7; // padding bits
			uint32_t arqos_upd : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AQOSMAP1 8'h04 [Unused] */
	uint32_t empty_word_aqosmap1;
	/* WFBD 8'h08 */
	union {
		uint32_t wfbd; // word name
		struct {
			uint32_t awid_forbid : 32;
		};
	};
	/* RFBD 8'h0C */
	union {
		uint32_t rfbd; // word name
		struct {
			uint32_t arid_forbid : 32;
		};
	};
	/* WDET 8'h10 */
	union {
		uint32_t wdet; // word name
		struct {
			uint32_t awid_detect : 32;
		};
	};
	/* RDET 8'h14 */
	union {
		uint32_t rdet; // word name
		struct {
			uint32_t arid_detect : 32;
		};
	};
	/* WERR 8'h18 */
	union {
		uint32_t werr; // word name
		struct {
			uint32_t awid_error : 32;
		};
	};
	/* RERR 8'h1C */
	union {
		uint32_t rerr; // word name
		struct {
			uint32_t arid_error : 32;
		};
	};
	/* WMAP0 8'h20 */
	union {
		uint32_t wmap0; // word name
		struct {
			uint32_t awqos_id_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP1 8'h24 */
	union {
		uint32_t wmap1; // word name
		struct {
			uint32_t awqos_id_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP2 8'h28 */
	union {
		uint32_t wmap2; // word name
		struct {
			uint32_t awqos_id_8 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_9 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_10 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_11 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP3 8'h2C */
	union {
		uint32_t wmap3; // word name
		struct {
			uint32_t awqos_id_12 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_13 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_14 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_15 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP4 8'h30 */
	union {
		uint32_t wmap4; // word name
		struct {
			uint32_t awqos_id_16 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_17 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_18 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_19 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP5 8'h34 */
	union {
		uint32_t wmap5; // word name
		struct {
			uint32_t awqos_id_20 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_21 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_22 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_23 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP6 8'h38 */
	union {
		uint32_t wmap6; // word name
		struct {
			uint32_t awqos_id_24 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_25 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_26 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_27 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* WMAP7 8'h3C */
	union {
		uint32_t wmap7; // word name
		struct {
			uint32_t awqos_id_28 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_29 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_30 : 4;
			uint32_t : 4; // padding bits
			uint32_t awqos_id_31 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP0 8'h40 */
	union {
		uint32_t rmap0; // word name
		struct {
			uint32_t arqos_id_0 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_1 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_2 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_3 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP1 8'h44 */
	union {
		uint32_t rmap1; // word name
		struct {
			uint32_t arqos_id_4 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_5 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_6 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_7 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP2 8'h48 */
	union {
		uint32_t rmap2; // word name
		struct {
			uint32_t arqos_id_8 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_9 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_10 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_11 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP3 8'h4C */
	union {
		uint32_t rmap3; // word name
		struct {
			uint32_t arqos_id_12 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_13 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_14 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_15 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP4 8'h50 */
	union {
		uint32_t rmap4; // word name
		struct {
			uint32_t arqos_id_16 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_17 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_18 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_19 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP5 8'h54 */
	union {
		uint32_t rmap5; // word name
		struct {
			uint32_t arqos_id_20 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_21 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_22 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_23 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP6 8'h58 */
	union {
		uint32_t rmap6; // word name
		struct {
			uint32_t arqos_id_24 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_25 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_26 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_27 : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RMAP7 8'h5C */
	union {
		uint32_t rmap7; // word name
		struct {
			uint32_t arqos_id_28 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_29 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_30 : 4;
			uint32_t : 4; // padding bits
			uint32_t arqos_id_31 : 4;
			uint32_t : 4; // padding bits
		};
	};
} CsrBankAxiqos;

#endif