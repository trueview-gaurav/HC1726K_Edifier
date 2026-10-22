################################################################################
#
# Build the ubifs filesystem image
#
################################################################################

SYSTEM_UBIFS_OPTS := -e $(UBIFS_LEBSIZE) -c $(UBIFS_MAXLEBCNT) -m $(UBIFS_MINIOSIZE)

#ifeq ($(UBIFS_RT_ZLIB),y)
SYSTEM_UBIFS_OPTS += -x zlib
#endif
#ifeq ($(UBIFS_RT_LZO),y)
#SYSTEM_UBIFS_OPTS += -x lzo
#endif
#ifeq ($(UBIFS_RT_NONE),y)
#SYSTEM_UBIFS_OPTS += -x none
#endif

SYSTEM_UBIFS_OPTS += -F

SYSTEM_UBI_UBINIZE_OPTS := -m $(UBIFS_MINIOSIZE)
SYSTEM_UBI_UBINIZE_OPTS += -p $(UBI_PEBSIZE)
ifneq ($(UBI_SUBSIZE),0)
SYSTEM_UBI_UBINIZE_OPTS += -s $(UBI_SUBSIZE)
endif
