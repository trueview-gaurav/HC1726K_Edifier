
############################################################
#### <choose hardware scheme> ###############################

if IPC_CPUFAMILY_QCHC17
source "build/menu/ipc.hardware/ipc.hardware.qchc17.h" 
endif

if IPC_CPUFAMILY_HI3516CV500
source "build/menu/ipc.hardware/ipc.hardware.hi3516cv500.h" 
endif

if IPC_CPUFAMILY_HI3516EV200
source "build/menu/ipc.hardware/ipc.hardware.hi3516ev200.h" 
endif

if IPC_CPUFAMILY_JZT30
source "build/menu/ipc.hardware/ipc.hardware.jzt30.h" 
endif

if IPC_CPUFAMILY_JZT32
source "build/menu/ipc.hardware/ipc.hardware.jzt32.h" 
endif

if IPC_CPUFAMILY_JZT33
source "build/menu/ipc.hardware/ipc.hardware.jzt33.h" 
endif

if IPC_CPUFAMILY_JZT40
source "build/menu/ipc.hardware/ipc.hardware.jzt40.h" 
endif

if IPC_CPUFAMILY_JZT41
source "build/menu/ipc.hardware/ipc.hardware.jzt41.h"
endif

# <choose hardware scheme/> ----------------------------------------------#

