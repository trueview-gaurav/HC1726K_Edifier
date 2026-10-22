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

#define SENSOR_ID (327) // sensor ID
#define IMX327_VMAX1_ADDR (0x3018) // vmax(fps line)[7:0]
#define IMX327_VMAX2_ADDR (0x3019) // vmax(fps line)[15:8]
#define IMX327_VMAX3_ADDR (0x301A) // vmax(fps line)[17:16]
#define IMX327_SHS2_1_ADDR (0x3024) // long sensor exposure line control [7:0]
#define IMX327_SHS2_2_ADDR (0x3025) // long sensor exposure line control [15:8]
#define IMX327_SHS2_3_ADDR (0x3026) // long sensor exposure line control [17:16]
#define IMX327_SHS1_1_ADDR (0x3020) // short exposure line control) [7:0]
#define IMX327_SHS1_2_ADDR (0x3021) // short exposure line control) [15:8]
#define IMX327_SHS1_3_ADDR (0x3022) // short exposure line control) [19:16]
#define IMX327_L_GAIN_ADDR (0x3014) // sensor gain [7:0]
#define IMX327_S_GAIN_ADDR (0x30F2) // sensor gain [7:0]

#define SHORT_EXP_LINE_MIN (1) // IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 12
#define SHORT_EXP_LINE_GAP (3) // IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 12

#define LONG_EXP_LINE_MIN (1) // IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 12
#define LONG_EXP_LINE_GAP (3) // IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 12

#define IMX327_INT_ERROR (0)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_VMAX_3,
	IDX_L_SHS_1,
	IDX_L_SHS_2,
	IDX_L_SHS_3,
	IDX_S_SHS_1,
	IDX_S_SHS_2,
	IDX_S_SHS_3,
	IDX_L_GAIN,
	IDX_S_GAIN,
	IDX_NUM,
} I2C_DATA_IDX_E;

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

/* clang-format off */

// db = gain_bin * 0.3 (might differ from different sensors)
// gain_val = (10 ** (db / 20)) * 32 (python)
static int g_gain_bin[] = {
	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,
	21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
	42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,
	63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,
	84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104,
	105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
	126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
	147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167,
	168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188,
	189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
	210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230,
};

static int g_gain_val[] = {
	32,    33,    34,    35,    37,    38,    39,    41,    42,    44,    45,    47,    48,    50,    52,    54,
	56,    58,    60,    62,    64,    66,    68,    71,    73,    76,    79,    81,    84,    87,    90,    93,
	97,    100,   104,   107,   111,   115,   119,   123,   127,   132,   137,   141,   146,   151,   157,   162,
	168,   174,   180,   186,   193,   200,   207,   214,   221,   229,   237,   246,   254,   263,   272,   282,
	292,   302,   313,   324,   335,   347,   359,   372,   385,   398,   412,   427,   442,   457,   473,   490,
	507,   525,   543,   563,   582,   603,   624,   646,   669,   692,   716,   742,   768,   795,   823,   851,
	881,   912,   944,   978,   1012,  1047,  1084,  1122,  1162,  1203,  1245,  1289,  1334,  1381,  1429,  1480,
	1532,  1585,  1641,  1699,  1759,  1820,  1884,  1951,  2019,  2090,  2163,  2239,  2318,  2400,  2484,  2571,
	2662,  2755,  2852,  2952,  3056,  3163,  3275,  3390,  3509,  3632,  3760,  3892,  4029,  4170,  4317,  4468,
	4625,  4788,  4956,  5130,  5311,  5497,  5690,  5890,  6097,  6312,  6534,  6763,  7001,  7247,  7502,  7765,
	8038,  8321,  8613,  8916,  9229,  9553,  9889,  10236, 10596, 10969, 11354, 11753, 12166, 12594, 13036, 13494,
	13969, 14459, 14968, 15494, 16038, 16602, 17185, 17789, 18414, 19061, 19731, 20424, 21142, 21885, 22654, 23450,
	24274, 25128, 26011, 26925, 27871, 28850, 29864, 30914, 32000, 33125, 34289, 35494, 36741, 38032, 39369, 40752,
	42184, 43667, 45201, 46790, 48434, 50136, 51898, 53722, 55610, 57564, 59587, 61681, 63848, 66092, 68415, 70819,
	73308, 75884, 78551, 81311, 84169, 87126, 90188,
};

static const int k_gain_table_len = sizeof(g_gain_bin) / sizeof(g_gain_bin[0]);

/* clang-format on */

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
		pregs[0].reg_num = IDX_NUM;

		for (i = 0; i < pregs[0].reg_num; ++i) {
			pregs[0].i2c_data[i].is_update = true;
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = SENSOR_I2C_REG_LENGTH;
			pregs[0].i2c_data[i].reg_data_byte_num = SENSOR_I2C_DAT_LENGTH;
		}

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = IMX327_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = IMX327_VMAX2_ADDR;
		pregs[0].i2c_data[IDX_VMAX_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_3].reg_addr = IMX327_VMAX3_ADDR;

		pregs[0].i2c_data[IDX_L_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_1].reg_addr = IMX327_SHS2_1_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_2].reg_addr = IMX327_SHS2_2_ADDR;
		pregs[0].i2c_data[IDX_L_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_SHS_3].reg_addr = IMX327_SHS2_3_ADDR;

		pregs[0].i2c_data[IDX_S_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_1].reg_addr = IMX327_SHS1_1_ADDR;
		pregs[0].i2c_data[IDX_S_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_2].reg_addr = IMX327_SHS1_2_ADDR;
		pregs[0].i2c_data[IDX_S_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_SHS_3].reg_addr = IMX327_SHS1_3_ADDR;

		pregs[0].i2c_data[IDX_L_GAIN].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_L_GAIN].reg_addr = IMX327_L_GAIN_ADDR;
		pregs[0].i2c_data[IDX_S_GAIN].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_S_GAIN].reg_addr = IMX327_S_GAIN_ADDR;

		pregs[0].is_config = true;
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	for (i = 0; i < pregs[0].reg_num; ++i) {
		pregs[0].i2c_data[i].is_update = false;
	}

	g_sns_state[idx.path]->exp_line[1] = g_sns_state[idx.path]->exp_line[0];
	g_sns_state[idx.path]->frame_line[1] = g_sns_state[idx.path]->frame_line[0];
	g_sns_state[idx.path]->line_pixel[1] = g_sns_state[idx.path]->line_pixel[0];

	return MPI_SUCCESS;
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	int64_t pclk = PCLK;
	int line_pixel = INIT_LINE_LEN;
	int frame_line = INIT_FRAME_LINE;

	g_sensor_state[idx.path].sensor_gain = 32;
	g_sensor_state[idx.path].pclk = pclk;
	g_sensor_state[idx.path].fps_line = frame_line;
	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sensor_state[idx.path].line_pixel[0] = line_pixel;

	int64_t tmp = (int64_t)(line_pixel << ROW_TIME_PRC) * 1000000;
	int row_time = (tmp + (pclk >> 1)) / pclk;
	g_sensor_state[idx.path].row_time[0] = row_time;

	g_sensor_state[idx.path].exp_line[0] = ((g_inttime << ROW_TIME_PRC) + (row_time >> 1)) / row_time;

	g_sensor_state[idx.path].exp_line[1] = g_sensor_state[idx.path].exp_line[0];
	g_sensor_state[idx.path].frame_line[1] = g_sensor_state[idx.path].frame_line[0];
	g_sensor_state[idx.path].line_pixel[1] = g_sensor_state[idx.path].line_pixel[0];
	g_sensor_state[idx.path].row_time[1] = g_sensor_state[idx.path].row_time[0];

	g_sns_state[idx.path]->regs_info[0] = (MPI_SNS_REGS_TABLE_S){ 0 };
	g_sns_state[idx.path]->regs_info[1] = (MPI_SNS_REGS_TABLE_S){ 0 };
	g_sns_state[idx.path]->regs_info[0].is_config = false;
	g_sns_state[idx.path]->regs_info[1].is_config = false;

	// HDR info , IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 12
	// long exposure
	uint32_t effc_frame_line = INIT_FRAME_LINE * 2;
	uint32_t long_exp_max = effc_frame_line - RHS1 - LONG_EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[0].effective_frame_line = effc_frame_line;
	g_sns_state[idx.path]->exp_info[0].exp_gap = LONG_EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[0].hard_exp_max = long_exp_max;
	g_sns_state[idx.path]->exp_info[0].curr_exp_max = long_exp_max;
	g_sns_state[idx.path]->exp_info[0].exp_min = LONG_EXP_LINE_MIN;
	g_sns_state[idx.path]->exp_info[0].exp_line = LONG_EXP_LINE_MIN;
	g_sns_state[idx.path]->exp_info[0].inttime = 30;
	g_sns_state[idx.path]->exp_info[0].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[0].shs_idx[0] = IDX_L_SHS_1;
	g_sns_state[idx.path]->exp_info[0].shs_idx[1] = IDX_L_SHS_2;
	g_sns_state[idx.path]->exp_info[0].shs_idx[2] = IDX_L_SHS_3;
	g_sns_state[idx.path]->exp_info[0].gain_idx[0] = IDX_L_GAIN;

	// short exposure
	effc_frame_line = RHS1;
	g_sns_state[idx.path]->exp_info[1].effective_frame_line = effc_frame_line;
	g_sns_state[idx.path]->exp_info[1].exp_gap = SHORT_EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[1].hard_exp_max = effc_frame_line - SHORT_EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[1].curr_exp_max = effc_frame_line - SHORT_EXP_LINE_GAP;
	g_sns_state[idx.path]->exp_info[1].exp_min = SHORT_EXP_LINE_MIN;
	g_sns_state[idx.path]->exp_info[1].exp_line = SHORT_EXP_LINE_MIN;
	g_sns_state[idx.path]->exp_info[1].inttime = 30;
	g_sns_state[idx.path]->exp_info[1].sensor_gain = 32;

	g_sns_state[idx.path]->exp_info[1].shs_idx[0] = IDX_S_SHS_1;
	g_sns_state[idx.path]->exp_info[1].shs_idx[1] = IDX_S_SHS_2;
	g_sns_state[idx.path]->exp_info[1].shs_idx[2] = IDX_S_SHS_3;
	g_sns_state[idx.path]->exp_info[1].gain_idx[0] = IDX_S_GAIN;
}

static int32_t SENSOR_setInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, uint32_t *effective_time)
{
	uint32_t hard_exp_max = g_sns_state[idx.path]->exp_info[image_idx].hard_exp_max;
	uint32_t curr_exp_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;
	uint32_t exp_min = g_sns_state[idx.path]->exp_info[image_idx].exp_min;

	int row_time = g_sensor_state[idx.path].row_time[0];
	int exp_line = ((time_us - IMX327_INT_ERROR) << ROW_TIME_PRC) / row_time;

	if (time_us == 0) {
		printf("[Sensor Error] exposure time must be greater than 0.\n");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->row_time[0] == 0) {
		printf("[Sensor Error] Global parameters(row time) error.\n");
		return MPI_FAILURE;
	}
	if (image_idx >= HDR_IMAGE_NUM) {
		printf("[Sensor Error] Sub image index exceeds the current limit.");
		return MPI_FAILURE;
	}

	// printf("[SNS] get set inttime request with time_us = %u\n", time_us);

	if (exp_line > hard_exp_max || exp_line < exp_min) {
		printf("[SNS] Exposure time exceeds hardware limit.\n");
		// printf("      time_us = %u\n", time_us);
		// printf("      exp_line = %u\n", exp_line);
		// printf("      hard_exp_max = %u\n", hard_exp_max);
		// printf("      exp_min = %u\n", exp_min);
		exp_line = CLAMP(exp_line, (exp_min), (hard_exp_max));
	}

	if (exp_line > curr_exp_max) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sns_state[idx.path]->exp_info[image_idx].exp_line = exp_line;
	uint32_t time_tmp = ((uint32_t)exp_line * row_time) >> ROW_TIME_PRC;
	time_tmp += IMX327_INT_ERROR;
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_sns_state[idx.path]->exp_info[image_idx].inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	// IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 12
	uint32_t shs = g_sns_state[idx.path]->exp_info[image_idx].effective_frame_line -
	               g_sns_state[idx.path]->exp_info[image_idx].exp_line - 1;

	int idx0 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[0];
	int idx1 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[1];
	int idx2 = g_sns_state[idx.path]->exp_info[image_idx].shs_idx[2];

	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].reg_data = (shs & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx1].reg_data = ((shs >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx2].reg_data = ((shs >> 16) & 0x03);

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
		printf("[Sensor Error] Sub image index exceeds the current limit.");
		return MPI_FAILURE;
	}

	if (gain < SENSOR_GAIN_MIN) {
		printf("[Sensor Error] Sensor gain must be greater than %d\n", SENSOR_GAIN_MIN);
		return -EINVAL;
	} else if (gain > SENSOR_GAIN_MAX) {
		printf("[Sensor Error] Sensor gain must be lesser than %d (sensor limit)\n", SENSOR_GAIN_MAX);
		return -EINVAL;
	}

	g_sns_state[idx.path]->exp_info[image_idx].sensor_gain = gain;

	int target_bin = binary_search_nr(gain, g_gain_val, 0, k_gain_table_len - 1);

	// directly compare the nearest two value
	int diff_low = gain - g_gain_val[target_bin];
	int diff_high = g_gain_val[target_bin + 1] - gain;
	int gain_sensor_bin = diff_low < diff_high ? g_gain_bin[target_bin] : g_gain_bin[target_bin + 1];

	int idx0 = g_sns_state[idx.path]->exp_info[image_idx].gain_idx[0];

	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].reg_data = (gain_sensor_bin & 0xff);
	g_sns_state[idx.path]->regs_info[0].i2c_data[idx0].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	return SENSOR_setSensorGainHdr(idx, 0, gain);
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	if (fps <= 0.0) {
		printf("[Sensor Error] FPS must be greater than 0.\n");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->line_pixel[0] == 0) {
		printf("[Sensor Error] Global parameters(line_pixel) error.\n");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->row_time[0] == 0) {
		printf("[Sensor Error] Global parameters(row_time) error.\n");
		return MPI_FAILURE;
	}

	// Effectively, sensor run through 2x the pixels in a single line for LE and SE
	// So we half the PCLK here, then it should be equal to (HMAX * VMAX * FPS)
	int line_pixel = g_sns_state[idx.path]->line_pixel[0];
	int64_t pclk = g_sns_state[idx.path]->pclk >> 1;
	int64_t sec_line; /* Lines of pixels the sensor will run through in one second. */
	int32_t frame_line; /* Lines of pixels the sensor will run through in a frame. */

	// Real VMAX setting is half of (PCLK / HMAX), but we already divide pclk by 2
	sec_line = (((int64_t)pclk << FPS_PRC) + (line_pixel >> 1)) / line_pixel;
	if (sec_line == 0) {
		printf("[Sensor Error] sec_line must be greater than 0.\n");
		return MPI_FAILURE;
	}

	int32_t fps_i = fps * FPS_UNIT;
	frame_line = (sec_line + (fps_i >> 1)) / fps_i;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	int32_t effc_frame_line = frame_line * 2;
	g_sns_state[idx.path]->frame_line[0] = frame_line;
	g_sns_state[idx.path]->exp_info[0].effective_frame_line = effc_frame_line;
	g_sns_state[idx.path]->exp_info[0].curr_exp_max = effc_frame_line - RHS1 - LONG_EXP_LINE_GAP;

	for (int image_idx = 0; image_idx < HDR_IMAGE_NUM; image_idx++) {
		int32_t row_time = g_sns_state[idx.path]->row_time[0];
		uint32_t exp_line_max = g_sns_state[idx.path]->exp_info[image_idx].curr_exp_max;

		int32_t inttime_max = ((exp_line_max * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
		int32_t inttime_min = ((LONG_EXP_LINE_MIN * row_time + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);

		// integration error
		inttime_max += IMX327_INT_ERROR;
		inttime_min += IMX327_INT_ERROR;

		if (g_sns_state[idx.path]->exp_info[image_idx].exp_line > exp_line_max) {
			// printf("[SNS] set sensor idx %d with max inttime %u\n", image_idx, inttime_max);
			SENSOR_setInttimeHdr(idx, image_idx, inttime_max, NULL);
		} else {
			// printf("[SNS] set sensor idx %d with previous inttime %u\n", image_idx, g_sns_state[idx.path]->exp_info[image_idx].inttime);
			SENSOR_setInttimeHdr(idx, image_idx, g_sns_state[idx.path]->exp_info[image_idx].inttime, NULL);
		}

		if (image_idx == 0 && inttime) {
			inttime->max = inttime_max;
			inttime->min = inttime_min;
		}
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x03);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttimeHdr(MPI_PATH idx, uint32_t image_idx, uint32_t time_us, float *fps)
{
	if (time_us == 0) {
		printf("[Sensor Error] exposure time must be greater than 0.\n");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->line_pixel[0] == 0) {
		printf("[Sensor Error] Global parameters(line_pixel) error.\n");
		return MPI_FAILURE;
	}
	if (g_sns_state[idx.path]->row_time[0] == 0) {
		printf("[Sensor Error] Global parameters(row_time) error.\n");
		return MPI_FAILURE;
	}

	if (image_idx != 0) {
		printf("[Sensor warning] setSlowInttimeHdr does not support image_idx > 0.\n");
		return SENSOR_setInttimeHdr(idx, image_idx, time_us, NULL);
	}

	int32_t row_time = g_sns_state[idx.path]->row_time[0];
	int exp_line = ((time_us - IMX327_INT_ERROR) << ROW_TIME_PRC) / row_time;
	int frame_line = exp_line + LONG_EXP_LINE_GAP + RHS1;
	// Register of a single frame_line(VMAX) contains 2 exposure lines,
	// and since we need to make it sufficient, we need to round up the setting.
	frame_line = (frame_line + 1) / 2;
	if (frame_line <= 0) {
		printf("[Sensor Error] frame_line must be greater than 0.\n");
		return MPI_FAILURE;
	}

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	if (fps) {
		int temp = (frame_line * g_sns_state[idx.path]->line_pixel[0] * 2);
		*fps = (double)g_sns_state[idx.path]->pclk / temp;
	}

	int32_t effc_frame_line = frame_line * 2;
	g_sns_state[idx.path]->exp_info[0].effective_frame_line = effc_frame_line;
	g_sns_state[idx.path]->exp_info[0].curr_exp_max = effc_frame_line - RHS1 - LONG_EXP_LINE_GAP;
	int ret = SENSOR_setInttimeHdr(idx, image_idx, time_us, NULL);

	g_sns_state[idx.path]->frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x03);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;
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
		// printf("[SNS] Inttime range[%d].max = %u\n", i, dft->hdr.hdr_inttime_range[i].max);
		// printf("[SNS] Inttime range[%d].min = %u\n", i, dft->hdr.hdr_inttime_range[i].min);
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
