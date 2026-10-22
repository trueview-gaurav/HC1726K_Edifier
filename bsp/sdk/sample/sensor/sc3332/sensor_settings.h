#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2304_1296_20fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2304)
#define SENSOR_HEIGHT (1296)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (1980) // 0x320E/0x320F => default:0x7BC = 1980
#define INIT_LINE_LEN (2500) // 0x320C/0x320D => 0x4E2 = 1250 * 2 = 2500
#define SENSOR_FPS_MAX (20)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (155) // 176.25ns in real timming
#define T_D_TERM_EN_NS (39) // 75.45ns in real timming
#define T_CLK_SETTLE_NS (219) // 218.95.ns in real timming
#define T_CLK_TERM_EN_NS (38) // 59.4ns in real timming

#endif
#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MIN)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MAX)
#define SENSOR_GAIN_MAX (16383) // soft limit of AE, will be increased in future
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
