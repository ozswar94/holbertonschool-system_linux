#include <stdlib.h>
#include <signal.h>

/**
*
*/
int handle_pending(void (*handler)(int signum))
{
    struct sigaction act;
    sigset_t pending;

    
}