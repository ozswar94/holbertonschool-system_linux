#include "hls.h"


/**
 * setup_pathname - setup pathname of lstat()
 * @name: string argv
 *
 * Return: pathname
 */
char *setup_pathname(char *name)
{
	unsigned int size = hstrlen(name);
	char *pathname;

	pathname = (char *)malloc(sizeof(char) * size + 4);

	if (!pathname)
	{
		fprintf(stderr, "Error malloc pathname !");
		exit(EXIT_FAILURE);
	}
	hstrcpy(pathname, name);

	return (pathname);
}
