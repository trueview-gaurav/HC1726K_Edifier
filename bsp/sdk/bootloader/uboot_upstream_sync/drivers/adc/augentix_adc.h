/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __AUGENTIX_ADC_H__
#define __AUGENTIX_ADC_H__

#include <linux/types.h>

#if defined(CONFIG_AUGENTIX_SOC_KYOTO)
void augentix_adc_workaround(void);
void augentix_adc_power_on(void);
void augentix_adc_power_off(void);
void augentix_adc_setup(void);
#else
int augentix_adc_setup(void);
#endif

/* This API should always return a 12-bit saradc value as result */
int augentix_adc_read(int adc_ch, uint32_t *adc_result);

#endif /* __AUGENTIX_ADC_H__ */
