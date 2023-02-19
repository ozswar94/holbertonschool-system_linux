#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

/**
* print_caught - print when the signal send
* @signum: signal number
*/
void print_caught(int signum)
{
	printf("Caught %d\n", signum);
	puts("Signal received");

	exit(EXIT_SUCCESS);
}


/**
* main - suspend indefinitely until a signal is received
* Return: EXIT_SUCCESS
*/
int main(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = print_caught;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);

	pause();

	return (0);
}
