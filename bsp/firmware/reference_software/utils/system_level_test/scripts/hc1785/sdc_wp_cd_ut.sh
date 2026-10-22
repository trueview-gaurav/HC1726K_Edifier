#!/bin/sh

# --- Color Definitions ---
RED='\033[0;31m'  # ANSI code for Red color
BLUE='\033[0;34m' # ANSI code for Blue color definition
NC='\033[0m'      # ANSI code for No Color (resetting text formatting)

SDC_INTF_SIGNAL_SW_CTRL=0x82130008
SDC_INTF_SIGNAL_CTRL_EN=0x8213000C
SDHCI_WP_REG=0x82DFD024
SDHCI_CD_REG=0x82DFD024

read_intf_signal_sw_ctrl(){
    sdc_intf_signal_sw_ctrl=$(devmem $SDC_INTF_SIGNAL_SW_CTRL)
    sd_wp_from_csr=$(($sdc_intf_signal_sw_ctrl>>8 & 0x1))
    echo "$SDC_INTF_SIGNAL_SW_CTRL bit[8](sd_wp_from_csr) = $sd_wp_from_csr"
    sd_cd_from_csr=$(($sdc_intf_signal_sw_ctrl>>24 & 0x1))
    echo "$SDC_INTF_SIGNAL_SW_CTRL bit[24](sd_cd_from_csr) = $sd_cd_from_csr"
}

read_intf_signal_ctrl_en(){
    sdc_intf_signal_ctrl_en=$(devmem $SDC_INTF_SIGNAL_CTRL_EN)
    en_sd_wp_from_csr=$(($sdc_intf_signal_ctrl_en>>8 & 0x1))
    echo "$SDC_INTF_SIGNAL_CTRL_EN bit[8](en_sd_wp_from_csr) = $en_sd_wp_from_csr"
    en_sd_cd_from_csr=$(($sdc_intf_signal_ctrl_en>>24 & 0x1))
    echo "$SDC_INTF_SIGNAL_CTRL_EN bit[24](en_sd_cd_from_csr) = $en_sd_cd_from_csr"
}

check_cdetect(){
    echo -n "DW_MMC_CDETECT: "
    devmem $SDHCI_CD_REG
    dw_mmc_cdetect=$((($(devmem $SDHCI_CD_REG) >> 18) & 0x1))
    if [ "$dw_mmc_cdetect" != "$1" ] || [ "$sd_cd_from_csr" != "$1" ]; then
        cmp_flag=$(($cmp_flag+1))
    fi
}

check_wrtprt(){
    echo -n "DW_MMC_WRTPRT: "
    devmem $SDHCI_WP_REG
    dw_mmc_wrtprt=$((($(devmem $SDHCI_WP_REG) >> 19) & 0x1))
    if [ "$dw_mmc_wrtprt" != "$1" ] || [ "$sd_wp_from_csr" != "$1" ]; then
        cmp_flag=$(($cmp_flag+1))
    fi
}


cmp_flag=0

echo "Run $0"

# first time check sdc_intf_signal_sw_ctrl & sdc_intf_signal_ctrl_1
echo "1. default value"
read_intf_signal_sw_ctrl
read_intf_signal_ctrl_en


# second time check sdc_intf_signal_sw_ctrl & sdc_intf_signal_ctrl_1
echo "2. set SDC_INTF_SIGNAL_CTRL_EN = 1, SDC_INTF_SIGNAL_SW_CTRL = 0"
devmem $SDC_INTF_SIGNAL_CTRL_EN 32 $(($sdc_intf_signal_ctrl_en | (0x1<<8) | (0x1<<24)))
devmem $SDC_INTF_SIGNAL_SW_CTRL 32 $(($sdc_intf_signal_sw_ctrl & (0x0<<8) & (0x0<<24)))

read_intf_signal_sw_ctrl
read_intf_signal_ctrl_en
check_cdetect "0"
check_wrtprt "0"

# third time check sdc_intf_signal_sw_ctrl & sdc_intf_signal_ctrl_en
echo "3. set SDC_INTF_SIGNAL_CTRL_EN = 1, SDC_INTF_SIGNAL_SW_CTRL = 1"
devmem $SDC_INTF_SIGNAL_CTRL_EN 32 $(($sdc_intf_signal_ctrl_en | (0x1<<8) | (0x1<<24)))
devmem $SDC_INTF_SIGNAL_SW_CTRL 32 $(($sdc_intf_signal_sw_ctrl | (0x1<<8) | (0x1<<24)))

read_intf_signal_sw_ctrl
read_intf_signal_ctrl_en
check_cdetect "1"
check_wrtprt "1"

if [ "$cmp_flag" == "0" ]; then
    echo -e "${BLUE}Pass: WP/CD can be controlled by CSR${NC}"
else
    echo -e "${RED}Fail: WP/CD can not be controlled by CSR${NC}"
fi

# fourth time check sdc_intf_signal_sw_ctrl & sdc_intf_signal_ctrl_en
echo "4. set SDC_INTF_SIGNAL_CTRL_EN = 0, SDC_INTF_SIGNAL_SW_CTRL = 0"
devmem $SDC_INTF_SIGNAL_CTRL_EN 32 $(($sdc_intf_signal_ctrl_en & (0x0<<8) & (0x0<<24)))
devmem $SDC_INTF_SIGNAL_SW_CTRL 32 $(($sdc_intf_signal_sw_ctrl & (0x0<<8) & (0x0<<24)))

while true; do
    # Display prompt and wait for a single character input
    # -p: Display the prompt
    # -n 1: Read only one character
    # -r: Prevents backslash escapes
    read -r -n 1 -p "Enter command ('g' to continue, 'q' to quit): " char

    # Print a newline for cleaner output after reading the character
    echo

    # Case statement to handle the input character
    case "$char" in
        # If input is 'g' (continue)
        [gG])
            echo -e "${BLUE}Card detect:${NC}$((($(devmem $SDHCI_CD_REG) >> 18) & 0x1))"
            echo -e "${BLUE}Wrte protect:${NC}$((($(devmem $SDHCI_WP_REG) >> 19) & 0x1))"
            # No 'break' or 'exit', so the loop naturally repeats (continues)
            ;;

        # If input is 'q' (quit)
        [qQ])
            echo -e "${BLUE}Exiting the loop. Goodbye!${NC}"
            break # Exit the while loop
            ;;

        # If input is any other character
        *)
            echo "Invalid input: '$char'. Please enter 'g' or 'q'."
            ;;
    esac
done

echo -e "${BLUE}UT finished.${NC}"
