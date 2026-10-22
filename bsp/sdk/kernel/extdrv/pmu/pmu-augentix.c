#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <asm/io.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/delay.h>

#define DRV_NAME "pmu_button"

#define IRQ_CLEAR_OFFSET	0x08
#define IRQ_MASK_OFFSET		0x0C
#define IRQ_STATUS_OFFSET	0x10

//#define PMU_BTN_DEBUG (1)

#ifdef PMU_BTN_DEBUG
#define DBG(fmt, args...) \
do { \
	printk("[PMU] (%d, %s) " fmt, __LINE__, __func__, ##args); \
} while (0)
#else
#define DBG(fmt, args...) \
do { \
} while (0)
#endif

struct agtx_pmu_data {
	struct device *dev;
	int pmu_irq_num;
	void __iomem *pmu_reg_base;
	void __iomem *pc_ck_def_apb;
	void __iomem *pc_syscfg_pmu_en;
	struct work_struct pd_off_work;
};

extern void augentix_amc_pd_off(void);

static void pd_off_command(void)
{
	char cmdPath[] = "/sbin/poweroff";
	char *cmdArgv[] = { cmdPath, NULL };
	char *cmdEnvp[] = { "HOME=/", NULL };

	call_usermodehelper(cmdPath, cmdArgv, cmdEnvp, UMH_WAIT_PROC);
}

static void agtx_pmu_poweroff_work_func(struct work_struct *work)
{
	// struct agtx_pmu_data *pmu = container_of(work, struct agtx_pmu_data, poweroff_work);

	printk(KERN_NOTICE "PMU sleep triggered\n");
	pm_power_off = augentix_amc_pd_off;
	pd_off_command();
}

static irqreturn_t agtx_pmu_button_irq_handler(int irq, void *data)
{
	struct agtx_pmu_data *pmu = (struct agtx_pmu_data *)data;
	u32 reg;
	void __iomem *pmu_reg_base = pmu->pmu_reg_base;

	DBG("PMU Button IRQ triggered!\n");
	reg = readl_relaxed(pmu_reg_base + IRQ_STATUS_OFFSET);

	if (reg & 0x1) {
		DBG("Click event!\n");
		writel_relaxed(0x1, pmu_reg_base + IRQ_CLEAR_OFFSET);
	} else if ((reg >> 8) & 0x1) {
		DBG("Press event!\n");
		writel_relaxed(0x1 << 8, pmu_reg_base + IRQ_CLEAR_OFFSET);
		schedule_work(&pmu->pd_off_work);
	} else {
		DBG("Not equal Click & Press!\n");
		return IRQ_NONE;
	}

	return IRQ_HANDLED;
}

void agtx_pmu_prepare(struct agtx_pmu_data *pmu)
{
	void __iomem *pmu_reg_base = pmu->pmu_reg_base;
	void __iomem *pc_ck_def_apb = pmu->pc_ck_def_apb;
	void __iomem *pc_syscfg_pmu_en = pmu->pc_syscfg_pmu_en;
	u32 reg_pmu, reg_ck, reg_syscfg;

	reg_ck = readl_relaxed(pc_ck_def_apb);
	DBG("DEF_APB_0: 0x%08x\n", reg_ck);
	reg_ck |= 0x1;
	writel_relaxed(reg_ck, pc_ck_def_apb);

	reg_syscfg = readl_relaxed(pc_syscfg_pmu_en);
	DBG("PMU_EN: 0x%08x\n", reg_syscfg);
	writel_relaxed(0x1010101, pc_syscfg_pmu_en);

	reg_pmu = readl_relaxed(pmu_reg_base + IRQ_MASK_OFFSET);
	DBG("IRQ_MASK: 0x%08x\n", reg_pmu);
	writel_relaxed(0x0, pmu_reg_base + IRQ_MASK_OFFSET);
}

void agtx_pmu_done(struct agtx_pmu_data *pmu)
{
	void __iomem *pc_ck_def_apb = pmu->pc_ck_def_apb;
	void __iomem *pc_syscfg_pmu_en = pmu->pc_syscfg_pmu_en;
	u32 reg_ck, reg_syscfg;

	reg_ck = readl_relaxed(pc_ck_def_apb);
	DBG("DEF_APB_0: 0x%08x\n", reg_ck);
	reg_ck &= ~0x1;
	writel_relaxed(reg_ck, pc_ck_def_apb);

	reg_syscfg = readl_relaxed(pc_syscfg_pmu_en);
	DBG("PMU_EN: 0x%08x\n", reg_syscfg);
	writel_relaxed(0x0, pc_syscfg_pmu_en);
}

static int agtx_pmu_probe(struct platform_device *pdev)
{
	struct agtx_pmu_data *pmu;
	struct resource *res;
	int ret;

	printk("Probing for %s\n", DRV_NAME);

	pmu = devm_kzalloc(&pdev->dev, sizeof(*pmu), GFP_KERNEL);
	if (!pmu) {
		dev_err(&pdev->dev, "Failed to allocate private data\n");
		return -ENOMEM;
	}
	pmu->dev = &pdev->dev;

	pmu->pmu_irq_num = platform_get_irq(pdev, 0);
	if (pmu->pmu_irq_num < 0) {
		dev_err(pmu->dev, "Failed to get PMU IRQ number: %d\n", pmu->pmu_irq_num);
		return pmu->pmu_irq_num;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(pmu->dev, "Failed to get PMU MEM resource\n");
		return -ENODEV;
	}

	pmu->pmu_reg_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(pmu->pmu_reg_base)) {
		ret = PTR_ERR(pmu->pmu_reg_base);
		dev_err(pmu->dev, "Failed to ioremap PMU registers: %d\n", ret);
		return ret;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	if (!res) {
		dev_err(pmu->dev, "Failed to get CK MEM resource\n");
		return -ENODEV;
	}

	pmu->pc_ck_def_apb = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(pmu->pc_ck_def_apb)) {
		ret = PTR_ERR(pmu->pc_ck_def_apb);
		dev_err(pmu->dev, "Failed to ioremap DEF_APB_0 registers: %d\n", ret);
		return ret;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	if (!res) {
		dev_err(pmu->dev, "Failed to get SYSCFG MEM resource\n");
		return -ENODEV;
	}

	pmu->pc_syscfg_pmu_en = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(pmu->pc_syscfg_pmu_en)) {
		ret = PTR_ERR(pmu->pc_syscfg_pmu_en);
		dev_err(pmu->dev, "Failed to ioremap PMU_EN registers: %d\n", ret);
		return ret;
	}

	ret = devm_request_irq(pmu->dev, pmu->pmu_irq_num, agtx_pmu_button_irq_handler, IRQF_SHARED, DRV_NAME, pmu);
	if (ret) {
		dev_err(pmu->dev, "Failed to request PMU IRQ %d: %d\n", pmu->pmu_irq_num, ret);
		return ret;
	}
	DBG("Successfully registered PMU IRQ\n");

	INIT_WORK(&pmu->pd_off_work, agtx_pmu_poweroff_work_func);
	platform_set_drvdata(pdev, pmu);
	agtx_pmu_prepare(pmu);

	return 0;
}

static int agtx_pmu_remove(struct platform_device *pdev)
{
	struct agtx_pmu_data *pmu = platform_get_drvdata(pdev);

	printk("Removing %s, PMU IRQ %d freed.\n", DRV_NAME, pmu->pmu_irq_num);
	cancel_work_sync(&pmu->pd_off_work);
	agtx_pmu_done(pmu);
	platform_set_drvdata(pdev, NULL);

	return 0;
}

static const struct of_device_id agtx_pmu_dt_ids[] = {
	{ .compatible = "augentix,pmu-button" },
	{}
};
MODULE_DEVICE_TABLE(of, agtx_pmu_dt_ids);

static struct platform_driver pmu_button_driver = {
	.probe = agtx_pmu_probe,
	.remove = agtx_pmu_remove,
	.driver = {
		.name = DRV_NAME,
		.owner = THIS_MODULE,
		.of_match_table = agtx_pmu_dt_ids,
	},
};

module_platform_driver(pmu_button_driver);

MODULE_AUTHOR("Gavin Cheng, Augentix <gavin.cheng@augentix.com>");
MODULE_DESCRIPTION("PMU Button driver");
MODULE_LICENSE("GPL");