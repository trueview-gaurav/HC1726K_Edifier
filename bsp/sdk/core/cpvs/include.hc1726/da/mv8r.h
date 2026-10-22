/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_MV8R_H_
#define SAPPORO_MV8R_H_

#include "da_utils.h"
#include "csr_bank_mv8r.h"

#ifdef __KERNEL__
void mv8r_set_tile_csr(volatile CsrBankMv8r *csr, DaLinearTile *da, uint32_t init_addr);
#else
void mv8r_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaLinearTile *da);
void mv8r_set_frame_csr(volatile CsrBankMv8r *csr, DramAgentConfig *cfg, FrameInfo *frame);
#endif /* __KERNEL__ */

#endif /* SAPPORO_MV8R_H_ */
