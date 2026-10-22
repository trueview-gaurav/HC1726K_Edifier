#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_1920_1080_30fps_1lane

#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1125)
#define INIT_LINE_LEN (2560)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (196)
#define T_D_TERM_EN_NS (60)
#define T_CLK_SETTLE_NS (214)
#define T_CLK_TERM_EN_NS (60)
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
// #define SENSOR_GAIN_MAX (7936) // sensor hardware limit
#define SENSOR_GAIN_MAX (992) // soft limit

#endif /* SENSOR_SETTINGS_H_ */
