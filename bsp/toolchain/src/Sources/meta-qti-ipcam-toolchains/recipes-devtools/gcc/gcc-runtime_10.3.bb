require recipes-devtools/gcc/gcc-${PV}.inc
require gcc-runtime.inc

# Krogoth has no dejagnu recipe; we do not run GCC runtime testsuites.
do_check[noexec] = "1"
do_check[depends] = ""

# In case something adds them via DEPENDS
DEPENDS_remove = "dejagnu-native expect-native"

