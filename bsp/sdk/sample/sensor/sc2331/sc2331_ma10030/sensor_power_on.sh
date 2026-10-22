#!/bin/sh

SENSOR=SC2331

echo "Start to power on $SENSOR"

# GPIO for powering up Sensor 0 and Sensor 2
rstb0_pin=49
rstb2_pin=2

# I2C slave addresses
# Note: Slave addresses and power on script may need to be changed to fit the actual hardware layout
dft_slv_addr=0x30 # Original slave address when the sensor is powered up
sns1_slv_addr=0x31 # Preferred slave address for sensor 1, this should fit the one in sensor_params.h
sns2_slv_addr=0x32 # Preferred slave address for sensor 2, this should fit the one in sensor_params.h

# Sensor 1 should have been powered up by the circuits
# Soft reset Sensor 1 if it has already been configured
i2crw -Wb -D0 -S"${sns1_slv_addr}" 0x0103 0x01 > /dev/null 2>&1
usleep 10

# Power down Sensor 0
echo ${rstb0_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb0_pin}/direction
echo 0 > /sys/class/gpio/gpio${rstb0_pin}/value

# Power down Sensor 2
echo ${rstb2_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb2_pin}/direction
echo 0 > /sys/class/gpio/gpio${rstb2_pin}/value

# Change Sensor 1's I2C slave address
i2crw -Wb -D0 -S"${dft_slv_addr}" 0x3004 $(($sns1_slv_addr * 2))

# Power up Sensor 2
echo 1 > /sys/class/gpio/gpio${rstb2_pin}/value
echo ${rstb2_pin} > /sys/class/gpio/unexport

# Change Sensor 2's I2C slave address
i2crw -Wb -D0 -S"${dft_slv_addr}" 0x3004 $(($sns2_slv_addr * 2))

# Power up Sensor 0
echo 1 > /sys/class/gpio/gpio${rstb0_pin}/value
echo ${rstb0_pin} > /sys/class/gpio/unexport

echo "Power on $SENSOR done"
