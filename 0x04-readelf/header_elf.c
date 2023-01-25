#include <stdio.h>
#include "hreadelf.h"

/**
* read_elf64_header - check if elf 64bit
* @ptr_elf: anonyme pointer elf
* Return: -1 if error 1 if success
*/
int read_elf64_header(void *ptr_elf)
{
	Elf64_Ehdr *header = (Elf64_Ehdr *)ptr_elf;

	if (header->e_ident[EI_MAG0] != 0x7f &&
		header->e_ident[EI_MAG1] != 'E' &&
		header->e_ident[EI_MAG1] != 'L' &&
		header->e_ident[EI_MAG1] != 'F')
	{
		return (-1);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS64)
		print_elf64_header(header);
	else
		return (-1);

	return (1);
}


/**
* read_elf32_header - check if elf 32bit
* @ptr_elf: anonyme pointer elf
* Return: -1 if error 1 if success
*/
int read_elf32_header(void *ptr_elf)
{
	Elf32_Ehdr *header = (Elf32_Ehdr *)ptr_elf;

	if (header->e_ident[EI_MAG0] != 0x7f &&
		header->e_ident[EI_MAG1] != 'E' &&
		header->e_ident[EI_MAG1] != 'L' &&
		header->e_ident[EI_MAG1] != 'F')
	{
		return (-1);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		print_elf32_header(header);
	else
		return (-1);

	return (1);
}
