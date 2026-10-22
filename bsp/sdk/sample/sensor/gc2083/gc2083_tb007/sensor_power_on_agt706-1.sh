#!/bin/sh

SENSOR=GC2083

echo "Start to power on $SENSOR"

# gpio 35, output_enable:1, output_value:0
rstb_pin=35

echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 50us)
usleep 200

echo "Power on $SENSOR done"
