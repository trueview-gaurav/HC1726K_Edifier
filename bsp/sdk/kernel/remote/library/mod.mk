mod_lib := $(notdir $(subdir))

mod_lib-$(CONFIG_LIBTFLITE_MICRO) := libtflite_micro
PHONY += libtflite_micro libtflite_micro-clean libtflite_micro-distclean
PHONY += libtflite_micro-install libtflite_micro-uninstall
libtflite_micro:
	$(Q)$(MAKE) -C $(TFLITE_MICRO_PATH) all

libtflite_micro-clean:
	$(Q)$(MAKE) -C $(TFLITE_MICRO_PATH) clean

libtflite_micro-distclean:
	$(Q)$(MAKE) -C $(TFLITE_MICRO_PATH) distclean

libtflite_micro-install:
	$(Q)$(MAKE) -C $(TFLITE_MICRO_PATH) install

libtflite_micro-uninstall:
	$(Q)$(MAKE) -C $(TFLITE_MICRO_PATH) uninstall

mod_lib-$(CONFIG_LIBNCNN) += libncnn
PHONY += libncnn libncnn-clean libncnn-distclean
PHONY += libncnn-install libncnn-uninstall
libncnn:
	$(Q)$(MAKE) -C $(NCNN_PATH)/build all

libncnn-clean:
	$(Q)$(MAKE) -C $(NCNN_PATH)/build clean

libncnn-distclean:
	$(Q)$(MAKE) -C $(NCNN_PATH)/build distclean

libncnn-install:
	$(Q)$(MAKE) -C $(NCNN_PATH)/build install

libncnn-uninstall:
	$(Q)$(MAKE) -C $(NCNN_PATH)/build uninstall

mod_lib-$(CONFIG_LIBROSA) += librosa
PHONY += librosa librosa-clean librosa-distclean
PHONY += librosa-install librosa-uninstall
librosa:
	$(Q)$(MAKE) -C $(ROSA_PATH)/build all

librosa-clean:
	$(Q)$(MAKE) -C $(ROSA_PATH)/build clean

librosa-distclean:
	$(Q)$(MAKE) -C $(ROSA_PATH)/build distclean

librosa-install:
	$(Q)$(MAKE) -C $(ROSA_PATH)/build install

librosa-uninstall:
	$(Q)$(MAKE) -C $(ROSA_PATH)/build uninstall

mod_lib-$(CONFIG_LIBMETAL) += libmetal
PHONY += libmetal libmetal-clean libmetal-distclean
PHONY += libmetal-install libmetal-uninstall
libmetal:
	$(Q)$(MAKE) -C $(LIBMETAL_SRC_PATH)/build all

libmetal-clean:
	$(Q)$(MAKE) -C $(LIBMETAL_SRC_PATH)/build clean
	@echo $(mod_lib-y)

libmetal-distclean:
	$(Q)$(MAKE) -C $(LIBMETAL_SRC_PATH)/build distclean

libmetal-install:
	$(Q)$(MAKE) -C $(LIBMETAL_SRC_PATH)/build install

libmetal-uninstall:
	$(Q)$(MAKE) -C $(LIBMETAL_SRC_PATH)/build uninstall

mod_lib-$(CONFIG_LIBAMPC) += libampc
PHONY += libampc libampc-clean libampc-distclean
PHONY += libampc-install libampc-uninstall
libampc: libmetal libopen_amp
	$(Q)$(MAKE) -C $(AMPC_SRC_PATH)/build all

libampc-clean:
	$(Q)$(MAKE) -C $(AMPC_SRC_PATH)/build clean

libampc-distclean:
	$(Q)$(MAKE) -C $(AMPC_SRC_PATH)/build distclean

libampc-install:
	$(Q)$(MAKE) -C $(AMPC_SRC_PATH)/build install

libampc-uninstall:
	$(Q)$(MAKE) -C $(AMPC_SRC_PATH)/build uninstall

mod_lib-$(CONFIG_LIBOPEN_AMP) += libopen_amp
PHONY += libopen_amp libopen_amp-clean libopen_amp-distclean
PHONY += libopen_amp-install libopen_amp-uninstall
libopen_amp:
	$(Q)$(MAKE) -C $(OPENAMP_SRC_PATH)/build all

libopen_amp-clean:
	$(Q)$(MAKE) -C $(OPENAMP_SRC_PATH)/build clean

libopen_amp-distclean:
	$(Q)$(MAKE) -C $(OPENAMP_SRC_PATH)/build distclean

libopen_amp-install:
	$(Q)$(MAKE) -C $(OPENAMP_SRC_PATH)/build install

PHONY += $(mod_lib) $(mod_lib)-clean $(mod_lib)-distclean
PHONY += $(mod_lib)-install $(mod_lib)-uninstall
$(mod_lib): $(mod_lib-y)
$(mod_lib)-clean: $(addsuffix -clean,$(mod_lib-y))
$(mod_lib)-distclean: $(addsuffix -distclean,$(mod_lib-y))
$(mod_lib)-install: $(addsuffix -install,$(mod_lib-y))
$(mod_lib)-uninstall: $(addsuffix -uninstall,$(mod_lib-y))

REMOTE_BUILD_DEPS += $(mod_lib)
REMOTE_CLEAN_DEPS += $(mod_lib)-clean
REMOTE_DISTCLEAN_DEPS += $(mod_lib)-distclean
REMOTE_INSTALL_DEPS += $(mod_lib)-install
REMOTE_UNINSTALL_DEPS += $(mod_lib)-uninstall
