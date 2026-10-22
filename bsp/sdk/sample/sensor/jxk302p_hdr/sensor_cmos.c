/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include "sensor.h"
#include "l_sensor_cal.h"
#include "sensor_settings.h"

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (302) // sensor ID

#define JXK302P_L_SHS1_ADDR (0x01) // HDR long exposure line control(shs1) [7:0]
#define JXK302P_L_SHS2_ADDR (0x02) // HDR long exposure line control(shs2) [15:8]
#define JXK302P_S_SHS1_ADDR (0x05) // HDR short exposure line control(shs1) [7:0]
#define JXK302P_S_SHS2_ADDR (0x08) // HDR short exposure line control(shs2) [8]

//Total gain = (2 ** gain[6:4]) * (1 + gain[3:0] / 16)
//Total gain = (2^gain[6:4]) * (1 + gain[3:0] / 16)
#define JXK302P_GAIN_ADDR (0x00) // sensor gain [6:0]

#define JXK302P_VMAX1_ADDR (0x22) // vmax(fps line)[7:0]
#define JXK302P_VMAX2_ADDR (0x23) // vmax(fps line)[15:8]

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define FIX_EXP_RATIO (8)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_L_SHS_1,
	IDX_L_SHS_2,
	IDX_S_SHS_1,
	IDX_S_SHS_2,
	IDX_GAIN,
	IDX_NUM,
} I2C_DATA_IDX_E;
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

	ret = SENSOR_writeSeqBaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[IDX_VMAX_1].dev_addr);
	return ret;
}

static int32_t SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[idx.path]->regs_info;
	int32_t i;

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

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = JXK302P_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = JXK302P_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_L_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_1].reg_addr = JXK302P_L_SHS1_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_2].reg_addr = JXK302P_L_SHS2_ADDR;

		pregs[0].i2c_data[IDX_S_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_1].reg_addr = JXK302P_S_SHS1_ADDR;
		pregs[0].i2c_data[IDX_S_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_2].reg_addr = JXK302P_S_SHS2_ADDR;

		pregs[0].i2c_data[IDX_GAIN].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN].reg_addr = JXK302P_GAIN_ADDR;

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
	g_sensor_state[idx.path].sensor_gain = SENSOR_MIN_GAIN;
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

	// HDR info
	// long exposure
	g_sns_state[idx.path]->exp_info[0].effective_frame_line = INIT_FRAME_LINE - HDR_BLANK_LINE;
	g_sns_state[idx.path]->exp_info[0].exp_gap = EXP_LINE_GAP;
	if (FIX_EXP_RATIO) {
		g_sns_state[idx.path]->exp_info[0].exp_min = SENSOR_EXP_LINES_MIN * FIX_EXP_RATIO;
	} else {
		g_sns_state[idx.path]->exp_info[0].exp_min = SENSOR_EXP_LINES_MIN;
	}
	g_sns_state[idx.path]->exp_info[0].exp_line = 3584;
	g_sns_state[idx.path]->exp_info[0].inttime = 35398;
	g_sns_state[idx.path]->exp_info[0].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[0].shs_idx[0] = IDX_L_SHS_1;
	g_sns_state[idx.path]->exp_info[0].shs_idx[1] = IDX_L_SHS_2;

	// short exposure
	g_sns_state[idx.path]->exp_info[1].effective_frame_line = HDR_BLANK_LINE;
	g_sns_state[idx.path]->exp_info[1].exp_gap = 0;
	g_sns_state[idx.path]->exp_info[1].exp_min = SENSOR_EXP_LINES_MIN;
	g_sns_state[idx.path]->exp_info[1].exp_line = 448;
	g_sns_state[idx.path]->exp_info[1].inttime = 4425;
	g_sns_state[idx.path]->exp_info[1].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[1].shs_idx[0] = IDX_S_SHS_1;
	g_sns_state[idx.path]->exp_info[1].shs_idx[1] = IDX_S_SHS_2;

	// Declare a fake maximum exposure time to fit the exposure ratio
	int32_t le_hard_max = SENSOR_FRAME_LINES_MAX - HDR_BLANK_LINE - g_sns_state[idx.path]->exp_info[0].exp_gap;
	int32_t le_effc_max =
	        g_sns_state[idx.path]->exp_info[0].effective_frame_line - g_sns_state[idx.path]->exp_info[0].exp_gap;
	int32_t se_hard_max = HDR_BLANK_LINE - g_sns_state[idx.path]->exp_info[1].exp_gap;
	int32_t se_effc_max =
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
	le_hard_max = ((le_hard_max > HDR_LONG_EXPS_MAX) ? HDR_LONG_EXPS_MAX : le_hard_max);
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
	if (image_idx >= HDR_IMAGE_NUM) {
		printf("[Sensor Error] Sub image index exceeds the current limit.");
		return MPI_FAILURE;
	}
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row time) must be greater than than 0.\n");

	uint32_t hard_exp_max = g_sns_state[idx.path]->exp_info[image_idx].hard_exp_max;
	uint32_t curr_exp_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;
	uint32_t exp_min = g_sns_state[idx.path]->exp_info[image_idx].exp_min;

	//exp_line_addr value = exp_line * 2
	int32_t line_shif = SENSOR_EXP_LINE_SHIF;
	int32_t exp_line_x2 = (time_us << (ROW_TIME_PRC + line_shif)) / g_sensor_state[idx.path].row_time[0];
	if (image_idx == 0) {
		if (FIX_EXP_RATIO) {
			exp_line_x2 = exp_line_x2 / FIX_EXP_RATIO * FIX_EXP_RATIO;
		}
	} else {
		if (FIX_EXP_RATIO) {
			int32_t expected_line = g_sns_state[idx.path]->exp_info[0].exp_line / FIX_EXP_RATIO;
			exp_line_x2 = expected_line < exp_line_x2 ? expected_line : exp_line_x2;
		}
	}
	//exp_line_addr value max = fps_line * 2 - EXP_LINE_GAP
	if (exp_line_x2 > (hard_exp_max << line_shif) || (exp_line_x2 < (exp_min << line_shif))) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line_x2 = CLAMP(exp_line_x2, (exp_min << line_shif), (hard_exp_max << line_shif));
	}

	if (exp_line_x2 > (curr_exp_max << line_shif)) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->exp_info[image_idx].exp_line = (exp_line_x2 >> line_shif);
	uint32_t time_tmp = (uint32_t)exp_line_x2 * g_sensor_state[idx.path].row_time[0];
	time_tmp = (time_tmp + (1 << (ROW_TIME_PRC + line_shif - 1))) >> (ROW_TIME_PRC + line_shif);
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	g_sns_state[idx.path]->exp_info[image_idx].inttime = g_inttime;
	if (effective_time) {
		*effective_time = time_tmp;
	}
	int32_t value = exp_line_x2;
	switch (image_idx) {
	case 0:
		value = ((value > HDR_LONG_EXPS_MAX) ? HDR_LONG_EXPS_MAX : value);
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_L_SHS_1].reg_data = value & 0xFF;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_L_SHS_2].reg_data = (value & 0xFF00) >> 8;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_L_SHS_1].is_update = true;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_L_SHS_2].is_update = true;
		break;
	case 1:
		value = ((value > HDR_SHORT_EXPS_MAX) ? HDR_SHORT_EXPS_MAX : value);
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_S_SHS_1].reg_data = value & 0xFF;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_S_SHS_2].reg_data = (value & 0x0100) >> 8;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_S_SHS_1].is_update = true;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_S_SHS_2].is_update = true;
		break;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	return SENSOR_setInttimeHdr(idx, 0, time_us, effective_time);
}

static int32_t SENSOR_setSensorGainHdr(MPI_PATH idx, uint32_t image_idx, uint32_t gain)
{
	if (image_idx >= HDR_IMAGE_NUM) {
		printf("[Sensor Error] Sub image index exceeds the current limit.");
		return MPI_FAILURE;
	}
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->sensor_gain = gain;
	g_sns_state[idx.path]->exp_info[image_idx].sensor_gain = gain;

	/* a_gain max and d_gain min*/
	int32_t ac_gain = 0x00;
	int32_t df_gain = 0x00;

	//const int ac_step[] = { 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304 }; // PGA[6:4] x1, x2, x4, x8, x16, x32
	//const int ac_val[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	//const int df_step[] = { 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304 }; // PGA[3:0] x1, x2, x4, x8
	//const int df_val[] = { 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000};	// s
	const int32_t ac_step[] = { 256, 512, 1024, 2048 }; // x1, x2, x4, x8, x16, x32
	const int32_t ac_val[] = { 0x00, 0x01, 0x02, 0x03 };

	const int32_t df_step[] = { 256, 512, 1024, 2048 }; // x1, x2, x4, x8
	const int32_t df_val[] = { 0x10, 0x20, 0x40, 0x80 }; // step*8: 1, 2, 4, 8

	const int32_t df_base_step = 0x01; // 1/32 = 4 base step
	const int32_t df_base = 0x00;

	const int32_t df_max = 0x0F;

	int32_t ac_gain_tmp;
	int32_t tmp;
	int32_t tmp_gain = gain * 8; // ac_step[0] = 256/32 = 8

	if (gain < SENSOR_MIN_GAIN) {
		printf("[Sensor Error] Sensor gain must be greater than %d\n", SENSOR_MIN_GAIN);
		return MPI_FAILURE;
	} else if (gain > SENSOR_MAX_GAIN) {
		printf("[Sensor Error] Sensor gain must be lesser than %d (sensor limit)\n", SENSOR_MAX_GAIN);
		return MPI_FAILURE;
	}

	// analog coarse gain
	tmp = binary_search_nr(tmp_gain, ac_step, 0, sizeof(ac_step) / sizeof(int));
	ac_gain = ac_val[tmp];
	tmp_gain = ((tmp_gain * ac_step[0]) + (ac_step[tmp] >> 1)) / ac_step[tmp];
	ac_gain_tmp = ac_step[tmp] / ac_step[0];

	// digital fine gain
	df_gain = 256 * ac_gain_tmp;
	tmp = binary_search_nr(df_gain, df_step, 0, sizeof(df_step) / sizeof(int));
	df_gain = gain * 8;
	df_gain = ((df_gain - df_step[tmp]) / df_val[tmp]) * df_base_step + df_base;

	// digital fine gain
	df_gain = df_gain > df_max ? df_max : df_gain;

	// tmp_gain = ((ac_gain & 0x0F) << 4) | (df_gain & 0x0F);
	tmp_gain = ((ac_gain & 0x03) << 4) | (df_gain & 0x0F);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN].reg_data = tmp_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN].is_update = true;
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	return SENSOR_setSensorGainHdr(idx, 0, gain);
}

static int32_t SENSOR_setFramerate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	assert(fps > 0 && "[Sensor Error] FPS must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");
	uint32_t frame_line; /* Lines of pixels the sensor will run through in a frame. */
	uint32_t sec_line; /* Lines of pixels the sensor will run through in one second. */
	uint32_t line_pixel = g_sensor_state[idx.path].line_pixel[0];
	uint32_t row_time = g_sensor_state[idx.path].row_time[0];
	uint32_t pclk = g_sensor_state[idx.path].pclk;
	uint32_t inttime_max;
	uint32_t inttime_min;

	fps = fps * FPS_UNIT;
	sec_line = (pclk + (line_pixel >> 1)) / line_pixel;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");

	frame_line = ((sec_line << FPS_PRC) + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	for (int image_idx = 0; image_idx < HDR_IMAGE_NUM; image_idx++) {
		uint32_t exp_line_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;

		inttime_max = ((exp_line_max * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
		inttime_min = ((SENSOR_EXP_LINES_MIN * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
		if (image_idx == 0 && inttime) {
			inttime->max = inttime_max;
			inttime->min = inttime_min;
		}

		if (g_sns_state[idx.path]->exp_info[image_idx].exp_line > exp_line_max) {
			// printf("[SNS] set sensor idx %d with max inttime %u\n", image_idx, inttime_max);
			SENSOR_setInttimeHdr(idx, image_idx, inttime_max, NULL);
		} else {
			// printf("[SNS] set sensor idx %d with previous inttime %u\n", image_idx, g_sns_state[idx.path]->exp_info[image_idx].inttime);
			SENSOR_setInttimeHdr(idx, image_idx, g_sns_state[idx.path]->exp_info[image_idx].inttime, NULL);
		}
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00) >> 8;
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

	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int32_t exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];
	int32_t frame_line = exp_line + g_sns_state[idx.path]->exp_info[0].exp_gap;
	frame_line = frame_line > SENSOR_FRAME_LINES_MIN ? frame_line : SENSOR_FRAME_LINES_MIN;

	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if (frame_line > SENSOR_FRAME_LINES_MAX) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	if (fps) {
		int32_t temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
		*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;
	}

	int ret = SENSOR_setInttimeHdr(idx, 0, time_us, NULL);
	return ret;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	return SENSOR_setSlowInttimeHdr(idx, 0, time_us, fps);
}

static int32_t SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	if (idx.path >= DIP_MAX_PATH_NUM) {
		printf("[Sensor Error] Invalid path index %d.\n", idx.path);
		return MPI_FAILURE;
	}
	int32_t row_time = g_sns_state[idx.path]->row_time[0];
	dft->hdr.image_num = HDR_IMAGE_NUM;
	for (int32_t i = 0; i < HDR_IMAGE_NUM; i++) {
		int32_t exp_max = g_sns_state[idx.path]->exp_info[i].hard_exp_max;
		int32_t exp_min = g_sns_state[idx.path]->exp_info[i].exp_min;
		dft->hdr.hdr_inttime_range[i].max = ((exp_max * row_time) >> ROW_TIME_PRC) + 1;
		dft->hdr.hdr_inttime_range[i].min = ((exp_min * row_time) >> ROW_TIME_PRC) + 1;
	}
	dft->inttime_range.max = dft->hdr.hdr_inttime_range[0].max;
	dft->inttime_range.min = dft->hdr.hdr_inttime_range[0].min;
	dft->sensor_gain_range.max = SENSOR_MAX_GAIN;
	dft->sensor_gain_range.min = SENSOR_MIN_GAIN;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_MAX_GAIN;
	dft->target_sensor_gain_range.min = SENSOR_MIN_GAIN;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 256;
	dft->gain_thr_down = 512;
	dft->max_fps = MAX_FPS;
	dft->min_fps = MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 4600;
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
	/*
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
	*/

	// DBC_level of K05 needs to shift by sensor temperature. We contorl sesnor BLC target to shif.
	// DBC_level changing by temperature and ISO are mutually exclusive

	// Using BLC_B to mapping sensor temperature

	int32_t blc_b = SENSOR_readRegBB(g_i2c_fd[idx.path], 0x4B);
	int32_t blc_b_high = SENSOR_readRegBB(g_i2c_fd[idx.path], 0x4F);

	if (blc_b < 0 || blc_b_high < 0) {
		printf("[Sensor Error] SENSOR_getBlackLevel : SENSOR_readRegBB failed!\n");
		return MPI_FAILURE;
	}
	blc_b = ((blc_b_high & 3) << 8) + blc_b;

	blc_b = CLAMP(blc_b, k_sensor_blc_bin[0], k_sensor_blc_bin[SENSOR_BLC_NUM - 1]);

	int32_t blc_bin = binary_search_bin(blc_b, k_sensor_blc_bin, 0, SENSOR_BLC_NUM - 1);
	int32_t norm = k_sensor_blc_bin[blc_bin] - k_sensor_blc_bin[blc_bin - 1];
	int32_t alpha = blc_b - k_sensor_blc_bin[blc_bin - 1];
	int32_t blc_target = interpolation(k_sensor_blc_val[blc_bin], k_sensor_blc_val[blc_bin - 1], alpha, norm);

	SensCmd cmd[1];
	cmd[0].reg = 0x49;
	cmd[0].val = blc_target;
	uint8_t cmd_num = 1;

	int32_t ret = SENSOR_writeRegBB(g_i2c_fd[idx.path], cmd_num, cmd);
	if (ret != cmd_num) {
		printf("[Sensor Error] SENSOR_getBlackLevel : SENSOR_writeRegBB failed!\n");
		return MPI_FAILURE;
	}

	level->dbc_level = black_level_table.black_level[0];

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
