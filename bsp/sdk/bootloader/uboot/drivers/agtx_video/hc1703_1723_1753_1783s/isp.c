#include "isp.h"

#include <asm/io.h>

#include "agtx_video.h"
#include "agtx_early_amp.h"

#if CONFIG_AMP

#define IRQF_VPW_0 0x1
#define IRQF_VPW_1 0x2
#define IRQF_NRW 0x4

extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

typedef struct isp_runtime_info {
	struct isp_frame_table *ftbl;
	int frame_idx;
	int tile_idx;
	int irq_done_flag;
} IspRuntimeInfo;

IspRuntimeInfo g_runtime;

#if EARLYVIDEO_DEBUG
void isp_show_checksum(void)
{
	struct isp_csr *csr = &g_earlyvideo_drvdata.isp_csr;

	printf("\033[93m===== Start dumping ISP/ISPIN/VP checksum =====\033[0m\n");
	printf("isp.isp_checksum.checksum_ispin0: 0x%08X\n", csr->isp_checksum->checksum_ispin0);
	printf("isp.isp_checksum.checksum_ispin1: 0x%08X\n", csr->isp_checksum->checksum_ispin1);
	printf("isp.isp_checksum.checksum_dpchdr: 0x%08X\n", csr->isp_checksum->checksum_dpchdr);
	printf("isp.isp_checksum.checksum_rgbp: 0x%08X\n", csr->isp_checksum->checksum_rgbp);
	printf("isp.isp_checksum.checksum_sc: 0x%08X\n", csr->isp_checksum->checksum_sc);
	printf("isp.isp_checksum.checksum_enh: 0x%08X\n", csr->isp_checksum->checksum_enh);
	printf("isp.isp_checksum.checksum_dhz: 0x%08X\n\n", csr->isp_checksum->checksum_dhz);

	printf("isp.ispin_checksum.checksum_ispr0: 0x%08X\n", csr->ispin_checksum->checksum_ispr0);
	printf("isp.ispin_checksum.checksum_ispr0_data_0: 0x%08X\n", csr->ispin_checksum->checksum_ispr0_data_0);
	printf("isp.ispin_checksum.checksum_ispr0_data_1: 0x%08X\n", csr->ispin_checksum->checksum_ispr0_data_1);
	printf("isp.ispin_checksum.checksum_ispr0_data_2: 0x%08X\n", csr->ispin_checksum->checksum_ispr0_data_2);
	printf("isp.ispin_checksum.checksum_ispr1: 0x%08X\n", csr->ispin_checksum->checksum_ispr1);
	printf("isp.ispin_checksum.checksum_ispr1_data_0: 0x%08X\n", csr->ispin_checksum->checksum_ispr1_data_0);
	printf("isp.ispin_checksum.checksum_ispr1_data_1: 0x%08X\n", csr->ispin_checksum->checksum_ispr1_data_1);
	printf("isp.ispin_checksum.checksum_ispr1_data_2: 0x%08X\n", csr->ispin_checksum->checksum_ispr1_data_2);
	printf("isp.ispin_checksum.checksum_pg0: 0x%08X\n", csr->ispin_checksum->checksum_pg0);
	printf("isp.ispin_checksum.checksum_pg1: 0x%08X\n", csr->ispin_checksum->checksum_pg1);
	printf("isp.ispin_checksum.checksum_gfx0: 0x%08X\n", csr->ispin_checksum->checksum_gfx0);
	printf("isp.ispin_checksum.checksum_gfx1: 0x%08X\n", csr->ispin_checksum->checksum_gfx1);
	printf("isp.ispin_checksum.checksum_cs0: 0x%08X\n", csr->ispin_checksum->checksum_cs0);
	printf("isp.ispin_checksum.checksum_cs1: 0x%08X\n", csr->ispin_checksum->checksum_cs1);
	printf("isp.ispin_checksum.checksum_prd0: 0x%08X\n", csr->ispin_checksum->checksum_prd0);
	printf("isp.ispin_checksum.checksum_prd1: 0x%08X\n", csr->ispin_checksum->checksum_prd1);
	printf("isp.ispin_checksum.checksum_bld: 0x%08X\n\n", csr->ispin_checksum->checksum_bld);

	printf("isp.vp_checksum.checksum_mcvp_nr_disp_0: 0x%08X\n", csr->vp_checksum->checksum_mcvp_nr_disp_0);
	printf("isp.vp_checksum.checksum_mcvp_nr_disp_1: 0x%08X\n", csr->vp_checksum->checksum_mcvp_nr_disp_1);
	printf("isp.vp_checksum.checksum_mcvp_nr_disp_2: 0x%08X\n", csr->vp_checksum->checksum_mcvp_nr_disp_2);
	printf("isp.vp_checksum.checksum_mcvp_nr_ink_0: 0x%08X\n", csr->vp_checksum->checksum_mcvp_nr_ink_0);
	printf("isp.vp_checksum.checksum_mcvp_nr_ink_1: 0x%08X\n", csr->vp_checksum->checksum_mcvp_nr_ink_1);
	printf("isp.vp_checksum.checksum_mcvp_nr_ink_2: 0x%08X\n", csr->vp_checksum->checksum_mcvp_nr_ink_2);
	printf("isp.vp_checksum.checksum_unpacker: 0x%08X\n", csr->vp_checksum->checksum_unpacker);
	printf("isp.vp_checksum.checksum_b2r: 0x%08X\n", csr->vp_checksum->checksum_b2r);
	printf("isp.vp_checksum.checksum_yuv420to444_0: 0x%08X\n", csr->vp_checksum->checksum_yuv420to444_0);
	printf("isp.vp_checksum.checksum_yuv420to444_1: 0x%08X\n", csr->vp_checksum->checksum_yuv420to444_1);
	printf("isp.vp_checksum.checksum_scaler: 0x%08X\n", csr->vp_checksum->checksum_scaler);
	printf("isp.vp_checksum.checksum_vpcst_0: 0x%08X\n", csr->vp_checksum->checksum_vpcst_0);
	printf("isp.vp_checksum.checksum_vpcst_1: 0x%08X\n", csr->vp_checksum->checksum_vpcst_1);
	printf("isp.vp_checksum.checksum_vpcfa: 0x%08X\n", csr->vp_checksum->checksum_vpcfa);
	printf("isp.vp_checksum.checksum_vplp: 0x%08X\n\n", csr->vp_checksum->checksum_vplp);
}

void isp_print_ftbl(struct isp_frame_table *ftbl)
{
	struct tile_info *tile = NULL;
	int t;

	printf("======= ISP FRAME TABLE %d =======\n", ftbl->idx);
	printf("idx = %u\n", ftbl->idx);
	printf("binding_path = %u\n", ftbl->binding_path);
	printf("bayer_phase = %u\n", ftbl->bayer_phase);
	printf("Tile-related -\n");
	printf("\ttile_n = %u\n", ftbl->tile_n);
	printf("\tpre-sc\n");
	for (t = 0; t < ftbl->tile_n; t++) {
		tile = &ftbl->pre_sc[t];
		printf("\t\t{ %4u, %4u, %4u, %4u, %3u, %3u }\n", tile->first_x, tile->first_out_x, tile->last_out_x,
		       tile->last_x, tile->tile_in_width, tile->tile_out_width);
	}
	printf("\tpost-sc\n");
	for (t = 0; t < ftbl->tile_n; t++) {
		tile = &ftbl->post_sc[t];
		printf("\t\t{ %3u, %3u, %3u, %3u, %2u, %2u }\n", tile->first_x, tile->first_out_x, tile->last_out_x,
		       tile->last_x, tile->tile_in_width, tile->tile_out_width);
	}
	printf("frame start -\n");
	printf("\tstart_ispr[0] = %u\n", ftbl->start_ispr[0]);
	printf("\tstart_ispr[1] = %u\n", ftbl->start_ispr[1]);
	printf("\tstart_dms = %u\n", ftbl->start_dms);
	printf("\tstart_sc = %u\n", ftbl->start_sc);
	printf("\tstart_enh = %u\n", ftbl->start_enh);
	printf("\tstart_mcvp = %u\n", ftbl->start_mcvp);
	printf("\tstart_vpw[0] = %u\n", ftbl->start_vpw[0]);
	printf("\tstart_vpw[1] = %u\n", ftbl->start_vpw[1]);
	printf("Input resolution -\n");
	printf("\twidth = %u\n", ftbl->frame_width_i);
	printf("\theight = %u\n", ftbl->frame_height_i);
	printf("Output resolution -\n");
	printf("\twidth = %u\n", ftbl->frame_width_o);
	printf("\theight = %u\n\n", ftbl->frame_height_o);
	printf("Buffer information -\n");
	printf("\tispr_addr = 0x%08X\n", ftbl->buffer_info.ispr_addr);
	printf("\tnrw_addr = 0x%08X\n", ftbl->buffer_info.nrw_addr);
	printf("\tmer_addr = 0x%08X\n", ftbl->buffer_info.mer_addr);
	printf("\tmv8w_addr = 0x%08X\n", ftbl->buffer_info.mv8w_addr);
	printf("\tmv8r_addr = 0x%08X\n", ftbl->buffer_info.mv8r_addr);
	printf("\tvenc_mvw_addr = 0x%08X\n", ftbl->buffer_info.venc_mvw_addr);
	printf("\tvpw_addr = 0x%08X\n", ftbl->buffer_info.vpw_addr);
}

void isp_print_info(void)
{
	int i;

	/* Print ISP frame table */
	for (i = 0; i < EARLYVIDEO_ISP_FRAME_NUM; i++) {
		isp_print_ftbl(&g_earlyvideo_drvdata.isp_ftbl[i]);
	}
#if ISP_USE_CCQ
	/* Print ISP CCQ */
	printf("======= ISP CCQ =======\n");
	printf("blk_phys_addr = %u\n", g_earlyvideo_drvdata.isp_ccq_s.blk_phys_addr);
	printf("curr_virt_addr = %u\n", g_earlyvideo_drvdata.isp_ccq_s.curr_virt_addr);
	printf("instruction_length = %u\n\n", g_earlyvideo_drvdata.isp_ccq_s.instruction_length);
#endif
}
#endif

static void isp_set_clk(uint8_t enable)
{
	struct isp_csr *csr = &g_earlyvideo_drvdata.isp_csr;
	volatile uint32_t *vp_clk = (void *)0x80000044;
	uint32_t val = readl(vp_clk);

	if (enable == 0) {
		csr->isp_cfg->cken_ispr0 = enable;
		csr->isp_cfg->cken_ispr1 = enable;
		csr->isp_cfg->cken_cs0 = enable;
		csr->isp_cfg->cken_cs1 = enable;
		csr->isp_cfg->cken_rgbp = enable;
		csr->isp_cfg->cken_sc = enable;
		csr->isp_cfg->cken_enh = enable;
		csr->isp_cfg->cken_ctrl = enable;
		val &= ~(1 << 8);
		writel(val, vp_clk);
	} else {
		val |= (1 << 8);
		writel(val, vp_clk);
		csr->isp_cfg->cken_ctrl = enable;
		csr->isp_cfg->cken_enh = enable;
		csr->isp_cfg->cken_sc = enable;
		csr->isp_cfg->cken_rgbp = enable;
		csr->isp_cfg->cken_cs1 = enable;
		csr->isp_cfg->cken_cs0 = enable;
		csr->isp_cfg->cken_ispr1 = enable;
		csr->isp_cfg->cken_ispr0 = enable;
	}
}

#define SCALE_POST_OVERLAP (4)
#define SCALE_GRID_WIDTH (2)
#define MAX_TILE_WIDTH (256)
void isp_calc_scale_down_tile(struct isp_frame_table *ftbl)
{
	/*
	 * The tiling algorithm used during the scaling down pass is simplified
	 * based on the following assumptions:
	 * 1. ISP route: ISPIN -> RGBP -> SC -> VPW
	 * 2. Only downscaling is required
	 * 3. The post-tile overlap is fixed to 4
	 * 4. The number of tiles must be greater than 2
	 */
	struct tile_info *tile = NULL;
	uint8_t pre_overlap = round_up_div(SCALE_POST_OVERLAP * ftbl->frame_width_i, ftbl->frame_width_o);
	/* The middle/side pre/post-tile width without overlap */
	uint32_t mid_pre_tile_w = 0;
	uint32_t mid_post_tile_w = 0;
	uint32_t side_pre_tile_w = 0;
	uint32_t side_post_tile_w = 0;
	uint8_t i;

	pre_overlap = round_up_base(pre_overlap, 2);

	for (ftbl->tile_n = 2; ftbl->tile_n < EARLYVIDEO_MAX_TILE_NUM; ftbl->tile_n++) {
		mid_pre_tile_w = round_down_div(ftbl->frame_width_i, ftbl->tile_n);
		mid_pre_tile_w = round_down_base(mid_pre_tile_w, SCALE_GRID_WIDTH);
		if ((mid_pre_tile_w + (pre_overlap << 1)) <= MAX_TILE_WIDTH) {
			break;
		}
	}

	mid_post_tile_w = round_down_div(mid_pre_tile_w * ftbl->frame_width_o, ftbl->frame_width_i);
	mid_post_tile_w = round_down_base(mid_post_tile_w, SCALE_GRID_WIDTH);

	while (1) {
		side_pre_tile_w = (ftbl->frame_width_i - (ftbl->tile_n - 2) * mid_pre_tile_w) >> 1;
		if ((side_pre_tile_w % SCALE_GRID_WIDTH) == 0) {
			break;
		}
		mid_pre_tile_w -= SCALE_GRID_WIDTH;
	}
	while (1) {
		side_post_tile_w = (ftbl->frame_width_o - (ftbl->tile_n - 2) * mid_post_tile_w) >> 1;
		if ((side_post_tile_w % SCALE_GRID_WIDTH) == 0) {
			break;
		}
		mid_post_tile_w -= SCALE_GRID_WIDTH;
	}

	/* Fill in the pre-tile table */
	tile = &ftbl->pre_sc[0];
	tile->first_x = 0;
	tile->first_out_x = 0;
	tile->last_out_x = side_pre_tile_w - 1;
	tile->last_x = side_pre_tile_w + pre_overlap - 1;
	tile->tile_in_width = side_pre_tile_w + pre_overlap;
	tile->tile_out_width = side_pre_tile_w;

	tile = &ftbl->pre_sc[ftbl->tile_n - 1];
	tile->last_x = ftbl->frame_width_i - 1;
	tile->last_out_x = ftbl->frame_width_i - 1;
	tile->first_out_x = tile->last_out_x - side_pre_tile_w + 1;
	tile->first_x = tile->last_x - side_pre_tile_w - pre_overlap + 1;
	tile->tile_in_width = side_pre_tile_w + pre_overlap;
	tile->tile_out_width = side_pre_tile_w;

	for (i = 1; i < ftbl->tile_n - 1; i++) {
		tile = &ftbl->pre_sc[i];
		tile->first_out_x = ftbl->pre_sc[i - 1].last_out_x + 1;
		tile->first_x = (tile->first_out_x > pre_overlap) ? tile->first_out_x - pre_overlap : 0;
		tile->last_out_x = tile->first_out_x + mid_pre_tile_w - 1;
		tile->last_x = tile->last_out_x + pre_overlap;
		tile->tile_in_width = tile->last_x - tile->first_x + 1;
		tile->tile_out_width = tile->last_out_x - tile->first_out_x + 1;
	}

	/* Fill in the post-tile table */
	tile = &ftbl->post_sc[0];
	tile->first_x = 0;
	tile->first_out_x = 0;
	tile->last_out_x = side_post_tile_w - 1;
	tile->last_x = side_post_tile_w + SCALE_POST_OVERLAP - 1;
	tile->tile_in_width = side_post_tile_w + SCALE_POST_OVERLAP;
	tile->tile_out_width = side_post_tile_w;

	tile = &ftbl->post_sc[ftbl->tile_n - 1];
	tile->last_x = ftbl->frame_width_o - 1;
	tile->last_out_x = ftbl->frame_width_o - 1;
	tile->first_out_x = tile->last_out_x - side_post_tile_w + 1;
	tile->first_x = tile->last_x - side_post_tile_w - SCALE_POST_OVERLAP + 1;
	tile->tile_in_width = side_post_tile_w + SCALE_POST_OVERLAP;
	tile->tile_out_width = side_post_tile_w;

	for (i = 1; i < ftbl->tile_n - 1; i++) {
		tile = &ftbl->post_sc[i];
		tile->first_out_x = ftbl->post_sc[i - 1].last_out_x + 1;
		tile->first_x = (tile->first_out_x > SCALE_POST_OVERLAP) ? tile->first_out_x - SCALE_POST_OVERLAP : 0;
		tile->last_out_x = tile->first_out_x + mid_post_tile_w - 1;
		tile->last_x = tile->last_out_x + SCALE_POST_OVERLAP;
		tile->tile_in_width = tile->last_x - tile->first_x + 1;
		tile->tile_out_width = tile->last_out_x - tile->first_out_x + 1;
	}
}

#define PROCESS_MV_OVERLAP (16)
#define PROCESS_MV_GRID_WIDTH (8)
void isp_calc_process_mv_tile(struct isp_frame_table *ftbl)
{
	/*
	 * The tiling algorithm used during the MV processing pass is simplified
	 * based on the following assumptions:
	 * 1. ISP route: ISPIN -> ENH -> DHZ -> MCVP + NR
	 * 2. No scaling is applied
	 * 3. The number of tiles must be greater than 2
	 * 4. Only the tiling constraints of MCVP are considered
	 */
	struct tile_info *tile = NULL;
	/* The middle/side width without overlap */
	uint32_t mid_tile_w = 0;
	uint32_t side_tile_w = 0;
	uint8_t i;

	for (ftbl->tile_n = 2; ftbl->tile_n < EARLYVIDEO_MAX_TILE_NUM; ftbl->tile_n++) {
		mid_tile_w = round_down_div(ftbl->frame_width_i, ftbl->tile_n);
		mid_tile_w = round_up_base(mid_tile_w, PROCESS_MV_GRID_WIDTH);
		if ((mid_tile_w + (PROCESS_MV_OVERLAP << 1)) <= MAX_TILE_WIDTH) {
			break;
		}
	}

	while (1) {
		side_tile_w = (ftbl->frame_width_i - (ftbl->tile_n - 2) * mid_tile_w) >> 1;
		if ((side_tile_w % PROCESS_MV_GRID_WIDTH) == 0) {
			break;
		}
		mid_tile_w -= PROCESS_MV_GRID_WIDTH;
	}

	/* Fill in the pre-tile table */
	tile = &ftbl->pre_sc[0];
	tile->first_x = 0;
	tile->first_out_x = 0;
	tile->last_out_x = side_tile_w - 1;
	tile->last_x = side_tile_w + PROCESS_MV_OVERLAP - 1;
	tile->tile_in_width = side_tile_w + PROCESS_MV_OVERLAP;
	tile->tile_out_width = side_tile_w;

	tile = &ftbl->pre_sc[ftbl->tile_n - 1];
	tile->last_x = ftbl->frame_width_i - 1;
	tile->last_out_x = ftbl->frame_width_i - 1;
	tile->first_out_x = tile->last_out_x - side_tile_w + 1;
	tile->first_x = tile->last_x - side_tile_w - PROCESS_MV_OVERLAP + 1;
	tile->tile_in_width = side_tile_w + PROCESS_MV_OVERLAP;
	tile->tile_out_width = side_tile_w;

	for (i = 1; i < ftbl->tile_n - 1; i++) {
		tile = &ftbl->pre_sc[i];
		tile->first_out_x = ftbl->pre_sc[i - 1].last_out_x + 1;
		tile->first_x = (tile->first_out_x > PROCESS_MV_OVERLAP) ? tile->first_out_x - PROCESS_MV_OVERLAP : 0;
		tile->last_out_x = tile->first_out_x + mid_tile_w - 1;
		tile->last_x = tile->last_out_x + PROCESS_MV_OVERLAP;
		tile->tile_in_width = tile->last_x - tile->first_x + 1;
		tile->tile_out_width = tile->last_out_x - tile->first_out_x + 1;
	}

	/* Fill in the post-tile table */
	memcpy(&ftbl->post_sc[0], &ftbl->pre_sc[0], sizeof(struct tile_info) * ftbl->tile_n);
}

static void isp_set_frame_csr(struct isp_frame_table *ftbl, int frame_cnt)
{
	struct earlyvideo_drvdata *drvdata = &g_earlyvideo_drvdata;
	struct isp_csr *csr = &drvdata->isp_csr;
	struct dram_agent_config *ispr_da_cfg = (ftbl->idx == 0) ? &drvdata->da_cfg[DRAM_AGENT_ISPR] :
	                                                           &drvdata->da_cfg[DRAM_AGENT_INTER];
	struct dram_agent_config *vpw_da_cfg = (ftbl->idx == 0) ? &drvdata->da_cfg[DRAM_AGENT_INTER] :
	                                                          &drvdata->da_cfg[DRAM_AGENT_VPW];
	struct frame_info f_info;

	isp_set_clk(0);
	/* ISPIN */
	f_info.width = ftbl->frame_width_i;
	f_info.height = ftbl->frame_height_i;
	f_info.bit_depth = 8;
	if (ftbl->start_ispr[0]) {
		pxr_set_frame_csr(csr->ispr[0], ispr_da_cfg, &f_info);
		csr->pg[0]->mode = 1; /* Sensor's timing and sensor's pixel */
		csr->pg[0]->height = ftbl->frame_height_i;
		csr->cs[0]->height = ftbl->frame_height_i;
	}
	if (ftbl->start_ispr[1]) {
		pxr_set_frame_csr(csr->ispr[1], ispr_da_cfg, &f_info);
		csr->pg[1]->mode = 1; /* Sensor's timing and sensor's pixel */
		csr->pg[1]->height = ftbl->frame_height_i;
		csr->cs[1]->height = ftbl->frame_height_i;
	}
	/* RGBP */
	if (ftbl->start_dms) {
		csr->dms->mode = 0; /* Normal */
		csr->dms->ini_bayer_phase = ftbl->bayer_phase;
		csr->dms->height = ftbl->frame_height_i;

		csr->fcs->mode = 1; /* Disable */
		csr->fcs->height = ftbl->frame_height_i;

		csr->dbf->enable = 0; /* Disable */

		/* This set of settings has the same effect as disabling */
		csr->ccm->coeff_00_2s = 8192;
		csr->ccm->coeff_01_2s = 0;
		csr->ccm->coeff_02_2s = 0;
		csr->ccm->offset_o_0_2s = 0;
		csr->ccm->coeff_10_2s = 0;
		csr->ccm->coeff_11_2s = 8192;
		csr->ccm->coeff_12_2s = 0;
		csr->ccm->offset_o_1_2s = 0;
		csr->ccm->coeff_20_2s = 0;
		csr->ccm->coeff_21_2s = 0;
		csr->ccm->coeff_22_2s = 8192;
		csr->ccm->offset_o_2_2s = 0;

		csr->gma->mode = 1; /* Disable */

		csr->pca->height = ftbl->frame_height_i;

		/* Use the BT709 full range format as default */
		csr->cst->coeff_00_2s = 435;
		csr->cst->coeff_01_2s = 1465;
		csr->cst->coeff_02_2s = 148;
		csr->cst->offset_o_0_2s = 0;
		csr->cst->coeff_10_2s = -235;
		csr->cst->coeff_11_2s = -789;
		csr->cst->coeff_12_2s = 1024;
		csr->cst->offset_o_1_2s = 512;
		csr->cst->coeff_20_2s = 1024;
		csr->cst->coeff_21_2s = -930;
		csr->cst->coeff_22_2s = -94;
		csr->cst->offset_o_2_2s = 512;
	}
	/* Scaler */
	if (ftbl->start_sc) {
		isp_sc_set_frame_csr(csr->sc, &ftbl->sc_param);
	}
	/* ENH */
	if (ftbl->start_enh) {
		csr->enh->height = ftbl->frame_height_o;
		csr->enh->sample_mode = 1; /* YUV420 */
		csr->enh->y_mode = 1;
		csr->enh->c_mode = 1;
		csr->enh->cac_enable = 1;

		csr->shp->height = ftbl->frame_height_o;
		csr->shp->sample_mode = 1; /* YUV420 */
		csr->shp->mode = 1;
	}

	f_info.width = ftbl->frame_width_o;
	f_info.height = ftbl->frame_height_o;
	f_info.bit_depth = 8;

	/* MCVP + NR */
	if (ftbl->start_mcvp) {
		csr->mcvp->frame_height = ftbl->frame_height_o;
		csr->mcvp->blk_height = ftbl->frame_height_o / BLOCK_HEIGHT;
		csr->mcvp->blk_height_m1 = ftbl->frame_height_o / BLOCK_HEIGHT - 1;
		csr->mcvp->sr_ix = drvdata->da_cfg[DRAM_AGENT_MER].search_range - 4;
		csr->mcvp->sr_blk8_ix = drvdata->da_cfg[DRAM_AGENT_MER].search_range / BLOCK_WIDTH;

		if (frame_cnt == 0) {
			csr->me->mode = 1; /* Disable */
			csr->me->scene_change = 0;
			csr->me->gmv_cand_valid = 0;
		} else if (frame_cnt == 1) {
			csr->me->mode = 0; /* Normal */
			csr->me->scene_change = 1;
			csr->me->gmv_cand_valid = 0;
		} else {
			csr->me->mode = 0; /* Normal */
			csr->me->scene_change = 1;
			csr->me->gmv_cand_valid = 1;
		}
		/* Candidates */
		csr->me->gmv_x = 0;
		csr->me->gmv_y = 0;
		csr->me->mode_left_mv_diff_th = 32;
		csr->me->mode_top_left_mv_diff_th = 32;
		csr->me->mode_top_right_mv_diff_th = 32;
		csr->me->bottom_left_dist_x = 4;
		csr->me->bottom_left_dist_y = 4;
		csr->me->bottom_right_dist_x = 4;
		csr->me->bottom_right_dist_y = 4;
		/* Search range */
		csr->me->sw_center_mode = 0;
		csr->me->sw_center_x_sw = 0;
		csr->me->sw_center_y_sw = 0;
		csr->me->sw_center_weight = 3;
		csr->me->sw_ix = 31;
		csr->me->sw_iy = 15;
		csr->me->sw_ix_size = 63;
		csr->me->sw_iy_size = 31;
		csr->me->mvr_left_extend_dist = 8;
		csr->me->mvr_right_extend_dist = 8;
		/* Motion search */
		csr->me->ime_penalty_gain_x_sel = 3;
		csr->me->ime_penalty_gain_y_sel = 3;
		csr->me->ime_penalty_bound_x_ini = 255;
		csr->me->ime_penalty_bound_y_ini = 255;
		csr->me->search_texture_th = 40;
		/* Cost */
		csr->me->valid_true_mv_th = 10000;
		csr->me->matching_weight = 1;
		csr->me->singularity_weight = 6;
		csr->me->range_weight = 8;
		/* Block matching */
		csr->me->m_cost_quarter_gain = 32;
		csr->me->m_cost_half_gain = 35;
		csr->me->m_cost_frac_offset = 0;
		/* Singularity */
		csr->me->singularity_min_th = 0;
		csr->me->singularity_max_th = 16;
		csr->me->texture_gain_low_th = 120;
		csr->me->texture_gain_high_th = 400;
		csr->me->texture_gain_low = 1;
		csr->me->texture_gain_high = 63;
		csr->me->texture_gain_slope = 56;
		/* MV range */
		csr->me->range_min_x_th = 0;
		csr->me->range_max_x_th = 32;
		csr->me->range_min_y_th = 0;
		csr->me->range_max_y_th = 32;
		/* Type */
		csr->me->spatial_cost_offset = 0;
		csr->me->temporal_cost_offset = 21;
		csr->me->search_weak_cost_offset = 30;
		csr->me->search_cost_offset = 25;
		csr->me->refine_cost_offset = 50;
		csr->me->gmv_cost_offset = 0;
		/* Non zero */
		csr->me->non_zero_mv_cost_offset = 20;

		csr->nr->mode = 4; /* Disable */
		csr->nr->abs_diff_hist_en = 0;
		csr->nr->tdiff_roi_0_en = 0;
		csr->nr->tdiff_roi_1_en = 0;
		csr->nr->tdiff_roi_2_en = 0;
		csr->nr->tdiff_roi_3_en = 0;
		csr->nr->demo_en = 0;
		csr->nr->demo_mode = 4;
		csr->nr->ink_en = 0;

		nrw_set_frame_csr(csr->nrw, &drvdata->da_cfg[DRAM_AGENT_NRW], &f_info);
		mer_set_frame_csr(csr->mer, &drvdata->da_cfg[DRAM_AGENT_MER], &f_info);
		mv8w_set_frame_csr(csr->mv8w, &drvdata->da_cfg[DRAM_AGENT_MV8W], &f_info);
		mv8r_set_frame_csr(csr->mv8r, &drvdata->da_cfg[DRAM_AGENT_MV8R], &f_info);
		venc_mvw_set_frame_csr(csr->venc_mvw, &drvdata->da_cfg[DRAM_AGENT_VENC_MVW], &f_info);

		/* Set CSRs related to IQ and the bitdepth */
		csr->mer->rounding = 0;
		csr->mer->pre_clip = 0;
		csr->mer->lsb_append_mode = 0;
		csr->nrw->rounding = 1;
		csr->nrw->pre_clip = 1;
		/* Set 1 for default of chroma rounding is 128-center rounding, #35377 */
		csr->nrw->rounding_c_adapt = 1;

		csr->b2r->y_block_v_num = ftbl->frame_height_o / BLOCK_HEIGHT;
		csr->b2r->c_block_v_num = ftbl->frame_height_o / BLOCK_HEIGHT;
	}

	/* VPW */
	if (ftbl->start_vpw[0]) {
		pxw_set_frame_csr(csr->vpw[0], vpw_da_cfg, &f_info);
	}
	if (ftbl->start_vpw[1]) {
		pxw_set_frame_csr(csr->vpw[1], vpw_da_cfg, &f_info);
	}

	if (ftbl->idx == 0) {
		/* Scaling down route: ISPIN -> RGBP -> SC -> VPW */
		/* Set ISP routes */
		csr->isp->ispr0_broadcast = 0x00000001;
		csr->isp->pg0_broadcast = 0x00000001;
		csr->isp->word_gfxbld_bypass = 0x00000001;
		csr->isp->gfxbld_in0_mux = 0x00000001;
		csr->isp->ispin0_yc_broadcast = 0x00000001;
		csr->isp->word_ispin0_y_broadcast = 0x00000002;
		/* RGBP */
		csr->isp->rgbp_gma_mode = 0x00000001;
		csr->isp->rgbp_mux = 0x00000002;
		csr->isp->rgbp_yc_broadcast = 0x00000101;
		csr->isp->word_rgbp_y_broadcast = 0x00000001;
		csr->isp->word_rgbp_c_broadcast = 0x00000001;
		/* SC */
		csr->isp->sc_y_mux = 0x00000000;
		csr->isp->sc_c_mux = 0x00000000;
		csr->isp->sc_yc_broadcast = 0x00000101;
		csr->isp->word_sc_y_broadcast = 0x00000002;
		csr->isp->word_sc_c_broadcast = 0x00000002;
		/* FIFO1 */
		csr->isp->fifo1_y_mux = 0x00000003;
		csr->isp->fifo1_c_mux = 0x00000003;
		/* Set VP routes */
		csr->vp->isp1_broadcast = 0x00010000;
		csr->vp->sel_vpwrite1 = 0x00000003;
	} else if (ftbl->idx == 1) {
		/* Processing MV route: ISPIN -> ENH -> DHZ -> MCVP + NR */
		/* Set ISP routes */
		csr->isp->ispr0_broadcast = 0x00000001;
		csr->isp->pg0_broadcast = 0x00000001;
		csr->isp->word_gfxbld_bypass = 0x00000001;
		csr->isp->gfxbld_in0_mux = 0x00000001;
		csr->isp->ispin0_yc_broadcast = 0x00000101;
		csr->isp->word_ispin0_y_broadcast = 0x00000008;
		csr->isp->word_ispin0_c_broadcast = 0x00000002;
		/* ENH + DHZ */
		csr->isp->enh_y_mux = 0x00000004;
		csr->isp->enh_c_mux = 0x00000004;
		csr->isp->dhz_yc_broadcast = 0x00000101;
		csr->isp->word_dhz_y_broadcast = 0x00000001;
		csr->isp->word_dhz_c_broadcast = 0x00000001;
		/* FIFO0 */
		csr->isp->fifo0_y_mux = 0x00000002;
		csr->isp->fifo0_c_mux = 0x00000002;
		/* Set VP routes */
		csr->vp->unpacker_sel = 1;
		csr->vp->b2r_broadcast_ack_not_sel = 1;
		csr->vp->unpacker_mux_ack_not_sel = 1;
	} else {
		/* Reordering chroma route: ISPIN0 -> VPW0 + ISPIN1 -> VPW1 */
		/* Set ISP routes */
		csr->isp->ispr0_broadcast = 0x00000001;
		csr->isp->ispr1_broadcast = 0x00000001;
		csr->isp->pg0_broadcast = 0x00000001;
		csr->isp->pg1_broadcast = 0x00000001;
		csr->isp->word_gfxbld_bypass = 0x00000001;
		csr->isp->gfxbld_in0_mux = 0x00000001;
		csr->isp->gfxbld_in1_mux = 0x00000001;
		csr->isp->gfxbld_in1_broadcast = 0x00000100;
		csr->isp->ispin0_yc_broadcast = 0x00000101;
		csr->isp->word_ispin0_y_broadcast = 0x00000020;
		csr->isp->word_ispin0_c_broadcast = 0x00000008;
		csr->isp->ispin1_yc_broadcast = 0x00000101;
		csr->isp->word_ispin1_y_broadcast = 0x00000040;
		csr->isp->word_ispin1_c_broadcast = 0x00000010;
		/* FIFO1 */
		csr->isp->fifo1_y_mux = 0x00000000;
		csr->isp->fifo1_c_mux = 0x00000000;
		csr->isp->fifo2_y_mux = 0x00000001;
		csr->isp->fifo2_c_mux = 0x00000001;
		/* Set VP routes */
		csr->vp->isp1_broadcast = 0x00000100;
		csr->vp->sel_vpwrite0 = 0x00000003;
		csr->vp->isp2_broadcast = 0x00010000;
		csr->vp->sel_vpwrite1 = 0x00000002;

		/* These special settings are used for reordering pixels. #89398-4 */
		csr->vpw[1]->bank_group_type = 1;
		csr->ispr[1]->channel_swap = 1;
	}
	/* Update the double buffer */
	csr->isp->rgbp_gamma_mode = 1;

	csr->mcvp->nrw_irq_mask_frame_end = 0;
	csr->vpw[0]->irq_mask_frame_end = 0;
	csr->vpw[1]->irq_mask_frame_end = 0;

	isp_set_clk(1);

	if (ftbl->start_dms) {
		/* Set the SRAM after enabling clock */
		isp_pca_set_table_cfg(csr->pca, &ftbl->pca_table);
	}

	/* DHZ */
	if (ftbl->start_enh) {
		csr->dhz->height = ftbl->frame_height_o;
		csr->dhz->strength = 0;
		csr->dhz->rgl_x_num = 8;
		csr->dhz->rgl_y_num = 8;
		csr->dhz->rgl_x_cnt_ini = 0;
		csr->dhz->rgl_y_cnt_ini = 0;
		csr->dhz->rgl_x_cnt_step = 0;
		csr->dhz->rgl_y_cnt_step = 0;
	}
}

static void isp_set_tile_csr(struct isp_frame_table *ftbl, int tile_idx)
{
	struct earlyvideo_drvdata *drvdata = &g_earlyvideo_drvdata;
	struct isp_buffer_info *buffer_info = &ftbl->buffer_info;
	struct isp_csr *csr = &drvdata->isp_csr;
	struct tile_da_reg *tile_reg = &ftbl->tile_da_reg[tile_idx];
	struct tile_info *pre_tile = &ftbl->pre_sc[tile_idx];
	struct tile_info *post_tile = &ftbl->post_sc[tile_idx];

	g_runtime.irq_done_flag = 0;

	isp_set_clk(0);
	/* ISPR */
	if (ftbl->start_ispr[0]) {
		pxr_set_tile_csr(csr->ispr[0], &tile_reg->ispr[0], buffer_info->ispr_addr);
		csr->pg[0]->width = pre_tile->tile_in_width;
		csr->cs[0]->width = pre_tile->tile_in_width;
	}
	if (ftbl->start_ispr[1]) {
		pxr_set_tile_csr(csr->ispr[1], &tile_reg->ispr[1], buffer_info->ispr_addr);
		csr->pg[1]->width = pre_tile->tile_in_width;
		csr->cs[1]->width = pre_tile->tile_in_width;
	}
	/* RGBP */
	if (ftbl->start_dms) {
		csr->dms->width = pre_tile->tile_in_width;
		csr->fcs->width = pre_tile->tile_in_width;
		csr->dbf->width = pre_tile->tile_in_width;
		csr->pca->width = pre_tile->tile_in_width;
	}
	/* Scaler */
	if (ftbl->start_sc) {
		isp_sc_set_tile_csr(csr->sc, &ftbl->sc_param, tile_idx);
	}
	/* ENH + DHZ */
	if (ftbl->start_enh) {
		csr->enh->width = post_tile->tile_in_width;
		csr->shp->width = post_tile->tile_in_width;
		csr->dhz->width = post_tile->tile_in_width;
	}

	/* MCVP + NR */
	if (ftbl->start_mcvp) {
		uint32_t tow_div_bw = post_tile->tile_out_width / BLOCK_WIDTH;
		uint32_t tiw_div_bw = post_tile->tile_in_width / BLOCK_WIDTH;

		csr->me->mv_roi_0_ex = post_tile->tile_out_width - 1;

		if (tile_idx == 0) {
			csr->mcvp->most_left_tile = 1;
			csr->mcvp->most_right_tile = 0;
			csr->mcvp->r2b_out_blk_width = MIN(tiw_div_bw, tow_div_bw + 2);
			csr->mcvp->me_out_blk_width = MIN(tiw_div_bw, tow_div_bw + 1);
			csr->mcvp->r2b_left_skip_pel = 0;
		} else if (tile_idx == (ftbl->tile_n - 1)) {
			csr->mcvp->most_left_tile = 0;
			csr->mcvp->most_right_tile = 1;
			csr->mcvp->r2b_out_blk_width = MIN(tiw_div_bw, tow_div_bw + 1);
			csr->mcvp->me_out_blk_width = tow_div_bw;
			csr->mcvp->r2b_left_skip_pel = post_tile->first_out_x - post_tile->first_x - BLOCK_WIDTH;
		} else {
			csr->mcvp->most_left_tile = 0;
			csr->mcvp->most_right_tile = 0;
			csr->mcvp->r2b_out_blk_width = MIN(tiw_div_bw, tow_div_bw + 3);
			csr->mcvp->me_out_blk_width = MIN(tiw_div_bw, tow_div_bw + 1);
			csr->mcvp->r2b_left_skip_pel = post_tile->first_out_x - post_tile->first_x - BLOCK_WIDTH;
		}
		csr->mcvp->frame_width_i = post_tile->tile_in_width;
		csr->mcvp->me_out_blk_width_m1 = csr->mcvp->me_out_blk_width - 1;

		nrw_set_tile_csr(csr->nrw, &tile_reg->nrw, buffer_info->nrw_addr);
		mer_set_tile_csr(csr->mer, &tile_reg->mer, buffer_info->mer_addr);
		venc_mvw_set_tile_csr(csr->venc_mvw, &tile_reg->venc_mvw, buffer_info->venc_mvw_addr);
		mv8w_set_tile_csr(csr->mv8w, &tile_reg->mv8w, buffer_info->mv8w_addr);
		mv8r_set_tile_csr(csr->mv8r, &tile_reg->mv8r, buffer_info->mv8r_addr);

		csr->b2r->y_block_h_num = tow_div_bw;
		csr->b2r->c_block_h_num = tow_div_bw;
	}

	/* VPW */
	if (ftbl->start_vpw[0]) {
		pxw_set_tile_csr(csr->vpw[0], &tile_reg->vpw[0], buffer_info->vpw_addr);
		csr->vpw[0]->width = post_tile->tile_in_width;
		csr->vpw[0]->h_start = post_tile->first_out_x - post_tile->first_x;
		csr->vpw[0]->h_end = post_tile->last_out_x - post_tile->first_x;
	}
	if (ftbl->start_vpw[1]) {
		if (ftbl->idx == 0) {
			pxw_set_tile_csr(csr->vpw[1], &tile_reg->vpw[1], buffer_info->vpw_addr);
		} else {
			uint32_t y_pixel_num = ftbl->frame_width_o * ftbl->frame_height_o;
			/* Only write C pixels to the start point of chrominance data #89398-4 */
			pxw_set_tile_csr(csr->vpw[1], &tile_reg->vpw[1], buffer_info->vpw_addr + y_pixel_num);
		}
		csr->vpw[1]->width = post_tile->tile_in_width;
		csr->vpw[1]->h_start = post_tile->first_out_x - post_tile->first_x;
		csr->vpw[1]->h_end = post_tile->last_out_x - post_tile->first_x;
	}
	isp_set_clk(1);
#if EARLYVIDEO_DEBUG
	csr->isp_checksum->clear = 1;
	csr->ispin_checksum->clear = 1;
	csr->enh_checksum->clear = 1;
	csr->vp_checksum->clear = 1;
#endif
	csr->isp->double_buf_update = 1;
	csr->vp->double_buf_update = 1;

	/* VPW */
	if (ftbl->start_vpw[0]) {
		csr->vpw[0]->frame_start = 1;
	}
	if (ftbl->start_vpw[1]) {
		csr->vpw[1]->frame_start = 1;
	}
	/* MCVP + NR */
	if (ftbl->start_mcvp) {
		csr->b2r->frame_start = 1;
		csr->nrw->frame_start = 1;
		csr->mer->frame_start = 1;
		csr->mv8w->frame_start = 1;
		csr->mv8r->frame_start = 1;
		csr->venc_mvw->frame_start = 1;
		csr->mcvp->frame_start = 1;
	}
	/* ENH + DHZ */
	if (ftbl->start_enh) {
		csr->dhz->frame_start = 1;
		csr->shp->frame_start = 1;
		csr->enh->frame_start = 1;
	}
	/* SC */
	if (ftbl->start_sc) {
		csr->sc->frame_start = 1;
	}
	/* RGBP */
	if (ftbl->start_dms) {
		csr->pca->frame_start = 1;
		csr->fcs->frame_start = 1;
		csr->dms->frame_start = 1;
	}
	/* ISPIN */
	if (ftbl->start_ispr[0]) {
		csr->cs[0]->frame_start = 1;
		csr->ispr[0]->frame_start = 1;
	}
	if (ftbl->start_ispr[1]) {
		csr->cs[1]->frame_start = 1;
		csr->ispr[1]->frame_start = 1;
	}
}

static void isp_process_frame(struct isp_frame_table *ftbl, uint8_t frame_cnt)
{
	struct earlyvideo_drvdata *drvdata = &g_earlyvideo_drvdata;
	struct earlyvideo_shm_segment *segment = &drvdata->shm_ptr->segments[ftbl->binding_path];
	struct isp_buffer_info *buffer_info = &ftbl->buffer_info;

	/* Update the addresses of DRAM agents. See buffer_layout.h for details. */
	switch (ftbl->idx) {
	case 0:
		buffer_info->ispr_addr = EV_PRIMARY_ISPR_ADDR(segment->raw_addr, frame_cnt, segment->frame_size);
		buffer_info->vpw_addr = EV_VPW_ADDR(segment->base_addr, segment->snapshot_size);
		break;
	case 1:
		buffer_info->ispr_addr = EV_REUSED_ISPR_ADDR(segment->base_addr, segment->snapshot_size);
		if (frame_cnt == 0) {
			buffer_info->nrw_addr = EV_NRW_ADDR(segment->base_addr, segment->snapshot_size);
			buffer_info->mer_addr = EV_MER_ADDR(segment->base_addr, segment->snapshot_size);
			buffer_info->mv8w_addr = EV_MV8W_ADDR(segment->mv_addr, segment->mv_size);
			buffer_info->mv8r_addr = EV_MV8R_ADDR(segment->mv_addr, segment->mv_size);
			buffer_info->venc_mvw_addr = EV_VENC_MVW_ADDR(segment->mv_addr, segment->mv_size);
		} else {
			SWAP(buffer_info->nrw_addr, buffer_info->mer_addr);
		}
		break;
	case 2:
		buffer_info->ispr_addr = EV_REUSED_ISPR_ADDR(segment->base_addr, segment->snapshot_size);
		buffer_info->vpw_addr = EV_REORDERED_VPW_ADDR(segment->base_addr, segment->snapshot_size);
		break;
	default:
		break;
	}

	g_runtime.ftbl = ftbl;
	g_runtime.tile_idx = 0;

	isp_set_frame_csr(ftbl, frame_cnt);
	isp_set_tile_csr(ftbl, g_runtime.tile_idx++);
}

static void isp_process_next_frame(void)
{
	struct isp_frame_table *ftbl = g_earlyvideo_drvdata.isp_ftbl;
	struct false_alarm_info *false_alarm = &g_earlyvideo_drvdata.false_alarm;
	int total_frame_num = (EARLYVIDEO_ISP_FRAME_NUM - 1) * false_alarm->frame_num;
	void *early_detect_info;

	/* 
	 * Originally implemented as:
	 *     for (frame_cnt = 0; frame_cnt < detect_frame_num; frame_cnt++)
	 *         for (idx = 0; idx < EARLYVIDEO_ISP_FRAME_NUM - 1; idx++)
	 * Now handled by an IRQ-based flow.
	 */
	if (g_runtime.frame_idx < total_frame_num) {
		int frame_cnt = g_runtime.frame_idx / (EARLYVIDEO_ISP_FRAME_NUM - 1);
		int ftbl_idx = g_runtime.frame_idx % (EARLYVIDEO_ISP_FRAME_NUM - 1);

		isp_process_frame(&ftbl[ftbl_idx], frame_cnt);
		g_runtime.frame_idx++;
		return;
	}

	/* Perform the reordering chroma pass for the last frame */
	if (g_runtime.frame_idx == total_frame_num) {
		isp_process_frame(&ftbl[EARLYVIDEO_ISP_FRAME_NUM - 1], false_alarm->frame_num - 1);
		g_runtime.frame_idx++;
		return;
	}

	early_detect_info = (void *)&g_earlyvideo_drvdata.shm_ptr->segments[0].early_detect_info;
	amp_false_alarm_detect(false_alarm->type, false_alarm->thres, early_detect_info);

	g_earlyvideo_drvdata.done_flag |= VIDEO_DONE_SNAPSHOT;
}

void isp_start_snapshot(void)
{
	g_runtime.frame_idx = 0;
	isp_process_next_frame();
}

static void isp_irq_handler(uint32_t irq, void *arg)
{
	struct earlyvideo_drvdata *drvdata = &g_earlyvideo_drvdata;
	struct isp_csr *csr = &drvdata->isp_csr;
	struct isp_frame_table *ftbl = g_runtime.ftbl;

	switch (irq) {
	case IRQ_VPW_0:
		csr->vpw[0]->irq_clear_frame_end = 1;
		g_runtime.irq_done_flag |= IRQF_VPW_0;
		break;
	case IRQ_VPW_1:
		csr->vpw[1]->irq_clear_frame_end = 1;
		g_runtime.irq_done_flag |= IRQF_VPW_1;
		break;
	case IRQ_NRW:
		csr->mcvp->nrw_irq_clear_frame_end = 1;
		g_runtime.irq_done_flag |= IRQF_NRW;
		break;
	default:
		printf("[%s]: unexpected IRQ: %d\n", __func__, irq);
		break;
	}

	if ((ftbl->start_vpw[0] == 1 && (g_runtime.irq_done_flag & IRQF_VPW_0) == 0) ||
	    (ftbl->start_vpw[1] == 1 && (g_runtime.irq_done_flag & IRQF_VPW_1) == 0) ||
	    (ftbl->start_mcvp == 1 && (g_runtime.irq_done_flag & IRQF_NRW) == 0)) {
		return;
	}

	if (g_runtime.tile_idx < ftbl->tile_n) {
		isp_set_tile_csr(ftbl, g_runtime.tile_idx++);
	} else {
		isp_process_next_frame();
	}
}

void isp_install_irq_handler(void)
{
	int irqs[] = { IRQ_VPW_0, IRQ_VPW_1, IRQ_NRW };
	int i;

	for (i = 0; i < ARRAY_SIZE(irqs); i++) {
		int ret = uboot_irq_install_handler(irqs[i], isp_irq_handler, NULL);
		if (ret) {
			printf("Failed to install %d IRQ handler, ret: %d\n", irqs[i], ret);
		}
	}
}

#endif
