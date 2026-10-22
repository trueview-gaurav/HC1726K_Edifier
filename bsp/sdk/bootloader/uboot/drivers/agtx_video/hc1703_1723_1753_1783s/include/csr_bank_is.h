#ifndef CSR_BANK_IS_H_
#define CSR_BANK_IS_H_

#include <linux/types.h>

/***  C struct generated from is  ***/
typedef struct csr_bank_is {
	/* IRQ_CLEAR 10'h000 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_lp_not_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 10'h004 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_lp_not_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 10'h008 */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_lp_not_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EFUSE_VIO 10'h00C */
	union {
		uint32_t efuse_vio; // word name
		struct {
			uint32_t fe0_efuse_resolution_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t fe0_efuse_data_rate_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_efuse_resolution_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_efuse_data_rate_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_FE0_PRD_MODE 10'h010 */
	union {
		uint32_t word_fe0_prd_mode; // word name
		struct {
			uint32_t fe0_prd_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE0_PRD_BROADCST 10'h014 */
	union {
		uint32_t fe0_prd_broadcst; // word name
		struct {
			uint32_t fe0_prd_broadcast_to_edp_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t fe0_prd_broadcast_to_isr_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FE0_EDP_MUX_SEL 10'h018 */
	union {
		uint32_t word_fe0_edp_mux_sel; // word name
		struct {
			uint32_t fe0_edp_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE0_ACK_NOT_SEL 10'h01C */
	union {
		uint32_t fe0_ack_not_sel; // word name
		struct {
			uint32_t fe0_prd_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t fe0_edp_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FE1_PRD_MODE 10'h020 */
	union {
		uint32_t word_fe1_prd_mode; // word name
		struct {
			uint32_t fe1_prd_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE1_PRD_BROADCST 10'h024 */
	union {
		uint32_t fe1_prd_broadcst; // word name
		struct {
			uint32_t fe1_prd_broadcast_to_edp_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_prd_broadcast_to_isr_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FE1_EDP_MUX_SEL 10'h028 */
	union {
		uint32_t word_fe1_edp_mux_sel; // word name
		struct {
			uint32_t fe1_edp_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE1_ACK_NOT_SEL 10'h02C */
	union {
		uint32_t fe1_ack_not_sel; // word name
		struct {
			uint32_t fe1_prd_broadcast_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_edp_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_ENABLE_0 10'h030 */
	union {
		uint32_t iroute_enable_0; // word name
		struct {
			uint32_t iroute_src_lp_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe0_edp0_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe0_edp1_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe0_isr_broadcast_enable : 6;
			uint32_t : 2; // padding bits
		};
	};
	/* IROUTE_ENABLE_1 10'h034 */
	union {
		uint32_t iroute_enable_1; // word name
		struct {
			uint32_t iroute_src_fe1_edp0_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe1_edp1_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe1_isr_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_SEL_0 10'h038 */
	union {
		uint32_t iroute_sel_0; // word name
		struct {
			uint32_t iroute_dst_bypass_isk0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk0_in0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk0_in1_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_bypass_isk1_sel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* IROUTE_SEL_1 10'h03C */
	union {
		uint32_t iroute_sel_1; // word name
		struct {
			uint32_t iroute_dst_isk1_in0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk1_in1_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_ACK_NOT_SEL_0 10'h040 */
	union {
		uint32_t iroute_ack_not_sel_0; // word name
		struct {
			uint32_t iroute_src_broadcast_ack_not_sel : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_ACK_NOT_SEL_1 10'h044 */
	union {
		uint32_t iroute_ack_not_sel_1; // word name
		struct {
			uint32_t iroute_dst_mux_ack_not_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_CAT0 10'h048 */
	union {
		uint32_t iroute_cat0; // word name
		struct {
			uint32_t iroute_dst_bypass_isk0_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t iroute_dst_isk0_in0_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t iroute_dst_isk0_in1_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t iroute_dst_bypass_isk1_msb_cat : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* IROUTE_CAT1 10'h04C */
	union {
		uint32_t iroute_cat1; // word name
		struct {
			uint32_t iroute_dst_isk1_in0_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t iroute_dst_isk1_in1_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_ENABLE_0 10'h050 */
	union {
		uint32_t oroute_enable_0; // word name
		struct {
			uint32_t oroute_src_bypass_isk0_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_agma_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_crop_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_bsp_broadcast_enable : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_ENABLE_1 10'h054 */
	union {
		uint32_t oroute_enable_1; // word name
		struct {
			uint32_t oroute_src_isk0_fgma_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_fsc_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_cvs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_cs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_ENABLE_2 10'h058 */
	union {
		uint32_t oroute_enable_2; // word name
		struct {
			uint32_t oroute_src_isk0_ink_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_ENABLE_3 10'h05C */
	union {
		uint32_t oroute_enable_3; // word name
		struct {
			uint32_t oroute_src_bypass_isk1_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_agma_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_crop_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_bsp_broadcast_enable : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_ENABLE_4 10'h060 */
	union {
		uint32_t oroute_enable_4; // word name
		struct {
			uint32_t oroute_src_isk1_fgma_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_fsc_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_cvs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_cs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_ENABLE_5 10'h064 */
	union {
		uint32_t oroute_enable_5; // word name
		struct {
			uint32_t oroute_src_isk1_ink_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_SEL 10'h068 */
	union {
		uint32_t oroute_sel; // word name
		struct {
			uint32_t oroute_dst_iswroi0_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t oroute_dst_iswroi1_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t oroute_dst_isw0_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t oroute_dst_isw1_sel : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* OROUTE_CAT 10'h06C */
	union {
		uint32_t oroute_cat; // word name
		struct {
			uint32_t oroute_dst_iswroi0_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t oroute_dst_iswroi1_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t oroute_dst_isw0_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t oroute_dst_isw1_msb_cat : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* OROUTE_ACK_NOT_SEL_0 10'h070 */
	union {
		uint32_t oroute_ack_not_sel_0; // word name
		struct {
			uint32_t oroute_src0_broadcast_ack_not_sel : 9;
			uint32_t : 7; // padding bits
			uint32_t oroute_src1_broadcast_ack_not_sel : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* OROUTE_ACK_NOT_SEL_1 10'h074 */
	union {
		uint32_t oroute_ack_not_sel_1; // word name
		struct {
			uint32_t oroute_dst_mux_ack_not_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHARED_SRAM_FSC 10'h078 */
	union {
		uint32_t shared_sram_fsc; // word name
		struct {
			uint32_t fsc_buf_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHARED_SRAM_CFG 10'h07C */
	union {
		uint32_t shared_sram_cfg; // word name
		struct {
			uint32_t bsp_cvs_cs_sram_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t bsp_cvs_cs_sram_master : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWE_MODE 10'h080 */
	union {
		uint32_t pwe_mode; // word name
		struct {
			uint32_t pwe0_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwe1_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwe2_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwe3_mode : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DBG_MON_SEL 10'h084 */
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
	/* BUF_UPDATE 10'h088 */
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
	/* IS00 10'h08C [Unused] */
	uint32_t empty_word_is00;
	/* IS01 10'h090 [Unused] */
	uint32_t empty_word_is01;
	/* IS02 10'h094 [Unused] */
	uint32_t empty_word_is02;
	/* MEM_LP_CTRL 10'h098 */
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
	/* FE_DBG_MON_SEL 10'h09C */
	union {
		uint32_t fe_dbg_mon_sel; // word name
		struct {
			uint32_t fe0_debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t fe1_debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISK_DBG_MON_SEL 10'h0A0 */
	union {
		uint32_t isk_dbg_mon_sel; // word name
		struct {
			uint32_t isk0_debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t isk1_debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIs;

#endif