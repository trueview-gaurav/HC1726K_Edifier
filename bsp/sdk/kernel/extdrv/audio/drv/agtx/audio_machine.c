#include <linux/gpio.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/version.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>

#include "wm8731.h"

#define DRIVER_NAME "agtx-audio"

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define PLATFORM_NAME "80120000.audio_pcm"
#elif defined(CONFIG_OSAKA)
#define PLATFORM_NAME "81070000.audio_pcm"
#else
#define PLATFORM_NAME "80100000.audio_pcm"
#endif

#define _custom_widget(x) agtx_##x##_dapm_widgets
#define custom_widget(x) _custom_widget(x)
#define _custom_dai(x) agtx_##x##_dais
#define custom_dai(x) _custom_dai(x)
#define _custom_map(x) agtx_##x##_map
#define custom_map(x) _custom_map(x)

/* clang-format off */
/* ak4637 custom settings start */
static const struct snd_soc_dapm_widget agtx_ak4637_dapm_widgets[] = {
	SND_SOC_DAPM_MIC("AMic", NULL),
	SND_SOC_DAPM_MIC("DMic", NULL),
	SND_SOC_DAPM_SPK("Speaker", NULL),
};

static const struct snd_soc_dapm_route agtx_ak4637_map[] = {
	{"Speaker", NULL, "SPKLO"},
	{"DMICIN", NULL, "DMic"},
	{"AIN", NULL, "AMic"},
};

static int agtx_ak4637_init(struct snd_soc_pcm_runtime *rtd)
{
	int ret = 0;
	struct snd_soc_dapm_context *dapm = &rtd->card->dapm;

	snd_soc_dapm_enable_pin(dapm, "AMic");
	snd_soc_dapm_enable_pin(dapm, "DMic");
	snd_soc_dapm_enable_pin(dapm, "Speaker");
	snd_soc_dapm_sync(dapm);
	
	return ret;
}

static int agtx_ak4637_hw_params(struct snd_pcm_substream *substream,
				  struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 7, 0)
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
#else
	struct snd_soc_dai *codec_dai = asoc_rtd_to_codec(rtd, 0);
#endif
	unsigned int freq;

	freq = params_rate(params);
	snd_soc_dai_set_sysclk(codec_dai, 0, freq, SND_SOC_CLOCK_IN);

	return 0;
}

static struct snd_soc_ops agtx_ak4637_ops = {
	.hw_params = agtx_ak4637_hw_params,
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 3, 0)
SND_SOC_DAILINK_DEFS(ak4637,
		DAILINK_COMP_ARRAY(COMP_CPU("agtx-dai")),
		DAILINK_COMP_ARRAY(COMP_CODEC(NULL, "ak4637-aif")),
		DAILINK_COMP_ARRAY(COMP_PLATFORM(PLATFORM_NAME)));
#endif
static struct snd_soc_dai_link agtx_ak4637_dais[] = {
	{
		.name = DRIVER_NAME,
		.stream_name = DRIVER_NAME,
		.init = agtx_ak4637_init,
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		.codec_dai_name = "ak4637-aif",
		.cpu_dai_name = PLATFORM_NAME,
		.platform_name = PLATFORM_NAME,
#else
		SND_SOC_DAILINK_REG(ak4637),
#endif
		.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM,
		.ops = &agtx_ak4637_ops,
	},
};
/* ak4637 custom settings end */

/* cjc8990 custom settings start */
static const struct snd_soc_dapm_widget agtx_cjc8990_dapm_widgets[] = {
	SND_SOC_DAPM_SPK("SPK", NULL),
	SND_SOC_DAPM_MIC("MIC", NULL),
};

static const struct snd_soc_dapm_route agtx_cjc8990_map[] = {
	{ "SPK", NULL, "OUT" },
	{ "MICIN", NULL, "MIC" },
};

static int agtx_cjc8990_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_dapm_context *dapm = &rtd->card->dapm;

	snd_soc_dapm_enable_pin(dapm, "SPK");
	snd_soc_dapm_sync(dapm);

	return 0;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 3, 0)
SND_SOC_DAILINK_DEFS(cjc8990,
		DAILINK_COMP_ARRAY(COMP_CPU("agtx-dai")),
		DAILINK_COMP_ARRAY(COMP_CODEC(NULL, "cjc8990-dai")),
		DAILINK_COMP_ARRAY(COMP_PLATFORM(PLATFORM_NAME)));
#endif
static struct snd_soc_dai_link agtx_cjc8990_dais[] = {
	{
		.name = DRIVER_NAME,
		.stream_name = DRIVER_NAME,
		.init = agtx_cjc8990_init,
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		.codec_dai_name = "cjc8990-dai",
		.cpu_dai_name = PLATFORM_NAME,
		.platform_name = PLATFORM_NAME,
#else
		SND_SOC_DAILINK_REG(cjc8990),
#endif
		.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM,
	},
};
/* cjc8990 custom settings end */

/* rt5660 custom settings start */
#define RT5660_SYSCLK_RATE 24576000
#define RT5660_MCLK_RATE 12000000

static const struct snd_soc_dapm_widget agtx_rt5660_dapm_widgets[] = {
	SND_SOC_DAPM_MIC("AMIC1", NULL),
	SND_SOC_DAPM_MIC("AMIC2", NULL),
	SND_SOC_DAPM_MIC("AMIC3", NULL),
	SND_SOC_DAPM_SPK("SPK", NULL),
	SND_SOC_DAPM_HP("HPOL", NULL),
	SND_SOC_DAPM_HP("HPOR", NULL),
};

static const struct snd_soc_dapm_route agtx_rt5660_map[] = {
	{ "SPK", NULL, "SPO" },
	{ "HPOL", NULL, "LOUTL" },
	{ "HPOR", NULL, "LOUTL" },
	{ "AMIC1", NULL, "MICBIAS1" },
	{ "IN1P", NULL, "AMIC1" },
	{ "IN1N", NULL, "AMIC1" },
	{ "AMIC2", NULL, "MICBIAS2" },
	{ "IN2P", NULL, "AMIC2" },
	{ "AMIC3", NULL, "MICBIAS2" },
	{ "IN3P", NULL, "AMIC3" },
	{ "IN3N", NULL, "AMIC3" },
};

static int agtx_rt5660_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_dapm_context *dapm = &rtd->card->dapm;

	snd_soc_dapm_enable_pin(dapm, "AMIC1");
	snd_soc_dapm_enable_pin(dapm, "AMIC2");
	snd_soc_dapm_enable_pin(dapm, "SPK");
	snd_soc_dapm_enable_pin(dapm, "HPOL");
	snd_soc_dapm_enable_pin(dapm, "HPOR");
	snd_soc_dapm_sync(dapm);

	return 0;
}

static int agtx_rt5660_hw_params(struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 7, 0)
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
#else
	struct snd_soc_dai *codec_dai = asoc_rtd_to_codec(rtd, 0);
#endif
	int ret;

	ret = snd_soc_dai_set_sysclk(codec_dai, 1, RT5660_SYSCLK_RATE, SND_SOC_CLOCK_IN); // 1: RT5660_SCLK_S_PLL1
	if (ret < 0) {
		pr_info("[%s] set sysclk failed\n", DRIVER_NAME);
		return ret;
	}
	ret = snd_soc_dai_set_pll(codec_dai, 0, 0, RT5660_MCLK_RATE,
	                          RT5660_SYSCLK_RATE); // source 0: RT5660_PLL1_S_MCLK
	if (ret < 0) {
		pr_info("[%s] set pll failed\n", DRIVER_NAME);
		return ret;
	}

	return ret;
}

static struct snd_soc_ops agtx_rt5660_ops = {
	.hw_params = agtx_rt5660_hw_params,
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 3, 0)
SND_SOC_DAILINK_DEFS(rt5660,
		DAILINK_COMP_ARRAY(COMP_CPU("agtx-dai")),
		DAILINK_COMP_ARRAY(COMP_CODEC(NULL, "rt5660-aif1")),
		DAILINK_COMP_ARRAY(COMP_PLATFORM(PLATFORM_NAME)));
#endif
static struct snd_soc_dai_link agtx_rt5660_dais[] = {
	{
		.name = DRIVER_NAME,
		.stream_name = DRIVER_NAME,
		.init = agtx_rt5660_init,
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		.codec_dai_name = "rt5660-aif1",
		.cpu_dai_name = PLATFORM_NAME,
		.platform_name = PLATFORM_NAME,
#else
		SND_SOC_DAILINK_REG(rt5660),
#endif
		.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM,
		.ops = &agtx_rt5660_ops,
	},
};
/* rt5660 custom settings end */

/* rt5677 custom settings start */
#define RT5677_SYSCLK_RATE 12288000
#define RT5677_MCLK_RATE 12000000

static const struct snd_soc_dapm_widget agtx_rt5677_dapm_widgets[] = {
	SND_SOC_DAPM_MIC("AMIC1", NULL),
	SND_SOC_DAPM_MIC("AMIC2", NULL),
	SND_SOC_DAPM_MIC("AMIC3", NULL),
	//SND_SOC_DAPM_MIC("DMIC1_L", NULL),
	//SND_SOC_DAPM_MIC("DMIC1_R", NULL),
	//SND_SOC_DAPM_MIC("DMIC2_L", NULL),
	//SND_SOC_DAPM_MIC("DMIC2_R", NULL),
	SND_SOC_DAPM_HP("HPO1", NULL),
	SND_SOC_DAPM_HP("HPO2", NULL),
	SND_SOC_DAPM_HP("HPO3", NULL),
	// SND_SOC_DAPM_SPK("SPK", NULL),
};

static const struct snd_soc_dapm_route agtx_rt5677_map[] = {
	{ "IN1P", NULL, "AMIC1" },
	{ "IN1N", NULL, "AMIC1" },
	{ "IN2P", NULL, "AMIC2" },
	{ "IN1P", NULL, "AMIC3" },
	{ "IN2P", NULL, "AMIC3" },

	{ "AMIC1", NULL, "MICBIAS1" },
	{ "AMIC2", NULL, "MICBIAS1" },
	{ "HPO1", NULL, "LOUT1" },
	{ "HPO2", NULL, "LOUT2" },
	{ "HPO3", NULL, "LOUT1" },
	{ "HPO3", NULL, "LOUT2" },
	// { "SPK", NULL, "SPO" },
};

static int agtx_rt5677_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_dapm_context *dapm = &rtd->card->dapm;

	snd_soc_dapm_enable_pin(dapm, "AMIC1");
	snd_soc_dapm_enable_pin(dapm, "AMIC2");
	snd_soc_dapm_enable_pin(dapm, "AMIC3");
	snd_soc_dapm_enable_pin(dapm, "HPO1");
	snd_soc_dapm_enable_pin(dapm, "HPO2");
	snd_soc_dapm_enable_pin(dapm, "HPO3");
	//snd_soc_dapm_enable_pin(dapm, "SPK");
	snd_soc_dapm_sync(dapm);

	return 0;
}

static int agtx_rt5677_hw_params(struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 7, 0)
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
#else
	struct snd_soc_dai *codec_dai = asoc_rtd_to_codec(rtd, 0);
#endif
	int ret;
#if 1
	/* Patch for PLL source BCLK 16KHz ,MCLK 12.288MHz, RT5677 Slave mode*/
	ret = snd_soc_dai_set_pll(codec_dai, 0, 0, 12288000,
	                          params_rate(params)*512); // source 0: RT5660_PLL1_S_MCLK
	if (ret < 0) {
		pr_info("[%s] set pll failed\n", DRIVER_NAME);
		return ret;
	}
	/* Patch for PLL source MCLK */
	ret = snd_soc_dai_set_sysclk(codec_dai, 1, params_rate(params)*512, SND_SOC_CLOCK_IN); // 1: RT5677_SCLK_S_PLL1
	if (ret < 0) {
		pr_info("[%s] set sysclk failed\n", DRIVER_NAME);
		return ret;
	}
#endif
#if 0
	/* Patch for PLL source BCLK 16KHz ,MCLK 12.288MHz, RT5677 Slave mode*/
	ret = snd_soc_dai_set_pll(codec_dai, 0, 1, params_rate(params)*64,
	                          params_rate(params)*512); // source 0: RT5660_PLL1_S_MCLK
	if (ret < 0) {
		pr_info("[%s] set pll failed\n", DRIVER_NAME);
		return ret;
	}
	/* Patch for PLL source BCLK */
	ret = snd_soc_dai_set_sysclk(codec_dai, 1, params_rate(params)*512, SND_SOC_CLOCK_IN); // 1: RT5677_SCLK_S_PLL1
	if (ret < 0) {
		pr_info("[%s] set sysclk failed\n", DRIVER_NAME);
		return ret;
	}
#endif
	return ret;
}

static struct snd_soc_ops agtx_rt5677_ops = {
	.hw_params = agtx_rt5677_hw_params,
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 3, 0)
SND_SOC_DAILINK_DEFS(rt5677,
		DAILINK_COMP_ARRAY(COMP_CPU("agtx-dai")),
		DAILINK_COMP_ARRAY(COMP_CODEC(NULL, "rt5677-aif1")),
		DAILINK_COMP_ARRAY(COMP_PLATFORM(PLATFORM_NAME)));
#endif
static struct snd_soc_dai_link agtx_rt5677_dais[] = {
	{
		.name = DRIVER_NAME,
		.stream_name = DRIVER_NAME,
		.init = agtx_rt5677_init,
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		.codec_dai_name = "rt5677-aif1",
		.cpu_dai_name = PLATFORM_NAME,
		.platform_name = PLATFORM_NAME,
#else
		SND_SOC_DAILINK_REG(rt5677),
#endif
		.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM,
		.ops = &agtx_rt5677_ops,
	},
};
/* rt5677 custom settings end */

/* wm8731 custom settings start */
#define WM8731_SYSCLK_RATE 12288000

static const struct snd_soc_dapm_widget agtx_wm8731_dapm_widgets[] = {
	SND_SOC_DAPM_AIF_IN("AIFRX", "AIF Playback", 0, SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_MIC("Int Mic", NULL),
	SND_SOC_DAPM_SPK("Ext Spk", NULL),
	SND_SOC_DAPM_HP("Headphone Jack", NULL),
};

static const struct snd_soc_dapm_route agtx_wm8731_map[] = {
	{ "Ext Spk", NULL, "AIFRX" },

	/* headphone connected to LHPOUT, RHPOUT */
	{ "Headphone Jack", NULL, "LHPOUT" },
	{ "Headphone Jack", NULL, "RHPOUT" },

	/* speaker connected to LOUT, ROUT */
	{ "Ext Spk", NULL, "LOUT" },
	{ "Ext Spk", NULL, "ROUT" },

	/* mic is connected to Mic Jack, with WM8731 Mic Bias */
	{ "MICIN", NULL, "Int Mic" },
};

static int agtx_wm8731_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_dapm_context *dapm = &rtd->card->dapm;

	snd_soc_dapm_nc_pin(dapm, "LLINEIN");
	snd_soc_dapm_nc_pin(dapm, "RLINEIN");

	return 0;
}

static int agtx_wm8731_hw_params(struct snd_pcm_substream *substream, struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 7, 0)
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
#else
	struct snd_soc_dai *codec_dai = asoc_rtd_to_codec(rtd, 0);
#endif
	int ret;

	/* wm8731 codec proto uses 12M external crystal */
	ret = snd_soc_dai_set_sysclk(codec_dai, WM8731_SYSCLK_XTAL, WM8731_SYSCLK_RATE, SND_SOC_CLOCK_IN);
	if (ret) {
		dev_err(codec_dai->dev, "Failed to set sysclk to %u.%03uMHz\n", (WM8731_SYSCLK_RATE / 1000000),
		        ((WM8731_SYSCLK_RATE / 1000) % 1000));
		return ret;
	}

	return ret;
}

static int agtx_wm8731_startup(struct snd_pcm_substream *substream)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dapm_context *dapm = &rtd->card->dapm;

	snd_soc_dapm_enable_pin(dapm, "Ext Spk");
	snd_soc_dapm_enable_pin(dapm, "Int Mic");
	snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
	snd_soc_dapm_sync(dapm);

	return 0;
}

static struct snd_soc_ops agtx_wm8731_ops = {
	.startup = agtx_wm8731_startup,
	.hw_params = agtx_wm8731_hw_params,
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 3, 0)
SND_SOC_DAILINK_DEFS(wm8731,
		DAILINK_COMP_ARRAY(COMP_CPU("agtx-dai")),
		DAILINK_COMP_ARRAY(COMP_CODEC(NULL, "wm8731-hifi")),
		DAILINK_COMP_ARRAY(COMP_PLATFORM(PLATFORM_NAME)));
#endif
static struct snd_soc_dai_link agtx_wm8731_dais[] = {
	{
		.name = DRIVER_NAME,
		.stream_name = DRIVER_NAME,
		.init = agtx_wm8731_init,
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		.codec_dai_name = "wm8731-hifi",
		.cpu_dai_name = PLATFORM_NAME,
		.platform_name = PLATFORM_NAME,
#else
		SND_SOC_DAILINK_REG(wm8731),
#endif
		.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM,
		.ops = &agtx_wm8731_ops,
	},
};
/* wm8731 custom settings end */

/* agtx in-house adc/dac settings start */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
static const struct snd_soc_dapm_widget agtx_adc_dapm_widgets[] = {
	/* AMIC */
	SND_SOC_DAPM_MIC("MIC BIAS", NULL),
	SND_SOC_DAPM_INPUT("AMIC L"),
	SND_SOC_DAPM_INPUT("AMIC R"),
	SND_SOC_DAPM_ADC("ADC L", "Capture", SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_ADC("ADC R", "Capture", SND_SOC_NOPM, 0, 0),

	/* DMIC */
	SND_SOC_DAPM_INPUT("DMIC L"),
	SND_SOC_DAPM_INPUT("DMIC R"),
	SND_SOC_DAPM_PGA("DMIC", SND_SOC_NOPM, 0, 0, NULL, 0),

	/* DAC */
	SND_SOC_DAPM_DAC("DAC", "Playback", SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_OUTPUT("LINE2"),
	SND_SOC_DAPM_SPK("SPK", NULL),
};

static const struct snd_soc_dapm_route agtx_adc_map[] = {
	/* AMIC */
	{ "AMIC L", NULL, "MIC BIAS" },
	{ "AMIC R", NULL, "MIC BIAS" },
	{ "ADC L", NULL, "AMIC L" },
	{ "ADC R", NULL, "AMIC R" },
	/* DMIC */
	{ "DMIC", NULL, "DMIC L" },
	{ "DMIC", NULL, "DMIC R" },
	/* DAC */
	{ "DAC", NULL, "LINE2" },
	{ "LINE2", NULL, "SPK" }
};
#else
static const struct snd_soc_dapm_widget agtx_adc_dapm_widgets[] = {
	SND_SOC_DAPM_MIC("AMIC", NULL),
	SND_SOC_DAPM_INPUT("LINE1"),
	SND_SOC_DAPM_ADC("ADC", "Capture", SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_DAC("DAC", "Playback", SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_OUTPUT("LINE2"),
	SND_SOC_DAPM_SPK("SPK", NULL),
};

static const struct snd_soc_dapm_route agtx_adc_map[] = {
	{ "LINE1", NULL, "AMIC" },
	{ "ADC", NULL, "LINE1" },
	{ "DAC", NULL, "LINE2" },
	{ "LINE2", NULL, "SPK" }
};
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 3, 0)
SND_SOC_DAILINK_DEFS(agtx,
		DAILINK_COMP_ARRAY(COMP_CPU("agtx-dai")),
		DAILINK_COMP_ARRAY(COMP_DUMMY()),
		DAILINK_COMP_ARRAY(COMP_PLATFORM(PLATFORM_NAME)));
#endif
static struct snd_soc_dai_link agtx_adc_dais[] = {
	{
		.name = DRIVER_NAME,
		.stream_name = "Capture",
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		.codec_name = "snd-soc-dummy",
		.codec_dai_name = "snd-soc-dummy-dai",
		.cpu_dai_name = PLATFORM_NAME,
		.platform_name = PLATFORM_NAME,
#else
		SND_SOC_DAILINK_REG(agtx),
#endif
		.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS,
	},
};
/* agtx in-house adc/dac custom settings end */
/* clang-format on */

static struct snd_soc_card agtx_card = {
	.name = DRIVER_NAME,
	.owner = THIS_MODULE,
};

#define agtx_card_fill_up(x)                                           \
	{                                                              \
		card->dai_link = custom_dai(x);                        \
		card->num_links = ARRAY_SIZE(custom_dai(x));           \
		card->dapm_widgets = custom_widget(x);                 \
		card->num_dapm_widgets = ARRAY_SIZE(custom_widget(x)); \
		card->dapm_routes = custom_map(x);                     \
		card->num_dapm_routes = ARRAY_SIZE(custom_map(x));     \
	}

static int audio_machine_probe(struct platform_device *pdev)
{
	int ret;
	struct device_node *np;
	struct device_node *codec_np;
	struct snd_soc_card *card = &agtx_card;

	np = pdev->dev.of_node;
	card->dev = &pdev->dev;

	/* request device node of codec device */
	codec_np = of_parse_phandle(np, "audio-codec", 0);
	if (!codec_np) {
		/* ADC */
		agtx_card_fill_up(adc);
	} else {
		/* I2S */
		if (strcmp(codec_np->name, "ak4637") == 0) {
			agtx_card_fill_up(ak4637);
		} else if (strcmp(codec_np->name, "cjc8990") == 0) {
			agtx_card_fill_up(cjc8990);
		} else if (strcmp(codec_np->name, "rt5660") == 0) {
			agtx_card_fill_up(rt5660);
		} else if (strcmp(codec_np->name, "rt5677") == 0) {
			agtx_card_fill_up(rt5677);
		} else if (strcmp(codec_np->name, "wm8731") == 0) {
			agtx_card_fill_up(wm8731);
		} else {
			of_node_put(codec_np);
			dev_err(&pdev->dev, "Codec %s not support.", codec_np->name);
			return -EINVAL;
		}
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 3, 0)
		card->dai_link[0].codec_of_node = codec_np;
#else
		card->dai_link[0].codecs->of_node = codec_np;
#endif
		of_node_put(codec_np);
	}

	ret = devm_snd_soc_register_card(&pdev->dev, card);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (error: %d)\n", ret);
		return -EINVAL;
	}

	pr_info("ASoC: %s audio probed.\n", DRIVER_NAME);

	return 0;
}

static int audio_machine_remove(struct platform_device *pdev)
{
	/* */

	return 0;
}

static const struct of_device_id audio_machine_of_ids[] = {
	{ .compatible = "augentix,audio_machine" },
	{},
};
MODULE_DEVICE_TABLE(of, audio_machine_of_ids);

static struct platform_driver audio_machine_driver = {
	.probe = audio_machine_probe,
	.remove = audio_machine_remove,
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = audio_machine_of_ids,
		.pm = &snd_soc_pm_ops,
	},
};
module_platform_driver(audio_machine_driver);

MODULE_DESCRIPTION("Augentix Audio Machine");
MODULE_AUTHOR("Henry Liu <henry.liu@augentix.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:agtx-audio");
