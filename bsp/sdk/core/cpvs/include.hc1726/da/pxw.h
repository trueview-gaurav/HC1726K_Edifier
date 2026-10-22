/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_PXW_H_
#define SAPPORO_PXW_H_

#include "csr_bank_pxw.h"
#include "da_utils.h"

uint32_t calc_pxw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent);

void pxw_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaPixelTile *da);
void pxw_calc_tile_info_using_tiw(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaPixelTile *da);
void pxw_set_tile_csr(volatile CsrBankPxw *pxw, DaPixelTile *da, uint32_t init_addr);
void pxw_set_frame_csr(volatile CsrBankPxw *pxw, DramAgentConfig *cfg, FrameInfo *frame);

#endif /* SAPPORO_PXW_H_ */
