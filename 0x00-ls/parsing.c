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


/**
 * isdirectory - check if pathname is a directory
 * @pathname: string
 * @flag: flag option
 *
 */

void isdirectory(char *pathname, flag_t *flag)
{
	struct stat buf;
	unsigned int size = hstrlen(pathname);

	lstat(pathname, &buf);

	if (buf.st_mode & S_IFDIR)
	{
		flag->directory = 1;
		if (pathname[size - 1] != '/')
			hstrcat(pathname, "/");
	}
}
