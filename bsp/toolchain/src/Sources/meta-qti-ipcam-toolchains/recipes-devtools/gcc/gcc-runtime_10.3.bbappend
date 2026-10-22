# We don't run GCC runtime testsuite in this deliverable
#do_check[noexec] = "1"
#do_check[depends] = ""
#do_check[deptask] = ""
#do_check[recrdeptask] = ""

do_install_append() {
    # Only apply to target gcc-runtime (avoid touching nativesdk-gcc-runtime)
    case "${PN}" in
        gcc-runtime) ;;
        *) return 0 ;;
    esac

    inc="${D}${includedir}/c++/${PV}"

    # We should link header file from uclibceabi to gnueabi
    if [ -d "${inc}/${TARGET_SYS}" ]; then
        if [ -e "${inc}/${QTI_IPCAM_GNUEABI_SYS}" ] && [ ! -L "${inc}/${QTI_IPCAM_GNUEABI_SYS}" ]; then
            bbwarn "gcc-runtime: ${inc}/${QTI_IPCAM_GNUEABI_SYS} exists and is not a symlink; not overwriting"
         else
             ( cd "${inc}" && ln -snf "${TARGET_SYS}" "${QTI_IPCAM_GNUEABI_SYS}" )
         fi
     fi

}

FILES_libstdc++-dev_append = " ${includedir}/c++/${PV}/${QTI_IPCAM_GNUEABI_SYS}"

EXTRA_OECONF_append = " \
    --disable-libmudflap \
    --disable-libgomp \
    --disable-libquadmath \
    --disable-libquadmath-support \
    --disable-libsanitizer \
    --disable-libmpx \
    --disable-libstdcxx-verbose \
    --enable-__cxa_atexit \
"

# Build gcc-runtime (libstdc++/libgcc_s/etc.) with size optimization
SELECTED_OPTIMIZATION_pn-gcc-runtime = "-Os -pipe"

# Optional extra shrink (usually safe)
CFLAGS_append_pn-gcc-runtime   = " -ffunction-sections -fdata-sections"
CXXFLAGS_append_pn-gcc-runtime = " -ffunction-sections -fdata-sections"
LDFLAGS_append_pn-gcc-runtime  = " -Wl,--gc-sections"
