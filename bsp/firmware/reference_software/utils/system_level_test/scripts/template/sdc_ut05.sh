#!/bin/sh

# refers dw_mmc.c::sw_mci_setup_bus()
set_sdc_clock(){
    # disable clock
    devmem 0x818A0010 32 0x0
    devmem 0x818A000C 32 0x0

    # inform CIU
    devmem 0x818A0028 32 0x0
    devmem 0x818A002C 32 0x80202000

    # set clock to desired speed
    devmem 0x818A0008 32 $1

    # inform CIU
    devmem 0x818A0028 32 0x0
    devmem 0x818A002C 32 0x80202000

    #enable clock
    devmem 0x818A0010 32 0x00010001

    # inform CIU
    devmem 0x818A0028 32 0x0
    devmem 0x818A002C 32 0x80202000
}

echo "Unit Test SDC-5"

echo "Clock division is 2*n."
echo "0 = bypass, 1 means divide by 2*1 = 2, ..."

set_sdc_clock "1"
sdc_ip_clkdiv=$(devmem 0x818A0008)
echo "SDC_IP_CLKDIV = $sdc_ip_clkdiv"

#direct write
dd if=/dev/zero of=/mnt/sdcard/test bs=1M count=10 oflag=direct

#direct read
dd if=/mnt/sdcard/test of=/dev/null bs=1M count=10 iflag=direct


set_sdc_clock "2"
sdc_ip_clkdiv=$(devmem 0x818A0008)
echo "SDC_IP_CLKDIV = $sdc_ip_clkdiv"

#direct write
dd if=/dev/zero of=/mnt/sdcard/test bs=1M count=10 oflag=direct

#direct read
dd if=/mnt/sdcard/test of=/dev/null bs=1M count=10 iflag=direct


set_sdc_clock "3"
sdc_ip_clkdiv=$(devmem 0x818A0008)
echo "SDC_IP_CLKDIV = $sdc_ip_clkdiv"

#direct write
dd if=/dev/zero of=/mnt/sdcard/test bs=1M count=10 oflag=direct

#direct read
dd if=/mnt/sdcard/test of=/dev/null bs=1M count=10 iflag=direct
