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
#include "l_sensor_cal.h"
#include "sensor_settings.h"
#include "sensor_params.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#define SENSOR_ID (676) // sensor ID
#define IMX676_VMAX_ADDR1 (0x3028) // frame line [7:0]
#define IMX676_VMAX_ADDR2 (0x3029) // frame line [15:8]
#define IMX676_VMAX_ADDR3 (0x302A) // frame line [19:16]
#define IMX676_SHR0_ADDR1 (0x3050) // exposure line for long frame [7:0]
#define IMX676_SHR0_ADDR2 (0x3051) // exposure line for long frame [15:8]
#define IMX676_SHR0_ADDR3 (0x3052) // exposure line for long frame [19:16]
#define IMX676_SHR1_ADDR1 (0x3054) // exposure line for short frame [7:0]
#define IMX676_SHR1_ADDR2 (0x3055) // exposure line for short frame [15:8]
#define IMX676_SHR1_ADDR3 (0x3056) // exposure line for short frame [19:16]

#define IMX676_GAIN0_ADDR1 (0x3070) // gain for long frame [7:0]
#define IMX676_GAIN0_ADDR2 (0x3071) // gain for long frame [9:8], but have no use
#define IMX676_GAIN1_ADDR1 (0x3072) // gain for short frame [7:0]
#define IMX676_GAIN1_ADDR2 (0x3073) // gain for short frame [9:8], but have no use

#define EXP_LINE_GAP (10)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (4)
#define RHS1 (HDR_BLANK_LINE * 2 + 2)

#define IMX676_INT_ERROR (0)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (8) // support up to 0.01 frame rate precision
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_VMAX_3,
	IDX_SHR0_1,
	IDX_SHR0_2,
	IDX_SHR0_3,
	IDX_SHR1_1,
	IDX_SHR1_2,
	IDX_SHR1_3,
	IDX_GAIN0_1,
	IDX_GAIN1_1,
	IDX_NUM,
} I2C_DATA_IDX_E;

CUSTOM_SNS_STATE_S g_sensor_state;

// db = gain_bin * 0.3 (might differ from different sensors)
// gain_val = (10 ** (db / 20)) * 32
static int sony_gain_val[] = {
	32,     33,    34,    35,    37,    38,    39,    41,    42,     44,     45,     47,     48,     50,     52,
	54,     56,    58,    60,    62,    64,    66,    68,    71,     73,     76,     79,     81,     84,     87,
	90,     93,    97,    100,   104,   107,   111,   115,   119,    123,    127,    132,    137,    141,    146,
	151,    157,   162,   168,   174,   180,   186,   193,   200,    207,    214,    221,    229,    237,    246,
	254,    263,   272,   282,   292,   302,   313,   324,   335,    347,    359,    372,    385,    398,    412,
	427,    442,   457,   473,   490,   507,   525,   543,   563,    582,    603,    624,    646,    669,    692,
	716,    742,   768,   795,   823,   851,   881,   912,   944,    978,    1012,   1047,   1084,   1122,   1162,
	1203,   1245,  1289,  1334,  1381,  1429,  1480,  1532,  1585,   1641,   1699,   1759,   1820,   1884,   1951,
	2019,   2090,  2163,  2239,  2318,  2400,  2484,  2571,  2662,   2755,   2852,   2952,   3056,   3163,   3275,
	3390,   3509,  3632,  3760,  3892,  4029,  4170,  4317,  4468,   4625,   4788,   4956,   5130,   5311,   5497,
	5690,   5890,  6097,  6312,  6534,  6763,  7001,  7247,  7502,   7765,   8038,   8321,   8613,   8916,   9229,
	9553,   9889,  10236, 10596, 10969, 11354, 11753, 12166, 12594,  13036,  13494,  13969,  14459,  14968,  15494,
	16038,  16602, 17185, 17789, 18414, 19061, 19731, 20424, 21142,  21885,  22654,  23450,  24274,  25128,  26011,
	26925,  27871, 28850, 29864, 30914, 32000, 33125, 34289, 35494,  36741,  38032,  39369,  40752,  42184,  43667,
	45201,  46790, 48434, 50136, 51898, 53722, 55610, 57564, 59587,  61681,  63848,  66092,  68415,  70819,  73308,
	75884,  78551, 81311, 84169, 87126, 90188, 93358, 96638, 100035, 103550, 107189, 110956, 114855, 118891, 123069,
	127394,
};

#define SONY_BIN (sizeof(sony_gain_val) / sizeof(sony_gain_val[0]))

static int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
{
	MPI_SNS_REGS_TABLE_S *regs = g_sensor_state.regs_info;
	SensCmd cmd[MPI_SNS_TABLE_REGS_NUM];
	int cmd_len = 0;
	int ret;

	if (regs[0].is_config == false) {
		return MPI_SUCCESS;
	}

	for (int i = 0; i < regs[0].reg_num; ++i) {
		if (regs[0].i2c_data[i].is_update) {
			cmd[cmd_len].reg = regs->i2c_data[i].reg_addr;
			cmd[cmd_len].val = regs->i2c_data[i].reg_data;
			cmd_len++;
		}
	}

	if (cmd_len > 0) {
		ret = SENSOR_writeSeqWaddrBdata(i2c_fd, cmd_len, cmd, regs[0].i2c_data[0].dev_addr);
	}

	return ret;
}

static int SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sensor_state.regs_info;
	int i;

	(void)idx;

	if (NULL == regs) {
		sensor_log_err("Invalid data pointer.");
		return -EINVAL;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	for (i = 0; i < pregs[0].reg_num; ++i) {
		if (pregs[1].i2c_data[i].delay_frm_num > 0 && pregs[1].i2c_data[i].is_update) {
			regs->i2c_data[i] = pregs[1].i2c_data[i];
		}
	}
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	for (i = 0; i < pregs[0].reg_num; ++i) {
		pregs[0].i2c_data[i].is_update = false;
	}

	g_sensor_state.exp_line[1] = g_sensor_state.exp_line[0];
	g_sensor_state.frame_line[1] = g_sensor_state.frame_line[0];
	g_sensor_state.line_pixel[1] = g_sensor_state.line_pixel[0];

	return MPI_SUCCESS;
}

static void SENSOR_initRegs(MPI_PATH idx)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sensor_state.regs_info;
	int i;

	(void)idx;

	memset(g_sensor_state.regs_info, 0, sizeof(g_sensor_state.regs_info));

	pregs[0].bus_type = BUS_TYPE_I2C;
#ifdef SNS_I2C_1
	pregs[0].bus_sel.i2c_dev = 2;
#else
	pregs[0].bus_sel.i2c_dev = 1;
#endif
	pregs[0].cfg_delay_max = 2;
	pregs[0].reg_num = IDX_NUM;

	for (i = 0; i < pregs[0].reg_num; ++i) {
		pregs[0].i2c_data[i] = (MPI_I2C_DATA_S){
			.is_update = 0,
			.int_pos = 0,
			.delay_frm_num = 0,
			.dev_addr = SENSOR_I2C_SLAVE_ADDR,
			.reg_addr = 0,
			.reg_addr_byte_num = 2,
			.reg_data = 0,
			.reg_data_byte_num = 1,
		};
	}

	pregs[0].i2c_data[IDX_VMAX_1].reg_addr = IMX676_VMAX_ADDR1;
	pregs[0].i2c_data[IDX_VMAX_2].reg_addr = IMX676_VMAX_ADDR2;
	pregs[0].i2c_data[IDX_VMAX_3].reg_addr = IMX676_VMAX_ADDR3;

	pregs[0].i2c_data[IDX_SHR0_1].reg_addr = IMX676_SHR0_ADDR1;
	pregs[0].i2c_data[IDX_SHR0_2].reg_addr = IMX676_SHR0_ADDR2;
	pregs[0].i2c_data[IDX_SHR0_3].reg_addr = IMX676_SHR0_ADDR3;
	pregs[0].i2c_data[IDX_SHR1_1].reg_addr = IMX676_SHR1_ADDR1;
	pregs[0].i2c_data[IDX_SHR1_2].reg_addr = IMX676_SHR1_ADDR2;
	pregs[0].i2c_data[IDX_SHR1_3].reg_addr = IMX676_SHR1_ADDR3;

	pregs[0].i2c_data[IDX_GAIN0_1].reg_addr = IMX676_GAIN0_ADDR1;
	pregs[0].i2c_data[IDX_GAIN1_1].reg_addr = IMX676_GAIN1_ADDR1;

	pregs[0].is_config = true;

	pregs[1] = pregs[0];
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	int64_t tmp;

	(void)idx;

	g_sensor_state.sensor_gain = 32;
	g_sensor_state.pclk = PCLK;
	g_sensor_state.fps_line = INIT_FRAME_LINE;
	g_sensor_state.frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state.line_pixel[0] = INIT_LINE_LEN;

	tmp = (int64_t)(g_sensor_state.line_pixel[0] << ROW_TIME_PRC) * 1000000;
	g_sensor_state.row_time[0] = (tmp + g_sensor_state.pclk / 2) / g_sensor_state.pclk;

	// effc frame line = FSC - RHS1 = VMAX * 2 - RHS1
	g_sensor_state.exp_info[0].effective_frame_line = INIT_FRAME_LINE * 2 - RHS1;
	g_sensor_state.exp_info[0].exp_gap = EXP_LINE_GAP;
	// exp_max = FSC - RHS1 - GAP = VMAX * 2 - RHS1 - 10
	g_sensor_state.exp_info[0].hard_exp_max = SENSOR_FRAME_LINES_MAX * 2 - RHS1 - EXP_LINE_GAP;
	g_sensor_state.exp_info[0].hard_exp_max = g_sensor_state.exp_info[0].hard_exp_max / 4 * 4;
	g_sensor_state.exp_info[0].curr_exp_max = g_sensor_state.exp_info[0].effective_frame_line - EXP_LINE_GAP;
	g_sensor_state.exp_info[0].curr_exp_max = g_sensor_state.exp_info[0].curr_exp_max / 4 * 4;
	g_sensor_state.exp_info[0].exp_min = SENSOR_EXP_LINES_MIN;
	g_sensor_state.exp_info[0].exp_line = g_sensor_state.exp_info[0].curr_exp_max;
	g_sensor_state.exp_info[0].inttime =
	        (g_sensor_state.exp_info[0].exp_line * g_sensor_state.row_time[0] + ROW_TIME_UNIT - 1) >> ROW_TIME_PRC;
	g_sensor_state.exp_info[0].sensor_gain = 32;

	// effc frame line = RHS1 = HDR_BLANK_LINE * 2 + 2
	g_sensor_state.exp_info[1].effective_frame_line = RHS1;
	g_sensor_state.exp_info[1].exp_gap = EXP_LINE_GAP;
	// exp_max = RHS1 - GAP = HDR_BLANK_LINE * 2 - 8
	g_sensor_state.exp_info[1].hard_exp_max = RHS1 - EXP_LINE_GAP; // cannot be increased
	g_sensor_state.exp_info[1].curr_exp_max = g_sensor_state.exp_info[1].effective_frame_line - EXP_LINE_GAP;
	g_sensor_state.exp_info[1].exp_min = SENSOR_EXP_LINES_MIN;
	g_sensor_state.exp_info[1].exp_line = g_sensor_state.exp_info[1].curr_exp_max;
	g_sensor_state.exp_info[1].inttime =
	        (g_sensor_state.exp_info[1].exp_line * g_sensor_state.row_time[0] + ROW_TIME_UNIT - 1) >> ROW_TIME_PRC;
	g_sensor_state.exp_info[1].sensor_gain = 32;

	SENSOR_initRegs(idx);
}

static int32_t SENSOR_setInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, uint32_t *effective_time)
{
	if (!g_sensor_state.regs_info[0].is_config) {
		sensor_log_err("Internal data for path %d might not be correctly initialized.", idx.path);
		if (effective_time) {
			*effective_time = time_us;
		}
		return MPI_FAILURE;
	}

	// Input check
	if (image_idx >= HDR_IMAGE_NUM) {
		sensor_log_err("Invalid image index %u.", image_idx);
		return MPI_FAILURE;
	}

	// Calculate equivalent exposure line for sensor
	uint32_t row_time = g_sensor_state.row_time[0];
	// exp_line must be a multiple of 4
	uint32_t exp_line = (time_us << ROW_TIME_PRC) / row_time / 4 * 4;
	if (exp_line < g_sensor_state.exp_info[image_idx].exp_min) {
		sensor_log_warn("Exposure line (%d) for path %d is less than minimum limit (%d).",
		                exp_line, idx.path, g_sensor_state.exp_info[image_idx].exp_min);
	} else if (exp_line > g_sensor_state.exp_info[image_idx].hard_exp_max) {
		sensor_log_warn("Exposure line (%d) for path %d is greater than hard limit (%d).",
		                exp_line, idx.path, g_sensor_state.exp_info[image_idx].hard_exp_max);
	} else if (exp_line > g_sensor_state.exp_info[image_idx].curr_exp_max) {
		sensor_log_warn("Exposure line (%d) for path %d is greater than available line under current fps (%d).",
		                exp_line, idx.path, g_sensor_state.exp_info[image_idx].curr_exp_max);
	}
	exp_line = CLAMP(exp_line, g_sensor_state.exp_info[image_idx].exp_min,
	                 g_sensor_state.exp_info[image_idx].curr_exp_max);
	if (image_idx == 0) {
		g_sensor_state.exp_line[0] = exp_line;
	}

	// Update actual exposure time
	uint32_t real_inttime = (exp_line * row_time + ROW_TIME_UNIT - 1) >> ROW_TIME_PRC;
	g_sensor_state.exp_info[image_idx].inttime = real_inttime;
	if (effective_time) {
		*effective_time = real_inttime;
	}

	// Calculate register values
	MPI_I2C_DATA_S *i2c_data = g_sensor_state.regs_info[0].i2c_data;
	if (image_idx == 0) {
		// SHR0 = VMAX * 2 - exposure line
		uint32_t shr0 = g_sensor_state.frame_line[0] * 2 - exp_line;

		i2c_data[IDX_SHR0_1].reg_data = shr0 & 0xff;
		i2c_data[IDX_SHR0_1].is_update = true;
		i2c_data[IDX_SHR0_2].reg_data = (shr0 >> 8) & 0xff;
		i2c_data[IDX_SHR0_2].is_update = true;
		i2c_data[IDX_SHR0_3].reg_data = (shr0 >> 16) & 0x0f;
		i2c_data[IDX_SHR0_3].is_update = true;
	} else { // image_idx == 1
		// SHR1 = RHS1 - exposure line
		uint32_t shr1 = RHS1 - exp_line;

		i2c_data[IDX_SHR1_1].reg_data = shr1 & 0xff;
		i2c_data[IDX_SHR1_1].is_update = true;
		i2c_data[IDX_SHR1_2].reg_data = (shr1 >> 8) & 0xff;
		i2c_data[IDX_SHR1_2].is_update = true;
		i2c_data[IDX_SHR1_3].reg_data = (shr1 >> 16) & 0x0f;
		i2c_data[IDX_SHR1_3].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	return SENSOR_setInttimeHdr(idx, 0, time_us, effective_time);
}

static int32_t SENSOR_setSensorGainHdr(MPI_PATH idx, uint32_t image_idx, uint32_t gain)
{
	if (!g_sensor_state.regs_info[0].is_config) {
		sensor_log_err("Internal data for path %d might not be correctly initialized.", idx.path);
		return MPI_FAILURE;
	}

	// Input check
	if (image_idx >= HDR_IMAGE_NUM) {
		sensor_log_err("Invalid image index %u.", image_idx);
		return MPI_FAILURE;
	}
	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_warn("Sensor gain (%d) for path %d should be in range [%d, %d]",
		                gain, idx.path, SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
	}
	gain = CLAMP(gain, SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);

	// Look for the closest setting
	int gain_idx = binary_search_nr(gain, sony_gain_val, 0, SONY_BIN - 1);
	int lower_diff = gain - sony_gain_val[gain_idx];
	int upper_diff = sony_gain_val[gain_idx + 1] - gain;
	if (upper_diff < lower_diff) {
		gain_idx += 1;
	}

	// Update register values
	MPI_I2C_DATA_S *i2c_data = g_sensor_state.regs_info[0].i2c_data;
	if (image_idx == 0) {
		i2c_data[IDX_GAIN0_1].reg_data = gain_idx;
		i2c_data[IDX_GAIN0_1].is_update = true;
	} else { // image_idx == 1
		i2c_data[IDX_GAIN1_1].reg_data = gain_idx;
		i2c_data[IDX_GAIN1_1].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	return SENSOR_setSensorGainHdr(idx, 0, gain);
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime_range)
{
	if (!g_sensor_state.regs_info[0].is_config) {
		sensor_log_err("Internal data for path %d might not be correctly initialized.", idx.path);
		return MPI_FAILURE;
	}

	// Calculate frame line for new fps
	int fps_int = fps * FPS_UNIT;
	int32_t sec_line = ((g_sensor_state.pclk + (g_sensor_state.line_pixel[0] >> 1)) / g_sensor_state.line_pixel[0]);
	// frame line must be a multiple of 2
	// the final frame line is actually half of the real "line" because it's HDR
	int32_t new_frame_line = (sec_line << FPS_PRC) / fps_int / 4 * 2;

	// Check the limits
	if (new_frame_line < SENSOR_FRAME_LINES_MIN || new_frame_line > SENSOR_FRAME_LINES_MAX) {
		sensor_log_warn("New frame line (%d) for path %d is beyond the designed limits [%d, %d].",
		                new_frame_line, idx.path, SENSOR_FRAME_LINES_MIN, SENSOR_FRAME_LINES_MAX);
	}
	new_frame_line = CLAMP(new_frame_line, SENSOR_FRAME_LINES_MIN, SENSOR_FRAME_LINES_MAX);
	g_sensor_state.frame_line[0] = new_frame_line;

	// Update register values
	MPI_I2C_DATA_S *i2c_data = g_sensor_state.regs_info[0].i2c_data;
	i2c_data[IDX_VMAX_1].reg_data = new_frame_line & 0xff;
	i2c_data[IDX_VMAX_1].is_update = true;
	i2c_data[IDX_VMAX_2].reg_data = (new_frame_line >> 8) & 0xff;
	i2c_data[IDX_VMAX_2].is_update = true;
	i2c_data[IDX_VMAX_3].reg_data = (new_frame_line >> 16) & 0x0f;
	i2c_data[IDX_VMAX_3].is_update = true;

	// Update exposure settings again to make sure the setting is correct.
	// We only update long exposure here because we don't adjust the exposure limits for short exposure for now.
	// But it may not be true if we use virtual channel and update short exposure along with fps change.
	uint32_t new_exp_max = (uint32_t)(new_frame_line * 2 - RHS1 - g_sensor_state.exp_info[0].exp_gap);
	new_exp_max = new_exp_max / 4 * 4;
	g_sensor_state.exp_info[0].curr_exp_max = new_exp_max;
	uint32_t inttime_max = (new_exp_max * g_sensor_state.row_time[0] + ROW_TIME_UNIT - 1) >> ROW_TIME_PRC;
	if (g_sensor_state.exp_info[0].exp_line <= new_exp_max) {
		// Current exposure time is fine, just update the register again.
		SENSOR_setInttimeHdr(idx, 0, g_sensor_state.exp_info[0].inttime, NULL);
	} else {
		// Expected exposure time cannot be fit into new frame rate, need to calculate a new proper setting.
		uint32_t exp_val = g_sensor_state.exp_info[0].exp_line * g_sensor_state.exp_info[0].sensor_gain;
		uint32_t new_gain = (exp_val + (new_exp_max >> 1)) / new_exp_max;
		new_gain = CLAMP(new_gain, SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);

		SENSOR_setInttimeHdr(idx, 0, inttime_max, NULL);
		SENSOR_setSensorGainHdr(idx, 0, new_gain);
	}

	// Update inttime limits, this is also only for long exposure for now
	if (inttime_range) {
		uint32_t inttime_min =
		        (g_sensor_state.exp_info[0].exp_min * g_sensor_state.row_time[0] + ROW_TIME_UNIT - 1) >>
		        ROW_TIME_PRC;

		inttime_range->max = inttime_max;
		inttime_range->min = inttime_min;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, float *fps)
{
	if (!g_sensor_state.regs_info[0].is_config) {
		sensor_log_err("Internal data for path %d might not be correctly initialized.", idx.path);
		return MPI_FAILURE;
	}

	uint32_t frame_line_backup = g_sensor_state.frame_line[0];

	// We don't update frame rate for short exposure frame.
	if (image_idx != 0) {
		return SENSOR_setInttimeHdr(idx, image_idx, time_us, NULL);
	}

	// Calculate required exposure line, but we won't do protection on this value at this step.
	// exp_line must be a multiple of 4
	uint32_t exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state.row_time[0] / 4 * 4;

	// Calculate expected frame line if exp_line is greater than the minimum frame rate
	uint32_t new_frame_line = (exp_line + g_sensor_state.exp_info[0].exp_gap + RHS1) / 2;
	if (new_frame_line > SENSOR_FRAME_LINES_MAX) {
		sensor_log_warn("New frame line (%d) for path %d is greater than the designed limit (%d).",
		                new_frame_line, idx.path, SENSOR_FRAME_LINES_MAX);
	}
	new_frame_line = CLAMP(new_frame_line, SENSOR_FRAME_LINES_MIN, SENSOR_FRAME_LINES_MAX);
	g_sensor_state.frame_line[0] = new_frame_line;

	// Try to update inttime, but rollback if it fails.
	int ret = SENSOR_setInttimeHdr(idx, 0, time_us, NULL);
	if (ret != MPI_SUCCESS) {
		g_sensor_state.frame_line[0] = frame_line_backup;
		return MPI_FAILURE;
	}

	// Calculate new fps under current setting
	if (fps) {
		int32_t sec_line =
		        ((g_sensor_state.pclk + (g_sensor_state.line_pixel[0] >> 1)) / g_sensor_state.line_pixel[0]);
		// Real fps is half of (PCLK/HMAX/VMAX) because it's HDR
		int32_t new_fps_int = ((sec_line << FPS_PRC) + (new_frame_line >> 1)) / new_frame_line / 2;
		float new_fps = (float)new_fps_int / FPS_UNIT;

		*fps = new_fps;
	}

	// Update register values
	MPI_I2C_DATA_S *i2c_data = g_sensor_state.regs_info[0].i2c_data;
	i2c_data[IDX_VMAX_1].reg_data = new_frame_line & 0xff;
	i2c_data[IDX_VMAX_1].is_update = true;
	i2c_data[IDX_VMAX_2].reg_data = (new_frame_line >> 8) & 0xff;
	i2c_data[IDX_VMAX_2].is_update = true;
	i2c_data[IDX_VMAX_3].reg_data = (new_frame_line >> 16) & 0x0f;
	i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	return SENSOR_setSlowInttimeHdr(idx, 0, time_us, fps);
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->hdr.image_num = HDR_IMAGE_NUM;
	for (int i = 0; i < HDR_IMAGE_NUM; i++) {
		dft->hdr.hdr_inttime_range[i].max =
		        (g_sensor_state.exp_info[i].hard_exp_max * g_sensor_state.row_time[0] + ROW_TIME_UNIT - 1) >>
		        ROW_TIME_PRC;
		dft->hdr.hdr_inttime_range[i].min =
		        (g_sensor_state.exp_info[i].exp_min * g_sensor_state.row_time[0] + ROW_TIME_UNIT - 1) >>
		        ROW_TIME_PRC;
	}
	dft->inttime_range.max = dft->hdr.hdr_inttime_range[0].max;
	dft->inttime_range.min = dft->hdr.hdr_inttime_range[0].min;
	dft->sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 512;
	dft->gain_thr_down = 768;
	dft->max_fps = MAX_FPS;
	dft->min_fps = MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 5800;
	dft->exp_value = 528000;

	return MPI_SUCCESS;
}

static int SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	if (!dft) {
		sensor_log_err("Invalid data pointer for DIP default settings.");
		return MPI_FAILURE;
	}

	*dft = dip_dft;
	return MPI_SUCCESS;
}

static int SENSOR_getAwbDefault(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *awb)
{
	if (!awb) {
		sensor_log_err("Invalid data pointer for AWB default settings.");
		return MPI_FAILURE;
	}

	*awb = awb_tbl_dft;
	return MPI_SUCCESS;
}

static int SENSOR_getBlackLevel(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level)
{
	int32_t black_level;
	int gain;
	int gain_idx;

	if (!level) {
		sensor_log_err("Invalid data pointer for Black level.");
		return MPI_FAILURE;
	}

	gain = g_sensor_state.sensor_gain;
	gain = CLAMP(gain, k_sensor_gain_bin[0], k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1]);
	for (int i = 1; i < MPI_SENSOR_GAIN_LUT_ENTRY_NUM; i++) {
		if (k_sensor_gain_bin[i] >= gain) {
			gain_idx = i - 1;
			break;
		}
	}

	int norm = k_sensor_gain_bin[gain_idx] - k_sensor_gain_bin[gain_idx - 1];
	int alpha = gain - k_sensor_gain_bin[gain_idx - 1];
	black_level = interpolation(black_level_table[gain_idx], black_level_table[gain_idx - 1], alpha, norm);

	level->dbc_level = CLAMP(black_level, 0, 65535);

	return MPI_SUCCESS;
}

static int SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
{
	if (!cal) {
		sensor_log_err("Invalid data pointer for CAL default settings.");
		return MPI_FAILURE;
	}

	*cal = cal_tbl_dft;
	return MPI_SUCCESS;
}

static int SENSOR_regCallback(MPI_PATH idx)
{
	static MPI_SNS_CALLBACK_S sensor_callback = {
		.dip = {
			.init = SENSOR_configInit,
			.get_sns_op_info = SENSOR_getOpInfo,
			.global_init = SENSOR_globalInit,
			.get_dip_default = SENSOR_getDipDefault,
			.get_regs_info = SENSOR_getRegsInfo,
			.exit = SENSOR_configExit,
		},
		.cal = {
			.get_black_level = SENSOR_getBlackLevel,
			.get_cal_default = SENSOR_getCalDefault,
		},
		.ae = {
			.get_ae_default = SENSOR_getAeDefault,
			.set_framerate = SENSOR_setFramrate,
			.set_slow_inttime = SENSOR_setSlowInttime,
			.set_inttime = SENSOR_setInttime,
			.set_sensor_gain = SENSOR_setSensorGain,
			.set_slow_inttime_hdr = SENSOR_setSlowInttimeHdr,
			.set_inttime_hdr = SENSOR_setInttimeHdr,
			.set_sensor_gain_hdr = SENSOR_setSensorGainHdr,
		},
		.awb = {
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
