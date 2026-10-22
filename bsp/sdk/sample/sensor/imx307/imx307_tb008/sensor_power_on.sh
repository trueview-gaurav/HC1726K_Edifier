#!/bin/sh

SENSOR=IMX307

echo "Start to power on $SENSOR"

# turn off 24MHz sensor clock
snsclk_pin=47
echo ${snsclk_pin}    > /sys/class/gpio/export
echo "in" > /sys/class/gpio/gpio${snsclk_pin}/direction
echo ${snsclk_pin}    > /sys/class/gpio/unexport
# disable original sensor clock
# csr io.pioc.pad_sensor_clk_iosel 0
devmem 0x80001604 32 0x00000000

# clock settings
devmem 0x8340008C 32 0x01000000 #FPLL_ENABLE0
devmem 0x83400098 32 0x01010101 #FPLL_DIG_EN
devmem 0x834000A8 32 0x00000301 #FPLL_LF_SEL
devmem 0x834000AC 32 0x01020002 #FPLL_LPF_SEL
devmem 0x834000B4 32 0x00420123 #FPLL_DIV_SEL
devmem 0x834000B8 32 0x01010410 #FPLL_POST_DIV_SEL
devmem 0x834000BC 32 0x00000000 #FPLL_POSTDIV_CLKIN_SEL
devmem 0x834000C4 32 0x00000401 #FPLL_MON_CLK_SEL
devmem 0x834000CC 32 0x00000000 #FPLL_SSCG_F
devmem 0x8340008C 32 0x01000100 #FPLL_ENABLE0
usleep 10
devmem 0x834000A8 32 0x0F000305 #FPLL_LF_SEL

# XCE is fixed to high

# Initialize XCLR as low
# sensor_rstb (gpio 49), output_enable:1, output_value:0
rstb_pin=49
echo ${rstb_pin}    > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# CLK and IOMUX
devmem 0x80001508 32 0x00030000 # increase driving strength
devmem 0x8000164C 32 0x00000003 # use DISPIF_CLK

# INCK -> Clear OFF (Tlow) (min 500ns)
usleep 1

# Setting XCLR high
# sensor_rstb (gpio 49), output_enable:1, output_value:1
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin}    > /sys/class/gpio/unexport

# Clear OFF -> Communication start (Txce) (min 20us)
usleep 25

echo "Power on $SENSOR done"

