#!/bin/sh
# Usage: source load_mpp.sh [-i]
#

####################Variables Definition##########################

MPP_DRV=/root/ko/mpp.ko
SNS_DRV=/root/ko/sensor.ko
PCM_DRV=/root/ko/audio_pcm.ko
AUDIO_MACH_DRV=/root/ko/audio_machine.ko
OTP_DRV=/root/ko/otp-agtx.ko
OTP_EP_DRV=/root/ko/otp-ep.ko
POWER_ON_SCRIPT_PATH=/root/sensor/script/
VIDEO_DRV_INSERT=/tmp/mpp_video_driver.lock
AUDIO_DRV_INSERT=/tmp/mpp_audio_driver.lock

##################################################################

load_usage()
{
	echo "Usage:  source load_mpp.sh [-option]"
	echo "options:"
	echo "    -i  initialize MPP"
	echo "    -iv initialize video modules of MPP"
	echo "    -ia initialize audio modules of MPP"
	echo "    -f  active fastboot of MPP"
	echo "    -e  exit MPP"
	echo "    -a  exit MPP first, then initialize MPP"
	echo "    -h  help information"
	echo -e "example: source load_mpp.sh -i\n"
}

power_on()
{
	SENSOR_POWER_ON=`find $POWER_ON_SCRIPT_PATH -iname "sensor_power_on*.sh"`

	if [ -z "$SENSOR_POWER_ON" ]; then
		echo "Cannot find sensor power on script!"
		exit 1
	fi

	for script in $SENSOR_POWER_ON
	do
		sh $script
	done
}

insert_video_ko()
{
	# install video modules
	if [ -f $OTP_DRV ]; then
		insmod $OTP_DRV
	else
		echo "Cannot find $OTP_DRV!"
		exit 1
	fi

	if [ -f $OTP_EP_DRV ]; then
		insmod $OTP_EP_DRV
	else
		echo "Cannot find $OTP_EP_DRV!"
		exit 1
	fi

	if [ -f $MPP_DRV ]; then
		if [ $b_arg_fastboot == 1 ]; then
			insmod $MPP_DRV param_frame_drop_at_start=0
		else
			insmod $MPP_DRV param_frame_buffer_num=3 param_max_rd_num=6
		fi
	else
		echo "Cannot find $MPP_DRV!"
		exit 1
	fi

	if [ -f $SNS_DRV ]; then
		insmod $SNS_DRV
	fi
}

insert_audio_ko()
{
	# install audio modules
	if [ -f $PCM_DRV ]; then
		insmod $PCM_DRV
	else
		echo "Cannot find $PCM_DRV!"
		exit 1
	fi

	if [ -f $AUDIO_MACH_DRV ]; then
		insmod $AUDIO_MACH_DRV
	else
		echo "Cannot find $AUDIO_MACH_DRV!"
		exit 1
	fi
}

remove_ko()
{
	#Remove modules
	rmmod audio_machine.ko
	rmmod audio_pcm.ko
	[ -d /sys/module/sensor ] && rmmod sensor.ko
	rmmod mpp.ko
	rmmod otp-ep.ko
	rmmod otp-agtx.ko
}

init_mpp_video()
{
	#Insert video modules
	insert_video_ko

	#Power sensor
	if [ $b_arg_fastboot != 1 ]; then
		power_on
	fi
}

init_mpp_audio()
{
	#Insert audio modules
	insert_audio_ko
}

exit_mpp()
{
	#Remove modules
	remove_ko
}

######################parse arg###################################

b_arg_exit=0
b_arg_init_video=0
b_arg_init_audio=0
b_arg_fastboot=0

for arg in $@
do
	case $arg in
	"-i")
		b_arg_init_video=1;
		b_arg_init_audio=1;
		;;
	"-iv")
		b_arg_init_video=1;
		;;
	"-ia")
		b_arg_init_audio=1;
		;;
	"-f")
		b_arg_fastboot=1;
		;;
	"-e")
		b_arg_exit=1;
		;;
	"-a")
		b_arg_init_video=1;
		b_arg_init_audio=1;
		b_arg_exit=1;
		;;
	"-h")
		load_usage;
		;;
	*)
		echo "Invalid Parameter"
		;;
	esac
done

#######################parse arg end########################


#######################Action###############################

if [ $# -lt 1 ]; then
    load_usage;
    exit 0;
fi

if [ $b_arg_exit == 1 ]; then
	exit_mpp;
	rm -f $VIDEO_DRV_INSERT
	rm -f $AUDIO_DRV_INSERT
	exit 0
fi

if [ ! -f $VIDEO_DRV_INSERT ] && [ $b_arg_init_video == 1 ]; then
	touch $VIDEO_DRV_INSERT
	init_mpp_video;
fi

if [ ! -f $AUDIO_DRV_INSERT ] && [ $b_arg_init_audio == 1 ]; then
	touch $AUDIO_DRV_INSERT
	init_mpp_audio;
fi

if [ $b_arg_exit == 0 ] && [ $b_arg_init_video == 0 ] && [ $b_arg_init_audio == 0 ]; then
	echo "Nothing happen since initialization script has not yet been run!"
fi

