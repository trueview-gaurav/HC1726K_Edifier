#!/bin/sh

SENSOR=SC2335

echo "Start to power on $SENSOR"

# gpio 49, output_enable:1, output_value:0
PWDNB_pin=49
echo ${PWDNB_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${PWDNB_pin}/direction
echo 0     > /sys/class/gpio/gpio${PWDNB_pin}/value

# 24MHz sensor clock is always running

# gpio 49, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${PWDNB_pin}/value
echo ${PWDNB_pin}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 4ms)
usleep 4000

echo "Power on $SENSOR done"

