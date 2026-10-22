#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4062,
	},
	.dcc = {
		.gain = {1091, 1808, 1880, 1087},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3600,
		.y_trend_2s = 1912,
		.x_curvature = 6680,
		.y_curvature = 8540,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                                     4062,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 171, 329, 256 },
	  .k = 2700,
	  .matrix = { 4365, -642, -1675, -2239, 7224, -2937, -2237, -3914, 8199 } },
	{ .gain = { 256, 218, 288, 256 },
	  .k = 4000,
	  .matrix = { 5775, -2768, -959, -2260, 6545, -2237, -1234, -3064, 6346 } },
	{ .gain = { 256, 254, 254, 256 },
	  .k = 5000,
	  .matrix = { 6628, -3967, -613, -2233, 6515, -2234, -868, -2699, 5615 } },
	{ .gain = { 256, 274, 230, 256 },
	  .k = 6500,
	  .matrix = { 6625, -4341, -236, -2161, 6532, -2323, -742, -2332, 5122 } },
	{ .gain = { 256, 287, 214, 256 },
	  .k = 7500,
	  .matrix = { 6747, -4361, -338, -2174, 6517, -2295, -639, -2223, 4910 } },
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
		.effective_iso[0] =  138,
		.effective_iso[1] =  181,
		.effective_iso[2] =  264,
		.effective_iso[3] =  370,
		.effective_iso[4] =  497,
		.effective_iso[5] =  736,
		.effective_iso[6] =  984,
		.effective_iso[7] =  1390,
		.effective_iso[8] =  1965,
		.effective_iso[9] =  2637,
		.effective_iso[10] =  3783,
	},

	.csm = {
		.sat_table[0] =    128,
		.sat_table[1] =    126,
		.sat_table[2] =    124,
		.sat_table[3] =    120,
		.sat_table[4] =    116,
		.sat_table[5] =    112,
		.sat_table[6] =    108,
		.sat_table[7] =    100,
		.sat_table[8] =    90,
		.sat_table[9] =    85,
		.sat_table[10] =    75,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   255,
		.shp_table[3] =   254,
		.shp_table[4] =   241,
		.shp_table[5] =   212,
		.shp_table[6] =   160,
		.shp_table[7] =    67,
		.shp_table[8] =    36,
		.shp_table[9] =    15,
		.shp_table[10] =   15,
	},

	.nr = {
		.y_level_3d[0] =  90,
		.y_level_3d[1] =  95,
		.y_level_3d[2] =  105,
		.y_level_3d[3] =  110,
		.y_level_3d[4] =  120,
		.y_level_3d[5] =  155,
		.y_level_3d[6] =  165,
		.y_level_3d[7] =  175,
		.y_level_3d[8] =  185,
		.y_level_3d[9] =  255,
		.y_level_3d[10] =  255,

		.c_level_3d[0] =    24,
		.c_level_3d[1] =    42,
		.c_level_3d[2] =    72,
		.c_level_3d[3] =    128,
		.c_level_3d[4] =    145,
		.c_level_3d[5] =    170,
		.c_level_3d[6] =    190,
		.c_level_3d[7] =    215,
		.c_level_3d[8] =    235,
		.c_level_3d[9] =    255,
		.c_level_3d[10] =    255,

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
		.y_level_2d[10] =    0,

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
		.c_level_2d[10] =    0,
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
