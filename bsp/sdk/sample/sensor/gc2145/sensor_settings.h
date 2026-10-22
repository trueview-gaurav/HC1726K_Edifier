#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1600)
#define SENSOR_HEIGHT (1200)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (1250) // 0x0d41/0x0d42 = 0x465 = 1125
#define INIT_LINE_LEN (1800) // 0x0d05/0x0d06 = 0x72c = 1836
#define MAX_FPS (20)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (150)
#define T_D_TERM_EN_NS (39) // real timming is 73
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#ifndef PCLK
#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#endif
#define SENSOR_FRAME_LINES_MAX (int)(INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (int)(INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
