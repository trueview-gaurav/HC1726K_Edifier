#include "agtx_video.h"
#include "agtx_cpu_time.h"

#include <common.h>
#include <sensor_def.h>

#include "csr_bank_is.h"
#include "csr_bank_is_cfg.h"
#include "csr_bank_frame_time_gen.h"
#include "csr_bank_edp.h"
#include "csr_bank_isk.h"
#include "csr_bank_gma.h"
#include "csr_bank_fpnr.h"
#include "csr_bank_crop.h"
#include "csr_bank_dbc.h"
#include "csr_bank_dcc.h"
#include "csr_bank_lsc.h"
#include "csr_bank_bsp.h"
#include "csr_bank_pxw.h"
#include "is_setting.h"
#if EARLYVIDEO_DEBUG
#include "csr_bank_is_checksum.h"
#include "csr_bank_isk_checksum.h"
#endif

#ifdef CONFIG_EARLYVIDEO
#include "sensor_cal.h"
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
#include "sensor_cal_1.h"
#endif
#endif

extern void is_dbc_set_cfg(volatile CsrBankDbc *csr, const struct is_dbc_cfg *cfg);
extern void is_dcc_set_cfg(volatile CsrBankDcc *csr, const struct is_dcc_cfg *cfg);
extern void is_dcc_set_gain_curve_cfg(volatile CsrBankDcc *csr, const enum cfa_phase phase,
                                      const struct is_dcc_gain_curve_cfg *cfg);
extern void is_initBspHwReg(volatile CsrBankBsp *csr, int width, int height);

extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

#ifdef CONFIG_DUAL_SENSOR_SUPPORT
CbFuncPtr g_irq_cb[2];
#else
CbFuncPtr g_irq_cb[1];
#endif

static void is_set_clk(uint8_t enable)
{
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;

	if (enable == 0) {
		csr->is_cfg->cken_iswroi0 = enable;
		csr->is_cfg->cken_iswroi1 = enable;
		csr->is_cfg->cken_fe0 = enable;
		csr->is_cfg->cken_fe1 = enable;
		csr->is_cfg->cken_ctrl = enable;
		csr->is_cfg->cken_isk0 = enable;
		csr->is_cfg->cken_isk1 = enable;
	} else {
		csr->is_cfg->cken_isk1 = enable;
		csr->is_cfg->cken_isk0 = enable;
		csr->is_cfg->cken_ctrl = enable;
		csr->is_cfg->cken_fe1 = enable;
		csr->is_cfg->cken_fe0 = enable;
		csr->is_cfg->cken_iswroi1 = enable;
		csr->is_cfg->cken_iswroi0 = enable;
	}
}

static void is_reset(void)
{
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;

	/* Workaround for #27397, trigger dram agent before reset */
	csr->iswroi[0]->frame_start = 0x1;
	csr->iswroi[1]->frame_start = 0x1;

	is_set_clk(0);

	csr->is_cfg->lv_rst_iswroi0 = 0x1;
	csr->is_cfg->lv_rst_iswroi1 = 0x1;

	csr->is_cfg->sw_rst_fe0 = 0x1;
	csr->is_cfg->sw_rst_fe1 = 0x1;

	csr->is_cfg->lv_rst_iswroi0 = 0x0;
	csr->is_cfg->lv_rst_iswroi1 = 0x0;

	is_set_clk(1);
}

void is_init_hw(void)
{
	struct is_dcc_gain_curve_cfg dcc_gain_curve_cfg = {
		.x = {
			0, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535,
		},
		.m = {
			8, 8, 8, 8, 8, 8, 8, 8,
		},
		.y = {
			0, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535,
		},
	};
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;
	struct earlyvideo_shm_segment *segment = NULL;
	struct is_param *param = NULL;
	struct is_dbc_cfg *dbc_init_cfg = NULL;
	struct is_dcc_cfg *dcc_init_cfg = NULL;
	int i;

	debug_print("\n");

	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (g_earlyvideo_drvdata.sensor_bmp & BIT(i)) {
			segment = &g_earlyvideo_drvdata.shm_ptr->segments[i];
			param = &g_earlyvideo_drvdata.is_param[i];
			if (i == 0) {
				dbc_init_cfg = &dbc_init_cfg_0;
				dcc_init_cfg = &dcc_init_cfg_0;
				csr->is->pwe0_mode = (param->bit_depth <= 10) ? 1 : 0;
			}
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
			if (i == 1) {
				dbc_init_cfg = &dbc_init_cfg_1;
				dcc_init_cfg = &dcc_init_cfg_1;
				csr->is->pwe1_mode = (param->bit_depth <= 10) ? 1 : 0;
			}
#endif
			csr->frame_time_gen[i]->width = segment->width;
			csr->frame_time_gen[i]->height = segment->height;
			csr->frame_time_gen[i]->irq_mask_frame_end = 1;

			csr->edp[i]->width = segment->width;
			csr->edp[i]->height = segment->height;
			csr->edp[i]->mode = 0;
			csr->edp[i]->target = 0;
			csr->edp[i]->irq_mask_frame_end = 1;

			csr->gma[i]->mode = 1;

			csr->fpnr[i]->width = segment->width;
			csr->fpnr[i]->height = segment->height;
			csr->fpnr[i]->mode = 1;
			csr->fpnr[i]->irq_mask_frame_end = 1;

			csr->crop[i]->width = segment->width;
			csr->crop[i]->height = segment->height;
			csr->crop[i]->crop_left = 0;
			csr->crop[i]->crop_right = 0;
			csr->crop[i]->crop_up = 0;
			csr->crop[i]->crop_down = 0;

			csr->dbc[i]->width = segment->width;
			csr->dbc[i]->height = segment->height;
			csr->dbc[i]->cfa_mode = 0;
			csr->dbc[i]->bayer_ini_phase = param->bayer_phase;
			csr->dbc[i]->mode = 0;
			csr->dbc[i]->level_g0 = 0;
			csr->dbc[i]->level_r = 0;
			csr->dbc[i]->level_b = 0;
			csr->dbc[i]->level_g1 = 0;
			csr->dbc[i]->level_s = 0;
			csr->dbc[i]->irq_mask_frame_end = 1;
			is_dbc_set_cfg(csr->dbc[i], dbc_init_cfg);

			csr->dcc[i]->width = segment->width;
			csr->dcc[i]->height = segment->height;
			csr->dcc[i]->cfa_mode = 0;
			csr->dcc[i]->bayer_ini_phase = param->bayer_phase;
			csr->dcc[i]->mode = 1;
			csr->dcc[i]->irq_mask_frame_end = 1;
			is_dcc_set_cfg(csr->dcc[i], dcc_init_cfg);

			is_dcc_set_gain_curve_cfg(csr->dcc[i], CFA_PHASE_G0, &dcc_gain_curve_cfg);
			is_dcc_set_gain_curve_cfg(csr->dcc[i], CFA_PHASE_R, &dcc_gain_curve_cfg);
			is_dcc_set_gain_curve_cfg(csr->dcc[i], CFA_PHASE_B, &dcc_gain_curve_cfg);
			is_dcc_set_gain_curve_cfg(csr->dcc[i], CFA_PHASE_G1, &dcc_gain_curve_cfg);
			is_dcc_set_gain_curve_cfg(csr->dcc[i], CFA_PHASE_S, &dcc_gain_curve_cfg);

			csr->lsc[i]->width = segment->width;
			csr->lsc[i]->height = segment->height;
			csr->lsc[i]->cfa_mode = 0;
			csr->lsc[i]->bayer_ini_phase = param->bayer_phase;
			csr->lsc[i]->mode = 1;
			csr->lsc[i]->irq_mask_frame_end = 1;

			is_initBspHwReg(csr->bsp[i], segment->width, segment->height);
			csr->bsp[i]->cfa_mode = 0;
			csr->bsp[i]->bayer_ini_phase_i = param->bayer_phase;
			csr->bsp[i]->bayer_ini_phase_o = param->bayer_phase;
			csr->bsp[i]->irq_mask_frame_end = 0;

			csr->isk[i]->src01_broadcast = 0x00000000;
			csr->isk[i]->agma_broadcast = 0x00000100;
			csr->isk[i]->fpnr_broadcast = 0x00000100;
			csr->isk[i]->crop_broadcast = 0x00000100;
			csr->isk[i]->bsp_broadcast = 0x00000000;
			csr->isk[i]->fgma_broadcast = 0x00000000;
			csr->isk[i]->bsp_broadcast_ack_not_sel = 1;
			csr->isk[i]->double_buf_update = 1;
		}
	}
	csr->is_cfg->cken_iswroi0 = 0;
	csr->is_cfg->cken_iswroi1 = 0;
	is_init_dram_agent();
	csr->is_cfg->cken_iswroi0 = 1;
	csr->is_cfg->cken_iswroi1 = 1;

	/* Set routes */
	csr->is->word_fe0_edp_mux_sel = 0x00000001;
	csr->is->word_fe1_edp_mux_sel = 0x00000001;
	csr->is->iroute_enable_0 = 0x00020100;
	csr->is->iroute_enable_1 = 0x00001008;
	csr->is->iroute_sel_0 = 0x04070201;
	csr->is->iroute_sel_1 = 0x00000705;
	csr->is->oroute_enable_0 = 0x00000001;
	csr->is->oroute_enable_1 = 0x00000000;
	csr->is->oroute_enable_2 = 0x00000000;
	csr->is->oroute_enable_3 = 0x00000002;
	csr->is->oroute_enable_4 = 0x00000000;
	csr->is->oroute_enable_5 = 0x00000000;
	csr->is->oroute_sel = 0x12120900;
	csr->is->double_buf_update = 1;

	is_reset();
}

static void __set_front_end(uint8_t path)
{
	struct earlyvideo_shm_segment *segment = &g_earlyvideo_drvdata.shm_ptr->segments[path];
	struct is_param *param = &g_earlyvideo_drvdata.is_param[path];
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;

	if ((param->route_bmp & ENABLE_DRAM_ROUTE) && (param->route_bmp & ENABLE_BSP_ROUTE)) {
		csr->edp[path]->height = segment->height * segment->uboot_capture_num;
		csr->frame_time_gen[path]->height = segment->height * segment->uboot_capture_num;
		csr->edp[path]->mode = 1; /* All-frame broadcast */
	} else if (param->route_bmp & ENABLE_DRAM_ROUTE) {
		csr->edp[path]->height = segment->height * segment->uboot_capture_num;
		csr->frame_time_gen[path]->height = segment->height * segment->uboot_capture_num;
		csr->edp[path]->target = 0; /* Target to main path */
	} else if (param->route_bmp & ENABLE_BSP_ROUTE) {
		csr->edp[path]->target = 1; /* Target to sub path */
	}
	csr->edp[path]->double_buf_update = 1;
}

void is_enable_dram_route(uint8_t path)
{
	debug_print("\n");

	if (g_earlyvideo_drvdata.shm_ptr->segments[path].uboot_capture_num != 0) {
		g_earlyvideo_drvdata.is_param[path].route_bmp |= ENABLE_DRAM_ROUTE;
		__set_front_end(path);
	}
}

void is_adjust_kernel_height(uint8_t path, uint8_t *frame_num)
{
	struct earlyvideo_shm_segment *segment = &g_earlyvideo_drvdata.shm_ptr->segments[path];
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;

	if (*frame_num > segment->uboot_capture_num) {
		printf("Attempting to use frame %u for object detection, but only %u frames were captured in U-Boot\n",
		       *frame_num, segment->uboot_capture_num);
		printf("Using frame %u for detection instead\n", segment->uboot_capture_num);
		*frame_num = segment->uboot_capture_num;
	}

	debug_print("\n");

	csr->fpnr[path]->height = segment->height * *frame_num;
	csr->crop[path]->height = segment->height * *frame_num;
	csr->dbc[path]->height = segment->height * *frame_num;
	csr->dcc[path]->height = segment->height * *frame_num;
	csr->lsc[path]->height = segment->height * *frame_num;
	csr->bsp[path]->height = segment->height * *frame_num;
}

void is_enable_bsp_route(uint8_t path)
{
	debug_print("\n");

	g_earlyvideo_drvdata.is_param[path].route_bmp |= ENABLE_BSP_ROUTE;
	__set_front_end(path);
}

void is_trigger_start(uint8_t path)
{
	struct is_param *param = &g_earlyvideo_drvdata.is_param[path];
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;

	debug_print("\n");
	if ((g_earlyvideo_drvdata.sensor_bmp & BIT(path)) == 0) {
		g_earlyvideo_drvdata.shm_ptr->segments[path].uboot_capture_num = 0;
		return;
	}

	if (param->route_bmp & ENABLE_DRAM_ROUTE) {
		csr->iswroi[path]->frame_start = 1;
	}
	if (param->route_bmp & ENABLE_BSP_ROUTE) {
		csr->bsp[path]->frame_start = 1;
		csr->lsc[path]->frame_start = 1;
		csr->dcc[path]->frame_start = 1;
		csr->dbc[path]->frame_start = 1;
		csr->crop[path]->frame_start = 1;
		csr->fpnr[path]->frame_start = 1;
	}
	if (param->route_bmp & ENABLE_DRAM_ROUTE || param->route_bmp & ENABLE_BSP_ROUTE) {
		csr->edp[path]->frame_start = 1;
		csr->frame_time_gen[path]->frame_start = 1;
	}
	if (param->route_bmp & ENABLE_DRAM_ROUTE) {
		printf("[%u]Start capturing %u frames on path %u\n", get_cpu_time(),
		       g_earlyvideo_drvdata.shm_ptr->segments[path].uboot_capture_num, path);
	}
}

void is_set_sensor_data(uint8_t path, uint32_t fps, uint32_t exp, uint32_t gain)
{
	struct earlyvideo_shm_segment *segment = &g_earlyvideo_drvdata.shm_ptr->segments[path];

	segment->fps = fps;
	segment->exps_time_us = exp;
	segment->gain32 = gain;
}

static void is_irq_handler(uint32_t irq, void *arg)
{
	struct earlyvideo_drvdata *drvdata = &g_earlyvideo_drvdata;
	struct is_csr *csr = &drvdata->is_csr;
	int path = 0;

	switch (irq) {
	case IRQ_BSP_0:
		path = 0;
		break;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	case IRQ_BSP_1:
		path = 1;
		break;
#endif
	default:
		printf("[%s]: unexpected IRQ: %d\n", __func__, irq);
		break;
	}

	/* Disable BSP route */
	csr->edp[path]->mode = 0; /* All-frame to target */
	csr->edp[path]->target = 0; /* Target to main path */
	csr->edp[path]->double_buf_update = 1;
	g_earlyvideo_drvdata.is_param[path].route_bmp &= ~ENABLE_BSP_ROUTE;

	csr->bsp[path]->irq_clear_frame_end = 1;

	if (g_irq_cb[path]) {
		(*g_irq_cb[path])(path);
	}
}

void is_install_irq_handler(void)
{
	int i;
	int irqs[] = { IRQ_BSP_0,
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
		       IRQ_BSP_1
#endif
	};

	for (i = 0; i < ARRAY_SIZE(irqs); i++) {
		int ret = uboot_irq_install_handler(irqs[i], is_irq_handler, NULL);
		if (ret) {
			printf("Failed to install %d IRQ handler, ret: %d\n", irqs[i], ret);
		}
	}
}

void is_set_irq_cb(uint8_t path, CbFuncPtr cb)
{
	g_irq_cb[path] = cb;
}

#if EARLYVIDEO_DEBUG
void is_poll_da(uint8_t path)
{
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;
	uint16_t frame_height = g_earlyvideo_drvdata.shm_ptr->segments[path].height;
	uint16_t wait_cnt = (frame_height == 0) ? 1 : csr->iswroi[path]->height / frame_height;
	uint32_t fps = g_earlyvideo_drvdata.shm_ptr->segments[path].fps;
	uint64_t start_ticks = get_ticks();
	uint64_t max_wait_ticks = (fps > 0) ? (wait_cnt * SEC_TO_TICKS / fps + 1) : (2 * SEC_TO_TICKS);

	debug_print("\n");

	while ((g_earlyvideo_drvdata.sensor_bmp & BIT(path)) && (csr->iswroi[path]->status_frame_end == 0)) {
		/* Do nothing */
		if ((get_ticks() - start_ticks) > max_wait_ticks) {
			printf("Failed to poll the frame end of path %u\n", path);
			g_earlyvideo_drvdata.sensor_bmp &= ~BIT(path);

			is_show_checksum();

			printf("frame_time_gen0.width = %d\n", csr->frame_time_gen[0]->width);
			printf("frame_time_gen0.height = %d\n\n", csr->frame_time_gen[0]->height);

			printf("edp0.width = %d\n", csr->edp[0]->width);
			printf("edp0.height = %d\n", csr->edp[0]->height);
			printf("edp0.mode = %d\n", csr->edp[0]->mode);
			printf("edp0.target = %d\n", csr->edp[0]->target);
			printf("edp0.broadcast_ack_not_sel = %d\n", csr->edp[0]->broadcast_ack_not_sel);

			printf("iswroi0.width = %d\n", csr->iswroi[0]->width);
			printf("iswroi0.height = %d\n\n", csr->iswroi[0]->height);
			printf("iswroi0.h_end = %d\n", csr->iswroi[0]->h_end);
			printf("iswroi0.v_end = %d\n", csr->iswroi[0]->v_end);
			printf("iswroi0.pixel_flush_len = %d\n", csr->iswroi[0]->pixel_flush_len);
			printf("iswroi0.fifo_flush_len  = %d\n", csr->iswroi[0]->fifo_flush_len);
			printf("iswroi0.fifo_end_phase = %d\n", csr->iswroi[0]->fifo_end_phase);
			printf("iswroi0.msb_only = %d\n", csr->iswroi[0]->msb_only);
			printf("iswroi0.isw->ini_addr_linear_0 = 0x%08x\n", csr->iswroi[0]->ini_addr_linear_0);

			break;
		}
	}
	csr->iswroi[path]->irq_clear_frame_end = 1;
	printf("poll da path %u success\n\n", path);

	printf("frame_time_gen0.width = %d\n", csr->frame_time_gen[0]->width);
	printf("frame_time_gen0.height = %d\n\n", csr->frame_time_gen[0]->height);

	printf("edp0.width = %d\n", csr->edp[0]->width);
	printf("edp0.height = %d\n", csr->edp[0]->height);
	printf("edp0.mode = %d\n", csr->edp[0]->mode);
	printf("edp0.target = %d\n", csr->edp[0]->target);
	printf("edp0.broadcast_ack_not_sel = %d\n", csr->edp[0]->broadcast_ack_not_sel);

	printf("iswroi0.width = %d\n", csr->iswroi[0]->width);
	printf("iswroi0.height = %d\n\n", csr->iswroi[0]->height);
	printf("iswroi0.h_end = %d\n", csr->iswroi[0]->h_end);
	printf("iswroi0.v_end = %d\n", csr->iswroi[0]->v_end);
	printf("iswroi0.pixel_flush_len = %d\n", csr->iswroi[0]->pixel_flush_len);
	printf("iswroi0.fifo_flush_len  = %d\n", csr->iswroi[0]->fifo_flush_len);
	printf("iswroi0.fifo_end_phase = %d\n", csr->iswroi[0]->fifo_end_phase);
	printf("iswroi0.msb_only = %d\n", csr->iswroi[0]->msb_only);
	printf("iswroi0.isw->ini_addr_linear_0 = 0x%08x\n", csr->iswroi[0]->ini_addr_linear_0);
}

void is_show_checksum(void)
{
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;

	printf("\033[93m===== Start dumping IS_SET0.IS_CHECKSUM and ISK0.ISK_CHESKSUM =====\033[0m\n");
	printf("is_set0.is_checksum.checksum_fe0_edp_0: 0x%08X\n", csr->is_checksum->checksum_fe0_edp_0);
	printf("is_set0.is_checksum.checksum_fe0_edp_1: 0x%08X\n", csr->is_checksum->checksum_fe0_edp_1);
	printf("is_set0.is_checksum.checksum_fe1_edp_0: 0x%08X\n", csr->is_checksum->checksum_fe1_edp_0);
	printf("is_set0.is_checksum.checksum_fe1_edp_1: 0x%08X\n", csr->is_checksum->checksum_fe1_edp_1);
	printf("is_set0.is_checksum.checksum_input_route_dst0: 0x%08X\n", csr->is_checksum->checksum_input_route_dst0);
	printf("is_set0.is_checksum.checksum_input_route_dst1: 0x%08X\n", csr->is_checksum->checksum_input_route_dst1);
	printf("is_set0.is_checksum.checksum_input_route_dst2: 0x%08X\n", csr->is_checksum->checksum_input_route_dst2);
	printf("is_set0.is_checksum.checksum_input_route_dst3: 0x%08X\n", csr->is_checksum->checksum_input_route_dst3);
	printf("is_set0.is_checksum.checksum_input_route_dst4: 0x%08X\n", csr->is_checksum->checksum_input_route_dst4);
	printf("is_set0.is_checksum.checksum_input_route_dst5: 0x%08X\n", csr->is_checksum->checksum_input_route_dst5);
	printf("is_set0.is_checksum.checksum_output_route_dst0: 0x%08X\n",
	       csr->is_checksum->checksum_output_route_dst0);
	printf("is_set0.is_checksum.checksum_output_route_dst1: 0x%08X\n",
	       csr->is_checksum->checksum_output_route_dst1);
	printf("is_set0.is_checksum.checksum_output_route_dst2: 0x%08X\n",
	       csr->is_checksum->checksum_output_route_dst2);
	printf("is_set0.is_checksum.checksum_output_route_dst3: 0x%08X\n",
	       csr->is_checksum->checksum_output_route_dst3);
	printf("is_set0.is_checksum.checksum_pwe0: 0x%08X\n", csr->is_checksum->checksum_pwe0);
	printf("is_set0.is_checksum.checksum_pwe1: 0x%08X\n", csr->is_checksum->checksum_pwe1);
	printf("is_set0.is_checksum.checksum_pwe2: 0x%08X\n", csr->is_checksum->checksum_pwe2);
	printf("is_set0.is_checksum.checksum_pwe3: 0x%08X\n", csr->is_checksum->checksum_pwe3);
	printf("isk0.isk_checksum.checksum_agma: 0x%08X\n", csr->isk_checksum[0]->checksum_agma);
	printf("isk0.isk_checksum.checksum_fpnr: 0x%08X\n", csr->isk_checksum[0]->checksum_fpnr);
	printf("isk0.isk_checksum.checksum_crop: 0x%08X\n", csr->isk_checksum[0]->checksum_crop);
	printf("isk0.isk_checksum.checksum_dbc: 0x%08X\n", csr->isk_checksum[0]->checksum_dbc);
	printf("isk0.isk_checksum.checksum_dcc: 0x%08X\n", csr->isk_checksum[0]->checksum_dcc);
	printf("isk0.isk_checksum.checksum_lsc: 0x%08X\n", csr->isk_checksum[0]->checksum_lsc);
	printf("isk0.isk_checksum.checksum_bsp: 0x%08X\n", csr->isk_checksum[0]->checksum_bsp);
	printf("isk0.isk_checksum.checksum_agma: 0x%08X\n", csr->isk_checksum[1]->checksum_agma);
	printf("isk0.isk_checksum.checksum_fpnr: 0x%08X\n", csr->isk_checksum[1]->checksum_fpnr);
	printf("isk1.isk_checksum.checksum_crop: 0x%08X\n", csr->isk_checksum[1]->checksum_crop);
	printf("isk1.isk_checksum.checksum_dbc: 0x%08X\n", csr->isk_checksum[1]->checksum_dbc);
	printf("isk1.isk_checksum.checksum_dcc: 0x%08X\n", csr->isk_checksum[1]->checksum_dcc);
	printf("isk1.isk_checksum.checksum_lsc: 0x%08X\n", csr->isk_checksum[1]->checksum_lsc);
	printf("isk1.isk_checksum.checksum_bsp: 0x%08X\n\n", csr->isk_checksum[1]->checksum_bsp);
}

void is_print(void)
{
	struct is_csr *csr = &g_earlyvideo_drvdata.is_csr;
	printf("hist roi: %u, %u, %u, %u\n", csr->bsp[0]->y_hist_roi_sx, csr->bsp[0]->y_hist_roi_ex,
	       csr->bsp[0]->y_hist_roi_sy, csr->bsp[0]->y_hist_roi_ey);
	printf("avg roi: %u, %u, %u, %u, %u\n", csr->bsp[0]->roi_0_y_avg_sx, csr->bsp[0]->roi_0_y_avg_ex,
	       csr->bsp[0]->roi_0_y_avg_sy, csr->bsp[0]->roi_0_y_avg_ey, csr->bsp[0]->roi_0_y_avg_pix_num);
}
#endif
