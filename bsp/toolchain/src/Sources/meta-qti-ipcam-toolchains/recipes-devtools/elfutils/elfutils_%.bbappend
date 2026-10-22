# Workaround for nativesdk-elfutils build error
CFLAGS_remove_class-nativesdk = " -Werror"
CFLAGS_append_class-nativesdk = " \
  -Wno-error=missing-attributes \
  -Wno-error=implicit-fallthrough \
  -Wno-error=format-truncation \
  -Wno-error=format-overflow \
"

