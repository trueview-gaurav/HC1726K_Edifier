/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor.h"
#include "sensor_settings.h"
#include "sensor_params.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "l_sensor_cal.h"

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (301) // sensor ID

#define SC301IOT_VMAX1_ADDR (0x320E) // vmax(fps line) [14:8]
#define SC301IOT_VMAX2_ADDR (0x320F) // vmax(fps line) [7:0]

#define SC301IOT_L_SHS1_ADDR (0x3E00) // sensor exposure line control(shs1) [3:0] => [15:12]
#define SC301IOT_L_SHS2_ADDR (0x3E01) // sensor exposure line control(shs2) [7:0] => [11: 4]
#define SC301IOT_L_SHS3_ADDR (0x3E02) // sensor exposure line control(shs3) [7:4] => [ 3: 0]

#define SC301IOT_S_SHS1_ADDR (0x3E22) // sensor exposure line control(shs1) [3:0] => [15:12]
#define SC301IOT_S_SHS2_ADDR (0x3E04) // sensor exposure line control(shs2) [7:0] => [11: 4]
#define SC301IOT_S_SHS3_ADDR (0x3E05) // sensor exposure line control(shs3) [7:4] => [ 3: 0]

#define EXP_LINE_GAP (11)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2)
#define SENSOR_EXP_LINE_SHIF (0)

#define SC301IOT_GAIN_MODE_ADDR (0x3E03) // sensor gain mode 4'hb

#define SC301IOT_L_AC_GAIN_ADDR (0x3E09) // sensor analog coarse gain
#define SC301IOT_L_DC_GAIN_ADDR (0x3E06) // sensor digital coarse gain
#define SC301IOT_L_DF_GAIN_ADDR (0x3E07) // sensor digital fine gain

#define SC301IOT_S_AC_GAIN_ADDR (0x3E13) // sensor analog coarse gain
#define SC301IOT_S_DC_GAIN_ADDR (0x3E10) // sensor digital coarse gain
#define SC301IOT_S_DF_GAIN_ADDR (0x3E11) // sensor digital fine gain

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (16)
#define FPS_UNIT (1 << FPS_PRC)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_L_SHS_1,
	IDX_L_SHS_2,
	IDX_L_SHS_3,
	IDX_S_SHS_1,
	IDX_S_SHS_2,
	IDX_S_SHS_3,
	IDX_L_AC,
	IDX_L_DC,
	IDX_L_DF,
	IDX_S_AC,
	IDX_S_DC,
	IDX_S_DF,
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int32_t g_inttime = 16500;

int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
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

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

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
			// pregs[0].i2c_data[i].is_update = true;

#if defined(DUAL_SENSOR_SUPPORT) || defined(CONFIG_DUAL_SENSOR_SUPPORT)
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
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = SC301IOT_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = SC301IOT_VMAX2_ADDR;

		pregs[0].i2c_data[IDX_L_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_1].reg_addr = SC301IOT_L_SHS1_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_2].reg_addr = SC301IOT_L_SHS2_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_3].reg_addr = SC301IOT_L_SHS3_ADDR;

		pregs[0].i2c_data[IDX_L_AC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_AC].reg_addr = SC301IOT_L_AC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_L_DC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_DC].reg_addr = SC301IOT_L_DC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_L_DF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_DF].reg_addr = SC301IOT_L_DF_GAIN_ADDR;

		pregs[0].i2c_data[IDX_S_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_1].reg_addr = SC301IOT_S_SHS1_ADDR;
		pregs[0].i2c_data[IDX_S_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_2].reg_addr = SC301IOT_S_SHS2_ADDR;
		pregs[0].i2c_data[IDX_S_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_3].reg_addr = SC301IOT_S_SHS3_ADDR;

		pregs[0].i2c_data[IDX_L_AC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_AC].reg_addr = SC301IOT_L_AC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_L_DC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_DC].reg_addr = SC301IOT_L_DC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_L_DF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_DF].reg_addr = SC301IOT_L_DF_GAIN_ADDR;

		pregs[0].i2c_data[IDX_S_AC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_AC].reg_addr = SC301IOT_S_AC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_S_DC].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_DC].reg_addr = SC301IOT_S_DC_GAIN_ADDR;
		pregs[0].i2c_data[IDX_S_DF].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_DF].reg_addr = SC301IOT_S_DF_GAIN_ADDR;

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
	if (tmp_pclk <= 0) {
		sensor_log_err("PCLK cannot be correctly calculated.");
		return;
	}
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
	uint32_t effc_frame_line;
	effc_frame_line = INIT_FRAME_LINE - HDR_BLANK_LINE * 2;
	g_sns_state[idx.path]->exp_info[0].effective_frame_line = effc_frame_line;
	g_sns_state[idx.path]->exp_info[0].exp_gap = EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[0].hard_exp_max = SENSOR_FRAME_LINES_MAX - HDR_BLANK_LINE * 2 - EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[0].curr_exp_max = effc_frame_line - EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[0].exp_min = SENSOR_EXP_LINES_MIN;
	g_sns_state[idx.path]->exp_info[0].exp_line = 448;
	g_sns_state[idx.path]->exp_info[0].inttime = 4500;
	g_sns_state[idx.path]->exp_info[0].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[0].shs_idx[0] = IDX_L_SHS_1;
	g_sns_state[idx.path]->exp_info[0].shs_idx[1] = IDX_L_SHS_2;
	g_sns_state[idx.path]->exp_info[0].shs_idx[2] = IDX_L_SHS_3;
	g_sns_state[idx.path]->exp_info[0].gain_idx[0] = IDX_L_AC;
	g_sns_state[idx.path]->exp_info[0].gain_idx[1] = IDX_L_DC;
	g_sns_state[idx.path]->exp_info[0].gain_idx[2] = IDX_L_DF;

	// short exposure
	effc_frame_line = HDR_BLANK_LINE * 2;
	g_sns_state[idx.path]->exp_info[1].effective_frame_line = effc_frame_line;
	g_sns_state[idx.path]->exp_info[1].exp_gap = EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[1].hard_exp_max = HDR_BLANK_LINE * 2 - EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[1].curr_exp_max = effc_frame_line - EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[1].exp_min = SENSOR_EXP_LINES_MIN;
	g_sns_state[idx.path]->exp_info[1].exp_line = 448;
	g_sns_state[idx.path]->exp_info[1].inttime = 4500;
	g_sns_state[idx.path]->exp_info[1].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[1].shs_idx[0] = IDX_S_SHS_1;
	g_sns_state[idx.path]->exp_info[1].shs_idx[1] = IDX_S_SHS_2;
	g_sns_state[idx.path]->exp_info[1].shs_idx[2] = IDX_S_SHS_3;
	g_sns_state[idx.path]->exp_info[1].gain_idx[0] = IDX_S_AC;
	g_sns_state[idx.path]->exp_info[1].gain_idx[1] = IDX_S_DC;
	g_sns_state[idx.path]->exp_info[1].gain_idx[2] = IDX_S_DF;

}

static int32_t SENSOR_setInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, uint32_t *effective_time)
{
	uint32_t hard_exp_max = g_sns_state[idx.path]->exp_info[image_idx].hard_exp_max;
	uint32_t curr_exp_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;
	uint32_t exp_min = g_sns_state[idx.path]->exp_info[image_idx].exp_min;

	int exp_line_prc = 0;
	int exp_line = (time_us << (ROW_TIME_PRC + exp_line_prc)) / g_sns_state[idx.path]->row_time[0];

	if (time_us <= 0) {
		sensor_log_err("Exposure time must be greater than than 0.");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->row_time[0] <= 0) {
		sensor_log_err("Internal parameters might not be correctly initialized.");
		return MPI_FAILURE;
	}
	if (image_idx >= HDR_IMAGE_NUM) {
		sensor_log_err("Sub image index exceeds the current limit.");
		return MPI_FAILURE;
	}

	if (exp_line > (hard_exp_max << exp_line_prc) || exp_line < (exp_min << exp_line_prc)) {
		sensor_log_warn("Exposure time exceeds hardware limit.");
		exp_line = CLAMP(exp_line, (exp_min << exp_line_prc), (hard_exp_max << exp_line_prc));
	}

	if (exp_line > (curr_exp_max << exp_line_prc)) {
		sensor_log_err("Expsoure time too long in current FPS.");
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->exp_info[image_idx].exp_line = (exp_line >> exp_line_prc);
	uint32_t time_tmp = (uint32_t)exp_line * g_sns_state[idx.path]->row_time[0];
	time_tmp = (time_tmp + (1 << (ROW_TIME_PRC + exp_line_prc - 1))) >> (ROW_TIME_PRC + exp_line_prc);
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_sns_state[idx.path]->exp_info[image_idx].inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	int value = exp_line << 4;

	int idx0 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[0];
	int idx1 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[1];
	int idx2 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[2];

	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].reg_data = (value & 0xF0000) >> 16;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].reg_data = (value & 0xFF00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx2].reg_data = value & 0xF0;

	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	return SENSOR_setInttimeHdr(idx, 0, time_us, effective_time);
}

static int32_t SENSOR_setSensorGainHdr(MPI_PATH idx, uint32_t image_idx, uint32_t gain)
{
	if (image_idx >= HDR_IMAGE_NUM) {
		sensor_log_err("Sub image index exceeds the current limit.");
		return MPI_FAILURE;
	}

	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_err("Sensor gain must be in range [%d, %d]", SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
		return MPI_FAILURE;
	}

	/* a_gain max and d_gain min*/
	int ac_gain = 0x00;
	int dc_gain = 0x00;
	int df_gain = 0x80;

	// spec 2.2.3
	const int ac_step[] = {
		256, 401, 803, 1606, 3213, 6426, 12853
	}; // x1, x1.569, x3.138, x6.276, x12.552, x25.104, x50.208
	const int ac_val[] = { 0x00, 0x40, 0x48, 0x49, 0x4B, 0x4F, 0x5F };

	const int dc_step[] = { 256, 512, 1024, 2048, 8192 }; // x1, x2, x4, x8, x16
	const int dc_val[] = { 0x00, 0x01, 0x03, 0x07, 0x0F };

	const int df_step[] = { 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 }; // x1, x2, x4, x8, x16, x32

	const int df_b_step[] = { 0, 256, 512, 1024, 2048, 4096, 8192, 16384 }; // x1, x2, x4, x8, x16, x32
	const int df_b_val[] = {
		0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200
	}; // step*8: 1, 2, 4, 8, 16, 32, 64, 128

	const int df_base_step = 0x04; // 1/32 = 4 base step
	const int df_base = 0x80; // 0x80 start
	// const int df_max = 0xFF; // DIG FINE GAIN = 1/128, (0x80~0xFF)/1 = 128, 0x100-1=0xFF
	const int df_max = 0xFC; // DIG FINE GAIN = 1/32, (0x80~0xFF)/4 = 32, 0x100-4=0xFC

	int ac_val_index = 0;
	int dc_val_index = 0;
	int df_gain_tmp;
	int tmp;
	int tmp_gain = gain * 8; // ac_step[0] = 256/32 = 8

	g_sns_state[idx.path]->exp_info[image_idx].sensor_gain = gain;

	// analog coarse gain
	tmp = binary_search_nr(tmp_gain, ac_step, 0, sizeof(ac_step) / sizeof(int));
	ac_val_index = tmp;
	ac_gain = ac_val[tmp];
	tmp_gain = ((tmp_gain * dc_step[0]) + (ac_step[tmp] >> 1)) / ac_step[tmp];

	// digital coarse gain
	tmp = binary_search_nr(tmp_gain, dc_step, 0, sizeof(dc_step) / sizeof(int));
	dc_val_index = tmp;
	dc_gain = dc_val[tmp];
	tmp_gain = ((tmp_gain * df_base) + (dc_step[tmp] >> 1)) / dc_step[tmp];

	// digital fine gain
	df_gain = tmp_gain > df_max ? df_max : tmp_gain;

	tmp = binary_search_nr(tmp_gain, df_step, 0, sizeof(df_step) / sizeof(int));
	df_gain_tmp = tmp_gain - df_base;
	tmp_gain = ((df_gain_tmp - df_b_step[tmp]) / df_b_val[tmp]) * df_base_step + df_base;
	if (tmp_gain > df_max && (ac_val_index + 1) < (sizeof(ac_val) / sizeof(int))) {
		df_gain = df_base;
		ac_gain = ac_val[ac_val_index + 1];
	} else if (tmp_gain > df_max && (dc_val_index + 1) < (sizeof(dc_val) / sizeof(int))) {
		df_gain = df_base;
		dc_gain = dc_val[dc_val_index + 1];
	} else if (ac_val_index) {
		df_gain = tmp_gain;
	}

	int idx0 = g_sns_state[idx.path]->exp_info[image_idx].gain_idx[0]; // AC
	int idx1 = g_sns_state[idx.path]->exp_info[image_idx].gain_idx[1]; // DC
	int idx2 = g_sns_state[idx.path]->exp_info[image_idx].gain_idx[2]; // DF

	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].reg_data = ac_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].reg_data = dc_gain;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx2].reg_data = df_gain;

	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	return SENSOR_setSensorGainHdr(idx, 0, gain);
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
	uint64_t temp;
	fps = fps * FPS_UNIT;
	sec_line = (pclk + (line_pixel >> 1)) / line_pixel;
	if (sec_line <= 0) {
		sensor_log_err("Cannot correctly calculate line per second.");
		return MPI_FAILURE;
	}

	temp = ((uint64_t)sec_line << FPS_PRC) + (((uint32_t)fps) >> 1);
	frame_line = temp / (uint32_t)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);
	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Requested fps exceeds driver limit.");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->exp_info[0].curr_exp_max = frame_line - HDR_BLANK_LINE * 2 - EXP_LINE_GAP;

	for (int image_idx = 0; image_idx < HDR_IMAGE_NUM; image_idx++) {
		uint32_t exp_line_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;

		inttime_max = ((exp_line_max * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
		inttime_min = ((SENSOR_EXP_LINES_MIN * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
		if (image_idx == 0 && inttime) {
			inttime->max = inttime_max;
			inttime->min = inttime_min;
		}

		if (g_sns_state[idx.path]->exp_info[image_idx].exp_line > exp_line_max) {
			SENSOR_setInttimeHdr(idx, image_idx, inttime_max, NULL);
		} else {
			SENSOR_setInttimeHdr(idx, image_idx, g_sns_state[idx.path]->exp_info[image_idx].inttime, NULL);
		}
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, float *fps)
{
	if (time_us <= 0) {
		sensor_log_err("Exposure time must be greater than than 0.");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->row_time[0] <= 0 || g_sns_state[idx.path]->line_pixel[0] <= 0) {
		sensor_log_err("Internal parameters might not be correctly initialized.");
		return MPI_FAILURE;
	}

	if (image_idx != 0) {
		sensor_log_warn("SENSOR_setSlowInttimeHdr does not support image_idx > 0.");
		return SENSOR_setInttimeHdr(idx, image_idx, time_us, NULL);
	}

	int exp_line = ((time_us << ROW_TIME_PRC) + (g_sns_state[idx.path]->row_time[0] >> 1)) /
	               g_sns_state[idx.path]->row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;
	if (frame_line <= 0) {
		sensor_log_err("Cannot correctly calculate line per frame.");
		return MPI_FAILURE;
	}

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Exposure time or FPS exceeds hardware limit.");
		return MPI_FAILURE;
	}
	
	if (fps) {
		int temp = (frame_line * g_sns_state[idx.path]->line_pixel[0]);
		*fps = (float)g_sns_state[idx.path]->pclk / (float)temp;
	}

	int ret = SENSOR_setInttimeHdr(idx, image_idx, time_us, NULL);

	g_sns_state[idx.path]->frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0x7F00) >> 8;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = (frame_line & 0xFF);

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	return ret;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	return SENSOR_setSlowInttimeHdr(idx, 0, time_us, fps);
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->hdr.image_num = HDR_IMAGE_NUM;
	for (int i = 0; i < HDR_IMAGE_NUM; i++) {
		dft->hdr.hdr_inttime_range[i].max =
		        ((g_sns_state[idx.path]->exp_info[i].hard_exp_max * g_sns_state[idx.path]->row_time[0] +
		          (ROW_TIME_UNIT >> 1)) >>
		         ROW_TIME_PRC);
		dft->hdr.hdr_inttime_range[i].min =
		        ((g_sns_state[idx.path]->exp_info[i].exp_min * g_sns_state[idx.path]->row_time[0] +
		          (ROW_TIME_UNIT >> 1)) >>
		         ROW_TIME_PRC);
	}
	dft->inttime_range.max = dft->hdr.hdr_inttime_range[0].max;
	dft->inttime_range.min = dft->hdr.hdr_inttime_range[0].min;
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
	dft->max_fps = (float)SENSOR_FPS_MAX;
	dft->min_fps = SENSOR_FPS_MIN;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 7000;
	dft->exp_value = g_inttime * 32;

	return MPI_SUCCESS;
}

int32_t SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	memcpy(dft, &dip_dft, sizeof(dip_dft));
	return MPI_SUCCESS;
}

int32_t SENSOR_getAwbDefault(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *awb)
{
	/* TODO - fool proof design */

	memcpy(awb->k_table, &ct_tbl_dft[0], sizeof(MPI_AWB_COLOR_TEMP_S) * MPI_K_TABLE_ENTRY_NUM);
	memcpy(awb->delta_table, &delta_tbl_dft[0], sizeof(MPI_AWB_COLOR_DELTA_S) * MPI_K_TABLE_ENTRY_NUM);

	return MPI_SUCCESS;
}

int32_t SENSOR_getBlackLevel(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level)
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

int32_t SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
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
