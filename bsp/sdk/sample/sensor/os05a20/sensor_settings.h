#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2592_1944_30fps_2lane

#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1995) // 0x7CB
#define INIT_LINE_LEN (3008) // 0x5E0 * 2 = 3008
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (116)
#define T_D_TERM_EN_NS (51)
#define T_CLK_SETTLE_NS (116)
#define T_CLK_TERM_EN_NS (51)

#elif defined(SET_2592_1944_15fps_1lane)

#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (1995) // 0x7CB
#define INIT_LINE_LEN (6016) // 0xBC0 * 2 = 6016
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (116)
#define T_D_TERM_EN_NS (51)
#define T_CLK_SETTLE_NS (116)
#define T_CLK_TERM_EN_NS (51)

#elif defined(SET_2560_1440_15fps_1lane)

#define SENSOR_WIDTH (2560)
#define SENSOR_HEIGHT (1440)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (1995) // 0x7CB
#define INIT_LINE_LEN (6016) // 0xBC0 * 2 = 6016
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (116)
#define T_D_TERM_EN_NS (51)
#define T_CLK_SETTLE_NS (116)
#define T_CLK_TERM_EN_NS (51)

#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (PCLK / INIT_LINE_LEN / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (PCLK / INIT_LINE_LEN / MAX_FPS)

#define SENSOR_MAX_GAIN (7935)
#define SENSOR_MAX_AGAIN (496) // max analog gain
#define SENSOR_MIN_GAIN (32)

#endif /* SENSOR_SETTINGS_H_ */
