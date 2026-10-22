#!/bin/sh

SENSOR=OS08A20

echo "Start to power on $SENSOR"

# gpio 49, output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# 24MHz clock is always free running

# gpio 49, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (t1+t2)(512+512 clock) (1024 / 24000000 = 0.000426667 = 42.6667 us)
usleep 43

echo "Power on $SENSOR done"
