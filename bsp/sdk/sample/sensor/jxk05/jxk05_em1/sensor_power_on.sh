#!/bin/sh

SENSOR=JXK05

echo "Start to power on $SENSOR"

# PWDN(gpio 67), output_value:1
pwdn=67
echo ${pwdn}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn}/direction
echo 1     > /sys/class/gpio/gpio${pwdn}/value

# RSTB(gpio 66)
rstb=66
echo ${rstb}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb}/direction

# RSTB(gpio 66), output_value:1
echo 1     > /sys/class/gpio/gpio${rstb}/value

# Enable 24MHz clock to sensor
csr ioc.ioc.sensor_clk_iosel  1; #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0; #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0; #set div value
csr pc.pc.cken_sensor         1; #clock output enable

usleep 1000

# RSTB(gpio 66), output_value:0
echo 0     > /sys/class/gpio/gpio${rstb}/value

usleep 10000

# RSTB(gpio 66), output_value:1
echo 1     > /sys/class/gpio/gpio${rstb}/value
echo ${rstb}    > /sys/class/gpio/unexport

# PWDN(gpio 67), output_value:0
echo 0     > /sys/class/gpio/gpio${pwdn}/value
echo ${pwdn}    > /sys/class/gpio/unexport

# RSTB -> I2C activity ready (T4 >= 8192 EXCLK cycles = 342 us)
usleep 400

echo "Power on $SENSOR done"
