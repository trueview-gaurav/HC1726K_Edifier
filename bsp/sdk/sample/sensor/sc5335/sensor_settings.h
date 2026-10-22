#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2592_1944_20fps_2lane

#define SENSOR_WIDTH           (2592)
#define SENSOR_HEIGHT          (1944)
#define SENSOR_FPS             (20)
#define SENSOR_FRAME_LINES_MAX (7920) // min fps = 5
#define SENSOR_FRAME_LINES_MIN (1980) // fps = 20
#define PCLK                   (118800000)
#define INIT_FRAME_LINE        (1980)
#define INIT_LINE_LEN          (3000)
#define MAX_FPS                SENSOR_FPS
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#else /* SET_2560_1440_25fps_2lane */

#define SENSOR_WIDTH           (2560)
#define SENSOR_HEIGHT          (1440)
#define SENSOR_FPS             (25)
#define SENSOR_FRAME_LINES_MAX (7500) // min fps = 5
#define SENSOR_FRAME_LINES_MIN (1500) // fps = 25
#define PCLK                   (121500000)
#define INIT_FRAME_LINE        (1500)
#define INIT_LINE_LEN          (3240)
#define MAX_FPS                SENSOR_FPS
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif


#endif /* SENSOR_SETTINGS_H_ */
