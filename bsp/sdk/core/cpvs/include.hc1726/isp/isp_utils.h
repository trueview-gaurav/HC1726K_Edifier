/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_ISP_UTILS_H_
#define KYOTO_ISP_UTILS_H_

#include "common.h"
#include "da_define.h"

#define _reg(addr) *((volatile uint32_t *)(addr))

#define ISP_NORMAL 0
#define ISP_DISABLE 1
#define ISP_SRAM_EN 1

typedef enum isp_pixel_format_i {
	ISP_PIXEL_FORMAT_I_BAYER = 0,
	ISP_PIXEL_FORMAT_I_CFA22 = 1,
	ISP_PIXEL_FORMAT_I_CFA44 = 2,
	ISP_PIXEL_FORMAT_I_NUM = 3,
} IspPixelFormatI;

#define DHZ_MAX_RGL_NUM (64)
#define DHZ_RGL_ATTR_GAIN_BIT (10)
#define DHZ_RGL_ATTR_GAIN_BIT_MASK (0b11111111110000000000)
#define DHZ_RGL_ATTR_OFFSET_BIT_MASK (0b00000000001111111111)
#define DHZ_RGL_STEP_UNIT (2097152)
#define ENH_BLEND_CURVE_CTRL_POINT_NUM (2)
#define ENH_EDGE_CURVE_CTRL_POINT_NUM (2)
#define ENH_GAIN_CURVE_CTRL_POINT_NUM (6)
#define ENH_LUMA_LUT_ENTRTY_NUM (5)
#define GMA_CURVE_ENTRY_NUM (60)
#define HDR_LTM_RGL_HOR_NUM (8)
#define HDR_LTM_RGL_VER_NUM (8)
#define HDR_LTM_RGL_NUM (HDR_LTM_RGL_HOR_NUM * HDR_LTM_RGL_VER_NUM)
#define HDR_LTM_CURVE_ENTRY_NUM (257)
#define HDR_AWB_CHN_NUM (4)
#define HDR_HIST_ENTRY_NUM (60)
#define HDR_RGL_HIST_ENTRY_NUM (3840)
#define PCA_EEE_WORD_NUM (490)
#define PCA_EOE_WORD_NUM (420)
#define PCA_OEE_WORD_NUM (490)
#define PCA_OOE_WORD_NUM (420)
#define PCA_EEO_WORD_NUM (392)
#define PCA_EOO_WORD_NUM (336)
#define PCA_OEO_WORD_NUM (392)
#define PCA_OOO_WORD_NUM (336)
#define PCA_CTRL_POINTS_NUM_L (9)
#define PCA_CTRL_POINTS_NUM_S (13)
#define PCA_CTRL_POINTS_NUM_H (28)
#define SHP_LEVEL_GAIN_ROI_NUM (4)
#define SHP_GAIN_CURVE_CTRL_POINT_NUM (10)
#define SHP_LUMA_CTRL_GAIN_CTRL_POINT_NUM (11)
#define SHP_MAX_RGL_NUM (64)
#define SHP_RGL_STAT_LUMA_MIN_BIT (10)
#define SHP_RGL_STAT_LUMA_MIN_BIT_MASK (0b11111111110000000000)
#define SHP_RGL_STAT_LUMA_AVG_BIT_MASK (0b00000000001111111111)
#define DST_AFF_MAX_NUM (2)
#define SPH_R_RATIO_ADJ_NUM (31)
#define LDC_CURVE_CTRL_POINT_NUM (9)
#define SRC_PSP_MAX_NUM (2)
#define PG_CB_ENTRY_NUM (9)
#define CCM_CORING_TH_ENTRY_NUM (4)
#define NR2D_LUMA_LUT_ENTRTY_NUM (6)
#define NR2D_CHROMA_CTRL_GAIN_ENTRY_NUM (2)
#define NR2D_EDGE_CONFIDENCE_ENTRY_NUM (2)
#define NR2D_NLM_LUT_ENTRY_NUM (32)
#define NR2D_NLM_LUT_X_LAST_VAL (128)
#define ME_MV_HIST_ENTRY_NUM (32)
#define ME_BEST_SAD_HIST_ENTRY_NUM (33)
#define ME_MV_ROI_STAT_MVX_PADDING_BIT (22)
#define ME_MV_ROI_STAT_MVY_PADDING_BIT (12)
#define ME_MV_ROI_STAT_MVY_BIT_MASK (0b00000000001111111111)
#define ME_MV_ROI_STAT_COUNT_BIT_MASK (0b00000000000000000000111111111111)
#define ME_FG_Y_ENTRY_NUM (33)
#define PTE_CURVE_ENTRY_NUM (33)

typedef RectPoint IspDhzRoi;
typedef RectPoint IspShpRoi;

typedef struct ispvp_frame_ctrl {
	int16_t sy;
	int16_t ey;
	uint32_t pix_cnt;
} IspvpFrameCtrl;

typedef struct ispvp_tile_ctrl {
	int16_t sx;
	int16_t ex;
} IspvpTileCtrl;

void ispvp_calc_roi_frame_ctrl(struct rect_point *roi, struct ispvp_frame_ctrl *cfg);
void ispvp_calc_roi_frame2tile(struct rect_point *roi, struct tile_info *tile, struct ispvp_tile_ctrl *cfg);
void ispvp_clear_frame_ctrl(struct ispvp_frame_ctrl *cfg);
void ispvp_clear_tile_ctrl(struct ispvp_tile_ctrl *cfg);

#ifndef __KERNEL__
void isp_frame_end(int cond, char *name);
void hw_isp_init_setting(uint32_t width, uint32_t height, uint32_t ini_bayer_phase);
void hw_isp_eng_bypass(void);
void hw_isp_unmask_irq_frame_end(void);
void hw_isp_clear_irq(void);
void hw_isp_frame_start(void);
void hw_isp_frame_start_no_enhdhz(void);
void hw_isp_check_frame_end(void);
#endif

#endif /* KYOTO_ISP_UTILS_H_ */
