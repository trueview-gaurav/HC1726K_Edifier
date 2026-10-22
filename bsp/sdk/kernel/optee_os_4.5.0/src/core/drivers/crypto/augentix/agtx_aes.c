/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <initcall.h>
#include <trace.h>
#include <utee_defines.h>
#include <drvcrypt.h>
#include <drvcrypt_cipher.h>
#include <string.h>
#include <mm/core_memprot.h>
#include <tee/cache.h>
#include <io.h>

#include <drivers/crypto/agtx_aes.h>
#include <drivers/crypto/agtx_aes_utils.h>
#include <drivers/crypto/agtx_aes_key_expansion.h>
#include <drivers/agtx_delay.h>

register_phys_mem_pgdir(MEM_AREA_IO_SEC, AES_ENC_BASE, 0x400);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, AES_DEC_BASE, 0x400);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, AES_CODEC_BASE, 0x400);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, SDMA_QSPIR_BASE, 0x400);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, SDMA_QSPIW_BASE, 0x400);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, LLI_BASE, 0x400);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, DARB_BASE, 0x400);

static const uint32_t aes_mode_table[][2] = {
	/* [ECB] = */ { 0x00, 0x00 }, // encrypt, decrypt
	/* [CBC] = */ { 0x01, 0x01 },
	/* [CTR] = */ { 0x06, 0x07 },
};

TEE_Result agtx_aes_init(void);

static void agtx_aes_release_buffer(struct agtx_cipher_ctx *c_ctx)
{
	if (!c_ctx) {
		EMSG("ctx is NULL");
		return;
	}
	if (c_ctx->iv) {
		DMSG("Free IV buffer");
		free(c_ctx->iv);
		c_ctx->iv = NULL;
	}
	if (c_ctx->key) {
		DMSG("Free key buffer");
		free(c_ctx->key);
		c_ctx->key = NULL;
	}
}

static TEE_Result agtx_aes_allocate(void **ctx, uint32_t algo)
{
	struct agtx_cipher_ctx *c_ctx = NULL;

	c_ctx = (struct agtx_cipher_ctx *)calloc(1, sizeof(struct agtx_cipher_ctx));
	if (!c_ctx) {
		EMSG("Memory allocation failed");
		return TEE_ERROR_OUT_OF_MEMORY;
	}

	switch (algo) {
	case TEE_ALG_AES_ECB_NOPAD:
		c_ctx->algo = ECB;
		break;
	case TEE_ALG_AES_CBC_NOPAD:
		c_ctx->algo = CBC;
		break;
	case TEE_ALG_AES_CTR:
		c_ctx->algo = CTR;
		break;
	default:
		return TEE_ERROR_NOT_IMPLEMENTED;
	}

	*ctx = c_ctx;

	return TEE_SUCCESS;
}

static TEE_Result agtx_aes_initialize(struct drvcrypt_cipher_init *dinit)
{
	uint32_t *iv, *inverse_key, *key;
	uint8_t key_mode;
	volatile uint32_t *key_mode_reg, *key_regs, *iv_regs, *mode_reg;
	uint32_t aes_reg;

	struct agtx_cipher_ctx *c_ctx = dinit->ctx;

	if (!c_ctx) {
		EMSG("c_ctx is NULL");
		return TEE_ERROR_BAD_PARAMETERS;
	}

	if (dinit->key1.length == 24) {
		EMSG("192-bit key is not supported");
		return TEE_ERROR_NOT_SUPPORTED;
	}

	DMSG("encrypt/decrypt: %u", dinit->encrypt);

	key_mode = dinit->key1.length == 16 ? KEY_128 : KEY_256;
	c_ctx->key_len = dinit->key1.length;

	agtx_aes_release_buffer(c_ctx);

	iv = calloc(1, 16);
	if (!iv) {
		EMSG("IV memory allocation failed");
		return TEE_ERROR_OUT_OF_MEMORY;
	}
	if (c_ctx->algo != ECB) {
		memcpy(iv, dinit->iv.data, 16);
	}
	cache_operation(TEE_CACHECLEAN, iv, 16);
	c_ctx->iv = iv;

	if ((c_ctx->algo == ECB || c_ctx->algo == CBC) && !(dinit->encrypt)) {
		g_aes_codec_reg->mode = DECODE;
		aes_reg = (uint32_t)g_aes_dec_reg;

		key = calloc(1, dinit->key1.length);
		if (!key) {
			EMSG("Key memory allocation failed");
			return TEE_ERROR_OUT_OF_MEMORY;
		}

		memcpy(key, dinit->key1.data, dinit->key1.length);

		inverse_key = calloc(1, 32);
		if (!inverse_key) {
			EMSG("Inverse key memory allocation failed");
			return TEE_ERROR_OUT_OF_MEMORY;
		}

		if (key_mode == KEY_128) {
			aes_key_expansion(AES_CIPHER_128, key, inverse_key);
		} else {
			aes_key_expansion(AES_CIPHER_256, key, inverse_key);
		}
		free(key);
		cache_operation(TEE_CACHECLEAN, inverse_key, 32);
		c_ctx->key = inverse_key;
	} else {
		g_aes_codec_reg->mode = ENCODE;
		aes_reg = (uint32_t)g_aes_enc_reg;

		key = calloc(1, 32);
		if (!key) {
			EMSG("Key memory allocation failed");
			return TEE_ERROR_OUT_OF_MEMORY;
		}

		memcpy(key, dinit->key1.data, dinit->key1.length);
		cache_operation(TEE_CACHECLEAN, key, 32);
		c_ctx->key = key;
	}

	key_mode_reg = (uint32_t *)(aes_reg + 0x00C);
	*key_mode_reg = key_mode;

	key_regs = (uint32_t *)(aes_reg + 0x010);
	for (int i = 0; i < 8; i++)
		key_regs[i] = c_ctx->key[i];

	iv_regs = (uint32_t *)(aes_reg + 0x044);
	for (int i = 0; i < 4; i++)
		iv_regs[i] = c_ctx->iv[i];

	mode_reg = (uint32_t *)(aes_reg + 0x040);
	*mode_reg = (*mode_reg & ~0x7) | (aes_mode_table[c_ctx->algo][dinit->encrypt ? 0 : 1] & 0x7);

	g_aes_codec_reg->word_swap = 0;
	g_aes_codec_reg->byte_swap = 0;

	return TEE_SUCCESS;
}

static void agtx_aes_free(void *ctx)
{
	struct agtx_cipher_ctx *c_ctx = ctx;

	free(c_ctx->key);
	free(c_ctx->iv);
	free(c_ctx);
}

static TEE_Result agtx_aes_update(struct drvcrypt_cipher_update *dupdate)
{
	size_t src_n, dst_n;
	bool is_src_aligned, is_dst_aligned;
	uint8_t *aligned_src, *aligned_dst;

	struct segment src_seg[MAX_PAGE_SEG];
	struct segment dst_seg[MAX_PAGE_SEG];
	struct secure_lli lli[MAX_LLI_SEG] __attribute__((aligned(8)));

	is_src_aligned = (virt_to_phys(dupdate->src.data) & 0x7) == 0;
	is_dst_aligned = (virt_to_phys(dupdate->dst.data) & 0x7) == 0;

	if (!is_src_aligned) {
		aligned_src = memalign(8, dupdate->src.length);
	} else {
		aligned_src = dupdate->src.data;
	}
	if (!is_dst_aligned) {
		aligned_dst = memalign(8, dupdate->dst.length);
	} else {
		aligned_dst = dupdate->dst.data;
	}

	if (!dupdate->src.data || !dupdate->dst.data) {
		EMSG("Invalid src or dst address");
		return TEE_ERROR_BAD_PARAMETERS;
	}

	if (!is_src_aligned) {
		memcpy(aligned_src, dupdate->src.data, dupdate->src.length);
	}

	src_n = split_from_va(aligned_src, dupdate->src.length, src_seg);
	dst_n = split_from_va(aligned_dst, dupdate->dst.length, dst_seg);

	build_secure_lli(src_seg, src_n, dst_seg, dst_n, lli);
	cache_operation(TEE_CACHECLEAN, lli, sizeof(struct secure_lli) * MAX_LLI_SEG);

	/* clear DA IRQ */
	clear_da_irq();

	/* mask DA IRQ except for frame end */
	mask_da_irq_except_for_frame_end();

	/* disable mask of AES CODEC frame end IRQ */
	g_aes_codec_reg->irq_mask_frame_end = DISABLE;

	/* clear AES IRQ */
	g_aes_codec_reg->irq_clear_frame_end = ENABLE;

	g_lli_reg->first_lli_addr = virt_to_phys(lli) >> 3;

	/* clear frame end */
	g_lli_reg->irq_clr_all_lli_done = ENABLE;
	delay_ns(1000);
	cache_operation(TEE_CACHECLEAN, aligned_src, dupdate->src.length);
	cache_operation(TEE_CACHECLEAN, aligned_dst, dupdate->dst.length);

	/* frame start */
	g_lli_reg->lli_start = ENABLE;

	/* polling for frame end */
	while (g_lli_reg->status_all_lli_done != ENABLE) {
		if (g_lli_reg->status_one_lli_done == ENABLE) {
			g_lli_reg->irq_clr_one_lli_done = ENABLE;
		}
	}

	/* clear frame end */
	g_lli_reg->irq_clr_all_lli_done = ENABLE;
	delay_ns(1000);
	cache_operation(TEE_CACHEINVALIDATE, aligned_dst, dupdate->dst.length);

	if (!is_src_aligned) {
		free(aligned_src);
	}
	if (!is_dst_aligned) {
		memcpy(dupdate->dst.data, aligned_dst, dupdate->dst.length);
		free(aligned_dst);
	}

	return TEE_SUCCESS;
}

static void agtx_aes_finalize(void *ctx __unused)
{
}

static void agtx_aes_copy_state(void *dst_ctx, void *src_ctx)
{
	uint32_t *iv, *key;

	struct agtx_cipher_ctx *dst_c_ctx = dst_ctx;
	struct agtx_cipher_ctx *src_c_ctx = src_ctx;

	dst_c_ctx->key_mode = src_c_ctx->key_mode;
	dst_c_ctx->encrypt = src_c_ctx->encrypt;
	dst_c_ctx->key_len = src_c_ctx->key_len;

	agtx_aes_release_buffer(dst_c_ctx);

	iv = (uint32_t *)calloc(1, 16);
	if (!iv) {
		EMSG("IV memory allocation failed");
		return TEE_ERROR_OUT_OF_MEMORY;
	}

	memcpy(iv, src_c_ctx->iv, 16);
	dst_c_ctx->iv = iv;

	key = (uint32_t *)calloc(1, 32);
	if (!key) {
		EMSG("Key memory allocation failed");
		return TEE_ERROR_OUT_OF_MEMORY;
	}

	memcpy((uint8_t *)key, src_c_ctx->key, src_c_ctx->key_len);
	dst_c_ctx->key = key;
}

static struct drvcrypt_cipher driver_cipher = {
	.alloc_ctx = agtx_aes_allocate,
	.free_ctx = agtx_aes_free,
	.init = agtx_aes_initialize,
	.update = agtx_aes_update,
	.final = agtx_aes_finalize,
	.copy_state = agtx_aes_copy_state,
};

TEE_Result agtx_aes_init(void)
{
	TEE_Result ret = TEE_SUCCESS;

	g_aes_enc_reg = (struct csr_bank_aes_enc *)phys_to_virt(AES_ENC_BASE, MEM_AREA_IO_SEC, 0x400);
	g_aes_dec_reg = (struct csr_bank_aes_dec *)phys_to_virt(AES_DEC_BASE, MEM_AREA_IO_SEC, 0x400);
	g_aes_codec_reg = (struct csr_bank_aes_codec *)phys_to_virt(AES_CODEC_BASE, MEM_AREA_IO_SEC, 0x400);
	g_linear_r_da_reg = (struct csr_bank_qspir *)phys_to_virt(SDMA_QSPIR_BASE, MEM_AREA_IO_SEC, 0x400);
	g_linear_w_da_reg = (struct csr_bank_qspiw *)phys_to_virt(SDMA_QSPIW_BASE, MEM_AREA_IO_SEC, 0x400);
	g_lli_reg = (struct csr_bank_lli *)phys_to_virt(LLI_BASE, MEM_AREA_IO_SEC, 0x400);
	g_darb_reg = (struct csr_bank_darb *)phys_to_virt(DARB_BASE, MEM_AREA_IO_SEC, 0x400);

	ret = drvcrypt_register_cipher(&driver_cipher);
	if (ret) {
		EMSG("AGTX AES driver registration failed with: %u", ret);
		return ret;
	}

	darb_init();

	return ret;
}
service_init_crypto(agtx_aes_init);
