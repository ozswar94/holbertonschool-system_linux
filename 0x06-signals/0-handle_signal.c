#include <stdio.h>
#include <signal.h>


/**
* print_Gotcha - Gotcha! [<signum>] followed by a new line
* @signum: signal number that was caught
*/
static void print_Gotcha(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
* handle_signal - set a handler for the signal SIGINT
* Return: 0 on success, or -1 on error
*/
int handle_signal(void)
{
	void (*prev_handler)(int);

	prev_handler = signal(SIGINT, print_Gotcha);
	if (prev_handler == SIG_ERR)
		return (-1);
	return (0);
}
