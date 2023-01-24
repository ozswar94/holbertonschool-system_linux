#include <stdio.h>
#include "hreadelf.h"

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

	print_elf64_header(header);

	return (0);
}
