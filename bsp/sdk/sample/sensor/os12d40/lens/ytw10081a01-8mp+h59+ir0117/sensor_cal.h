#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4108,
	},
	.dcc = {
		.gain = {1092, 2006, 2034, 1092},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3668,
		.y_trend_2s = 2220,
		.x_curvature = 4460,
		.y_curvature = 6292,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                                     4084,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 178, 439, 256 },
	  .k = 2700,
	  .matrix = { 2456, -235, -173, -1268, 3501, -185, -417, -2537, 5002 } },
	{ .gain = { 256, 219, 348, 256 },
	  .k = 4000,
	  .matrix = { 2137, -259, 170, -1028, 3086, -11, -237, -1620, 3905 } },
	{ .gain = { 256, 255, 255, 256 }, .k = 5000, .matrix = { 2370, -476, 154, -830, 3317, -439, 56, -1706, 3698 } },
	{ .gain = { 256, 284, 226, 256 }, .k = 6500, .matrix = { 2964, -927, 11, -563, 3321, -710, 299, -1884, 3633 } },
	{ .gain = { 256, 343, 210, 256 }, .k = 7500, .matrix = { 2688, -680, 41, -505, 3128, -575, 122, -1544, 3470 } },
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
		.sat_table[0] =  140,
		.sat_table[1] =  140,
		.sat_table[2] =  134,
		.sat_table[3] =  122,
		.sat_table[4] =  111,
		.sat_table[5] =  104,
		.sat_table[6] =   99,
		.sat_table[7] =   90,
		.sat_table[8] =   90,
		.sat_table[9] =   90,
		.sat_table[10] =  90,
	},

	.shp = {
		.shp_table[0] =  255,
		.shp_table[1] =  255,
		.shp_table[2] =  248,
		.shp_table[3] =  219,
		.shp_table[4] =  164,
		.shp_table[5] =   67,
		.shp_table[6] =   38,
		.shp_table[7] =   20,
		.shp_table[8] =   20,
		.shp_table[9] =   20,
		.shp_table[10] =  20,
	},

	.nr = {
		.y_level_3d[0] =  168,
		.y_level_3d[1] =  168,
		.y_level_3d[2] =  171,
		.y_level_3d[3] =  182,
		.y_level_3d[4] =  204,
		.y_level_3d[5] =  212,
		.y_level_3d[6] =  231,
		.y_level_3d[7] =  240,
		.y_level_3d[8] =  240,
		.y_level_3d[9] =  240,
		.y_level_3d[10] = 240,

		.c_level_3d[0] =  150,
		.c_level_3d[1] =  150,
		.c_level_3d[2] =  150,
		.c_level_3d[3] =  157,
		.c_level_3d[4] =  160,
		.c_level_3d[5] =  160,
		.c_level_3d[6] =  160,
		.c_level_3d[7] =  160,
		.c_level_3d[8] =  160,
		.c_level_3d[9] =  160,
		.c_level_3d[10] = 160,

		.y_level_2d[0] =  32,
		.y_level_2d[1] =  32,
		.y_level_2d[2] =  32,
		.y_level_2d[3] =  32,
		.y_level_2d[4] =  32,
		.y_level_2d[5] =  32,
		.y_level_2d[6] =  32,
		.y_level_2d[7] =  32,
		.y_level_2d[8] =  32,
		.y_level_2d[9] =  32,
		.y_level_2d[10] = 32,

		.c_level_2d[0] =  32,
		.c_level_2d[1] =  32,
		.c_level_2d[2] =  32,
		.c_level_2d[3] =  32,
		.c_level_2d[4] =  32,
		.c_level_2d[5] =  32,
		.c_level_2d[6] =  32,
		.c_level_2d[7] =  32,
		.c_level_2d[8] =  32,
		.c_level_2d[9] =  32,
		.c_level_2d[10] = 32,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =   864,
		.noise_cstr[1] =  1024,
		.noise_cstr[2] =  1024,
		.noise_cstr[3] =  1024,
		.noise_cstr[4] =  1024,
		.noise_cstr[5] =  1024,
		.noise_cstr[6] =  1024,
		.noise_cstr[7] =  1024,
		.noise_cstr[8] =  1024,
		.noise_cstr[9] =  1024,
		.noise_cstr[10] = 1024,

		.curve[0] =       0,
		.curve[1] =      40,
		.curve[2] =      95,
		.curve[3] =     161,
		.curve[4] =     235,
		.curve[5] =     316,
		.curve[6] =     404,
		.curve[7] =     494,
		.curve[8] =     583,
		.curve[9] =     762,
		.curve[10] =    938,
		.curve[11] =   1110,
		.curve[12] =   1279,
		.curve[13] =   1443,
		.curve[14] =   1602,
		.curve[15] =   1759,
		.curve[16] =   1915,
		.curve[17] =   2070,
		.curve[18] =   2224,
		.curve[19] =   2376,
		.curve[20] =   2528,
		.curve[21] =   2679,
		.curve[22] =   2829,
		.curve[23] =   2978,
		.curve[24] =   3126,
		.curve[25] =   3419,
		.curve[26] =   3709,
		.curve[27] =   3996,
		.curve[28] =   4280,
		.curve[29] =   4561,
		.curve[30] =   4839,
		.curve[31] =   5114,
		.curve[32] =   5387,
		.curve[33] =   5656,
		.curve[34] =   5919,
		.curve[35] =   6174,
		.curve[36] =   6421,
		.curve[37] =   6661,
		.curve[38] =   6894,
		.curve[39] =   7119,
		.curve[40] =   7338,
		.curve[41] =   7755,
		.curve[42] =   8146,
		.curve[43] =   8525,
		.curve[44] =   8921,
		.curve[45] =   9334,
		.curve[46] =   9765,
		.curve[47] =  10240,
		.curve[48] =  10752,
		.curve[49] =  11264,
		.curve[50] =  11776,
		.curve[51] =  12288,
		.curve[52] =  12800,
		.curve[53] =  13312,
		.curve[54] =  13824,
		.curve[55] =  14336,
		.curve[56] =  14848,
		.curve[57] =  15360,
		.curve[58] =  15872,
		.curve[59] =  16384,
	},
};

#endif
