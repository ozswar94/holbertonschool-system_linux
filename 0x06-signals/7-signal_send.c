#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

/**
* main - sends the signal SIGINT to a process, given its PID
* @argc: number of argument
* @argv: arguments and name of program
* Return: EXIT_SUCCESS on success, or EXIT_FAILURE
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	kill(atoi(argv[1]), SIGINT);
	return (EXIT_SUCCESS);
}
