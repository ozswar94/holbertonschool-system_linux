#include <signal.h>
#include <stdlib.h>

/**
* signals_block - block a given set of signals from being
* delivered to the current process
*
* @signals: array of int, each one being a signal number
*
* Return: 0 on success, or -1 on error
*/
int signals_block(int *signals)
{
	sigset_t set;
	int i;

	sigemptyset(&set);
	for (i = 0; signals[i] != 0; i++)
		if (sigaddset(&set, signals[i]) == -1)
			return (-1);
	return (sigprocmask(SIG_BLOCK, &set, NULL));
}
