#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_magic - Prints the ELF magic number.
 * @e_ident: ELF identification array.
 */
void print_magic(unsigned char *e_ident)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

/**
 * print_class - Prints the ELF class.
 * @e_ident: ELF identification array.
 */
void print_class(unsigned char *e_ident)
{
    printf("Class:                             ");
    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("None\n"); break;
        case ELFCLASS32:   printf("ELF32\n"); break;
        case ELFCLASS64:   printf("ELF64\n"); break;
        default:           printf("<unknown>\n"); break;
    }
}

/**
 * print_data - Prints the ELF data encoding.
 * @e_ident: ELF identification array.
 */
void print_data(unsigned char *e_ident)
{
    printf("Data:                              ");
    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE: printf("None\n"); break;
        case ELFDATA2LSB: printf("2's complement, little-endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big-endian\n"); break;
        default:          printf("<unknown>\n"); break;
    }
}

/**
 * print_version - Prints the ELF version.
 * @e_ident: ELF identification array.
 */
void print_version(unsigned char *e_ident)
{
    printf("Version:                           %d\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the ELF OS/ABI.
 * @e_ident: ELF identification array.
 */
void print_osabi(unsigned char *e_ident)
{
    printf("OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:        printf("UNIX System V ABI\n"); break;
        case ELFOSABI_HPUX:        printf("HP-UX\n"); break;
        case ELFOSABI_NETBSD:      printf("NetBSD\n"); break;
        case ELFOSABI_LINUX:       printf("Linux\n"); break;
        case ELFOSABI_SOLARIS:     printf("Solaris\n"); break;
        case ELFOSABI_AIX:         printf("AIX\n"); break;
        case ELFOSABI_IRIX:        printf("IRIX\n"); break;
        case ELFOSABI_FREEBSD:     printf("FreeBSD\n"); break;
        case ELFOSABI_TRU64:       printf("TRU64 UNIX\n"); break;
        case ELFOSABI_MODESTO:     printf("Modesto\n"); break;
        case ELFOSABI_OPENBSD:     printf("OpenBSD\n"); break;
        default:                   printf("<unknown>\n"); break;
    }
}

/**
 * print_abiversion - Prints the ELF ABI version.
 * @e_ident: ELF identification array.
 */
void print_abiversion(unsigned char *e_ident)
{
    printf("ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF type.
 * @e_type: ELF type.
 */
void print_type(uint16_t e_type)
{
    printf("Type:                              ");
    switch (e_type)
    {
        case ET_NONE:   printf("NONE (None)\n"); break;
        case ET_REL:    printf("REL (Relocatable file)\n"); break;
        case ET_EXEC:   printf("EXEC (Executable file)\n"); break;
        case ET_DYN:    printf("DYN (Shared object file)\n"); break;
        case ET_CORE:   printf("CORE (Core file)\n"); break;
        default:        printf("<unknown>\n"); break;
    }
}

/**
 * print_entry - Prints the ELF entry point address.
 * @e_entry: ELF entry point address.
 */
void print_entry(uint64_t e_entry)
{
    printf("Entry point address:               %#lx\n", e_entry);
}

/**
 * main - Displays the ELF header information of a file.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return (EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
        return (EXIT_FAILURE);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Cannot read ELF header from '%s'\n", argv[1]);
        close(fd);
        return (EXIT_FAILURE);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: File '%s' is not an ELF file\n", argv[1]);
        close(fd);
        return (EXIT_FAILURE);
    }

    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abiversion(header.e_ident);
    print_type(header.e_type);
    print_entry(header.e_entry);

    close(fd);
    return (EXIT_SUCCESS);
}
}

