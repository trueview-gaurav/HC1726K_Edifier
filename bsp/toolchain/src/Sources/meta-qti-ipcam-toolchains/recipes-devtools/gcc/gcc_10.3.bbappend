# Drop graphite to avoid isl dependency
#EXTRA_OECONF_append = " --disable-graphite --without-isl "
#DEPENDS_remove = " isl"
DEPENDS_append = " isl"

# We don't run GCC testsuite in this deliverable
EXTRA_OECONF_append = " --disable-bootstrap"
do_check[noexec] = "1"

# Avoid pulling in testsuite tools
DEPENDS_remove = " dejagnu-native expect-native"

# Nuke testsuite task deps (they pull dejagnu/expect even if do_check is noexec)
do_check[depends] = ""
do_check[deptask] = ""
do_check[recrdeptask] = ""

