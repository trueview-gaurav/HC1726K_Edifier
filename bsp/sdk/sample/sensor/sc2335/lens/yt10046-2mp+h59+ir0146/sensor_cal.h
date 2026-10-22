#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4116,
	},
	.dcc = {
		.gain = {1093, 1797, 1577, 1093},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3872,
		.y_trend_2s = 2401,
		.x_curvature = 7290,
		.y_curvature = 7767,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                                     4116,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 191, 370, 256 },
	  .k = 2700,
	  .matrix = { 3404, -1350, -7, -2046, 4776, -682, -1716, -5113, 8877 } },
	{ .gain = { 256, 222, 310, 256 },
	  .k = 4000,
	  .matrix = { 3552, -1755, 251, -1668, 4393, -676, -655, -2653, 5356 } },
	{ .gain = { 256, 257, 257, 256 },
	  .k = 5000,
	  .matrix = { 3333, -1741, 456, -1553, 4758, -1157, -425, -2999, 5472 } },
	{ .gain = { 256, 281, 232, 256 },
	  .k = 6500,
	  .matrix = { 3212, -1673, 509, -1521, 4653, -1084, -454, -2438, 4940 } },
	{ .gain = { 256, 324, 226, 256 },
	  .k = 7500,
	  .matrix = { 4010, -2299, 338, -1113, 4343, -1182, -200, -2582, 4830 } },
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
		.sat_table[0] =    138,
		.sat_table[1] =    129,
		.sat_table[2] =    120,
		.sat_table[3] =    110,
		.sat_table[4] =    104,
		.sat_table[5] =     98,
		.sat_table[6] =     90,
		.sat_table[7] =     90,
		.sat_table[8] =     90,
		.sat_table[9] =     90,
		.sat_table[10] =    90,
	},

	.shp = {
		.shp_table[0] =   200,
		.shp_table[1] =   180,
		.shp_table[2] =   130,
		.shp_table[3] =    80,
		.shp_table[4] =    50,
		.shp_table[5] =    20,
		.shp_table[6] =     0,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  169,
		.y_level_3d[1] =  174,
		.y_level_3d[2] =  185,
		.y_level_3d[3] =  204,
		.y_level_3d[4] =  213,
		.y_level_3d[5] =  232,
		.y_level_3d[6] =  240,
		.y_level_3d[7] =  242,
		.y_level_3d[8] =  255,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =    150,
		.c_level_3d[1] =    150,
		.c_level_3d[2] =    160,
		.c_level_3d[3] =    160,
		.c_level_3d[4] =    160,
		.c_level_3d[5] =    160,
		.c_level_3d[6] =    160,
		.c_level_3d[7] =    160,
		.c_level_3d[8] =    160,
		.c_level_3d[9] =    160,
		.c_level_3d[10] =   160,

		.y_level_2d[0] =    255,
		.y_level_2d[1] =    255,
		.y_level_2d[2] =    255,
		.y_level_2d[3] =    255,
		.y_level_2d[4] =    255,
		.y_level_2d[5] =    255,
		.y_level_2d[6] =    255,
		.y_level_2d[7] =    255,
		.y_level_2d[8] =    255,
		.y_level_2d[9] =    255,
		.y_level_2d[10] =   255,

		.c_level_2d[0] =    255,
		.c_level_2d[1] =    255,
		.c_level_2d[2] =    255,
		.c_level_2d[3] =    255,
		.c_level_2d[4] =    255,
		.c_level_2d[5] =    255,
		.c_level_2d[6] =    255,
		.c_level_2d[7] =    255,
		.c_level_2d[8] =    255,
		.c_level_2d[9] =    255,
		.c_level_2d[10] =   255,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =    896,
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
		.curve[1] =     28,
		.curve[2] =     86,
		.curve[3] =    157,
		.curve[4] =    234,
		.curve[5] =    316,
		.curve[6] =    404,
		.curve[7] =    494,
		.curve[8] =    587,
		.curve[9] =    779,
		.curve[10] =   977,
		.curve[11] =  1179,
		.curve[12] =  1385,
		.curve[13] =  1595,
		.curve[14] =  1807,
		.curve[15] =  2018,
		.curve[16] =  2225,
		.curve[17] =  2427,
		.curve[18] =  2623,
		.curve[19] =  2814,
		.curve[20] =  2999,
		.curve[21] =  3180,
		.curve[22] =  3355,
		.curve[23] =  3524,
		.curve[24] =  3689,
		.curve[25] =  4003,
		.curve[26] =  4297,
		.curve[27] =  4572,
		.curve[28] =  4830,
		.curve[29] =  5070,
		.curve[30] =  5293,
		.curve[31] =  5501,
		.curve[32] =  5693,
		.curve[33] =  5873,
		.curve[34] =  6054,
		.curve[35] =  6240,
		.curve[36] =  6431,
		.curve[37] =  6626,
		.curve[38] =  6827,
		.curve[39] =  7032,
		.curve[40] =  7242,
		.curve[41] =  7675,
		.curve[42] =  8127,
		.curve[43] =  8584,
		.curve[44] =  9016,
		.curve[45] =  9423,
		.curve[46] =  9807,
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
