
# Force libcpp (built with g++) to use C++11
EXTRA_OEMAKE_append = " \
  CXXFLAGS_FOR_BUILD='${CXXFLAGS_FOR_BUILD} -std=gnu++11' \
  CXX_FOR_BUILD='${BUILD_CXX} -std=gnu++11' \
  CXX='${BUILD_CXX} -std=gnu++11' \
"

do_configure_prepend () {
    # Some gcc-cross* code uses ${RECIPE_SYSROOT}${SDKPATHNATIVE} to stage
    # a dummy limits.h; if RECIPE_SYSROOT is empty, it becomes /opt/poky -> EACCES.
    if [ -z "${RECIPE_SYSROOT}" ]; then
        export RECIPE_SYSROOT="${STAGING_DIR_NATIVE}"
    fi
}

DEPENDS_append = " patchelf-native"

fix_sdkhost_cc1_rpath() {
    case "${PN}" in
        gcc-crosssdk-x86_64) ;;
        *) return 0 ;;
    esac

    bbnote "gcc-crosssdk: HOST_SYS=${HOST_SYS} SDK_SYS=${SDK_SYS} PV=${PV}"

    for exe in cc1 cc1plus; do
        found=0

        # for root in "${SYSROOT_DESTDIR}" "${SYSROOT_DESTDIR}${STAGING_DIR_NATIVE}"; do
        for root in "${SYSROOT_DESTDIR}" "${STAGING_DIR_NATIVE}"; do
            [ -d "$root" ] || continue

            # HOST_SYS is FOUND
            for f in $(find "$root" -type f -name "${exe}" \
                -path "*/usr/libexec/${HOST_SYS}/gcc/${HOST_SYS}/${PV}/${exe}" 2>/dev/null); do

                bbnote "gcc-crosssdk: patch ${f}"
                found=1

                ${STAGING_BINDIR_NATIVE}/patchelf --remove-rpath "$f" 2>/dev/null || true
                ${STAGING_BINDIR_NATIVE}/patchelf --set-rpath \
                  '$ORIGIN/../../../../../lib:$ORIGIN/../../../../../lib64:$ORIGIN/../../../../../../lib:$ORIGIN/../../../../../../lib64' \
                  "$f"
            done

            # HOST_SYS is NOT FOUND
            if [ "$found" = "0" ]; then
                for f in $(find "$root" -type f -name "${exe}" \
                    -path "*/usr/libexec/*/gcc/*/${PV}/${exe}" 2>/dev/null); do

                    bbnote "gcc-crosssdk: patch (fallback) ${f}"
                    found=1

                    ${STAGING_BINDIR_NATIVE}/patchelf --remove-rpath "$f" 2>/dev/null || true
                    ${STAGING_BINDIR_NATIVE}/patchelf --set-rpath \
                      '$ORIGIN/../../../../../lib:$ORIGIN/../../../../../lib64:$ORIGIN/../../../../../../lib:$ORIGIN/../../../../../../lib64' \
                      "$f"
                done
            fi
        done

        if [ "$found" = "0" ]; then
            bbwarn "gcc-crosssdk: ${exe} not found; no patch applied"
        fi
    done
}

do_populate_sysroot[postfuncs] += " fix_sdkhost_cc1_rpath"


# GCC 10.3 libcpp uses C++11 constructs; some builds invoke g++ without -std=...
# Force build-side C++ standard for gcc-crosssdk (host tools in SDK).
BUILD_CXXFLAGS += " -std=gnu++11"
CXXFLAGS_FOR_BUILD += " -std=gnu++11"

