SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

mod_cli := $(notdir $(subdir))

optee-client-$(CONFIG_OPTEE_CLIENT) += optee-client
PHONY += optee-client optee-client-clean optee-client-distclean
PHONY += optee-client-install optee-client-uninstall
optee-client:
ifeq ("$(wildcard $(OPTEE_CLIENT_BUILD_PATH)/Makefile)","")
	mkdir -p $(OPTEE_CLIENT_BUILD_PATH)
	cmake -DCMAKE_C_COMPILER=$(CROSS_COMPILE)gcc $(OPTEE_CLIENT_SRC_PATH) \
	      -B $(OPTEE_CLIENT_BUILD_PATH) $(OPTEE_CLIENT_SRC_PATH) \
	      -DCMAKE_INSTALL_PREFIX=$(OPTEE_CLIENT_OUT_PATH) \
	      -DCFG_TEE_FS_PARENT_PATH=/usrdata/tee \
	      -DCFG_TEE_SUPP_LOG_LEVEL=$(CONFIG_TEE_SUPPLICANT_LOG_LEVEL) \
	      -DCFG_TEE_CLIENT_LOG_LEVEL=$(CONFIG_TEE_CLIENT_LOG_LEVEL) \
	      -DBUILD_SHARED_LIBS=ON \
	      -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
	      -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \
	      -DCMAKE_EXE_LINKER_FLAGS="-L$(BUILDROOT_TARGET_LIB) -luuid" \
	      -DCMAKE_FIND_ROOT_PATH=$(BUILDROOT_TARGET_LIB)/../../
endif
	$(MAKE) -C $(OPTEE_CLIENT_BUILD_PATH) all
	$(MAKE) -C $(OPTEE_CLIENT_BUILD_PATH) install

optee-client-clean:
	@rm -rf $(OPTEE_CLIENT_BUILD_PATH)
	@rm -rf $(OPTEE_CLIENT_OUT_PATH)

optee-client-distclean: optee-client-clean

optee-client-install:
	install -c $(OPTEE_CLIENT_OUT_PATH)/sbin/tee-supplicant $(SYSTEM_BIN)
	cp -a $(OPTEE_CLIENT_OUT_PATH)/lib/libteec.so* $(SYSTEM_LIB)
	cp -a $(OPTEE_CLIENT_OUT_PATH)/lib/libckteec.so* $(SYSTEM_LIB)
	cp -a $(OPTEE_CLIENT_OUT_PATH)/lib/libseteec.so* $(SYSTEM_LIB)
	cp -a $(OPTEE_CLIENT_OUT_PATH)/lib/libteeacl.so* $(SYSTEM_LIB)
	
optee-client-uninstall:
	@rm -f $(SYSTEM_BIN)/tee-supplicant
	@rm -f $(SYSTEM_LIB)/libteec.so*
	@rm -f $(SYSTEM_LIB)/libckteec.so*
	@rm -f $(SYSTEM_LIB)/libseteec.so*
	@rm -f $(SYSTEM_LIB)/libteeacl.so*

PHONY += $(mod_cli) $(mod_cli)-clean $(mod_cli)-distclean
PHONY += $(mod_cli)-install $(mod_cli)-uninstall
$(mod_cli): $(optee-client-y)
$(mod_cli)-clean: $(addsuffix -clean,$(optee-client-y))
$(mod_cli)-distclean: $(addsuffix -distclean,$(optee-client-y))
$(mod_cli)-install: $(addsuffix -install,$(optee-client-y))
$(mod_cli)-uninstall: $(addsuffix -uninstall,$(optee-client-y))

SAMPLE_OPTEE_BUILD_DEPS += $(mod_cli)
SAMPLE_OPTEE_CLEAN_DEPS += $(mod_cli)-clean
SAMPLE_OPTEE_DISTCLEAN_DEPS += $(mod_cli)-distclean
SAMPLE_OPTEE_INTALL_DEPS += $(mod_cli)-install
SAMPLE_OPTEE_UNINTALL_DEPS += $(mod_cli)-uninstall
