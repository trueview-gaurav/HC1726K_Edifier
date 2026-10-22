#!/bin/sh

SENSOR=JXF37P

echo "Start to power on $SENSOR"

rstb_pin=49 # SENSOR0_RSTB
rstb_pin2=48 # SENSOR1_RSTB

echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo ${rstb_pin2} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin2}/direction

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo 1 > /sys/class/gpio/gpio${rstb_pin2}/value

# 24MHz clock is always free running

# RSTB de-assert -> EXTCLK settle (min 0us)
usleep 10

# RSTB assert
echo 0 > /sys/class/gpio/gpio${rstb_pin}/value
echo 0 > /sys/class/gpio/gpio${rstb_pin2}/value

# RSTB assert -> de-assert (min 10ms)
usleep 12000

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport
echo 1 > /sys/class/gpio/gpio${rstb_pin2}/value
echo ${rstb_pin2} > /sys/class/gpio/unexport

# PWDN inactive -> I2C valid (min 8192 EXT clock cycle ~= 341us)
usleep 400

echo "Power on $SENSOR done"
