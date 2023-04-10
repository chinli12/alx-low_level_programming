#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(98);
    }

    // Read and check the ELF magic number
    unsigned char e_ident[EI_NIDENT];
    if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT ||
        e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s: not an ELF file\n", argv[1]);
        exit(98);
    }

    // Determine the ELF class and data encoding
    int e_class = e_ident[EI_CLASS];
    int e_data = e_ident[EI_DATA];
    const char *class_str;
    const char *data_str;
    switch (e_class) {
        case ELFCLASSNONE: class_str = "none"; break;
        case ELFCLASS32: class_str = "ELF32"; break;
        case ELFCLASS64: class_str = "ELF64"; break;
        default: class_str = "unknown"; break;
    }
    switch (e_data) {
        case ELFDATANONE: data_str = "none"; break;
        case ELFDATA2LSB: data_str = "2's complement, little endian"; break;
        case ELFDATA2MSB: data_str = "2's complement, big endian"; break;
        default: data_str = "unknown"; break;
    }

    // Read the rest of the ELF header
    Elf64_Ehdr ehdr;
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        exit(98);
    }
    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
        perror("read");
        exit(98);
    }

    // Print the information from the ELF header
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
    printf("Class:   %s\n", class_str);
    printf("Data:    %s\n", data_str);
    printf("Version: %d\n", e_ident[EI_VERSION]);
    printf("OS/ABI:  %d\n", e_ident[EI_OSABI]);
    printf("ABI Ver: %d\n", e_ident[EI_ABIVERSION]);
    printf("Type:    %d\n", ehdr.e_type);
    printf("Entry:   0x%lx\n", ehdr.e_entry);

    close(fd);
    return 0;
}
