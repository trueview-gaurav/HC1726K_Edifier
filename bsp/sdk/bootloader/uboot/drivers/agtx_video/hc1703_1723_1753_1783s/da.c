#include "da.h"

#include "agtx_video.h"

extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

void gen_da_setting(DramAgentConfig *dram_agent_table, const uint8_t start_item, const uint8_t end_item)
{
	uint8_t i = 0;
	uint8_t pixel_per_blk = BLOCK_WIDTH * BLOCK_WIDTH;
	uint8_t bit_per_pixel;
	DramAgentConfig *dram_agent = 0;

	for (i = start_item; i < end_item; i++) {
		dram_agent = &dram_agent_table[i - start_item];
		dram_agent->col_addr_type = COL_ADDR_TYPE;
		dram_agent->msb_only = 1;

		switch (i) {
		case DRAM_AGENT_VENC_MVW:
			dram_agent->bank_group_type = 2;
			dram_agent->fifo_full_level = 64;
			break;
		case DRAM_AGENT_MV8R:
		case DRAM_AGENT_MV8W:
			dram_agent->bank_group_type = 0;
			dram_agent->fifo_full_level = 64;
			break;
		case DRAM_AGENT_ISW:
		case DRAM_AGENT_ISPR:
		case DRAM_AGENT_INTER:
		case DRAM_AGENT_VPW:
			dram_agent->bank_group_type = 0;
			dram_agent->fifo_full_level = 256;
			break;
		case DRAM_AGENT_NRW:
		case DRAM_AGENT_MER:
			dram_agent->bank_group_type = 2;
			dram_agent->fifo_full_level = 256;
			break;
		default:
			break;
		}

		dram_agent->bank_interleave_type = BITWIDTH_BANK - dram_agent->bank_group_type;
		dram_agent->phy_to_linear_shift = WORD_ADDR_BW + dram_agent->bank_group_type;
		dram_agent->target_fifo_level = 32;
		dram_agent->target_burst_len = 16;
		switch (i) {
		case DRAM_AGENT_ISW:
		case DRAM_AGENT_ISPR:
		case DRAM_AGENT_MER:
			dram_agent->access_end_sel = 1;
			break;
		default:
			dram_agent->access_end_sel = 0;
			break;
		}

		if (i == DRAM_AGENT_ISW) {
			dram_agent->allow_stall = 0;
		} else {
			dram_agent->allow_stall = 1;
		}

		/* y_only */
		switch (i) {
		case DRAM_AGENT_ISW:
		case DRAM_AGENT_ISPR:
		case DRAM_AGENT_VPW:
			dram_agent->y_only = 1;
			dram_agent->y_only_o = 1;
			break;
		case DRAM_AGENT_INTER:
			dram_agent->y_only = 1;
			dram_agent->y_only_o = 0;
			break;
		default:
			dram_agent->y_only = 0;
			dram_agent->y_only_o = 0;
			break;
		}

		/* fifo_per_block */
		bit_per_pixel = (dram_agent->msb_only == 0) ? MSB_BIT_NUM + LSB_BIT_NUM : MSB_BIT_NUM;
		bit_per_pixel = (dram_agent->y_only == 0) ? bit_per_pixel / 2 * 3 : bit_per_pixel;
		dram_agent->fifo_per_block = bit_per_pixel * pixel_per_blk / DA_FIFO_WORD;

		if (dram_agent->msb_only) {
			dram_agent->pixel_per_package = PPW_MSB;
			dram_agent->package_size = 1;
			dram_agent->package_size_last = 0;
		} else {
			dram_agent->pixel_per_package = PPW_LSB;
			dram_agent->package_size = PPW_LSB / PPW_MSB + 1;
			dram_agent->package_size_last = dram_agent->package_size;
		}

		/* Set SR default as 128, can be changed later */
		dram_agent->search_range = 128;
	}
}

/*
 * ========================================================
 *  Start of the helper functions for the Pixel DRAM agent
 * ========================================================
 */
uint32_t calc_pxw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent,
                              uint8_t align)
{
	uint32_t bitdepth = dram_agent->msb_only ? MSB_BIT_NUM : MSB_BIT_NUM + LSB_BIT_NUM;
	uint32_t bpp_even_line = dram_agent->y_only ? bitdepth : bitdepth * 2; /* bpp: bits per pixel */
	uint32_t bpp_odd_line = dram_agent->y_only_o ? bitdepth : bitdepth * 2;

	/* Currently we only use bank_group_type 0 in earlyvideo */
	uint32_t bpp_avg = (bpp_even_line + bpp_odd_line) / 2;
	uint32_t bytes_total = width * height * bpp_avg / 8;

	return align ? round_up_base(bytes_total, DRAM_COL_NUM * DRAM_BANK_NUM) : bytes_total;
}

void pxw_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaPixelTile *da)
{
	uint32_t flush_addr_skip;
	uint16_t addr_per_row;

	da->width = tile->last_out_x - tile->first_out_x + 1;

	da->ini_addr_linear_e_add = tile->first_out_x / cfg->pixel_per_package * cfg->package_size;
	da->ini_addr_linear_o_add = da->ini_addr_linear_e_add;

	if (cfg->y_only == 0)
		da->ini_addr_linear_e_add *= 2;

	if (cfg->y_only_o == 0)
		da->ini_addr_linear_o_add *= 2;

	da->fifo_start_phase = tile->first_out_x % cfg->pixel_per_package;
	da->fifo_end_phase = tile->last_out_x % cfg->pixel_per_package;
	da->pixel_flush_len = da->width + da->fifo_start_phase + (cfg->pixel_per_package - 1 - da->fifo_end_phase);
	da->fifo_flush_len = da->pixel_flush_len / PPW_MSB;
	da->fifo_flush_len_last = 0;
	if (cfg->msb_only == 0) {
		da->fifo_flush_len += da->pixel_flush_len / PPW_LSB;
		da->fifo_flush_len_last = cfg->package_size;
	}

	addr_per_row = round_up_div(frame->width, cfg->pixel_per_package) * cfg->package_size;
	flush_addr_skip = addr_per_row - da->fifo_flush_len;
	da->flush_addr_skip_e = flush_addr_skip;
	da->flush_addr_skip_o = cfg->y_only_o ? flush_addr_skip : flush_addr_skip * 2;

	/*
	 * Adjust address to skip when Y-only and Y+C lines are in the same
	 * bank group to maintain correct memory access. (#54516)
	 */
	if (cfg->bank_group_type == 0 && cfg->y_only_o == 0) {
		da->flush_addr_skip_e += da->ini_addr_linear_e_add;
		da->flush_addr_skip_o -= da->ini_addr_linear_e_add;
	}

	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

void pxw_set_tile_csr(volatile CsrBankPxw *pxw, DaPixelTile *da, uint32_t init_addr)
{
	uint32_t linear_addr_e = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_e_add;
	uint32_t linear_addr_o = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_o_add;

	/* AXI Address Control */
	pxw->ini_addr_linear_0 = linear_addr_e;
	pxw->ini_addr_linear_1 = linear_addr_o;
	pxw->ini_addr_linear_2 = linear_addr_e;
	pxw->ini_addr_linear_3 = linear_addr_o;

	/* DA Size */
	pxw->width = da->width;
	pxw->h_end = da->width - 1;
	pxw->pixel_flush_len = da->pixel_flush_len;
	pxw->fifo_start_phase = da->fifo_start_phase;
	pxw->fifo_end_phase = da->fifo_end_phase;
	pxw->fifo_flush_len = da->fifo_flush_len;
	pxw->fifo_flush_len_last = da->fifo_flush_len_last;
	pxw->flush_addr_skip_e = da->flush_addr_skip_e;
	pxw->flush_addr_skip_o = da->flush_addr_skip_o;
}

void pxw_set_frame_csr(volatile CsrBankPxw *pxw, DramAgentConfig *cfg, FrameInfo *frame)
{
	/* AXI Address Control */
	pxw->col_addr_type = COL_ADDR_TYPE;
	pxw->bank_interleave_type = cfg->bank_interleave_type;
	pxw->bank_group_type = cfg->bank_group_type;
	pxw->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;

	/* DA Size */
	pxw->height = frame->height;
	pxw->v_end = frame->height - 1;

	/* Data Format and Package */
	pxw->msb_only = cfg->msb_only;
	pxw->y_only_e = cfg->y_only;
	pxw->y_only_o = cfg->y_only_o;
	pxw->package_size_last = cfg->package_size_last;

	/* Efficiency Setting */
	pxw->access_end_sel = cfg->access_end_sel;
}

/*
 * Calculate tile-related config according to the tile table and DA config.
 */
void pxr_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaPixelTile *da)
{
	uint16_t end_addr_add;
	uint16_t addr_per_row = round_up_div(frame->width, cfg->pixel_per_package) * cfg->package_size;

	da->ini_addr_linear_e_add = tile->first_x / cfg->pixel_per_package * cfg->package_size;
	da->ini_addr_linear_o_add = tile->first_x / cfg->pixel_per_package * cfg->package_size;

	da->width = tile->last_x - tile->first_x + 1;
	da->fifo_start_phase = tile->first_x % cfg->pixel_per_package;
	da->fifo_end_phase = tile->last_x % cfg->pixel_per_package;

	/* Currently we only use bank_group_type 0 in earlyvideo */
	da->fifo_flush_len = round_up_div((da->fifo_start_phase + da->width), PPW_MSB);
	da->fifo_flush_len_last = 0;
	end_addr_add = round_up_div((tile->last_x + 1), PPW_MSB) * cfg->package_size;
	da->flush_addr_skip_e = addr_per_row - (end_addr_add - da->ini_addr_linear_e_add);
	da->flush_addr_skip_o = da->flush_addr_skip_e;

	if (cfg->y_only == 0) {
		da->ini_addr_linear_e_add *= 2;
		da->flush_addr_skip_e *= 2;
	}
	if (cfg->y_only_o == 0) {
		da->ini_addr_linear_o_add *= 2;
		da->flush_addr_skip_o *= 2;
	}

	/* #54516 Reduce VB usage of VPW from 2X to 1.5X */
	if (cfg->bank_group_type == 0 && cfg->y_only_o == 0) {
		da->flush_addr_skip_e += da->ini_addr_linear_e_add;
		da->flush_addr_skip_o -= da->ini_addr_linear_e_add;
	}

	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

/*
 * These tile-related CSRs need to be updated at every tile's frame start.
 */
void pxr_set_tile_csr(volatile CsrBankPxr *pxr, DaPixelTile *da, uint32_t init_addr)
{
	uint32_t linear_addr_e = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_e_add;
	uint32_t linear_addr_o = (init_addr >> da->phy_to_linear_shift) + da->ini_addr_linear_o_add;

	/* DRAM Setting */
	pxr->ini_addr_linear_0 = linear_addr_e;
	pxr->ini_addr_linear_1 = linear_addr_o;
	pxr->ini_addr_linear_2 = linear_addr_e;
	pxr->ini_addr_linear_3 = linear_addr_o;

	/* Configuration Setting */
	pxr->width = da->width;
	pxr->pixel_flush_len = da->width;
	pxr->fifo_flush_len = da->fifo_flush_len;
	pxr->fifo_flush_len_last = da->fifo_flush_len_last;
	pxr->fifo_start_phase = da->fifo_start_phase;
	pxr->fifo_end_phase = da->fifo_end_phase;
	pxr->flush_addr_skip_e = da->flush_addr_skip_e;
	pxr->flush_addr_skip_o = da->flush_addr_skip_o;
}

/*
 * Usually, these frame-related CSRs stay unchanged through whole frame.
 * Therefore, pxr_set_frame_csr() only needs to be called once. 
 */
void pxr_set_frame_csr(volatile CsrBankPxr *pxr, DramAgentConfig *cfg, FrameInfo *frame)
{
	/* DRAM Setting */
	pxr->col_addr_type = COL_ADDR_TYPE;
	pxr->bank_interleave_type = cfg->bank_interleave_type;
	pxr->bank_group_type = cfg->bank_group_type;
	pxr->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;
	pxr->ini_addr_bank_add_sub = 0;

	/* Configuration Setting */
	pxr->height = frame->height;

	/* Data Format and Package */
	pxr->y_only_e = cfg->y_only;
	pxr->y_only_o = cfg->y_only_o;
	pxr->msb_only = cfg->msb_only;
	pxr->package_size_last = cfg->package_size_last;

	/* Efficiency Setting */
	pxr->access_end_sel = cfg->access_end_sel;

	/* Others */
	pxr->mirror_mode = 0;
	pxr->flip_mode = 0;
	pxr->block_mode = 0;
	pxr->addr_per_row = round_up_div(frame->width, cfg->pixel_per_package) * cfg->package_size;

	/* Currently we only use bank_group_type 0 in earlyvideo */
	pxr->lsb_append_mode = 3;
}
/*
 * ========================================================
 *  Start of the helper functions for the NRW
 * ========================================================
 */
void nrw_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaBlockTile *da, uint16_t offset_x,
                        uint16_t offset_y)
{
	uint32_t addr_per_row;
	uint32_t addr_offset_y;
	da->width = tile->last_out_x - tile->first_out_x + 1;
	da->block_cnt_hor = da->width / BLOCK_WIDTH;
	da->pixel_flush_len = da->width * BLOCK_WIDTH;
	da->fifo_flush_len = da->width / BLOCK_WIDTH * cfg->fifo_per_block;
	addr_per_row = round_up_base(frame->width, MACRO_BLOCK_WIDTH) / BLOCK_WIDTH * cfg->fifo_per_block;
	da->flush_addr_skip = addr_per_row - da->fifo_flush_len;
	addr_offset_y = offset_y / (1 << cfg->bank_group_type) / BLOCK_HEIGHT * addr_per_row;
	da->addr_add = (tile->first_out_x + offset_x) / BLOCK_WIDTH * cfg->fifo_per_block + addr_offset_y;
	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

void nrw_set_tile_csr(volatile CsrBankNrw *csr, DaBlockTile *da, uint32_t init_addr)
{
	uint32_t linear_addr = (init_addr >> da->phy_to_linear_shift) + da->addr_add;
	csr->ini_addr_linear_0 = linear_addr;
	csr->ini_addr_linear_1 = linear_addr;
	csr->ini_addr_linear_2 = linear_addr;
	csr->ini_addr_linear_3 = linear_addr;
	csr->ini_addr_linear_4 = linear_addr;
	csr->ini_addr_linear_5 = linear_addr;
	csr->ini_addr_linear_6 = linear_addr;
	csr->ini_addr_linear_7 = linear_addr;
	csr->block_cnt_hor = da->block_cnt_hor;
	csr->fifo_flush_len = da->fifo_flush_len;
	csr->pixel_flush_len = da->pixel_flush_len;
	csr->flush_addr_skip = da->flush_addr_skip;
	csr->h_start = 0;
	csr->h_end = da->block_cnt_hor - 1;
}

void nrw_set_frame_csr(volatile CsrBankNrw *csr, DramAgentConfig *cfg, FrameInfo *frame)
{
	csr->col_addr_type = cfg->col_addr_type;
	csr->bank_interleave_type = cfg->bank_interleave_type;
	csr->bank_group_type = cfg->bank_group_type;
	csr->height = frame->height;
	csr->v_start = 0;
	csr->v_end = frame->height - 1;

	csr->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;
	csr->msb_only = cfg->msb_only;
	csr->y_only = cfg->y_only;

	csr->access_end_sel = cfg->access_end_sel;
	csr->target_burst_len = cfg->target_burst_len;
	csr->target_fifo_level = cfg->target_fifo_level;
	csr->fifo_full_level = cfg->fifo_full_level;
}
/*
 * ========================================================
 *  Start of the helper functions for the MER
 * ========================================================
 */
void mer_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, FrameInfo *window, TileInfo *tile, DaBlockTile *da,
                        uint16_t offset_x, uint16_t offset_y)
{
	uint16_t start_hor;
	uint16_t end_hor;
	uint32_t addr_per_row;
	uint32_t addr_offset_y;
	if (tile->first_out_x >= cfg->search_range) {
		start_hor = tile->first_out_x - cfg->search_range;
	} else {
		start_hor = 0;
	}
	if ((tile->last_out_x + 1) + BLOCK_WIDTH + cfg->search_range <= window->width) {
		end_hor = (tile->last_out_x + 1) + BLOCK_WIDTH + cfg->search_range;
	} else {
		end_hor = window->width;
	}
	da->width = end_hor - start_hor;
	da->fifo_flush_len = da->width / BLOCK_WIDTH * cfg->fifo_per_block;
	da->pixel_flush_len = da->width * BLOCK_WIDTH;
	addr_per_row = round_up_base(frame->width, MACRO_BLOCK_WIDTH) / BLOCK_WIDTH * cfg->fifo_per_block;
	da->flush_addr_skip = addr_per_row - da->fifo_flush_len;
	addr_offset_y = offset_y / (1 << cfg->bank_group_type) / BLOCK_HEIGHT * addr_per_row;
	da->addr_add = (start_hor + offset_x) / BLOCK_WIDTH * cfg->fifo_per_block + addr_offset_y;
	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

void mer_set_tile_csr(volatile CsrBankMer *csr, DaBlockTile *da, uint32_t init_addr)
{
	uint32_t linear_addr = (init_addr >> da->phy_to_linear_shift) + da->addr_add;
	csr->ini_addr_linear_0 = linear_addr;
	csr->ini_addr_linear_1 = linear_addr;
	csr->ini_addr_linear_2 = linear_addr;
	csr->ini_addr_linear_3 = linear_addr;
	csr->ini_addr_linear_4 = linear_addr;
	csr->ini_addr_linear_5 = linear_addr;
	csr->ini_addr_linear_6 = linear_addr;
	csr->ini_addr_linear_7 = linear_addr;

	csr->width = da->width;
	csr->fifo_flush_len = da->fifo_flush_len;
	csr->pixel_flush_len = da->pixel_flush_len;
	csr->flush_addr_skip = da->flush_addr_skip;
}

void mer_set_frame_csr(volatile CsrBankMer *csr, DramAgentConfig *cfg, FrameInfo *frame)
{
	csr->col_addr_type = cfg->col_addr_type;
	csr->bank_interleave_type = cfg->bank_interleave_type;
	csr->bank_group_type = cfg->bank_group_type;
	csr->height = frame->height;

	csr->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;
	csr->msb_only = cfg->msb_only;
	csr->y_only = cfg->y_only;

	csr->access_end_sel = cfg->access_end_sel;
	csr->target_burst_len = cfg->target_burst_len;
	csr->target_fifo_level = cfg->target_fifo_level;
	csr->fifo_full_level = cfg->fifo_full_level;
}
/*
 * ========================================================
 *  Start of the helper functions for the MV8W
 * ========================================================
 */
uint32_t calc_mvw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent)
{
	uint32_t bank_group_num = (1 << dram_agent->bank_group_type);
	uint32_t bank_interleaving_num = (1 << dram_agent->bank_interleave_type);
	uint32_t blk_num_hor = round_up_base(width, MACRO_BLOCK_WIDTH) / BLOCK_WIDTH;
	uint32_t blk_num_ver = round_up_base(height, MACRO_BLOCK_HEIGHT) / BLOCK_HEIGHT;
	uint32_t word_per_row = round_up_div(blk_num_hor, MV_PER_WORD);
	uint32_t blk_per_group = round_up_div(blk_num_ver, bank_group_num);
	uint32_t addr_per_group = word_per_row * blk_per_group * (DA_FIFO_WORD / 8);
	uint32_t addr_per_group_align = round_up_base(addr_per_group, DRAM_PAGE_SIZE * bank_interleaving_num);
	uint32_t size = addr_per_group_align * bank_group_num;

	return size;
}

void mv8w_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaLinearTile *da)
{
	uint16_t addr_per_line;
	da->width = tile->tile_out_width / BLOCK_WIDTH;
	da->fifo_start_phase = (tile->first_out_x / BLOCK_WIDTH) % MV_PER_WORD;
	da->fifo_end_phase = ((tile->last_out_x + 1) / BLOCK_WIDTH - 1) % MV_PER_WORD;
	da->pixel_flush_len = da->width + da->fifo_start_phase + (MV_PER_WORD - 1 - da->fifo_end_phase);
	da->fifo_flush_len = da->pixel_flush_len / MV_PER_WORD;
	addr_per_line = round_up_div((frame->width / BLOCK_WIDTH), MV_PER_WORD);
	da->flush_addr_skip = addr_per_line - da->fifo_flush_len;
	da->addr_add = (tile->first_out_x / BLOCK_WIDTH) / MV_PER_WORD;
	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

void mv8w_set_tile_csr(volatile CsrBankMv8w *csr, DaLinearTile *da, uint32_t init_addr)
{
	uint32_t linear_addr = (init_addr >> da->phy_to_linear_shift) + da->addr_add;
	csr->ini_addr_linear_0 = linear_addr;
	csr->ini_addr_linear_1 = linear_addr;
	csr->ini_addr_linear_2 = linear_addr;
	csr->ini_addr_linear_3 = linear_addr;
	csr->ini_addr_linear_4 = linear_addr;
	csr->ini_addr_linear_5 = linear_addr;
	csr->ini_addr_linear_6 = linear_addr;
	csr->ini_addr_linear_7 = linear_addr;
	csr->width = da->width;
	csr->h_start = 0;
	csr->h_end = da->width - 1;
	csr->fifo_flush_len = da->fifo_flush_len;
	csr->pixel_flush_len = da->pixel_flush_len;
	csr->flush_addr_skip = da->flush_addr_skip;
	csr->fifo_start_phase = da->fifo_start_phase;
	csr->fifo_end_phase = da->fifo_end_phase;
}

void mv8w_set_frame_csr(volatile CsrBankMv8w *csr, DramAgentConfig *cfg, FrameInfo *frame)
{
	csr->col_addr_type = cfg->col_addr_type;
	csr->bank_interleave_type = cfg->bank_interleave_type;
	csr->bank_group_type = cfg->bank_group_type;
	csr->height = frame->height / BLOCK_WIDTH;
	csr->v_start = 0;
	csr->v_end = csr->height - 1;

	csr->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;
	csr->access_end_sel = cfg->access_end_sel;
	csr->target_burst_len = cfg->target_burst_len;
	csr->target_fifo_level = cfg->target_fifo_level;
	csr->fifo_full_level = cfg->fifo_full_level;
}
/*
 * ========================================================
 *  Start of the helper functions for the MV8R
 * ========================================================
 */
void mv8r_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaLinearTile *da)
{
	uint16_t start_hor;
	uint16_t end_hor;
	uint16_t addr_per_line;
	if (tile->first_out_x >= ME_FIXED_MVR_EXTEND_DIST * BLOCK_WIDTH) {
		start_hor = tile->first_out_x - ME_FIXED_MVR_EXTEND_DIST * BLOCK_WIDTH;
	} else {
		start_hor = 0;
	}
	if (tile->last_out_x + BLOCK_WIDTH + ME_FIXED_MVR_EXTEND_DIST * BLOCK_WIDTH <= frame->width - 1) {
		end_hor = tile->last_out_x + BLOCK_WIDTH + ME_FIXED_MVR_EXTEND_DIST * BLOCK_WIDTH;
	} else {
		end_hor = frame->width - 1;
	}
	da->width = (end_hor - start_hor + 1) / BLOCK_WIDTH;
	da->fifo_start_phase = (start_hor / BLOCK_WIDTH) % MV_PER_WORD;
	da->fifo_end_phase = (end_hor / BLOCK_WIDTH) % MV_PER_WORD;
	da->pixel_flush_len = da->width;
	da->fifo_flush_len = (da->width + da->fifo_start_phase + (MV_PER_WORD - 1 - da->fifo_end_phase)) / MV_PER_WORD;
	addr_per_line = round_up_div((frame->width / BLOCK_WIDTH), MV_PER_WORD);
	da->flush_addr_skip = addr_per_line - da->fifo_flush_len;
	da->addr_add = (start_hor / BLOCK_WIDTH) / MV_PER_WORD;
	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

void mv8r_set_tile_csr(volatile CsrBankMv8r *csr, DaLinearTile *da, uint32_t init_addr)
{
	uint32_t linear_addr = (init_addr >> da->phy_to_linear_shift) + da->addr_add;
	csr->ini_addr_linear_0 = linear_addr;
	csr->ini_addr_linear_1 = linear_addr;
	csr->ini_addr_linear_2 = linear_addr;
	csr->ini_addr_linear_3 = linear_addr;
	csr->ini_addr_linear_4 = linear_addr;
	csr->ini_addr_linear_5 = linear_addr;
	csr->ini_addr_linear_6 = linear_addr;
	csr->ini_addr_linear_7 = linear_addr;
	csr->width = da->width;
	csr->fifo_flush_len = da->fifo_flush_len;
	csr->pixel_flush_len = da->pixel_flush_len;
	csr->flush_addr_skip = da->flush_addr_skip;
	csr->fifo_start_phase = da->fifo_start_phase;
}

void mv8r_set_frame_csr(volatile CsrBankMv8r *csr, DramAgentConfig *cfg, FrameInfo *frame)
{
	csr->col_addr_type = cfg->col_addr_type;
	csr->bank_interleave_type = cfg->bank_interleave_type;
	csr->bank_group_type = cfg->bank_group_type;
	csr->height = frame->height / BLOCK_WIDTH;

	csr->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;
	csr->access_end_sel = cfg->access_end_sel;
	csr->target_burst_len = cfg->target_burst_len;
	csr->target_fifo_level = cfg->target_fifo_level;
	csr->fifo_full_level = cfg->fifo_full_level;
}
/*
 * ========================================================
 *  Start of the helper functions for the VENC_MVW
 * ========================================================
 */
void venc_mvw_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaLinearTile *da,
                             uint16_t offset_x, uint16_t offset_y, int is_last_tile)
{
	uint32_t block_per_line;
	uint32_t addr_per_line;
	uint32_t addr_offset_y;
	if (is_last_tile && frame->width % MACRO_BLOCK_WIDTH != 0) {
		da->width = (tile->tile_out_width + MACRO_BLOCK_WIDTH) / SUBBLOCK_WIDTH * SB_PER_MB;
	} else {
		da->width = tile->tile_out_width / SUBBLOCK_WIDTH * SB_PER_MB;
	}
	da->pixel_flush_len = da->width;
	da->fifo_flush_len = round_up_div(da->pixel_flush_len, MV_PER_WORD);
	block_per_line = round_up_div(frame->width, MACRO_BLOCK_WIDTH) * SB_PER_MB * SB_PER_MB;
	addr_per_line = round_up_div(block_per_line, MV_PER_WORD);
	da->flush_addr_skip = addr_per_line - da->fifo_flush_len;
	addr_offset_y = offset_y / MACRO_BLOCK_HEIGHT / (1 << cfg->bank_group_type) * addr_per_line;
	da->addr_add = round_up_div(((tile->first_out_x + offset_x) / SUBBLOCK_WIDTH * SB_PER_MB), MV_PER_WORD) +
	               addr_offset_y;
	da->phy_to_linear_shift = cfg->phy_to_linear_shift;
}

void venc_mvw_set_tile_csr(volatile CsrBankVenc_mvw *csr, DaLinearTile *da, uint32_t init_addr)
{
	uint32_t linear_addr = (init_addr >> da->phy_to_linear_shift) + da->addr_add;
	csr->ini_addr_linear_0 = linear_addr;
	csr->ini_addr_linear_1 = linear_addr;
	csr->ini_addr_linear_2 = linear_addr;
	csr->ini_addr_linear_3 = linear_addr;
	csr->ini_addr_linear_4 = linear_addr;
	csr->ini_addr_linear_5 = linear_addr;
	csr->ini_addr_linear_6 = linear_addr;
	csr->ini_addr_linear_7 = linear_addr;
	csr->width = da->width;
	csr->h_start = 0;
	csr->h_end = da->width - 1;
	csr->fifo_flush_len = da->fifo_flush_len;
	csr->pixel_flush_len = da->pixel_flush_len;
	csr->flush_addr_skip = da->flush_addr_skip;
}

void venc_mvw_set_frame_csr(volatile CsrBankVenc_mvw *csr, DramAgentConfig *cfg, FrameInfo *frame)
{
	csr->col_addr_type = cfg->col_addr_type;
	csr->bank_interleave_type = cfg->bank_interleave_type;
	csr->bank_group_type = cfg->bank_group_type;
	csr->height = round_up_div(frame->height, MACRO_BLOCK_WIDTH);
	csr->v_start = 0;
	csr->v_end = csr->height - 1;

	csr->ini_addr_bank_offset = INI_ADDR_BANK_OFFSET;
	csr->access_end_sel = cfg->access_end_sel;
	csr->target_burst_len = cfg->target_burst_len;
	csr->target_fifo_level = cfg->target_fifo_level;
	csr->fifo_full_level = cfg->fifo_full_level;
}
/*
 * ========================================================
 *  End of the helper functions for each DRAM agent
 * ========================================================
 */
static int calc_max_search_range(struct isp_frame_table *ftbl)
{
	int SR_0;
	int SR_1;

	/* A frame must have at least two tiles for Kyoto MCVP */
	SR_0 = ftbl->post_sc[1].first_out_x;
	SR_1 = ftbl->frame_width_o - (ftbl->post_sc[ftbl->tile_n - 2].last_out_x + 1 + BLOCK_WIDTH);

	return MIN(128, MIN(SR_0, SR_1));
}

void isp_calc_da_tile_info(struct isp_frame_table *ftbl)
{
	struct earlyvideo_drvdata *drvdata = &g_earlyvideo_drvdata;
	struct frame_info f_info;
	struct tile_da_reg *tile_reg = ftbl->tile_da_reg;
	struct dram_agent_config *ispr_da_cfg = (ftbl->idx == 0) ? &drvdata->da_cfg[DRAM_AGENT_ISPR] :
	                                                           &drvdata->da_cfg[DRAM_AGENT_INTER];
	struct dram_agent_config *vpw_da_cfg = (ftbl->idx == 0) ? &drvdata->da_cfg[DRAM_AGENT_INTER] :
	                                                          &drvdata->da_cfg[DRAM_AGENT_VPW];
	struct tile_info *tile = NULL;
	uint8_t t;

	/* ISPR tiles */
	f_info.width = ftbl->frame_width_i;
	f_info.height = ftbl->frame_height_i;
	f_info.bit_depth = 8;
	if (ftbl->start_ispr[0]) {
		for (t = 0; t < ftbl->tile_n; t++) {
			tile = &ftbl->pre_sc[t];
			pxr_calc_tile_info(ispr_da_cfg, &f_info, tile, &tile_reg[t].ispr[0]);
		}
	}
	if (ftbl->start_ispr[1]) {
		for (t = 0; t < ftbl->tile_n; t++) {
			tile = &ftbl->pre_sc[t];
			pxr_calc_tile_info(ispr_da_cfg, &f_info, tile, &tile_reg[t].ispr[1]);
		}
	}

	f_info.width = ftbl->frame_width_o;
	f_info.height = ftbl->frame_height_o;
	f_info.bit_depth = 8;
	/* MCVP tiles */
	if (ftbl->start_mcvp) {
		drvdata->da_cfg[DRAM_AGENT_MER].search_range = calc_max_search_range(ftbl);
		for (t = 0; t < ftbl->tile_n; t++) {
			tile = &ftbl->post_sc[t];
			mer_calc_tile_info(&drvdata->da_cfg[DRAM_AGENT_MER], &f_info, &f_info, tile, &tile_reg[t].mer,
			                   0, 0);
			nrw_calc_tile_info(&drvdata->da_cfg[DRAM_AGENT_NRW], &f_info, tile, &tile_reg[t].nrw, 0, 0);
			mv8w_calc_tile_info(&drvdata->da_cfg[DRAM_AGENT_MV8W], &f_info, tile, &tile_reg[t].mv8w);
			mv8r_calc_tile_info(&drvdata->da_cfg[DRAM_AGENT_MV8R], &f_info, tile, &tile_reg[t].mv8r);
			venc_mvw_calc_tile_info(&drvdata->da_cfg[DRAM_AGENT_VENC_MVW], &f_info, tile,
			                        &tile_reg[t].venc_mvw, 0, 0, (t == (ftbl->tile_n - 1)));
		}
	}
	/* VPW tiles */
	if (ftbl->start_vpw[0]) {
		for (t = 0; t < ftbl->tile_n; t++) {
			tile = &ftbl->post_sc[t];
			pxw_calc_tile_info(vpw_da_cfg, &f_info, tile, &tile_reg[t].vpw[0]);
		}
	}
	if (ftbl->start_vpw[1]) {
		for (t = 0; t < ftbl->tile_n; t++) {
			tile = &ftbl->post_sc[t];
			pxw_calc_tile_info(vpw_da_cfg, &f_info, tile, &tile_reg[t].vpw[1]);
		}
	}
}

void is_init_dram_agent(void)
{
	struct dram_agent_config *isw_cfg = &g_earlyvideo_drvdata.da_cfg[DRAM_AGENT_ISW];
	struct earlyvideo_shm_segment *segment = NULL;
	volatile struct csr_bank_pxw *isw = NULL;
	struct frame_info f_info;
	uint8_t path;

	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		segment = &g_earlyvideo_drvdata.shm_ptr->segments[path];
		isw = g_earlyvideo_drvdata.is_csr.iswroi[path];

		f_info.width = segment->width;
		f_info.height = segment->height * segment->uboot_capture_num;
		f_info.bit_depth = 8;

		pxw_set_frame_csr(isw, isw_cfg, &f_info);

		isw->irq_mask_frame_end = 1;
		isw->irq_mask_bw_insufficient = 1;
		isw->irq_mask_overflow = 1;
		isw->irq_mask_access_violation = 1;
		isw->irq_mask_burst_fifo_full = 1;
		isw->frame_start_mode = 1;
		isw->pixel_flush_len = segment->width;
		if (isw->msb_only) {
			isw->fifo_end_phase = (segment->width - 1) % 8;
			isw->fifo_flush_len = isw->pixel_flush_len / 8;
			isw->fifo_flush_len_last = 0;
			isw->package_size_last = 0;
		} else {
			isw->fifo_end_phase = (segment->width - 1) % 32;
			isw->fifo_flush_len = isw->pixel_flush_len / 8 + isw->pixel_flush_len / 32;
			isw->fifo_flush_len_last = 5;
			isw->package_size_last = 5;
		}
		isw->fifo_start_phase = 0;
		isw->width = segment->width;
		isw->h_end = segment->width - 1;

		isw->ini_addr_linear_0 = segment->raw_addr >> isw_cfg->phy_to_linear_shift;
	}
}