#!/bin/sh

SENSOR=IMX327

echo "Start to power on $SENSOR"

# turn off 24MHz sensor clock
snsclk_pin=47
echo ${snsclk_pin}    > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio${snsclk_pin}/direction
echo ${snsclk_pin}    > /sys/class/gpio/unexport
# disable original sensor clock
csr io.pioc.pad_sensor_clk_iosel 0

# XCE is fixed to high

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# INCK -> Clear OFF (Tlow) (min 500ns)
usleep 1

# Setting XCLR high
# sensor_rstb (gpio 49), output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# Clear OFF -> Communication start (Txce) (min 20us)
usleep 25

echo "Power on $SENSOR done"
