# Workaround: fixed yylloc (-fcommon) & libfdt.so PIC(-fPIC)
HOSTCFLAGS_append_pn-nativesdk-dtc = " -fcommon -fPIC"
CFLAGS_append_pn-nativesdk-dtc     = " -fcommon -fPIC"
EXTRA_OEMAKE_append_pn-nativesdk-dtc = " HOSTCFLAGS+=' -fcommon -fPIC' CFLAGS+=' -fcommon -fPIC' "
