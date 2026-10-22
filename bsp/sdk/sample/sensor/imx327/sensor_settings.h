#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_1920_1080_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1125)
#define INIT_LINE_LEN (2200)
#define SENSOR_FPS_MAX (30)
#define SENSOR_FPS_MIN (5)
#define BIT_DEPTH MPI_BITS_12
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MIN)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MAX)
#define SENSOR_GAIN_MAX (16383) // soft limit of AE, will be increased in future
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
