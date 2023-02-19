#ifndef SIGNALS_H
#define SIGNALS_H

int handle_signal(void);
int handle_sigaction(void);

void (*current_handler_signal(void))(int);
void (*current_handler_sigaction(void))(int);

#endif /*SIGNALS_H*/
