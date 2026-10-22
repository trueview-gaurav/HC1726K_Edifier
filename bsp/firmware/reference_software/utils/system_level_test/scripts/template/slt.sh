#!/bin/sh

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/root/bin:/system/bin

echo "================= Starting System Test ==============="

./slt_emac.sh &
./sdc_system_test.sh &
