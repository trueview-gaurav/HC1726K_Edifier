#include <linux/init.h>
#include <linux/module.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/mm.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/delay.h>
#include <linux/unistd.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/mm.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include "augentix-dma-proxy.h"

#include <linux/crypto.h>
#include <crypto/aes.h>
#include <linux/scatterlist.h>
#include <linux/vmalloc.h>

#define TEST_TIMEOUT 4000

extern u32 dma_memcpy(void *dest, void *src, size_t len);
extern u32 dma_phy_memcpy(unsigned long dest, unsigned long src, size_t len);
extern u32 dma_phy_memcpy_nrw(unsigned long dest, unsigned long src, size_t access_length, u32 loop_cnt,
                              u32 flush_skip_r, u32 flush_skip_w);
extern u32 dma_phy_memcpy_timeout(unsigned long dest, unsigned long src, size_t len, int timeout);

struct crypt_result {
	struct completion completion;
	int err;
};

static dev_t g_dma_devt;
static struct class *g_dma_class;
static struct cdev g_dma_cdev;

static void show_dma_results(u8 *src, u8 *dst, u32 xfer_len)
{
	int i;
	int last_i = 0;
	u8 last = 0;
	for (i = 0; i < xfer_len; i++) {
		if (last != dst[i]) {
			if (i != last_i) {
				pr_cont("(%d)\n", i - last_i);
				last_i = i;
			}
			last = dst[i];
			pr_info("%d : %c", i, dst[i]);
		}
	}
	pr_cont("(%d)\n", i - last_i);
	pr_info("=========================\n");
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
static void request_done(struct crypto_async_request *req, int err)
{
	struct crypt_result *res = req->data;
	if (err == -EINPROGRESS)
		return;
	res->err = err;
	complete(&res->completion);
}

void aes_encrypt_blocks(u8 *name, u8 *dst, u8 *src, u32 len, u8 *pkey, u8 *piv)
{
	int ret;
	struct crypto_ablkcipher *tfm;
	struct ablkcipher_request *req;
	struct scatterlist *src_sg;
	struct scatterlist *dst_sg;
	struct crypt_result result;
	size_t iv_len;

	src_sg = kmalloc(sizeof(struct scatterlist), GFP_KERNEL);
	if (!src_sg) {
		pr_err("failed to alloc src_sg!!!\n");
		goto src_sg_free;
	}

	dst_sg = kmalloc(sizeof(struct scatterlist), GFP_KERNEL);
	if (!dst_sg) {
		pr_err("failed to alloc dst_sg!!!\n");
		goto dst_sg_free;
	}

	init_completion(&result.completion);

	tfm = crypto_alloc_ablkcipher(name, 0, 0);
	if (!tfm) {
		pr_err("failed to alloc tfm!!!\n");
		goto crypto_free;
	}

	crypto_ablkcipher_setkey(tfm, pkey, 32);

	req = ablkcipher_request_alloc(tfm, GFP_KERNEL);
	if (!req) {
		pr_info("ablkcipher_request_alloc failed\n");
		goto free_cipher;
	}
	ablkcipher_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG, request_done, &result);
	//crypto_ablkcipher_clear_flags(tfm, ~0);

	sg_init_one(src_sg, src, len);
	sg_init_one(dst_sg, dst, len);

	ablkcipher_request_set_crypt(req, src_sg, dst_sg, len, piv);
	ret = crypto_ablkcipher_encrypt(req);
	if (ret == 0) {
		request_done(&req->base, 0);
	} else if (ret != -EINPROGRESS && ret != -EBUSY) {
		pr_info("crypte_ablkcipher_encrypt failed %d\n", ret);
		goto free_all;
	}

	/* wait for completion... */
	ret = wait_for_completion_interruptible(&result.completion);
	if (ret || (ret = result.err)) {
		pr_info("decryption failed %d\n", ret);
		goto free_all;
	}

free_all:
	ablkcipher_request_free(req);
free_cipher:
	crypto_free_ablkcipher(tfm);
crypto_free:
	kfree(dst_sg);
dst_sg_free:
	kfree(src_sg);
src_sg_free:
	return;
}

void aes_decrypt_blocks(char *name, u8 *dst, u8 *src, u32 len, u8 *pkey, u8 *piv)
{
	int ret;
	struct crypto_ablkcipher *tfm;
	struct ablkcipher_request *req;
	struct scatterlist *src_sg;
	struct scatterlist *dst_sg;
	struct crypt_result result;
	size_t iv_len;

	src_sg = kmalloc(sizeof(struct scatterlist), GFP_KERNEL);
	if (!src_sg) {
		pr_err("failed to alloc src_sg!!!\n");
		goto src_sg_free;
	}

	dst_sg = kmalloc(sizeof(struct scatterlist), GFP_KERNEL);
	if (!dst_sg) {
		pr_err("failed to alloc dst_sg!!!\n");
		goto dst_sg_free;
	}

	init_completion(&result.completion);

	tfm = crypto_alloc_ablkcipher(name, 0, 0);
	if (!tfm) {
		pr_err("failed to alloc tfm!!!\n");
		goto crypto_free;
	}

	crypto_ablkcipher_setkey(tfm, pkey, 32);

	req = ablkcipher_request_alloc(tfm, GFP_KERNEL);
	if (!req) {
		pr_info("ablkcipher_request_alloc failed\n");
		goto free_cipher;
	}
	ablkcipher_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG, request_done, &result);
	crypto_ablkcipher_clear_flags(tfm, ~0);
	iv_len = crypto_ablkcipher_ivsize(tfm);

	sg_init_one(src_sg, src, len);
	sg_init_one(dst_sg, dst, len);

	ablkcipher_request_set_crypt(req, src_sg, dst_sg, len, piv);
	ret = crypto_ablkcipher_decrypt(req);
	if (ret == 0) {
		request_done(&req->base, 0);
	} else if (ret != -EINPROGRESS && ret != -EBUSY) {
		pr_info("crypte_ablkcipher_encrypt failed %d\n", ret);
		goto free_all;
	}

	/* wait for completion... */
	ret = wait_for_completion_interruptible(&result.completion);
	if (ret || (ret = result.err)) {
		pr_info("decryption failed %d\n", ret);
		goto free_all;
	}

free_all:
	ablkcipher_request_free(req);
free_cipher:
	crypto_free_ablkcipher(tfm);
crypto_free:
	kfree(dst_sg);
dst_sg_free:
	kfree(src_sg);
src_sg_free:
	return;
}

#if 0
void aes_cbc_encrypt_blocks(u8* dst, u8* src, u32 len, u8 *pkey, u8 *piv)
{
	int ret;
	struct crypto_blkcipher 	*tfm;
	struct blkcipher_desc 	desc;
	struct scatterlist 		*src_sg;
	struct scatterlist 		*dst_sg;
	size_t iv_len;
	void *iv;

	src_sg = kmalloc(sizeof(struct scatterlist),GFP_KERNEL);
	if (!src_sg) {
		pr_err("failed to alloc src_sg!!!\n");
		goto src_sg_free;
	}
	dst_sg = kmalloc(sizeof(struct scatterlist),GFP_KERNEL);
	if (!dst_sg) {
		pr_err("failed to alloc dst_sg!!!\n");
		goto dst_sg_free;
	}

	tfm = crypto_alloc_blkcipher("cbc(aes)", 0,  CRYPTO_ALG_ASYNC);
	if (!tfm)
	{
		pr_err("failed to alloc tfm!!!\n");
		goto crypto_free;
	}

	desc.tfm = tfm;
	desc.flags = 0;

	crypto_blkcipher_setkey(tfm, pkey, LEN_AES_KEY);

	iv = crypto_blkcipher_crt(tfm)->iv;
	iv_len = crypto_blkcipher_ivsize(tfm);

	memcpy(iv, piv, LEN_AES_INIT_VT);

	sg_init_one(src_sg, src, len);
	sg_init_one(dst_sg, dst, len);

	ret = crypto_blkcipher_encrypt(&desc, dst_sg, src_sg, src_sg->length);
	if (ret < 0) {
		  pr_err("crypto_blkcipher_encrypt failed %d\n", ret);
	}
	crypto_free_blkcipher(tfm);

crypto_free:
	kfree(dst_sg);
dst_sg_free:
	kfree(src_sg);
src_sg_free:
	pr_err("MY_TEST: END!!!\n");
}

void aes_ecb_encrypt_blocks(u8* dst, u8* src, u32 len, u8 *pkey)
{
	int ret;
	struct crypto_blkcipher 	*tfm;
	struct blkcipher_desc 	desc;
	struct scatterlist 		*src_sg;
	struct scatterlist 		*dst_sg;
	size_t iv_len;
	void *iv;

	src_sg = kmalloc(sizeof(struct scatterlist),GFP_KERNEL);
	if (!src_sg) {
		pr_err("failed to alloc src_sg!!!\n");
		goto src_sg_free;
	}
	dst_sg = kmalloc(sizeof(struct scatterlist),GFP_KERNEL);
	if (!dst_sg) {
		pr_err("failed to alloc dst_sg!!!\n");
		goto dst_sg_free;
	}

	tfm = crypto_alloc_blkcipher("ecb(aes)", 0,  CRYPTO_ALG_ASYNC);
	if (!tfm)
	{
		pr_err("failed to alloc tfm!!!\n");
		goto crypto_free;
	}

	desc.tfm = tfm;
	desc.flags = 0;

	crypto_blkcipher_setkey(tfm, pkey, LEN_AES_KEY);

	//iv = crypto_blkcipher_crt(tfm)->iv;
	//iv_len = crypto_blkcipher_ivsize(tfm);

	//memcpy(iv, piv, LEN_AES_INIT_VT);

	sg_init_one(src_sg, src, len);
	sg_init_one(dst_sg, dst, len);

	ret = crypto_blkcipher_encrypt(&desc, dst_sg, src_sg, src_sg->length);
	if (ret < 0) {
		  pr_err("crypto_blkcipher_encrypt failed %d\n", ret);
	}
	crypto_free_blkcipher(tfm);

crypto_free:
	kfree(dst_sg);
dst_sg_free:
	kfree(src_sg);
src_sg_free:
	pr_err("MY_TEST: END!!!\n");
}
#endif
#endif // LINUX_VERSION_CODE

struct file_operations dma_client_fops = {
	.owner = THIS_MODULE,
	.open = NULL,
	.release = NULL,
	.unlocked_ioctl = NULL,
	.mmap = NULL,
};

static int augentix_dma_client_test_dma(void)
{
	struct device *dev;

	u32 xfer_len = 32768 * 16;
	u8 *dst;
	u8 *dst_virt;
	u8 *src;
	dma_addr_t bus_src = 0, bus_dst = 0;

	u32 err;

	err = alloc_chrdev_region(&g_dma_devt, 0, 1, "dma_client");
	if (err) {
		return 0;
	}

	/* fill cdev Data Structure */
	cdev_init(&g_dma_cdev, &dma_client_fops);
	g_dma_cdev.owner = THIS_MODULE;
	g_dma_cdev.ops = &dma_client_fops;

	if (cdev_add(&g_dma_cdev, g_dma_devt, 1)) {
		unregister_chrdev_region(g_dma_devt, 1);
		pr_err("cdev_add fail\n");
		return 0;
	}

	/* generate Class */
	g_dma_class = class_create(THIS_MODULE, "dma_client");
	if (IS_ERR(g_dma_class)) {
		cdev_del(&g_dma_cdev);
		unregister_chrdev_region(g_dma_devt, 1);
		pr_err("class_create fail\n");
		return 0;
	}

	/* create device node in sys file system */
	dev = device_create(g_dma_class, NULL, g_dma_devt, NULL, "dma_client");

	if (dev == NULL) {
		pr_err("create device fail\n");
		return 0;
	}

	dma_set_coherent_mask(dev, DMA_BIT_MASK(32));

	src = dma_alloc_coherent(dev, xfer_len, &bus_src, GFP_KERNEL);
	dst = dma_alloc_coherent(dev, xfer_len, &bus_dst, GFP_KERNEL);

	pr_info("Source: virt %x, bus %x\n", (int)src, bus_src);
	pr_info("Dest: virt %x, bus %x\n", (int)dst, bus_dst);
	pr_info("PHY: %x\n", virt_to_phys(src));

	if (src == NULL || dst == NULL)
		return 0;

	memset(src, '*', xfer_len);

	/* Using kernel virtual address as the input */
	dst_virt = kzalloc(xfer_len, GFP_KERNEL);
	memset(dst, '-', xfer_len);
	/*do not use virtual address allocated by dma_alloc_coherent */
	dma_memcpy(dst_virt, src, xfer_len);
	show_dma_results(src, dst_virt, xfer_len);

	/* Using physical address as the input */
	memset(dst, '-', xfer_len);
	dma_phy_memcpy(bus_dst, bus_src, xfer_len);
	show_dma_results(src, dst, xfer_len);

	memset(dst, '-', xfer_len);
	dma_phy_memcpy_nrw(bus_dst, bus_src, 35874, 4, 35874, 14521);
	show_dma_results(src, dst, xfer_len);

	memset(dst, '-', xfer_len);
	dma_phy_memcpy_nrw(bus_dst, bus_src, 47510, 4, 47510, 25471);
	show_dma_results(src, dst, xfer_len);

	memset(dst, '-', xfer_len);
	dma_phy_memcpy_nrw(bus_dst, bus_src, 78452, 4, 78452, 12547);
	show_dma_results(src, dst, xfer_len);

	memset(dst, '-', xfer_len);
	dma_phy_memcpy_nrw(bus_dst, bus_src, 4096, 8, 4096, 10240);
	show_dma_results(src, dst, xfer_len);

	/* Using physical address as the input */
	memset(dst, '-', xfer_len);
	dma_phy_memcpy(bus_dst, bus_src, xfer_len);
	show_dma_results(src, dst, xfer_len);

	memset(dst, '-', xfer_len);
	dma_phy_memcpy_timeout(bus_dst, bus_src, xfer_len, TEST_TIMEOUT);
	show_dma_results(src, dst, xfer_len);

	kfree(dst_virt);
	dma_free_coherent(dev, xfer_len, src, bus_src);
	dma_free_coherent(dev, xfer_len, dst, bus_dst);
	device_del(dev);
	class_destroy(g_dma_class);
	cdev_del(&g_dma_cdev);
	unregister_chrdev_region(g_dma_devt, 1);

	return 0;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0)
void show_crypto_result(u8 *data, size_t len)
{
	int i;
	u8 buf[100];
	memset(buf, 0, 100);
	for (i = 0; i < len; i++) {
		if (i % 16 == 0) {
			pr_info("%s\n", buf);
			sprintf(buf, "%03x: ", i);
		}
		sprintf(buf + strlen(buf), "%02x, ", data[i]);
	}
	pr_info("%s\n", buf);
}

void Init_src(u8 *src, size_t len)
{
	int i;
	for (i = 0; i < len; i++) {
		src[i] = (u8)(i & 0xff);
	}
}

static void augentix_dma_client_test_crypto(void)
{
	u8 key[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
		       0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };

	u8 key_inv[32];

	u8 ivec[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

	u8 *dst, *src;
	u32 xfer_len = 128;

	src = kmalloc(xfer_len, GFP_KERNEL);
	dst = kmalloc(xfer_len, GFP_KERNEL);
	/* do aes-ecb encrypt */
	//memset(dst, 0, xfer_len);
	//aes_ecb_encrypt_blocks(dst, src, xfer_len, key);
	//how_results(dst, xfer_len);

	/* do aes-cbc encrypt */
	pr_info("CBC encrypt\n");
	Init_src(src, xfer_len);
	memset(dst, 0x55, xfer_len);
	aes_encrypt_blocks("cbc(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("CBC decrypt\n");
	memcpy(src, dst, xfer_len);
	aes_decrypt_blocks("cbc(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("ECB encrypt\n");
	key[0] = 55;
	Init_src(src, xfer_len);
	aes_encrypt_blocks("ecb(aes)", dst, src, xfer_len, key, NULL);
	show_crypto_result(dst, xfer_len);

	pr_info("ECB decrypt\n");
	memcpy(src, dst, xfer_len);
	aes_decrypt_blocks("ecb(aes)", dst, src, xfer_len, key, NULL);
	show_crypto_result(dst, xfer_len);

	pr_info("CFB encrypt\n");
	key[0] = 88;
	Init_src(src, xfer_len);
	aes_encrypt_blocks("cfb(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("CFB decrypt\n");
	memcpy(src, dst, xfer_len);
	aes_decrypt_blocks("cfb(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("OFB encrypt\n");
	key[0] = 65;
	Init_src(src, xfer_len);
	aes_encrypt_blocks("ofb(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("OFB decrypt\n");
	memcpy(src, dst, xfer_len);
	aes_decrypt_blocks("ofb(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("ctr encrypt\n");
	key[0] = 98;
	Init_src(src, xfer_len);
	aes_encrypt_blocks("ctr(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);

	pr_info("ctr decrypt\n");
	memcpy(src, dst, xfer_len);
	aes_decrypt_blocks("ctr(aes)", dst, src, xfer_len, key, ivec);
	show_crypto_result(dst, xfer_len);
}
#endif // LINUX_VERSION_CODE

static int __init augentix_dma_client_init(void)
{
	augentix_dma_client_test_dma();

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
	augentix_dma_client_test_crypto();
#endif // LINUX_VERSION_CODE

	return 0;
}

static void __exit augentix_dma_client_exit(void)
{
	pr_info("augentix_dma_client_exit\n");
}

module_init(augentix_dma_client_init);
module_exit(augentix_dma_client_exit);

MODULE_DESCRIPTION("Augentix dma client for debug");
MODULE_AUTHOR("Nick Lin <nick.lin@augentix.com>");
MODULE_LICENSE("Dual BSD/GPL");
