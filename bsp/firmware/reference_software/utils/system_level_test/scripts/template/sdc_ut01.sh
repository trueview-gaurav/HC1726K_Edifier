#!/bin/sh

read_intf_signal_ctrl_0(){
    sdc_intf_signal_ctrl_0=$(devmem 0x81340008)
    sd_wp_from_csr=$(($sdc_intf_signal_ctrl_0>>8 & 0x1))
    echo "SDC_INTF_SIGNAL_CTRL_0 bit[8](sd_wp_from_csr) = $sd_wp_from_csr"
    sd_cd_from_csr=$(($sdc_intf_signal_ctrl_0>>24 & 0x1))
    echo "SDC_INTF_SIGNAL_CTRL_0 bit[24](sd_cd_from_csr) = $sd_cd_from_csr"
}

read_intf_signal_ctrl_1(){
    sdc_intf_signal_ctrl_1=$(devmem 0x8134000C)
    en_sd_wp_from_csr=$(($sdc_intf_signal_ctrl_1>>8 & 0x1))
    echo "SDC_INTF_SIGNAL_CTRL_1 bit[8](en_sd_wp_from_csr) = $en_sd_wp_from_csr"
    en_sd_cd_from_csr=$(($sdc_intf_signal_ctrl_1>>24 & 0x1))
    echo "SDC_INTF_SIGNAL_CTRL_1 bit[24](en_sd_cd_from_csr) = $en_sd_cd_from_csr"
}

check_cdetect(){
    echo -n "DW_MMC_CDETECT: "
    devmem 0x818A0050
    dw_mmc_cdetect=$(($(devmem 0x818A0050) & 0x1))
    if [ "$dw_mmc_cdetect" != "$1" ] || [ "$sd_cd_from_csr" != "$1" ]; then
        cmp_flag=$(($cmp_flag+1))
    fi
}

check_wrtprt(){
    echo -n "DW_MMC_WRTPRT: "
    devmem 0x818A0054
    dw_mmc_wrtprt=$(($(devmem 0x818A0054) & 0x1))
    if [ "$dw_mmc_wrtprt" != "$1" ] || [ "$sd_wp_from_csr" != "$1" ]; then
        cmp_flag=$(($cmp_flag+1))
    fi
}


cmp_flag=0

echo "Unit Test SDC-1"

# first time check sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
echo "1. default value"
read_intf_signal_ctrl_0
read_intf_signal_ctrl_1

# set 0/1 to sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
devmem 0x8134000C 32 $(($sdc_intf_signal_ctrl_1 | (0x1<<8) | (0x1<<24)))
devmem 0x81340008 32 $(($sdc_intf_signal_ctrl_0 & (0x0<<8) & (0x0<<24)))

# second time check sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
echo "2. set sdc_intf_signal_ctrl_1 = 1, sdc_intf_signal_ctrl_0 = 0"
read_intf_signal_ctrl_0
read_intf_signal_ctrl_1
check_cdetect "0"
check_wrtprt "0"

# set 1/1 to sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
devmem 0x8134000C 32 $(($sdc_intf_signal_ctrl_1 | (0x1<<8) | (0x1<<24)))
devmem 0x81340008 32 $(($sdc_intf_signal_ctrl_0 | (0x1<<8) | (0x1<<24)))

# third time check sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
echo "3. set sdc_intf_signal_ctrl_1 = 1, sdc_intf_signal_ctrl_0 = 1"
read_intf_signal_ctrl_0
read_intf_signal_ctrl_1
check_cdetect "1"
check_wrtprt "1"

# set 0/0 to sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
devmem 0x8134000C 32 $(($sdc_intf_signal_ctrl_1 & (0x0<<8) & (0x0<<24)))
devmem 0x81340008 32 $(($sdc_intf_signal_ctrl_0 & (0x0<<8) & (0x0<<24)))

# fourth time check sdc_intf_signal_ctrl_0 & sdc_intf_signal_ctrl_1
echo "4. set sdc_intf_signal_ctrl_1 = 0, sdc_intf_signal_ctrl_0 = 0"
read_intf_signal_ctrl_0
read_intf_signal_ctrl_1
check_cdetect "0"
check_wrtprt "0"

if [ "$cmp_flag" == "0" ]; then
    echo "Pass: WP/CD can be controlled by CSR"
else
    echo "Fail: WP/CD can not be controlled by CSR"
fi