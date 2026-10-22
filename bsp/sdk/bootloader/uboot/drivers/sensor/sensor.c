/*
 * sensor.c: Function wrappers for other files in the uboot sensor driver.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#include "sensor.h"

#include <common.h>

#include "mpi_index.h"
#include "mpi_dip_sns.h"

#include "sensor_comm.h"
#include "sensor_settings.h"

extern void is_set_sensor_data(uint8_t path, uint32_t fps, uint32_t exp, uint32_t gain);

static MPI_SNS_CALLBACK_S sns_callbacks[2];
static RANGE_S g_exposure_range[2];

long g_camera_fps[2];
long g_init_exp[2];
uint32_t g_lux[2];
uint32_t g_exps_time_us[2];
uint32_t g_gain32[2];

/**
 * The Uboot sensor driver might be initialized before environment variables
 * become writable, so values are temporarily stored and written later
 */
void sensor_set_env(void)
{
	char value_buf[32];

	sprintf(value_buf, "%u", g_lux[0]);
	setenv("lux", value_buf);
	sprintf(value_buf, "%ld", g_camera_fps[0]);
	setenv("camera_fps", value_buf);
	sprintf(value_buf, "%ld", g_init_exp[0]);
	setenv("init_exp", value_buf);
	is_set_sensor_data(0, (uint32_t)g_camera_fps[0], g_exps_time_us[0], g_gain32[0]);
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	sprintf(value_buf, "%u", g_lux[1]);
	setenv("lux_1", value_buf);
	sprintf(value_buf, "%ld", g_camera_fps[1]);
	setenv("camera_fps_1", value_buf);
	if (ALL_SENSOR_SHARE_LUX) {
		g_init_exp[1] = g_init_exp[0];
	}
	sprintf(value_buf, "%ld", g_init_exp[1]);
	setenv("init_exp_1", value_buf);
	is_set_sensor_data(1, (uint32_t)g_camera_fps[1], g_exps_time_us[1], g_gain32[1]);
#endif
}

/* sensor_cmos.c */
INT32 MPI_regSnsCallback(MPI_PATH idx, __attribute__((unused)) INT32 sns_id, const MPI_SNS_CALLBACK_S *p_sns_cb)
{
	int path_idx = idx.path;
	MPI_SNS_REGS_TABLE_S regs;

	if (!p_sns_cb) {
		return MPI_FAILURE;
	}

	sns_callbacks[path_idx] = *p_sns_cb;
	sns_callbacks[path_idx].dip.global_init(idx);
	// Make sure every register in sensor_cmos.c is reseted
	sns_callbacks[path_idx].dip.get_regs_info(idx, &regs);

	return MPI_SUCCESS;
}

INT32 MPI_deregSnsCallback(__attribute__((unused)) MPI_PATH idx, __attribute__((unused)) INT32 sns_id)
{
	return MPI_SUCCESS;
}

int binary_search_bin(const int value, const int *x1, const int i0, const int i1)
{
	if ((i1 - i0) <= 1) {
		return i1;
	}

	int i = (i0 + i1) >> 1;

	if (value < x1[i]) {
		return binary_search_bin(value, x1, i0, i);
	}

	return binary_search_bin(value, x1, i, i1);
}

int binary_search_nr(const int value, const int arr[], const int start, const int end)
{
	int idx = 0;
	int mask = 0x40000000;
	int tmp_idx;

	if (start == end) {
		return -EINVAL;
	}

	for (; mask; mask >>= 1) {
		tmp_idx = idx + mask;
		if (tmp_idx >= end) {
			continue;
		}
		if (tmp_idx < start) {
			idx = tmp_idx;
			continue;
		}

		if (arr[tmp_idx] <= value) {
			idx = tmp_idx;
		}
	}

	return idx;
}

/* sensor_ctrl.c */
int sensor_get_fps_instruction(long frame_rate, SensCmd *command_arr, int arr_len, int sns_id)
{
	MPI_PATH idx = MPI_INPUT_PATH(0, 0);
	MPI_SNS_REGS_TABLE_S regs;

	int i;
	int j;

	// Calculate register values for the preferred frame rate
	sns_callbacks[0].ae.set_framerate(idx, frame_rate, &g_exposure_range[0]);
#ifdef CONFIG_VERBOSE
	printf("inttime max = %d\n", g_exposure_range[0].max);
	printf("inttime min = %d\n", g_exposure_range[0].min);
#endif

	// Retrieve the corresponding sensor registers
	sns_callbacks[0].dip.get_regs_info(idx, &regs);
	for (i = 0; i < arr_len; i++) {
		uint32_t register_addr = command_arr[i].reg;
		for (j = 0; j < regs.reg_num; j++) {
			if (regs.i2c_data[j].reg_addr == register_addr) {
				command_arr[i].val = regs.i2c_data[j].reg_data;
			}
		}
	}

	return 0;
}

int sensor_get_exposure_instruction(unsigned long init_exposure, SensCmd *command_arr, int arr_len, int sns_id)
{
	MPI_PATH idx = MPI_INPUT_PATH(0, 0);
	MPI_SNS_REGS_TABLE_S regs;

	uint32_t inttime;
	uint32_t real_inttime;
	uint32_t sensor_gain;
	int i;
	int j;

	// Calculate a proper exposure time setting
	inttime = init_exposure / 32;
	if (inttime > g_exposure_range[0].max) {
		inttime = g_exposure_range[0].max;
	} else if (inttime < g_exposure_range[0].min) {
		inttime = g_exposure_range[0].min;
	}

#ifdef CONFIG_VERBOSE
	printf("Preferred inttime = %u\n", inttime);
#endif

	// Calculate register values for the preferred inttime, and get the real time setting
	sns_callbacks[0].ae.set_inttime(idx, inttime, &real_inttime);
#ifdef CONFIG_VERBOSE
	printf("Real inttime = %u\n", real_inttime);
#endif
	switch (sns_id) {
	case SNS0_ID:
		g_exps_time_us[0] = real_inttime;
		break;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	case SNS1_ID:
		g_exps_time_us[1] = real_inttime;
		break;
#endif
	default:
		printf("[Sensor Error] Set exps_time_us fail.\n");
		break;
	}

	// Use the real inttime to calculate a proper sensor gain
	sensor_gain = ((uint32_t)init_exposure + (real_inttime >> 1)) / real_inttime;
	if (sensor_gain > SENSOR_GAIN_MAX) {
		sensor_gain = SENSOR_GAIN_MAX;
	} else if (sensor_gain < SENSOR_GAIN_MIN) {
		sensor_gain = SENSOR_GAIN_MIN;
	}
#ifdef CONFIG_VERBOSE
	printf("sensor gain = %u\n", sensor_gain);
#endif

	// Calculate register values for the sensor gain
	sns_callbacks[0].ae.set_sensor_gain(idx, sensor_gain);

	switch (sns_id) {
	case SNS0_ID:
		g_gain32[0] = sensor_gain;
		break;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	case SNS1_ID:
		g_gain32[1] = sensor_gain;
		break;
#endif
	default:
		printf("[Sensor Error] Set gain32 fail.\n");
		break;
	}

	// Retrieve the corresponding sensor registers
	sns_callbacks[0].dip.get_regs_info(idx, &regs);
	for (i = 0; i < arr_len; i++) {
		uint32_t register_addr = command_arr[i].reg;
		for (j = 0; j < regs.reg_num; j++) {
			if (regs.i2c_data[j].reg_addr == register_addr) {
				command_arr[i].val = regs.i2c_data[j].reg_data;
			}
		}
	}

	return 0;
}
