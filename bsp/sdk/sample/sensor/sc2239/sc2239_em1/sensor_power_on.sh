#!/bin/sh

SENSOR=SC2239

echo "Start to power on $SENSOR"

# gpio 66, output_enable:1, output_value:0
pin_num=66
echo ${pin_num}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pin_num}/direction
echo 0     > /sys/class/gpio/gpio${pin_num}/value

# Enable 24MHz clock to sensor
csr ioc.ioc.sensor_clk_iosel  1; #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0; #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0; #set div value
csr pc.pc.cken_sensor         1; #clock output enable

# gpio 66, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${pin_num}/value
echo ${pin_num}    > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 2ms)
usleep 4400

echo "Power on $SENSOR done"

