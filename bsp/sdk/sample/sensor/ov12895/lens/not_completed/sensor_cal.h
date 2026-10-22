#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4064,
	},
	.dcc = {
		.gain = {1096, 1869, 1764, 1086},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 65536,
		.x_trend_2s = 0,
		.y_trend_2s = 0,
		.x_curvature = 0,
		.y_curvature = 0,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                                     4064,
	                                             } };

/* clang-format off */

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
		.gain = { 256,166,430,255 },
		.k = 2700,
		.matrix = {
			2501,-238,-215,
			-793,3381,-540,
			-558,-2478,5084 }
	},
	{
		.gain = { 255,214,333,256 },
		.k = 4000,
		.matrix = {
			2025,-220,242,
			-692,2838,-98,
			-160,-2099,4308 }
	},
	{
		.gain = { 255,262,254,256 },
		.k = 5000,
		.matrix = {
			2478,-622,192,
			-418,3061,-595,
			-28,-1938,4014 }
	},
	{
		.gain = { 255,306,223,256 },
		.k = 6500,
		.matrix = {
			2058,-468,458,
			-532,3038,-457,
			-20,-1776,3844 }
	},
	{
		.gain = { 255,327,218,256 },
		.k = 8000,
		.matrix = {
			2973, -1081,  156,
			 -227, 2968,  -692,
			 -18, -1493, 3560 }
	},
	{
		.gain = { 256,256,256,256 },
		.k = 0,
		.matrix = {
			2048,    0,    0,
			   0, 2048,    0,
			   0,    0, 2048 }
	},
	{
		.gain = { 256,256,256,256 },
		.k = 0,
		.matrix = {
			2048,    0,    0,
			   0, 2048,    0,
			   0,    0, 2048 }
	},
	{
		.gain = { 256,256,256,256 },
		.k = 0,
		.matrix = {
			2048,    0,    0,
			   0, 2048,    0,
			   0,    0, 2048 }
	},
};

/* clang-format on */

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
		.sat_table[2] =    120,
		.sat_table[3] =    110,
		.sat_table[4] =    100,
		.sat_table[5] =    100,
		.sat_table[6] =     90,
		.sat_table[7] =     90,
		.sat_table[8] =     90,
		.sat_table[9] =     90,
		.sat_table[10] =    90,
	},

	.shp = {
		.shp_table[0] =   250,
		.shp_table[1] =   220,
		.shp_table[2] =   200,
		.shp_table[3] =   100,
		.shp_table[4] =    62,
		.shp_table[5] =    20,
		.shp_table[6] =     0,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  100,
		.y_level_3d[1] =  115,
		.y_level_3d[2] =  130,
		.y_level_3d[3] =  159,
		.y_level_3d[4] =  168,
		.y_level_3d[5] =  180,
		.y_level_3d[6] =  180,
		.y_level_3d[7] =  190,
		.y_level_3d[8] =  190,
		.y_level_3d[9] =  190,
		.y_level_3d[10] = 200,

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
		.curve[1] =      6,
		.curve[2] =     21,
		.curve[3] =     40,
		.curve[4] =     71,
		.curve[5] =    102,
		.curve[6] =    130,
		.curve[7] =    168,
		.curve[8] =    206,
		.curve[9] =    283,
		.curve[10] =   360,
		.curve[11] =   446,
		.curve[12] =   538,
		.curve[13] =   637,
		.curve[14] =   740,
		.curve[15] =   849,
		.curve[16] =   961,
		.curve[17] =  1077,
		.curve[18] =  1197,
		.curve[19] =  1319,
		.curve[20] =  1444,
		.curve[21] =  1572,
		.curve[22] =  1702,
		.curve[23] =  1833,
		.curve[24] =  1967,
		.curve[25] =  2239,
		.curve[26] =  2516,
		.curve[27] =  2799,
		.curve[28] =  3087,
		.curve[29] =  3379,
		.curve[30] =  3674,
		.curve[31] =  3973,
		.curve[32] =  4277,
		.curve[33] =  4583,
		.curve[34] =  4892,
		.curve[35] =  5204,
		.curve[36] =  5520,
		.curve[37] =  5838,
		.curve[38] =  6159,
		.curve[39] =  6482,
		.curve[40] =  6807,
		.curve[41] =  7464,
		.curve[42] =  8127,
		.curve[43] =  8794,
		.curve[44] =  9461,
		.curve[45] = 10125,
		.curve[46] = 10783,
		.curve[47] = 11431,
		.curve[48] = 12063,
		.curve[49] = 12674,
		.curve[50] = 13260,
		.curve[51] = 13814,
		.curve[52] = 14330,
		.curve[53] = 14803,
		.curve[54] = 15227,
		.curve[55] = 15594,
		.curve[56] = 15899,
		.curve[57] = 16135,
		.curve[58] = 16299,
		.curve[59] = 16384,
	},
};

#endif
