#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

// #ifdef SET_2304_1296_30fps_2lane

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2250) // 0x320E/0x320F => default:0x8CA = 1360
#define INIT_LINE_LEN (4267) // 0x320C/0x320D => 0x44C = 1100 * 4 = 4400
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // 176.25ns in real timming
#define T_D_TERM_EN_NS (39) // 75.45ns in real timming
#define T_CLK_SETTLE_NS (219) // 218.95.ns in real timming
#define T_CLK_TERM_EN_NS (38) // 59.4ns in real timming

#endif
#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383) // soft limit of AE, will be increased in future
#define SENSOR_GAIN_MIN (32)

/* SENSOR_SETTINGS_H_ */
