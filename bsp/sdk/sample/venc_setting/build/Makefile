# Makefile to read .list file, copy corresponding .ini files, and create symbolic links

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SENSOR_PATH)/common.mk

# Convert CONFIG_CHIP to lowercase
CONFIG_CHIP_LOWER = $(shell echo $(CONFIG_CHIP) | tr '[:upper:]' '[:lower:]' | sed 's/_/-/g')


LIST_FILE = ../list/$(CONFIG_CHIP_LOWER)/$(CONFIG_MACH).list
SOURCE_DIR = ../source
OUTPUT_DIR = ../output

all: read_list copy_ini create_symlinks

.PHONY : read_list copy_ini create_symlinks install uninstall clean

read_list:
	@if [ ! -f $(LIST_FILE) ]; then \
		echo "Error: $(LIST_FILE) does not exist."; \
		exit 1; \
	fi
	@echo "Reading list file: $(LIST_FILE)"
	@grep -E '^\[Channel [0-9]\]$$|normal:|ir:|light:' $(LIST_FILE) | while read line ; do \
		if echo $$line | grep -q '^\[Channel' ; then \
			channel=`echo $$line | sed 's/^\[Channel \([0-9]\)\]$$/\1/'` ; \
		else \
			mode=`echo $$line | cut -d':' -f1` ; \
			ini_file=`echo $$line | cut -d':' -f2 | tr -d ' '` ; \
			echo "Channel $$channel $$mode: $$ini_file" ; \
		fi \
	done

copy_ini:
	@if [ ! -f $(LIST_FILE) ]; then \
		echo "Error: $(LIST_FILE) does not exist."; \
		exit 1; \
	fi
	@echo "Copying .ini files to output directory..."
	@mkdir -p $(OUTPUT_DIR)
	@grep -E 'normal:|ir:|light:' $(LIST_FILE) | while read line ; do \
		ini_file=`echo $$line | cut -d':' -f2 | tr -d ' '` ; \
		if [ -n "$$ini_file" ]; then \
			if [ -e $(SOURCE_DIR)/$$ini_file ]; then \
				cp $(SOURCE_DIR)/$$ini_file $(OUTPUT_DIR)/ ; \
			else \
				echo "Error: $(SOURCE_DIR)/$$ini_file not exist." ; \
				exit 1; \
			fi \
		fi \
	done
	@echo "Copy complete."

create_symlinks: copy_ini
	@echo "Creating symbolic links..."
	@grep -E '^\[Channel [0-9]\]$$|normal:|ir:|light:' $(LIST_FILE) | while read line ; do \
		if echo $$line | grep -q '^\[Channel' ; then \
			channel=`echo $$line | sed 's/^\[Channel \([0-9]\)\]$$/\1/'` ; \
		else \
			mode=`echo $$line | cut -d':' -f1` ; \
			ini_file=`echo $$line | cut -d':' -f2 | tr -d ' '` ; \
			if [ -n "$$ini_file" ]; then \
				if [ "$$mode" = "normal" ]; then \
					ln -sf $$ini_file $(OUTPUT_DIR)/venc_extend_$${channel}.ini ; \
					echo "Link created for Channel $$channel Mode $$mode: $(OUTPUT_DIR)/venc_extend_$${channel}.ini -> $$ini_file" ; \
				else \
					ln -sf $$ini_file $(OUTPUT_DIR)/venc_extend_$${mode}_$${channel}.ini ; \
					echo "Link created for Channel $$channel Mode $$mode: $(OUTPUT_DIR)/venc_extend_$${mode}_$${channel}.ini -> $$ini_file" ; \
				fi \
			fi \
		fi \
	done
	@echo "Symbolic links creation complete."

install: all
	@echo "Installing files to $(TARGET_SCRIPT_DIR)..."
	@mkdir -p $(TARGET_SCRIPT_DIR)
	@if [ -d "$(OUTPUT_DIR)" ]; then \
		if [ -n "$$(ls -A $(OUTPUT_DIR))" ]; then \
			echo "Installing files from $(OUTPUT_DIR)"; \
			cp -a $(OUTPUT_DIR)/* $(TARGET_SCRIPT_DIR); \
		else \
			echo "Warning: $(OUTPUT_DIR) is empty. Nothing to install."; \
		fi \
	else \
		echo "Warning: $(OUTPUT_DIR) does not exist. Nothing to install."; \
	fi

uninstall:
	@echo "Uninstalling symbolic links and their targets from $(TARGET_SCRIPT_DIR)..."
	@if [ -d "$(TARGET_SCRIPT_DIR)" ]; then \
		find $(TARGET_SCRIPT_DIR) -name 'venc_extend*.ini' -type l | while read symlink; do \
			if [ -n "$$(command -v readlink)" ]; then \
				target=$$(readlink "$$symlink"); \
				rm -f "$(TARGET_SCRIPT_DIR)/$$target"; \
			fi; \
			rm -f "$$symlink"; \
		done; \
	fi
	@echo "Uninstall complete."

clean:
	@echo "Cleaning output directory..."
	@rm -rf $(OUTPUT_DIR)
	@echo "Clean complete."

distclean: uninstall clean
