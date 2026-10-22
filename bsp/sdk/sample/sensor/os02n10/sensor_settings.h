#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

// 1920x1080@20fps, 2 lanes, 300Mbps
#ifdef SET_1920_1080_20fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (1379)
#define INIT_LINE_LEN (2176)
#define MAX_FPS (24)
#define MIN_FPS (5)
#define PCLK (60000000)
#define T_HS_SETTLE_NS (100)
#define T_D_TERM_EN_NS (60)
#define T_CLK_SETTLE_NS (200)
#define T_CLK_TERM_EN_NS (60)

#endif

#define SENSOR_FRAME_LINES_MAX (PCLK / INIT_LINE_LEN / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (PCLK / INIT_LINE_LEN / MAX_FPS)

#endif /* SENSOR_SETTINGS_H_ */
