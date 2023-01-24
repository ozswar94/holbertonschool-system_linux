#ifndef HREADELF_H
#define HREADELF_H

#include <elf.h>

int read_elf64_header(void *ptr_elf);
void print_elf64_header(Elf64_Ehdr *h);

#endif /*HREADELF_H*/
