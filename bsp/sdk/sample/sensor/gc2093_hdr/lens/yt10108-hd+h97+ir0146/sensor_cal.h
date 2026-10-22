#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4096,
	},
	.dcc = {
		.gain = {1092, 1880, 2378, 1092},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3896,
		.y_trend_2s = 2228,
		.x_curvature = 4392,
		.y_curvature = 4856,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                                     4096,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 166, 402, 256 },
	  .k = 2700,
	  .matrix = { 3735, -1481, -207, -554, 2962, -360, 512, -4694, 6230 } },
	{ .gain = { 256, 225, 290, 256 },
	  .k = 4000,
	  .matrix = { 3533, -1775, 290, -492, 2936, -396, 493, -3571, 5126 } },
	{ .gain = { 256, 259, 258, 256 },
	  .k = 5000,
	  .matrix = { 3481, -1834, 401, -465, 2915, -402, 378, -3187, 4857 } },
	{ .gain = { 256, 289, 218, 256 },
	  .k = 6500,
	  .matrix = { 3523, -1994, 519, -474, 2939, -417, 342, -2950, 4656 } },
	{ .gain = { 256, 307, 196, 256 },
	  .k = 8000,
	  .matrix = { 3507, -2027, 568, -466, 2930, -416, 308, -2761, 4500 } },
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
		.effective_iso[0] = 100,
		.effective_iso[1] = 200,
		.effective_iso[2] = 400,
		.effective_iso[3] = 800,
		.effective_iso[4] = 1600,
		.effective_iso[5] = 3200,
		.effective_iso[6] = 6400,
		.effective_iso[7] = 12800,
		.effective_iso[8] = 25600,
		.effective_iso[9] = 51200,
		.effective_iso[10] = 102400,
	},

	.csm = {
		.sat_table[0] = 130,
		.sat_table[1] = 128,
		.sat_table[2] = 126,
		.sat_table[3] = 124,
		.sat_table[4] = 120,
		.sat_table[5] = 112,
		.sat_table[6] = 96,
		.sat_table[7] = 64,
		.sat_table[8] = 64,
		.sat_table[9] = 48,
		.sat_table[10] = 48,
	},

	.shp = {
		.shp_table[0] = 48,
		.shp_table[1] = 40,
		.shp_table[2] = 36,
		.shp_table[3] = 32,
		.shp_table[4] = 24,
		.shp_table[5] = 16,
		.shp_table[6] = 12,
		.shp_table[7] = 0,
		.shp_table[8] = 0,
		.shp_table[9] = 0,
		.shp_table[10] = 0,
	},

	.nr = {
		.y_level_3d[0] = 119,
		.y_level_3d[1] = 136,
		.y_level_3d[2] = 153,
		.y_level_3d[3] = 170,
		.y_level_3d[4] = 180,
		.y_level_3d[5] = 204,
		.y_level_3d[6] = 221,
		.y_level_3d[7] = 238,
		.y_level_3d[8] = 255,
		.y_level_3d[9] = 255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] = 16,
		.c_level_3d[1] = 32,
		.c_level_3d[2] = 64,
		.c_level_3d[3] = 87,
		.c_level_3d[4] = 100,
		.c_level_3d[5] = 100,
		.c_level_3d[6] = 100,
		.c_level_3d[7] = 100,
		.c_level_3d[8] = 100,
		.c_level_3d[9] = 100,
		.c_level_3d[10] = 100,

		.y_level_2d[0] = 32,
		.y_level_2d[1] = 32,
		.y_level_2d[2] = 32,
		.y_level_2d[3] = 32,
		.y_level_2d[4] = 32,
		.y_level_2d[5] = 32,
		.y_level_2d[6] = 32,
		.y_level_2d[7] = 32,
		.y_level_2d[8] = 32,
		.y_level_2d[9] = 32,
		.y_level_2d[10] = 32,

		.c_level_2d[0] = 255,
		.c_level_2d[1] = 255,
		.c_level_2d[2] = 255,
		.c_level_2d[3] = 255,
		.c_level_2d[4] = 255,
		.c_level_2d[5] = 255,
		.c_level_2d[6] = 255,
		.c_level_2d[7] = 255,
		.c_level_2d[8] = 255,
		.c_level_2d[9] = 255,
		.c_level_2d[10] = 255,
	},

	.gamma = {
		.mode = 0,
	},

	.te = {
		.noise_cstr[0] = 544,
		.noise_cstr[1] = 544,
		.noise_cstr[2] = 544,
		.noise_cstr[3] = 544,
		.noise_cstr[4] = 544,
		.noise_cstr[5] = 544,
		.noise_cstr[6] = 544,
		.noise_cstr[7] = 544,
		.noise_cstr[8] = 544,
		.noise_cstr[9] = 544,
		.noise_cstr[10] = 544,

		.curve[0] = 0,
		.curve[1] = 16,
		.curve[2] = 32,
		.curve[3] = 64,
		.curve[4] = 113,
		.curve[5] = 172,
		.curve[6] = 230,
		.curve[7] = 280,
		.curve[8] = 340,
		.curve[9] = 460,
		.curve[10] = 580,
		.curve[11] = 600,
		.curve[12] = 740,
		.curve[13] = 880,
		.curve[14] = 1030,
		.curve[15] = 1200,
		.curve[16] = 1370,
		.curve[17] = 1540,
		.curve[18] = 1700,
		.curve[19] = 1860,
		.curve[20] = 2048,
		.curve[21] = 2176,
		.curve[22] = 2304,
		.curve[23] = 2432,
		.curve[24] = 2560,
		.curve[25] = 2816,
		.curve[26] = 3072,
		.curve[27] = 3328,
		.curve[28] = 3584,
		.curve[29] = 3840,
		.curve[30] = 4096,
		.curve[31] = 4352,
		.curve[32] = 4608,
		.curve[33] = 4864,
		.curve[34] = 5120,
		.curve[35] = 5376,
		.curve[36] = 5632,
		.curve[37] = 5888,
		.curve[38] = 6144,
		.curve[39] = 6400,
		.curve[40] = 6656,
		.curve[41] = 7168,
		.curve[42] = 7680,
		.curve[43] = 8192,
		.curve[44] = 8704,
		.curve[45] = 9216,
		.curve[46] = 9728,
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
