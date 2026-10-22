#ifndef CSR_BANK_ISP_H_
#define CSR_BANK_ISP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isp  ***/
typedef struct csr_bank_isp {
	/* ISPBR_BROADCAST0 8'h000 [Unused] */
	uint32_t empty_word_ispbr_broadcast0;
	/* ISPBR_BROADCAST1 8'h004 [Unused] */
	uint32_t empty_word_ispbr_broadcast1;
	/* ISPR_BROADCAST0 8'h008 [Unused] */
	uint32_t empty_word_ispr_broadcast0;
	/* ISPR0_BROADCAST 8'h00C */
	union {
		uint32_t ispr0_broadcast; // word name
		struct {
			uint32_t ispr0_broadcast_to_pg_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispr0_broadcast_to_gfxmux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispr0_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR1_BROADCAST 8'h010 */
	union {
		uint32_t ispr1_broadcast; // word name
		struct {
			uint32_t ispr1_broadcast_to_pg_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispr1_broadcast_to_gfxmux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispr1_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG0_BROADCAST 8'h014 */
	union {
		uint32_t pg0_broadcast; // word name
		struct {
			uint32_t pg0_broadcast_to_cs_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg0_broadcast_to_gfxmux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg0_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PG1_BROADCAST 8'h018 */
	union {
		uint32_t pg1_broadcast; // word name
		struct {
			uint32_t pg1_broadcast_to_cs_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg1_broadcast_to_gfxmux_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t pg1_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX0_MUX 8'h01C */
	union {
		uint32_t gfx0_mux; // word name
		struct {
			uint32_t gfx0_din_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t gfx0_din_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFX1_MUX 8'h020 */
	union {
		uint32_t gfx1_mux; // word name
		struct {
			uint32_t gfx1_din_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t gfx1_din_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PRD_MODE 8'h024 */
	union {
		uint32_t prd_mode; // word name
		struct {
			uint32_t prd0_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t prd1_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_GFXBLD_BYPASS 8'h028 */
	union {
		uint32_t word_gfxbld_bypass; // word name
		struct {
			uint32_t gfxbld_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFXBLD_IN0_MUX 8'h02C */
	union {
		uint32_t gfxbld_in0_mux; // word name
		struct {
			uint32_t gfxbld_in0_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t gfxbld_in0_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFXBLD_IN1_MUX 8'h030 */
	union {
		uint32_t gfxbld_in1_mux; // word name
		struct {
			uint32_t gfxbld_in1_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t gfxbld_in1_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* GFXBLD_IN1_BROADCAST 8'h034 */
	union {
		uint32_t gfxbld_in1_broadcast; // word name
		struct {
			uint32_t gfxbld1_broadcast_to_gfxbld_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t gfxbld1_broadcast_to_out_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t gfxbld1_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_YC_BROADCAST 8'h038 */
	union {
		uint32_t ispin0_yc_broadcast; // word name
		struct {
			uint32_t ispin0_y_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispin0_c_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispin0_yc_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ISPIN0_Y_BROADCAST 8'h03C */
	union {
		uint32_t word_ispin0_y_broadcast; // word name
		struct {
			uint32_t ispin0_y_broadcast : 7;
			uint32_t : 1; // padding bits
			uint32_t ispin0_y_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ISPIN0_C_BROADCAST 8'h040 */
	union {
		uint32_t word_ispin0_c_broadcast; // word name
		struct {
			uint32_t ispin0_c_broadcast : 5;
			uint32_t : 3; // padding bits
			uint32_t ispin0_c_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_YC_BROADCAST 8'h044 */
	union {
		uint32_t ispin1_yc_broadcast; // word name
		struct {
			uint32_t ispin1_y_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispin1_c_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ispin1_yc_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ISPIN1_Y_BROADCAST 8'h048 */
	union {
		uint32_t word_ispin1_y_broadcast; // word name
		struct {
			uint32_t ispin1_y_broadcast : 7;
			uint32_t : 1; // padding bits
			uint32_t ispin1_y_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ISPIN1_C_BROADCAST 8'h04C */
	union {
		uint32_t word_ispin1_c_broadcast; // word name
		struct {
			uint32_t ispin1_c_broadcast : 5;
			uint32_t : 3; // padding bits
			uint32_t ispin1_c_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_HDR_BYPASS 8'h050 */
	union {
		uint32_t word_hdr_bypass; // word name
		struct {
			uint32_t hdr_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPCHDR_C_MUX 8'h054 */
	union {
		uint32_t dpchdr_c_mux; // word name
		struct {
			uint32_t dpchdr_c_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t dpchdr_c_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DPCHDR_YC_BROADCAST 8'h058 */
	union {
		uint32_t dpchdr_yc_broadcast; // word name
		struct {
			uint32_t dpchdr_y_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dpchdr_c_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dpchdr_yc_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DPCHDR_Y_BROADCAST 8'h05C */
	union {
		uint32_t word_dpchdr_y_broadcast; // word name
		struct {
			uint32_t dpchdr_y_broadcast : 5;
			uint32_t : 3; // padding bits
			uint32_t dpchdr_y_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DPCHDR_C_BROADCAST 8'h060 */
	union {
		uint32_t word_dpchdr_c_broadcast; // word name
		struct {
			uint32_t dpchdr_c_broadcast : 4;
			uint32_t : 4; // padding bits
			uint32_t dpchdr_c_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_MUX 8'h064 */
	union {
		uint32_t rgbp_mux; // word name
		struct {
			uint32_t rgbp_mux_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t rgbp_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_YC_BROADCAST 8'h068 */
	union {
		uint32_t rgbp_yc_broadcast; // word name
		struct {
			uint32_t rgbp_y_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t rgbp_c_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t rgbp_yc_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BUF_UPDATE 8'h06C */
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
	/* RGBP_GMA_MODE 8'h070 */
	union {
		uint32_t rgbp_gma_mode; // word name
		struct {
			uint32_t rgbp_gamma_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGBP_Y_BROADCAST 8'h074 */
	union {
		uint32_t word_rgbp_y_broadcast; // word name
		struct {
			uint32_t rgbp_y_broadcast : 2;
			uint32_t : 6; // padding bits
			uint32_t rgbp_y_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_RGBP_C_BROADCAST 8'h078 */
	union {
		uint32_t word_rgbp_c_broadcast; // word name
		struct {
			uint32_t rgbp_c_broadcast : 2;
			uint32_t : 6; // padding bits
			uint32_t rgbp_c_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_Y_MUX 8'h07C */
	union {
		uint32_t sc_y_mux; // word name
		struct {
			uint32_t sc_y_mux_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t sc_y_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_C_MUX 8'h080 */
	union {
		uint32_t sc_c_mux; // word name
		struct {
			uint32_t sc_c_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t sc_c_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_YC_BROADCAST 8'h084 */
	union {
		uint32_t sc_yc_broadcast; // word name
		struct {
			uint32_t sc_y_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t sc_c_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t sc_yc_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SC_Y_BROADCAST 8'h088 */
	union {
		uint32_t word_sc_y_broadcast; // word name
		struct {
			uint32_t sc_y_broadcast : 3;
			uint32_t : 5; // padding bits
			uint32_t sc_y_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_SC_C_BROADCAST 8'h08C */
	union {
		uint32_t word_sc_c_broadcast; // word name
		struct {
			uint32_t sc_c_broadcast : 3;
			uint32_t : 5; // padding bits
			uint32_t sc_c_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENH_Y_MUX 8'h090 */
	union {
		uint32_t enh_y_mux; // word name
		struct {
			uint32_t enh_y_mux_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t enh_y_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ENH_C_MUX 8'h094 */
	union {
		uint32_t enh_c_mux; // word name
		struct {
			uint32_t enh_c_mux_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t enh_c_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DHZ_YC_BROADCAST 8'h098 */
	union {
		uint32_t dhz_yc_broadcast; // word name
		struct {
			uint32_t dhz_y_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dhz_c_broadcast_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t dhz_yc_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DHZ_Y_BROADCAST 8'h09C */
	union {
		uint32_t word_dhz_y_broadcast; // word name
		struct {
			uint32_t dhz_y_broadcast : 3;
			uint32_t : 5; // padding bits
			uint32_t dhz_y_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_DHZ_C_BROADCAST 8'h0A0 */
	union {
		uint32_t word_dhz_c_broadcast; // word name
		struct {
			uint32_t dhz_c_broadcast : 3;
			uint32_t : 5; // padding bits
			uint32_t dhz_c_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO0_Y_MUX 8'h0A4 */
	union {
		uint32_t fifo0_y_mux; // word name
		struct {
			uint32_t fifo0_y_mux_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t fifo0_y_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO0_C_MUX 8'h0A8 */
	union {
		uint32_t fifo0_c_mux; // word name
		struct {
			uint32_t fifo0_c_mux_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t fifo0_c_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO1_Y_MUX 8'h0AC */
	union {
		uint32_t fifo1_y_mux; // word name
		struct {
			uint32_t fifo1_y_mux_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t fifo1_y_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO1_C_MUX 8'h0B0 */
	union {
		uint32_t fifo1_c_mux; // word name
		struct {
			uint32_t fifo1_c_mux_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t fifo1_c_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO2_Y_MUX 8'h0B4 */
	union {
		uint32_t fifo2_y_mux; // word name
		struct {
			uint32_t fifo2_y_mux_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t fifo2_y_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO2_C_MUX 8'h0B8 */
	union {
		uint32_t fifo2_c_mux; // word name
		struct {
			uint32_t fifo2_c_mux_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t fifo2_c_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_LP_CTRL 8'h0BC */
	union {
		uint32_t mem_lp_ctrl; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_MON_SEL 8'h0C0 */
	union {
		uint32_t dbg_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIsp;

#endif