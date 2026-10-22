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

#define SENSOR_ID (410) // sensor ID

#define OS04D10_PAGE_SEL_ADDR (0xFD)

#define OS04D10_SHS1_ADDR (0x03) // sensor exposure line control(shs1) [15:8]
#define OS04D10_SHS2_ADDR (0x04) // sensor exposure line control(shs2) [ 7:0]

#define OS04D10_AGAIN_ADDR (0x24) // sensor analog gain [7:0], 0x10 - 0xF8 (15.5x)
#define OS04D10_DGAIN1_ADDR (0x37) // sensor digital gain [10:8]
#define OS04D10_DGAIN2_ADDR (0x39) // sensor digital gain [ 7:0]

#define OS04D10_VTS1_ADDR (0x35) // VTS [15:8]  read only
#define OS04D10_VTS2_ADDR (0x36) // VTS [ 7:0]  read only

#define OS04D10_VBLANK1_ADDR (0x05) // VBLANK1 [15:8]
#define OS04D10_VBLANK2_ADDR (0x06) // VBLANK2 [ 7:0]

#define OS04D10_EXP_UPDATE_ADDR (0x01)

#define EXP_LINE_GAP (9) // SPEC 4.4.1
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2) // SPEC 4.4.1 is 1 but IQ is suck, set to 2 for better IQ
#define SENSOR_MAX_GAIN (15872) // analog (15.5x) * digital (32x) , SPEC 4.4.1
#define SENSOR_MAX_A_GAIN (496) // analog 15.5x , SPEC 4.4.1
#define SENSOR_MIN_GAIN (32)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

#ifdef __UBOOT__
#define VBLANK_OFFSET (INIT_FRAME_LINE - 8) // Know from experiment (shooting 120Hz light bulb)
#else

#if SET_2560_1440_30fps_2lane
#define VBLANK_OFFSET (INIT_FRAME_LINE - 8) // Know from experiment (shooting 120Hz light bulb)
#endif
#if SET_2568_1448_30fps_2lane
#define VBLANK_OFFSET (INIT_FRAME_LINE - 2) // Know from experiment (shooting 120Hz light bulb)
#endif

#endif

typedef enum {
	IDX_PAGE_SEL, /* Do not change enum order */
	IDX_VBLANK_1,
	IDX_VBLANK_2,
	IDX_EXP_UPDATE,
	IDX_PAGE_SEL2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_AGAIN,
	IDX_PAGE_SEL3,
	IDX_DGAIN_1,
	IDX_DGAIN_2,
	IDX_PAGE_SEL4,
	IDX_EXP_UPDATE2,
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

#ifndef __UBOOT__
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

	ret = SENSOR_writeSeqBaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

	return ret;
}
#endif

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
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = 1;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[IDX_PAGE_SEL].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PAGE_SEL].reg_addr = OS04D10_PAGE_SEL_ADDR;
		pregs[0].i2c_data[IDX_PAGE_SEL].reg_data = 0x01;

		pregs[0].i2c_data[IDX_PAGE_SEL2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PAGE_SEL2].reg_addr = OS04D10_PAGE_SEL_ADDR;
		pregs[0].i2c_data[IDX_PAGE_SEL2].reg_data = 0x01;

		pregs[0].i2c_data[IDX_PAGE_SEL3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PAGE_SEL3].reg_addr = OS04D10_PAGE_SEL_ADDR;
		pregs[0].i2c_data[IDX_PAGE_SEL3].reg_data = 0x05;

		pregs[0].i2c_data[IDX_PAGE_SEL4].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_PAGE_SEL4].reg_addr = OS04D10_PAGE_SEL_ADDR;
		pregs[0].i2c_data[IDX_PAGE_SEL4].reg_data = 0x01;

		pregs[0].i2c_data[IDX_VBLANK_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VBLANK_1].reg_addr = OS04D10_VBLANK1_ADDR;
		pregs[0].i2c_data[IDX_VBLANK_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VBLANK_2].reg_addr = OS04D10_VBLANK2_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = OS04D10_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = OS04D10_SHS2_ADDR;

		pregs[0].i2c_data[IDX_AGAIN].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AGAIN].reg_addr = OS04D10_AGAIN_ADDR;
		pregs[0].i2c_data[IDX_DGAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DGAIN_1].reg_addr = OS04D10_DGAIN1_ADDR;
		pregs[0].i2c_data[IDX_DGAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DGAIN_2].reg_addr = OS04D10_DGAIN2_ADDR;

		pregs[0].i2c_data[IDX_EXP_UPDATE].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_EXP_UPDATE].reg_addr = OS04D10_EXP_UPDATE_ADDR;
		pregs[0].i2c_data[IDX_EXP_UPDATE].reg_data = 0x01;

		pregs[0].i2c_data[IDX_EXP_UPDATE2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_EXP_UPDATE2].reg_addr = OS04D10_EXP_UPDATE_ADDR;
		pregs[0].i2c_data[IDX_EXP_UPDATE2].reg_data = 0x01;

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

	g_sensor_state[idx.path].row_time[0] = (uint64_t)(1000000 << ROW_TIME_PRC) * INIT_LINE_LEN / PCLK;

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
	uint32_t time_tmp = ((uint32_t)exp_line * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC;
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	int value = exp_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = value & 0xFF;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PAGE_SEL2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_UPDATE2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	g_sns_state[idx.path]->sensor_gain = gain;

	/* a_gain min and d_gain min*/
	int a_gain = 16;
	int d_gain = 64;

	const int a_max = 0xf8; // 248, 15.5x
	const int d_max = 0x7ff; // 2047, 32x

	if (gain < SENSOR_MIN_GAIN) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > SENSOR_MAX_GAIN) {
		printf("[Sensor Error] Sensor gain bigger than %d(sensor limit)\n", SENSOR_MAX_GAIN);
		return MPI_FAILURE;
	}

	if (gain <= SENSOR_MAX_A_GAIN) {
		a_gain = gain / 2; /* gain 32 ~ 496 */
	} else {
		a_gain = a_max; /* gain 497 ~ 15872 */
	}
	d_gain = (gain * 32 + a_gain / 2) / a_gain;
	if (d_gain > d_max)
		d_gain = d_max;
#if 0
	static int log =0;
	++log;
	if(log >= 400)
	{
		printf("setSensorGain:%u,0x%X,0x%X\n",gain,a_gain,d_gain);
		log=0;
	}
#endif
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN].reg_data = a_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_1].reg_data = (d_gain & 0x700) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_2].reg_data = d_gain & 0xff;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PAGE_SEL2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AGAIN].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PAGE_SEL3].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DGAIN_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PAGE_SEL4].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_UPDATE2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramerate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	assert(fps > 0 && "[Sensor Error] FPS must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	uint32_t frame_line; /* number of lines the sensor can output in one frame */
	uint32_t sec_line; /* number of lines sensor can output in a second */
	uint32_t exp_max;
	uint32_t exp_min;

	fps = fps * FPS_UNIT;
	sec_line = PCLK / INIT_LINE_LEN;
	frame_line = ((sec_line << FPS_PRC) + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}
	g_sensor_state[idx.path].frame_line[0] = frame_line;

	exp_max = (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >>
	           ROW_TIME_PRC);
	exp_min =
	        ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC) +
	        1;
	if (inttime) {
		inttime->max = exp_max;
		inttime->min = exp_min;
	}
	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, exp_max, NULL);
	} else {
		SENSOR_setInttime(idx, g_inttime, NULL);
	}
	frame_line -= VBLANK_OFFSET;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_1].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_2].reg_data = frame_line & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PAGE_SEL].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_UPDATE].is_update = true;

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

	int exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;

	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if (frame_line > SENSOR_FRAME_LINES_MAX) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	if (frame_line < SENSOR_FRAME_LINES_MIN) {
		frame_line = SENSOR_FRAME_LINES_MIN;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	uint32_t frame_line_reg = frame_line - VBLANK_OFFSET;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_1].reg_data = (frame_line_reg & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_2].reg_data = frame_line_reg & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_PAGE_SEL].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VBLANK_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_EXP_UPDATE].is_update = true;

	int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	if (fps) {
		*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;
	}

	SENSOR_setInttime(idx, time_us, NULL);
	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	dft->sensor_gain_range.max = SENSOR_MAX_GAIN;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 16383;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_MAX_GAIN;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 256;
	dft->gain_thr_down = 512;
	dft->max_fps = MAX_FPS;
	dft->min_fps = MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 800;
	dft->brightness = 8000;
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
			.set_framerate = SENSOR_setFramerate,
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