#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 1060,
	},
	.dcc = {
		.gain = {1041, 1654, 1745, 1041},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3772,
		.y_trend_2s = 2401,
		.x_curvature = 7290,
		.y_curvature = 7767,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                                     1060,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 174, 378, 256 },
	  .k = 2700,
	  .matrix = { 3022, -904, -69, -1868, 4919, -1003, -1131, -4166, 7344 } },
	{ .gain = { 256, 217, 316, 256 },
	  .k = 4000,
	  .matrix = { 3068, -1177, 157, -1297, 3995, -651, -603, -2705, 5357 } },
	{ .gain = { 256, 257, 259, 256 },
	  .k = 5000,
	  .matrix = { 2930, -1158, 276, -1222, 4597, -1328, -361, -2813, 5222 } },
	{ .gain = { 256, 291, 234, 256 },
	  .k = 6500,
	  .matrix = { 2742, -1122, 428, -1201, 4527, -1278, -401, -2321, 4770 } },
	{ .gain = { 256, 332, 230, 256 },
	  .k = 7500,
	  .matrix = { 3318, -1473, 202, -894, 4351, -1409, -173, -2547, 4767 } },
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
		.sat_table[0] =    132,
		.sat_table[1] =    131,
		.sat_table[2] =    128,
		.sat_table[3] =    125,
		.sat_table[4] =    118,
		.sat_table[5] =     95,
		.sat_table[6] =     80,
		.sat_table[7] =     64,
		.sat_table[8] =     64,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   255,
		.shp_table[3] =   254,
		.shp_table[4] =   187,
		.shp_table[5] =    50,
		.shp_table[6] =    50,
		.shp_table[7] =    50,
		.shp_table[8] =    50,
		.shp_table[9] =    50,
		.shp_table[10] =   50,
	},

	.nr = {
		.y_level_3d[0] =  160,
		.y_level_3d[1] =  163,
		.y_level_3d[2] =  171,
		.y_level_3d[3] =  184,
		.y_level_3d[4] =  204,
		.y_level_3d[5] =  230,
		.y_level_3d[6] =  240,
		.y_level_3d[7] =  240,
		.y_level_3d[8] =  241,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =  150,
		.c_level_3d[1] =  150,
		.c_level_3d[2] =  151,
		.c_level_3d[3] =  164,
		.c_level_3d[4] =  187,
		.c_level_3d[5] =  232,
		.c_level_3d[6] =  255,
		.c_level_3d[7] =  255,
		.c_level_3d[8] =  255,
		.c_level_3d[9] =  255,
		.c_level_3d[10] = 255,

		.y_level_2d[0] =  255,
		.y_level_2d[1] =  255,
		.y_level_2d[2] =  255,
		.y_level_2d[3] =  255,
		.y_level_2d[4] =  255,
		.y_level_2d[5] =  255,
		.y_level_2d[6] =  255,
		.y_level_2d[7] =  255,
		.y_level_2d[8] =  255,
		.y_level_2d[9] =  255,
		.y_level_2d[10] = 255,

		.c_level_2d[0] =  255,
		.c_level_2d[1] =  255,
		.c_level_2d[2] =  255,
		.c_level_2d[3] =  255,
		.c_level_2d[4] =  255,
		.c_level_2d[5] =  255,
		.c_level_2d[6] =  255,
		.c_level_2d[7] =  255,
		.c_level_2d[8] =  255,
		.c_level_2d[9] =  255,
		.c_level_2d[10] = 255,
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
		.curve[1] =     42,
		.curve[2] =    104,
		.curve[3] =    174,
		.curve[4] =    246,
		.curve[5] =    320,
		.curve[6] =    396,
		.curve[7] =    474,
		.curve[8] =    553,
		.curve[9] =    714,
		.curve[10] =   877,
		.curve[11] =  1043,
		.curve[12] =  1210,
		.curve[13] =  1379,
		.curve[14] =  1549,
		.curve[15] =  1718,
		.curve[16] =  1887,
		.curve[17] =  2053,
		.curve[18] =  2218,
		.curve[19] =  2381,
		.curve[20] =  2542,
		.curve[21] =  2702,
		.curve[22] =  2859,
		.curve[23] =  3015,
		.curve[24] =  3169,
		.curve[25] =  3471,
		.curve[26] =  3766,
		.curve[27] =  4054,
		.curve[28] =  4336,
		.curve[29] =  4611,
		.curve[30] =  4879,
		.curve[31] =  5142,
		.curve[32] =  5398,
		.curve[33] =  5648,
		.curve[34] =  5894,
		.curve[35] =  6136,
		.curve[36] =  6374,
		.curve[37] =  6607,
		.curve[38] =  6837,
		.curve[39] =  7063,
		.curve[40] =  7285,
		.curve[41] =  7718,
		.curve[42] =  8138,
		.curve[43] =  8549,
		.curve[44] =  8959,
		.curve[45] =  9370,
		.curve[46] =  9782,
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
