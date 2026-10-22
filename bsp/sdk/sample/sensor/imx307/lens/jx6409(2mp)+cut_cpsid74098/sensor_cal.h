#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

#define SENSOR_PIXEL_CLOCK (74250000)

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 3839,
	},
	.dcc = {
		.gain = {1087, 2207, 2124, 1091},
		.offset_2s = {0, 2, 29, -7},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3872,
		.y_trend_2s = 1910,
		.x_curvature = 2867,
		.y_curvature = 1092,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     3839,
	                                                     3835,
	                                                     3802,
	                                                     3770,
	                                                     3791,
	                                                     3812,
	                                                     3812,
	                                                     3812,
	                                                     3812,
	                                                     3812,
	                                                     3812,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 166, 418, 256 },
	  .k = 2700,
	  .matrix = { 2267, -1030, 811, -1261, 2678, 631, 274, -3543, 5317 } },
	{ .gain = { 256, 196, 325, 256 },
	  .k = 4000,
	  .matrix = { 2383, -789, 454, -1108, 2695, 461, 86, -2856, 4818 } },
	{ .gain = { 256, 226, 241, 256 },
	  .k = 5000,
	  .matrix = { 2667, -797, 178, -1267, 3760, -445, -3, -2421, 4472 } },
	{ .gain = { 256, 252, 208, 256 },
	  .k = 6500,
	  .matrix = { 2636, -1023, 435, -958, 3154, -148, 17, -2231, 4262 } },
	{ .gain = { 256, 320, 197, 256 },
	  .k = 7500,
	  .matrix = { 3070, -1089, 67, -1018, 3793, -727, -185, -2139, 4372 } },
	{ .gain = { 256, 450, 256, 256 }, .k = 0, .matrix = { 2575, -821, 294, -413, 3090, -628, -10, -1025, 3084 } },
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
		.effective_iso[0] =     350,
		.effective_iso[1] =     450,
		.effective_iso[2] =     700,
		.effective_iso[3] =    1000,
		.effective_iso[4] =    2800,
		.effective_iso[5] =    4200,
		.effective_iso[6] =    8400,
		.effective_iso[7] =   12800,
		.effective_iso[8] =   25600,
		.effective_iso[9] =   51200,
		.effective_iso[10] = 102400,
	},

	.csm = {
		.sat_table[0] =    128,
		.sat_table[1] =    120,
		.sat_table[2] =    115,
		.sat_table[3] =    110,
		.sat_table[4] =    105,
		.sat_table[5] =    100,
		.sat_table[6] =     90,
		.sat_table[7] =     75,
		.sat_table[8] =     64,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
	},

	.shp = {
		.shp_table[0] =   128,
		.shp_table[1] =   118,
		.shp_table[2] =   108,
		.shp_table[3] =   100,
		.shp_table[4] =    90,
		.shp_table[5] =    90,
		.shp_table[6] =    90,
		.shp_table[7] =    90,
		.shp_table[8] =    87,
		.shp_table[9] =    64,
		.shp_table[10] =   64,
	},

	.nr = {
		.y_level_3d[0] =  85,
		.y_level_3d[1] =  95,
		.y_level_3d[2] =  105,
		.y_level_3d[3] =  115,
		.y_level_3d[4] =  135,
		.y_level_3d[5] =  170,
		.y_level_3d[6] =  200,
		.y_level_3d[7] =  220,
		.y_level_3d[8] =  255,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =    130,
		.c_level_3d[1] =    146,
		.c_level_3d[2] =    162,
		.c_level_3d[3] =    162,
		.c_level_3d[4] =    162,
		.c_level_3d[5] =    162,
		.c_level_3d[6] =    162,
		.c_level_3d[7] =    162,
		.c_level_3d[8] =    162,
		.c_level_3d[9] =    162,
		.c_level_3d[10] =   162,

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
