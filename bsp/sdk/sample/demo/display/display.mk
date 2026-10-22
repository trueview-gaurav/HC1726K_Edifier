mod := $(notdir $(subdir))


sample-demo-$(CONFIG_SAMPLE_DD_DEMO) += dd_demo
PHONY += dd_demo dd_demo-clean dd_demo-distclean
PHONY += dd_demo-install dd_demo-uninstall
dd_demo:
	$(Q)$(MAKE) -C $(DD_DEMO_PATH)/build all

dd_demo-clean:
	$(Q)$(MAKE) -C $(DD_DEMO_PATH)/build clean

dd_demo-distclean:
	$(Q)$(MAKE) -C $(DD_DEMO_PATH)/build distclean

dd_demo-install:
	$(Q)$(MAKE) -C $(DD_DEMO_PATH)/build install

dd_demo-uninstall:
	$(Q)$(MAKE) -C $(DD_DEMO_PATH)/build uninstall
	   
sample-demo-$(CONFIG_SAMPLE_DEMO_DFB_DEMO) += dfb_demo
PHONY += dfb_demo dfb_demo-clean dfb_demo-distclean
PHONY += dfb_demo-install dfb_demo-uninstall
dfb_demo:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build all

dfb_demo-clean:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build clean

dfb_demo-distclean:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build distclean

dfb_demo-install:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build install

dfb_demo-uninstall:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_GTK3_DEMO_GUI) += gtk3_demo_gui
PHONY += gtk3_demo_gui gtk3_demo_gui-clean gtk3_demo_gui-distclean
PHONY += gtk3_demo_gui-install gtk3_demo_gui-uninstall
gtk3_demo_gui:
	$(Q)$(MAKE) -C $(GTK3_DEMO_GUI_PATH)/build all

gtk3_demo_gui-clean:
	$(Q)$(MAKE) -C $(GTK3_DEMO_GUI_PATH)/build clean

gtk3_demo_gui-distclean:
	$(Q)$(MAKE) -C $(GTK3_DEMO_GUI_PATH)/build distclean

gtk3_demo_gui-install:
	$(Q)$(MAKE) -C $(GTK3_DEMO_GUI_PATH)/build install

gtk3_demo_gui-uninstall:
	$(Q)$(MAKE) -C $(GTK3_DEMO_GUI_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_SDL_DEMO) += sdl_demo
PHONY += sdl_demo sdl_demo-clean sdl_demo-distclean
PHONY += sdl_demo-install sdl_demo-uninstall
sdl_demo:
	$(Q)$(MAKE) -C $(SDL_DEMO_PATH)/build all

sdl_demo-clean:
	$(Q)$(MAKE) -C $(SDL_DEMO_PATH)/build clean

sdl_demo-distclean:
	$(Q)$(MAKE) -C $(SDL_DEMO_PATH)/build distclean

sdl_demo-install:
	$(Q)$(MAKE) -C $(SDL_DEMO_PATH)/build install

sdl_demo-uninstall:
	$(Q)$(MAKE) -C $(SDL_DEMO_PATH)/build uninstall

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
