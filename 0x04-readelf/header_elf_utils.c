#include <stdio.h>
#include "hreadelf.h"
/**
* choose_type - print type of binary file
* @type: id of type
*
*/
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

/**
* choose_os_abi- print OS/ABI
* @os_abi: id of os_abi
*
*/
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

/**
* choose_data- print type of data encoding
* @id_data: id of data encoding
*
*/
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
