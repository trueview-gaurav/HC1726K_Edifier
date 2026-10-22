#include <common.h>

#if defined(CONFIG_HC1703_1723_1753_1783S)
void augentix_adc_workaround(void);
void augentix_adc_power_on(void);
void augentix_adc_power_off(void);
void augentix_adc_setup(void);
#else
int augentix_adc_setup(void);
#endif

/* This API should always return a 12-bit saradc value as result */
int augentix_adc_read(int adc_ch, uint32_t *adc_result);
