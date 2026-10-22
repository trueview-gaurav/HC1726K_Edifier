#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

#define SENSOR_PIXEL_CLOCK (76147400)

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 3840,
	},
	.dcc = {
		.gain = {1094, 1995, 1870, 1094},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3872,
		.y_trend_2s = 2401,
		.x_curvature = 7290,
		.y_curvature = 7767,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                                     3840,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 162, 520, 255 },
	  .k = 2700,
	  .matrix = { 3124, -735, -341, -1334, 3723, -340, 712, -4365, 5700 } },
	{ .gain = { 256, 229, 400, 255 },
	  .k = 4150,
	  .matrix = { 3776, -1820, 91, -1135, 3285, -102, 496, -2508, 4059 } },
	{ .gain = { 256, 252, 261, 255 },
	  .k = 6500,
	  .matrix = { 3282, -1398, 163, -790, 3464, -626, 499, -2248, 3796 } },
	{ .gain = { 256, 277, 248, 255 },
	  .k = 8000,
	  .matrix = { 3314, -1400, 134, -677, 3085, -360, 248, -1701, 3501 } },
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
		.sat_table[0] =    138,
		.sat_table[1] =    138,
		.sat_table[2] =    128,
		.sat_table[3] =    128,
		.sat_table[4] =    118,
		.sat_table[5] =    110,
		.sat_table[6] =    110,
		.sat_table[7] =    105,
		.sat_table[8] =     10,
		.sat_table[9] =     10,
		.sat_table[10] =    10,
	},

	.shp = {
		.shp_table[0] =   200,
		.shp_table[1] =   191,
		.shp_table[2] =   191,
		.shp_table[3] =   191,
		.shp_table[4] =    64,
		.shp_table[5] =     0,
		.shp_table[6] =     0,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =    150,
		.y_level_3d[1] =    150,
		.y_level_3d[2] =    160,
		.y_level_3d[3] =    170,
		.y_level_3d[4] =    175,
		.y_level_3d[5] =    188,
		.y_level_3d[6] =    200,
		.y_level_3d[7] =    200,
		.y_level_3d[8] =    200,
		.y_level_3d[9] =    200,
		.y_level_3d[10] =   200,

		.c_level_3d[0] =     25,
		.c_level_3d[1] =     37,
		.c_level_3d[2] =     62,
		.c_level_3d[3] =     77,
		.c_level_3d[4] =     87,
		.c_level_3d[5] =    110,
		.c_level_3d[6] =    150,
		.c_level_3d[7] =    150,
		.c_level_3d[8] =    150,
		.c_level_3d[9] =    150,
		.c_level_3d[10] =   150,

		.y_level_2d[0] =     32,
		.y_level_2d[1] =     64,
		.y_level_2d[2] =     96,
		.y_level_2d[3] =    128,
		.y_level_2d[4] =    128,
		.y_level_2d[5] =    128,
		.y_level_2d[6] =    225,
		.y_level_2d[7] =    255,
		.y_level_2d[8] =    255,
		.y_level_2d[9] =    255,
		.y_level_2d[10] =   255,

		.c_level_2d[0] =     32,
		.c_level_2d[1] =     64,
		.c_level_2d[2] =     96,
		.c_level_2d[3] =    128,
		.c_level_2d[4] =    128,
		.c_level_2d[5] =    128,
		.c_level_2d[6] =    225,
		.c_level_2d[7] =    255,
		.c_level_2d[8] =    255,
		.c_level_2d[9] =    255,
		.c_level_2d[10] =   255,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =    960,
		.noise_cstr[1] =    960,
		.noise_cstr[2] =    960,
		.noise_cstr[3] =    960,
		.noise_cstr[4] =   1024,
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
