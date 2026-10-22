#!/bin/sh

SENSOR=IMX335

echo "Start to power on $SENSOR"

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# Temporary disable clock output
# might not be necessary
devmem 0x80001604 32 0

# Power on -> XCLR high (Tlow) (min 500ns)
usleep 1

# Setting XCLR high
# sensor_rstb (gpio 49), output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# Turn on 24MHz clock again
devmem 0x80001604 32 1

# Clear OFF -> Communication start (T4) (min 20us)
usleep 20

echo "Power on $SENSOR done"

