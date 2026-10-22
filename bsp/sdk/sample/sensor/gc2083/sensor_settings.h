#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_1lane

#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1125) // 0x0d41/0x0d42 = 0x465 = 1125
#define INIT_LINE_LEN (1836) // 0x0d05/0x0d06 = 0x72c = 1836
#define MAX_FPS (30)
#define MIN_FPS (3) // Frame line of GC2083 cannot exceed 16383
#define T_HS_SETTLE_NS (150)
#define T_D_TERM_EN_NS (39) // real timming is 73
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

// Warning: DO NOT USE THIS SETTING FOR PROJECT RELEASES
#ifdef SET_1920_1080_12_5fps_2lane_INTERNAL

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (12.5)
#define INIT_FRAME_LINE (1350) // 0x0d41/0x0d42 = 0x564 = 1350
#define INIT_LINE_LEN (1185) // 0x0d05/0x0d06 = 0x4a1 = 1185
#define MAX_FPS (12.5)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (150)
#define T_D_TERM_EN_NS (39)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#define PCLK (20000000) // 1350 * 1185 * 12.5 ~ 20Mpx/s
// In fact line length(HTS) should be 1185 * 2 = 2370, so PCLK is 40 Mpx/s

#endif

#ifndef PCLK
#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#endif
#define SENSOR_FRAME_LINES_MAX (int)(INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (int)(INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
