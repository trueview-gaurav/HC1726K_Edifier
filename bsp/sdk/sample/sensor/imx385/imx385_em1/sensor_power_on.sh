#!/bin/sh

SENSOR=IMX385

echo "Start to power on $SENSOR"

# XCE is fixed to high

# gpio 67, output_enable:1, output_value:1
#XCE_pin=67
#echo ${XCE_pin}    > /sys/class/gpio/export
#echo "out" > /sys/class/gpio/gpio${XCE_pin}/direction
#echo 1     > /sys/class/gpio/gpio${XCE_pin}/value
#echo ${XCE_pin}    > /sys/class/gpio/unexport

# gpio 66, output_enable:1, output_value:0
XCLR_pin=66
echo ${XCLR_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${XCLR_pin}/direction
echo 0     > /sys/class/gpio/gpio${XCLR_pin}/value

# CLK and IOMUX
csr ioc.ioc.sensor_clk_iosel  1;
csr pc.pc.cksel_sensor        2;
csr pc.pc.div_sel_sensor      7;
csr pc.pc.cken_sensor         1;

# INCK -> Clear OFF (Tlow) (min 500ns)
usleep 1

# Setting XCLR high

# gpio 66, output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${XCLR_pin}/value
echo ${XCLR_pin}    > /sys/class/gpio/unexport

# Clear OFF -> Communication start (Txce) (min 20us)
usleep 25

echo "Power on $SENSOR done"

# Extra settings for back porch,
# senif can now set this value by calling the function in sensor_ctrl.c
# csr fe.fe.h_porch 4
