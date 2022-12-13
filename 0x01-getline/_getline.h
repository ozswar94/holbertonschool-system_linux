#ifndef __GETLINE_H_
#define __GETLINE_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE 1024

typedef struct lines_s
{
    int fd;
    char *line;
    struct line_s *next;
} lines_t;

char *_getline(const int fd);

#endif /*__GETLINE_H_*/