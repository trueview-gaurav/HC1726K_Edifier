
############################################################
# choose project of customer

if IPC_CUSTOMER_NEUTRAL
source "build/menu/ipc.project/ipc.project.neutral.h"
endif

if IPC_CUSTOMER_HDT
source "build/menu/ipc.project/ipc.project.hdt.h"
endif

if IPC_CUSTOMER_DONGSHUN
source "build/menu/ipc.project/ipc.project.dongshun.h"
endif

if IPC_CUSTOMER_FSAN
source "build/menu/ipc.project/ipc.project.fsan.h"
endif
