#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_4056_3040_15fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (4056)
#define SENSOR_HEIGHT (3040)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (3703) // 0x0340/0x3041 => 0x0E77 = 3703
#define INIT_LINE_LEN (10800) // 0x0342/0x3043 => 0x2A30 = 10800
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (123)
#define T_D_TERM_EN_NS (39) // real timming is 60.4 ns
#define T_CLK_SETTLE_NS (194)
#define T_CLK_TERM_EN_NS (38) // real timming is 54.1 ns
#endif
#if SET_4056_3040_20fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (4056)
#define SENSOR_HEIGHT (3040)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (3856) // 0x0340/0x3041 => 0x0F10 = 3856
#define INIT_LINE_LEN (6224) // 0x0342/0x3043 => 0x1850 = 6224
#define MAX_FPS (20)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (123)
#define T_D_TERM_EN_NS (39) // real timming is 60.4 ns
#define T_CLK_SETTLE_NS (194)
#define T_CLK_TERM_EN_NS (38) // real timming is 54.1 ns
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (11394) // Again max is 22.2608x , Dgain max is 15.99609375x
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
