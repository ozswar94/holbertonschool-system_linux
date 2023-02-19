#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "signals.h"

/* Our functions */
void print_hello(int signum)
{
    (void) signum;
    printf("Hello :)\n");
}

void set_print_hello(void)
{
    struct sigaction my_sa;

	my_sa.sa_handler = print_hello;
	sigemptyset(&my_sa.sa_mask);
	my_sa.sa_flags = 0;
    sigaction(SIGINT, &my_sa, NULL);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    void (*handler)(int);
    int i;

    handler = current_handler_sigaction();
    printf("Address of the current handler: %#lx\n", (unsigned long int)handler);

    /* Set 'print_hello()` as the handler for SIGINT */
    set_print_hello();

    handler = current_handler_sigaction();
    printf("Address of the 'print_hello' function: %#lx\n", (unsigned long int)&print_hello);
    printf("Address of the current handler: %#lx\n", (unsigned long int)handler);

    for (i = 0; ; i++)
    {
        printf("[%d] Wait for it ...\n", i);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}