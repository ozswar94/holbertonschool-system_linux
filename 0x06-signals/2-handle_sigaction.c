#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "signals.h"

/**
* print_Gotcha - Gotcha! [<signum>] followed by a new line
* @signum: signal number that was caught
*/
static void print_Gotcha(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}


/**
* handle_sigaction - set a handler for the signal SIGINT
* Return: 0 on success, or -1 on error
*/
int handle_sigaction(void)
{
	struct sigaction my_sa;

	my_sa.sa_handler = print_Gotcha;
	sigemptyset(&my_sa.sa_mask);
	my_sa.sa_flags = 0;

	return (sigaction(SIGINT, &my_sa, NULL));
}
