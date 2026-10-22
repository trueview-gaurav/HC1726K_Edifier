#!/bin/sh

SENSOR=IMX676

echo "Start to power on $SENSOR"

# Initialize XCLR as low
rstb_pin=49
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value
usleep 1

# Reset sensor
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport
usleep 25

echo "Power on $SENSOR done"
