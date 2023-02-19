#include <signal.h>
#include <stdlib.h>

/**
* current_handler_signal - retrieves the current handler of the signal SIGINT
* Return: pointer to the current handler of SIGINT, or NULL on failure
*/
void (*current_handler_signal(void))(int)
{
	void (*sig)(int);

	sig = signal(SIGINT, NULL);

	if (sig == SIG_ERR)
		return (NULL);
	return (signal(SIGINT, sig));
}
