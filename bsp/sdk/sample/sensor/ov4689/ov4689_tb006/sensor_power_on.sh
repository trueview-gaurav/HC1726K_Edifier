#!/bin/sh

SENSOR=OV4689
echo "Start to power on $SENSOR"

# sensor_rstb (gpio 49), output_enable:1, output_value:0
sensor_rstb_offset=17
gpio_o=$(printf "%d\n" $(devmem 0x80001818))
gpio_oe=$(printf "%d\n" $(devmem 0x8000181C))
gpio_sensor_rstb_mask=$(printf "%d\n" 0xFFFDFFFF)
gpio_o=$((${gpio_o} & ${gpio_sensor_rstb_mask}))
devmem 0x80001818 32 ${gpio_o}
gpio_oe=$((${gpio_oe} | $((1 << ${sensor_rstb_offset}))))
devmem 0x8000181C 32 ${gpio_oe}

# TODO: sensor clk 24Mhz enable

# External clock settle time (min 0us)
# usleep 1

# sensor_rstb (gpio 49), output_enable:1, output_value:1
gpio_o=$((${gpio_o} | $((1 << ${sensor_rstb_offset}))))
devmem 0x80001818 32 ${gpio_o}

# XSHUTDOWN raising -> first SCCB transaction (min 8192 external clock cycles)
usleep 500

echo "Power on $SENSOR done"

