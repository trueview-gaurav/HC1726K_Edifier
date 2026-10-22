mod_mc := $(notdir $(subdir))

OPTEE_EFUSE_PATH = $(SAMPLE_OPTEE_PATH)/efuse
OPTEE_EFUSE_OUT_PATH = $(SAMPLE_OPTEE_PATH)/efuse/out

RM_TARGET = $(addprefix $(SYSTEM_BIN)/,uuid)


tee-efuse-$(CONFIG_TEE_EFUSE) += tee-efuse
PHONY += tee-efuse tee-efuse-clean tee-efuse-distclean
PHONY += tee-efuse-install tee-efuse-uninstall

tee-efuse:
	$(MAKE) -C $(OPTEE_EFUSE_PATH) all TEEC_EXPORT=$(OPTEE_CLIENT_OUT_PATH)
	echo $(mod_mc)

tee-efuse-clean:
	$(MAKE) -C $(OPTEE_EFUSE_PATH) clean

tee-efuse-distclean: tee-efuse-clean

tee-efuse-install:
	@cp -f $(OPTEE_EFUSE_OUT_PATH)/ca/* $(SYSTEM_BIN)

tee-efuse-uninstall:
	@rm -f $(RM_TARGET)

PHONY += $(mod_mc) $(mod_mc)-clean $(mod_mc)-distclean
PHONY += $(mod_mc)-install $(mod_mc)-uninstall

SAMPLE_OPTEE_BUILD_DEPS += $(tee-efuse-y)
SAMPLE_OPTEE_CLEAN_DEPS += $(addsuffix -clean,$(tee-efuse-y))
SAMPLE_OPTEE_DISTCLEAN_DEPS += $(addsuffix -distclean,$(tee-efuse-y))
SAMPLE_OPTEE_INTALL_DEPS += $(addsuffix -install,$(tee-efuse-y))
SAMPLE_OPTEE_UNINTALL_DEPS += $(addsuffix -uninstall,$(tee-efuse-y))
