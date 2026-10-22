#ifndef HE2823_MOTOR_H_
#define HE2823_MOTOR_H_

#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include "libmotor.h"
#include "gpio.h"

#define MAX_HE2823_GPIO_CNT (3)

typedef struct he2823_motor {
	Gpio control_gpio[MAX_HE2823_GPIO_CNT]; /*< GPIO for sen command to chip he2823 */
	float step_angle; /*< Minimum step angle of motor hardware */
	float ptz_speed_factor[AXIS_NUM]; /*< The inverse of the angle needed to move the tracking box by one pixel.
	                                      list by [X,Y,Z] axis*/
} He2823Motor;

MotorData *newHe2823Motor(const MotorLimit *limit, const He2823Motor *gpio);
int deleteHe2823Motor(MotorData *data);

#ifdef __cplusplus
}
#endif /**< __cplusplus */

#endif