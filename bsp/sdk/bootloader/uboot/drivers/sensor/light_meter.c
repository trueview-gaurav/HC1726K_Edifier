// (C) Copyright 2023
// Kelan Jhao, Augentix, kelan.jhao@augentix.com

#include <common.h> // for uint (in 12c.h), NULL
#include <asm/io.h> // for writel(), readl()
#include "is_setting.h"
#include "augentix_adc.h"

#define DEFAULT_LUX 180
#define LIGHT_METER_REPEAT_TIME 10

#define SHIFT_CNT(shift) (shift >= 3) ? (shift - 3) : (3 - shift)

#define SHIFT_ROUND(val, shift, round, multiplier)                                  \
	val >> shift;                                                               \
	if (multiplier == 1 && shift >= 3) {                                        \
		round += ((val % ((uint32_t)0x01 << shift)) >> (SHIFT_CNT(shift))); \
	} else if (multiplier == 1 && shift < 3) {                                  \
		round += ((val % ((uint32_t)0x01 << shift)) << (SHIFT_CNT(shift))); \
	} else if (multiplier == -1 && shift >= 3) {                                \
		round -= ((val % ((uint32_t)0x01 << shift)) >> (SHIFT_CNT(shift))); \
	} else if (multiplier == -1 && shift < 3) {                                 \
		round -= ((val % ((uint32_t)0x01 << shift)) << (SHIFT_CNT(shift))); \
	}

#define DEBUG(...) //printf(__VA_ARGS__)

static unsigned int k_hist_bin_8b[BSP_Y_HIST_ENTRY_NUM] = {
	0,   1,   2,   3,   4,   5,   6,   7,   8,   10,  12,  14,  16,  18,  20,  22,  24,  26,  28,  30,
	32,  34,  36,  38,  40,  44,  48,  52,  56,  60,  64,  68,  72,  76,  80,  84,  88,  92,  96,  100,
	104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256,
};

extern void is_path_bsp_get_y_hist_roi_stat(int path, struct is_bsp_y_hist_roi_stat *stat);
extern void is_path_bsp_get_y_avg_roi_stat(int path, uint8_t idx, struct is_bsp_y_avg_roi_stat *stat);

uint32_t adc_to_lux(uint32_t adc_val)
{
	int8_t multiplier = 1;
	int32_t lux;
	int32_t round_col = 0; // 1 unit = 0.125
#if LIGHT_SENSOR_TYPE == 1
	lux = 6;
	lux += SHIFT_ROUND(adc_val, 2, round_col, multiplier);
	lux += SHIFT_ROUND(adc_val, 5, round_col, multiplier);
	lux += SHIFT_ROUND(adc_val, 7, round_col, multiplier);
	lux += SHIFT_ROUND(adc_val, 8, round_col, multiplier);
	lux += SHIFT_ROUND(adc_val, 9, round_col, multiplier);
	lux += (round_col + (0x01 << 2)) >> 3;
#elif LIGHT_SENSOR_TYPE == 2
	uint64_t tmp;

	if (adc_val < 3500) {
		lux = 1;

		lux += SHIFT_ROUND(adc_val, 3, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 5, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 6, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 7, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 8, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 9, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 10, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 11, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 12, round_col, multiplier);

		multiplier = -1;
		tmp = adc_val * adc_val;
		lux -= SHIFT_ROUND(tmp, 17, round_col, multiplier);

		multiplier = 1;
		tmp *= adc_val;
		lux += SHIFT_ROUND(tmp, 30, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 31, round_col, multiplier);

		lux += (round_col + (0x01 << 2)) >> 3;
	} else {
		lux = -6389922;

		lux += (5396 * adc_val);
		lux += SHIFT_ROUND(adc_val, 1, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 2, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 3, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 8, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 9, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 11, round_col, multiplier);
		lux += SHIFT_ROUND(adc_val, 12, round_col, multiplier);

		multiplier = -1;
		tmp = adc_val * adc_val;
		lux -= (1 * tmp);
		lux -= SHIFT_ROUND(tmp, 1, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 6, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 9, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 10, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 11, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 12, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 13, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 17, round_col, multiplier);
		lux -= SHIFT_ROUND(tmp, 18, round_col, multiplier);

		multiplier = 1;
		tmp *= adc_val;
		lux += SHIFT_ROUND(tmp, 13, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 16, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 18, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 20, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 21, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 25, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 28, round_col, multiplier);
		lux += SHIFT_ROUND(tmp, 30, round_col, multiplier);

		lux += (round_col + (0x01 << 2)) >> 3;
	}
#endif
	DEBUG("adc_to_lux: %u  -->  %d\n", adc_val, lux);
	if (lux < 0) {
		lux = 0;
	}
	return (uint32_t)lux;
}

static uint32_t transform_luma_to_lux(uint32_t luma)
{
	uint32_t luma_to_lux_idx;
	uint32_t lux;

	/* clang-format off */
	uint32_t luma_to_lux[] = {
		   0,
		  48,   96,  144,  192,  240,  288,  336,  384, 
		 432,  480,  528,  576,  624,  672,  720,  768, 
		 816,  864,  912,  960, 1008, 1056, 1104, 1152, 
		1200, 1248, 1296, 1344, 1392, 1440, 1488, 1536, 
		1584, 1632, 1680, 1728, 1776, 1824, 1872, 1920, 
		1968, 2016, 2064, 2112, 2160, 2208, 2256, 2304, 
		2352, 2400, 2448, 2496, 2544, 2592, 2640, 2688, 
		2736, 2784, 2832, 2880, 2928, 2976, 3024, 3072
	};
	/* clang-format on */

	uint16_t table_size = sizeof(luma_to_lux) / sizeof(luma_to_lux[0]);

	luma_to_lux_idx = (luma >> 8);

	if (luma_to_lux_idx >= table_size) {
		lux = luma_to_lux[table_size - 1];
	} else {
		// Assuming the table of luma_avg to lux is defined by the step = 256
		// Therefore, the interpolation is calculated by the interval = 256
		uint32_t lower_dif = luma - (luma_to_lux_idx << 8);
		uint32_t upper_dif = ((luma_to_lux_idx + 1) << 8) - luma;
		lux = luma_to_lux[luma_to_lux_idx] * upper_dif + luma_to_lux[luma_to_lux_idx + 1] * lower_dif;
		lux = (lux + (1 << 7)) >> 8;
	}

	return lux;
}

int measure_light_intensity(int adc_ch, uint8_t *nbit, uint32_t *raw_val, uint32_t *percent, uint32_t *lux, int sns_id)
{
	uint32_t adc_result;
	char *ret_str;
	int env_lux;
	static int adc_check = 0;
#if defined(CONFIG_HC1703_1723_1753_1783S)
	int n_repeat = LIGHT_METER_REPEAT_TIME;
	int i, j, ret;
	uint32_t last_adc_result[6];
#endif

	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_SRC) : getenv("lux_src");
	DEBUG("lux_src = %s\n", ret_str);

	if (strcmp(ret_str, "env") == 0) {
		switch (sns_id) {
		case SNS0_ID:
			ret_str = getenv("lux");
			break;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
		case SNS1_ID:
			ret_str = getenv("lux_1");
			break;
#endif
		default:
			printf("[LIGHT METER ERROR] getenv: lux fail.");
			break;
		}
		env_lux = (int)simple_strtoul(ret_str, NULL, 10);
		if (env_lux <= 0) {
			env_lux = DEFAULT_LUX;
		}
		if (lux != NULL) {
			*lux = env_lux;
		}
		if (raw_val != NULL) {
			*raw_val = 0xffffffff;
		}
		if (percent != NULL) {
			*percent = 0xffff;
		}
		return 0;
	} else if (strcmp(ret_str, "hw") == 0) {
#if defined(CONFIG_HC1703_1723_1753_1783S)
		if ((adc_ch < 2) || (adc_ch > 5)) {
			return -1;
		}
#else
		if (adc_ch > 2) {
			return -1;
		}
#endif

		if (adc_check == 0) {
			adc_check = 1;

#if defined(CONFIG_HC1703_1723_1753_1783S)
			memset(last_adc_result, 0xff, sizeof(last_adc_result));
			augentix_adc_setup();
			augentix_adc_power_on();
			for (i = 0; i < n_repeat; i++) {
				for (j = 0; j < 6; j++) {
					ret = augentix_adc_read(j + 0, &adc_result);
					if (ret != 0) {
						continue;
					}
					if (last_adc_result[j] != 0xFFFFFFFF) {
						if (last_adc_result[j] != adc_result) {
							goto WORKAROUND_END;
						}
					}
					last_adc_result[j] = adc_result;
				}
				udelay(10);

				if (i != 0) {
					augentix_adc_workaround();
				}
			}
		WORKAROUND_END:
			augentix_adc_read(adc_ch, &adc_result);
			augentix_adc_power_off();
#else
			augentix_adc_setup();
			augentix_adc_read(adc_ch, &adc_result);
#endif
		}

		if (nbit != NULL) {
			*nbit = 12;
		}
		if (raw_val != NULL) {
			*raw_val = adc_result;
		}
		if (percent != NULL) {
			*percent = (adc_result * 100 + 0x800) >> 12;
		}
		if (lux != NULL) {
			*lux = adc_to_lux(adc_result);
		}
	} else if (strcmp(ret_str, "sw") == 0) {
		// get IS statistic
		struct is_bsp_y_hist_roi_stat hist = { 0 };

		uint32_t luma = 0;
		int i;
		uint32_t norm = 0;

		is_path_bsp_get_y_hist_roi_stat(sns_id, &hist); // note: assume sensor id equals to path id

		for (i = 0; i < BSP_Y_HIST_ENTRY_NUM; i++) {
			luma += (hist.hist[i] * k_hist_bin_8b[i]);
			norm += hist.hist[i];
		}

		norm = norm >> 6;
		if (norm > 0) {
			luma /= norm;
		}

		// convert Lux
		*lux = transform_luma_to_lux(luma);
	} else {
		*lux = DEFAULT_LUX;
	}

	return 0;
}
