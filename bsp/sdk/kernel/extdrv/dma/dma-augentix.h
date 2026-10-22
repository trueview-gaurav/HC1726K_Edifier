#ifndef __DMA_AUGENTIX__H__
#define __DMA_AUGENTIX__H__

/* ACCESS VIOLATION */
#define STR_ADDR_DEF 0x0
#define END_ADDR_DEF 0xFFFFFFF
#define AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER 0

#define AUGENTIX_DMA_MAX_CHAN_DESCRIPTORS 1
#define AUGENTIX_DMA_MAX_CHANNELS 1
#define MAX_DMA_ACCESS_CNT 1
#define MAX_XFER_SIZE_PER_CH 32768

/* DMA OFFSET */
#define DMA00_ACCESS_START 0x000
#define DMA01_IRQ_CLEAR 0x004
#define DMA02_IRQ_CLEAR 0x008
#define DMA03_IRQ_STATUS 0x00C
#define DMA04_IRQ_STATUS 0x010
#define DMA05_IRQ_MASK 0x014
#define DMA06_IRQ_MASK 0x018
#define DMA07_ACCESS_ILLEGAL 0x1C
#define DMA10_CTRL 0x028
#define DMA11_CTRL 0x02C
#define DMA12_CTRL 0x030
#define DMA14_EFUSE_CTRL 0x038
#define CH_CTRL0_BASE 0x03C // ACCESS_LENGTH_R
#define CH_CTRL1_BASE 0x040 // LOOP_CNT
#define CH_CTRL2_BASE 0x044
#define CH_CTRL3_BASE 0x188 // ACCESS_LENGTH_W
#define DMA_CH_CTRL0(n) (n ? (n == 1 ? 0x034 : (0x38 + (n * 0x10))) : CH_CTRL0_BASE)
#define DMA_CH_CTRL1(n) (n ? (n == 1 ? 0x048 : (0x130 + (n * 0x4))) : CH_CTRL1_BASE)
#define DMA_CH_CTRL2(n) (CH_CTRL2_BASE + (n * 0x10))
#define DMA_CH_CTRL3(n) (CH_CTRL3_BASE + (n * 0x4))
#define DMA46_BANK_INTER_TP_R_0 0x0B8
#define DMA47_BANK_INTER_TP_R_1 0x0BC
#define DMA48_ADDR_BANK_OFF_R_0 0x0C0
#define DMA49_ADDR_BANK_OFF_R_1 0x0C4
#define INI_ADDR_LINEAR_W_BASE 0x0C8
#define DMA_INI_ADDR_LINEAR_W(n) (INI_ADDR_LINEAR_W_BASE + (n * 0x4))
#define INI_ADDR_LINEAR_R_BASE 0x0E8
#define DMA_INI_ADDR_LINEAR_R(n) (INI_ADDR_LINEAR_R_BASE + (n * 0x4))
#define FLUSH_ADDR_SKIP_R_BASE 0x108
#define DMA_FLUSH_ADDR_SKIP_R(n) (FLUSH_ADDR_SKIP_R_BASE + (n * 0x4))
#define FLUSH_ADDR_SKIP_W_BASE 0x148
#define DMA_FLUSH_ADDR_SKIP_W(n) (FLUSH_ADDR_SKIP_W_BASE + (n * 0x4))
#define DMA90_BANK_INTER_TP_W_0 0x168
#define DMA91_BANK_INTER_TP_W_1 0x16C
#define DMA92_ADDR_BANK_OFF_W_0 0x170
#define DMA93_ADDR_BANK_OFF_W_1 0x174
#define DMA94_START_ADDR_R 0x178
#define DMA95_END_ADDR_R 0x17C
#define DMA96_START_ADDR_W 0x180
#define DMA97_END_ADDR_W 0x184

/* IRQ */
#define IRQ_MASK_ACCESS_END (1 << 0)
#define IRQ_MASK_BW_INSUFFICIENT_R (1 << 8)
#define IRQ_MASK_ACCESS_VIOLATION_R (1 << 16)
#define IRQ_MASK_BW_INSUFFICIENT_W (1 << 24)
#define IRQ_MASK_ACCESS_VIOLATION_W (1 << 0)

/* DMA03, 04 */
#define STATUS_ACCESS_END IRQ_MASK_ACCESS_END
#define STATUS_BW_INSUFFICIENT_R IRQ_MASK_BW_INSUFFICIENT_R
#define STATUS_ACCESS_VIOLATION_R IRQ_MASK_ACCESS_VIOLATION_R
#define STATUS_BW_INSUFFICIENT_W IRQ_MASK_BW_INSUFFICIENT_W
#define STATUS_ACCESS_VIOLATION_W IRQ_MASK_ACCESS_VIOLATION_W

/* DMA10 */
#if 0
#define COL_ADDR_TYPE_512 0
#define COL_ADDR_TYPE_1024 1
#define COL_ADDR_TYPE_2048 2
#define COL_ADDR_TYPE_4096 3
#endif
#define TOTAL_ACCESS_CNT(n) (n << 16)

/* DMA11 */
#define TARGET_BURST_LEN_R(n) (n << 0)
#define TARGET_BURST_LEN_W(n) (n << 8)
#if 0
#define BANK_ADDR_TYPE_4 0
#define BANK_ADDR_TYPE_8 1
#endif
#define ACCESS_END_SEL_0 ~(1 << 24)
#define ACCESS_END_SEL_1 (1 << 24)

/* DMA12 */
#define TARGET_FIFO_LEVEL_R(n) (n << 0)
#define TARGET_FIFO_LEVEL_W(n) (n << 8)
#define FIFO_FULL_LEVEL_R(n) (n << 16)
#define FIFO_FULL_LEVEL_W(n) (n << 24)

#if 0
#define BANK_INTERLEAVE_0 0
#define BANK_INTERLEAVE_2 1
#define BANK_INTERLEAVE_4 2
#define BANK_INTERLEAVE_8 3
#endif

/* DMA_CH_CTRL2 */
#define DMA_AES_MODE_ENC 0
#define DMA_AES_MODE_BYPASS 1
#define DMA_AES_MODE_INVALID 2
#define DMA_AES_MODE_DEC 3

#define DMA_ACCESS_MODE_LINEAR (0 << 8)
#define DMA_ACCESS_MODE_YORC (1 << 8)
#define DMA_ACCESS_MODE_CB (2 << 8)
#define DMA_ACCESS_MODE_CR (3 << 8)

/* AES_ENC Offset */
#define AES_ENC03_KEY_MODE 0x80C
#define AES_ENC04_KEY_0 0x810
#define AES_ENC05_KEY_1 0x814
#define AES_ENC06_KEY_2 0x818
#define AES_ENC07_KEY_3 0x81C
#define AES_ENC08_KEY_4 0x820
#define AES_ENC09_KEY_5 0x824
#define AES_ENC10_KEY_6 0x828
#define AES_ENC11_KEY_7 0x82C
#define AES_ENC12_INTER_0 0x830
#define AES_ENC13_INTER_1 0x834
#define AES_ENC14_INTER_2 0x838
#define AES_ENC15_INTER_3 0x83C
#define AES_ENC16_CTRL 0x840
#define AES_ENC17_IV_0 0x844
#define AES_ENC18_IV_1 0x848
#define AES_ENC19_IV_2 0x84C
#define AES_ENC20_IV_3 0x850

/* AES_DEC Offset */
#define AES_DEC03_KEY_MODE 0xC0C
#define AES_DEC04_KEY_0 0xC10
#define AES_DEC05_KEY_1 0xC14
#define AES_DEC06_KEY_2 0xC18
#define AES_DEC07_KEY_3 0xC1C
#define AES_DEC08_KEY_4 0xC20
#define AES_DEC09_KEY_5 0xC24
#define AES_DEC10_KEY_6 0xC28
#define AES_DEC11_KEY_7 0xC2C
#define AES_DEC12_INTER_0 0xC30
#define AES_DEC13_INTER_1 0xC34
#define AES_DEC14_INTER_2 0xC38
#define AES_DEC15_INTER_3 0xC3C
#define AES_DEC16_CTRL 0xC40
#define AES_DEC17_IV_0 0xC44
#define AES_DEC18_IV_1 0xC48
#define AES_DEC19_IV_2 0xC4C
#define AES_DEC20_IV_3 0xC50

/* AES */
#define AES_MODE_ECB 0
#define AES_MODE_CBC 1
#define AES_MODE_CFB_ENC 2
#define AES_MODE_CFB_DEC 3
#define AES_MODE_OFB_ENC 4
#define AES_MODE_OFB_DEC 5
#define AES_MODE_CTR_ENC 6
#define AES_MODE_CTR_DEC 7

#define AES_BYTE_SWAP_LE ~(1 << 8)
#define AES_BYTE_SWAP_BE (1 << 8)
#define AES_WORD_SWAP_LE ~(1 << 9)
#define AES_WORD_SWAP_BE (1 << 9)
#define AES_BIG_ENDIAN (AES_BYTE_SWAP_BE | AES_WORD_SWAP_BE)
#define AES_LIT_ENDIAN 0

#define AES_KEY_128 0
#define AES_KEY_256 1

/* Timeout */
#define TIMEOUT_THRESHOLD 3000

#define BigtoLittle32(A)                                                                               \
	((((u32)(A)&0xff000000) >> 24) | (((u32)(A)&0x00ff0000) >> 8) | (((u32)(A)&0x0000ff00) << 8) | \
	 (((u32)(A)&0x000000ff) << 24))

typedef enum {
	DMA_NORMAL,

	DMA_AES_ECB_DEC_BE,
	DMA_AES_ECB_DEC_LE,
	DMA_AES_CBC_DEC_BE,
	DMA_AES_CBC_DEC_LE,

	DMA_AES_DEC_MAX,

	DMA_AES_ECB_ENC_BE,
	DMA_AES_ECB_ENC_LE,
	DMA_AES_CBC_ENC_BE,
	DMA_AES_CBC_ENC_LE,
	DMA_AES_CFB_ENC_BE,
	DMA_AES_CFB_ENC_LE,
	DMA_AES_CFB_DEC_BE,
	DMA_AES_CFB_DEC_LE,
	DMA_AES_OFB_ENC_BE,
	DMA_AES_OFB_ENC_LE,
	DMA_AES_OFB_DEC_BE,
	DMA_AES_OFB_DEC_LE,
	DMA_AES_CTR_ENC_BE,
	DMA_AES_CTR_ENC_LE,
	DMA_AES_CTR_DEC_BE,
	DMA_AES_CTR_DEC_LE,

	DMA_NRW,
	DMA_MAX,
} dma_op_mode;

#define AES_KEY_LEN 32
#define AES_IV_LEN 16
/* if the key inserted is big endian, define the macro as BigtoLittle32 */
#define AES_KEY_ENDIAN

struct dma_args {
	u32 oper_mode;
	u32 loop_cnt;
	u32 flush_addr_skip_r;
	u32 flush_addr_skip_w;
#ifdef AUGENTIX_CRYPTO_ALG_TYPE_ABLKCIPHER
	u32 *aes_key;
	u32 *aes_iv;
	u32 aes_key_len;
#else
	unsigned char aes_key[AES_KEY_LEN];
	unsigned char aes_iv[AES_IV_LEN];
#endif
};

enum augentix_dma_prep_type {
	AUGENTIX_DMA_DESC_MEMCPY = 0,
};

struct augentix_dma_desc {
	struct list_head node;
	struct dma_async_tx_descriptor desc;
	enum dma_status status;
	dma_addr_t src;
	dma_addr_t dest;
	size_t len;
	size_t len_off;
	int loop;
	size_t skip_r;
	size_t skip_w;
	enum dma_transfer_direction direction;
	enum augentix_dma_prep_type type;
};

struct augentix_dma_channel {
	struct augentix_dma_engine *dma;
	unsigned int channel;
	struct tasklet_struct dma_tasklet;
	struct list_head ld_free;
	struct list_head ld_queue;
	struct list_head ld_active;
	int descs_allocated;
	struct dma_chan chan;
	enum dma_status status;
};

enum engine_status {
	ENGINE_IDLE,
	ENGINE_BUSY,
	ENGINE_W_DEQUEUE,
};

enum dma_addr_type {
	START,
	END,
};

struct augentix_dma_engine {
	struct device *dev;
	struct dma_device dma_device;
	void __iomem *base;
	struct clk *dma_clk;
	spinlock_t lock;
	struct augentix_dma_channel channel[AUGENTIX_DMA_MAX_CHANNELS];

	struct ablkcipher_request *req;
	struct scatterlist *sg_src;
	struct scatterlist *sg_dst;
	struct tasklet_struct tasklet;
	enum engine_status eng_st;
	// u8 bank_addr_type;
	// u8 col_addr_type;
	// u32 bank_interleave;
	u8 busy;
	u8 is_ablk_mode;
};

struct augentix_aes_ctx {
	struct augentix_dma_engine *dev;
	void *src;
	void *dst;
	u32 mode;
	u32 len;
	u32 keylen;
	u32 aes_key[8];
	u32 *aes_iv;
};

struct augentix_aes_reqctx {
	unsigned long mode;
};

#endif
