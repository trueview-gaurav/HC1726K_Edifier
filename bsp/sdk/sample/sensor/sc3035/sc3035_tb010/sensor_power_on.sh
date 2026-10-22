#!/bin/sh

SENSOR=SC3035D

echo "Start to power on $SENSOR"

# control pin definition
rstb_pin=31

# Initialize control pins
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value

# pull down RSTB
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# hold RSTB, 1ms (T3)
usleep 2000

# pull up RSTB
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# I2C ready, 1ms (T4)
usleep 2000

# turn off the sensor in default
i2crw -Wb -D0 -S0x30 0x0100 0x00

echo "Power on $SENSOR done"
