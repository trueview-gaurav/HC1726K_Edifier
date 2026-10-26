/*
 * mpi_dip_sns.h: A copy of mpp/include/mpi_dip_sns.h without redundant headers/functions for uboot.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_MPI_DIP_SNS_H_
#define UBOOT_MPI_DIP_SNS_H_

#include "mpi_dev.h"
#include "mpi_dip_types.h"

#define LVDS_CALIB_FILE "/calib/factory_default/lvds_delay"
#define MPI_SNS_HDR_MAX_IMAGE_NUM (2)

typedef enum mpi_bus_type {
	BUS_TYPE_I2C,
	BUS_TYPE_SPI,
	BUS_TYPE_NUM,
} MPI_BUS_TYPE_E;

typedef enum mpi_bit_width {
	MPI_BITS_16,
	MPI_BITS_14,
	MPI_BITS_12,
	MPI_BITS_10,
	MPI_BITS_9,
	MPI_BITS_8,
	MPI_BITS_7,
	MPI_BITS_6,
	MPI_BITS_NUM,
} MPI_BIT_WIDTH_E;

typedef enum mpi_msb_first {
	MPI_LSB_FIRST,
	MPI_MSB_FIRST,
} MPI_MSB_FIRST_E;

typedef enum mpi_lane_type {
	MPI_LANE_TYPE_DATA_0,
	MPI_LANE_TYPE_DATA_1,
	MPI_LANE_TYPE_DATA_2,
	MPI_LANE_TYPE_DATA_3,
	MPI_LANE_TYPE_CLOCK,
	MPI_LANE_TYPE_UNUSED,
} MPI_LANE_TYPE_E;

typedef enum mpi_lane_delay {
	MPI_LANE_DELAY_0,
	MPI_LANE_DELAY_1,
	MPI_LANE_DELAY_2,
	MPI_LANE_DELAY_3,
	MPI_LANE_DELAY_4,
	MPI_LANE_DELAY_5,
	MPI_LANE_DELAY_6,
	MPI_LANE_DELAY_7,
	MPI_LANE_DELAY_8,
	MPI_LANE_DELAY_9,
	MPI_LANE_DELAY_10,
	MPI_LANE_DELAY_11,
	MPI_LANE_DELAY_12,
	MPI_LANE_DELAY_13,
	MPI_LANE_DELAY_14,
	MPI_LANE_DELAY_15,
	MPI_LANE_DELAY_16,
	MPI_LANE_DELAY_17,
	MPI_LANE_DELAY_18,
	MPI_LANE_DELAY_19,
	MPI_LANE_DELAY_20,
	MPI_LANE_DELAY_21,
	MPI_LANE_DELAY_22,
	MPI_LANE_DELAY_23,
	MPI_LANE_DELAY_24,
	MPI_LANE_DELAY_25,
	MPI_LANE_DELAY_26,
	MPI_LANE_DELAY_27,
	MPI_LANE_DELAY_28,
	MPI_LANE_DELAY_29,
	MPI_LANE_DELAY_30,
	MPI_LANE_DELAY_31,
	MPI_LANE_DELAY_NUM,
} MPI_LANE_DELAY_E;

typedef enum mpi_impd_sel {
	MPI_IMPD_SEL_ON_CHIP,
	MPI_IMPD_SEL_OFF_CHIP,
} MPI_IMPD_SEL_E;

typedef enum mpi_intf_ptcl {
	MPI_INTF_PTCL_HISPI = 0x0,
	MPI_INTF_PTCL_SONY_LVDS = 0x1,
	MPI_INTF_PTCL_PAN_LVDS = 0x2,
	MPI_INTF_PTCL_MIPI = 0x4,
	MPI_INTF_PTCL_DVP = 0x8,
	MPI_INTF_PTCL_NUM = 0xF,
} MPI_INTF_PTCL_E;

typedef enum mpi_ptcl_mode {
	MPI_PTCL_MODE_NONE = 0,
	MPI_MIPI_CSI2 = 0,
	MPI_HISPI_PKTZ_SP = 0,
	MPI_HISPI_STRM_SP = 1,
	MPI_HISPI_STRM_S = 2,
	MPI_SONY_LVDS_DDR = 2,
	MPI_PAN_LVDS_DDR = 2,
} MPI_PTCL_MODE_E;

typedef enum mpi_sns_mode {
	MPI_SNS_MODE_MASTER,
	MPI_SNS_MODE_SLAVE,
	MPI_SNS_MODE_NUM,
} MPI_SNS_MODE_E;

typedef enum mpi_slv_sync_src {
	MPI_SLV_SYNC_SRC_NONE,
	MPI_SLV_SYNC_SRC_MAIN,
	MPI_SLV_SYNC_SRC_SUB,
} MPI_SLV_SYNC_SRC_E;

typedef enum mpi_sync_plty {
	MPI_PLTY_HIGH,
	MPI_PLTY_LOW,
	MPI_PLTY_NUM,
} MPI_SYNC_PLTY_E;

typedef enum mpi_volt {
	MPI_VOLT_1P8V,
	MPI_VOLT_3P3V,
} MPI_VOLT_E;

typedef struct mpi_parl_lane_info {
	MPI_LANE_DELAY_E clock_delay;
} MPI_PARL_LANE_INFO_S;

typedef struct mpi_serl_lane_info {
	MPI_LANE_TYPE_E lane_type;
	INT8 lane_idx;
	MPI_LANE_DELAY_E data_delay;
	MPI_LANE_DELAY_E clock_delay;
	MPI_IMPD_SEL_E impd_sel;
} MPI_SERL_LANE_INFO_S;

typedef struct mpi_ob_conf {
	UINT16 skipped_line_num;
	MPI_POS_E pos;
	MPI_RECT_S region;
} MPI_OB_CONF_S;

typedef struct mpi_sns_out_dvp {
	MPI_VOLT_E io_volt;
} MPI_SNS_OUT_DVP_S;

typedef struct mpi_sns_out_hispi {
	UINT8 flr_enable;
	UINT8 flr_word_num;
	UINT8 crc_enable;
	UINT8 idl_enable;
	UINT16 idl_word;
} MPI_SNS_OUT_HISPI_S;

typedef struct mpi_sns_out_sonylvds {
	MPI_PORCH_S bp_img;
	MPI_PORCH_S fp_img;
	MPI_OB_CONF_S ob_conf;
} MPI_SNS_OUT_SONYLVDS_S;

typedef struct mpi_sns_out_panlvds {
	MPI_PORCH_S bp_img;
	MPI_PORCH_S fp_img;
	MPI_OB_CONF_S ob_conf;
} MPI_SNS_OUT_PANLVDS_S;

typedef struct mpi_sns_out_mipi {
	MPI_PORCH_S bp_img;
	MPI_PORCH_S fp_img;
	MPI_PORCH_S bp_eff_pix;
	MPI_OB_CONF_S ob_conf;
	UINT32 vc_bmp;
	UINT32 dt_bmp;
	UINT32 t_hs_settle;
	UINT32 t_hs_settle_ns;
	UINT32 t_d_term_en_ns;
	UINT32 t_clk_settle_ns;
	UINT32 t_clk_term_en_ns;

} MPI_SNS_OUT_MIPI_S;

typedef struct mpi_sns_hdr_info {
	UINT32 vc_enable;
	MPI_HDR_MODE_E hdr_mode;
	UINT32 image_num;
	UINT32 blank_line_num[MPI_SNS_HDR_MAX_IMAGE_NUM - 1];
} MPI_SNS_HDR_INFO;

typedef struct mpi_sns_op_info {
	MPI_SNS_MODE_E sensor_mode;
	MPI_SLV_SYNC_SRC_E slv_sync_src;
	MPI_BIT_WIDTH_E bit_width;
	MPI_MSB_FIRST_E msb_first;
	MPI_PTCL_MODE_E ptcl_mode;
	MPI_SYNC_PLTY_E hsync_plty;
	MPI_SYNC_PLTY_E vsync_plty;
	MPI_BAYER_E bayer;
	UINT32 ext_clk_freq;
	MPI_SIZE_S sensor_res;
	FLOAT sensor_fps;
	INT16 frame_len_line;
	UINT16 i2c_slv_addr;
	UINT8 ob_enable;
	UINT8 reserved;

	MPI_PARL_LANE_INFO_S parl_lane;
	MPI_SERL_LANE_INFO_S serl_lane[MPI_MAX_LVDSRX_LANE_NUM];

	MPI_INTF_PTCL_E intf_ptcl;
	union {
		MPI_SNS_OUT_DVP_S dvp;
		MPI_SNS_OUT_HISPI_S hispi;
		MPI_SNS_OUT_SONYLVDS_S sonylvds;
		MPI_SNS_OUT_PANLVDS_S panlvds;
		MPI_SNS_OUT_MIPI_S mipi;
	};

	MPI_SNS_HDR_INFO hdr;
} MPI_SNS_OP_INFO_S;

typedef struct mpi_ae_sns_hdr_info {
	UINT32 image_num;
	RANGE_S hdr_inttime_range[MPI_SNS_HDR_MAX_IMAGE_NUM];
} MPI_AE_SNS_HDR_INFO_S;

typedef struct mpi_ae_sns_default {
	RANGE_S inttime_range;
	RANGE_S sensor_gain_range;
	RANGE_S target_sys_gain_range;
	RANGE_S target_sensor_gain_range;
	RANGE_S target_isp_gain_range;
	UINT16 gain_thr_up;
	UINT16 gain_thr_down;
	FLOAT max_fps;
	FLOAT min_fps;
	UINT8 speed;
	UINT16 tolerance;
	UINT16 brightness;
	UINT32 exp_value;
	MPI_AE_SNS_HDR_INFO_S hdr;
} MPI_AE_SNS_DEFAULT_S;

typedef struct mpi_iso_sns_default {
	BOOL is_valid;
	INT32 effective_iso[MPI_ISO_LUT_ENTRY_NUM];
} MPI_ISO_SNS_DEFAULT_S;

typedef struct mpi_awb_color_temp {
	UINT16 k;
	UINT16 gain[MPI_AWB_CHN_NUM];
	INT16 matrix[MPI_COLOR_CHN_NUM * MPI_COLOR_CHN_NUM];
} MPI_AWB_COLOR_TEMP_S;

typedef struct mpi_awb_color_delta {
	INT16 gain[MPI_AWB_CHN_NUM];
} MPI_AWB_COLOR_DELTA_S;

typedef struct mpi_awb_sns_default {
	MPI_AWB_COLOR_TEMP_S k_table[MPI_K_TABLE_ENTRY_NUM];
	MPI_AWB_COLOR_DELTA_S delta_table[MPI_K_TABLE_ENTRY_NUM];
} MPI_AWB_SNS_DEFAULT_S;

typedef struct mpi_dbc_sns_default {
	UINT16 dbc_level;
} MPI_DBC_SNS_DEFAULT_S;

typedef struct mpi_lsc_sns_default {
	UINT32 origin;
	UINT32 x_trend_2s;
	UINT32 y_trend_2s;
	UINT32 x_curvature;
	UINT32 y_curvature;
	UINT32 tilt_2s;
} MPI_LSC_SNS_DEFAULT_S;

typedef struct mpi_dcc_sns_default {
	UINT16 gain[MPI_DCC_CHN_NUM];
	UINT16 offset_2s[MPI_DCC_CHN_NUM];
} MPI_DCC_SNS_DEFAULT_S;

typedef struct mpi_shp_sns_default {
	BOOL is_valid;
	UINT8 shp_table[MPI_ISO_LUT_ENTRY_NUM];
} MPI_SHP_SNS_DEFAULT_S;

typedef struct mpi_nr_sns_default {
	BOOL is_valid;
	UINT8 y_level_3d[MPI_ISO_LUT_ENTRY_NUM];
	UINT8 c_level_3d[MPI_ISO_LUT_ENTRY_NUM];
	UINT8 y_level_2d[MPI_ISO_LUT_ENTRY_NUM];
	UINT8 c_level_2d[MPI_ISO_LUT_ENTRY_NUM];
} MPI_NR_SNS_DEFAULT_S;

typedef struct mpi_csm_sns_default {
	BOOL is_valid;
	UINT8 sat_table[MPI_ISO_LUT_ENTRY_NUM];
} MPI_CSM_SNS_DEFAULT_S;

typedef struct mpi_te_sns_default {
	BOOL is_valid;
	UINT32 curve[MPI_TE_CURVE_ENTRY_NUM];
	UINT16 noise_cstr[MPI_ISO_LUT_ENTRY_NUM];
} MPI_TE_SNS_DEFAULT_S;

typedef struct mpi_gamma_sns_default {
	UINT8 mode;
} MPI_GAMMA_SNS_DEFAULT_S;

typedef struct mpi_dip_sns_default {
	MPI_ISO_SNS_DEFAULT_S iso;
	MPI_NR_SNS_DEFAULT_S nr;
	MPI_SHP_SNS_DEFAULT_S shp;
	MPI_CSM_SNS_DEFAULT_S csm;
	MPI_GAMMA_SNS_DEFAULT_S gamma;
	MPI_TE_SNS_DEFAULT_S te;
} MPI_DIP_SNS_DEFAULT_S;

typedef struct mpi_cal_sns_default {
	MPI_DBC_SNS_DEFAULT_S dbc;
	MPI_DCC_SNS_DEFAULT_S dcc;
	MPI_LSC_SNS_DEFAULT_S lsc;
} MPI_CAL_SNS_DEFAULT_S;

typedef struct mpi_black_level_table {
	UINT16 black_level[MPI_SENSOR_GAIN_LUT_ENTRY_NUM];
} MPI_BLACK_LEVEL_TABLE_S;

typedef struct mpi_i2c_data {
	BOOL is_update;
	UINT8 int_pos;
	UINT8 delay_frm_num;
	UINT8 dev_addr;
	UINT32 reg_addr;
	UINT32 reg_addr_byte_num;
	UINT32 reg_data;
	UINT32 reg_data_byte_num;
} MPI_I2C_DATA_S;

typedef MPI_I2C_DATA_S MPI_SPI_DATA_S;

typedef union mpi_ctrl_bus {
	UINT8 i2c_dev;

	struct {
		UINT8 dev : 4;
		UINT8 cs : 4;
	} ssp_dev;
} MPI_CTRL_BUS_S;

typedef struct mpi_sns_regs_table {
	BOOL is_config;
	INT32 reg_num;
	INT32 cfg_delay_max;
	MPI_BUS_TYPE_E bus_type;
	MPI_CTRL_BUS_S bus_sel;
	union {
		MPI_I2C_DATA_S i2c_data[MPI_SNS_TABLE_REGS_NUM];
		MPI_SPI_DATA_S spi_data[MPI_SNS_TABLE_REGS_NUM];
	};
} MPI_SNS_REGS_TABLE_S;

typedef struct dip_sns_callback {
	VOID (*global_init)(MPI_PATH idx);
	VOID (*init)(UINT8 idx);
	INT32 (*get_sns_op_info)(UINT8 idx, UINT32 sns_idx, MPI_SNS_OP_INFO_S *op_info);
	INT32 (*get_dip_default)(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft);
	INT32 (*get_regs_info)(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs_info);
	VOID (*exit)(UINT8 idx);
} DIP_SNS_CALLBACK_S;

typedef struct cal_sns_callback {
	INT32 (*get_cal_default)(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *dft);
	INT32 (*get_black_level)(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level);
} CAL_SNS_CALLBACK_S;

typedef struct ae_sns_callback {
	INT32 (*get_ae_default)(MPI_PATH idx, MPI_AE_SNS_DEFAULT_S *dft);
	INT32 (*set_framerate)(MPI_PATH idx, FLOAT fps, RANGE_S *time_range);
	INT32 (*set_inttime)(MPI_PATH idx, UINT32 time_us, UINT32 *effective_time);
	INT32 (*set_slow_inttime)(MPI_PATH idx, UINT32 period_us, FLOAT *fps);
	INT32 (*set_sensor_gain)(MPI_PATH idx, UINT32 gain);
	INT32 (*set_inttime_hdr)(MPI_PATH idx, UINT32 image_idx, UINT32 time_us, UINT32 *effective_time);
	INT32 (*set_slow_inttime_hdr)(MPI_PATH idx, UINT32 image_idx, UINT32 period_us, FLOAT *fps);
	INT32 (*set_sensor_gain_hdr)(MPI_PATH idx, UINT32 image_idx, UINT32 gain);
} AE_SNS_CALLBACK_S;

typedef struct awb_sns_callback {
	INT32 (*get_awb_default)(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *dft);
} AWB_SNS_CALLBACK_S;

typedef struct mpi_sns_callback {
	DIP_SNS_CALLBACK_S dip;
	CAL_SNS_CALLBACK_S cal;
	AE_SNS_CALLBACK_S ae;
	AWB_SNS_CALLBACK_S awb;
} MPI_SNS_CALLBACK_S;

typedef struct serl_lane_delay {
	INT8 clock_delay;
	INT8 data_delay;
} SERL_LANE_DELAY_S;

typedef struct serl_data_lanes_delay {
	SERL_LANE_DELAY_S data[MPI_MAX_DATA_LANE_NUM];
} SERL_DATA_LANES_DELAY_S;

INT32 MPI_regSnsCallback(MPI_PATH idx, INT32 sns_id, const MPI_SNS_CALLBACK_S *p_sns_cb);
INT32 MPI_deregSnsCallback(MPI_PATH idx, INT32 sns_id);

#endif
