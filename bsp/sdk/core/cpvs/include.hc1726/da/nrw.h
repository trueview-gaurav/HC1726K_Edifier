/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_NRW_H_
#define SAPPORO_NRW_H_

#include "da_utils.h"
#include "csr_bank_nrw.h"

#ifdef __KERNEL__
void nrw_set_tile_csr(volatile CsrBankNrw *csr, DaBlockTile *da, uint32_t init_addr);
uint32_t calc_nrw_buffer_size(const uint32_t width, const uint32_t height, const struct dram_agent_config *dram_agent);
#else
void nrw_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaBlockTile *da, uint16_t offset_x,
                        uint16_t offset_y);
void nrw_set_frame_csr(volatile CsrBankNrw *csr, DramAgentConfig *cfg, FrameInfo *frame);
#endif /* __KERNEL__ */

#endif /* SAPPORO_NRW_H_ */
