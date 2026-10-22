#!/bin/sh

IP="192.168.10.166"

check_ephy_intf_sel(){
	echo "Make sure EPHY_INTF_SEL=1 (RMII)"
	ephy_intf_sel=$(($(devmem 0x81360000 32) & 0x1))
	if [ "$ephy_intf_sel" != "1" ]; then
		return 255
	fi
	return 1
}

check_fifo_size(){
	echo "Make sure FIFO size, TX = 4096 bytes ([10:6] = 0x5), RX = 2048 bytes([4:0] = 0x4)"
	mac_hw_feature1=$(devmem 0x81880120 32)
	tx_fifo_size=$(($mac_hw_feature1>>6 & 0x1F))
	rx_fifo_size=$(($mac_hw_feature1 & 0x1F))
	if [ "$tx_fifo_size" != "5" ] || [ "$rx_fifo_size" != "4" ]; then
		return 255
	fi
	return 2
}

check_switching_speed(){
	echo "Iperf test for 10Mbps"
	./ethtool -s eth0 speed 10 duplex full autoneg on
	sleep 5
	cat /sys/class/net/eth0/speed | grep "10" > /dev/null
	if  [ $? -ne 0 ]; then
	        echo "/sys/class/net/eth0/speed is not 10"
	fi
	iperf3 -c $IP -t 5
	sleep 2
	iperf3 -R -c $IP -t 5
	echo "Iperf speed for 100Mbps"
	./ethtool -s eth0 speed 100 duplex full autoneg on
	sleep 5
	cat /sys/class/net/eth0/speed | grep "100" > /dev/null
	if  [ $? -ne 0 ]; then
	        echo "/sys/class/net/eth0/speed is not 100"
	fi
	iperf3 -c $IP -t 5
	sleep 2
	iperf3 -R -c $IP -t 5
	return 3
}

echo "Unit Test EMAC-1"

check_ephy_intf_sel
if [ $? -ne 1 ]; then
    echo "check_ephy_intf_sel failed"
fi
check_fifo_size
if [ $? -ne 2 ]; then
    echo "check_fifo_size failed"
fi
check_switching_speed
echo "Unit Test EMAC-1 done"
