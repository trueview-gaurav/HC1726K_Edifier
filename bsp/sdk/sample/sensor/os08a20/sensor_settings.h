#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_3840_2160_15fps_2lane_12bit
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2317) // 0x90D = 2317
#define INIT_LINE_LEN (4144) // 0x1030 = 4144
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (116)
#define T_D_TERM_EN_NS (39) // real value is 46, but software limit is 39
#define T_CLK_SETTLE_NS (199)
#define T_CLK_TERM_EN_NS (29)
#endif
#if SET_3840_2160_30fps_4lane_12bit
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2317) // 0x90D = 2317
#define INIT_LINE_LEN (4144) // 0x818 * 2 = 4144
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (109)
#define T_D_TERM_EN_NS (39) // real value is 45, but software limit is 39
#define T_CLK_SETTLE_NS (191)
#define T_CLK_TERM_EN_NS (27)
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_MAX_GAIN (7935)
#define SENSOR_MAX_AGAIN (496) // max analog gain
#define SENSOR_MIN_GAIN (32)

#endif /* SENSOR_SETTINGS_H_ */
