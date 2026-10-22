#!/bin/sh

# --- Color Definitions ---
RED='\033[0;31m'  # ANSI code for Red color
BLUE='\033[0;34m' # ANSI code for Blue color definition
NC='\033[0m'      # ANSI code for No Color (resetting text formatting)

SDC_INTF_SIGNAL_SW_CTRL=0x82130008
CHIP_RESET_GEN_SDC0_REG=0x820004BC
CHIP_RESET_GEN_SDC0_HOLD=0x3
CHIP_RESET_GEN_SDC0_RELEASE=0x0
SDHCI0_REG_PWREN=0x82DFD029

echo "Run $0"

# reset CSR value
devmem $CHIP_RESET_GEN_SDC0_REG 32 $CHIP_RESET_GEN_SDC0_HOLD
sleep 0.1
devmem $CHIP_RESET_GEN_SDC0_REG 32 $CHIP_RESET_GEN_SDC0_RELEASE

#Show origin CSR value
ori_sdc_ip_pwren=$(devmem $SDHCI0_REG_PWREN)
echo -e "SDC_IP_PWREN ${BLUE}(origin)${NC} = $ori_sdc_ip_pwren"
ori_sdc_intf_signal_sw_ctrl=$(devmem $SDC_INTF_SIGNAL_SW_CTRL)
echo -e "SDC_INTF_SIGNAL_SW_CTRL ${BLUE}(origin)${NC} = $ori_sdc_intf_signal_sw_ctrl"

# modified CSR value
mo_sdc_ip_pwren=$(($ori_sdc_ip_pwren | 0xf))
devmem $SDHCI0_REG_PWREN 32 $mo_sdc_ip_pwren
mo_sdc_intf_signal_sw_ctrl=$(($ori_sdc_intf_signal_sw_ctrl | 0x1010101))
devmem $SDC_INTF_SIGNAL_SW_CTRL 32 $mo_sdc_intf_signal_sw_ctrl

# Show modified CSR value
mo_sdc_ip_pwren=$(devmem $SDHCI0_REG_PWREN)
echo -e "SDC_IP_PWREN ${BLUE}(modified)${NC} = $mo_sdc_ip_pwren"
mo_sdc_intf_signal_sw_ctrl=$(devmem $SDC_INTF_SIGNAL_SW_CTRL)
echo -e "SDC_INTF_SIGNAL_SW_CTRL ${BLUE}(modified)${NC} = $mo_sdc_intf_signal_sw_ctrl"

# reset CSR value
devmem $CHIP_RESET_GEN_SDC0_REG 32 $CHIP_RESET_GEN_SDC0_HOLD
sleep 0.1
devmem $CHIP_RESET_GEN_SDC0_REG 32 $CHIP_RESET_GEN_SDC0_RELEASE

# Show reset CSR value
re_sdc_ip_pwren=$(devmem $SDHCI0_REG_PWREN)
echo -e "SDC_IP_PWREN ${BLUE}(after reset)${NC} = $re_sdc_ip_pwren"
re_sdc_intf_signal_sw_ctrl=$(devmem $SDC_INTF_SIGNAL_SW_CTRL)
echo -e "SDC_INTF_SIGNAL_SW_CTRL ${BLUE}(after reset)${NC} = $re_sdc_intf_signal_sw_ctrl"

# Show Result
if [ "$ori_sdc_ip_pwren" == "$re_sdc_ip_pwren" ] && [ "$ori_sdc_intf_signal_sw_ctrl" == "$re_sdc_intf_signal_sw_ctrl" ]; then
    echo -e "${BLUE}Pass: The CSR value go to default after reset.${NC}"
else
    echo -e "${RED}Fail: The CSR value can't go to default after reset.${NC}"
fi