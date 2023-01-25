#ifndef HREADELF_H
#define HREADELF_H

#include <elf.h>

int hreadelf(void **ptr_elf);

int read_elf64_header(void *ptr_elf);
int read_elf32_header(void *ptr_elf);

void print_elf64_header(Elf64_Ehdr *h);
void print_elf32_header(Elf32_Ehdr *h);

void choose_type(unsigned int type);
void choose_os_abi(unsigned int os_abi);
void choose_data(unsigned int id_data);

#endif /*HREADELF_H*/
