#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_1280_720_30fps_1lane
#define BINNING_MODE 0
#define SENSOR_WIDTH (1280)
#define SENSOR_HEIGHT (720)
#define SENSOR_FPS (30)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define INIT_LINE_LEN (2200) // 0x0d05/0x0d06 = 0x898 = 2200
#define INIT_FRAME_LINE (818) // 0x0d41/0x0d42 = 0x332 = 818
#define T_HS_SETTLE_NS (155) // real timming is 610 ns
#define T_D_TERM_EN_NS (39) // real timming is 462 ns
#define T_CLK_SETTLE_NS (155)
#define T_CLK_TERM_EN_NS (38)
#endif
#if SET_640_360_60fps_1lane
#define BINNING_MODE 1
#define SENSOR_WIDTH (640)
#define SENSOR_HEIGHT (360)
#define SENSOR_FPS (60)
#define MAX_FPS (60)
#define MIN_FPS (5)
#define INIT_LINE_LEN (1111) // 0x0d05/0x0d06 = 0x08AE = 2222 (only need half in binning mode)
#define INIT_FRAME_LINE (375) // 0x0d41/0x0d42 = 0x02EE = 750 (only need half in binning mode)
#define T_HS_SETTLE_NS (155) // real timming is 266 ns
#define T_D_TERM_EN_NS (39) // real timming is 122 ns
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#define PCLK ((uint64_t)INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (2048)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
