PV = "1.0.38"

SRC_URI_remove = "git://uclibc-ng.org/git/uclibc-ng file://0001-Disable-lrount_tes-function.patch"
SRC_URI_prepend = "https://downloads.uclibc-ng.org/releases/${PV}/uClibc-ng-${PV}.tar.xz "

LIC_FILES_CHKSUM_remove = "file://${S}/test/regex/testregex.c;beginline=1;endline=31;md5=234efb227d0a40677f895e4a1e26e960"


SRC_URI[sha256sum] = "b1a3328330d2c94a2bec8c1436a8f15673f3a9b5895e155efc2e91d4e1882570"

S = "${WORKDIR}/uClibc-ng-${PV}"

# uClibc utilities may be linked without GNU_HASH; allow in short-term bring-up
INSANE_SKIP_${PN} += "ldflags"
INSANE_SKIP_${PN}-utils += "ldflags"
INSANE_SKIP_ldd += "ldflags"

# uclibc-initial: bootstrap stage only need headers/startfiles
# but Rules.mak will check --hash-style, so we should workaround

do_install_prepend () {
    if [ -f "${S}/Rules.mak" ]; then
        sed -i \
          -e 's/install_headers headers-y,/install_headers headers-y install_startfiles,/' \
          "${S}/Rules.mak"
    fi
}

# make sure the kernel headers exist
DEPENDS += " linux-libc-headers"
do_configure[depends] += "linux-libc-headers:do_populate_sysroot"
do_install[depends]   += "linux-libc-headers:do_populate_sysroot"

