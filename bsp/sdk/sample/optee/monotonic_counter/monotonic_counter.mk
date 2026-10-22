mod_mc := $(notdir $(subdir))

OPTEE_MONO_CNT_PATH = $(SAMPLE_OPTEE_PATH)/monotonic_counter
OPTEE_MONO_CNT_OUT_PATH = $(SAMPLE_OPTEE_PATH)/monotonic_counter/out

RM_TARGET = $(addprefix $(SYSTEM_BIN)/,$(mod_mc))


tee-monotonic-cnt-$(CONFIG_TEE_MONO_CNT) += tee-monotonic-cnt
PHONY += tee-monotonic-cnt tee-monotonic-cnt-clean tee-monotonic-cnt-distclean
PHONY += tee-monotonic-cnt-install tee-monotonic-cnt-uninstall

tee-monotonic-cnt:
	$(MAKE) -C $(OPTEE_MONO_CNT_PATH) all TEEC_EXPORT=$(OPTEE_CLIENT_OUT_PATH)
	echo $(mod_mc)

tee-monotonic-cnt-clean:
	$(MAKE) -C $(OPTEE_MONO_CNT_PATH) clean

tee-monotonic-cnt-distclean: tee-monotonic-cnt-clean

tee-monotonic-cnt-install:
	@cp -f $(OPTEE_MONO_CNT_OUT_PATH)/ca/* $(SYSTEM_BIN)

tee-monotonic-cnt-uninstall:
	@rm -f $(RM_TARGET)

PHONY += $(mod_mc) $(mod_mc)-clean $(mod_mc)-distclean
PHONY += $(mod_mc)-install $(mod_mc)-uninstall

SAMPLE_OPTEE_BUILD_DEPS += $(tee-monotonic-cnt-y)
SAMPLE_OPTEE_CLEAN_DEPS += $(addsuffix -clean,$(tee-monotonic-cnt-y))
SAMPLE_OPTEE_DISTCLEAN_DEPS += $(addsuffix -distclean,$(tee-monotonic-cnt-y))
SAMPLE_OPTEE_INTALL_DEPS += $(addsuffix -install,$(tee-monotonic-cnt-y))
SAMPLE_OPTEE_UNINTALL_DEPS += $(addsuffix -uninstall,$(tee-monotonic-cnt-y))
