#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2880_1616_20fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2880)
#define SENSOR_HEIGHT (1616)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (1650) // 0x23/0x22 => 0x672 = 1650
#define INIT_LINE_LEN (4400) // 0x21/0x20 => 0x44C = 1100,  1100*4=4400
#define MAX_FPS (20)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (146) // [85, 155] real timming is 146 ns
#define T_D_TERM_EN_NS (39) // [0, 39] real timming is 79 ns
#define T_CLK_SETTLE_NS (220) // [95, 300]  real timming is 220 ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]  real timming is 76 ns
#endif

#if SET_2592_1616_25fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1616)
#define SENSOR_FPS (25)
#define INIT_FRAME_LINE (1990) // 0x23/0x22 => 0x7C6 = 1990
#define INIT_LINE_LEN (3472) // 0x21/0x20 => 0x364 = 868,  868*4=3472
#define MAX_FPS (25)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (121) // [85, 155] real timming is 121.5 ns
#define T_D_TERM_EN_NS (39) // [0, 39] real timming is 66.5 ns
#define T_CLK_SETTLE_NS (196) // [95, 300]  real timming is 196 ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]  real timming is 66 ns
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (496) // AGain max is 15.5x, DGain max is 16x, but accuracy of DGain is too low
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
