#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hreadelf.h"

/**
* print_elf64_section_header - print section header
* @header: header of elf file
* @ptr_elf: elf map in memory
*
*/
void print_elf64_section_header(Elf64_Ehdr *header, void *ptr_elf)
{
	int i, strndx, stroff, spot;
	Elf64_Shdr section_header;
	char *strtable, *sh_name;

	/*read section header string table header*/
	spot = header->e_shoff; /*section header table file offset*/
	strndx = header->e_shstrndx; /*section header string table index*/
	stroff = spot + strndx * header->e_shentsize;
	memcpy(&section_header, (char *)ptr_elf + stroff, header->e_shentsize);

	/*read section string table*/
	strtable = malloc(section_header.sh_size);
	memcpy(strtable, (char *)ptr_elf + section_header.sh_offset,
		section_header.sh_size);

	for (i = 0; i < header->e_shnum; ++i)
	{
		memcpy(&section_header, (char *)ptr_elf + spot, header->e_shentsize);
		spot += header->e_shentsize;
		sh_name = &strtable[section_header.sh_name];
		printf("[%d] %s\n", i, sh_name);
	}
}


/**
* print_elf32_section_header - print section header
* @header: header of elf file
* @ptr_elf: elf map in memory
*
*/
void print_elf32_section_header(Elf32_Ehdr *header, void *ptr_elf)
{
	int i, strndx, stroff, spot;
	Elf32_Shdr section_header;
	char *strtable, *sh_name;

	/*read section header string table header*/
	spot = header->e_shoff; /*section header table file offset*/
	strndx = header->e_shstrndx; /*section header string table index*/
	stroff = spot + strndx * header->e_shentsize;
	memcpy(&section_header, (char *)ptr_elf + stroff, header->e_shentsize);

	/*read section string table*/
	strtable = malloc(section_header.sh_size);
	memcpy(strtable, (char *)ptr_elf + section_header.sh_offset,
		section_header.sh_size);

	for (i = 0; i < header->e_shnum; ++i)
	{
		memcpy(&section_header, (char *)ptr_elf + spot, header->e_shentsize);
		spot += header->e_shentsize;
		sh_name = &strtable[section_header.sh_name];
		printf("[%d] %s\n", i, sh_name);
	}
}
