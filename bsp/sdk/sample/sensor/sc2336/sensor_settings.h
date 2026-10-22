#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1136) // 0x320E/0x320F => 0x0470 = 1136
#define INIT_LINE_LEN (2200) // 0x320C/0x320D => 0x0898 = 2200
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_1920_1080_limit_15fps_2lane
// Use 30 fps settings as base, but with increased V Blanking and slowed down to 15 fps.
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2272)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_1920_1080_15fps_2lane_PSEUDO_MASTER

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2272)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_1920_1080_10fps_2lane_PSEUDO_MASTER

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (10)
#define INIT_FRAME_LINE (3408)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_1920_1080_15fps_2lane_PSEUDO_SLAVE

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2272)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#define SNS_SLAVE_MODE

#endif

#ifdef SET_1920_1080_10fps_2lane_PSEUDO_SLAVE

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (10)
#define INIT_FRAME_LINE (3408)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_1920_1080_15fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (1200) // 0x320E/0x320F => 0x04b0 = 1200
#define INIT_LINE_LEN (2250) // 0x320C/0x320D => 0x08ca = 2250
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_1920_1080_15fps_2lane_LOWPOWER

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (1200)
#define INIT_LINE_LEN (2250)
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define LOW_HS_DRIVING

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (2040) // analog gain only, for workaround
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
