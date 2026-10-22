#!/bin/sh

SENSOR=SC2336

echo "Start to power on $SENSOR"

# GPIO for powering up Sensor 0,2
# Reset pin for Sensor 1
rstb_pin0=35
# Reset pin for Sensor 0
rstb_pin1=31

# I2C slave addresses
dft_slv_addr=0x30 # Original slave address when the Sensor is powered up
sns1_slv_addr=0x31 # Preferred slave address for Sensor 1, this should fit the one in sensor_params.h
sns2_slv_addr=0x32 # Preferred slave address for Sensor 2, this should fit the one in sensor_params.h

# Soft reset Sensor 1 and Sensor 2 if it has already been configured
i2crw -Wb -D0 -S"${sns1_slv_addr}" 0x0103 0x01 > /dev/null 2>&1
i2crw -Wb -D0 -S"${sns2_slv_addr}" 0x0103 0x01 > /dev/null 2>&1
usleep 10

# Power down Sensor 1
echo ${rstb_pin0} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin0}/direction
echo 0 > /sys/class/gpio/gpio${rstb_pin0}/value

# Power down Sensor 0
echo ${rstb_pin1} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin1}/direction
echo 0 > /sys/class/gpio/gpio${rstb_pin1}/value

# Change Sensor 2's I2C slave address
i2crw -Wb -D0 -S"${dft_slv_addr}" 0x3004 $(($sns2_slv_addr * 2))

# Power up Sensor 1
echo 1 > /sys/class/gpio/gpio${rstb_pin0}/value
echo ${rstb_pin0} > /sys/class/gpio/unexport

# Change Sensor 1's I2C slave address
i2crw -Wb -D0 -S"${dft_slv_addr}" 0x3004 $(($sns1_slv_addr * 2))

# Power up Sensor 0
echo 1 > /sys/class/gpio/gpio${rstb_pin1}/value
echo ${rstb_pin1} > /sys/class/gpio/unexport

echo "Power on $SENSOR done"

