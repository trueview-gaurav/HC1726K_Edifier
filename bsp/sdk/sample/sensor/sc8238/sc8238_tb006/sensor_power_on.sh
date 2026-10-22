#!/bin/sh

SENSOR=SC8238

echo "Start to power on $SENSOR"

# gpio 66, output_enable:1, output_value:0
pin_num=49
echo ${pin_num}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pin_num}/direction
echo 0     > /sys/class/gpio/gpio${pin_num}/value

# Enable 24MHz clock to sensor


# gpio 66, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${pin_num}/value
echo ${pin_num}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 2ms)
usleep 2200

echo "Power on $SENSOR done"

