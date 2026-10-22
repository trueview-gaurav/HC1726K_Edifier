################################################################################
#
# pkcs11-provider
#
################################################################################

PKCS11_PROVIDER_VERSION = v1.0
PKCS11_PROVIDER_SITE = $(call github,latchset,pkcs11-provider,$(PKCS11_PROVIDER_VERSION))
PKCS11_PROVIDER_LICENSE = Apache-2.0
PKCS11_PROVIDER_LICENSE_FILES = COPYING

PKCS11_PROVIDER_DEPENDENCIES = openssl
PKCS11_PROVIDER_CONF_OPTS = \
	-Ddefault_pkcs11_module=/system/lib/libckteec.so \
	-Dbuild.pkg_config_path=

$(eval $(meson-package))