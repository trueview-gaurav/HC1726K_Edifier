#!/bin/sh

SENSOR=JXQ03P

echo "Start to power on $SENSOR"

# PWDN(gpio 50), output_value:1
pwdn=32
echo ${pwdn}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn}/direction
echo 1     > /sys/class/gpio/gpio${pwdn}/value

# RSTB(gpio 49)
rstb=31
echo ${rstb}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb}/direction

# RSTB(gpio 49), output_value:1
echo 1     > /sys/class/gpio/gpio${rstb}/value

# 24MHz clock is always free running

usleep 1000

# RSTB(gpio 49), output_value:0
echo 0     > /sys/class/gpio/gpio${rstb}/value

usleep 10000

# RSTB(gpio 49), output_value:1
echo 1     > /sys/class/gpio/gpio${rstb}/value
echo ${rstb}    > /sys/class/gpio/unexport

# PWDN(gpio 50), output_value:0
echo 0     > /sys/class/gpio/gpio${pwdn}/value
echo ${pwdn}    > /sys/class/gpio/unexport

# RSTB -> I2C activity ready (T4 >= 8192 EXCLK cycles = 342 us)
usleep 400

echo "Power on $SENSOR done"
