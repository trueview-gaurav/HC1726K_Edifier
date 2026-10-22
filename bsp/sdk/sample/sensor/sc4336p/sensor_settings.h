#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2560_1440_30fps_2lane

#define SENSOR_WIDTH (2560)
#define SENSOR_HEIGHT (1440)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1500) // 0x320E/0x320F => 0x05dc = 1136
#define INIT_LINE_LEN (2800) // 0x320C/0x320D => 0x0af0 = 2800, default value get from SC FAE
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (2040) // analog gain only, for workaround
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
