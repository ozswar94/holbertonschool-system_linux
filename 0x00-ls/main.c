#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct perm_s{
	int mask;
	char symbole;
}perm_t;
	
char *check_typeof_file(mode_t mode);

int main(int argc, char **argv)
{
	DIR *dir;
	char pathname[256];
	char *perm;
	struct stat buf;
	struct dirent *read;
	if (argc < 2)
		return (-1);

	dir = opendir(argv[1]);
	while ((read = readdir(dir)))
	{
		/* create pathname for lstat */
		strcpy(pathname, argv[1]);
		strcat(pathname, read->d_name);

		perm = check_typeof_file(buf.st_mode);
		lstat(pathname, &buf);
		printf("%s %lu %s\n", perm, buf.st_size, read->d_name);	
		
		/* clean pathname for the next */
		memset(pathname, 0, 256);
		free(perm);
	}
	return (0);
}


char *check_typeof_file(mode_t mode)
{

	int i;
	perm_t permissions [7] = {
		{S_ISREG(mode), '-'},
		{S_ISDIR(mode), 'd'},
		{S_ISCHR(mode), 'c'},
		{S_ISBLK(mode), 'b'},
		{S_ISFIFO(mode), 'P'},
		{S_ISLNK(mode), 'l'},
		{S_ISSOCK(mode), 's'},
	};
	char *perm = (char *)malloc(sizeof(char) * 11);
	memset(perm, 0, 11);

	for (i = 0; i < 7; i++)
	{
		if (permissions[i].mask)
		{
			printf("%d ", mode);
			perm[0] = permissions[i].symbole;
			break;
		}
	}

	return (perm);
}
