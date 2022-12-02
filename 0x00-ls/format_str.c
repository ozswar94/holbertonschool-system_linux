#include "line_hls.h"

/**
 * format_string - list name of file
 * @node: head of node
 * @flag: option command
 * Return: fotmat string
 */
void format_string(line_hls_t *node, flag_t flag)
{
	if (hstrlen(node->name) == 2 || hstrlen(node->name) == 1)
	{
		if (flag.almost_all &&
			(hstrcmp(node->name, ".") == 0 || hstrcmp(node->name, "..") == 0))
		{
			if (node->next == NULL)
				printf("\n");
			return;
		}
	}

	if (flag.long_listing_f)
	{
		printf("%s %u %s %s %u %s %s\n", node->perm, node->hlnk,
				node->usrname, node->grpname, node->size,
				node->time, node->name);
		return;
	}

	if (!(flag.all) && node->name[0] == '.')
	{
		if (node->next == NULL && !flag.list_on_file_per_line)
			printf("\n");
		return;
	}

	if (flag.list_on_file_per_line)
	{
		printf("%s\n", node->name);
		return;
	}

	if (node->next == NULL)
		printf("%s\n", node->name);
	else
		printf("%s ", node->name);
}
