/*
 * Configuation settings for hc1703/hc1723/hc1753/hc1783s based products.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __FASTBOOT_COMMON_CONFIG_H
#define __FASTBOOT_COMMON_CONFIG_H

#ifdef CONFIG_FASTBOOT

#ifndef CONFIG_PROD_AGT200_21
#define CONFIG_EARLYVIDEO
#endif

/*
 *
 * Customization
 *
 */

#ifdef CONFIG_PROD_AGT300_26
#define EARLY_VB_SIZE 30
#define EARLY_VIDEO_PATH0_WIDTH 2592
#define EARLY_VIDEO_PATH0_HEIGHT 1944
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT300_26 */

#ifdef CONFIG_PROD_AGT300_25
#define EARLY_VB_SIZE 120
#define EARLY_VIDEO_PATH0_WIDTH 2592
#define EARLY_VIDEO_PATH0_HEIGHT 1944
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT300_25 */

#ifdef CONFIG_PROD_AGT300_29
#define EARLY_VB_SIZE 120
#define EARLY_VIDEO_PATH0_WIDTH 2592
#define EARLY_VIDEO_PATH0_HEIGHT 1944
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT300_29 */

#ifdef CONFIG_PROD_AGT300_22
#define LIGHT_LED_GPIO 15
#define LIGHT_LED_GPIO_ACT_LEVEL 1
#define LIGHT_LED_MODE 0
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 12
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LIGHT_LED_ON_LUX_OFFSET 8
#define LIGHT_SRC sw
#define LOCK_PARAM_TO_SPEED_UP 1
#define LIGHT_SENSOR_TYPE 2
#endif /* CONFIG_PROD_AGT300_22 */

#ifdef CONFIG_PROD_AGT725_3
#define LIGHT_LED_GPIO 15
#define LIGHT_LED_GPIO_ACT_LEVEL 1
#define LIGHT_LED_MODE 0
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 12
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LOCK_PARAM_TO_SPEED_UP 1
#define LIGHT_SENSOR_TYPE 2
#endif /* CONFIG_PROD_AGT725_3 */

#ifdef CONFIG_PROD_AGT725_10
#define LIGHT_LED_GPIO 15
#define LIGHT_LED_GPIO_ACT_LEVEL 1
#define LIGHT_LED_MODE 0
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 12
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LIGHT_LED_ON_LUX_OFFSET 8
#define LIGHT_SRC sw
#define EARLY_VB_SIZE 40
#define LOCK_PARAM_TO_SPEED_UP 0
#define LIGHT_SENSOR_TYPE 2
#define CAMERA_FPS 15
#define FALSE_ALARM_TYPE 1
#define FALSE_ALARM_THRESHOLD 94
#define FALSE_ALARM_SLEEP_TYPE 2
#define FALSE_ALARM_SLEEP_IO 0
#endif /* CONFIG_PROD_AGT725_10 */

#ifdef CONFIG_PROD_AGT300_27
#define LIGHT_LED_GPIO 2
#define LIGHT_LED_GPIO_ACT_LEVEL 1
#define LIGHT_LED_MODE 1
#define IR_CUT_MODE 2
#define IR_CUT_GPIO_1 12
#define IR_CUT_GPIO_2 14
#define IR_FILTER_ENABLE_LEVEL 0x02
#define IR_FILTER_DISABLE_LEVEL 0x01
#define IR_CUT_IDLE_LEVEL 0x00
#define IR_CUT_SWTICH_TIME 30
#define LIGHT_SRC hw
#define EARLY_VB_SIZE 48
#define LIGHT_LED_ON_LUX_OFFSET 0
#define LOCK_PARAM_TO_SPEED_UP 1
#define LIGHT_SENSOR_TYPE 1
#endif /* CONFIG_PROD_AGT300_27 */

#ifdef CONFIG_PROD_AGT300_30
#define LIGHT_LED_GPIO 2
#define LIGHT_LED_GPIO_ACT_LEVEL 1
#define LIGHT_LED_MODE 1
#define IR_CUT_MODE 2
#define IR_CUT_GPIO_1 12
#define IR_CUT_GPIO_2 14
#define IR_FILTER_ENABLE_LEVEL 0x02
#define IR_FILTER_DISABLE_LEVEL 0x01
#define IR_CUT_IDLE_LEVEL 0x00
#define IR_CUT_SWTICH_TIME 30
#define LIGHT_SRC hw
#define EARLY_VB_SIZE 48
#define LIGHT_LED_ON_LUX_OFFSET 0
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT300_30 */

#ifdef CONFIG_PROD_AGT301_20
#define CAMERA_FPS 20
#define CAMERA1_FPS 20
#define EARLY_VB_SIZE 8
#define EARLY_VB_PATH0_SIZE 4
#define EARLY_VB_PATH1_SIZE 4
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define EARLY_VB_PATH1_STRATEGY 1 /* 1: overwrite head when out of block */
#define LIGHT_SRC sw
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT301_20 */

#ifdef CONFIG_PROD_AGT301_21
#define EARLY_VIDEO_PATH0_WIDTH 1280
#define EARLY_VIDEO_PATH0_HEIGHT 720
#define EARLY_VIDEO_PATH1_WIDTH 1280
#define EARLY_VIDEO_PATH1_HEIGHT 720
#define EARLY_VB_SIZE 4
#define EARLY_VB_PATH0_SIZE 2
#define EARLY_VB_PATH1_SIZE 2
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define EARLY_VB_PATH1_STRATEGY 0 /* 0: overwrite tail when out of block */
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT301_21 */

#ifdef CONFIG_PROD_AGT725_2
#define EARLY_VB_SIZE 38
#define EARLY_VB_PATH0_SIZE 34
#define EARLY_VB_PATH1_SIZE 4
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define EARLY_VB_PATH1_STRATEGY 0 /* 1: overwrite head when out of block */
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT725_2 */

#ifdef CONFIG_PROD_AGT300_31
#define EARLY_VB_SIZE 4
#define EARLY_VB_PATH0_SIZE 4
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT300_31 */

#ifdef CONFIG_PROD_AGT706_5
#define EARLY_VIDEO_PATH0_WIDTH 2048
#define EARLY_VIDEO_PATH0_HEIGHT 1536
#define EARLY_VB_SIZE 7
#define EARLY_VB_PATH0_SIZE 7
#define CAMERA_FPS 25
#define LIGHT_SRC sw
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT706_5 */

#ifdef CONFIG_PROD_AGT706_3
#define EARLY_VIDEO_PATH0_WIDTH 2560
#define EARLY_VIDEO_PATH0_HEIGHT 1440
#define EARLY_VB_SIZE 8
#define EARLY_VB_PATH0_SIZE 8
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define CAMERA_FPS 15
#define LIGHT_SRC sw
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 41
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT706_3 */

#ifdef CONFIG_PROD_AGT706_11
#define EARLY_VIDEO_PATH0_WIDTH 1920
#define EARLY_VIDEO_PATH0_HEIGHT 1080
#define EARLY_VB_SIZE 8
#define EARLY_VB_PATH0_SIZE 8
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define CAMERA_FPS 15
#define LIGHT_SRC sw
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 41
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT706_11 */

#ifdef CONFIG_PROD_AGT706_12
#define EARLY_VIDEO_PATH0_WIDTH 1920
#define EARLY_VIDEO_PATH0_HEIGHT 1080
#define EARLY_VB_SIZE 8
#define EARLY_VB_PATH0_SIZE 8
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define CAMERA_FPS 30
#define LIGHT_SRC sw
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT706_12 */

#ifdef CONFIG_PROD_AGT706_13
#define EARLY_VIDEO_PATH0_WIDTH 2560
#define EARLY_VIDEO_PATH0_HEIGHT 1440
#define EARLY_VB_SIZE 8
#define EARLY_VB_PATH0_SIZE 8
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define CAMERA_FPS 15
#define LIGHT_SRC sw
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT706_13 */

#ifdef CONFIG_PROD_AGT301_23
#define CAMERA_FPS 20
#define CAMERA1_FPS 20
#define EARLY_VB_SIZE 9
#define EARLY_VB_PATH0_SIZE 5
#define EARLY_VB_PATH1_SIZE 4
#define EARLY_VB_PATH0_STRATEGY 0 /* 0: overwrite tail when out of block */
#define EARLY_VB_PATH1_STRATEGY 1 /* 1: overwrite head when out of block */
#define LIGHT_SRC sw
#define ALL_SENSOR_SHARE_LUX 1
#define LOCK_PARAM_TO_SPEED_UP 1
#endif /* CONFIG_PROD_AGT301_23 */

#ifdef CONFIG_PROD_AGT726_2
#define EARLY_VIDEO_PATH0_WIDTH 1920
#define EARLY_VIDEO_PATH0_HEIGHT 1080
#define EARLY_VB_SIZE 4
#define EARLY_VB_PATH0_SIZE 4
#define CAMERA_FPS 30
#define LIGHT_SRC sw
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 41
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LOCK_PARAM_TO_SPEED_UP 1
#define CONFIG_EARLYAUDIO
#endif /* CONFIG_PROD_AGT726_2 */

#ifdef CONFIG_PROD_AGT726_10
#define EARLY_VIDEO_PATH0_WIDTH 2592
#define EARLY_VIDEO_PATH0_HEIGHT 1944
#define EARLY_VB_SIZE 15
#define EARLY_VB_PATH0_SIZE 15
#define CAMERA_FPS 25
#define LIGHT_SRC sw
#define IR_CUT_MODE 1
#define IR_CUT_GPIO_1 41
#define IR_FILTER_ENABLE_LEVEL 0x00
#define LOCK_PARAM_TO_SPEED_UP 1
#define CONFIG_EARLYAUDIO
#endif /* CONFIG_PROD_AGT726_8 */

/*
 *
 * Default configurations
 *
 */
#ifndef LIGHT_ADC_CH
#define LIGHT_ADC_CH 2
#endif

#ifndef LIGHT1_ADC_CH
#define LIGHT1_ADC_CH 2
#endif

#ifndef LIGHT_SRC
#define LIGHT_SRC sw
#endif

#ifndef CAMERA_FPS
#define CAMERA_FPS 15
#endif

#ifndef CAMERA1_FPS
#define CAMERA1_FPS 15
#endif

/* 0: Disable, 1: Enable IR cut by default when lux_src=sw */
#ifndef IR_FILTER_DEFAULT_STATUS
#define IR_FILTER_DEFAULT_STATUS 1
#endif

/* Early VB and Early Video */
#ifndef EARLY_VB_SIZE
#define EARLY_VB_SIZE 64
#endif

#ifndef EARLY_VB_PATH0_SIZE
#define EARLY_VB_PATH0_SIZE 0
#endif

#ifndef EARLY_VB_PATH1_SIZE
#define EARLY_VB_PATH1_SIZE 0
#endif

/* 0: overwrite tail, 1: overwrite head when out of block */
#ifndef EARLY_VB_PATH0_STRATEGY
#define EARLY_VB_PATH0_STRATEGY 0
#endif

#ifndef EARLY_VB_PATH1_STRATEGY
#define EARLY_VB_PATH1_STRATEGY 0
#endif

#ifndef EARLY_VB_PATH0_KEEP_NUM
#define EARLY_VB_PATH0_KEEP_NUM 2
#endif

#ifndef EARLY_VB_PATH1_KEEP_NUM
#define EARLY_VB_PATH1_KEEP_NUM 2
#endif

#ifndef EARLY_VIDEO_PATH0_WIDTH
#define EARLY_VIDEO_PATH0_WIDTH 1920
#endif

#ifndef EARLY_VIDEO_PATH0_HEIGHT
#define EARLY_VIDEO_PATH0_HEIGHT 1080
#endif

#ifndef EARLY_VIDEO_PATH1_WIDTH
#define EARLY_VIDEO_PATH1_WIDTH 1920
#endif

#ifndef EARLY_VIDEO_PATH1_HEIGHT
#define EARLY_VIDEO_PATH1_HEIGHT 1080
#endif

#ifndef UBOOT_CAPTURE_DURATION
#define UBOOT_CAPTURE_DURATION 550
#endif

#ifndef UBOOT_DROP_NUM
#define UBOOT_DROP_NUM 2
#endif

#ifndef LIGHT_LED_ON_THRESHOLD
#define LIGHT_LED_ON_THRESHOLD 100
#endif

#ifndef LIGHT_LED_ON_LUX_OFFSET
#define LIGHT_LED_ON_LUX_OFFSET 9
#endif

/* Early Audio */
#ifndef EARLY_AUDIO_BEFORE_VIDEO
#define EARLY_AUDIO_BEFORE_VIDEO 0
#endif

#ifndef EARLY_AUDIO_BUF_KB
#define EARLY_AUDIO_BUF_KB 256
#endif

/* 0:adc, 1:pdm, 2:i2s */
#ifndef EARLY_AUDIO_INTERFACE
#define EARLY_AUDIO_INTERFACE 0
#endif

#ifndef EARLY_AUDIO_CHANNELS
#define EARLY_AUDIO_CHANNELS 1
#endif

#ifndef EARLY_AUDIO_RATE
#define EARLY_AUDIO_RATE 8000
#endif

/* 0:s16le, 1:s32le */
#ifndef EARLY_AUDIO_FORMAT
#define EARLY_AUDIO_FORMAT 0
#endif

/* 0: +30dB, 1: +36dB, 2: +42dB */
#ifndef EARLY_AUDIO_ANALOG_GAIN
#define EARLY_AUDIO_ANALOG_GAIN 0
#endif
/* This parameter is deprecated and will be removed in a future release */
#undef ALL_SENSOR_SHARE_LUX
#define ALL_SENSOR_SHARE_LUX 0

#ifndef LOCK_PARAM_TO_SPEED_UP
#define LOCK_PARAM_TO_SPEED_UP 0
#endif

/* 1: AGT300_27 light sensor, 2: AGT300_22 light sensor */
#ifndef LIGHT_SENSOR_TYPE
#define LIGHT_SENSOR_TYPE 1
#endif

#ifdef CONFIG_AMP
#ifndef FALSE_ALARM_TYPE
#define FALSE_ALARM_TYPE 0
#endif

#ifndef FALSE_ALARM_THRESHOLD
#define FALSE_ALARM_THRESHOLD 50
#endif

#ifndef FALSE_ALARM_SLEEP_TYPE
#define FALSE_ALARM_SLEEP_TYPE 0
#endif

#ifndef FALSE_ALARM_SLEEP_IO
#define FALSE_ALARM_SLEEP_IO 0
#endif

#ifndef FALSE_ALARM_FRAME_NUM
#define FALSE_ALARM_FRAME_NUM 3
#endif

#ifndef FALSE_ALARM_DEBUG
#define FALSE_ALARM_DEBUG 0
#endif
#endif /* CONFIG_AMP */

#ifndef EARLY_AE_DROP_NUM
#define EARLY_AE_DROP_NUM 0
#endif

/* clang-format off */
/*
 *
 * Environment parameter processing
 *
 */
#define EARLY_VIDEO_PAR							\
	"early_vb_size="TO_STR(EARLY_VB_SIZE)"\0"			\
	"early_vb_path0_size="TO_STR(EARLY_VB_PATH0_SIZE)"\0"		\
	"early_vb_path1_size="TO_STR(EARLY_VB_PATH1_SIZE)"\0"		\
	"early_vb_path0_strategy="TO_STR(EARLY_VB_PATH0_STRATEGY)"\0"	\
	"early_vb_path1_strategy="TO_STR(EARLY_VB_PATH1_STRATEGY)"\0"	\
	"early_vb_path0_keep_num="TO_STR(EARLY_VB_PATH0_KEEP_NUM)"\0"	\
	"early_vb_path1_keep_num="TO_STR(EARLY_VB_PATH1_KEEP_NUM)"\0"	\
	"path0_width="TO_STR(EARLY_VIDEO_PATH0_WIDTH)"\0"		\
	"path0_height="TO_STR(EARLY_VIDEO_PATH0_HEIGHT)"\0"		\
	"path1_width="TO_STR(EARLY_VIDEO_PATH1_WIDTH)"\0"		\
	"path1_height="TO_STR(EARLY_VIDEO_PATH1_HEIGHT)"\0"		\
	"uboot_capture_duration="TO_STR(UBOOT_CAPTURE_DURATION)"\0"	\
	"uboot_drop_num="TO_STR(UBOOT_DROP_NUM)"\0"
#define EARLY_VIDEO_ARG \
	"early_vb_memaddr=${early_vb_memaddr} early_vb_size=${early_vb_size} early_vb_path0_strategy=${early_vb_path0_strategy} early_vb_path1_strategy=${early_vb_path1_strategy} "

#ifdef CONFIG_AMP
#define EARLY_AMP_PAR \
	"fal_alarm_type="TO_STR(FALSE_ALARM_TYPE)"\0"		\
	"fal_alarm_thre="TO_STR(FALSE_ALARM_THRESHOLD)"\0"	\
	"fal_alarm_frame_num="TO_STR(FALSE_ALARM_FRAME_NUM)"\0"     \
	"fal_alarm_debug="TO_STR(FALSE_ALARM_DEBUG)"\0"
#define EARLY_AMP_ARG "fal_alarm_debug=${fal_alarm_debug} "
#else
#define EARLY_AMP_PAR
#define EARLY_AMP_ARG
#endif

#ifdef CONFIG_DUAL_SENSOR_SUPPORT
#define DUAL_SENSOR_PAR "camera_fps_1="TO_STR(CAMERA1_FPS)"\0"
#define DUAL_SENSOR_ARG
#else
#define DUAL_SENSOR_PAR
#define DUAL_SENSOR_ARG
#endif /* CONFIG_DUAL_SENSOR_SUPPORT */

#ifdef CONFIG_EARLYAUDIO
#define EARLY_AUDIO_PAR \
	"early_audio_interface="TO_STR(EARLY_AUDIO_INTERFACE)"\0" \
	"early_audio_channels="TO_STR(EARLY_AUDIO_CHANNELS)"\0" \
	"early_audio_rate="TO_STR(EARLY_AUDIO_RATE)"\0" \
	"early_audio_format="TO_STR(EARLY_AUDIO_FORMAT)"\0" \
	"early_audio_analog_gain="TO_STR(EARLY_AUDIO_ANALOG_GAIN)"\0"
#define EARLY_AUDIO_ARG \
	"early_audio_buf_addr=${early_audio_buf_addr} early_audio_buf_kb=${early_audio_buf_kb} "
#else
#define EARLY_AUDIO_PAR
#define EARLY_AUDIO_ARG
#endif

#define FASTBOOT_PAR						\
	"camera_fps="TO_STR(CAMERA_FPS)"\0"			\
	"lux_src="TO_STR(LIGHT_SRC)"\0"				\
	"led_on_thre="TO_STR(LIGHT_LED_ON_THRESHOLD)"\0"	\
	"led_on_offset="TO_STR(LIGHT_LED_ON_LUX_OFFSET)"\0"	\
	"early_ae_drop_num="TO_STR(EARLY_AE_DROP_NUM)"\0"	\
	EARLY_VIDEO_PAR						\
	EARLY_AMP_PAR						\
	DUAL_SENSOR_PAR \
	EARLY_AUDIO_PAR

#define FASTBOOT_ARG EARLY_VIDEO_ARG EARLY_AUDIO_ARG EARLY_AMP_ARG DUAL_SENSOR_ARG

/* Define a callback handler for bootargs */
#define CONFIG_ENV_CALLBACK_LIST_DEFAULT "bootargs:bootargs_h"

#else /* !CONFIG_FASTBOOT */

#define FASTBOOT_PAR
#define FASTBOOT_ARG

#endif /* CONFIG_FASTBOOT*/
/* clang-format on */

#endif /*__FASTBOOT_COMMON_CONFIG_H*/
