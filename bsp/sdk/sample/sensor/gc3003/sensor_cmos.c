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

#define SENSOR_ID (3003) // sensor ID

#define GC3003_VMAX1_ADDR (0x0d41) // frame line [15:8]
#define GC3003_VMAX2_ADDR (0x0d42) // frame line [7:0]

#define GC3003_SHS1_ADDR (0x0d03) // sensor exposure line control(shs1) [13:8]
#define GC3003_SHS2_ADDR (0x0d04) // sensor exposure line control(shs2) [7:0]

#define GC3003_PGA_GAIN_1 (0x00d1) // [13:8]
#define GC3003_PGA_GAIN_2 (0x00d0) // [7:0]

#define GC3003_COL_GAIN_1 (0x00b8) // [11:6]
#define GC3003_COL_GAIN_2 (0x00b9) // [5:0]

#define GC3003_CTRL_GAIN_A (0x0155)
#define GC3003_CTRL_GAIN_B (0x006E)
#define GC3003_CTRL_GAIN_C (0x0080)

#define GC3003_PRE_GAIN_1 (0x00b1) // [9:6]
#define GC3003_PRE_GAIN_2 (0x00b2) // [5:0]

#define GC3003_PRE_GAIN_BASE (64)

#define EXP_LINE_GAP (16)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

// From IDX_PGA_GAIN_1 to IDX_PRE_GAIN_2, these IDX should not change order
typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_PGA_GAIN_1, // begin: do not change order
	IDX_PGA_GAIN_2,
	IDX_COL_GAIN_1,
	IDX_COL_GAIN_2,
	IDX_CTRL_GAIN_1,
	IDX_CTRL_GAIN_2,
	IDX_CTRL_GAIN_3,
	IDX_PRE_GAIN_1,
	IDX_PRE_GAIN_2, // end: do not change order
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

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
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = GC3003_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = GC3003_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = GC3003_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = GC3003_SHS2_ADDR;

		pregs[0].i2c_data[IDX_PGA_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PGA_GAIN_1].reg_addr = GC3003_PGA_GAIN_1;
		pregs[0].i2c_data[IDX_PGA_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PGA_GAIN_2].reg_addr = GC3003_PGA_GAIN_2;
		pregs[0].i2c_data[IDX_COL_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_COL_GAIN_1].reg_addr = GC3003_COL_GAIN_1;
		pregs[0].i2c_data[IDX_COL_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_COL_GAIN_2].reg_addr = GC3003_COL_GAIN_2;
		pregs[0].i2c_data[IDX_CTRL_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_CTRL_GAIN_1].reg_addr = GC3003_CTRL_GAIN_A;
		pregs[0].i2c_data[IDX_CTRL_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_CTRL_GAIN_2].reg_addr = GC3003_CTRL_GAIN_B;
		pregs[0].i2c_data[IDX_CTRL_GAIN_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_CTRL_GAIN_3].reg_addr = GC3003_CTRL_GAIN_C;
		pregs[0].i2c_data[IDX_PRE_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PRE_GAIN_1].reg_addr = GC3003_PRE_GAIN_1;
		pregs[0].i2c_data[IDX_PRE_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PRE_GAIN_2].reg_addr = GC3003_PRE_GAIN_2;
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
	int value = exp_line_x2;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = (value & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	if (gain < SENSOR_GAIN_MIN) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > SENSOR_GAIN_MAX) {
		printf("[Sensor Error] Sensor gain bigger than 3536(sensor limit)\n");
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->sensor_gain = gain;

	const uint8_t regValTable[25][7] = {
		//00d1,00d0,00b8,00b9,0155,006e,0080
		{ 0x00, 0x00, 0x01, 0x00, 0x04, 0x03, 0x09 }, //  1.00
		{ 0x0A, 0x00, 0x01, 0x0c, 0x04, 0x03, 0x0b }, //  1.18
		{ 0x00, 0x01, 0x01, 0x1a, 0x04, 0x03, 0x0d }, //  1.40
		{ 0x0A, 0x01, 0x01, 0x2a, 0x04, 0x04, 0x10 }, //  1.65
		{ 0x20, 0x00, 0x02, 0x00, 0x04, 0x05, 0x17 }, //  2.00
		{ 0x25, 0x00, 0x02, 0x18, 0x04, 0x06, 0x1e }, //  2.37
		{ 0x20, 0x01, 0x02, 0x33, 0x04, 0x07, 0x22 }, //  2.79
		{ 0x25, 0x01, 0x03, 0x14, 0x04, 0x08, 0x28 }, //  3.31
		{ 0x30, 0x00, 0x04, 0x00, 0x04, 0x08, 0x2c }, //  4.00
		{ 0x32, 0x80, 0x04, 0x2f, 0x04, 0x08, 0x2e }, //  4.73
		{ 0x30, 0x01, 0x05, 0x26, 0x04, 0x08, 0x2f }, //  5.59
		{ 0x32, 0x81, 0x06, 0x29, 0x04, 0x08, 0x30 }, //  6.64
		{ 0x38, 0x00, 0x08, 0x00, 0x04, 0x07, 0x2f }, //  8.00
		{ 0x39, 0x40, 0x09, 0x1f, 0x06, 0x07, 0x2e }, //  9.48
		{ 0x38, 0x01, 0x0b, 0x0d, 0x06, 0x06, 0x2b }, //  11.18
		{ 0x39, 0x41, 0x0d, 0x12, 0x06, 0x04, 0x24 }, //  13.25
		{ 0x30, 0x08, 0x10, 0x00, 0x06, 0x03, 0x27 }, //  16.00
		{ 0x32, 0x88, 0x12, 0x3e, 0x06, 0x03, 0x29 }, //  18.96
		{ 0x30, 0x09, 0x16, 0x1a, 0x06, 0x03, 0x2a }, //  22.40
		{ 0x32, 0x89, 0x1a, 0x23, 0x06, 0x03, 0x2d }, //  26.54
		{ 0x38, 0x08, 0x20, 0x00, 0x06, 0x03, 0x31 }, //  32.00
		{ 0x39, 0x48, 0x25, 0x3b, 0x09, 0x03, 0x36 }, //  37.92
		{ 0x38, 0x09, 0x2c, 0x33, 0x0b, 0x03, 0x3a }, //  44.76
		{ 0x39, 0x49, 0x35, 0x06, 0x0d, 0x03, 0x3c }, //  53.01
		{ 0x38, 0x0A, 0x3f, 0x3f, 0x0f, 0x03, 0x3f }, //  64.00
	};

	const uint32_t gainLevelTable[26] = {
		64,  76,  90,  106,  128,  152,  179,  212,  256,  303,  358,  425,  512,
		607, 717, 849, 1024, 1213, 1434, 1699, 2048, 2427, 2867, 3398, 4096, 0xffffffff,
	};

	const uint32_t total = sizeof(gainLevelTable) / sizeof(gainLevelTable[0]);
	const uint32_t gain_6b = gain << 1; //5b->6b

	int32_t i = 0;
	for (i = 0; i < total; i++) {
		if ((gainLevelTable[i] <= gain_6b) && (gain_6b < gainLevelTable[i + 1]))
			break;
	}

	uint32_t tol_dig_gain = gain_6b * GC3003_PRE_GAIN_BASE / gainLevelTable[i];

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PGA_GAIN_1].reg_data = regValTable[i][0];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PGA_GAIN_2].reg_data = regValTable[i][1];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_COL_GAIN_1].reg_data = regValTable[i][2];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_COL_GAIN_2].reg_data = regValTable[i][3];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CTRL_GAIN_1].reg_data = regValTable[i][4];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CTRL_GAIN_2].reg_data = regValTable[i][5];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CTRL_GAIN_3].reg_data = regValTable[i][6];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PRE_GAIN_1].reg_data = (tol_dig_gain >> 6);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PRE_GAIN_2].reg_data = ((tol_dig_gain & 0x3f) << 2);

	for (i = IDX_PGA_GAIN_1; i <= IDX_PRE_GAIN_2; ++i) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[i].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramerate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	assert(fps > 0 && "[Sensor Error] FPS must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t sec_line; /* In one second, number of sensor can output lines */

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

	inttime->max = (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >>
	                ROW_TIME_PRC);
	inttime->min =
	        ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);

	uint32_t effective_time;
	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime->max, &effective_time);
	} else {
		SENSOR_setInttime(idx, g_inttime, &effective_time);
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

	int32_t exp_line = ((time_us << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	                   g_sensor_state[idx.path].row_time[0];
	int32_t frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data =
	        (g_sensor_state[idx.path].frame_line[0] & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data =
	        (g_sensor_state[idx.path].frame_line[0] & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	int32_t temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	if (fps) {
		*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;
	}
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
	dft->gain_thr_up = 2048;
	dft->gain_thr_down = 2176;
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = (float)MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 5800;
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

static int32_t SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
{
	/* TODO - fool proof design*/

	memcpy(cal, &cal_tbl_dft, sizeof(MPI_CAL_SNS_DEFAULT_S));

	return MPI_SUCCESS;
}

static int32_t SENSOR_regCallback(MPI_PATH idx)
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
		                .set_framerate = SENSOR_setFramerate,
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
