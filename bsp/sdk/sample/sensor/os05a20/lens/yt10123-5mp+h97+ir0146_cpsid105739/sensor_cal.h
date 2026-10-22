#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4068,
	},
	.dcc = {
		.gain = {1091, 2189, 2003, 1097},
		.offset_2s = {0, 50, 34, 3},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 4900,
		.y_trend_2s = 3884,
		.x_curvature = 6160,
		.y_curvature = 6412,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4068,
	                                                     4048,
	                                                     4024,
	                                                     4008,
	                                                     4008,
	                                                     4008,
	                                                     4008,
	                                                     4008,
	                                                     4008,
	                                                     4008,
	                                                     4008,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 171, 393, 256 },
	  .k = 2700,
	  .matrix = { 3105, -1107, 50, -1855, 4229, -326, -266, -3704, 6018 } },
	{ .gain = { 256, 204, 332, 256 },
	  .k = 4000,
	  .matrix = { 3267, -1330, 111, -1677, 3967, -242, 55, -3185, 5178 } },
	{ .gain = { 256, 235, 254, 256 },
	  .k = 5000,
	  .matrix = { 3516, -1622, 154, -1582, 4544, -914, 269, -3303, 5082 } },
	{ .gain = { 256, 264, 219, 256 },
	  .k = 6500,
	  .matrix = { 3393, -1614, 269, -1370, 4324, -906, 232, -2855, 4671 } },
	{ .gain = { 256, 324, 211, 256 },
	  .k = 7500,
	  .matrix = { 3809, -1931, 170, -1227, 4457, -1182, 182, -3049, 4915 } },
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
		.sat_table[0] =    135,
		.sat_table[1] =    130,
		.sat_table[2] =    124,
		.sat_table[3] =    116,
		.sat_table[4] =    110,
		.sat_table[5] =    101,
		.sat_table[6] =    100,
		.sat_table[7] =    100,
		.sat_table[8] =    100,
		.sat_table[9] =    100,
		.sat_table[10] =   100,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   255,
		.shp_table[3] =   248,
		.shp_table[4] =   242,
		.shp_table[5] =   224,
		.shp_table[6] =   205,
		.shp_table[7] =   158,
		.shp_table[8] =   109,
		.shp_table[9] =    56,
		.shp_table[10] =   56,
	},

	.nr = {
		.y_level_3d[0] =  176,
		.y_level_3d[1] =  182,
		.y_level_3d[2] =  192,
		.y_level_3d[3] =  206,
		.y_level_3d[4] =  209,
		.y_level_3d[5] =  226,
		.y_level_3d[6] =  238,
		.y_level_3d[7] =  240,
		.y_level_3d[8] =  252,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =    151,
		.c_level_3d[1] =    157,
		.c_level_3d[2] =    160,
		.c_level_3d[3] =    160,
		.c_level_3d[4] =    160,
		.c_level_3d[5] =    160,
		.c_level_3d[6] =    160,
		.c_level_3d[7] =    160,
		.c_level_3d[8] =    160,
		.c_level_3d[9] =    160,
		.c_level_3d[10] =   160,

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
		.noise_cstr[0] =    864,
		.noise_cstr[1] =   1024,
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
		.curve[1] =     40,
		.curve[2] =     95,
		.curve[3] =    161,
		.curve[4] =    235,
		.curve[5] =    316,
		.curve[6] =    404,
		.curve[7] =    494,
		.curve[8] =    583,
		.curve[9] =    762,
		.curve[10] =   938,
		.curve[11] =  1110,
		.curve[12] =  1279,
		.curve[13] =  1443,
		.curve[14] =  1602,
		.curve[15] =  1759,
		.curve[16] =  1915,
		.curve[17] =  2070,
		.curve[18] =  2224,
		.curve[19] =  2376,
		.curve[20] =  2528,
		.curve[21] =  2679,
		.curve[22] =  2829,
		.curve[23] =  2978,
		.curve[24] =  3126,
		.curve[25] =  3419,
		.curve[26] =  3709,
		.curve[27] =  3996,
		.curve[28] =  4280,
		.curve[29] =  4561,
		.curve[30] =  4839,
		.curve[31] =  5114,
		.curve[32] =  5387,
		.curve[33] =  5656,
		.curve[34] =  5919,
		.curve[35] =  6174,
		.curve[36] =  6421,
		.curve[37] =  6661,
		.curve[38] =  6894,
		.curve[39] =  7119,
		.curve[40] =  7338,
		.curve[41] =  7755,
		.curve[42] =  8146,
		.curve[43] =  8525,
		.curve[44] =  8921,
		.curve[45] =  9334,
		.curve[46] =  9765,
		.curve[47] = 10240,
		.curve[48] = 10752,
		.curve[49] = 11264,
		.curve[50] = 11776,
		.curve[51] = 12288,
		.curve[52] = 12800,
		.curve[53] = 13312,
		.curve[54] = 13824,
		.curve[55] = 14336,
		.curve[56] = 14848,
		.curve[57] = 15360,
		.curve[58] = 15872,
		.curve[59] = 16384,
	},
};

#endif
