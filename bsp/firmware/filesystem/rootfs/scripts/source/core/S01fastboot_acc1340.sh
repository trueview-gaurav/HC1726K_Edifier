#!/bin/sh
export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/root/bin:/system/bin

do_mmc() {
	busybox modprobe dw_mmc-host
	busybox modprobe mmc_block
}

do_video() {
	echo "[DEBUG] S01fastboot do_stream begin"
	# shellcheck source=/dev/null
	. /etc/fastboot_video start
	echo "[DEBUG] S01fastboot do_stream end"
}

do_usb() {
	busybox modprobe dwc2
}

do_late_insmod() {
	sleep 2
	do_usb &
}

do_start() {
	do_mmc &
	do_video
	do_late_insmod &
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

