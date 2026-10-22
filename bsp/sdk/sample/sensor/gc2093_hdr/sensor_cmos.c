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

#define GC2093_S_SHS_1_ADDR (0x0001) // HDR short exposure line [13:8] (WO)
#define GC2093_S_SHS_2_ADDR (0x0002) // HDR short exposure line [7:0] (WO)
#define GC2093_L_SHS_1_ADDR (0x0003) // HDR long exposure line [13:8]
#define GC2093_L_SHS_2_ADDR (0x0004) // HDR long exposure line [7:0]
#define GC2093_SHS_VREF_ADDR (0x0032)

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

#define EXP_LINE_GAP (8)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

#define GAIN_LUT_ENTRY_NUM 25
static uint8_t regValTable_30fpshdr[GAIN_LUT_ENTRY_NUM][7] = {
	//0xb3  0xb8  0xb9 0x155  0xc2  0xcf  0xd9
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

// use 256 as base, 73.22x max
static uint32_t gainLevelTable[GAIN_LUT_ENTRY_NUM] = {
	256,  304,  366,  428,  500,  588,  708,  844,  992,  1188,  1424,  1700,  2016,
	2396, 2836, 3344, 3912, 4612, 5860, 6604, 7740, 9168, 12956, 15836, 18744,
};

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

/*
Note: Sensor driver will always make LE lines a certain multiple of SE lines,
and maintain the ratio of LE/SE exposure lines,
such that AE will use the same gain value on both images automatically.
But the exposure ratio of AE should be set to the same value as this one
*/
#define FIX_EXP_RATIO (9)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_S_SHS_1,
	IDX_S_SHS_2,
	IDX_L_SHS_1,
	IDX_L_SHS_2,
	IDX_SHS_VERF,
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

		pregs[0].i2c_data[IDX_S_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_1].reg_addr = GC2093_S_SHS_1_ADDR;
		pregs[0].i2c_data[IDX_S_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_2].reg_addr = GC2093_S_SHS_2_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_1].reg_addr = GC2093_L_SHS_1_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_2].reg_addr = GC2093_L_SHS_2_ADDR;
		pregs[0].i2c_data[IDX_SHS_VERF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_VERF].reg_addr = GC2093_SHS_VREF_ADDR;

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

	// HDR info
	// long exposure
	g_sns_state[idx.path]->exp_info[0].effective_frame_line = INIT_FRAME_LINE - HDR_BLANK_LINE;
	g_sns_state[idx.path]->exp_info[0].exp_gap = 2;
	if (FIX_EXP_RATIO) {
		g_sns_state[idx.path]->exp_info[0].exp_min = SENSOR_EXP_LINES_MIN * FIX_EXP_RATIO;
	} else {
		g_sns_state[idx.path]->exp_info[0].exp_min = SENSOR_EXP_LINES_MIN;
	}
	g_sns_state[idx.path]->exp_info[0].exp_line = 640;
	g_sns_state[idx.path]->exp_info[0].inttime = 17064;
	g_sns_state[idx.path]->exp_info[0].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[0].shs_idx[0] = IDX_L_SHS_1;
	g_sns_state[idx.path]->exp_info[0].shs_idx[1] = IDX_L_SHS_2;

	// short exposure
	g_sns_state[idx.path]->exp_info[1].effective_frame_line = HDR_BLANK_LINE;
	g_sns_state[idx.path]->exp_info[1].exp_gap = 0;
	g_sns_state[idx.path]->exp_info[1].exp_min = SENSOR_EXP_LINES_MIN;
	g_sns_state[idx.path]->exp_info[1].exp_line = 80;
	g_sns_state[idx.path]->exp_info[1].inttime = 2133;
	g_sns_state[idx.path]->exp_info[1].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[1].shs_idx[0] = IDX_S_SHS_1;
	g_sns_state[idx.path]->exp_info[1].shs_idx[1] = IDX_S_SHS_2;

	// Declare a fake maximum exposure time to fit the exposure ratio
	int le_hard_max = SENSOR_FRAME_LINES_MAX - HDR_BLANK_LINE - g_sns_state[idx.path]->exp_info[0].exp_gap;
	int le_effc_max =
	        g_sns_state[idx.path]->exp_info[0].effective_frame_line - g_sns_state[idx.path]->exp_info[0].exp_gap;
	int se_hard_max = HDR_BLANK_LINE - g_sns_state[idx.path]->exp_info[1].exp_gap;
	int se_effc_max =
	        g_sns_state[idx.path]->exp_info[0].effective_frame_line - g_sns_state[idx.path]->exp_info[1].exp_gap;

	if (FIX_EXP_RATIO) {
		if (se_effc_max * FIX_EXP_RATIO > le_effc_max) {
			se_effc_max = le_effc_max / FIX_EXP_RATIO;
		}
		le_effc_max = se_effc_max * FIX_EXP_RATIO;

		if (se_hard_max * FIX_EXP_RATIO > le_hard_max) {
			se_hard_max = le_hard_max / FIX_EXP_RATIO;
		}
		le_hard_max = se_hard_max * FIX_EXP_RATIO;
	}

	g_sns_state[idx.path]->exp_info[0].curr_exp_max = le_effc_max;
	g_sns_state[idx.path]->exp_info[1].curr_exp_max = se_effc_max;
	g_sns_state[idx.path]->exp_info[0].hard_exp_max = le_hard_max;
	g_sns_state[idx.path]->exp_info[1].hard_exp_max = se_hard_max;
}

static int32_t SENSOR_setInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, uint32_t *effective_time)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	uint32_t row_time = g_sensor_state[idx.path].row_time[0];
	assert(row_time > 0 && "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	if (image_idx >= HDR_IMAGE_NUM) {
		printf("[Sensor Error] Sub image index exceeds the current setting.");
		return MPI_FAILURE;
	}
	uint32_t exp_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;
	uint32_t exp_min = g_sns_state[idx.path]->exp_info[image_idx].exp_min;
	/*
	Force LE lines be a multiple of exp_ratio
	and SE lines will be truncated to fit LE lines if needed
	*/
	int exp_line;
	exp_line = (time_us << ROW_TIME_PRC) / row_time;
	if (image_idx == 0) {
		if (FIX_EXP_RATIO) {
			exp_line = exp_line / FIX_EXP_RATIO * FIX_EXP_RATIO;
		}
	} else {
		if (FIX_EXP_RATIO) {
			int expected_line = g_sns_state[idx.path]->exp_info[0].exp_line / FIX_EXP_RATIO;
			exp_line = expected_line < exp_line ? expected_line : exp_line;
		}
	}

	if (exp_line > exp_max || exp_line < exp_min) {
		printf("[Sensor warning] Exposure time exceeds limit.\n");
		exp_line = CLAMP(exp_line, exp_min, exp_max);
	}

	g_sns_state[idx.path]->exp_info[image_idx].exp_line = exp_line;
	uint32_t time_tmp = (uint32_t)exp_line * g_sns_state[idx.path]->row_time[0];
	time_tmp = (time_tmp + (1 << (ROW_TIME_PRC - 1))) >> ROW_TIME_PRC;
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_sns_state[idx.path]->exp_info[image_idx].inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	int idx0 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[0];
	int idx1 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[1];
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].reg_data = (exp_line & 0x3F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].reg_data = exp_line & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].is_update = true;

	if (image_idx == 1) {
		if (exp_line <= 30) {
			g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_VERF].reg_data = 0xfd;
		} else {
			g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_VERF].reg_data = 0xf8;
		}
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_VERF].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	// treated as setting LE in HDR function
	int ret = SENSOR_setInttimeHdr(idx, 0, time_us, effective_time);
	if (ret == MPI_SUCCESS) {
		g_inttime = g_sns_state[idx.path]->exp_info[0].inttime;
	}
	return ret;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	if (gain < 32) {
		printf("[Sensor Error] Sensor gain must be at least 32(1.0x).\n");
		return MPI_FAILURE;
	} else if (gain > SENSOR_MAX_GAIN) {
		printf("[Sensor Error] Sensor gain cannot be bigger than %d(sensor limit).\n", SENSOR_MAX_GAIN);
		return MPI_FAILURE;
	}
	g_sns_state[idx.path]->sensor_gain = gain;

	int tmp_gain = gain << 3; // 256 as 1x
	int gain_idx = 1;

	while (gain_idx < GAIN_LUT_ENTRY_NUM) {
		if (tmp_gain < gainLevelTable[gain_idx]) {
			break;
		}
		gain_idx++;
	}
	gain_idx -= 1;
	int dgain = (tmp_gain * 64 + gainLevelTable[gain_idx] / 2) / gainLevelTable[gain_idx];

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_1].reg_data = regValTable_30fpshdr[gain_idx][0];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_2].reg_data = regValTable_30fpshdr[gain_idx][1];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_3].reg_data = regValTable_30fpshdr[gain_idx][2];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_4].reg_data = regValTable_30fpshdr[gain_idx][3];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_5].reg_data = regValTable_30fpshdr[gain_idx][4];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_6].reg_data = regValTable_30fpshdr[gain_idx][5];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN_7].reg_data = regValTable_30fpshdr[gain_idx][6];

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_1].reg_data = (dgain >> 6);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_2].reg_data = ((dgain & 0x3F) << 2);

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

static int32_t SENSOR_setSensorGainHdr(MPI_PATH idx, uint32_t image_idx, uint32_t gain)
{
	// GC2093 does not support multiple sensor gain, redirect to non-HDR function
	int ret = SENSOR_setSensorGain(idx, gain);
	if (ret == MPI_SUCCESS) {
		g_sns_state[idx.path]->exp_info[image_idx].sensor_gain = g_sns_state[idx.path]->sensor_gain;
	}

	return ret;
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	CUSTOM_SNS_STATE_S *sns_state = &(g_sensor_state[idx.path]); /* sensor state */
	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t sec_line; /* In one second, number of sensor can output lines */
	uint32_t line_pixel = sns_state->line_pixel[0];
	uint32_t row_time = sns_state->row_time[0];
	uint32_t pclk = sns_state->pclk;
	uint32_t inttime_max;
	uint32_t inttime_min;
	assert(line_pixel > 0 && "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(row_time > 0 && "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");
	sec_line = (pclk + (line_pixel >> 1)) / line_pixel;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");

	if (fps < MIN_FPS || fps > MAX_FPS) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}
	int32_t fps_int = fps * FPS_UNIT;
	frame_line = ((sec_line << FPS_PRC) + (fps_int >> 1)) / fps_int;
	frame_line = CLAMP(frame_line, SENSOR_FRAME_LINES_MIN, SENSOR_FRAME_LINES_MAX);

	sns_state->frame_line[0] = frame_line;

	for (int image_idx = 0; image_idx < HDR_IMAGE_NUM; image_idx++) {
		uint32_t exp_line_max = sns_state->exp_info[image_idx].curr_exp_max;

		inttime_max = ((exp_line_max * row_time) >> ROW_TIME_PRC) + 1;
		inttime_min = ((SENSOR_EXP_LINES_MIN * row_time) >> ROW_TIME_PRC) + 1;
		if (image_idx == 0 && inttime) {
			inttime->max = inttime_max;
			inttime->min = inttime_min;
		}

		if (sns_state->exp_info[image_idx].exp_line > exp_line_max) {
			SENSOR_setInttimeHdr(idx, image_idx, inttime_max, NULL);
		} else {
			SENSOR_setInttimeHdr(idx, image_idx, sns_state->exp_info[image_idx].inttime, NULL);
		}
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, float *fps)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	if (image_idx != 0) {
		printf("[Sensor warning] setSlowInttimeHdr does not support image_idx > 0.\n");
		return SENSOR_setInttimeHdr(idx, image_idx, time_us, NULL);
	}

	CUSTOM_SNS_STATE_S *sns_state = &(g_sensor_state[idx.path]); /* sensor state */
	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t line_pixel = sns_state->line_pixel[0];
	uint32_t row_time = sns_state->row_time[0];
	uint32_t pclk = sns_state->pclk;
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int exp_line = (time_us << ROW_TIME_PRC) / row_time;
	frame_line = exp_line + sns_state->exp_info[0].exp_gap;
	frame_line = frame_line > SENSOR_FRAME_LINES_MIN ? frame_line : SENSOR_FRAME_LINES_MIN;

	if (frame_line > SENSOR_FRAME_LINES_MAX) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	if (fps) {
		int temp = frame_line * line_pixel;
		*fps = (float)pclk / (float)temp;
	}

	g_sns_state[idx.path]->frame_line[0] = frame_line;
	int ret = SENSOR_setInttimeHdr(idx, 0, time_us, NULL);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	return ret;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	// treated as setting LE in HDR function
	int ret = SENSOR_setSlowInttimeHdr(idx, 0, time_us, fps);
	if (ret == MPI_SUCCESS) {
		g_inttime = g_sns_state[idx.path]->exp_info[0].inttime;
	}
	return ret;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	int row_time = g_sns_state[idx.path]->row_time[0];
	dft->hdr.image_num = HDR_IMAGE_NUM;
	for (int i = 0; i < HDR_IMAGE_NUM; i++) {
		int exp_max = g_sns_state[idx.path]->exp_info[i].hard_exp_max;
		int exp_min = g_sns_state[idx.path]->exp_info[i].exp_min;
		dft->hdr.hdr_inttime_range[i].max = ((exp_max * row_time) >> ROW_TIME_PRC) + 1;
		dft->hdr.hdr_inttime_range[i].min = ((exp_min * row_time) >> ROW_TIME_PRC) + 1;
	}
	dft->inttime_range.max = dft->hdr.hdr_inttime_range[0].max;
	dft->inttime_range.min = dft->hdr.hdr_inttime_range[0].min;
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
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = MIN_FPS;
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
		                .set_slow_inttime_hdr = SENSOR_setSlowInttimeHdr,
		                .set_inttime_hdr = SENSOR_setInttimeHdr,
		                .set_sensor_gain_hdr = SENSOR_setSensorGainHdr,
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
