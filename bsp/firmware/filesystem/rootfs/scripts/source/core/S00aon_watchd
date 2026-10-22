#! /bin/sh

NAME=watchd
DAEMON=/usr/sbin/watchd

# Gracefully exit if the package has been removed.
test -x $DAEMON || exit 0

# Read config file if it is present.
if [ -r /etc/default/$NAME ]
then
  . /etc/default/$NAME
fi

case "$1" in
  start)
    ;;
  stop)
    printf "AON WATCHDOG force to reboot\n"
    echo '' > /dev/watchdog
    ;;
  halt)
   ;;
  restart|reload)
    ;;
  *)
    echo "Usage: $0 {start|stop|halt|restart|reload}" >&2
    exit 1
    ;;
esac

exit 0
