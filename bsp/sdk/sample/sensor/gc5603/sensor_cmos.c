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
#include <assert.h>

#include "l_sensor_cal.h"
#endif
#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (5603) // sensor ID

// VMAX_AUX = VMAX -32
#define GC5603_VMAX1_AUX_ADDR (0x0259) // should modify these with VMAX
#define GC5603_VMAX2_AUX_ADDR (0x025A)

#define GC5603_VMAX1_ADDR (0x0340) // frame length [13:8]
#define GC5603_VMAX2_ADDR (0x0341) // frame length [7:0]

#define GC5603_SHS1_ADDR (0x0202) // shutter time [13:8], sensor exposure line control(shs1)
#define GC5603_SHS2_ADDR (0x0203) // shutter time [7:0],  sensor exposure line control(shs2)

#define GC5603_AGAIN1_ADDR (0x0614)
#define GC5603_AGAIN2_ADDR (0x0615)
#define GC5603_AGAIN3_ADDR (0x0225)
#define GC5603_AGAIN4_ADDR (0x1467)
#define GC5603_AGAIN5_ADDR (0x1468)
#define GC5603_AGAIN6_ADDR (0x00B8)
#define GC5603_AGAIN7_ADDR (0x00B9)
#define GC5603_DGAIN1_ADDR (0x0064)
#define GC5603_DGAIN2_ADDR (0x0065)

#define EXP_LINE_GAP (52 + 0x10) // Sensor Datasheet spec 7.9,  VB is 0x10
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2) // Line 1 IQ is horrible, set to 2 for better IQ
#define SENSOR_EXP_LINE_SHIF (0)

#define ROW_TIME_PRC (5) // Significant Figures, This value is relevant to the calculation and should not be modified.
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (16) // Significant Figures, This value is relevant to the calculation and should not be modified.
#define FPS_UNIT (1 << FPS_PRC)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

//0614, 0615, 0225, 1467  1468, 00b8, 00b9
static uint8_t regValTable_30fps[26][7] = {
	{ 0x00, 0x00, 0x04, 0x15, 0x15, 0x01, 0x00 }, { 0x90, 0x02, 0x04, 0x15, 0x15, 0x01, 0x0A },
	{ 0x00, 0x00, 0x00, 0x15, 0x15, 0x01, 0x12 }, { 0x90, 0x02, 0x00, 0x15, 0x15, 0x01, 0x20 },
	{ 0x01, 0x00, 0x00, 0x15, 0x15, 0x01, 0x30 }, { 0x91, 0x02, 0x00, 0x15, 0x15, 0x02, 0x05 },
	{ 0x02, 0x00, 0x00, 0x15, 0x15, 0x02, 0x19 }, { 0x92, 0x02, 0x00, 0x16, 0x16, 0x02, 0x3F },
	{ 0x03, 0x00, 0x00, 0x16, 0x16, 0x03, 0x20 }, { 0x93, 0x02, 0x00, 0x17, 0x17, 0x04, 0x0A },
	{ 0x00, 0x00, 0x01, 0x18, 0x18, 0x05, 0x02 }, { 0x90, 0x02, 0x01, 0x19, 0x19, 0x05, 0x39 },
	{ 0x01, 0x00, 0x01, 0x19, 0x19, 0x06, 0x3C }, { 0x91, 0x02, 0x01, 0x19, 0x19, 0x08, 0x0D },
	{ 0x02, 0x00, 0x01, 0x1a, 0x1a, 0x09, 0x21 }, { 0x92, 0x02, 0x01, 0x1a, 0x1a, 0x0B, 0x0F },
	{ 0x03, 0x00, 0x01, 0x1c, 0x1c, 0x0D, 0x17 }, { 0x93, 0x02, 0x01, 0x1c, 0x1c, 0x0F, 0x33 },
	{ 0x04, 0x00, 0x01, 0x1d, 0x1d, 0x12, 0x30 }, { 0x94, 0x02, 0x01, 0x1d, 0x1d, 0x16, 0x10 },
	{ 0x05, 0x00, 0x01, 0x1e, 0x1e, 0x1A, 0x19 }, { 0x95, 0x02, 0x01, 0x1e, 0x1e, 0x1F, 0x13 },
	{ 0x06, 0x00, 0x01, 0x20, 0x20, 0x25, 0x08 }, { 0x96, 0x02, 0x01, 0x20, 0x20, 0x2C, 0x03 },
	{ 0xb6, 0x04, 0x01, 0x20, 0x20, 0x34, 0x0F }, { 0x86, 0x06, 0x01, 0x20, 0x20, 0x3D, 0x3D },
};

// use 64 as base, 3965 max
static uint32_t analogGainTable[27] = { 64,   74,   82,   96,   112,  133,  153,  191,  224,
	                                266,  322,  377,  444,  525,  609,  719,  855,  1011,
	                                1200, 1424, 1689, 2003, 2376, 2819, 3343, 3965, 0xffffffff };

typedef enum {
	IDX_VMAX1_AUX,
	IDX_VMAX2_AUX,
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_AGAIN_CONTROL_1,
	IDX_AGAIN_1,
	IDX_AGAIN_2,
	IDX_AGAIN_3,
	IDX_AGAIN_CONTROL_2,
	IDX_AGAIN_4,
	IDX_AGAIN_5,
	IDX_AGAIN_6,
	IDX_AGAIN_7,
	IDX_DGAIN_1,
	IDX_DGAIN_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int32_t g_inttime = 16500;
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

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[IDX_VMAX_1].dev_addr);
	return ret;
}
#endif

static int32_t SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[idx.path]->regs_info;
	int i;

	if (NULL == regs) {
		printf("invalid NULL pointer!\n");
		return -EINVAL;
	}

	if (false == pregs[0].is_config) {
		pregs[0].bus_type = BUS_TYPE_I2C;
		pregs[0].bus_sel.i2c_dev = 1;
		pregs[0].cfg_delay_max = 2;
		pregs[0].reg_num = IDX_NUM;

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
			pregs[0].i2c_data[i].reg_addr_byte_num = 2;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[IDX_VMAX1_AUX].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX1_AUX].reg_addr = GC5603_VMAX1_AUX_ADDR;
		pregs[0].i2c_data[IDX_VMAX2_AUX].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX2_AUX].reg_addr = GC5603_VMAX2_AUX_ADDR;

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = GC5603_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = GC5603_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = GC5603_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = GC5603_SHS2_ADDR;

		pregs[0].i2c_data[IDX_AGAIN_CONTROL_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_CONTROL_1].reg_addr = 0x031D;
		pregs[0].i2c_data[IDX_AGAIN_CONTROL_1].reg_data = 0x2D;

		pregs[0].i2c_data[IDX_AGAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_1].reg_addr = GC5603_AGAIN1_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_2].reg_addr = GC5603_AGAIN2_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_3].reg_addr = GC5603_AGAIN3_ADDR;

		pregs[0].i2c_data[IDX_AGAIN_CONTROL_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_CONTROL_2].reg_addr = 0x031D;
		pregs[0].i2c_data[IDX_AGAIN_CONTROL_2].reg_data = 0x28;

		pregs[0].i2c_data[IDX_AGAIN_4].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_4].reg_addr = GC5603_AGAIN4_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_5].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_5].reg_addr = GC5603_AGAIN5_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_6].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_6].reg_addr = GC5603_AGAIN6_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_7].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_7].reg_addr = GC5603_AGAIN7_ADDR;
		pregs[0].i2c_data[IDX_DGAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DGAIN_1].reg_addr = GC5603_DGAIN1_ADDR;
		pregs[0].i2c_data[IDX_DGAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DGAIN_2].reg_addr = GC5603_DGAIN2_ADDR;
		pregs[0].is_config = true;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	for (i = 0; i < IDX_NUM; i++) {
		switch (pregs[0].i2c_data[i].delay_frm_num) {
		case 1:
			memcpy(&regs->i2c_data[i], &pregs[1].i2c_data[i], sizeof(MPI_I2C_DATA_S));
			break;
		default:;
		}
	}
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

	int32_t tmp_pclk = (g_sensor_state[idx.path].pclk + (1 << ROW_TIME_PRC)) >> (ROW_TIME_PRC + 1);

	assert(tmp_pclk > 0 && "[Sensor Error] tmp_pclk must be greater than than 0.\n");
	g_sensor_state[idx.path].row_time[0] =
	        ((g_sensor_state[idx.path].line_pixel[0] * 500000) + (tmp_pclk >> 1)) / tmp_pclk;

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
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row time) must be greater than than 0.\n");
	//exp_line_addr value = exp_line * 2
	int32_t line_shif = SENSOR_EXP_LINE_SHIF;
	int32_t exp_line_x2 = (time_us << (ROW_TIME_PRC + line_shif)) / g_sensor_state[idx.path].row_time[0];

	//exp_line_addr value max = fps_line * 2 - EXP_LINE_GAP
	if (exp_line_x2 > (SENSOR_EXP_LINES_MAX << line_shif) || (exp_line_x2 < (SENSOR_EXP_LINES_MIN << line_shif))) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line_x2 =
		        CLAMP(exp_line_x2, (SENSOR_EXP_LINES_MIN << line_shif), (SENSOR_EXP_LINES_MAX << line_shif));
	}

	if (exp_line_x2 > (g_sensor_state[idx.path].frame_line[0] << line_shif) - (EXP_LINE_GAP << line_shif)) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = (exp_line_x2 >> line_shif);
	uint32_t time_tmp = (uint32_t)exp_line_x2 * g_sensor_state[idx.path].row_time[0];
	time_tmp = (time_tmp + (1 << (ROW_TIME_PRC + line_shif - 1))) >> (ROW_TIME_PRC + line_shif);
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	int32_t value = exp_line_x2;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = (value & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	g_sns_state[idx.path]->sensor_gain = gain;

	uint32_t aGain = gain << 1;
	uint8_t i;
	uint8_t total;
	uint32_t tol_dig_gain = 0;

	if (gain < SENSOR_GAIN_MIN) {
		printf("[Sensor Error] Sensor gain must be greater than %d\n", SENSOR_GAIN_MIN);
		return -EINVAL;
	} else if (gain > SENSOR_GAIN_MAX) {
		printf("[Sensor Error] Sensor gain must be lesser than %d (sensor limit)\n", SENSOR_GAIN_MAX);
		return -EINVAL;
	}

	// GC FAE supply.
	total = sizeof(analogGainTable) / sizeof(UINT32);

	for (i = 0; i < total; i++) {
		if ((analogGainTable[i] <= aGain) && (aGain < analogGainTable[i + 1])) {
			break;
		}
	}

	tol_dig_gain = aGain * 64 / analogGainTable[i];

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_1].reg_data = regValTable_30fps[i][0];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_2].reg_data = regValTable_30fps[i][1];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_3].reg_data = regValTable_30fps[i][2];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_4].reg_data = regValTable_30fps[i][3];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_5].reg_data = regValTable_30fps[i][4];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_6].reg_data = regValTable_30fps[i][5];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_7].reg_data = regValTable_30fps[i][6];

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_1].reg_data = (tol_dig_gain >> 6);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_2].reg_data = ((tol_dig_gain & 0x3f) << 2);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_CONTROL_1].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_3].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_CONTROL_2].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_4].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_5].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_6].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_7].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_2].is_update = true;

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
	uint32_t inttime_max;
	uint32_t inttime_min;

	fps = fps * FPS_UNIT;
	sec_line = ((g_sensor_state[idx.path].pclk + (g_sensor_state[idx.path].line_pixel[0] >> 1)) /
	            g_sensor_state[idx.path].line_pixel[0])
	           << FPS_PRC;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");
	frame_line = (sec_line + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	inttime_max = (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >>
	               ROW_TIME_PRC);
	inttime_min =
	        ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}
	uint32_t effective_time;
	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime_max, &effective_time);
	} else {
		SENSOR_setInttime(idx, g_inttime, &effective_time);
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX1_AUX].reg_data = ((frame_line - 32) & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX2_AUX].reg_data = ((frame_line - 32) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX1_AUX].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX2_AUX].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	return MPI_SUCCESS;
}

#ifndef __UBOOT__
static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int32_t exp_line = ((time_us << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	                   g_sensor_state[idx.path].row_time[0];
	int32_t frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if (frame_line < SENSOR_FRAME_LINES_MIN) {
		frame_line = SENSOR_FRAME_LINES_MIN;
	}
	if (frame_line > SENSOR_FRAME_LINES_MAX) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX1_AUX].reg_data = ((frame_line - 32) & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX2_AUX].reg_data = ((frame_line - 32) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX1_AUX].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX2_AUX].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	int32_t temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;

	uint32_t effective_time;
	SENSOR_setInttime(idx, time_us, &effective_time);

	return MPI_SUCCESS;
}

static int32_t SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	dft->sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->target_sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 256;
	dft->gain_thr_down = 512;
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = (float)MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 7400;
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

static int SENSOR_regCallback(MPI_PATH idx)
{
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
