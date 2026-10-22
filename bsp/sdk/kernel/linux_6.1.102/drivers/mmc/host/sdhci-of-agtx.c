#include <linux/acpi.h>
#include <linux/clk.h>
#include <linux/dma-mapping.h>
#include <linux/iopoll.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/reset.h>
#include <linux/sizes.h>
#include <linux/gpio/consumer.h>
#include <linux/delay.h>
#include "sdhci-pltfm.h"

#define SDHCI_AGTX_ARG2_STUFF GENMASK(31, 16)

/* AGTX specific Mode Select value */
#define AGTX_CTRL_HS400 0x7

/* DWC IP vendor area 1 pointer */
#define AGTX_P_VENDOR_AREA1 0xe8
#define AGTX_AREA1_MASK GENMASK(11, 0)
/* Offset inside the  vendor area 1 */
#define AGTX_HOST_CTRL3 0x8
#define AGTX_EMMC_CONTROL 0x2c
#define AGTX_CARD_IS_EMMC BIT(0)
#define AGTX_ENHANCED_STROBE BIT(8)
#define AGTX_EMMC_ATCTRL 0x40

#define AGT_GPIO_HIGH_AT_PROBE "highatprobe"
#define AGT_GPIO_SD_PWR_EN "sdpwren"

#define AGT_SDC_CFG_CORE_CKEN_OFFSET 0x0
#define AGT_SDC_CFG_PHASE_SHIFT_OFFSET 0x4

#define AGT_SDC_CLK_ENABLE 0x1
#define AGT_SDC_CLK_DISABLE 0x0
#define AGT_SDC_CLK_SHIFT_DEGREE_0 0
#define AGT_SDC_CLK_SHIFT_DEGREE_90 1
#define AGT_SDC_CLK_SHIFT_DEGREE_180 2
#define AGT_SDC_CLK_SHIFT_DEGREE_270 3

#define AGT_SDC_RX_CLK_SHIFT 0
#define AGT_SDC_TX_CLK_SHIFT 8

#define DLL_LOCK_WO_TMOUT(x) \
	((((x)&AGTX_EMMC_DLL_LOCKED) == AGTX_EMMC_DLL_LOCKED) && (((x)&AGTX_EMMC_DLL_TIMEOUT) == 0))

#define BOUNDARY_OK(addr, len) ((addr | (SZ_128M - 1)) == ((addr + len - 1) | (SZ_128M - 1)))

struct agtx_priv {
	struct clk *bus_clk;
	int vendor_specific_area1; /* P_VENDOR_SPECIFIC_AREA reg */
	void __iomem *agt_sdc_gpi_base;
	void __iomem *agt_sdc_cfg_base;
};

/* Initialize AGTX SDC config */
static int agtx_sdhci_init(struct sdhci_host *host, struct platform_device *pdev, struct agtx_priv *priv)
{
	struct gpio_desc *gpio_highatprobe;
	struct resource *regs;
	void __iomem *base;
	int sdc_cd, sdc_wp;
	int msec = 0;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	base = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(base))
		return PTR_ERR(base);

	priv->agt_sdc_cfg_base = base;

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	base = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(base))
		return PTR_ERR(base);

	priv->agt_sdc_gpi_base = base;

	/* #42309, #55901 */
	gpio_highatprobe = devm_gpiod_get(&pdev->dev, AGT_GPIO_HIGH_AT_PROBE, GPIOD_OUT_LOW);
	if (!IS_ERR(gpio_highatprobe)) {
		dev_err(&pdev->dev, "Import GPIO_HIGH_AT_PROBE solution\n");
		gpiod_set_value(gpio_highatprobe, 1);
		if (!of_property_read_u32(pdev->dev.of_node, "delay-after-gpioh", &msec)) {
			dev_err(&pdev->dev, "Request delay time for %d ms after gpio pull high\n", msec);
			mdelay(msec);
		}
	}

	if (of_property_read_u32(pdev->dev.of_node, "sdc-cd-gpio-num", &sdc_cd)) {
		dev_notice(&pdev->dev, "sdc-cd-gpio-num undefined, use default 63\n");
		sdc_cd = 63;
	}

	if (of_property_read_u32(pdev->dev.of_node, "sdc-wp-gpio-num", &sdc_wp)) {
		dev_notice(&pdev->dev, "sdc-wp-gpio-num undefined, use default 63\n");
		sdc_wp = 63;
	}

	writew_relaxed((sdc_cd << 8) | (sdc_wp), priv->agt_sdc_gpi_base);

	/* enable SDC Core clock */
	writel_relaxed(AGT_SDC_CLK_ENABLE, priv->agt_sdc_cfg_base + AGT_SDC_CFG_CORE_CKEN_OFFSET);

	/* set clock phase as 90 degree */
	writel_relaxed(AGT_SDC_CLK_SHIFT_DEGREE_90 << AGT_SDC_TX_CLK_SHIFT,
	               priv->agt_sdc_cfg_base + AGT_SDC_CFG_PHASE_SHIFT_OFFSET);

	return 0;
}

/*
 * If DMA addr spans 128MB boundary, we split the DMA transfer into two
 * so that each DMA transfer doesn't exceed the boundary.
 */
static void agtx_adma_write_desc(struct sdhci_host *host, void **desc, dma_addr_t addr, int len, unsigned int cmd)
{
	int tmplen, offset;

	if (likely(!len || BOUNDARY_OK(addr, len))) {
		sdhci_adma_write_desc(host, desc, addr, len, cmd);
		return;
	}

	offset = addr & (SZ_128M - 1);
	tmplen = SZ_128M - offset;
	sdhci_adma_write_desc(host, desc, addr, tmplen, cmd);

	addr += tmplen;
	len -= tmplen;
	sdhci_adma_write_desc(host, desc, addr, len, cmd);
}

static unsigned int agtx_get_max_clock(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);

	if (pltfm_host->clk)
		return sdhci_pltfm_clk_get_max_clock(host);
	else
		return pltfm_host->clock;
}

static void agtx_check_auto_cmd23(struct mmc_host *mmc, struct mmc_request *mrq)
{
	struct sdhci_host *host = mmc_priv(mmc);

	/*
	 * No matter V4 is enabled or not, ARGUMENT2 register is 32-bit
	 * block count register which doesn't support stuff bits of
	 * CMD23 argument on dwcmsch host controller.
	 */
	if (mrq->sbc && (mrq->sbc->arg & SDHCI_AGTX_ARG2_STUFF))
		host->flags &= ~SDHCI_AUTO_CMD23;
	else
		host->flags |= SDHCI_AUTO_CMD23;
}

static void agtx_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
	agtx_check_auto_cmd23(mmc, mrq);

	sdhci_request(mmc, mrq);
}

static void agtx_set_uhs_signaling(struct sdhci_host *host, unsigned int timing)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct agtx_priv *priv = sdhci_pltfm_priv(pltfm_host);
	u16 ctrl, ctrl_2;

	ctrl_2 = sdhci_readw(host, SDHCI_HOST_CONTROL2);
	/* Select Bus Speed Mode for host */
	ctrl_2 &= ~SDHCI_CTRL_UHS_MASK;
	if ((timing == MMC_TIMING_MMC_HS200) || (timing == MMC_TIMING_UHS_SDR104))
		ctrl_2 |= SDHCI_CTRL_UHS_SDR104;
	else if (timing == MMC_TIMING_UHS_SDR12)
		ctrl_2 |= SDHCI_CTRL_UHS_SDR12;
	else if ((timing == MMC_TIMING_UHS_SDR25) || (timing == MMC_TIMING_MMC_HS))
		ctrl_2 |= SDHCI_CTRL_UHS_SDR25;
	else if (timing == MMC_TIMING_UHS_SDR50)
		ctrl_2 |= SDHCI_CTRL_UHS_SDR50;
	else if ((timing == MMC_TIMING_UHS_DDR50) || (timing == MMC_TIMING_MMC_DDR52))
		ctrl_2 |= SDHCI_CTRL_UHS_DDR50;
	else if (timing == MMC_TIMING_MMC_HS400) {
		/* set CARD_IS_EMMC bit to enable Data Strobe for HS400 */
		ctrl = sdhci_readw(host, priv->vendor_specific_area1 + AGTX_EMMC_CONTROL);
		ctrl |= AGTX_CARD_IS_EMMC;
		sdhci_writew(host, ctrl, priv->vendor_specific_area1 + AGTX_EMMC_CONTROL);

		ctrl_2 |= AGTX_CTRL_HS400;
	}

	sdhci_writew(host, ctrl_2, SDHCI_HOST_CONTROL2);
}

static void agtx_hs400_enhanced_strobe(struct mmc_host *mmc, struct mmc_ios *ios)
{
	u32 vendor;
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct agtx_priv *priv = sdhci_pltfm_priv(pltfm_host);
	int reg = priv->vendor_specific_area1 + AGTX_EMMC_CONTROL;

	vendor = sdhci_readl(host, reg);
	if (ios->enhanced_strobe)
		vendor |= AGTX_ENHANCED_STROBE;
	else
		vendor &= ~AGTX_ENHANCED_STROBE;

	sdhci_writel(host, vendor, reg);
}

static const struct sdhci_ops sdhci_agtx_ops = {
	.set_clock = sdhci_set_clock,
	.set_bus_width = sdhci_set_bus_width,
	.set_uhs_signaling = agtx_set_uhs_signaling,
	.get_max_clock = agtx_get_max_clock,
	.reset = sdhci_reset,
	.adma_write_desc = agtx_adma_write_desc,
};

static const struct sdhci_pltfm_data sdhci_agtx_pdata = {
	.ops = &sdhci_agtx_ops,
	.quirks = SDHCI_QUIRK_CAP_CLOCK_BASE_BROKEN,
	.quirks2 = SDHCI_QUIRK2_PRESET_VALUE_BROKEN,
};

#ifdef CONFIG_ACPI
static const struct sdhci_pltfm_data sdhci_agtx_bf3_pdata = {
	.ops = &sdhci_agtx_ops,
	.quirks = SDHCI_QUIRK_CAP_CLOCK_BASE_BROKEN,
	.quirks2 = SDHCI_QUIRK2_PRESET_VALUE_BROKEN | SDHCI_QUIRK2_ACMD23_BROKEN,
};
#endif

static const struct of_device_id sdhci_agtx_dt_ids[] = {
	{
	        .compatible = "augentix,sdc-sdhci",
	        .data = &sdhci_agtx_pdata,
	},
	{},
};
MODULE_DEVICE_TABLE(of, sdhci_agtx_dt_ids);

#ifdef CONFIG_ACPI
static const struct acpi_device_id sdhci_agtx_acpi_ids[] = { {
	                                                             .id = "SDCBF30",
	                                                             .driver_data =
	                                                                     (kernel_ulong_t)&sdhci_agtx_bf3_pdata,
	                                                     },
	                                                     {} };
#endif

static int agtx_sdc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_host *host;
	struct agtx_priv *priv;
	const struct sdhci_pltfm_data *pltfm_data;
	int err;
	u32 extra;

	pltfm_data = device_get_match_data(&pdev->dev);
	if (!pltfm_data) {
		dev_err(&pdev->dev, "Error: No device match data found\n");
		return -ENODEV;
	}

	host = sdhci_pltfm_init(pdev, pltfm_data, sizeof(struct agtx_priv));
	if (IS_ERR(host))
		return PTR_ERR(host);

	/*
	 * extra adma table cnt for cross 128M boundary handling.
	 */
	extra = DIV_ROUND_UP_ULL(dma_get_required_mask(dev), SZ_128M);
	if (extra > SDHCI_MAX_SEGS)
		extra = SDHCI_MAX_SEGS;
	host->adma_table_cnt += extra;

	pltfm_host = sdhci_priv(host);
	priv = sdhci_pltfm_priv(pltfm_host);

	if (dev->of_node) {
		pltfm_host->clk = devm_clk_get(dev, "core");
		if (IS_ERR(pltfm_host->clk)) {
			err = PTR_ERR(pltfm_host->clk);
			dev_err(dev, "failed to get core clk: %d\n", err);
			goto free_pltfm;
		}
		err = clk_prepare_enable(pltfm_host->clk);
		if (err)
			goto free_pltfm;

		priv->bus_clk = devm_clk_get(dev, "bus");
		if (!IS_ERR(priv->bus_clk))
			clk_prepare_enable(priv->bus_clk);
	}

	err = mmc_of_parse(host->mmc);
	if (err)
		goto err_clk;

	sdhci_get_of_property(pdev);

	priv->vendor_specific_area1 = sdhci_readl(host, AGTX_P_VENDOR_AREA1) & AGTX_AREA1_MASK;

	host->mmc_host_ops.request = agtx_request;
	host->mmc_host_ops.hs400_enhanced_strobe = agtx_hs400_enhanced_strobe;

	err = agtx_sdhci_init(host, pdev, priv);
	if (err) {
		dev_err(dev, "failed to initialize agtx sdhci: %d\n", err);
		goto err_clk;
	}

	host->mmc->caps |= MMC_CAP_WAIT_WHILE_BUSY;

	err = sdhci_setup_host(host);
	if (err)
		goto err_clk;

	err = __sdhci_add_host(host);
	if (err)
		goto err_setup_host;

	return 0;

err_setup_host:
	sdhci_cleanup_host(host);
err_clk:
	clk_disable_unprepare(pltfm_host->clk);
	clk_disable_unprepare(priv->bus_clk);
free_pltfm:
	sdhci_pltfm_free(pdev);
	return err;
}

static int agtx_sdc_remove(struct platform_device *pdev)
{
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct agtx_priv *priv = sdhci_pltfm_priv(pltfm_host);

	sdhci_remove_host(host, 0);

	clk_disable_unprepare(pltfm_host->clk);
	clk_disable_unprepare(priv->bus_clk);
	sdhci_pltfm_free(pdev);

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int agtx_sdc_suspend(struct device *dev)
{
	struct sdhci_host *host = dev_get_drvdata(dev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct agtx_priv *priv = sdhci_pltfm_priv(pltfm_host);
	int ret;

	ret = sdhci_suspend_host(host);
	if (ret)
		return ret;

	clk_disable_unprepare(pltfm_host->clk);
	if (!IS_ERR(priv->bus_clk))
		clk_disable_unprepare(priv->bus_clk);

	return ret;
}

static int agtx_sdc_resume(struct device *dev)
{
	struct sdhci_host *host = dev_get_drvdata(dev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct agtx_priv *priv = sdhci_pltfm_priv(pltfm_host);
	int ret;

	ret = clk_prepare_enable(pltfm_host->clk);
	if (ret)
		return ret;

	if (!IS_ERR(priv->bus_clk)) {
		ret = clk_prepare_enable(priv->bus_clk);
		if (ret)
			return ret;
	}

	return sdhci_resume_host(host);
}
#endif

static SIMPLE_DEV_PM_OPS(agtx_sdc_pmops, agtx_sdc_suspend, agtx_sdc_resume);

static struct platform_driver sdhci_agtx_driver = {
	.driver	= {
		.name	= "sdhci-agtx",
		.probe_type = PROBE_PREFER_ASYNCHRONOUS,
		.of_match_table = sdhci_agtx_dt_ids,
		.acpi_match_table = ACPI_PTR(sdhci_agtx_acpi_ids),
		.pm = &agtx_sdc_pmops,
	},
	.probe	= agtx_sdc_probe,
	.remove	= agtx_sdc_remove,
};
module_platform_driver(sdhci_agtx_driver);

MODULE_DESCRIPTION("SDHCI platform driver for Augentix SDC");
