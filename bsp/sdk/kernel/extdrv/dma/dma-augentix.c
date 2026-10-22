// SPDX-License-Identifier: GPL-2.0-only
/*
* Copyright (c) 2015-2025 Augentix Inc. All rights reserved.
*/

#include <linux/err.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/dmaengine.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of_dma.h>
#include <linux/version.h>
#include <asm/irq.h>

#include <linux/crypto.h>
#include <crypto/algapi.h>
#include <crypto/aes.h>
#include <crypto/ctr.h>

#include <linux/kthread.h>

#include "dmaengine.h"
#include "dma-augentix.h"
#include <linux/clk.h>
#include <linux/io.h>
#include <linux/delay.h>

#define EN_DBG_AES 0
struct dma_chan *memcpy_chan;

noinline void augentix_dma_stub(void)
{
	asm volatile("stub_start:\n"
	             "nop\n");
}
EXPORT_SYMBOL(augentix_dma_stub);

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
static void augentix_aes_complete(struct augentix_dma_engine *dev, int err);
#endif

static int setup_xfer_desc_next(struct augentix_dma_engine *pdma, struct augentix_dma_desc *d);

static bool xfer_done(struct augentix_dma_desc *d);

static int enable_dma_access(struct augentix_dma_engine *pdma);

static void *g_dma_engine = NULL;

static struct augentix_dma_channel *to_augentix_dma_chan(struct dma_chan *chan)
{
	return container_of(chan, struct augentix_dma_channel, chan);
}

static void augentix_dma_writel(struct augentix_dma_engine *pdma, unsigned val, unsigned offset)
{
	__raw_writel(val, pdma->base + offset);
}

static unsigned augentix_dma_readl(struct augentix_dma_engine *pdma, unsigned offset)
{
	return __raw_readl(pdma->base + offset);
}

static const struct of_device_id augentix_dma_of_dev_id[] = {
	{
	        .compatible = "augentix,dma",
	},
	{},
};
MODULE_DEVICE_TABLE(of, augentix_dma_of_dev_id);

static const u32 g_aes_rcon[] = { 0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000,
	                          0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000,
	                          0x6c000000, 0xd8000000, 0xab000000, 0xed000000, 0x9a000000 };

/* aes sbox and invert-sbox */
static const u8 g_aes_sbox[256] = {
	/* 0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F  */
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, 0xca, 0x82,
	0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, 0xb7, 0xfd, 0x93, 0x26,
	0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96,
	0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
	0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb,
	0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f,
	0x50, 0x3c, 0x9f, 0xa8, 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff,
	0xf3, 0xd2, 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, 0xe0, 0x32,
	0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, 0xe7, 0xc8, 0x37, 0x6d,
	0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6,
	0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
	0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e,
	0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f,
	0xb0, 0x54, 0xbb, 0x16
};

#define aes_sub_sbox(x) g_aes_sbox[x]

u32 aes_sub_dword(u32 val)
{
	u32 tmp = 0;
	tmp |= ((u32)aes_sub_sbox((u8)((val >> 0) & 0xFF))) << 0;
	tmp |= ((u32)aes_sub_sbox((u8)((val >> 8) & 0xFF))) << 8;
	tmp |= ((u32)aes_sub_sbox((u8)((val >> 16) & 0xFF))) << 16;
	tmp |= ((u32)aes_sub_sbox((u8)((val >> 24) & 0xFF))) << 24;
	return tmp;
}

u32 aes_rot_dword(u32 val)
{
	u32 tmp = val;
	return (val >> 8) | ((tmp & 0xFF) << 24);
}

void aes_key_expansion(u32 *key, u32 *result, u8 mode)
{
	u32 w[4 * 4 * 15] = { 0 };
	u32 t;
	int i = 0;
	int g_aes_rounds[] = { /* AES_CYPHER_128 */ 10,
		               /* AES_CYPHER_256 */ 14 };

	int g_aes_nk[] = { /* AES_CYPHER_128 */ 4,
		           /* AES_CYPHER_256 */ 8 };

	do {
		w[i] = key[i];
	} while (++i < g_aes_nk[mode]);

	do {
		if ((i % g_aes_nk[mode]) == 0) {
			t = aes_rot_dword(w[i - 1]);
			t = aes_sub_dword(t);
			t = t ^ BigtoLittle32(g_aes_rcon[i / g_aes_nk[mode] - 1]);
		} else if (g_aes_nk[mode] > 6 && (i % g_aes_nk[mode]) == 4) {
			t = aes_sub_dword(w[i - 1]);
		} else {
			t = w[i - 1];
		}
		w[i] = w[i - g_aes_nk[mode]] ^ t;
	} while (++i < 4 * (g_aes_rounds[mode] + 1));

	t = g_aes_nk[mode];
	i = 4 * (g_aes_rounds[mode] + 1) - 1;
	while (t) {
		result[t - 1] = w[i];
		t--;
		i--;
	}
}

static int set_aes_enc(struct augentix_dma_engine *pdma, u32 edian, u32 mode)
{
	u32 val = 0;

	val = (augentix_dma_readl(pdma, AES_ENC16_CTRL) & (~(0x00000307)));
	augentix_dma_writel(pdma, (val | edian | mode), AES_ENC16_CTRL);

	return 0;
}

static int set_aes_dec(struct augentix_dma_engine *pdma, u32 edian, u32 mode)
{
	u32 val = 0;

	val = (augentix_dma_readl(pdma, AES_DEC16_CTRL) & (~(0x00000307)));
	augentix_dma_writel(pdma, (val | edian | mode), AES_DEC16_CTRL);

	return 0;
}

static int set_aes_enc_init_vector(struct augentix_dma_engine *pdma, u32 *p_iv)
{
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 0)), AES_ENC17_IV_0);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 1)), AES_ENC18_IV_1);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 2)), AES_ENC19_IV_2);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 3)), AES_ENC20_IV_3);
	return 0;
}

static int set_aes_dec_init_vector(struct augentix_dma_engine *pdma, u32 *p_iv)
{
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 0)), AES_DEC17_IV_0);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 1)), AES_DEC18_IV_1);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 2)), AES_DEC19_IV_2);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_iv) + 3)), AES_DEC20_IV_3);
	return 0;
}

static int set_aes_enc_key(struct augentix_dma_engine *pdma, u32 *p_key)
{
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 0)), AES_ENC04_KEY_0);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 1)), AES_ENC05_KEY_1);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 2)), AES_ENC06_KEY_2);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 3)), AES_ENC07_KEY_3);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 4)), AES_ENC08_KEY_4);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 5)), AES_ENC09_KEY_5);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 6)), AES_ENC10_KEY_6);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key) + 7)), AES_ENC11_KEY_7);
	return 0;
}

static int set_aes_dec_key(struct augentix_dma_engine *pdma, u32 *p_key, int mode)
{
	u32 p_key_inv[8];
	aes_key_expansion(p_key, p_key_inv, mode);

	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 0)), AES_DEC04_KEY_0);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 1)), AES_DEC05_KEY_1);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 2)), AES_DEC06_KEY_2);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 3)), AES_DEC07_KEY_3);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 4)), AES_DEC08_KEY_4);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 5)), AES_DEC09_KEY_5);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 6)), AES_DEC10_KEY_6);
	augentix_dma_writel(pdma, AES_KEY_ENDIAN(*((p_key_inv) + 7)), AES_DEC11_KEY_7);
	return 0;
}

static int set_channel_operation_mode(struct augentix_dma_engine *pdma, int ch_num, unsigned int oper_mode)
{
	u32 val = 0;

	val = (augentix_dma_readl(pdma, DMA_CH_CTRL2(ch_num)) & (~(0x00000003))) | (oper_mode);
	augentix_dma_writel(pdma, val, DMA_CH_CTRL2(ch_num));

	return 0;
}

static int set_channel_access_mode(struct augentix_dma_engine *pdma, int ch_num, unsigned int access_mode)
{
	u32 val = 0;

	val = (augentix_dma_readl(pdma, DMA_CH_CTRL2(ch_num)) & (~(0x00000300))) | (access_mode);
	augentix_dma_writel(pdma, val, DMA_CH_CTRL2(ch_num));

	return 0;
}

#if 0
static int set_bank_interleave_type(struct augentix_dma_engine *pdma, int ch_num, unsigned int type)
{
	u32 val = 0;
	u32 clr_mask = 0;
	u32 shift = 0;

	if (ch_num < 4) {
		shift = 8 * ch_num;
		clr_mask = ~(0x3 << shift);
		val = (augentix_dma_readl(pdma, DMA46_BANK_INTER_TP_R_0) & (clr_mask)) | (type << shift);
		augentix_dma_writel(pdma, val, DMA46_BANK_INTER_TP_R_0);
		val = (augentix_dma_readl(pdma, DMA90_BANK_INTER_TP_W_0) & (clr_mask)) | (type << shift);
		augentix_dma_writel(pdma, val, DMA90_BANK_INTER_TP_W_0);
	} else {
		shift = 8 * (ch_num - 4);
		clr_mask = ~(0x3 << shift);
		val = (augentix_dma_readl(pdma, DMA47_BANK_INTER_TP_R_1) & (clr_mask)) | (type << shift);
		augentix_dma_writel(pdma, val, DMA47_BANK_INTER_TP_R_1);
		val = (augentix_dma_readl(pdma, DMA91_BANK_INTER_TP_W_1) & (clr_mask)) | (type << shift);
		augentix_dma_writel(pdma, val, DMA91_BANK_INTER_TP_W_1);
	}
	return 0;
}
#endif

static void dma_slave_config(struct augentix_dma_engine *pdma, struct dma_args *args)
{
	int i = 0;
	struct augentix_dma_channel *augentix_dmac;
	struct augentix_dma_desc *desc;
	if (args->oper_mode == DMA_NORMAL || args->oper_mode == DMA_NRW) {
		for (i = 0; i < MAX_DMA_ACCESS_CNT; i++) {
			set_channel_operation_mode(pdma, i, DMA_AES_MODE_BYPASS);
			augentix_dmac = &pdma->channel[i];
			desc = list_first_entry(&augentix_dmac->ld_free, struct augentix_dma_desc, node);
			if (args->oper_mode == DMA_NRW) {
				desc->loop = args->loop_cnt;
				desc->skip_r = args->flush_addr_skip_r;
				desc->skip_w = args->flush_addr_skip_w;
			} else {
				desc->loop = 1;
				desc->skip_r = 0;
				desc->skip_w = 0;
			}
		}
	} else if (args->oper_mode < DMA_MAX) {
		/* AES DEC */
		augentix_dmac = &pdma->channel[0];
		desc = list_first_entry(&augentix_dmac->ld_free, struct augentix_dma_desc, node);
		desc->loop = 1;
		desc->skip_r = 0;
		desc->skip_w = 0;
		if (args->oper_mode < DMA_AES_DEC_MAX) {
			for (i = 0; i < MAX_DMA_ACCESS_CNT; i++) {
				set_channel_operation_mode(pdma, i, DMA_AES_MODE_DEC);
			}

			if (args->aes_key_len == AES_KEYSIZE_128) {
				augentix_dma_writel(pdma, AES_KEY_128, AES_DEC03_KEY_MODE);
				set_aes_dec_key(pdma, args->aes_key, AES_KEY_128);
			} else {
				augentix_dma_writel(pdma, AES_KEY_256, AES_DEC03_KEY_MODE);
				set_aes_dec_key(pdma, args->aes_key, AES_KEY_256);
			}

			if (args->oper_mode == DMA_AES_ECB_DEC_BE || args->oper_mode == DMA_AES_ECB_DEC_LE) {
				if (args->oper_mode == DMA_AES_ECB_DEC_BE)
					set_aes_dec(pdma, AES_BIG_ENDIAN, AES_MODE_ECB);
				else
					set_aes_dec(pdma, AES_LIT_ENDIAN, AES_MODE_ECB);
			} else if (args->oper_mode == DMA_AES_CBC_DEC_BE || args->oper_mode == DMA_AES_CBC_DEC_LE) {
				set_aes_dec_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_CBC_DEC_BE)
					set_aes_dec(pdma, AES_BIG_ENDIAN, AES_MODE_CBC);
				else
					set_aes_dec(pdma, AES_LIT_ENDIAN, AES_MODE_CBC);
			}
		} else {
			for (i = 0; i < MAX_DMA_ACCESS_CNT; i++) {
				set_channel_operation_mode(pdma, i, DMA_AES_MODE_ENC);
			}

			if (args->aes_key_len == AES_KEYSIZE_128) {
				augentix_dma_writel(pdma, AES_KEY_128, AES_ENC03_KEY_MODE);
			} else {
				augentix_dma_writel(pdma, AES_KEY_256, AES_ENC03_KEY_MODE);
			}

			set_aes_enc_key(pdma, args->aes_key);

			if (args->oper_mode == DMA_AES_ECB_ENC_BE || args->oper_mode == DMA_AES_ECB_ENC_LE) {
				if (args->oper_mode == DMA_AES_ECB_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_ECB);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_ECB);
			} else if (args->oper_mode == DMA_AES_CBC_ENC_BE || args->oper_mode == DMA_AES_CBC_ENC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_CBC_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_CBC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_CBC);
			} else if (args->oper_mode == DMA_AES_CFB_ENC_BE || args->oper_mode == DMA_AES_CFB_ENC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_CFB_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_CFB_ENC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_CFB_ENC);
			} else if (args->oper_mode == DMA_AES_CFB_DEC_BE || args->oper_mode == DMA_AES_CFB_DEC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_CFB_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_CFB_DEC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_CFB_DEC);
			} else if (args->oper_mode == DMA_AES_OFB_ENC_BE || args->oper_mode == DMA_AES_OFB_ENC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_OFB_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_OFB_ENC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_OFB_ENC);
			} else if (args->oper_mode == DMA_AES_OFB_DEC_BE || args->oper_mode == DMA_AES_OFB_DEC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_OFB_DEC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_OFB_DEC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_OFB_DEC);
			} else if (args->oper_mode == DMA_AES_CTR_ENC_BE || args->oper_mode == DMA_AES_CTR_ENC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_CTR_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_CTR_ENC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_CTR_ENC);
			} else if (args->oper_mode == DMA_AES_CTR_DEC_BE || args->oper_mode == DMA_AES_CTR_DEC_LE) {
				set_aes_enc_init_vector(pdma, args->aes_iv);
				if (args->oper_mode == DMA_AES_CTR_ENC_BE)
					set_aes_enc(pdma, AES_BIG_ENDIAN, AES_MODE_CTR_DEC);
				else
					set_aes_enc(pdma, AES_LIT_ENDIAN, AES_MODE_CTR_DEC);
			}
		}
	} else {
		pr_err("operation mode error\n");
	}
}

// static void set_addr_type(struct augentix_dma_engine *pdma)
// {
// 	phys_addr_t darb_paddr = 0x81300000;
// 	size_t darb_size = 0x1EC;
// 	unsigned int type_offset = 0x120;
// 	unsigned int res_offset = 0x1C8;
// 	void __iomem *darb_base = devm_ioremap(pdma->dev, darb_paddr, darb_size);
// 	uint32_t t_reg;

// 	if (darb_base == NULL){
// 		BUG();
// 	} else {
// 		/* read BANK_ADDR_TYPE, COL_ADDR_TYPE from DARB */
// 		t_reg = readl(darb_base + type_offset);
// 		pdma->bank_addr_type = (t_reg >> 8) & 0x1;
// 		pdma->col_addr_type = (t_reg >> 24) & 0x3;
// 		/* read BANK_INTERLEAVE_TYPE from DARB */
// 		t_reg = readl(darb_base + res_offset);
// 		// pdma->bank_interleave = t_reg & 0x3;
// 		pdma->bank_interleave = BANK_INTERLEAVE_8; // workaround
// 	}
// }

static void augentix_dma_init(struct augentix_dma_engine *pdma)
{
	u32 val = 0;
	u32 i = 0;

	// augentix_sw_rst(SW_RST_DMA);
	// set_addr_type(pdma);
	/*enable all irq*/
	val = augentix_dma_readl(pdma, DMA05_IRQ_MASK) & (~IRQ_MASK_ACCESS_END);
	augentix_dma_writel(pdma, val, DMA05_IRQ_MASK);

	/* col_addr_type */
	val = augentix_dma_readl(pdma, DMA10_CTRL) | TOTAL_ACCESS_CNT(1);
	augentix_dma_writel(pdma, val, DMA10_CTRL);

	/* bank_addr_type,target_burst_len_r,target_burst_len_w */
	val = augentix_dma_readl(pdma, DMA11_CTRL) | TARGET_BURST_LEN_R(16) | TARGET_BURST_LEN_W(16) | ACCESS_END_SEL_1;
	augentix_dma_writel(pdma, val, DMA11_CTRL);

	/*fifo level*/
	val = TARGET_FIFO_LEVEL_R(16) | TARGET_FIFO_LEVEL_W(16) | FIFO_FULL_LEVEL_R(32) | FIFO_FULL_LEVEL_W(32);
	augentix_dma_writel(pdma, val, DMA12_CTRL);

	for (i = 0; i < MAX_DMA_ACCESS_CNT; i++) {
		set_channel_operation_mode(pdma, i, DMA_AES_MODE_BYPASS);
		set_channel_access_mode(pdma, i, DMA_ACCESS_MODE_LINEAR);
		// set_bank_interleave_type(pdma, i, pdma->bank_interleave);
	}
}

static void dma_irq_handle_channel(struct augentix_dma_channel *augentix_dmac)
{
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	struct augentix_dma_desc *desc;
	unsigned long flags;

	spin_lock_irqsave(&augentix_dma->lock, flags);

	if (list_empty(&augentix_dmac->ld_active)) {
		spin_unlock_irqrestore(&augentix_dma->lock, flags);
		goto out;
	}

	desc = list_first_entry(&augentix_dmac->ld_active, struct augentix_dma_desc, node);

	spin_unlock_irqrestore(&augentix_dma->lock, flags);

	if (!xfer_done(desc)) {
		setup_xfer_desc_next(augentix_dma, desc);
		enable_dma_access(augentix_dma);
		return;
	}

out:
	/* Tasklet irq */
	tasklet_schedule(&augentix_dmac->dma_tasklet);
}

static irqreturn_t dma_irq_handler(int irq, void *dev_id)
{
	struct augentix_dma_engine *augentix_dma = dev_id;
	unsigned int status[2];

	status[0] = augentix_dma_readl(augentix_dma, DMA03_IRQ_STATUS) &
	            ~(augentix_dma_readl(augentix_dma, DMA05_IRQ_MASK));
	status[1] = augentix_dma_readl(augentix_dma, DMA04_IRQ_STATUS) &
	            ~(augentix_dma_readl(augentix_dma, DMA06_IRQ_MASK));
	//pr_err("%s called, status=0x%08x, 0x%08x\n", __func__, status[0], status[1]);
	if ((status[0] & STATUS_ACCESS_END)) {
		augentix_dma_writel(augentix_dma, STATUS_ACCESS_END, DMA01_IRQ_CLEAR);
		dma_irq_handle_channel(&augentix_dma->channel[0]);
	}
	if (status[0] & STATUS_BW_INSUFFICIENT_R) {
		augentix_dma_writel(augentix_dma, STATUS_BW_INSUFFICIENT_R, DMA01_IRQ_CLEAR);
	}
	if (status[0] & STATUS_BW_INSUFFICIENT_W) {
		augentix_dma_writel(augentix_dma, STATUS_BW_INSUFFICIENT_W, DMA01_IRQ_CLEAR);
	}
	if (status[0] & STATUS_ACCESS_VIOLATION_R) {
		augentix_dma_writel(augentix_dma, STATUS_ACCESS_VIOLATION_R, DMA01_IRQ_CLEAR);
	}
	if (status[1] & STATUS_ACCESS_VIOLATION_W) {
		augentix_dma_writel(augentix_dma, STATUS_ACCESS_VIOLATION_W, DMA02_IRQ_CLEAR);
	}

	return IRQ_HANDLED;
}

static u32 pa_to_viol_addr(struct augentix_dma_engine *pdma, u32 pa, enum dma_addr_type type)
{
	u32 carry;
	u32 row;
	u32 bank;
	u32 col;
	u32 row_bank;
	u32 col_mask;
	u32 col_width[4] = { 9, 10, 11, 12 };
	unsigned int bank_addr_type, col_addr_type;

	col_addr_type = (augentix_dma_readl(pdma, DMA10_CTRL) >> 8 & 0x3);
	bank_addr_type = (augentix_dma_readl(pdma, DMA11_CTRL) >> 16) & 0x1;

	if ((type == END) && (pa & 0x7)) {
		carry = 1;
	} else {
		carry = 0;
	}

	col_mask = 0xffffffff >> (32 - col_width[col_addr_type]);
	col = (pa & col_mask) >> 3;
	row_bank = pa >> col_width[col_addr_type];

	if (bank_addr_type == 0) {
		bank = row_bank & 0x3;
		row = row_bank >> 2;
	} else {
		bank = row_bank & 0x7;
		row = row_bank >> 3;
	}

	return ((row << 12) + (bank << 9) + col + carry);
}

static int setup_xfer_desc(struct augentix_dma_engine *pdma, struct augentix_dma_desc *desc, size_t len)
{
	unsigned int val = 0;
	unsigned int src_offset = 0;
	unsigned int dest_offset = 0;
	dma_addr_t xfer_src;
	dma_addr_t xfer_dest;
	size_t cur_len = 0;
	size_t xfer_len = 0;
	int as_no = 0; //need to set total access count
	u32 loop_cnt;
	u32 src_end, dst_end;
	u32 xfer_skip_r, xfer_skip_w;

	cur_len = len;
	xfer_src = desc->src + desc->len_off;
	xfer_dest = desc->dest + desc->len_off;
	loop_cnt = desc->loop;

	clk_disable(pdma->dma_clk);

	do {
		xfer_len = (cur_len < MAX_XFER_SIZE_PER_CH) ? cur_len : MAX_XFER_SIZE_PER_CH;

		src_offset = xfer_src - ((xfer_src >> 3) << 3);
		dest_offset = xfer_dest - ((xfer_dest >> 3) << 3);

		xfer_skip_r = desc->skip_r + desc->len - xfer_len;
		xfer_skip_w = desc->skip_w + desc->len - xfer_len;

		//	pr_debug("%s as_no: %d xfer_dest=0x%08llx xfer_src=0x%08llx xfer_len=%zu\n", __func__, as_no,
		//	         (unsigned long long)xfer_dest, (unsigned long long)xfer_src, xfer_len);

		val = (augentix_dma_readl(pdma, DMA_CH_CTRL2(as_no)) & (~(0x07070000))) | (src_offset << 16) |
		      (dest_offset << 24);
		augentix_dma_writel(pdma, val, DMA_CH_CTRL2(as_no));
		augentix_dma_writel(pdma, (xfer_src >> 3), DMA_INI_ADDR_LINEAR_R(as_no));
		augentix_dma_writel(pdma, (xfer_dest >> 3), DMA_INI_ADDR_LINEAR_W(as_no));
		augentix_dma_writel(pdma, xfer_len, DMA_CH_CTRL0(as_no));
		augentix_dma_writel(pdma, xfer_len, DMA_CH_CTRL3(as_no));

		augentix_dma_writel(pdma, loop_cnt << 16, DMA_CH_CTRL1(as_no));
		augentix_dma_writel(pdma, xfer_skip_r & 0xFFFFF, DMA_FLUSH_ADDR_SKIP_R(as_no));
		augentix_dma_writel(pdma, xfer_skip_w & 0xFFFFF, DMA_FLUSH_ADDR_SKIP_W(as_no));

		xfer_src = xfer_src + xfer_len;
		xfer_dest = xfer_dest + xfer_len;
		cur_len = cur_len - xfer_len;
		as_no++;
	} while ((cur_len > 0) && (as_no < MAX_DMA_ACCESS_CNT));

	src_end = (u32)(desc->src + (desc->len + desc->skip_r) * loop_cnt);
	dst_end = (u32)(desc->dest + (desc->len + desc->skip_w) * loop_cnt);

	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)desc->src, (enum dma_addr_type)START),
	                    DMA94_START_ADDR_R); // start address for read
	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, src_end, (enum dma_addr_type)END),
	                    DMA95_END_ADDR_R); // end address for read
	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)desc->dest, (enum dma_addr_type)START),
	                    DMA96_START_ADDR_W); // start address for write
	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, dst_end, (enum dma_addr_type)END),
	                    DMA97_END_ADDR_W); // end address for write

	val = augentix_dma_readl(pdma, DMA10_CTRL) & (~TOTAL_ACCESS_CNT(0xF));
	augentix_dma_writel(pdma, val | TOTAL_ACCESS_CNT(as_no), DMA10_CTRL);

	// Zero the unused channel registers
	for (; as_no < MAX_DMA_ACCESS_CNT; ++as_no) {
		augentix_dma_writel(pdma, 0, DMA_CH_CTRL0(as_no));
		augentix_dma_writel(pdma, 0, DMA_CH_CTRL1(as_no));
		val = augentix_dma_readl(pdma, DMA_CH_CTRL2(as_no) & (~(0x07070000)));
		augentix_dma_writel(pdma, val, DMA_CH_CTRL2(as_no));
		augentix_dma_writel(pdma, 0, DMA_CH_CTRL3(as_no));
		augentix_dma_writel(pdma, 0, DMA_INI_ADDR_LINEAR_R(as_no));
		augentix_dma_writel(pdma, 0, DMA_INI_ADDR_LINEAR_W(as_no));
	}

	return 0;
}

static int setup_xfer_desc_octa(struct augentix_dma_engine *pdma, unsigned long **dma_src_pg_list,
                                unsigned long **dma_dest_pg_list, size_t len)
{
	unsigned int val = 0;
	unsigned int src_offset = 0;
	unsigned int dest_offset = 0;
	dma_addr_t xfer_src;
	dma_addr_t xfer_dest;
	int as_no = 0;

	clk_disable(pdma->dma_clk);

	for (as_no = 0; as_no < MAX_DMA_ACCESS_CNT; as_no++) {
		xfer_src = (dma_addr_t)dma_src_pg_list[as_no];
		xfer_dest = (dma_addr_t)dma_dest_pg_list[as_no];
		if ((xfer_src == 0) || (xfer_dest == 0)) {
			break;
		}

		src_offset = xfer_src - ((xfer_src >> 3) << 3);
		dest_offset = xfer_dest - ((xfer_dest >> 3) << 3);

		val = (augentix_dma_readl(pdma, DMA_CH_CTRL2(as_no)) & (~(0x03030000))) | (src_offset << 16) |
		      (dest_offset << 24);
		augentix_dma_writel(pdma, val, DMA_CH_CTRL2(as_no));
		augentix_dma_writel(pdma, (xfer_src >> 3), DMA_INI_ADDR_LINEAR_R(as_no));
		augentix_dma_writel(pdma, (xfer_dest >> 3), DMA_INI_ADDR_LINEAR_W(as_no));
		augentix_dma_writel(pdma, len, DMA_CH_CTRL0(as_no));
		augentix_dma_writel(pdma, len, DMA_CH_CTRL3(as_no));
	}

	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)dma_src_pg_list[0], (enum dma_addr_type)START),
	                    DMA94_START_ADDR_R); // start address for read
	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)dma_src_pg_list[as_no - 1] + len, (enum dma_addr_type)END),
	                    DMA95_END_ADDR_R); // end address for read
	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)dma_dest_pg_list[0], (enum dma_addr_type)START),
	                    DMA96_START_ADDR_W); // start address for write
	augentix_dma_writel(pdma,
	                    pa_to_viol_addr(pdma, (u32)dma_dest_pg_list[as_no - 1] + len, (enum dma_addr_type)END),
	                    DMA97_END_ADDR_W); // end address for write

	val = augentix_dma_readl(pdma, DMA10_CTRL) & (~TOTAL_ACCESS_CNT(15));
	augentix_dma_writel(pdma, val | TOTAL_ACCESS_CNT(as_no), DMA10_CTRL);

	return 0;
}

#ifdef US_EN
static int setup_xfer_desc_for_us(struct augentix_dma_engine *pdma, unsigned long **dma_src_pg_list,
                                  unsigned long **dma_dest_pg_list, size_t npages)
{
	unsigned int val = 0;
	size_t xfer_len = 4096;
	unsigned int src_offset = 0;
	unsigned int dest_offset = 0;
	dma_addr_t xfer_src;
	dma_addr_t xfer_dest;
	int as_no = 0;
	do {
		xfer_src = (dma_addr_t)dma_src_pg_list[as_no];
		xfer_dest = (dma_addr_t)dma_dest_pg_list[as_no];

		src_offset = xfer_src - ((xfer_src >> 3) << 3);
		dest_offset = xfer_dest - ((xfer_dest >> 3) << 3);

		val = (augentix_dma_readl(pdma, DMA_CH_CTRL2(as_no)) & (~(0x03030000))) | (src_offset << 16) |
		      (dest_offset << 24);
		augentix_dma_writel(pdma, val, DMA_CH_CTRL2(as_no));
		augentix_dma_writel(pdma, (xfer_src >> 3), DMA_INI_ADDR_LINEAR_R(as_no));
		augentix_dma_writel(pdma, (xfer_dest >> 3), DMA_INI_ADDR_LINEAR_W(as_no));
		augentix_dma_writel(pdma, xfer_len, DMA_CH_CTRL0(as_no));
		augentix_dma_writel(pdma, xfer_len, DMA_CH_CTRL3(as_no));
		as_no++;
	} while ((as_no < npages));

	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)dma_src_pg_list[0], (enum dma_addr_type)START),
	                    DMA94_STR_ADDR_R); // start address for read
	augentix_dma_writel(pdma,
	                    pa_to_viol_addr(pdma, (u32)dma_src_pg_list[as_no] + xfer_len, (enum dma_addr_type)END),
	                    DMA95_END_ADDR_R); // end address for read
	augentix_dma_writel(pdma, pa_to_viol_addr(pdma, (u32)dma_dest_pg_list[0], (enum dma_addr_type)START),
	                    DMA96_STR_ADDR_W); // start address for write
	augentix_dma_writel(pdma,
	                    pa_to_viol_addr(pdma, (u32)dma_dest_pg_list[as_no] + xfer_len, (enum dma_addr_type)END),
	                    DMA97_END_ADDR_W); // end address for write

	val = augentix_dma_readl(pdma, DMA10_CTRL) & (~TOTAL_ACCESS_CNT(15));
	augentix_dma_writel(pdma, val | TOTAL_ACCESS_CNT(as_no), DMA10_CTRL);

	return 0;
}
#endif

static bool xfer_done(struct augentix_dma_desc *d)
{
	return (d->len_off == d->len);
}

static int setup_xfer_desc_next(struct augentix_dma_engine *pdma, struct augentix_dma_desc *d)
{
#define MAX_XFER_SIZE (MAX_XFER_SIZE_PER_CH * MAX_DMA_ACCESS_CNT)

	size_t xfer_len = 0;
	size_t cur_len = 0;
	size_t remainder_len;

	cur_len = d->len - d->len_off;

	if (xfer_done(d)) {
		return 0;
	}

	/*
	   * Apply #20386 SW workaround
	   * Originally, xfer_len = (cur_len < MAX_XFER_SIZE)? cur_len:MAX_XFER_SIZE;
	   * We isolate non-full data section out here
	   */
	xfer_len = cur_len;
	if (xfer_len > MAX_XFER_SIZE)
		xfer_len = MAX_XFER_SIZE;
	else {
		remainder_len = xfer_len & (MAX_XFER_SIZE_PER_CH - 1);
		if ((remainder_len != 0) && (xfer_len > (MAX_XFER_SIZE_PER_CH * 2))) {
			xfer_len -= remainder_len;
		}
	}

	setup_xfer_desc(pdma, d, xfer_len);

	d->len_off += xfer_len;

	return 0;
}

static int enable_dma_access(struct augentix_dma_engine *pdma)
{
	// augentix_sw_rst(SW_RST_DMA);
	clk_enable(pdma->dma_clk);
	augentix_dma_stub();
	augentix_dma_writel(pdma, 0x00000001, DMA00_ACCESS_START);
	return 0;
}

static int augentix_dma_xfer_desc(struct augentix_dma_desc *d)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(d->desc.chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;

	switch (d->type) {
	case AUGENTIX_DMA_DESC_MEMCPY:
		if (!(0xC0000000 & d->src)) {
			setup_xfer_desc_next(augentix_dma, d);
		} else {
#ifdef US_EN
			int npages = 1 + (d->len - 1) / PAGE_SIZE;
			setup_xfer_desc_for_us(augentix_dma, (unsigned long **)d->src, (unsigned long **)d->dest,
			                       npages);
#endif
			setup_xfer_desc_octa(augentix_dma, (unsigned long **)d->src, (unsigned long **)d->dest, d->len);
		}

		pr_debug("%s channel: %d dest=0x%08llx src=0x%08llx dma_length=%zu\n", __func__, augentix_dmac->channel,
		         (unsigned long long)d->dest, (unsigned long long)d->src, d->len);

		break;
	default:
		return -EINVAL;
	}

	enable_dma_access(augentix_dma);
	return 0;
}

static enum dma_status augentix_dma_tx_status(struct dma_chan *chan, dma_cookie_t cookie, struct dma_tx_state *txstate)
{
	return dma_cookie_status(chan, cookie, txstate);
}

static dma_cookie_t augentix_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(tx->chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	dma_cookie_t cookie;
	unsigned long flags;
	spin_lock_irqsave(&augentix_dma->lock, flags);

	list_move_tail(augentix_dmac->ld_free.next, &augentix_dmac->ld_queue);
	cookie = dma_cookie_assign(tx);

	spin_unlock_irqrestore(&augentix_dma->lock, flags);

	return cookie;
}

static int augentix_dma_alloc_chan_resources(struct dma_chan *chan)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	//struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	//struct imx_dma_data *data = chan->private;

	//if (data != NULL)
	//	imxdmac->dma_request = data->dma_request;

	while (augentix_dmac->descs_allocated < AUGENTIX_DMA_MAX_CHAN_DESCRIPTORS) {
		struct augentix_dma_desc *desc;

		desc = kzalloc(sizeof(*desc), GFP_KERNEL);
		if (!desc) {
			pr_err("%s: failure to allocate augentix_dma_desc.\n", __func__);
			break;
		}

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
		__memzero(&desc->desc, sizeof(struct dma_async_tx_descriptor));
#else
		memset(&desc->desc, 0, sizeof(struct dma_async_tx_descriptor));
#endif

		dma_async_tx_descriptor_init(&desc->desc, chan);
		desc->desc.tx_submit = augentix_dma_tx_submit;
		/* txd.flags will be overwritten in prep funcs */
		desc->desc.flags = DMA_CTRL_ACK;
		desc->status = DMA_COMPLETE;

		list_add_tail(&desc->node, &augentix_dmac->ld_free);
		augentix_dmac->descs_allocated++;
	}

	if (!augentix_dmac->descs_allocated) {
		pr_err("%s: No any descs.\n", __func__);
		return -ENOMEM;
	}

	return augentix_dmac->descs_allocated;
}

static void augentix_dma_free_chan_resources(struct dma_chan *chan)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	struct augentix_dma_desc *desc, *_desc;
	unsigned long flags;

	spin_lock_irqsave(&augentix_dma->lock, flags);

	//imxdma_disable_hw(imxdmac);
	list_splice_tail_init(&augentix_dmac->ld_active, &augentix_dmac->ld_free);
	list_splice_tail_init(&augentix_dmac->ld_queue, &augentix_dmac->ld_free);

	spin_unlock_irqrestore(&augentix_dma->lock, flags);

	list_for_each_entry_safe (desc, _desc, &augentix_dmac->ld_free, node) {
		kfree(desc);
		augentix_dmac->descs_allocated--;
	}
	INIT_LIST_HEAD(&augentix_dmac->ld_free);
}

static struct dma_async_tx_descriptor *augentix_dma_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest,
                                                                    dma_addr_t src, size_t len, unsigned long flags)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	struct augentix_dma_desc *desc;

	if (list_empty(&augentix_dmac->ld_free))
		return NULL;

	desc = list_first_entry(&augentix_dmac->ld_free, struct augentix_dma_desc, node);

	desc->type = AUGENTIX_DMA_DESC_MEMCPY;
	desc->src = src;
	desc->dest = dest;
	desc->len = len;
	desc->len_off = 0;
	desc->direction = DMA_MEM_TO_MEM;
	desc->desc.callback = NULL;
	desc->desc.callback_param = NULL;

	return &desc->desc;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 0, 0)
static int augentix_dma_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd, unsigned long arg)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	struct dma_args *dma_args = (struct dma_args *)arg;
	unsigned long flags;

	switch (cmd) {
	case DMA_SLAVE_CONFIG:
		dma_slave_config(augentix_dma, dma_args);
		return 0;
	case DMA_TERMINATE_ALL:
		spin_lock_irqsave(&augentix_dma->lock, flags);

		list_splice_tail_init(&augentix_dmac->ld_active, &augentix_dmac->ld_free);
		list_splice_tail_init(&augentix_dmac->ld_queue, &augentix_dmac->ld_free);

		spin_unlock_irqrestore(&augentix_dma->lock, flags);
		return 0;
	default:
		return -ENOSYS;
	}
	return -EINVAL;
}
#else
static int augentix_dma_config(struct dma_chan *chan, struct dma_slave_config *config)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	struct dma_args *dma_args = (struct dma_args *)config->peripheral_config;

	dma_slave_config(augentix_dma, dma_args);
	return 0;
}
static int augentix_dma_terminate_all(struct dma_chan *chan)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	unsigned long flags;

	spin_lock_irqsave(&augentix_dma->lock, flags);

	list_splice_tail_init(&augentix_dmac->ld_active, &augentix_dmac->ld_free);
	list_splice_tail_init(&augentix_dmac->ld_queue, &augentix_dmac->ld_free);

	spin_unlock_irqrestore(&augentix_dma->lock, flags);

	return 0;
}
#endif

static void augentix_dma_issue_pending(struct dma_chan *chan)
{
	struct augentix_dma_channel *augentix_dmac = to_augentix_dma_chan(chan);
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	struct augentix_dma_desc *desc;
	unsigned long flags;

	spin_lock_irqsave(&augentix_dma->lock, flags);

	if (list_empty(&augentix_dmac->ld_active) && !list_empty(&augentix_dmac->ld_queue)) {
		desc = list_first_entry(&augentix_dmac->ld_queue, struct augentix_dma_desc, node);
		//pr_info("desc: len=%d",desc->len);
		if (augentix_dma_xfer_desc(desc) < 0) {
			pr_warn("%s: channel: %d couldn't issue DMA xfer\n", __func__, augentix_dmac->channel);
		} else {
			list_move_tail(augentix_dmac->ld_queue.next, &augentix_dmac->ld_active);
		}
	}

	spin_unlock_irqrestore(&augentix_dma->lock, flags);
}

static void augentix_dma_tasklet(unsigned long data)
{
	struct augentix_dma_channel *augentix_dmac = (void *)data;
	struct augentix_dma_engine *augentix_dma = augentix_dmac->dma;
	struct augentix_dma_desc *desc;
	unsigned long flags;

	spin_lock_irqsave(&augentix_dma->lock, flags);

	if (list_empty(&augentix_dmac->ld_active)) {
		/* Someone might have called terminate all */
		spin_unlock_irqrestore(&augentix_dma->lock, flags);
		return;
	}

	desc = list_first_entry(&augentix_dmac->ld_active, struct augentix_dma_desc, node);

	dma_cookie_complete(&desc->desc);

	list_move_tail(augentix_dmac->ld_active.next, &augentix_dmac->ld_free);

	if (!list_empty(&augentix_dmac->ld_queue)) {
		desc = list_first_entry(&augentix_dmac->ld_queue, struct augentix_dma_desc, node);
		list_move_tail(augentix_dmac->ld_queue.next, &augentix_dmac->ld_active);
		if (augentix_dma_xfer_desc(desc) < 0)
			pr_warn("%s: channel: %d couldn't xfer desc\n", __func__, augentix_dmac->channel);
	}

	spin_unlock_irqrestore(&augentix_dma->lock, flags);

	if (desc->desc.callback)
		desc->desc.callback(desc->desc.callback_param);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
#ifdef AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER
	augentix_aes_complete(augentix_dma, 0);
#endif
#endif
}

struct dma_chan *__augentix_get_dma_chan(void)
{
	return memcpy_chan;
}
EXPORT_SYMBOL(__augentix_get_dma_chan);

struct dma_chan *__augentix_dma_request_channel(unsigned int flags)
{
	dma_cap_mask_t mask;

	dma_cap_zero(mask);
	dma_cap_set(flags, mask);

	return dma_request_channel(mask, NULL, NULL);
}
EXPORT_SYMBOL(__augentix_dma_request_channel);

void __augentix_dma_release_channel(struct dma_chan *chan)
{
	dma_release_channel(chan);
}
EXPORT_SYMBOL(__augentix_dma_release_channel);

static struct dma_async_tx_descriptor *__augentix_device_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest,
                                                                         dma_addr_t src, size_t len, unsigned int flags)
{
	return chan->device->device_prep_dma_memcpy(chan, dest, src, len, flags);
}

static void __augentix_dma_start_transfer(struct dma_chan *chan, struct completion *cmp, dma_cookie_t cookie, int wait)
{
	enum dma_status status;
	u32 timeout = 0;

	timeout = msecs_to_jiffies(wait < TIMEOUT_THRESHOLD ? TIMEOUT_THRESHOLD : wait);

	init_completion(cmp);
	dma_async_issue_pending(chan);

	if (wait) {
		pr_debug("waiting for dma to complete...\n");

		timeout = wait_for_completion_timeout(cmp, timeout);
		status = dma_async_is_tx_complete(chan, cookie, NULL, NULL);

		if (timeout == 0) {
			pr_err("dma xfer timeout\n");
		} else if (status != DMA_COMPLETE) {
			pr_err("dma returned completion callback status of: %s\n",
			       status == DMA_ERROR ? "error" : "in progress");
		}
	}
}

unsigned int __augentix_dma_config(struct dma_chan *chan, u32 op_mode, unsigned long arg)
{
	struct dma_args *dma_args;
	if (arg)
		dma_args = (struct dma_args *)arg;
	else
		dma_args = kzalloc(sizeof(struct dma_args), GFP_KERNEL);

	dma_args->oper_mode = op_mode;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 0, 0)
	dmaengine_device_control(chan, DMA_SLAVE_CONFIG, (unsigned long)dma_args);
#else
	struct dma_slave_config *dma_slave_config;
	dma_slave_config = kzalloc(sizeof(struct dma_slave_config), GFP_KERNEL);
	dma_slave_config->peripheral_config = dma_args;
	dma_slave_config->peripheral_size = sizeof(struct dma_args);

	dmaengine_slave_config(chan, dma_slave_config);
	kfree(dma_slave_config);
#endif
	kfree(dma_args);

	return 0;
}
EXPORT_SYMBOL(__augentix_dma_config);

void __augentix_dma_sync_callback(void *completion)
{
	complete(completion);
}

unsigned int __augentix_dma_copy(struct dma_chan *chan, void *dest, void *src, size_t len, int timeout)
{
	u32 ret = 0;
	struct dma_async_tx_descriptor *memcpy_chan_desc;
	dma_cookie_t memcpy_cookie;
	struct completion memcpy_cmp;

	memcpy_chan_desc = __augentix_device_prep_dma_memcpy(chan, (dma_addr_t)dest, (dma_addr_t)src, len,
	                                                     DMA_CTRL_ACK | DMA_PREP_INTERRUPT);
	if (!memcpy_chan_desc) {
		//pr_err("failure to prep_dma_memcpy\n");
		memcpy_cookie = -EBUSY;
		ret = -1;
		goto end;
	} else {
		if (timeout) {
			memcpy_chan_desc->callback = __augentix_dma_sync_callback;
			memcpy_chan_desc->callback_param = &memcpy_cmp;
		}
		memcpy_cookie = dmaengine_submit(memcpy_chan_desc);
	}
	if (dma_submit_error(memcpy_cookie)) {
		pr_err("memcpy_cookie error\n");
	}
	__augentix_dma_start_transfer(chan, &memcpy_cmp, memcpy_cookie, timeout);

end:
	return ret;
}
EXPORT_SYMBOL(__augentix_dma_copy);

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
#ifdef AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER

u32 do_aes_ablkcipher(struct augentix_aes_ctx *op)
{
	struct dma_args *args = kzalloc(sizeof(struct dma_args), GFP_KERNEL);

	args->aes_key = op->aes_key;
	args->aes_iv = op->aes_iv;
	args->aes_key_len = op->keylen;

	__augentix_dma_config(memcpy_chan, op->mode, (unsigned long)args);

	__augentix_dma_copy(memcpy_chan, (void *)op->dst, (void *)op->src, op->len, 0);

	return op->len;
}

static int augentix_set_in(struct augentix_dma_engine *dev, struct scatterlist *sg)
{
	int err;
	if (!IS_ALIGNED(sg_dma_len(sg), AES_BLOCK_SIZE)) {
		err = -EINVAL;
		goto exit;
	}
	if (!sg_dma_len(sg)) {
		err = -EINVAL;
		goto exit;
	}

	err = dma_map_sg(dev->dev, sg, 1, DMA_TO_DEVICE);
	if (!err) {
		err = -ENOMEM;
		goto exit;
	}

	dev->sg_src = sg;
	err = 0;

exit:
	return err;
}

static int augentix_set_out(struct augentix_dma_engine *dev, struct scatterlist *sg)
{
	int err;

	if (!IS_ALIGNED(sg_dma_len(sg), AES_BLOCK_SIZE)) {
		err = -EINVAL;
		goto exit;
	}
	if (!sg_dma_len(sg)) {
		err = -EINVAL;
		goto exit;
	}

	err = dma_map_sg(dev->dev, sg, 1, DMA_FROM_DEVICE);
	if (!err) {
		err = -ENOMEM;
		goto exit;
	}

	dev->sg_dst = sg;
	err = 0;

exit:
	return err;
}

static void augentix_unset_out(struct augentix_dma_engine *dev)
{
	dma_unmap_sg(dev->dev, dev->sg_dst, 1, DMA_FROM_DEVICE);
}

static void augentix_unset_in(struct augentix_dma_engine *dev)
{
	dma_unmap_sg(dev->dev, dev->sg_src, 1, DMA_TO_DEVICE);
}

static void augentix_aes_complete(struct augentix_dma_engine *dev, int err)
{
	/* holding a lock outside */
	if (dev->is_ablk_mode) {
		augentix_unset_in(dev);
		augentix_unset_out(dev);
		dev->req->base.complete(&dev->req->base, err);
		dev->is_ablk_mode = 0;
	}
}

static int augentix_handle_req(struct augentix_aes_ctx *ctx, u32 mode)
{
	struct augentix_dma_engine *dev = ctx->dev;

	if (augentix_set_in(dev, dev->req->src)) {
		return -EINVAL;
	}
	if (augentix_set_out(dev, dev->req->dst)) {
		return -EINVAL;
	}
	if (ctx->keylen != AES_KEYSIZE_256 && ctx->keylen != AES_KEYSIZE_128)
		return -EINVAL;

	ctx->src = (void *)sg_dma_address(dev->sg_src);
	ctx->dst = (void *)sg_dma_address(dev->sg_dst);
	ctx->len = sg_dma_len(dev->sg_src);
	ctx->mode = mode;

	ctx->aes_iv = dev->req->info;
	do_aes_ablkcipher(ctx);

	/* return 0 means the encryption / decryption has finished.
	if not finished, this function should return -EINPROGRESS*/
	return -EINPROGRESS;
}

static int augentix_aes_cbc_encrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_CBC_ENC_LE);
}

static int augentix_aes_cbc_decrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_CBC_DEC_LE);
}

static int augentix_aes_ecb_encrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_ECB_ENC_LE);
}

static int augentix_aes_ecb_decrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_ECB_DEC_LE);
}

static int augentix_aes_cfb_encrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_CFB_ENC_LE);
}

static int augentix_aes_cfb_decrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_CFB_DEC_LE);
}

static int augentix_aes_ofb_encrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_OFB_ENC_LE);
}

static int augentix_aes_ofb_decrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_OFB_DEC_LE);
}

static int augentix_aes_ctr_encrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_CTR_ENC_LE);
}

static int augentix_aes_ctr_decrypt(struct ablkcipher_request *req)
{
	struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
	struct augentix_dma_engine *dev = ctx->dev;

//pr_info("crypto_ablkcipher: %s\n",__func__);

	dev->req = req;
	dev->is_ablk_mode = 1;

	return augentix_handle_req(ctx, DMA_AES_CTR_DEC_LE);
}

#else
static int __aes_zero_padding(u8 *buf, u32 xfer_len, u32 encrypt_len)
{
	int pad_num = 0;
	if (encrypt_len > xfer_len) {
		pad_num = (encrypt_len - xfer_len);
		memset(buf + xfer_len, 0, pad_num);
	}

	return pad_num;
}

u32 do_aes_blkcipher(struct augentix_aes_ctx *op)
{
	//static struct dma_chan* memcpy_chan;
	u32 encrypt_len = (((op->len + 15) >> 4) << 4);
	dma_addr_t dma_dst, dma_src;
	struct dma_args *args = kzalloc(sizeof(struct dma_args), GFP_KERNEL);
#if 0
	memcpy_chan = __augentix_dma_request_channel(DMA_MEMCPY);
	if (!memcpy_chan) {
		pr_err("failure to request dma channel\n");
		return -1;
	}
#endif
	//__aes_zero_padding(op->src,op->len,encrypt_len);

	args->aes_key = op->aes_key;
	args->aes_iv = op->aes_iv;

	__augentix_dma_config(memcpy_chan, op->mode, (unsigned long)args);

	dma_src = dma_map_single(memcpy_chan->device->dev, op->src, encrypt_len, DMA_TO_DEVICE);
	dma_dst = dma_map_single(memcpy_chan->device->dev, op->dst, encrypt_len, DMA_FROM_DEVICE);

	pr_info("dma_src=%x, dma_dst=%x\n", dma_src, dma_dst);
	__augentix_dma_copy(memcpy_chan, (void *)dma_dst, (void *)dma_src, encrypt_len, 1);

	dma_unmap_single(memcpy_chan->device->dev, dma_src, encrypt_len, DMA_TO_DEVICE);
	dma_unmap_single(memcpy_chan->device->dev, dma_dst, encrypt_len, DMA_FROM_DEVICE);

	//	__augentix_dma_release_channel(memcpy_chan);

	return op->len;
}

static int augentix_aes_cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	//pr_info("%s\n",__func__);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);
	op->aes_iv = walk.iv;

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_CBC_ENC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

	pr_info("%s\n", __func__);

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	pr_info("%s, nbytes=%u\n", __func__, nbytes);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_CBC_DEC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	pr_info("%s, nbytes=%u\n", __func__, nbytes);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_ECB_ENC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	pr_info("%s, nbytes=%u\n", __func__, nbytes);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_ECB_DEC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_cfb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	//pr_info("%s\n",__func__);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);
	op->aes_iv = walk.iv;

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_CFB_ENC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

	pr_info("%s\n", __func__);

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_cfb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	pr_info("%s, nbytes=%u\n", __func__, nbytes);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_CFB_DEC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_ofb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	//pr_info("%s\n",__func__);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);
	op->aes_iv = walk.iv;

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_OFB_ENC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

	pr_info("%s\n", __func__);

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_ofb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	pr_info("%s, nbytes=%u\n", __func__, nbytes);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_OFB_DEC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_ctr_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	//pr_info("%s\n",__func__);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);
	op->aes_iv = walk.iv;

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_CTR_ENC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

	pr_info("%s\n", __func__);

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}

static int augentix_aes_ctr_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst, struct scatterlist *src,
                                    unsigned int nbytes)
{
	struct augentix_aes_ctx *op = crypto_blkcipher_ctx(desc->tfm);
	struct blkcipher_walk walk;
	int err;
	//u8* p_dest;

	pr_info("%s, nbytes=%u\n", __func__, nbytes);

	blkcipher_walk_init(&walk, dst, src, nbytes);
	err = blkcipher_walk_virt(desc, &walk);

	while ((nbytes = walk.nbytes)) {
		op->src = walk.src.virt.addr, op->dst = walk.dst.virt.addr;
		op->mode = DMA_AES_CTR_DEC_BE;
		op->len = nbytes;
		do_aes_blkcipher(op);
		nbytes = 0;
		err = blkcipher_walk_done(desc, &walk, nbytes);
	}

#if 0
	p_dest = op->src;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}


	pr_info("========================\n");
	p_dest = op->dst;

	for (i=0; i<8; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dest[0],p_dest[1],p_dest[2],p_dest[3],p_dest[4],p_dest[5],p_dest[6],p_dest[7]);
			p_dest	= p_dest + (8);
	}
#endif
	return err;
}
#endif // AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER

static int augentix_aes_cra_init(struct crypto_tfm *tfm)
{
	struct augentix_aes_ctx *ctx = crypto_tfm_ctx(tfm);
	//pr_info("crypto_ablkcipher: %s\n",__func__);
	ctx->dev = g_dma_engine;
#ifdef AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER
	tfm->crt_ablkcipher.reqsize = sizeof(struct augentix_aes_ctx);
#endif

	return 0;
}

#ifndef AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER
static void augentix_aes_cra_exit(struct crypto_tfm *tfm)
{
	//struct augentix_aes_ctx  *ctx = crypto_tfm_ctx(tfm);
	pr_info("%s\n", __func__);
}
#endif

#ifdef AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER
static int augentix_aes_setkey(struct crypto_ablkcipher *tfm, const u8 *key, unsigned int keylen)
{
	struct augentix_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);

	if (keylen != AES_KEYSIZE_256 && keylen != AES_KEYSIZE_128)
		return -EINVAL;

	pr_debug("enter, keylen: %d\n", keylen);

	memcpy(ctx->aes_key, key, keylen);
	ctx->keylen = keylen;

	return 0;
}

static struct crypto_alg ecb_alg = {
	.cra_name = "ecb(aes)",
	.cra_driver_name = "augentix-ecb",
	.cra_priority = 300,
	.cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER | CRYPTO_ALG_KERN_DRIVER_ONLY | CRYPTO_ALG_ASYNC,
	.cra_blocksize = AES_BLOCK_SIZE,
	.cra_ctxsize = sizeof(struct augentix_aes_ctx),
	.cra_alignmask = 0,
	.cra_type = &crypto_ablkcipher_type,
	.cra_module = THIS_MODULE,
	.cra_init = augentix_aes_cra_init,
	.cra_u =
	        {
	                .ablkcipher =
	                        {
	                                //.ivsize		=	AES_BLOCK_SIZE,
	                                .min_keysize = AES_MIN_KEY_SIZE,
	                                .max_keysize = AES_MAX_KEY_SIZE,
	                                .setkey = augentix_aes_setkey,
	                                .encrypt = augentix_aes_ecb_encrypt,
	                                .decrypt = augentix_aes_ecb_decrypt,
	                        },
	        },
};

static struct crypto_alg cbc_alg = {
	.cra_name = "cbc(aes)",
	.cra_driver_name = "augentix-cbc",
	.cra_priority = 300,
	.cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER | CRYPTO_ALG_KERN_DRIVER_ONLY | CRYPTO_ALG_ASYNC,
	.cra_blocksize = AES_BLOCK_SIZE,
	.cra_ctxsize = sizeof(struct augentix_aes_ctx),
	.cra_alignmask = 0,
	.cra_type = &crypto_ablkcipher_type,
	.cra_module = THIS_MODULE,
	.cra_init = augentix_aes_cra_init,
	.cra_u =
	        {
	                .ablkcipher =
	                        {
	                                .ivsize = AES_BLOCK_SIZE,
	                                .min_keysize = AES_MIN_KEY_SIZE,
	                                .max_keysize = AES_MAX_KEY_SIZE,
	                                .setkey = augentix_aes_setkey,
	                                .encrypt = augentix_aes_cbc_encrypt,
	                                .decrypt = augentix_aes_cbc_decrypt,
	                        },
	        },
};

static struct crypto_alg cfb_alg = {
	.cra_name = "cfb(aes)",
	.cra_driver_name = "augentix-cfb",
	.cra_priority = 300,
	.cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER | CRYPTO_ALG_KERN_DRIVER_ONLY | CRYPTO_ALG_ASYNC,
	.cra_blocksize = AES_BLOCK_SIZE,
	.cra_ctxsize = sizeof(struct augentix_aes_ctx),
	.cra_alignmask = 0,
	.cra_type = &crypto_ablkcipher_type,
	.cra_module = THIS_MODULE,
	.cra_init = augentix_aes_cra_init,
	.cra_u =
	        {
	                .ablkcipher =
	                        {
	                                .ivsize = AES_BLOCK_SIZE,
	                                .min_keysize = AES_MIN_KEY_SIZE,
	                                .max_keysize = AES_MAX_KEY_SIZE,
	                                .setkey = augentix_aes_setkey,
	                                .encrypt = augentix_aes_cfb_encrypt,
	                                .decrypt = augentix_aes_cfb_decrypt,
	                        },
	        },
};

static struct crypto_alg ofb_alg = {
	.cra_name = "ofb(aes)",
	.cra_driver_name = "augentix-ofb",
	.cra_priority = 300,
	.cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER | CRYPTO_ALG_KERN_DRIVER_ONLY | CRYPTO_ALG_ASYNC,
	.cra_blocksize = AES_BLOCK_SIZE,
	.cra_ctxsize = sizeof(struct augentix_aes_ctx),
	.cra_alignmask = 0,
	.cra_type = &crypto_ablkcipher_type,
	.cra_module = THIS_MODULE,
	.cra_init = augentix_aes_cra_init,
	.cra_u =
	        {
	                .ablkcipher =
	                        {
	                                .ivsize = AES_BLOCK_SIZE,
	                                .min_keysize = AES_MIN_KEY_SIZE,
	                                .max_keysize = AES_MAX_KEY_SIZE,
	                                .setkey = augentix_aes_setkey,
	                                .encrypt = augentix_aes_ofb_encrypt,
	                                .decrypt = augentix_aes_ofb_decrypt,
	                        },
	        },
};

static struct crypto_alg ctr_alg = {
	.cra_name = "ctr(aes)",
	.cra_driver_name = "augentix-ctr",
	.cra_priority = 300,
	.cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER | CRYPTO_ALG_KERN_DRIVER_ONLY | CRYPTO_ALG_ASYNC,
	.cra_blocksize = AES_BLOCK_SIZE,
	.cra_ctxsize = sizeof(struct augentix_aes_ctx),
	.cra_alignmask = 0,
	.cra_type = &crypto_ablkcipher_type,
	.cra_module = THIS_MODULE,
	.cra_init = augentix_aes_cra_init,
	.cra_u =
	        {
	                .ablkcipher =
	                        {
	                                .ivsize = AES_BLOCK_SIZE,
	                                .min_keysize = AES_MIN_KEY_SIZE,
	                                .max_keysize = AES_MAX_KEY_SIZE,
	                                .setkey = augentix_aes_setkey,
	                                .encrypt = augentix_aes_ctr_encrypt,
	                                .decrypt = augentix_aes_ctr_decrypt,
	                        },
	        },
};

#else
static int augentix_aes_setkey(struct crypto_tfm *tfm, const u8 *key, u32 len)
{
	struct augentix_aes_ctx *op = crypto_tfm_ctx(tfm);
	u32 ret = 0, i;
	u8 *p_dst;
	//pr_info("%s\n",__func__);

	if (len == AES_KEYSIZE_256) {
		op->keylen = len;
		memcpy(op->aes_key, key, len);
#if 0
		p_dst = op->aes_key;
		for (i=0; i<4; i++) {
			pr_info("%x %x %x %x %x %x %x %x\n",p_dst[0],p_dst[1],p_dst[2],p_dst[3],p_dst[4],p_dst[5],p_dst[6],p_dst[7]);
			p_dst	= p_dst + (8);
		}
#endif
	} else {
		//pr_err("%s Only support AES-256\n",__func__);
	}

	return ret;
}

static struct crypto_alg cbc_alg = { .cra_name = "cbc(aes)",
	                             .cra_driver_name = "augentix-cbc",
	                             .cra_priority = 300,
	                             .cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER |
	                                          CRYPTO_ALG_KERN_DRIVER_ONLY, // | CRYPTO_ALG_NEED_FALLBACK,
	                             .cra_init = augentix_aes_cra_init,
	                             .cra_exit = augentix_aes_cra_exit,
	                             .cra_blocksize = AES_BLOCK_SIZE,
	                             .cra_ctxsize = sizeof(struct augentix_aes_ctx),
	                             .cra_alignmask = 15,
	                             .cra_type = &crypto_blkcipher_type,
	                             .cra_module = THIS_MODULE,
	                             .cra_u = { .blkcipher = {
	                                                .min_keysize = AES_MIN_KEY_SIZE,
	                                                .max_keysize = AES_MAX_KEY_SIZE,
	                                                .setkey = augentix_aes_setkey,
	                                                .encrypt = augentix_aes_cbc_encrypt,
	                                                .decrypt = augentix_aes_cbc_decrypt,
	                                                .ivsize = AES_BLOCK_SIZE,
	                                        } } };

static struct crypto_alg ecb_alg = { .cra_name = "ecb(aes)",
	                             .cra_driver_name = "augentix-ecb",
	                             .cra_priority = 300,
	                             .cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER |
	                                          CRYPTO_ALG_KERN_DRIVER_ONLY, // | CRYPTO_ALG_NEED_FALLBACK,
	                             .cra_init = augentix_aes_cra_init,
	                             .cra_exit = augentix_aes_cra_exit,
	                             .cra_blocksize = AES_BLOCK_SIZE,
	                             .cra_ctxsize = sizeof(struct augentix_aes_ctx),
	                             .cra_alignmask = 15,
	                             .cra_type = &crypto_blkcipher_type,
	                             .cra_module = THIS_MODULE,
	                             .cra_u = { .blkcipher = {
	                                                .min_keysize = AES_MIN_KEY_SIZE,
	                                                .max_keysize = AES_MAX_KEY_SIZE,
	                                                .setkey = augentix_aes_setkey,
	                                                .encrypt = augentix_aes_ecb_encrypt,
	                                                .decrypt = augentix_aes_ecb_decrypt,
	                                                //.ivsize			=	AES_BLOCK_SIZE,
	                                        } } };

static struct crypto_alg cbc_alg = { .cra_name = "cfb(aes)",
	                             .cra_driver_name = "augentix-cfb",
	                             .cra_priority = 300,
	                             .cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER |
	                                          CRYPTO_ALG_KERN_DRIVER_ONLY, // | CRYPTO_ALG_NEED_FALLBACK,
	                             .cra_init = augentix_aes_cra_init,
	                             .cra_exit = augentix_aes_cra_exit,
	                             .cra_blocksize = AES_BLOCK_SIZE,
	                             .cra_ctxsize = sizeof(struct augentix_aes_ctx),
	                             .cra_alignmask = 15,
	                             .cra_type = &crypto_blkcipher_type,
	                             .cra_module = THIS_MODULE,
	                             .cra_u = { .blkcipher = {
	                                                .min_keysize = AES_MIN_KEY_SIZE,
	                                                .max_keysize = AES_MAX_KEY_SIZE,
	                                                .setkey = augentix_aes_setkey,
	                                                .encrypt = augentix_aes_cfb_encrypt,
	                                                .decrypt = augentix_aes_cfb_decrypt,
	                                                .ivsize = AES_BLOCK_SIZE,
	                                        } } };

static struct crypto_alg cbc_alg = { .cra_name = "ofb(aes)",
	                             .cra_driver_name = "augentix-ofb",
	                             .cra_priority = 300,
	                             .cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER |
	                                          CRYPTO_ALG_KERN_DRIVER_ONLY, // | CRYPTO_ALG_NEED_FALLBACK,
	                             .cra_init = augentix_aes_cra_init,
	                             .cra_exit = augentix_aes_cra_exit,
	                             .cra_blocksize = AES_BLOCK_SIZE,
	                             .cra_ctxsize = sizeof(struct augentix_aes_ctx),
	                             .cra_alignmask = 15,
	                             .cra_type = &crypto_blkcipher_type,
	                             .cra_module = THIS_MODULE,
	                             .cra_u = { .blkcipher = {
	                                                .min_keysize = AES_MIN_KEY_SIZE,
	                                                .max_keysize = AES_MAX_KEY_SIZE,
	                                                .setkey = augentix_aes_setkey,
	                                                .encrypt = augentix_aes_ofb_encrypt,
	                                                .decrypt = augentix_aes_ofb_decrypt,
	                                                .ivsize = AES_BLOCK_SIZE,
	                                        } } };

static struct crypto_alg cbc_alg = { .cra_name = "ctr(aes)",
	                             .cra_driver_name = "augentix-ctr",
	                             .cra_priority = 300,
	                             .cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER |
	                                          CRYPTO_ALG_KERN_DRIVER_ONLY, // | CRYPTO_ALG_NEED_FALLBACK,
	                             .cra_init = augentix_aes_cra_init,
	                             .cra_exit = augentix_aes_cra_exit,
	                             .cra_blocksize = AES_BLOCK_SIZE,
	                             .cra_ctxsize = sizeof(struct augentix_aes_ctx),
	                             .cra_alignmask = 15,
	                             .cra_type = &crypto_blkcipher_type,
	                             .cra_module = THIS_MODULE,
	                             .cra_u = { .blkcipher = {
	                                                .min_keysize = AES_MIN_KEY_SIZE,
	                                                .max_keysize = AES_MAX_KEY_SIZE,
	                                                .setkey = augentix_aes_setkey,
	                                                .encrypt = augentix_aes_ctr_encrypt,
	                                                .decrypt = augentix_aes_ctr_decrypt,
	                                                .ivsize = AES_BLOCK_SIZE,
	                                        } } };
#endif // AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER
#endif // LINUX_VERSION_CODE

static int __init augentix_dma_probe(struct platform_device *pdev)
{
	struct augentix_dma_engine *augentix_dma;
	struct resource *res;
	int ret, i;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
	int err = -ENODEV;
#endif
	int irq;

	/* alloc struct augentix_dma_engine */
	augentix_dma = devm_kzalloc(&pdev->dev, sizeof(*augentix_dma), GFP_KERNEL);
	if (!augentix_dma) {
		pr_err("%s: Can't alloc dma engine.\n", __func__);
		return -ENOMEM;
	}

	g_dma_engine = augentix_dma;

	augentix_dma->dev = &pdev->dev;

	/* get memory resource and do ioremap*/
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	augentix_dma->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(augentix_dma->base)) {
		pr_err("%s: failure to devm_ioremap_resource.\n", __func__);
		return PTR_ERR(augentix_dma->base);
	}

	/* get irq number and register irq handler */
	irq = platform_get_irq(pdev, 0);
	ret = devm_request_irq(&pdev->dev, irq, dma_irq_handler, 0, "DMA", augentix_dma);
	if (ret) {
		pr_err("%s: failure to register irq handler for dma.\n", __func__);
		return ret;
	}

	/*
	 * devm_clk_get(dev, NULL) is same as of_clk_get(np, 0).
	 * If intending to use plural clock source, use of_clk_get(np, index).
	 * Remember not to use clock-names to reduce code size and boot time
	 */
	augentix_dma->dma_clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(augentix_dma->dma_clk)) {
		pr_err("%s: failure to enable dma-clk.\n", __func__);
		return PTR_ERR(augentix_dma->dma_clk);
	}

	clk_prepare_enable(augentix_dma->dma_clk);

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
	/* register aes algorithm */
	err = crypto_register_alg(&cbc_alg);
	if (err) {
		pr_err("%s: failure to reg cbc.\n", __func__);
		goto e_cbc;
	}

	err = crypto_register_alg(&ecb_alg);
	if (err) {
		pr_err("%s: failure to reg ecb.\n", __func__);
		goto e_ecb;
	}

	err = crypto_register_alg(&cfb_alg);
	if (err) {
		pr_err("%s: failure to reg cfb.\n", __func__);
		goto e_cfb;
	}

	err = crypto_register_alg(&ofb_alg);
	if (err) {
		pr_err("%s: failure to reg ofb.\n", __func__);
		goto e_ofb;
	}

	err = crypto_register_alg(&ctr_alg);
	if (err) {
		pr_err("%s: failure to reg ctr.\n", __func__);
		goto e_ctr;
	}
#endif
	/* init lower level dma settings */
	augentix_dma_init(augentix_dma);

	INIT_LIST_HEAD(&augentix_dma->dma_device.channels);

	/* support DMA_MEMCPY */
	dma_cap_set(DMA_MEMCPY, augentix_dma->dma_device.cap_mask);

	spin_lock_init(&augentix_dma->lock);

	/* init channel parameters */
	for (i = 0; i < AUGENTIX_DMA_MAX_CHANNELS; i++) {
		struct augentix_dma_channel *augentix_dmac = &augentix_dma->channel[i];
		augentix_dmac->dma = augentix_dma;

		INIT_LIST_HEAD(&augentix_dmac->ld_queue);
		INIT_LIST_HEAD(&augentix_dmac->ld_free);
		INIT_LIST_HEAD(&augentix_dmac->ld_active);

		tasklet_init(&augentix_dmac->dma_tasklet, augentix_dma_tasklet, (unsigned long)augentix_dmac);
		augentix_dmac->chan.device = &augentix_dma->dma_device;
		dma_cookie_init(&augentix_dmac->chan);
		augentix_dmac->channel = i;

		/* add the channel to the DMAC list */
		list_add_tail(&augentix_dmac->chan.device_node, &augentix_dma->dma_device.channels);
	}

	augentix_dma->dma_device.dev = &pdev->dev;

	augentix_dma->dma_device.device_alloc_chan_resources = augentix_dma_alloc_chan_resources;
	augentix_dma->dma_device.device_free_chan_resources = augentix_dma_free_chan_resources;
	augentix_dma->dma_device.device_tx_status = augentix_dma_tx_status;
	augentix_dma->dma_device.device_prep_dma_memcpy = augentix_dma_prep_dma_memcpy;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 0, 0)
	augentix_dma->dma_device.device_control = augentix_dma_control;
#else
	augentix_dma->dma_device.device_config = augentix_dma_config;
	augentix_dma->dma_device.device_terminate_all = augentix_dma_terminate_all;
#endif
	augentix_dma->dma_device.device_issue_pending = augentix_dma_issue_pending;

	platform_set_drvdata(pdev, augentix_dma);

	augentix_dma->dma_device.copy_align = 2; /* 2^2 = 4 bytes alignment */
	//augentix_dma->dma_device.dev->dma_parms = &augentix_dma->dma_parms;
	//dma_set_max_seg_size(augentix_dma->dma_device.dev, 0xffffff);

	ret = dma_async_device_register(&augentix_dma->dma_device);
	if (ret) {
		pr_err("%s: failure to reg dma.\n", __func__);
		goto e_dma;
	}

	memcpy_chan = __augentix_dma_request_channel(DMA_MEMCPY);
	if (!memcpy_chan) {
		pr_err("failure to request dma channel\n");
		return -1;
	}

	return 0;

e_dma:
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
	crypto_unregister_alg(&ctr_alg);
e_ctr:
	crypto_unregister_alg(&ofb_alg);
e_ofb:
	crypto_unregister_alg(&cfb_alg);
e_cfb:
	crypto_unregister_alg(&ecb_alg);
e_ecb:
	crypto_unregister_alg(&cbc_alg);
e_cbc:
#endif
	clk_unprepare(augentix_dma->dma_clk);
	return ret;
}

static int augentix_dma_remove(struct platform_device *pdev)
{
	struct augentix_dma_engine *augentix_dma = platform_get_drvdata(pdev);

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
	crypto_unregister_alg(&cbc_alg);
	crypto_unregister_alg(&ecb_alg);
	crypto_unregister_alg(&cfb_alg);
	crypto_unregister_alg(&ofb_alg);
	crypto_unregister_alg(&ctr_alg);
#endif

	__augentix_dma_release_channel(memcpy_chan);

	dma_async_device_unregister(&augentix_dma->dma_device);

	clk_unprepare(augentix_dma->dma_clk);

	return 0;
}

static struct platform_driver augentix_dma_driver = {
	.driver =
	        {
	                .name = "augentix-dma",
	                .owner = THIS_MODULE,
	                .of_match_table = augentix_dma_of_dev_id,
	        },
	.remove = augentix_dma_remove,
};

static int __init augentix_dma_module_init(void)
{
	return platform_driver_probe(&augentix_dma_driver, augentix_dma_probe);
}
subsys_initcall(augentix_dma_module_init);

MODULE_AUTHOR("HungTe Cheng <hungte.cheng@augentix.com>");
MODULE_DESCRIPTION("augentix dma/aes driver");
MODULE_LICENSE("GPL");
