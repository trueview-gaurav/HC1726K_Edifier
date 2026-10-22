#!/bin/sh

SENSOR=IMX415

echo "Start to power on $SENSOR"

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# 37.125MHz sensor clock for the sensor
# comes from the sensor board itself in default

echo "Power on $SENSOR done"
