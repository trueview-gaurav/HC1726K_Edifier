mod := $(notdir $(subdir))

sample-demo-$(CONFIG_LIBEAIF) += libeaif
PHONY += libeaif libeaif-clean libeaif-distclean
PHONY += libeaif-install libeaif-uninstall
libeaif: libinf
	$(Q)$(MAKE) -C $(LIBEAIF_PATH)/build all

libeaif-clean: libinf-clean
	$(Q)$(MAKE) -C $(LIBEAIF_PATH)/build clean

libeaif-install: libinf-install
	$(Q)$(MAKE) -C $(LIBEAIF_PATH)/build install

libeaif-uninstall: libinf-uninstall
	$(Q)$(MAKE) -C $(LIBEAIF_PATH)/build uninstall

libeaif-distclean: libinf-distclean
	$(Q)$(MAKE) -C $(LIBEAIF_PATH)/build distclean

sample-demo-$(CONFIG_LIBINF) += libinf
PHONY += libinf libinf-clean libinf-distclean
PHONY += libinf-install libinf-uninstall

libinf:
	$(Q)$(MAKE) -C $(LIBINF_PATH)/build all

libinf-clean:
	$(Q)$(MAKE) -C $(LIBINF_PATH)/build clean

libinf-install:
	$(Q)$(MAKE) -C $(LIBINF_PATH)/build install

libinf-uninstall:
	$(Q)$(MAKE) -C $(LIBINF_PATH)/build uninstall

libinf-distclean:
	$(Q)$(MAKE) -C $(LIBINF_PATH)/build distclean


sample-demo-$(CONFIG_SAMPLE_DEMO_VFTR_DUMP) += vftr_dump
PHONY += vftr_dump vftr_dump-clean vftr_dump-distclean
PHONY += vftr_dump-install vftr_dump-uninstall
vftr_dump:
	$(Q)$(MAKE) -C $(VFTR_DUMP_PATH)/build all

vftr_dump-clean:
	$(Q)$(MAKE) -C $(VFTR_DUMP_PATH)/build clean

vftr_dump-distclean:
	$(Q)$(MAKE) -C $(VFTR_DUMP_PATH)/build distclean

vftr_dump-install:
	$(Q)$(MAKE) -C $(VFTR_DUMP_PATH)/build install

vftr_dump-uninstall:
	$(Q)$(MAKE) -C $(VFTR_DUMP_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_AROI_DEMO) += aroi_demo
PHONY += aroi_demo aroi_demo-clean aroi_demo-distclean
PHONY += aroi_demo-install aroi_demo-uninstall
aroi_demo:
	$(Q)$(MAKE) -C $(AROI_DEMO_PATH)/build all

aroi_demo-clean:
	$(Q)$(MAKE) -C $(AROI_DEMO_PATH)/build clean

aroi_demo-distclean:
	$(Q)$(MAKE) -C $(AROI_DEMO_PATH)/build distclean

aroi_demo-install:
	$(Q)$(MAKE) -C $(AROI_DEMO_PATH)/build install

aroi_demo-uninstall:
	$(Q)$(MAKE) -C $(AROI_DEMO_PATH)/build uninstall


sample-demo-$(CONFIG_SAMPLE_DEMO_AUTO_TRACKING) += auto_tracking
PHONY += auto_tracking auto_tracking-clean auto_tracking-distclean
PHONY += auto_tracking-install auto_tracking-uninstall
auto_tracking: libsample libmotor
	$(Q)$(MAKE) -C $(AUTO_TRACKING_PATH)/build all

auto_tracking-clean: libsample-clean libmotor-clean
	$(Q)$(MAKE) -C $(AUTO_TRACKING_PATH)/build clean

auto_tracking-distclean: libsample-distclean libmotor-distclean
	$(Q)$(MAKE) -C $(AUTO_TRACKING_PATH)/build distclean

auto_tracking-install: libsample-install libmotor-install
	$(Q)$(MAKE) -C $(AUTO_TRACKING_PATH)/build install

auto_tracking-uninstall: libsample-uninstall libmotor-uninstall
	$(Q)$(MAKE) -C $(AUTO_TRACKING_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_BM_DEMO) += bm_demo
PHONY += bm_demo bm_demo-clean bm_demo-distclean
PHONY += bm_demo-install bm_demo-uninstall
bm_demo:
	$(Q)$(MAKE) -C $(BM_DEMO_PATH)/build all

bm_demo-clean:
	$(Q)$(MAKE) -C $(BM_DEMO_PATH)/build clean

bm_demo-distclean:
	$(Q)$(MAKE) -C $(BM_DEMO_PATH)/build distclean

bm_demo-install:
	$(Q)$(MAKE) -C $(BM_DEMO_PATH)/build install

bm_demo-uninstall:
	$(Q)$(MAKE) -C $(BM_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_DK_DEMO) += dk_demo
PHONY += dk_demo dk_demo-clean dk_demo-distclean
PHONY += dk_demo-install dk_demo-uninstall
dk_demo:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build all

dk_demo-clean:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build clean

dk_demo-distclean:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build distclean

dk_demo-install:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build install

dk_demo-uninstall:
	$(Q)$(MAKE) -C $(DK_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_EF_DEMO) += ef_demo
PHONY += ef_demo ef_demo-clean ef_demo-distclean
PHONY += ef_demo-install ef_demo-uninstall
ef_demo:
	$(Q)$(MAKE) -C $(EF_DEMO_PATH)/build all

ef_demo-clean:
	$(Q)$(MAKE) -C $(EF_DEMO_PATH)/build clean

ef_demo-distclean:
	$(Q)$(MAKE) -C $(EF_DEMO_PATH)/build distclean

ef_demo-install:
	$(Q)$(MAKE) -C $(EF_DEMO_PATH)/build install

ef_demo-uninstall:
	$(Q)$(MAKE) -C $(EF_DEMO_PATH)/build uninstall
	
sample-demo-$(CONFIG_SAMPLE_DEMO_FACEDET_DEMO) += facedet_demo
PHONY += facedet_demo facedet_demo-clean facedet_demo-distclean
PHONY += facedet_demo-install facedet_demo-uninstall
facedet_demo: libinf
	$(Q)$(MAKE) -C $(FACEDET_DEMO_PATH)/build all

facedet_demo-clean: libinf-clean
	$(Q)$(MAKE) -C $(FACEDET_DEMO_PATH)/build clean

facedet_demo-distclean: libinf-distclean
	$(Q)$(MAKE) -C $(FACEDET_DEMO_PATH)/build distclean

facedet_demo-install: libinf-install
	$(Q)$(MAKE) -C $(FACEDET_DEMO_PATH)/build install

facedet_demo-uninstall: libinf-uninstall
	$(Q)$(MAKE) -C $(FACEDET_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_FACERECO_DEMO) += facereco_demo
PHONY += facereco_demo facereco_demo-clean facereco_demo-distclean
PHONY += facereco_demo-install facereco_demo-uninstall
facereco_demo: libeaif
	$(Q)$(MAKE) -C $(FACERECO_DEMO_PATH)/build all

facereco_demo-clean: libeaif-clean
	$(Q)$(MAKE) -C $(FACERECO_DEMO_PATH)/build clean

facereco_demo-distclean: libeaif-distclean
	$(Q)$(MAKE) -C $(FACERECO_DEMO_PATH)/build distclean

facereco_demo-install: libeaif-install
	$(Q)$(MAKE) -C $(FACERECO_DEMO_PATH)/build install

facereco_demo-uninstall: libeaif-uninstall
	$(Q)$(MAKE) -C $(FACERECO_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_FLD_DEMO) += fld_demo
PHONY += fld_demo fld_demo-clean fld_demo-distclean
PHONY += fld_demo-install fld_demo-uninstall
fld_demo:
	$(Q)$(MAKE) -C $(FLD_DEMO_PATH)/build all

fld_demo-clean:
	$(Q)$(MAKE) -C $(FLD_DEMO_PATH)/build clean

fld_demo-distclean:
	$(Q)$(MAKE) -C $(FLD_DEMO_PATH)/build distclean

fld_demo-install:
	$(Q)$(MAKE) -C $(FLD_DEMO_PATH)/build install

fld_demo-uninstall:
	$(Q)$(MAKE) -C $(FLD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_HD_DEMO) += hd_demo
PHONY += hd_demo hd_demo-clean hd_demo-distclean
PHONY += hd_demo-install hd_demo-uninstall
hd_demo: libeaif libinf
	$(Q)$(MAKE) -C $(HD_DEMO_PATH)/build all

hd_demo-clean: libeaif-clean libinf-clean
	$(Q)$(MAKE) -C $(HD_DEMO_PATH)/build clean

hd_demo-distclean: libeaif-distclean libinf-distclean
	$(Q)$(MAKE) -C $(HD_DEMO_PATH)/build distclean

hd_demo-install: libeaif-install libinf-install
	$(Q)$(MAKE) -C $(HD_DEMO_PATH)/build install

hd_demo-uninstall: libeaif-uninstall libinf-uninstall
	$(Q)$(MAKE) -C $(HD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_LOD_DEMO) += lod_demo
PHONY += lod_demo lod_demo-clean lod_demo-distclean
PHONY += lod_demo-install lod_demo-uninstall
lod_demo:
	$(Q)$(MAKE) -C $(LOD_DEMO_PATH)/build all

lod_demo-clean:
	$(Q)$(MAKE) -C $(LOD_DEMO_PATH)/build clean

lod_demo-distclean:
	$(Q)$(MAKE) -C $(LOD_DEMO_PATH)/build distclean

lod_demo-install:
	$(Q)$(MAKE) -C $(LOD_DEMO_PATH)/build install

lod_demo-uninstall:
	$(Q)$(MAKE) -C $(LOD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_LSD_DEMO) += lsd_demo
PHONY += lsd_demo lsd_demo-clean lsd_demo-distclean
PHONY += lsd_demo-install lsd_demo-uninstall
lsd_demo:
	$(Q)$(MAKE) -C $(LSD_DEMO_PATH)/build all

lsd_demo-clean:
	$(Q)$(MAKE) -C $(LSD_DEMO_PATH)/build clean

lsd_demo-distclean:
	$(Q)$(MAKE) -C $(LSD_DEMO_PATH)/build distclean

lsd_demo-install:
	$(Q)$(MAKE) -C $(LSD_DEMO_PATH)/build install

lsd_demo-uninstall:
	$(Q)$(MAKE) -C $(LSD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_SD_DEMO) += sd_demo
PHONY += sd_demo sd_demo-clean sd_demo-distclean
PHONY += sd_demo-install sd_demo-uninstall
sd_demo:
	$(Q)$(MAKE) -C $(SD_DEMO_PATH)/build all

sd_demo-clean:
	$(Q)$(MAKE) -C $(SD_DEMO_PATH)/build clean

sd_demo-distclean:
	$(Q)$(MAKE) -C $(SD_DEMO_PATH)/build distclean

sd_demo-install:
	$(Q)$(MAKE) -C $(SD_DEMO_PATH)/build install

sd_demo-uninstall:
	$(Q)$(MAKE) -C $(SD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_MD_DEMO) += md_demo
PHONY += md_demo md_demo-clean md_demo-distclean
PHONY += md_demo-install md_demo-uninstall
md_demo:
	$(Q)$(MAKE) -C $(MD_DEMO_PATH)/build all

md_demo-clean:
	$(Q)$(MAKE) -C $(MD_DEMO_PATH)/build clean

md_demo-distclean:
	$(Q)$(MAKE) -C $(MD_DEMO_PATH)/build distclean

md_demo-install:
	$(Q)$(MAKE) -C $(MD_DEMO_PATH)/build install

md_demo-uninstall:
	$(Q)$(MAKE) -C $(MD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_OD_DEMO) += od_demo
PHONY += od_demo od_demo-clean od_demo-distclean
PHONY += od_demo-install od_demo-uninstall
od_demo:
	$(Q)$(MAKE) -C $(OD_DEMO_PATH)/build all

od_demo-clean:
	$(Q)$(MAKE) -C $(OD_DEMO_PATH)/build clean

od_demo-distclean:
	$(Q)$(MAKE) -C $(OD_DEMO_PATH)/build distclean

od_demo-install:
	$(Q)$(MAKE) -C $(OD_DEMO_PATH)/build install

od_demo-uninstall:
	$(Q)$(MAKE) -C $(OD_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_TD_DEMO) += pfm_demo
PHONY += pfm_demo pfm_demo-clean pfm_demo-distclean
PHONY += pfm_demo-install pfm_demo-uninstall
pfm_demo:
	$(Q)$(MAKE) -C $(PFM_DEMO_PATH)/build all

pfm_demo-clean:
	$(Q)$(MAKE) -C $(PFM_DEMO_PATH)/build clean

pfm_demo-distclean:
	$(Q)$(MAKE) -C $(PFM_DEMO_PATH)/build distclean

pfm_demo-install:
	$(Q)$(MAKE) -C $(PFM_DEMO_PATH)/build install

pfm_demo-uninstall:
	$(Q)$(MAKE) -C $(PFM_DEMO_PATH)/build uninstall

sample-demo-$(CONFIG_SAMPLE_DEMO_PKG_DEMO) += pkg_demo
PHONY += pkg_demo pkg_demo-clean pkg_demo-distclean
PHONY += pkg_demo-install pkg_demo-uninstall
pkg_demo:
	$(Q)$(MAKE) -C $(PKG_DEMO_PATH)/build all

pkg_demo-clean:
	$(Q)$(MAKE) -C $(PKG_DEMO_PATH)/build clean

pkg_demo-distclean:
	$(Q)$(MAKE) -C $(PKG_DEMO_PATH)/build distclean

pkg_demo-install:
	$(Q)$(MAKE) -C $(PKG_DEMO_PATH)/build install-all

pkg_demo-uninstall:
	$(Q)$(MAKE) -C $(PKG_DEMO_PATH)/build uninstall-all

sample-demo-$(CONFIG_SAMPLE_DEMO_TD_DEMO) += td_demo
PHONY += td_demo td_demo-clean td_demo-distclean
PHONY += td_demo-install td_demo-uninstall
td_demo:
	$(Q)$(MAKE) -C $(TD_DEMO_PATH)/build all

td_demo-clean:
	$(Q)$(MAKE) -C $(TD_DEMO_PATH)/build clean

td_demo-distclean:
	$(Q)$(MAKE) -C $(TD_DEMO_PATH)/build distclean

td_demo-install:
	$(Q)$(MAKE) -C $(TD_DEMO_PATH)/build install

td_demo-uninstall:
	$(Q)$(MAKE) -C $(TD_DEMO_PATH)/build uninstall

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
