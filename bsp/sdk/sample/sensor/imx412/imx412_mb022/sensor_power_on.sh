#!/bin/sh

SENSOR=IMX412

echo "Start to power on $SENSOR"

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value
usleep 1000
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# 24MHz sensor clock for the sensor

# T7 (min 8 ms) spec 6.1.2
usleep 9000

echo "Power on $SENSOR done"
