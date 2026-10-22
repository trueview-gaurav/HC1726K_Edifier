#include <linux/errno.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/completion.h>
#include <linux/spinlock.h>
#include <linux/version.h>
#include <linux/iio/iio.h>
#include <asm/delay.h>

#include "csr_bank_saadcctr.h"

#define CALI_SAMPLE_TIMES 63 // 64 times
#define EXP_0_3V 68 // #95854
#define EXP_0_9V 206 // #95854
#define MAX_RETRY_TIMES 3

#define NORAML_SAMPLE_TIMES 1023 // 1024 times

#define DEBUG(...) //pr_err(__VA_ARGS__)

struct adc_driver_data {
	struct device *dev;
	struct clk *clk;
	bool clk_enabled;
	/* adc runtime */
	struct iio_dev *iio_dev;
	spinlock_t lock;
	struct completion comp;
	void __iomem *ldo_base;
	volatile CsrBankSaadcctr *saadc;
};

static irqreturn_t agtx_adc_irq_handler(int irq_id, void *dev_id)
{
	struct adc_driver_data *drvdata = (struct adc_driver_data *)dev_id;
	volatile CsrBankSaadcctr *saadc = drvdata->saadc;

	DEBUG("%s: interrupts occur\n", __func__);
	saadc->irq_clear0 = 0x11111111;
	complete(&drvdata->comp);

	return IRQ_HANDLED;
}

static uint32_t agtx_adc_read_raw(struct iio_dev *indio_dev, struct iio_chan_spec const *chan)
{
	struct adc_driver_data *adc_drv_data = iio_priv(indio_dev);
	int channel = chan->channel;
	volatile CsrBankSaadcctr *saadc = adc_drv_data->saadc;
	unsigned long flags;
	uint32_t ret = 0;

	spin_lock_irqsave(&adc_drv_data->lock, flags);
	reinit_completion(&adc_drv_data->comp);

	if (adc_drv_data->clk_enabled == false) {
		clk_prepare_enable(adc_drv_data->clk);
		adc_drv_data->clk_enabled = true;
	}

	saadc->start = 1;
	saadc->calibration_swset = 1;

	wait_for_completion_interruptible(&adc_drv_data->comp);

	switch (channel) {
	case 0:
		ret = saadc->avg_ch0;
		break;
	case 1:
		ret = saadc->avg_ch1;
		break;
	case 2:
		ret = saadc->avg_ch2;
		break;
	case 3:
		ret = saadc->avg_ch3;
		break;
	default:
		ret = -EINVAL;
		dev_err(adc_drv_data->dev, "Invalid channel %u\n", channel);
		break;
	}
	spin_unlock_irqrestore(&adc_drv_data->lock, flags);
	return ret;
}

/**
 * iio_adc_read_raw() - data read function.
 * @indio_dev:	the struct iio_dev associated with this device instance
 * @chan:	the channel whose data is to be read
 * @val:	first element of returned value (typically INT)
 * @mask:	what we actually want to read as per the info_mask_*
 *		in iio_chan_spec.
 */
static int adc_read_raw(struct iio_dev *indio_dev, struct iio_chan_spec const *chan, int *val, int *val2, long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		/* Read channel value */
		*val = agtx_adc_read_raw(indio_dev, chan);
		break;
	}
	return IIO_VAL_INT;
}

#define ADC_CHANNEL(_index, _id)																														 \
	{																																										\
		.indexed = 1, .channel = _index, .datasheet_name = _id, .type = IIO_VOLTAGE, \
		.info_mask_separate = BIT(IIO_CHAN_INFO_RAW),																\
	}
static const struct iio_chan_spec agtx_saradc_iio_channels[] = {
	ADC_CHANNEL(0, "adc0"),
	ADC_CHANNEL(1, "adc1"),
	ADC_CHANNEL(2, "adc2"),
};

static void agtx_adc_hw_init(struct adc_driver_data *drvdata)
{
	void __iomem *ldo_base = drvdata->ldo_base;
	volatile CsrBankSaadcctr *saadc = drvdata->saadc;

	saadc->reserved = 0x628;
	saadc->sample_cycle = 130;
	saadc->sample_pre_cycle = 45;
	saadc->saadccs_ck_half_cycle = 5;

	saadc->rg_saadccs_enext = 1;
	saadc->rg_saadccs_engpi = 0;

	saadc->calibration_on = 0;
	saadc->ch_en = 0xF;
	saadc->tsensor_enable = 1;

	saadc->sample_mode_ch0 = 1;
	saadc->sample_mode_ch1 = 1;
	saadc->sample_mode_ch2 = 1;
	saadc->sample_mode_ch3 = 1;

	saadc->sample_data_num_ch0 = CALI_SAMPLE_TIMES;
	saadc->sample_data_num_ch1 = CALI_SAMPLE_TIMES;
	saadc->sample_data_num_ch2 = CALI_SAMPLE_TIMES;
	saadc->sample_data_num_ch3 = CALI_SAMPLE_TIMES;

	// enable ldo (important)
	writel(0x1010101, ldo_base);
	udelay(30);
	saadc->irq_clear0 = 0x11111111;
	saadc->irq_mask_saadc_real_stop = 0;
}

#if 0 // no need to use currently
static void agtx_adc_reset(struct adc_driver_data *drvdata)
{
	volatile CsrBankAdoin_syscfg *adoin_sys = drvdata->adoin_sys;

	//ADOIN.ADOIN_SYSCFG.lv_rst_saadc_k
	adoin_sys->lv_rst_saadc_k = 1;
	adoin_sys->lv_rst_saadc_p = 1;
	adoin_sys->lv_rst_saadc_k = 0;
	adoin_sys->lv_rst_saadc_p = 0;
	agtx_adc_hw_init(drvdata);
}
#endif

static void agtx_adc_sample_start(volatile CsrBankSaadcctr *saadc)
{
	saadc->start = 1;
	saadc->calibration_swset = 1;
	while (!(saadc->saadc_kernel_idle)) {
	}
}

static int agtx_adc_calibration(struct adc_driver_data *drvdata)
{
	volatile CsrBankSaadcctr *saadc = drvdata->saadc;
	struct device *dev = drvdata->dev;
	int calp = 0;
	int caln = 0;
	int vref = 0;
	int diff_0_9V = 0;
	int diff_0_3V = 0;
	int diff_tol = 1;
	int standard = 0;
	int gain_error;
	int candidate = 0;
	int calp_cand = 0;
	int caln_cand = 0;
	int retry_times = 0;

	saadc->calp_wr = 0;
	saadc->caln_wr = 0;
vref_retry:
	for (vref = 0x0; vref <= 0xA; vref++) {
		saadc->vrefpsel = vref;

		standard = EXP_0_9V;
		saadc->rg_saadccs_engpi = 1;
		agtx_adc_sample_start(saadc);
		diff_0_9V = saadc->avg_ch2 - standard;

		standard = EXP_0_3V;
		saadc->rg_saadccs_engpi = 5;
		agtx_adc_sample_start(saadc);
		diff_0_3V = saadc->avg_ch2 - standard;

		gain_error = abs(diff_0_9V - diff_0_3V);
		if (gain_error <= diff_tol) {
			retry_times = 0;
			goto tune_calp_caln;
		}
	}

	dev_info(dev, "can't find calibration setting on vref section, retry\n");
	retry_times++;
	if (retry_times <= MAX_RETRY_TIMES) {
		goto vref_retry;
	} else {
		goto calibration_failed;
	}

tune_calp_caln:
	for (calp = 0, caln = 0; calp < 8 && caln < 8;) {
		saadc->calp_wr = calp;
		saadc->caln_wr = caln;

		standard = EXP_0_9V;
		saadc->rg_saadccs_engpi = 1;
		agtx_adc_sample_start(saadc);
		diff_0_9V = saadc->avg_ch2 - standard;

		if (abs(diff_0_9V) == 0){
			goto calibration_done;
		} else if (abs(diff_0_9V) == 1 && !candidate) {
			calp_cand = calp;
			caln_cand = caln;
			candidate = 1;
		} else if (diff_0_9V > 0) {
			calp++;
		} else { //diff < 0
			caln++;
		}
	}

	if (candidate){
		dev_info(dev, "Only find candidate\n");
		saadc->calp_wr = calp_cand;
		saadc->caln_wr = caln_cand;
		goto calibration_done;
	}

	dev_info(dev, "can't find calibration setting on calp, caln section, retry\n");
	retry_times++;
	if (retry_times <= MAX_RETRY_TIMES) {
		goto tune_calp_caln;
	}

calibration_failed:
	return -EIO;

calibration_done:
	dev_info(dev, "final set calp = %u, caln = %u, vref = %u\n", saadc->calp_wr, saadc->caln_wr, saadc->vrefpsel);

	// set for normal sampling
	saadc->rg_saadccs_engpi = 0;
	return 0;
}
static const struct iio_info adc_env_iio_info = {
	.read_raw = &adc_read_raw,
};

static int agtx_adc_platform_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct iio_dev *indio_dev;
	struct device *dev = &pdev->dev;
	void __iomem *temp_base;
	int ret;
	int irq;
	struct adc_driver_data *adc_drv_data;

	indio_dev = devm_iio_device_alloc(dev, sizeof(struct adc_driver_data));

	if (!indio_dev)
		return -ENOMEM;

	adc_drv_data = iio_priv(indio_dev);
	adc_drv_data->iio_dev = indio_dev;
	adc_drv_data->dev = dev;
	init_completion(&adc_drv_data->comp);
	spin_lock_init(&adc_drv_data->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	temp_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(temp_base)) {
		dev_err(dev, "Failed to map saradc address!\n");
		return -EINVAL;
	}
	adc_drv_data->saadc = ((volatile CsrBankSaadcctr *)temp_base);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	adc_drv_data->ldo_base = devm_ioremap(dev, res->start, resource_size(res));
	if (IS_ERR(adc_drv_data->ldo_base)) {
		dev_err(dev, "Failed to map ldo address!\n");
		return -EINVAL;
	}

	adc_drv_data->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(adc_drv_data->clk)) {
		dev_err(dev, "Failed to get saadc clock!\n");
		return -EINVAL;
	}
	adc_drv_data->clk_enabled = false;

	if (adc_drv_data->saadc->none_overlap_cycle != 1) {
		dev_info(dev, "First time to use saradc\n");
		/* initialize hardware */
		agtx_adc_hw_init(adc_drv_data);
		ret = agtx_adc_calibration(adc_drv_data);
		if (ret == 0) {
			adc_drv_data->saadc->none_overlap_cycle = 1;
		} else {
			dev_err(dev, "Calibration failed\n");
		}
	} else {
		dev_info(dev, "Not first time to use saradc, skip calibration\n");
	}

	indio_dev->dev.parent = dev;
	indio_dev->dev.of_node = pdev->dev.of_node;
	indio_dev->name = dev_name(dev);
	indio_dev->info = &adc_env_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = agtx_saradc_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(agtx_saradc_iio_channels);

	irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
	ret = devm_request_irq(dev, irq, agtx_adc_irq_handler, IRQF_SHARED, pdev->name, adc_drv_data);
	if (ret != 0) {
		dev_err(dev, "failed to install irq(%d)", ret);
		return -EINVAL;
	}

	ret = devm_iio_device_register(dev, indio_dev);
	if (ret)
		goto exit_iio;

	platform_set_drvdata(pdev, adc_drv_data);

	dev_info(dev, "Init augentix adc dirver done\n");

exit_iio:

	return ret;
}

static const struct of_device_id agtx_adc_of_ids[] = {
	{
		.compatible = "augentix,agtx-adc",
	},
	{},
};
MODULE_DEVICE_TABLE(of, agtx_adc_of_ids);

static struct platform_driver agtx_adc_driver = {
		.probe = agtx_adc_platform_probe,
		.driver = {
			.name = "adc-driver",
			.owner = THIS_MODULE,
			.of_match_table = of_match_ptr(agtx_adc_of_ids),
		},
};

module_platform_driver(agtx_adc_driver);

MODULE_AUTHOR("Eddie Lee<eddie.lee@augentix.com>");
MODULE_DESCRIPTION("Augentix ADC Driver V2");
MODULE_LICENSE("GPL");
