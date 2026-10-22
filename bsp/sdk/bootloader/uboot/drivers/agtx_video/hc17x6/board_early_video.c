#include <common.h>

#include "agtx_video.h"

#ifdef CONFIG_EARLYVIDEO
#include <i2c.h>
#include <sensor_params.h>
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
#include <sensor_params_1.h>

extern void sensor_start_1(int sensor_i2c_addr);
extern void sensor_set_exposure_1(int sensor_i2c_addr);
extern void sensor_set_fps_1(int sensor_i2c_addr);
#endif
extern void ir_cut_control(int filter_enable);
extern void sensor_power_up(void);
extern void sensor_start(int sensor_i2c_addr);
extern void sensor_set_exposure(int sensor_i2c_addr);
extern void sensor_set_fps(int sensor_i2c_addr);
extern void agtx_video_init(void);
extern void agtx_video_enable_sw_light_meter(uint8_t path);
extern void agtx_video_enable_image_capture(uint8_t path);
extern void agtx_video_start(uint8_t path);
extern void agtx_video_poll_sw_light_meter(uint8_t path);
extern void agtx_video_poll_frame_end(uint8_t path);

int board_early_video_init(void)
{
	int i2c_speed = 400 * 1000; /* It should be either 100, 200, 300, 375 or 400 KHz */
#if EARLYVIDEO_DEBUG
	uint64_t init_start_ticks;
#endif
	uint8_t uboot_drop_num;
	uint8_t is_sw_lux_src;
	char value_buf[32];
	char *ret_str;
	int i;
#if EARLYVIDEO_DEBUG
	/* Record the starting time */
	init_start_ticks = get_ticks();
#endif
	/* Get the values of lux_src and drop_num to decide the initial flow */
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(UBOOT_DROP_NUM) : getenv("uboot_drop_num");
	if (ret_str) {
		uboot_drop_num = (uint8_t)simple_strtoul(ret_str, NULL, 10);
	} else {
		uboot_drop_num = 2;
	}
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_SRC) : getenv("lux_src");
	if (ret_str && (strcmp(ret_str, "env") == 0 || strcmp(ret_str, "hw") == 0)) {
		is_sw_lux_src = 0;
		/* The uboot_drop_num is only valid in the case of lux_src=sw */
		uboot_drop_num = 0;
		sprintf(value_buf, "%u", uboot_drop_num);
		setenv("uboot_drop_num", value_buf);
	} else {
		is_sw_lux_src = 1;
		ir_cut_control(IR_FILTER_DEFAULT_STATUS);
	}

	/* Configure i2c slave address and i2c speed */
	i2c_set_bus_num(0);
	i2c_init(i2c_speed, SENSOR_I2C_SLAVE_ADDR);
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
#ifdef SNS_I2C_1
	i2c_set_bus_num(1);
#endif
	i2c_init(i2c_speed, SENSOR_I2C_SLAVE_ADDR1);
#endif
	agtx_video_init();
	sensor_power_up();

	/* Path 0 */
	i2c_set_bus_num(0);
	sensor_start(SENSOR_I2C_SLAVE_ADDR);
	if (is_sw_lux_src) {
		agtx_video_enable_sw_light_meter(0);
		if (uboot_drop_num == 0) {
			agtx_video_enable_image_capture(0);
		}
		agtx_video_start(0);
		agtx_video_poll_sw_light_meter(0);
		sensor_set_exposure(SENSOR_I2C_SLAVE_ADDR);
		sensor_set_fps(SENSOR_I2C_SLAVE_ADDR);
		if (uboot_drop_num != 0) {
			for (i = 1; i < uboot_drop_num; i++) {
				agtx_video_enable_sw_light_meter(0);
				agtx_video_start(0);
				agtx_video_poll_sw_light_meter(0);
			}
			agtx_video_enable_image_capture(0);
			agtx_video_start(0);
		}
	} else {
		agtx_video_enable_image_capture(0);
		agtx_video_start(0);
	}
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	/* Path 1 */
#ifdef SNS_I2C_1
	i2c_set_bus_num(1);
#endif
	sensor_start_1(SENSOR_I2C_SLAVE_ADDR1);
	if (ALL_SENSOR_SHARE_LUX == 0 && is_sw_lux_src) {
		agtx_video_enable_sw_light_meter(1);
		if (uboot_drop_num == 0) {
			agtx_video_enable_image_capture(1);
		}
		agtx_video_start(1);
		agtx_video_poll_sw_light_meter(1);
		sensor_set_exposure_1(SENSOR_I2C_SLAVE_ADDR1);
		sensor_set_fps_1(SENSOR_I2C_SLAVE_ADDR1);
		if (uboot_drop_num != 0) {
			for (i = 1; i < uboot_drop_num; i++) {
				agtx_video_enable_sw_light_meter(1);
				agtx_video_start(1);
				agtx_video_poll_sw_light_meter(1);
			}
			agtx_video_enable_image_capture(1);
			agtx_video_start(1);
		}
	} else {
		agtx_video_enable_image_capture(1);
		agtx_video_start(1);
	}
#endif
#if EARLYVIDEO_DEBUG
	/* Calculate the time spent starting the video and sensor */
	serial_printf(">> Uboot video and sensor driver executing time = %llu ticks\n", get_ticks() - init_start_ticks);
#endif
	return 0;
}

void board_early_video_wait_finish(void)
{
	// TODO: Port IRQ-based handling from HC17x3 to HC17x6
}

#endif /* CONFIG_EARLYVIDEO */
