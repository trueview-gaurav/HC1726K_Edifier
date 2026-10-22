#!/bin/sh

SENSOR=JXF37

echo "Start to power on $SENSOR"

rstb_pin=66
pwdn_pin=67

echo ${pwdn_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn_pin}/direction
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction

# Initialize PWDN and RSTB pin
echo 1 > /sys/class/gpio/gpio${pwdn_pin}/value

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value

# Enable 24MHz clock to sensor
csr ioc.ioc.sensor_clk_iosel  1; #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0; #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0; #set div value
csr pc.pc.cken_sensor         1; #clock output enable

# RSTB de-assert -> EXTCLK settle (min 0us)
usleep 10

# RSTB assert
echo 0 > /sys/class/gpio/gpio${rstb_pin}/value

# RSTB assert -> de-assert (min 10ms)
usleep 12000

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# PWDN inactive
echo 0 > /sys/class/gpio/gpio${pwdn_pin}/value
echo ${pwdn_pin} > /sys/class/gpio/unexport

# PWDN inactive -> I2C valid (min 8192 EXT clock cycle ~= 341us)
usleep 400

echo "Power on $SENSOR done"

