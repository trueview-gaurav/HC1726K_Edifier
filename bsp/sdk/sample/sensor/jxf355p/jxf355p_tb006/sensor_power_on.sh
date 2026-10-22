#!/bin/sh

SENSOR=JXF355P

echo "Start to power on $SENSOR"

rstb_pin=49 # SENSOR_RSTB
pwdn_pin=50 # SENSOR_PWDN

echo ${pwdn_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn_pin}/direction
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction

# Initialize PWDN and RSTB pin
echo 1 > /sys/class/gpio/gpio${pwdn_pin}/value

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value

# 24MHz clock is always free running

# RSTB de-assert -> EXTCLK settle (T3 min 1ms)
usleep 1000

# RSTB assert
echo 0 > /sys/class/gpio/gpio${rstb_pin}/value

# RSTB assert -> de-assert (min 10ms)
usleep 10000

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# PWDN inactive
echo 0 > /sys/class/gpio/gpio${pwdn_pin}/value
echo ${pwdn_pin} > /sys/class/gpio/unexport

# PWDN inactive -> I2C valid (min 8192 EXT clock cycle ~= 341.33 us)
usleep 342

echo "Power on $SENSOR done"

