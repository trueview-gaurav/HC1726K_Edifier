import configparser
import sys

if len(sys.argv) != 3:
	print("Input format error on", sys.argv[0])
	sys.exit(1)

# parse_file = hc1706-agt706-1.ini
parse_file = sys.argv[1]
# dest_file = nvsp_partiion_size.env
dest_file = sys.argv[2]

print("Now Parsing file ",parse_file, "...")

config = configparser.ConfigParser()
config.read(parse_file)

factor = 1

def find_nvs_type():
	NVS_TYPE = config['bootconfig']['nvs_type']
	if NVS_TYPE == 'emmc':
		return 512
	else:
		return 1

def find_bin_name(input_name):
	return config[input_name]['file_name']

def find_nvs_size(input_name):
	MAXIMUM_SIZE = 0
	for section in config.sections():
		if not config.has_option(section, 'img_label'):
			continue
		if config.get(section, 'img_label') == input_name:
			MAXIMUM_SIZE_HEX = config.get(section, 'nvs_size')
			MAXIMUM_SIZE_DEX = int(MAXIMUM_SIZE_HEX, 16)
			MAXIMUM_SIZE = MAXIMUM_SIZE_DEX * factor
			break
	if MAXIMUM_SIZE == 0:
		print("[error] rootfs_maximum_size not found")
		sys.exit(1)
	return MAXIMUM_SIZE

factor = find_nvs_type()

CEHCK_ROOTFS_BIN = find_bin_name('rootfs')
CHECK_ROOTFS_MAXIMUM_SIZE = find_nvs_size('rootfs')

with open(dest_file, "w") as f:
	f.write(f"# Generate by {sys.argv[0]}\n")
	f.write(f"CEHCK_ROOTFS_BIN={CEHCK_ROOTFS_BIN}\n")
	f.write(f"CHECK_ROOTFS_MAXIMUM_SIZE={CHECK_ROOTFS_MAXIMUM_SIZE}\n")
