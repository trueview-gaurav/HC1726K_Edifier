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
		.gain = {1094, 1631, 1931, 1090},
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

// clang-format off
static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
		.gain = { 256, 193, 365, 255 },
		.k = 2700,
		.matrix = {
			 2598, -563,   13,
			-2198,  4178,   67,
			-2619, -6154,  10821
		}
	},
	{
		.gain = { 256, 227, 313, 255 },
		.k = 4000,
		.matrix = {
			 2483, -1031,   596,
			-2152,  4162,   38,
			 -1238 -4116,  7402
		}
	},
	{
		.gain = { 256, 257, 255, 255 },
		.k = 5000,
		.matrix = {
			 2759, -1294,   583,
			 -1809,  4426,  -568,
			  -499, -3631,  6178
		}
	},
	{
		.gain = { 256, 283, 229, 255 },
		.k = 6500,
		.matrix = {
			 2337, -1198,   908,
			 -1886,  4223,  -289,
			  -723, -3214,  5986
		}
	},
	{
		.gain = { 255, 296, 227, 256 },
		.k = 8000,
		.matrix = {
			 3426, -1581,   203,
			-1239,  3508,  -221,
			 -449, -2675,  5172
		}
	},
	{
		.gain = { 256, 256, 256, 256 },
		.k = 0,
		.matrix = {
			 2048,     0,     0,
			    0,  2048,     0,
			    0,     0,  2048
		}
	},
	{
		.gain = { 256, 256, 256, 256 },
		.k = 0,
		.matrix = {
			 2048,     0,     0,
			    0,  2048,     0,
			    0,     0,  2048
		}
	},
	{
		.gain = { 256, 256, 256, 256 },
		.k = 0,
		.matrix = {
			 2048,     0,     0,
			    0,  2048,     0,
			    0,     0,  2048
		}
	},
};
// clang-format on

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
		.sat_table[0] =    128,
		.sat_table[1] =    120,
		.sat_table[2] =    100,
		.sat_table[3] =     90,
		.sat_table[4] =     70,
		.sat_table[5] =     40,
		.sat_table[6] =     10,
		.sat_table[7] =     10,
		.sat_table[8] =     10,
		.sat_table[9] =     10,
		.sat_table[10] =    10,
	},

	.shp = {
		.shp_table[0] =   200,
		.shp_table[1] =   170,
		.shp_table[2] =   100,
		.shp_table[3] =    60,
		.shp_table[4] =    10,
		.shp_table[5] =     0,
		.shp_table[6] =     0,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  110,
		.y_level_3d[1] =  125,
		.y_level_3d[2] =  140,
		.y_level_3d[3] =  169,
		.y_level_3d[4] =  190,
		.y_level_3d[5] =  210,
		.y_level_3d[6] =  230,
		.y_level_3d[7] =  250,
		.y_level_3d[8] =  250,
		.y_level_3d[9] =  250,
		.y_level_3d[10] = 250,

		.c_level_3d[0] =     32,
		.c_level_3d[1] =     50,
		.c_level_3d[2] =     77,
		.c_level_3d[3] =     87,
		.c_level_3d[4] =     95,
		.c_level_3d[5] =    100,
		.c_level_3d[6] =    100,
		.c_level_3d[7] =    100,
		.c_level_3d[8] =    100,
		.c_level_3d[9] =    100,
		.c_level_3d[10] =   100,

		.y_level_2d[0] =    168,
		.y_level_2d[1] =    168,
		.y_level_2d[2] =    168,
		.y_level_2d[3] =    168,
		.y_level_2d[4] =    168,
		.y_level_2d[5] =    168,
		.y_level_2d[6] =    168,
		.y_level_2d[7] =    168,
		.y_level_2d[8] =    168,
		.y_level_2d[9] =    168,
		.y_level_2d[10] =   168,

		.c_level_2d[0] =     32,
		.c_level_2d[1] =     64,
		.c_level_2d[2] =     96,
		.c_level_2d[3] =    128,
		.c_level_2d[4] =    128,
		.c_level_2d[5] =    128,
		.c_level_2d[6] =    128,
		.c_level_2d[7] =    128,
		.c_level_2d[8] =    128,
		.c_level_2d[9] =    128,
		.c_level_2d[10] =   128,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =    960,
		.noise_cstr[1] =    960,
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
