#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#ifdef SET_2688_1520_30fps_4lane

#define SENSOR_WIDTH (2688)
#define SENSOR_HEIGHT (1520)
#define SENSOR_FPS (30)

#elif defined SET_2032_1520_25fps_2lane

#define SENSOR_WIDTH (2032)
#define SENSOR_HEIGHT (1520)
#define SENSOR_FPS (25)

#else /* SET_1920_1080_30fps_1/2/4lane */

#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)

#endif

#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif /* SENSOR_SETTINGS_H_ */
