#include "agtx_video.h"
#include "agtx_cpu_time.h"

#include <common.h>
#include <sensor_def.h>

#include "csr_bank_is.h"
#include "csr_bank_is_cfg.h"
#include "csr_bank_tg.h"
#include "csr_bank_edp.h"
#include "csr_bank_isk.h"
#include "csr_bank_crop.h"
#include "csr_bank_dbc.h"
#include "csr_bank_dcc.h"
#include "csr_bank_lsc.h"
#include "csr_bank_dfk.h"
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

DECLARE_GLOBAL_DATA_PTR;

extern void is_dbc_set_cfg(volatile CsrBankDbc *csr, const struct is_dbc_cfg *cfg);
extern void is_dcc_set_cfg(volatile CsrBankDcc *csr, const struct is_dcc_cfg *cfg);
extern void is_dcc_set_gain_curve_cfg(volatile CsrBankDcc *csr, const enum cfa_phase phase,
                                      const struct is_dcc_gain_curve_cfg *cfg);
extern void is_initBspHwReg(volatile CsrBankBsp *csr, int width, int height);
extern void is_init_dram_agent(struct is_drvdata *drvdata);
extern void is_init_shm_info(struct is_drvdata *drvdata);

struct is_drvdata g_is_drvdata;

void is_init_drvdata(void)
{
	struct is_csr *csr = &g_is_drvdata.csr;
	struct is_param *param = NULL;
	struct earlyvideo_shm_info *shm_info = NULL;

	debug_print("\n");

	/* Initialize csr address */
	csr->is = (void *)0x83000000;
	csr->is_cfg = (void *)0x83000400;
	csr->tg[0] = (void *)0x83020400;
	csr->edp[0] = (void *)0x83020800;
	csr->tg[1] = (void *)0x83030400;
	csr->edp[1] = (void *)0x83030800;
	csr->isk[0] = (void *)0x83100000;
	csr->crop[0] = (void *)0x83118000;
	csr->dbc[0] = (void *)0x83128000;
	csr->dcc[0] = (void *)0x83130000;
	csr->lsc[0] = (void *)0x83138000;
	csr->bsp[0] = (void *)0x83140000;
	csr->dfk[0] = (void *)0x83148000;
	csr->isk[1] = (void *)0x83180000;
	csr->crop[1] = (void *)0x83198000;
	csr->dbc[1] = (void *)0x831A8000;
	csr->dcc[1] = (void *)0x831B0000;
	csr->lsc[1] = (void *)0x831B8000;
	csr->bsp[1] = (void *)0x831C0000;
	csr->dfk[1] = (void *)0x831C8000;
	csr->isw[0] = (void *)0x83060000;
	csr->isw[1] = (void *)0x83070000;
#if EARLYVIDEO_DEBUG
	csr->is_checksum = (void *)0x83000800;
	csr->isk_checksum[0] = (void *)0x83100800;
	csr->isk_checksum[1] = (void *)0x83180800;
#endif

	/* Initialize the sensor bitmap */
	g_is_drvdata.sensor_bmp = 0;

	/* Initialize the sensor parameters */
#ifdef CONFIG_EARLYVIDEO
	g_is_drvdata.sensor_bmp |= BIT(0);
	param = &g_is_drvdata.path_param[0];
	param->route_bmp = 0;
	param->bit_depth = 8; /* FIXME */
	param->bayer_phase = SENSOR_BAYER_PHASE_0;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	g_is_drvdata.sensor_bmp |= BIT(1);
	param = &g_is_drvdata.path_param[1];
	param->route_bmp = 0;
	param->bit_depth = 8; /* FIXME */
	param->bayer_phase = SENSOR_BAYER_PHASE_1;
#endif

	/* Initialize share memory */
	is_init_shm_info(&g_is_drvdata);

	/* Update sensor bitmap according to pool_size */
	shm_info = (struct earlyvideo_shm_info *)gd->fb_base;

	if (shm_info->segments[0].pool_size == 0) {
		g_is_drvdata.sensor_bmp &= ~BIT(0);
	}
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	if (shm_info->segments[1].pool_size == 0) {
		g_is_drvdata.sensor_bmp &= ~BIT(1);
	}
#endif
	printf("sensor bmp: %u\n", g_is_drvdata.sensor_bmp);
#endif
}

static void __set_clk(uint8_t config)
{
	struct is_csr *csr = &g_is_drvdata.csr;

	if (config == 0) { /* Disable */
		csr->is_cfg->cken_isw0_d = config;
		csr->is_cfg->cken_isw0_k = config;
		csr->is_cfg->cken_isw0_ref = config;
		csr->is_cfg->cken_isw0_p_clk_g = config;
		csr->is_cfg->cken_isw1_d = config;
		csr->is_cfg->cken_isw1_k = config;
		csr->is_cfg->cken_isw1_ref = config;
		csr->is_cfg->cken_isw1_p_clk_g = config;
		csr->is_cfg->cken_fe0_k = config;
		csr->is_cfg->cken_fe0_ref = config;
		csr->is_cfg->cken_fe0_p_clk_g = config;
		csr->is_cfg->cken_fe1_k = config;
		csr->is_cfg->cken_fe1_ref = config;
		csr->is_cfg->cken_fe1_p_clk_g = config;
		csr->is_cfg->cken_ctrl_k = config;
		csr->is_cfg->cken_csr_k = config;
		csr->is_cfg->cken_csr_p_clk_g = config;
		csr->is_cfg->cken_isk0_d = config;
		csr->is_cfg->cken_isk0_k = config;
		csr->is_cfg->cken_isk0_p_clk_g = config;
		csr->is_cfg->cken_isk1_d = config;
		csr->is_cfg->cken_isk1_k = config;
		csr->is_cfg->cken_isk1_p_clk_g = config;
		csr->is_cfg->cken_bspshb_k = config;
	} else { /* Enable */
		csr->is_cfg->cken_bspshb_k = config;
		csr->is_cfg->cken_isk1_p_clk_g = config;
		csr->is_cfg->cken_isk1_k = config;
		csr->is_cfg->cken_isk1_d = config;
		csr->is_cfg->cken_isk0_p_clk_g = config;
		csr->is_cfg->cken_isk0_k = config;
		csr->is_cfg->cken_isk0_d = config;
		csr->is_cfg->cken_csr_p_clk_g = config;
		csr->is_cfg->cken_csr_k = config;
		csr->is_cfg->cken_ctrl_k = config;
		csr->is_cfg->cken_fe1_p_clk_g = config;
		csr->is_cfg->cken_fe1_ref = config;
		csr->is_cfg->cken_fe1_k = config;
		csr->is_cfg->cken_fe0_p_clk_g = config;
		csr->is_cfg->cken_fe0_ref = config;
		csr->is_cfg->cken_fe0_k = config;
		csr->is_cfg->cken_isw1_p_clk_g = config;
		csr->is_cfg->cken_isw1_ref = config;
		csr->is_cfg->cken_isw1_k = config;
		csr->is_cfg->cken_isw1_d = config;
		csr->is_cfg->cken_isw0_p_clk_g = config;
		csr->is_cfg->cken_isw0_ref = config;
		csr->is_cfg->cken_isw0_k = config;
		csr->is_cfg->cken_isw0_d = config;
	}
}

static void __reset(void)
{
	struct is_csr *csr = &g_is_drvdata.csr;

	/* Workaround for #27397, trigger dram agent before reset */
	csr->isw[0]->frame_start = 0x1;
	csr->isw[1]->frame_start = 0x1;

	__set_clk(0);

	csr->is_cfg->lv_rst_isw0_d = 1;
	csr->is_cfg->lv_rst_isw0_k = 1;
	csr->is_cfg->lv_rst_isw0_ref = 1;
	csr->is_cfg->lv_rst_isw0_p_clk_g = 1;
	csr->is_cfg->lv_rst_isw1_d = 1;
	csr->is_cfg->lv_rst_isw1_k = 1;
	csr->is_cfg->lv_rst_isw1_ref = 1;
	csr->is_cfg->lv_rst_isw1_p_clk_g = 1;

	csr->is_cfg->lv_rst_fe0_k = 1;
	csr->is_cfg->lv_rst_fe0_ref = 1;
	csr->is_cfg->lv_rst_fe0_p_clk_g = 1;
	csr->is_cfg->lv_rst_fe1_k = 1;
	csr->is_cfg->lv_rst_fe1_ref = 1;
	csr->is_cfg->lv_rst_fe1_p_clk_g = 1;

	csr->is_cfg->lv_rst_fe0_p_clk_g = 0;
	csr->is_cfg->lv_rst_fe0_ref = 0;
	csr->is_cfg->lv_rst_fe0_k = 0;
	csr->is_cfg->lv_rst_fe1_p_clk_g = 0;
	csr->is_cfg->lv_rst_fe1_ref = 0;
	csr->is_cfg->lv_rst_fe1_k = 0;

	csr->is_cfg->lv_rst_isw0_p_clk_g = 0;
	csr->is_cfg->lv_rst_isw0_ref = 0;
	csr->is_cfg->lv_rst_isw0_k = 0;
	csr->is_cfg->lv_rst_isw0_d = 0;
	csr->is_cfg->lv_rst_isw1_p_clk_g = 0;
	csr->is_cfg->lv_rst_isw1_ref = 0;
	csr->is_cfg->lv_rst_isw1_k = 0;
	csr->is_cfg->lv_rst_isw1_d = 0;

	__set_clk(1);
}

void is_init_hw(void)
{
	struct is_dcc_gain_curve_cfg dcc_gain_curve_cfg = {
		.y = {
			0, 256, 512, 768, 1024, 2048, 3072, 4096, 6144, 8192,
			10240, 12288, 16384, 24576, 32768, 49512,
		},
	};
	struct is_csr *csr = &g_is_drvdata.csr;
	struct earlyvideo_shm_segment *segment = NULL;
	struct is_param *param = NULL;
	struct is_dbc_cfg *dbc_init_cfg = NULL;
	struct is_dcc_cfg *dcc_init_cfg = NULL;
	int i;

	debug_print("\n");
	__reset();

	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (g_is_drvdata.sensor_bmp & BIT(i)) {
			segment = &g_is_drvdata.shm_ptr->segments[i];
			param = &g_is_drvdata.path_param[i];
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
			csr->tg[i]->width = segment->width;
			csr->tg[i]->height = segment->height;
			csr->tg[i]->irq_mask_frame_end = 1;

			csr->edp[i]->width = segment->width;
			csr->edp[i]->height = segment->height;
			csr->edp[i]->mode = 0;
			csr->edp[i]->target = 0;
			csr->edp[i]->idle_stall = 1;
			csr->edp[i]->irq_mask_frame_end = 1;

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

			csr->dfk[i]->width = segment->width;
			csr->dfk[i]->height = segment->height;
			csr->dfk[i]->cfa_mode = 0;
			csr->dfk[i]->bayer_ini_phase_i = param->bayer_phase;
			csr->dfk[i]->deflicker_enable = 0;
			csr->dfk[i]->deflicker_bypass = 1;
			csr->dfk[i]->irq_mask_frame_end = 1;

			is_initBspHwReg(csr->bsp[i], segment->width, segment->height);
			csr->bsp[i]->cfa_mode = 0;
			csr->bsp[i]->bayer_ini_phase_i = param->bayer_phase;
			csr->bsp[i]->bayer_ini_phase_o = param->bayer_phase;
			csr->bsp[i]->irq_mask_frame_end = 1;

			csr->isk[i]->src01_broadcast = 0x00000000;
			csr->isk[i]->fpnr_broadcast = 0x00000100;
			csr->isk[i]->crop_broadcast = 0x00000100;
			csr->isk[i]->bsp_broadcast = 0x00000000;
			csr->isk[i]->fgma_broadcast = 0x00000000;
			csr->isk[i]->bsp_broadcast_ack_not_sel = 1;
			csr->isk[i]->double_buf_update = 1;
		}
	}
	csr->is_cfg->cken_isw0_d = 0;
	csr->is_cfg->cken_isw0_k = 0;
	csr->is_cfg->cken_isw0_ref = 0;
	csr->is_cfg->cken_isw1_d = 0;
	csr->is_cfg->cken_isw1_k = 0;
	csr->is_cfg->cken_isw1_ref = 0;
	is_init_dram_agent(&g_is_drvdata);
	csr->is_cfg->cken_isw0_ref = 1;
	csr->is_cfg->cken_isw0_k = 1;
	csr->is_cfg->cken_isw0_d = 1;
	csr->is_cfg->cken_isw1_ref = 1;
	csr->is_cfg->cken_isw1_k = 1;
	csr->is_cfg->cken_isw1_d = 1;

	/* Set routes */
	csr->is->fe0_ctrl = 0x00010001;
	csr->is->fe1_ctrl = 0x00010001;
	csr->is->iroute_enable_0 = 0x00000201;
	csr->is->iroute_enable_1 = 0x00001008;
	csr->is->iroute_sel_0 = 0x00060100;
	csr->is->iroute_sel_1 = 0x00060403;
	csr->is->oroute_enable_0 = 0x00000001;
	csr->is->oroute_enable_1 = 0x00000000;
	csr->is->oroute_enable_2 = 0x00000002;
	csr->is->oroute_enable_3 = 0x00000000;
	csr->is->oroute_sel = 0x0e0e0700;
	csr->is->lpmd_enable = 0x00000001;
	csr->is->double_buf_update = 1;
}

static void __set_front_end(uint8_t path)
{
	struct earlyvideo_shm_segment *segment = &g_is_drvdata.shm_ptr->segments[path];
	struct is_param *param = &g_is_drvdata.path_param[path];
	struct is_csr *csr = &g_is_drvdata.csr;

	if ((param->route_bmp & ENABLE_DRAM_ROUTE) && (param->route_bmp & ENABLE_BSP_ROUTE)) {
		csr->edp[path]->height = segment->height * segment->uboot_capture_num;
		csr->tg[path]->height = segment->height * segment->uboot_capture_num;
		csr->edp[path]->mode = 1; /* All-frame broadcast */
	} else if (param->route_bmp & ENABLE_DRAM_ROUTE) {
		csr->edp[path]->height = segment->height * segment->uboot_capture_num;
		csr->tg[path]->height = segment->height * segment->uboot_capture_num;
		csr->edp[path]->target = 0; /* Target to main path */
	} else if (param->route_bmp & ENABLE_BSP_ROUTE) {
		csr->edp[path]->target = 1; /* Target to sub path */
	}
	csr->edp[path]->double_buf_update = 1;
}

void is_enable_dram_route(uint8_t path)
{
	debug_print("\n");

	if (g_is_drvdata.shm_ptr->segments[path].uboot_capture_num != 0) {
		g_is_drvdata.path_param[path].route_bmp |= ENABLE_DRAM_ROUTE;
		__set_front_end(path);
	}
}

void is_enable_bsp_route(uint8_t path)
{
	debug_print("\n");

	g_is_drvdata.path_param[path].route_bmp |= ENABLE_BSP_ROUTE;
	__set_front_end(path);
}

void is_trigger_start(uint8_t path)
{
	struct is_param *param = &g_is_drvdata.path_param[path];
	struct is_csr *csr = &g_is_drvdata.csr;

	debug_print("\n");
	if ((g_is_drvdata.sensor_bmp & BIT(path)) == 0) {
		g_is_drvdata.shm_ptr->segments[path].uboot_capture_num = 0;
		return;
	}

	if (param->route_bmp & ENABLE_DRAM_ROUTE) {
		csr->isw[path]->frame_start = 1;
	}
	if (param->route_bmp & ENABLE_BSP_ROUTE) {
		csr->bsp[path]->frame_start = 1;
		csr->dfk[path]->frame_start = 1;
		csr->lsc[path]->frame_start = 1;
		csr->dcc[path]->frame_start = 1;
		csr->dbc[path]->frame_start = 1;
		csr->crop[path]->frame_start = 1;
	}
	if (param->route_bmp & ENABLE_DRAM_ROUTE || param->route_bmp & ENABLE_BSP_ROUTE) {
		csr->edp[path]->frame_start = 1;
		csr->tg[path]->frame_start = 1;
	}
	if (param->route_bmp & ENABLE_DRAM_ROUTE) {
		printf("[%u]Start capturing %u frames on path %u\n", get_cpu_time(),
			g_is_drvdata.shm_ptr->segments[path].uboot_capture_num, path);
	}
}

void is_set_sensor_data(uint8_t path, uint32_t fps, uint32_t exp, uint32_t gain)
{
	struct earlyvideo_shm_segment *segment = &g_is_drvdata.shm_ptr->segments[path];

	segment->fps = fps;
	segment->exps_time_us = exp;
	segment->gain32 = gain;
}

#define SEC_TO_TICKS (1000000000ULL)
void is_poll_bsp_path(uint8_t path)
{
	struct is_csr *csr = &g_is_drvdata.csr;
	uint32_t fps = g_is_drvdata.shm_ptr->segments[path].fps;
	uint64_t start_ticks = get_ticks();
	uint64_t max_wait_ticks = (fps > 0) ? (10 * (SEC_TO_TICKS / fps)) : (2 * SEC_TO_TICKS);

	debug_print("\n");

	while ((g_is_drvdata.sensor_bmp & BIT(path)) && (csr->bsp[path]->status_frame_end == 0)) {
		/* Do nothing */
		if ((get_ticks() - start_ticks) > max_wait_ticks) {
			printf("Failed to set up the early software light meter\n");
			g_is_drvdata.sensor_bmp &= ~BIT(path);
#if EARLYVIDEO_DEBUG
			is_show_checksum();
			printf("is_set0.is.fe0_ctrl = 0x%08x\n", csr->is->fe0_ctrl);
			printf("is_set0.is.fe1_ctrl = 0x%08x\n", csr->is->fe1_ctrl);
			printf("is_set0.is.iroute_enable_0 = 0x%08x\n", csr->is->iroute_enable_0);
			printf("is_set0.is.iroute_enable_1 = 0x%08x\n", csr->is->iroute_enable_1);
			printf("is_set0.is.iroute_sel_0 = 0x%08x\n", csr->is->iroute_sel_0);
			printf("is_set0.is.iroute_sel_1 = 0x%08x\n", csr->is->iroute_sel_1);
			printf("is_set0.is.oroute_enable_0 = 0x%08x\n", csr->is->oroute_enable_0);
			printf("is_set0.is.oroute_enable_1 = 0x%08x\n", csr->is->oroute_enable_1);
			printf("is_set0.is.oroute_enable_2 = 0x%08x\n", csr->is->oroute_enable_2);
			printf("is_set0.is.oroute_enable_3 = 0x%08x\n", csr->is->oroute_enable_3);
			printf("is_set0.is.route_sel = 0x%08x\n\n", csr->is->oroute_sel);

			printf("tg0.width = %d\n", csr->tg[0]->width);
			printf("tg0.height = %d\n\n", csr->tg[0]->height);

			printf("edp0.width = %d\n", csr->edp[0]->width);
			printf("edp0.height = %d\n", csr->edp[0]->height);
			printf("edp0.mode = %d\n", csr->edp[0]->mode);
			printf("edp0.target = %d\n", csr->edp[0]->target);
			printf("edp0.broadcast_ack_not_sel = %d\n", csr->edp[0]->broadcast_ack_not_sel);

			printf("tg1.width = %d\n", csr->tg[1]->width);
			printf("tg1.height = %d\n\n", csr->tg[1]->height);

			printf("edp1.width = %d\n", csr->edp[1]->width);
			printf("edp1.height = %d\n", csr->edp[1]->height);
			printf("edp1.mode = %d\n", csr->edp[1]->mode);
			printf("edp1.target = %d\n", csr->edp[1]->target);
			printf("edp1.broadcast_ack_not_sel = %d\n", csr->edp[1]->broadcast_ack_not_sel);
#endif
			break;
		}
	}
	/* Disable BSP route */
	csr->edp[path]->mode = 0; /* All-frame to target */
	csr->edp[path]->target = 0; /* Target to main path */
	csr->edp[path]->double_buf_update = 1;
	g_is_drvdata.path_param[path].route_bmp &= ~ENABLE_BSP_ROUTE;

	csr->bsp[path]->irq_clear_frame_end = 1;
	debug_print("poll bsp path %u success\n", path);
}

#if EARLYVIDEO_DEBUG
void is_poll_da(uint8_t path)
{
	struct is_csr *csr = &g_is_drvdata.csr;
	uint32_t fps = g_is_drvdata.shm_ptr->segments[path].fps;
	uint64_t start_ticks = get_ticks();
	uint64_t max_wait_ticks = (fps > 0) ? (10 * (SEC_TO_TICKS / fps)) : (2 * SEC_TO_TICKS);

	debug_print("\n");

	while ((g_is_drvdata.sensor_bmp & BIT(path)) && (csr->isw[path]->status_frame_end == 0)) {
		/* Do nothing */
		if ((get_ticks() - start_ticks) > max_wait_ticks) {
			printf("Failed to poll the frame end of path %u\n", path);
			g_is_drvdata.sensor_bmp &= ~BIT(path);
			is_show_checksum();
			break;
		}
	}
	csr->isw[path]->irq_clear_frame_end = 1;
	printf("tg[%d].width = %d\n", path, csr->tg[path]->width);
	printf("tg[%d].height = %d\n\n", path, csr->tg[path]->height);

	printf("edp[%d].width = %d\n", path, csr->edp[path]->width);
	printf("edp[%d].height = %d\n", path, csr->edp[path]->height);
	printf("edp[%d].mode = %d\n", path, csr->edp[path]->mode);
	printf("edp[%d].target = %d\n", path, csr->edp[path]->target);
	printf("edp[%d].broadcast_ack_not_sel = %d\n", path, csr->edp[path]->broadcast_ack_not_sel);

	printf("isw[%d].width = %d\n", path, csr->isw[path]->width);
	printf("isw[%d].height = %d\n\n", path, csr->isw[path]->height);
	printf("isw[%d].h_end = %d\n", path, csr->isw[path]->h_end);
	printf("isw[%d].v_end = %d\n", path, csr->isw[path]->v_end);
	printf("isw[%d].pixel_flush_len = %d\n", path, csr->isw[path]->pixel_flush_len);
	printf("isw[%d].fifo_flush_len  = %d\n", path, csr->isw[path]->fifo_flush_len);
	printf("isw[%d].fifo_end_phase = %d\n", path, csr->isw[path]->fifo_end_phase);
	printf("isw[%d].msb_only = %d\n", path, csr->isw[path]->msb_only);
	printf("isw[%d].isw->ini_addr_linear_0 = 0x%08x\n", path, csr->isw[path]->ini_addr_linear_0);
}

void is_show_checksum(void)
{
	struct is_csr *csr = &g_is_drvdata.csr;

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
	printf("isk0.isk_checksum.checksum_crop: 0x%08X\n", csr->isk_checksum[0]->checksum_crop);
	printf("isk0.isk_checksum.checksum_dbc: 0x%08X\n", csr->isk_checksum[0]->checksum_dbc);
	printf("isk0.isk_checksum.checksum_dcc: 0x%08X\n", csr->isk_checksum[0]->checksum_dcc);
	printf("isk0.isk_checksum.checksum_lsc: 0x%08X\n", csr->isk_checksum[0]->checksum_lsc);
	printf("isk0.isk_checksum.checksum_bsp: 0x%08X\n", csr->isk_checksum[0]->checksum_bsp);
	printf("isk1.isk_checksum.checksum_crop: 0x%08X\n", csr->isk_checksum[1]->checksum_crop);
	printf("isk1.isk_checksum.checksum_dbc: 0x%08X\n", csr->isk_checksum[1]->checksum_dbc);
	printf("isk1.isk_checksum.checksum_dcc: 0x%08X\n", csr->isk_checksum[1]->checksum_dcc);
	printf("isk1.isk_checksum.checksum_lsc: 0x%08X\n", csr->isk_checksum[1]->checksum_lsc);
	printf("isk1.isk_checksum.checksum_bsp: 0x%08X\n\n", csr->isk_checksum[1]->checksum_bsp);
}
#endif
