#include "hls.h"


/**
 * error_message- setup error message
 * @name: pathname
 * @program_name: name of program
 *
 * Return: erro message
 */
char *error_message(char *name, char *program_name)
{
	char *error_msg;
	unsigned int size_program_name = hstrlen(program_name);

	error_msg = (char *)malloc(sizeof(char) * 1024 + size_program_name);
	if (!error_msg)
	{
		fprintf(stderr, "Error malloc pathname !");
		return (NULL);
	}
	hstrcpy(error_msg, program_name);
	hstrcat(error_msg, ": ");
	hstrcat(error_msg, "cannot access ");
	hstrcat(error_msg, name);
	return (error_msg);
}
/**
 * setup_pathname - setup pathname of lstat()
 * @name: string argv
 * @program_name: name of programme
 *
 * Return: pathname
 */
char *setup_pathname(char *name, char *program_name)
{
	unsigned int size = hstrlen(name);
	char *pathname;
	struct stat buf;
	char *err_msg;

	pathname = (char *)malloc(sizeof(char) * size + 4);

	if (!pathname)
	{
		fprintf(stderr, "Error malloc pathname !");
		exit(EXIT_FAILURE);
	}

	hstrcpy(pathname, name);

	if ((lstat(name, &buf)) == -1)
	{
		err_msg = error_message(pathname, program_name);
		perror(err_msg);
		free(err_msg);
		free(pathname);
		errno = 2;
		return (NULL);
	}

	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		hstrcat(pathname, "/");
	return (pathname);
}
