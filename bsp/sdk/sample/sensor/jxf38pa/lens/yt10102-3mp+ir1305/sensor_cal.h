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
	36, //30 degree
	43, //50 degree
	61, //60 degree
	117, //70 degree
	183, //80 degree
};

// BLC target
static int k_sensor_blc_val[SENSOR_BLC_NUM] = {
	16, 17, 20, 25, 36,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 998,
	},
	.dcc = {
		.gain = {1039, 1439, 1469, 1039},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3772,
		.y_trend_2s = 2401,
		.x_curvature = 7290,
		.y_curvature = 7767,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                                     998,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 222, 342, 256 },
	  .k = 2800,
	  .matrix = { 7692, -5127, -518, -2177, 4964, -739, -2177, -7324, 11549 } },
	{ .gain = { 256, 238, 300, 256 },
	  .k = 4000,
	  .matrix = { 11985, -8577, -1360, -2468, 5991, -1475, 512, -8788, 10324 } },
	{ .gain = { 256, 255, 259, 256 },
	  .k = 5000,
	  .matrix = { 11985, -9601, -336, -2468, 5991, -1475, 1518, -10027, 10561 } },
	{ .gain = { 256, 264, 239, 256 },
	  .k = 6500,
	  .matrix = { 11985, -9601, -336, -2468, 5991, -1475, 1518, -10027, 10561 } },
	{ .gain = { 256, 281, 228, 256 },
	  .k = 7500,
	  .matrix = { 11985, -9601, -336, -2468, 5991, -1475, 1518, -10027, 10561 } },
	{ .gain = { 256, 192, 380, 256 },
	  .k = 2300,
	  .matrix = { 10111, -7324, -739, -3483, 6714, -1183, -3048, -10253, 15349 } },
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
		.sat_table[1] =    118,
		.sat_table[2] =    110,
		.sat_table[3] =    100,
		.sat_table[4] =     90,
		.sat_table[5] =     90,
		.sat_table[6] =     90,
		.sat_table[7] =     90,
		.sat_table[8] =     87,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   250,
		.shp_table[2] =   220,
		.shp_table[3] =   200,
		.shp_table[4] =   180,
		.shp_table[5] =   170,
		.shp_table[6] =   170,
		.shp_table[7] =   170,
		.shp_table[8] =   170,
		.shp_table[9] =   170,
		.shp_table[10] =  170,
	},

	.nr = {
		.y_level_3d[0] =  160,
		.y_level_3d[1] =  175,
		.y_level_3d[2] =  180,
		.y_level_3d[3] =  200,
		.y_level_3d[4] =  211,
		.y_level_3d[5] =  220,
		.y_level_3d[6] =  230,
		.y_level_3d[7] =  240,
		.y_level_3d[8] =  250,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =  130,
		.c_level_3d[1] =  146,
		.c_level_3d[2] =  162,
		.c_level_3d[3] =  178,
		.c_level_3d[4] =  194,
		.c_level_3d[5] =  210,
		.c_level_3d[6] =  226,
		.c_level_3d[7] =  226,
		.c_level_3d[8] =  226,
		.c_level_3d[9] =  226,
		.c_level_3d[10] = 226,

		.y_level_2d[0] =  100,
		.y_level_2d[1] =  100,
		.y_level_2d[2] =  100,
		.y_level_2d[3] =  100,
		.y_level_2d[4] =  100,
		.y_level_2d[5] =  100,
		.y_level_2d[6] =  100,
		.y_level_2d[7] =  100,
		.y_level_2d[8] =  100,
		.y_level_2d[9] =  100,
		.y_level_2d[10] = 100,

		.c_level_2d[0] =  150,
		.c_level_2d[1] =  150,
		.c_level_2d[2] =  150,
		.c_level_2d[3] =  150,
		.c_level_2d[4] =  150,
		.c_level_2d[5] =  150,
		.c_level_2d[6] =  150,
		.c_level_2d[7] =  150,
		.c_level_2d[8] =  150,
		.c_level_2d[9] =  150,
		.c_level_2d[10] = 150,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =      0,
		.noise_cstr[1] =      0,
		.noise_cstr[2] =    256,
		.noise_cstr[3] =    512,
		.noise_cstr[4] =    700,
		.noise_cstr[5] =    768,
		.noise_cstr[6] =    900,
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
