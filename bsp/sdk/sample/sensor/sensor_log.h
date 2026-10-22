#ifndef SENSOR_DEBUG_H_
#define SENSOR_DEBUG_H_

#ifdef __KERNEL__
#include <linux/types.h>
#include <linux/printk.h>
#else
#include <syslog.h>
#endif

#ifdef __KERNEL__
#define sensor_log_err(fmt, ...) pr_err("[Error][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_warn(fmt, ...) pr_warn("[Warning][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_notice(fmt, ...) pr_notice("[Notice][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_info(fmt, ...) pr_info("[Info][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_debug(fmt, ...) pr_debug("[Debug][SENSOR] " fmt "\n", ##__VA_ARGS__)
#else
#define sensor_log_err(fmt, ...) syslog(LOG_LOCAL7 | LOG_ERR, "[Error][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_warn(fmt, ...) syslog(LOG_LOCAL7 | LOG_WARNING, "[Warning][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_notice(fmt, ...) syslog(LOG_LOCAL7 | LOG_NOTICE, "[Notice][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_info(fmt, ...) syslog(LOG_LOCAL7 | LOG_INFO, "[Info][SENSOR] " fmt "\n", ##__VA_ARGS__)
#define sensor_log_debug(fmt, ...) syslog(LOG_LOCAL7 | LOG_DEBUG, "[Debug][SENSOR] " fmt "\n", ##__VA_ARGS__)
#endif

#endif
