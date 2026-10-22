#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#define SENSOR_WIDTH (2560) // Sensor Datasheet image width active pixels
#define SENSOR_HEIGHT (1440) // Sensor Datasheet image height active pixels
#define INIT_LINE_LEN (2592) // Sensor Register {0x0342,0x0343}= 0x360 = 864, 864x3 = 2592
#define INIT_FRAME_LINE (1562) // Sensor Register {0x0340,0x0341}= 0x61A = 1562

#define SENSOR_FPS (30) // Sensor Datasheet FPS Max
#define MAX_FPS (30)
#define MIN_FPS (5)

#define T_HS_SETTLE_NS (155) // T_HS_SETTLE_NS: [85, 155] , real timming is 161 ns
#define T_D_TERM_EN_NS (39) // T_D_TERM_EN_NS: [0, 39] , real timming is 81 ns
#define T_CLK_SETTLE_NS (253) // T_CLK_SETTLE_NS: [95, 300] , real timming is 253 ns
#define T_CLK_TERM_EN_NS (38) // T_CLK_TERM_EN_NS: [0, 38] , real timming is 61 ns

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#define SENSOR_GAIN_MAX (2048) // 32 * 64
#define SENSOR_GAIN_MIN (32) // 32 is 1.0x

#endif /* SENSOR_SETTINGS_H_ */
