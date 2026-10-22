#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 1016,
	},
	.dcc = {
		.gain = {1100, 2400, 1700, 1100},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s = 3368,
		.y_trend_2s = 1928,
		.x_curvature = 13569,
		.y_curvature = 54810,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                                     1016,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 144, 446, 255 },
	  .k = 2800,
	  .matrix = { 3529, -801, -679, -1337, 4019, -634, 132, -3587, 5502 } },
	{ .gain = { 255, 211, 355, 256 },
	  .k = 4000,
	  .matrix = { 4162, -1984, -130, -875, 3175, -252, 330, -2404, 4122 } },
	{ .gain = { 256, 227, 310, 255 },
	  .k = 4800,
	  .matrix = { 3825, -1409, -368, -1059, 3831, -724, 53, -2353, 4347 } },
	{ .gain = { 256, 252, 252, 255 }, .k = 6500, .matrix = { 3504, -1535, 79, -489, 3198, -660, 347, -2207, 3907 } },
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
		.sat_table[0] =    160,
		.sat_table[1] =    150,
		.sat_table[2] =    140,
		.sat_table[3] =    128,
		.sat_table[4] =     85,
		.sat_table[5] =     85,
		.sat_table[6] =     85,
		.sat_table[7] =     85,
		.sat_table[8] =     85,
		.sat_table[9] =     85,
		.sat_table[10] =    85,
	},

	.shp = {
		.shp_table[0] =   191,
		.shp_table[1] =    75,
		.shp_table[2] =    45,
		.shp_table[3] =     0,
		.shp_table[4] =     0,
		.shp_table[5] =     0,
		.shp_table[6] =     0,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  113,
		.y_level_3d[1] =  137,
		.y_level_3d[2] =  143,
		.y_level_3d[3] =  150,
		.y_level_3d[4] =  156,
		.y_level_3d[5] =  162,
		.y_level_3d[6] =  168,
		.y_level_3d[7] =  175,
		.y_level_3d[8] =  181,
		.y_level_3d[9] =  187,
		.y_level_3d[10] = 193,

		.c_level_3d[0] =     49,
		.c_level_3d[1] =     75,
		.c_level_3d[2] =     81,
		.c_level_3d[3] =     87,
		.c_level_3d[4] =     93,
		.c_level_3d[5] =    100,
		.c_level_3d[6] =    106,
		.c_level_3d[7] =    113,
		.c_level_3d[8] =    119,
		.c_level_3d[9] =    125,
		.c_level_3d[10] =   131,

		.y_level_2d[0] =    100,
		.y_level_2d[1] =    100,
		.y_level_2d[2] =    100,
		.y_level_2d[3] =    100,
		.y_level_2d[4] =    100,
		.y_level_2d[5] =    100,
		.y_level_2d[6] =    100,
		.y_level_2d[7] =    100,
		.y_level_2d[8] =    100,
		.y_level_2d[9] =    100,
		.y_level_2d[10] =   100,

		.c_level_2d[0] =    150,
		.c_level_2d[1] =    150,
		.c_level_2d[2] =    150,
		.c_level_2d[3] =    150,
		.c_level_2d[4] =    150,
		.c_level_2d[5] =    150,
		.c_level_2d[6] =    150,
		.c_level_2d[7] =    150,
		.c_level_2d[8] =    150,
		.c_level_2d[9] =    150,
		.c_level_2d[10] =   150,
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
		.curve[1] =     25,
		.curve[2] =     57,
		.curve[3] =     91,
		.curve[4] =    133,
		.curve[5] =    175,
		.curve[6] =    215,
		.curve[7] =    261,
		.curve[8] =    308,
		.curve[9] =    402,
		.curve[10] =   496,
		.curve[11] =   596,
		.curve[12] =   700,
		.curve[13] =   809,
		.curve[14] =   920,
		.curve[15] =  1035,
		.curve[16] =  1153,
		.curve[17] =  1273,
		.curve[18] =  1395,
		.curve[19] =  1519,
		.curve[20] =  1645,
		.curve[21] =  1773,
		.curve[22] =  1903,
		.curve[23] =  2033,
		.curve[24] =  2165,
		.curve[25] =  2431,
		.curve[26] =  2701,
		.curve[27] =  2975,
		.curve[28] =  3253,
		.curve[29] =  3533,
		.curve[30] =  3815,
		.curve[31] =  4099,
		.curve[32] =  4387,
		.curve[33] =  4677,
		.curve[34] =  4968,
		.curve[35] =  5261,
		.curve[36] =  5557,
		.curve[37] =  5855,
		.curve[38] =  6154,
		.curve[39] =  6455,
		.curve[40] =  6757,
		.curve[41] =  7365,
		.curve[42] =  7978,
		.curve[43] =  8593,
		.curve[44] =  9209,
		.curve[45] =  9822,
		.curve[46] = 10431,
		.curve[47] = 11034,
		.curve[48] = 11626,
		.curve[49] = 12204,
		.curve[50] = 12765,
		.curve[51] = 13305,
		.curve[52] = 13820,
		.curve[53] = 14306,
		.curve[54] = 14759,
		.curve[55] = 15175,
		.curve[56] = 15549,
		.curve[57] = 15877,
		.curve[58] = 16157,
		.curve[59] = 16384,
	},
};

#endif
