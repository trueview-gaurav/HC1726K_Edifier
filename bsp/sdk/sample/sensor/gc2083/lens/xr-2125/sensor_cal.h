#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4060,
	},
	.dcc = {
		.gain = {1092, 1812, 1872, 1092},
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
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                                     4060,
	                                             } };

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 191, 381, 256 },
	  .k = 2700,
	  .matrix = { 4509, -2545, 84, -1480, 3325, 203, -569, -5905, 8521 } },
	{ .gain = { 256, 226, 317, 256 }, 
	  .k = 4000, 
	  .matrix = { 5337, -1622, -1666, -1167, 4724, -1510, 89, -5389, 7348 } },
	{ .gain = { 256, 256, 254, 256 },
	  .k = 5000,
	  .matrix = { 5558, -2552, -957, -805, 4331, -1477, 198, -4699, 6549 } },
	{ .gain = { 256, 280, 225, 256 },
	  .k = 6500,
	  .matrix = { 4494, -989, -1458, -1708, 5081, -1325, -828, -2740, 5615 } },
	{ .gain = { 256, 335, 217, 256 }, 
	  .k = 7500, 
	  .matrix = { 4433, -1530, -856, -1844, 5254, -1362, -889, -2516, 5453 } },
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
		.effective_iso[0] = 134,
		.effective_iso[1] = 185,
		.effective_iso[2] = 266,
		.effective_iso[3] = 352,
		.effective_iso[4] = 512,
		.effective_iso[5] = 748,
		.effective_iso[6] = 1050,
		.effective_iso[7] = 1461,
		.effective_iso[8] = 1846,
		.effective_iso[9] = 2555,
		.effective_iso[10] = 2555,
	},

	.csm = {
		.sat_table[0] =    138,
		.sat_table[1] =    135,
		.sat_table[2] =    128,
		.sat_table[3] =    125,
		.sat_table[4] =    120,
		.sat_table[5] =    115,
		.sat_table[6] =    85,
		.sat_table[7] =    75,
		.sat_table[8] =    70,
		.sat_table[9] =    60,
		.sat_table[10] =   55,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   255,
		.shp_table[3] =   255,
		.shp_table[4] =   255,
		.shp_table[5] =   255,
		.shp_table[6] =   255,
		.shp_table[7] =   255,
		.shp_table[8] =   255,
		.shp_table[9] =   255,
		.shp_table[10] =  255,
	},

	.nr = {
		.y_level_3d[0] = 130,
		.y_level_3d[1] = 140,
		.y_level_3d[2] = 165,
		.y_level_3d[3] = 176,
		.y_level_3d[4] = 238,
		.y_level_3d[5] = 255,
		.y_level_3d[6] = 255,
		.y_level_3d[7] = 255,
		.y_level_3d[8] = 255,
		.y_level_3d[9] = 255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =  24,
		.c_level_3d[1] =  42,
		.c_level_3d[2] =  72,
		.c_level_3d[3] =  128,
		.c_level_3d[4] =  156,
		.c_level_3d[5] =  196,
		.c_level_3d[6] =  225,
		.c_level_3d[7] =  255,
		.c_level_3d[8] =  255,
		.c_level_3d[9] =  255,
		.c_level_3d[10] = 255,

		.y_level_2d[0] =    0,
		.y_level_2d[1] =    0,
		.y_level_2d[2] =    0,
		.y_level_2d[3] =    0,
		.y_level_2d[4] =    0,
		.y_level_2d[5] =    0,
		.y_level_2d[6] =    0,
		.y_level_2d[7] =    0,
		.y_level_2d[8] =    0,
		.y_level_2d[9] =    0,
		.y_level_2d[10] =   0,

		.c_level_2d[0] =    0,
		.c_level_2d[1] =    0,
		.c_level_2d[2] =    0,
		.c_level_2d[3] =    0,
		.c_level_2d[4] =    0,
		.c_level_2d[5] =    0,
		.c_level_2d[6] =    0,
		.c_level_2d[7] =    0,
		.c_level_2d[8] =    0,
		.c_level_2d[9] =    0,
		.c_level_2d[10] =   0,
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

		.curve[0] =  0,
		.curve[1] =  576,
		.curve[2] =  1152,
		.curve[3] =  1704,
		.curve[4] =  2163,
		.curve[5] =  2563,
		.curve[6] =  2921,
		.curve[7] =  3247,
		.curve[8] =  3549,
		.curve[9] =  4095,
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
		.curve[27] =  10383,
		.curve[28] =  10790,
		.curve[29] =  11182,
		.curve[30] =  11559,
		.curve[31] =  11924,
		.curve[32] =  12277,
		.curve[33] =  12619,
		.curve[34] =  12951,
		.curve[35] =  13275,
		.curve[36] =  13590,
		.curve[37] =  13897,
		.curve[38] =  14198,
		.curve[39] =  14491,
		.curve[40] =  14778,
		.curve[41] =  15334,
		.curve[42] =  15869,
		.curve[43] =  16383,
		.curve[44] =  16383,
		.curve[45] =  16383,
		.curve[46] =  16383,
		.curve[47] =  16383,
		.curve[48] =  16383,
		.curve[49] =  16383,
		.curve[50] =  16383,
		.curve[51] =  16383,
		.curve[52] =  16383,
		.curve[53] =  16383,
		.curve[54] =  16383,
		.curve[55] =  16383,
		.curve[56] =  16383,
		.curve[57] =  16383,
		.curve[58] =  16383,
		.curve[59] =  16384,
	},
};

#endif
