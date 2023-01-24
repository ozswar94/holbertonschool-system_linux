#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>


int main(int argc, char **argv)
{
    int fd;
    size_t file_size;
    void *ptr_elf = NULL;
    int err = EXIT_SUCESS;
    ElfN_Ehdr *header_elf = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [bin] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open failed!");
        err = EXIT_FAILURE;
        goto cleanup;
    }

    file_size = lseek(fd, 0, SEEK_END);
    if (file_size < 0)
    {
        perror("lseek failed!");
        err = EXIT_FAILURE;
        goto cleanup;
    }

    ptr_elf = mmap(NULL, file_size, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr_elf == MAP_FAILED)
    {
        perror("mmap failed!")
        err = EXIT_FAILURE;
        goto cleanup;
    }


    cleanup:
    if (fd != -1)
        close(fd);
    if (ptr_elf != MAP_FAILED)
        munmap((void *)ptr_elf, file_size);
    return (err);
}