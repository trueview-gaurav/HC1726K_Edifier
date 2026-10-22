/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_COORDR_H_
#define SAPPORO_COORDR_H_

#include "csr_bank_coordr.h"
#include "da_utils.h"

#ifdef __KERNEL__
#include <linux/types.h>
void coordr_set_tile_csr(volatile CsrBankCoordr *csr, DaSampleTile *da, uint32_t init_addr);
#else
#include <stdint.h>
void coordr_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaSampleTile *da);
void coordr_set_frame_csr(volatile CsrBankCoordr *csr, DramAgentConfig *cfg, FrameInfo *frame);
#endif /* __KERNEL__ */

#endif /* SAPPORO_COORDR_H_ */
