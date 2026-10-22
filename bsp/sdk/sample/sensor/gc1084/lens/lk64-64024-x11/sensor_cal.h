#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 3721,
	},
	.dcc = {
		.gain = {1086, 1772, 2014, 1086},
		.offset_2s = {0, 0, 0, 0},
	},
	.lsc = {
		.origin = 4,
		.x_trend_2s =  3872,
		.y_trend_2s =  2401,
		.x_curvature = 7290,
		.y_curvature = 7767,
		.tilt_2s = 0,
	},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { .black_level = {
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                                     3721,
	                                             } };

/* the following lines contain some mathematical information like matrices
 * clang-format will force a matrix to a single line, which isn't good for its meaning
 * so i'll turn off formatting for this part
 */
/* clang-format off */
static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
		.gain = { 256,181,469,256 },
		.k = 2700,
		.matrix = {
			 2629,  -465, -116,
			-1750,  4081, -282,
			115,   -3174, 5108 }
	},
	{
		.gain = { 256,225,347,256 },
		.k = 4000,
		.matrix = {
			 2432,   -533, 149,
			 -1414,  3706, -244,
			 92,    -2164, 4120 }
	},
	{
		.gain = { 256,262,252,256 },
		.k = 5000,
		.matrix = {
			 2711, -841,  178,
			 -1285, 4113, -780,
			 292,  -2371, 4127}
	},
	{
		.gain = { 256,293,220,256 },
		.k = 6500,
		.matrix = {
			 2542,-748,254,
			 -1213,3984,-723,
			 133,-2013,3928 }
	},
	{
		.gain = { 256,341,213,256 },
		.k = 7500,
		.matrix = {
			 3072,-1036,12,
			 -946,3882,-887,
			 220,-2119,3947 }
	},
	{
		.gain = { 256,256,256,256 },
		.k = 0,
		.matrix = {
			 2048,     0,     0,
			    0,  2048,     0,
			    0,     0,  2048 }
	},
	{
		.gain = { 256,256,256,256 },
		.k = 0,
		.matrix = {
			 2048,     0,     0,
			    0,  2048,     0,
			    0,     0,  2048 }
	},
	{
		.gain = { 256,256,256,256 },
		.k = 0,
		.matrix = {
			 2048,     0,     0,
			    0,  2048,     0,
			    0,     0,  2048 }
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
		.effective_iso[0] =   100,
		.effective_iso[1] =   200,
		.effective_iso[2] =   400,
		.effective_iso[3] =   800,
		.effective_iso[4] =   1600,
		.effective_iso[5] =   3200,
		.effective_iso[6] =   6400,
		.effective_iso[7] =   12800,
		.effective_iso[8] =   25600,
		.effective_iso[9] =   51200,
		.effective_iso[10] =  102400,
	},

	.csm = {
		.sat_table[0] =   136,
		.sat_table[1] =   128,
		.sat_table[2] =   128,
		.sat_table[3] =   118,
		.sat_table[4] =   100,
		.sat_table[5] =   90,
		.sat_table[6] =   90,
		.sat_table[7] =   90,
		.sat_table[8] =   90,
		.sat_table[9] =   90,
		.sat_table[10] =  90,
	},

	.shp = {
		.shp_table[0] =   255,
		.shp_table[1] =   255,
		.shp_table[2] =   250,
		.shp_table[3] =   240,
		.shp_table[4] =   230,
		.shp_table[5] =   200,
		.shp_table[6] =   200,
		.shp_table[7] =   150,
		.shp_table[8] =   100,
		.shp_table[9] =    50,
		.shp_table[10] =   50,
	},

	.nr = {
		.y_level_3d[0] =  168,
		.y_level_3d[1] =  175,
		.y_level_3d[2] =  185,
		.y_level_3d[3] =  205,
		.y_level_3d[4] =  210,
		.y_level_3d[5] =  230,
		.y_level_3d[6] =  240,
		.y_level_3d[7] =  240,
		.y_level_3d[8] =  255,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =    150,
		.c_level_3d[1] =    150,
		.c_level_3d[2] =    160,
		.c_level_3d[3] =    160,
		.c_level_3d[4] =    160,
		.c_level_3d[5] =    160,
		.c_level_3d[6] =    160,
		.c_level_3d[7] =    160,
		.c_level_3d[8] =    160,
		.c_level_3d[9] =    160,
		.c_level_3d[10] =   160,

		.y_level_2d[0] =    255,
		.y_level_2d[1] =    255,
		.y_level_2d[2] =    255,
		.y_level_2d[3] =    255,
		.y_level_2d[4] =    255,
		.y_level_2d[5] =    255,
		.y_level_2d[6] =    255,
		.y_level_2d[7] =    255,
		.y_level_2d[8] =    255,
		.y_level_2d[9] =    255,
		.y_level_2d[10] =   255,

		.c_level_2d[0] =    255,
		.c_level_2d[1] =    255,
		.c_level_2d[2] =    255,
		.c_level_2d[3] =    255,
		.c_level_2d[4] =    255,
		.c_level_2d[5] =    255,
		.c_level_2d[6] =    255,
		.c_level_2d[7] =    255,
		.c_level_2d[8] =    255,
		.c_level_2d[9] =    255,
		.c_level_2d[10] =   255,
	},

	.gamma = {
		.mode =     0,
	},

	.te = {
		.noise_cstr[0] =   864,
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
