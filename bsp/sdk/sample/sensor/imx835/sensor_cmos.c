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
#include "sensor_settings.h"
#include "sensor_params.h"

#ifdef __UBOOT__
#include <common.h>
#else
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "l_sensor_cal.h"
#endif

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (835) // sensor ID
#define IMX835_VMAX1_ADDR (0x3028) // vmax(fps line)[7:0]
#define IMX835_VMAX2_ADDR (0x3029) // vmax(fps line)[15:8]
#define IMX835_VMAX3_ADDR (0x302A) // vmax(fps line)[19:16]
#define IMX835_SHS1_ADDR (0x3050) // sensor exposure line control(shs1) [7:0]
#define IMX835_SHS2_ADDR (0x3051) // sensor exposure line control(shs1) [15:8]
#define IMX835_SHS3_ADDR (0x3052) // sensor exposure line control(shs1) [19:16]
#define IMX835_GAIN1_ADDR (0x306C) // sensor gain [7:0]
#define IMX835_GAIN2_ADDR (0x306D) // sensor gain [10:8]

#define EXP_LINE_GAP (8) // IMX835_SoftwareReferenceManual_E_Rev5.0.pdf , "Sets the shutter sweep time.""
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (2)

#define IMX835_INT_ERROR (0) // IMX835_SoftwareReferenceManual_E_Rev5.0.pdf , keyword "Toffset"

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_VMAX_3,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_GAIN_1,
	IDX_GAIN_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

/* clang-format off */

// db = gain_bin * 0.3 (might differ from different sensors)
// gain_val = (10 ** (db / 20)) * 32 (python)
static int sony_gain_bin[] = {
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

static int sony_gain_val[] = {
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

#define SONY_BIN (sizeof(sony_gain_bin) / sizeof(int))

/* clang-format on */

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

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

	return ret;
}
#endif

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
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = IMX835_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = IMX835_VMAX2_ADDR;
		pregs[0].i2c_data[IDX_VMAX_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_3].reg_addr = IMX835_VMAX3_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = IMX835_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = IMX835_SHS2_ADDR;
		pregs[0].i2c_data[IDX_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_3].reg_addr = IMX835_SHS3_ADDR;

		pregs[0].i2c_data[IDX_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN_1].reg_addr = IMX835_GAIN1_ADDR;
		pregs[0].i2c_data[IDX_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN_2].reg_addr = IMX835_GAIN2_ADDR;
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

#ifdef __UBOOT__
static void SENSOR_globalInit(MPI_PATH idx)
{
	uint32_t line_pixel = INIT_LINE_LEN;
	uint32_t pclk = PCLK;
	uint32_t pclk_k; /* pclk / 1000 */
	uint32_t row_time; /* calculated row time */
	uint32_t exp_line; /* exposure lines */

	g_sensor_state[idx.path].sensor_gain = 32;
	g_sensor_state[idx.path].pclk = PCLK;
	g_sensor_state[idx.path].fps_line = INIT_FRAME_LINE;
	g_sensor_state[idx.path].frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state[idx.path].line_pixel[0] = line_pixel;

	/* ---------- UBOOT SAFE ROW_TIME CALCULATION (32-bit only) ---------- */
	pclk_k = pclk / 1000; /* prevent 64-bit division */

	/* row_time = (((line_pixel * 1000) << ROW_TIME_PRC) + pclk_k/2) / pclk_k */
	row_time = (((line_pixel * 1000) << ROW_TIME_PRC) + (pclk_k >> 1)) / pclk_k;

	g_sensor_state[idx.path].row_time[0] = (int32_t)row_time;

	/* ---------- EXPOSURE LINE CALCULATION ---------- */
	exp_line = ((g_inttime << ROW_TIME_PRC) + (row_time >> 1)) / row_time;

	g_sensor_state[idx.path].exp_line[0] = exp_line;
	g_sensor_state[idx.path].exp_line[1] = exp_line;

	/* ---------- COPY VALUES TO [1] SLOT ---------- */
	g_sensor_state[idx.path].frame_line[1] = g_sensor_state[idx.path].frame_line[0];
	g_sensor_state[idx.path].line_pixel[1] = line_pixel;
	g_sensor_state[idx.path].row_time[1] = row_time;

	/* ---------- RESET REGS TABLE ---------- */
	{
		MPI_SNS_REGS_TABLE_S init_regs;
		memset(&init_regs, 0, sizeof(MPI_SNS_REGS_TABLE_S));

		memcpy(&g_sns_state[idx.path]->regs_info[0], &init_regs, sizeof(MPI_SNS_REGS_TABLE_S));
		memcpy(&g_sns_state[idx.path]->regs_info[1], &init_regs, sizeof(MPI_SNS_REGS_TABLE_S));

		g_sns_state[idx.path]->regs_info[0].is_config = false;
		g_sns_state[idx.path]->regs_info[1].is_config = false;
	}
}
#else
static void SENSOR_globalInit(MPI_PATH idx)
{
	g_sensor_state[idx.path].sensor_gain = 32;
	g_sensor_state[idx.path].pclk = PCLK;
	g_sensor_state[idx.path].fps_line = INIT_FRAME_LINE;
	g_sensor_state[idx.path].frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state[idx.path].line_pixel[0] = INIT_LINE_LEN;

	g_sensor_state[idx.path].row_time[0] =
	        (int32_t)((((int64_t)g_sensor_state[idx.path].line_pixel[0] << ROW_TIME_PRC) * 1000000 +
	                   (g_sensor_state[idx.path].pclk >> 1)) /
	                  g_sensor_state[idx.path].pclk);

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
#endif

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
	int row_time = g_sensor_state[idx.path].row_time[0];
	int exp_line = ((time_us - IMX835_INT_ERROR) << ROW_TIME_PRC) / row_time;

	if (exp_line > SENSOR_EXP_LINES_MAX || exp_line < SENSOR_EXP_LINES_MIN) {
		sensor_log_warn("Exposure time exceeds hardware limit.");
		exp_line = CLAMP(exp_line, SENSOR_EXP_LINES_MIN, SENSOR_EXP_LINES_MAX);
	}

	if (exp_line > g_sensor_state[idx.path].frame_line[0] - EXP_LINE_GAP) {
		sensor_log_err("Expsoure time too long in current FPS.");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = exp_line;
	uint32_t time_tmp = ((uint32_t)exp_line * row_time) >> ROW_TIME_PRC;
	time_tmp += IMX835_INT_ERROR;
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	uint32_t shs = g_sensor_state[idx.path].frame_line[0] - g_sensor_state[idx.path].exp_line[0];
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (shs & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = ((shs >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].reg_data = ((shs >> 16) & 0x0F);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].is_update = true;

	return MPI_SUCCESS;
}

#ifdef __UBOOT__

/* U-Boot safe binary search */
static int uboot_binary_search_nr(uint32_t value, int *array, int left, int right)
{
	int mid;

	while (left < right) {
		mid = (left + right) >> 1;

		if (array[mid] == value)
			return mid;
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	int target_bin;
	int diff_low, diff_high;
	int gain_sensor_bin;

	g_sns_state[idx.path]->sensor_gain = gain;

	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_err("Sensor gain must be in range [%d, %d]", SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
		return MPI_FAILURE;
	}

	/* ---- UBOOT SAFE VERSION OF BINARY SEARCH ---- */
	target_bin = uboot_binary_search_nr(gain, sony_gain_val, 0, SONY_BIN - 1);

	/* prevent array overflow */
	if (target_bin >= (SONY_BIN - 1)) {
		target_bin = SONY_BIN - 2;
	}

	diff_low = gain - sony_gain_val[target_bin];
	diff_high = sony_gain_val[target_bin + 1] - gain;

	gain_sensor_bin = (diff_low < diff_high) ? sony_gain_bin[target_bin] : sony_gain_bin[target_bin + 1];

	/* ---- Write to registers ---- */
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].reg_data = (gain_sensor_bin & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].reg_data = ((gain_sensor_bin >> 8) & 0x01);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].is_update = true;

	return MPI_SUCCESS;
}

#else

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	if (gain < SENSOR_GAIN_MIN || gain > SENSOR_GAIN_MAX) {
		sensor_log_err("Sensor gain must be in range [%d, %d]", SENSOR_GAIN_MIN, SENSOR_GAIN_MAX);
		return MPI_FAILURE;
	}
	g_sns_state[idx.path]->sensor_gain = gain;

	int target_bin = binary_search_nr(gain, sony_gain_val, 0, SONY_BIN - 1);

	// directly compare the nearest two value
	int diff_low = gain - sony_gain_val[target_bin];
	int diff_high = sony_gain_val[target_bin + 1] - gain;
	int gain_sensor_bin = diff_low < diff_high ? sony_gain_bin[target_bin] : sony_gain_bin[target_bin + 1];

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].reg_data = (gain_sensor_bin & 0xff);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].reg_data = ((gain_sensor_bin >> 8) & 0x01);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].is_update = true;

	return MPI_SUCCESS;
}
#endif

#ifdef __UBOOT__
static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	uint32_t frame_line;
	uint32_t sec_line;

	uint32_t line_pixel = g_sensor_state[idx.path].line_pixel[0];
	uint32_t pclk = g_sensor_state[idx.path].pclk;

	/* -------- UBOOT: convert fps to fixed point -------- */
	uint32_t fps_fixed = (uint32_t)(fps * FPS_UNIT);

	/* sec_line = (pclk / line_pixel) << (FPS_PRC - 1); */
	sec_line = (pclk + (line_pixel >> 1)) / line_pixel;
	sec_line <<= (FPS_PRC - 1);

	/* frame_line = (sec_line / fps_fixed) * 2 */
	frame_line = (sec_line + (fps_fixed >> 1)) / fps_fixed;
	frame_line <<= 1;

	if (frame_line < 1)
		frame_line = 1;

	if (frame_line > SENSOR_FRAME_LINES_MAX || frame_line < SENSOR_FRAME_LINES_MIN) {
		sensor_log_err("Requested fps exceeds driver limit.");
		return MPI_FAILURE;
	}

	/* ------- Calculate inttime range ------- */
	uint32_t inttime_max =
	        (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >>
	         ROW_TIME_PRC);

	uint32_t inttime_min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;

	inttime_max += IMX835_INT_ERROR;
	inttime_min += IMX835_INT_ERROR;

	g_sensor_state[idx.path].frame_line[0] = frame_line;

	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP)
		SENSOR_setInttime(idx, inttime_max, NULL);
	else
		SENSOR_setInttime(idx, g_inttime, NULL);

	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}

	/* Update VMAX */
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x0F);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}
#else
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
	frame_line = (sec_line + ((int)fps >> 1)) / (int)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		sensor_log_err("Requested fps exceeds driver limit.");
		return MPI_FAILURE;
	}

	uint32_t inttime_max =
	        (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >>
	         ROW_TIME_PRC);
	uint32_t inttime_min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	// integration error
	inttime_max += IMX835_INT_ERROR;
	inttime_min += IMX835_INT_ERROR;

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime_max, NULL);
	} else {
		SENSOR_setInttime(idx, g_inttime, NULL);
	}

	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}

	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x0F);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}
#endif

#ifndef __UBOOT__
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

	int exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];
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
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x0F);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	if (fps) {
		int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
		*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;
	}

	SENSOR_setInttime(idx, time_us, NULL);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC) -
	        1;
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	// integration error
	dft->inttime_range.max += IMX835_INT_ERROR;
	dft->inttime_range.min += IMX835_INT_ERROR;
	dft->sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_GAIN_MAX;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 512;
	dft->gain_thr_down = 768;
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = (float)MIN_FPS;
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
#endif

static int SENSOR_regCallback(MPI_PATH idx)
{
	MPI_SNS_CALLBACK_S sensor_callback = {
		.dip =
		        {
						.global_init = SENSOR_globalInit,
						.get_regs_info = SENSOR_getRegsInfo,
#ifndef __UBOOT__
		                .init = SENSOR_configInit,
		                .get_sns_op_info = SENSOR_getOpInfo,
		                .get_dip_default = SENSOR_getDipDefault,
		                .exit = SENSOR_configExit,
#endif
		        },
#ifndef __UBOOT__
		.cal =
		        {
		                .get_black_level = SENSOR_getBlackLevel,
		                .get_cal_default = SENSOR_getCalDefault,
		        },
#endif
		.ae =
		        {
						.set_framerate = SENSOR_setFramrate,
						.set_inttime = SENSOR_setInttime,
						.set_sensor_gain = SENSOR_setSensorGain,
#ifndef __UBOOT__
		                .get_ae_default = SENSOR_getAeDefault,
		                .set_slow_inttime = SENSOR_setSlowInttime,
#endif
		        },
#ifndef __UBOOT__
		.awb =
		        {
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
