#!/bin/sh

SENSOR=OV12895

echo "Start to power on $SENSOR"

# power down high
#csr ioc.ioc.pwm4_iosel        0   #pwm4 as gpio66, to control OV12895 PWDNB
#csr ioc.ioc.gpio_o_66         1   #PWDNB=1 to let OV12895 enter power up mode
#csr ioc.ioc.gpio_oe_66        1   #PWDNB=1 output enable

# gpio 66, output_enable:1, output_value:1 
PWDN_pin=66
echo ${PWDN_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${PWDN_pin}/direction
echo 1     > /sys/class/gpio/gpio${PWDN_pin}/value
echo ${PWDN_pin} > /sys/class/gpio/unexport

#xshutdown de-assertion
#csr ioc.ioc.spi1_sdi_iosel    0   #SPI1 as gpio65, to control OV12895 XSHUTDOWN
#csr ioc.ioc.gpio_o_65         0
#csr ioc.ioc.gpio_oe_65        1

# gpio 65, output_enable:1, output_value:1
XSHUT_pin=65
echo ${XSHUT_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${XSHUT_pin}/direction
echo 0     > /sys/class/gpio/gpio${XSHUT_pin}/value

# sensor clk 24Mhz enable and deassert reset
csr ioc.ioc.sensor_clk_iosel  1   #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0   #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0   #set div value
csr pc.pc.cken_sensor         1   #clock output enable
usleep 1000                       #delay

# xshutdown de-assertion
#csr ioc.ioc.gpio_o_65         1   #sensor_rstn=1, release sensor reset
echo 1     > /sys/class/gpio/gpio${XSHUT_pin}/value
echo ${XSHUT_pin} > /sys/class/gpio/unexport

usleep 10000                      # it require "at least" 5.35 ms to be ready

echo "Power on $SENSOR done"

