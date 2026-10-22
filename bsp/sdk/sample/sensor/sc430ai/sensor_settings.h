#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1456)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1650) // 0x320E/0x320F => 0x465 = 1125
#define INIT_LINE_LEN (3200) // 0x320C/0x320D => 0x960 = 2400
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (144)
#define T_D_TERM_EN_NS (39) // 59.5ns in real timming
#define T_CLK_SETTLE_NS (204)
#define T_CLK_TERM_EN_NS (38) // 64ns in real timming

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (2477) // soft limit of AE, will be increased in future
#define SENSOR_GAIN_MIN (32)
// Analog gain max: 2447(76.48x)
// Analog + Digital max: 9636(301.14x)

#endif /* SENSOR_SETTINGS_H_ */
