devmem 0x8380000C 32 0x00000001 #pwr_up
devmem 0x83800010 32 0x00000003 #soft_reset_0
devmem 0x83800014 32 0xFFFFFFFF #soft_reset_1
devmem 0x83800100 32 0x00010C00 #phy_mode_cfg [phy_mode=D-PHY, ppi_width=PPI-16]
devmem 0x83800204 32 0x00000000 #csi2_descrambling_cfg [disable descrambling]
devmem 0x83800104 32 0x00000000 #phy_deskew_cfg []
devmem 0x83800200 32 0x00000001 #csi2_general_cfg
#devmem 0x83800400 32 0x00000001 #sdi_cfg
devmem 0x83800300 32 0x00000001 #ipi_port_sel
devmem 0x83800308 32 0x00000001 #ipi_port_ctrl
devmem 0x83800304 32 0x00000100 #ipi_port_cfg
