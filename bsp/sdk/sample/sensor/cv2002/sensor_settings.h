#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_896_504_115fps_2lane

#define SENSOR_WIDTH (896)
#define SENSOR_HEIGHT (504)
#define SENSOR_FPS (115)
#define MAX_FPS (115)
#define MIN_FPS (5)
#define INIT_FRAME_LINE (626) // 0x3021,0x3020 = 0x4E4 = 1252 , 1252/2 = 626 > SENSOR_HEIGHT 504
#define INIT_LINE_LEN (1248) //   0x3025,0x3024 = 0x270 = 624 , 624x2 = 1248 > SENSOR_WIDTH 896
#define T_HS_SETTLE_NS (155) //  [85, 155] real value : 156.5ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 81ns
#define T_CLK_SETTLE_NS (263) // [95, 300] real value : 262.5ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 81.5ns

#endif

#ifdef SET_1920_1080_30fps_2lane

#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define INIT_FRAME_LINE (1250) // 0x3021,0x3020 = 0x9C4= 2500 , 2500/2 = 1250 > SENSOR_HEIGHT 1080
#define INIT_LINE_LEN (2528) //   0x3025,0x3024 = 0x278 = 632 , 1264x4 = 2528 > SENSOR_WIDTH 1920
#define T_HS_SETTLE_NS (155) //  [85, 155] real value : 320ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 168ns
#define T_CLK_SETTLE_NS (300) // [95, 300] real value : 504ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 164sns

#endif

#ifdef SET_1280_960_60fps_2lane

#define SENSOR_WIDTH (1280)
#define SENSOR_HEIGHT (960)
#define SENSOR_FPS (60)
#define MAX_FPS (60)
#define MIN_FPS (5)
#define INIT_FRAME_LINE (1200) // 0x3021,0x3020 = 0x960= 2400 , 2400/2 = 1200 > SENSOR_HEIGHT 960
#define INIT_LINE_LEN (2600) //   0x3025,0x3024 = 0x28A = 650 , 650x4 = 2600 > SENSOR_WIDTH 1280
#define T_HS_SETTLE_NS (155) //  [85, 155] real value : 320ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 168ns
#define T_CLK_SETTLE_NS (300) // [95, 300] real value : 504ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 164sns

#endif
#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (1024)
// Analog gain max: 1024(32x)
// Analog + Digital max: 32000(1000x)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
