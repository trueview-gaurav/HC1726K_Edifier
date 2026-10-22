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

// Change to 2 if it needs to support individual controls on stitched sensors.
// Some procedures need to be reviewed.
#define DIP_MAX_PATH_NUM (1)

#define SENSOR_ID (2331) // sensor ID

#define SC2331_VMAX1_ADDR (0x320E) // vmax(fps line) [6:0] => [15:8]
#define SC2331_VMAX2_ADDR (0x320F) // vmax(fps line) [7:0] => [7:0]

#define SC2331_SHS1_ADDR (0x3E00) // sensor exposure line control(shs1) [3:0] => [15:12]
#define SC2331_SHS2_ADDR (0x3E01) // sensor exposure line control(shs2) [7:0] => [11: 4]
#define SC2331_SHS3_ADDR (0x3E02) // sensor exposure line control(shs3) [7:4] => [ 3: 0]

#define SC2331_AC_GAIN_ADDR (0x3E08) // sensor analog coarse gain [7:0]
#define SC2331_DC_GAIN_ADDR (0x3E06) // sensor digital coarse gain [7:0]
#define SC2331_DF_GAIN_ADDR (0x3E07) // sensor digital fine gain [7:0]

#ifdef SNS_SLAVE_OUT_OF_SYNC
#define SC2331_FDELAY1_ADDR (0x3230)
#define SC2331_FDELAY2_ADDR (0x3231)
#endif

#define EXP_LINE_GAP (7) // Sensor Datasheet spec 2.2.2 AEC Max info : 2 * {16'h320e, 16'h320f} - 'd13
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1) // Sensor Datasheet spec 2.2.2 AEC Min info : 2
#define SENSOR_EXP_LINE_SHIF (1) // Sensor Datasheet spec 2.2.2 AEC step size : 1 step size = 0 or 0.5 step size = 1

#define ROW_TIME_PRC (5) // Significant Figures, This value is relevant to the calculation and should not be modified.
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (16) // Significant Figures, This value is relevant to the calculation and should not be modified.
#define FPS_UNIT (1 << FPS_PRC)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

typedef enum {
#ifdef SNS_MASTER_MODE
	IDX_DELAYED_VMAX_1,
	IDX_DELAYED_VMAX_2,
#endif
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_AC,
	IDX_DC,
	IDX_DF,
#ifdef SNS_SLAVE_OUT_OF_SYNC
	IDX_FDELAY_DELAYED_1,
	IDX_FDELAY_DELAYED_2,
	IDX_FDELAY_1,
	IDX_FDELAY_2,
#endif
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0] };

static int32_t g_inttime = 16500;

static int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
{
	MPI_SNS_REGS_TABLE_S *regs = g_sns_state[0]->regs_info;
	SensCmd cmd[32];
	int32_t ret;

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

static int32_t SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[0]->regs_info;
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
#ifdef SENSOR_I2C_SLAVE_ADDR1
			if (idx.path == 1) {
				pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR1;
			}
#endif
#ifdef SENSOR_I2C_SLAVE_ADDR2
			if (idx.path == 2) {
				pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR2;
			}
#endif
			pregs[0].i2c_data[i].reg_addr_byte_num = 2;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

#ifdef SNS_MASTER_MODE
		pregs[0].i2c_data[IDX_DELAYED_VMAX_1].delay_frm_num = 1;
		pregs[0].i2c_data[IDX_DELAYED_VMAX_1].reg_addr = SC2331_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_DELAYED_VMAX_1].is_update = false;
		pregs[0].i2c_data[IDX_DELAYED_VMAX_2].delay_frm_num = 1;
		pregs[0].i2c_data[IDX_DELAYED_VMAX_2].reg_addr = SC2331_VMAX2_ADDR;
		pregs[0].i2c_data[IDX_DELAYED_VMAX_2].is_update = false;
#endif

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = SC2331_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = SC2331_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = SC2331_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = SC2331_SHS2_ADDR;
		pregs[0].i2c_data[IDX_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_3].reg_addr = SC2331_SHS3_ADDR;

		pregs[0].i2c_data[IDX_AC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_AC].reg_addr = SC2331_AC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_DC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DC].reg_addr = SC2331_DC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_DF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_DF].reg_addr = SC2331_DF_GAIN_ADDR;

#ifdef SNS_SLAVE_OUT_OF_SYNC
		pregs[0].i2c_data[IDX_FDELAY_DELAYED_1].delay_frm_num = 1;
		pregs[0].i2c_data[IDX_FDELAY_DELAYED_1].reg_addr = SC2331_FDELAY1_ADDR;
		pregs[0].i2c_data[IDX_FDELAY_DELAYED_1].is_update = false;
		pregs[0].i2c_data[IDX_FDELAY_DELAYED_2].delay_frm_num = 1;
		pregs[0].i2c_data[IDX_FDELAY_DELAYED_2].reg_addr = SC2331_FDELAY2_ADDR;
		pregs[0].i2c_data[IDX_FDELAY_DELAYED_1].is_update = false;

		pregs[0].i2c_data[IDX_FDELAY_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_FDELAY_1].reg_addr = SC2331_FDELAY1_ADDR;
		pregs[0].i2c_data[IDX_FDELAY_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_FDELAY_2].reg_addr = SC2331_FDELAY2_ADDR;
#endif

		pregs[0].is_config = true;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	for (int i = 0; i < IDX_NUM; i++) {
		switch (pregs[0].i2c_data[i].delay_frm_num) {
		case 1:
			memcpy(&regs->i2c_data[i], &pregs[1].i2c_data[i], sizeof(MPI_I2C_DATA_S));
			break;
		default:;
		}
	}
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	g_sns_state[0]->exp_line[1] = g_sns_state[0]->exp_line[0];
	g_sns_state[0]->frame_line[1] = g_sns_state[0]->frame_line[0];
	g_sns_state[0]->line_pixel[1] = g_sns_state[0]->line_pixel[0];

	for (i = 0; i < pregs[0].reg_num; ++i) {
		pregs[0].i2c_data[i].is_update = false;
	}

	return MPI_SUCCESS;
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	int i;

	for (i = 0; i < DIP_MAX_PATH_NUM; i++) {
		MPI_SNS_REGS_TABLE_S init_regs = { 0 };

		g_sensor_state[i].sensor_gain = SENSOR_GAIN_MIN;
		g_sensor_state[i].pclk = PCLK;
		g_sensor_state[i].fps_line = INIT_FRAME_LINE;
		g_sensor_state[i].frame_line[0] = INIT_FRAME_LINE;
		g_sensor_state[i].line_pixel[0] = INIT_LINE_LEN;

		int32_t tmp_pclk = (g_sensor_state[i].pclk + (1 << ROW_TIME_PRC)) >> (ROW_TIME_PRC + 1);
		assert(tmp_pclk > 0 && "[Sensor Error] tmp_pclk must be greater than than 0.\n");

		g_sensor_state[i].row_time[0] =
		        ((g_sensor_state[i].line_pixel[0] * 500000) + (tmp_pclk >> 1)) / tmp_pclk;

		g_sensor_state[i].exp_line[0] = ((g_inttime << ROW_TIME_PRC) + (g_sensor_state[i].row_time[0] >> 1)) /
		                                g_sensor_state[i].row_time[0];

		g_sensor_state[i].exp_line[1] = g_sensor_state[i].exp_line[0];
		g_sensor_state[i].frame_line[1] = g_sensor_state[i].frame_line[0];
		g_sensor_state[i].line_pixel[1] = g_sensor_state[i].line_pixel[0];
		g_sensor_state[i].row_time[1] = g_sensor_state[i].row_time[0];

		g_sensor_state[i].regs_info[0] = init_regs;
		g_sensor_state[i].regs_info[1] = init_regs;
		g_sensor_state[i].regs_info[0].is_config = false;
		g_sensor_state[i].regs_info[1].is_config = false;
	}
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than than 0.\n");
	assert(g_sensor_state[0].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row time) must be greater than than 0.\n");
	//exp_line_addr value = exp_line * 2
	int32_t line_shif = SENSOR_EXP_LINE_SHIF;
	int32_t exp_line_x2 = (time_us << (ROW_TIME_PRC + line_shif)) / g_sensor_state[0].row_time[0];

	//exp_line_addr value max = fps_line * 2 - EXP_LINE_GAP
	if (exp_line_x2 > (SENSOR_EXP_LINES_MAX << line_shif) || (exp_line_x2 < (SENSOR_EXP_LINES_MIN << line_shif))) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line_x2 =
		        CLAMP(exp_line_x2, (SENSOR_EXP_LINES_MIN << line_shif), (SENSOR_EXP_LINES_MAX << line_shif));
	}

	if (exp_line_x2 > (g_sensor_state[0].frame_line[0] << line_shif) - (EXP_LINE_GAP << line_shif)) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[0].exp_line[0] = (exp_line_x2 >> line_shif);
	uint32_t time_tmp = (uint32_t)exp_line_x2 * g_sensor_state[0].row_time[0];
	time_tmp = (time_tmp + (1 << (ROW_TIME_PRC + line_shif - 1))) >> (ROW_TIME_PRC + line_shif);
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	int value = exp_line_x2 << 4;

	g_sns_state[0]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (value & 0x0F0000) >> 16;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_SHS_3].reg_data = (value & 0xF0);

	g_sns_state[0]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_SHS_3].is_update = true;
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	g_sns_state[0]->sensor_gain = gain;

	/* a_gain max and d_gain min*/
	int ac_gain = 0x03;
	int dc_gain = 0x00;
	int df_gain = 0x80;

	// spec 2.2.3
	const int ac_step[] = { 256, 512, 1024, 2048, 4096, 8192 }; // x1, x2, x4, x8, x16, x32
	const int ac_val[] = { 0x00, 0x08, 0x09, 0x0B, 0x0F, 0x1F };

	const int dc_step[] = { 256, 512, 1024 }; // x1, x2, x4
	const int dc_val[] = { 0x00, 0x01, 0x03 };

	const int df_step[] = { 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 }; // x1, x2, x4, x8, x16, x32
	const int df_val[] = {
		0x08, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400
	}; // step*8: 1, 2, 4, 8, 16, 32, 64, 128
	const int df_base_step = 0x04; // 1/32 = 4 base step
	const int df_base = 0x80; // 0x80 start
	// const int df_max = 0xFF; // DIG FINE GAIN = 1/128, (0x80~0xFF)/1 = 128, 0x100-1=0xFF
	const int df_max = 0xFC; // DIG FINE GAIN = 1/32, (0x80~0xFF)/4 = 32, 0x100-4=0xFC

	int ac_gain_tmp;
	int dc_gain_tmp;
	int tmp;
	int tmp_gain = gain * 8; // ac_step[0] = 256/32 = 8

	if (gain < SENSOR_GAIN_MIN) {
		printf("[Sensor Error] Sensor gain must be greater than %d\n", SENSOR_GAIN_MIN);
		return -EINVAL;
	} else if (gain > SENSOR_GAIN_MAX) {
		printf("[Sensor Error] Sensor gain must be lesser than %d (sensor limit)\n", SENSOR_GAIN_MAX);
		return -EINVAL;
	}

	// analog coarse gain
	tmp = binary_search_nr(tmp_gain, ac_step, 0, sizeof(ac_step) / sizeof(int));
	ac_gain = ac_val[tmp];
	tmp_gain = ((tmp_gain * ac_step[0]) + (ac_step[tmp] >> 1)) / ac_step[tmp];
	ac_gain_tmp = ac_step[tmp] / ac_step[0];

	// digital coarse gain
	tmp = binary_search_nr(tmp_gain, dc_step, 0, sizeof(dc_step) / sizeof(int));
	dc_gain = dc_val[tmp];
	tmp_gain = ((tmp_gain * dc_step[0]) + (dc_step[tmp] >> 1)) / dc_step[tmp];
	dc_gain_tmp = ac_step[tmp] / ac_step[0];

	// digital fine gain
	df_gain = 256 * ac_gain_tmp * dc_gain_tmp; // 32 * 8 = 256
	tmp = binary_search_nr(df_gain, df_step, 0, sizeof(df_step) / sizeof(int));

	df_gain = gain * 8;
	tmp_gain = ((df_gain - df_step[tmp]) / df_val[tmp]) * df_base_step + df_base;
	df_gain = tmp_gain > df_max ? df_max : tmp_gain;

	g_sns_state[0]->regs_info[0].i2c_data[IDX_AC].reg_data = ac_gain;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DC].reg_data = dc_gain;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DF].reg_data = df_gain;

	g_sns_state[0]->regs_info[0].i2c_data[IDX_AC].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DC].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DF].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	assert(fps > 0 && "[Sensor Error] FPS must be greater than 0.\n");
	assert(g_sensor_state[0].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[0].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t sec_line; /* In one second, number of sensor can output lines */
#ifdef SNS_SLAVE_OUT_OF_SYNC
	uint32_t f_delay = 2; // This value is determined by sensor settings
	uint32_t f_delay_next = f_delay;
	uint32_t prev_frame_line = g_sensor_state[0].frame_line[0];
#endif
#ifdef SNS_MASTER_MODE
	uint32_t prev_frame_line = g_sensor_state[0].frame_line[0];
#endif

	fps = fps * FPS_UNIT;
	sec_line = ((g_sensor_state[0].pclk + (g_sensor_state[0].line_pixel[0] >> 1)) / g_sensor_state[0].line_pixel[0])
	           << FPS_PRC;
	assert(sec_line > 0 && "[Sensor Error] sec_line must be greater than than 0.\n");
	frame_line = (sec_line + ((int32_t)fps >> 1)) / (int32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[0].frame_line[0] = frame_line;

	inttime->max =
	        (((frame_line - EXP_LINE_GAP) * g_sensor_state[0].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	inttime->min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[0].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);

	uint32_t effective_time;
	if (g_sensor_state[0].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime->max, &effective_time);
	} else {
		SENSOR_setInttime(idx, g_inttime, &effective_time);
	}

#ifdef SNS_MASTER_MODE
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_2].reg_data = (frame_line & 0xFF);
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	if (prev_frame_line > frame_line) {
		frame_line = prev_frame_line - ((prev_frame_line - frame_line) / 2);
		g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

		g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_2].is_update = true;
	}

	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
#else
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
#endif

#ifdef SNS_SLAVE_OUT_OF_SYNC
	f_delay += frame_line / 2;
	f_delay_next = f_delay;

	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_1].reg_data = (f_delay_next & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_2].reg_data = (f_delay_next & 0xFF);
	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].reg_data = (f_delay & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].reg_data = (f_delay & 0xFF);

	if (prev_frame_line > frame_line) {
		f_delay -= 0x10;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].reg_data = (f_delay & 0x7F00) >> 8;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].reg_data = (f_delay & 0xFF);
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_2].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].is_update = true;
	} else {
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].is_update = true;
	}
#endif
	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[0].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[0].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int32_t exp_line =
	        ((time_us << ROW_TIME_PRC) + (g_sensor_state[0].row_time[0] >> 1)) / g_sensor_state[0].row_time[0];
	int32_t frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");
#ifdef SNS_SLAVE_OUT_OF_SYNC
	int f_delay = 2; // This value is determined by sensor settings
	int f_delay_next = f_delay;
	uint32_t prev_frame_line = g_sensor_state[0].frame_line[0];
#endif
#ifdef SNS_MASTER_MODE
	uint32_t prev_frame_line = g_sensor_state[0].frame_line[0];
#endif

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[0].frame_line[0] = frame_line;

#ifdef SNS_MASTER_MODE
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_2].reg_data = (frame_line & 0xFF);
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	if (prev_frame_line > frame_line) {
		frame_line = prev_frame_line - ((prev_frame_line - frame_line) / 2);
		g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

		g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_DELAYED_VMAX_2].is_update = true;
	}

	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
#else
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
#endif

#ifdef SNS_SLAVE_OUT_OF_SYNC
	f_delay += frame_line / 2;
	f_delay_next = f_delay;

	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_1].reg_data = (f_delay_next & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_2].reg_data = (f_delay_next & 0xFF);
	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].reg_data = (f_delay & 0x7F00) >> 8;
	g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].reg_data = (f_delay & 0xFF);

	if (prev_frame_line > frame_line) {
		f_delay -= 0x10;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].reg_data = (f_delay & 0x7F00) >> 8;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].reg_data = (f_delay & 0xFF);
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_DELAYED_2].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].is_update = true;
	} else {
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_1].is_update = true;
		g_sns_state[0]->regs_info[0].i2c_data[IDX_FDELAY_2].is_update = true;
	}
#endif

	int32_t temp = (frame_line * g_sensor_state[0].line_pixel[0]);
	*fps = (float)g_sensor_state[0].pclk / (float)temp;

	uint32_t effective_time;
	SENSOR_setInttime(idx, time_us, &effective_time);

	return MPI_SUCCESS;
}

static int32_t SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[0].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[0].row_time[0]) >> ROW_TIME_PRC) + 1;
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
	dft->min_fps = MIN_FPS;
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

	for (int i = 0; i < 11; i++) {
		array[i] = black_level_table.black_level[i];
	}

	int32_t black_level;
	uint32_t gain = g_sns_state[0]->sensor_gain;
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

#ifdef SNS2
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS2_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};

__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS2_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif
