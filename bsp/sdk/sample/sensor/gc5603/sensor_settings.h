#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define SENSOR_WIDTH (2960)
#define SENSOR_HEIGHT (1664)
#define INIT_LINE_LEN (4800) // {0x0342,0x0343} = 0x4B0 = 1200 , 1200 *4 = 4800
#define INIT_FRAME_LINE (1750) // {0x0340,0x0341} = 0x6D6 = 1750

#define SENSOR_FPS (30)
#define MAX_FPS (30)
#define MIN_FPS (5)

// wiki : User-guide-r3-x-How_to_light_up_a_new_sensor 12. Calibrate LVDS delay
#define T_HS_SETTLE_NS (120) // T_HS_SETTLE_NS: [85, 155]
#define T_D_TERM_EN_NS (39) // T_D_TERM_EN_NS: [0, 39] , real timming is 55 ns
#define T_CLK_SETTLE_NS (216) // T_CLK_SETTLE_NS: [95, 300]
#define T_CLK_TERM_EN_NS (38) // T_CLK_TERM_EN_NS: [0, 38] , reall timming is 50 ns

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#define SENSOR_GAIN_MAX (1982)
#define SENSOR_GAIN_MIN (32) // 32 is 1.0x

#endif /* SENSOR_SETTINGS_H_ */
