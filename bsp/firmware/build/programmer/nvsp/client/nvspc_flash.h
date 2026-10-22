#ifndef NVSPC_FLASH_DEFINE_H_
#define NVSPC_FLASH_DEFINE_H_

int init_flash(uint32_t flash_type, BootConfig *boot_config);

/* 
 * @erase_progress : show erase progress if 1
 */
int nvspc_erase_partition(uint32_t part_base, uint32_t part_size, uint32_t erase_progress, uint32_t part_num);
int read_from_partition(uint32_t nvs_start, uint32_t nvs_size, uintptr_t img_addr, uint32_t img_size);
void get_quad_mode_detection(int flash_type);

/* 
 * @write_progress : show write progress if 1
 */
int write_to_partition(uint32_t part_base, uint32_t part_size, uintptr_t mem_base, uint32_t img_size,
                       uint32_t write_progress);
void exit_flash_program(void);

#endif // NVSPC_FLASH_DEFINE_H_
