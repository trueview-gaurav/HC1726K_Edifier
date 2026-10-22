#!/bin/sh
export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/root/bin:/system/bin
pir_pin=33
irled_pin=2

do_mmc() {
	# Load mmc_block.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/mmc/card/mmc_block.ko ]; then
		busybox modprobe mmc_block.ko
	fi
}

do_wlan() {
	. /etc/fastboot_video start
}

do_video_probe() {
	busybox modprobe otp_ep
	busybox modprobe mpp.ko
}

do_audio_probe() {
	busybox modprobe audio_pcm.ko
	busybox modprobe audio_machine.ko
}

do_tutk_service() {
	echo 'se' 100 > /proc/p824m
	echo 'bl' 2 > /proc/p824m
	echo 'tutk_service start...'
	/system/bin/tutk_service -w -i /system/tutk_service_config/agt_ma300027_v1.json -bl > /dev/console &
}

do_start() {
	do_video_probe

	echo $pir_pin > /sys/class/gpio/export
	ret="`cat /sys/class/gpio/gpio$pir_pin/value`"

	echo $irled_pin > /sys/class/gpio/export
	ret1="`cat /sys/class/gpio/gpio$irled_pin/value`"

	if [ "$ret1" -eq "0" ]; then
		export DIP_INTL_INI_PATH=/system/mpp/script/dip_extend_0.ini
		iq_file=/system/mpp/script/sensor_0.ini
	else
		export DIP_INTL_INI_PATH=/system/mpp/script/dip_extend_ir_0.ini
		iq_file=/system/mpp/script/sensor_ir_0.ini

	fi

	# if it is not pir event
	if [ "$ret" -eq "0" ]; then
		do_wlan
		do_tutk_service
		echo 'mpi_stream start...'
		mpi_stream -d /system/mpp/case_config/DBT102-1 -s0,day,$iq_file -g0,$irled_pin,high > /dev/null &
		sleep 0.5
		do_audio_probe
	else
		do_wlan
		do_audio_probe
		mkdir -p /tmp/record
		echo 'mpi_stream start...'
		mpi_stream -d /system/mpp/case_config/DBT102-1 -s0,day,$iq_file -g0,$irled_pin,high -penc_idx=0 -precord_enable=1 -pframe_num=-150 -poutput_file=/tmp/record/%F_%H%M%S.mp4 -pmax_dumped_files=3 > /dev/null &
		sleep 0.5
		do_tutk_service
	fi

	sleep 2
	do_mmc
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
