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
	int i;
	int status = 0;
	char *pathname;

	if (argc < 2)
		hls("./");
	else
		for (i = argc - 1; i > 0; i--)
		{
			pathname = setup_pathname(argv[i], argv[0]);
			if (errno > status)
				status = errno;

			if (argc >= 3 && pathname)
				printf("%s:\n", argv[i]);

			hls(pathname);

			if (argc >= 3 && i > 1 && pathname)
				printf("\n");
			free(pathname);
		}
	return (status);
}
