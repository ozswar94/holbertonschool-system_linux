#include <elf.h>
#include <stdio.h>
#include "machine.h"


void choose_type(unsigned int type)
{
	switch (type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		case ET_NUM:
			printf("NUM (Number of defined types)\n");
			break;
		case ET_LOOS:
			printf("LOOS (OS-specific range start)\n");
			break;
		case ET_HIOS:
			printf("HIOS (OS-specific range end)\n");
			break;
		case ET_LOPROC:
			printf("LOPROC (Processor-specific range start)\n");
			break;
		case ET_HIPROC:
			printf("HIPROC (Processor-specific range end)\n");
	}
}

void choose_os_abi(unsigned int os_abi)
{

	if (os_abi == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (os_abi == ELFOSABI_HPUX)
		printf("HP-UX\n");
	else if (os_abi == ELFOSABI_NETBSD)
		printf("NetBSD\n");
	else if (os_abi == ELFOSABI_LINUX)
		printf("Linux\n");
	else if (os_abi == ELFOSABI_SOLARIS)
		printf("Sun Solaris\n");
	else if (os_abi == ELFOSABI_AIX)
		printf("IBM AIX\n");
	else if (os_abi == ELFOSABI_IRIX)
		printf("SGI Irix\n");
	else if (os_abi == ELFOSABI_FREEBSD)
		printf("FreeBSD\n");
	else if (os_abi == ELFOSABI_TRU64)
		printf("Compaq TRU64 UNIX\n");
	else if (os_abi == ELFOSABI_MODESTO)
		printf("Novell Modesto\n");
	else if (os_abi == ELFOSABI_OPENBSD)
		printf("OpenBSD\n");
	else if (os_abi == ELFOSABI_ARM)
		printf("ARM\n");
	else if (os_abi == ELFOSABI_STANDALONE)
		printf("Standalone (embedded) application\n");
}

void choose_data(unsigned int id_data)
{
	switch (id_data)
	{
		case ELFCLASSNONE:
			printf("Invalid data encoding\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
	}
}

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
	printf("  Class:                             ");
	if  (h->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (h->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
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
