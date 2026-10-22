/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/* sensor_settings.h - Information for different streaming settings.
 * Please refer to the documents for each member.
 */

#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1500)
#define INIT_LINE_LEN (2400)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (100)
#define T_D_TERM_EN_NS (20)
#define T_CLK_SETTLE_NS (100)
#define T_CLK_TERM_EN_NS (20)

#endif

#ifndef PCLK
#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#endif
#define SENSOR_FRAME_LINES_MAX (int)(INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (int)(INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
