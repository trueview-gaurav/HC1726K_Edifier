#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_3328_2496_20fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3328)
#define SENSOR_HEIGHT (2496)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (2778) // {0x380e,0x380f} = 0xADA  = 2778
#define INIT_LINE_LEN (6480) //  {0x380c,0x380d} = 0x654 = 1620, 1620*4 = 6480
#define MAX_FPS (20)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // real value is 1161ns , [85, 155]
#define T_D_TERM_EN_NS (39) // real value is 144ns,  [0, 39]
#define T_CLK_SETTLE_NS (300) // real value is 535ns , [95, 300]
#define T_CLK_TERM_EN_NS (38) // real value is 102ns , [0, 38]
#endif

#if SET_1184_896_120fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (1184)
#define SENSOR_HEIGHT (896)
#define SENSOR_FPS (120)
#define INIT_FRAME_LINE (1190) // {0x380e,0x380f} = 0x4A6 = 1190
#define INIT_LINE_LEN (2520) // {0x380c,0x380d} = 0x276 = 630 , 630x4 = 2520
#define MAX_FPS (120)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (127) // real value is 127ns , [85, 155]
#define T_D_TERM_EN_NS (39) // real value is 58ns,  [0, 39]
#define T_CLK_SETTLE_NS (191) // real value is 191 ns , [95, 300]
#define T_CLK_TERM_EN_NS (36) // real value is 36 ns , [0, 38]
#endif

#if SET_1664_1248_60fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (1664)
#define SENSOR_HEIGHT (1248)
#define SENSOR_FPS (60)
#define INIT_FRAME_LINE (1390) // {0x380e,0x380f} = 0x56D = 1390
#define INIT_LINE_LEN (2160) // {0x380c,0x380d} = 0x438 = 1080, 1080x2 = 2160
#define MAX_FPS (60)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // real value is 188ns , [85, 155]
#define T_D_TERM_EN_NS (39) // real value is 85ns,  [0, 39]
#define T_CLK_SETTLE_NS (300) // real value is 302 ns , [95, 300]
#define T_CLK_TERM_EN_NS (38) // real value is 65 ns , [0, 38]
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (7935) // analog gain is 15.5x , digtal gain is 15.9990234375x
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
