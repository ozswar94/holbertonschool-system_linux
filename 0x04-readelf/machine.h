#ifndef MACHINE_H
#define MACHINE_H

typedef struct machine_s
{
    unsigned int id;
    char name[100];
} machine_t;

void choose_machine(int id_machine);

#endif /*MACHINE_H*/