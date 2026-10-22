#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define SENSOR_PATH_MAX (2) // Should not be greater than MPI_MAX_INPUT_PATH_NUM

#if SET_1920_1080_30fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1125)
#define INIT_LINE_LEN (2560)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (94)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif
#if SET_1920_1080_125fps_2lane_S2 // 12.5 fps setting
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (12.5)
#define INIT_FRAME_LINE (2250) // {0x23,0x22} = 0x08CA = 2250
#define INIT_LINE_LEN (3072) // {0x21,0x20} = 0x0600 = 1536, x2 = 3072
#define MAX_FPS (12.5)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (129) // [85,155] , real timming is 129 ns
#define T_D_TERM_EN_NS (39) // [0,39] , real timming is 69 ns
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#define PCLK (86400000L) // 12.5 * 2250 * 3072
#endif

#if SET_1920_1080_10fps_2lane_S2
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (10)
#define INIT_FRAME_LINE (2812) // {0x23,0x22} = 0x0AFC = 2812
#define INIT_LINE_LEN (3072) // {0x21,0x20} = 0x0600 = 1536, x2 = 3072
#define MAX_FPS (10)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (129) // [85,155] , real timming is 129 ns
#define T_D_TERM_EN_NS (39) // [0,39] , real timming is 69 ns
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#define PCLK (86384640L) // 10 * 2812 * 3072
#endif

#ifndef PCLK
#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#endif
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_MAX_GAIN (496) // need to modify

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_GAIN,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
