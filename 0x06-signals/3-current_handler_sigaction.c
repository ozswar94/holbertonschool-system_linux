#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/**
* current_handler_sigaction - retrieves the current handler
* of the signal SIGINT
* Return: pointer to the current handler of SIGINT, or NULL on failure
*/
void (*current_handler_sigaction(void))(int)
{
	struct sigaction old;

	memset(&old, 0, sizeof(old));
	if (!sigaction(SIGINT, NULL, &old))
		return (old.sa_handler);
	return (NULL);
}
