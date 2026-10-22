#ifndef CSR_BANK_DISP_H_
#define CSR_BANK_DISP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from disp  ***/
typedef struct csr_bank_disp {
	/* EFUSE_VIO 10'h000 */
	union {
		uint32_t efuse_vio; // word name
		struct {
			uint32_t disp_efuse_resolution_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t disp_efuse_data_rate_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG_BROADCAST 10'h004 */
	union {
		uint32_t pg_broadcast; // word name
		struct {
			uint32_t pg_broadcast_to_cs_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg_broadcast_to_pg_mux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG_MUX_BROADCAST 10'h008 */
	union {
		uint32_t pg_mux_broadcast; // word name
		struct {
			uint32_t pg_mux_broadcast_to_420to422_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg_mux_broadcast_to_dosd_mux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg_mux_broadcast_to_out_mux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* YUV422_BROADCAST 10'h00C */
	union {
		uint32_t yuv422_broadcast; // word name
		struct {
			uint32_t yuv422_broadcast_to_yuv444_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t yuv422_broadcast_to_dosd_mux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DOSD_BROADCAST 10'h010 */
	union {
		uint32_t dosd_broadcast; // word name
		struct {
			uint32_t dosd_broadcast_to_dcst_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dosd_broadcast_to_out_mux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dosd_broadcast_to_dcs_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DGMA_BROADCAST 10'h014 */
	union {
		uint32_t dgma_broadcast; // word name
		struct {
			uint32_t dgma_broadcast_to_dcfa_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dgma_broadcast_to_out_mux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SEL0 10'h018 */
	union {
		uint32_t sel0; // word name
		struct {
			uint32_t pg_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t dosd_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t out_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FN_BYPASS 10'h01C */
	union {
		uint32_t fn_bypass; // word name
		struct {
			uint32_t disp_cs_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t disp_dosd_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BUF_UPDATE 10'h020 */
	union {
		uint32_t buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ACK_NOT_SEL0 10'h024 */
	union {
		uint32_t ack_not_sel0; // word name
		struct {
			uint32_t pg_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t pg_mux_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t yuv422_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t dosd_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ACK_NOT_SEL1 10'h028 */
	union {
		uint32_t ack_not_sel1; // word name
		struct {
			uint32_t dgma_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t pg_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t dosd_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t out_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MASK_EN 10'h02C */
	union {
		uint32_t mask_en; // word name
		struct {
			uint32_t ready_en_00 : 1;
			uint32_t : 7; // padding bits
			uint32_t ready_en_01 : 1;
			uint32_t : 7; // padding bits
			uint32_t ready_en_10 : 1;
			uint32_t : 7; // padding bits
			uint32_t ready_en_11 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RESOLTION 10'h030 */
	union {
		uint32_t resoltion; // word name
		struct {
			uint32_t width_o : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PRD_MODE 10'h034 */
	union {
		uint32_t prd_mode; // word name
		struct {
			uint32_t pixel_read_decode_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_LP_CTRL 10'h038 */
	union {
		uint32_t mem_lp_ctrl; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t sd_senif : 1;
			uint32_t : 7; // padding bits
			uint32_t slp_senif : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_DEBUG_MON_SEL 10'h03C */
	union {
		uint32_t word_debug_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankDisp;

#endif