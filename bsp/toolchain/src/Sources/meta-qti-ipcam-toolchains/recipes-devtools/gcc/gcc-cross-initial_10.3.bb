require recipes-devtools/gcc/gcc-cross_${PV}.bb
require gcc-cross-initial.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://limits-bootstrap.h"

# 讓 BUILD_CPPFLAGS 會被 export 到 configure 環境
export BUILD_CPPFLAGS
BUILD_CPPFLAGS_append = " -include ${B}/limits-bootstrap.h"

# GCC 10 的 build tools（libcpp 等）需要 C++11
export BUILD_CXXFLAGS
BUILD_CXXFLAGS_append = " -std=gnu++11"

export CXXFLAGS_FOR_BUILD
CXXFLAGS_FOR_BUILD_append = " -std=gnu++11"

# Host g++ (Ubuntu 16.04) default is gnu++98; GCC 10 libcpp needs C++11
CXXFLAGS_append = " -std=gnu++11"

do_configure_prepend () {
    install -d ${B}

    src="${WORKDIR}/limits-bootstrap.h"
    if [ ! -f "$src" ]; then
        src="${THISDIR}/files/limits-bootstrap.h"
    fi

    install -m 0644 "$src" ${B}/limits-bootstrap.h
}

do_compile_append () {
    # GCC 的 install-unwind_h 需要 builddir/libgcc/unwind.h 存在
    for d in ${B}/${TARGET_SYS}/libgcc ${B}/libgcc; do
        if [ -f "$d/Makefile" ]; then
            bbnote "Force-generate unwind.h in $d"
            oe_runmake -C "$d" unwind.h enable-execute-stack.c md-unwind-support.h sfp-machine.h gthr-default.h || true
        fi
    done
}

# 只針對 make 階段把 LD_LIBRARY_PATH 硬塞進去（避免被中途 reset 掉）
EXTRA_OEMAKE_append = " LD_LIBRARY_PATH=${STAGING_DIR_NATIVE}/usr/lib:${STAGING_DIR_NATIVE}/lib"

do_install_prepend () {
    export LD_LIBRARY_PATH="${STAGING_DIR_NATIVE}/usr/lib:${STAGING_DIR_NATIVE}/lib:${LD_LIBRARY_PATH}"
    echo "DEBUG(do_install): LD_LIBRARY_PATH=${LD_LIBRARY_PATH}" >&2
    echo "DEBUG(do_install): ldd cc1:" >&2
    ldd ${B}/gcc/cc1 | egrep 'mpfr|gmp|mpc|not found' >&2 || true
}

# 讓 do_gcc_stash_builddir 可重跑：每次開始前先清掉 shared components 目的地
gcc_stash_clean_components () {
    rm -rf ${TMPDIR}/components/${BUILD_ARCH}/gcc-stashed-builddir-${TARGET_SYS}
}

do_gcc_stash_builddir[prefuncs] += "gcc_stash_clean_components"

