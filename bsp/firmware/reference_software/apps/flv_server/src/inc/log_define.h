#ifndef LOG_DEFINE_H_
#define LOG_DEFINE_H_

#include <syslog.h>

#define FLV_DEBUG
#define flv_server_log_err(fmt, ...) syslog(LOG_LOCAL7 | LOG_ERR, "[Error] " fmt, ##__VA_ARGS__)
#define flv_server_log_warn(fmt, ...) syslog(LOG_LOCAL7 | LOG_WARNING, "[Warning] " fmt, ##__VA_ARGS__)
#define flv_server_log_notice(fmt, ...) syslog(LOG_LOCAL7 | LOG_NOTICE, "[Notice] " fmt, ##__VA_ARGS__)
#ifdef FLV_DEBUG
#define flv_server_log_info(fmt, ...) syslog(LOG_LOCAL7 | LOG_INFO, "[Info] " fmt, ##__VA_ARGS__)
#define flv_server_log_debug(fmt, ...) syslog(LOG_LOCAL7 | LOG_DEBUG, "[Debug] " fmt, ##__VA_ARGS__)
#else
#define flv_server_log_info(fmt, args...)
#define flv_server_log_debug(fmt, args...)
#endif

#endif