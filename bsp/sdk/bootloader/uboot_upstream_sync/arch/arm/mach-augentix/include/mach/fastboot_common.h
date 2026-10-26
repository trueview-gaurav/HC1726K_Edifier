/*
 * Configuation settings for hc1703/hc1723/hc1753/hc1783s based products.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __FASTBOOT_COMMON_CONFIG_H
#define __FASTBOOT_COMMON_CONFIG_H

#ifndef __ASSEMBLY__
extern unsigned long agtx_fb_base;
extern unsigned long agtx_audio_base;

int agtx_gpio_output(unsigned int gpio, int value);
int agtx_gpio_input(unsigned int gpio);
#ifndef AGTX_GPIO_HELPER_IMPL
/* DM gpio needs a request first; the migrated callers predate that */
#define gpio_direction_output(gpio, value) agtx_gpio_output(gpio, value)
#define gpio_set_value(gpio, value) agtx_gpio_output(gpio, value)
#define gpio_direction_input(gpio) agtx_gpio_input(gpio)
#endif
#endif

#define TO_STR_HELPER(x) #x
#define TO_STR(x) TO_STR_HELPER(x)

/* Per-product values, stated by the product defconfig */
#define EARLY_VIDEO_PATH0_WIDTH CONFIG_AUGENTIX_EARLY_VIDEO_PATH0_WIDTH
#define EARLY_VIDEO_PATH0_HEIGHT CONFIG_AUGENTIX_EARLY_VIDEO_PATH0_HEIGHT
#define EARLY_VIDEO_PATH1_WIDTH CONFIG_AUGENTIX_EARLY_VIDEO_PATH1_WIDTH
#define EARLY_VIDEO_PATH1_HEIGHT CONFIG_AUGENTIX_EARLY_VIDEO_PATH1_HEIGHT
#define EARLY_VB_SIZE CONFIG_AUGENTIX_EARLY_VB_SIZE
#define EARLY_VB_PATH0_SIZE CONFIG_AUGENTIX_EARLY_VB_PATH0_SIZE
#define EARLY_VB_PATH1_SIZE CONFIG_AUGENTIX_EARLY_VB_PATH1_SIZE
#define CAMERA_FPS CONFIG_AUGENTIX_CAMERA_FPS
#define IR_CUT_MODE CONFIG_AUGENTIX_IR_CUT_MODE
#define IR_CUT_GPIO_1 CONFIG_AUGENTIX_IR_CUT_GPIO_1
#define IR_FILTER_ENABLE_LEVEL CONFIG_AUGENTIX_IR_FILTER_ENABLE_LEVEL
#define LIGHT_SENSOR_TYPE CONFIG_AUGENTIX_LIGHT_SENSOR_TYPE

#if CONFIG_AUGENTIX_IR_CUT_GPIO_2 >= 0
#define IR_CUT_GPIO_2 CONFIG_AUGENTIX_IR_CUT_GPIO_2
#endif

#if CONFIG_AUGENTIX_LIGHT_LED_GPIO >= 0
#define LIGHT_LED_GPIO CONFIG_AUGENTIX_LIGHT_LED_GPIO
#define LIGHT_LED_GPIO_ACT_LEVEL CONFIG_AUGENTIX_LIGHT_LED_GPIO_ACT_LEVEL
#define LIGHT_LED_MODE CONFIG_AUGENTIX_LIGHT_LED_MODE
#endif

#ifdef CONFIG_AUGENTIX_LIGHT_SRC_HW
#define LIGHT_SRC hw
#else
#define LIGHT_SRC sw
#endif

#ifdef CONFIG_AUGENTIX_LOCK_PARAM_TO_SPEED_UP
#define LOCK_PARAM_TO_SPEED_UP 1
#else
#define LOCK_PARAM_TO_SPEED_UP 0
#endif

/* Legacy defaults section */
#ifndef LIGHT_ADC_CH
#define LIGHT_ADC_CH 2
#endif
#ifndef LIGHT1_ADC_CH
#define LIGHT1_ADC_CH 2
#endif
#ifndef CAMERA1_FPS
#define CAMERA1_FPS 15
#endif
#ifndef IR_FILTER_DEFAULT_STATUS
#define IR_FILTER_DEFAULT_STATUS 1
#endif
#ifndef IR_FILTER_DISABLE_LEVEL
#define IR_FILTER_DISABLE_LEVEL 0x01
#endif
#ifndef IR_CUT_IDLE_LEVEL
#define IR_CUT_IDLE_LEVEL 0x00
#endif
#ifndef IR_CUT_SWTICH_TIME
#define IR_CUT_SWTICH_TIME 30
#endif
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
#ifndef EARLY_AE_DROP_NUM
#define EARLY_AE_DROP_NUM 0
#endif
#ifndef ALL_SENSOR_SHARE_LUX
#define ALL_SENSOR_SHARE_LUX 0
#endif

/* Early audio defaults; 0:adc 1:pdm 2:i2s, 0:s16le 1:s32le */
#ifndef EARLY_AUDIO_BUF_KB
#define EARLY_AUDIO_BUF_KB 256
#endif
#ifndef EARLY_AUDIO_INTERFACE
#define EARLY_AUDIO_INTERFACE 0
#endif
#ifndef EARLY_AUDIO_CHANNELS
#define EARLY_AUDIO_CHANNELS 1
#endif
#ifndef EARLY_AUDIO_RATE
#define EARLY_AUDIO_RATE 8000
#endif
#ifndef EARLY_AUDIO_FORMAT
#define EARLY_AUDIO_FORMAT 0
#endif
#ifndef EARLY_AUDIO_ANALOG_GAIN
#define EARLY_AUDIO_ANALOG_GAIN 0
#endif

#ifndef EARLY_AUDIO_BEFORE_VIDEO
#define EARLY_AUDIO_BEFORE_VIDEO 0
#endif

#endif /*__FASTBOOT_COMMON_CONFIG_H*/
