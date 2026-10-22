#!/bin/sh

# Disable AE - the sensor is not GC2083 yet
sed -i 's/is_ae_en = 1/is_ae_en = 0/g' /system/mpp/script/sensor_0.ini

# Start video system
/system/mpp/script/load_mpp.sh -i
/system/mpp/script/MIPI_Controller.sh
/system/mpp/script/Phy_board.sh
mpi_stream -d /system/mpp/case_config/agt785-1_640x480 > /dev/null &
sleep 20
echo trigger 1 > /dev/is

# FIXME move into senif driver after W08
devmem 0x83808404 32 0x002B0001
devmem 0x83808494 32 0x00000300
devmem 0x8380849C 32 0x00000001

testOnDemandRTSPServer 0 -n &
/system/mpp/script/OV5647_command.sh
