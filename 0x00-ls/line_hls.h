#ifndef _LINE_HLS_H
#define _LINE_HLS_H

#include "hls.h"

/**
 * struct line_hls_s- node of file
 * @perm: permision of file
 * @usrname: user file
 * @grpname: group file
 * @size: size of file
 * @name: name of file
 * @next: next file of the list
 * @time: date of the last modification of file
 *
 * Description: node of file list  with different section
 */
typedef struct line_hls_s
{
	char *perm;
	char *usrname;
	char *grpname;
	unsigned int size;
	const time_t *time; /*ctime() format string*/
	char *name;
	struct line_hls_s *next;
} line_hls_t;

/**
 * diren - Typedef for struct dirent
 */
typedef struct dirent dirent;

void print_name(line_hls_t *node);
void add_line(line_hls_t **node);
void clean(line_hls_t *node);

#endif /* _LINE_HLS_H */
