#include <common.h>
#include <asm/io.h>

#include "augentix_adc.h"
#include "csr_bank_saadcctr.h"

#define SAADCCTRL_BASE 0x80110000
#define ADO_LDO_BASE 0x80250000
#define EXP_0_3V 68 // #95854
#define EXP_0_9V 206 // #95854
#define CALI_SAMPLE_TIMES 63 // 64 times

#define NORAML_SAMPLE_TIMES 1023 // 1024 times
#define MAX_TRIAL_TIMES 70 // equal to 7 ms (#85143-35)
#define MAX_RETRY_TIMES 3

#define DEBUG(...) //printf(__VA_ARGS__)

/* This API should always return a 12-bit saradc value as result */
int augentix_adc_read(int adc_ch, uint32_t *adc_result)
{
	volatile CsrBankSaadcctr *saadc = (volatile CsrBankSaadcctr *)SAADCCTRL_BASE;
	int i = 0;

	saadc->start = 1;
	saadc->calibration_swset = 1;

	for (i = 0; i < MAX_TRIAL_TIMES; i++) {
		udelay(100);
		if (saadc->saadc_kernel_idle) {
			break;
		}
	}

	if (i == MAX_TRIAL_TIMES) {
		printf("wait saadc time exceeds limitation\n");
		return -ETIME;
	}

	switch (adc_ch) {
	case 0:
		*adc_result = saadc->avg_ch0 << 4;
		break;
	case 1:
		*adc_result = saadc->avg_ch1 << 4;
		break;
	case 2:
		*adc_result = saadc->avg_ch2 << 4;
		break;
	case 3:
		*adc_result = saadc->avg_ch3 << 4;
		break;
	default:
		printf("Invalid adc_ch %d\n", adc_ch);
		return -EINVAL;
	}
	DEBUG("ch%u = %u\n", adc_ch, *adc_result);
	return 0;
}

static void agtx_adc_sample_start(volatile CsrBankSaadcctr *saadc)
{
	saadc->start = 1;
	saadc->calibration_swset = 1;
	while (!(saadc->saadc_kernel_idle)) {
	}
}

static int augentix_adc_calibration(void)
{
	volatile CsrBankSaadcctr *saadc = (volatile CsrBankSaadcctr *)SAADCCTRL_BASE;
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

	if (saadc->none_overlap_cycle == 1)
		return 0;

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

	printf("can't find calibration setting on vref section, retry\n");
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
		printf("Only find candidate\n");
		saadc->calp_wr = calp_cand;
		saadc->caln_wr = caln_cand;
		goto calibration_done;
	}

	printf("can't find calibration setting on calp, caln section, retry\n");
	retry_times++;
	if (retry_times <= MAX_RETRY_TIMES) {
		goto tune_calp_caln;
	}

calibration_failed:
	printf("Calibration failed\n");
	return -1;

calibration_done:
	DEBUG("final set calp = %u, caln = %u, vref = %u\n", saadc->calp_wr, saadc->caln_wr, saadc->vrefpsel);

	// set for normal sampling
	saadc->rg_saadccs_engpi = 0;
	return 0;
}

int augentix_adc_setup(void)
{
	volatile CsrBankSaadcctr *saadc = (volatile CsrBankSaadcctr *)SAADCCTRL_BASE;
	int ret = 0;

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
	// set low sample time here to take less time for calibration
	saadc->sample_data_num_ch0 = CALI_SAMPLE_TIMES;
	saadc->sample_data_num_ch1 = CALI_SAMPLE_TIMES;
	saadc->sample_data_num_ch2 = CALI_SAMPLE_TIMES;
	saadc->sample_data_num_ch3 = CALI_SAMPLE_TIMES;

	// enable ldo (important)
	writel(0x1010101, ADO_LDO_BASE);
	udelay(30);
	saadc->irq_clear0 = 0x11111111;
	ret = augentix_adc_calibration();

	if (ret == 0) {
		// set this unused csr to record calibration has been done.
		saadc->none_overlap_cycle = 1;
	}

	return ret;
}
