#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define SENSOR_PATH_MAX (3) // Should not be greater than MPI_MAX_INPUT_PATH_NUM

#if SET_1280_720_60fps_1lane
#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (1280)
#define SENSOR_HEIGHT (720)
#define SENSOR_FPS (60)
#define INIT_FRAME_LINE (750) // 0x22/0x23 => default: 0x02EE = 750
#define INIT_LINE_LEN (1920) // 0x20/0221 => default: 0x03C0 = 960 => x2 = 1920
#define MAX_FPS (60)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (133) // T_HS_SETTLE_NS: [85, 155]
#define T_D_TERM_EN_NS (39) // T_D_TERM_EN_NS: [0, 39]  61.1ns in real timming
#define T_CLK_SETTLE_NS (190) // T_CLK_SETTLE_NS: [95, 300]
#define T_CLK_TERM_EN_NS (38) // T_CLK_TERM_EN_NS: [0, 38]  56.7ns in real timming
#endif

#if SET_1280_720_30fps_1lane
#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (1280)
#define SENSOR_HEIGHT (720)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (750) // 0x22/0x23 => default: 0x02EE = 750
#define INIT_LINE_LEN (1920) // 0x20/0221 => default: 0x03C0 = 960 => x2 = 1920
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (133) // T_HS_SETTLE_NS: [85, 155]
#define T_D_TERM_EN_NS (39) // T_D_TERM_EN_NS: [0, 39]  61.1ns in real timming
#define T_CLK_SETTLE_NS (190) // T_CLK_SETTLE_NS: [95, 300]
#define T_CLK_TERM_EN_NS (38) // T_CLK_TERM_EN_NS: [0, 38]  56.7ns in real timming
#endif

#if SET_1280_720_15fps_1lane_S2
#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (1280)
#define SENSOR_HEIGHT (720)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (1600) // 0x22/0x23 => default: 0x640 = 1600
#define INIT_LINE_LEN (1600) // 0x20/0221 => default: 0x0320 = 800 => x2 = 1600
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // T_HS_SETTLE_NS: [85, 155] 179ns in real timming
#define T_D_TERM_EN_NS (39) // T_D_TERM_EN_NS: [0, 39]  ,80ns in real timming
#define T_CLK_SETTLE_NS (190) // T_CLK_SETTLE_NS: [95, 300]
#define T_CLK_TERM_EN_NS (38) // T_CLK_TERM_EN_NS: [0, 38]
#endif

#if SET_1280_720_15fps_1lane_S3
#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (1280)
#define SENSOR_HEIGHT (720)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (3000) // 0x22/0x23 => default: 0x0BB8 = 3000
#define INIT_LINE_LEN (1920) // 0x20/0221 => default: 0x03C0 = 960 => x2 = 1920
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (133) // T_HS_SETTLE_NS: [85, 155]
#define T_D_TERM_EN_NS (39) // T_D_TERM_EN_NS: [0, 39]  61.1ns in real timming
#define T_CLK_SETTLE_NS (190) // T_CLK_SETTLE_NS: [95, 300]
#define T_CLK_TERM_EN_NS (38) // T_CLK_TERM_EN_NS: [0, 38]  56.7ns in real timming
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#define SENSOR_MIN_GAIN (32)
#define SENSOR_MAX_GAIN (496)

#define EXP_LINE_GAP (1) // should be 0 but let's give it some time to reset properly
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1) // should be tested if 1 line doesn't have a proper IQ
#define SENSOR_EXP_LINE_SHIF (0) // Sensor Datasheet spec 2.2.2 AEC step size : 1 step size = 0 or 0.5 step size = 1

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (16)
#define FPS_UNIT (1 << FPS_PRC)
#endif /* SENSOR_SETTINGS_H_ */
