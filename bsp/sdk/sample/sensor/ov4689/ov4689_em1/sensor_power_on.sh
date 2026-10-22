#!/bin/sh

SENSOR=OV4689
#CUSTOM=TAIYEE
echo "Start to power on $SENSOR"

# sensor RST
if [ $CUSTOM == "TAIYEE" ]; then
        # gpio 66, output_enable:1, output_value:1
        pin_num=66
        echo ${pin_num}    > /sys/class/gpio/export
        echo "out" > /sys/class/gpio/gpio${pin_num}/direction
        echo 1     > /sys/class/gpio/gpio${pin_num}/value
        echo ${pin_num}    > /sys/class/gpio/unexport

        # gpio 65, output_enable:1, output_value:0
        pin_num=65
        echo ${pin_num}    > /sys/class/gpio/export
        echo "out" > /sys/class/gpio/gpio${pin_num}/direction
        echo 0     > /sys/class/gpio/gpio${pin_num}/value
else
        # gpio 66, output_enable:1, output_value:0
        pin_num=66
        echo ${pin_num}    > /sys/class/gpio/export
        echo "out" > /sys/class/gpio/gpio${pin_num}/direction
        echo 0     > /sys/class/gpio/gpio${pin_num}/value
fi

# sensor clk 24Mhz enable and deassert reset
csr ioc.ioc.sensor_clk_iosel  1   #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0   #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0   #set div value
csr pc.pc.cken_sensor         1   #clock output enable

# External clock settle time (min 0us)
# usleep 1

if [ $CUSTOM == "TAIYEE" ]; then
	#sensor_rstn=1, release sensor reset
        echo 1     > /sys/class/gpio/gpio${pin_num}/value
        echo ${pin_num}    > /sys/class/gpio/unexport
else
	#sensor_rstn=1, release sensor reset
        echo 1     > /sys/class/gpio/gpio${pin_num}/value
        echo ${pin_num}    > /sys/class/gpio/unexport
fi

# XSHUTDOWN raising -> first SCCB transaction (min 8192 external clock cycles)
usleep 500

echo "Power on $SENSOR done"

