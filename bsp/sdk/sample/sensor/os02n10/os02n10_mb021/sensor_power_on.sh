#!/bin/sh
echo "Start to power on $SENSOR"

SENSOR=OS02N10
rstb0_pin=49
dft_slv_addr=0x3c

echo ${rstb0_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb0_pin}/direction
echo 0 > /sys/class/gpio/gpio${rstb0_pin}/value
usleep 6000
echo 1 > /sys/class/gpio/gpio${rstb0_pin}/value
usleep 6000
i2crw -Bb -D0 -S"${dft_slv_addr}" 0xfc 0x01
echo ${rstb0_pin} > /sys/class/gpio/unexport
echo "Power on $SENSOR done"
