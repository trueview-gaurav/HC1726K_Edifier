// (C) Copyright 2023
// Kelan Jhao, Augentix, kelan.jhao@augentix.com

#ifndef _EXPOSURE_H_
#define _EXPOSURE_H_

#include <linux/types.h>

uint32_t sensor_measure_init_exposure(int adc_ch, int sns_id);
void ir_cut_control_idle(void);

#endif // _EXPOSURE_H_
