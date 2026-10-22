################################################################################
#
# Build the ubifs filesystem image
#
################################################################################

CALIB_UBIFS_OPTS := -e $(CONFIG_UBIFS_LEBSIZE) -c $(CONFIG_CALIB_UBIFS_MAXLEBCNT) -m $(CONFIG_UBIFS_MINIOSIZE)
CALIB_UBIFS_OPTS += -F
CALIB_UBIFS_OPTS += -j $(CONFIG_USRDATA_UBIFS_JRNLSIZE)
CALIB_UBIFS_OPTS += -x zlib

CALIB_UBI_UBINIZE_OPTS := -m $(CONFIG_UBIFS_MINIOSIZE)
CALIB_UBI_UBINIZE_OPTS += -p $(CONFIG_UBI_PEBSIZE)
ifneq ($(CONFIG_UBI_SUBSIZE),0)
CALIB_UBI_UBINIZE_OPTS += -s $(CONFIG_UBI_SUBSIZE)
endif
