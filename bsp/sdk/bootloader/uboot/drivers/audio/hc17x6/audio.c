#include <common.h>

#include "agtx_cpu_time.h"
#include "csr_bank_audio_ldo.h"
#include "csr_bank_aadc.h"
#ifdef CONFIG_EARLYAUDIO
#include "csr_bank_adoin.h"
#include "csr_bank_adoin_syscfg.h"
#include "csr_bank_amic.h"
#include "csr_bank_ccqw.h"
#include "csr_bank_dmic.h"
#include "csr_bank_i2s.h"
#include "hw_dram.h" /* drivers/agtx_video/include */

/* Copy from da_define.h */
#define BITWIDTH_BANK (BANK_ADDR_TYPE + 2)
#define BITWIDTH_COL (COL_ADDR_TYPE + 9)
#define WORD_ADDR_BW (3) /* (DA_FIFO_WORD / 8) byte -> need 3 bit */

DECLARE_GLOBAL_DATA_PTR;

struct earlyaudio_info {
	unsigned long data_addr;
	uint32_t rate;
	uint16_t channels;
	uint16_t format; // 0: s16le, 1: s32le
	uint16_t interface; // 0: adc, 1: pdm, 2: i2s
	uint16_t analog_gain;
};
#endif

#define AUDIO_CLK (225792000)

struct audio_csr {
	volatile struct csr_bank_audio_ldo *audio_ldo;
	volatile struct csr_bank_aadc *aadc_l;
	volatile struct csr_bank_aadc *aadc_r;
#ifdef CONFIG_EARLYAUDIO
	volatile struct csr_bank_adoin *adoin;
	volatile struct csr_bank_adoin_syscfg *adoin_syscfg;
	volatile struct csr_bank_ccqw *audiow;
	volatile struct csr_bank_i2s *i2s_rx;
	volatile struct csr_bank_amic *amic_l;
	volatile struct csr_bank_amic *amic_r;
	volatile struct csr_bank_dmic *dmic_l;
	volatile struct csr_bank_dmic *dmic_r;
#endif
};

struct audio_drvdata {
	struct audio_csr csr;
#ifdef CONFIG_EARLYAUDIO
	struct earlyaudio_info early;
#endif
};

static struct audio_drvdata g_drvdata;

static void audio_csr_init(struct audio_drvdata *drvdata)
{
	struct audio_csr *csr = &drvdata->csr;

	csr->audio_ldo = (void *)0x80250000;
	csr->aadc_l = (void *)0x80180000;
	csr->aadc_r = (void *)0x80190000;
}

static void audio_adc_init(struct audio_drvdata *drvdata)
{
	struct audio_csr *csr = &drvdata->csr;
	volatile struct csr_bank_audio_ldo *audio_ldo = csr->audio_ldo;
	volatile struct csr_bank_aadc *aadc_l = csr->aadc_l;
	volatile struct csr_bank_aadc *aadc_r = csr->aadc_r;

	/* Base on #98644 Solution 3 - Lower settling time */
	aadc_l->preamp_reg0 = 0x00003001;
	aadc_l->preamp_reg1 = 0x00000100;
	aadc_r->preamp_reg0 = 0x00003001;
	aadc_r->preamp_reg1 = 0x00000100;
	audio_ldo->audio_ldo_reg00 = 0x01010101;

	aadc_l->aadc_ctrl_enable = 0x01010101;
#ifdef CONFIG_FPGA
	aadc_l->aadc_ctrl_cycle = 0x60600102; // For 112.896MHz
#else
#if AUDIO_CLK == 225792000
	aadc_l->aadc_ctrl_cycle = 0xC0C00106;
#else /* AUDIO_CLK == 282240000 */
	aadc_l->aadc_ctrl_cycle = 0xF0F00108; // #87321
#endif

#endif /* CONFIG_FPGA */
#if defined(CONFIG_SAPPORO)
	aadc_r->aadc_ctrl_enable = 0x01010101;
#ifdef CONFIG_FPGA
	aadc_r->aadc_ctrl_cycle = 0x60600102; // For 112.896MHz
#else
#if AUDIO_CLK == 225792000
	aadc_r->aadc_ctrl_cycle = 0xC0C00106;
#else /* AUDIO_CLK == 282240000 */
	aadc_r->aadc_ctrl_cycle = 0xF0F00108; // #87321
#endif
#endif /* CONFIG_FPGA */
#endif /* CONFIG_SAPPORO */

#ifndef CONFIG_EARLYAUDIO
	aadc_l->aadc_ctrl_power_on_off = 1;
#if defined(CONFIG_SAPPORO)
	aadc_r->aadc_ctrl_power_on_off = 1;
#endif
#endif
}

int audio_init(void)
{
	struct audio_drvdata *drvdata = &g_drvdata;

	audio_csr_init(drvdata);

	/* FIXME: Only set when ADC */
	audio_adc_init(drvdata);

	return 0;
}

#ifdef CONFIG_EARLYAUDIO
static void earlyaudio_csr_init(struct audio_drvdata *drvdata)
{
	struct audio_csr *csr = &drvdata->csr;

	csr->adoin = (void *)0x80120000;
	csr->adoin_syscfg = (void *)0x80120400;
	csr->audiow = (void *)0x80150000;
	csr->i2s_rx = (void *)0x80170000;
	csr->amic_l = (void *)0x80200000;
	csr->amic_r = (void *)0x80210000;
	csr->dmic_l = (void *)0x80220000;
	csr->dmic_r = (void *)0x80230000;
}

void earlyaudio_set_env(void)
{
	char value_buf[32];

	sprintf(value_buf, "0x%08lx", gd->audio_base);
	setenv("early_audio_buf_addr", value_buf);
	sprintf(value_buf, "%d", EARLY_AUDIO_BUF_KB);
	setenv("early_audio_buf_kb", value_buf);
}

static void earlyaudio_params_init(struct earlyaudio_info *ea)
{
	if (gd->audio_base) {
		ea->data_addr = gd->audio_base;
		memset((void *)ea->data_addr, 0, EARLY_AUDIO_BUF_KB << 10);
	}

#if LOCK_PARAM_TO_SPEED_UP
	ea->channels = EARLY_AUDIO_CHANNELS;
	ea->rate = EARLY_AUDIO_RATE;
	ea->format = EARLY_AUDIO_FORMAT;
	ea->interface = EARLY_AUDIO_INTERFACE;
	ea->analog_gain = EARLY_AUDIO_ANALOG_GAIN;
#else
	ea->channels = (uint32_t)simple_strtoul(getenv("early_audio_channels"), NULL, 10);
	ea->rate = (uint32_t)simple_strtoul(getenv("early_audio_rate"), NULL, 10);
	ea->format = (uint32_t)simple_strtoul(getenv("early_audio_format"), NULL, 10);
	ea->interface = (uint32_t)simple_strtoul(getenv("early_audio_interface"), NULL, 10);
	ea->analog_gain = (uint32_t)simple_strtoul(getenv("early_audio_analog_gain"), NULL, 10);
#endif

	/* Check parameters */
	if (ea->channels < 1) {
		ea->channels = 1;
	} else if (ea->channels > 2) {
		ea->channels = 2;
	}

	switch (ea->rate) {
	case 8000:
	case 16000:
	case 32000:
	case 48000:
	case 96000:
	case 11025:
	case 22050:
	case 44100:
	case 88200:
		break;
	default:
		ea->rate = 96000;
		break;
	}

	switch (ea->format) {
	case 0: /* s16le */
		break;
	case 1: /* s32le Not Ready */
	default:
		ea->format = 0;
		break;
	}

	switch (ea->interface) {
	case 0: /* adc */
		break;
	case 1: /* pdm Not Ready */
	case 2: /* i2s Not Ready */
	default:
		ea->interface = 0;
		break;
	}

	/* Workaround #103217 */
	if (ea->analog_gain > 2) {
		ea->analog_gain = 2;
	}
}

static void earlyaudio_start(struct audio_drvdata *drvdata)
{
	struct earlyaudio_info *ea = &drvdata->early;
	struct audio_csr *csr = &drvdata->csr;
	volatile struct csr_bank_aadc *aadc_l = csr->aadc_l;
	volatile struct csr_bank_aadc *aadc_r = csr->aadc_r;
	volatile struct csr_bank_amic *amic_l = csr->amic_l;
	volatile struct csr_bank_amic *amic_r = csr->amic_r;
	volatile struct csr_bank_ccqw *audiow = csr->audiow;
	volatile struct csr_bank_adoin *adoin = csr->adoin;
	volatile struct csr_bank_adoin_syscfg *adoin_syscfg = csr->adoin_syscfg;
	uint32_t osr = 0;
	/* DA access violation formual in #70725-23 */
	uint8_t start_end_addr_shift = WORD_ADDR_BW - ((MAX_BITWIDTH_BANK - BITWIDTH_BANK) + (MAX_BITWIDTH_COL - BITWIDTH_COL));
	unsigned long size = EARLY_AUDIO_BUF_KB / 24 * 24 << 10;
	uint16_t analog_gain = ea->analog_gain + 2;

	audiow->bank_addr_type = BANK_ADDR_TYPE;
	audiow->col_addr_type = COL_ADDR_TYPE;
	audiow->buffer_size = size >> 3;
	audiow->ini_addr_linear_0 = ea->data_addr >> 3;

	/* Let addr 1 access violation to stop DA */
	audiow->ini_addr_linear_1 = (ea->data_addr + size) >> 3;
	audiow->end_addr = (ea->data_addr + size - 1) >> start_end_addr_shift;

	switch(ea->interface) {
	case 1: //pdm
		/* Not Ready */
		break;
	case 2: //i2s
		/* Not Ready */
		break;
	case 0: //adc
	default:
		/* ADC L */
		aadc_l->aadc_ctrl_power_on_off = 1;
		/* DRC not support yet */
		//aadc_l->apreamp_gain_sel = 1;
		//amic_l->audio_agc_mode = 0x01010101; // Default
		//amic_l->audio_agc_index = (analog_gain - 2) << 24 | analog_gain << 16 | (analog_gain + 2) << 8 | (analog_gain + 3);
		aadc_l->preamp_reg0 = 0x00003000;
		aadc_l->rg_apreamp_en = 1;
		aadc_l->rg_apreamp_gain_sel = analog_gain;

		switch(ea->rate) {
		case 11025:
		case 22050:
		case 44100:
		case 88200:
			amic_l->comb_gain = 0x83126E97;
			osr = 160;
			amic_l->comb_down = osr;
			break;
		case 8000:
		case 16000:
		case 32000:
		case 48000:
		case 96000:
		default:
			amic_l->comb_gain = 0xA9031AD3;
			osr = 147;
			amic_l->comb_down = osr;
			break;
		}

		if (ea->channels == 1) {
			adoin->audio_ch_en = 1; // TODO: channel selection
			adoin->audio_swap_ch_mux_0 = 0;
			adoin->audio_swap_ch_mux_1 = 0;
			adoin->audio_gain_2_csr = ((osr - 1) << 8) | 1;
			adoin->audio_gain_2_csr_agc_info = 0x3FF;
			adoin->sample_number = osr - 1;
			adoin_syscfg->cken_write_k = 1;
			adoin_syscfg->cken_write_p = 1;

			/* Trigger start */
			audiow->frame_start = 1;
			adoin->g2c_start = 1;
			adoin->audio_w1p_start = 0x1; // TODO: channel selection
		} else { // channels == 2
			/* ADC R */
			aadc_r->aadc_ctrl_power_on_off = 1;
			/* DRC not support yet */
			//aadc_r->apreamp_gain_sel = 1;
			//amic_r->audio_agc_mode = 0x01010101; // Default
			//amic_r->audio_agc_index = (analog_gain - 2) << 24 | analog_gain << 16 | (analog_gain + 2) << 8 | (analog_gain + 3);
			aadc_r->preamp_reg0 = 0x00003000;
			aadc_r->rg_apreamp_en = 1;
			aadc_r->rg_apreamp_gain_sel = analog_gain;

			switch(ea->rate) {
			case 11025:
			case 22050:
			case 44100:
			case 88200:
				amic_r->comb_gain = 0x83126E97;
				amic_r->comb_down = 0x000000A0;
				break;
			case 8000:
			case 16000:
			case 32000:
			case 48000:
			case 96000:
			default:
				amic_r->comb_gain = 0xA9031AD3;
				amic_r->comb_down = 0x00000093;
				break;
			}

			adoin->audio_ch_en = 3;
			adoin->audio_swap_ch_mux_0 = ((((osr - 1) >> 1) << 16) | ((osr - 1) >> 1));
			adoin->audio_swap_ch_mux_1 = (osr - 1) >> 1;
			adoin->amic_ch_num = ((osr - 1) << 8) | 3;
			adoin->audio_gain_2_csr_agc_info = 0x01FF03FF;
			adoin->sample_number = osr - 1;

			adoin_syscfg->cken_write_k = 1;
			adoin_syscfg->cken_write_p = 1;

			audiow->frame_start = 1;
			adoin->g2c_start = 1;
			adoin->audio_w1p_start = 0x101;
		}

		break;
	}
}

int earlyaudio_init(void)
{
	struct audio_drvdata *drvdata = &g_drvdata;

	earlyaudio_csr_init(drvdata);
	earlyaudio_params_init(&drvdata->early);
	earlyaudio_start(drvdata);

	printf("[%u][Notice][AUDIO] Start capture\n", get_cpu_time());

	return 0;
}
#endif /* CONFIG_EARLYAUDIO */
