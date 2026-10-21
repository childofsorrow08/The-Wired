#include <stdint.h>
#include <stddef.h>

#include <elf.h>

static void memory_copy(void *destination,
                        const void *source,
                        uint32_t size) {
    uint8_t *dst = (uint8_t *)destination;
    const uint8_t *src = (const uint8_t *)source;

    for (uint32_t i = 0; i < size; i++)
        dst[i] = src[i];
}

static void memory_zero(void *destination, uint32_t size) {
    uint8_t *dst = (uint8_t *)destination;

    for (uint32_t i = 0; i < size; i++)
        dst[i] = 0;
}

void *elf_load(const void *file, uint32_t file_size) {
    if (file == NULL)
        return NULL;

    if (file_size < sizeof(elf32_header_t))
        return NULL;

    const uint8_t *data = (const uint8_t *)file;
    const elf32_header_t *header =
        (const elf32_header_t *)file;

    if (header->ident[0] != 0x7F ||
        header->ident[1] != 'E'  ||
        header->ident[2] != 'L'  ||
        header->ident[3] != 'F')
        return NULL;

    if (header->ident[4] != 1)
        return NULL;

    if (header->ident[5] != 1)
        return NULL;

    if (header->type != 2)
        return NULL;

    if (header->machine != 3)
        return NULL;

    if (header->program_header_size != sizeof(elf32_program_header_t))
        return NULL;

    uint32_t ph_table_size =
        (uint32_t)header->program_header_count *
        header->program_header_size;

    if (header->program_header_offset > file_size)
        return NULL;

    if (ph_table_size >
        file_size - header->program_header_offset)
        return NULL;

    for (uint16_t i = 0;
         i < header->program_header_count;
         i++) {

        const elf32_program_header_t *program =
            (const elf32_program_header_t *)(
                data +
                header->program_header_offset +
                i * header->program_header_size
            );

        if (program->type != ELF_PT_LOAD)
            continue;

        if (program->memory_size < program->file_size)
            return NULL;

        if (program->offset > file_size)
            return NULL;

        if (program->file_size >
            file_size - program->offset)
            return NULL;

        uint8_t *destination = (uint8_t *)(uintptr_t)program->virtual_address;

        const uint8_t *source = data + program->offset;

        memory_copy(destination, source, program->file_size);
        memory_zero(destination + program->file_size,
                    program->memory_size - program->file_size);
    }

    return (void *)(uintptr_t)header->entry;
}
