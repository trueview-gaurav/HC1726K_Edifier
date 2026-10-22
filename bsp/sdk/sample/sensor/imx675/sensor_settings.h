#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2592_1944_25fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (25)
#define INIT_FRAME_LINE (2200) // {0x302A,0x3029,0x3028} = 0x898 = 2200
#define INIT_LINE_LEN \
	(3600) // INIT_FRAME_LINE * INIT_LINE_LEN = (MIPI data rate * MIPI lane ) / MIPI bit-width / fps  2200*3636=(1440*2)/12/30
#define MAX_FPS (25)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (115)
#define T_D_TERM_EN_NS (39)
#define T_CLK_SETTLE_NS (182)
#define T_CLK_TERM_EN_NS (38)
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383) // soft limit of AE
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
