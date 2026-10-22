# Workaround: fixed build error for glib-2.0
CFLAGS_append_class-nativesdk = " -Wno-error=format-overflow -Wno-error=format-truncation"
