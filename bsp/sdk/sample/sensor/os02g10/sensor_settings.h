#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

// 1920x1080@30fps, 2 lanes, 720Mbps
#ifdef SET_1920_1080_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1109)
#define INIT_LINE_LEN (2164)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define PCLK (72000000) // define this value without the formula to make it exact
#define T_HS_SETTLE_NS (400)
#define T_D_TERM_EN_NS (140)
#define T_CLK_SETTLE_NS (400)
#define T_CLK_TERM_EN_NS (140)

#endif

#define SENSOR_FRAME_LINES_MAX (PCLK / INIT_LINE_LEN / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (PCLK / INIT_LINE_LEN / MAX_FPS)

#endif /* SENSOR_SETTINGS_H_ */
