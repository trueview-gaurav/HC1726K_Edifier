/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_PXR_H_
#define SAPPORO_PXR_H_

#include "csr_bank_pxr.h"
#include "da_utils.h"

void pxr_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaPixelTile *da);
void pxr_calc_transform_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaPixelTile *da);
void pxr_set_tile_csr(volatile CsrBankPxr *pxr, DaPixelTile *tile, uint32_t init_addr);
void pxr_set_frame_csr(volatile CsrBankPxr *pxr, DramAgentConfig *cfg, FrameInfo *frame);

#endif /* SAPPORO_PXR_H_ */
