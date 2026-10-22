#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_3536_3536_20fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3536)
#define SENSOR_HEIGHT (3536)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (3940)
#define INIT_LINE_LEN (942)
#define MAX_FPS (20)
#define MIN_FPS (5)
#define SENSOR_FRAME_LINES_MAX (15764)

#define MIPI_HBP (8)
#define MIPI_VBP (12)
#define MIPI_HFP (8)
#define MIPI_VFP (8)

#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#ifdef SET_3520_1920_30fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3520)
#define SENSOR_HEIGHT (1920)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2627)
#define INIT_LINE_LEN (942)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define SENSOR_FRAME_LINES_MAX (15764)

#define MIPI_HBP (8)
#define MIPI_VBP (12)
#define MIPI_HFP (8)
#define MIPI_VFP (8)

#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#define PCLK (74250000)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (1012) // Analog
// #define SENSOR_GAIN_MAX (127394) // Analog + Digital
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
