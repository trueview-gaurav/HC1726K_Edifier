import argparse
import configparser
import logging
import os
from enum import IntEnum
from typing import Optional, Callable, NamedTuple, Union, Iterator

_log = logging.getLogger(__name__)
ImageSupplier = Callable[[], bytes]


class NvsType(IntEnum):
    NAND = 0
    NOR = 1
    EMMC = 2

    @classmethod
    def by_name(cls, name: str) -> Optional["NvsType"]:
        try:
            return cls[name.upper()]
        except KeyError:
            return None


class Partition(NamedTuple):
    nvs_start: int
    nvs_size: int
    pt_label: str
    img_label: Optional[str]
    memory_address: int
    image: Union[bytes, ImageSupplier]

    @property
    def image_data(self):
        if callable(self.image):
            return self.image()
        return self.image

    def __repr__(self):
        image_desc = '...' if callable(self.image) else f'<{len(self.image)} bytes>'
        return f"Partition(nvs_start={self.nvs_start}, nvs_size={self.nvs_size}, pt_label={self.pt_label}, img_label={self.img_label}, memory_address={self.memory_address}, image={image_desc})"


class IniSource:
    def __init__(self, ini_path, *, preload_image=True):
        self._source_dir = os.path.dirname(os.path.abspath(ini_path))
        self._config = configparser.ConfigParser()
        self._config.read(ini_path)
        self._images = {}
        self._baudrate = 7875000
        self._partition_table_addr = 0x8000
        self._image_holder_addr = 0x80000
        if preload_image:
            self._preload_images()

    def _preload_images(self):
        partition_sections = (self._config[name] for name in self._config.keys() if name.startswith("partition_"))
        image_section_names = (section["img_label"] for section in partition_sections if section["img_label"])
        for name in image_section_names:
            file_name = self._config.get(name, "file_name", fallback=None)
            if file_name:
                image_path = os.path.join(self._source_dir, file_name)
                try:
                    with open(image_path, 'rb') as fp:
                        self._images[name] = fp.read()
                    _log.info("%s is loaded", image_path)
                except:
                    _log.exception("access file %s FAILED", image_path)
            else:
                _log.debug("section [%s] has NO file_name option", name)

    @property
    def nvs_type(self) -> NvsType:
        return NvsType.by_name(self._config["bootconfig"]["nvs_type"])

    @property
    def boot_index(self) -> int:
        return int(self._config["bootconfig"]["boot_idx"])

    @property
    def verify_in_booting(self) -> int:
        return int(self._config["bootconfig"]["verify"])

    @property
    def nvspc_data(self) -> bytes:
        with open(os.path.join(self._source_dir, "nvspc.bin"), 'rb') as fp:
            return fp.read()

    @property
    def baudrate(self) -> int:
        return self._baudrate

    @baudrate.setter
    def baudrate(self, baudrate: int):
        self._baudrate = baudrate

    @property
    def partition_table_address(self) -> int:
        return self._partition_table_addr

    @partition_table_address.setter
    def partition_table_address(self, address: int):
        self._partition_table_addr = address

    @property
    def image_holder_address(self) -> int:
        return self._image_holder_addr

    @image_holder_address.setter
    def image_holder_address(self, address):
        self._image_holder_addr = address

    def enumerate_partitions(self) -> Iterator[Partition]:
        partition_names = [name for name in self._config.keys() if name.startswith("partition_")]
        for name in partition_names:
            nvs_start = self.__to_int(self._config[name]["nvs_start"])
            nvs_size = self.__to_int(self._config[name]["nvs_size"])
            partition_label = self._config[name]["pt_label"]
            memory_addr = self.__to_int(self._config[name]["mem_start"])
            image_label = self._config[name]["img_label"]
            image = bytes()
            if image_label:
                if image_label in self._images:
                    image = self._images[image_label]
                else:
                    with open(os.path.join(self._source_dir, self._config[image_label]["file_name"]), 'rb') as fp:
                        image = fp.read()
            yield Partition(nvs_start=nvs_start,
                            nvs_size=nvs_size,
                            pt_label=partition_label,
                            img_label=image_label,
                            memory_address=memory_addr,
                            image=image)

    @staticmethod
    def __to_int(expression):
        if expression.startswith("0x") or expression.startswith("0X"):
            return int(expression, 16)
        return int(expression)


def build_stream(partitions: Iterator[Partition]) -> Iterator[bytes]:
    all_partitions = sorted(partitions, key=lambda p: p.memory_address)
    output_size = 0
    for partition in all_partitions:
        if output_size < partition.nvs_start:
            yield b'\xff' * (partition.nvs_start - output_size)
            output_size = partition.nvs_start
        data = partition.image
        yield data
        if len(data) < partition.nvs_size:
            yield b'\xff' * (partition.nvs_size - len(data))
        output_size += partition.nvs_size


def get_options():
    parser = argparse.ArgumentParser()
    parser.add_argument("-o", "--output", default=None, help="output file path")
    parser.add_argument('-f', '--force', action='store_true', help='force overwrite output file')
    parser.add_argument('partition_ini', help="ini file path")
    return parser.parse_args()

def main():
    options = get_options()
    if not os.path.exists(options.partition_ini):
        print(f'[ERROR] partition ini file `{options.partition_ini}` not exists')
        return

    if options.output:
        target_file = os.path.abspath(options.output)
    else:
        target_file = os.path.splitext(os.path.abspath(options.partition_ini))[0] + '.bin'

    if os.path.exists(target_file) and not options.force:
        print(f"[ERROR] output file `{target_file}` exists, use '-f' to overwrite")
        return

    with open(target_file, 'wb') as fp:
        chunks = build_stream(IniSource(options.partition_ini).enumerate_partitions())
        for chunk in chunks:
            fp.write(chunk)
    print(f'[INFO] output file is `{target_file}`')


if __name__ == '__main__':
    main()
