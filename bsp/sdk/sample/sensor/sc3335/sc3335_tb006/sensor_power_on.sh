#!/bin/sh

SENSOR=SC3335

echo "Start to power on $SENSOR"

# gpio 49, output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# Enable 24MHz clock to sensor

# gpio 66, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 2ms)
usleep 4400

echo "Power on $SENSOR done"

