/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <drivers/crypto/csr_bank_aes_codec.h>
#include <drivers/crypto/csr_bank_aes_dec.h>
#include <drivers/crypto/csr_bank_aes_enc.h>
#include <drivers/crypto/csr_bank_lli.h>
#include <drivers/crypto/csr_bank_qspir.h>
#include <drivers/crypto/csr_bank_qspiw.h>
#include <drivers/crypto/csr_bank_darb.h>

#define AES_ENC_BASE 0x835F0400
#define AES_DEC_BASE 0x835F0800
#define AES_CODEC_BASE 0x835F0C00
#define SDMA_QSPIR_BASE 0x835F1000
#define SDMA_QSPIW_BASE 0x835F1400
#define LLI_BASE 0x835F1800
#define DARB_BASE 0x81300000

#define ENABLE 1
#define DISABLE 0

#define MAX_PAGE_SEG 32
#define MAX_LLI_SEG 64

enum DMA_SEL { BYPASS = 0, AES };

extern volatile struct csr_bank_aes_enc *g_aes_enc_reg;
extern volatile struct csr_bank_aes_dec *g_aes_dec_reg;
extern volatile struct csr_bank_aes_codec *g_aes_codec_reg;
extern volatile struct csr_bank_qspir *g_linear_r_da_reg;
extern volatile struct csr_bank_qspiw *g_linear_w_da_reg;
extern volatile struct csr_bank_lli *g_lli_reg;
extern volatile struct csr_bank_darb *g_darb_reg;

struct segment {
	paddr_t paddr;
	size_t size;
};

struct secure_lli {
	uint32_t llp; // next LLI address, 8-byte align [30:3]
	uint32_t dma_sel; // 0: bypass; 1: AES
	uint32_t length; // pixel_flush_len for src and dst
	uint32_t src_addr; // address for src, 8-byte align
	uint32_t dst_addr; // address for dst, 8-byte align
	uint32_t reserved_0;
	uint32_t reserved_1;
	uint32_t reserved_2;
	uint32_t reserved_3;
	uint32_t reserved_4;
	uint32_t reserved_5;
	uint32_t reserved_6;
	uint32_t reserved_7;
	uint32_t reserved_8;
	uint32_t reserved_9;
	uint32_t reserved_10;
};

void darb_init(void);
void clear_da_irq(void);
void mask_da_irq_except_for_frame_end(void);

size_t split_from_va(void *va, size_t len, struct segment *out);
void build_secure_lli(const struct segment *src, size_t src_n, const struct segment *dst, size_t dst_n,
                      struct secure_lli *lli);
