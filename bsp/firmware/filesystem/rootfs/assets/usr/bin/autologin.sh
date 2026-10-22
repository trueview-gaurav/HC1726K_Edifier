#!/bin/sh

current_mode=$(/system/bin/mode)


if [ ! "$current_mode" == "user" ]; then

/sbin/getty -l /usr/bin/autologin -n -L ttyAS0 0 vt100 # GENERIC_SERIAL

fi