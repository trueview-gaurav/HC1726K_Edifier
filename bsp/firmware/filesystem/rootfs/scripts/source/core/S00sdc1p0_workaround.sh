#!/bin/sh
#
# Kyoto chip sdc1p0 workaround
# For details, please refer to #41077
#

case "$1" in
	start)
		# wifi en gpio5
		echo 65 > /sys/class/gpio/export
		echo "out" > /sys/class/gpio/gpio65/direction
		echo 0 > /sys/class/gpio/gpio65/value
		;;
	stop)
		;;
	*)
		echo "Usage: $0 {start|stop}"
		exit 1
esac

exit $?

