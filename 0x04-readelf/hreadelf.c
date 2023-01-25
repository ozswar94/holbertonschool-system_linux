#include "hreadelf.h"
#include <stdio.h>

/**
* hreadelf - copy of programme readelf
* @ptr_elf: anonyme pointer elf
* Return: -1 if error, 0 if success
*/
int hreadelf(void **ptr_elf)
{
	if (read_elf64_header(*ptr_elf) < 0)
	{
		read_elf32_header(*ptr_elf);
	}
	else
		return (-1);

	return (0);
}
