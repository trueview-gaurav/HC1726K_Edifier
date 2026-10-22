
choice 
    prompt "Hardware Scheme"

config IPC_HARDWARE_QCHC1726_D61_Q38
	depends on IPC_PLATFORM_QCHC1726
	bool "QCHC1726_D61_Q38"
	select IPC_FLASH_NOR16M

endchoice

config IPC_HARDWARE
	string
	default "QCHC1726_D61_Q38" if IPC_HARDWARE_QCHC1726_D61_Q38


config IPC_HWID
	string
	default "3300" if IPC_HARDWARE_QCHC1726_D61_Q38