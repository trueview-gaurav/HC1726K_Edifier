include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

include $(SDKSRC_DIR)/firmware/build/build_flags.mk

APP_LIB = $(APP_PATH)/library/output

AVMAIN2_PATH = $(APP_PATH)/apps/av_daemon/av_main2/build

AIC8800M40_PATH = $(APP_PATH)/apps/aic8800_m40
CONNSEL_PATH = $(APP_PATH)/apps/connsel
EAIF_SERV_PATH = $(APP_PATH)/apps/eaif_server
EAIF_SERV_BUILD_PATH = $(EAIF_SERV_PATH)/build
ONVIF_SERVER_PATH = $(APP_PATH)/apps/onvif_server
IPASSIGN_PATH = $(APP_PATH)/apps/ip_assign
STAMEN_PATH = $(APP_PATH)/apps/stamen
SECURE_ELEMENT_DEMO_PATH = $(APP_PATH)/3rd_party/secure_element_demo
SE_AUTH_PATH = $(APP_PATH)/apps/se_auth/build
TEE_AUTH_PATH = $(APP_PATH)/apps/tee_auth/build
WIFI_PATH= $(APP_PATH)/apps/wifi
WS_DISCOVERY_PATH = $(APP_PATH)/apps/ws_discovery
MP4_RECORDER_PATH = $(APP_PATH)/apps/mp4_recorder
EXIF_SNAPSHOT_PATH = $(APP_PATH)/apps/exif_snapshot

# ONVIF_DISCOVERY_PATH is deprecated.
# Please use WS_DISCOVERY_PATH instead.
ONVIF_DISCOVERY_PATH = $(WS_DISCOVERY_PATH)

CENTCTRL_PATH = $(APP_PATH)/database/centctrl
CENTCTRL_INC = $(CENTCTRL_PATH)/include
DBMONITOR_PATH = $(APP_PATH)/database/dbmonitor
SQLAPP_PATH = $(APP_PATH)/database/sqlapp
SQLAPP_INC = $(SQLAPP_PATH)/include
CASE_CONFIG_PATH = $(APP_PATH)/database/case_config

FLV_PATH = $(APP_PATH)/apps/flv_server
GST_RTSP_SERVER_PATH = $(APP_PATH)/apps/gst-rtsp-server

ACCESS_MODE_PATH = $(APP_PATH)/utils/access_mode
ALARMOUT_PATH = $(APP_PATH)/utils/alarm_out
APPVERIFY_PATH = $(APP_PATH)/utils/appverify
DAY_NIGHT_MODE_PATH = $(APP_PATH)/utils/day_night_mode
EVENTD_PATH = $(APP_PATH)/utils/event_daemon
GPIO_DAEMONS_PATH = $(APP_PATH)/utils/gpio_daemons
MP_AUTOTEST_PATH = $(APP_PATH)/utils/mp_autotest
NRS_PATH = $(APP_PATH)/utils/nrs
NRS_BUILD = $(NRS_PATH)/build
NRS_INC = $(NRS_PATH)/include
NRS_LIB = $(NRS_PATH)/lib
OTP_PATH = $(APP_PATH)/utils/otp
OTP_BUILD = $(OTP_PATH)/build
OTP_INC = $(OTP_PATH)/include
OTP_LIB = $(OTP_PATH)/lib
SNTP_PATH = $(APP_PATH)/utils/sntp
SYSUPD_TOOLS_PATH = $(APP_PATH)/utils/sysupd_tools
UVC_PATH = $(APP_PATH)/utils/uvc
THERMAL_PROTECTION_PATH = $(APP_PATH)/utils/thermal_protection
WATCHDOG_PATH = $(APP_PATH)/utils/watchdog
SYSTEM_LEVEL_TEST_PATH = $(APP_PATH)/utils/system_level_test
FW_ENV_PATH = $(APP_PATH)/utils/fw_env
REALTIME_DBG_PATH = $(APP_PATH)/utils/realtime_dbg

WEBCGI_PATH = $(APP_PATH)/web/webcgi

LIBFOO_PATH = $(APP_PATH)/library/libfoo
LIBFOO_INC = $(LIBFOO_PATH)/include
LIBFOO_LIB = $(LIBFOO_PATH)/lib

LIBGPIO_PATH = $(APP_PATH)/library/libgpio
LIBLEDEVT_PATH = $(EVENTD_PATH)/libledevt
LIBLEDEVT_INC = $(LIBLEDEVT_PATH)
LIBLEDEVT_LIB = $(LIBLEDEVT_PATH)

LIBUTILS_PATH = $(APP_PATH)/library/libutils
LIBUTILS_INC = $(LIBUTILS_PATH)/include
LIBUTILS_LIB = $(LIBUTILS_PATH)/lib

LIBPWM_PATH = $(APP_PATH)/library/libpwm

LIBSQL_PATH = $(APP_PATH)/library/libsql
LIBSQL_INC = $(LIBSQL_PATH)
LIBSQL_LIB = $(LIBSQL_PATH)

LIBTZ_PATH = $(APP_PATH)/library/libtz
LIBTZ_INC = $(LIBTZ_PATH)/include
LIBTZ_LIB = $(LIBTZ_PATH)

SECURE_ELEMENT_PATH = $(APP_PATH)/3rd_party/secure_element
SECURE_ELEMENT_INC_PATH = $(SECURE_ELEMENT_PATH)/include
SECURE_ELEMENT_LIB_PATH = $(SECURE_ELEMENT_PATH)/lib
