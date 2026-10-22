/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_VENC_MVW_H_
#define SAPPORO_VENC_MVW_H_

#include "da_utils.h"
#include "csr_bank_mv8w.h"
#include "mpi_enc.h"

#ifdef __KERNEL__
void venc_mvw_set_tile_csr(volatile CsrBankMv8w *csr, DaLinearTile *da, uint32_t init_addr);
uint32_t calc_venc_mvw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent,
                                   MPI_VENC_TYPE_E codec);
#endif /* __KERNEL__ */
void venc_mvw_calc_tile_info(DramAgentConfig *cfg, FrameInfo *frame, TileInfo *tile, DaLinearTile *da,
                             uint16_t offset_x, uint16_t offset_y, int is_last_tile, MPI_VENC_TYPE_E codec);
void venc_mvw_set_frame_csr(volatile CsrBankMv8w *csr, DramAgentConfig *cfg, FrameInfo *frame, MPI_VENC_TYPE_E codec);

#endif /* SAPPORO_VENC_MVW_H_ */
