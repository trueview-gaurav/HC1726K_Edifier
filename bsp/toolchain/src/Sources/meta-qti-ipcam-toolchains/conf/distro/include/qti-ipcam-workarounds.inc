# SDK / nativesdk workarounds
EXTRA_OECONF_append_pn-nativesdk-db = " --disable-cxx --disable-stl"
EXTRA_OECONF_append_pn-nativesdk-libpcre = " --disable-cpp"

# binutils-cross-canadian (arm): disable gold
EXTRA_OECONF_append_pn-binutils-cross-canadian-arm = " --disable-gold"

