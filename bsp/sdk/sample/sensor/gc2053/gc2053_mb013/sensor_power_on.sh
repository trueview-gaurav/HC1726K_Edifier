#!/bin/sh

SENSOR=GC2053

echo "Start to power on $SENSOR"

# pwdn and resetb are connected to PWM5(GPIO 67) on MB013
pwdn_pin=67

echo ${pwdn_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn_pin}/direction
echo 0     > /sys/class/gpio/gpio${pwdn_pin}/value
usleep 10

# Enable 24MHz clock to sensor
csr ioc.ioc.sensor_clk_iosel  1; #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0; #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0; #set div value
csr pc.pc.cken_sensor         1; #clock output enable

usleep 10
echo 1 > /sys/class/gpio/gpio${pwdn_pin}/value

# RESETB -> I2C activity ready (min 50us)
usleep 150

echo "Power on $SENSOR done"

