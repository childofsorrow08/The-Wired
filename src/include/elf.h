#ifndef ELF_H
#define ELF_H

#include <stdint.h>

#define ELF_PT_LOAD 1

typedef struct __attribute__((packed)) {
    uint8_t  ident[16];

    uint16_t type;
    uint16_t machine;
    uint32_t version;

    uint32_t entry;
    uint32_t program_header_offset;
    uint32_t section_header_offset;

    uint32_t flags;

    uint16_t header_size;
    uint16_t program_header_size;
    uint16_t program_header_count;

    uint16_t section_header_size;
    uint16_t section_header_count;
    uint16_t section_header_string_index;
} elf32_header_t;

typedef struct __attribute__((packed)) {
    uint32_t type;
    uint32_t offset;
    uint32_t virtual_address;
    uint32_t physical_address;
    uint32_t file_size;
    uint32_t memory_size;
    uint32_t flags;
    uint32_t alignment;
} elf32_program_header_t;

void *elf_load(
    const void *file,
    uint32_t file_size
);

#endif
