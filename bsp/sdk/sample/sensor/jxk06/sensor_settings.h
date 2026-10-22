#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2560)
#define SENSOR_HEIGHT (1440)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1500) // 0x23/0x22 => 0x5DC = 1500
#define INIT_LINE_LEN (2880) // 0x21/0x20 => 0x3C0 = 960,  960*3=2880
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (132)
#define T_D_TERM_EN_NS (39) // real timming is 72.8 ns
#define T_CLK_SETTLE_NS (132)
#define T_CLK_TERM_EN_NS (38)

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_MAX_GAIN (496) // AGain max is 15.5x, DGain max is 16x, but accuracy of DGain is too low
#define SENSOR_MIN_GAIN (32)

#endif /* SENSOR_SETTINGS_H_ */
