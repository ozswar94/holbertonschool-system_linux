#include <elf.h>
#include <stdio.h>
#include "machine.h"
#include "hreadelf.h"

/**
* print_elf64_header - print header elf 64 bit
* @h: struct Elf64_Ehdr
*/
void print_elf64_header(Elf64_Ehdr *h)
{
	int i;

	puts("ELF Header:");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		if (i < EI_NIDENT - 1)
			printf("%02x ", h->e_ident[i]);
		else
			printf("%02x\n", h->e_ident[i]);
	printf("  Class:                             ELF64\n");
	printf("  Data:                              ");
	choose_data(h->e_ident[EI_DATA]);
	printf("  Version:                           %u (current)\n", h->e_version);
	printf("  OS/ABI:                            ");
	choose_os_abi(h->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %u\n",
			h->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	choose_type(h->e_type);
	printf("  Machine:                           ");
	choose_machine(h->e_machine);
	printf("  Version:                           0x%x\n",
			h->e_version);
	printf("  Entry point address:               0x%lx\n", h->e_entry);
	printf("  Start of program headers:          %lu (bytes into file)\n",
			h->e_phoff);
	printf("  Start of section headers:          %lu (bytes into file)\n",
			h->e_shoff);
	printf("  Flags:                             0x%x\n", h->e_flags);
	printf("  Size of this header:               %u (bytes)\n", h->e_ehsize);
	printf("  Size of program headers:           %u (bytes)\n", h->e_phentsize);
	printf("  Number of program headers:         %u\n", h->e_phnum);
	printf("  Size of section headers:           %u (bytes)\n", h->e_shentsize);
	printf("  Number of section headers:         %u\n", h->e_shnum);
	printf("  Section header string table index: %u\n", h->e_shstrndx);
}

/**
* print_elf32_header - print header elf 32 bit
* @h: struct Elf32_Ehdr
*/
void print_elf32_header(Elf32_Ehdr *h)
{
	int i;

	puts("ELF Header:");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		if (i < EI_NIDENT - 1)
			printf("%02x ", h->e_ident[i]);
		else
			printf("%02x\n", h->e_ident[i]);
	printf("  Class:                             ELF32\n");
	printf("  Data:                              ");
	choose_data(h->e_ident[EI_DATA]);
	printf("  Version:                           %u (current)\n", h->e_version);
	printf("  OS/ABI:                            ");
	choose_os_abi(h->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %u\n",
			h->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	choose_type(h->e_type);
	printf("  Machine:                           ");
	choose_machine(h->e_machine);
	printf("  Version:                           0x%x\n",
			h->e_version);
	printf("  Entry point address:               0x%x\n", h->e_entry);
	printf("  Start of program headers:          %u (bytes into file)\n",
			h->e_phoff);
	printf("  Start of section headers:          %u (bytes into file)\n",
			h->e_shoff);
	printf("  Flags:                             0x%x\n", h->e_flags);
	printf("  Size of this header:               %u (bytes)\n", h->e_ehsize);
	printf("  Size of program headers:           %u (bytes)\n", h->e_phentsize);
	printf("  Number of program headers:         %u\n", h->e_phnum);
	printf("  Size of section headers:           %u (bytes)\n", h->e_shentsize);
	printf("  Number of section headers:         %u\n", h->e_shnum);
	printf("  Section header string table index: %u\n", h->e_shstrndx);
}
