#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4088,
	},
	.dcc = {
		.gain = {1093, 1872, 1498, 1085},
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
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                                     4088,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 186, 357, 256 },
	  .k = 2700,
	  .matrix = { 4578, -1782, -748, -2763, 6820, -2009, -3001, -8371, 13775 } },
	{ .gain = { 256, 220, 314, 256 },
	  .k = 4150,
	  .matrix = { 6151, -4572, 469, -2230, 5192, -914, -1027, -4916, 7992 } },
	{ .gain = { 256, 256, 256, 256 },
	  .k = 6500,
	  .matrix = { 5385, -3862, 525, -1382, 5057, -1627, -333, -3892, 6274 } },
	{ .gain = { 256, 369, 204, 256 },
	  .k = 8000,
	  .matrix = { 5583, -3878, 343, -1360, 4468, -1059, -514, -3157, 5720 } },
	{ .gain = { 256, 256, 256, 256 }, .k = 0, .matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 } },
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
		.sat_table[0] =    130,
		.sat_table[1] =    128,
		.sat_table[2] =    100,
		.sat_table[3] =     60,
		.sat_table[4] =     40,
		.sat_table[5] =     20,
		.sat_table[6] =     20,
		.sat_table[7] =     20,
		.sat_table[8] =     20,
		.sat_table[9] =     20,
		.sat_table[10] =    20,
	},

	.shp = {
		.shp_table[0] =   240,
		.shp_table[1] =   200,
		.shp_table[2] =   160,
		.shp_table[3] =   120,
		.shp_table[4] =    80,
		.shp_table[5] =    40,
		.shp_table[6] =    40,
		.shp_table[7] =    40,
		.shp_table[8] =    40,
		.shp_table[9] =    40,
		.shp_table[10] =   40,
	},

	.nr = {
		.y_level_3d[0] =  111,
		.y_level_3d[1] =  135,
		.y_level_3d[2] =  141,
		.y_level_3d[3] =  153,
		.y_level_3d[4] =  165,
		.y_level_3d[5] =  179,
		.y_level_3d[6] =  185,
		.y_level_3d[7] =  191,
		.y_level_3d[8] =  191,
		.y_level_3d[9] =  191,
		.y_level_3d[10] = 191,

		.c_level_3d[0] =      0,
		.c_level_3d[1] =     37,
		.c_level_3d[2] =     62,
		.c_level_3d[3] =     71,
		.c_level_3d[4] =     80,
		.c_level_3d[5] =     89,
		.c_level_3d[6] =     98,
		.c_level_3d[7] =    103,
		.c_level_3d[8] =    103,
		.c_level_3d[9] =    103,
		.c_level_3d[10] =   103,

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
