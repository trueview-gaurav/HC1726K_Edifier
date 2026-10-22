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
#include "sensor_params.h"
#include "sensor_settings.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (533) // sensor ID

#define SC533HAI_VMAX1_ADDR (0x326D) // vmax(fps line)[0] 	-> [16]
#define SC533HAI_VMAX2_ADDR (0x320E) // vmax(fps line)[7:0] -> [15:8]
#define SC533HAI_VMAX3_ADDR (0x320F) // vmax(fps line)[7:0] -> [7:0]

#define SC533HAI_SHS1_ADDR (0x3E00) // sensor exposure line control(shs1) [4:0] => [16:12]
#define SC533HAI_SHS2_ADDR (0x3E01) // sensor exposure line control(shs2) [7:0] => [11: 4]
#define SC533HAI_SHS3_ADDR (0x3E02) // sensor exposure line control(shs3) [7:4] => [ 3: 0]

#define EXP_LINE_GAP (8) 			//see datasheet spec 2.4.2
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2)	//see datasheet spec 2.4.2

#define SC533HAI_GAIN_MODE_ADDR (0x3E03) // sensor gain mode
#define SC533HAI_AC_GAIN_ADDR (0x3E08) // sensor analog coarse gain
#define SC533HAI_AF_GAIN_ADDR (0x3E09) // sensor analog fine gain
#define SC533HAI_DC_GAIN_ADDR (0x3E06) // sensor digital coarse gain
#define SC533HAI_DF_GAIN_ADDR (0x3E07) // sensor digital fine gain

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
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

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

	return ret;
}

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
			pregs[0].i2c_data[i].is_update = true;
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = 2;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = SC533HAI_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = SC533HAI_VMAX2_ADDR;
		pregs[0].i2c_data[IDX_VMAX_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_3].reg_addr = SC533HAI_VMAX3_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = SC533HAI_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = SC533HAI_SHS2_ADDR;
		pregs[0].i2c_data[IDX_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_3].reg_addr = SC533HAI_SHS3_ADDR;

		pregs[0].i2c_data[IDX_AC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AC].reg_addr = SC533HAI_AC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_AF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AF].reg_addr = SC533HAI_AF_GAIN_ADDR;
		pregs[0].i2c_data[IDX_DC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DC].reg_addr = SC533HAI_DC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_DF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DF].reg_addr = SC533HAI_DF_GAIN_ADDR;
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

	int exp_line_prc = 0;
	int exp_line = (time_us << (ROW_TIME_PRC + exp_line_prc)) / g_sensor_state[idx.path].row_time[0];

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

	int value = exp_line << 4;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (value & 0x1F0000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].reg_data = value & 0xF0;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	/* a_gain max and d_gain min*/
	int ac_gain = 0x00;
	int af_gain = 0x20;
	int dc_gain = 0x00;
	int df_gain = 0x80;

	int ac_step[] = { 256,  512,  681,  1362, 2724, 5448, 10895  }; // 256 implies 1x here, to suppress calculation error
	int ac_val[] = {  0x00, 0x01, 0x80, 0x81, 0x83, 0x87, 0x8f };
	int af_mul[] = {8, 16, 21, 42, 84, 170, 340};//The analog gain value increases when the analog fine register increases by one unit; then multiply the analog gain value by 256.
	// int af_base = 64; // 1x
	int af_max = 0x3f - 0x20; //
	int dc_step[] = { 256,  512,  1024, 2048 };
	int dc_val[] =  { 0x00, 0x01, 0x03, 0x07 };
	int df_mul[] = {8, 16, 32, 64};
	// int df_base = 128; // 1x
	int df_max = 0xfc - 0x80; //
	int tmp;
	int tmp_gain = gain << 3; // make 256 as 1x to decrease calculation error
	int origin_gain = tmp_gain;
	int ana_total_gain = 0;
	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_err("Sensor gain must be in range [%d, %d]", SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
		return MPI_FAILURE;
	}
	g_sns_state[idx.path]->sensor_gain = gain;

	// analog coarse gain
	tmp = binary_search_nr(tmp_gain, ac_step, 0, sizeof(ac_step) / sizeof(int));
	ac_gain = ac_val[tmp];
	tmp_gain = tmp_gain - ac_step[tmp];
	//spec 2.4.3, table 2-8
	if(0x01 == ac_gain)
	{
		af_max = 0x2a - 0x20;
	}
	// analog fine gain
	if (tmp_gain >= af_max * af_mul[tmp]) {
		af_gain = af_max * af_mul[tmp];
	} else {
		af_gain = (tmp_gain + af_mul[tmp]/2)/ af_mul[tmp] * af_mul[tmp];
	}

	ana_total_gain = ac_step[tmp] + af_gain;
	tmp_gain = ((origin_gain*256) + (ana_total_gain>>1)) / ana_total_gain;
	tmp_gain = tmp_gain < 256 ? 256 : tmp_gain;
	af_gain = af_gain / af_mul[tmp] + 0x20;

	// digital coarse gain
	tmp = binary_search_nr(tmp_gain, dc_step, 0, sizeof(dc_step) / sizeof(int));
	dc_gain = dc_val[tmp];
	tmp_gain = tmp_gain  - dc_step[tmp];

	// digital fine gain
	if (tmp_gain >= df_max / 4 * df_mul[tmp]) {
		df_gain = df_max;
	} else {
		df_gain = (tmp_gain + df_mul[tmp] / 2) / df_mul[tmp] * 4;
	}
	df_gain += 0x80;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AC].reg_data = ac_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AF].reg_data = af_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DC].reg_data = dc_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DF].reg_data = df_gain;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AC].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_AF].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DC].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_DF].is_update = true;
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

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x010000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00)   >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}

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

	int exp_line = ((time_us << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	               g_sensor_state[idx.path].row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;
	if (frame_line <= 0) {
		sensor_log_err("Cannot correctly calculate line per frame.");
		return MPI_FAILURE;
	}

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Exposure time or FPS exceeds hardware limit.");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x010000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00)   >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

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
	dft->sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->sensor_gain_range.min = SENSOR_GAIN_MIN;
	dft->target_sys_gain_range.max = 16383;
	dft->target_sys_gain_range.min = 32;
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
		array[i] = black_level_table[0].black_level[i];
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
