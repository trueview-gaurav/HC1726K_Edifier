#ifndef AGTX_VIDEO_DA_H_
#define AGTX_VIDEO_DA_H_

#include <stdlib.h>
#include <common.h>

#include "hw_dram.h"
#include "da_define.h"

#include "csr_bank_pxr.h"
#include "csr_bank_pxw.h"
#include "csr_bank_nrw.h"
#include "csr_bank_mer.h"
#include "csr_bank_mv8r.h"
#include "csr_bank_mv8w.h"
#include "csr_bank_venc_mvw.h"

void is_init_dram_agent(void);
void gen_da_setting(DramAgentConfig *dram_agent_table, const uint8_t start_item, const uint8_t end_item);

uint32_t calc_pxw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent,
                              uint8_t align);
uint32_t calc_mvw_buffer_size(uint32_t width, uint32_t height, const struct dram_agent_config *dram_agent);
void pxw_set_tile_csr(volatile CsrBankPxw *pxw, DaPixelTile *da, uint32_t init_addr);
void pxw_set_frame_csr(volatile CsrBankPxw *pxw, DramAgentConfig *cfg, FrameInfo *frame);
void pxr_set_tile_csr(volatile CsrBankPxr *pxr, DaPixelTile *da, uint32_t init_addr);
void pxr_set_frame_csr(volatile CsrBankPxr *pxr, DramAgentConfig *cfg, FrameInfo *frame);
void nrw_set_tile_csr(volatile CsrBankNrw *csr, DaBlockTile *da, uint32_t init_addr);
void nrw_set_frame_csr(volatile CsrBankNrw *csr, DramAgentConfig *cfg, FrameInfo *frame);
void mer_set_tile_csr(volatile CsrBankMer *csr, DaBlockTile *da, uint32_t init_addr);
void mer_set_frame_csr(volatile CsrBankMer *csr, DramAgentConfig *cfg, FrameInfo *frame);
void mv8w_set_tile_csr(volatile CsrBankMv8w *csr, DaLinearTile *da, uint32_t init_addr);
void mv8w_set_frame_csr(volatile CsrBankMv8w *csr, DramAgentConfig *cfg, FrameInfo *frame);
void mv8r_set_tile_csr(volatile CsrBankMv8r *csr, DaLinearTile *da, uint32_t init_addr);
void mv8r_set_frame_csr(volatile CsrBankMv8r *csr, DramAgentConfig *cfg, FrameInfo *frame);
void venc_mvw_set_tile_csr(volatile CsrBankVenc_mvw *csr, DaLinearTile *da, uint32_t init_addr);
void venc_mvw_set_frame_csr(volatile CsrBankVenc_mvw *csr, DramAgentConfig *cfg, FrameInfo *frame);

#endif /* AGTX_VIDEO_DA_H_ */