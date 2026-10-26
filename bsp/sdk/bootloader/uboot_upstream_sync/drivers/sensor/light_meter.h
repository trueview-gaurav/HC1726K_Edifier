// (C) Copyright 2023
// Kelan Jhao, Augentix, kelan.jhao@augentix.com

#ifndef _LIGHT_METER_H_
#define _LIGHT_METER_H_

#include <linux/types.h>

int measure_light_intensity(int adc_ch, uint8_t *nbit, uint32_t *raw_val, uint32_t *percent, uint32_t *lux, int sns_id);

#endif // _LIGHT_METER_H_
