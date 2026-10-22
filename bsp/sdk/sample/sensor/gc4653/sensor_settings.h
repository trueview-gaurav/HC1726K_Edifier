#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define SENSOR_WIDTH (2560)      // Sensor Datasheet image width active pixels
#define SENSOR_HEIGHT (1440)     // Sensor Datasheet image height active pixels
#define INIT_LINE_LEN (3200)     // Sensor Register 0x33f & 0x33e (0xC80) = 0x342 & 0x343 (0x640)*2, HTS , FrameW, LINE width
#define INIT_FRAME_LINE (1500)   // Sensor Register 0x340 & 0x341 (0x5DC), VTS , FrameH, VMAX
#define INIT_SHUTTER_LINE (1488) // Sensor Register 0x020 & 0x023 (0x5D0), Sensor Datasheet spec 9.9 : if shutter time > minimum frame length, Actual frame length = shutter time + 32

#define SENSOR_FPS (30)          // Sensor Datasheet FPS Max
#define MAX_FPS (30)
#define MIN_FPS (5)

// wiki : User-guide-r3-x-How_to_light_up_a_new_sensor 12. Calibrate LVDS delay
#define T_HS_SETTLE_NS (155)    // T_HS_SETTLE_NS: [85, 155]
#define T_D_TERM_EN_NS (39)     // T_D_TERM_EN_NS: [0, 39]
#define T_CLK_SETTLE_NS (155)   // T_CLK_SETTLE_NS: [95, 300]
#define T_CLK_TERM_EN_NS (38)   // T_CLK_TERM_EN_NS: [0, 38]

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#define SENSOR_GAIN_MAX (2844) //
#define SENSOR_GAIN_MIN (32)   // 32 is 1.0x

#endif /* SENSOR_SETTINGS_H_ */
