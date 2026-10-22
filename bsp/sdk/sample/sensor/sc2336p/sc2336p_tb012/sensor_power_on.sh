#!/bin/sh

SENSOR=SC2336P

echo "Start to power on $SENSOR"

rstb_pin=35 # SENSOR_RSTB
pwdn_pin=-1 # SENSOR_PWDN

echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value

# 24MHz clock is always free running

# RSTB de-assert -> EXTCLK settle (min 0us)
usleep 10

# RSTB assert
echo 0 > /sys/class/gpio/gpio${rstb_pin}/value

# RSTB assert -> de-assert (min 10ms)
usleep 12000

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# PWDN inactive -> I2C valid (min 8192 EXT clock cycle ~= 341us)
usleep 5342

echo "Power on $SENSOR done"

