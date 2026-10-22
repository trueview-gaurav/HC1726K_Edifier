/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_MV8W_H_
#define SAPPORO_MV8W_H_

#include "da_utils.h"
#include "csr_bank_mv8w.h"

#ifdef __KERNEL__
uint32_t calc_mvw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent);
void mv8w_set_tile_csr(volatile CsrBankMv8w *csr, DaLinearTile *da, uint32_t init_addr);
#else
void mv8w_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaLinearTile *da);
void mv8w_set_frame_csr(volatile CsrBankMv8w *csr, DramAgentConfig *cfg, FrameInfo *frame);
#endif /* __KERNEL__ */

#endif /* SAPPORO_MV8W_H_ */
