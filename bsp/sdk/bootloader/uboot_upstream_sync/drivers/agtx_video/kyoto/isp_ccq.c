#include "isp.h"

#include "agtx_video.h"

#if ISP_USE_CCQ
extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

enum ccq_op_code {
	CCQ_OP_CODE_CSR_WRITE = 0,
	CCQ_OP_CODE_CSR_BURST_WRITE_INCR,
	CCQ_OP_CODE_CSR_BURST_WRITE_FIXED,
	CCQ_OP_CODE_CSR_READ,
	CCQ_OP_CODE_CSR_BURST_READ_INCR,
	CCQ_OP_CODE_CSR_BURST_READ_FIXED,
	CCQ_OP_CODE_CSR_POLLING,
	CCQ_OP_CODE_CSR_CHECK,
	CCQ_OP_CODE_WAIT,
	CCQ_OP_CODE_WAIT_IRQ,
	CCQ_OP_CODE_ISSUE_IRQ,
	CCQ_OP_CODE_NUM,
};

enum ccq_isp_irq {
	CCQ_ISP_VPWRITE0_IRQ = 7,
	CCQ_ISP_VPWRITE1_IRQ = 6,
};

static uint32_t __part_value(uint32_t data, uint32_t value, uint32_t start_bit, uint32_t bit_width)
{
	uint32_t tmp_val;
	uint32_t val_mask;

	val_mask = ((1 << bit_width) - 1) << start_bit;
	tmp_val = (value << start_bit) & val_mask;
	data &= ~val_mask;
	data |= tmp_val;

	return data;
}

#if 0
static inline void __add_csr_write_cmd(uint32_t *ptr, uint32_t csr_addr, uint32_t data)
{
	/* In 64-bit instruction, first use LSB part [31:0] as first write data, then use MSB part [63:32] */
	ptr[1] = CCQ_OP_CODE_CSR_WRITE << OP_CODE_OFFSET;
	ptr[1] |= (csr_addr & CCQ_ADDR_MASK) >> 2;
	ptr[0] = data;
}

static void __ccq_write_command(struct isp_ccq *ccq, void *csr_ptr, uint32_t data)
{
	uint32_t csr_addr;
	csr_addr = (uint32_t)csr_ptr - ccq->ioremap_offset;
	__add_csr_write_cmd((uint32_t *)ccq->curr_virt_addr, csr_addr, data);
	ccq->instruction_length++;
	ccq->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}
#endif

static void __ccq_write_command(struct isp_ccq *isp_ccq_s, void *csr_ptr, uint32_t data)
{
	uint32_t *ptr = (uint32_t *)isp_ccq_s->curr_virt_addr;

	ptr[1] = (CCQ_OP_CODE_CSR_WRITE << OP_CODE_OFFSET) | (((uint32_t)csr_ptr & CCQ_ADDR_MASK) >> 2);
	ptr[0] = data;

	isp_ccq_s->instruction_length++;
	isp_ccq_s->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}

#if 0
static inline void __add_csr_wait_irq_cmd(uint32_t *ptr, uint64_t irq)
{
	ptr[1] = CCQ_OP_CODE_WAIT_IRQ << OP_CODE_OFFSET;
	ptr[1] |= ~(irq >> 32) & 0x3FFFFFF;
	ptr[0] = ~(irq)&0xFFFFFFFF;
}

static void isp_ccq_wait_irq_command(struct isp_ccq *ccq, uint64_t irq_mask)
{
	__add_csr_wait_irq_cmd((uint32_t *)ccq->curr_virt_addr, irq_mask);
	// pr_err("[%s][%d] irq_mask %llu\n", __func__, __LINE__, irq_mask);
	ccq->instruction_length++;
	ccq->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}
#endif

static void __ccq_wait_irq_command(struct isp_ccq *isp_ccq_s, uint64_t irq)
{
	uint32_t *ptr = (uint32_t *)isp_ccq_s->curr_virt_addr;

	ptr[1] = (CCQ_OP_CODE_WAIT_IRQ << OP_CODE_OFFSET) | (~(irq >> 32) & 0x3FFFFFF);
	ptr[0] = ~(irq)&0xFFFFFFFF;

	isp_ccq_s->instruction_length++;
	isp_ccq_s->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}

#if 0
static inline void __add_csr_issue_irq_cmd(uint32_t *ptr)
{
	ptr[1] = CCQ_OP_CODE_ISSUE_IRQ << OP_CODE_OFFSET;
	ptr[0] = 0;
}


void isp_ccq_issue_irq_command(struct isp_ccq *ccq)
{
	__add_csr_issue_irq_cmd((uint32_t *)ccq->curr_virt_addr);
	ccq->instruction_length++;
	ccq->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}
#endif

static void __ccq_issue_irq_command(struct isp_ccq *isp_ccq_s)
{
	uint32_t *ptr = (uint32_t *)isp_ccq_s->curr_virt_addr;

	ptr[1] = CCQ_OP_CODE_ISSUE_IRQ << OP_CODE_OFFSET;
	ptr[0] = 0;

	isp_ccq_s->instruction_length++;
	isp_ccq_s->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}

#if 0
static inline void __add_csr_wait_cmd(u32 *ptr, u32 cycle)
{
	ptr[1] = CCQ_OP_CODE_WAIT << OP_CODE_OFFSET;
	ptr[0] = cycle;
}

static void isp_ccq_wait_command(struct isp_ccq *ccq, u32 cycle)
{
	ccq_add_csr_wait_cmd((u32 *)ccq->curr_virt_addr, cycle);
	ccq->instruction_length++;
	ccq->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}
#endif

static void __ccq_wait_command(struct isp_ccq *isp_ccq_s, u32 cycle)
{
	uint32_t *ptr = (uint32_t *)isp_ccq_s->curr_virt_addr;

	ptr[1] = CCQ_OP_CODE_WAIT << OP_CODE_OFFSET;
	ptr[0] = cycle;

	isp_ccq_s->instruction_length++;
	isp_ccq_s->curr_virt_addr += CCQ_CMD_LEN_BYTES;
}

static void ccq_pxr_set_tile_csr(struct isp_ccq *isp_ccq_s, volatile CsrBankPxr *pxr, DaPixelTile *da,
                                 uint32_t init_addr)
{
	uint32_t tmp_val;
	uint32_t linear_addr_e = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_e_add;
	uint32_t linear_addr_o = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_o_add;

	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_40, linear_addr_e);
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_41, linear_addr_o);
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_42, linear_addr_e);
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_43, linear_addr_o);

	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_09,
	                    __part_value(pxr->pr0_09, da->width, 16, 16)); /* height, width */
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_16, da->width); /* pixel_flush_len */
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_13, da->fifo_flush_len); /* fifo_flush_len */
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_21, da->fifo_flush_len_last); /* fifo_flush_len_last */
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_18, da->flush_addr_skip_e); /* flush_addr_skip_e */
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_19, da->flush_addr_skip_o); /* flush_addr_skip_o */

	tmp_val = __part_value(pxr->pr0_20, da->fifo_start_phase, 0, 5);
	tmp_val = __part_value(tmp_val, da->fifo_end_phase, 8, 5);
	__ccq_write_command(isp_ccq_s, (void *)&pxr->pr0_20, tmp_val); /* fifo_start_phase, fifo_end_phase */
}

static void ccq_pxw_set_tile_csr(struct isp_ccq *isp_ccq_s, volatile CsrBankPxw *pxw, DaPixelTile *da,
                                 uint32_t init_addr)
{
	uint32_t tmp_val;
	uint32_t linear_addr_e = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_e_add;
	uint32_t linear_addr_o = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_o_add;

	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_40, linear_addr_e);
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_41, linear_addr_o);
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_42, linear_addr_e);
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_43, linear_addr_o);

	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_09, __part_value(pxw->pw0_09, da->width, 16, 16)); // width
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_23, __part_value(pxw->pw0_23, da->width - 1, 16, 16)); // h_end
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_16, da->pixel_flush_len);
	tmp_val = __part_value(da->fifo_flush_len, da->fifo_start_phase, 16, 5); // fifo_flush_len, fifo_start_phase
	tmp_val = __part_value(tmp_val, da->fifo_end_phase, 24, 5); // fifo_end_phase
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_12, tmp_val);
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_21, __part_value(pxw->pw0_21, da->fifo_flush_len_last, 0, 3));
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_19, da->flush_addr_skip_e); // flush_addr_skip_e
	__ccq_write_command(isp_ccq_s, (void *)&pxw->pw0_20, da->flush_addr_skip_o); // flush_addr_skip_o
}

static void ccq_sc_set_tile_csr(struct isp_ccq *isp_ccq_s, volatile CsrBankSc *csr, struct tile_sc_param *sc_param,
                                int t)
{
	uint32_t tmp_val;

	__ccq_write_command(isp_ccq_s, (void *)&csr->res_i, __part_value(csr->res_i, sc_param->tile_width_i[t], 0, 16));
	tmp_val = __part_value(csr->res_o, sc_param->tile_width_o[t] + sc_param->crop_o_left[t], 0, 16);
	__ccq_write_command(isp_ccq_s, (void *)&csr->res_o, tmp_val);
	tmp_val = __part_value(csr->crop_i_res, sc_param->tile_width_i[t], 0, 16);
	__ccq_write_command(isp_ccq_s, (void *)&csr->crop_i_res, tmp_val);
	__ccq_write_command(isp_ccq_s, (void *)&csr->ini_phase_h, sc_param->ini_phase_hor[t]);
	__ccq_write_command(isp_ccq_s, (void *)&csr->ini_phase_ds_h, sc_param->ini_filt_phase_ds_hor[t]);

	tmp_val = __part_value(csr->ini_cnt_h_0, sc_param->ini_cnt_hor[t][0], 0, 8);
	tmp_val = __part_value(tmp_val, sc_param->ini_cnt_hor[t][1], 8, 8);
	tmp_val = __part_value(tmp_val, sc_param->ini_cnt_hor[t][2], 16, 8);
	tmp_val = __part_value(tmp_val, sc_param->ini_cnt_hor[t][3], 24, 8);
	__ccq_write_command(isp_ccq_s, (void *)&csr->ini_cnt_h_0, tmp_val);

	tmp_val = __part_value(csr->ini_cnt_h_1, sc_param->ini_cnt_hor[t][4], 0, 8);
	tmp_val = __part_value(tmp_val, sc_param->ini_cnt_hor[t][5], 8, 8);
	__ccq_write_command(isp_ccq_s, (void *)&csr->ini_cnt_h_1, tmp_val);

	__ccq_write_command(isp_ccq_s, (void *)&csr->crop_o_lr,
	                    __part_value(csr->crop_o_lr, sc_param->crop_o_left[t], 0, 16));
}

static void isp_ccq_update_tile_cmd(struct earlyvideo_drvdata *drvdata, struct isp_frame_table *ftbl, int tile_cnt)
{
	struct isp_csr *csr = &drvdata->isp_csr;
	struct isp_ccq *isp_ccq_s = &drvdata->isp_ccq_s;
	struct tile_sc_param *sc_param = &ftbl->sc_param;
	const struct tile_info *pre_tile = &ftbl->pre_sc[tile_cnt];
	const struct tile_info *post_tile = &ftbl->post_sc[tile_cnt];
	struct tile_da_reg *tile_reg = &ftbl->tile_da_reg[tile_cnt];
	uint32_t tmp_val;
	uint16_t pre_tiw = pre_tile->tile_in_width;

	/* ISPIN */
	if (ftbl->start_ispr[0]) {
		ccq_pxr_set_tile_csr(isp_ccq_s, csr->ispr[0], &tile_reg->ispr[0], ftbl->phy_addr_i);
		__ccq_write_command(isp_ccq_s, (void *)&csr->pg[0]->resolution,
		                    __part_value(csr->pg[0]->resolution, pre_tiw, 0, 16));
		__ccq_write_command(isp_ccq_s, (void *)&csr->cs[0]->cs07, pre_tiw);
	}
	if (ftbl->start_ispr[1]) {
		ccq_pxr_set_tile_csr(isp_ccq_s, csr->ispr[1], &tile_reg->ispr[1], ftbl->phy_addr_i);
		__ccq_write_command(isp_ccq_s, (void *)&csr->pg[1]->resolution,
		                    __part_value(csr->pg[1]->resolution, pre_tiw, 0, 16));
		__ccq_write_command(isp_ccq_s, (void *)&csr->cs[1]->cs07, pre_tiw);
	}
	/* RGBP */
	if (ftbl->start_dms) {
		__ccq_write_command(isp_ccq_s, (void *)&csr->dms->dms04, __part_value(csr->dms->dms04, pre_tiw, 0, 16));
		__ccq_write_command(isp_ccq_s, (void *)&csr->fcs->resolution,
		                    __part_value(csr->fcs->resolution, pre_tiw, 0, 16));
		__ccq_write_command(isp_ccq_s, (void *)&csr->dbf->dbf06, __part_value(csr->dbf->dbf06, pre_tiw, 0, 16));
		__ccq_write_command(isp_ccq_s, (void *)&csr->pca->res, __part_value(csr->pca->res, pre_tiw, 0, 16));
	}
	/* SC */
	if (ftbl->start_sc) {
		ccq_sc_set_tile_csr(isp_ccq_s, csr->sc, sc_param, tile_cnt);
	}
	/* VPW */
	if (ftbl->start_vpw[0]) {
		ccq_pxw_set_tile_csr(isp_ccq_s, csr->vpw[0], &tile_reg->vpw[0], ftbl->phy_addr_o);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_09,
		                    __part_value(csr->vpw[0]->pw0_09, post_tile->tile_in_width, 16, 16)); // width
		tmp_val = __part_value(csr->vpw[0]->pw0_23, post_tile->first_out_x - post_tile->first_x, 0,
		                       16); // h_start
		tmp_val = __part_value(tmp_val, post_tile->last_out_x - post_tile->first_x, 16, 16); // h_end
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_23, tmp_val);
	}
	if (ftbl->start_vpw[1]) {
		ccq_pxw_set_tile_csr(isp_ccq_s, csr->vpw[1], &tile_reg->vpw[1], ftbl->phy_addr_o);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[1]->pw0_09,
		                    __part_value(csr->vpw[1]->pw0_09, post_tile->tile_in_width, 16, 16)); // width
		tmp_val = __part_value(csr->vpw[1]->pw0_23, post_tile->first_out_x - post_tile->first_x, 0,
		                       16); // h_start
		tmp_val = __part_value(tmp_val, post_tile->last_out_x - post_tile->first_x, 16, 16); // h_end
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[1]->pw0_23, tmp_val);
	}
}

static void isp_ccq_frame_start_cmd(struct earlyvideo_drvdata *drvdata, struct isp_frame_table *ftbl)
{
	struct isp_ccq *isp_ccq_s = &drvdata->isp_ccq_s;
	struct isp_csr *csr = &drvdata->isp_csr;

	/* VPW */
	if (ftbl->start_vpw[0]) {
		__ccq_write_command(isp_ccq_s, (void *)csr->vpw[0], 0x1);
	}
	if (ftbl->start_vpw[1]) {
		__ccq_write_command(isp_ccq_s, (void *)csr->vpw[1], 0x1);
	}
	/* SC */
	if (ftbl->start_sc) {
		__ccq_write_command(isp_ccq_s, (void *)csr->sc, 0x1);
	}
	/* RGBP */
	if (ftbl->start_dms) {
		__ccq_write_command(isp_ccq_s, (void *)csr->pca, 0x1);
		__ccq_write_command(isp_ccq_s, (void *)csr->fcs, 0x1);
		__ccq_write_command(isp_ccq_s, (void *)csr->dms, 0x1);
	}
	/* ISPIN */
	if (ftbl->start_ispr[0]) {
		__ccq_write_command(isp_ccq_s, (void *)csr->cs[0], 0x1);
		__ccq_write_command(isp_ccq_s, (void *)csr->ispr[0], 0x1);
	}
	if (ftbl->start_ispr[1]) {
		__ccq_write_command(isp_ccq_s, (void *)csr->cs[1], 0x1);
		__ccq_write_command(isp_ccq_s, (void *)csr->ispr[1], 0x1);
	}
}

static void isp_ccq_clear_checksum_cmd(struct earlyvideo_drvdata *drvdata)
{
	struct isp_ccq *isp_ccq_s = &drvdata->isp_ccq_s;
	struct isp_csr *csr = &drvdata->isp_csr;

	__ccq_write_command(isp_ccq_s, (void *)csr->isp_checksum, 0x1);
	__ccq_write_command(isp_ccq_s, (void *)csr->ispin_checksum, 0x1);
	__ccq_write_command(isp_ccq_s, (void *)csr->vp_checksum, 0x1);
}

static void isp_ccq_clear_irq_cmd(struct earlyvideo_drvdata *drvdata)
{
	struct isp_ccq *isp_ccq_s = &drvdata->isp_ccq_s;
	struct isp_csr *csr = &drvdata->isp_csr;

	__ccq_write_command(isp_ccq_s, (void *)&csr->ispr[0]->pr0_01, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->ispr[1]->pr0_01, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->cs[0]->cs01, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->cs[1]->cs01, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->dms->dms01, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->fcs->irq_clear, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->pca->irq_clear, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->sc->irq_clear, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_01, 0xFFFFFFFF);
	__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[1]->pw0_01, 0xFFFFFFFF);
}

static void isp_ccq_set_clk_cmd(struct earlyvideo_drvdata *drvdata, int enable)
{
	struct isp_ccq *isp_ccq_s = &drvdata->isp_ccq_s;
	volatile struct csr_bank_isp_cfg *isp_cfg = drvdata->isp_csr.isp_cfg;

	if (enable == 0) {
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_ispr0, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_ispr1, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_cs0, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_cs1, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_rgbp, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_sc, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_ctrl, enable);
	} else {
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_ctrl, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_sc, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_rgbp, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_cs1, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_cs0, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_ispr1, enable);
		__ccq_write_command(isp_ccq_s, (void *)&isp_cfg->conf0_ispr0, enable);
	}
}

void isp_write_ccq_cmd(struct earlyvideo_drvdata *drvdata, struct isp_frame_table *ftbl)
{
	struct isp_csr *csr = &drvdata->isp_csr;
	struct isp_ccq *isp_ccq_s = &drvdata->isp_ccq_s;
	uint8_t tile_cnt;

	__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, 0x1F1F);
	for (tile_cnt = 0; tile_cnt < 2; tile_cnt++) {
		if (tile_cnt) {
			isp_ccq_set_clk_cmd(drvdata, 0);
			__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x0);
			isp_ccq_update_tile_cmd(drvdata, ftbl, tile_cnt);
			__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x1);
			isp_ccq_set_clk_cmd(drvdata, 1);
			__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x2);
		}
		__ccq_write_command(isp_ccq_s, (void *)&csr->isp->buf_update, 0x1);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vp->buf_update, 0x1);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x3);
		isp_ccq_clear_irq_cmd(drvdata);
		isp_ccq_clear_checksum_cmd(drvdata);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x4);
		isp_ccq_frame_start_cmd(drvdata, ftbl);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x5);
		__ccq_wait_irq_command(isp_ccq_s, ftbl->irq);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x6);
		__ccq_wait_command(isp_ccq_s, 2048);
		__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, (tile_cnt << 4) | 0x7);
	}
	__ccq_write_command(isp_ccq_s, (void *)&csr->vpw[0]->pw0_24, 0xF1F1);
	__ccq_issue_irq_command(isp_ccq_s);
}

void isp_ccq_init(struct earlyvideo_drvdata *drvdata)
{
	struct isp_csr *csr = &drvdata->isp_csr;

	/* ccq init */
	csr->ccq->arbitration_mode = 1;
	csr->ccq->dis_cg = 0;
	csr->ccq->irq_clr = 0x3F;
	csr->ccq->irq_mask = 0x0;
	/* ccqr init */
	csr->ccqr->access_end_sel = 0;
	csr->ccqr->bank_addr_type = BANK_ADDR_TYPE;
	/* ccqw init */
	csr->ccqw->access_end_sel = 0;
	csr->ccqw->bank_addr_type = BANK_ADDR_TYPE;
}

void ccq_buf_setting(volatile struct csr_bank_ccqr *ccqr, volatile struct csr_bank_ccqw *ccqw,
                     struct isp_ccq *isp_ccq_s)
{
	ccqr->ini_addr_linear = isp_ccq_s->blk_phys_addr >> 3;
	ccqr->fifo_flush_len = isp_ccq_s->instruction_length;
	ccqr->pixel_flush_len = isp_ccq_s->instruction_length;
	ccqw->ini_addr_linear_0 = (isp_ccq_s->blk_phys_addr + isp_ccq_s->instruction_length * CCQ_CMD_LEN_BYTES) >> 3;
	ccqw->buffer_set_0 = 1;
	ccqw->buffer_size = 0x10;
}

void ccq_start(struct earlyvideo_drvdata *drvdata)
{
	struct isp_csr *csr = &drvdata->isp_csr;

	csr->ccq->instruction_length = drvdata->isp_ccq_s.instruction_length;
	csr->ccqr->irq_clear_frame_end = 1;
	csr->ccqw->irq_clear_frame_end = 1;
	csr->ccqr->frame_start = 1;
	csr->ccqw->frame_start = 1;
	csr->ccq->ccq_start = 1;
}
#endif /* ISP_USE_CCQ */