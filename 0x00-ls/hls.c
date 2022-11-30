#include "hls.h"
#include "line_hls.h"

/**
 * setup_list_file - setup node
 * @head: head of nodes
 * @name: name of file
 * @read: stream directory
 * @flag: flag of option command
 */
void setup_list_file(line_hls_t ***head, char *name,
dirent *read, flag_t *flag)
{
	struct stat buf;
	struct passwd *usr;
	struct group *grp;
	line_hls_t **lines = *head;

	lstat(name, &buf);

	usr = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);

	add_line(lines);

	check_typeof_file(buf.st_mode, (*lines)->perm);

	hstrcpy((*lines)->usrname, usr->pw_name);
	hstrcpy((*lines)->grpname, grp->gr_name);

	(*lines)->size = buf.st_size;

	(*lines)->time = &(buf.st_mtime);
	if (flag->directory)
		hstrcpy((*lines)->name, read->d_name);
	else
		hstrcpy((*lines)->name, name);
	**head = *lines;
}

/**
 * setup_list_dir - setup list directory
 * @head: head of nodes
 * @name: pathname directory
 * @flag: flag of option command
 */
void setup_list_dir(line_hls_t **head, char *name, flag_t *flag)
{
	DIR *dir;
	struct dirent *read;
	char pathname[1024];
	line_hls_t **lines = head;

	dir = opendir(name);
	while ((read = readdir(dir)))
	{
		hstrcpy(pathname, name);
		hstrcat(pathname, read->d_name);

		if ((hstrcmp(read->d_name, ".") == 0 ||
				hstrcmp(read->d_name, "..") == 0))
			continue;
		setup_list_file(&lines, pathname, read, flag);
	}
	closedir(dir);
}

/**
 * hls - command hls
 * @flag: flag of option command
 * @name: pathname
 *
 * Return: error handling
 */
int hls(flag_t *flag, char *name)
{
	line_hls_t *lines = NULL;

	setup_list_dir(&lines, name, flag);
	print_name(lines, flag);
	clean(lines);
	return (0);
}
