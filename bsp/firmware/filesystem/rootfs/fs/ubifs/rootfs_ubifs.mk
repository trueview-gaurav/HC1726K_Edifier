################################################################################
# UBIFS filesystem image
# ################################################################################

ROOTFS_UBIFS_OPTS := -e $(CONFIG_UBIFS_LEBSIZE) -c $(CONFIG_ROOTFS_UBIFS_MAXLEBCNT) -m $(CONFIG_UBIFS_MINIOSIZE)
ROOTFS_UBIFS_OPTS += -F
ROOTFS_UBIFS_OPTS += -j $(CONFIG_ROOTFS_UBIFS_JRNLSIZE)

#ifeq ($(UBIFS_RT_ZLIB),y)
ROOTFS_UBIFS_OPTS += -x zlib
#endif
#ifeq ($(UBIFS_RT_LZO),y)
#ROOTFS_UBIFS_OPTS += -x lzo
#endif
#ifeq ($(UBIFS_RT_NONE),y)
#ROOTFS_UBIFS_OPTS += -x none
#endif

ROOTFS_UBI_UBINIZE_OPTS := -m $(CONFIG_UBIFS_MINIOSIZE)
ROOTFS_UBI_UBINIZE_OPTS += -p $(CONFIG_UBI_PEBSIZE)
ifneq ($(CONFIG_UBI_SUBSIZE),0)
ROOTFS_UBI_UBINIZE_OPTS += -s $(CONFIG_UBI_SUBSIZE)
endif
