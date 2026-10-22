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

#define SENSOR_ID (5230) // sensor ID
#define PS5230_BANK_ADDR (0xef) // sensor register bank
#define PS5230_OFFNY1_ADDR (0x0d) // sensor exposure line control(offny1) [7:0]
#define PS5230_OFFNY2_ADDR (0x0c) // sensor exposure line control(offny1) [15:8]
#define PS5230_GAIN1_ADDR (0x79) // sensor gain [7:0]
#define PS5230_GAIN2_ADDR (0x78) // sensor gain [12:8]
#define PS5230_LPF1_ADDR (0x0b) // Line per frame(fps line)[7:0]
#define PS5230_LPF2_ADDR (0x0a) // Line per frame(fps line)[15:8]
#define PS5230_UPDATE_ADDR (0x09) // exposure parameter update

#define PS_BIN (81)
#define EXP_LINE_GAP (3)
#define SENSOR_FRAME_LINES_MAX (3374) // min fps = 10
#define SENSOR_FRAME_LINES_MIN (1124)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (11)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))
#define CLOSE(a, b, c, d) (((c) < (d)) ? (a) : (b))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

static int ps_gain_bin[PS_BIN] = { 128,  132,  137,  141,  146,  152,  158,  164,  171,  178,  186,  195,  205,  215,
	                           227,  241,  256,  264,  273,  282,  293,  303,  315,  328,  341,  356,  372,  390,
	                           410,  431,  455,  482,  512,  529,  546,  565,  585,  607,  630,  655,  683,  712,
	                           745,  780,  819,  862,  910,  964,  1024, 1057, 1092, 1130, 1170, 1214, 1260, 1311,
	                           1365, 1425, 1489, 1560, 1638, 1725, 1820, 1928, 2048, 2114, 2185, 2260, 2341, 2427,
	                           2521, 2621, 2731, 2849, 2979, 3121, 3277, 3449, 3641, 3855, 4096 };

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
		pregs[0].reg_num = 8;

		for (i = 0; i < pregs[0].reg_num; ++i) {
			pregs[0].i2c_data[i].is_update = true;
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = 1;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[0].delay_frm_num = 0;
		pregs[0].i2c_data[0].reg_addr = PS5230_BANK_ADDR;

		pregs[0].i2c_data[1].delay_frm_num = 0;
		pregs[0].i2c_data[1].reg_addr = PS5230_LPF1_ADDR;
		pregs[0].i2c_data[2].delay_frm_num = 0;
		pregs[0].i2c_data[2].reg_addr = PS5230_LPF2_ADDR;

		pregs[0].i2c_data[3].delay_frm_num = 0;
		pregs[0].i2c_data[3].reg_addr = PS5230_OFFNY1_ADDR;
		pregs[0].i2c_data[4].delay_frm_num = 0;
		pregs[0].i2c_data[4].reg_addr = PS5230_OFFNY2_ADDR;

		pregs[0].i2c_data[5].delay_frm_num = 0;
		pregs[0].i2c_data[5].reg_addr = PS5230_GAIN1_ADDR;
		pregs[0].i2c_data[6].delay_frm_num = 0;
		pregs[0].i2c_data[6].reg_addr = PS5230_GAIN2_ADDR;

		pregs[0].i2c_data[7].delay_frm_num = 0;
		pregs[0].i2c_data[7].reg_addr = PS5230_UPDATE_ADDR;

		pregs[0].is_config = true;
	} else {
		for (i = 0; i < pregs[0].reg_num; ++i) {
			if ((pregs[0].i2c_data[i].reg_data) == (pregs[1].i2c_data[i].reg_data)) {
				pregs[0].i2c_data[i].is_update = false;
			} else {
				pregs[0].i2c_data[i].is_update = true;
			}
		}
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	g_sns_state[idx.path]->exp_line[1] = g_sns_state[idx.path]->exp_line[0];
	g_sns_state[idx.path]->frame_line[1] = g_sns_state[idx.path]->frame_line[0];
	g_sns_state[idx.path]->line_pixel[1] = g_sns_state[idx.path]->line_pixel[0];

	return MPI_SUCCESS;
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	g_sensor_state[idx.path].pclk = 76000000;
	g_sensor_state[idx.path].fps_line = 1124;
	g_sensor_state[idx.path].exp_line[0] = 557;
	g_sensor_state[idx.path].frame_line[0] = 1124;
	g_sensor_state[idx.path].line_pixel[0] = 2252;

	int tmp_pclk = (g_sensor_state[idx.path].pclk + (1 << 5)) >> 6;
	g_sensor_state[idx.path].row_time[0] =
	        ((g_sensor_state[idx.path].line_pixel[0] * 500000) + (tmp_pclk >> 1)) / tmp_pclk;

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

	int exp_line = (time_us << 5) / g_sensor_state[idx.path].row_time[0];

	if (exp_line > SENSOR_EXP_LINES_MAX || exp_line < SENSOR_EXP_LINES_MIN) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line = CLAMP(exp_line, SENSOR_EXP_LINES_MIN, SENSOR_EXP_LINES_MAX);
	}

	if (exp_line > g_sensor_state[idx.path].frame_line[0] - EXP_LINE_GAP) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = exp_line;
	*effective_time = (uint32_t)(exp_line * g_sensor_state[idx.path].row_time[0]) >> 5;
	g_inttime = *effective_time;

	uint32_t ny1 = g_sensor_state[idx.path].frame_line[0] - g_sensor_state[idx.path].exp_line[0] - 1;
	g_sns_state[idx.path]->regs_info[0].i2c_data[0].reg_data = 1;
	g_sns_state[idx.path]->regs_info[0].i2c_data[3].reg_data = (ny1 & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[4].reg_data = (ny1 & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[7].reg_data = 1;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	/* min gian = 8(1.5x), max gain = 80(32x)*/
	/* 32 -> 8(1.5x), 48 -> 18(2.25x), 682 -> 80(32x) */

	if (gain < 32) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > 1024) {
		printf("[Sensor Error] Sensor gain bigger than 1024(sensor limit)\n");
		return MPI_FAILURE;
	} else {
		int gain_cmd = (131072 + (gain >> 1)) / gain;
		int target_bin = binary_search_bin(gain_cmd, ps_gain_bin, 0, PS_BIN - 1);
		int next_delta = (ps_gain_bin[target_bin] - gain_cmd);
		int last_delta = (gain_cmd - ps_gain_bin[target_bin - 1]);
		int cmd_gdac = CLOSE(ps_gain_bin[target_bin - 1], ps_gain_bin[target_bin], last_delta, next_delta);

		g_sns_state[idx.path]->regs_info[0].i2c_data[0].reg_data = 1;
		g_sns_state[idx.path]->regs_info[0].i2c_data[5].reg_data = (cmd_gdac & 0xFF);
		g_sns_state[idx.path]->regs_info[0].i2c_data[6].reg_data = (cmd_gdac & 0xFF00) >> 8;
		g_sns_state[idx.path]->regs_info[0].i2c_data[7].reg_data = 1;

		return MPI_SUCCESS;
	}
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

	inttime->max = (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0]) >> 5) - 1;
	inttime->min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> 5) + 1;
	g_sensor_state[idx.path].frame_line[0] = frame_line;

	uint32_t effective_time;
	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime->max, &effective_time);
	} else {
		SENSOR_setInttime(idx, g_inttime, &effective_time);
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].reg_data = 1;
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].reg_data = ((frame_line - 1) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[2].reg_data = ((frame_line - 1) & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[7].reg_data = 1;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int exp_line = ((time_us << 5) + (g_sensor_state[idx.path].row_time[0] >> 1))
	                / g_sensor_state[idx.path].row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[0].reg_data = 1;
	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[1].reg_data = ((frame_line - 1) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[2].reg_data = ((frame_line - 1) & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[7].reg_data = 1;

	int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
	*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;

	uint32_t effective_time;
	SENSOR_setInttime(idx, time_us, &effective_time);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max = ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + 16) >> 5);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0] + 16) >> 5);
	dft->sensor_gain_range.max = 1024;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = 1024;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 248;
	dft->gain_thr_down = 376;
	dft->max_fps = 30;
	dft->min_fps = 10;
	dft->speed = 32;
	dft->tolerance = 1280;
	dft->brightness = 5800;
	dft->exp_value = 528000;

	return MPI_SUCCESS;
}

static int SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	dft->csm.sat_table[0] = 160;
	dft->csm.sat_table[1] = 150;
	dft->csm.sat_table[2] = 130;
	dft->csm.sat_table[3] = 110;
	dft->csm.sat_table[4] = 100;
	dft->csm.sat_table[5] = 95;
	dft->csm.sat_table[6] = 90;
	dft->csm.sat_table[7] = 75;
	dft->csm.sat_table[8] = 75;
	dft->csm.sat_table[9] = 75;
	dft->csm.sat_table[10] = 75;

	dft->shp.shp_table[0] = 191;
	dft->shp.shp_table[1] = 78;
	dft->shp.shp_table[2] = 45;
	dft->shp.shp_table[3] = 0;
	dft->shp.shp_table[4] = 0;
	dft->shp.shp_table[5] = 0;
	dft->shp.shp_table[6] = 0;
	dft->shp.shp_table[7] = 0;
	dft->shp.shp_table[8] = 0;
	dft->shp.shp_table[9] = 0;
	dft->shp.shp_table[10] = 0;

	dft->nr.y_level_3d[0] = 32;
	dft->nr.y_level_3d[1] = 96;
	dft->nr.y_level_3d[2] = 120;
	dft->nr.y_level_3d[3] = 255;
	dft->nr.y_level_3d[4] = 255;
	dft->nr.y_level_3d[5] = 255;
	dft->nr.y_level_3d[6] = 255;
	dft->nr.y_level_3d[7] = 255;
	dft->nr.y_level_3d[8] = 255;
	dft->nr.y_level_3d[9] = 255;
	dft->nr.y_level_3d[10] = 255;

	dft->nr.c_level_3d[0] = 32;
	dft->nr.c_level_3d[1] = 96;
	dft->nr.c_level_3d[2] = 120;
	dft->nr.c_level_3d[3] = 255;
	dft->nr.c_level_3d[4] = 255;
	dft->nr.c_level_3d[5] = 255;
	dft->nr.c_level_3d[6] = 255;
	dft->nr.c_level_3d[7] = 255;
	dft->nr.c_level_3d[8] = 255;
	dft->nr.c_level_3d[9] = 255;
	dft->nr.c_level_3d[10] = 255;

	dft->nr.y_level_2d[0] = 100;
	dft->nr.y_level_2d[1] = 100;
	dft->nr.y_level_2d[2] = 100;
	dft->nr.y_level_2d[3] = 100;
	dft->nr.y_level_2d[4] = 100;
	dft->nr.y_level_2d[5] = 100;
	dft->nr.y_level_2d[6] = 100;
	dft->nr.y_level_2d[7] = 100;
	dft->nr.y_level_2d[8] = 100;
	dft->nr.y_level_2d[9] = 100;
	dft->nr.y_level_2d[10] = 100;

	dft->nr.c_level_2d[0] = 150;
	dft->nr.c_level_2d[1] = 150;
	dft->nr.c_level_2d[2] = 150;
	dft->nr.c_level_2d[3] = 150;
	dft->nr.c_level_2d[4] = 150;
	dft->nr.c_level_2d[5] = 150;
	dft->nr.c_level_2d[6] = 150;
	dft->nr.c_level_2d[7] = 150;
	dft->nr.c_level_2d[8] = 150;
	dft->nr.c_level_2d[9] = 150;
	dft->nr.c_level_2d[10] = 150;

	dft->gamma.mode = 0;

	dft->te.noise_cstr[0] = 64;
	dft->te.noise_cstr[1] = 128;
	dft->te.noise_cstr[2] = 256;
	dft->te.noise_cstr[3] = 512;
	dft->te.noise_cstr[4] = 640;
	dft->te.noise_cstr[5] = 768;
	dft->te.noise_cstr[6] = 896;
	dft->te.noise_cstr[7] = 1024;
	dft->te.noise_cstr[8] = 1024;
	dft->te.noise_cstr[9] = 1024;
	dft->te.noise_cstr[10] = 1024;

	dft->te.curve[0] = 0;
	dft->te.curve[1] = 20;
	dft->te.curve[2] = 40;
	dft->te.curve[3] = 80;
	dft->te.curve[4] = 130;
	dft->te.curve[5] = 180;
	dft->te.curve[6] = 230;
	dft->te.curve[7] = 280;
	dft->te.curve[8] = 340;
	dft->te.curve[9] = 460;
	dft->te.curve[10] = 580;
	dft->te.curve[11] = 600;
	dft->te.curve[12] = 740;
	dft->te.curve[13] = 880;
	dft->te.curve[14] = 1030;
	dft->te.curve[15] = 1200;
	dft->te.curve[16] = 1370;
	dft->te.curve[17] = 1540;
	dft->te.curve[18] = 1700;
	dft->te.curve[19] = 1860;
	dft->te.curve[20] = 2048;
	dft->te.curve[21] = 2176;
	dft->te.curve[22] = 2304;
	dft->te.curve[23] = 2432;
	dft->te.curve[24] = 2560;
	dft->te.curve[25] = 2816;
	dft->te.curve[26] = 3072;
	dft->te.curve[27] = 3328;
	dft->te.curve[28] = 3584;
	dft->te.curve[29] = 3840;
	dft->te.curve[30] = 4096;
	dft->te.curve[31] = 4352;
	dft->te.curve[32] = 4608;
	dft->te.curve[33] = 4864;
	dft->te.curve[34] = 5120;
	dft->te.curve[35] = 5376;
	dft->te.curve[36] = 5632;
	dft->te.curve[37] = 5888;
	dft->te.curve[38] = 6144;
	dft->te.curve[39] = 6400;
	dft->te.curve[40] = 6656;
	dft->te.curve[41] = 7168;
	dft->te.curve[42] = 7680;
	dft->te.curve[43] = 8192;
	dft->te.curve[44] = 8704;
	dft->te.curve[45] = 9216;
	dft->te.curve[46] = 9728;
	dft->te.curve[47] = 10240;
	dft->te.curve[48] = 10752;
	dft->te.curve[49] = 11264;
	dft->te.curve[50] = 11776;
	dft->te.curve[51] = 12288;
	dft->te.curve[52] = 12800;
	dft->te.curve[53] = 13312;
	dft->te.curve[54] = 13824;
	dft->te.curve[55] = 14336;
	dft->te.curve[56] = 14848;
	dft->te.curve[57] = 15360;
	dft->te.curve[58] = 15872;
	dft->te.curve[59] = 16384;

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
