/*
 * dummy-codec.c  --  HC18XX ALSA SoC Dummy Codec Class driver
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/regmap.h>
#include <linux/regulator/consumer.h>
#include <linux/spi/spi.h>
#include <linux/of_device.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

/* codec private data */
struct hc18xx_codec_drvdata {
	struct regmap *regmap;
	u32 __iomem *adc_base;
//	const struct snd_pcm_hw_constraint_list *constraints;
//	unsigned int sysclk;
//	int sysclk_type;
//	int playback_fs;
};
/*
static int hc18xx_codec_read_reg(void *context, unsigned int reg,
				 unsigned int *value)
{
	int ret = 0;
	return ret;
}

static int hc18xx_codec_write_reg(void *context, unsigned int reg,
				 unsigned int value)
{
	int ret = 0;
	pr_info("hc18xx_codec_write_reg: reg = 0x%X, value = 0x%X", reg, value);
	return ret;
}*/
/*
static const struct regmap_config hc18xx_codec_regmap = {
	.reg_read = hc18xx_codec_read_reg,
	.reg_write = hc18xx_codec_write_reg,
};
static int hc18xx_codec_control_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol) {
	pr_info("fn: %s\n", __func__);
	return 0;
}

static int hc18xx_codec_control_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol) {
	pr_info("fn: %s\n", __func__);
	return 0;
}
*/

static const struct snd_kcontrol_new hc18xx_codec_snd_controls[] = {
};

static const struct snd_soc_dapm_widget hc18xx_codec_dapm_widgets[] = {
};

static const struct snd_soc_dapm_route hc18xx_codec_route[] = {
};

static int hc18xx_codec_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *dai)
{
	return 0;
}

static int hc18xx_codec_mute(struct snd_soc_dai *dai, int mute)
{
	return 0;
}

static int hc18xx_codec_set_dai_sysclk(struct snd_soc_dai *codec_dai,
		int clk_id, unsigned int freq, int dir)
{
	return 0;
}


static int hc18xx_codec_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	return 0;
}

static int hc18xx_codec_startup(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	return 0;
}

static const struct snd_soc_dai_ops hc18xx_codec_dai_ops = {
	.startup	= hc18xx_codec_startup,
	.hw_params	= hc18xx_codec_hw_params,
	.digital_mute	= hc18xx_codec_mute,
	.set_sysclk	= hc18xx_codec_set_dai_sysclk,
	.set_fmt	= hc18xx_codec_set_dai_fmt,
};

static struct snd_soc_dai_driver hc18xx_codec_dai = {
	.name = "dummy-codec-dai",
	.playback = {
		.stream_name = "Playback",
		.channels_min = 1,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_8000_96000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S16_BE,
	},
	.capture = {
		.stream_name = "Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_8000_96000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S16_BE,
	},
	.ops = &hc18xx_codec_dai_ops,
};

static int hc18xx_codec_probe(struct snd_soc_codec *codec)
{
	return 0;
}

/* power down chip */
static int hc18xx_codec_remove(struct snd_soc_codec *codec)
{
	return 0;
}

static struct snd_soc_codec_driver hc18xx_codec_driver = {
	.probe =    hc18xx_codec_probe,
	.remove =   hc18xx_codec_remove,
	.dapm_widgets = hc18xx_codec_dapm_widgets,
	.num_dapm_widgets = ARRAY_SIZE(hc18xx_codec_dapm_widgets),
	.dapm_routes = hc18xx_codec_route,
	.num_dapm_routes = ARRAY_SIZE(hc18xx_codec_route),
	.controls = hc18xx_codec_snd_controls,
	.num_controls = ARRAY_SIZE(hc18xx_codec_snd_controls),
};

static int hc18xx_codec_driver_probe(struct platform_device *pdev)
{
	int ret;

	pr_info("ASoC: dummy codec i/f is found. Probing...\n");
	pr_debug("fn: %s\n", __func__);

	ret = snd_soc_register_codec(&pdev->dev,
			&hc18xx_codec_driver, &hc18xx_codec_dai, 1);
	if (ret != 0) {
		pr_info("ASoC: dummy codec register failed.\n");
		return ret;
	}

	pr_info("ASoC: dummy codec i/f probed.\n");

	return 0;
}

static int hc18xx_codec_driver_remove(struct platform_device *pdev)
{
	pr_debug("fn: %s\n", __func__);
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

static const struct of_device_id hc18xx_codec_of_ids[] = {
	{ .compatible = "augentix,dummy-codec", },
	{ }
};

MODULE_DEVICE_TABLE(of, hc18xx_codec_of_ids);

static struct platform_driver hc18xx_codec_platform_driver = {
	.probe = hc18xx_codec_driver_probe,
	.remove = hc18xx_codec_driver_remove,
	.driver = {
		.name   = "dummy-codec",
		.owner  = THIS_MODULE,
		.of_match_table = hc18xx_codec_of_ids,
	},
};
module_platform_driver(hc18xx_codec_platform_driver);

MODULE_DESCRIPTION("ASoC dummy-codec driver");
MODULE_AUTHOR("Henry Liu, Augentix");
MODULE_LICENSE("GPL");
