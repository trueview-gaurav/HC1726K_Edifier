# RTL8188 Series WIFI Driver Deployment Tool

### Overview
This tool is designed to automate the integration of **RTL8188 series (EU/FU)** wireless drivers into the **Linux 3.18.31** kernel tree. It handles the entire lifecycle of driver setup: from fetching source code and pinning versions to patching and updating the kernel build system.

---

### Prerequisites
Before running the script, ensure the following requirements are met:

1.  **Work Directory**: The script **must** be executed from the **SDK Root Directory**.
2.  **Tools**: `git`, `sed`, `grep`, and `bash` must be available in your environment.
3.  **Required Files**: The following patch files must be present in the same directory as the script:
    * `ivanovborislav_rtl8188eu.patch`
    * `supremegamers_rtl8188fu.patch`
    * `install_wifi_driver_linux_r3.18.31.sh`
    * `install_wifi_driver_linux_r6.1.102.sh`

---

### Usage Instructions

#### 1. Set Permissions

Grant execution rights to the deployment script:

```bash
$ chmod +x install_wifi_driver_linux_r3.18.31.sh
$ chmod +x install_wifi_driver_linux_r6.1.102.sh
$ chmod +x run_wifi_driver_install_scripts.sh
```

#### 2. Execute Deployment

Run the script from the **build** folder in the SDK:

```Bash
# For Example, in the build folder.
$ cd <SDK_root>/firmware/build/
$ sh ../../sdk/kernel/linux_patch/wifi_drivers/run_wifi_driver_install.sh
```
----------------------------------
**Copyright (C) 2026 Qualcomm Technologies, Inc. All rights reserved. Confidential and Proprietary - Qualcomm Technologies, Inc.**
