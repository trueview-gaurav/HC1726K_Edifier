#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 5745,
	},
	.dcc = {
		.gain = { 1337, 2199, 2799, 1337 },
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

/* clang-format off */

static MPI_BLACK_LEVEL_TABLE_S black_level_table = {
	.black_level = {
		5745,
		5745,
		5745,
		5745,
		5745,
		5745,
		5745,
		5745,
		5745,
		5745,
		5745,
	}
};

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
		.gain = { 255, 176, 457, 256 },
		.k = 2700,
		.matrix = { 2044, -28, 32, -1557, 3615, -9, -93, -3059, 5200 }
	},
	{
		.gain = { 255, 225, 353, 256 },
		.k = 4000,
		.matrix = { 1860, -509, 696, -1241, 2973, 316, 131, -2780, 4697 }
	},
	{
		.gain = { 255, 260, 255, 256 },
		.k = 5000,
		.matrix = { 1984, -425, 488, -1199, 3501, -254, 85, -2147, 4110 }
	},
	{
		.gain = { 255, 298, 218, 256 },
		.k = 6500,
		.matrix = { 1863, -542, 727, -1001, 3023, 25, 329, -2691, 4410 }
	},
	{
		.gain = { 255, 321, 218, 256 },
		.k = 8000,
		.matrix = { 2662, -881, 266, -510, 2561, -2, 65, -1693, 3675 }
	},
	{
		.gain = { 256, 256, 256, 256 },
		.k = 0,
		.matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 }
	},
	{
		.gain = { 256, 256, 256, 256 },
		.k = 0,
		.matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 }
	},
	{
		.gain = { 256, 256, 256, 256 },
		.k = 0,
		.matrix = { 2048, 0, 0, 0, 2048, 0, 0, 0, 2048 }
	},
};

static MPI_AWB_COLOR_DELTA_S delta_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 0, 0, 0, 0 } }, // gr, r, b, gb
	{ .gain = { 0, 0, 0, 0 } },
	{ .gain = { 0, 0, 0, 0 } },
	{ .gain = { 0, 0, 0, 0 } },
	{ .gain = { 0, 0, 0, 0 } },
	{ .gain = { 0, 0, 0, 0 } },
	{ .gain = { 0, 0, 0, 0 } },
	{ .gain = { 0, 0, 0, 0 } },
};

/* clang-format on */

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
		.sat_table[0] =    133,
		.sat_table[1] =    128,
		.sat_table[2] =    120,
		.sat_table[3] =    120,
		.sat_table[4] =    110,
		.sat_table[5] =    110,
		.sat_table[6] =    110,
		.sat_table[7] =    100,
		.sat_table[8] =     80,
		.sat_table[9] =     50,
		.sat_table[10] =    50,
	},

	.shp = {
		.shp_table[0] =   230,
		.shp_table[1] =   191,
		.shp_table[2] =   160,
		.shp_table[3] =   120,
		.shp_table[4] =   100,
		.shp_table[5] =    90,
		.shp_table[6] =    80,
		.shp_table[7] =    70,
		.shp_table[8] =    60,
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
		.noise_cstr[0] =     64,
		.noise_cstr[1] =    128,
		.noise_cstr[2] =    256,
		.noise_cstr[3] =    512,
		.noise_cstr[4] =    640,
		.noise_cstr[5] =    768,
		.noise_cstr[6] =    896,
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
