#!/bin/sh

echo "Unit Test SDC-4"

dd if=/dev/urandom of=/tmp/1MF bs=1M count=1 conv=fsync
cp /tmp/1MF /mnt/sdcard/sdc_test_write
sync
cp /mnt/sdcard/sdc_test_write /tmp/sdc_test_read
sync
cmp /tmp/1MF /mnt/sdcard/sdc_test_write
cmp /tmp/1MF /tmp/sdc_test_read
