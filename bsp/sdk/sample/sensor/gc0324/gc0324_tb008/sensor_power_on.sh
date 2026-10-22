#!/bin/sh

SENSOR=GC0324

echo "Start to power on $SENSOR"

# pwdn and resetb are connected to PWM5(GPIO 67) on MB013
rstb_pin=49

echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value


echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport
# RESETB -> I2C activity ready (min 50us)
usleep 60

echo "Power on $SENSOR done"

