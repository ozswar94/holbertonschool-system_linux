#ifndef SIGNALS_H
#define SIGNALS_H

int handle_signal(void);
int handle_sigaction(void);

void (*current_handler_signal(void))(int);
void (*current_handler_sigaction(void))(int);

int trace_signal_sender(void);

#endif /*SIGNALS_H*/
