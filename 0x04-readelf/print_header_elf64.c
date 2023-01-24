#include <elf.h>
#include <stdio.h>

void print_elf64_header(Elf64_Ehdr *h)
{
	int i;

	puts("ELF Header:");
	
	printf(" Magic:\t");
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (i < EI_NIDENT - 1)
			printf("%x ", h->e_ident[i]);
		else
			printf("%x\n", h->e_ident[i]);
	}

	printf(" Class:\t\t");
	switch (h->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
	}

	printf(" Data:\t\t");
	switch (h->e_ident[EI_DATA])
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

	printf(" Version:\t");
	printf("%u (current)\n", h->e_version);

	printf(" Data:\t\t");
	switch (h->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Sun Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("IBM AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("SGI Irix\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
	}
}
