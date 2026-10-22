#!/bin/sh

SENSOR=SC301IOT_HDR

echo "Start to power on $SENSOR"

# gpio 32, output_enable:1, output_value:0
rstb_pin=32
echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# 24MHz clock is always free running

# gpio 32, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 5ms + 8192 clock) (8192 / 24000000 = 0.0003413333 = 341.3333 us)
usleep 5342

echo "Power on $SENSOR done"
