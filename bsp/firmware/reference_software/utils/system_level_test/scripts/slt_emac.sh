#!/bin/sh

CLIENT_IP=192.168.10.xx
BANDWIDTH_LIMIT=10M
TIME=30

if [ "$CLIENT_IP" == "192.168.10.xx" ]
then
    echo "==================================="
    echo "Please set CLIENT_IP in slt_emac.sh"
    echo "==================================="
    exit
fi

count=0
ret=0

while [ $count -le 1000 ]
do
	iperf3 -c $CLIENT_IP -b $BANDWIDTH_LIMIT -t $TIME >> emac_test
	if [ $? -eq 1 ]
	then
		echo "[EMAC SLT] iperf3 error"
		exit
	fi

	test -e emac_test
	if [ $? -ne 0 ]
	then
		echo "[EMAC SLT] Can't add EMAC test file"
		exit
	fi

	ret=$(grep -c "0.00 b" emac_test)
	if [ $ret -ge 3 ]
	then
		echo "[EMAC SLT] transmit error"
		exit
	fi

	rm -f emac_test
	count=$(($count + 1))
	echo "[EMAC SLT] testing..., count = $count"
done

echo "[EMAC SLT] EMAC system test pass"

