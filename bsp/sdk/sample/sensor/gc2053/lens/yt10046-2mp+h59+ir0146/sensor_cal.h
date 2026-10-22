#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

static int k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM] = {
	32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
};

static MPI_CAL_SNS_DEFAULT_S cal_tbl_dft = {
	.dbc = {
		.dbc_level = 4108,
	},
	.dcc = {
		.gain = {1092, 1804, 2085, 1092},
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
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                                     4108,
	                                             } };

/* the following lines contain some mathematical information like matrices
 * clang-format will force a matrix to a single line, which isn't good for its meaning
 * so i'll turn off formatting for this part
 */
/* clang-format off */
static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{
		.gain = { 256,178,427,256 },
		.k = 2700,
		.matrix = {
			4740, -2011,  -670,
			-646,  3350,  -656,
			 720, -5264,  6592 }
	},
	{
		.gain = { 256,217,334,256 },
		.k = 4000,
		.matrix = {
			 3796, -1293,  -455,
			 -785,  3359,  -526,
			  366, -2959,  4640 }
	},
	{
		.gain = { 256,257,267,256 },
		.k = 5000,
		.matrix = {
			 4150, -1573,  -529,
			 -506,  3884, -1330,
			  773, -3173,  4448 }
	},
	{
		.gain = { 256,281,228,256 },
		.k = 6500,
		.matrix = {
			 5341, -2328,  -965,
			 -145,  4120, -1927,
			 1206, -3545,  4387 }
	},
	{
		.gain = { 256,334,218,256 },
		.k = 7500,
		.matrix = {
			 4904, -2211,  -645,
			   34,  3560, -1547,
			 1003, -3147,  4192 }
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
		.effective_iso[0] =     180,
		.effective_iso[1] =     236,
		.effective_iso[2] =     318,
		.effective_iso[3] =     426,
		.effective_iso[4] =     596,
		.effective_iso[5] =     818,
		.effective_iso[6] =    1135,
		.effective_iso[7] =     900,
		.effective_iso[8] =    1200,
		.effective_iso[9] =    1500,
		.effective_iso[10] =   1500,
	},

	.csm = {
		.sat_table[0] =    152,
		.sat_table[1] =    144,
		.sat_table[2] =    132,
		.sat_table[3] =    128,
		.sat_table[4] =    110,
		.sat_table[5] =     90,
		.sat_table[6] =     64,
		.sat_table[7] =     64,
		.sat_table[8] =     64,
		.sat_table[9] =     64,
		.sat_table[10] =    64,
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
		.y_level_3d[0] =  130,
		.y_level_3d[1] =  140,
		.y_level_3d[2] =  165,
		.y_level_3d[3] =  176,
		.y_level_3d[4] =  238,
		.y_level_3d[5] =  255,
		.y_level_3d[6] =  255,
		.y_level_3d[7] =  255,
		.y_level_3d[8] =  255,
		.y_level_3d[9] =  255,
		.y_level_3d[10] = 255,

		.c_level_3d[0] =    24,
		.c_level_3d[1] =    42,
		.c_level_3d[2] =    72,
		.c_level_3d[3] =    128,
		.c_level_3d[4] =    156,
		.c_level_3d[5] =    196,
		.c_level_3d[6] =    225,
		.c_level_3d[7] =    255,
		.c_level_3d[8] =    255,
		.c_level_3d[9] =    255,
		.c_level_3d[10] =   255,

		.y_level_2d[0] =      0,
		.y_level_2d[1] =      0,
		.y_level_2d[2] =      0,
		.y_level_2d[3] =      0,
		.y_level_2d[4] =      0,
		.y_level_2d[5] =      0,
		.y_level_2d[6] =      0,
		.y_level_2d[7] =      0,
		.y_level_2d[8] =      0,
		.y_level_2d[9] =      0,
		.y_level_2d[10] =     0,

		.c_level_2d[0] =      0,
		.c_level_2d[1] =      0,
		.c_level_2d[2] =      0,
		.c_level_2d[3] =      0,
		.c_level_2d[4] =      0,
		.c_level_2d[5] =      0,
		.c_level_2d[6] =      0,
		.c_level_2d[7] =      0,
		.c_level_2d[8] =      0,
		.c_level_2d[9] =      0,
		.c_level_2d[10] =     0,
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
		.curve[1] =     64,
		.curve[2] =    128,
		.curve[3] =    192,
		.curve[4] =    256,
		.curve[5] =    320,
		.curve[6] =    384,
		.curve[7] =    448,
		.curve[8] =    512,
		.curve[9] =    640,
		.curve[10] =   768,
		.curve[11] =   896,
		.curve[12] =  1024,
		.curve[13] =  1152,
		.curve[14] =  1280,
		.curve[15] =  1408,
		.curve[16] =  1536,
		.curve[17] =  1664,
		.curve[18] =  1792,
		.curve[19] =  1920,
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
