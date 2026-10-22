#!/bin/sh

SENSOR=GC2083

echo "Start to power on $SENSOR"

rstb_pin=49 # SENSOR0_RSTB
rstb_pin2=48 # SENSOR1_RSTB

echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

echo ${rstb_pin2}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin2}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin2}/value

echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

echo 1 > /sys/class/gpio/gpio${rstb_pin2}/value
echo ${rstb_pin2}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 50us)
usleep 200

echo "Power on $SENSOR done"