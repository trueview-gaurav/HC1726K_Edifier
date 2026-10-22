#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4243,
	},
	.dcc = {
		.gain = {1098, 1579, 1676, 1098},
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
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                                    4243,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 176, 357, 256 },
	  .k = 2700,
	  .matrix = { 2722, 537, -1211, -1646, -4297, -602, -681, -5373, 8102 } },
	{ .gain = { 256, 222, 302, 256 },
	  .k = 4000,
	  .matrix = { 2815, -999, 232, -1206, 3865, -610, -53, -3561, 5662 } },
	{ .gain = { 256, 258, 255, 256 },
	  .k = 5000,
	  .matrix = { 3159, -1322, 211, -1044, 4509, -1416, 175, -3379, 5251 } },
	{ .gain = { 256, 285, 233, 256 },
	  .k = 6500,
	  .matrix = { 3099, -1441, 389, -985, 4363, -1329, 125, -3037, 4960 } },
	{ .gain = { 256, 313, 224, 256 }, 
	  .k = 7500, 
	  .matrix = { 3512, -1445, -19, -737, 4399, -1614, -211, -2961, 4798 } },
	{ .gain = { 256, 256, 256, 256 }, .k = 0, .matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 } },
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
		.sat_table[0] =    128,
		.sat_table[1] =    110,
		.sat_table[2] =     90,
		.sat_table[3] =     90,
		.sat_table[4] =     90,
		.sat_table[5] =     80,
		.sat_table[6] =     80,
		.sat_table[7] =     80,
		.sat_table[8] =     80,
		.sat_table[9] =     80,
		.sat_table[10] =    80,
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
		.y_level_3d[0] =    150,
		.y_level_3d[1] =    165,
		.y_level_3d[2] =    175,
		.y_level_3d[3] =    185,
		.y_level_3d[4] =    200,
		.y_level_3d[5] =    210,
		.y_level_3d[6] =    230,
		.y_level_3d[7] =    240,
		.y_level_3d[8] =    250,
		.y_level_3d[9] =    255,
		.y_level_3d[10] =   255,

		.c_level_3d[0] =     80,
		.c_level_3d[1] =     80,
		.c_level_3d[2] =     80,
		.c_level_3d[3] =     85,
		.c_level_3d[4] =     90,
		.c_level_3d[5] =     95,
		.c_level_3d[6] =    100,
		.c_level_3d[7] =    100,
		.c_level_3d[8] =    100,
		.c_level_3d[9] =    100,
		.c_level_3d[10] =   100,

		.y_level_2d[0] =    100,
		.y_level_2d[1] =    100,
		.y_level_2d[2] =    100,
		.y_level_2d[3] =    100,
		.y_level_2d[4] =    100,
		.y_level_2d[5] =    100,
		.y_level_2d[6] =    100,
		.y_level_2d[7] =    100,
		.y_level_2d[8] =    100,
		.y_level_2d[9] =    100,
		.y_level_2d[10] =   100,

		.c_level_2d[0] =    150,
		.c_level_2d[1] =    150,
		.c_level_2d[2] =    150,
		.c_level_2d[3] =    150,
		.c_level_2d[4] =    150,
		.c_level_2d[5] =    150,
		.c_level_2d[6] =    150,
		.c_level_2d[7] =    150,
		.c_level_2d[8] =    150,
		.c_level_2d[9] =    150,
		.c_level_2d[10] =   150,
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
