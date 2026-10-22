#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

/*
static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
    32,     64,    128,    256,     512,
  1024,   2048,   4096,   8192,   16384,
 32768,
};
*/

#define SENSOR_BLC_NUM (5)
//0x4B BLC_B
static int k_sensor_blc_bin[SENSOR_BLC_NUM] = {
	36, //30 degree
	43, //50 degree
	61, //60 degree
	117, //70 degree
	183, //80 degree
};

// BLC target
static int k_sensor_blc_val[SENSOR_BLC_NUM] = {
	16, 17, 20, 25, 36,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 1011,
	},
	.dcc = {
		.gain = {1041, 1722, 1661, 1029},
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
	                                                     1011,
	                                                     1012,
	                                                     997,
	                                                     1024,
	                                                     1050,
	                                                     1050,
	                                                     1050,
	                                                     1050,
	                                                     1050,
	                                                     1050,
	                                                     1050,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 182, 364, 256 },
	  .k = 2700,
	  .matrix = { 4493, -2418, -27, -2015, 4376, -313, -962, -5653, 8663 } },
	{ .gain = { 256, 221, 315, 256 },
	  .k = 4000,
	  .matrix = { 3904, -2234, 378, -1966, 4277, -263, -633, -3861, 6541 } },
	{ .gain = { 256, 256, 257, 256 },
	  .k = 5000,
	  .matrix = { 4228, -2691, -512, -1870, 5261, -1343, -581, -3069, 5698 } },
	{ .gain = { 256, 287, 230, 256 },
	  .k = 6500,
	  .matrix = { 4115, -2681, 615, -1766, 5211, -1396, -537, -2543, 5127 } },
	{ .gain = { 256, 339,230, 256 },
	  .k = 7500,
	  .matrix = { 4713, -3280, 615, -1424, 4915, -1443, -65, -3251, 5364 } },
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
		.sat_table[0] =    134,
		.sat_table[1] =    130,
		.sat_table[2] =    125,
		.sat_table[3] =    120,
		.sat_table[4] =    115,
		.sat_table[5] =    105,
		.sat_table[6] =     90,
		.sat_table[7] =     75,
		.sat_table[8] =     64,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   250,
		.shp_table[2] =   220,
		.shp_table[3] =   200,
		.shp_table[4] =   180,
		.shp_table[5] =   170,
		.shp_table[6] =   170,
		.shp_table[7] =   170,
		.shp_table[8] =   170,
		.shp_table[9] =   170,
		.shp_table[10] =  170,
	},

	.nr = {
		.y_level_3d[0] =  100,
		.y_level_3d[1] =  108,
		.y_level_3d[2] =  114,
		.y_level_3d[3] =  126,
		.y_level_3d[4] =  135,
		.y_level_3d[5] =  170,
		.y_level_3d[6] =  200,
		.y_level_3d[7] =  220,
		.y_level_3d[8] =  255,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =  64,
		.c_level_3d[1] =  88,
		.c_level_3d[2] =  128,
		.c_level_3d[3] =  156,
		.c_level_3d[4] =  196,
		.c_level_3d[5] =  225,
		.c_level_3d[6] =  255,
		.c_level_3d[7] =  255,
		.c_level_3d[8] =  255,
		.c_level_3d[9] =  255,
		.c_level_3d[10] = 255,

		.y_level_2d[0] =  0,
		.y_level_2d[1] =  0,
		.y_level_2d[2] =  0,
		.y_level_2d[3] =  0,
		.y_level_2d[4] =  0,
		.y_level_2d[5] =  0,
		.y_level_2d[6] =  0,
		.y_level_2d[7] =  0,
		.y_level_2d[8] =  0,
		.y_level_2d[9] =  0,
		.y_level_2d[10] = 0,

		.c_level_2d[0] =  0,
		.c_level_2d[1] =  0,
		.c_level_2d[2] =  0,
		.c_level_2d[3] =  0,
		.c_level_2d[4] =  0,
		.c_level_2d[5] =  0,
		.c_level_2d[6] =  0,
		.c_level_2d[7] =  0,
		.c_level_2d[8] =  0,
		.c_level_2d[9] =  0,
		.c_level_2d[10] = 0,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =      0,
		.noise_cstr[1] =      0,
		.noise_cstr[2] =    256,
		.noise_cstr[3] =    512,
		.noise_cstr[4] =    700,
		.noise_cstr[5] =    768,
		.noise_cstr[6] =    900,
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
