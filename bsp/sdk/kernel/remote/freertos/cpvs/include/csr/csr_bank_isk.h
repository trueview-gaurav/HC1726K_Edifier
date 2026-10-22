#ifndef CSR_BANK_ISK_H_
#define CSR_BANK_ISK_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isk  ***/
typedef struct csr_bank_isk {
	/* FGMA_MODE 10'h000 */
	union {
		uint32_t fgma_mode; // word name
		struct {
			uint32_t bsp_fgma_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SRC01_BROADCAST 10'h004 */
	union {
		uint32_t src01_broadcast; // word name
		struct {
			uint32_t src1_broadcast_to_fpnr_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t src1_broadcast_to_cvs_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t src1_broadcast_to_cs_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AGMA_BROADCAST 10'h008 */
	union {
		uint32_t agma_broadcast; // word name
		struct {
			uint32_t agma_broadcast_to_out_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t agma_broadcast_to_fpnr_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FPNR_BROADCAST 10'h00C */
	union {
		uint32_t fpnr_broadcast; // word name
		struct {
			uint32_t fpnr_broadcast_to_bls_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t fpnr_broadcast_to_crop_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CROP_BROADCAST 10'h010 */
	union {
		uint32_t crop_broadcast; // word name
		struct {
			uint32_t crop_broadcast_to_out_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t crop_broadcast_to_dbc_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BSP_BROADCAST 10'h014 */
	union {
		uint32_t bsp_broadcast; // word name
		struct {
			uint32_t bsp_broadcast_to_out_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t bsp_broadcast_to_fgma_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FGMA_BROADCAST 10'h018 */
	union {
		uint32_t fgma_broadcast; // word name
		struct {
			uint32_t fgma_broadcast_to_out_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t fgma_broadcast_to_fsc_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BSP_MUX 10'h01C */
	union {
		uint32_t bsp_mux; // word name
		struct {
			uint32_t bsp_cvs_cs_mux_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
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
	/* ISK_ACK_NOT0 10'h024 */
	union {
		uint32_t isk_ack_not0; // word name
		struct {
			uint32_t src1_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t agma_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t fpnr_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t crop_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ISK_ACK_NOT1 10'h028 */
	union {
		uint32_t isk_ack_not1; // word name
		struct {
			uint32_t bsp_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t fgma_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIsk;

#endif