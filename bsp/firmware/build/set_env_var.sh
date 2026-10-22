#! /bin/sh
#
# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.
#

BUILD_PATH=$PWD
TOOLCHAIN_ROOT=$(realpath "$BUILD_PATH/../../toolchain")
BUILDROOT_ROOT=$BUILD_PATH/../../buildroot/output/host/usr

TOOLCHAIN_0=gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi
TOOLCHAIN_1=gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf
TOOLCHAIN_2=arm-augentix-linux-uclibcgnueabihf
TOOLCHAIN_3=arm-augentix-linux-uclibcgnueabi
TOOLCHAIN_4=arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi
TOOLCHAIN_5=gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu
TOOLCHAIN_6=zephyr-sdk-0.17.4

function usage() {
	echo ""
	echo "Usage: . set_env_var.sh <chip_type>"
	echo "   or: . set_env_var.sh -h or --help"
	echo "   or: . set_env_var.sh show"
	echo ""
	echo "Supported chip types:"
	echo "	HC1703"
	echo "	HC1703L"
	echo "	HC1705"
	echo "	HC1705I"
	echo "	HC1705L"
	echo "	HC1705K"
	echo "	HC1706"
	echo "	HC1706H"
	echo "	HC1706K"
	echo "	HC1706K_ES"
	echo "	HC1715"
	echo "	HC1723"
	echo "	HC1725"
	echo "	HC1725_FPU"
	echo "	HC1725S"
	echo "	HC1726"
	echo "	HC1753"
	echo "	HC1753_FPU"
	echo "	HC1753S"
	echo "	HC1783S"
	echo "	HC1783S_FPU"
	echo "	HC1785"
	echo ""
	echo "Arguments:"
	echo "  -h or --help : Show this message and exit."
	echo "  show         : Show current environment variables setting and exit."
	echo ""
}

function set_hc1703() {
	echo "export CONFIG_CHIP=HC1703"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1703l() {
	echo "export CONFIG_CHIP=HC1703L"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1705() {
	echo "export CONFIG_CHIP=HC1705"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1705i() {
	echo "export CONFIG_CHIP=HC1705I"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1705l() {
	echo "export CONFIG_CHIP=HC1705L"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1705k() {
	echo "export CONFIG_CHIP=HC1705K"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1706() {
	echo "export CONFIG_CHIP=HC1706"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1706h() {
	echo "export CONFIG_CHIP=HC1706H"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1706k() {
	echo "export CONFIG_CHIP=HC1706K"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1706k_es() {
	echo "export CONFIG_CHIP=HC1706K_ES"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1715() {
	echo "export CONFIG_CHIP=HC1715"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1723() {
	echo "export CONFIG_CHIP=HC1723"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1725() {
	echo "export CONFIG_CHIP=HC1725"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabi-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_0}"
	echo "export XTOOL_PATH_0=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_0}\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_3}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_0}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_0}/bin:\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1725_fpu() {
	echo "export CONFIG_CHIP=HC1725_FPU"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1725s() {
	echo "export CONFIG_CHIP=HC1725S"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabi-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_0}"
	echo "export XTOOL_PATH_0=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_0}\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_3}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_0}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_0}/bin:\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1726() {
	echo "export CONFIG_CHIP=HC1726"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1753() {
	echo "export CONFIG_CHIP=HC1753"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabi-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_0}"
	echo "export XTOOL_PATH_0=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_0}\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_3}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_0}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_0}/bin:\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1753_fpu() {
	echo "export CONFIG_CHIP=HC1753_FPU"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1753s() {
	echo "export CONFIG_CHIP=HC1753S"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabi-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_0}"
	echo "export XTOOL_PATH_0=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_0}\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_3}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_0}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_0}/bin:\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1783s() {
	echo "export CONFIG_CHIP=HC1783S"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabi-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_0}"
	echo "export XTOOL_PATH_0=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_0}\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_3}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_0}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_0}/bin:\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1783s_fpu() {
	echo "export CONFIG_CHIP=HC1783S_FPU"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

function set_hc1785() {
	echo "export CONFIG_CHIP=HC1785"
	echo "export ARCH=arm"
	echo "export CROSS_COMPILE_0=\"arm-linux-gnueabi-\""
	echo "export CROSS_COMPILE_1=\"arm-linux-gnueabihf-\""
	echo "export CROSS_COMPILE_2=\"arm-augentix-linux-uclibcgnueabihf-\""
	echo "export CROSS_COMPILE_4=\"arm-none-eabi-\""
	echo "export CROSS_COMPILE_5=\"aarch64-none-linux-gnu-\""
	echo "export CROSS_COMPILE=\${CROSS_COMPILE_1}"
	echo "export XTOOL_PATH_0=\"\""
	echo "export XTOOL_PATH_1=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_1}\""
	echo "export XTOOL_PATH_2=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_2}\""
	echo "export XTOOL_PATH_4=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_4}\""
	echo "export XTOOL_PATH_5=\"${TOOLCHAIN_ROOT}/${TOOLCHAIN_5}\""
	echo "export XTOOL_PATH=\${XTOOL_PATH_1}"
	echo "export BUILDROOT_PATH=\${BUILDROOT_ROOT}"
	echo "export PATH=\"\${XTOOL_PATH_1}/bin:\${XTOOL_PATH_2}/bin:\${XTOOL_PATH_4}/bin:\${XTOOL_PATH_5}/bin:\$PATH:\${BUILDROOT_PATH}/bin\""
}

set_env_var() {
	# Executes by CONFIG_CHIP.
	case $CONFIG_CHIP in
		HC1703)
			eval "$(set_hc1703)"
			;;
		HC1703L)
			eval "$(set_hc1703l)"
			;;
		HC1705)
			eval "$(set_hc1705)"
			;;
		HC1705I)
			eval "$(set_hc1705i)"
			;;
		HC1705L)
			eval "$(set_hc1705l)"
			;;
		HC1705K)
			eval "$(set_hc1705k)"
			;;
		HC1706)
			eval "$(set_hc1706)"
			;;
		HC1706H)
			eval "$(set_hc1706h)"
			;;
		HC1706K)
			eval "$(set_hc1706k)"
			;;
		HC1706K_ES)
			eval "$(set_hc1706k_es)"
			;;
		HC1715)
			eval "$(set_hc1715)"
			;;
		HC1723)
			eval "$(set_hc1723)"
			;;
		HC1725)
			eval "$(set_hc1725)"
			;;
		HC1725_FPU)
			eval "$(set_hc1725_fpu)"
			;;
		HC1725S)
			eval "$(set_hc1725s)"
			;;
		HC1726)
			eval "$(set_hc1726)"
			;;
		HC1753)
			eval "$(set_hc1753)"
			;;
		HC1753_FPU)
			eval "$(set_hc1753_fpu)"
			;;
		HC1753S)
			eval "$(set_hc1753s)"
			;;
		HC1783S)
			eval "$(set_hc1783s)"
			;;
		HC1783S_FPU)
			eval "$(set_hc1783s_fpu)"
			;;
		HC1785)
			eval "$(set_hc1785)"
			;;
		*)
			echo "Invalid CONFIG_CHIP value: $CONFIG_CHIP"
			return 1
			;;
	esac
}

save_env_var() {
	# Executes by CONFIG_CHIP.
	case $CONFIG_CHIP in
		HC1703)
			set_hc1703 > "$BUILD_PATH/temp.env"
			;;
		HC1703L)
			set_hc1703l > "$BUILD_PATH/temp.env"
			;;
		HC1705)
			set_hc1705 > "$BUILD_PATH/temp.env"
			;;
		HC1705I)
			set_hc1705i > "$BUILD_PATH/temp.env"
			;;
		HC1705L)
			set_hc1705l > "$BUILD_PATH/temp.env"
			;;
		HC1705K)
			set_hc1705k > "$BUILD_PATH/temp.env"
			;;
		HC1706)
			set_hc1706 > "$BUILD_PATH/temp.env"
			;;
		HC1706H)
			set_hc1706h > "$BUILD_PATH/temp.env"
			;;
		HC1706K)
			set_hc1706k > "$BUILD_PATH/temp.env"
			;;
		HC1706K_ES)
			set_hc1706k_es > "$BUILD_PATH/temp.env"
			;;
		HC1715)
			set_hc1715 > "$BUILD_PATH/temp.env"
			;;
		HC1723)
			set_hc1723 > "$BUILD_PATH/temp.env"
			;;
		HC1725)
			set_hc1725 > "$BUILD_PATH/temp.env"
			;;
		HC1725_FPU)
			set_hc1725_fpu > "$BUILD_PATH/temp.env"
			;;
		HC1725S)
			set_hc1725s > "$BUILD_PATH/temp.env"
			;;
		HC1726)
			set_hc1726 > "$BUILD_PATH/temp.env"
			;;
		HC1753)
			set_hc1753 > "$BUILD_PATH/temp.env"
			;;
		HC1753_FPU)
			set_hc1753_fpu > "$BUILD_PATH/temp.env"
			;;
		HC1753S)
			set_hc1753s > "$BUILD_PATH/temp.env"
			;;
		HC1783S)
			set_hc1783s > "$BUILD_PATH/temp.env"
			;;
		HC1783S_FPU)
			set_hc1783s_fpu > "$BUILD_PATH/temp.env"
			;;
		HC1785)
			set_hc1785 > "$BUILD_PATH/temp.env"
			;;
		*)
			echo "Invalid CONFIG_CHIP value: $CONFIG_CHIP"
			return 1
			;;
	esac
}

unpack_toolchain() {
	# Executes by CONFIG_CHIP.
	case $CONFIG_CHIP in
		HC1703)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1703L)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1705)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1705I)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1705L)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1705K)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1706)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1706H)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1706K)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1706K_ES)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1715)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1725)
			if [ ! -d "${XTOOL_PATH_0}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_0}
			fi
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1725_FPU)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1725S)
			if [ ! -d "${XTOOL_PATH_0}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_0}
			fi
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1726)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1723)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1753)
			if [ ! -d "${XTOOL_PATH_0}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_0}
			fi
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1753_FPU)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1753S)
			if [ ! -d "${XTOOL_PATH_0}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_0}
			fi
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1783S)
			if [ ! -d "${XTOOL_PATH_0}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_0}
			fi
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1783S_FPU)
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			;;
		HC1785)
			if [ ! -d "${XTOOL_PATH_5}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_5}
			fi
			if [ ! -d "${XTOOL_PATH_4}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_4}
			fi
			if [ ! -d "${XTOOL_PATH_1}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_1}
			fi
			if [ ! -d "${XTOOL_PATH_2}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack CROSS_COMPILE=${CROSS_COMPILE_2}
			fi
			if [ ! -d "${TOOLCHAIN_ROOT}/${TOOLCHAIN_6}" ]; then
				make -C "${TOOLCHAIN_ROOT}" unpack-zephyr-sdk
			fi
			;;
		*)
			echo "Invalid CONFIG_CHIP value: $CONFIG_CHIP"
			return 1
			;;
	esac
}

print_env() {
	echo ""
	echo "Current cross compiler and toolchain environment variables:"
	echo ""


	if [[ ! -v CONFIG_CHIP || -z "$CONFIG_CHIP" ]]; then
		echo "  CONFIG_CHIP: "
	else
		echo "  CONFIG_CHIP: ${CONFIG_CHIP}"
	fi

	if [[ ! -v ARCH || -z "$ARCH" ]]; then
		echo "  ARCH: "
	else
		echo "  ARCH: ${ARCH}"
	fi

	if [[ ! -v CROSS_COMPILE_0 || -z "$CROSS_COMPILE_0" ]]; then
		echo "  CROSS_COMPILE_0: "
	else
		echo "  CROSS_COMPILE_0: ${CROSS_COMPILE_0}"
	fi

	if [[ ! -v CROSS_COMPILE_1 || -z "$CROSS_COMPILE_1" ]]; then
		echo "  CROSS_COMPILE_1: "
	else
		echo "  CROSS_COMPILE_1: ${CROSS_COMPILE_1}"
	fi

	if [[ ! -v CROSS_COMPILE_2 || -z "$CROSS_COMPILE_2" ]]; then
		echo "  CROSS_COMPILE_2: "
	else
		echo "  CROSS_COMPILE_2: ${CROSS_COMPILE_2}"
	fi

	if [[ ! -v CROSS_COMPILE_4 || -z "$CROSS_COMPILE_4" ]]; then
		echo "  CROSS_COMPILE_4: "
	else
		echo "  CROSS_COMPILE_4: ${CROSS_COMPILE_4}"
	fi

	if [[ ! -v CROSS_COMPILE_5 || -z "$CROSS_COMPILE_5" ]]; then
		echo "  CROSS_COMPILE_5: "
	else
		echo "  CROSS_COMPILE_5: ${CROSS_COMPILE_5}"
	fi

	if [[ ! -v CROSS_COMPILE || -z "$CROSS_COMPILE" ]]; then
		echo "  CROSS_COMPILE: "
	else
		echo "  CROSS_COMPILE: ${CROSS_COMPILE}"
	fi

	if [[ ! -v XTOOL_PATH_0 || -z "$XTOOL_PATH_0" ]]; then
		echo "  XTOOL_PATH_0: "
	else
		echo "  XTOOL_PATH_0: ${XTOOL_PATH_0}"
	fi

	if [[ ! -v XTOOL_PATH_1 || -z "$XTOOL_PATH_1" ]]; then
		echo "  XTOOL_PATH_1: "
	else
		echo "  XTOOL_PATH_1: ${XTOOL_PATH_1}"
	fi

	if [[ ! -v XTOOL_PATH_2 || -z "$XTOOL_PATH_2" ]]; then
		echo "  XTOOL_PATH_2: "
	else
		echo "  XTOOL_PATH_2: ${XTOOL_PATH_2}"
	fi

	if [[ ! -v XTOOL_PATH_4 || -z "$XTOOL_PATH_4" ]]; then
		echo "  XTOOL_PATH_4: "
	else
		echo "  XTOOL_PATH_4: ${XTOOL_PATH_4}"
	fi

	if [[ ! -v XTOOL_PATH_5 || -z "$XTOOL_PATH_5" ]]; then
		echo "  XTOOL_PATH_5: "
	else
		echo "  XTOOL_PATH_5: ${XTOOL_PATH_5}"
	fi

	if [[ ! -v XTOOL_PATH || -z "$XTOOL_PATH" ]]; then
		echo "  XTOOL_PATH: "
	else
		echo "  XTOOL_PATH: ${XTOOL_PATH}"
	fi

	if [[ ! -v BUILDROOT_PATH || -z "$BUILDROOT_PATH" ]]; then
		echo "  BUILDROOT_PATH: "
	else
		echo "  BUILDROOT_PATH: ${BUILDROOT_PATH}"
	fi

	if [[ ! -v PATH || -z "$PATH" ]]; then
		echo "  PATH: "
	else
		echo "  PATH: ${PATH}"
	fi

	echo ""
}

remove_old_path() {
	REMOVE_PATH=$1/bin
	if [[ ":$PATH:" == *":$REMOVE_PATH:"* ]]; then
		PATH=${PATH//":$REMOVE_PATH:"/":"}
		PATH=${PATH/#"$REMOVE_PATH:"/}
		PATH=${PATH/%":$REMOVE_PATH"/}
		export PATH
	fi
}

if [[ $# -ne 1 ]]; then
	usage
	return 1
fi

if [[ $1 == "-h" || $1 == "--help" ]]; then
	usage
    return 0
fi

if [[ $1 == "show" ]]; then
	print_env
	return 0
fi

# Assign first argument to chip type
CONFIG_CHIP=$1

# Remove old path in PATH
if [[ ! -v XTOOL_PATH_0 ]]; then
	echo "XTOOL_PATH_0 not set yet." > /dev/null
elif [[ -z "$XTOOL_PATH_0" ]]; then
	echo "XTOOL_PATH_0 no value." > /dev/null
else
	remove_old_path "$XTOOL_PATH_0"
fi

if [[ ! -v XTOOL_PATH_1 ]]; then
	echo "XTOOL_PATH_1 not set yet." > /dev/null
elif [[ -z "$XTOOL_PATH_1" ]]; then
	echo "XTOOL_PATH_1 no value." > /dev/null
else
    remove_old_path "$XTOOL_PATH_1"
fi

if [[ ! -v XTOOL_PATH_2 ]]; then
	echo "XTOOL_PATH_2 not set yet." > /dev/null
elif [[ -z "$XTOOL_PATH_2" ]]; then
	echo "XTOOL_PATH_2 no value." > /dev/null
else
    remove_old_path "$XTOOL_PATH_2"
fi

if [[ ! -v BUILDROOT_PATH ]]; then
	echo "BUILDROOT_PATH not set yet." > /dev/null
elif [[ -z "$BUILDROOT_PATH" ]]; then
	echo "BUILDROOT_PATH no value." > /dev/null
else
    remove_old_path "$BUILDROOT_PATH"
fi

# Set environment variable
set_env_var
if [ $? -eq 1 ]; then
    return 1
fi

# Save environment variable to $BUILD_PATH/temp.env
save_env_var
if [ $? -eq 1 ]; then
    return 1
fi
echo "Environment variables written to $BUILD_PATH/temp.env"

# Unpack toolchain
unpack_toolchain
if [ $? -eq 1 ]; then
    return 1
fi

# Show environment variable
print_env
