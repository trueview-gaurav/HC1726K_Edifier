#!/bin/sh

SENSOR=JXF35

echo "Start to power on $SENSOR"

rstb_pin=49 # SENSOR_RSTB
pwdn_pin=17 # UART1_RXD

# Edit the IOMUX of UART1_RXD to GPIO
csr io.pioc.pad_uart1_rxd_iosel 0

echo ${pwdn_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn_pin}/direction
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction

# Initialize PWDN and RSTB pin
echo 1 > /sys/class/gpio/gpio${pwdn_pin}/value

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value

# check 24MHz clock here

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

