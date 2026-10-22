SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/buildroot.mk

mod_trng := $(notdir $(subdir))

SRC_NAME = $(subdir)/src/$(mod_trng).c
SO_NAME = $(subdir)/build/$(mod_trng).so

tee-trng-$(CONFIG_TEE_TRNG) += tee-trng
PHONY += tee-trng tee-trng-clean tee-trng-distclean
PHONY += tee-trng-install tee-trng-uninstall

tee-trng:
	mkdir -p $(subdir)/build
	$(CROSS_COMPILE)gcc -fPIC -shared -o $(SO_NAME) $(SRC_NAME) -I$(OPENSSL_INC) -I$(OPTEE_CLIENT_SRC_PATH)/libckteec/include \
	-L$(OPTEE_CLIENT_OUT_PATH)/lib -lckteec

tee-trng-clean:
	@rm -rf $(subdir)/build

tee-trng-distclean: tee-trng-clean

tee-trng-install:
	cp -a $(SO_NAME) $(SYSROOT_DBG)/usr/lib/ossl-modules/
	
tee-trng-uninstall:
	@rm -f $(SYSROOT_REL)/usr/lib/ossl-modules/$(mod_trng).so
	@rm -f $(SYSROOT_DBG)/usr/lib/ossl-modules/$(mod_trng).so

SAMPLE_OPTEE_BUILD_DEPS += $(tee-trng-y)
SAMPLE_OPTEE_CLEAN_DEPS += $(addsuffix -clean,$(tee-trng-y))
SAMPLE_OPTEE_DISTCLEAN_DEPS += $(addsuffix -distclean,$(tee-trng-y))
SAMPLE_OPTEE_INTALL_DEPS += $(addsuffix -install,$(tee-trng-y))
SAMPLE_OPTEE_UNINTALL_DEPS += $(addsuffix -uninstall,$(tee-trng-y))
