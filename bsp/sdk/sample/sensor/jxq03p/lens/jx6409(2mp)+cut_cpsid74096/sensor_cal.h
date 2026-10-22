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
	48, //30 degree
	49, //50 degree
	56, //60 degree
	81, //70 degree
	155, //80 degree
};

// BLC target
static int k_sensor_blc_val[SENSOR_BLC_NUM] = {
	16, 16, 17, 20, 25,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 1019,
	},
	.dcc = {
		.gain = {1041, 1486, 1516, 1032},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 0,
		.x_trend_2s = 0,
		.y_trend_2s = 0,
		.x_curvature = 0,
		.y_curvature = 0,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     1019,
	                                                     967,
	                                                     948,
	                                                     960,
	                                                     941,
	                                                     941,
	                                                     941,
	                                                     941,
	                                                     941,
	                                                     941,
	                                                     941,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 220, 332, 256 },
	  .k = 2700,
	  .matrix = { 11349, -5254, -4047, -2012, 5568, -1508, 583, -11698, 13163 } },
	{ .gain = { 256, 241, 302, 256 },
	  .k = 4000,
	  .matrix = { 9326, -4970, -2307, -3050, 6490, -1392, 175, -8569, 10443 } },
	{ .gain = { 256, 256, 260, 256 },
	  .k = 5000,
	  .matrix = { 10625, -7767, -810, -2244, 4887, -596, 1236, -7662, 8474 } },
	{ .gain = { 256, 267, 238, 256 },
	  .k = 6500,
	  .matrix = { 11152, -8450, -655, -1699, 4890, -1143, 872, -7054, 8230 } },
	{ .gain = { 256, 287, 230, 256 },
	  .k = 7500,
	  .matrix = { 13373, -9944, -1381, -1599, 4895, -1248, 2104, -8397, 8341 } },
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
		.effective_iso[0] =     139,
		.effective_iso[1] =     189,
		.effective_iso[2] =     261,
		.effective_iso[3] =     364,
		.effective_iso[4] =     514,
		.effective_iso[5] =     714,
		.effective_iso[6] =    1002,
		.effective_iso[7] =    1404,
		.effective_iso[8] =    2012,
		.effective_iso[9] =    2750,
		.effective_iso[10] =   3000,
	},

	.csm = {
		.sat_table[0] =    133,
		.sat_table[1] =    131,
		.sat_table[2] =    126,
		.sat_table[3] =    120,
		.sat_table[4] =    115,
		.sat_table[5] =    110,
		.sat_table[6] =    100,
		.sat_table[7] =    90,
		.sat_table[8] =    70,
		.sat_table[9] =    64,
		.sat_table[10] =   64,
	},

	.shp = {
		.shp_table[0] =    255,
		.shp_table[1] =    255,
		.shp_table[2] =    255,
		.shp_table[3] =    255,
		.shp_table[4] =    255,
		.shp_table[5] =    255,
		.shp_table[6] =    255,
		.shp_table[7] =    255,
		.shp_table[8] =    255,
		.shp_table[9] =    255,
		.shp_table[10] =   255,
	},

	.nr = {
		.y_level_3d[0] =    100,
		.y_level_3d[1] =    110,
		.y_level_3d[2] =    130,
		.y_level_3d[3] =    155,
		.y_level_3d[4] =    170,
		.y_level_3d[5] =    185,
		.y_level_3d[6] =    185,
		.y_level_3d[7] =    185,
		.y_level_3d[8] =    185,
		.y_level_3d[9] =    185,
		.y_level_3d[10] =   185,

		.c_level_3d[0] =     24,
		.c_level_3d[1] =     42,
		.c_level_3d[2] =     72,
		.c_level_3d[3] =    128,
		.c_level_3d[4] =    128,
		.c_level_3d[5] =    128,
		.c_level_3d[6] =    128,
		.c_level_3d[7] =    128,
		.c_level_3d[8] =    128,
		.c_level_3d[9] =    128,
		.c_level_3d[10] =   128,

		.y_level_2d[0] =     0,
		.y_level_2d[1] =     0,
		.y_level_2d[2] =     0,
		.y_level_2d[3] =     0,
		.y_level_2d[4] =     0,
		.y_level_2d[5] =     0,
		.y_level_2d[6] =     0,
		.y_level_2d[7] =     0,
		.y_level_2d[8] =     0,
		.y_level_2d[9] =     0,
		.y_level_2d[10] =    0,

		.c_level_2d[0] =     0,
		.c_level_2d[1] =     0,
		.c_level_2d[2] =     0,
		.c_level_2d[3] =     0,
		.c_level_2d[4] =     0,
		.c_level_2d[5] =     0,
		.c_level_2d[6] =     0,
		.c_level_2d[7] =     0,
		.c_level_2d[8] =     0,
		.c_level_2d[9] =     0,
		.c_level_2d[10] =    0,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =   2,
		.noise_cstr[1] =   2,
		.noise_cstr[2] =   1,
		.noise_cstr[3] =   1,
		.noise_cstr[4] =   1,
		.noise_cstr[5] =   1,
		.noise_cstr[6] =   1,
		.noise_cstr[7] =   1,
		.noise_cstr[8] =   1,
		.noise_cstr[9] =   1,
		.noise_cstr[10] =  1,

		.curve[0] =      0,
		.curve[1] =    576,
		.curve[2] =   1152,
		.curve[3] =   1704,
		.curve[4] =   2163,
		.curve[5] =   2563,
		.curve[6] =   2921,
		.curve[7] =   3247,
		.curve[8] =   3549,
		.curve[9] =   4095,
		.curve[10] =  4584,
		.curve[11] =  5030,
		.curve[12] =  5442,
		.curve[13] =  5826,
		.curve[14] =  6188,
		.curve[15] =  6530,
		.curve[16] =  6855,
		.curve[17] =  7166,
		.curve[18] =  7464,
		.curve[19] =  7751,
		.curve[20] =  8027,
		.curve[21] =  8294,
		.curve[22] =  8552,
		.curve[23] =  8803,
		.curve[24] =  9046,
		.curve[25] =  9514,
		.curve[26] =  9959,
		.curve[27] = 10383,
		.curve[28] = 10790,
		.curve[29] = 11182,
		.curve[30] = 11559,
		.curve[31] = 11924,
		.curve[32] = 12277,
		.curve[33] = 12619,
		.curve[34] = 12951,
		.curve[35] = 13275,
		.curve[36] = 13590,
		.curve[37] = 13897,
		.curve[38] = 14198,
		.curve[39] = 14491,
		.curve[40] = 14778,
		.curve[41] = 15334,
		.curve[42] = 15869,
		.curve[43] = 16383,
		.curve[44] = 16383,
		.curve[45] = 16383,
		.curve[46] = 16383,
		.curve[47] = 16383,
		.curve[48] = 16383,
		.curve[49] = 16383,
		.curve[50] = 16383,
		.curve[51] = 16383,
		.curve[52] = 16383,
		.curve[53] = 16383,
		.curve[54] = 16383,
		.curve[55] = 16383,
		.curve[56] = 16383,
		.curve[57] = 16383,
		.curve[58] = 16383,
		.curve[59] = 16384,
	},
};

#endif
