#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2560_1440_30fps_2lane
#define SENSOR_WIDTH (2560)
#define SENSOR_HEIGHT (1440)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1472) //VTS {0x35,0x36} = 0x05C0=1472
#define INIT_LINE_LEN (3256) //HTS {0x37,0x38} = 0x032E=814, 814*4=3256
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // [85, 155] real timming is 155 ns
#define T_D_TERM_EN_NS (39) // [0, 39] real timming is 61 ns
#define T_CLK_SETTLE_NS (135) // [95, 300]
#define T_CLK_TERM_EN_NS (14) // [0, 38]
#endif

#if SET_2568_1448_30fps_2lane
#define SENSOR_WIDTH (2568)
#define SENSOR_HEIGHT (1448)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1473) //VTS 0x35=05 0x36=C1 0536=1473
#define INIT_LINE_LEN (3256) //HTS 0x37=03 0x38=2E 032E=814, 814*4=3256
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // [85, 155] real timming is 155 ns
#define T_D_TERM_EN_NS (39) // [0, 39] real timming is 61 ns
#define T_CLK_SETTLE_NS (135) // [95, 300]
#define T_CLK_TERM_EN_NS (14) // [0, 38]
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#endif /* SENSOR_SETTINGS_H_ */
