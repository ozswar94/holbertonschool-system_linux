#ifndef SIGNALS_H
#define SIGNALS_H

int handle_signal(void);
int handle_sigaction(void);

void (*current_handler_signal(void))(int);
void (*current_handler_sigaction(void))(int);

int trace_signal_sender(void);

int pid_exist(pid_t pid);

void all_in_one(void);

int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);

#endif /*SIGNALS_H*/
