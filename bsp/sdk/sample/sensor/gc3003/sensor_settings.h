#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#define SENSOR_WIDTH (2304)
#define SENSOR_HEIGHT (1296)
#define SENSOR_FPS (30)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define INIT_LINE_LEN (2688) // 0x0d05/0x0d06 = 0x540 = 1344*2 = 2688
#define INIT_FRAME_LINE (1336) // 0x0d41/0x0d42 = 0x53c = 1340  ~> flicker 0x538 = 1336
#define T_HS_SETTLE_NS (155) // [85, 155]    171ns in real timming
#define T_D_TERM_EN_NS (39) // [0, 39]      81ns in real timming
#define T_CLK_SETTLE_NS (287) // [95, 300]    287ns in real timming
#define T_CLK_TERM_EN_NS (38) // [0, 38]      69ns in real timming

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (2048)
#define SENSOR_GAIN_MIN (32)
#define SENSOR_EXP_LINE_SHIF (0)
#endif /* SENSOR_SETTINGS_H_ */
