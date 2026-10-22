#!/bin/sh

SENSOR=SC2335

echo "Start to power on $SENSOR"

# gpio 66, output_enable:1, output_value:0
PWDNB_pin=66
echo ${PWDNB_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${PWDNB_pin}/direction
echo 0     > /sys/class/gpio/gpio${PWDNB_pin}/value

# Enable 24MHz clock to sensor
csr ioc.ioc.sensor_clk_iosel  1; #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0; #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0; #set div value
csr pc.pc.cken_sensor         1; #clock output enable

# gpio 66, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${PWDNB_pin}/value
echo ${PWDNB_pin}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 4ms)
usleep 4000

echo "Power on $SENSOR done"

