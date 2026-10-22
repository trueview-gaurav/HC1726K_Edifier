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

#define DIP_MAX_PATH_NUM        (2)

#define SENSOR_ID (2232) // sensor ID

#define SC2232_SHS1_ADDR (0x3E02) // sensor exposure line control(shs1) [7:4]
#define SC2232_SHS2_ADDR (0x3E01) // sensor exposure line control(shs2) [15:8]
#define SC2232_SHS3_ADDR (0x3E00) // sensor exposure line control(shs3) [19:16]
#define SC2232_PRECHAGE (0x3314) // exp_line > 1104 = 0x04, exp_line < 592 = 0x14

#define SC2232_GAIN_MODE_ADDR (0x3E03) // sensor gain mode
#define SC2232_AC_GAIN_ADDR (0x3E08) // sensor analog coarse gain [4:2]
#define SC2232_AF_GAIN_ADDR (0x3E09) // sensor analog fine gain [7:0]
#define SC2232_DC_GAIN_ADDR (0x3E06) // sensor digital coarse gain [3:0]
#define SC2232_DF_GAIN_ADDR (0x3E07) // sensor digital fine gain [7:0]
#define SC2232_DENOISE_LOGIC_1 (0x3301) // denoise logic 1
#define SC2232_DENOISE_LOGIC_2 (0x3632) // denoise logic 2

#define SC2232_VMAX1_ADDR (0x320F) // vmax(fps line)[7:0]
#define SC2232_VMAX2_ADDR (0x320E) // vmax(fps line)[15:8]

#define SC2232_EXP_UPDATE (0x3812) // Update exposure setting in same frame

#define SC2232_FRAME_DELAY (0x3802) //SC223 frame delay

#define EXP_LINE_GAP (2)
#define SENSOR_FRAME_LINES_MAX (7500) // min fps = 5
#define SENSOR_FRAME_LINES_MIN (1250)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (3)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (7)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)

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

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

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
		pregs[0].reg_num = 15;

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

		pregs[0].i2c_data[0].delay_frm_num = 0;
		pregs[0].i2c_data[0].reg_addr = SC2232_VMAX1_ADDR;
		pregs[0].i2c_data[1].delay_frm_num = 0;
		pregs[0].i2c_data[1].reg_addr = SC2232_VMAX2_ADDR;

		pregs[0].i2c_data[2].delay_frm_num = 0;
		pregs[0].i2c_data[2].reg_addr = SC2232_FRAME_DELAY;
		pregs[0].i2c_data[2].reg_data = 0x00;

		pregs[0].i2c_data[3].delay_frm_num = 0;
		pregs[0].i2c_data[3].reg_addr = SC2232_SHS1_ADDR;
		pregs[0].i2c_data[4].delay_frm_num = 0;
		pregs[0].i2c_data[4].reg_addr = SC2232_SHS2_ADDR;
		pregs[0].i2c_data[5].delay_frm_num = 0;
		pregs[0].i2c_data[5].reg_addr = SC2232_SHS3_ADDR;

		pregs[0].i2c_data[6].delay_frm_num = 0;
		pregs[0].i2c_data[6].reg_addr = SC2232_PRECHAGE;

		pregs[0].i2c_data[7].delay_frm_num = 0;
		pregs[0].i2c_data[7].reg_addr = SC2232_AC_GAIN_ADDR;
		pregs[0].i2c_data[8].delay_frm_num = 0;
		pregs[0].i2c_data[8].reg_addr = SC2232_AF_GAIN_ADDR;
		pregs[0].i2c_data[9].delay_frm_num = 0;
		pregs[0].i2c_data[9].reg_addr = SC2232_DC_GAIN_ADDR;
		pregs[0].i2c_data[10].delay_frm_num = 0;
		pregs[0].i2c_data[10].reg_addr = SC2232_DF_GAIN_ADDR;
		pregs[0].i2c_data[11].delay_frm_num = 0;
		pregs[0].i2c_data[11].reg_addr = SC2232_EXP_UPDATE;
		pregs[0].i2c_data[11].reg_data = 0x00;
		pregs[0].i2c_data[12].delay_frm_num = 0;
		pregs[0].i2c_data[12].reg_addr = SC2232_DENOISE_LOGIC_1;
		pregs[0].i2c_data[13].delay_frm_num = 0;
		pregs[0].i2c_data[13].reg_addr = SC2232_DENOISE_LOGIC_2;
		pregs[0].i2c_data[14].delay_frm_num = 0;
		pregs[0].i2c_data[14].reg_addr = SC2232_EXP_UPDATE;
		pregs[0].i2c_data[14].reg_data = 0x30;

		pregs[0].is_config = true;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	g_sns_state[idx.path]->exp_line[1]   = g_sns_state[idx.path]->exp_line[0];
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
	g_sensor_state[idx.path].pclk = 78000000;
	g_sensor_state[idx.path].fps_line = 1250;
	g_sensor_state[idx.path].frame_line[0] = 1250;
	g_sensor_state[idx.path].line_pixel[0] = 2080;

	int tmp_pclk = (g_sensor_state[idx.path].pclk + (1 << ROW_TIME_PRC)) >> (ROW_TIME_PRC + 1);

	assert(tmp_pclk > 0 && "[Sensor Error] tmp_pclk must be greater than than 0.\n");

	g_sensor_state[idx.path].row_time[0] =
	        ((g_sensor_state[idx.path].line_pixel[0] * 500000) + (tmp_pclk >> 1)) / tmp_pclk;

	g_sensor_state[idx.path].exp_line[0] = ((16500 << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1))
	                                       / g_sensor_state[idx.path].row_time[0];

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
	int line_shif = 1;
	int exp_line_x2 = (time_us << (ROW_TIME_PRC + line_shif)) / g_sensor_state[idx.path].row_time[0];

	//exp_line_addr value max = fps_line * 2 - 4
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

	int value = exp_line_x2 << 4;
	g_sns_state[idx.path]->regs_info[0].i2c_data[3].reg_data = value & 0xFF;
	g_sns_state[idx.path]->regs_info[0].i2c_data[4].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[5].reg_data = (value & 0xF0000) >> 16;

	if (exp_line_x2 < 592) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[6].reg_data = 0x14;
	} else if (exp_line_x2 > 1104) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[6].reg_data = 0x04;
	} else {
		g_sns_state[idx.path]->regs_info[0].i2c_data[6].reg_data = 0x08;
	}

	for (int i = 3; i < 7; i++) {
		g_sns_state[idx.path]->regs_info[0].i2c_data[i].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	g_sns_state[idx.path]->sensor_gain = gain;

	/* a_gain max and d_gain min*/
	int ac_gain = 7;
	int af_gain = 31;
	int dc_gain = 0;
	int df_gain = 128;
	int a_gain = 16; // 4 digit decimal, 16 means 1x
	int d_gain = 128; // 7 digit decimal, 128 means 1x
	int denoise_1 = 0x12;
	int denoise_2 = 0x08;

	/* min gian = 32(1x), max gain = 15376(480.5x)*/
	if (gain < 32) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > 15376) {
		printf("[Sensor Error] Sensor gain bigger than 15376(sensor limit)\n");
		return MPI_FAILURE;
	} else if ((32 <= gain) && (gain < 497)) {
		/* d_gain = 1x. Only a_gain work[32~496(1x~15.5x)]*/
		if (gain < 64) {
			//gain < 2
			ac_gain = 0; //1x
			af_gain = gain >> 1;
			a_gain = af_gain;
			denoise_1 = 0x12;
			denoise_2 = 0x08;
		} else if (gain < 128) {
			//2 <= gain < 4
			ac_gain = 1; //2x
			af_gain = gain >> 2;
			a_gain = (af_gain << 1);
			denoise_1 = 0x20;
			denoise_2 = 0x08;
		} else if (gain < 256) {
			//4 <= gain < 8x
			ac_gain = 3; //4x
			af_gain = gain >> 3;
			a_gain = (af_gain << 2);
			denoise_1 = 0x28;
			denoise_2 = 0x08;
		} else if (gain == 496) {
			//gain = 15.5x
			ac_gain = 7; //8x
			af_gain = 31;
			a_gain = 248;
			denoise_1 = 0x64;
			denoise_2 = 0x48;
		} else {
			//8 <= gain < 15.5x
			ac_gain = 7; //8x
			af_gain = gain >> 4;
			a_gain = (af_gain << 3);
			denoise_1 = 0x64;
			denoise_2 = 0x08;
		}
		dc_gain = 0; //1x
		df_gain = ((gain << 9) + (a_gain << 2)) / (a_gain << 3);

	} else if ((497 <= gain) && (gain <= 15376)) {
		/* a_gain is max(15.5). Just calculate d_gain*/
		a_gain = 248;
		ac_gain = 7;
		af_gain = 31;
		denoise_1 = 0x64;
		denoise_2 = 0x48;
		d_gain = ((gain << 7) + 248) / 496; //d_gain = gain / 15.5x
		if (gain < 992) {
			//gain < 31x
			dc_gain = 0; //1x
			df_gain = d_gain;
		} else if (gain < 1984) {
			//gain < 62x
			dc_gain = 1; //2x
			df_gain = (d_gain + 1) >> 1;
		} else if (gain < 3968) {
			//gain < 124x
			dc_gain = 3; //4x
			df_gain = (d_gain + (1 << 1)) >> 2;
		} else if (gain < 7936) {
			//gain < 248x
			dc_gain = 7; //8x
			df_gain = (d_gain + (1 << 2)) >> 3;
		} else {
			//gain <= 480.5
			dc_gain = 15; //16x
			df_gain = (d_gain + (1 << 3)) >> 4;
		}
	} else {
		printf("[Sensor Error] Sensor gain impossible path\n");
		return MPI_FAILURE;
	}

	uint8_t a_def = 3;
	g_sns_state[idx.path]->regs_info[0].i2c_data[7].reg_data = ((ac_gain << 2) | (int)a_def);
	g_sns_state[idx.path]->regs_info[0].i2c_data[8].reg_data = af_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[9].reg_data = dc_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[10].reg_data = df_gain;

	g_sns_state[idx.path]->regs_info[0].i2c_data[12].reg_data = denoise_1;
	g_sns_state[idx.path]->regs_info[0].i2c_data[13].reg_data = denoise_2;

	for (int i = 7; i < 15; i++) {
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

	fps = fps * 32768;
	sec_line = ((g_sensor_state[idx.path].pclk + (g_sensor_state[idx.path].line_pixel[0] >> 1)) /
	            g_sensor_state[idx.path].line_pixel[0]) << 15;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");

	frame_line = (sec_line + ((int)fps >> 1)) / (int)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}
	g_sensor_state[idx.path].frame_line[0] = frame_line;

	inttime->max = (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1))
	                >> ROW_TIME_PRC);
	inttime->min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1))
	                >> ROW_TIME_PRC);

	uint32_t effective_time;
	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime->max, &effective_time);
	} else {
		SENSOR_setInttime(idx, g_inttime, &effective_time);
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].reg_data = (g_sensor_state[idx.path].frame_line[0] & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].reg_data = (g_sensor_state[idx.path].frame_line[0] & 0xFF00) >> 8;

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].is_update = true;

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

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[0].reg_data = (g_sensor_state[idx.path].frame_line[0] & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].reg_data = (g_sensor_state[idx.path].frame_line[0] & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].is_update = true;

	int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;

	uint32_t effective_time;
	SENSOR_setInttime(idx, time_us, &effective_time);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max = ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1))
	                          >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1))
	                          >> ROW_TIME_PRC);
	dft->sensor_gain_range.max = 15376;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = 15376;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 2048;
	dft->gain_thr_down = 2176;
	dft->max_fps = 30;
	dft->min_fps = 5;
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
