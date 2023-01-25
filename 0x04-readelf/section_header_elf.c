#include "hreadelf.h"

int read_section_header_elf64(ptr *ptr_elf)
{
	Elf64_Ehdr *header = (Elf64_Ehdr *)ptr_elf;
	Elf64_Shdr *section_header = NULL;

	if (header->e_ident[EI_MAG0] != 0x7f &&
		header->e_ident[EI_MAG1] != 'E' &&
		header->e_ident[EI_MAG1] != 'L' &&
		header->e_ident[EI_MAG1] != 'F')
	{
		return (-1);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS64)
	{
		print_elf64_header(header, &ptr_elf);

		section_header = (Elf64_Shdr *) (ptr_elf + (unsigned int)header->e_shoff);
		print_elf64_header(Elf64_Shdr *section_header);
	}
	else
		return (-1);

	return (1);
}


int read_section_header_elf32(ptr *ptr_elf)
{
	Elf32_Ehdr *header = (Elf32_Ehdr *)ptr_elf;

	if (header->e_ident[EI_MAG0] != 0x7f &&
		header->e_ident[EI_MAG1] != 'E' &&
		header->e_ident[EI_MAG1] != 'L' &&
		header->e_ident[EI_MAG1] != 'F')
	{
		return (-1);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS64)
	{
		print_elf64_header(header, &ptr_elf);

		section_header = (Elf64_Shdr *) (ptr_elf + (unsigned int)header->e_shoff);
		print_elf64_header(Elf64_Shdr *section_header);
	}
	else
		return (-1);

	return (1);
}