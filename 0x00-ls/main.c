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
	int i, nb_option = 0, status = 0;
	char *pathname;
	flag_t flag = {0, 0, 0, 0, 0, 0, 0, 0, 1};

    /*option validation*/
	for (i = argc - 1; i > 0; i--)
		if (argv[i][0] == '-')
		{
			define_flag(argv[i], &flag);
			nb_option++;
		}

	if (argc < 2 || nb_option == argc - 1)
		hls("./", flag);
	else
		for (i = argc - 1; i > 0; i--)
		{
			if (argv[i][0] == '-')
				continue;
			pathname = setup_pathname(argv[i], argv[0]);
			if (errno > status)
				status = errno;

			if (argc >= 3 && pathname)
				printf("%s:\n", argv[i]);

			hls(pathname, flag);

			if (argc >= 3 && i > 1 && pathname)
				printf("\n");
			free(pathname);
		}
	return (status);
}
