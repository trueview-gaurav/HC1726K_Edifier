SUMMARY = "Compatibility alias: gcc-cross-x86_64 -> gcc-crosssdk-initial-x86_64"
LICENSE = "CLOSED"

DEPENDS = "gcc-crosssdk-initial-x86_64"

do_configure[noexec] = "1"
do_compile[noexec] = "1"
do_install[noexec] = "1"

# Ensure the depended-on compiler sysroot is ready
do_populate_sysroot[depends] += "gcc-crosssdk-initial-x86_64:do_populate_sysroot"

