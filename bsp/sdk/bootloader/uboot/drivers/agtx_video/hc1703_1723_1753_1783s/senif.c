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

#define SENIF_IRQ_SLB_MASK0_ALL (0x01010101)
#define SENIF_IRQ_SLB_MASK1_ALL (0x00000101)
#define SENIF_IRQ_RX_MASK_ALL (0x001FFFFF)
#define SENIF_IRQ_DEC_MASK_ALL (0x0001FFFF)
#define SLB1_SLB0_DATA_SHIFT_OFFSET (8)

extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

void senif_init_hw(void)
{
	volatile struct csr_bank_senif_ctrl *senif_ctrl = g_earlyvideo_drvdata.senif_csr.senif_ctrl;
	volatile struct csr_bank_senif_syscfg *senif_syscfg = g_earlyvideo_drvdata.senif_csr.senif_syscfg;
	volatile struct csr_bank_slb *slb = NULL;
	volatile struct csr_bank_rx *lvds_rx = NULL;
	volatile struct csr_bank_dec *lvds_dec = NULL;
	volatile struct csr_bank_rx_phycfg *rxphy_phycfg = NULL;
	volatile struct csr_bank_rx_ctrl *rxphy_ctrl = NULL;
	struct senif_param *param = NULL;
	uint32_t swap = 0;
	uint32_t lane_en = 0;
	uint8_t word_size = 0;
	uint8_t offset;
	int i;
	int j;

	/* Reset */
	senif_syscfg->sw_rst_ctrl_sensor_clk = 1;
	senif_syscfg->sw_rst_rx0_senif_clk = 1;
	senif_syscfg->lv_rst_dec0_senif_clk = 1;
	senif_syscfg->lv_rst_dec0_out_clk = 1;
	senif_syscfg->sw_rst_slb0_out_clk = 1;
	senif_syscfg->lv_rst_dec0_senif_clk = 0;
	senif_syscfg->lv_rst_dec0_out_clk = 0;

	senif_syscfg->sw_rst_rx1_senif_clk = 1;
	senif_syscfg->lv_rst_dec1_senif_clk = 1;
	senif_syscfg->lv_rst_dec1_out_clk = 1;
	senif_syscfg->sw_rst_slb1_out_clk = 1;
	senif_syscfg->lv_rst_dec1_senif_clk = 0;
	senif_syscfg->lv_rst_dec1_out_clk = 0;

	/* SENIF control */
	senif_ctrl->mux0_sel = 0;
	senif_ctrl->mux1_sel = 1;
	senif_ctrl->slb_out_data_shift = 0x0000;

	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (g_earlyvideo_drvdata.sensor_bmp & BIT(i)) {
			param = &g_earlyvideo_drvdata.senif_param[i];
			slb = g_earlyvideo_drvdata.senif_csr.slb[i];
			lvds_rx = g_earlyvideo_drvdata.senif_csr.lvds_rx[i];
			lvds_dec = g_earlyvideo_drvdata.senif_csr.lvds_dec[i];
			rxphy_phycfg = g_earlyvideo_drvdata.senif_csr.rxphy_phycfg[i];
			rxphy_ctrl = g_earlyvideo_drvdata.senif_csr.rxphy_ctrl[i];
			offset = i ? SLB1_SLB0_DATA_SHIFT_OFFSET : 0;

			lvds_dec->irqmsk = SENIF_IRQ_DEC_MASK_ALL;
			lvds_rx->irq_msk = SENIF_IRQ_RX_MASK_ALL;
			slb->irqmsk_0 = SENIF_IRQ_SLB_MASK0_ALL;
			slb->irqmsk_1 = SENIF_IRQ_SLB_MASK1_ALL;

			switch (param->bit_depth) {
			/* 0: 0, 1: 2, 2: 4, 3: 6, 4: 8, 5: 9, 6: 10 */
			case 16:
				word_size = 6;
				break;
			case 14:
				senif_ctrl->slb_out_data_shift |= (0x0001 << offset);
				word_size = 5;
				break;
			case 12:
				senif_ctrl->slb_out_data_shift |= (0x0002 << offset);
				word_size = 4;
				break;
			case 10:
				senif_ctrl->slb_out_data_shift |= (0x0003 << offset);
				word_size = 3;
				break;
			case 8:
				senif_ctrl->slb_out_data_shift |= (0x0004 << offset);
				word_size = 2;
				break;
			case 7:
				senif_ctrl->slb_out_data_shift |= (0x0005 << offset);
				word_size = 1;
				break;
			case 6:
				senif_ctrl->slb_out_data_shift |= (0x0006 << offset);
				word_size = 0;
				break;
			default:
				BUG();
				break;
			}

			slb->frame_reset = 1;
			slb->lbuf_en = 1;
			slb->crop_en = 0;
			slb->comp_en = 1;
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

#define senif_ns_to_cycle(ns) (ns * 1000 / 3367) /* FIXME: hardcode 3367ps = 1s / 297MHz */
			if (param->t_hs_settle_ns > 155 || param->t_hs_settle_ns < 85) {
				lvds_rx->t_da_settle = 24;
			} else {
				lvds_rx->t_da_settle =
				        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_hs_settle_ns)) - 3;
			}

			if (param->t_d_term_en_ns > 39) {
				lvds_rx->t_da_term_en = 1;
			} else {
				lvds_rx->t_da_term_en =
				        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_d_term_en_ns)) - 3;
			}
			lvds_rx->t_da_rst_src = 0;

			if (param->t_clk_settle_ns > 300 || param->t_clk_settle_ns < 95) {
				lvds_rx->t_ck_settle = 37;
			} else {
				lvds_rx->t_ck_settle =
				        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_clk_settle_ns)) - 3;
			}

			if (param->t_clk_term_en_ns > 38) {
				lvds_rx->t_ck_term_en = 1;
			} else {
				lvds_rx->t_ck_term_en =
				        max((uint32_t)3, (uint32_t)senif_ns_to_cycle(param->t_clk_term_en_ns)) - 3;
			}
			lvds_rx->t_ck_rst_src = 0;

			for (j = 0; j < EARLYVIDEO_MAX_MIPI_LANE_NUM; j++) {
				if (param->lane_idx[j] < EARLYVIDEO_MAX_MIPI_LANE_NUM) {
					swap |= ((uint32_t)param->lane_idx[j]) << (j * 8);
				}
			}
			lvds_rx->swap = swap;

			for (j = 0; j < param->lane_num; j++) {
				lane_en |= (1 << param->lane_idx[j]);
			}
			lvds_rx->lane_en = lane_en;
			lvds_rx->lane_ck_en = 0x10;
			lvds_rx->spec_mipi = 1;

			rxphy_ctrl->ctrl_1 = lvds_rx->lane_en | lvds_rx->lane_ck_en;

			rxphy_phycfg->mipi_rx_ck = 0x10000;

			lvds_dec->word_num = param->width * param->bit_depth / 8;
			lvds_dec->out0_vc_vld = 1;
			lvds_dec->out1_vc_vld = i ? 1 : 0;
			lvds_dec->dec_reset = 1;
			lvds_dec->frame_reset = 1;
			lvds_dec->spec_sel = 4;
			lvds_dec->lane_sel = param->lane_num - 1;
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
}

void senif_trigger_start(void)
{
	int i;

	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (g_earlyvideo_drvdata.sensor_bmp & BIT(i)) {
			g_earlyvideo_drvdata.senif_csr.slb[i]->enable = 1;
			g_earlyvideo_drvdata.senif_csr.lvds_dec[i]->dec_en = 1;
			g_earlyvideo_drvdata.senif_csr.lvds_rx[i]->rx_en = 1;
		}
	}
}