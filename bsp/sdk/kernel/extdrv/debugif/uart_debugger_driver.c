#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/io.h>

#if defined(CONFIG_SAPPORO)
#define UART_REF_CLK 199200000
#define UART_BAUD 921600
#else
#define UART_REF_CLK 125000000
#define UART_BAUD 7875000
#endif // CONFIG_SAPPORO

#if defined(CONFIG_OSAKA)
#define UART0_BASE 0x81190000
#define UART1_BASE 0x811A0000
#define UART2_BASE 0x811B0000
#else
#define UART0_BASE 0x80820000
#define UART1_BASE 0x80830000
#define UART2_BASE 0x80840000
#endif // CONFIG_OSAKA

#if defined(CONFIG_SAPPORO)
#define UART0_TXD_IOMUX 0x8000117C
#define UART1_TXD_IOMUX 0x800010D4
/* Note that it only supports UART2 P0 */
#define UART2_TXD_IOMUX 0x80001174
#else
#define UART0_TXD_IOMUX 0x8000163C
#define UART1_TXD_IOMUX 0x80001554
#define UART2_TXD_IOMUX 0x8000155C
#endif // CONFIG_SAPPORO

#define UART_LCR_OFFSET 0x0C
#define UART_DLL_OFFSET 0x00
#define UART_DLH_OFFSET 0x04
#define UART_IER_OFFSET 0x04
#define UART_FCR_OFFSET 0x08
#define UART_MCR_OFFSET 0x10
#define UART_LSR_OFFSET 0x14
#define UART_THR_OFFSET 0x00
#define UART_DLF_OFFSET 0xC0

/*
 * This csr can be used to temporarily save 8 bits data for programmers,
 * use this to save wait_fifo or not for user space
 */
#define UART_SCR_OFFSET 0x1C

#define UART_LCR__DLAB__ENABLE 0x80
#define UART_LCR__DLAB__DISABLE 0x00
#define UART_LCR__DLS__8_BIT 0x03
#define UART_LCR__PEN__NONE 0x00
#define UART_LCR__STOP__1_BIT 0x00
#define UART_FCR__FIFOE__ENABLE 0x01
#define UART_LSR__THRE__UMASK (1 << 5)

#define UART_TX_FIFO_SIZE 32
#define GICC_CTRL 0x84002000

static struct cdev g_uart_dbg_cdev;
static struct class *g_uart_dbg_class;
static dev_t g_device_number;

static u32 volatile __iomem *g_uart_base_va;
static u32 volatile __iomem *g_txd_iomux_va;
static u32 volatile __iomem *g_gicc_ctrl;

static u32 g_uart_base_pa;
static u8 g_original_txd_iomux;

/* Set by user space or device tree, 0xFF means no setting */
static unsigned int uart_dev_num = 0xFF;
/* Set by user space or deivce tree, default value means waiting TX FIFO empty */
static unsigned int wait_fifo = 1;
#ifdef MODULE
module_param(uart_dev_num, uint, 0644); // 0644 : root-writable
MODULE_PARM_DESC(uart_dev_num, "UART device number");

module_param(wait_fifo, uint, 0644); // 0644 : root-writable
MODULE_PARM_DESC(wait_fifo, "Wait until TX FIFO empty");
#endif

static inline volatile u32 __iomem *get_uart_reg_addr(u32 offset)
{
	return (volatile u32 __iomem *)(g_uart_base_va + (offset / 4));
}

static void wait_uart_tx_fifo_empty(void)
{
	u32 csr;
	if (wait_fifo) {
		do {
			csr = readl(get_uart_reg_addr(UART_LSR_OFFSET));
		} while ((csr & UART_LSR__THRE__UMASK) == 0);
	}
}

/**
 * uart_dbg_log_event - write event log to uart debugger
 * @event_id: number of event type
 *
 * event_id ranges from 0 to 127.
 */
int uart_dbg_log_event(u8 event_id)
{
	if (event_id > 127) {
		pr_err("[UART_DBG] event_id is invalid\n");
		return -EINVAL;
	}
	/* Disable interrupt of local processor */
	writel(0, g_gicc_ctrl);

	wait_uart_tx_fifo_empty();
	writel(event_id, get_uart_reg_addr(UART_THR_OFFSET));

	/* Enable interrupt of local processor */
	writel(1, g_gicc_ctrl);

	return 0;
}
EXPORT_SYMBOL(uart_dbg_log_event);

/**
 * uart_dbg_log_data - write data log to uart debugger
 * @data_id: number of data type
 * @len: length of data
 * @data: data of log
 *
 * data_id ranges from 0 to 31.
 * len ranges from 1 to 4, which means data length.
 */
int uart_dbg_log_data(u8 data_id, u8 len, u8 *data)
{
	u8 i = 0;

	if (len == 0 || len > 4) {
		pr_err("[UART_DBG] Data length is invalid\n");
		return -EINVAL;
	}

	if (data_id > 31) {
		pr_err("[UART_DBG] Data ID is invalid\n");
		return -EINVAL;
	}

	/* Disable interrupt of local processor */
	writel(0, g_gicc_ctrl);

	wait_uart_tx_fifo_empty();

	/*
	* The first byte tells data type and data length.
	* The data format is "0x1TTTTTKK",T = data_id, K = data length.
	*/
	writel((1 << 7) | (data_id << 2) | (len - 1), get_uart_reg_addr(UART_THR_OFFSET));

	i = len;
	for (; i > 0; i--) {
		writel(*data, get_uart_reg_addr(UART_THR_OFFSET));
		data++;
	}

	/* Enable interrupt of local processor */
	writel(1, g_gicc_ctrl);

	return 0;
}
EXPORT_SYMBOL(uart_dbg_log_data);

static void uart_dbg_uart_init(void)
{
	uint32_t divisor;
	uint32_t csr;

#if defined(CONFIG_SAPPORO)
	u16 divisor_i;
	u16 divisor_f;
	u8 dlf_divided = 16;

	divisor = UART_REF_CLK / (UART_BAUD * 16) * dlf_divided;
	divisor_i = divisor / dlf_divided;
	divisor_f = divisor % dlf_divided;
#else
	divisor = (UART_REF_CLK + UART_BAUD * 8) / (UART_BAUD * 16);
#endif
	writel(UART_LCR__DLAB__ENABLE, get_uart_reg_addr(UART_LCR_OFFSET)); // Enable

#if defined(CONFIG_SAPPORO)
	writel((divisor_i & 0xFF), get_uart_reg_addr(UART_DLL_OFFSET)); // Low divisor
	writel(((divisor_i >> 8) & 0xFF), get_uart_reg_addr(UART_DLH_OFFSET)); // High divisor
	writel((divisor_f & 0xF), get_uart_reg_addr(UART_DLF_OFFSET)); // Float divisor
#else
	writel((divisor & 0xFF), get_uart_reg_addr(UART_DLL_OFFSET)); // Low divisor
	writel(((divisor >> 8) & 0xFF), get_uart_reg_addr(UART_DLH_OFFSET)); // High divisor
#endif
	writel(UART_LCR__DLAB__DISABLE, get_uart_reg_addr(UART_LCR_OFFSET)); // Disable

	/* Set line control to 8-N-1 */
#if defined(CONFIG_SAPPORO)
	writel(UART_LCR__DLS__8_BIT, get_uart_reg_addr(UART_LCR_OFFSET));
#else
	writel((UART_LCR__DLS__8_BIT | UART_LCR__PEN__NONE | UART_LCR__STOP__1_BIT),
	       get_uart_reg_addr(UART_LCR_OFFSET));
#endif
	/* Enable TX/RX FIFOs */
	writel(UART_FCR__FIFOE__ENABLE, get_uart_reg_addr(UART_FCR_OFFSET));
	/* Set interrupt mask */
	writel(0x0, get_uart_reg_addr(UART_IER_OFFSET));

#if !defined(CONFIG_SAPPORO)
	csr = readl(get_uart_reg_addr(UART_MCR_OFFSET));
	writel((csr | (1 << 5)), get_uart_reg_addr(UART_MCR_OFFSET));
#endif
}

static int uart_dbg_set_iomux(void)
{
	switch (uart_dev_num) {
	case 0:
		g_uart_base_pa = UART0_BASE;
		g_txd_iomux_va = ioremap(UART0_TXD_IOMUX, 4);
		break;
	case 1:
		g_uart_base_pa = UART1_BASE;
		g_txd_iomux_va = ioremap(UART1_TXD_IOMUX, 4);
		break;
	case 2:
		g_uart_base_pa = UART2_BASE;
		g_txd_iomux_va = ioremap(UART2_TXD_IOMUX, 4);
		break;
	// case 3:
	// 	g_uart_base_pa = UART3_BASE;
	// 	g_txd_iomux_va = ioremap(UART3_TXD_IOMUX, 4);
	// 	break;
	// case 4:
	// 	g_uart_base_pa = UART4_BASE;
	// 	g_txd_iomux_va = ioremap(UART4_TXD_IOMUX, 4);
	// 	break;
	// case 5:
	// 	g_uart_base_pa = UART5_BASE;
	// 	g_txd_iomux_va = ioremap(UART5_TXD_IOMUX, 4);
	// 	break;
	default:
		pr_err("[UART_DBG] Wrong uart_dev_num\n");
		return -EINVAL;
	}

	g_original_txd_iomux = readl(g_txd_iomux_va);

	if (uart_dev_num < 3) {
		writel(0x1, g_txd_iomux_va);
	} else {
		writel(0x4, g_txd_iomux_va);
	}

	pr_info("[UART_DBG] UART%u iomux has been set\n", uart_dev_num);
	return 0;
}

#ifndef MODULE
static void get_uart_info_from_dt(struct device *dev)
{
	struct device_node *dev_node = dev->of_node;

	/* Get "uart-dev-num" property from device tree node*/
	of_property_read_u32(dev_node, "uart-dev-num", &uart_dev_num);

	/* Get "wait-fifo" property from device tree node*/
	if (of_property_read_u32(dev_node, "wait-fifo", &wait_fifo)) {
		pr_notice("[UART_DBG] No wait-fifo property in dts, set as TRUE\n");
	} else {
		if (wait_fifo && wait_fifo != 1)
			wait_fifo = 1;
		pr_info("[UART_DBG] wait-fifo is set as %s\n", (wait_fifo) ? "TRUE" : "FALSE");
	}
}
#endif

static struct of_device_id uart_dbg_device_match[] = {
	{
	        .compatible = "augentix,uart-debugger",
	},
	{},
};

static int uart_dbg_probe(struct platform_device *pdev)
{
#ifndef MODULE
	struct device *dev = &pdev->dev;

	get_uart_info_from_dt(dev);
	if (uart_dev_num > 5) {
		pr_err("[UART_DBG] Wrong uart-dev-num setting in dts\n");
		return -EINVAL;
	}
	uart_dbg_set_iomux();
	g_uart_base_va = ioremap(g_uart_base_pa, 128);

	// Save wait_fifo in SCR to announce it for user space
	writel(wait_fifo, get_uart_reg_addr(UART_SCR_OFFSET));

	uart_dbg_uart_init();
#endif
	return 0;
}

static int uart_dbg_remove(struct platform_device *pdev)
{
#ifndef MODULE
	writel(g_original_txd_iomux, g_txd_iomux_va);

	/* unmap */
	iounmap(g_uart_base_va);
	iounmap(g_txd_iomux_va);
#endif
	return 0;
}

struct platform_driver uart_dbg_platform_driver = {
	.probe = uart_dbg_probe,
	.remove = uart_dbg_remove,
	.driver = {
		.name = "uart_debugger",
		.of_match_table = of_match_ptr(uart_dbg_device_match), }

};

static int uart_dbg_open(struct inode *inode, struct file *filp)
{
	return 0;
}

static int uart_dbg_release(struct inode *inode, struct file *flip)
{
	return 0;
}

static int uart_dbg_mmap(struct file *filp, struct vm_area_struct *vma)
{
	int ret = 0;
	unsigned long vm_size = (unsigned long)(vma->vm_end - vma->vm_start);

	/* Set page non-cached*/
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	if (vma->vm_pgoff == 0) {
		ret = remap_pfn_range(vma, vma->vm_start, (g_uart_base_pa >> PAGE_SHIFT), vm_size, vma->vm_page_prot);
		if (ret < 0) {
			pr_err("[UART_DBG] Remap uart address fail\n");
			return -EAGAIN;
		}
	} else if (vma->vm_pgoff == 1) {
		ret = remap_pfn_range(vma, vma->vm_start, (GICC_CTRL >> PAGE_SHIFT), vm_size, vma->vm_page_prot);
		if (ret < 0) {
			pr_err("[UART_DBG] Remap gicc address fail\n");
			return -EAGAIN;
		}
	} else {
		pr_err("[UART_DBG] Invalid page\n");
		return -EINVAL;
	}

	return ret;
}

struct file_operations uart_dbg_fops = { .open = uart_dbg_open,
	                                 .release = uart_dbg_release,
	                                 .mmap = uart_dbg_mmap,
	                                 .owner = THIS_MODULE };

static int __init uart_dbg_init(void)
{
	struct device *uart_dbg_device;
	int ret;
#ifdef MODULE
	/* Set UART device */
	ret = uart_dbg_set_iomux();
	if (ret < 0) {
		goto out;
	}
	g_uart_base_va = ioremap(g_uart_base_pa, 128);
	uart_dbg_uart_init();
	if (wait_fifo) {
		if (wait_fifo != 1)
			wait_fifo = 1;
		pr_info("[UART_DBG] Wait TX FIFO is enabled\n");
	} else {
		pr_info("[UART_DBG] Wait TX FIFO is disabled\n");
	}

	// Save wait_fifo in SCR to announce it for user space
	writel(wait_fifo, get_uart_reg_addr(UART_SCR_OFFSET));

#endif //MODULE

	g_gicc_ctrl = ioremap(GICC_CTRL, 0x10);

	ret = alloc_chrdev_region(&g_device_number, 0, 1, "uart_dbg_device");
	if (ret < 0) {
		pr_err("[UART_DBG] Allocating chrdev region failed\n");
		goto unmap_gicc;
	}

	/* Initialize the cdev structure with fops */
	cdev_init(&g_uart_dbg_cdev, &uart_dbg_fops);
	g_uart_dbg_cdev.owner = THIS_MODULE;

	/* Register a device (cdev structure) with VFS */
	ret = cdev_add(&g_uart_dbg_cdev, g_device_number, 1);
	if (ret < 0) {
		pr_err("[UART_DBG] Adding Cdev failed\n");
		goto unreg_chrdev;
	}

	/* Create file under /sys/class/ */
	g_uart_dbg_class = class_create(THIS_MODULE, "UART_debugger");
	if (IS_ERR(g_uart_dbg_class)) {
		pr_err("[UART_DBG] Error in creating class\n");
		goto cdev_del;
	}

	/* populate the sysfs with device information */
	uart_dbg_device = device_create(g_uart_dbg_class, NULL, g_device_number, NULL, "uart_debugger");
	if (IS_ERR(uart_dbg_device)) {
		pr_err("[UART_DBG] Creating device failed\n");
		ret = PTR_ERR(uart_dbg_device);
		goto class_del;
	}

	/* Driver registration*/
	platform_driver_register(&uart_dbg_platform_driver);

	pr_info("[UART_DBG] Initialize UART debugger successfully\n");

	return 0;

class_del:
	class_destroy(g_uart_dbg_class);
cdev_del:
	cdev_del(&g_uart_dbg_cdev);
unreg_chrdev:
	unregister_chrdev_region(g_device_number, 1);
unmap_gicc:
	iounmap(g_gicc_ctrl);

#ifdef MODULE
	writel(g_original_txd_iomux, g_txd_iomux_va);

	iounmap(g_uart_base_va);
	iounmap(g_txd_iomux_va);
out:
#endif // MODULE

	pr_err("Insmod UART debugger failed\n");
	return ret;
}

static void __exit uart_dbg_exit(void)
{
	platform_driver_unregister(&uart_dbg_platform_driver);
	device_destroy(g_uart_dbg_class, g_device_number);
	class_destroy(g_uart_dbg_class);
	cdev_del(&g_uart_dbg_cdev);
	unregister_chrdev_region(g_device_number, 1);

	iounmap(g_gicc_ctrl);

#ifdef MODULE
	writel(g_original_txd_iomux, g_txd_iomux_va);

	/* unmap */
	iounmap(g_uart_base_va);
	iounmap(g_txd_iomux_va);
#endif // MODULE

	pr_info("Remove UART debugger successfully\n");
}

module_init(uart_dbg_init);
module_exit(uart_dbg_exit);

MODULE_DESCRIPTION("UART debugger driver");
MODULE_AUTHOR("Eddie Lee <Eddie.Lee@augentix.com>");
MODULE_LICENSE("GPL");
