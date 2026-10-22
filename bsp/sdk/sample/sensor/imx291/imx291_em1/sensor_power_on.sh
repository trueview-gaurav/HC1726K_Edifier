#!/bin/sh

SENSOR=IMX291

echo "Start to power on $SENSOR"

# XCE is fixed to high

# gpio 67, output_enable:1, output_value:1
pin_num=67
echo ${pin_num}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pin_num}/direction
echo 1     > /sys/class/gpio/gpio${pin_num}/value
echo ${pin_num}    > /sys/class/gpio/unexport

# gpio 66, output_enable:1, output_value:0
pin_num=66
echo ${pin_num}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pin_num}/direction
echo 0     > /sys/class/gpio/gpio${pin_num}/value

# CLK and IOMUX
csr ioc.ioc.sensor_clk_iosel  1;
csr pc.pc.cksel_sensor        2;
csr pc.pc.div_sel_sensor      7;
csr pc.pc.cken_sensor         1;

# INCK -> Clear OFF (Tlow) (min 500ns)
usleep 1

# Setting XCLR high

# gpio 66, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${pin_num}/value
echo ${pin_num}    > /sys/class/gpio/unexport

# Clear OFF -> Communication start (Txce) (min 20us)
usleep 25

echo "Power on $SENSOR done"

