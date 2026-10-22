#ifndef SENSOR_CAL_H__
#define SENSOR_CAL_H__

#include "mpi_dip_sns.h"

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
			.dbc_level = 993,
		},
		.dcc = {
			.gain = {1040, 1866, 1795, 1038},
			.offset_2s = {0, 0, 0, 0},
		},
		.lsc = {
			.origin = 4,
			.x_trend_2s = 3872,
			.y_trend_2s = 1910,
			.x_curvature = 2867,
			.y_curvature = 1092,
			.tilt_2s = 0,
		},
};

static MPI_BLACK_LEVEL_TABLE_S black_level_table = { 
		.black_level = {
		    993,
		    993,
		    993,
		    993,
		    993,
		    993,
		    993,
		    993,
		    993,
		    993,
		    993,
		},
};

static MPI_AWB_COLOR_TEMP_S ct_tbl_dft[MPI_K_TABLE_ENTRY_NUM] = {
	{ .gain = { 256, 162, 380, 256 },
	  .k = 2700,
	  .matrix = { 4109, -1461, -600, -284, 5765, -3433, -1699, -2078, 5824 } },
	{ .gain = { 256, 217, 300, 256 },
	  .k = 4000,
	  .matrix = { 3822, -1376, -397, -874, 5230, -2308, -895, -1664, 4607 } },
	{ .gain = { 256, 258, 256, 256 },
	  .k = 5000,
	  .matrix = { 3728, -1261, -419, -1091, 4990, -1850, -620, -1560, 4228 } },
	{ .gain = { 256, 280, 228, 256 },
	  .k = 6500,
	  .matrix = { 3716, -1217, -451, -1259, 4833, -1526, -453, -1461, 3962 } },
	{ .gain = { 256, 295, 212, 256 },
	  .k = 7500,
	  .matrix = { 3685, -1181, -457, -1312, 4744, -1384, -371, -1408, 3827 } },
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
			.effective_iso[9] =  51200,
			.effective_iso[10] = 102400,
		},

		.csm = {
			.sat_table[0] =    160,
			.sat_table[1] =    150,
			.sat_table[2] =    140,
			.sat_table[3] =    136,
			.sat_table[4] =    132,
			.sat_table[5] =    130,
			.sat_table[6] =    122,
			.sat_table[7] =    110,
			.sat_table[8] =    100,
			.sat_table[9] =     85,
			.sat_table[10] =    64,
		},

		.shp = {
			.shp_table[0] =   128,
			.shp_table[1] =   118,
			.shp_table[2] =   108,
			.shp_table[3] =   100,
			.shp_table[4] =    90,
			.shp_table[5] =    90,
			.shp_table[6] =    90,
			.shp_table[7] =    90,
			.shp_table[8] =    87,
			.shp_table[9] =    64,
			.shp_table[10] =   64,
		},

		.nr = {
			.y_level_3d[0] =   90,
			.y_level_3d[1] =  100,
			.y_level_3d[2] =  130,
			.y_level_3d[3] =  155,
			.y_level_3d[4] =  170,
			.y_level_3d[5] =  185,
			.y_level_3d[6] =  185,
			.y_level_3d[7] =  185,
			.y_level_3d[8] =  185,
			.y_level_3d[9] =  185,
			.y_level_3d[10] = 185,

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
