#!/bin/sh
# --- Color Definitions ---
RED='\033[0;31m'  # ANSI code for Red color
BLUE='\033[0;34m' # ANSI code for Blue color definition
NC='\033[0m'      # ANSI code for No Color (resetting text formatting)

SDC_INTF_SIGNAL_SW_CTRL=0x82130008
SDC_INTF_SIGNAL_CTRL_EN=0x8213000C
SDHCI_CLK_REG=0x82DFD02C

# refers sdhci.c::sdhci_calc_clk()
set_sdhci_clock(){
    # 1. disable clock
    tmp_clk_csr=$(($(devmem $SDHCI_CLK_REG) & ~0x1))

    # 2. set clock to desired speed and enable clock
    devmem $SDHCI_CLK_REG 32 &(&tmp_clk_csr | (($1)<<8) | 0x1)

    # 3. Wait for Internal Clock Stability (Polling ICS Bit 1)
    echo "Step 3: Polling for Internal Clock Stable (ICS)..."
    COUNT=0
    STABLE=0
    while [ $COUNT -lt 100 ]; do
        # Read register value to check status bits
        CHECK_VAL=$(devmem $SDHCI_CLK_REG)
    
        # Check Bit 1: ICS (Internal Clock Stable) - Read Only
        STABLE=$(( (CHECK_VAL >> 1) & 0x1 ))
    
        if [ "$STABLE" -eq 1 ]; then
            echo "Clock is stable!"
            break
        fi
    
        COUNT=$((COUNT + 1))
        sleep 0.01
    done

    # Check for Timeout
    if [ "$STABLE" -ne 1 ]; then
        echo "ERROR: Internal Clock Stability Timeout!"
    fi
}

echo "$0"

echo "Clock division is 2*n."
echo "0 = bypass, 1 means divide by 2*1 = 2, ..."

read -r -n 1 -p "Enter to continue: "
echo

set_sdhci_clock "1"
sdc_ip_clkdiv=$(devmem $SDHCI_CLK_REG)
echo "SDHCI_CLK_REG = $sdc_ip_clkdiv"

#direct write
dd if=/dev/zero of=/mnt/sdcard/test bs=1M count=10 oflag=direct

#direct read
dd if=/mnt/sdcard/test of=/dev/null bs=1M count=10 iflag=direct

read -r -n 1 -p "Enter to continue: "
echo
set_sdhci_clock "2"
sdc_ip_clkdiv=$(devmem $SDHCI_CLK_REGG)
echo "SDHCI_CLK_REG = $sdc_ip_clkdiv"

#direct write
dd if=/dev/zero of=/mnt/sdcard/test bs=1M count=10 oflag=direct

#direct read
dd if=/mnt/sdcard/test of=/dev/null bs=1M count=10 iflag=direct

read -r -n 1 -p "Enter to continue: "
echo
set_sdhci_clock "3"
sdc_ip_clkdiv=$(devmem $SDHCI_CLK_REG)
echo "SDHCI_CLK_REG = $sdc_ip_clkdiv"

#direct write
dd if=/dev/zero of=/mnt/sdcard/test bs=1M count=10 oflag=direct

#direct read
dd if=/mnt/sdcard/test of=/dev/null bs=1M count=10 iflag=direct
