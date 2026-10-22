#!/bin/sh

echo "Unit Test SDC-3"

# reset CSR value
devmem 0x800004A8 32 0x1
devmem 0x800004A8 32 0x3
sleep 0.1
devmem 0x800004A8 32 0x2
devmem 0x800004A8 32 0x0

# origin CSR value
ori_sdc_ip_pwren=$(devmem 0x818A0004)
echo "SDC_IP_PWREN (origin) = $ori_sdc_ip_pwren"

ori_sdc_intf_signal_ctrl_0=$(devmem 0x81340008)
echo "SDC_INTF_SIGNAL_CTRL_0 (origin) = $ori_sdc_intf_signal_ctrl_0"

# modified CSR value
mo_sdc_ip_pwren=$(($ori_sdc_ip_pwren | 0x3))
devmem 0x818A0004 32 $mo_sdc_ip_pwren
mo_sdc_intf_signal_ctrl_0=$(($ori_sdc_intf_signal_ctrl_0 | 0x1010101))
devmem 0x81340008 32 $mo_sdc_intf_signal_ctrl_0

mo_sdc_ip_pwren=$(devmem 0x818A0004)
echo "SDC_IP_PWREN (modified) = $mo_sdc_ip_pwren"

mo_sdc_intf_signal_ctrl_0=$(devmem 0x81340008)
echo "SDC_INTF_SIGNAL_CTRL_0 (modified) = $mo_sdc_intf_signal_ctrl_0"

# reset CSR value
devmem 0x800004A8 32 0x1
devmem 0x800004A8 32 0x3
sleep 0.1
devmem 0x800004A8 32 0x2
devmem 0x800004A8 32 0x0

re_sdc_ip_pwren=$(devmem 0x818A0004)
echo "SDC_IP_PWREN (after reset) = $re_sdc_ip_pwren"

re_sdc_intf_signal_ctrl_0=$(devmem 0x81340008)
echo "SDC_INTF_SIGNAL_CTRL_0 (after reset) = $re_sdc_intf_signal_ctrl_0"

if [ "$ori_sdc_ip_pwren" == "$re_sdc_ip_pwren" ] && [ "$ori_sdc_intf_signal_ctrl_0" == "$re_sdc_intf_signal_ctrl_0" ]; then
    echo "Pass: The CSR value go to default after reset."
else
    echo "Fail: The CSR value can't go to default after reset."
fi