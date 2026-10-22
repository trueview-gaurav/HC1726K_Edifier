#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/mm.h>
#include <linux/pagemap.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/vmalloc.h>
#include <linux/time.h>
#include "augentix-dma-proxy.h"

/* char driver info */
#define DRIVER_NAME "security"
static dev_t g_dma_devt;
static struct class *g_dma_class;
struct cdev g_dma_cdev;

struct dma_pxy_dev {
	//struct dma_args_t 	dma;  		/*it's for dma copy*/
	esreq aes; /*it's for aes encrypt*/
	u8 *mmap_buf;
	u32 mmap_usr_vir;
	spinlock_t lock;
};

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

extern struct dma_chan *__augentix_dma_request_channel(unsigned int flags);
extern void __augentix_dma_release_channel(struct dma_chan *chan);
extern unsigned int __augentix_dma_copy(struct dma_chan *chan, void *dest, void *src, size_t len, int timeout);
extern unsigned int __augentix_dma_config(struct dma_chan *chan, u32 op_mode, unsigned long arg);
extern struct dma_chan *__augentix_get_dma_chan(void);

/**
 * Function to copy data by dma. The inputs must be physical address.
 * @dest the destination physical address .
 * @src the source physical address.
 * @len the copied length.
 * \return Returns 0 on success else return the error status.
 */
u32 dma_phy_memcpy(unsigned long dest, unsigned long src, size_t len)
{
	u32 ret = 0;
	struct dma_chan *memcpy_chan;

	memcpy_chan = __augentix_get_dma_chan();

	if (!memcpy_chan) {
		pr_err("failure to request dma channel\n");
		return -1;
	}

	__augentix_dma_config(memcpy_chan, DMA_NORMAL, 0);

	ret = __augentix_dma_copy(memcpy_chan, (void *)dest, (void *)src, len, 1);

	return ret;
}
EXPORT_SYMBOL(dma_phy_memcpy);

/**
 * Function to copy data by dma. The inputs must be physical address.
 * @dest the destination physical address .
 * @src the source physical address.
 * @len the copied length.
 * @timeout the timeout value.
 * \return Returns 0 on success else return the error status.
 */
u32 dma_phy_memcpy_timeout(unsigned long dest, unsigned long src, size_t len, int timeout)
{
	u32 ret = 0;
	struct dma_chan *memcpy_chan;

	memcpy_chan = __augentix_get_dma_chan();

	if (!memcpy_chan) {
		pr_err("failure to request dma channel\n");
		return -1;
	}

	__augentix_dma_config(memcpy_chan, DMA_NORMAL, 0);

	ret = __augentix_dma_copy(memcpy_chan, (void *)dest, (void *)src, len, timeout);

	return ret;
}
EXPORT_SYMBOL(dma_phy_memcpy_timeout);

/**
 * Function to copy data by dma with flush_skip. The inputs must be physical address.
 * @dest the destination physical address .
 * @src the source physical address.
 * @access_length the copied length of each loop.
 * @loop_cnt the number of times to copy.
 * @flush_skip_r the address to skip while reading. (note that maximum skip is 2^20 - 1)
 * @flush_skip_w the address to skip while writing. (note that maximum skip is 2^20 - 1)
 * \return Returns 0 on success else return the error status.
 */
u32 dma_phy_memcpy_nrw(unsigned long dest, unsigned long src, size_t access_length, u32 loop_cnt, u32 flush_skip_r,
                       u32 flush_skip_w)
{
	u32 ret = 0;
	struct dma_chan *memcpy_chan;
	struct dma_args *arg = kzalloc(sizeof(struct dma_args), GFP_KERNEL);

	memcpy_chan = __augentix_get_dma_chan();

	if (!memcpy_chan) {
		pr_err("failure to request dma channel\n");
		return -1;
	}

	arg->loop_cnt = loop_cnt;
	arg->flush_addr_skip_r = flush_skip_r;
	arg->flush_addr_skip_w = flush_skip_w;

	__augentix_dma_config(memcpy_chan, DMA_NRW, (unsigned long)arg);

	ret = __augentix_dma_copy(memcpy_chan, (void *)dest, (void *)src, access_length, 1);

	return ret;
}
EXPORT_SYMBOL(dma_phy_memcpy_nrw);

/**
 * Function to copy data by dma. The inputs must be kernel virtual address.
 * @dest the destination kernel virtual address.
 * @src the source kernel virtual address.
 * @len the copied length.
 * \return Returns 0 on success else return the error status.
 */
u32 dma_memcpy(void *dest, void *src, size_t len)
{
	u32 ret = 0;
	dma_addr_t dma_dest, dma_src;
	struct dma_chan *memcpy_chan;

	memcpy_chan = __augentix_get_dma_chan();

	if (!memcpy_chan) {
		pr_err("failure to request dma channel\n");
		return -1;
	}

	__augentix_dma_config(memcpy_chan, DMA_NORMAL, 0);

	dma_src = dma_map_single(memcpy_chan->device->dev, src, len, DMA_TO_DEVICE);
	dma_dest = dma_map_single(memcpy_chan->device->dev, dest, len, DMA_FROM_DEVICE);

	if ((dma_src == dma_dest) || (len <= 0)) {
		ret = 0;
		goto end;
	}

	if ((dma_src < dma_dest) && ((dma_src + len) > dma_dest)) {
		ret = -1;
		pr_err("dma source address overlaps with dma destination address\n");
		printk(KERN_INFO
		       "dma src address overlaps with dma dest address, dma src address:0x%x, dma dest address:0x%x,len=0x%x\n",
		       dma_src, dma_dest, len);
		goto end;
	}

	if ((dma_dest < dma_src) && ((dma_dest + len) > dma_src)) {
		ret = -1;
		printk(KERN_INFO
		       "dma src address overlaps with dma dest address, dma src address:0x%x, dma dest address:0x%x,len=0x%x\n",
		       dma_src, dma_dest, len);
		goto end;
	}

	ret = __augentix_dma_copy(memcpy_chan, (void *)dma_dest, (void *)dma_src, len, 1);

end:

	dma_unmap_single(memcpy_chan->device->dev, dma_src, len, DMA_TO_DEVICE);
	dma_unmap_single(memcpy_chan->device->dev, dma_dest, len, DMA_FROM_DEVICE);

	return ret;
}
EXPORT_SYMBOL(dma_memcpy);

static int dma_proxy_open(struct inode *inode, struct file *file)
{
	struct dma_pxy_dev *dev;

	dev = kzalloc(sizeof(struct dma_pxy_dev), GFP_KERNEL);
	if (dev == NULL) {
		return -ENOMEM;
	}

	dev->mmap_buf = kzalloc(MAX_MMAP_SIZE, GFP_KERNEL);
	if (dev->mmap_buf == NULL) {
		return -ENOMEM;
	}

	spin_lock_init(&dev->lock);

	file->private_data = dev;

	return 0;
}

static int dma_proxy_close(struct inode *inode, struct file *file)
{
	struct dma_pxy_dev *dev = file->private_data;

	kfree(dev->mmap_buf);
	dev->mmap_buf = NULL;

	kfree(dev);
	dev = NULL;

	return 0;
}

static long dma_proxy_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct dma_pxy_dev *dev = file->private_data;
	int ret = 0;
	struct dma_chan *chan = __augentix_get_dma_chan();
	struct dma_args *dma_args = kzalloc(sizeof(struct dma_args), GFP_KERNEL);
	dma_addr_t dma_dst, dma_src;
	void *src, *dst;
	u32 op_mode = 0;
	u32 ecrylen = 0;
	//int i;
	//u8* p_dest;

	switch (cmd) {
	case ES_ENCRYPT:
		if (copy_from_user(&dev->aes, (int __user *)arg, sizeof(esreq))) {
			ret = -EFAULT;
			goto done;
		}
		//pr_info("dev->aes.key_length = %d\n",dev->aes.key_length);
		src = dev->mmap_buf + (dev->aes.DataIn_addr - dev->mmap_usr_vir);
		dst = dev->mmap_buf + (dev->aes.DataOut_addr - dev->mmap_usr_vir);

		ecrylen = dev->aes.data_length - dev->aes.IV_length;

		/* FIXME: should consider endianness */
		if (dev->aes.mode == CBC_mode) {
			//pr_info("CBC_mode\n");
			op_mode = DMA_AES_CBC_ENC_BE;
		} else if (dev->aes.mode == ECB_mode) {
			//pr_info("ECB_mode\n");
			op_mode = DMA_AES_ECB_ENC_BE;
		}

		/* FIXME: assgina the aes key and iv to dma_args */
		// dma_args->aes_key = &dev->aes.key_addr;
		// dma_args->aes_iv = &dev->aes.IV_addr;

		__augentix_dma_config(chan, op_mode, (unsigned long)dma_args);

		dma_src = dma_map_single(chan->device->dev, src, ecrylen, DMA_TO_DEVICE);
		dma_dst = dma_map_single(chan->device->dev, dst, ecrylen, DMA_FROM_DEVICE);

		__augentix_dma_copy(chan, (void *)dma_dst, (void *)dma_src, ecrylen, 1);

		dma_unmap_single(chan->device->dev, dma_src, ecrylen, DMA_TO_DEVICE);
		dma_unmap_single(chan->device->dev, dma_dst, ecrylen, DMA_FROM_DEVICE);

		break;

	default:
		kfree(dma_args);
		ret = -ENOTTY;
		break;
	}

done:
	return (ret);
}

static int dma_proxy_mmap(struct file *file, struct vm_area_struct *vma)
{
	int ret = 0;
	struct dma_pxy_dev *dev = file->private_data;
	//unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
	unsigned long pfn_start = (virt_to_phys(dev->mmap_buf) >> PAGE_SHIFT) + vma->vm_pgoff;
	//unsigned long virt_start = (unsigned long)dev->mmap_buf + offset;
	unsigned long size = vma->vm_end - vma->vm_start;

	//printk("phy: 0x%lx, offset: 0x%lx, size: 0x%lx\n", pfn_start << PAGE_SHIFT, offset, size);
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	ret = remap_pfn_range(vma, vma->vm_start, pfn_start, size, vma->vm_page_prot);
	if (ret) {
		printk("%s: remap_pfn_range failed at [0x%lx  0x%lx]\n", __func__, vma->vm_start, vma->vm_end);
	} else {
		//printk("%s: map 0x%lx to 0x%lx, size: 0x%lx\n", __func__, virt_start,
		//		   vma->vm_start, size);
		dev->mmap_usr_vir = vma->vm_start;
	}

	return ret;
}

struct file_operations dma_pxy_fops = {
	.owner = THIS_MODULE,
	.open = dma_proxy_open,
	.release = dma_proxy_close,
	.unlocked_ioctl = dma_proxy_ioctl,
	.mmap = dma_proxy_mmap,
};

static int __init augentix_dma_proxy_init(void)
{
	int err;

	err = alloc_chrdev_region(&g_dma_devt, 0, 1, DRIVER_NAME);
	if (err) {
		return -EBUSY;
	}

	/* fill cdev Data Structure */
	cdev_init(&g_dma_cdev, &dma_pxy_fops);
	g_dma_cdev.owner = THIS_MODULE;
	g_dma_cdev.ops = &dma_pxy_fops;

	if (cdev_add(&g_dma_cdev, g_dma_devt, 1)) {
		unregister_chrdev_region(g_dma_devt, 1);
		return -EBUSY;
	}

	/* generate Class */
	g_dma_class = class_create(THIS_MODULE, "dma_class");
	if (IS_ERR(g_dma_class)) {
		cdev_del(&g_dma_cdev);
		unregister_chrdev_region(g_dma_devt, 1);
		return PTR_ERR(g_dma_class);
	}

	/* create device node in sys file system */
	device_create(g_dma_class, NULL, g_dma_devt, NULL, DRIVER_NAME);

	return 0;
}

static void __exit augentix_dma_proxy_exit(void)
{
	device_destroy(g_dma_class, g_dma_devt);
	class_destroy(g_dma_class);
	cdev_del(&g_dma_cdev);
	unregister_chrdev_region(g_dma_devt, 1);
}

module_init(augentix_dma_proxy_init);
module_exit(augentix_dma_proxy_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Nick Lin<nick.lin@augentix.com>");
MODULE_DESCRIPTION("This is a dma/aes proxy driver");
MODULE_VERSION("v1");
