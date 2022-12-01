#ifndef _HLS_H
#define _HLS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include "hstring.h"
#include <errno.h>


/**
 * struct typefile_s - show type of files on command hls
 * @mask: st_mode of file
 * @symbole: symbole show on command hls
 *
 * Description: define the first symbole of string, determine if
 * is a regular file '-', or is directory 'd', or a socket 's', or (...)
 */
typedef struct typefile_s
{
	unsigned int mask;
	char symbole;
} typefile_t;


/**
 * struct permfile_s - show permision of files on hls
 * @mask: st_mode of file
 * @symbole: Second member
 *
 * Description: define is the owner group and other can do with the file,
 * read, write, execute
 */
typedef struct permfile_s
{
	unsigned int mask;
	char symbole;
} permfile_t;

/**
 * struct flag_s - flag of command
 * @long_listing_f: flag l
 * @all: flag a
 * @almost_all: flag A
 * @list_on_file_per_line: flag l
 * @reverse: flag r
 * @recursive: flag R
 * @sorting_by_size: flag S
 * @sorting_by_modificationtime: flag t
 * @directory: if is a directory or not
 * @default_hls: default
 * Description: define flag of command
 */
typedef struct flag_s
{
	unsigned char long_listing_f;
	unsigned char all;
	unsigned char almost_all;
	unsigned char list_on_file_per_line;
	unsigned char reverse;
	unsigned char recursive;
	unsigned char sorting_by_size;
	unsigned char sorting_by_modificationtime;
	unsigned char directory;
	unsigned char default_hls;
} flag_t;



/* function */
int hls(char *name);
char *check_typeof_file(mode_t mode, char *perm);
char *setup_pathname(char *name, char *program_name);

#endif /* _HLS_H */
