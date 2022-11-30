#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

typedef struct typefile_s{
	int mask;
	char symbole;
} typefile_t;


typedef struct permfile_s{
	int mask;
	char symbole;
} permfile_t;

char *check_typeof_file(mode_t mode);

int main(int argc, char **argv)
{
	DIR *dir;
	char *time;
	char pathname[256];
	char name[256];
	char *perm;
	struct stat buf;
	struct dirent *read;
	struct passwd *usr;
	struct group *grp;

	if (argc < 2)
		strcpy(name, "./");
	else
		strcpy(name, argv[1]);


	dir = opendir(name);
	while ((read = readdir(dir)))
	{
		/* create pathname for lstat */
		strcpy(pathname, name);
		strcat(pathname, read->d_name);

		lstat(pathname, &buf);

		/* delete new line */
		time = ctime(&(buf.st_mtime));
		time[strlen(time) - 1] = '\0';

		usr = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);

		perm = check_typeof_file(buf.st_mode);
		printf("%s %s %s %lu %s %s\n", perm, usr->pw_name, grp->gr_name, buf.st_size, time, read->d_name);	
		
		/* clean pathname for the next */
		memset(pathname, 0, 256);
		free(perm);
	}
	closedir(dir);
	return (0);
}


char *check_typeof_file(mode_t mode)
{

	int i;

	typefile_t types [7] = {
		{S_ISREG(mode), '-'}, {S_ISDIR(mode), 'd'}, {S_ISCHR(mode), 'c'},
		{S_ISBLK(mode), 'b'}, {S_ISFIFO(mode), 'P'}, {S_ISLNK(mode), 'l'},
		{S_ISSOCK(mode), 's'},
	};

	permfile_t perm_t[9] = {
		{S_IRUSR, 'r'}, {S_IWUSR, 'w'}, {S_IXUSR, 'x'}, {S_IRGRP, 'r'},
		{S_IWGRP, 'w'}, {S_IXGRP, 'x'}, {S_IROTH, 'r'}, {S_IWOTH, 'w'},
		{S_IXOTH, 'x'},
	};

	char *perm = (char *)malloc(sizeof(char) * 11);
	memset(perm, 0, 11);

	for (i = 0; i < 7; i++)
	{
		if (types[i].mask)
		{
			perm[0] = types[i].symbole;
			break;
		}
	}

	for (i = 0; i < 9; i++)
	{
		if(perm_t[i].mask & mode)
			perm[i + 1] = perm_t[i].symbole;
		else
			perm[i + 1] = '-';
	}
	return (perm);
}
