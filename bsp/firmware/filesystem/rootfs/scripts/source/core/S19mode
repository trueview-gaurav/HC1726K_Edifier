#!/bin/sh

#
# AUGENTIX INC. - PROPRIETARY
#
# S04mode - System mode statments and mode-specific rcS/rcK
# Copyright (C) 2018 Augentix Inc. - All Rights Reserved
#
# NOTICE: The information contained herein is the property of Augentix Inc.
# Copying and distributing of this file, via any medium,
# must be licensed by Augentix Inc.
#
# * Author: ShihChieh Lin <shihchieh.lin@augentix.com>
#

MODE=/system/bin/mode
new_mode=/usrdata/new_mode
reset_file="/usrdata/reset_file"

calib_dir=/calib/factory_default

rcS() {
	# update system mode if a new one exists
	$MODE -u
	mode=$($MODE)
	echo "Current system mode: $mode"

	# Start all init scripts in /etc/init.d/MODE
	# executing them in numerical order.
	#
	for i in /etc/init.d/$mode/S??* ;do

		# Ignore dangling symlinks (if any).
		[ ! -f "$i" ] && continue
		case "$i" in
		*.sh)
		    # Source shell script for speed.
		    (
			trap - INT QUIT TSTP
			set start
			. $i
		    )
		    ;;
		*)
		    # No sh extension, so fork subprocess.
		    $i start
		    ;;
		esac
	done

}

rcK() {
	mode=$($MODE)
	# Stop all init scripts in /etc/init.d
	# executing them in reversed numerical order.
	#
	for i in $(ls -r /etc/init.d/$mode/S??*) ;do

	# Ignore dangling symlinks (if any).
	[ ! -f "$i" ] && continue

	case "$i" in
	*.sh)
		# Source shell script for speed.
		(
			trap - INT QUIT TSTP
			set stop
			. $i
		)
		;;
	*)
		# No sh extension, so fork subprocess.
		$i stop
		;;
		esac
	done
}

case "$1" in
start)
	rcS
	;;
stop)
	rcK
	;;
restart|reload)
	rcK
	rcS
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac

exit $?
