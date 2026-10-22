mod_mc := $(notdir $(subdir))

OPTEE_SE_SIM_PATH = $(SAMPLE_OPTEE_PATH)/se_sim
OPTEE_SE_SIM_OUT_PATH = $(SAMPLE_OPTEE_PATH)/se_sim/out

RM_TARGET = $(addprefix $(SYSTEM_BIN)/,$(mod_mc))


tee-se-sim-$(CONFIG_TEE_SE_SIM) += tee-se-sim
PHONY += tee-se-sim tee-se-sim-clean tee-se-sim-distclean
PHONY += tee-se-sim-install tee-se-sim-uninstall

tee-se-sim:
	$(MAKE) -C $(OPTEE_SE_SIM_PATH) all TEEC_EXPORT=$(OPTEE_CLIENT_OUT_PATH)
	echo $(mod_mc)

tee-se-sim-clean:
	$(MAKE) -C $(OPTEE_SE_SIM_PATH) clean

tee-se-sim-distclean: tee-se-sim-clean

tee-se-sim-install:
	@cp -f $(OPTEE_SE_SIM_OUT_PATH)/ca/* $(SYSTEM_BIN)

tee-se-sim-uninstall:
	@rm -f $(RM_TARGET)

PHONY += $(mod_mc) $(mod_mc)-clean $(mod_mc)-distclean
PHONY += $(mod_mc)-install $(mod_mc)-uninstall

SAMPLE_OPTEE_BUILD_DEPS += $(tee-se-sim-y)
SAMPLE_OPTEE_CLEAN_DEPS += $(addsuffix -clean,$(tee-se-sim-y))
SAMPLE_OPTEE_DISTCLEAN_DEPS += $(addsuffix -distclean,$(tee-se-sim-y))
SAMPLE_OPTEE_INTALL_DEPS += $(addsuffix -install,$(tee-se-sim-y))
SAMPLE_OPTEE_UNINTALL_DEPS += $(addsuffix -uninstall,$(tee-se-sim-y))
