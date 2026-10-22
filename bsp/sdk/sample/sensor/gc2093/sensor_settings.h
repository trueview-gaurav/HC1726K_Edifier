#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_2lane
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1125)
#define INIT_LINE_LEN (2640)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (150)
#define T_D_TERM_EN_NS (35)
#define T_CLK_SETTLE_NS (280)
#define T_CLK_TERM_EN_NS (35)
#endif

#ifdef SET_1920_1080_60fps_2lane
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (60)
#define INIT_FRAME_LINE (1250)
#define INIT_LINE_LEN (2640)
#define MAX_FPS (60)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (120)
#define T_D_TERM_EN_NS (35)
#define T_CLK_SETTLE_NS (200)
#define T_CLK_TERM_EN_NS (22)
#endif

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_MAX_GAIN (16383)

#endif /* SENSOR_SETTINGS_H_ */
