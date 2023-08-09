#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *elf_header) {
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\nClass: %d\n", elf_header->e_ident[EI_CLASS]);
    printf("Data: %d\n", elf_header->e_ident[EI_DATA]);
    printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", elf_header->e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header->e_type);
    printf("Entry point address: 0x%lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        exit(98);
    }

    Elf64_Ehdr elf_header;
    ssize_t bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (bytes_read != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error: Unable to read ELF header\n");
        close(fd);
        exit(98);
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        exit(98);
    }

    print_elf_header_info(&elf_header);

    close(fd);
    return (0);
}

