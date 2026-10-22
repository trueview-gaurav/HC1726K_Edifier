#!/bin/sh

SENSOR=OS02G10

echo "Start to power on $SENSOR"

rstb_pin=49 # SENSOR_RSTB
pwdn_pin=50 # SENSOR_PWDN

echo ${pwdn_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn_pin}/direction
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction

# Initialize PWDN and RSTB pin
echo 0 > /sys/class/gpio/gpio${pwdn_pin}/value
echo 0 > /sys/class/gpio/gpio${rstb_pin}/value

# DVDD stable -> PWDN stable (T3, min 5ms)
usleep 6000

# PWDN de-assert
echo 1 > /sys/class/gpio/gpio${pwdn_pin}/value
echo ${pwdn_pin} > /sys/class/gpio/unexport

# 24MHz clock is always free running

# ECLK settle (T4, min 4ms)
usleep 5000

# RSTB de-assert
echo 1 > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# RSTB de-assert -> I2C valid (T6, min 5ms)
usleep 6000

# reset sensor
i2c_addr=0x3c
i2crw -Bb -D0 -S${i2c_addr} 0xfd 0x00
i2crw -Bb -D0 -S${i2c_addr} 0x36 0x01
usleep 1000
i2crw -Bb -D0 -S${i2c_addr} 0xfd 0x00
i2crw -Bb -D0 -S${i2c_addr} 0x36 0x00
usleep 1000
i2crw -Bb -D0 -S${i2c_addr} 0xfd 0x00
i2crw -Bb -D0 -S${i2c_addr} 0x20 0x00 2> /dev/null # reset, will always pop an error
usleep 6000 # wait 5ms
i2crw -Bb -D0 -S${i2c_addr} 0xfd 0x01
i2crw -Bb -D0 -S${i2c_addr} 0xb1 0x01

echo "Power on $SENSOR done"

