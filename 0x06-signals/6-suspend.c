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
	sigaction(SIGINT, &act, NULL);
	pause();
	return (EXIT_SUCCESS);
}
