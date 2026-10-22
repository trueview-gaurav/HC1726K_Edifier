#!/bin/sh

SENSOR=SC3035D

echo "Start to power on $SENSOR"

# control pin definition
rstb_pin=61 # PWM3
csr ioc.ioc.pwm3_iosel 0
pwdn_pin=60 # PWM6
csr ioc.ioc.pwm6_iosel 0

# DVP3 pins settings
# D0~D3 share LVDS data pins
csr ioc.ioc.pwm4_iosel 4 # D4 backup
csr ioc.ioc.pwm5_iosel 4 # D5 backup
csr ioc.ioc.dvp_d10_iosel 4 # D6 backup
csr ioc.ioc.dvp_d11_iosel 4 # D7 backup
csr ioc.ioc.dvp_d8_iosel 1 # D8
csr ioc.ioc.dvp_d9_iosel 1 # D9
csr ioc.ioc.spi1_ck_iosel 4 # D10 backup
csr ioc.ioc.spi1_sdi_iosel 4 # D11 backup
csr ioc.ioc.dvp_hsync_iosel 1 # DVP HSYNC
# DVP VSYNC shares LVDS clock lane
# DVP CLK shares LVDS clock lane

# DVP3 senif settings
csr senif.senif.sync_det_mode 0
csr senif.senif.dvp_src_b0_sel 0
csr senif.senif.dvp_src_b1_sel 0
csr senif.senif.dvp_src_b2_sel 0
csr senif.senif.dvp_src_b3_sel 0
csr senif.senif.dvp_src_b4_sel 2
csr senif.senif.dvp_src_b5_sel 2
csr senif.senif.dvp_src_b6_sel 2
csr senif.senif.dvp_src_b7_sel 2
csr senif.senif.dvp_src_b8_sel 0
csr senif.senif.dvp_src_b9_sel 0
csr senif.senif.dvp_src_b10_sel 2
csr senif.senif.dvp_src_b11_sel 2
csr senif.senif.dvp_src_hsync_sel 0
csr senif.senif.dvp_src_vsync_sel 0
csr senif.senif.sensor_sync_mode 0

# change SENIF/IS clock to DVP1 PCLK
csr pc.pc.cken_is 0
usleep 10
csr pc.pc.cksel_is 10 # DVP1 inverse
csr pc.pc.div_sel_is 0
csr pc.pc.cken_is 1

# reset SENIF / IS
csr pc.pc.sw_rst_senif 1
csr pc.pc.sw_rst_sub_senif 1
csr pc.pc.sw_rst_is 1
usleep 5
csr pc.pc.sw_rst_senif 0
csr pc.pc.sw_rst_sub_senif 0
csr pc.pc.sw_rst_is 0

# Initialize control pins
echo ${rstb_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${rstb_pin}/direction
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value

echo ${pwdn_pin} > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio${pwdn_pin}/direction
echo 1     > /sys/class/gpio/gpio${pwdn_pin}/value

# Enable 24MHz clock to sensor
csr ioc.ioc.sensor_clk_iosel  1; #set mux pin as sensor clock
csr pc.pc.cksel_sensor        0; #set sensor clock reference system clock
csr pc.pc.div_sel_sensor      0; #set div value
csr pc.pc.cken_sensor         1; #clock output enable

# hold PWDN, 100ms (T1)
sleep 1

# pull down PWDN
echo 0     > /sys/class/gpio/gpio${pwdn_pin}/value
echo ${pwdn_pin} > /sys/class/gpio/unexport

# hold RSTB, 5ms (T2)
usleep 6000

# pull down RSTB
echo 0     > /sys/class/gpio/gpio${rstb_pin}/value

# hold RSTB, 1ms (T3)
usleep 2000

# pull up RSTB
echo 1     > /sys/class/gpio/gpio${rstb_pin}/value
echo ${rstb_pin} > /sys/class/gpio/unexport

# I2C ready, 1ms (T4)
usleep 2000

# turn off the sensor in default
i2crw -Wb -D1 -S0x30 0x0100 0x00

echo "Power on $SENSOR done"
