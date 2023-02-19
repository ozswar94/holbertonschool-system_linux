#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


/**
* print_quit - print signal SIGQIT with pid
* @signum: signal number
* @info: stuct signal info
* @ucontext: pointer sturct context of signal
*/
static void print_quit(int signum, siginfo_t *info, void *ucontext)
{
	(void) signum;
	(void) ucontext;

	printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
* trace_signal_sender - a handler for the signal SIGQUIT
* Return: 0 on success, or -1 on error
*/
int trace_signal_sender(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = print_quit;
	return (sigaction(SIGQUIT, &act, NULL));
}
