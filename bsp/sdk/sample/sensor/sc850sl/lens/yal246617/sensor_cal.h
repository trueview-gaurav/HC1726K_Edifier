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
		.gain = {1093, 2191, 2302, 1093},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 5868,
		.y_trend_2s = 2300,
		.x_curvature = 14328,
		.y_curvature = 28416,
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
	{ .gain = { 256, 154, 425, 256 }, .k = 2700, .matrix = { 2180, -13, -119, -1226, 3668, -395, 70, -2840, 4818 } },
	{ .gain = { 256, 218, 291, 256 }, .k = 4000, .matrix = { 2333, -285, 1, -876, 3526, -602, 38, -2034, 4044 } },
	{ .gain = { 265, 255, 255, 256 }, .k = 5000, .matrix = { 2411, -394, 31, -751, 3463, -664, 17, -1837, 3868 } },
	{ .gain = { 256, 291, 216, 256 }, .k = 6500, .matrix = { 2490, -504, 62, -689, 3478, -741, -10, -1574, 3632 } },
	{ .gain = { 256, 305, 198, 256 }, .k = 7500, .matrix = { 2521, -537, 64, -652, 3459, -758, -13, -1484, 3545 } },
	{ .gain = { 256, 268, 249, 255 }, .k = 0, .matrix = { 5102, -3259, 204, -1083, 3792, -661, -604, -2550, 5202 } },
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
		.sat_table[1] =    138,
		.sat_table[2] =    129,
		.sat_table[3] =    119,
		.sat_table[4] =    109,
		.sat_table[5] =    101,
		.sat_table[6] =    100,
		.sat_table[7] =    100,
		.sat_table[8] =    100,
		.sat_table[9] =    100,
		.sat_table[10] =   100,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   255,
		.shp_table[3] =   251,
		.shp_table[4] =   241,
		.shp_table[5] =   222,
		.shp_table[6] =   203,
		.shp_table[7] =   160,
		.shp_table[8] =   121,
		.shp_table[9] =    82,
		.shp_table[10] =   82,
	},

	.nr = {
		.y_level_3d[0] =  168,
		.y_level_3d[1] =  173,
		.y_level_3d[2] =  183,
		.y_level_3d[3] =  204,
		.y_level_3d[4] =  209,
		.y_level_3d[5] =  228,
		.y_level_3d[6] =  239,
		.y_level_3d[7] =  240,
		.y_level_3d[8] =  249,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =    150,
		.c_level_3d[1] =    150,
		.c_level_3d[2] =    158,
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
		.curve[5] =    315,
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
