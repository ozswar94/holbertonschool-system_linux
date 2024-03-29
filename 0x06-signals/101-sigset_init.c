#include <signal.h>

/**
* sigset_init - initializes a sigset
* @set: a pointer to the signal set to initialize
* @signals: array of int, each one being a signal number
* Return: 0 on success, or -1 on error
*/
int sigset_init(sigset_t *set, int *signals)
{
	int i = 0;

	sigemptyset(set);
	for (i = 0; signals[i] != 0; i++)
		if (sigaddset(set, signals[i]) == -1)
			return (-1);
	return (0);
}
