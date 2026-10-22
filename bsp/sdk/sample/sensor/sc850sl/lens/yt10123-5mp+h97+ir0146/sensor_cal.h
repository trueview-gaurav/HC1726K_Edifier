#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4095,
	},
	.dcc = {
		.gain = {1096, 2124, 2175, 1091},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 5448,
		.y_trend_2s = 3852,
		.x_curvature = 11482,
		.y_curvature = 11198,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                                     4095,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 153, 428, 256 }, .k = 2700, .matrix = { 3426, -1677, 299, -428, 2178, 298, 620, -4030, 5458 } },
	{ .gain = { 256, 186, 318, 256 }, .k = 4000, .matrix = { 2719, -1002, 331, -653, 2564, 137, 175, -2299, 4172 } },
	{ .gain = { 256, 222, 232, 256 },
	  .k = 5000,
	  .matrix = { 2939, -1246, 354, -520, 2911, -343, 312, -2243, 3979 } },
	{ .gain = { 256, 250, 204, 256 },
	  .k = 6500,
	  .matrix = { 3292, -1564, 320, -310, 2855, -497, 390, -2146, 3804 } },
	{ .gain = { 256, 308, 194, 256 },
	  .k = 7500,
	  .matrix = { 3290, -1627, 384, -202, 2616, -366, 373, -2186, 3862 } },
	{ .gain = { 256, 514, 129, 256 }, .k = 0, .matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 } },
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
		.sat_table[5] =     90,
		.sat_table[6] =     64,
		.sat_table[7] =     64,
		.sat_table[8] =     64,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
	},

	.shp = {
		.shp_table[0] =   210,
		.shp_table[1] =   200,
		.shp_table[2] =   195,
		.shp_table[3] =   190,
		.shp_table[4] =   185,
		.shp_table[5] =   180,
		.shp_table[6] =   128,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  104,
		.y_level_3d[1] =  112,
		.y_level_3d[2] =  144,
		.y_level_3d[3] =  156,
		.y_level_3d[4] =  180,
		.y_level_3d[5] =  210,
		.y_level_3d[6] =  245,
		.y_level_3d[7] =  255,
		.y_level_3d[8] =  255,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =     16,
		.c_level_3d[1] =     32,
		.c_level_3d[2] =     64,
		.c_level_3d[3] =     87,
		.c_level_3d[4] =    100,
		.c_level_3d[5] =    100,
		.c_level_3d[6] =    100,
		.c_level_3d[7] =    100,
		.c_level_3d[8] =    100,
		.c_level_3d[9] =    100,
		.c_level_3d[10] =   100,

		.y_level_2d[0] =      0,
		.y_level_2d[1] =      0,
		.y_level_2d[2] =      0,
		.y_level_2d[3] =      0,
		.y_level_2d[4] =      0,
		.y_level_2d[5] =      0,
		.y_level_2d[6] =      0,
		.y_level_2d[7] =      0,
		.y_level_2d[8] =      0,
		.y_level_2d[9] =      0,
		.y_level_2d[10] =     0,

		.c_level_2d[0] =      0,
		.c_level_2d[1] =      0,
		.c_level_2d[2] =      0,
		.c_level_2d[3] =      0,
		.c_level_2d[4] =      0,
		.c_level_2d[5] =      0,
		.c_level_2d[6] =      0,
		.c_level_2d[7] =      0,
		.c_level_2d[8] =      0,
		.c_level_2d[9] =      0,
		.c_level_2d[10] =     0,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =     32,
		.noise_cstr[1] =    544,
		.noise_cstr[2] =    800,
		.noise_cstr[3] =    928,
		.noise_cstr[4] =    992,
		.noise_cstr[5] =   1024,
		.noise_cstr[6] =   1024,
		.noise_cstr[7] =   1024,
		.noise_cstr[8] =   1024,
		.noise_cstr[9] =   1024,
		.noise_cstr[10] =  1024,

		.curve[0] =      0,
		.curve[1] =     20,
		.curve[2] =     40,
		.curve[3] =     80,
		.curve[4] =    130,
		.curve[5] =    180,
		.curve[6] =    230,
		.curve[7] =    280,
		.curve[8] =    340,
		.curve[9] =    460,
		.curve[10] =   580,
		.curve[11] =   600,
		.curve[12] =   740,
		.curve[13] =   880,
		.curve[14] =  1030,
		.curve[15] =  1200,
		.curve[16] =  1370,
		.curve[17] =  1540,
		.curve[18] =  1700,
		.curve[19] =  1860,
		.curve[20] =  2048,
		.curve[21] =  2176,
		.curve[22] =  2304,
		.curve[23] =  2432,
		.curve[24] =  2560,
		.curve[25] =  2816,
		.curve[26] =  3072,
		.curve[27] =  3328,
		.curve[28] =  3584,
		.curve[29] =  3840,
		.curve[30] =  4096,
		.curve[31] =  4352,
		.curve[32] =  4608,
		.curve[33] =  4864,
		.curve[34] =  5120,
		.curve[35] =  5376,
		.curve[36] =  5632,
		.curve[37] =  5888,
		.curve[38] =  6144,
		.curve[39] =  6400,
		.curve[40] =  6656,
		.curve[41] =  7168,
		.curve[42] =  7680,
		.curve[43] =  8192,
		.curve[44] =  8704,
		.curve[45] =  9216,
		.curve[46] =  9728,
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
