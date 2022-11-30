#include "hls.h"

/**
 * main - entry function
 * @argc: number of argument
 * @argv: argument
 *
 * Return: Succes = 0, Error = 2
 */
int main(int argc, char **argv)
{
	char *pathname;
	flag_t *flag;

	setup_flag(&flag);

	if (argc < 2)
		pathname = setup_pathname(".");
	else
		pathname = setup_pathname(argv[1]);
	isdirectory(pathname, flag);
	hls(flag, pathname);
	free(flag);
	free(pathname);
	return (0);
}
