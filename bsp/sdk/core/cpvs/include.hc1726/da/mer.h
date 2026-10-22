/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_MER_H_
#define SAPPORO_MER_H_

#include "da_utils.h"
#include "csr_bank_mer.h"

#ifdef __KERNEL__
void mer_set_tile_csr(volatile CsrBankMer *csr, DaBlockTile *da, uint32_t init_addr);
#else
void mer_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, FrameInfo *window, TileInfo *tile, DaBlockTile *da,
                        uint16_t offset_x, uint16_t offset_y);
void mer_set_frame_csr(volatile CsrBankMer *csr, DramAgentConfig *cfg, FrameInfo *frame);

#endif /* __KERNEL__ */

#endif /* SAPPORO_MER_H_ */
