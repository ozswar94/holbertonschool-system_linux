#include "hls.h"


/**
 * check_typeof_file - setup permision of file
 * @mode: mask permission of file
 * @perm: string perm
 *
 * Return: perm of file
 */
char *check_typeof_file(mode_t mode, char *perm)
{
	int i;
	typefile_t types[7] = {
		{S_ISREG(mode), '-'}, {S_ISDIR(mode), 'd'}, {S_ISCHR(mode), 'c'},
		{S_ISBLK(mode), 'b'}, {S_ISFIFO(mode), 'P'}, {S_ISLNK(mode), 'l'},
		{S_ISSOCK(mode), 's'},
	};

	permfile_t perm_t[9] = {
		{S_IRUSR, 'r'}, {S_IWUSR, 'w'}, {S_IXUSR, 'x'}, {S_IRGRP, 'r'},
		{S_IWGRP, 'w'}, {S_IXGRP, 'x'}, {S_IROTH, 'r'}, {S_IWOTH, 'w'},
		{S_IXOTH, 'x'},
	};

	hmemset(perm, 0, 12);

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
		if (perm_t[i].mask & mode)
			perm[i + 1] = perm_t[i].symbole;
		else
			perm[i + 1] = '-';
	}
	return (perm);
}
