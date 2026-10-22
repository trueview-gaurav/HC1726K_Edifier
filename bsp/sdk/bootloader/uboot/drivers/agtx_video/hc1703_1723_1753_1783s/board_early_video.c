#include <common.h>

#include "agtx_video.h"
#include "agtx_early_amp.h"

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

extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

#ifdef CONFIG_DUAL_SENSOR_SUPPORT
struct sensor_info g_sensor[2];
uint8_t g_curr_uboot_drop_num[2]; /* Current number of Uboot dropped frames */
uint8_t g_curr_early_ae_drop_num[2];
#else
struct sensor_info g_sensor[1];
uint8_t g_curr_uboot_drop_num[1]; /* Current number of Uboot dropped frames */
uint8_t g_curr_early_ae_drop_num[1];
#endif

uint8_t g_uboot_drop_num = UBOOT_DROP_NUM;
uint8_t g_is_sw_lux_src;
uint8_t g_early_ae_drop_num = EARLY_AE_DROP_NUM;

/* Functions handling IRQ callbacks and flow control */
static void start_path(uint8_t path);
static void finish_path(uint8_t path);
static void process_sw_lux(uint8_t path);
static void process_last_frame(uint8_t path, uint8_t *detect_frame_num);
#if CONFIG_AMP
static void start_snapshot(uint8_t path);
#endif

int board_early_video_init(void)
{
	int i2c_speed = 400 * 1000; /* It should be either 100, 200, 300, 375 or 400 KHz */
#if CONFIG_AMP
	struct false_alarm_info *false_alarm = &g_earlyvideo_drvdata.false_alarm;
#endif
	char value_buf[32];
	char *ret_str;
	struct sensor_info *sensor;

#if CONFIG_AMP
	false_alarm->thres = FALSE_ALARM_THRESHOLD;

	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(FALSE_ALARM_TYPE) : getenv("fal_alarm_type");
	if (ret_str) {
		false_alarm->type = (uint8_t)simple_strtoul(ret_str, NULL, 10);
	}
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(FALSE_ALARM_THRESHOLD) : getenv("fal_alarm_thre");
	if (ret_str) {
		false_alarm->thres = (uint8_t)simple_strtoul(ret_str, NULL, 10);
	}
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(FALSE_ALARM_FRAME_NUM) : getenv("fal_alarm_frame_num");
	if (ret_str) {
		false_alarm->frame_num = (uint8_t)simple_strtoul(ret_str, NULL, 10);
	} else {
		false_alarm->frame_num = FALSE_ALARM_FRAME_NUM;
	}
#endif
	/* Get the values of lux_src and drop_num to decide the initial flow */
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(UBOOT_DROP_NUM) : getenv("uboot_drop_num");
	if (ret_str) {
		g_uboot_drop_num = (uint8_t)simple_strtoul(ret_str, NULL, 10);
	}
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_SRC) : getenv("lux_src");
	if (ret_str && (strcmp(ret_str, "env") == 0 || strcmp(ret_str, "hw") == 0)) {
		g_is_sw_lux_src = 0;
		/* The uboot_drop_num is only valid in the case of lux_src=sw */
		g_uboot_drop_num = 0;
		sprintf(value_buf, "%u", g_uboot_drop_num);
		setenv("uboot_drop_num", value_buf);
	} else {
		g_is_sw_lux_src = 1;
		ir_cut_control(IR_FILTER_DEFAULT_STATUS);
	}
	ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(EARLY_AE_DROP_NUM) : getenv("early_ae_drop_num");
	if (ret_str) {
		g_early_ae_drop_num = (uint8_t)simple_strtoul(ret_str, NULL, 10);
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

	/* Set sensor-related callback functions */
	sensor = &g_sensor[0];
	sensor->start = sensor_start;
	sensor->set_exposure = sensor_set_exposure;
	sensor->set_fps = sensor_set_fps;
	sensor->i2c_slave_addr = SENSOR_I2C_SLAVE_ADDR;
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	sensor = &g_sensor[1];
	sensor->start = sensor_start_1;
	sensor->set_exposure = sensor_set_exposure_1;
	sensor->set_fps = sensor_set_fps_1;
	sensor->i2c_slave_addr = SENSOR_I2C_SLAVE_ADDR1;
#endif

	start_path(0);
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	start_path(1);
#endif

	return 0;
}

void board_early_video_wait_finish(void)
{
	uint8_t expect_flag = VIDEO_DONE_PATH_0;
	uint64_t start_ticks = get_ticks();
	uint64_t max_wait_ticks = SEC_TO_TICKS;

#if CONFIG_AMP
	struct false_alarm_info *false_alarm = &g_earlyvideo_drvdata.false_alarm;
	if (false_alarm->type != 0) {
		expect_flag |= VIDEO_DONE_SNAPSHOT;
	}
#endif
#ifdef CONFIG_DUAL_SENSOR_SUPPORT
	expect_flag |= VIDEO_DONE_PATH_1;
#endif

	while (g_earlyvideo_drvdata.done_flag != expect_flag) {
		if ((get_ticks() - start_ticks) > max_wait_ticks) {
			printf("\nUboot earlyvideo timeout\n");
#if CONFIG_AMP
			/* Snapshot failed, reset ISP hardware */
			if (expect_flag & VIDEO_DONE_SNAPSHOT) {
				volatile uint32_t *swrst_ispvp = (uint32_t *)(0x8000042c);
				*swrst_ispvp = (1 << 8) | (1 << 0);
			}
#endif
			break;
		}
	}

#if EARLYVIDEO_DEBUG
	printf("\n[%s]: Wait %llu ticks\n", __func__, get_ticks() - start_ticks);
#endif
}

static void start_path(uint8_t path)
{
	struct sensor_info *sensor = &g_sensor[path];

#if defined(CONFIG_DUAL_SENSOR_SUPPORT) && defined(SNS_I2C_1)
	i2c_set_bus_num(path);
#endif
	sensor->start(sensor->i2c_slave_addr);
	if (g_is_sw_lux_src) {
		g_curr_uboot_drop_num[path] = 0;
		g_curr_early_ae_drop_num[path] = 0;
		process_sw_lux(path);
	} else {
		process_last_frame(path, NULL);
	}
}

static void process_sw_lux(uint8_t path)
{
	struct agtx_video_route route = {
		.path = path,
		.sw_light_meter_cb = process_sw_lux,
		.image_capture = 0,
	};

	struct sensor_info *sensor = &g_sensor[path];

	/* Early AE drop frame */
	if (g_curr_early_ae_drop_num[path] < g_early_ae_drop_num) {
		g_curr_early_ae_drop_num[path]++;
		agtx_video_start(&route);
		return;
	}

	/* Process one frame to compute the software light meter */
	if (g_curr_uboot_drop_num[path] == 0) {
		if (g_uboot_drop_num == 0) {
			route.image_capture = 1;
		}
		g_curr_uboot_drop_num[path]++;
		agtx_video_start(&route);
		return;
	}

	/* Set the sensor exposure */
	if (g_curr_uboot_drop_num[path] == 1) {
#if defined(CONFIG_DUAL_SENSOR_SUPPORT) && defined(SNS_I2C_1)
		i2c_set_bus_num(path);
#endif
		sensor->set_exposure(sensor->i2c_slave_addr);
	}

	/* Perform frame dropping */
	if (g_curr_uboot_drop_num[path] < g_uboot_drop_num) {
		g_curr_uboot_drop_num[path]++;
		agtx_video_start(&route);
		return;
	}

	/* Reset sensor FPS to configured setting */
#if defined(CONFIG_DUAL_SENSOR_SUPPORT) && defined(SNS_I2C_1)
	i2c_set_bus_num(path);
#endif
	sensor->set_fps(sensor->i2c_slave_addr);

	if (g_uboot_drop_num == 0) {
		finish_path(path);
	} else {
		uint8_t *detect_frame_num = NULL;
#if CONFIG_AMP
		struct false_alarm_info *false_alarm = &g_earlyvideo_drvdata.false_alarm;

		/* Currently, only snapshot on path 0 is supported */
		if (path == 0 && false_alarm->type != 0) {
			detect_frame_num = &false_alarm->frame_num;
		}
#endif
		process_last_frame(path, detect_frame_num);
	}
}

static void process_last_frame(uint8_t path, uint8_t *detect_frame_num)
{
	struct agtx_video_route route = {
		.path = path,
		.sw_light_meter_cb = NULL,
		.image_capture = 1,
	};

#if CONFIG_AMP
	if (detect_frame_num) {
		agtx_video_adjust_light_meter_height(0, detect_frame_num);
		route.sw_light_meter_cb = start_snapshot;
	}
#else
	(void)detect_frame_num;
#endif

	agtx_video_start(&route);
	finish_path(path);
}

static void finish_path(uint8_t path)
{
	if (path == 0) {
		g_earlyvideo_drvdata.done_flag |= VIDEO_DONE_PATH_0;
	} else if (path == 1) {
		g_earlyvideo_drvdata.done_flag |= VIDEO_DONE_PATH_1;
	}
}

#if CONFIG_AMP
static void start_snapshot(uint8_t path)
{
	if (path > 0) {
		return;
	}

	/* Capture YUV snapshot and motion vectors for false alarm */
	agtx_video_start_snapshot();
}
#endif

#endif
