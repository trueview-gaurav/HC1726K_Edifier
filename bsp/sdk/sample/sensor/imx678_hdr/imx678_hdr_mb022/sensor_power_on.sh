#!/bin/sh

SENSOR=IMX678

echo "Start to power on $SENSOR"

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value
usleep 10

# Pull XCLR to high
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport
usleep 25

echo "Power on $SENSOR done"
