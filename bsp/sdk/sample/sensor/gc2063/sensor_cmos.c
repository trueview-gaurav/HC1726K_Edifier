/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor.h"
#include "l_sensor_cal.h"
#include "sensor_settings.h"
#include "sensor_params.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (2063) // sensor ID

#define GC2063_PAGE_ARRD (0xfe) // sensor register page

#define GC2063_SHS1_ADDR (0x03) // sensor exposure line control(shs1) [13:8]
#define GC2063_SHS2_ADDR (0x04) // sensor exposure line control(shs2) [7:0]

#define GC2063_A_GAIN_H_ADDR (0xb4) // sensor analog fine gain        [1:0] => [9:8]
#define GC2063_A_GAIN_L_ADDR (0xb3) // sensor analog coarse gain      [7:0] => [7:0]
#define GC2063_COL_GAIN_H_ADDR (0xb8) // sensor digital coarse gain   [5:0] => [11:6]. precision 6b.
#define GC2063_COL_GAIN_L_ADDR (0xb9) // sensor digital fine gain     [5:0] => [5:0]
#define GC2063_PRE_GAIN_H_ADDR (0xb1) // sensor precision coarse gain [3:0] => [9:6]
#define GC2063_PRE_GAIN_L_ADDR (0xb2) // sensor precision fine gain   [7:2] => [5:0]
/* 0xb1 and 0xb2 can be treated as a 12-bit digital gain ranging from 0 to 4095
 * that is, the actual gain is linearly related to this value
 * this value cannot be changed too fast
 * if you happen to make it too bright or too dark, you need to change this value gradually
 * like: 0 -> 1 -> 32 -> 256...
 * currently, 0xb1 will always be 0x01 and 0xb2 can vary by different gain level
 * so it's like a floating point number with 6 precision ranging from 1.0 to 1.984 (1+63/64)
 * this can be changed if need to align the sensor gain with other sensors
 * eg. if this sensor needs to be 3x brighter to catch up other sensors,
 * just multiply the following number by 3
 */
#define GC2063_PRE_GAIN_BASE (64)

#define GC2063_VMAX1_ADDR (0x41) // frame line [13:8]
#define GC2063_VMAX2_ADDR (0x42) // frame line [7:0]

#define EXP_LINE_GAP (16)
// #define SENSOR_FRAME_LINES_MAX (6744) // defined in sensor_params.h
// #define SENSOR_FRAME_LINES_MIN (1124)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1)
// #define SENSOR_WINDOW_LEGNTH (1108) // sensor window(1088) + black pixels(20)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

static uint8_t regValTable[29][4] = { //0xb4 0xb3 0xb8 0xb9
	{ 0x00, 0x00, 0x01, 0x00 }, { 0x00, 0x10, 0x01, 0x0c }, { 0x00, 0x20, 0x01, 0x1b }, { 0x00, 0x30, 0x01, 0x2c },
	{ 0x00, 0x40, 0x01, 0x3f }, { 0x00, 0x50, 0x02, 0x16 }, { 0x00, 0x60, 0x02, 0x35 }, { 0x00, 0x70, 0x03, 0x16 },
	{ 0x00, 0x80, 0x04, 0x02 }, { 0x00, 0x90, 0x04, 0x31 }, { 0x00, 0xa0, 0x05, 0x32 }, { 0x00, 0xb0, 0x06, 0x35 },
	{ 0x00, 0xc0, 0x08, 0x04 }, { 0x00, 0x5a, 0x09, 0x19 }, { 0x00, 0x83, 0x0b, 0x0f }, { 0x00, 0x93, 0x0d, 0x12 },
	{ 0x00, 0x84, 0x10, 0x00 }, { 0x00, 0x94, 0x12, 0x3a }, { 0x01, 0x2c, 0x1a, 0x02 }, { 0x01, 0x3c, 0x1b, 0x20 },
	{ 0x00, 0x8c, 0x20, 0x0f }, { 0x00, 0x9c, 0x26, 0x07 }, { 0x02, 0x64, 0x36, 0x21 }, { 0x02, 0x74, 0x37, 0x3a },
	{ 0x00, 0xc6, 0x3d, 0x02 }, { 0x00, 0xdc, 0x3f, 0x3f }, { 0x02, 0x85, 0x3f, 0x3f }, { 0x02, 0x95, 0x3f, 0x3f },
	{ 0x00, 0xce, 0x3f, 0x3f }
};

static uint32_t gainLevelTable[30] = { 64,   74,   89,   102,  127,  147,  177,  203,  260,  300,
	                               361,  415,  504,  581,  722,  832,  1027, 1182, 1408, 1621,
	                               1990, 2291, 2850, 3282, 4048, 5180, 5500, 6744, 7073, 0xffffffff };

static int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
{
	MPI_SNS_REGS_TABLE_S *regs = g_sns_state[path_idx]->regs_info;
	SensCmd cmd[32];
	int ret;

	if (regs[0].is_config == false) {
		return MPI_SUCCESS;
	}

	for (int i = 0; i < regs[0].reg_num; ++i) {
		cmd[i].reg = regs->i2c_data[i].reg_addr;
		cmd[i].val = regs->i2c_data[i].reg_data;
	}

	ret = SENSOR_writeSeqBaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[1].dev_addr);

	return ret;
}

static int SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[idx.path]->regs_info;
	int i;

	if (NULL == regs) {
		printf("invalid NULL pointer!\n");
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
		pregs[0].reg_num = 11;

		for (i = 0; i < pregs[0].reg_num; ++i) {
			pregs[0].i2c_data[i].is_update = true;
#ifdef DUAL_SENSOR_SUPPORT
			if (idx.path == 0) {
				pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			} else if (idx.path == 1) {
				pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR1;
			}
#else
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
#endif
			pregs[0].i2c_data[i].reg_addr_byte_num = 1;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[0].delay_frm_num = 0;
		pregs[0].i2c_data[0].reg_addr = GC2063_PAGE_ARRD;
		pregs[0].i2c_data[0].reg_data = 0x00;

		pregs[0].i2c_data[1].delay_frm_num = 0;
		pregs[0].i2c_data[1].reg_addr = GC2063_VMAX1_ADDR;
		pregs[0].i2c_data[2].delay_frm_num = 0;
		pregs[0].i2c_data[2].reg_addr = GC2063_VMAX2_ADDR;

		pregs[0].i2c_data[3].delay_frm_num = 0;
		pregs[0].i2c_data[3].reg_addr = GC2063_SHS1_ADDR;
		pregs[0].i2c_data[4].delay_frm_num = 0;
		pregs[0].i2c_data[4].reg_addr = GC2063_SHS2_ADDR;

		pregs[0].i2c_data[5].delay_frm_num = 0;
		pregs[0].i2c_data[5].reg_addr = GC2063_A_GAIN_H_ADDR;
		pregs[0].i2c_data[6].delay_frm_num = 0;
		pregs[0].i2c_data[6].reg_addr = GC2063_A_GAIN_L_ADDR;
		pregs[0].i2c_data[7].delay_frm_num = 0;
		pregs[0].i2c_data[7].reg_addr = GC2063_COL_GAIN_H_ADDR;
		pregs[0].i2c_data[8].delay_frm_num = 0;
		pregs[0].i2c_data[8].reg_addr = GC2063_COL_GAIN_L_ADDR;
		pregs[0].i2c_data[9].delay_frm_num = 0;
		pregs[0].i2c_data[9].reg_addr = GC2063_PRE_GAIN_H_ADDR;
		pregs[0].i2c_data[10].delay_frm_num = 0;
		pregs[0].i2c_data[10].reg_addr = GC2063_PRE_GAIN_L_ADDR;

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
	g_sensor_state[idx.path].sensor_gain = 32;
	g_sensor_state[idx.path].pclk = PCLK;
	g_sensor_state[idx.path].fps_line = INIT_FRAME_LINE;
	g_sensor_state[idx.path].frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state[idx.path].line_pixel[0] = INIT_LINE_LEN;

	int32_t tmp_pclk = (g_sensor_state[idx.path].pclk + (1 << 5)) >> (6);

	assert(tmp_pclk > 0 && "[Sensor Error] tmp_pclk must be greater than than 0.\n");
	g_sensor_state[idx.path].row_time[0] =
	        ((g_sensor_state[idx.path].line_pixel[0] * 500000) + (tmp_pclk >> 1)) / tmp_pclk;

	g_sensor_state[idx.path].exp_line[0] =
	        ((16500 << 5) + (g_sensor_state[idx.path].row_time[0] >> 1)) / g_sensor_state[idx.path].row_time[0];

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
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row time) must be greater than than 0.\n");

	int exp_line = (time_us << 5) / g_sensor_state[idx.path].row_time[0];

	if (exp_line > SENSOR_EXP_LINES_MAX || exp_line < SENSOR_EXP_LINES_MIN) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line = CLAMP(exp_line, SENSOR_EXP_LINES_MIN, SENSOR_EXP_LINES_MAX);
	}

	if (exp_line > g_sensor_state[idx.path].frame_line[0] - EXP_LINE_GAP) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = exp_line;
	*effective_time = (uint32_t)((exp_line * g_sensor_state[idx.path].row_time[0]) >> 5) + 1;
	g_inttime = *effective_time;

	int value = exp_line;

	g_sns_state[idx.path]->regs_info[0].i2c_data[3].reg_data = (value & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[4].reg_data = value & 0xFF;

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[3].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[4].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	uint32_t tol_dig_gain = 64;
	int32_t i = 0;
	g_sns_state[idx.path]->sensor_gain = gain;

	/* min gian = 32(1x), max gain = 3536(110.5x)*/
	if (gain < 32) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > 3536) {
		printf("[Sensor Error] Sensor gain bigger than 3536(sensor limit)\n");
		return MPI_FAILURE;
	} else if ((32 <= gain) && (gain < 3537)) {
		uint32_t total = 30;
		uint32_t gain_6b = gain << 1; //5b->6b

		for (i = 0; i < total; i++) {
			if ((gainLevelTable[i] <= gain_6b) && (gain_6b < gainLevelTable[i + 1]))
				break;
		}

		tol_dig_gain = gain_6b * GC2063_PRE_GAIN_BASE / gainLevelTable[i];
	} else {
		printf("[Sensor Error] Sensor gain impossible path\n");
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[5].reg_data = regValTable[i][0];
	g_sns_state[idx.path]->regs_info[0].i2c_data[6].reg_data = regValTable[i][1];
	g_sns_state[idx.path]->regs_info[0].i2c_data[7].reg_data = regValTable[i][2];
	g_sns_state[idx.path]->regs_info[0].i2c_data[8].reg_data = regValTable[i][3];
	g_sns_state[idx.path]->regs_info[0].i2c_data[9].reg_data = (tol_dig_gain >> 6);
	g_sns_state[idx.path]->regs_info[0].i2c_data[10].reg_data = ((tol_dig_gain & 0x3f) << 2);

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].is_update = true;
	for (int i = 5; i < 11; ++i) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[i].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	assert(fps > 0 && "[Sensor Error] FPS must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t sec_line; /* In one second, number of sensor can output lines */
	CUSTOM_SNS_STATE_S *sns_state = &(g_sensor_state[idx.path]); /* sensor state */

	fps = fps * 65536;
	sec_line = ((sns_state->pclk + (sns_state->line_pixel[0] >> 1)) / sns_state->line_pixel[0]) << 16;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");
	frame_line = (sec_line + ((int)fps >> 1)) / (int)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	inttime->max = (((frame_line - EXP_LINE_GAP) * sns_state->row_time[0] + (1 << 4)) >> 5) - 1;
	inttime->min = ((SENSOR_EXP_LINES_MIN * sns_state->row_time[0] + (1 << 4)) >> 5) + 1;
	sns_state->frame_line[0] = frame_line;

	uint32_t effective_time;
	if (sns_state->exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime->max, &effective_time);
	} else {
		SENSOR_setInttime(idx, g_inttime, &effective_time);
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[2].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int exp_line =
	        ((time_us << 5) + (g_sensor_state[idx.path].row_time[0] >> 1)) / g_sensor_state[idx.path].row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	g_sns_state[idx.path]->regs_info[0].i2c_data[1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[2].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[2].is_update = true;

	int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;

	uint32_t effective_time;
	SENSOR_setInttime(idx, time_us, &effective_time);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max = ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + 16) >> 5);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + 16) >> 5);
	dft->sensor_gain_range.max = 3536;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = 3536;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 2048;
	dft->gain_thr_down = 2176;
	dft->max_fps = (float)SENSOR_FPS;
	dft->min_fps = 5.0;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 5800;
	dft->exp_value = 528000;

	return MPI_SUCCESS;
}

static int SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	memcpy(dft, &dip_dft, sizeof(dip_dft));
	return MPI_SUCCESS;
}

static int SENSOR_getAwbDefault(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *awb)
{
	/* TODO - fool proof design */

	memcpy(awb->k_table, &ct_tbl_dft[0], sizeof(MPI_AWB_COLOR_TEMP_S) * MPI_K_TABLE_ENTRY_NUM);
	memcpy(awb->delta_table, &delta_tbl_dft[0], sizeof(MPI_AWB_COLOR_DELTA_S) * MPI_K_TABLE_ENTRY_NUM);

	return MPI_SUCCESS;
}

static int SENSOR_getBlackLevel(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level)
{
	int32_t array[11];

	for (int i = 0; i < 11; i++) {
		array[i] = black_level_table.black_level[i];
	}

	int32_t black_level;
	uint32_t gain = g_sns_state[idx.path]->sensor_gain;
	gain = CLAMP(gain, k_sensor_gain_bin[0], k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1]);

	int32_t target_bin = binary_search_bin(gain, k_sensor_gain_bin, 0, MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1);
	int norm = k_sensor_gain_bin[target_bin] - k_sensor_gain_bin[target_bin - 1];
	int alpha = gain - k_sensor_gain_bin[target_bin - 1];
	black_level = interpolation(array[target_bin], array[target_bin - 1], alpha, norm);

	level->dbc_level = (uint16_t)black_level;

	return MPI_SUCCESS;
}

static int SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
{
	/* TODO - fool proof design*/

	memcpy(cal, &cal_tbl_dft, sizeof(MPI_CAL_SNS_DEFAULT_S));

	return MPI_SUCCESS;
}

static int SENSOR_regCallback(MPI_PATH idx)
{
	MPI_SNS_CALLBACK_S sensor_callback = {
		.dip =
		        {
		                .init = SENSOR_configInit,
		                .get_sns_op_info = SENSOR_getOpInfo,
		                .global_init = SENSOR_globalInit,
		                .get_dip_default = SENSOR_getDipDefault,
		                .get_regs_info = SENSOR_getRegsInfo,
		                .exit = SENSOR_configExit,
		        },

		.cal =
		        {
		                .get_black_level = SENSOR_getBlackLevel,
		                .get_cal_default = SENSOR_getCalDefault,
		        },

		.ae =
		        {
		                .get_ae_default = SENSOR_getAeDefault,
		                .set_framerate = SENSOR_setFramrate,
		                .set_slow_inttime = SENSOR_setSlowInttime,
		                .set_inttime = SENSOR_setInttime,
		                .set_sensor_gain = SENSOR_setSensorGain,
		        },

		.awb =
		        {
		                .get_awb_default = SENSOR_getAwbDefault,
		        },
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

__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS0_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif

#ifdef SNS1
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS1_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};

__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS1_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif
