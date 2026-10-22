/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor.h"
#include "l_sensor_cal.h"
#include "sensor_settings.h"
#include "sensor_params.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#define DIP_MAX_PATH_NUM (2)

#define SENSOR_ID (385) // sensor ID
#define IMX385_VMAX1_ADDR (0x3018) // vmax(fps line)[7:0]
#define IMX385_VMAX2_ADDR (0x3019) // vmax(fps line)[15:8]
#define IMX385_VMAX3_ADDR (0x301A) // vmax(fps line)[16]
#define IMX385_SHS1_ADDR (0x3020) // sensor exposure line control(shs1) [7:0]
#define IMX385_SHS2_ADDR (0x3021) // sensor exposure line control(shs1) [15:8]
#define IMX385_SHS3_ADDR (0x3022) // sensor exposure line control(shs1) [16]
#define IMX385_GAIN1_ADDR (0x3014) // sensor gain [7:0]
#define IMX385_GAIN2_ADDR (0x3015) // sensor gain [9:8]

#define SONY_BIN (689)
#define EXP_LINE_GAP (3)
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (3)

#define CLAMP(x, min, max) (((x) > (max)) ? (max) : (((x) < (min)) ? (min) : (x)))

static CUSTOM_SNS_STATE_S g_sensor_state[DIP_MAX_PATH_NUM];
static CUSTOM_SNS_STATE_S *g_sns_state[DIP_MAX_PATH_NUM] = { &g_sensor_state[0], &g_sensor_state[1] };

static int g_inttime = 16500;

/* clang-format off */

// db = gain_bin / 10 (might differ from different sensors)
// gain_val = (10 ** (db / 20)) * 32 (python)
static int sony_gain_bin[SONY_BIN] = {
	  0,   3,   5,   8,  10,  13,  15,  17,  19,  22,  24,  26,  28,  30,  32,  33,  35,  37,  39,  40,
	 42,  44,  45,  47,  49,  50,  52,  53,  55,  56,  57,  59,  60,  62,  63,  64,  65,  67,  68,  69,
	 70,  72,  73,  74,  75,  76,  77,  78,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,
	 92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
	112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
	132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151,
	152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171,
	172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
	192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211,
	212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231,
	232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251,
	252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
	272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291,
	292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311,
	312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
	332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351,
	352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371,
	372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391,
	392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411,
	412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431,
	432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451,
	452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471,
	472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491,
	492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511,
	512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531,
	532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551,
	552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571,
	572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591,
	592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611,
	612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631,
	632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651,
	652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671,
	672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690, 691,
	692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 710, 711,
	712, 713, 714, 715, 716, 717, 718, 719, 720,
};

static int sony_gain_val[SONY_BIN] = {
	    32,     33,     34,     35,     36,     37,     38,     39,     40,     41,
	    42,     43,     44,     45,     46,     47,     48,     49,     50,     51,
	    52,     53,     54,     55,     56,     57,     58,     59,     60,     61,
	    62,     63,     64,     65,     66,     67,     68,     69,     70,     71,
	    72,     73,     74,     75,     76,     77,     78,     79,     80,     81,
	    82,     83,     84,     85,     86,     87,     88,     89,     90,     91,
	    92,     93,     94,     96,     97,     98,     99,    100,    101,    102,
	   104,    105,    106,    107,    108,    110,    111,    112,    114,    115,
	   116,    118,    119,    120,    122,    123,    124,    126,    127,    129,
	   130,    132,    133,    135,    137,    138,    140,    141,    143,    145,
	   146,    148,    150,    151,    153,    155,    157,    159,    160,    162,
	   164,    166,    168,    170,    172,    174,    176,    178,    180,    182,
	   184,    186,    188,    191,    193,    195,    197,    200,    202,    204,
	   207,    209,    211,    214,    216,    219,    221,    224,    227,    229,
	   232,    235,    237,    240,    243,    246,    248,    251,    254,    257,
	   260,    263,    266,    269,    272,    276,    279,    282,    285,    289,
	   292,    295,    299,    302,    306,    309,    313,    316,    320,    324,
	   327,    331,    335,    339,    343,    347,    351,    355,    359,    363,
	   367,    372,    376,    380,    385,    389,    394,    398,    403,    408,
	   412,    417,    422,    427,    432,    437,    442,    447,    452,    457,
	   463,    468,    473,    479,    484,    490,    496,    501,    507,    513,
	   519,    525,    531,    537,    543,    550,    556,    563,    569,    576,
	   582,    589,    596,    603,    610,    617,    624,    631,    638,    646,
	   653,    661,    669,    676,    684,    692,    700,    708,    716,    725,
	   733,    742,    750,    759,    768,    777,    786,    795,    804,    813,
	   823,    832,    842,    851,    861,    871,    881,    892,    902,    912,
	   923,    934,    944,    955,    966,    978,    989,   1000,   1012,   1024,
	  1035,   1047,   1060,   1072,   1084,   1097,   1110,   1122,   1135,   1149,
	  1162,   1175,   1189,   1203,   1217,   1231,   1245,   1259,   1274,   1289,
	  1304,   1319,   1334,   1349,   1365,   1381,   1397,   1413,   1429,   1446,
	  1463,   1480,   1497,   1514,   1532,   1549,   1567,   1585,   1604,   1622,
	  1641,   1660,   1679,   1699,   1719,   1738,   1759,   1779,   1799,   1820,
	  1841,   1863,   1884,   1906,   1928,   1951,   1973,   1996,   2019,   2042,
	  2066,   2090,   2114,   2139,   2163,   2189,   2214,   2239,   2265,   2292,
	  2318,   2345,   2372,   2400,   2427,   2456,   2484,   2513,   2542,   2571,
	  2601,   2631,   2662,   2692,   2724,   2755,   2787,   2819,   2852,   2885,
	  2918,   2952,   2986,   3021,   3056,   3091,   3127,   3163,   3200,   3237,
	  3275,   3312,   3351,   3390,   3429,   3469,   3509,   3549,   3590,   3632,
	  3674,   3717,   3760,   3803,   3847,   3892,   3937,   3982,   4029,   4075,
	  4122,   4170,   4218,   4267,   4317,   4367,   4417,   4468,   4520,   4572,
	  4625,   4679,   4733,   4788,   4843,   4899,   4956,   5014,   5072,   5130,
	  5190,   5250,   5311,   5372,   5434,   5497,   5561,   5625,   5690,   5756,
	  5823,   5890,   5959,   6028,   6097,   6168,   6240,   6312,   6385,   6459,
	  6534,   6609,   6686,   6763,   6841,   6921,   7001,   7082,   7164,   7247,
	  7331,   7416,   7502,   7588,   7676,   7765,   7855,   7946,   8038,   8131,
	  8225,   8321,   8417,   8514,   8613,   8713,   8814,   8916,   9019,   9123,
	  9229,   9336,   9444,   9553,   9664,   9776,   9889,  10003,  10119,  10236,
	 10355,  10475,  10596,  10719,  10843,  10969,  11096,  11224,  11354,  11486,
	 11618,  11753,  11889,  12027,  12166,  12307,  12449,  12594,  12739,  12887,
	 13036,  13187,  13340,  13494,  13651,  13809,  13969,  14130,  14294,  14459,
	 14627,  14796,  14968,  15141,  15316,  15494,  15673,  15854,  16038,  16224,
	 16412,  16602,  16794,  16988,  17185,  17384,  17585,  17789,  17995,  18203,
	 18414,  18627,  18843,  19061,  19282,  19505,  19731,  19960,  20191,  20424,
	 20661,  20900,  21142,  21387,  21635,  21885,  22139,  22395,  22654,  22917,
	 23182,  23450,  23722,  23997,  24274,  24556,  24840,  25128,  25419,  25713,
	 26011,  26312,  26616,  26925,  27236,  27552,  27871,  28194,  28520,  28850,
	 29184,  29522,  29864,  30210,  30560,  30914,  31272,  31634,  32000,  32371,
	 32745,  33125,  33508,  33896,  34289,  34686,  35087,  35494,  35905,  36320,
	 36741,  37166,  37597,  38032,  38472,  38918,  39369,  39824,  40286,  40752,
	 41224,  41701,  42184,  42673,  43167,  43667,  44172,  44684,  45201,  45725,
	 46254,  46790,  47331,  47880,  48434,  48995,  49562,  50136,  50717,  51304,
	 51898,  52499,  53107,  53722,  54344,  54973,  55610,  56254,  56905,  57564,
	 58230,  58905,  59587,  60277,  60975,  61681,  62395,  63118,  63848,  64588,
	 65336,  66092,  66857,  67632,  68415,  69207,  70008,  70819,  71639,  72469,
	 73308,  74157,  75015,  75884,  76763,  77652,  78551,  79460,  80380,  81311,
	 82253,  83205,  84169,  85143,  86129,  87126,  88135,  89156,  90188,  91233,
	 92289,  93358,  94439,  95532,  96638,  97757,  98889, 100035, 101193, 102365,
	103550, 104749, 105962, 107189, 108430, 109686, 110956, 112241, 113540, 114855,
	116185, 117530, 118891, 120268, 121661, 123069, 124494, 125936, 127394,
};

/* clang-format on */

static int32_t SENSOR_updateExpCmd(int32_t i2c_fd, uint8_t path_idx)
{
	MPI_SNS_REGS_TABLE_S *regs = g_sns_state[path_idx]->regs_info;
	SensCmd cmd[32];
	int ret;

	if (regs[0].is_config == false) {
		return MPI_SUCCESS;
	}

	for (int i = 0; i < regs[0].reg_num; ++i) {
		cmd[i].reg = regs->i2c_data[i].reg_addr;
		cmd[i].val = regs->i2c_data[i].reg_data;
	}

	ret = SENSOR_writeSeqWaddrBdata(i2c_fd, regs[0].reg_num, cmd, regs[0].i2c_data[0].dev_addr);

	return ret;
}

static int SENSOR_getRegsInfo(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs)
{
	MPI_SNS_REGS_TABLE_S *pregs = g_sns_state[idx.path]->regs_info;
	int i;

	if (NULL == regs) {
		printf("invalid NULL pointer!\n");
		return -EINVAL;
	}

	if (false == pregs[0].is_config) {
		pregs[0].bus_type = BUS_TYPE_I2C;
#ifdef SNS_I2C_1
		pregs[0].bus_sel.i2c_dev = 2;
#else
		pregs[0].bus_sel.i2c_dev = 1;
#endif
		pregs[0].cfg_delay_max = 2;
		pregs[0].reg_num = IDX_NUM;

		for (i = 0; i < pregs[0].reg_num; ++i) {
			pregs[0].i2c_data[i].is_update = true;
			pregs[0].i2c_data[i].dev_addr = SENSOR_I2C_SLAVE_ADDR;
			pregs[0].i2c_data[i].reg_addr_byte_num = 2;
			pregs[0].i2c_data[i].reg_data_byte_num = 1;
		}

		pregs[0].i2c_data[IDX_VMAX_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_1].reg_addr = IMX385_VMAX1_ADDR;
		pregs[0].i2c_data[IDX_VMAX_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_2].reg_addr = IMX385_VMAX2_ADDR;
		pregs[0].i2c_data[IDX_VMAX_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_VMAX_3].reg_addr = IMX385_VMAX3_ADDR;

		pregs[0].i2c_data[IDX_SHS_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_1].reg_addr = IMX385_SHS1_ADDR;
		pregs[0].i2c_data[IDX_SHS_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_2].reg_addr = IMX385_SHS2_ADDR;
		pregs[0].i2c_data[IDX_SHS_3].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_SHS_3].reg_addr = IMX385_SHS3_ADDR;

		pregs[0].i2c_data[IDX_GAIN_1].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN_1].reg_addr = IMX385_GAIN1_ADDR;
		pregs[0].i2c_data[IDX_GAIN_2].delay_frm_num = 0;
		pregs[0].i2c_data[IDX_GAIN_2].reg_addr = IMX385_GAIN2_ADDR;
		pregs[0].is_config = true;

		// unknown design, comment out until we find it be necessary
		/*
		pregs[1].i2c_data[IDX_GAIN_1].is_update = true;
		pregs[1].i2c_data[IDX_GAIN_1].dev_addr = SENSOR_I2C_SLAVE_ADDR;
		pregs[1].i2c_data[IDX_GAIN_1].reg_addr_byte_num = 2;
		pregs[1].i2c_data[IDX_GAIN_1].reg_data_byte_num = 1;
		pregs[1].i2c_data[IDX_GAIN_1].delay_frm_num = 0;
		pregs[1].i2c_data[IDX_GAIN_1].reg_addr = IMX385_GAIN1_ADDR;

		pregs[1].i2c_data[IDX_GAIN_2].is_update = true;
		pregs[1].i2c_data[IDX_GAIN_2].dev_addr = SENSOR_I2C_SLAVE_ADDR;
		pregs[1].i2c_data[IDX_GAIN_2].reg_addr_byte_num = 2;
		pregs[1].i2c_data[IDX_GAIN_2].reg_data_byte_num = 1;
		pregs[1].i2c_data[IDX_GAIN_2].delay_frm_num = 0;
		pregs[1].i2c_data[IDX_GAIN_2].reg_addr = IMX385_GAIN2_ADDR;
		*/
	}

	memcpy(regs, &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));
	// regs->i2c_data[6].reg_data = pregs[1].i2c_data[6].reg_data;
	// regs->i2c_data[6].is_update = pregs[1].i2c_data[6].is_update;
	memcpy(&pregs[1], &pregs[0], sizeof(MPI_SNS_REGS_TABLE_S));

	for (i = 0; i < pregs[0].reg_num; ++i) {
		pregs[0].i2c_data[i].is_update = false;
	}

	g_sns_state[idx.path]->exp_line[1] = g_sns_state[idx.path]->exp_line[0];
	g_sns_state[idx.path]->frame_line[1] = g_sns_state[idx.path]->frame_line[0];
	g_sns_state[idx.path]->line_pixel[1] = g_sns_state[idx.path]->line_pixel[0];

	return MPI_SUCCESS;
}

static void SENSOR_globalInit(MPI_PATH idx)
{
	g_sensor_state[idx.path].sensor_gain = 32;
	g_sensor_state[idx.path].pclk = PCLK;
	g_sensor_state[idx.path].fps_line = INIT_FRAME_LINE;
	g_sensor_state[idx.path].frame_line[0] = INIT_FRAME_LINE;
	g_sensor_state[idx.path].line_pixel[0] = INIT_LINE_LEN;

	// old method
	/*
	int tmp_pclk = (g_sensor_state[idx.path].pclk + ROW_TIME_UNIT) >> (ROW_TIME_PRC + 1);
	assert(tmp_pclk > 0 && "[Sensor Error] tmp_pclk must be greater than than 0.\n");
	g_sensor_state[idx.path].row_time[0] =
	        ((g_sensor_state[idx.path].line_pixel[0] * 500000) + (tmp_pclk >> 1)) / tmp_pclk;
	*/

	// direct method, require 64bit int
	g_sensor_state[idx.path].row_time[0] =
	        (int32_t)((((int64_t)g_sensor_state[idx.path].line_pixel[0] << ROW_TIME_PRC) * 1000000 +
	                 (g_sensor_state[idx.path].pclk >> 1)) /
	                g_sensor_state[idx.path].pclk);

	g_sensor_state[idx.path].exp_line[0] =
	        ((g_inttime << ROW_TIME_PRC) + (g_sensor_state[idx.path].row_time[0] >> 1)) /
	        g_sensor_state[idx.path].row_time[0];

	g_sensor_state[idx.path].exp_line[1] = g_sensor_state[idx.path].exp_line[0];
	g_sensor_state[idx.path].frame_line[1] = g_sensor_state[idx.path].frame_line[0];
	g_sensor_state[idx.path].line_pixel[1] = g_sensor_state[idx.path].line_pixel[0];
	g_sensor_state[idx.path].row_time[1] = g_sensor_state[idx.path].row_time[0];

	MPI_SNS_REGS_TABLE_S init_regs = { 0 };
	memcpy(&g_sns_state[idx.path]->regs_info[0], &init_regs, sizeof(MPI_SNS_REGS_TABLE_S));
	memcpy(&g_sns_state[idx.path]->regs_info[1], &init_regs, sizeof(MPI_SNS_REGS_TABLE_S));
	g_sns_state[idx.path]->regs_info[0].is_config = false;
	g_sns_state[idx.path]->regs_info[1].is_config = false;
}

static int32_t SENSOR_setInttime(MPI_PATH idx, uint32_t time_us, uint32_t *effective_time)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row time) must be greater than than 0.\n");
	int exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];

	if (exp_line > SENSOR_EXP_LINES_MAX || exp_line < SENSOR_EXP_LINES_MIN) {
		printf("[Sensor warning] Exposure time exceeds hardware limit.\n");
		exp_line = CLAMP(exp_line, SENSOR_EXP_LINES_MIN, SENSOR_EXP_LINES_MAX);
	}

	if (exp_line > g_sensor_state[idx.path].frame_line[0] - EXP_LINE_GAP) {
		printf("[Sensor Error] Expsoure time too long in current FPS.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].exp_line[0] = exp_line;
	uint32_t time_tmp = ((uint32_t)exp_line * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC;
	if (time_tmp < time_us) {
		time_tmp += 1;
	}
	g_inttime = time_tmp;
	if (effective_time) {
		*effective_time = time_tmp;
	}

	uint32_t shs1 = g_sensor_state[idx.path].frame_line[0] - g_sensor_state[idx.path].exp_line[0] - 1;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].reg_data = (shs1 & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].reg_data = ((shs1 >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].reg_data = ((shs1 >> 16) & 0x01);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_SHS_3].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSensorGain(MPI_PATH idx, uint32_t gain)
{
	g_sns_state[idx.path]->sensor_gain = gain;

	if (gain < 32) {
		printf("[Sensor Error] Sensor gain must be greater than 32\n");
		return MPI_FAILURE;
	} else if (gain > sony_gain_val[SONY_BIN - 1]) {
		printf("[Sensor Error] Sensor gain bigger than sensor limit\n");
		return MPI_FAILURE;
	} else {
		int target_bin = binary_search_bin(gain, sony_gain_val, 0, SONY_BIN - 1);

		// old interpolation method
		/*
		int norm = sony_gain_val[target_bin] - sony_gain_val[target_bin - 1];
		int alpha = gain - sony_gain_val[target_bin - 1];
		int gain_sensor_bin =
		        interpolation(sony_gain_bin[target_bin], sony_gain_bin[target_bin - 1], alpha, norm);
		*/

		// directly compare the nearest two value
		int diff_low = gain - sony_gain_val[target_bin - 1];
		int diff_high = sony_gain_val[target_bin] - gain;
		int gain_sensor_bin = diff_low < diff_high ? sony_gain_bin[target_bin - 1] : sony_gain_bin[target_bin];

		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].reg_data = (gain_sensor_bin & 0xFF);
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_1].is_update = true;
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].reg_data = ((gain_sensor_bin >> 8) & 0x03);
		g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_GAIN_2].is_update = true;
	}

	return MPI_SUCCESS;
}

static int32_t SENSOR_setFramrate(MPI_PATH idx, float fps, RANGE_S *inttime)
{
	assert(fps > 0 && "[Sensor Error] FPS must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters(line_pixel) must be greater than 0.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	uint32_t frame_line; /* In one frame, number of sensor can output lines */
	uint32_t sec_line; /* In one second, number of sensor can output lines */

	fps = fps * FPS_UNIT;
	sec_line = ((g_sensor_state[idx.path].pclk + (g_sensor_state[idx.path].line_pixel[0] >> 1)) /
	            g_sensor_state[idx.path].line_pixel[0])
	           << FPS_PRC;
	frame_line = (sec_line + ((int)fps >> 1)) / (int)fps;
	frame_line = ((frame_line < 1) ? 1 : frame_line);

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	uint32_t inttime_max =
	        (((frame_line - EXP_LINE_GAP) * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >>
	         ROW_TIME_PRC);
	uint32_t inttime_min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;

	if (g_sensor_state[idx.path].exp_line[0] > frame_line - EXP_LINE_GAP) {
		SENSOR_setInttime(idx, inttime_max, NULL);
	} else {
		SENSOR_setInttime(idx, g_inttime, NULL);
	}

	if (inttime) {
		inttime->max = inttime_max;
		inttime->min = inttime_min;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x01);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	return MPI_SUCCESS;
}

static int32_t SENSOR_setSlowInttime(MPI_PATH idx, uint32_t time_us, float *fps)
{
	assert(time_us > 0 && "[Sensor Error] exposure time must be greater than 0.\n");
	assert(g_sensor_state[idx.path].line_pixel[0] > 0 &&
	       "[Sensor Error] Global parameters of sensor driver has problem.\n");
	assert(g_sensor_state[idx.path].row_time[0] > 0 &&
	       "[Sensor Error] Global parameters(row_time) must be greater than 0.\n");

	int exp_line = (time_us << ROW_TIME_PRC) / g_sensor_state[idx.path].row_time[0];
	int frame_line = exp_line + EXP_LINE_GAP;
	assert(frame_line > 0 && "[Sensor Error] frame_line must be greater than 0.\n");

	if ((frame_line) > SENSOR_FRAME_LINES_MAX || ((frame_line) < SENSOR_FRAME_LINES_MIN)) {
		printf("[Sensor Error] Exposure time or FPS exceeds hardware limit.\n");
		return MPI_FAILURE;
	}

	g_sensor_state[idx.path].frame_line[0] = frame_line;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].reg_data = (frame_line & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_1].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].reg_data = ((frame_line >> 8) & 0xFF);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_2].is_update = true;
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].reg_data = ((frame_line >> 16) & 0x01);
	g_sns_state[idx.path]->regs_info[0].i2c_data[IDX_VMAX_3].is_update = true;

	if (fps) {
		int temp = (frame_line * g_sensor_state[idx.path].line_pixel[0]);
		*fps = (float)g_sensor_state[idx.path].pclk / (float)temp;
	}

	SENSOR_setInttime(idx, time_us, NULL);

	return MPI_SUCCESS;
}

static int SENSOR_getAeDefault(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft)
{
	dft->inttime_range.max =
	        ((SENSOR_EXP_LINES_MAX * g_sensor_state[idx.path].row_time[0] + (ROW_TIME_UNIT >> 1)) >> ROW_TIME_PRC);
	dft->inttime_range.min = ((SENSOR_EXP_LINES_MIN * g_sensor_state[idx.path].row_time[0]) >> ROW_TIME_PRC) + 1;
	dft->sensor_gain_range.max = SENSOR_MAX_GAIN;
	dft->sensor_gain_range.min = 32;
	dft->target_sys_gain_range.max = 3200;
	dft->target_sys_gain_range.min = 32;
	dft->target_sensor_gain_range.max = SENSOR_MAX_GAIN;
	dft->target_sensor_gain_range.min = 32;
	dft->target_isp_gain_range.max = 3200;
	dft->target_isp_gain_range.min = 32;
	dft->gain_thr_up = 2048;
	dft->gain_thr_down = 2176;
	dft->max_fps = (float)MAX_FPS;
	dft->min_fps = (float)MIN_FPS;
	dft->speed = 160;
	dft->tolerance = 1280;
	dft->brightness = 5800;
	dft->exp_value = 528000;

	return MPI_SUCCESS;
}

static int SENSOR_getDipDefault(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft)
{
	memcpy(dft, &dip_dft, sizeof(dip_dft));
	return MPI_SUCCESS;
}

static int SENSOR_getAwbDefault(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *awb)
{
	/* TODO - fool proof design */

	memcpy(awb->k_table, &ct_tbl_dft[0], sizeof(MPI_AWB_COLOR_TEMP_S) * MPI_K_TABLE_ENTRY_NUM);
	memcpy(awb->delta_table, &delta_tbl_dft[0], sizeof(MPI_AWB_COLOR_DELTA_S) * MPI_K_TABLE_ENTRY_NUM);

	return MPI_SUCCESS;
}

static int SENSOR_getBlackLevel(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level)
{
	int32_t array[11];

	for (int i = 0; i < 11; i++) {
		array[i] = black_level_table.black_level[i];
	}

	int32_t black_level;
	uint32_t gain = g_sns_state[idx.path]->sensor_gain;
	gain = CLAMP(gain, k_sensor_gain_bin[0], k_sensor_gain_bin[MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1]);

	int32_t target_bin = binary_search_bin(gain, k_sensor_gain_bin, 0, MPI_SENSOR_GAIN_LUT_ENTRY_NUM - 1);
	int norm = k_sensor_gain_bin[target_bin] - k_sensor_gain_bin[target_bin - 1];
	int alpha = gain - k_sensor_gain_bin[target_bin - 1];
	black_level = interpolation(array[target_bin], array[target_bin - 1], alpha, norm);

	level->dbc_level = (uint16_t)black_level;

	return MPI_SUCCESS;
}

static int SENSOR_getCalDefault(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *cal)
{
	/* TODO - fool proof design*/

	memcpy(cal, &cal_tbl_dft, sizeof(MPI_CAL_SNS_DEFAULT_S));

	return MPI_SUCCESS;
}

static int SENSOR_regCallback(MPI_PATH idx)
{
	MPI_SNS_CALLBACK_S sensor_callback = {
		.dip =
		        {
		                .init = SENSOR_configInit,
		                .get_sns_op_info = SENSOR_getOpInfo,
		                .global_init = SENSOR_globalInit,
		                .get_dip_default = SENSOR_getDipDefault,
		                .get_regs_info = SENSOR_getRegsInfo,
		                .exit = SENSOR_configExit,
		        },

		.cal =
		        {
		                .get_black_level = SENSOR_getBlackLevel,
		                .get_cal_default = SENSOR_getCalDefault,
		        },

		.ae =
		        {
		                .get_ae_default = SENSOR_getAeDefault,
		                .set_framerate = SENSOR_setFramrate,
		                .set_slow_inttime = SENSOR_setSlowInttime,
		                .set_inttime = SENSOR_setInttime,
		                .set_sensor_gain = SENSOR_setSensorGain,
		        },

		.awb =
		        {
		                .get_awb_default = SENSOR_getAwbDefault,
		        },
	};

	MPI_regSnsCallback(idx, SENSOR_ID, &sensor_callback);

	return MPI_SUCCESS;
}

static int SENSOR_deregSnsCallback(MPI_PATH idx)
{
	MPI_deregSnsCallback(idx, SENSOR_ID);
	return MPI_SUCCESS;
}

#ifdef SNS0
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS0_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};

__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS0_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif

#ifdef SNS1
__attribute__((visibility("default"))) CUSTOM_SNS_CTRL_S custom_sns(SNS1_ID) = {
	.reg_callback = SENSOR_regCallback,
	.dereg_callback = SENSOR_deregSnsCallback,
};

__attribute__((visibility("default"))) SENSOR_CMOS_CTRL_S cmos_ctrl(SNS1_ID) = {
	.update_exp_cmd = SENSOR_updateExpCmd,
};
#endif
