#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if defined SET_3536x3536_DOL_4x_10fps_4lane || defined SET_3536x3536_DOL_8x_10fps_4lane ||       \
        defined SET_3536x3536_DOL_16x_10fps_4lane || defined SET_3536x3536_DOL_24x_10fps_4lane || \
        defined SET_3536x3536_DOL_32x_10fps_4lane || defined SET_3536x3536_DOL_64x_10fps_4lane || \
        defined SET_3536x3536_DOL_128x_10fps_4lane || defined SET_3536x3536_DOL_256x_10fps_4lane
#define DOL2_HDR
#define VC_DISABLE
#define HDR_MODE MPI_HDR_MODE_FRAME_COMB
#define HDR_IMAGE_NUM (2)

// HDR_BLANK_LINE = (RHS - 1) / 2 + 1
#ifdef SET_3536x3536_DOL_4x_10fps_4lane
#define HDR_BLANK_LINE (324)
#elif defined SET_3536x3536_DOL_8x_10fps_4lane
#define HDR_BLANK_LINE (324)
#elif defined SET_3536x3536_DOL_16x_10fps_4lane
#define HDR_BLANK_LINE (234)
#elif defined SET_3536x3536_DOL_24x_10fps_4lane
#define HDR_BLANK_LINE (160)
#elif defined SET_3536x3536_DOL_32x_10fps_4lane
#define HDR_BLANK_LINE (122)
#elif defined SET_3536x3536_DOL_64x_10fps_4lane
#define HDR_BLANK_LINE (64)
#elif defined SET_3536x3536_DOL_128x_10fps_4lane
#define HDR_BLANK_LINE (34)
#elif defined SET_3536x3536_DOL_256x_10fps_4lane
#define HDR_BLANK_LINE (18)
#endif

#define MIPI_HBP (24) // 16(LI) + 8(Margin)
#define MIPI_VBP (64) // (10(Ignored OB) + 10(OB) + 4(Ignored) + 8(Margin)) * 2(HDR)
#define MIPI_HFP (8) // 8(Margin)
#define MIPI_VFP (16) // 8(Margin) * 2(HDR)

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3536)
#define SENSOR_HEIGHT (3536)
#define SENSOR_FPS (10)
#define INIT_FRAME_LINE (3940)
#define INIT_LINE_LEN (942) // HMAX = 942
#define MAX_FPS (10)
#define MIN_FPS (1)
#define SENSOR_FRAME_LINES_MAX (39410) // 1 fps

#define T_HS_SETTLE_NS (91) // Not measured
#define T_D_TERM_EN_NS (14) // Not measured
#define T_CLK_SETTLE_NS (135) // Not measured
#define T_CLK_TERM_EN_NS (14) // Not measured
#endif

#if defined SET_3520x1920_DOL_4x_15fps_4lane || defined SET_3520x1920_DOL_8x_15fps_4lane ||       \
        defined SET_3520x1920_DOL_16x_15fps_4lane || defined SET_3520x1920_DOL_24x_15fps_4lane || \
        defined SET_3520x1920_DOL_32x_15fps_4lane || defined SET_3520x1920_DOL_64x_15fps_4lane || \
        defined SET_3520x1920_DOL_128x_15fps_4lane || defined SET_3520x1920_DOL_256x_15fps_4lane
#define DOL2_HDR
#define VC_DISABLE
#define HDR_MODE MPI_HDR_MODE_FRAME_COMB
#define HDR_IMAGE_NUM (2)

// HDR_BLANK_LINE = (RHS - 1) / 2 + 1
#ifdef SET_3520x1920_DOL_4x_15fps_4lane
#define HDR_BLANK_LINE (526)
#elif defined SET_3520x1920_DOL_8x_15fps_4lane
#define HDR_BLANK_LINE (294)
#elif defined SET_3520x1920_DOL_16x_15fps_4lane
#define HDR_BLANK_LINE (156)
#elif defined SET_3520x1920_DOL_24x_15fps_4lane
#define HDR_BLANK_LINE (108)
#elif defined SET_3520x1920_DOL_32x_15fps_4lane
#define HDR_BLANK_LINE (82)
#elif defined SET_3520x1920_DOL_64x_15fps_4lane
#define HDR_BLANK_LINE (44)
#elif defined SET_3520x1920_DOL_128x_15fps_4lane
#define HDR_BLANK_LINE (24)
#elif defined SET_3520x1920_DOL_256x_15fps_4lane
#define HDR_BLANK_LINE (14)
#endif

#define MIPI_HBP (24) // 16(LI) + 8(Margin)
#define MIPI_VBP (64) // (10(Ignored OB) + 10(OB) + 4(Ignored) + 8(Margin)) * 2(HDR)
#define MIPI_HFP (8) // 8(Margin)
#define MIPI_VFP (16) // 8(Margin) * 2(HDR)

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3520)
#define SENSOR_HEIGHT (1920)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2626)
#define INIT_LINE_LEN (942) // HMAX = 942
#define MAX_FPS (15)
#define MIN_FPS (1)
#define SENSOR_FRAME_LINES_MAX (39410) // 1 fps

#define T_HS_SETTLE_NS (91) // Not measured
#define T_D_TERM_EN_NS (14) // Not measured
#define T_CLK_SETTLE_NS (135) // Not measured
#define T_CLK_TERM_EN_NS (14) // Not measured
#endif

#define PCLK (74250000) // Note: this PCLK is double of VMAX * HMAX * fps because of HDR
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (1012) // Analog 30 dB
// #define SENSOR_GAIN_MAX (127394) // Analog + Digital 72 dB
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
