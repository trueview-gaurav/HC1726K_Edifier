#!/bin/bash

COUNT=1
CHECK=0

rm -f /tmp/10M_golden_file
echo "Create golden file for read/write test ..." > /dev/console
dd if=/dev/urandom of=/tmp/10M_golden_file bs=1M count=10 conv=fsync

cmp_write() {
	cmp /tmp/10M_golden_file /mnt/sdcard/sdc_test_write
}

cmp_read() {
	cmp /tmp/10M_golden_file /tmp/sdc_test_read
}

while [ $CHECK -eq 0 ]
do
	if [ `expr $COUNT % 5` -eq 0 ]; then
		echo "SDC system test $COUNT times..." > /dev/console
	fi

	cp /tmp/10M_golden_file /mnt/sdcard/sdc_test_write
	sync
	cp /mnt/sdcard/sdc_test_write /tmp/sdc_test_read
	sync

	cmp_write
	if [ ! $? -eq 0 ]; then
		echo "[SDC][Error] Diffs in the sdc_test_write" > /dev/console
		CHECK=1
	fi

	cmp_read
	if [ ! $? -eq 0 ]; then
		echo "[SDC][Error] Diffs in the sdc_test_read" > /dev/console
		CHECK=1
	fi

	rm -f /mnt/sdcard/sdc_test_write
	rm -f /tmp/sdc_test_read
	sync

	COUNT=$(( COUNT+1 ))

	if [ $CHECK -eq 1 ]; then
		echo "[SDC][Error] SDC system test was terminated due to encountered errors during testing" > /dev/console
	fi
done
