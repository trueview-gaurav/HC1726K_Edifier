/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_ISP_H_
#define HW_ISP_H_

#include "csr_bank_isp.h"

/* clang-format off */

/***** enum of mux select *****/

typedef enum isp_bld_sel {
	ISP_BLD_SEL_ISPIN0 = 0,
	ISP_BLD_SEL_ISPIN1,
	ISP_BLD_SEL_NONE = 0,
} IspBldSel;

typedef enum isp_hdr1_sel {
	ISP_HDR1_SEL_ISPIN0 = 0,
	ISP_HDR1_SEL_ISPIN1,
	ISP_HDR1_SEL_BLD0,
	ISP_HDR1_SEL_NONE = 0,
} IspHdr1Sel;

typedef enum isp_rgbp_sel {
	ISP_RGBP_SEL_ISPIN0 = 0,
	ISP_RGBP_SEL_ISPIN1,
	ISP_RGBP_SEL_BLD0,
	ISP_RGBP_SEL_HDR0,
	ISP_RGBP_SEL_NONE = 0,
} IspRgbpSel;

typedef enum isp_cus_sel {
	ISP_CUS_SEL_ISPIN0 = 0,
	ISP_CUS_SEL_ISPIN1,
	ISP_CUS_SEL_BLD0,
	ISP_CUS_SEL_NONE = 0,
} IspCusSel;

typedef enum isp_cds_sel {
	ISP_CDS_SEL_RGBP = 0,
	ISP_CDS_SEL_SHP,
	ISP_CDS_SEL_NONE = 0,
} IspCdsSel;

typedef enum isp_nr2d_sel {
	ISP_NR2D_SEL_RGBP = 0,
	ISP_NR2D_SEL_CUS,
	ISP_NR2D_SEL_NONE = 0,
} IspNr2dSel;

typedef enum isp_sc_sel {
	ISP_SC_SEL_ISPIN0 = 0,
	ISP_SC_SEL_ISPIN1,
	ISP_SC_SEL_SHP,
	ISP_SC_SEL_RGBP,
	ISP_SC_SEL_CUS,
	ISP_SC_SEL_NONE = 0,
} IspScSel;

typedef enum isp_fifo_sel {
	ISP_FIFO_SEL_ISPIN0 = 0,
	ISP_FIFO_SEL_ISPIN1,
	ISP_FIFO_SEL_BLD0,
	ISP_FIFO_SEL_HDR0,
	ISP_FIFO_SEL_SC,
	ISP_FIFO_SEL_CDS,
	ISP_FIFO_SEL_NONE = 0,
} IspFifoSel;

typedef enum isp_ispin0_sel {
	ISP_ISPIN0_SEL_CS0 = 0,
	ISP_ISPIN0_SEL_GFX0,
	ISP_ISPIN0_SEL_NONE = 0,
} IspIspin0Sel;

/***** union of broadcast *****/

typedef union isp_ispin0_y_brdcst {
	struct {
		uint32_t to_bld0  : 1;
		uint32_t to_bld1  : 1;
		uint32_t to_hdr0  : 1;
		uint32_t to_hdr1  : 1;
		uint32_t to_rgbp  : 1;
		uint32_t to_cus   : 1;
		uint32_t to_sc    : 1;
		uint32_t to_fifo0 : 1;
		uint32_t to_fifo1 : 1;
		uint32_t to_fifo2 : 1;
		uint32_t : 23; /* padding */
	};
	uint32_t value;
} IspIspin0YBrdcst;

typedef union isp_ispin_c_brdcst {
	struct {
		uint32_t to_bld0  : 1;
		uint32_t to_bld1  : 1;
		uint32_t to_cus   : 1;
		uint32_t to_sc    : 1;
		uint32_t to_fifo0 : 1;
		uint32_t to_fifo1 : 1;
		uint32_t to_fifo2 : 1;
		uint32_t : 26; /* padding */
	};
	uint32_t value;
} IspIspinCBrdcst;

typedef union isp_ispin1_y_brdcst {
	struct {
		uint32_t to_bld0  : 1;
		uint32_t to_bld1  : 1;
		uint32_t to_hdr1  : 1;
		uint32_t to_rgbp  : 1;
		uint32_t to_cus   : 1;
		uint32_t to_sc    : 1;
		uint32_t to_fifo0 : 1;
		uint32_t to_fifo1 : 1;
		uint32_t to_fifo2 : 1;
		uint32_t : 24; /* padding */
	};
	uint32_t value;
} IspIspin1YBrdcst;

typedef union isp_bld_y_brdcst {
	struct {
		uint8_t to_hdr1  : 1;
		uint8_t to_rgbp  : 1;
		uint8_t to_cus   : 1;
		uint8_t to_fifo0 : 1;
		uint8_t to_fifo1 : 1;
		uint8_t to_fifo2 : 1;
		uint8_t : 2; /* padding */
	};
	uint8_t value;
} IspBldYBrdcst;

typedef union isp_bld_c_brdcst {
	struct {
		uint8_t to_cus   : 1;
		uint8_t to_fifo0 : 1;
		uint8_t to_fifo1 : 1;
		uint8_t to_fifo2 : 1;
		uint8_t : 4; /* padding */
	};
	uint8_t value;
} IspBldCBrdcst;

typedef union isp_hdr_y_brdcst {
	struct {
		uint8_t to_rgbp  : 1;
		uint8_t to_fifo0 : 1;
		uint8_t to_fifo1 : 1;
		uint8_t to_fifo2 : 1;
		uint8_t : 4; /* padding */
	};
	uint8_t value;
} IspHdrYBrdcst;

typedef union isp_hdr_c_brdcst {
	struct {
		uint8_t to_fifo0 : 1;
		uint8_t to_fifo1 : 1;
		uint8_t to_fifo2 : 1;
		uint8_t : 5; /* padding */
	};
	uint8_t value;
} IspHdrCBrdcst;

typedef union isp_rgbp_brdcst {
	struct {
		uint8_t to_cds  : 1;
		uint8_t to_nr2d : 1;
		uint8_t to_sc   : 1;
		uint8_t : 5; /* padding */
	};
	uint8_t value;
} IspRgbpBrdcst;

typedef union isp_cus_brdcst {
	struct {
		uint8_t to_nr2d : 1;
		uint8_t to_sc   : 1;
		uint8_t : 6; /* padding */
	};
	uint8_t value;
} IspCusBrdcst;

typedef union isp_cds_brdcst {
	struct {
		uint8_t to_fifo0 : 1;
		uint8_t to_fifo1 : 1;
		uint8_t to_fifo2 : 1;
		uint8_t : 5; /* padding */
	};
	uint8_t value;
} IspCdsBrdcst;

typedef union isp_shp_brdcst {
	struct {
		uint8_t to_cds : 1;
		uint8_t to_sc  : 1;
		uint8_t : 6; /* padding */
	};
	uint8_t value;
} IspShpBrdcst;

typedef union isp_sc_brdcst {
	struct {
		uint8_t to_fifo0 : 1;
		uint8_t to_fifo1 : 1;
		uint8_t to_fifo2 : 1;
		uint8_t : 5; /* padding */
	};
	uint8_t value;
} IspScBrdcst;

typedef union isp_ispr0_brdcst {
	struct {
		uint8_t to_pg0  : 1;
		uint8_t to_gfx0 : 1;
		uint8_t : 6; /* padding */
	};
	uint8_t value;
} IspIspr0Brdcst;

typedef struct isp_path_cfg {
	/*
	 * It is possible to combine Y/C channels for broadcast and mux
	 * select. This makes it easier to configure routing. However, consult
	 * PIC of route synthesizer(RS) and chip designer of ISP before
	 * revising following section.
	 */

	/* mux select */
	IspBldSel    bld0_y_sel;
	IspBldSel    bld0_c_sel;
	IspBldSel    bld1_y_sel;
	IspBldSel    bld1_c_sel;
	IspHdr1Sel   hdr1_sel;
	IspRgbpSel   rgbp_sel;
	IspCusSel    cus_y_sel;
	IspCusSel    cus_c_sel;
	IspCdsSel    cds_y_sel;
	IspCdsSel    cds_c_sel;
	IspNr2dSel   nr2d_y_sel;
	IspNr2dSel   nr2d_c_sel;
	IspScSel     sc_y_sel;
	IspScSel     sc_c_sel;
	IspFifoSel   fifo0_sel;
	IspFifoSel   fifo1_sel;
	IspFifoSel   fifo2_sel;
	IspIspin0Sel ispin0_sel;

	/* broadcast */
	IspIspr0Brdcst   ispr0_brdcst;
	IspIspin0YBrdcst ispin0_y_brdcst;
	IspIspinCBrdcst  ispin0_c_brdcst;
	IspIspin1YBrdcst ispin1_y_brdcst;
	IspIspinCBrdcst  ispin1_c_brdcst;
	IspBldYBrdcst    bld_y_brdcst;
	IspBldCBrdcst    bld_c_brdcst;
	IspHdrYBrdcst    hdr_y_brdcst;
	IspHdrCBrdcst    hdr_c_brdcst;
	IspRgbpBrdcst    rgbp_y_brdcst;
	IspRgbpBrdcst    rgbp_c_brdcst;
	IspCusBrdcst     cus_y_brdcst;
	IspCusBrdcst     cus_c_brdcst;
	IspCdsBrdcst     cds_y_brdcst;
	IspCdsBrdcst     cds_c_brdcst;
	IspShpBrdcst     shp_y_brdcst;
	IspShpBrdcst     shp_c_brdcst;
	IspScBrdcst      sc_y_brdcst;
	IspScBrdcst      sc_c_brdcst;
} IspPathCfg;

void isp_set_path(volatile CsrBankIsp *csr, const IspPathCfg *cfg);

#endif /* HW_ISP_H_ */
