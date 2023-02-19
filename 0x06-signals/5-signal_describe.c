#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
* main - prints a description of a given signal
* @argc: number of argument
* @argv: string of all arguments
* Return: 0 Success, EXIT_FAILURE error
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	return (0);
}
