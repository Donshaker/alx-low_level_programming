#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *header) {
    int i;
    printf("Magic: ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
                          header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Unknown");

    printf("Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" :
                         header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big-endian" : "Unknown");

    printf("Version: %d\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI: %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
                        header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX" :
                        header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone" : "Unknown");

    printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type: %s\n", header->e_type == ET_NONE ? "No file type" :
                        header->e_type == ET_REL ? "Relocatable file" :
                        header->e_type == ET_EXEC ? "Executable file" :
                        header->e_type == ET_DYN ? "Shared object file" :
                        header->e_type == ET_CORE ? "Core file" : "Unknown");

    printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    const char *elf_filename = argv[1];
    int fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 98;
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        perror("Error reading ELF header");
        close(fd);
        return 98;
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 98;
    }

    print_elf_header_info(&header);

    close(fd);
    return 0;
}

