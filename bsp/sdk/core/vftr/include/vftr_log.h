/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_log.h
 * @brief Logging level control interface for core video feature-lib
 */

#ifndef VFTR_LOG_H_
#define VFTR_LOG_H_

#include <syslog.h>

void VFTR_setLog(int level);

#endif /* VFTR_LOG_H_ */