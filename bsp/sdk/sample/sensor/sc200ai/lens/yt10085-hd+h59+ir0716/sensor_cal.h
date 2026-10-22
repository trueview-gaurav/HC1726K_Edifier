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
		.gain = {1093, 1847, 2054, 1093},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3808,
		.y_trend_2s = 2532,
		.x_curvature = 4884,
		.y_curvature = 5012,
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
	{ .gain = { 256, 144, 472, 256 },
	  .k = 2700,
	  .matrix = { 2432, 685, -1069, -1418, 4376, -909, -272, -597, 2917 } },
	{ .gain = { 256, 213, 352, 256 },
	  .k = 4000,
	  .matrix = { 1969, 130, -51, -1181, 3525, -296, -217, -1062, 3326 } },
	{ .gain = { 256, 251, 255, 256 }, .k = 5000, .matrix = { 2068, -150, 130, -990, 3519, -481, -81, -1302, 3431 } },
	{ .gain = { 256, 288, 226, 256 }, .k = 6500, .matrix = { 2556, -571, 63, -640, 3442, -754, 139, -1305, 3213 } },
	{ .gain = { 256, 302, 210, 256 }, .k = 7500, .matrix = { 1837, 276, -65, -832, 3478, -597, -247, -934, 3229 } },
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
		.sat_table[0] =    140,
		.sat_table[1] =    140,
		.sat_table[2] =    140,
		.sat_table[3] =    130,
		.sat_table[4] =    121,
		.sat_table[5] =    111,
		.sat_table[6] =    106,
		.sat_table[7] =    102,
		.sat_table[8] =     93,
		.sat_table[9] =     93,
		.sat_table[10] =    93,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   255,
		.shp_table[3] =   242,
		.shp_table[4] =   212,
		.shp_table[5] =   166,
		.shp_table[6] =    85,
		.shp_table[7] =    50,
		.shp_table[8] =    27,
		.shp_table[9] =    27,
		.shp_table[10] =   27,
	},

	.nr = {
		.y_level_3d[0] =  168,
		.y_level_3d[1] =  168,
		.y_level_3d[2] =  168,
		.y_level_3d[3] =  174,
		.y_level_3d[4] =  184,
		.y_level_3d[5] =  203,
		.y_level_3d[6] =  209,
		.y_level_3d[7] =  224,
		.y_level_3d[8] =  237,
		.y_level_3d[9] =  237,
		.y_level_3d[10] = 237,

		.c_level_3d[0] =    150,
		.c_level_3d[1] =    150,
		.c_level_3d[2] =    150,
		.c_level_3d[3] =    150,
		.c_level_3d[4] =    159,
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
