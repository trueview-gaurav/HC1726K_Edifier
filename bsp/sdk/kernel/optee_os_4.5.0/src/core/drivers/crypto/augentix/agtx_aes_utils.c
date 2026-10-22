/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <trace.h>
#include <util.h>
#include <mm/core_memprot.h>

#include <drivers/crypto/agtx_aes_utils.h>
#include <drivers/agtx_delay.h>

volatile struct csr_bank_aes_enc *g_aes_enc_reg = NULL;
volatile struct csr_bank_aes_dec *g_aes_dec_reg = NULL;
volatile struct csr_bank_aes_codec *g_aes_codec_reg = NULL;
volatile struct csr_bank_qspir *g_linear_r_da_reg = NULL;
volatile struct csr_bank_qspiw *g_linear_w_da_reg = NULL;
volatile struct csr_bank_lli *g_lli_reg = NULL;
volatile struct csr_bank_darb *g_darb_reg = NULL;

void darb_init(void)
{
	/* Use the DRAM configuration correctly initialized in SPL */
	g_linear_r_da_reg->bank_addr_type = g_darb_reg->bank_addr_type;
	g_linear_w_da_reg->bank_addr_type = g_darb_reg->bank_addr_type;
	g_linear_r_da_reg->col_addr_type = g_darb_reg->col_addr_type;
	g_linear_w_da_reg->col_addr_type = g_darb_reg->col_addr_type;
}

void clear_da_irq(void)
{
	/* clear linear read DA IRQ */
	g_linear_r_da_reg->irq_clear_frame_end = ENABLE;
	g_linear_r_da_reg->irq_clear_bw_insufficient = ENABLE;
	g_linear_r_da_reg->irq_clear_access_violation = ENABLE;
	g_linear_r_da_reg->irq_clear_resp_error = ENABLE;

	/* clear linear write DA IRQ */
	g_linear_w_da_reg->irq_clear_frame_end = ENABLE;
	g_linear_w_da_reg->irq_clear_bw_insufficient = ENABLE;
	g_linear_w_da_reg->irq_clear_access_violation = ENABLE;
	g_linear_w_da_reg->irq_clear_resp_error = ENABLE;

	delay_ns(1000);
}

void mask_da_irq_except_for_frame_end(void)
{
	g_linear_r_da_reg->irq_mask_frame_end = DISABLE;
	g_linear_r_da_reg->irq_mask_bw_insufficient = ENABLE;
	g_linear_r_da_reg->irq_mask_access_violation = ENABLE;
	g_linear_r_da_reg->irq_mask_resp_error = ENABLE;

	g_linear_w_da_reg->irq_mask_frame_end = DISABLE;
	g_linear_w_da_reg->irq_mask_bw_insufficient = ENABLE;
	g_linear_w_da_reg->irq_mask_access_violation = ENABLE;
	g_linear_w_da_reg->irq_mask_resp_error = ENABLE;
}

size_t split_from_va(void *va, size_t len, struct segment *out)
{
	uint8_t *cur = va;
	size_t rem = len;
	size_t cnt = 0;
	size_t page_off, chunk;

	while (rem && cnt < MAX_PAGE_SEG) {
		paddr_t pa = virt_to_phys(cur);
		if (!pa)
			return 0;

		page_off = (vaddr_t)cur & (SMALL_PAGE_SIZE - 1);
		chunk = MIN(SMALL_PAGE_SIZE - page_off, rem);

		if (cnt && out[cnt - 1].paddr + out[cnt - 1].size == pa) {
			out[cnt - 1].size += chunk;
		} else {
			out[cnt].paddr = pa;
			out[cnt].size = chunk;
			cnt++;
		}

		cur += chunk;
		rem -= chunk;
	}

	return cnt;
}

void build_secure_lli(const struct segment *src, size_t src_n, const struct segment *dst, size_t dst_n,
                      struct secure_lli *lli)
{
	size_t i = 0, j = 0, k = 0;
	size_t src_off = 0, dst_off = 0;
	size_t chunk;

	while (i < src_n && j < dst_n && k < MAX_LLI_SEG) {
		chunk = MIN(src[i].size - src_off, dst[j].size - dst_off);

		lli[k].src_addr = src[i].paddr + src_off;
		lli[k].dst_addr = dst[j].paddr + dst_off;
		lli[k].length = (chunk + 3) >> 2;
		lli[k].dma_sel = AES;
		lli[k].llp = 0;

		DMSG("src_addr: %p, dst_addr: %p, length: %u", (void *)lli[k].src_addr, (void *)lli[k].dst_addr, chunk);

		src_off += chunk;
		dst_off += chunk;

		if (src_off == src[i].size) {
			i++;
			src_off = 0;
		}
		if (dst_off == dst[j].size) {
			j++;
			dst_off = 0;
		}
		k++;
	}

	for (size_t idx = 0; idx < k - 1; idx++)
		lli[idx].llp = virt_to_phys(&lli[idx + 1]);
	lli[k - 1].llp = 0;
}