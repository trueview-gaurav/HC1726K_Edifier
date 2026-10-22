#!/bin/sh
#
# Start logging
#

[ -r /etc/default/logging ] && . /etc/default/logging

syslog_cfg=/tmp/syslog.conf

SYSLOGD_ARGS="-S -n -f $syslog_cfg"
KLOGD_ARGS=-n

# TZ file path
TZ="/etc/TZ"

start() {
	# get Timezone
	if [ -e "$TZ" ]; then
		export TZ=$(cat /etc/TZ)
	fi

	# get syslog
	if [ ! -f $syslog_cfg ]; then
		cp -f /etc/syslog.conf $syslog_cfg
	fi

	printf "Starting logging: "
	start-stop-daemon -b -S -q -m -p /var/run/syslogd.pid --exec /sbin/syslogd -- $SYSLOGD_ARGS
	start-stop-daemon -b -S -q -m -p /var/run/klogd.pid --exec /sbin/klogd -- $KLOGD_ARGS
	echo "OK"
}

stop() {
	printf "Stopping logging: "
	start-stop-daemon -K -q -p /var/run/syslogd.pid
	start-stop-daemon -K -q -p /var/run/klogd.pid
	echo "OK"
}

case "$1" in
  start)
	start
	;;
  stop)
	stop
	;;
  restart|reload)
	stop
	start
	;;
  *)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac

exit $?
