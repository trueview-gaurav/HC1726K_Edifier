# Workaround: fixed for gcc10 build error for multiple definition
CFLAGS_append = " -fcommon"
CFLAGS_append_class-nativesdk = " -fcommon"
HOSTCFLAGS_append_class-nativesdk = " -fcommon"
