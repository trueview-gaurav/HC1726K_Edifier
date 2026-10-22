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
		.dbc_level = 922,
	},
	.dcc = {
		.gain = {1039, 1548, 1458, 1039},
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
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                                     922,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 178, 332, 256 },
	  .k = 2700,
	  .matrix = { 3597, -441, -1109, -2366, 5697, -1283, -3570, -5122, 10740 } },
	{ .gain = { 256, 223, 292, 256 },
	  .k = 4000,
	  .matrix = { 3478, -1833, 403, -1838, 4739, -853, -1486, -4016, 7550 } },
	{ .gain = { 256, 257, 257, 256 },
	  .k = 5000,
	  .matrix = { 3819, -2340, 569, -1511, 5338, -1779, -799, -3717, 6564 } },
	{ .gain = { 256, 281, 238, 256 },
	  .k = 6500,
	  .matrix = { 3691, -2340, 697, -1485, 5185, -1652, -722, -3111, 5881 } },
	{ .gain = { 256, 296, 233, 256 }, 
	  .k = 7500, 
	  .matrix = { 4169, -2403, 282, -1181, 5044, -1815, -521, -3271, 5840 } },
	{ .gain = { 256, 392, 168, 256 }, 
	  .k = 10000, 
	  .matrix = { 5844, -4190, 394, -845, 5150,-2257, -146, -2486, 4680 } },
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
		.sat_table[0] =    144,
		.sat_table[1] =    136,
		.sat_table[2] =    120,
		.sat_table[3] =    115,
		.sat_table[4] =    105,
		.sat_table[5] =    100,
		.sat_table[6] =    100,
		.sat_table[7] =     80,
		.sat_table[8] =     80,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
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
		.y_level_3d[0] =    160,
		.y_level_3d[1] =    175,
		.y_level_3d[2] =    180,
		.y_level_3d[3] =    200,
		.y_level_3d[4] =    211,
		.y_level_3d[5] =    220,
		.y_level_3d[6] =    230,
		.y_level_3d[7] =    240,
		.y_level_3d[8] =    250,
		.y_level_3d[9] =    255,
		.y_level_3d[10] =   255,

		.c_level_3d[0] =    130,
		.c_level_3d[1] =    146,
		.c_level_3d[2] =    162,
		.c_level_3d[3] =    178,
		.c_level_3d[4] =    194,
		.c_level_3d[5] =    210,
		.c_level_3d[6] =    226,
		.c_level_3d[7] =    226,
		.c_level_3d[8] =    226,
		.c_level_3d[9] =    226,
		.c_level_3d[10] =   226,

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
