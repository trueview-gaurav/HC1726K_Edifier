#!/bin/sh

# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

# sensor_power_on.sh - shell commands to power up the sensor
# Follows the power up sequence provided in the documents of the sensor.

SENSOR=TMPLT

echo "Start to power on $SENSOR"

# gpio 65, output_enable:1, output_value:1
rtsb_pin=65
echo ${rtsb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rtsb_pin}/direction
echo 1     > /sys/class/gpio/gpio${rtsb_pin}/value

usleep 3000

echo "Power on $SENSOR done"
