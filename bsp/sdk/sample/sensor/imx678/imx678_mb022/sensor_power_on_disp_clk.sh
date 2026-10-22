#!/bin/sh
# This script uses DISP_CLK instead of SENSOR_OUT_CLK for sensor clock, but set DISP_CLK to 24 MHz.

SENSOR=IMX678

echo "Start to power on $SENSOR"

# set DISP_CLK to 24MHz
devmem 0x8340008C 32 0x00000000
devmem 0x83400098 32 0x01010101
devmem 0x834000A8 32 0x00000002
devmem 0x834000AC 32 0x01020002
devmem 0x834000B4 32 0x00140010
devmem 0x834000B8 32 0x00141414
devmem 0x834000BC 32 0x00000000
devmem 0x834000C4 32 0x00000401
devmem 0x834000CC 32 0x00000000
devmem 0x8340008C 32 0x00000100
usleep 10
devmem 0x834000A8 32 0x0F000002

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value
usleep 10

echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport
usleep 10

# CLK and IOMUX
devmem 0x80001508 32 0x00030000 # increase driving strength
devmem 0x8000164C 32 0x00000003 # use DISPIF_CLK
usleep 20

echo "Power on $SENSOR done"
