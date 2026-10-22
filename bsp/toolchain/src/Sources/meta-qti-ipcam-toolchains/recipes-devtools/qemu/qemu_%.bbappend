# Workaround: avoid include_next CANT FOUND stdlib.h
CFLAGS_remove_class-nativesdk   = " -isystem${STAGING_INCDIR}"
CPPFLAGS_remove_class-nativesdk = " -isystem${STAGING_INCDIR}"
CXXFLAGS_remove_class-nativesdk = " -isystem${STAGING_INCDIR}"
