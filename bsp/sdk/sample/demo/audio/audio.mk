mod := $(notdir $(subdir))

sample-demo-$(CONFIG_LIBADO) += libado
PHONY += libado libado-clean libado-distclean
PHONY += libado-install libado-uninstall
libado:
	$(Q)$(MAKE) -C $(LIBADO_PATH) all

libado-clean:
	$(Q)$(MAKE) -C $(LIBADO_PATH) clean

libado-distclean:
	$(Q)$(MAKE) -C $(LIBADO_PATH) distclean

libado-install:
	$(Q)$(MAKE) -C $(LIBADO_PATH) install

libado-uninstall:
	$(Q)$(MAKE) -C $(LIBADO_PATH) uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_ACTL) += actl
PHONY += actl actl-clean actl-distclean
PHONY += actl-install actl-uninstall
actl:
	$(Q)$(MAKE) -C $(ACTL_PATH) all

actl-clean:
	$(Q)$(MAKE) -C $(ACTL_PATH) clean

actl-distclean:
	$(Q)$(MAKE) -C $(ACTL_PATH) distclean

actl-install:
	$(Q)$(MAKE) -C $(ACTL_PATH) install

actl-uninstall:
	$(Q)$(MAKE) -C $(ACTL_PATH) uninstall
 
sample-demo-$(CONFIG_SAMPLE_DEMO_G726) += g726
PHONY += g726 g726-clean g726-distclean
PHONY += g726-install g726-uninstall
g726:
	$(Q)$(MAKE) -C $(G726_PATH)/build all

g726-clean:
	$(Q)$(MAKE) -C $(G726_PATH)/build clean

g726-distclean:
	$(Q)$(MAKE) -C $(G726_PATH)/build distclean

g726-install:
	$(Q)$(MAKE) -C $(G726_PATH)/build install

g726-uninstall:
	$(Q)$(MAKE) -C $(G726_PATH)/build uninstall

PHONY += $(mod) $(mod)-clean $(mod)-distclean
PHONY += $(mod)-install $(mod)-uninstall
$(mod): $(sample-demo-y)
$(mod)-clean: $(addsuffix -clean,$(sample-demo-y))
$(mod)-distclean: $(addsuffix -distclean,$(sample-demo-y))
$(mod)-install: $(addsuffix -install,$(sample-demo-y))
$(mod)-uninstall: $(addsuffix -uninstall,$(sample-demo-y))

SAMPLE_DEMO_BUILD_DEPS += $(mod)
SAMPLE_DEMO_CLEAN_DEPS += $(mod)-clean
SAMPLE_DEMO_DISTCLEAN_DEPS += $(mod)-distclean
SAMPLE_DEMO_INTALL_DEPS += $(mod)-install
SAMPLE_DEMO_UNINTALL_DEPS += $(mod)-uninstall
