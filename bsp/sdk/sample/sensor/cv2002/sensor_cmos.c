/******************************************************************************
 * *
 * * Copyright (c) Augentix Inc. - All Rights Reserved
 * *
 * * Unauthorized copying of this file, via any medium is strictly prohibited.
 * *
 * * Proprietary and confidential.
 * *
 * *****************************************************************************/

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

#define SENSOR_ID (2002) // sensor ID

#define CV2003_SHS1_ADDR (0x3048) // sensor exposure line control(shs1) [7:0]
#define CV2003_SHS2_ADDR (0x3049) // sensor exposure line control(shs2) [15:8]
#define CV2003_SHS3_ADDR (0x304A) // sensor exposure line control(shs2) [19:16]

#define CV2003_GAIN_ANALOG_ADDR (0x3154) // sensor analog gain
#define CV2003_GAIN_DIGITAL_L_ADDR (0x314C) // sensor digital gain [7:0]
#define CV2003_GAIN_DIGITAL_H_ADDR (0x314D) // sensor digital gain [15:8]

#define CV2003_VMAX1_ADDR (0x3020) // frame line [7:0]
#define CV2003_VMAX2_ADDR (0x3021) // frame line [15:8]
#define CV2003_VMAX3_ADDR (0x3022) // frame line [19:16]

#define EXP_LINE_GAP (3) // spec 8.2-1
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1) // spec 8.2-1

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int32_t g_inttime = 16500;

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_VMAX_3,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_AG,
	IDX_DG_L,
	IDX_DG_H,
	IDX_NUM,
} I2C_DATA_IDX_E;

#ifndef __UBOOT__
static int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
{
	MPI_SNS_REGS_TABLE_S *regs = g_sns_state[path_idx]->regs_info;
	SensCmd cmd[32];
	int32_t ret;
	if (regs[0].is_config == false) {
		return MPI_SUCCESS;
	}

	for (int32_t i = 0; i < regs[0].reg_num; ++i) {
		cmd[i].reg = regs->i2c_data[i].reg_addr;
		cmd[i].val = regs->i2c_data[i].reg_data;
	}

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

	return ret;
}
#endif

static int32_t SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[idx.path]->regs_info;
	int32_t i;
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
			pregs[0].i2c_data[i].is_update = true;
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = 2;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = CV2003_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = CV2003_VMAX2_ADDR;
		pregs[0].i2c_data[IDX_VMAX_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_3].reg_addr = CV2003_VMAX3_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = CV2003_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = CV2003_SHS2_ADDR;
		pregs[0].i2c_data[IDX_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_3].reg_addr = CV2003_SHS3_ADDR;

		pregs[0].i2c_data[IDX_AG].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AG].reg_addr = CV2003_GAIN_ANALOG_ADDR;
		pregs[0].i2c_data[IDX_DG_L].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DG_L].reg_addr = CV2003_GAIN_DIGITAL_L_ADDR;
		pregs[0].i2c_data[IDX_DG_H].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DG_H].reg_addr = CV2003_GAIN_DIGITAL_H_ADDR;
		pregs[0].is_config = true;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	g_sns_state[idx.path]->exp_line[1] = g_sns_state[idx.path]->exp_line[0];
	g_sns_state[idx.path]->frame_line[1] = g_sns_state[idx.path]->frame_line[0];
	g_sns_state[idx.path]->line_pixel[1] = g_sns_state[idx.path]->line_pixel[0];

	for (i = 0; i < pregs[0].reg_num; ++i) {
		pregs[0].i2c_data[i].is_update = false;
	}

	return MPI_SUCCESS;
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	g_sensor_state[idx.path].sensor_gain = SENSOR_GAIN_MIN;
	g_sensor_state[idx.path].pclk = PCLK;
	g_sensor_state[idx.path].fps_line = INIT_FRAME_LINE;
	g_sensor_state[idx.path].frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state[idx.path].line_pixel[0] = INIT_LINE_LEN;

	g_sensor_state[idx.path].row_time[0] =
	        (int32_t)(((((uint64_t)INIT_LINE_LEN * 1000000) << ROW_TIME_PRC) + (uint64_t)(PCLK >> 1)) / PCLK);

	g_sensor_state[idx.path].exp_line[0] =
	        ((g_inttime << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	        g_sensor_state[idx.path].row_time[0];
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
	if (time_us <= 0) {
		sensor_log_err("Exposure time must be greater than than 0.");
		return MPI_FAILURE;
	}
	if (g_sensor_state[idx.path].row_time[0] <= 0) {
		sensor_log_err("Internal parameters might not be correctly initialized.");
		return MPI_FAILURE;
	}
	int32_t exp_line_prc = 0;
	int32_t exp_line = (time_us << (ROW_TIME_PRC + exp_line_prc)) / g_sensor_state[idx.path].row_time[0];

	if (exp_line > (SENSOR_EXP_LINES_MAX << exp_line_prc) || exp_line < (SENSOR_EXP_LINES_MIN << exp_line_prc)) {
		sensor_log_warn("Exposure time exceeds hardware limit.");
		exp_line =
		        CLAMP(exp_line, (SENSOR_EXP_LINES_MIN << exp_line_prc), (SENSOR_EXP_LINES_MAX << exp_line_prc));
	}

	if (exp_line > (g_sensor_state[idx.path].frame_line[0] << exp_line_prc) - (EXP_LINE_GAP << exp_line_prc)) {
		sensor_log_err("Expsoure time too long in current FPS.");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = (exp_line >> exp_line_prc);
	uint32_t time_tmp = (uint32_t)exp_line * g_sensor_state[idx.path].row_time[0];
	time_tmp = (time_tmp + (1 << (ROW_TIME_PRC + exp_line_prc - 1))) >> (ROW_TIME_PRC + exp_line_prc);
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	int32_t value = (g_sensor_state[idx.path].frame_line[0] - exp_line) * 2; // spec 8.2-1
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = value & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].reg_data = (value & 0xF0000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].is_update = true;
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_err("Sensor gain must be in range [%d, %d]", SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
		return MPI_FAILURE;
	}
	g_sns_state[idx.path]->sensor_gain = gain;

	/* a_gain max and d_gain min*/
	int ac_gain = 0xF8;
	int df_gain = 0x40;

	const int ac_step[] = { 256, 512, 1024, 2048, 4096, 8192 }; // x1, x2, x4, x8, x16, x32
	const int ac_val[] = { 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8 };

	const int df_step[] = { 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 }; // x1, x2, x4, x8, x16, x32
	const int df_val[] = { 0x08, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400 };
	const int df_base_step = 0x02; // 1/64 = 2 base step, 1/128 = 1 base step
	const int df_base = 0x40; // 0x40 start

	int ac_gain_tmp;
	int tmp;
	int tmp_gain = gain * 8; // ac_step[0] = 256/32 = 8

	// analog coarse gain
	tmp = binary_search_nr(tmp_gain, ac_step, 0, sizeof(ac_step) / sizeof(int));
	ac_gain = ac_val[tmp];
	tmp_gain = ((tmp_gain * ac_step[0]) + (ac_step[tmp] >> 1)) / ac_step[tmp];
	ac_gain_tmp = ac_step[tmp] / ac_step[0];

	// digital fine gain
	df_gain = 256 * ac_gain_tmp; // 32 * 8 = 256
	tmp = binary_search_nr(df_gain, df_step, 0, sizeof(df_step) / sizeof(int));
	df_gain = gain * 8;
	df_gain = ((df_gain - df_step[tmp]) / df_val[tmp]) * df_base_step + df_base;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AG].reg_data = ac_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DG_L].reg_data = df_gain & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DG_H].reg_data = (df_gain & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AG].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DG_L].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DG_H].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	if (fps <= 0) {
		sensor_log_err("FPS must be greater than than 0.");
		return MPI_FAILURE;
	}
	if (g_sensor_state[idx.path].row_time[0] <= 0 || g_sensor_state[idx.path].line_pixel[0] <= 0) {
		sensor_log_err("Internal parameters might not be correctly initialized.");
		return MPI_FAILURE;
	}
	uint32_t frame_line; /* Lines of pixels the sensor will run through in a frame. */
	uint32_t sec_line; /* Lines of pixels the sensor will run through in one second. */
	uint32_t line_pixel = g_sensor_state[idx.path].line_pixel[0];
	uint32_t row_time = g_sensor_state[idx.path].row_time[0];
	uint32_t pclk = g_sensor_state[idx.path].pclk;
	uint32_t inttime_max;
	uint32_t inttime_min;

	fps = fps * FPS_UNIT;
	sec_line = (pclk + (line_pixel >> 1)) / line_pixel;
	if (sec_line <= 0) {
		sensor_log_err("Cannot correctly calculate line per second.");
		return MPI_FAILURE;
	}

	frame_line = ((sec_line << FPS_PRC) + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Requested fps exceeds driver limit.");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	inttime_max = (((frame_line - EXP_LINE_GAP) * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	inttime_min = ((SENSOR_EXP_LINES_MIN * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}

	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime->max, NULL);
	} else {
		SENSOR_setInttime(idx, g_inttime, NULL);
	}
	frame_line *= 2; // spec 8.2-1
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = (frame_line & 0xF0000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}

#ifndef __UBOOT__
static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	if (time_us <= 0) {
		sensor_log_err("Exposure time must be greater than than 0.");
		return MPI_FAILURE;
	}
	if (g_sensor_state[idx.path].row_time[0] <= 0 || g_sensor_state[idx.path].line_pixel[0] <= 0) {
		sensor_log_err("Internal parameters might not be correctly initialized.");
		return MPI_FAILURE;
	}

	int32_t exp_line = ((time_us << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	                   g_sensor_state[idx.path].row_time[0];
	int32_t frame_line = exp_line + EXP_LINE_GAP;
	if (frame_line <= 0) {
		sensor_log_err("Cannot correctly calculate line per frame.");
		return MPI_FAILURE;
	}
	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Exposure time or FPS exceeds hardware limit.");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	int32_t temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;

	frame_line *= 2;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = (frame_line & 0xF0000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	SENSOR_setInttime(idx, time_us, NULL);
	return MPI_SUCCESS;
}

static int32_t SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	dft->sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_sys_gain_range.max = 16383;
	dft->target_sys_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->target_sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 384;
	dft->gain_thr_down = 512;
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 7000;
	dft->exp_value = g_inttime * 32;
	return MPI_SUCCESS;
}

static int32_t SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	memcpy(dft, &dip_dft, sizeof(dip_dft));
	return MPI_SUCCESS;
}

static int32_t SENSOR_getAwbDefault(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *awb)
{
	/* TODO - fool proof design */
	memcpy(awb->k_table, &ct_tbl_dft[0], sizeof(MPI_AWB_COLOR_TEMP_S) * MPI_K_TABLE_ENTRY_NUM);
	memcpy(awb->delta_table, &delta_tbl_dft[0], sizeof(MPI_AWB_COLOR_DELTA_S) * MPI_K_TABLE_ENTRY_NUM);
	return MPI_SUCCESS;
}

static int32_t SENSOR_getBlackLevel(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level)
{
	int32_t array[11];
	for (int32_t i = 0; i < 11; i++) {
		array[i] = black_level_table.black_level[i];
	}

	int32_t black_level;
	uint32_t gain = g_sns_state[idx.path]->sensor_gain;
	gain = CLAMP(gain, k_sensor_gain_bin[0], k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1]);

	int32_t target_bin = binary_search_bin(gain, k_sensor_gain_bin, 0, MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1);
	int32_t norm = k_sensor_gain_bin[target_bin] - k_sensor_gain_bin[target_bin - 1];
	int32_t alpha = gain - k_sensor_gain_bin[target_bin - 1];
	black_level = interpolation(array[target_bin], array[target_bin - 1], alpha, norm);

	level->dbc_level = (uint16_t)black_level;
	return MPI_SUCCESS;
}

static int32_t SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
{
	/* TODO - fool proof design*/
	memcpy(cal, &cal_tbl_dft, sizeof(MPI_CAL_SNS_DEFAULT_S));
	return MPI_SUCCESS;
}
#endif

static int32_t SENSOR_regCallback(MPI_PATH idx)
{
	MPI_SNS_CALLBACK_S sensor_callback = {
		.dip =
		        {


		                .global_init = SENSOR_globalInit,
						.get_regs_info = SENSOR_getRegsInfo,
#ifndef __UBOOT__
						.init = SENSOR_configInit,
		                .get_sns_op_info = SENSOR_getOpInfo,
						.get_dip_default = SENSOR_getDipDefault,
		                .exit = SENSOR_configExit,
#endif
		        },
		.ae =
		        {

		                .set_framerate = SENSOR_setFramrate,
		                .set_inttime = SENSOR_setInttime,
		                .set_sensor_gain = SENSOR_setSensorGain,
#ifndef __UBOOT__
		                .set_slow_inttime = SENSOR_setSlowInttime,
		                .get_ae_default = SENSOR_getAeDefault,
#endif
		        },
#ifndef __UBOOT__
		.cal =
		        {
		                .get_black_level = SENSOR_getBlackLevel,
		                .get_cal_default = SENSOR_getCalDefault,
		        },
		.awb =
		        {
		                .get_awb_default = SENSOR_getAwbDefault,
		        },
#endif

	};
	MPI_regSnsCallback(idx, SENSOR_ID, &sensor_callback);
	return MPI_SUCCESS;
}

static int32_t SENSOR_deregSnsCallback(MPI_PATH idx)
{
	MPI_deregSnsCallback(idx, SENSOR_ID);
	return MPI_SUCCESS;
}

#ifdef SNS0
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS0_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};

#ifndef __UBOOT__
__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS0_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif
#endif

#ifdef SNS1
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS1_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};

#ifndef __UBOOT__
__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS1_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif
#endif
