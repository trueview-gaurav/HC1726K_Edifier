#!/bin/sh

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/root/bin:/system/bin

# set video streaming client IP
CLIENT_IP=192.168.10.xx

do_aplay () {
	for i in $(seq 0 1000)
	do
		aplay -t raw -f S16_LE -r 48000 /tmp/test.raw > /dev/null 2>&1
		sleep 1
	done
}

if [ "$CLIENT_IP" == "192.168.10.xx" ]
then
    echo "==============================="
    echo "Please set CLIENT_IP in slt.sh"
    echo "==============================="
    exit
else
	true
fi

# remount /usrdata to avoid data broken
mount -o remount,ro /usrdata

# verify eFuse
/usrdata/efuse_verify.sh

# load mpp drivers for video and audio
/system/mpp/script/load_mpp.sh -i

# test audio input
arecord -t raw -f S16_LE -r 48000 -d 5 /tmp/test.raw > /dev/null 2>&1 &

sleep 5

# test video streaming with ethernet
mpi_stream -d /system/mpp/case_config/case_config_1004_FHD > /dev/null 2>&1 &

sleep 3

testOnDemandRTSPServer 0 -n 2>&1 | grep URL &

# check video frame rate and also test audio output at the same time
sleep 1
echo "==============================="
cat /dev/is | grep "^Frame"
echo "==============================="
sleep 10
cat /dev/is | grep "^Frame"
echo "==============================="
sensor_ini='/system/mpp/script/sensor_0.ini'
sensor_fps=$(sed -n 's/^frame_rate[[:space:]]*=[[:space:] ]*\([0-9.]*\)$/\1/p' ${sensor_ini})
frames=$(awk "BEGIN { printf \"%.0f\", $sensor_fps * 10 }")
echo "In ${sensor_ini}, frame_rate = ${sensor_fps}. You should see ${frames} frames after 10 seconds." 

# test usb
/usrdata/slt_usb.sh

# test sd card
/usrdata/slt_sdc.sh

do_aplay &
