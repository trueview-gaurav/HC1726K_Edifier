#!/bin/sh

SENSOR=GC5603

echo "Start to power on $SENSOR"

# gpio 49, output_enable:1, output_value:0
rstb_pin=49

echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

usleep 50

echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 50us)
usleep 50

echo "Power on $SENSOR done"

