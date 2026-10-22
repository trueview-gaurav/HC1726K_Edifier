#!/bin/bash

count=0

head -c 131073 </dev/urandom > /usrdata/golden_file_for_qspi #131073 = 2 Nor block(64k) + 1 bytes
sync


while [ $count -le 1000 ]
do

	cp /usrdata/golden_file_for_qspi /usrdata/test_file_for_qspi
	sync

	cmp /usrdata/golden_file_for_qspi /usrdata/test_file_for_qspi

	if [ $? -eq 1 ]
	then
		echo "[QSPI SLT] golden file diff "
		exit
	fi

	rm /usrdata/test_file_for_qspi
	sync

	count=$(($count+1))
	echo "[QSPI SLT] testing..., count = $count"
done

echo "[QSPI SLT] system test pass"

