#!/usr/bin/env sh

# Extern Collect Data Tool V1.0.1

SDKSRC_DIR="$1"
SDK_DIR="${SDKSRC_DIR}"
TOOL_DIR="${SDK_DIR}/firmware/filesystem/rootfs/build/extern_collect_data"
SYSROOT="${SDK_DIR}/firmware/filesystem/rootfs/output/target"
OUTPUT="${SDK_DIR}/firmware/filesystem/rootfs/output/"
BUILDROOT="${SDK_DIR}/buildroot/output/target"
STRIP="${CROSS_COMPILE}strip"
SETUP_ENV_SCRIPT="${SDKSRC_DIR}/firmware/filesystem/rootfs/tool/setup_collect_data_env.sh"
IS_UCLIBC=$(cat "${SDK_DIR}/firmware/build/.config" | awk 'BEGIN {FS="="} /CONFIG_UCLIBC/{print $2}')
AUDIO_PATTERNS="${SDKSRC_DIR}/sdk/sample/demo/audio/audio_patterns"
CONFIG_CHIP=$(cat "${SDK_DIR}/firmware/build/.config" | awk 'BEGIN {FS="="} /CONFIG_CHIP/{print $2}')
SDK_VER=$(cat "${SYSROOT}/etc/sdk-version" | awk 'BEGIN{FS=": "} /SDK version/{print $2}')
PACKAGE_NAME="extern_collect_data_${CONFIG_CHIP}-${CROSS_COMPILE}${SDK_VER}.tgz"
IS_SECURE_APP=0
CORE_SAMPLE_PATH="${SDK_DIR}/sdk/sample/demo"

collect_data_tool() {
	version="V1.0.1"
	echo "!!!! Extern IQ Collect Data Tool ${version}"
	echo "-------"

	if [ ! -e "$SDK_DIR/firmware/build/sdk-version" ]; then
		echo "[Error] This is not SDK root directory !  exit"
		exit 1
	fi

	if [ $IS_UCLIBC ]; then
		PACKAGE_NAME="extern_collect_data_${CONFIG_CHIP}-${CROSS_COMPILE_2}${SDK_VER}.tgz"
	fi

	if [ -e "$TOOL_DIR" ]; then
		rm -rf "${TOOL_DIR}"
	fi

	mkdir -p "${TOOL_DIR}"

	if [ ! -e "$TOOL_DIR" ]; then
		echo "[Error] mkdir TOOL_DIR fail !  exit"
		rm -rf "$TOOL_DIR"
		exit 1
	fi

	Check_and_prepare

	if [ ! -f "${TOOL_DIR}/${PACKAGE_NAME}" ]; then
		rm -rf "${TOOL_DIR}/${PACKAGE_NAME}"
	fi

	tar -zcf "${PACKAGE_NAME}" "$(basename ${TOOL_DIR})"
	mv "${PACKAGE_NAME}" "${OUTPUT}"

	rm -rf "$TOOL_DIR"

	echo "[Finish] Generate external collect data package complete"
	echo "Output package Extern_Collect_Data_package"
}

main() {
	collect_data_tool
}

Check_and_prepare() {

	PASS=1

	if [ ! -f "${SYSROOT}/system/bin/cmdsender" ]; then
		echo "cmdsender does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/csr" ]; then
		echo "csr does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/ddr2pgm" ]; then
		echo "ddr2pgm does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/dip_dump" ]; then
		echo "dip_dump does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/dump" ]; then
		echo "dump does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/dump_csr" ]; then
		echo "dump_csr does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/mpi_snapshot" ]; then
		echo "mpi_snapshot does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/vftr_dump" ]; then
		echo "vftr_dump does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/unicorn" ]; then
		echo "unicorn does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/system/bin/mpi_stream" ]; then
		# CONFIG_SECURE_APP makes mpi_stream become a symbol link.
		if [ ! -L "${SYSROOT}/system/bin/mpi_stream" ]; then
			echo "mpi_stream does not exist!"
			PASS=0
		else
			IS_SECURE_APP=1
		fi
	fi

	if [ ! -f "$BUILDROOT/usr/lib/libmagic.so.1" ]; then
		echo "libmagic.so.1 does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/usr/lib/libasound.so.2" ]; then
		echo "libasound.so.1 does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/usr/lib/libjson-c.so.5" ]; then
		echo "libjson-c.so.5 does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/system/lib/libmpp.so.3" ]; then
		echo "libmpp.so.3 does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/system/mpp/script/collect_data.sh" ]; then
		echo "collect_data.sh does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/system/mpp/script/debug_videopipeline.sh" ]; then
		echo "debug_videopipeline.sh does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/system/mpp/script/collect_audio_data.sh" ]; then
		echo "collect_audio_data.sh does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/usr/bin/aplay" ]; then
		echo "aplay does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/usr/bin/arecord" ]; then
		echo "arecord does not exist!"
		PASS=0
	fi
	if [ ! -f "${SYSROOT}/usr/bin/amixer" ]; then
		echo "amixer does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/usr/bin/file" ]; then
		echo "file does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/bin/busybox" ]; then
		echo "busybox does not exist!"
		PASS=0
	fi

	if [ ! -f "${SYSROOT}/system/schema.tar" ]; then
		echo "schema.tar does not exist!"
		PASS=0
	fi

	if [ $PASS = "1" ]; then
		cp -f "${SYSROOT}/system/bin/cmdsender" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/csr" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/ddr2pgm" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/dip_dump" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/dump" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/dump_csr" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/mpi_snapshot" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/vftr_dump" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/bin/unicorn" "${TOOL_DIR}"
		if [ "${IS_SECURE_APP}" = "0" ]; then
			cp -f "${SYSROOT}/system/bin/mpi_stream" "${TOOL_DIR}"
		else
			cp -f "${CORE_SAMPLE_PATH}/video/mpi_stream/mpi_stream" "${TOOL_DIR}"
		fi

		cp -f "$BUILDROOT/usr/lib/libmagic.so.1" "${TOOL_DIR}"
		cp -f "${SYSROOT}/usr/lib/libasound.so.2" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/lib/libmpp.so.3" "${TOOL_DIR}"
		cp -f "${SYSROOT}/usr/lib/libjson-c.so.5" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/mpp/script/collect_data.sh" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/mpp/script/debug_videopipeline.sh" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/mpp/script/collect_audio_data.sh" "${TOOL_DIR}"

		cp -f "${SYSROOT}/usr/bin/aplay" "${TOOL_DIR}"
		cp -f "${SYSROOT}/usr/bin/arecord" "${TOOL_DIR}"
		cp -f "${SYSROOT}/usr/bin/amixer" "${TOOL_DIR}"
		cp -f "${SYSROOT}/usr/bin/file" "${TOOL_DIR}"
		cp -af "$AUDIO_PATTERNS" "${TOOL_DIR}"

		cp -f "${SYSROOT}/bin/busybox" "${TOOL_DIR}"
		cp -f "${SYSROOT}/system/schema.tar" "${TOOL_DIR}"

		"${STRIP}" "${TOOL_DIR}/libmagic.so.1"

		cp -af "$SDK_DIR/firmware/build/sdk-version" "${TOOL_DIR}"
		cp -af "$SDK_DIR/firmware/build/.config" "${TOOL_DIR}/Product_config"
		cp -af "$SETUP_ENV_SCRIPT" "${TOOL_DIR}"

		prepare_agtx_rtsp_server

	else
		echo "[Error] Missing required executable files"
		rm -rf "$TOOL_DIR"
		exit 1
	fi
}

safe_copy_file() {
	local src=$1
	local dest=$2
	if [ -z "${src}" ]; then
		echo "safe_copy_file src is missing."
		return 1
	fi

	if [ -z "${dest}" ]; then
		echo "safe_copy_file dest is missing."
		return 1
	fi

	if [ ! -f "${src}" ]; then
		echo "safe_copy_file src:$src not found."
		return 2
	fi

	cp -f "${src}" "${dest}"
}

safe_copy_file_regx() {
	local src_dir=$1
	local src=$2
	local dest=$3

	if [ -z "${src_dir}" ]; then
		src_dir="."
	fi

	if [ -z "${src}" ]; then
		echo "safe_copy_file src is missing."
		return 1
	fi

	if [ -z "${dest}" ]; then
		echo "safe_copy_file dest is missing."
		return 1
	fi

	find "${src_dir}" -name "${src}" -exec cp -f {} "${TOOL_DIR}" \;
}

prepare_agtx_rtsp_server (){
	safe_copy_file "${SYSROOT}/system/bin/agtx-rtsp-server" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libglib-2.0.so.0" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libgio-2.0.so.0" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libgobject-2.0.so.0" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libgmodule-2.0.so.0" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libpcre.so.1" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libpcre2-8.so.0" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libz.so.1" "${TOOL_DIR}"
	safe_copy_file "${SYSROOT}/usr/lib/libffi.so.8" "${TOOL_DIR}"
	safe_copy_file_regx "${SYSROOT}/usr/lib/" "libgst*.so.0" "${TOOL_DIR}"
	if [ -d "${SYSROOT}/usr/lib/gstreamer-1.0" ]; then
		cp -r "${SYSROOT}/usr/lib/gstreamer-1.0" "${TOOL_DIR}"
	fi
}

main "$@"
