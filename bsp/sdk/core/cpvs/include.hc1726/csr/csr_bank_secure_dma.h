#ifndef CSR_BANK_SECURE_DMA_H_
#define CSR_BANK_SECURE_DMA_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from secure_dma  ***/
typedef struct csr_bank_secure_dma {
	/* DMAR_BRCT 10'h000 */
	union {
		uint32_t dmar_brct; // word name
		struct {
			uint32_t dmar_broadcast_to_dmaw : 1;
			uint32_t : 7; // padding bits
			uint32_t dmar_broadcast_to_aes : 1;
			uint32_t : 7; // padding bits
			uint32_t dmar_broadcast_to_lli : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMAW_MUX 10'h004 */
	union {
		uint32_t dmaw_mux; // word name
		struct {
			uint32_t dmaw_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMAR_BRCT_NOT_SEL 10'h008 */
	union {
		uint32_t dmar_brct_not_sel; // word name
		struct {
			uint32_t dmar_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMAW_MUX_NOT_SEL 10'h00C */
	union {
		uint32_t dmaw_mux_not_sel; // word name
		struct {
			uint32_t dmaw_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DMA_DEBUG_MON 10'h010 */
	union {
		uint32_t dma_debug_mon; // word name
		struct {
			uint32_t dma_debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DEBUG_AXI_R_STATUS_0 10'h014 */
	union {
		uint32_t debug_axi_r_status_0; // word name
		struct {
			uint32_t debug_arsize : 3;
			uint32_t : 5; // padding bits
			uint32_t debug_arlen : 4;
			uint32_t : 4; // padding bits
			uint32_t debug_araddr_bank : 3;
			uint32_t : 5; // padding bits
			uint32_t debug_araddr_word : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DEBUG_AXI_R_STATUS_1 10'h018 */
	union {
		uint32_t debug_axi_r_status_1; // word name
		struct {
			uint32_t debug_araddr_row : 16;
			uint32_t debug_araddr_col : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* DEBUG_AXI_R_STATUS_2 10'h01C */
	union {
		uint32_t debug_axi_r_status_2; // word name
		struct {
			uint32_t debug_rdata_b31_0 : 32;
		};
	};
	/* DEBUG_AXI_R_STATUS_3 10'h020 */
	union {
		uint32_t debug_axi_r_status_3; // word name
		struct {
			uint32_t debug_rdata_b63_32 : 32;
		};
	};
	/* DEBUG_AXI_W_STATUS_0 10'h024 */
	union {
		uint32_t debug_axi_w_status_0; // word name
		struct {
			uint32_t debug_awsize : 3;
			uint32_t : 5; // padding bits
			uint32_t debug_awlen : 4;
			uint32_t : 4; // padding bits
			uint32_t debug_awaddr_bank : 3;
			uint32_t : 5; // padding bits
			uint32_t debug_awaddr_word : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* DEBUG_AXI_W_STATUS_1 10'h028 */
	union {
		uint32_t debug_axi_w_status_1; // word name
		struct {
			uint32_t debug_awaddr_row : 16;
			uint32_t debug_awaddr_col : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* DEBUG_AXI_W_STATUS_2 10'h02C */
	union {
		uint32_t debug_axi_w_status_2; // word name
		struct {
			uint32_t debug_wdata_b31_0 : 32;
		};
	};
	/* DEBUG_AXI_W_STATUS_3 10'h030 */
	union {
		uint32_t debug_axi_w_status_3; // word name
		struct {
			uint32_t debug_wdata_b63_32 : 32;
		};
	};
	/* RESV 10'h034 */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* DMA_8_14 10'h038 [Unused] */
	uint32_t empty_word_dma_8_14;
	/* DMA_8_15 10'h03C [Unused] */
	uint32_t empty_word_dma_8_15;
	/* DMA_8_16 10'h040 [Unused] */
	uint32_t empty_word_dma_8_16;
	/* DMA_8_17 10'h044 [Unused] */
	uint32_t empty_word_dma_8_17;
	/* DMA_8_18 10'h048 [Unused] */
	uint32_t empty_word_dma_8_18;
	/* DMA_8_19 10'h04C [Unused] */
	uint32_t empty_word_dma_8_19;
	/* DMA_8_20 10'h050 [Unused] */
	uint32_t empty_word_dma_8_20;
	/* DMA_8_21 10'h054 [Unused] */
	uint32_t empty_word_dma_8_21;
	/* DMA_8_22 10'h058 [Unused] */
	uint32_t empty_word_dma_8_22;
	/* DMA_8_23 10'h05C [Unused] */
	uint32_t empty_word_dma_8_23;
	/* DMA_8_24 10'h060 [Unused] */
	uint32_t empty_word_dma_8_24;
	/* DMA_8_25 10'h064 [Unused] */
	uint32_t empty_word_dma_8_25;
	/* DMA_8_26 10'h068 [Unused] */
	uint32_t empty_word_dma_8_26;
	/* DMA_8_27 10'h06C [Unused] */
	uint32_t empty_word_dma_8_27;
	/* DMA_8_28 10'h070 [Unused] */
	uint32_t empty_word_dma_8_28;
	/* DMA_8_29 10'h074 [Unused] */
	uint32_t empty_word_dma_8_29;
	/* DMA_8_30 10'h078 [Unused] */
	uint32_t empty_word_dma_8_30;
	/* DMA_8_31 10'h07C [Unused] */
	uint32_t empty_word_dma_8_31;
	/* DMA_8_32 10'h080 [Unused] */
	uint32_t empty_word_dma_8_32;
	/* DMA_8_33 10'h084 [Unused] */
	uint32_t empty_word_dma_8_33;
	/* DMA_8_34 10'h088 [Unused] */
	uint32_t empty_word_dma_8_34;
	/* DMA_8_35 10'h08C [Unused] */
	uint32_t empty_word_dma_8_35;
	/* DMA_8_36 10'h090 [Unused] */
	uint32_t empty_word_dma_8_36;
	/* DMA_8_37 10'h094 [Unused] */
	uint32_t empty_word_dma_8_37;
	/* DMA_8_38 10'h098 [Unused] */
	uint32_t empty_word_dma_8_38;
	/* DMA_8_39 10'h09C [Unused] */
	uint32_t empty_word_dma_8_39;
	/* DMA_8_40 10'h0A0 [Unused] */
	uint32_t empty_word_dma_8_40;
} CsrBankSecure_dma;

#endif