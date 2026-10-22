mod_ex := $(notdir $(subdir))


ifeq ("$(CONFIG_HELLO_WORLD_EXAMPLE)","y")
EXAMPLE_LIST += hello_world
endif
ifeq ("$(CONFIG_AES_EXAMPLE)","y")
EXAMPLE_LIST += aes
endif
ifeq ("$(CONFIG_ACIPHER_EXAMPLE)","y")
EXAMPLE_LIST += acipher
endif
ifeq ("$(CONFIG_HOTP_EXAMPLE)","y")
EXAMPLE_LIST += hotp
endif
ifeq ("$(CONFIG_RANDOM_EXAMPLE)","y")
EXAMPLE_LIST += random
endif
ifeq ("$(CONFIG_SECURE_STORAGE_EXAMPLE)","y")
EXAMPLE_LIST += secure_storage
endif
ifeq ("$(CONFIG_USER_AUTH_AGTX_EXAMPLE)","y")
EXAMPLE_LIST += user_auth_agtx
endif
ifeq ("$(CONFIG_SECURE_STORAGE_AGTX_EXAMPLE)","y")
EXAMPLE_LIST += secure_storage_agtx
endif


RM_TARGET = $(addprefix $(SYSTEM_BIN)/optee_example_,$(EXAMPLE_LIST))

optee-examples-$(CONFIG_OPTEE_EXAMPLES) += optee-examples
PHONY += optee-examples optee-examples-clean optee-examples-distclean
PHONY += optee-examples-install optee-examples-uninstall
PHONY += show
optee-examples:
	$(MAKE) -C $(OPTEE_EXAMPLES_PATH) all TEEC_EXPORT=$(OPTEE_CLIENT_OUT_PATH) \
	PLATFORM=augentix TA_DEV_KIT_DIR=$(OPTEE_PATH)/output/export-ta_arm32 \
	--no-builtin-variables EXAMPLE_LIST="$(EXAMPLE_LIST)"
	echo $(EXAMPLE_LIST)

optee-examples-clean:
	$(MAKE) -C $(OPTEE_EXAMPLES_PATH) clean \
	TA_DEV_KIT_DIR=$(OPTEE_PATH)/output/export-ta_arm32

optee-examples-distclean: optee-examples-clean

optee-examples-install:
	@cp -f $(OPTEE_EXAMPLES_OUT_PATH)/ca/* $(SYSTEM_BIN)
	@mkdir -p $(SYSROOT_DBG)/lib/optee_armtz
	@cp -f $(OPTEE_EXAMPLES_OUT_PATH)/ta/* $(SYSROOT_DBG)/lib/optee_armtz

optee-examples-uninstall:
	@rm -f $(RM_TARGET)
	@rm -rf $(SYSROOT_DBG)/lib/optee_armtz

PHONY += $(mod_ex) $(mod_ex)-clean $(mod_ex)-distclean
PHONY += $(mod_ex)-install $(mod_ex)-uninstall
$(mod_ex): $(optee-examples-y)
$(mod_ex)-clean: $(addsuffix -clean,$(optee-examples-y))
$(mod_ex)-distclean: $(addsuffix -distclean,$(optee-examples-y))
$(mod_ex)-install: $(addsuffix -install,$(optee-examples-y))
$(mod_ex)-uninstall: $(addsuffix -uninstall,$(optee-examples-y))

SAMPLE_OPTEE_BUILD_DEPS += $(mod_ex)
SAMPLE_OPTEE_CLEAN_DEPS += $(mod_ex)-clean
SAMPLE_OPTEE_DISTCLEAN_DEPS += $(mod_ex)-distclean
SAMPLE_OPTEE_INTALL_DEPS += $(mod_ex)-install
SAMPLE_OPTEE_UNINTALL_DEPS += $(mod_ex)-uninstall
