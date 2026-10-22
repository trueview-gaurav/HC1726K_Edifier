/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor.h"
#include "sensor_settings.h"
#include "sensor_params.h"

#ifdef __UBOOT__
#include <common.h>
#else
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "l_sensor_cal.h"
#endif

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (0) // sensor ID, not important

// Example of different registers for controlling the frame rate or exposure.
// These registers should be mentioned from the documents of the sensor.
#define TMPLT_VTS_ADDR1 (0x0100)
#define TMPLT_VTS_ADDR2 (0x0101)

#define TMPLT_EXP_ADDR1 (0x0120)
#define TMPLT_EXP_ADDR2 (0x0121)

#define TMPLT_GAIN_ADDR1 (0x0130)
#define TMPLT_GAIN_ADDR2 (0x0131)

#define EXP_LINE_GAP (4) // spec 8.8
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1)

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))
typedef enum {
	IDX_VTS_1,
	IDX_VTS_2,
	IDX_EXP_1,
	IDX_EXP_2,
	IDX_GAIN_1,
	IDX_GAIN_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

static int SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[idx.path]->regs_info;
	int i;

	if (NULL == regs) {
		sensor_log_err("Invalid data pointer.");
		return -EINVAL;
	}

	if (false == pregs[0].is_config) {
		pregs[0].bus_type = BUS_TYPE_I2C;
#ifdef SNS_I2C_1
		pregs[0].bus_sel.i2c_dev = 2;
#else
		pregs[0].bus_sel.i2c_dev = 1;
#endif
		pregs[0].cfg_delay_max = 2;
		pregs[0].reg_num = IDX_NUM;

		for (i = 0; i < pregs[0].reg_num; ++i) {
			pregs[0].i2c_data[i].is_update = false;
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = SENSOR_I2C_REG_LENGTH;
			pregs[0].i2c_data[i].reg_data_byte_num = SENSOR_I2C_DAT_LENGTH;
		}

		pregs[0].i2c_data[IDX_VTS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VTS_1].reg_addr = TMPLT_VTS_ADDR1;
		pregs[0].i2c_data[IDX_VTS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VTS_2].reg_addr = TMPLT_VTS_ADDR2;

		pregs[0].i2c_data[IDX_EXP_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_EXP_1].reg_addr = TMPLT_EXP_ADDR1;
		pregs[0].i2c_data[IDX_EXP_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_EXP_2].reg_addr = TMPLT_EXP_ADDR2;

		pregs[0].i2c_data[IDX_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN_1].reg_addr = TMPLT_GAIN_ADDR1;
		pregs[0].i2c_data[IDX_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN_2].reg_addr = TMPLT_GAIN_ADDR2;
		pregs[0].is_config = true;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	g_sns_state[idx.path]->exp_line[1] = g_sns_state[idx.path]->exp_line[0];
	g_sns_state[idx.path]->frame_line[1] = g_sns_state[idx.path]->frame_line[0];
	g_sns_state[idx.path]->line_pixel[1] = g_sns_state[idx.path]->line_pixel[0];

	return MPI_SUCCESS;
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	// initialize internal data
	g_sensor_state[idx.path].sensor_gain = 32;
	g_sensor_state[idx.path].pclk = PCLK;
	g_sensor_state[idx.path].fps_line = INIT_FRAME_LINE;
	g_sensor_state[idx.path].frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state[idx.path].line_pixel[0] = INIT_LINE_LEN;

	uint64_t tmp = (uint64_t)g_sensor_state[idx.path].line_pixel[0] * 1000000 * ROW_TIME_UNIT;
	g_sensor_state[idx.path].row_time[0] = (uint32_t)((tmp + (PCLK >> 1)) / PCLK);

	g_sensor_state[idx.path].exp_line[0] = (16500 << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];

	g_sensor_state[idx.path].exp_line[1] = g_sensor_state[idx.path].exp_line[0];
	g_sensor_state[idx.path].frame_line[1] = g_sensor_state[idx.path].frame_line[0];
	g_sensor_state[idx.path].line_pixel[1] = g_sensor_state[idx.path].line_pixel[0];
	g_sensor_state[idx.path].row_time[1] = g_sensor_state[idx.path].row_time[0];

	MPI_SNS_REGS_TABLE_S init_regs = { 0 };
	memcpy(&g_sns_state[idx.path]->regs_info[0], &init_regs, sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&g_sns_state[idx.path]->regs_info[1], &init_regs, sizeof(MPI_SNS_REGS_TABLE_S));
	g_sns_state[idx.path]->regs_info[0].is_config = false;
	g_sns_state[idx.path]->regs_info[1].is_config = false;
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	int reg_val;

	// convert exposure time to register values
	// ...

	// update internal data
	g_inttime = time_us;
	if (effective_time) {
		*effective_time = time_us;
	}

	// update register
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_1].reg_data = reg_val & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_2].reg_data = (reg_val >> 8) & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	int reg_val;

	// convert sensor gain to register values
	// ...

	// update register
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].reg_data = reg_val & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].reg_data = (reg_val >> 8) & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	int frame_line;
	int inttime_max;
	int inttime_min;

	// convert fps to register values
	// ...

	// calculate maximum and minimum exposure time
	// ...
	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}

	// update registers
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_1].reg_data = frame_line & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_2].reg_data = (frame_line >> 8) & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_2].is_update = true;

	// update exposure time setting again
	if (g_inttime > inttime_max) {
		SENSOR_setInttime(idx, inttime_max, NULL);
	} else {
		SENSOR_setInttime(idx, g_inttime, NULL);
	}

	return MPI_SUCCESS;
}

#ifndef __UBOOT__
static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	int frame_line;

	// calculate maximum fps for the required exposure time
	// ...
	if (frame_line < SENSOR_FRAME_LINES_MIN) {
		frame_line = SENSOR_FRAME_LINES_MIN;
	}
	if (frame_line > SENSOR_FRAME_LINES_MAX) {
		return MPI_FAILURE;
	}

	// update registers
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_1].reg_data = frame_line & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_2].reg_data = (frame_line >> 8) & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VTS_2].is_update = true;

	// update exposure time
	SENSOR_setInttime(idx, time_us, NULL);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	// provide limits or default settings for AE
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;

	dft->sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_sys_gain_range.max = 16383;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->target_sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 256;
	dft->gain_thr_down = 512;
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 5800;
	dft->exp_value = 528000;

	return MPI_SUCCESS;
}

int SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	memcpy(dft, &dip_dft, sizeof(dip_dft));

	return MPI_SUCCESS;
}

int SENSOR_getAwbDefault(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *awb)
{
	memcpy(awb->k_table, &ct_tbl_dft[0], sizeof(MPI_AWB_COLOR_TEMP_S) * MPI_K_TABLE_ENTRY_NUM);
	memcpy(awb->delta_table, &delta_tbl_dft[0], sizeof(MPI_AWB_COLOR_DELTA_S) * MPI_K_TABLE_ENTRY_NUM);

	return MPI_SUCCESS;
}

int SENSOR_getBlackLevel(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level)
{
	// acquire black-level directly from the sensor or from predefined table
	// ...
	return MPI_SUCCESS;
}

int SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
{
	memcpy(cal, &cal_tbl_dft, sizeof(MPI_CAL_SNS_DEFAULT_S));

	return MPI_SUCCESS;
}
#endif

static int SENSOR_regCallback(MPI_PATH idx)
{
	// function callbacks for libmpp
	MPI_SNS_CALLBACK_S sensor_callback = {
		.dip = {
			.global_init = SENSOR_globalInit,
			.get_regs_info = SENSOR_getRegsInfo,
#ifndef __UBOOT__
			.init = SENSOR_configInit,
			.get_sns_op_info = SENSOR_getOpInfo,
			.get_dip_default = SENSOR_getDipDefault,
			.exit = SENSOR_configExit,
#endif
		},
		.ae = {
			.set_framerate = SENSOR_setFramrate,
			.set_inttime = SENSOR_setInttime,
			.set_sensor_gain = SENSOR_setSensorGain,
#ifndef __UBOOT__
			.set_slow_inttime = SENSOR_setSlowInttime,
			.get_ae_default = SENSOR_getAeDefault,
#endif
		},
#ifndef __UBOOT__
		.cal = {
			.get_black_level = SENSOR_getBlackLevel,
			.get_cal_default = SENSOR_getCalDefault,
		},
		.awb = {
			.get_awb_default = SENSOR_getAwbDefault,
		},
#endif
	};

	MPI_regSnsCallback(idx, SENSOR_ID, &sensor_callback);

	return MPI_SUCCESS;
}

static int SENSOR_deregSnsCallback(MPI_PATH idx)
{
	MPI_deregSnsCallback(idx, SENSOR_ID);
	return MPI_SUCCESS;
}

#ifdef SNS0
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS0_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};
#endif
