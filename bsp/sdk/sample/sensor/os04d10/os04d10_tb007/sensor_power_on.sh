#!/bin/sh
echo "Start to power on $SENSOR"

SENSOR=OS04D10
rstb0_pin=49

echo ${rstb0_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb0_pin}/direction
echo 0 > /sys/class/gpio/gpio${rstb0_pin}/value
usleep 5000
echo 1 > /sys/class/gpio/gpio${rstb0_pin}/value
usleep 8000
echo ${rstb0_pin} > /sys/class/gpio/unexport
echo "Power on $SENSOR done"
