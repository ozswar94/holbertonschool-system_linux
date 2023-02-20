#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

/**
* print_caught - print signals T with info
* @signum: signal number
* @info: stuct signal info
* @ucontext: pointer sturct context of signal
*/
void print_caught(int signum, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	(void) signum;
	psiginfo(info, "Caught");
}

/**
* all_in_one - single handler for all the signals
*/
void all_in_one(void)
{
	int sig;
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = print_caught;
	act.sa_flags = SA_SIGINFO;
	for (sig = 1; sig <= SIGRTMAX; sig++)
		sigaction(sig, &act, NULL);
}
