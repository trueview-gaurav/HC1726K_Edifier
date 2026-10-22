#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/io.h>

#define SPI0_START_ADDR 0x80800000
#define SPI1_START_ADDR 0x80810000

#if defined(CONFIG_SAPPORO)
#define SPI0_SDO_IOMUX 0x80001170
#define SPI0_SCK_IOMUX 0x8000116C
#define SPI1_SDO_P0_IOMUX 0x80001144
#define SPI1_SCK_P0_IOMUX 0x80001150
#define SPI1_SDO_P1_IOMUX 0x80001134
#define SPI1_SCK_P1_IOMUX 0x80001138
#else
#define SPI0_SDO_IOMUX 0x8000151C
#define SPI0_SCK_IOMUX 0x80001514
#define SPI1_SDO_P0_IOMUX 0x800015F0
#define SPI1_SCK_P0_IOMUX 0x800015F4
#define SPI1_SDO_P1_IOMUX 0x800015E4
#define SPI1_SCK_P1_IOMUX 0x800015E8
#endif // CONFIG_SAPPORO

#if defined(CONFIG_SAPPORO)
#define SPI0_SDO_OFFSET 0x04
#define SPI0_SCK_OFFSET 0x04
#define SPI1_SDO_P0_OFFSET 0x03
#define SPI1_SCK_P0_OFFSET 0x01
#define SPI1_SDO_P1_OFFSET 0x03
#define SPI1_SCK_P1_OFFSET 0x03
#else
#define SPI0_SDO_OFFSET 0x01
#define SPI0_SCK_OFFSET 0x01
#define SPI1_SDO_P0_OFFSET 0x01
#define SPI1_SCK_P0_OFFSET 0x01
#define SPI1_SDO_P1_OFFSET 0x02
#define SPI1_SCK_P1_OFFSET 0x02
#endif // CONFIG_SAPPORO

#define SPI_CTRLR0 0x0 // Control Register 0, offset = 0x0
#define SPI_SSIENR 0x8 // SSI Enable Register, offset = 0x08
#define SPI_TRIGGER 0x10 // Slave Enable Register, which also triggers data transmission, offset = 0x10
#define SPI_SER SPI_TRIGGER
#define SPI_BAUDR 0x14 // Baud Rate Select, offset = 0x14
#define SPI_TXFTLR 0x18 // Transmit FIFO Threshold Level, offset = 0x18
#define SPI_IMR 0x2C // Interrupt Mask Register, offset = 0x2C
#define SPI_FIFO_LEVEL 0x20 // Transmit FIFO Level Register, offset = 0x20
#define SPI_LOG 0x60 // Data Register, offset = 0x60

#define SPI_FIFO_SIZE 0x8
#define GICC_CTRL 0x84002000

static dev_t device_number;
struct cdev spi_dbg_cdev;
struct class *spi_dbg_class;
struct device *spi_dbg_device;

static unsigned int spi_dev_num = 0xFF; // Set by user space or device tree, 0xFF means no setting
static unsigned int spi_port_num = 0xFF; // Set by user space or device tree, 0xFF means no setting
#ifdef MODULE
module_param(spi_dev_num, uint, 0644); // 0644 : root-writable
MODULE_PARM_DESC(spi_dev_num, "SPI device number");

module_param(spi_port_num, uint, 0644); // 0644 : root-writable
MODULE_PARM_DESC(spi_port_num, "SPI port number");
#endif //MODULE

static unsigned int spi_start_addr = 0;

static unsigned int spi_sdo_old = 0;
static unsigned int spi_sck_old = 0;

static volatile unsigned int __iomem *spi_addr = NULL;

static volatile unsigned int __iomem *spi_sdo = NULL;
static volatile unsigned int __iomem *spi_sck = NULL;

static volatile unsigned int __iomem *gicc_ctlr = NULL;

static inline volatile unsigned int __iomem *get_spi_reg_addr(unsigned int offset)
{
	return (volatile unsigned int __iomem *)(spi_addr + (offset / 4));
}

/** 
 * spi_dbg_log_event - write event log to spi debugger
 * @event_id: number of event type
 * 
 * event_id ranges from 0 to 127.
 */
int spi_dbg_log_event(u8 event_id)
{
	if (event_id > 127) {
		pr_err("[SPI_DBG] event_id is not correct.\n");
		return -EINVAL;
	}
	/* Disable interrupt of local processor */
	writel(0, gicc_ctlr);

	/* Busy waiting until FIFO is not full*/
	while (readl(get_spi_reg_addr(SPI_FIFO_LEVEL)) > (SPI_FIFO_SIZE - 1)) {
		writel(0xFF, get_spi_reg_addr(SPI_TRIGGER));
	}

	/* The bit-7 is 0 which represents event log */
	writel((event_id & ~(1 << 7)), get_spi_reg_addr(SPI_LOG));
	writel(0xFF, get_spi_reg_addr(SPI_TRIGGER));

	/* Enable interrupt of local processor */
	writel(1, gicc_ctlr);

	return 0;
}
EXPORT_SYMBOL(spi_dbg_log_event);

/** 
 * spi_dbg_log_data - write data log to spi debugger
 * @data_id: number of data type
 * @len: length of data
 * @data: data of log
 * 
 * data_id ranges from 0 to 31.
 * len ranges from 1 to 4, which means data length.
 */
int spi_dbg_log_data(u8 data_id, u8 len, u8 *data)
{
	u8 count = 0;

	if (len < 1 || len > 4) {
		pr_err("[SPI_DBG] Data length is not correct.\n");
		return -EINVAL;
	}

	if (data_id > 31) {
		pr_err("[SPI_DBG] Data ID is not correct.\n");
		return -EINVAL;
	}

	/* Disable interrupt of local processor */
	writel(0, gicc_ctlr);

	/* Busy waiting until FIFO is not full*/
	while (readl(get_spi_reg_addr(SPI_FIFO_LEVEL)) > (SPI_FIFO_SIZE - 1)) {
		writel(0xFF, get_spi_reg_addr(SPI_TRIGGER));
	}

	/**
	 * The bit-7 is 1 which represents data log.
	 * The first byte tells the information about data type and data length. 
	 * The data format is "0x1TTTTTKK."
	 * T=data_id, K=data length.
	 */
	writel(((1 << 7) | (data_id << 2) | (len - 1)), get_spi_reg_addr(SPI_LOG));
	writel(0xFF, get_spi_reg_addr(SPI_TRIGGER));

	/* Transmit the rest of data according to data length. */
	for (; count <= (len - 1); count++) {
		while (readl(get_spi_reg_addr(SPI_FIFO_LEVEL)) > (SPI_FIFO_SIZE - 1)) {
			writel(0xFF, get_spi_reg_addr(SPI_TRIGGER));
		}

		writel(data[count], get_spi_reg_addr(SPI_LOG));
		writel(0xFF, get_spi_reg_addr(SPI_TRIGGER));
	}

	/* Enable interrupt of local processor */
	writel(1, gicc_ctlr);

	return 0;
}
EXPORT_SYMBOL(spi_dbg_log_data);

static void set_spi_register(void)
{
	writel(0x0, get_spi_reg_addr(SPI_SSIENR)); // Disable SPI.
	writel(0x70000, get_spi_reg_addr(SPI_CTRLR0)); // Set control register.
	writel(0x0, get_spi_reg_addr(SPI_SER)); // Disable Slave register.
#if defined(CONFIG_SAPPORO)
	/* Set baud rate. 249 M / 20 is about 12M */
	writel(0x14, get_spi_reg_addr(SPI_BAUDR));
#else
	/* Set baud rate. 24M / 2 = 12M */
	writel(0x2, get_spi_reg_addr(SPI_BAUDR));
#endif
	writel(0x0, get_spi_reg_addr(SPI_TXFTLR)); // Set Transmit FIFO Threshold Level.
	writel(0x0, get_spi_reg_addr(SPI_IMR)); // Set Interrup Mask.
	writel(0x1, get_spi_reg_addr(SPI_SSIENR)); // Enable SPI.
}

#ifndef MODULE
static void get_spi_info_from_dt(struct device *dev)
{
	struct device_node *dev_node = dev->of_node;

	/* Get "spi-dev-num" property from device tree node*/
	of_property_read_u32(dev_node, "spi-dev-num", &spi_dev_num);

	/* Get "spi-port-num" property from device tree node*/
	of_property_read_u32(dev_node, "spi-port-num", &spi_port_num);
}
#endif // MODULE

static struct of_device_id spi_dbg_device_match[] = { {
	                                                      .compatible = "augentix,spi-debugger",
	                                              },
	                                              {} };

static int spi_dbg_probe(struct platform_device *pdev)
{
#ifndef MODULE
	struct device *dev = &pdev->dev;

	get_spi_info_from_dt(dev);

	if (spi_dev_num == 0) {
		if (spi_port_num != 0) {
			pr_err("[SPI_DBG] Wrong spi-port-num from device tree node\n");
			return -EINVAL;
		}

		spi_start_addr = SPI0_START_ADDR;
		spi_addr = ioremap(spi_start_addr, 128);

		spi_sdo = ioremap(SPI0_SDO_IOMUX, 4);
		spi_sck = ioremap(SPI0_SCK_IOMUX, 4);

		spi_sdo_old = readl(spi_sdo);
		spi_sck_old = readl(spi_sck);

		writel(SPI0_SDO_OFFSET, spi_sdo);
		writel(SPI0_SCK_OFFSET, spi_sck);

		pr_info("[SPI_DBG] Set SPI device to SPI0 by DTS\n");

	} else if (spi_dev_num == 1) {
		spi_start_addr = SPI1_START_ADDR;
		spi_addr = ioremap(spi_start_addr, 128);

		if (spi_port_num == 1) {
			spi_sdo = ioremap(SPI1_SDO_P1_IOMUX, 4);
			spi_sck = ioremap(SPI1_SCK_P1_IOMUX, 4);

			spi_sdo_old = readl(spi_sdo);
			spi_sck_old = readl(spi_sck);

			writel(SPI1_SDO_P1_OFFSET, spi_sdo);
			writel(SPI1_SCK_P1_OFFSET, spi_sck);

			pr_info("[SPI_DBG] Set SPI device to SPI1(Port1) by DTS\n");
		} else if (spi_port_num == 0) {
			spi_sdo = ioremap(SPI1_SDO_P0_IOMUX, 4);
			spi_sck = ioremap(SPI1_SCK_P0_IOMUX, 4);

			spi_sdo_old = readl(spi_sdo);
			spi_sck_old = readl(spi_sck);

			writel(SPI1_SDO_P0_OFFSET, spi_sdo);
			writel(SPI1_SCK_P0_OFFSET, spi_sck);

			pr_info("[SPI_DBG] Set SPI device to SPI1(Port0) by DTS\n");
		} else {
			pr_err("[SPI_DBG] Wrong spi-port-num from device tree node\n");
			return -EINVAL;
		}
	} else {
		pr_err("[SPI_DBG] Wrong spi-dev-num from device tree node\n");
		return -EINVAL;
	}

	set_spi_register();
#endif // MODULE

	return 0;
}

static int spi_dbg_remove(struct platform_device *pdev)
{
#ifndef MODULE
	writel(spi_sdo_old, spi_sdo);
	writel(spi_sck_old, spi_sck);

	iounmap(spi_sdo);
	iounmap(spi_sck);

	iounmap(spi_addr);

#endif // MODULE
	return 0;
}

struct platform_driver spi_dbg_platform_driver = {
	.probe = spi_dbg_probe,
	.remove = spi_dbg_remove,
	.driver = { 
		.name = "spi_debugger", 
		.of_match_table = of_match_ptr(spi_dbg_device_match), }

};

static int spi_dbg_open(struct inode *inode, struct file *filp)
{
	pr_info("[SPI_DBG] spi_dbg open was successful\n");
	return 0;
}

static int spi_dbg_release(struct inode *inode, struct file *flip)
{
	pr_info("[SPI_DBG] spi_dbg close was successful\n");
	return 0;
}

static int spi_dbg_mmap(struct file *filp, struct vm_area_struct *vma)
{
	int ret = 0;
	unsigned long vm_size = (unsigned long)(vma->vm_end - vma->vm_start);

	/* Set page non-cached*/
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	if (vma->vm_pgoff == 0) {
		/* Turn virtual address of kernel space into virtual address of user space*/
		ret = remap_pfn_range(vma, vma->vm_start, (spi_start_addr >> PAGE_SHIFT), vm_size, vma->vm_page_prot);
		if (ret < 0) {
			pr_err("[SPI_DBG] Remap page address fail\n");
			return -EAGAIN;
		}
	} else if (vma->vm_pgoff == 1) {
		/* Turn virtual address of kernel space into virtual address of user space*/
		ret = remap_pfn_range(vma, vma->vm_start, (GICC_CTRL >> PAGE_SHIFT), vm_size, vma->vm_page_prot);
		if (ret < 0) {
			pr_err("[SPI_DBG] Remap page address fail\n");
			return -EAGAIN;
		}
	} else {
		pr_err("[SPI_DBG] Wrong page\n");
		return -EAGAIN;
	}

	return ret;
}

struct file_operations spi_dbg_fops = { .open = spi_dbg_open,
	                                .release = spi_dbg_release,
	                                .mmap = spi_dbg_mmap,
	                                .owner = THIS_MODULE };

static int __init spi_dbg_init(void)
{
	int ret = -1;
#ifdef MODULE
	/* Set SPI device & pinmux*/
	if (spi_dev_num == 1) {
		spi_start_addr = SPI1_START_ADDR;
		spi_addr = ioremap(spi_start_addr, 128);

		if (spi_port_num == 1) {
			spi_sdo = ioremap(SPI1_SDO_P1_IOMUX, 4);
			spi_sck = ioremap(SPI1_SCK_P1_IOMUX, 4);

			spi_sdo_old = readl(spi_sdo);
			spi_sck_old = readl(spi_sck);

			writel(SPI1_SDO_P1_OFFSET, spi_sdo);
			writel(SPI1_SCK_P1_OFFSET, spi_sck);

			pr_info("[SPI_DBG] Set SPI device to SPI1(Port1)\n");
		} else if (spi_port_num == 0) {
			spi_sdo = ioremap(SPI1_SDO_P0_IOMUX, 4);
			spi_sck = ioremap(SPI1_SCK_P0_IOMUX, 4);

			spi_sdo_old = readl(spi_sdo);
			spi_sck_old = readl(spi_sck);

			writel(SPI1_SDO_P0_OFFSET, spi_sdo);
			writel(SPI1_SCK_P0_OFFSET, spi_sck);

			pr_info("[SPI_DBG] Set SPI device to SPI1(Port0)\n");
		} else {
			pr_err("[SPI_DBG] Wrong spi_port_num.\n");
			goto spi_addr_del;
		}

	} else if (spi_dev_num == 0) {
		spi_start_addr = SPI0_START_ADDR;
		spi_addr = ioremap(spi_start_addr, 128);

		if (spi_port_num == 0) {
			spi_sdo = ioremap(SPI0_SDO_IOMUX, 4);
			spi_sck = ioremap(SPI0_SCK_IOMUX, 4);

			spi_sdo_old = readl(spi_sdo);
			spi_sck_old = readl(spi_sck);

			writel(SPI0_SDO_OFFSET, spi_sdo);
			writel(SPI0_SCK_OFFSET, spi_sck);

			pr_info("[SPI_DBG] Set SPI device to SPI0\n");
		} else {
			pr_err("[SPI_DBG] Wrong spi_port_num.\n");
			goto spi_addr_del;
		}

	} else {
		pr_err("[SPI_DBG] Wrong spi_dev_num.\n");
		goto out;
	}

	set_spi_register();

#endif // MODULE

	/* Get GICC control register virtual address in kernel space */
	gicc_ctlr = ioremap(GICC_CTRL, 0x10);

	/* Dynamically allocate device numbers */
	ret = alloc_chrdev_region(&device_number, 0, 1, "spi_dbg_device_num");
	if (ret < 0) {
		pr_err("[SPI_DBG] Alloc chrdev failed\n");
		goto unmap_gicc;
	}

	/* Initialize the cdev structure with fops */
	cdev_init(&spi_dbg_cdev, &spi_dbg_fops);
	spi_dbg_cdev.owner = THIS_MODULE;

	/* Register a device (cdev structure) with VFS */
	ret = cdev_add(&spi_dbg_cdev, device_number, 1);
	if (ret < 0) {
		pr_err("[SPI_DBG] Cdev add failed\n");
		goto unreg_chrdev;
	}

	/* Create file under /sys/class/ */
	spi_dbg_class = class_create(THIS_MODULE, "SPI_debugger");
	if (IS_ERR(spi_dbg_class)) {
		pr_err("[SPI_DBG] Error in creating class \n");
		goto cdev_del;
	}

	/* populate the sysfs with device information */
	spi_dbg_device = device_create(spi_dbg_class, NULL, device_number, NULL, "spi_debugger");
	if (IS_ERR(spi_dbg_device)) {
		pr_err("[SPI_DBG] Device creation failed\n");
		ret = PTR_ERR(spi_dbg_device);
		goto class_del;
	}

	/* Driver registration*/
	platform_driver_register(&spi_dbg_platform_driver);

	pr_info("[SPI_DBG] Successfully initialize SPI debugger\n");

	return 0;

class_del:
	class_destroy(spi_dbg_class);
cdev_del:
	cdev_del(&spi_dbg_cdev);
unreg_chrdev:
	unregister_chrdev_region(device_number, 1);
unmap_gicc:
	iounmap(gicc_ctlr);

#ifdef MODULE
	writel(spi_sdo_old, spi_sdo);
	writel(spi_sck_old, spi_sck);

	iounmap(spi_sdo);
	iounmap(spi_sck);
spi_addr_del:
	iounmap(spi_addr);
out:
#endif // MODULE
	pr_err("[SPI_DBG] Module insertion failed\n");
	return ret;
}

static void __exit spi_dbg_exit(void)
{
	platform_driver_unregister(&spi_dbg_platform_driver);
	device_destroy(spi_dbg_class, device_number);
	class_destroy(spi_dbg_class);
	cdev_del(&spi_dbg_cdev);
	unregister_chrdev_region(device_number, 1);

	/* unmap */
	iounmap(gicc_ctlr);

#ifdef MODULE
	writel(spi_sdo_old, spi_sdo);
	writel(spi_sck_old, spi_sck);

	iounmap(spi_sdo);
	iounmap(spi_sck);

	iounmap(spi_addr);
#endif // MODULE

	pr_info("[SPI_DBG] Successfully remove SPI debugger\n");
}

module_init(spi_dbg_init);
module_exit(spi_dbg_exit);

MODULE_DESCRIPTION("SPI debugger driver");
MODULE_AUTHOR("Jay Tung <Jay.Tung@augentix.com>");
MODULE_LICENSE("GPL");
