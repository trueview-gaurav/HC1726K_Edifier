/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file aftr_log.h
 * @brief Logging level control interface for core audio feature-lib
 */

#ifndef AFTR_LOG_H_
#define AFTR_LOG_H_

#include <syslog.h>

void AFTR_setLog(int level);

#endif /* AFTR_LOG_H_ */