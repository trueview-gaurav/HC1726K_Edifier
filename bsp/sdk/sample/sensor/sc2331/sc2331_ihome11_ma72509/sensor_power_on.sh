#!/bin/sh

SENSOR=SC2331

echo "Start to power on $SENSOR"

# GPIO for powering up Sensor 0 and Sensor 1
rstb01_pin=49

# I2C slave addresses
sensor2_addr_def=0x30 # Original IIC address when the sensor is powered up
sensor2_addr=0x31 # new IIC address for sensor 2
sensor0_addr=0x32
sensor1_addr=0x30

# Power down Sensor 0,1
echo ${rstb01_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb01_pin}/direction
echo 0 > /sys/class/gpio/gpio${rstb01_pin}/value

# Soft reset Sensor 2 if it has already been configured
i2crw -Wb -D0 -S"${sensor2_addr}" 0x0103 0x01 > /dev/null 2>&1
usleep 10

# Change Sensor 2's I2C slave address
i2crw -Wb -D0 -S"${sensor2_addr_def}" 0x3004 $(($sensor2_addr * 2))

# Power up Sensor 0,1
echo 1 > /sys/class/gpio/gpio${rstb01_pin}/value
echo ${rstb01_pin} > /sys/class/gpio/unexport

# RESETB -> I2C activity ready (min 4ms)
usleep 5000

# Soft reset Sensor 0,1 if it has already been configured
i2crw -Wb -D0 -S"${sensor0_addr}" 0x0103 0x01 > /dev/null 2>&1
i2crw -Wb -D0 -S"${sensor1_addr}" 0x0103 0x01 > /dev/null 2>&1
usleep 10

echo "Power on $SENSOR done"
