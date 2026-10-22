
#ifndef UBOOT_IS_SETTING_H_
#define UBOOT_IS_SETTING_H_

#define BSP_Y_HIST_ENTRY_NUM (60)

/* cpvs bsp.h */
typedef struct is_bsp_y_hist_roi_stat {
	uint8_t overflow;
	uint32_t hist[BSP_Y_HIST_ENTRY_NUM];
} IsBspYHistRoiStat;

typedef struct is_bsp_y_avg_roi_stat {
	uint16_t avg;
	uint32_t remainder;
} IsBspYAvgRoiStat;

/* cpvs dbc.h */
typedef enum cfa_phase {
	CFA_PHASE_G0 = 0, // GR
	CFA_PHASE_R,
	CFA_PHASE_B,
	CFA_PHASE_G1, // GB
	CFA_PHASE_S,
	CFA_PHASE_NUM,
} CfaPhase;

typedef enum is_dbc_mode {
	IS_DBC_MODE_NORMAL = 0,
	IS_DBC_MODE_DISABLE = 1,
	IS_DBC_MODE_NUM = 2,
} IsDbcMode;

typedef struct is_dbc_cfg {
	enum is_dbc_mode mode;
	uint16_t level[CFA_PHASE_NUM];
} IsDbcCfg;

typedef enum is_pixel_format_i {
	IS_PIXEL_FORMAT_I_BAYER = 0,
	IS_PIXEL_FORMAT_I_CFA22 = 1,
	IS_PIXEL_FORMAT_I_CFA44 = 2,
	IS_PIXEL_FORMAT_I_NUM = 3,
} IsPixelFormatI;

typedef enum ini_bayer_phase {
	INI_BAYER_PHASE_G0 = 0, // GR
	INI_BAYER_PHASE_R,
	INI_BAYER_PHASE_B,
	INI_BAYER_PHASE_G1, // GB
	INI_BAYER_PHASE_NUM,
} IniBayerPhase;

#define CFA_PHASE_ENTRY_NUM (16)

typedef struct is_input_format {
	enum is_pixel_format_i mode;
	enum ini_bayer_phase bayer;
	enum cfa_phase cfa[CFA_PHASE_ENTRY_NUM];
} IsInputFormat;

/* cpvs dcc.h */

typedef enum is_dcc_mode {
	IS_DCC_MODE_NORMAL = 0,
	IS_DCC_MODE_DISABLE = 1,
	IS_DCC_MODE_NUM = 2,
} IsDccMode;

typedef struct is_dcc_cfg {
	enum is_dcc_mode mode;
	uint32_t gain[CFA_PHASE_NUM];
	uint32_t offset_2s[CFA_PHASE_NUM];
} IsDccCfg;

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
#define DCC_GAIN_CURVE_CTRL_POINT_NUM (17)
typedef struct is_dcc_gain_curve_cfg {
	uint16_t y[DCC_GAIN_CURVE_CTRL_POINT_NUM]; /**< Curve value */
} IsDccGainCurveCfg;
#else
#define DCC_GAIN_CURVE_CTRL_POINT_NUM (9)
typedef struct is_dcc_gain_curve_cfg {
	uint16_t x[DCC_GAIN_CURVE_CTRL_POINT_NUM]; /**< Curve bin */
	uint8_t m[DCC_GAIN_CURVE_CTRL_POINT_NUM - 1]; /**< Curve slpoe */
	uint16_t y[DCC_GAIN_CURVE_CTRL_POINT_NUM]; /**< Curve value */
} IsDccGainCurveCfg;
#endif

#endif
