/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_ISP_H_
#define CSR_BANK_ISP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isp  ***/
typedef struct csr_bank_isp {
	/* PRD_MODE 10'h000 */
	union {
		uint32_t prd_mode; // word name
		struct {
			uint32_t prd1_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_MON_SEL 10'h004 */
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
	/* MEM_LP_CTRL 10'h008 */
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
	/* BUF_UPDATE 10'h00C */
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
	/* BLD0_MUX_Y 10'h010 */
	union {
		uint32_t bld0_mux_y; // word name
		struct {
			uint32_t bld0_mux_y_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_MUX_C 10'h014 */
	union {
		uint32_t bld0_mux_c; // word name
		struct {
			uint32_t bld0_mux_c_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD1_MUX_Y 10'h018 */
	union {
		uint32_t bld1_mux_y; // word name
		struct {
			uint32_t bld1_mux_y_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD1_MUX_C 10'h01C */
	union {
		uint32_t bld1_mux_c; // word name
		struct {
			uint32_t bld1_mux_c_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR1_MUX 10'h020 */
	union {
		uint32_t hdr1_mux; // word name
		struct {
			uint32_t hdr1_mux_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_MUX 10'h024 */
	union {
		uint32_t rgbp_mux; // word name
		struct {
			uint32_t rgbp_mux_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_MUX_Y 10'h028 */
	union {
		uint32_t cus_mux_y; // word name
		struct {
			uint32_t cus_mux_y_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_MUX_C 10'h02C */
	union {
		uint32_t cus_mux_c; // word name
		struct {
			uint32_t cus_mux_c_sel_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_MUX_Y 10'h030 */
	union {
		uint32_t cds_mux_y; // word name
		struct {
			uint32_t cds_mux_y_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_MUX_C 10'h034 */
	union {
		uint32_t cds_mux_c; // word name
		struct {
			uint32_t cds_mux_c_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_MUX_Y 10'h038 */
	union {
		uint32_t nr2d_mux_y; // word name
		struct {
			uint32_t nr2d_mux_y_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_MUX_C 10'h03C */
	union {
		uint32_t nr2d_mux_c; // word name
		struct {
			uint32_t nr2d_mux_c_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_MUX_Y 10'h040 */
	union {
		uint32_t sc_mux_y; // word name
		struct {
			uint32_t sc_mux_y_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_MUX_C 10'h044 */
	union {
		uint32_t sc_mux_c; // word name
		struct {
			uint32_t sc_mux_c_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO0_MUX_Y 10'h048 */
	union {
		uint32_t fifo0_mux_y; // word name
		struct {
			uint32_t fifo0_mux_y_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO0_MUX_C 10'h04C */
	union {
		uint32_t fifo0_mux_c; // word name
		struct {
			uint32_t fifo0_mux_c_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO1_MUX_Y 10'h050 */
	union {
		uint32_t fifo1_mux_y; // word name
		struct {
			uint32_t fifo1_mux_y_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO1_MUX_C 10'h054 */
	union {
		uint32_t fifo1_mux_c; // word name
		struct {
			uint32_t fifo1_mux_c_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO2_MUX_Y 10'h058 */
	union {
		uint32_t fifo2_mux_y; // word name
		struct {
			uint32_t fifo2_mux_y_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO2_MUX_C 10'h05C */
	union {
		uint32_t fifo2_mux_c; // word name
		struct {
			uint32_t fifo2_mux_c_sel_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_BC_Y 10'h060 */
	union {
		uint32_t ispin0_bc_y; // word name
		struct {
			uint32_t ispin0_bc_y_enable_buf : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_BC_C 10'h064 */
	union {
		uint32_t ispin0_bc_c; // word name
		struct {
			uint32_t ispin0_bc_c_enable_buf : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_BC_Y 10'h068 */
	union {
		uint32_t ispin1_bc_y; // word name
		struct {
			uint32_t ispin1_bc_y_enable_buf : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_BC_C 10'h06C */
	union {
		uint32_t ispin1_bc_c; // word name
		struct {
			uint32_t ispin1_bc_c_enable_buf : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_BC_Y 10'h070 */
	union {
		uint32_t bld0_bc_y; // word name
		struct {
			uint32_t bld0_bc_y_enable_buf : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_BC_C 10'h074 */
	union {
		uint32_t bld0_bc_c; // word name
		struct {
			uint32_t bld0_bc_c_enable_buf : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR0_BC_Y 10'h078 */
	union {
		uint32_t hdr0_bc_y; // word name
		struct {
			uint32_t hdr0_bc_y_enable_buf : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR0_BC_C 10'h07C */
	union {
		uint32_t hdr0_bc_c; // word name
		struct {
			uint32_t hdr0_bc_c_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_BC_Y 10'h080 */
	union {
		uint32_t rgbp_bc_y; // word name
		struct {
			uint32_t rgbp_bc_y_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_BC_C 10'h084 */
	union {
		uint32_t rgbp_bc_c; // word name
		struct {
			uint32_t rgbp_bc_c_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_BC_Y 10'h088 */
	union {
		uint32_t cus_bc_y; // word name
		struct {
			uint32_t cus_bc_y_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_BC_C 10'h08C */
	union {
		uint32_t cus_bc_c; // word name
		struct {
			uint32_t cus_bc_c_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_BC_Y 10'h090 */
	union {
		uint32_t cds_bc_y; // word name
		struct {
			uint32_t cds_bc_y_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_BC_C 10'h094 */
	union {
		uint32_t cds_bc_c; // word name
		struct {
			uint32_t cds_bc_c_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_BC_Y 10'h098 */
	union {
		uint32_t shp_bc_y; // word name
		struct {
			uint32_t shp_bc_y_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_BC_C 10'h09C */
	union {
		uint32_t shp_bc_c; // word name
		struct {
			uint32_t shp_bc_c_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_BC_Y 10'h0A0 */
	union {
		uint32_t sc_bc_y; // word name
		struct {
			uint32_t sc_bc_y_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_BC_C 10'h0A4 */
	union {
		uint32_t sc_bc_c; // word name
		struct {
			uint32_t sc_bc_c_enable_buf : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_YC_BC 10'h0A8 */
	union {
		uint32_t ispin0_yc_bc; // word name
		struct {
			uint32_t ispin0_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_YC_BC 10'h0AC */
	union {
		uint32_t ispin1_yc_bc; // word name
		struct {
			uint32_t ispin1_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_YC_BC 10'h0B0 */
	union {
		uint32_t bld0_yc_bc; // word name
		struct {
			uint32_t bld0_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR0_YC_BC 10'h0B4 */
	union {
		uint32_t hdr0_yc_bc; // word name
		struct {
			uint32_t hdr0_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_YC_BC 10'h0B8 */
	union {
		uint32_t rgbp_yc_bc; // word name
		struct {
			uint32_t rgbp_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_YC_BC 10'h0BC */
	union {
		uint32_t cus_yc_bc; // word name
		struct {
			uint32_t cus_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_YC_BC 10'h0C0 */
	union {
		uint32_t cds_yc_bc; // word name
		struct {
			uint32_t cds_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_YC_BC 10'h0C4 */
	union {
		uint32_t nr2d_yc_bc; // word name
		struct {
			uint32_t nr2d_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CCM_YC_BC 10'h0C8 */
	union {
		uint32_t ccm_yc_bc; // word name
		struct {
			uint32_t ccm_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PCA_YC_BC 10'h0CC */
	union {
		uint32_t pca_yc_bc; // word name
		struct {
			uint32_t pca_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_YC_BC 10'h0D0 */
	union {
		uint32_t shp_yc_bc; // word name
		struct {
			uint32_t shp_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_YC_BC 10'h0D4 */
	union {
		uint32_t sc_yc_bc; // word name
		struct {
			uint32_t sc_yc_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_MUX_Y_NSEL 10'h0D8 */
	union {
		uint32_t bld0_mux_y_nsel; // word name
		struct {
			uint32_t bld0_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_MUX_C_NSEL 10'h0DC */
	union {
		uint32_t bld0_mux_c_nsel; // word name
		struct {
			uint32_t bld0_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD1_MUX_Y_NSEL 10'h0E0 */
	union {
		uint32_t bld1_mux_y_nsel; // word name
		struct {
			uint32_t bld1_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD1_MUX_C_NSEL 10'h0E4 */
	union {
		uint32_t bld1_mux_c_nsel; // word name
		struct {
			uint32_t bld1_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR1_MUX_NSEL 10'h0E8 */
	union {
		uint32_t hdr1_mux_nsel; // word name
		struct {
			uint32_t hdr1_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_MUX_NSEL 10'h0EC */
	union {
		uint32_t rgbp_mux_nsel; // word name
		struct {
			uint32_t rgbp_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_MUX_Y_NSEL 10'h0F0 */
	union {
		uint32_t cus_mux_y_nsel; // word name
		struct {
			uint32_t cus_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_MUX_C_NSEL 10'h0F4 */
	union {
		uint32_t cus_mux_c_nsel; // word name
		struct {
			uint32_t cus_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_MUX_Y_NSEL 10'h0F8 */
	union {
		uint32_t cds_mux_y_nsel; // word name
		struct {
			uint32_t cds_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_MUX_C_NSEL 10'h0FC */
	union {
		uint32_t cds_mux_c_nsel; // word name
		struct {
			uint32_t cds_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_MUX_Y_NSEL 10'h100 */
	union {
		uint32_t nr2d_mux_y_nsel; // word name
		struct {
			uint32_t nr2d_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_MUX_C_NSEL 10'h104 */
	union {
		uint32_t nr2d_mux_c_nsel; // word name
		struct {
			uint32_t nr2d_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_MUX_Y_NSEL 10'h108 */
	union {
		uint32_t sc_mux_y_nsel; // word name
		struct {
			uint32_t sc_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_MUX_C_NSEL 10'h10C */
	union {
		uint32_t sc_mux_c_nsel; // word name
		struct {
			uint32_t sc_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO0_MUX_Y_NSEL 10'h110 */
	union {
		uint32_t fifo0_mux_y_nsel; // word name
		struct {
			uint32_t fifo0_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO0_MUX_C_NSEL 10'h114 */
	union {
		uint32_t fifo0_mux_c_nsel; // word name
		struct {
			uint32_t fifo0_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO1_MUX_Y_NSEL 10'h118 */
	union {
		uint32_t fifo1_mux_y_nsel; // word name
		struct {
			uint32_t fifo1_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO1_MUX_C_NSEL 10'h11C */
	union {
		uint32_t fifo1_mux_c_nsel; // word name
		struct {
			uint32_t fifo1_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO2_MUX_Y_NSEL 10'h120 */
	union {
		uint32_t fifo2_mux_y_nsel; // word name
		struct {
			uint32_t fifo2_mux_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FIFO2_MUX_C_NSEL 10'h124 */
	union {
		uint32_t fifo2_mux_c_nsel; // word name
		struct {
			uint32_t fifo2_mux_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_BC_Y_NSEL 10'h128 */
	union {
		uint32_t ispin0_bc_y_nsel; // word name
		struct {
			uint32_t ispin0_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_BC_C_NSEL 10'h12C */
	union {
		uint32_t ispin0_bc_c_nsel; // word name
		struct {
			uint32_t ispin0_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_BC_Y_NSEL 10'h130 */
	union {
		uint32_t ispin1_bc_y_nsel; // word name
		struct {
			uint32_t ispin1_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_BC_C_NSEL 10'h134 */
	union {
		uint32_t ispin1_bc_c_nsel; // word name
		struct {
			uint32_t ispin1_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_BC_Y_NSEL 10'h138 */
	union {
		uint32_t bld0_bc_y_nsel; // word name
		struct {
			uint32_t bld0_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_BC_C_NSEL 10'h13C */
	union {
		uint32_t bld0_bc_c_nsel; // word name
		struct {
			uint32_t bld0_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR0_BC_Y_NSEL 10'h140 */
	union {
		uint32_t hdr0_bc_y_nsel; // word name
		struct {
			uint32_t hdr0_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR0_BC_C_NSEL 10'h144 */
	union {
		uint32_t hdr0_bc_c_nsel; // word name
		struct {
			uint32_t hdr0_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_BC_Y_NSEL 10'h148 */
	union {
		uint32_t rgbp_bc_y_nsel; // word name
		struct {
			uint32_t rgbp_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_BC_C_NSEL 10'h14C */
	union {
		uint32_t rgbp_bc_c_nsel; // word name
		struct {
			uint32_t rgbp_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_BC_Y_NSEL 10'h150 */
	union {
		uint32_t cus_bc_y_nsel; // word name
		struct {
			uint32_t cus_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_BC_C_NSEL 10'h154 */
	union {
		uint32_t cus_bc_c_nsel; // word name
		struct {
			uint32_t cus_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_BC_Y_NSEL 10'h158 */
	union {
		uint32_t cds_bc_y_nsel; // word name
		struct {
			uint32_t cds_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_BC_C_NSEL 10'h15C */
	union {
		uint32_t cds_bc_c_nsel; // word name
		struct {
			uint32_t cds_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_BC_Y_NSEL 10'h160 */
	union {
		uint32_t shp_bc_y_nsel; // word name
		struct {
			uint32_t shp_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_BC_C_NSEL 10'h164 */
	union {
		uint32_t shp_bc_c_nsel; // word name
		struct {
			uint32_t shp_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_BC_Y_NSEL 10'h168 */
	union {
		uint32_t sc_bc_y_nsel; // word name
		struct {
			uint32_t sc_bc_y_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_BC_C_NSEL 10'h16C */
	union {
		uint32_t sc_bc_c_nsel; // word name
		struct {
			uint32_t sc_bc_c_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_YC_BC_NSEL 10'h170 */
	union {
		uint32_t ispin0_yc_bc_nsel; // word name
		struct {
			uint32_t ispin0_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN1_YC_BC_NSEL 10'h174 */
	union {
		uint32_t ispin1_yc_bc_nsel; // word name
		struct {
			uint32_t ispin1_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BLD0_YC_BC_NSEL 10'h178 */
	union {
		uint32_t bld0_yc_bc_nsel; // word name
		struct {
			uint32_t bld0_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HDR0_YC_BC_NSEL 10'h17C */
	union {
		uint32_t hdr0_yc_bc_nsel; // word name
		struct {
			uint32_t hdr0_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RGBP_YC_BC_NSEL 10'h180 */
	union {
		uint32_t rgbp_yc_bc_nsel; // word name
		struct {
			uint32_t rgbp_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CUS_YC_BC_NSEL 10'h184 */
	union {
		uint32_t cus_yc_bc_nsel; // word name
		struct {
			uint32_t cus_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CDS_YC_BC_NSEL 10'h188 */
	union {
		uint32_t cds_yc_bc_nsel; // word name
		struct {
			uint32_t cds_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* NR2D_YC_BC_NSEL 10'h18C */
	union {
		uint32_t nr2d_yc_bc_nsel; // word name
		struct {
			uint32_t nr2d_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CCM_YC_BC_NSEL 10'h190 */
	union {
		uint32_t ccm_yc_bc_nsel; // word name
		struct {
			uint32_t ccm_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PCA_YC_BC_NSEL 10'h194 */
	union {
		uint32_t pca_yc_bc_nsel; // word name
		struct {
			uint32_t pca_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHP_YC_BC_NSEL 10'h198 */
	union {
		uint32_t shp_yc_bc_nsel; // word name
		struct {
			uint32_t shp_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SC_YC_BC_NSEL 10'h19C */
	union {
		uint32_t sc_yc_bc_nsel; // word name
		struct {
			uint32_t sc_yc_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_MUX 10'h1A0 */
	union {
		uint32_t ispin0_mux; // word name
		struct {
			uint32_t ispin0_mux_sel_buf : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_BC 10'h1A4 */
	union {
		uint32_t ispr0_bc; // word name
		struct {
			uint32_t ispr0_bc_enable_buf : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPIN0_MUX_NSEL 10'h1A8 */
	union {
		uint32_t ispin0_mux_nsel; // word name
		struct {
			uint32_t ispin0_mux_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISPR0_BC_NSEL 10'h1AC */
	union {
		uint32_t ispr0_bc_nsel; // word name
		struct {
			uint32_t ispr0_bc_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIsp;

#endif