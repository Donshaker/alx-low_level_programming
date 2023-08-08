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
        return (98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
        return (98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Cannot read ELF header from '%s'\n", argv[1]);
        close(fd);
        return (98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: File '%s' is not an ELF file\n", argv[1]);
        close(fd);
        return (98);
    }

    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header.e_ident[i]);
    printf("\n");

    printf("Class:                             ");
    switch (header.e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("None\n"); break;
        case ELFCLASS32:   printf("ELF32\n"); break;
        case ELFCLASS64:   printf("ELF64\n"); break;
        default:           printf("<unknown>\n"); break;
    }

    printf("Data:                              ");
    switch (header.e_ident[EI_DATA])
    {
        case ELFDATANONE: printf("None\n"); break;
        case ELFDATA2LSB: printf("2's complement, little-endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big-endian\n"); break;
        default:          printf("<unknown>\n"); break;
    }

    printf("Version:                           %d\n", header.e_ident[EI_VERSION]);

    printf("OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI])
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

    printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (header.e_type)
    {
        case ET_NONE:   printf("NONE (None)\n"); break;
        case ET_REL:    printf("REL (Relocatable file)\n"); break;
        case ET_EXEC:   printf("EXEC (Executable file)\n"); break;
        case ET_DYN:    printf("DYN (Shared object file)\n"); break;
        case ET_CORE:   printf("CORE (Core file)\n"); break;
        default:        printf("<unknown>\n"); break;
    }

    printf("Entry point address:               %#lx\n", (unsigned long)header.e_entry);

    close(fd);
    return (0);
}
}

