#include <linux/module.h>
#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/random.h>
#include <linux/irqchip/arm-gic.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/uio_driver.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/mm.h>

#include <asm/io.h>
#include <linux/slab.h>

#include "common/config.h"

#define DRV_NAME "augentix_amp_driver"
#define KTHREAD_NAME "aug_amp"

#define PRINT_BUFF_SIZE (2048)

struct amp_early_channel {
	int32_t busy;
	int32_t request;
	int32_t response;
	void *data;
};

struct shm_header {
	volatile struct amp_early_channel chann;
	volatile uint32_t print_head;
	volatile uint32_t print_tail;
	volatile uint32_t sync_flag;
	volatile char print_buf[PRINT_BUFF_SIZE];
};

struct simple_shm_data {
	struct shm_header *shm_p;
	struct device *dev;
	struct task_struct *thread;
	bool thread_running;
	spinlock_t lock;
	int irq;
	struct completion complete;
	struct completion complete_sync;
};

struct uio_listener {
	struct uio_device *dev;
	s32 event_count;
};

static struct simple_shm_data *shm;
static bool uio_registered = false;

struct uio_info info = {
	.name = "amp_shm",
	.version = "0.1",
	.irq = UIO_IRQ_CUSTOM,
};

static int simple_shm_thread(void *data)
{
	struct simple_shm_data *shm = (struct simple_shm_data *)data;
	struct shm_header *shm_p = shm->shm_p;
	char buf[200 + 20];
	uint32_t len = 0;

	shm_p->sync_flag = 1;
	while (shm_p->sync_flag != 2) {
		schedule();
	}
	printk("## Shared memory hand shake complete\n");
	complete(&shm->complete_sync);

	while (1) {
		while (shm_p->print_head != shm_p->print_tail) {
			if (shm_p->print_head > shm_p->print_tail)
				len = shm_p->print_head - shm_p->print_tail;
			else
				len = PRINT_BUFF_SIZE - shm_p->print_tail;
			if (len > 200)
				len = 200;
			memset(buf, 0, sizeof(buf));
			sprintf(buf, "\n\e[1;34m");
			memcpy(buf + strlen(buf), (void *)shm_p->print_buf + shm_p->print_tail, len);
			sprintf(buf + strlen(buf), "\e[0m");
			printk(buf);
			shm_p->print_tail += len;
			shm_p->print_tail &= (PRINT_BUFF_SIZE - 1);
		}

		wait_for_completion(&shm->complete);
		//msleep(500);
	}

	return 0;
}

int simple_shm_start(struct simple_shm_data *shm)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&shm->lock, flags);

	shm->thread = kthread_create(simple_shm_thread, shm, KTHREAD_NAME);
	if (shm->thread == NULL) {
		printk("Create kthread fail\n");
		ret = -ENOMEM;
		goto END;
	}
	shm->thread_running = true;
	printk("Start shared-memory handling thread\n");
	wake_up_process(shm->thread);

END:
	spin_unlock_irqrestore(&shm->lock, flags);
	return ret;
}

int simple_shm_stop(struct simple_shm_data *shm)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&shm->lock, flags);

	ret = kthread_stop(shm->thread);
	if (ret < 0) {
		printk("Fail to disable\n");
		ret = -EINVAL;
		goto END;
	}

	shm->thread_running = false;
	printk("Stop shared-memory thread\n");
END:
	spin_unlock_irqrestore(&shm->lock, flags);
	return ret;
}

void simple_shm_cb(u32 sgi_id)
{
	complete(&shm->complete);
}

void amp_ipi_cb(u32 sgi_id)
{
	if (uio_registered)
		uio_event_notify(&info);
}

static ssize_t simple_shm_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int len;

	if (shm->thread_running == false)
		len = sprintf(buf, "Write \"on\" to start the shared-memory handling thread\n");
	else
		len = sprintf(
		        buf,
		        "Write \"queque X\"(X is an integer) to triger inter-processor communication\nor Write \"off\" to stop the shared-memory handling thread\n");
	if (len <= 0)
		dev_err(dev, "mydrv: Invalid sprintf len: %d\n", len);

	return len;
}


static ssize_t simple_shm_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	if (strncmp(buf, "on", 2) == 0) {
		if (shm->thread_running == false)
			simple_shm_start(shm);
	} else if (strncmp(buf, "off", 3) == 0) {
		if (shm->thread_running == true)
			simple_shm_stop(shm);
	} else {
		printk("Unknow command\n");
	}

	return count;
}
static DEVICE_ATTR(control, S_IRUGO | S_IWUSR, simple_shm_show, simple_shm_store);

static const struct vm_operations_struct shm_physical_vm_ops = {
#ifdef CONFIG_HAVE_IOREMAP_PROT
	.access = generic_access_phys,
#endif
};

static int _find_mem_index(struct uio_info *info, struct vm_area_struct *vma)
{
	if (vma->vm_pgoff < MAX_UIO_MAPS) {
		if (info->mem[vma->vm_pgoff].size == 0)
			return -1;
		return (int)vma->vm_pgoff;
	}
	return -1;
}

static int simple_shm_uio_mmap_physical(struct uio_info *info, struct vm_area_struct *vma)
{
	struct uio_device *idev = vma->vm_private_data;
	int mi = _find_mem_index(info, vma);
	struct uio_mem *mem;

	if (mi < 0)
		return -EINVAL;
	mem = idev->info->mem + mi;

	if (mem->addr & ~PAGE_MASK)
		return -ENODEV;
	if (vma->vm_end - vma->vm_start > mem->size)
		return -EINVAL;

	vma->vm_ops = &shm_physical_vm_ops;
	if (idev->info->mem[mi].memtype == UIO_MEM_PHYS) {
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	}

	/*
	 * We cannot use the vm_iomap_memory() helper here,
	 * because vma->vm_pgoff is the map index we looked
	 * up above in uio_find_mem_index(), rather than an
	 * actual page offset into the mmap.
	 *
	 * So we just do the physical mmap without a page
	 * offset.
	 */
	return remap_pfn_range(vma, vma->vm_start, mem->addr >> PAGE_SHIFT, vma->vm_end - vma->vm_start,
	                       vma->vm_page_prot);
}

static int simple_shm_uio_irqcontrol(struct uio_info *dev_info, s32 irq_on)
{
	return 0;
}

static int simple_shm_probe(struct platform_device *pdev)
{
	int ret = 0;
	//struct uio_info *info;

	//printk("##  simple_shm_probe probed\n");
	shm = devm_kzalloc(&pdev->dev, sizeof(struct simple_shm_data), GFP_KERNEL);
	if (!shm) {
		printk("simple_shm_probe alloc fail\n");
		return -ENOMEM;
	}
	memset(shm, 0, sizeof(struct simple_shm_data));
	shm->dev = &pdev->dev;

	spin_lock_init(&shm->lock);
	init_completion(&shm->complete);
	init_completion(&shm->complete_sync);

	shm->shm_p = (struct shm_header *)ioremap_cache(AMP_DRIVER_SHM_ADDR, AMP_DRIVER_SHM_SIZE);
	if (IS_ERR(shm->shm_p)) {
		printk("## Get shared memory fail\n");
		ret = -ENOMEM;
		goto ERR_1;
	}
	//printk("## shared memory virt: 0x%08x, size %d bytes\n", shm->shm_p, AMP_DRIVER_SHM_SIZE);

	info.mem[0].addr = AMP_SHM_START_ADDR;
	info.mem[0].memtype = UIO_MEM_LOGICAL;
	info.mem[0].size = AMP_SHM_TOTAL_SIZE;
	info.mem[0].name = "shared-memory";

	info.mem[1].addr = 0x84001000;
	info.mem[1].memtype = UIO_MEM_PHYS;
	info.mem[1].size = 0x1000;
	info.mem[1].name = "gic-reg";

	info.mmap = simple_shm_uio_mmap_physical;
	info.irqcontrol = simple_shm_uio_irqcontrol;

	if (uio_register_device(shm->dev, &info)) {
		printk("register UIO fail\n");
		ret = -ENODEV;
		goto ERR_2;
	}
	uio_registered = true;

	platform_set_drvdata(pdev, shm);

	simple_shm_start(shm);
	device_create_file(shm->dev, &dev_attr_control);

	gic_set_sgi_handler(0, simple_shm_cb);
	gic_set_sgi_handler(1, amp_ipi_cb);

	wait_for_completion(&shm->complete_sync);

	//printk("## simple_shm_probe end: %d\n", ret);
	return ret;
ERR_2:
	iounmap(shm->shm_p);
ERR_1:
	devm_kfree(&pdev->dev, shm);
	return ret;
}

static int simple_shm_remove(struct platform_device *pdev)
{
	struct simple_shm_data *shm = platform_get_drvdata(pdev);

	printk("##  simple_shm_remove\n");
	simple_shm_stop(shm);
	devm_kfree(&pdev->dev, shm);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

static const struct of_device_id simple_shm_dt_ids[] = {
	{ .compatible = "augentix,simple_shm" },
	{},
};
MODULE_DEVICE_TABLE(of, simple_shm_dt_ids);

static struct platform_driver simple_shm_driver = {
	.probe = simple_shm_probe,
	.remove = simple_shm_remove,
	.driver =
	        {
	                .owner = THIS_MODULE,
	                .name = DRV_NAME,
	                .of_match_table = simple_shm_dt_ids,
	        },
};
module_platform_driver(simple_shm_driver);

MODULE_AUTHOR("Jerry Wu, Augentix <jerry.wu@augentix.com>");
MODULE_DESCRIPTION("simple shm for dual core test");
MODULE_LICENSE("GPL");
