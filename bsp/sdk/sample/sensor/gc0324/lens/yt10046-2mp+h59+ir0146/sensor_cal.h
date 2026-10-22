#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4013,
	},
	.dcc = {
		.gain = {1091, 1796, 2105, 1091},
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
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                                     4071,
	                                             } };

/* the following lines contain some mathematical information like matrices
 * clang-format will force a matrix to a single line, which isn't good for its meaning
 * so i'll turn off formatting for this part
 */
/* clang-format off */
static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
		.gain = { 256,163,434,256 },
		.k = 2700,
		.matrix = {
			 2392,   -44, -300,
			-2162,  4303,  -93,
			-1340, -3215, 6604 }
	},
	{
		.gain = { 256,223,339,256 },
		.k = 4000,
		.matrix = {
			 2757, -453,  -256,
			-1468, 3697,  -180,
			-506, -1535,  4089 }
	},
	{
		.gain = { 256,251,265,256 },
		.k = 5000,
		.matrix = {
			 3072, -1080,   56,
			-1110,  3704, -546,
			  -22, -2341, 4411 }
	},
	{
		.gain = { 256,294,217,256 },
		.k = 6500,
		.matrix = {
			 2786, -1121,  383,
			-1028,  3584, -508,
			  -22, -2155, 4225 }
	},
	{
		.gain = { 256,332,212,256 },
		.k = 7500,
		.matrix = {
			 2554,  -831,  325,
			-1066,  3531, -417,
			 -296, -1640, 3984 }
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
		.effective_iso[0] =     100,
		.effective_iso[1] =     150,
		.effective_iso[2] =     250,
		.effective_iso[3] =     400,
		.effective_iso[4] =     800,
		.effective_iso[5] =    1600,
		.effective_iso[6] =    4800,
		.effective_iso[7] =   25600,
		.effective_iso[8] =   25600,
		.effective_iso[9] =   25600,
		.effective_iso[10] =  25600,
	},

	.csm = {
		.sat_table[0] =    133,
		.sat_table[1] =    120,
		.sat_table[2] =    100,
		.sat_table[3] =     90,
		.sat_table[4] =     80,
		.sat_table[5] =     70,
		.sat_table[6] =     60,
		.sat_table[7] =     40,
		.sat_table[8] =     20,
		.sat_table[9] =     20,
		.sat_table[10] =    20,
	},

	.shp = {
		.shp_table[0] =   240,
		.shp_table[1] =   200,
		.shp_table[2] =   160,
		.shp_table[3] =   120,
		.shp_table[4] =    64,
		.shp_table[5] =    20,
		.shp_table[6] =     0,
		.shp_table[7] =     0,
		.shp_table[8] =     0,
		.shp_table[9] =     0,
		.shp_table[10] =    0,
	},

	.nr = {
		.y_level_3d[0] =  100,
		.y_level_3d[1] =  125,
		.y_level_3d[2] =  150,
		.y_level_3d[3] =  159,
		.y_level_3d[4] =  178,
		.y_level_3d[5] =  190,
		.y_level_3d[6] =  213,
		.y_level_3d[7] =  230,
		.y_level_3d[8] =  230,
		.y_level_3d[9] =  230,
		.y_level_3d[10] = 230,

		.c_level_3d[0] =     32,
		.c_level_3d[1] =     50,
		.c_level_3d[2] =     77,
		.c_level_3d[3] =     87,
		.c_level_3d[4] =    105,
		.c_level_3d[5] =    105,
		.c_level_3d[6] =    105,
		.c_level_3d[7] =    105,
		.c_level_3d[8] =    105,
		.c_level_3d[9] =    105,
		.c_level_3d[10] =   105,

		.y_level_2d[0] =     32,
		.y_level_2d[1] =     64,
		.y_level_2d[2] =     96,
		.y_level_2d[3] =    128,
		.y_level_2d[4] =    128,
		.y_level_2d[5] =    128,
		.y_level_2d[6] =    128,
		.y_level_2d[7] =    128,
		.y_level_2d[8] =    128,
		.y_level_2d[9] =    128,
		.y_level_2d[10] =   128,

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
		.noise_cstr[0] =     32,
		.noise_cstr[1] =    544,
		.noise_cstr[2] =    800,
		.noise_cstr[3] =    928,
		.noise_cstr[4] =    992,
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
