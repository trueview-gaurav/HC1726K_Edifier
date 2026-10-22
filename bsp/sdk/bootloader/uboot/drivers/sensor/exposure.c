// (C) Copyright 2023
// Kelan Jhao, Augentix, kelan.jhao@augentix.com

#include "exposure.h"
#include <asm-generic/gpio.h>

#include <common.h>

#include "sensor_comm.h"
#include "light_meter.h"

extern uint32_t g_lux[2];

static uint32_t transform_lux_to_index(uint32_t illuminance_lux)
{
	uint32_t light_intensity_index = 0;

	// Assuming the table of lux to exposure is defined by the step of lux = 48
	light_intensity_index = illuminance_lux / 48;

	return light_intensity_index;
}

static uint32_t lux_to_exposure(uint32_t illuminance_lux)
{
	uint32_t lux_to_expos_idx;
	uint32_t exposure;

	/* clang-format off */
	uint32_t lux_to_exp[] = {
		7337795,
		1747165, 1176538, 415076, 368232,
		 301770,  258417, 227498, 205226,
		 178154,  144428, 123584, 100478,
		  83022,   74692,  68150,  62448,
		  56253,   52632,  49416,  46485,
		  43908,   41580,  39426,  37505,
		  35713,   34103,  32620,  31223,
		  29956,   28756,  27662,  26642,
		  25668,   24775,  23937,  23133,
		  22391,   21677,  21016,  20391,
		  19786,   19225,  18681,  18174,
		  17691,   17222,  16783,  16364,
		  15955,   15573,  15198,  14847,
		  14510,   14180,  13870,  13565,
		  13278,   12840,   9021,   6839,
		   5442,    3777,   2832,   2232
	};
	/* clang-format on */

	if (illuminance_lux < 9) {
#ifdef CONFIG_PROD_AGT300_27
		// for AGT300-27, due to the limitation of fps (15) and sensor analog gain (1856)
		// set the bound for exposure as 1000000/15 * 1856 ~= 120000000
		exposure = 120000000;
#else
		// due to the limitation of fps (15) and sensor analog gain (496)
		// set the min bound for exposure as 1000000/15 * 496 ~= 32000000
		exposure = 32000000;
#endif
	} else if (illuminance_lux < 12) {
		exposure = 14000000 - 150000 * (illuminance_lux - 8);
	} else {
		lux_to_expos_idx = transform_lux_to_index(illuminance_lux);

		uint32_t lower_dif = illuminance_lux - (lux_to_expos_idx * 48);
		uint32_t upper_dif = ((lux_to_expos_idx + 1) * 48) - illuminance_lux;
		exposure = lux_to_exp[lux_to_expos_idx] * upper_dif + lux_to_exp[lux_to_expos_idx + 1] * lower_dif;
		exposure = (exposure + 24) / 48;
	}
	return exposure;
}

void ir_cut_control(int filter_enable)
{
#if (IR_CUT_MODE == 1)
	if (filter_enable) {
		printf("IR filter on\n");
		gpio_direction_output(IR_CUT_GPIO_1, IR_FILTER_ENABLE_LEVEL);
	} else {
		printf("IR filter off\n");
		gpio_direction_output(IR_CUT_GPIO_1, !IR_FILTER_ENABLE_LEVEL);
	}

#elif (IR_CUT_MODE == 2)
	if (filter_enable) {
		printf("IR filter on\n");
		gpio_direction_output(IR_CUT_GPIO_1, IR_FILTER_ENABLE_LEVEL & 0x01);
		gpio_direction_output(IR_CUT_GPIO_2, IR_FILTER_ENABLE_LEVEL & 0x02);
	} else {
		printf("IR filter off\n");
		gpio_direction_output(IR_CUT_GPIO_1, IR_FILTER_DISABLE_LEVEL & 0x01);
		gpio_direction_output(IR_CUT_GPIO_2, IR_FILTER_DISABLE_LEVEL & 0x02);
	}
#endif
}

void ir_cut_control_idle(void)
{
#if (IR_CUT_MODE == 2)
	gpio_direction_output(IR_CUT_GPIO_1, IR_CUT_IDLE_LEVEL & 0x01);
	gpio_direction_output(IR_CUT_GPIO_2, IR_CUT_IDLE_LEVEL & 0x02);
#endif
}

uint32_t sensor_measure_init_exposure(int adc_ch, int sns_id)
{
	uint32_t light_intensity_raw = 0;
	uint32_t light_intensity_percent = 0;
	uint32_t light_intensity_lux = 0;
	int tmp;
#ifdef LIGHT_LED_GPIO
	char *ret_str;
#endif

	if (ALL_SENSOR_SHARE_LUX == 0 || sns_id == 0) {
		tmp = measure_light_intensity(adc_ch, NULL, &light_intensity_raw, &light_intensity_percent,
		                              &light_intensity_lux, sns_id);
		if (tmp) {
			printf("[Sensor Warning] Unable to read from ADC.\n");
		}

#ifdef LIGHT_LED_GPIO
		ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_LED_ON_THRESHOLD) : getenv("led_on_thre");
		tmp = (int)simple_strtoul(ret_str, NULL, 10);
		if (light_intensity_lux < tmp) {
			// Disable IR filter, or Enable IR filter under while LED scenario
			ir_cut_control(0 || (LIGHT_LED_MODE == 0));
			// Turn on LED
			gpio_direction_output(LIGHT_LED_GPIO, LIGHT_LED_GPIO_ACT_LEVEL);
			// Adjust Lux
			ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_LED_ON_LUX_OFFSET) : getenv("led_on_offset");
			tmp = (int)simple_strtoul(ret_str, NULL, 10);
			light_intensity_lux += tmp;
		} else {
			// Enable IR filter
			ir_cut_control(1);
			// Turn off LED
			gpio_direction_output(LIGHT_LED_GPIO, !LIGHT_LED_GPIO_ACT_LEVEL);
		}
#endif /*LIGHT_LED_GPIO*/
		switch (sns_id) {
		case SNS0_ID:
			g_lux[0] = light_intensity_lux;
			break;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
		case SNS1_ID:
			g_lux[1] = light_intensity_lux;
			break;
#endif
		default:
			printf("[Sensor Error] Set lux fail.\n");
			break;
		}
	} else if (sns_id != 0) {
		light_intensity_lux = g_lux[0];
		g_lux[1] = light_intensity_lux;
	}
	return lux_to_exposure(light_intensity_lux);
}
