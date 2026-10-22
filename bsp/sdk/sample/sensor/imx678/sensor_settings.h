#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_3840_2160_30fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2250) // {0x302A,0x3029,0x3028} = 0x8CA = 2250
#define INIT_LINE_LEN (4400) // {0x302D,0x302C} = 0x44c = 1100, 1100x4 = 4400
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif
#if SET_1920_1080_30fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2250) // {0x302A,0x3029,0x3028} = 0x8CA = 2250
#define INIT_LINE_LEN (4400) // {0x302D,0x302C} = 0x44c = 1100, 1100x4 = 4400
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383) // soft limit of AE
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
