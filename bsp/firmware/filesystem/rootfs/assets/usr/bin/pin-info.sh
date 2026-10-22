#!/bin/sh
#
#  AUGENTIX INC. - PROPRIETARY
#
#  automount.sh - Automount script for removable media devices
#  Copyright (C) 2019 Augentix Inc. - All Rights Reserved
#
#  NOTICE: The information contained herein is the property of Augentix Inc.
#  Copying and distributing of this file, via any medium,
#  must be licensed by Augentix Inc.
#

OUTPUT_PATH=$1

PINCTRL_DEBUG_PATH="/sys/kernel/debug/pinctrl/80000000.pinctrl"

PINMUX_PINS_PATH="$PINCTRL_DEBUG_PATH/pinmux-pins"

PINMUX_GROUP_PATH="$PINCTRL_DEBUG_PATH/pingroups"

GPIO_PATH="/sys/kernel/debug/gpio"

base_addr=2147483648
addr=$base_addr
count=0
PIN_NUM=73

rm -f $OUTPUT_PATH

echo "-----------------PIN GROUP INFORMATION----------------------------------------------" >> $OUTPUT_PATH


exec < $PINMUX_GROUP_PATH

while read line
do
   
	echo "$line" >> $OUTPUT_PATH

done

echo "-----------------END------------------------------------------------" >> $OUTPUT_PATH
echo " " >> $OUTPUT_PATH

echo "-----------------PINS-MUX INFORMATION-------------------------------------------------------" >> $OUTPUT_PATH

exec < $PINMUX_PINS_PATH

while read line
do

	count=`expr $count + 1`

	if [ $count -gt 2 ];then
		format_addr=`echo "obase=16;ibase=10;$addr" | bc`
		reg_val="$(devmem $addr 8)"
		echo "$line  physical addr=0x$format_addr value=$reg_val" >> $OUTPUT_PATH
		addr=`expr $addr + 1`
	else
		echo "$line" >> $OUTPUT_PATH
	fi

done

echo "-----------------END------------------------------------------------" >> $OUTPUT_PATH
echo " " >> $OUTPUT_PATH

echo "-----------------export GPIO----------------------------------------" >> $OUTPUT_PATH

exec < $GPIO_PATH
while read line
do
    echo "$line" >> $OUTPUT_PATH
done

echo "-----------------END------------------------------------------------" >> $OUTPUT_PATH
echo " " >> $OUTPUT_PATH


echo "-----------------GPIO Register value--------------------------------" >> $OUTPUT_PATH
echo " " 
addr=$base_addr
addr=`expr $addr + 80`

for i in $(seq 0 $PIN_NUM); do
        reg_val="$(devmem $addr 32)"
        format_addr=`echo "obase=16;ibase=10;$addr" | bc`
        addr=`expr $addr + 4`
        echo "GPIO$i  physical addr=0x$format_addr , value=$reg_val" >> $OUTPUT_PATH
done
echo "-----------------END--------------------------------" >> $OUTPUT_PATH
echo " " >> $OUTPUT_PATH
