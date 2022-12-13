#ifndef __GETLINE_H_
#define __GETLINE_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE 32


/**
 * struct reader_s - linked list for storage line in fd
 * @fd: file desciptor
 * @buf: buffer of read
 * @bytes: number of bytes read
 * @next: next element in linked list
 *
 * Description: Longer description
 */
typedef struct reader_s
{
	int fd;
	char *buf;
	int bytes;
	struct reader_s *next;
} reader_t;


/*function*/
char *_getline(const int fd);
char *find_line(reader_t *rd);

#endif /*__GETLINE_H_*/
