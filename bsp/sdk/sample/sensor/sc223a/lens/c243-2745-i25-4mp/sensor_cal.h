#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4104,
	},
	.dcc = {
		.gain = { 1092, 1802, 2248, 1092 },
		.offset_2s = { 0, 0, 0, 0 },
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3636,
		.y_trend_2s = 2424,
		.x_curvature = 4244,
		.y_curvature = 4524,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                                     4104,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 165, 400, 256 },
	  .k = 2700,
	  .matrix = { 2021, 607, -579, -1730, 4216, -438, -829, -3445, 6322 } },
	{ .gain = { 256, 222, 289, 256 },
	  .k = 4000,
	  .matrix = { 2196, 111, -259, -1274, 3901, -580, -349, -2542, 4940 } },
	{ .gain = { 256, 259, 254, 256 },
	  .k = 5000,
	  .matrix = { 2274, -47, -179, -1111, 3787, -628, -282, -2300, 4631 } },
	{ .gain = { 256, 293, 216, 256 },
	  .k = 6500,
	  .matrix = { 2361, -215, -98, -1024, 3735, -663, -230, -2015, 4293 } },
	{ .gain = { 256, 311, 195, 256 },
	  .k = 8000,
	  .matrix = { 2376, -231, -97, -971, 3703, -684, -227, -1816, 4091 } },
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
		.sat_table[0] = 142,
		.sat_table[1] = 136,
		.sat_table[2] = 129,
		.sat_table[3] = 116,
		.sat_table[4] = 101,
		.sat_table[5] = 85,
		.sat_table[6] = 64,
		.sat_table[7] = 57,
		.sat_table[8] = 48,
		.sat_table[9] = 48,
		.sat_table[10] = 48,
	},

	.shp = {
		.shp_table[0] = 252,
		.shp_table[1] = 244,
		.shp_table[2] = 216,
		.shp_table[3] = 165,
		.shp_table[4] = 86,
		.shp_table[5] = 44,
		.shp_table[6] = 12,
		.shp_table[7] = 0,
		.shp_table[8] = 0,
		.shp_table[9] = 0,
		.shp_table[10] = 0,
	},

	.nr = {
		.y_level_3d[0] = 181,
		.y_level_3d[1] = 196,
		.y_level_3d[2] = 211,
		.y_level_3d[3] = 219,
		.y_level_3d[4] = 234,
		.y_level_3d[5] = 255,
		.y_level_3d[6] = 255,
		.y_level_3d[7] = 255,
		.y_level_3d[8] = 255,
		.y_level_3d[9] = 255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] = 153,
		.c_level_3d[1] = 160,
		.c_level_3d[2] = 160,
		.c_level_3d[3] = 160,
		.c_level_3d[4] = 160,
		.c_level_3d[5] = 160,
		.c_level_3d[6] = 160,
		.c_level_3d[7] = 160,
		.c_level_3d[8] = 160,
		.c_level_3d[9] = 160,
		.c_level_3d[10] = 160,

		.y_level_2d[0] = 100,
		.y_level_2d[1] = 100,
		.y_level_2d[2] = 100,
		.y_level_2d[3] = 100,
		.y_level_2d[4] = 100,
		.y_level_2d[5] = 100,
		.y_level_2d[6] = 100,
		.y_level_2d[7] = 100,
		.y_level_2d[8] = 100,
		.y_level_2d[9] = 100,
		.y_level_2d[10] = 100,

		.c_level_2d[0] = 150,
		.c_level_2d[1] = 150,
		.c_level_2d[2] = 150,
		.c_level_2d[3] = 150,
		.c_level_2d[4] = 150,
		.c_level_2d[5] = 150,
		.c_level_2d[6] = 150,
		.c_level_2d[7] = 150,
		.c_level_2d[8] = 150,
		.c_level_2d[9] = 150,
		.c_level_2d[10] = 150,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] = 0,
		.noise_cstr[1] = 0,
		.noise_cstr[2] = 512,
		.noise_cstr[3] = 512,
		.noise_cstr[4] = 1024,
		.noise_cstr[5] = 1024,
		.noise_cstr[6] = 1024,
		.noise_cstr[7] = 1024,
		.noise_cstr[8] = 1024,
		.noise_cstr[9] = 1024,
		.noise_cstr[10] = 1024,

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
