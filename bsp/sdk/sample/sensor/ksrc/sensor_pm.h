/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SENSOR_PM_H_
#define SENSOR_PM_H_

#include "sensor_dev.h"

int sensor_suspend(int path_idx);
int sensor_resume(int path_idx);

#ifdef SNS0
int sns0_suspend(struct sensor_info *sensor_info);
int sns0_resume(struct sensor_info *sensor_info);
void sns0_init_data(struct sensor_info *sensor_info);
#endif
#ifdef SNS1
int sns1_suspend(struct sensor_info *sensor_info);
int sns1_resume(struct sensor_info *sensor_info);
void sns1_init_data(struct sensor_info *sensor_info);
#endif
#ifdef SNS2
int sns2_suspend(struct sensor_info *sensor_info);
int sns2_resume(struct sensor_info *sensor_info);
void sns2_init_data(struct sensor_info *sensor_info);
#endif
#ifdef SNS3
int sns3_suspend(struct sensor_info *sensor_info);
int sns3_resume(struct sensor_info *sensor_info);
void sns3_init_data(struct sensor_info *sensor_info);
#endif

#endif
