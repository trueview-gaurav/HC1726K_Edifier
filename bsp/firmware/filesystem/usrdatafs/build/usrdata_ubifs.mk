################################################################################
# UBIFS filesystem image
################################################################################

USRDATA_UBIFS_OPTS := -e $(CONFIG_UBIFS_LEBSIZE) -c $(CONFIG_USRDATA_UBIFS_MAXLEBCNT) -m $(CONFIG_UBIFS_MINIOSIZE)
USRDATA_UBIFS_OPTS += -F
USRDATA_UBIFS_OPTS += -j $(CONFIG_USRDATA_UBIFS_JRNLSIZE)

#ifeq ($(UBIFS_RT_ZLIB),y)
USRDATA_UBIFS_OPTS += -x zlib
#endif
#ifeq ($(UBIFS_RT_LZO),y)
#USRDATA_UBIFS_OPTS += -x lzo
#endif
#ifeq ($(UBIFS_RT_NONE),y)
#USRDATA_UBIFS_OPTS += -x none
#endif

USRDATA_UBI_UBINIZE_OPTS := -m $(CONFIG_UBIFS_MINIOSIZE)
USRDATA_UBI_UBINIZE_OPTS += -p $(CONFIG_UBI_PEBSIZE)
ifneq ($(CONFIG_UBI_SUBSIZE),0)
USRDATA_UBI_UBINIZE_OPTS += -s $(CONFIG_UBI_SUBSIZE)
endif
