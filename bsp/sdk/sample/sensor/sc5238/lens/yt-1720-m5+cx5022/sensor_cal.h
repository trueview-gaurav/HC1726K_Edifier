#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4193,
	},
	.dcc = {
		.gain = {1090, 1781, 1685, 1097},
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
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                                     4193,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 178, 367, 255 },
	  .k = 2700,
	  .matrix = { 3111, 229, -1292, -1218, 4545, -1279, -988, -2815, 5851 } },
	{ .gain = { 256, 219, 311, 255 },
	  .k = 4000,
	  .matrix = { 2776, -403, 325, -1155, 4457, -1253, -255, -2047, 4351 } },
	{ .gain = { 256, 259, 255, 255 },
	  .k = 5000,
	  .matrix = { 3169, -979, -141, -1046, 4935, -1840, -165, -1905, 4119 } },
	{ .gain = { 256, 292, 230, 255 },
	  .k = 6500,
	  .matrix = { 3075, -908, -118, -1016, 4839, -1775, -248, -1461, 3758 } },
	{ .gain = { 256, 330, 221, 255 }, 
	  .k = 7500, 
	  .matrix = { 3747, -1565, -134, -801, 4685, -1835, -146, -1822, 4016 } },
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
		.sat_table[0] =    135,
		.sat_table[1] =    130,
		.sat_table[2] =    122,
		.sat_table[3] =    110,
		.sat_table[4] =    100,
		.sat_table[5] =     95,
		.sat_table[6] =     80,
		.sat_table[7] =     80,
		.sat_table[8] =     70,
		.sat_table[9] =     32,
		.sat_table[10] =    32,
	},

	.shp = {
		.shp_table[0] =   300,
		.shp_table[1] =   290,
		.shp_table[2] =   280,
		.shp_table[3] =   270,
		.shp_table[4] =   260,
		.shp_table[5] =   210,
		.shp_table[6] =   160,
		.shp_table[7] =    80,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  121,
		.y_level_3d[1] =  141,
		.y_level_3d[2] =  171,
		.y_level_3d[3] =  181,
		.y_level_3d[4] =  191,
		.y_level_3d[5] =  201,
		.y_level_3d[6] =  221,
		.y_level_3d[7] =  231,
		.y_level_3d[8] =  231,
		.y_level_3d[9] =  247,
		.y_level_3d[10] = 247,

		.c_level_3d[0] =      0,
		.c_level_3d[1] =     16,
		.c_level_3d[2] =     32,
		.c_level_3d[3] =     64,
		.c_level_3d[4] =     96,
		.c_level_3d[5] =    100,
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
		.curve[12] =   1017,
		.curve[13] =   1205,
		.curve[14] =   1398,
		.curve[15] =   1593,
		.curve[16] =   1790,
		.curve[17] =   1986,
		.curve[18] =   2181,
		.curve[19] =   2375,
		.curve[20] =   2565,
		.curve[21] =   2752,
		.curve[22] =   2936,
		.curve[23] =   3116,
		.curve[24] =   3292,
		.curve[25] =   3633,
		.curve[26] =   3957,
		.curve[27] =   4266,
		.curve[28] =   4561,
		.curve[29] =   4841,
		.curve[30] =   5111,
		.curve[31] =   5368,
		.curve[32] =   5618,
		.curve[33] =   5858,
		.curve[34] =   6092,
		.curve[35] =   6320,
		.curve[36] =   6543,
		.curve[37] =   6763,
		.curve[38] =   6981,
		.curve[39] =   7197,
		.curve[40] =   7411,
		.curve[41] =   7839,
		.curve[42] =   8271,
		.curve[43] =   8710,
		.curve[44] =   9157,
		.curve[45] =   9615,
		.curve[46] =  10085,
		.curve[47] =  10567,
		.curve[48] =  11060,
		.curve[49] =  11562,
		.curve[50] =  12072,
		.curve[51] =  12587,
		.curve[52] =  13103,
		.curve[53] =  13618,
		.curve[54] =  14127,
		.curve[55] =  14623,
		.curve[56] =  15104,
		.curve[57] =  15561,
		.curve[58] =  15991,
		.curve[59] =  16384,
	},
};

#endif
