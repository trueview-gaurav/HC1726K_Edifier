#include "agtx_video.h"

#include <common.h>
#include <sensor_def.h>

#include "csr_bank_senif_ctrl.h"
#include "csr_bank_senif_syscfg.h"
#include "csr_bank_slb.h"
#include "csr_bank_rx.h"
#include "csr_bank_dec.h"
#include "csr_bank_rx_phycfg.h"
#include "csr_bank_rx_ctrl.h"

#define SENIF_MAX_DATA_LANE_NUM (2)
#define SENIF_MAX_MIPI_LANE_NUM (4)

#define SENIF_IRQ_SLB_MASK0_ALL (0x01010101)
#define SENIF_IRQ_SLB_MASK1_ALL (0x00000101)
#define SENIF_IRQ_RX_MASK_ALL (0x001FFFFF)
#define SENIF_IRQ_DEC_MASK_ALL (0x0001FFFF)
#define SLB1_SLB0_DATA_SHIFT_OFFSET (8)

DECLARE_GLOBAL_DATA_PTR;

struct senif_csr {
	volatile struct csr_bank_senif_ctrl *senif_ctrl;
	volatile struct csr_bank_senif_syscfg *senif_syscfg;
	volatile struct csr_bank_slb *slb[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx *lvds_rx;
	volatile struct csr_bank_dec *lvds_dec[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx_phycfg *rx_phycfg;
	volatile struct csr_bank_rx_ctrl *rx_ctrl;
};

struct senif_param {
	uint8_t data_lane_num;
	uint8_t bit_depth;
	uint32_t width;
	uint32_t height;
	uint32_t t_hs_settle_ns;
	uint32_t t_d_term_en_ns;
	uint32_t t_clk_settle_ns;
	uint32_t t_clk_term_en_ns;
};

struct senif_drvdata {
	struct senif_csr csr;
	struct senif_param sensor_param[EARLYVIDEO_MAX_PATH_NUM];
	uint8_t sensor_bmp; /* BIT(0): sensor 0, BIT(1): sensor 1 */
};

static struct senif_drvdata g_senif_drvdata;

static void __rx_phycfg_set_clk_lane(volatile struct csr_bank_rx_phycfg *rx_phycfg, uint8_t lane_idx)
{
	switch (lane_idx) {
	case 0:
		rx_phycfg->ln0_ck_en = 1;
		rx_phycfg->ln0_clk_sel = 1;
		break;
	case 1:
		rx_phycfg->ln1_ck_en = 1;
		rx_phycfg->ln1_clk_sel = 1;
		break;
	case 2:
		rx_phycfg->ln2_ck_en = 1;
		rx_phycfg->ln2_clk_sel = 1;
		break;
	case 3:
		rx_phycfg->ln3_ck_en = 1;
		rx_phycfg->ln3_clk_sel = 1;
		break;
	default:
		break;
	}
}

__attribute__((unused)) static void __rx_phycfg_set_lane_channel(volatile struct csr_bank_rx_phycfg *rx_phycfg,
                                                                 uint8_t lane_idx, uint32_t channel)
{
	switch (lane_idx) {
	case 0:
		rx_phycfg->ln0_ch_sel = channel & 0x01;
		break;
	case 1:
		rx_phycfg->ln1_ch_sel = channel & 0x01;
		break;
	case 2:
		rx_phycfg->ln2_ch_sel = channel & 0x01;
		break;
	case 3:
		rx_phycfg->ln3_ch_sel = channel & 0x01;
		break;
	default:
		break;
	}
}

void senif_init_drvdata(void)
{
	struct senif_csr *csr = &g_senif_drvdata.csr;
	struct senif_param *param = NULL;
	struct earlyvideo_shm_info *shm_info = (struct earlyvideo_shm_info *)gd->fb_base;

	/* Initialize csr address */
	csr->senif_ctrl = (void *)0x83570400;
	csr->senif_syscfg = (void *)0x83570000;
	csr->slb[0] = (void *)0x83550000;
	csr->slb[1] = (void *)0x83560000;
	csr->lvds_rx = (void *)0x83520000;
	csr->lvds_dec[0] = (void *)0x83520400;
	csr->lvds_dec[1] = (void *)0x83530000;
	csr->rx_phycfg = (void *)0x83500000;
	csr->rx_ctrl = (void *)0x83500400;

	/* Initialize the sensor bitmap and parameters */
	g_senif_drvdata.sensor_bmp = 0;
#ifdef _SENSOR_DEF_0_H_
	if (shm_info->segments[0].pool_size) {
		g_senif_drvdata.sensor_bmp |= BIT(0);
	}
	param = &g_senif_drvdata.sensor_param[0];

	param->data_lane_num = LVDS_DATA_NUM_0;
	param->width = SENSOR_WIDTH_0;
	param->height = SENSOR_HEIGHT_0;
	param->bit_depth = SENSOR_BIT_DEPTH_0;
	param->t_hs_settle_ns = T_HS_SETTLE_NS_0;
	param->t_d_term_en_ns = T_D_TERM_EN_NS_0;
	param->t_clk_settle_ns = T_CLK_SETTLE_NS_0;
	param->t_clk_term_en_ns = T_CLK_TERM_EN_NS_0;
#endif /* _SENSOR_DEF_0_H_ */

#ifdef _SENSOR_DEF_1_H_
	if (shm_info->segments[1].pool_size) {
		g_senif_drvdata.sensor_bmp |= BIT(1);
	}
	param = &g_senif_drvdata.sensor_param[1];

	param->data_lane_num = LVDS_DATA_NUM_1;
	param->width = SENSOR_WIDTH_1;
	param->height = SENSOR_HEIGHT_1;
	param->bit_depth = SENSOR_BIT_DEPTH_1;
	param->t_hs_settle_ns = T_HS_SETTLE_NS_1;
	param->t_d_term_en_ns = T_D_TERM_EN_NS_1;
	param->t_clk_settle_ns = T_CLK_SETTLE_NS_1;
	param->t_clk_term_en_ns = T_CLK_TERM_EN_NS_1;
#endif /* _SENSOR_DEF_1_H_ */
}

void senif_init_hw(void)
{
	volatile struct csr_bank_senif_ctrl *senif_ctrl = g_senif_drvdata.csr.senif_ctrl;
	volatile struct csr_bank_slb *slb = NULL;
	volatile struct csr_bank_rx *lvds_rx = g_senif_drvdata.csr.lvds_rx;
	volatile struct csr_bank_dec *lvds_dec = NULL;
	volatile struct csr_bank_rx_phycfg *rx_phycfg = g_senif_drvdata.csr.rx_phycfg;
	volatile struct csr_bank_rx_ctrl *rx_ctrl = g_senif_drvdata.csr.rx_ctrl;
	struct senif_param *param = NULL;
	uint8_t data_shift = 0;
	uint8_t word_size = 0;
	int i;

	/* Reset */
#if 0
	senif_syscfg->lv_rst_rx0_senif = 1;
	senif_syscfg->lv_rst_dec0_senif = 1;
	senif_syscfg->lv_rst_dec0_out = 1;
	senif_syscfg->lv_rst_slb0_out = 1;
	senif_syscfg->lv_rst_dec1_senif = 1;
	senif_syscfg->lv_rst_dec1_out = 1;
	senif_syscfg->lv_rst_slb1_out = 1;

	senif_syscfg->lv_rst_slb0_out = 0;
	senif_syscfg->lv_rst_dec0_out = 0;
	senif_syscfg->lv_rst_dec0_senif = 0;
	senif_syscfg->lv_rst_slb1_out = 0;
	senif_syscfg->lv_rst_dec1_out = 0;
	senif_syscfg->lv_rst_dec1_senif = 0;
	senif_syscfg->lv_rst_rx0_senif = 0;
#endif
	/* SENIF control */
	senif_ctrl->mux0_sel = 0;
	senif_ctrl->mux1_sel = 1;
	senif_ctrl->slb0_data_shift = 0;
	senif_ctrl->slb1_data_shift = 0;

	/* Reset lane configs */
	lvds_rx->main = 0;
	lvds_rx->spec_mipi = 1;
	lvds_rx->swap = 0x200;
	rx_phycfg->ln0_ch_sel = 0;
	rx_phycfg->ln1_ch_sel = 0;
	rx_phycfg->ln2_ch_sel = 0;
	rx_phycfg->ln3_ch_sel = 0;
	rx_phycfg->ln0_clk_sel = 0;
	rx_phycfg->ln1_clk_sel = 0;
	rx_phycfg->ln2_clk_sel = 0;
	rx_phycfg->ln3_clk_sel = 0;

	/* Set default termination setting to 15 for 100Ω impedance, see #92952-11 */
	rx_phycfg->ln0_term_sel = 15;
	rx_phycfg->ln1_term_sel = 15;
	rx_phycfg->ln2_term_sel = 15;
	rx_phycfg->ln3_term_sel = 15;

	rx_phycfg->mipi_rx_ck = 0x11000000;

	/* Set up lane configs */
#ifdef _SENSOR_DEF_0_H_
#ifdef LVDS_CLOCK_LANE_0
	lvds_rx->lane_ck_en |= BIT(LVDS_CLOCK_LANE_0);
	__rx_phycfg_set_clk_lane(rx_phycfg, LVDS_CLOCK_LANE_0);
#endif
#ifdef LVDS_DATA_LANE_0_0
	lvds_rx->lane_en |= BIT(LVDS_DATA_LANE_0_0);
#endif
#ifdef LVDS_DATA_LANE_1_0
	lvds_rx->lane_en |= BIT(LVDS_DATA_LANE_1_0);
#endif
#endif /* _SENSOR_DEF_0_H_ */

#ifdef _SENSOR_DEF_1_H_
#ifdef LVDS_CLOCK_LANE_1
	lvds_rx->lane_ck_en |= BIT(LVDS_CLOCK_LANE_1);
	__rx_phycfg_set_clk_lane(rx_phycfg, LVDS_CLOCK_LANE_1);
	__rx_phycfg_set_lane_channel(rx_phycfg, LVDS_CLOCK_LANE_1, 1);
#endif
#ifdef LVDS_DATA_LANE_0_1
	lvds_rx->lane_en |= BIT(LVDS_DATA_LANE_0_1);
	__rx_phycfg_set_lane_channel(rx_phycfg, LVDS_DATA_LANE_0_1, 1);
#endif
#ifdef LVDS_DATA_LANE_1_1
	lvds_rx->lane_en |= BIT(LVDS_DATA_LANE_1_1);
	__rx_phycfg_set_lane_channel(rx_phycfg, LVDS_DATA_LANE_1_1, 1);
#endif
#endif /* _SENSOR_DEF_1_H_ */

	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (g_senif_drvdata.sensor_bmp & BIT(i)) {
			param = &g_senif_drvdata.sensor_param[i];
			slb = g_senif_drvdata.csr.slb[i];
			lvds_dec = g_senif_drvdata.csr.lvds_dec[i];
			data_shift = 0;

			lvds_dec->irqmsk = SENIF_IRQ_DEC_MASK_ALL;
			lvds_rx->irq_msk = SENIF_IRQ_RX_MASK_ALL;
			slb->irqmsk_0 = SENIF_IRQ_SLB_MASK0_ALL;
			slb->irqmsk_1 = SENIF_IRQ_SLB_MASK1_ALL;

			switch (param->bit_depth) {
			/* 0: 0, 1: 2, 2: 4, 3: 6, 4: 8, 5: 9, 6: 10 */
			case 16:
				data_shift = 0;
				word_size = 6;
				break;
			case 14:
				data_shift = 1;
				word_size = 5;
				break;
			case 12:
				data_shift = 2;
				word_size = 4;
				break;
			case 10:
				data_shift = 3;
				word_size = 3;
				break;
			case 8:
				data_shift = 4;
				word_size = 2;
				break;
			case 7:
				data_shift = 5;
				word_size = 1;
				break;
			case 6:
				data_shift = 6;
				word_size = 0;
				break;
			default:
				BUG();
				break;
			}
			if (i == 0) {
				senif_ctrl->slb0_data_shift = data_shift;
			} else {
				senif_ctrl->slb1_data_shift = data_shift;
			}

			slb->frame_reset = 1;
			slb->lbuf_en = 1;
			slb->comp_en = 0;
			slb->src_width = param->width;
			slb->src_height = param->height;
#ifdef _SENSOR_DEF_0_H_
			if (i == 0) {
				slb->dst_width = EARLY_VIDEO_PATH0_WIDTH;
				slb->dst_height = EARLY_VIDEO_PATH0_HEIGHT;
			}
#endif
#ifdef _SENSOR_DEF_1_H_
			if (i == 1) {
				slb->dst_width = EARLY_VIDEO_PATH1_WIDTH;
				slb->dst_height = EARLY_VIDEO_PATH1_HEIGHT;
			}
#endif

			/* Check if the image need to be cropped */
			if (slb->src_width * slb->src_height > slb->dst_width * slb->dst_height) {
				uint32_t bp_hor = 0;
				uint32_t bp_ver = 0;
				uint32_t fp_hor = 0;
				uint32_t fp_ver = 0;
#ifdef _SENSOR_DEF_0_H_
				if (i == 0) {
					bp_hor = BP_HOR_0;
					bp_ver = BP_VER_0;
					fp_hor = FP_HOR_0;
					fp_ver = FP_VER_0;
				}
#endif
#ifdef _SENSOR_DEF_1_H_
				if (i == 1) {
					bp_hor = BP_HOR_1;
					bp_ver = BP_VER_1;
					fp_hor = FP_HOR_1;
					fp_ver = FP_VER_1;
				}
#endif
				slb->cord_x_left = bp_hor;
				slb->cord_x_right = slb->src_width - fp_hor;
				slb->cord_y_top = bp_ver;
				slb->cord_y_bottom = slb->src_height - fp_ver;
				slb->crop_en = 1;
			} else {
				slb->crop_en = 0;
			}

/*
 * Hardcoded SENIF clock speed for 17x6 series: 222.75MHz
 * 1s / 222.75MHz ≈ 4489ps, 1000 / 4489 ≈ 57 / 256
 */
#define senif_ns_to_cycle(ns) ((ns * 57) >> 8)
			if (param->t_hs_settle_ns > 155 || param->t_hs_settle_ns < 85) {
				if (i == 0) {
					lvds_rx->t_da_settle = 24;
				}
			} else {
				if (i == 0) {
					lvds_rx->t_da_settle =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_hs_settle_ns)) -
					        3;
				} else {
					uint32_t temp_da_settle =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_hs_settle_ns)) -
					        3;
					lvds_rx->t_da_settle = max((uint32_t)lvds_rx->t_da_settle, temp_da_settle);
				}
			}

			if (param->t_d_term_en_ns > 39) {
				if (i == 0) {
					lvds_rx->t_da_term_en = 1;
				}
			} else {
				if (i == 0) {
					lvds_rx->t_da_term_en =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_d_term_en_ns)) -
					        3;
				} else {
					uint32_t temp_da_term_en =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_d_term_en_ns)) -
					        3;
					lvds_rx->t_da_term_en = max((uint32_t)lvds_rx->t_da_term_en, temp_da_term_en);
				}
			}
			lvds_rx->t_da_rst_src = 0;

			if (param->t_clk_settle_ns > 300 || param->t_clk_settle_ns < 95) {
				if (i == 0) {
					lvds_rx->t_ck_settle = 37;
				}
			} else {
				if (i == 0) {
					lvds_rx->t_ck_settle =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_clk_settle_ns)) -
					        3;
				} else {
					uint32_t temp_ck_settle =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_clk_settle_ns)) -
					        3;
					lvds_rx->t_ck_settle = max((uint32_t)lvds_rx->t_ck_settle, temp_ck_settle);
				}
			}

			if (param->t_clk_term_en_ns > 38) {
				if (i == 0) {
					lvds_rx->t_ck_term_en = 1;
				}
			} else {
				if (i == 0) {
					lvds_rx->t_ck_term_en =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_clk_term_en_ns)) -
					        3;
				} else {
					uint32_t temp_ck_term_en =
					        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_clk_term_en_ns)) -
					        3;
					lvds_rx->t_ck_term_en = max((uint32_t)lvds_rx->t_ck_term_en, temp_ck_term_en);
				}
			}
			lvds_rx->t_ck_rst_src = 0;

			lvds_dec->word_num = param->width * param->bit_depth / 8;
			lvds_dec->out0_vc_vld = i ? 0 : 1;
			lvds_dec->out1_vc_vld = i ? 1 : 0;
			lvds_dec->frame_start_sel = i ? 1 : 0;
			lvds_dec->frame_done_sel = i ? 1 : 0;
			lvds_dec->frame_end_sel = i ? 1 : 0;
			lvds_dec->dec_reset = 1;
			lvds_dec->frame_reset = 1;
			lvds_dec->spec_sel = 4;
			lvds_dec->lane_sel = param->data_lane_num - 1;
			lvds_dec->word_size = word_size;
			lvds_dec->msb_first = 0;
			lvds_dec->line_num = param->height;
			lvds_dec->vbp_line_num = 0;
			lvds_dec->vfp_line_num = 0;
			lvds_dec->hbp_word_num = 0;
			lvds_dec->hfp_word_num = 0;
			lvds_dec->width = param->width;
			lvds_dec->height = param->height;

			lvds_dec->irqack = SENIF_IRQ_DEC_MASK_ALL;
			slb->irqack_0 = SENIF_IRQ_SLB_MASK0_ALL;
			slb->irqack_1 = SENIF_IRQ_SLB_MASK1_ALL;
		}
	}

	senif_ctrl->double_buf_update = 1;
	rx_ctrl->ctrl_1 = lvds_rx->lane_en | lvds_rx->lane_ck_en;
}

void senif_trigger_start(void)
{
	int i;

	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (g_senif_drvdata.sensor_bmp & BIT(i)) {
			g_senif_drvdata.csr.slb[i]->enable = 1;
			g_senif_drvdata.csr.lvds_dec[i]->dec_en = 1;
		}
	}
	g_senif_drvdata.csr.lvds_rx->rx_en = 1;
}
