#include "hls.h"
#include "line_hls.h"

/**
 * setup_list_file - setup node
 * @head: head of nodes
 * @name: name of file
 * @read: stream directory
 */
void setup_list_file(line_hls_t ***head, char *name,
dirent *read)
{
	struct stat buf;
	struct passwd *usr;
	struct group *grp;
	char datetime[256];
	line_hls_t **lines = *head;

	lstat(name, &buf);

	usr = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);

	add_line(lines);

	check_typeof_file(buf.st_mode, (*lines)->perm);

	hstrcpy((*lines)->usrname, usr->pw_name);
	hstrcpy((*lines)->grpname, grp->gr_name);

	(*lines)->size = buf.st_size;

	hstrcpy(datetime, ctime(&(buf.st_mtime)));
	datetime[hstrlen(datetime) - 9] = '\0';
	hstrcpy((*lines)->time, (datetime + 4));

	(*lines)->hlnk = buf.st_nlink;

	if (read)
		hstrcpy((*lines)->name, read->d_name);
	else
		hstrcpy((*lines)->name, name);
	**head = *lines;
}

/**
 * setup_list_dir - setup list directory
 * @head: head of nodes
 * @name: pathname directory
 */
void setup_list_dir(line_hls_t **head, char *name)
{
	DIR *dir;
	struct dirent *read;
	char pathname[1024];
	line_hls_t **lines = head;

	dir = opendir(name);
	if (dir == NULL)
	{
		setup_list_file(&lines, name, NULL);
		return;
	}
	while ((read = readdir(dir)))
	{
		hstrcpy(pathname, name);
		hstrcat(pathname, read->d_name);

		setup_list_file(&lines, pathname, read);
	}
	closedir(dir);
}

/**
 * hls - command hls
 * @name: pathname
 * @flag: option command
 * Return: error handling
 */
int hls(char *name, flag_t flag)
{
	line_hls_t *lines = NULL;

	if (!name)
		return (-1);

	setup_list_dir(&lines, name);
	print_list(lines, flag);
	clean(lines);
	return (0);
}
