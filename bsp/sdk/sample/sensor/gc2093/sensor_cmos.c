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

#define SENSOR_ID (2093) // sensor ID

#define GC2093_VMAX1_ADDR (0x0041) // frame line [13:8]
#define GC2093_VMAX2_ADDR (0x0042) // frame line [7:0]

#define GC2093_SHS1_ADDR (0x0003) // sensor exposure line control(shs1) [13:8]
#define GC2093_SHS2_ADDR (0x0004) // sensor exposure line control(shs2) [7:0]

#define GC2093_AGAIN1_ADDR (0x00b3)
#define GC2093_AGAIN2_ADDR (0x00b8)
#define GC2093_AGAIN3_ADDR (0x00b9)
#define GC2093_AGAIN4_ADDR (0x0155)
#define GC2093_AGAIN5_ADDR (0x00c2)
#define GC2093_AGAIN6_ADDR (0x00cf)
#define GC2093_AGAIN7_ADDR (0x00d9)
#define GC2093_DGAIN1_ADDR (0x00b1)
#define GC2093_DGAIN2_ADDR (0x00b2)
#define GC2093_CTRL_ADDR (0x031d)

//#define LINE_FRAME_TOTAL (1125)

#define EXP_LINE_GAP (8)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1)
// #define SENSOR_WINDOW_LEGNTH (1108) // sensor window(1088) + black pixels(20)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

static uint8_t regValTable_30fps[25][7] = { //0xb3 0xb8 0xb9 0x155 0xc2 0xcf 0xd9
	{ 0x00, 0x01, 0x00, 0x08, 0x10, 0x08, 0x0a }, { 0x10, 0x01, 0x0c, 0x08, 0x10, 0x08, 0x0a },
	{ 0x20, 0x01, 0x1b, 0x08, 0x10, 0x08, 0x0a }, { 0x30, 0x01, 0x2c, 0x08, 0x11, 0x08, 0x0c },
	{ 0x40, 0x01, 0x3f, 0x08, 0x12, 0x08, 0x0e }, { 0x50, 0x02, 0x16, 0x08, 0x14, 0x08, 0x12 },
	{ 0x60, 0x02, 0x35, 0x08, 0x15, 0x08, 0x14 }, { 0x70, 0x03, 0x16, 0x08, 0x17, 0x08, 0x18 },
	{ 0x80, 0x04, 0x02, 0x08, 0x18, 0x08, 0x1a }, { 0x90, 0x04, 0x31, 0x08, 0x19, 0x08, 0x1c },
	{ 0xa0, 0x05, 0x32, 0x08, 0x1b, 0x08, 0x20 }, { 0xb0, 0x06, 0x35, 0x08, 0x1c, 0x08, 0x22 },
	{ 0xc0, 0x08, 0x04, 0x08, 0x1e, 0x08, 0x26 }, { 0x5a, 0x09, 0x19, 0x08, 0x1c, 0x08, 0x26 },
	{ 0x83, 0x0b, 0x0f, 0x08, 0x1c, 0x08, 0x26 }, { 0x93, 0x0d, 0x12, 0x08, 0x1f, 0x08, 0x28 },
	{ 0x84, 0x10, 0x00, 0x0b, 0x20, 0x08, 0x2a }, { 0x94, 0x12, 0x3a, 0x0b, 0x22, 0x08, 0x2e },
	{ 0x5d, 0x1a, 0x02, 0x0b, 0x27, 0x08, 0x38 }, { 0x9b, 0x1b, 0x20, 0x0b, 0x28, 0x08, 0x3a },
	{ 0x8c, 0x20, 0x0f, 0x0b, 0x2a, 0x08, 0x3e }, { 0x9c, 0x26, 0x07, 0x12, 0x2d, 0x08, 0x44 },
	{ 0xB6, 0x36, 0x21, 0x12, 0x2d, 0x08, 0x44 }, { 0xad, 0x37, 0x3a, 0x12, 0x2d, 0x08, 0x44 },
	{ 0xbd, 0x3d, 0x02, 0x12, 0x2d, 0x08, 0x44 }
};

static uint8_t regValTable_60fps[25][7] = {
	//0xb3 0xb8 0xb9 0x155 0xc2 0xcf 0xd9
	{ 0x00, 0x01, 0x00, 0x08, 0x10, 0x08, 0x0a }, { 0x10, 0x01, 0x0c, 0x08, 0x10, 0x08, 0x0a },
	{ 0x20, 0x01, 0x1b, 0x08, 0x11, 0x08, 0x0c }, { 0x30, 0x01, 0x2c, 0x08, 0x12, 0x08, 0x0e },
	{ 0x40, 0x01, 0x3f, 0x08, 0x14, 0x08, 0x12 }, { 0x50, 0x02, 0x16, 0x08, 0x15, 0x08, 0x14 },
	{ 0x60, 0x02, 0x35, 0x08, 0x17, 0x08, 0x18 }, { 0x70, 0x03, 0x16, 0x08, 0x18, 0x08, 0x1a },
	{ 0x80, 0x04, 0x02, 0x08, 0x1a, 0x08, 0x1e }, { 0x90, 0x04, 0x31, 0x08, 0x1b, 0x08, 0x20 },
	{ 0xa0, 0x05, 0x32, 0x08, 0x1d, 0x08, 0x24 }, { 0xb0, 0x06, 0x35, 0x08, 0x1e, 0x08, 0x26 },
	{ 0xc0, 0x08, 0x04, 0x08, 0x20, 0x08, 0x2a }, { 0x5a, 0x09, 0x19, 0x08, 0x1e, 0x08, 0x2a },
	{ 0x83, 0x0b, 0x0f, 0x08, 0x1f, 0x08, 0x2a }, { 0x93, 0x0d, 0x12, 0x08, 0x21, 0x08, 0x2e },
	{ 0x84, 0x10, 0x00, 0x0b, 0x22, 0x08, 0x30 }, { 0x94, 0x12, 0x3a, 0x0b, 0x24, 0x08, 0x34 },
	{ 0x5d, 0x1a, 0x02, 0x0b, 0x26, 0x08, 0x34 }, { 0x9b, 0x1b, 0x20, 0x0b, 0x26, 0x08, 0x34 },
	{ 0x8c, 0x20, 0x0f, 0x0b, 0x26, 0x08, 0x34 }, { 0x9c, 0x26, 0x07, 0x12, 0x26, 0x08, 0x34 },
	{ 0xB6, 0x36, 0x21, 0x12, 0x26, 0x08, 0x34 }, { 0xad, 0x37, 0x3a, 0x12, 0x26, 0x08, 0x34 },
	{ 0xbd, 0x3d, 0x02, 0x12, 0x26, 0x08, 0x34 },
};

static uint32_t gainLevelTable[26] = { 64,  76,  91,  107, 125,  147,  177,  211,  248,  297,  356,  425,  504,
	                               599, 709, 836, 978, 1153, 1647, 1651, 1935, 2292, 3239, 3959, 4686, 0xffffffff };

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_AGAIN_1,
	IDX_AGAIN_2,
	IDX_AGAIN_3,
	IDX_AGAIN_4,
	IDX_CTRL_1,
	IDX_AGAIN_5,
	IDX_AGAIN_6,
	IDX_AGAIN_7,
	IDX_CTRL_2,
	IDX_DGAIN_1,
	IDX_DGAIN_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

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

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[1].dev_addr);

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

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = GC2093_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = GC2093_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = GC2093_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = GC2093_SHS2_ADDR;

		pregs[0].i2c_data[IDX_AGAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_1].reg_addr = GC2093_AGAIN1_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_2].reg_addr = GC2093_AGAIN2_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_3].reg_addr = GC2093_AGAIN3_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_4].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_4].reg_addr = GC2093_AGAIN4_ADDR;
		pregs[0].i2c_data[IDX_CTRL_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_CTRL_1].reg_addr = GC2093_CTRL_ADDR;
		pregs[0].i2c_data[IDX_CTRL_1].reg_data = 0x2d;
		pregs[0].i2c_data[IDX_AGAIN_5].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_5].reg_addr = GC2093_AGAIN5_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_6].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_6].reg_addr = GC2093_AGAIN6_ADDR;
		pregs[0].i2c_data[IDX_AGAIN_7].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN_7].reg_addr = GC2093_AGAIN7_ADDR;
		pregs[0].i2c_data[IDX_CTRL_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_CTRL_2].reg_addr = GC2093_CTRL_ADDR;
		pregs[0].i2c_data[IDX_CTRL_1].reg_data = 0x28;
		pregs[0].i2c_data[IDX_DGAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DGAIN_1].reg_addr = GC2093_DGAIN1_ADDR;
		pregs[0].i2c_data[IDX_DGAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DGAIN_2].reg_addr = GC2093_DGAIN2_ADDR;
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
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row time) must be greater than than 0.\n");

	int exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];

	if (exp_line > SENSOR_EXP_LINES_MAX || exp_line < SENSOR_EXP_LINES_MIN) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line = CLAMP(exp_line, SENSOR_EXP_LINES_MIN, SENSOR_EXP_LINES_MAX);
	}

	if (exp_line > g_sensor_state[idx.path].frame_line[0] - EXP_LINE_GAP) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = exp_line;
	uint32_t time_tmp = (uint32_t)((exp_line * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC);
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (exp_line & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = exp_line & 0xFF;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	uint32_t tol_dig_gain = 64;
	int32_t i = 0;

	if (gain < 32) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > SENSOR_MAX_GAIN) {
		printf("[Sensor Error] Sensor gain bigger than %d(sensor limit)\n", SENSOR_MAX_GAIN);
		return MPI_FAILURE;
	}
	g_sns_state[idx.path]->sensor_gain = gain;

	gain *= 2;
	while (gainLevelTable[i + 1] <= gain) {
		i++;
	}
	tol_dig_gain = (gain * 64 + gainLevelTable[i] / 2) / gainLevelTable[i];

	if (SENSOR_FPS == 30) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_1].reg_data = regValTable_30fps[i][0];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_2].reg_data = regValTable_30fps[i][1];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_3].reg_data = regValTable_30fps[i][2];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_4].reg_data = regValTable_30fps[i][3];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_5].reg_data = regValTable_30fps[i][4];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_6].reg_data = regValTable_30fps[i][5];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_7].reg_data = regValTable_30fps[i][6];
	} else if (SENSOR_FPS == 60) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_1].reg_data = regValTable_60fps[i][0];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_2].reg_data = regValTable_60fps[i][1];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_3].reg_data = regValTable_60fps[i][2];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_4].reg_data = regValTable_60fps[i][3];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_5].reg_data = regValTable_60fps[i][4];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_6].reg_data = regValTable_60fps[i][5];
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_7].reg_data = regValTable_60fps[i][6];
	} else {
		assert(0);
	}
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_1].reg_data = (tol_dig_gain >> 6);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_2].reg_data = ((tol_dig_gain & 0x3f) << 2);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_3].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_4].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CTRL_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_5].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_6].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_7].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CTRL_2].is_update = true;
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
	uint32_t line_pixel = g_sensor_state[idx.path].line_pixel[0];
	uint32_t row_time = g_sensor_state[idx.path].row_time[0];
	uint32_t pclk = g_sensor_state[idx.path].pclk;
	uint32_t inttime_max;
	uint32_t inttime_min;
	CUSTOM_SNS_STATE_S *sns_state = &(g_sensor_state[idx.path]); /* sensor state */

	fps = fps * FPS_UNIT;
	sec_line = (pclk + (line_pixel >> 1)) / line_pixel;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");
	frame_line = ((sec_line << FPS_PRC) + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);
	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}
	sns_state->frame_line[0] = frame_line;

	inttime_max = ((frame_line - EXP_LINE_GAP) * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC;
	inttime_min = ((SENSOR_EXP_LINES_MIN * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC) + 1;
	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}

	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime_max, NULL);
	} else {
		SENSOR_setInttime(idx, g_inttime, NULL);
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int exp_line = ((time_us << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	               g_sensor_state[idx.path].row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if (frame_line < SENSOR_FRAME_LINES_MIN) {
		frame_line = SENSOR_FRAME_LINES_MIN;
	}
	if (frame_line > SENSOR_FRAME_LINES_MAX) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;

	SENSOR_setInttime(idx, time_us, NULL);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	dft->sensor_gain_range.max = 16383;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 16383;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = 16383;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 256;
	dft->gain_thr_down = 512;
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
