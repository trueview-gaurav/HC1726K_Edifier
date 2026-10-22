#!/bin/sh

export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/root/bin:/system/bin
irled_pin=2

probe_video() {
	busybox modprobe otp_ep
	busybox modprobe mpp.ko
	echo g_rgl_qp=2,60,2,60,0,0,45,8,2,6,300000,800000,500,3000,40,51,40,51,400000,800000,500,3000,0,0,0,0,20000000,20000000,4,100,300,0,0,-1 > /dev/enc
	echo $irled_pin > /sys/class/gpio/export
	ret="`cat /sys/class/gpio/gpio$irled_pin/value`"
	if [ "$ret" -eq "0" ]; then
		export DIP_INTL_INI_PATH=/system/mpp/script/dip_extend_0.ini
		iq_file=/system/mpp/script/sensor_0.ini
	else
		export DIP_INTL_INI_PATH=/system/mpp/script/dip_extend_ir_0.ini
		iq_file=/system/mpp/script/sensor_ir_0.ini
	fi
}

probe_audio() {
	busybox modprobe audio_pcm.ko
	busybox modprobe audio_machine.ko
}

start_fastboot_video() {
	. /etc/fastboot_video start
}

start_p2p_service() {
	echo 'se' 100 > /proc/p824m
	echo 'bl' 2 > /proc/p824m
	/system/bin/tange_cloud -v 6 &
}

probe_mmc() {
	# Load mmc_block.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/mmc/card/mmc_block.ko ]; then
		busybox modprobe mmc_block.ko
	fi
}

do_start() {
	probe_video
	start_fastboot_video
	probe_audio
	start_p2p_service
	echo 'Starting mpi_stream...'
	/system/bin/mpi_stream -d /system/mpp/case_config/DBT102-2 -s0,day,$iq_file -g0,$irled_pin,high > /dev/null &

	sleep 2
	probe_mmc
}

case "$1" in
	start)
		do_start
		;;
	stop)
		;;
	*)
		echo "Usage: $0 {start|stop}"
esac
