#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

/*
static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
    32,     64,    128,    256,     512,
  1024,   2048,   4096,   8192,   16384,
 32768,
};
*/

#define SENSOR_BLC_NUM (5)
//0x4B BLC_B
static int k_sensor_blc_bin[SENSOR_BLC_NUM] = {
	48, //30 degree
	49, //50 degree
	56, //60 degree
	81, //70 degree
	155, //80 degree
};

// BLC target
static int k_sensor_blc_val[SENSOR_BLC_NUM] = {
	16, 16, 17, 20, 25,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 1002,
	},
	.dcc = {
		.gain = {1040, 1486, 1593, 1031},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 4960,
		.y_trend_2s = 4012,
		.x_curvature = 12405,
		.y_curvature = 12138,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     1002,
	                                                     988,
	                                                     956,
	                                                     953,
	                                                     952,
	                                                     952,
	                                                     952,
	                                                     952,
	                                                     952,
	                                                     952,
	                                                     952,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 208, 326, 256 },
	  .k = 2700,
	  .matrix = { 3852, -2399, 595, -1481, 2953, 576, -2292, -7376, 11716 } },
	{ .gain = { 256, 238, 284, 256 },
	  .k = 4000,
	  .matrix = { 3433, -2461, 1077, -1801, 3274, 575, -1395, -5345, 8788 } },
	{ .gain = { 256, 264, 260, 256 },
	  .k = 5000,
	  .matrix = { 3786, -2816, 1078, -1341, 3843, -455, -683, -4465, 7196 } },
	{ .gain = { 256, 301, 229, 256 },
	  .k = 6500,
	  .matrix = { 3733, -2725, 1039, -1364, 4153, -741, -579, -3745, 6372 } },
	{ .gain = { 256, 350, 227, 256 }, 
	  .k = 7500, 
	  .matrix = { 4758, -3786, 1076, -933, 3870, -889, -285, -4082, 6415 } },
	{ .gain = { 256, 256, 256, 256 }, 
	  .k = 10000, 
	  .matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 } },
	{ .gain = { 256, 256, 256, 256 }, .k = 0, .matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 } },
	{ .gain = { 256, 256, 256, 256 }, .k = 0, .matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 } },
};

static MPI_AWB_COLOR_DELTA_S delta_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
	        .gain = { 0, 0, 0, 0 }, // gr, r, b, gb
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
	{
	        .gain = { 0, 0, 0, 0 },
	},
};

static MPI_DIP_SNS_DEFAULT_S dip_dft = {

	.iso = {
		.effective_iso[0] =     100,
		.effective_iso[1] =     200,
		.effective_iso[2] =     400,
		.effective_iso[3] =     800,
		.effective_iso[4] =    1600,
		.effective_iso[5] =    3200,
		.effective_iso[6] =    6400,
		.effective_iso[7] =   12800,
		.effective_iso[8] =   25600,
		.effective_iso[9] =   51200,
		.effective_iso[10] = 102400,
	},

	.csm = {
		.sat_table[0] =    152,
		.sat_table[1] =    144,
		.sat_table[2] =    132,
		.sat_table[3] =    128,
		.sat_table[4] =    110,
		.sat_table[5] =    90,
		.sat_table[6] =    64,
		.sat_table[7] =    64,
		.sat_table[8] =    64,
		.sat_table[9] =    64,
		.sat_table[10] =   64,
	},

	.shp = {
		.shp_table[0] =    240,
		.shp_table[1] =    200,
		.shp_table[2] =    140,
		.shp_table[3] =     60,
		.shp_table[4] =     20,
		.shp_table[5] =      0,
		.shp_table[6] =      0,
		.shp_table[7] =      0,
		.shp_table[8] =      0,
		.shp_table[9] =      0,
		.shp_table[10] =     0,
	},

	.nr = {
		.y_level_3d[0] =    130,
		.y_level_3d[1] =    140,
		.y_level_3d[2] =    165,
		.y_level_3d[3] =    176,
		.y_level_3d[4] =    238,
		.y_level_3d[5] =    255,
		.y_level_3d[6] =    255,
		.y_level_3d[7] =    255,
		.y_level_3d[8] =    255,
		.y_level_3d[9] =    255,
		.y_level_3d[10] =   255,

		.c_level_3d[0] =    24,
		.c_level_3d[1] =    42,
		.c_level_3d[2] =    72,
		.c_level_3d[3] =    128,
		.c_level_3d[4] =    156,
		.c_level_3d[5] =    196,
		.c_level_3d[6] =    225,
		.c_level_3d[7] =    255,
		.c_level_3d[8] =    255,
		.c_level_3d[9] =    255,
		.c_level_3d[10] =   255,

		.y_level_2d[0] =    0,
		.y_level_2d[1] =    0,
		.y_level_2d[2] =    0,
		.y_level_2d[3] =    0,
		.y_level_2d[4] =    0,
		.y_level_2d[5] =    0,
		.y_level_2d[6] =    0,
		.y_level_2d[7] =    0,
		.y_level_2d[8] =    0,
		.y_level_2d[9] =    0,
		.y_level_2d[10] =   0,

		.c_level_2d[0] =    0,
		.c_level_2d[1] =    0,
		.c_level_2d[2] =    0,
		.c_level_2d[3] =    0,
		.c_level_2d[4] =    0,
		.c_level_2d[5] =    0,
		.c_level_2d[6] =    0,
		.c_level_2d[7] =    0,
		.c_level_2d[8] =    0,
		.c_level_2d[9] =    0,
		.c_level_2d[10] =   0,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =    960,
		.noise_cstr[1] =    992,
		.noise_cstr[2] =   1024,
		.noise_cstr[3] =   1024,
		.noise_cstr[4] =   1024,
		.noise_cstr[5] =   1024,
		.noise_cstr[6] =   1024,
		.noise_cstr[7] =   1024,
		.noise_cstr[8] =   1024,
		.noise_cstr[9] =   1024,
		.noise_cstr[10] =  1024,

		.curve[0] =      0,
		.curve[1] =     16,
		.curve[2] =     32,
		.curve[3] =     64,
		.curve[4] =    113,
		.curve[5] =    172,
		.curve[6] =    236,
		.curve[7] =    300,
		.curve[8] =    364,
		.curve[9] =    505,
		.curve[10] =   664,
		.curve[11] =   835,
		.curve[12] =  1017,
		.curve[13] =  1205,
		.curve[14] =  1398,
		.curve[15] =  1593,
		.curve[16] =  1790,
		.curve[17] =  1986,
		.curve[18] =  2181,
		.curve[19] =  2375,
		.curve[20] =  2565,
		.curve[21] =  2752,
		.curve[22] =  2936,
		.curve[23] =  3116,
		.curve[24] =  3292,
		.curve[25] =  3633,
		.curve[26] =  3957,
		.curve[27] =  4266,
		.curve[28] =  4561,
		.curve[29] =  4841,
		.curve[30] =  5111,
		.curve[31] =  5368,
		.curve[32] =  5618,
		.curve[33] =  5858,
		.curve[34] =  6092,
		.curve[35] =  6320,
		.curve[36] =  6543,
		.curve[37] =  6763,
		.curve[38] =  6981,
		.curve[39] =  7197,
		.curve[40] =  7411,
		.curve[41] =  7839,
		.curve[42] =  8271,
		.curve[43] =  8710,
		.curve[44] =  9157,
		.curve[45] =  9615,
		.curve[46] = 10085,
		.curve[47] = 10567,
		.curve[48] = 11060,
		.curve[49] = 11562,
		.curve[50] = 12072,
		.curve[51] = 12587,
		.curve[52] = 13103,
		.curve[53] = 13618,
		.curve[54] = 14127,
		.curve[55] = 14623,
		.curve[56] = 15104,
		.curve[57] = 15561,
		.curve[58] = 15991,
		.curve[59] = 16384,
	},
};

#endif
