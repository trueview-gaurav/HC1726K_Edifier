#!/bin/sh

PC_IP="192.168.10.82"
LOCAL_IP="192.168.35.33"
L3_Filter_Source="0xC0A80A52" # PC, ex 192.168.10.82
L3_Filter_Destination="0xC0A82321" # FPGA, ex 192.168.35.33
L4_Filter_Source="0x1451" # PC, use iperf default port 5201
L4_Filter_Destination="0x14520000" # FPGA, use port 5202

MAC_Packet_Filter="0x81880008"
MAC_Hash_Table_Reg0="0x81880010"
MAC_Hash_Table_Reg1="0x81880014"
MAC_L3_L4_Control="0x81880900"
MAC_Layer4_Address="0x81880904"
MAC_Layer3_Addr0_Reg="0x81880910"
MAC_Layer3_Addr1_Reg="0x81880914"

check_da_filter(){
	echo "DA filter test"
	/etc/init.d/factory/S40network stop
	ifconfig eth0 hw ether 12:34:56:78:90:12
	ip_assign -i $LOCAL_IP
	/etc/init.d/factory/S40network start
	sleep 5
	# 12:34:56:78:90:12 hasg reverse = 0b"100011
	echo "DA filter on, set hash reg1 = 0x8, iperf should receive packets normally"
	devmem $MAC_Packet_Filter 32 0x2
	devmem $MAC_Hash_Table_Reg1 32 0x8
	sleep 1
	iperf3 -c $PC_IP -R -t 50 &
	sleep 10
	echo "DA filter on, set hash reg1 = 0, iperf shouldn't receive any packets"
	devmem $MAC_Hash_Table_Reg1 32 0x0
	sleep 5
	kill $!
	echo "DA filter done"
}

check_L3_filter(){
	echo "L3 filter test"
	devmem $MAC_Packet_Filter 32 0x100010
	echo "iperf test for initial state"
	iperf3 -c $PC_IP -R -t 5
	echo "--- L3-source ip ---"
	echo "enable L3SAM0, iperf shouldn't receive any packets"
	devmem $MAC_L3_L4_Control 32 0x4
	iperf3 -c $PC_IP -R -t 100 &
	sleep 7
	echo "enable L3SAM0 and set MAC_Layer3_Addr0_Reg, iperf should reveive packets"
	devmem $MAC_Layer3_Addr0_Reg 32 $L3_Filter_Source
	sleep 10
	echo "enable L3DAM0 and set MAC_Layer3_Addr1_Reg, iperf should reveive packets"
	devmem $MAC_L3_L4_Control 32 0x10
	devmem $MAC_Layer3_Addr1_Reg 32 $L3_Filter_Destination
	sleep 10
	echo "enable L3DAM0, iperf shouldn't receive any packets"
	devmem $MAC_Layer3_Addr1_Reg 32 0x0
	sleep 10
	kill $!
	echo "L3 filter test done"
}

check_L4_filter(){
	echo "L4 filter test"
	echo "--- L4-source port ---"
	echo "enable L4SPM0, iperf shouldn't receive any packets"
	devmem $MAC_L3_L4_Control 32 0x40000
	iperf3 -c $PC_IP -R --cport 5202 -t 50 &
	sleep 7
	echo "enable L4SPM0 and set MAC_Layer4_Address, iperf should reveive packets"
	devmem $MAC_Layer4_Address 32 $L4_Filter_Source
	sleep 10
	kill $!
	sleep 1
	iperf3 -c $PC_IP -R --cport 5202 -u -t 50 &
	echo "enable L4SPM0, L4PEN0 and set MAC_Layer4_Address, iperf should reveive packets"
	devmem $MAC_L3_L4_Control 32 0x50000
	sleep 10
	echo "enable L4SPM0, L4PEN0, iperf shouldn't reveive any packets"
	devmem $MAC_Layer4_Address 32 0x0
	sleep 10
	echo "--- L4-destination port ---"
	echo "enable L4DPM0, L4PEN0, iperf shouldn't reveive any packets"
	devmem $MAC_L3_L4_Control 32 0x110000
	sleep 10
	echo "enable L4DPM0, L4PEN0 and set MAC_Layer4_Address, iperf should reveive packets"
	devmem $MAC_Layer4_Address 32 $L4_Filter_Destination
	sleep 10
	kill $!
	sleep 1
	iperf3 -c $PC_IP -R --cport 5202 -t 50 &
	sleep 7
	echo "enable L4DPM0 and set MAC_Layer4_Address, iperf should reveive packets"
	devmem $MAC_L3_L4_Control 32 0x100000
	sleep 10
	echo "enable L4DPM0, iperf shouldn't reveive any packets"
	devmem $MAC_Layer4_Address 32 0x0
	sleep 10
	kill $!
	echo "recover ethnet function, enable all packets"
	devmem $MAC_Packet_Filter 32 0x10
	echo "L4 filter test done"
}

echo "Unit Test EMAC-3"
check_da_filter
sleep 5
check_L3_filter
sleep 5
check_L4_filter
echo "Unit Test EMAC-3 done"
