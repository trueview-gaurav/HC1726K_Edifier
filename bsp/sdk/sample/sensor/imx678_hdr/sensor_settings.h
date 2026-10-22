#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if defined SET_3840x2160_DOL_4x_10fps_4lane || defined SET_3840x2160_DOL_8x_10fps_4lane ||       \
        defined SET_3840x2160_DOL_16x_10fps_4lane || defined SET_3840x2160_DOL_24x_10fps_4lane || \
        defined SET_3840x2160_DOL_32x_10fps_4lane || defined SET_3840x2160_DOL_64x_10fps_4lane || \
        defined SET_3840x2160_DOL_128x_10fps_4lane || defined SET_3840x2160_DOL_256x_10fps_4lane
#define DOL2_HDR
#define VC_DISABLE
#define HDR_MODE MPI_HDR_MODE_FRAME_COMB
#define HDR_IMAGE_NUM (2)

// HDR_BLANK_LINE = (RHS - 1) / 2 + 1
#ifdef SET_3840x2160_DOL_4x_10fps_4lane
#define HDR_BLANK_LINE (676)
#elif defined SET_3840x2160_DOL_8x_10fps_4lane
#define HDR_BLANK_LINE (376)
#elif defined SET_3840x2160_DOL_16x_10fps_4lane
#define HDR_BLANK_LINE (200)
#elif defined SET_3840x2160_DOL_24x_10fps_4lane
#define HDR_BLANK_LINE (136)
#elif defined SET_3840x2160_DOL_32x_10fps_4lane
#define HDR_BLANK_LINE (104)
#elif defined SET_3840x2160_DOL_64x_10fps_4lane
#define HDR_BLANK_LINE (53)
#elif defined SET_3840x2160_DOL_128x_10fps_4lane
#define HDR_BLANK_LINE (28)
#elif defined SET_3840x2160_DOL_256x_10fps_4lane
#define HDR_BLANK_LINE (15)
#endif

#define MIPI_HBP (24) // 16(LI) + 8(Margin)
#define MIPI_VBP (64) // ( 10(Ignored OB) + 10(OB) + 4(Ignored) + 8(Margin) ) * 2(HDR)
#define MIPI_HFP (8) // 8(Margin)
#define MIPI_VFP (16) // 8(Margin) * 2(HDR)

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (10)
// Original setting is 15 fps with VMAX = 2250
#define INIT_FRAME_LINE (3375)
#define INIT_LINE_LEN (1100) // HMAX = 1100
#define MAX_FPS (10)
#define MIN_FPS (1)

#define T_HS_SETTLE_NS (91) // Not measured
#define T_D_TERM_EN_NS (14) // Not measured
#define T_CLK_SETTLE_NS (135) // Not measured
#define T_CLK_TERM_EN_NS (14) // Not measured
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
// #define SENSOR_GAIN_MAX (127394) // Analog + Digital 72 dB
#define SENSOR_GAIN_MAX (1012) // Analog 30 dB
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
