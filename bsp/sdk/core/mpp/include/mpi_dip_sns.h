/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_dip_sns.h
 * @brief MPI for DIP sensor
 */

#ifndef MPI_DIP_SNS_H_
#define MPI_DIP_SNS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_dev.h"
#include "mpi_dip_types.h"


#define LVDS_CALIB_FILE "/calib/factory_default/lvds_delay" /**< The file path of LVDS calibration. */
#define MPI_SNS_HDR_MAX_IMAGE_NUM (2) /**< Maximum sub images within a frame under HDR mode. */

/**
 * @brief Enumeration of control bus type.
 */
typedef enum mpi_bus_type {
	BUS_TYPE_I2C, /**< I2C bus. */
	BUS_TYPE_SPI, /**< SPI bus. */
	BUS_TYPE_NUM,
} MPI_BUS_TYPE_E;

/**
 * @brief Enumeration of raw bit width.
 */
typedef enum mpi_bit_width {
	MPI_BITS_16, /**< 16 bits. */
	MPI_BITS_14, /**< 14 bits. */
	MPI_BITS_12, /**< 12 bits. */
	MPI_BITS_10, /**< 10 bits. */
	MPI_BITS_9, /**< 9 bits. */
	MPI_BITS_8, /**< 8 bits. */
	MPI_BITS_7, /**< 7 bits. */
	MPI_BITS_6, /**< 6 bits. */
	MPI_BITS_NUM,
} MPI_BIT_WIDTH_E;

/**
 * @brief Enumeration of raw bit width.
 */
typedef enum mpi_msb_first {
	MPI_LSB_FIRST, /**< Least significant bit first */
	MPI_MSB_FIRST, /**< Most significant bit first */
} MPI_MSB_FIRST_E;

/**
 * @brief Enumeration of LVDS lane type.
 */
typedef enum mpi_lane_type {
	MPI_LANE_TYPE_DATA_0, /**< LVDS data lane 0. */
	MPI_LANE_TYPE_DATA_1, /**< LVDS data lane 1. */
	MPI_LANE_TYPE_DATA_2, /**< LVDS data lane 2. */
	MPI_LANE_TYPE_DATA_3, /**< LVDS data lane 3. */
	MPI_LANE_TYPE_CLOCK, /**< LVDS clock lane. */
	MPI_LANE_TYPE_UNUSED, /**< Unused lane. */
} MPI_LANE_TYPE_E;

/**
 * @brief Enumeration of LVDS lane delay.
 */
typedef enum mpi_lane_delay {
	MPI_LANE_DELAY_0, /**< LVDS lane delay step 0. */
	MPI_LANE_DELAY_1, /**< LVDS lane delay step 1. */
	MPI_LANE_DELAY_2, /**< LVDS lane delay step 2. */
	MPI_LANE_DELAY_3, /**< LVDS lane delay step 3. */
	MPI_LANE_DELAY_4, /**< LVDS lane delay step 4. */
	MPI_LANE_DELAY_5, /**< LVDS lane delay step 5. */
	MPI_LANE_DELAY_6, /**< LVDS lane delay step 6. */
	MPI_LANE_DELAY_7, /**< LVDS lane delay step 7. */
	MPI_LANE_DELAY_8, /**< LVDS lane delay step 8. */
	MPI_LANE_DELAY_9, /**< LVDS lane delay step 9. */
	MPI_LANE_DELAY_10, /**< LVDS lane delay step 10. */
	MPI_LANE_DELAY_11, /**< LVDS lane delay step 11. */
	MPI_LANE_DELAY_12, /**< LVDS lane delay step 12. */
	MPI_LANE_DELAY_13, /**< LVDS lane delay step 13. */
	MPI_LANE_DELAY_14, /**< LVDS lane delay step 14. */
	MPI_LANE_DELAY_15, /**< LVDS lane delay step 15. */
	MPI_LANE_DELAY_16, /**< LVDS lane delay step 16. */
	MPI_LANE_DELAY_17, /**< LVDS lane delay step 17. */
	MPI_LANE_DELAY_18, /**< LVDS lane delay step 18. */
	MPI_LANE_DELAY_19, /**< LVDS lane delay step 19. */
	MPI_LANE_DELAY_20, /**< LVDS lane delay step 20. */
	MPI_LANE_DELAY_21, /**< LVDS lane delay step 21. */
	MPI_LANE_DELAY_22, /**< LVDS lane delay step 22. */
	MPI_LANE_DELAY_23, /**< LVDS lane delay step 23. */
	MPI_LANE_DELAY_24, /**< LVDS lane delay step 24. */
	MPI_LANE_DELAY_25, /**< LVDS lane delay step 25. */
	MPI_LANE_DELAY_26, /**< LVDS lane delay step 26. */
	MPI_LANE_DELAY_27, /**< LVDS lane delay step 27. */
	MPI_LANE_DELAY_28, /**< LVDS lane delay step 28. */
	MPI_LANE_DELAY_29, /**< LVDS lane delay step 29. */
	MPI_LANE_DELAY_30, /**< LVDS lane delay step 30. */
	MPI_LANE_DELAY_31, /**< LVDS lane delay step 31. */
	MPI_LANE_DELAY_NUM,
} MPI_LANE_DELAY_E;

/**
 * @brief Enumeration of termination impedance selection.
 */
typedef enum mpi_impd_sel {
	MPI_IMPD_SEL_ON_CHIP, /**< On chip termination. */
	MPI_IMPD_SEL_OFF_CHIP, /**< Off chip termination. */
} MPI_IMPD_SEL_E;

/**
 * @brief Enumeration of sensor interface protocol.
 */
typedef enum mpi_intf_ptcl {
	MPI_INTF_PTCL_HISPI = 0x0, /**< HiSPI. */
	MPI_INTF_PTCL_SONY_LVDS = 0x1, /**< SONY-LVDS. */
	MPI_INTF_PTCL_PAN_LVDS = 0x2, /**< PANASONIC-LVDS. */
	MPI_INTF_PTCL_MIPI = 0x4, /**< MIPI. */
	MPI_INTF_PTCL_DVP = 0x8, /**< DVP. */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
	MPI_INTF_PTCL_SPIRX = 0x10, /**< SPI-RX. */
	MPI_INTF_PTCL_NUM = 0x1F, /**< The number of interface type. */
#else
	MPI_INTF_PTCL_NUM = 0xF, /**< The number of interface type. */
#endif
} MPI_INTF_PTCL_E;

/**
 * @brief Enumeration of modes of sensor interface protocols.
 */
typedef enum mpi_ptcl_mode {
	MPI_PTCL_MODE_NONE = 0, /**< No specified protocol mode. */
	MPI_MIPI_CSI2 = 0, /**< MIPI CSI2 procotol. */
	MPI_HISPI_PKTZ_SP = 0, /**< HiSPI packtized SP protocol. */
	MPI_HISPI_STRM_SP = 1, /**< HiSPI streaming SP protocol. */
	MPI_HISPI_STRM_S = 2, /**< HiSPI streaming S protocol. */
	MPI_SONY_LVDS_DDR = 2, /**< SONY-LVDS DDR protocol. */
	MPI_PAN_LVDS_DDR = 2, /**< PANASONIC-LVDS DDR protocol. */
} MPI_PTCL_MODE_E;

/**
 * @brief Enumeration of sensor operation mode.
 */
typedef enum mpi_sns_mode {
	MPI_SNS_MODE_MASTER, /**< Sensor master mode. */
	MPI_SNS_MODE_SLAVE, /**< Sensor slave mode. */
	MPI_SNS_MODE_NUM,
} MPI_SNS_MODE_E;

/**
 * @brief Enumeration of sensor slave mode sync signal source.
 */
typedef enum mpi_slv_sync_src {
	MPI_SLV_SYNC_SRC_NONE, /**< Not select any signal source. */
	MPI_SLV_SYNC_SRC_MAIN, /**< Select sync signal from main LVDS. */
	MPI_SLV_SYNC_SRC_SUB, /**< Select sync signal from sub LVDS. */
} MPI_SLV_SYNC_SRC_E;

/**
 * @brief Enumeration of synchronization polarity of sensor interface.
 */
typedef enum mpi_sync_plty {
	MPI_PLTY_HIGH, /**< Polarity high. */
	MPI_PLTY_LOW, /**< Polarity low. */
	MPI_PLTY_NUM,
} MPI_SYNC_PLTY_E;

/**
 * @brief Enumeration of voltage.
 */
typedef enum mpi_volt {
	MPI_VOLT_1P8V, /**< Voltage 1.8V. */
	MPI_VOLT_3P3V, /**< Voltage 3.3V. */
} MPI_VOLT_E;

/**
 * @brief Struct for parallel LVDS lane info.
 */
typedef struct mpi_parl_lane_info {
	MPI_LANE_DELAY_E clock_delay; /**< Clock lane delay. */
} MPI_PARL_LANE_INFO_S;

/**
 * @brief Struct for serial LVDS lane info.
 */
typedef struct mpi_serl_lane_info {
	MPI_LANE_TYPE_E lane_type; /**< LVDS lane type. */
	INT8 lane_idx; /**< LVDS PHY lane index. */
	MPI_LANE_DELAY_E data_delay; /**< Data lane delay. */
	MPI_LANE_DELAY_E clock_delay; /**< Clock lane delay. */
	MPI_IMPD_SEL_E impd_sel; /**< Impedance selection. */
} MPI_SERL_LANE_INFO_S;

/**
 * @brief Struct for the configuration of optical black region.
 */
typedef struct mpi_ob_conf {
	UINT16 skipped_line_num; /**< The number of line with invalid header between OB and image. */
	MPI_POS_E pos; /**< The positon of OB region relative to image. */
	MPI_RECT_S region; /**< OB region info. */
} MPI_OB_CONF_S;

/**
 * @brief Struct for the info of sensor output for DVP interface.
 */
typedef struct mpi_sns_out_dvp {
	MPI_VOLT_E io_volt; /**< Sensor I/O voltage. */
} MPI_SNS_OUT_DVP_S;

/**
 * @brief Struct for the info of sensor output for HiSPI interface.
 */
typedef struct mpi_sns_out_hispi {
	UINT8 flr_enable; /**< Sensor filter code enable bit. */
	UINT8 flr_word_num; /**< Sensor filter code. */
	UINT8 crc_enable; /**< Sensor checksum enable bit. */
	UINT8 idl_enable; /**< Sensor idle period enable bit. */
	UINT16 idl_word; /**< Sensor idle word. */
} MPI_SNS_OUT_HISPI_S;

/**
 * @brief Struct for the info of sensor output for SONY-LVDS interface.
 */
typedef struct mpi_sns_out_sonylvds {
	MPI_PORCH_S bp_img; /**< Back porch of image in sensor output. */
	MPI_PORCH_S fp_img; /**< Front porch of image in sensor output. */
	MPI_OB_CONF_S ob_conf; /**< Optical black configuration. */
} MPI_SNS_OUT_SONYLVDS_S;

/**
 * @brief Struct for the info of sensor output for PANASONIC-LVDS interface.
 */
typedef struct mpi_sns_out_panlvds {
	MPI_PORCH_S bp_img; /**< Back porch of image in sensor output. */
	MPI_PORCH_S fp_img; /**< Front porch of image in sensor output. */
	MPI_OB_CONF_S ob_conf; /**< Optical black configuration. */
} MPI_SNS_OUT_PANLVDS_S;

/**
 * @brief Struct for the info of sensor output for MIPI interface.
 */
typedef struct mpi_sns_out_mipi {
	MPI_PORCH_S bp_img; /**< Back porch of image in sensor output. */
	MPI_PORCH_S fp_img; /**< Front porch of image in sensor output. */
	MPI_PORCH_S bp_eff_pix; /**< Back porch of effective pixel in sensor output. */
	MPI_OB_CONF_S ob_conf; /**< Optical black configuration. */
	UINT32 vc_bmp; /**< Virtual channel bitmap. */
	UINT32 dt_bmp; /**< Bitmap for user data type, bit N is used to enable user data with header 0x3N. */
	UINT32 t_hs_settle; /**< MIPI high speed settle time. (HC1702/HC1752/HC1772/HC1782 only) */
	UINT32 t_hs_settle_ns; /**< MIPI high speed data lane settle time (ns). */
	UINT32 t_d_term_en_ns; /**< MIPI high speed data lane enable termination time (ns). */
	UINT32 t_clk_settle_ns; /**< MIPI high speed clock lane settle time (ns). */
	UINT32 t_clk_term_en_ns; /**< MIPI high speed clock lane enable termination time (ns). */
} MPI_SNS_OUT_MIPI_S;

#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
typedef struct mpi_sns_out_spirx {
	UINT8 wire_count;
	UINT8 sensor_type;
	UINT8 ddr_mode;
	UINT8 clock_polarity;
	MPI_MSB_FIRST_E lsb_msb;
	UINT8 color_format;
	UINT8 clock_mode;
	UINT8 frame_code;
} MPI_SNS_OUT_SPIRX_S;
#endif

/**
 * @struct MPI_SNS_HDR_INFO
 * @brief Struct for characteristics of HDR mode of a sensor is using.
 * @details
 * This structure contains information for the video system to know
 * some of the HDR streaming characteristics that strongly related to
 * the settings of the sensor.
 *
 * @property MPI_SNS_HDR_INFO::image_num
 * @details
 * In range [2, ::MPI_SNS_HDR_MAX_IMAGE_NUM].
 *
 * @property MPI_SNS_HDR_INFO::blank_line_num
 * @details
 * Used in staggered HDR layout to determine the pixel drawing of the whole image.\n
 * blank_line_num is set in order of the incoming sub images.\n
 * Index 0 means the blanking between the first and the second image,\n
 * index 1 represents the second and the third, and so on.
 */
typedef struct mpi_sns_hdr_info {
	UINT32 vc_enable; /**< Virtual channel enable. */
	MPI_HDR_MODE_E hdr_mode; /**< Layout of HDR images. */
	UINT32 image_num; /**< Number of sub images in a frame. */
	UINT32 blank_line_num[MPI_SNS_HDR_MAX_IMAGE_NUM - 1]; /**< Number of time gaps or dummy lines of images. */
} MPI_SNS_HDR_INFO;

/**
 * @brief Struct for the attribute of sensor operation info.
 */
typedef struct mpi_sns_op_info {
	MPI_SNS_MODE_E sensor_mode; /**< Sensor operation mode. */
	MPI_SLV_SYNC_SRC_E slv_sync_src; /**< Slave mode sync signal source. */
	MPI_BIT_WIDTH_E bit_width; /**< Sensor raw bit-width. */
	MPI_MSB_FIRST_E msb_first; /**< Sensor msb first. */
	MPI_PTCL_MODE_E ptcl_mode; /**< Sensor interface protocol mode. */
	MPI_SYNC_PLTY_E hsync_plty; /**< Horizontal sync. polarity. */
	MPI_SYNC_PLTY_E vsync_plty; /**< Vertical sync. polarity. */
	MPI_BAYER_E bayer; /**< Sensor initial Bayer phase. */
	UINT32 ext_clk_freq; /**< Sensor external clock freq. */
	MPI_SIZE_S sensor_res; /**< Sensor output resolution. */
	FLOAT sensor_fps; /**< Sensor output frame rate. */
	INT16 frame_len_line; /**< The number of line per frame. */
	UINT16 i2c_slv_addr; /**< I2C slave address. */
	UINT8 ob_enable; /**< OB region enable bit. */
	UINT8 reserved; /**< Reserved. */

	MPI_PARL_LANE_INFO_S parl_lane; /**< Parallel output lane info. */
	MPI_SERL_LANE_INFO_S serl_lane[MPI_MAX_LVDSRX_LANE_NUM]; /**< Serial output lane info. */

	MPI_INTF_PTCL_E intf_ptcl; /**< Sensor interface protocol. */
	union {
		MPI_SNS_OUT_DVP_S dvp; /**< DVP sensor output. */
		MPI_SNS_OUT_HISPI_S hispi; /**< HiSPI sensor output. */
		MPI_SNS_OUT_SONYLVDS_S sonylvds; /**< SONY-LVDS sensor output. */
		MPI_SNS_OUT_PANLVDS_S panlvds; /**< PANASONIC-LVDS sensor output. */
		MPI_SNS_OUT_MIPI_S mipi; /**< MIPI sensor output. */
#if defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO) || defined(CONFIG_OSAKA)
		MPI_SNS_OUT_SPIRX_S spirx; /**< SPI sensor output.*/
#endif
	};

	MPI_SNS_HDR_INFO hdr; /**< HDR related information. */
} MPI_SNS_OP_INFO_S;

/**
 * @struct MPI_AE_SNS_HDR_INFO_S
 * @brief HDR related sensor exposure information
 *
 * @property MPI_AE_SNS_HDR_INFO_S::image_num
 * @brief Number of sub images in a frame.
 * @details
 * In range [ 2, @link MPI_SNS_HDR_MAX_IMAGE_NUM MPI_SNS_HDR_MAX_IMAGE_NUM @endlink ].
 *
 * @property MPI_AE_SNS_HDR_INFO_S::hdr_inttime_range
 * @brief Exposure time limit of each sub image.
 * @details
 * Provide the minimum and maximum valid exposure time in microsecond of each hdr sub image.
 */
typedef struct mpi_ae_sns_hdr_info {
	UINT32 image_num;
	RANGE_S hdr_inttime_range[MPI_SNS_HDR_MAX_IMAGE_NUM];
} MPI_AE_SNS_HDR_INFO_S;

/**
 * @brief Auto exposure sensor parameters.
 */
typedef struct mpi_ae_sns_default {
	RANGE_S inttime_range; /**< Exposure time. */
	RANGE_S sensor_gain_range; /**< Sensor gain range. */
	RANGE_S target_sys_gain_range; /**< Target system gain range. */
	RANGE_S target_sensor_gain_range; /**< Target sensor gain range. */
	RANGE_S target_isp_gain_range; /**< Target isp gain range. */
	UINT16 gain_thr_up; /**< System gain threshold during automatic drop fps. */
	UINT16 gain_thr_down; /**< System gain threshold during automatic rise fps. */
	FLOAT max_fps; /**< Max frame rate. */
	FLOAT min_fps; /**< Min frame rate. */
	UINT8 speed; /**< Convergence speed. */
	UINT16 tolerance; /**< Brightness tolerance. */
	UINT16 brightness; /**< Target brightness. */
	UINT32 exp_value; /**< Exposure value. */
	MPI_AE_SNS_HDR_INFO_S hdr; /**< HDR related information **/
} MPI_AE_SNS_DEFAULT_S;

/**
 * @brief Effective iso information.
 */
typedef struct mpi_iso_sns_default {
	BOOL is_valid; /**< Valid. */
	INT32 effective_iso[MPI_ISO_LUT_ENTRY_NUM]; /**< effective_iso table of iso = 100~102400. */
} MPI_ISO_SNS_DEFAULT_S;

/**
 * @brief Color temperature information.
 */
typedef struct mpi_awb_color_temp {
	UINT16 k; /**< Color temperature. The value range is [0, 15000]. */
	UINT16 gain[MPI_AWB_CHN_NUM]; /**< Gain of the Gr, R, B,and Gb color channels obtained from AWB algorithm. The value range is [0, 2047].*/
	INT16 matrix[MPI_COLOR_CHN_NUM *
				 MPI_COLOR_CHN_NUM]; /**< Color Correction Matrix. The value range is [-32768, 32767]. */
} MPI_AWB_COLOR_TEMP_S;

/**
 * @brief Difference color temperature gain information.
 */
typedef struct mpi_awb_color_delta {
	INT16 gain[MPI_AWB_CHN_NUM]; /**< Difference gain of the Gr, R, B, and Gb color channels obtained from AWB algorithm. The value range is [-255, 255]. */
} MPI_AWB_COLOR_DELTA_S;

/**
 * @brief Auto white balance sensor parameters.
 */
typedef struct mpi_awb_sns_default {
	MPI_AWB_COLOR_TEMP_S k_table[MPI_K_TABLE_ENTRY_NUM]; /**< Color temperature information. */
	MPI_AWB_COLOR_DELTA_S delta_table[MPI_K_TABLE_ENTRY_NUM]; /**< Difference color gain information. */
} MPI_AWB_SNS_DEFAULT_S;

/**
 * @brief Device black level sensor parameters.
 */
typedef struct mpi_dbc_sns_default {
	UINT16 dbc_level; /**< Device black level value. */
} MPI_DBC_SNS_DEFAULT_S;

/**
 * @brief Lens shadding correction sensor parameters.
 */
typedef struct mpi_lsc_sns_default {
	UINT32 origin; /**< LSC gain at origin. */
	UINT32 x_trend_2s; /**< LSC gain trend in X direction. */
	UINT32 y_trend_2s; /**< LSC gain trend in Y direction. */
	UINT32 x_curvature; /**< LSC gain curvature in X direction. */
	UINT32 y_curvature; /**< LSC gain curvature in Y direction. */
	UINT32 tilt_2s; /**< LSC gain curve tilt extent. */
} MPI_LSC_SNS_DEFAULT_S;

/**
 * @brief Device color correction sensor parameters.
 */
typedef struct mpi_dcc_sns_default {
	UINT16 gain[MPI_DCC_CHN_NUM]; /**< Gain value. */
	UINT16 offset_2s[MPI_DCC_CHN_NUM]; /**< Offset. */
} MPI_DCC_SNS_DEFAULT_S;

/**
 * @brief Sharpness sensor parameters.
 */
typedef struct mpi_shp_sns_default {
	BOOL is_valid; /**< Valid. */
	UINT8 shp_table[MPI_ISO_LUT_ENTRY_NUM]; /**< Sharpness table. */
} MPI_SHP_SNS_DEFAULT_S;

/**
 * @brief Noise reduction sensor parameters.
 */
typedef struct mpi_nr_sns_default {
	BOOL is_valid; /**< Valid. */
	UINT8 y_level_3d[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise reduction 3d luma table. */
	UINT8 c_level_3d[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise reduction 3d chroma table. */
	UINT8 y_level_2d[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise reduction 2d luma table. */
	UINT8 c_level_2d[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise reduction 2d chroma table. */
} MPI_NR_SNS_DEFAULT_S;

/**
 * @brief Color saturation management sensor parameters.
 */
typedef struct mpi_csm_sns_default {
	BOOL is_valid; /**< Valid. */
	UINT8 sat_table[MPI_ISO_LUT_ENTRY_NUM]; /**< Saturation table. */
} MPI_CSM_SNS_DEFAULT_S;

/**
 * @brief Default tone curve.
 */
typedef struct mpi_te_sns_default {
	BOOL is_valid; /**< Valid. */
	UINT32 curve[MPI_TE_CURVE_ENTRY_NUM]; /**< TE curve under normal mode. */
	UINT16 noise_cstr[MPI_ISO_LUT_ENTRY_NUM]; /**< Noise constraint under wdr mode. */
} MPI_TE_SNS_DEFAULT_S;

/**
 * @brief Gamma sensor parameters.
 */
typedef struct mpi_gamma_sns_default {
	UINT8 mode; /**< Gamma mode. */
} MPI_GAMMA_SNS_DEFAULT_S;

/**
 * @brief Defines the structure of DIP sensor parameters.
 */
typedef struct mpi_dip_sns_default {
	MPI_ISO_SNS_DEFAULT_S iso; /**< ISO to effective ISO table. */
	MPI_NR_SNS_DEFAULT_S nr; /**< Noise reduction sensor parameters. */
	MPI_SHP_SNS_DEFAULT_S shp; /**< Sharpness sensor parameters. */
	MPI_CSM_SNS_DEFAULT_S csm; /**< Color saturation management sensor parameters. */
	MPI_GAMMA_SNS_DEFAULT_S gamma; /**< Gamma sensor parameters. */
	MPI_TE_SNS_DEFAULT_S te; /**< Tone enhancement sensor parameters. */
} MPI_DIP_SNS_DEFAULT_S;

/**
 * @brief Defines the structure of CAL sensor parameters.
 */
typedef struct mpi_cal_sns_default {
	MPI_DBC_SNS_DEFAULT_S dbc; /**< Device black level sensor parameters. */
	MPI_DCC_SNS_DEFAULT_S dcc; /**< Device color correction sensor parameters. */
	MPI_LSC_SNS_DEFAULT_S lsc; /**< Lens shadding correction sensor parameters. */
} MPI_CAL_SNS_DEFAULT_S;

/**
 * @brief Defines the structure of Black level table.
 */
typedef struct mpi_black_level_table {
	UINT16 black_level[MPI_SENSOR_GAIN_LUT_ENTRY_NUM]; /**< Black level table by sensor gain. */
} MPI_BLACK_LEVEL_TABLE_S;

/**
 * @brief Sensor I2C message description.
 */
typedef struct mpi_i2c_data {
	BOOL is_update; /**< I2C data changed */
	UINT8 int_pos; /**< intterrupt time 0: frame-start 1: frame-end */
	UINT8 delay_frm_num; /**< Delay how many frame to set */
	UINT8 dev_addr; /**< I2C device address */
	UINT32 reg_addr; /**< I2C client register address */
	UINT32 reg_addr_byte_num; /**< I2C client byte number of register address */
	UINT32 reg_data; /**< Register value */
	UINT32 reg_data_byte_num; /**< Byte number of register value */
} MPI_I2C_DATA_S;

/**
 * @brief SPI message description.
 */
typedef MPI_I2C_DATA_S MPI_SPI_DATA_S;

/**
 * @brief Sensor bus description.
 */
typedef union mpi_ctrl_bus {
	UINT8 i2c_dev; /**< I2C bus index. 0: reserved, 1: I2C0, 2: I2C1 */
/**
 * @brief SPI bus device.
 */
	struct {
		UINT8 dev : 4; /**< SPI bus index */
		UINT8 cs : 4; /**< Reserved. */
	} ssp_dev;
} MPI_CTRL_BUS_S;

/**
 * @brief Structure to record sensor register configuration.
 */
typedef struct mpi_sns_regs_table {
	BOOL is_config; /**< This strucuture has been configured. */
	INT32 reg_num; /**< Total sensor register number. */
	INT32 cfg_delay_max; /**< Max delay after configuration activated. */
	MPI_BUS_TYPE_E bus_type; /**< Sensor bus type. */
	MPI_CTRL_BUS_S bus_sel; /**< Sensor bus information. */
	union {
		MPI_I2C_DATA_S i2c_data[MPI_SNS_TABLE_REGS_NUM]; /**< I2C message array. */
		MPI_SPI_DATA_S spi_data[MPI_SNS_TABLE_REGS_NUM]; /**< SPI message array. */
	};
} MPI_SNS_REGS_TABLE_S;

/**
 * @struct DIP_SNS_CALLBACK_S
 * @brief Structure to record sensor register configuration.
 *
 * @property DIP_SNS_CALLBACK_S::global_init
 * @brief Sensor driver initialization.
 * @details
 * Function pointer to the sensor driver initialization function.\n
 * Is usually implemented in sensor_cmos.c.\n
 * This function will have sensor driver calculate and prepare some variables\n
 * in the sensor driver for proper functioning.
 *
 * @property DIP_SNS_CALLBACK_S::init
 * @brief Sensor initialization.
 * @details
 * Function pointer to the sensor start up function.\n
 * Is usually implemented in sensor_ctrl.c.\n
 * This function write the initial sequence to the sensor,\n
 * and fire up the streaming of it.
 *
 * @property DIP_SNS_CALLBACK_S::exit
 * @brief Sensor termination.
 * @details
 * Function pointer to the sensor stopping function.\n
 * Is usually implemented in sensor_ctrl.c.\n
 * On the contrary of @link DIP_SNS_CALLBACK_S::init init @endlink,\n
 * this function stops the streaming coming out from the sensor.
 *
 * @property DIP_SNS_CALLBACK_S::get_sns_op_info
 * @brief Get sensor operation information.
 * @details
 * Function pointer to the function providing operation information of the sensor.\n
 * Is usually implemented in sensor_ctrl.c.\n
 * This information is crucial for controlling how our system should cooperate with the sensor.
 * @see MPI_SNS_OP_INFO_S
 *
 * @property DIP_SNS_CALLBACK_S::get_dip_default
 * @brief Get DIP default settings and information.
 * @details
 * Function pointer to the function providing default IQ parameters and limits related to the sensor.\n
 * This information is usually written in sensor_cal.h and sensor_cmos.c.\n
 * @see MPI_DIP_SNS_DEFAULT_S
 *
 * @property DIP_SNS_CALLBACK_S::get_regs_info
 * @brief Get sensor register information.
 * @details
 * Function pointer to the function providing information of registers of the sensor.\n
 * Is usually implemented in sensor_cmos.c.\n
 * This function is used to get the required I2C messages to be sent to the sensor
 * for exposure and frame rate controlling.
 */
typedef struct dip_sns_callback {
	VOID (*global_init)(MPI_PATH idx);
	VOID (*init)(UINT8 idx);
	INT32 (*get_sns_op_info)(UINT8 idx, UINT32 sns_idx, MPI_SNS_OP_INFO_S *op_info);
	INT32 (*get_dip_default)(MPI_PATH idx, MPI_DIP_SNS_DEFAULT_S *dft);
	INT32 (*get_regs_info)(MPI_PATH idx, MPI_SNS_REGS_TABLE_S *regs_info);
	VOID (*exit)(UINT8 idx);
} DIP_SNS_CALLBACK_S;

/**
 * @brief Structure to record sensor register configuration.
 */
typedef struct cal_sns_callback {
	INT32(*get_cal_default)(MPI_PATH idx, MPI_CAL_SNS_DEFAULT_S *dft); /**< Pointer to the callback function for getting calibration default. */
	INT32(*get_black_level)(MPI_PATH idx, MPI_DBC_SNS_DEFAULT_S *level); /**< Pointer to the callback function for getting sensor default for black level. */
} CAL_SNS_CALLBACK_S;

/**
 * @struct AE_SNS_CALLBACK_S
 * @brief Structure to record sensor register configuration.
 * @details
 * These members are organized for AE library to get the limitation\n
 * and set the exposure related settings.\n
 * Notice that the "set" functions do NOT directly set the settings to the sensor at the time it's called.\n
 * Instead, the DIP system will fire all of the settings set within a round at the same time later.
 *
 * @property AE_SNS_CALLBACK_S::get_ae_default
 * @brief Get AE default and limitation of the sensor.
 * @details
 * Function pointer to the function providing information crucial to AE library.
 * @see MPI_AE_SNS_DEFAULT_S
 *
 * @property AE_SNS_CALLBACK_S::set_framerate
 * @brief Set sensor framerate.
 * @details
 *
 * @property AE_SNS_CALLBACK_S::set_inttime
 * @brief Set exposure/integration time.
 * @details
 *
 *
 * @property AE_SNS_CALLBACK_S::set_slow_inttime
 * @brief Set exposure/integration time with possibly reducing the frame rate.
 * @details
 *
 *
 * @property AE_SNS_CALLBACK_S::set_sensor_gain
 * @brief Set sensor gain.
 * @details
 *
 *
 * @property AE_SNS_CALLBACK_S::set_inttime_hdr
 * @brief Set exposure/integration time.
 * @details
 *
 *
 * @property AE_SNS_CALLBACK_S::set_slow_inttime_hdr
 * @brief Set exposure/integration time with possibly reducing the frame rate.
 * @details
 *
 *
 * @property AE_SNS_CALLBACK_S::set_sensor_gain_hdr
 * @brief Set sensor gain.
 * @details
 *
 */
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

/**
 * @brief Structure to record sensor register configuration.
 */
typedef struct awb_sns_callback {
	INT32(*get_awb_default)(MPI_PATH idx, MPI_AWB_SNS_DEFAULT_S *dft); /**< Pointer to the callback function for obtaining the initial value of the AE algorithm library. */
} AWB_SNS_CALLBACK_S;

/**
 * @brief Structure to record sensor register configuration.
 */
typedef struct mpi_sns_callback {
	DIP_SNS_CALLBACK_S dip; /**< Defines the sensor callback function for DIP. */
	CAL_SNS_CALLBACK_S cal; /**< Defines the sensor callback function for CAL. */
	AE_SNS_CALLBACK_S ae; /**< Defines the sensor callback function for AE. */
	AWB_SNS_CALLBACK_S awb; /**< Defines the sensor callback function for AWB. */
} MPI_SNS_CALLBACK_S;

/**
 * @brief Structure to decide LVDS delay.
 */
typedef struct serl_lane_delay {
	INT8 clock_delay; /**< Clock delay. */
	INT8 data_delay; /**< Data delay. */
} SERL_LANE_DELAY_S;

/**
 * @brief Structure to decide all LVDS lanes delay.
 */
typedef struct serl_data_lanes_delay {
	SERL_LANE_DELAY_S data[MPI_MAX_DATA_LANE_NUM]; /**< LVDS lanes delay data. */
} SERL_DATA_LANES_DELAY_S;

/* Interface function prototype */
INT32 MPI_regSnsCallback(MPI_PATH idx, INT32 sns_id, const MPI_SNS_CALLBACK_S *p_sns_cb);
INT32 MPI_deregSnsCallback(MPI_PATH idx, INT32 sns_id);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPI_DIP_SNS_H_ */
