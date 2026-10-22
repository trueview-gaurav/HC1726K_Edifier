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

// sensor_cmos.c for this sensor is not correctly implemented
// Remove this #error if you acknowledge that you're not using this sensor for normal applications
#error "This sensor is not completed yet."

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (3035) // sensor ID

#define SC3035_SHS1_ADDR (0x3E02) // sensor exposure line control(shs1) [3:0]
#define SC3035_SHS2_ADDR (0x3E01) // sensor exposure line control(shs2) [11:4]

#define SC3035_GAIN_MODE_ADDR (0x3E03) // sensor gain mode
#define SC3035_COURSE_GAIN_ADDR (0x3E08) // sensor analog [4:2] / digital [7:5] coarse gain
#define SC3035_FINE_GAIN_ADDR (0x3E09) // sensor fine gain [7:0] (0x10 ~ 0x1f)
#define SC3035_DENOISE_LOGIC_1 (0x3630) // denoise logic 1
#define SC3035_DENOISE_LOGIC_2 (0x3635) // denoise logic 2
#define SC3035_DENOISE_LOGIC_3 (0x3620) // denoise logic 3
#define SC3035_DENOISE_LOGIC_4 (0x3627) // denoise logic 3

#define SC3035_VMAX1_ADDR (0x320F) // vmax(fps line)[7:0]
#define SC3035_VMAX2_ADDR (0x320E) // vmax(fps line)[15:8]

#define SC3035_EXP_UPDATE (0x3812) // Update exposure setting in same frame

#define EXP_LINE_GAP (4)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int32_t g_inttime = 16500;

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
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = SC3035_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = SC3035_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = SC3035_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = SC3035_SHS2_ADDR;

		pregs[0].i2c_data[IDX_CGAIN].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_CGAIN].reg_addr = SC3035_COURSE_GAIN_ADDR;
		pregs[0].i2c_data[IDX_FGAIN].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_FGAIN].reg_addr = SC3035_FINE_GAIN_ADDR;
		pregs[0].i2c_data[IDX_LOGIC_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_LOGIC_1].reg_addr = SC3035_DENOISE_LOGIC_1;
		pregs[0].i2c_data[IDX_LOGIC_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_LOGIC_2].reg_addr = SC3035_DENOISE_LOGIC_2;
		pregs[0].i2c_data[IDX_LOGIC_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_LOGIC_3].reg_addr = SC3035_DENOISE_LOGIC_3;
		pregs[0].i2c_data[IDX_LOGIC_4].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_LOGIC_4].reg_addr = SC3035_DENOISE_LOGIC_4;
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
	//exp_line_addr value = exp_line * 2
	int32_t line_shif = 0;
	int32_t exp_line_x2 = (time_us << (ROW_TIME_PRC + line_shif)) / g_sensor_state[idx.path].row_time[0];

	//exp_line_addr value max = fps_line * 2 - 4
	if (exp_line_x2 > (SENSOR_EXP_LINES_MAX << line_shif) || (exp_line_x2 < (SENSOR_EXP_LINES_MIN << line_shif))) {
		sensor_log_warn("Exposure time exceeds hardware limit.");
		exp_line_x2 =
		        CLAMP(exp_line_x2, (SENSOR_EXP_LINES_MIN << line_shif), (SENSOR_EXP_LINES_MAX << line_shif));
	}

	if (exp_line_x2 > (g_sensor_state[idx.path].frame_line[0] << line_shif) - (EXP_LINE_GAP << line_shif)) {
		sensor_log_err("Expsoure time too long in current FPS.");
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

	int value = exp_line_x2 << 4;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = value & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = (value & 0xFF00) >> 8;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	/* a_gain max and d_gain min*/
	int32_t ac_gain = 0;
	int32_t dc_gain = 0;
	int32_t df_gain = 16;
	int32_t denoise_1;
	int32_t denoise_2;
	int32_t denoise_3;
	int32_t denoise_4;

	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_err("Sensor gain must be in range [%d, %d]", SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
		return MPI_FAILURE;
	}
	g_sns_state[idx.path]->sensor_gain = gain;

	int32_t gain_val = gain >> 1;

	// additional denoise logic for SC3035
	if (gain < 64) {
		denoise_1 = 0xa9;
		denoise_2 = 0x66;
		denoise_3 = 0xd2;
		denoise_4 = 0x02;
	} else if (gain < 512) {
		denoise_1 = 0x67;
		denoise_2 = 0x64;
		denoise_3 = 0xd2;
		denoise_4 = 0x02;
	} else {
		denoise_1 = 0x67;
		denoise_2 = 0x62;
		denoise_3 = 0x63;
		denoise_4 = 0x06;
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CGAIN].reg_data = (gain_val & 0xff00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_FGAIN].reg_data = (gain_val & 0xff);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_1].reg_data = denoise_1;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_2].reg_data = denoise_2;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_3].reg_data = denoise_3;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_4].reg_data = denoise_4;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_CGAIN].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_FGAIN].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_3].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_LOGIC_4].is_update = true;

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

	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t sec_line; /* In one second, number of sensor can output lines */

	fps = fps * FPS_UNIT;
	sec_line = ((g_sensor_state[idx.path].pclk + (g_sensor_state[idx.path].line_pixel[0] >> 1)) /
	            g_sensor_state[idx.path].line_pixel[0])
	           << FPS_PRC;
	if (sec_line <= 0) {
		sensor_log_err("Cannot correctly calculate line per second.");
		return MPI_FAILURE;
	}

	frame_line = (sec_line + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Requested fps exceeds driver limit.");
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

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00) >> 8;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
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
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00) >> 8;

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
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 384;
	dft->gain_thr_down = 512;
	dft->max_fps = (float)SENSOR_FPS;
	dft->min_fps = 5;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 8000;
	dft->exp_value = 528000;
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
