#!/bin/sh

echo "Run $0"

echo -n "SDC_CLK_PHASE_SHIFT_CTRL: "
devmem 0x82130004

sdc_clk_phase_shift_ctrl=$(devmem 0x82130004)
sdc_spl_phase_sel=$(($sdc_clk_phase_shift_ctrl & 0x3))
echo "SDC_CLK_PHASE_SHIFT_CTRL bit[1:0] = $sdc_spl_phase_sel"
sdc_drv_phase_sel=$(($sdc_clk_phase_shift_ctrl>>8 & 0x3))
echo "SDC_CLK_PHASE_SHIFT_CTRL bit[9:8] = $sdc_drv_phase_sel"

echo "workflow:"
echo "1. set sdc_drv_phase_sel:"
echo "$ devmem 0x82130004 32 0x0 --> degree 0"
echo "or $ devmem 0x82130004 32 0x100 --> degree 90"
echo "or $ devmem 0x82130004 32 0x200 --> degree 180"
echo "or $ devmem 0x82130004 32 0x300 --> degree 270"
echo "2. write data to sdcard:"
echo "$ dd if=/dev/urandom of=/tmp/golden_file bs=512 count=1 conv=fsync"
echo "$ cp /tmp/golden_file /mnt/sdcard/sdc_write"
echo "$ sync"
echo "3. check the waveform of the data shifts as expected"
